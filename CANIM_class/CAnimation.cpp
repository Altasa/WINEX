#include "CAnimation.h"
//Определение конструктора параметров анимации
CAnimation::CAnimation(){
    //Текущий кадр
    CurrentFrame= -1;
    //Всего кадров, на 1 меньше чем факт
    MaxFrames=    0;
    //Направление кадров
    FrameInc=     1;
    //Частота кадров
    //milliseconds,fps 40=25 100=10
    FrameRate=    100;
    OldTime=      0;
    //Параметр двунаправленной анимации
    Oscillate=    false;
}
//Расчет текущего кадра
void CAnimation::OnAnimate(){
    //Проверка прошедшего времени
    if(OldTime+FrameRate>SDL_GetTicks64()){
        return;
    }
    //Обновление прошедшего времени
    OldTime=SDL_GetTicks64();
    //Вычисление следующего кадра
    CurrentFrame+=FrameInc;
    //Проверка цикла кадров
    if(Oscillate){
        //Поворот двунаправленной анимации
        if(FrameInc>0){
            if(CurrentFrame>=MaxFrames){
                FrameInc=-FrameInc;
            }
        }else{
            if(CurrentFrame<=0){
                FrameInc=-FrameInc;
            }
        }
    }else{
        //Возврат однонаправленной анимации
        if(CurrentFrame>MaxFrames){
            CurrentFrame=0;
        }
    }
}
//Установка частоты кадров
void CAnimation::SetFrameRate(int Rate){
    FrameRate=Rate;
}
//Установка текущего кадра
void CAnimation::SetCurrentFrame(int Frame){
    if(Frame<0 || Frame>=MaxFrames){
        return;
    }
    CurrentFrame=Frame;
}
//Получение номера текущего кадра
int CAnimation::GetCurrentFrame(){
    return CurrentFrame;
}