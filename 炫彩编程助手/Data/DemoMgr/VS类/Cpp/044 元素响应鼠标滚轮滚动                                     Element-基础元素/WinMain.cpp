#include "Common.h"




//事件响应

int CALLBACK OnMouseWheel(UINT nFlags,POINT *pPt,BOOL *pbHandled)
{
	MessageBoxW(NULL,L"接收到鼠标滚轮滚动消息!",L"提示",MB_OK);
	return 0;
}
int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
	xcgui::XWnd m_Wnd(0, 0, 400, 300, L"炫彩界面库窗口");
    if(m_Wnd)
    {
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);

		xcgui::XEle ele(0,0,100,100,m_Wnd);
		ele.EnableEvent_XE_MOUSEWHEEL(TRUE);
		ele.RegEventC(XE_MOUSEWHEEL,OnMouseWheel);

		m_Wnd.ShowWindow(SW_SHOW);//显示窗口
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


