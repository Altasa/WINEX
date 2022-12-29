#ifndef _CENTITY_H_
    #define _CENTITY_H_
#include <vector>
using namespace std;
#include "CAnimation.h"
#include "CSurface.h"
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
        int AnimState;
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
};
#endif