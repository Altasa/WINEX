#ifndef _CFPS_H_
    #define _CFPS_H_
#include <SDL.h>
//Класс контроля кадров
class CFPS{
    public:
        //Контроль скорости
        static CFPS FPSControl;
    private:
        //Переменные контроля скорости отображения
        int OldTime;
        int LastTime;
        float SpeedFactor;
        int NumFrames;
        int Frames;
    public:
        //Конструктор
        CFPS();
        //Вычисление скоростей отображения
        void OnLoop();
    public:
        int GetFPS();
        float GetSpeedFactor();
};
#endif