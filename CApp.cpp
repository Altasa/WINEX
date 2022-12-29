//Подключение всех компонентов
//Подключение класса Приложение
#include "CApp.h"
#include "CApp_OnInit.cpp"
#include "CApp_OnEvent.cpp"
#include "CApp_OnLoop.cpp"
#include "CApp_OnRender.cpp"
#include "CApp_OnCleanup.cpp"
//Подключение класса Поверхность
#include "CSurface.h"
#include "CSurface.cpp"
//Подключение класса Событие
#include "CEvent.h"
#include "CEvent.cpp"
//Определение конструктора
CApp::CApp(){
    //Флаг выполнения исполнителя процесса
    Running=true;
    //Окно приложения
    Window=NULL;
    //Поверхность окна
    Surf_Display=NULL;
    //Поверхности приложения
    Surf_Grid=NULL;
    Surf_XO=NULL;
    //Данные приложения
    CurrentPlayer=0;
    //Размер окна ширина высота
    SCREEN_WIDTH=300;
    SCREEN_HEIGHT=300; 
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
//Обнуление массива ячеек
void CApp::Reset(){
    for(int i=0;i<9;i++){
        Grid[i]=GRID_TYPE_NONE;
    }
}
//Установка статуса ячейки
void CApp::SetCell(int ID, int Type){
    if(ID<0 || ID>=9){
        return;
    }
    if(Type<0 || Type> GRID_TYPE_O){
        return;
    }
    Grid[ID]=Type;
}
//Задание точки входа
int main(int argc, char* argv[]){
    //Создание экземпляра приложения
    CApp theApp;
    //Вызов экземпляра приложения
    return theApp.OnExecute();
}