#ifndef _CENTITY_H_
    #define _CENTITY_H_
#include <vector>
using namespace std;
#include "../CMAP_class/CArea.h"
#include "../CANIM_class/CAnimation.h"
#include "../CANIM_class/CCamera.h"
#include "../CANIM_class/CFPS.h"
#include "../CANIM_class/CSurface.h"
//Тип
enum{
    ENTITY_TYPE_GENERIC=0,
    ENTITY_TYPE_PLLAYER
};
//Свойства
enum{
    ENTITY_FLAG_NONE=0,

    ENTITY_FLAG_GRAVITY=0x00000001,
    ENTITY_FLAG_GHOST  =0x00000002,
    ENTITY_FLAG_MAPONLY=0x00000004
};
//Класс Сущность
class CEntity{
    public:
        //Список сущностей
        static vector<CEntity*> EntityList;
    protected:
        //Параметры анимации сущности
        CAnimation Anim_Control;
        //Поверхность сущности
        SDL_Surface* Surf_Entity;
    public:
        //Параметры сущности
        float X;
        float Y;
        int Width;
        int Height;
        //Флаги движения
        bool MoveLeft;
        bool MoveRight;
    public:
        //Тип сущности
        int Type;
        //Статус сущности
        bool Dead;
        //Свойства сущности
        int Flags;
    protected:
        //Переменные движения сущности
        float SpeedX;
        float SpeedY;
        float AccelX;
        float AccelY;
    public:
        float MaxSpeedX;
        float MaxSpeedY;
    protected:
        //Текущий тип анимации
        int CurrentFrameCol;
        //Текущий кадр анимации
        int CurrentFrameRow;
    protected:
        //Хитбокс сущности
        int Col_X;
        int Col_Y;
        int Col_Width;
        int Col_Height;
    public:
        //Конструктор сущности
        CEntity();
        virtual ~CEntity();
    public:
        //Загрузка изображения сущности
        virtual bool OnLoad(const char* File, SDL_Surface* Surf_Display, int Width, int Height, int MaxFrames);
        //Логика сущности
        virtual void OnLoop();
        //Отррисовка поверхности сущности на другую поверхность
        virtual void OnRender(SDL_Surface* Surf_Display);
        //Очистка памяти
        virtual void OnCleanup();
        //Опредилитель анимации
        virtual void OnAnimate();
        //Событие столкновения
        virtual void OnCollision(CEntity* Entity);
    public:
        //Передвижение сущности
        void OnMove(float MoveX, float MoveY);
        void StopMove();
    public:
        //Определитель столкновения
        bool Collides(int oX, int oY, int oW, int oH);
    private:
        //Определители возможности движения
        bool PosValid(int NewX, int NewY);
        bool PosValidTile(CTile* Tile);
        bool PosValidEntity(CEntity* Entity, int NewX, int NewY);
};
//Класс Столкновение
class CEntityCol{
    public:
        //Список событий столкновения
        static vector<CEntityCol> EntityColList;
    public:
        CEntity* EntityA;
        CEntity* EntityB;
    public:
        CEntityCol();
};
#endif