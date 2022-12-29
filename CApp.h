#ifndef _CAPP_H_
    #define _CAPP_H_
#include <SDL.h>
//Подключение класса Поверхность
#include "CSurface.h"
//Подключение класса Событие
#include "CEvent.h"
//Класс Приложение
class CApp : public CEvent{
    //Поля класса
    private:
        //Флаг выполнения исполнителя процесса
        bool Running;
        //Окно приложения
        SDL_Window* Window;
        //Поверхность окна
        SDL_Surface* Surf_Display;
        //Поверхности приложения
        SDL_Surface* Surf_Test;
        //Размер окна ширина высота
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT; 
        
    //Методы класса
    public:
        //Конструктор
        CApp();
        //Исполнитель процесса
        int OnExecute();
    //Методы исполнителя процесса
    public:
        //Инициализация
        bool OnInit();
        //Обработчик события
        void OnEvent(SDL_Event* Event);
        //Инициатор завершения работы
        void OnExit();
        //Обработчик логики
        void OnLoop();
        //Отрисовщик
        void OnRender();
        //Освобождение памяти
        void OnCleanup();
};
#endif