#include "CApp.h"
//Определение обработчика событий
void CApp::OnEvent(SDL_Event* Event){
    CEvent::OnEvent(Event);
}
//Событие закрытия окна
void CApp::OnExit(){
    Running=false;
}