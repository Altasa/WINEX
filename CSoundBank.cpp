#include "CSoundBank.h"
CSoundBank CSoundBank::SoundControl;
CSoundBank::CSoundBank(){

}
//Загрузка звука из файла .WAV
int CSoundBank::OnLoad(const char* File){
    Mix_Chunk* TempSound=NULL;
    if((TempSound=Mix_LoadWAV(File))==NULL){
        return -1;
    }
    SoundList.push_back(TempSound);
    //Вернуть номер трека
    return (SoundList.size()-1);
}
//Очистка списка с освобождением памяти
void CSoundBank::OnCleanup(){
    for(int i=0;i<SoundList.size();i++){
        Mix_FreeChunk(SoundList[i]);
    }
    SoundList.clear();
}
void CSoundBank::Play(int ID){
    if((ID<0)||(ID>=SoundList.size()))
        return;
    if(SoundList[ID]==NULL)
        return;
    Mix_PlayChannel(-1, SoundList[ID], 0);
}