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

int CALLBACK OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	MINMAXINFO* pMiniMaxInfo = (MINMAXINFO*)lParam;

	//pMiniMaxInfo->ptMaxPosition
	MessageBoxW(g_Wnd.GetHWND(),L"窗口开始最大化",L"标题",MB_OK);
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    g_Wnd.Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(g_Wnd)
    {
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",g_Wnd);
		m_btn.SetType(button_type_close);

		xcgui::XBtn btnMax(100, 5, 60, 20,L"最大化",g_Wnd);
		btnMax.SetType(button_type_max);
		
		g_Wnd.RegEventC(WM_GETMINMAXINFO,OnWndOther);
		g_Wnd.ShowWindow(SW_SHOW);
		
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


