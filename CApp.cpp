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
//Определение конструктора приложения
CApp::CApp(){
    //Флаг выполнения исполнителя процесса
    Running=true;
    //Окно приложения
    Window=NULL;
    //Поверхность окна
    Surf_Display=NULL;
    //Размер окна ширина высота
    SCREEN_WIDTH=320;
    SCREEN_HEIGHT=320; 
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