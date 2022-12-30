#ifndef _CSURFACE_H_
    #define _CSURFACE_H_
#include <SDL.h>
#include <SDL_image.h>
//Класс Поверхность
class CSurface{
    //Методы класса
    public:
        //Конструктор
        CSurface();
    public:
        //Инициализация библиотеки SDL2_image
        static bool ImgInit();
        //Загрузчик изображения PNG
        static SDL_Surface* OnLoad(const char* File, SDL_Surface* Surf_Display);
        //Отображение поверхности
        static bool OnDraw(SDL_Surface* Surd_Dest, SDL_Surface* Surf_Src, int X, int Y);
        //Отображение части поверхности
        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);
};
#endif