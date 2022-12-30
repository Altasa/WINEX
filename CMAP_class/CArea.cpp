#include "CArea.h"
//Определение объекта контроля площади
CArea CArea::AreaControl;
//Определение конструктора площади
CArea::CArea(){
    AreaSize=0;
}
//Определение функции загрузки площади карт
bool CArea::OnLoad(const char* File, SDL_Surface* Surf_Display){
    //Очистка списка карт
    MapList.clear();
    //Открытие файла площади
    FILE* FileHandle=fopen(File, "r");
    if(FileHandle==NULL){
        return false;
    }
    //Загрузка тайлсета
    char TileSetFile[255];
    fscanf(FileHandle, "%s\n", TileSetFile);
    if((Surf_Tileset=CSurface::OnLoad(TileSetFile, Surf_Display))==NULL){
        fclose(FileHandle);
        return false;
    }
    //Считывание размера площади
    fscanf(FileHandle, "%d\n", &AreaSize);
    //Просмотр файла площади
    for(int X=0;X<AreaSize;X++){
        for(int Y=0;Y<AreaSize;Y++){
            //Считывание адреса карты
            char MapFile[255];
            fscanf(FileHandle, "%s", MapFile);
            //Загрузка карты
            CMap tempMap;
            if(tempMap.OnLoad(MapFile)==false){
                fclose(FileHandle);
                return false;
            }
            //Запись карты в список карт
            tempMap.Surf_Tileset=Surf_Tileset;
            MapList.push_back(tempMap);
        }
        //Переход к следующей строке карт
        fscanf(FileHandle, "\n");
    }
    //Закрытие файла площади
    fclose(FileHandle);
    return true;
}
//Отрисовка площади
void CArea::OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY){
    //Вычисление размера карт в пикселях
    int MapWidth=MAP_WIDTH*TILE_SIZE;
    int MapHeight=MAP_HEIGHT*TILE_SIZE;
    //Нахождение номера первой отрисовываемой карты
    int FirstID=-CameraX/MapWidth;
    FirstID=FirstID+((-CameraY/MapHeight)*AreaSize);
    //Отрисовка 4 карт
    for(int i=0;i<4;i++){
        //Номер текущей отрисовываемой из 4 карт
        int ID=FirstID+((i/2)*AreaSize)+(i%2);
        if(ID<0 || ID>=MapList.size()){
            continue;
        }
        //Вычисление координат отрисовываемой карты на экране
        int X=((ID % AreaSize)*MapWidth)+CameraX;
        int Y=((ID / AreaSize)*MapHeight)+CameraY;
        //Отрисовка карты
        MapList[ID].OnRender(Surf_Display, X, Y);
    }
}
//Очистка карт
void CArea::OnCleanup(){
    if(Surf_Tileset){
        SDL_FreeSurface(Surf_Tileset);
        Surf_Tileset=NULL;
    }
    MapList.clear();
}