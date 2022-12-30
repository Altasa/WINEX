#include "CMap.h"
#include <cstdio>
//Конструктор карты
CMap::CMap(){
    Surf_Tileset=NULL;
}
//Загрузка разметки карты
bool CMap::OnLoad(const char* File){
    //Предварительная очистка карты
    TileList.clear();
    //Открытие файла карты
    FILE* FileHandle=fopen(File, "r");
    if(FileHandle==NULL){
        return false;
    }
    //Просмотр карты, создание списка тайлов
    for(int Y=0;Y<MAP_HEIGHT;Y++){
        for(int X=0;X<MAP_WIDTH;X++){
            CTile tempTile;
            fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);
            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }
    //Закрытие файла карты
    fclose(FileHandle);
    return true;
}
//Отрисовка карты
void CMap::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY){
    if(Surf_Tileset==NULL){
        return;
    }
    //Установка параметров тайлсета
    int TilesetWidth =Surf_Tileset->w/TILE_SIZE;
    int TilesetHeight=Surf_Tileset->h/TILE_SIZE;
    //Просмотр и отрисовка списка тайлов карты
    int ID=0;
    for(int Y=0;Y<MAP_HEIGHT;Y++){
        for(int X=0;X<MAP_WIDTH;X++){
            //Пропуск пустых тайлов
            if(TileList[ID].TypeID==TILE_TYPE_NONE){
                ID++;
                continue;
            }
            //Вычисление координат тайла на экране относительно карты
            int tX=MapX+(X*TILE_SIZE);
            int tY=MapY+(Y*TILE_SIZE);
            //Вычисление положения тайла в тайлсете
            int TilesetX=(TileList[ID].TileID % TilesetWidth) * TILE_SIZE;
            int TilesetY=(TileList[ID].TileID / TilesetHeight) * TILE_SIZE;
            //Отрисовка тайла на экран
            CSurface::OnDraw(Surf_Display, Surf_Tileset, tX, tY, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);
            //Переход к следующему тайлу
            ID++;
        }
    }
}
//Вычислить адрес тайла в карте
CTile* CMap::GetTile(int X, int Y){
    int ID=0;
    ID=X/TILE_SIZE;
    ID=ID+(MAP_WIDTH * (Y/TILE_SIZE));
    if(ID<0 || ID>=TileList.size()){
        return NULL;
    }
    return &TileList[ID];
}