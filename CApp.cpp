//Подключение класса Приложение
#include "CApp.h"
#include "CApp_OnInit.cpp"
#include "CApp_OnEvent.cpp"
#include "CApp_OnLoop.cpp"
#include "CApp_OnRender.cpp"
#include "CApp_OnCleanup.cpp"
//Определение конструктора
CApp::CApp(){
    //Флаг выполнения исполнителя процесса
    Running=true;
    //Окно приложения
    Window=NULL;
    //Поверхность окна
    Surf_Display=NULL;
    //Поверхности приложения
    Surf_Test=NULL;
    //Размер окна ширина высота
    SCREEN_WIDTH=640;
    SCREEN_HEIGHT=480; 
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