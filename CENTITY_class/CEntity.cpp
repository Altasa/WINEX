#include "CEntity.h"
using namespace std;
//Список сущностей
vector<CEntity*> CEntity::EntityList;
//Список столкновений
vector<CEntityCol> CEntityCol::EntityColList;
//Определение конструктора столкновения
CEntityCol::CEntityCol(){
    EntityA=NULL;
    EntityB=NULL;
}
//Определение конструктора сущности
CEntity::CEntity(){
    //Поверхность
    Surf_Entity=NULL;
    //Координаты
    X=0;
    Y=0;
    //Размеры
    Width=0;
    Height=0;
    //Флаги движения
    MoveLeft=false;
    MoveRight=false;
    //Тип
    Type=ENTITY_TYPE_GENERIC;
    //Параметры
    Dead=false;
    Flags=ENTITY_FLAG_GRAVITY;
    //Параметры движения
    SpeedX=0;
    SpeedY=0;
    AccelX=0;
    AccelY=0;
    MaxSpeedX=5;
    MaxSpeedY=5;
    //Параметры анимации
    CurrentFrameCol=0;
    CurrentFrameRow=0;
    Col_X=0;
    Col_Y=0;
    Col_Width=0;
    Col_Height=0;
}
CEntity::~CEntity(){

}
//Определение загрузчика изображения сущности
bool CEntity::OnLoad(const char* File, SDL_Surface* Surf_Display, int Width, int Height, int MaxFrames){
    if((Surf_Entity=CSurface::OnLoad(File, Surf_Display))==NULL){
        return false;
    }
    this->Width=Width;
    this->Height=Height;
    Anim_Control.MaxFrames=MaxFrames;
    return true;
}
//Определение логики сущности
void CEntity::OnLoop(){
    //Остановка движения
    if(MoveLeft==false && MoveRight==false){
        StopMove();
    }
    if(MoveLeft){
        AccelX=-0.5;
    }else if(MoveRight){
        AccelX= 0.5;
    }
    if(Flags & ENTITY_FLAG_GRAVITY){
        AccelY=0.75f;
    }
    SpeedX+=AccelX * CFPS::FPSControl.GetSpeedFactor();
    SpeedY+=AccelY * CFPS::FPSControl.GetSpeedFactor();
    if(SpeedX > MaxSpeedX)  SpeedX=MaxSpeedX;
    if(SpeedX < -MaxSpeedX) SpeedX=-MaxSpeedX;
    if(SpeedY > MaxSpeedY)  SpeedY=MaxSpeedY;
    if(SpeedY < -MaxSpeedY) SpeedY=-MaxSpeedY;
    //Расчет анимации
    OnAnimate();
    //Расчет движения
    OnMove(SpeedX, SpeedY);
}
//Отрисовка текущего кадра анимации в координаты сущности
void CEntity::OnRender(SDL_Surface* Surf_Display){
    if(Surf_Entity==NULL || Surf_Display==NULL){
        return;
    }
    // * - умножение
    CSurface::OnDraw(Surf_Display, Surf_Entity,
        X - CCamera::CameraControl.GetX(),
        Y - CCamera::CameraControl.GetY(),
        CurrentFrameCol * Width,
        (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height,
        Width, Height);
}
//Очистка памяти поверхности сущности
void CEntity::OnCleanup(){
    if(Surf_Entity){
        SDL_FreeSurface(Surf_Entity);
    }
    Surf_Entity=NULL;
}
//Расчет анимации
void CEntity::OnAnimate(){
    if(MoveLeft){
        CurrentFrameCol=0;
    }else if(MoveRight){
        CurrentFrameCol=1;
    }
    Anim_Control.OnAnimate();
}
//Расчет столкновения
void CEntity::OnCollision(CEntity* Entity){

}
//Расчет движения
void CEntity::OnMove(float MoveX, float MoveY){
    if(MoveX == 0 && MoveY == 0){
        return;
    }
    double NewX=0;
    double NewY=0;
    //Вычисление движения во времени
    MoveX *= CFPS::FPSControl.GetSpeedFactor();
    MoveY *= CFPS::FPSControl.GetSpeedFactor();
    //Вычисление передвижения за кадр
    if(MoveX != 0){
        if(MoveX >=0)
            NewX = CFPS::FPSControl.GetSpeedFactor();
        else    
            NewX = -CFPS::FPSControl.GetSpeedFactor();
    }
    if(MoveY != 0){
        if(MoveY >=0)
            NewY = CFPS::FPSControl.GetSpeedFactor();
        else    
            NewY = -CFPS::FPSControl.GetSpeedFactor();
    }
    //Проверка столкновений
    while(true){
        //Проверка возможности движения
        if(Flags & ENTITY_FLAG_GHOST){
            PosValid((int)(X+NewX), (int)(Y+NewY));
            X+=NewX;
            Y+=NewY;
        }else{
            if(PosValid((int)(X+NewX), (int)(Y))){
                X+=NewX;
            }else{
                SpeedX=0;
            }
            if(PosValid((int)(X), (int)(Y+NewY))){
                Y+=NewY;
            }else{
                SpeedY=0;
            }
        }
        MoveX+=-NewX;
        MoveY+=-NewY;
        //Проверка окончания движения
        if(NewX > 0 && MoveX <= 0) NewX=0;
        if(NewX < 0 && MoveX >= 0) NewX=0;
        if(NewY > 0 && MoveY <= 0) NewY=0;
        if(NewY < 0 && MoveY >= 0) NewY=0;

        if(MoveX == 0) NewX=0;
        if(MoveY == 0) NewY=0;
        
        if(MoveX == 0 && MoveY == 0) break;
        if(NewX == 0 && NewY == 0) break;
    }
}
//Остановка движения
void CEntity::StopMove(){
    //Замедленная остановка
    if(SpeedX > 0){
        AccelX = -1;
    }
    if(SpeedX < 0){
        AccelX = 1;
    }
    //Полная остановка
    if(SpeedX < 2.0f && SpeedX > -2.0f){
        AccelX=0;
        SpeedX=0;
    }
}
//Проверка столкновения
bool CEntity::Collides(int oX, int oY, int oW, int oH){
    //Стороны хитбоксов сущностей
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;

    int tX=(int)X + Col_X;
    int tY=(int)Y + Col_Y;

    left1=tX;
    left2=oX;
    right1=left1+Width-1-Col_Width;
    right2=oX+oW-1;
    top1=tY;
    top2=oY;
    bottom1=top1+Height-1-Col_Height;
    bottom2=oY+oH-1;
    //Проверка пересечения хитбоксов
    if(bottom1 < top2) return false;
    if(top1 > bottom2) return false;
    if(right1 < left2) return false;
    if(left1 > right2) return false;

    return true;
}
//Проверка возможности движения
bool CEntity::PosValid(int NewX, int NewY){
    bool Return=true;
    //Просмотр тайлов, на которые движется сущность
    int StartX=(NewX+Col_X)/TILE_SIZE;
    int StartY=(NewY+Col_Y)/TILE_SIZE;
    int EndX=((NewX+Col_X)+Width-Col_Width-1)/TILE_SIZE;
    int EndY=((NewY+Col_Y)+Height-Col_Height-1)/TILE_SIZE;
    //Проверка доступности тайлов
    for(int iY=StartY;iY<=EndY;iY++){
        for(int iX=StartX;iX<=EndX;iX++){
            CTile* Tile=CArea::AreaControl.GetTile(iX*TILE_SIZE, iY*TILE_SIZE);
            if(PosValidTile(Tile)==false){
                Return=false;
            }
        }
    }
    //Проверка столкновений с сущностями
    if(Flags & ENTITY_FLAG_MAPONLY){
        //Нет столкновений с сущностями
    }else{
        for(int i=0;i<EntityList.size();i++){
            if(PosValidEntity(EntityList[i], NewX, NewY)==false){
                Return=false;
            }
        }
    }
    return Return;
}
//Проверка возможности движения по тайлу
bool CEntity::PosValidTile(CTile* Tile){
    if(Tile == NULL){
        return true;
    }
    if(Tile->TypeID == TILE_TYPE_BLOCK){
        return false;
    }
    return true;
}
//Проверка столкновения сущностей
bool CEntity::PosValidEntity(CEntity* Entity, int NewX, int NewY){
    if(this != Entity && //Если они не одно и то же
        Entity != NULL && //Если существует с чем сталкиваться
        Entity->Dead == false && //Если оно не мертво
        Entity->Flags ^ ENTITY_FLAG_MAPONLY && //Если может столкнуться
        Entity->Collides(NewX + Col_X, //Если хитбоксы перекрываются
            NewY + Col_Y,
            Width - Col_Width - 1,
            Height - Col_Height - 1
        ) == true){
        CEntityCol EntityCol; //То это столкновение
        EntityCol.EntityA = this;
        EntityCol.EntityB = Entity;
        //Регистрация столкновения
        CEntityCol::EntityColList.push_back(EntityCol);
        return false;
    }
    return true;
}