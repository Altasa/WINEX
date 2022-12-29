//����������� ���� �����������
//����������� ������ ����������
#include "CApp.h"
#include "CApp_OnInit.cpp"
#include "CApp_OnEvent.cpp"
#include "CApp_OnLoop.cpp"
#include "CApp_OnRender.cpp"
#include "CApp_OnCleanup.cpp"
//����������� ������ �����������
#include "CSurface.h"
#include "CSurface.cpp"
//����������� ������ �������
#include "CEvent.h"
#include "CEvent.cpp"
//����������� ������������
CApp::CApp(){
    //���� ���������� ����������� ��������
    Running=true;
    //���� ����������
    Window=NULL;
    //����������� ����
    Surf_Display=NULL;
    //����������� ����������
    Surf_Test=NULL;
    //������ ���� ������ ������
    SCREEN_WIDTH=640;
    SCREEN_HEIGHT=480; 
}
//����������� ����������� ��������
int CApp::OnExecute(){
    //�������������
    if(OnInit()==false){
        return -1;
    }
    //���� �������� ��������� �������
    SDL_Event Event;
    while(Running){
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();
    return 0;
}
//������� ����� �����
int main(int argc, char* argv[]){
    //�������� ���������� ����������
    CApp theApp;
    //����� ���������� ����������
    return theApp.OnExecute();
}