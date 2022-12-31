#include "CPlayer.h"
CPlayer::CPlayer(){

}
bool CPlayer::OnLoad(const char* File, SDL_Surface* Surf_Display, int Width, int Height, int MaxFrames){
    if(CEntity::OnLoad(File, Surf_Display, Width, Height, MaxFrames)==false){
        return false;
    }
    return true;
}
void CPlayer::OnLoop(){
    CEntity::OnLoop();
}
void CPlayer::OnRender(SDL_Surface* Surf_Display){
    CEntity::OnRender(Surf_Display);
}
void CPlayer::OnCleanup(){
    CEntity::OnCleanup();
}
//Установка анимации на ходьбу и покой
void CPlayer::OnAnimate(){
    if(SpeedX != 0){
        Anim_Control.MaxFrames=7;
    }else{
        Anim_Control.MaxFrames=0;
    }
    CEntity::OnAnimate();
}
//Обработка столкновения
bool CPlayer::OnCollision(CEntity* Entity){
    Jump();
    return true;
}