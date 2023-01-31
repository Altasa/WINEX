#ifndef _CSOUNDBANK_H_
    #define _CSOUNDBANK_H_
#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>
using namespace std;
//Класс Звук
class CSoundBank {
    public: 
        //Контроль звука и список звуков
        static CSoundBank SoundControl;
        vector<Mix_Chunk*> SoundList;
    public:
        //Заггрузка и очистка
        CSoundBank();
        int OnLoad(const char* File);
        void OnCleanup();
        //Воспроизведение
    public:
        void Play(int ID);
};
#endif