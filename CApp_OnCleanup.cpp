#include "CApp.h"
void CApp::OnCleanup(){
    SDL_DestroyWindow(Window);
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_Grid);
    SDL_FreeSurface(Surf_XO);
    Window=NULL;
    Surf_Display=NULL;
    Surf_Grid=NULL;
    Surf_XO=NULL;
    SDL_Quit();
}