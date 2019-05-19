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
        m_Wnd.Create(0, 0, 400, 300, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);
		
        HIMAGE hImage=XImage_LoadFile(L"image\\bk.png");
		m_Wnd.GetBkManager().AddImage(window_state_whole_leave,hImage);

        m_Wnd.EnableDrawBk(FALSE);
		m_Wnd.SetTransparentType_shaped();
		m_Wnd.EnableDragWindow(TRUE);
        
        XWnd_RegEventCPP(m_Wnd,WM_DESTROY,&CWindow_Demo::OnDestroy);
        m_Wnd.ShowWindow(SW_SHOW);
		
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
