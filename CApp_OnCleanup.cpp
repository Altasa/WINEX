#include "CApp.h"
void CApp::OnCleanup(){
    SDL_DestroyWindow(Window);
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_Test);
    Window=NULL;
    Surf_Display=NULL;
    Surf_Test=NULL;
    SDL_Quit();
}