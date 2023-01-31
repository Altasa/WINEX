#ifndef _CANIMATION_H_
    #define _CANIMATION_H_
#include <SDL.h>
//Класс Анимация
class CAnimation{
    //Параметры анимации
    private:
        int CurrentFrame; //Номер текущего кадра
        int FrameInc; //Направляющий
    private:
        long OldTime; //Время кадра
    public:
        int FrameRate; //milliseconds
        //Всего кадров текущей анимации, на 1 меньше чем факт
        int MaxFrames;
        //Всего кадров анимации сущности, на 1 меньше чем факт
        int GlobalMaxFrames;
        //Параметр двунаправленной анимации
        bool Oscillate;
    public:
        //Конструктор параметров анимации
        CAnimation();
        //Расчет текущего кадра
        void OnAnimate();
    public:
        void SetFrameRate(int Rate);
        void SetCurrentFrame(int Frame);
        int GetCurrentFrame();
};
#endif