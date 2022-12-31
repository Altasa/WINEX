#include "CEntity.h"
using namespace std;
//Список столкновений
vector<CEntityCol> CEntityCol::EntityColList;
//Определение конструктора столкновения
CEntityCol::CEntityCol(){
    this->EntityA=NULL;
    this->EntityB=NULL;
}
