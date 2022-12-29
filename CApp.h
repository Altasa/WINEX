#ifndef _CAPP_H_
    #define _CAPP_H_
#include <SDL.h>
//����������� ������ �����������
#include "CSurface.h"
#include "CSurface.cpp"
//����� ����������
class CApp{
    //���� ������
    private:
        //���� ���������� ����������� ��������
        bool Running;
        //���� ����������
        SDL_Window* Window;
        //����������� ����
        SDL_Surface* Surf_Display;
        //����������� ����������
        SDL_Surface* Surf_Test;
        //������ ���� ������ ������
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT; 
        
    //������ ������
    public:
        //�����������
        CApp();
        //����������� ��������
        int OnExecute();
    //������ ����������� ��������
    public:
        //�������������
        bool OnInit();
        //���������� �������
        void OnEvent(SDL_Event* Event);
        //���������� ������
        void OnLoop();
        //����������
        void OnRender();
        //������������ ������
        void OnCleanup();
};
#endif