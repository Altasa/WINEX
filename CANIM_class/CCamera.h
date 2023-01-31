#ifndef _CCAMERA_H_
    #define _CCAMERA_H_
#include <SDL.h>
#include "../Define.h"
enum{
    TARGET_MODE_NORMAL=0,
    TARGET_MODE_CENTER
};
class CCamera{
    public:
        //Контроль камеры
        static CCamera CameraControl;
    private:
        //Координаты камеры на площади карт
        int X;
        int Y;
        //Координаты цели камеры
        float* TargetX;
        float* TargetY;
    public:
        //Поправки центровки камеры
        float CorrectX;
        float CorrectY;
    public:
        //Режим нацеливания камеры
        int TargetMode;
    public:
        //Конструктор камеры
        CCamera();
    public:
        //Перемещение камеры
        void OnMove(int MoveX, int MoveY);
    public:
        //Нацеливание камеры
        int GetX();
        int GetY();
    public:
        //Установка координат камеры и цели
        void SetPos(int X, int Y);
        //Установка камеры на цель с поправками центровки
        void SetTarget(float* X, float* Y, float CorrX, float CorrY);
};
#endif