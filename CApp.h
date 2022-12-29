#ifndef _CAPP_H_
    #define _CAPP_H_
#include <SDL.h>
//Подключение класса Поверхность
#include "CSurface.h"
//Подключение класса Анимация
#include "CAnimation.h"
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
        SDL_Surface* Surf_Grid;
        SDL_Surface* Surf_XO;
        SDL_Surface* Surf_Yoshi;
        //Данные приложения
        CAnimation Anim_Yoshi;//Анимация
        int CurrentPlayer;//ИД игрока
        int Grid[9];//Массив ячеек
        enum{//Статусы ячеек
            GRID_TYPE_NONE=0,
            GRID_TYPE_X,
            GRID_TYPE_O
        };
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
        void OnLButtonDown(int mX, int mY);
        //Инициатор завершения работы
        void OnExit();
        //Обработчик логики
        void OnLoop();
        //Отрисовщик
        void OnRender();
        //Освобождение памяти
        void OnCleanup();
    //Методы приложения
    public:
        //Обнуление массива ячеек
        void Reset();
        //Установка статуса ячейки
        void SetCell(int ID, int Type);
};
#endif