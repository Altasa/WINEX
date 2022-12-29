#include "CApp.h"
void CApp::OnCleanup(){
    SDL_DestroyWindow(Window);
    SDL_FreeSurface(Surf_Display);
    Window=NULL;
    Surf_Display=NULL;
    //Очистка памяти всех сущностей
    for(int i=0;i<CEntity::EntityList.size();i++){
        if(!CEntity::EntityList[i]){
            continue;
        }
        CEntity::EntityList[i]->OnCleanup();
    }
    CEntity::EntityList.clear();
    SDL_Quit();
}