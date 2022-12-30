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
        int FrameRate; //milliseconds
        long OldTime; //Время кадра
    public:
        //Всего кадров, на 1 меньше чем факт
        int MaxFrames;
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