#include "CAnimation.h"
CAnimation::CAnimation(){
    CurrentFrame= -1;
    MaxFrames=    0;
    FrameInc=     1;

    //milliseconds,fps 40=25 100=10
    FrameRate=    100;
    OldTime=      0;
    
    Oscillate=    false;
}
void CAnimation::OnAnimate(){
    if(OldTime+FrameRate>SDL_GetTicks64()){
        return;
    }
    OldTime=SDL_GetTicks64();
    CurrentFrame+=FrameInc;
    if(Oscillate){
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
        if(CurrentFrame>MaxFrames){
            CurrentFrame=0;
        }
    }
}
void CAnimation::SetFrameRate(int Rate){
    FrameRate=Rate;
}
void CAnimation::SetCurrentFrame(int Frame){
    if(Frame<0 || Frame>=MaxFrames){
        return;
    }
    CurrentFrame=Frame;
}
int CAnimation::GetCurrentFrame(){
    return CurrentFrame;
}