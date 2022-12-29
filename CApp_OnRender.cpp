#include "CApp.h"
void CApp::OnRender(){
    CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
    SDL_UpdateWindowSurface(Window);
}