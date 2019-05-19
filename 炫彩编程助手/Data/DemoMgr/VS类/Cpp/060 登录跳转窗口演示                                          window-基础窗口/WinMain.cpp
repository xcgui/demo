#include "Common.h"



int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化

	xcgui::XModalWnd modal(300,200,L"登录系统",NULL);
	xcgui::XBtn btn(10, 5, 200, 20,L"关闭模态窗口",modal);
	btn.SetType(button_type_close);
	modal.DoModal();

	xcgui::XWnd m_Wnd(0,0,300,200,L"炫彩界面库-窗口");
    if(m_Wnd)
    {
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);
	
		SetFocus(m_Wnd.GetHWND());
		m_Wnd.ShowWindow(SW_SHOW);
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


