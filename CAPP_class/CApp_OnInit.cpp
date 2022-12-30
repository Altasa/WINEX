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
        WWIDTH,
        WHEIGHT,
        SDL_WINDOW_SHOWN
    );
    if(Window==NULL){
        return false;
    }
    //Получение поверхности окна
    Surf_Display=SDL_GetWindowSurface(Window);
    //Загрузка поверхностей изображений
    if((Surf_Bkg=CSurface::OnLoad("PNG_imgs/img1.png", Surf_Display)) == NULL){
        return false;
    }
    if(Player1.OnLoad("PNG_imgs/yoshi.png", Surf_Display, 64, 64, 7)==false){
        return false;
    }
    if(Player2.OnLoad("PNG_imgs/yoshi.png", Surf_Display, 64, 64, 7)==false){
        return false;
    }
    //Установка координат сущностей, по умолчанию 0, 0
    Player1.X=100;
    //Запись сущностей в список
    CEntity::EntityList.push_back(&Player1);
    CEntity::EntityList.push_back(&Player2);
    //Установка камеры на первого игрока
    CCamera::CameraControl.TargetMode=TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player1.X, &Player1.Y);
    //Загрузка площади
    if(CArea::AreaControl.OnLoad("maps/1.area", Surf_Display)==false){
        return false;
    }
    return true;
}