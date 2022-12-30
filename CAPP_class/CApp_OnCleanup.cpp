#include "CApp.h"
void CApp::OnCleanup(){
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_Bkg);
    SDL_DestroyWindow(Window);
    Window=NULL;
    Surf_Display=NULL;
    Surf_Bkg=NULL;
    //Очистка памяти всех сущностей
    for(int i=0;i<CEntity::EntityList.size();i++){
        if(!CEntity::EntityList[i]){
            continue;
        }
        CEntity::EntityList[i]->OnCleanup();
    }
    CEntity::EntityList.clear();
    //Очистка памяти площади
    CArea::AreaControl.OnCleanup();
    SDL_Quit();
}