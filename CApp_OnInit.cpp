#include "CApp.h"
bool CApp::OnInit(){
    //����������� ����������� ���������� SDL2
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        return false;
    }
    //����������� ����������� ���������� SDL2_image
    if(CSurface::ImgInit() == false){
        return false;
    }
    //�������� ���� ����������
    Window = SDL_CreateWindow(
        "CApp.exe",
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN
    );
    if(Window==NULL){
        return false;
    }
    //��������� ����������� ����
    Surf_Display=SDL_GetWindowSurface(Window);
    //�������� ������������ �����������
    if((Surf_Test=CSurface::OnLoad("img1.png", Surf_Display))==NULL){
        return false;
    }
    return true;
}