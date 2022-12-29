#include "CEntity.h"
//Список сущностей
vector<CEntity*> CEntity::EntityList;
//Определение конструктора сущности
CEntity::CEntity(){
    //Поверхность
    Surf_Entity=NULL;
    //Координаты
    X=Y=0.0f;
    //Размеры
    Width=Height=0;
    //Номер анимации в тулсете
    AnimState=0;
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
    //Расчет кадров анимации
    Anim_Control.OnAnimate();
}
//Отрисовка текущего кадра анимации в координаты сущности
void CEntity::OnRender(SDL_Surface* Surf_Display){
    if(Surf_Entity==NULL || Surf_Display==NULL){
        return;
    }
    // * - умножение
    CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, AnimState * Width, Anim_Control.GetCurrentFrame() * Height, Width, Height);
}
//Очистка памяти поверхности сущности
void CEntity::OnCleanup(){
    if(Surf_Entity){
        SDL_FreeSurface(Surf_Entity);
    }
    Surf_Entity=NULL;
}