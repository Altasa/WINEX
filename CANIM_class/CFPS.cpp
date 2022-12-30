#include "CFPS.h"
CFPS CFPS::FPSControl;
//Определение конструктора
CFPS::CFPS(){
    OldTime=0;
    LastTime=0;
    SpeedFactor=0;
    Frames=0;
    NumFrames=0;
}
//Вычисление скоростей отображения
void CFPS::OnLoop(){
    if(OldTime+1000 < SDL_GetTicks64()){
        OldTime=SDL_GetTicks64();
        NumFrames=Frames;
        Frames=0;
    }
    SpeedFactor=((SDL_GetTicks64()-LastTime) / 1000.0f) * 32.0f;
    LastTime=SDL_GetTicks64();
    Frames++;
}
int CFPS::GetFPS(){
    return NumFrames;
}
float CFPS::GetSpeedFactor(){
    return SpeedFactor;
}