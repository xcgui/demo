#include "Common.h"

struct my_image_info
{
    HIMAGE hImage1;
    HIMAGE hImage2;
    HIMAGE hImage3;
    HIMAGE hImage4;
    HIMAGE hImage5;
    HIMAGE hImage6;
};

void CreateButton(int left,int top,my_image_info  *pInfo,HWINDOW hWindow)
{
	xcgui::XBtn btn(left,top,37,42,L"A",hWindow);
    btn.AddAnimationFrame(pInfo->hImage1,100); //添加动画帧
    btn.AddAnimationFrame(pInfo->hImage2,100);
    btn.AddAnimationFrame(pInfo->hImage3,100);
    btn.AddAnimationFrame(pInfo->hImage4,100);
    btn.AddAnimationFrame(pInfo->hImage5,100);
    btn.AddAnimationFrame(pInfo->hImage6,100);
    btn.EnableAnimation(TRUE); //启动动画
}
void CreateButtonLoop(int left,int top,my_image_info  *pInfo,HWINDOW hWindow)
{
	xcgui::XBtn btn(left,top,37,42,L"B",hWindow);
    btn.AddAnimationFrame(pInfo->hImage1,100); //添加动画帧
    btn.AddAnimationFrame(pInfo->hImage2,100);
    btn.AddAnimationFrame(pInfo->hImage3,100);
    btn.AddAnimationFrame(pInfo->hImage4,100);
    btn.AddAnimationFrame(pInfo->hImage5,100);
    btn.AddAnimationFrame(pInfo->hImage6,100);
    btn.EnableAnimation(TRUE,TRUE); //启动动画,循环播放
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
	
	xcgui::XWnd m_wnd(0, 0, 300, 200, L"炫彩界面库窗口");
	xcgui::XBtn btn(10, 5, 60, 20,L"close",m_wnd);
	btn.SetType(button_type_close);
	
    my_image_info  info;
    info.hImage1=XImage_LoadFile(L"1.png");
    info.hImage2=XImage_LoadFile(L"2.png");
    info.hImage3=XImage_LoadFile(L"3.png");
    info.hImage4=XImage_LoadFile(L"4.png");
    info.hImage5=XImage_LoadFile(L"5.png");
    info.hImage6=XImage_LoadFile(L"6.png");
	
    int left=20;
    int top=50;
    CreateButton(left,top,&info,m_wnd); left+=50;
    CreateButton(left,top,&info,m_wnd); left+=50;
    CreateButton(left,top,&info,m_wnd); left+=50;
    CreateButton(left,top,&info,m_wnd); left+=50;
    CreateButton(left,top,&info,m_wnd); left+=50;
	
    left=20; top=100;
    CreateButtonLoop(left,top,&info,m_wnd); left+=50;
    CreateButtonLoop(left,top,&info,m_wnd); left+=50;
    CreateButtonLoop(left,top,&info,m_wnd); left+=50;
    CreateButtonLoop(left,top,&info,m_wnd); left+=50;
    CreateButtonLoop(left,top,&info,m_wnd); left+=50;
	
    m_wnd.ShowWindow(SW_SHOW);
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}



