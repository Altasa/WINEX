#ifndef _CAPP_H_
    #define _CAPP_H_
#include <SDL.h>
//Установки параметров приложения
#include "../Define.h"
//Подключение класса Поверхность
#include "../CSurface.h"
//Подключение класса Анимация
#include "../CAnimation.h"
//Подключение класса Событие
#include "../CEvent.h"
//Подключение класса Сущность
#include "../CEntity.h"
//Подключение класса Площадь
#include "../CMAP_class/CArea.h"
//Подключение класса Камера
#include "../CCamera.h"
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
        //Поверхность фона
        SDL_Surface* Surf_Bkg;
        //Сущности приложения
        CEntity Entity1;
        CEntity Entity2;
        
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
    //Методы приложения
        //Нажатие клавиши клавиатуры
        void OnKeyDown(SDL_Keycode sym, Uint16 unicode);
};
#endif