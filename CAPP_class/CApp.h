#ifndef _CAPP_H_
    #define _CAPP_H_
#include <SDL.h>
//Установки параметров приложения
#include "../Define.h"
//Подключение класса Поверхность
#include "../CANIM_class/CSurface.h"
//Подключение класса Анимация
#include "../CANIM_class/CAnimation.h"
//Подключение класса Событие
#include "../CEvent.h"
//Подключение класса Сущность
#include "../CENTITY_class/CEntity.h"
//Подключение класса Игрок
#include "../CENTITY_class/CPlayer.h"
//Подключение класса Площадь
#include "../CMAP_class/CArea.h"
//Подключение класса Камера
#include "../CANIM_class/CCamera.h"
//Подключение класса Звук
#include "../CSoundBank.h"
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
        //Игроки
        CPlayer Player1;
        CPlayer Player2;
        //Звуки
        int SoundA;
        int SoundB;
        
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
        //Отпускание клавиши клавиатуры
        void OnKeyUp(SDL_Keycode sym, Uint16 unicode);
};
#endif