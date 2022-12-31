#include "CApp.h"
//Определение обработчика событий
void CApp::OnEvent(SDL_Event* Event){
    CEvent::OnEvent(Event);
}
//Событие закрытия окна
void CApp::OnExit(){
    Running=false;
}
//Нажатие клавиши клавиатуры
void CApp::OnKeyDown(SDL_Keycode sym, Uint16 unicode){
    switch(sym){
        case SDLK_LEFT:
            Player1.MoveLeft = true;
            break;
        case SDLK_RIGHT:
            Player1.MoveRight = true;
            break;
        case SDLK_SPACE:
            Player1.Jump();
            break;
        default:{
            
        }
    }
}
//Отпускание клавиши клавиатуры
void CApp::OnKeyUp(SDL_Keycode sym, Uint16 unicode){
    switch(sym){
        case SDLK_LEFT:
            Player1.MoveLeft = false;
            break;
        case SDLK_RIGHT:
            Player1.MoveRight = false;
            break;
        default:{
            
        }
    }
}