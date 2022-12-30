//Подключение всех компонентов
#include "Define.h"
//Подключение класса Приложение
#include "CAPP_class/CApp.h"
#include "CAPP_class/CApp_OnInit.cpp"
#include "CAPP_class/CApp_OnEvent.cpp"
#include "CAPP_class/CApp_OnLoop.cpp"
#include "CAPP_class/CApp_OnRender.cpp"
#include "CAPP_class/CApp_OnCleanup.cpp"
//Подключение класса Поверхность
#include "CANIM_class/CSurface.h"
#include "CANIM_class/CSurface.cpp"
//Подключение класса Анимация
#include "CANIM_class/CAnimation.h"
#include "CANIM_class/CAnimation.cpp"
//Подключение класса контроля кадров
#include "CANIM_class/CFPS.h"
#include "CANIM_class/CFPS.cpp"
//Подключение класса Камера
#include "CANIM_class/CCamera.h"
#include "CANIM_class/CCamera.cpp"
//Подключение класса Площадь
#include "CMAP_class/CArea.h"
#include "CMAP_class/CArea.cpp"
#include "CMAP_class/CMap.h"
#include "CMAP_class/CMap.cpp"
#include "CMAP_class/CTile.h"
#include "CMAP_class/CTile.cpp"
//Подключение класса Событие
#include "CEvent.h"
#include "CEvent.cpp"
//Подключение класса Сущность
#include "../CENTITY_class/CEntity.h"
#include "../CENTITY_class/CEntity.cpp"
//Подключение класса Игрок
#include "../CENTITY_class/CPlayer.h"
#include "../CENTITY_class/CPlayer.cpp"
//Определение конструктора приложения
CApp::CApp(){
    //Флаг выполнения исполнителя процесса
    Running=true;
    //Окно приложения
    Window=NULL;
    //Поверхность окна
    Surf_Display=NULL;
    //Поверхность фона
    Surf_Bkg=NULL;
}
//Определение исполнителя процесса
int CApp::OnExecute(){
    //Инициализация
    if(OnInit()==false){
        return -1;
    }
    //Цикл процесса обработки событий
    SDL_Event Event;
    while(Running){
        //Вычисление параметров отрисовки
        CFPS::FPSControl.OnLoop();
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
        SDL_Delay(10);//100 FPS Max
    }
    OnCleanup();
    return 0;
}
//Задание точки входа
int main(int argc, char* argv[]){
    //Создание экземпляра приложения
    CApp theApp;
    //Вызов экземпляра приложения
    return theApp.OnExecute();
}