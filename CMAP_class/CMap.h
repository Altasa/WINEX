#ifndef _CMAP_H_
    #define _CMAP_H_
#include <SDL.h>
#include <vector>
using namespace std;
//Подключение классов Тайл, Поверхность
#include "CTile.h"
#include "../CSurface.h"
//Класс Карта
class CMap{
    public:
        //Поверхность тайлов карты
        SDL_Surface* Surf_Tileset;
    private:
        //Список тайлов карты
        vector<CTile> TileList;
    public:
        //Конструктор карты
        CMap();
    public:
        //Загрузка разметки карты
        bool OnLoad(const char* File);
        //Отрисовка карты
        void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);
};
#endif