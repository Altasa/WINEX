#include "CApp.h"
void CApp::OnLoop(){
    //Обработка всех сущностей
    for(int i=0;i<CEntity::EntityList.size();i++){
        if(!CEntity::EntityList[i]){
            continue;
        }
        CEntity::EntityList[i]->OnLoop();
    }
}