#include "CApp.h"
bool CApp::OnInit(){
    //Подключение компонентов библиотеки SDL2
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        return false;
    }
    //Подключение компонентов библиотеки SDL2_image
    if(CSurface::ImgInit() == false){
        return false;
    }
    //Создание окна приложения
    Window = SDL_CreateWindow(
        "CApp.exe",
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN
    );
    if(Window==NULL){
        return false;
    }
    //Получение поверхности окна
    Surf_Display=SDL_GetWindowSurface(Window);
    //Загрузка поверхностей изображений
    if((Surf_Grid=CSurface::OnLoad("bkg.png", Surf_Display))==NULL){
        return false;
    }
    if((Surf_XO=CSurface::OnLoad("xo.png", Surf_Display))==NULL){
        return false;
    }
    if((Surf_Yoshi=CSurface::OnLoad("yoshi.png", Surf_Display))==NULL){
        return false;
    }
    //Инициализация данных приложения
    Reset();
    Anim_Yoshi.MaxFrames=7;
    Anim_Yoshi.Oscillate=false;
    return true;
}