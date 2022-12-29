#ifndef _CAPP_H_
    #define _CAPP_H_
#include <SDL.h>
//����������� ������ �����������
#include "CSurface.h"
//����������� ������ �������
#include "CEvent.h"
//����� ����������
class CApp : public CEvent{
    //���� ������
    private:
        //���� ���������� ����������� ��������
        bool Running;
        //���� ����������
        SDL_Window* Window;
        //����������� ����
        SDL_Surface* Surf_Display;
        //����������� ����������
        SDL_Surface* Surf_Grid;
        SDL_Surface* Surf_XO;
        //������ ����������
        int CurrentPlayer;//�� ������
        int Grid[9];//������ �����
        enum{//������� �����
            GRID_TYPE_NONE=0,
            GRID_TYPE_X,
            GRID_TYPE_O
        };
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
        //����������� �������
        void OnEvent(SDL_Event* Event);
        void OnLButtonDown(int mX, int mY);
        //��������� ���������� ������
        void OnExit();
        //���������� ������
        void OnLoop();
        //����������
        void OnRender();
        //������������ ������
        void OnCleanup();
    //������ ����������
    public:
        //��������� ������� �����
        void Reset();
        //��������� ������� ������
        void SetCell(int ID, int Type);
};
#endif