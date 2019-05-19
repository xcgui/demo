#include "sxcgui.h"
#include "sxcgui.cpp"








HWINDOW  g_hWindow=NULL;
DWORD WINAPI Thread(LPVOID lpParam)
{
	HELE hButton=SXBtn_Create(g_hWindow,10,50,80,25,L"按钮",g_hWindow);
	SXEle_RedrawEle(g_hWindow,hButton,TRUE);
	return 0;
}
//事件响应
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    //弹出消息框
	CreateThread(NULL,0,Thread,g_hWindow,0,NULL);
    *pBool=TRUE; //对该事件进行拦截
    return 0;    //事件的返回值
}
int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    g_hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(g_hWindow)
    {
		SXWnd_EnableSafeFunction(g_hWindow);
		HELE hButton=XBtn_Create(10,10,80,25,L"按钮",g_hWindow);
        XEle_RegEventC(hButton,XE_BNCLICK,My_EventBtnClick);//注册按钮点击事件
        XWnd_ShowWindow(g_hWindow,SW_SHOW);//显示窗口
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放?
	return 0;
}