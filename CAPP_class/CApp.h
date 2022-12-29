#ifndef _CAPP_H_
    #define _CAPP_H_
#include <SDL.h>
//Подключение класса Поверхность
#include "../CSurface.h"
//Подключение класса Анимация
#include "../CAnimation.h"
//Подключение класса Событие
#include "../CEvent.h"
//Подключение класса Сущность
#include "../CEntity.h"
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
        //Сущности приложения
        CEntity Entity1;
        CEntity Entity2;
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
        //Обработчики событий
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