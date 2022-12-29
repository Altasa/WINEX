#include "CApp.h"
void CApp::OnRender(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            CSurface::OnDraw(Surf_Display, Surf_Grid, i*100, j*100);
            switch(int(Grid[i+j*3])){
                case int(GRID_TYPE_X):
                    CSurface::OnDraw(Surf_Display, Surf_XO, i*100, j*100, 0, 0, 100, 100);
                    break;
                case int(GRID_TYPE_O):
                    CSurface::OnDraw(Surf_Display, Surf_XO, i*100, j*100, 100, 0, 100, 100);
                    break;
            }
        }
    CSurface::OnDraw(Surf_Display, Surf_Yoshi, 0, 300, Anim_Yoshi.GetCurrentFrame()*64, 0, 64, 64);
    SDL_UpdateWindowSurface(Window);
}