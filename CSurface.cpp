#include "CSurface.h"
//Определение конструктора
CSurface::CSurface(){

}
//Определение Инициализации библиотеки SDL2_image
bool CSurface::ImgInit(){
    //Выбоор модуля загрузки изображения PNG
    int flags=IMG_INIT_PNG;
    if(!(IMG_Init(flags)&flags)){
        return false;
    }
    return true;
}
//Определение загрузчика изображения PNG
SDL_Surface* CSurface::OnLoad(const char* File, SDL_Surface* Surf_Display){
    SDL_Surface* Surf_Temp=NULL;
    //Загрузка изображения PNG
    Surf_Temp=IMG_Load(File);
    if(Surf_Temp==NULL){
        return NULL;
    }
    //Приведение поверхности к формату окна
    Surf_Temp=SDL_ConvertSurface(Surf_Temp, Surf_Display->format, 0);
    return Surf_Temp;
}
//Определение отображения поверхности
bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if(Surf_Dest==NULL || Surf_Src==NULL)
        return false;
    SDL_Rect DestR;
    DestR.x=X;
    DestR.y=Y;
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
    return true;
}
//Определение отображения части поверхности
bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H){
    if(Surf_Dest==NULL || Surf_Src==NULL)
        return false;
    SDL_Rect DestR;
    DestR.x=X;
    DestR.y=Y;
    SDL_Rect SrcR;
    SrcR.x=X2;
    SrcR.y=Y2;
    SrcR.w=W;
    SrcR.h=H;
    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);
    return true;
}