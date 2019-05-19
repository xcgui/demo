#include "Common.h"



HWINDOW  hWindow=NULL;


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
	hWindow=XWnd_CreateEx(WS_EX_TOOLWINDOW,NULL,L"不在任务栏显示",WS_VISIBLE,0,0,500,400);
//    hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(hWindow)
    {
        HELE hButton=XBtn_Create(10,10,80,25,L"关闭",hWindow);//创建按钮
		XBtn_SetType(hButton,button_type_close);
		
        XWnd_ShowWindow(hWindow,SW_SHOW);//显示窗口
		
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


