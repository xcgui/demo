#include "Common.h"



HWINDOW  hWindow=NULL;
LONG_PTR g_oldProc = NULL;
//事件响应
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    //弹出消息框
    MessageBoxW(XWnd_GetHWND(hWindow),L"你点击了按钮",L"提示",MB_OK);
    *pBool=TRUE; //对该事件进行拦截
    return 0;    //事件的返回值
}

LRESULT CALLBACK WindowProc(  HWND hwnd,      // handle to window
							UINT uMsg,      // message identifier
							WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
 )
{
	OutputDebugStringW(L"收到消息?\r\n");
	return CallWindowProc((WNDPROC)g_oldProc,hwnd,uMsg,wParam,lParam);
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(hWindow)
    {
        HELE hButton=XBtn_Create(10,10,80,25,L"按钮",hWindow);//创建按钮
        XEle_RegEventC(hButton,XE_BNCLICK,My_EventBtnClick);//注册按钮点击事件
		

		g_oldProc = SetWindowLongPtr(XWnd_GetHWND(hWindow),GWLP_WNDPROC,(LONG_PTR)&WindowProc);

        XWnd_ShowWindow(hWindow,SW_SHOW);//显示窗口
		
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


