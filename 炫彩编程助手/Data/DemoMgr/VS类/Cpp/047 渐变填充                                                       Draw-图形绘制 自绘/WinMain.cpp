#include "Common.h"



class CWindow_Demo
{
public:
	xcgui::XWnd m_Wnd;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
		
		m_Wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
		
		xcgui::XEle ele(8,30,250,150,m_Wnd);
		XEle_RegEventCPP(ele,XE_PAINT,&CWindow_Demo::OnDraw);
		XWnd_RegEventCPP(m_Wnd,WM_DESTROY,&CWindow_Demo::OnDestroy);
        m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		RECT rt = {0,0,250,150};
		XDraw_GradientFill2(hDraw,RGB(255,0,0),255,RGB(0,255,0),255,&rt,GRADIENT_FILL_RECT_H);
		return 0;
	}
    int OnDestroy(BOOL* pbHandled)
    {
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}





