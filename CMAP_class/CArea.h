#ifndef _CAREA_H_
    #define _CAREA_H_
#include "CMap.h"
using namespace std;
//Класс Площадь
class CArea{
    public:
        //Параметры площади
        static CArea AreaControl;
    public:
        //Список карт площади
        vector<CMap> MapList;
    private:
        //Количество карт в строке квадратной площади
        int AreaSize;
        //Поверхность тайлов площади
        SDL_Surface* Surf_Tileset;
    public:
        //Конструктор площади
        CArea();
        //Загрузчик площади
        bool OnLoad(const char* File, SDL_Surface* Surf_Display);
        //Отрисовщик площади
        void OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
        //Очистка площади
        void OnCleanup();
};
#endif