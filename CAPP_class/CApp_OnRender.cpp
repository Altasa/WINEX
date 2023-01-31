#include "CApp.h"
void CApp::OnRender(){
    //Отрисовка фона
    CSurface::OnDraw(Surf_Display, Surf_Bkg, 0, 0);
    //Отрисовка площади с поправкой на центровку цели
    CArea::AreaControl.OnRender(Surf_Display,
        -CCamera::CameraControl.GetX()-CCamera::CameraControl.CorrectX,
        -CCamera::CameraControl.GetY()-CCamera::CameraControl.CorrectY
    );
    //Отрисовка всех сущностей
    for(int i=0;i<CEntity::EntityList.size();i++){
        if(!CEntity::EntityList[i]){
            continue;
        }
        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
    SDL_UpdateWindowSurface(Window);
}