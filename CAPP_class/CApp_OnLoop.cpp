#include "CApp.h"
void CApp::OnLoop(){
    //Обработка всех сущностей
    for(int i=0;i<CEntity::EntityList.size();i++){
        if(!CEntity::EntityList[i]){
            continue;
        }
        CEntity::EntityList[i]->OnLoop();
    }
    //Обработка всех столкновений
    for(int i=0;i<CEntityCol::EntityColList.size();i++){
        CEntity* EntityA=CEntityCol::EntityColList[i].EntityA;
        CEntity* EntityB=CEntityCol::EntityColList[i].EntityB;
        if(EntityA==NULL || EntityB==NULL){
            continue;
        }
        //Обработка столкновения А с Б, и Б с А
        if(EntityA->OnCollision(EntityB)){
            EntityB->OnCollision(EntityA);
        }
    }
    CEntityCol::EntityColList.clear();
}