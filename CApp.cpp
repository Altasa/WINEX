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
//����������� ������ ��������
#include "CAnimation.h"
#include "CAnimation.cpp"
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
    Surf_Grid=NULL;
    Surf_XO=NULL;
    Surf_Yoshi=NULL;
    //������ ����������
    CurrentPlayer=0;
    //������ ���� ������ ������
    SCREEN_WIDTH=300;
    SCREEN_HEIGHT=364; 
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
        SDL_Delay(40);//25fps window
    }
    OnCleanup();
    return 0;
}
//��������� ������� �����
void CApp::Reset(){
    for(int i=0;i<9;i++){
        Grid[i]=GRID_TYPE_NONE;
    }
}
//��������� ������� ������
void CApp::SetCell(int ID, int Type){
    if(ID<0 || ID>=9){
        return;
    }
    if(Type<0 || Type> GRID_TYPE_O){
        return;
    }
    Grid[ID]=Type;
}
//������� ����� �����
int main(int argc, char* argv[]){
    //�������� ���������� ����������
    CApp theApp;
    //����� ���������� ����������
    return theApp.OnExecute();
}