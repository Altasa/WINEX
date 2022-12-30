//Подключение всех компонентов
//Подключение класса Приложение
#include "CAPP_class/CApp.h"
#include "CAPP_class/CApp_OnInit.cpp"
#include "CAPP_class/CApp_OnEvent.cpp"
#include "CAPP_class/CApp_OnLoop.cpp"
#include "CAPP_class/CApp_OnRender.cpp"
#include "CAPP_class/CApp_OnCleanup.cpp"
//Подключение класса Поверхность
#include "CSurface.h"
#include "CSurface.cpp"
//Подключение класса Анимация
#include "CAnimation.h"
#include "CAnimation.cpp"
//Подключение класса Событие
#include "CEvent.h"
#include "CEvent.cpp"
//Подключение класса Сущность
#include "CEntity.h"
#include "CEntity.cpp"
//Подключение класса Площадь
#include "CMAP_class/CArea.h"
#include "CMAP_class/CArea.cpp"
#include "CMAP_class/CMap.h"
#include "CMAP_class/CMap.cpp"
#include "CMAP_class/CTile.h"
#include "CMAP_class/CTile.cpp"
//Подключение класса Камера
#include "CCamera.h"
#include "CCamera.cpp"
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
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
        SDL_Delay(40);//25fps window
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