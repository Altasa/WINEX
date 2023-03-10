#include "CCamera.h"
//Статический объект контроля камеры
CCamera CCamera::CameraControl;
//Определение конструктора камеры
CCamera::CCamera(){
    X=Y=0;
    TargetX=TargetY=NULL;
    CorrectX=CorrectY=0;
    TargetMode=TARGET_MODE_NORMAL;
}
//Изменение координат камеры
void CCamera::OnMove(int MoveX, int MoveY){
    X+=MoveX;
    Y+=MoveY;
}
//Наведение по горизонтали
int CCamera::GetX(){
    if(TargetX!=NULL){
        if(TargetMode==TARGET_MODE_CENTER){
            return *TargetX - (WWIDTH/2);
        }
        return *TargetX;
    }
    return X;
}
//Наведение по вертикали
int CCamera::GetY(){
    if(TargetY != NULL){
        if(TargetMode == TARGET_MODE_CENTER){
            return *TargetY - (WHEIGHT/2);
        }
        return *TargetY;
    }
    return Y;
}
void CCamera::SetPos(int X, int Y){
    this->X=X;
    this->Y=Y;
}
//Установка камеры на цель с поправками центровки
void CCamera::SetTarget(float* X, float* Y, float CorrX, float CorrY){
    TargetX=X;
    TargetY=Y;
    CorrectX=CorrX;
    CorrectY=CorrY;
}