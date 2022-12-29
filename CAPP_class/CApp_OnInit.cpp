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
    if(Entity1.OnLoad("PNG_Imgs/entity1.png", Surf_Display, 64, 64, 7)==false){
        return false;
    }
    if(Entity2.OnLoad("PNG_Imgs/entity2.png", Surf_Display, 64, 64, 7)==false){
        return false;
    }
    //Установка координат сущностей, по умолчанию 0, 0
    Entity2.X=100;
    //Запись сущностей в список
    CEntity::EntityList.push_back(&Entity1);
    CEntity::EntityList.push_back(&Entity2);
    return true;
}