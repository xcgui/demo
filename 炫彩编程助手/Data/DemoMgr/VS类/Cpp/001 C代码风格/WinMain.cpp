#include "Common.h"



xcgui::XWnd g_Wnd;
//事件响应
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    //弹出消息框
    MessageBoxW(g_Wnd.GetHWND(),L"你点击了按钮",L"提示",MB_OK);
    *pBool=TRUE; //对该事件进行拦截
    return 0;    //事件的返回值
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    if(g_Wnd.Create(0,0,300,200,L"炫彩界面库-窗口"))//创建窗口
    {
		xcgui::XBtn btn;
		btn.Create(10,10,80,25,L"按钮",g_Wnd);
		btn.RegEventC(XE_BNCLICK,My_EventBtnClick);

		
        g_Wnd.ShowWindow(SW_SHOW);//显示窗口
		
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


