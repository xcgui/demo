#include "Common.h"



class CWindow_Demo
{
public:
	xcgui::XWnd m_wnd;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
		m_wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_wnd);
		btn.SetType(button_type_close);

        XWnd_RegEventCPP(m_wnd,WM_DESTROY,&CWindow_Demo::OnDestroy);
        m_wnd.ShowWindow(SW_SHOW);
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





