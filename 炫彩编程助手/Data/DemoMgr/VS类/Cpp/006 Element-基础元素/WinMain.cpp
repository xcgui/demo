#include "Common.h"

class CMyWindowElement
{
public:
	xcgui::XWnd m_Window;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
        m_Window.Create(0, 0, 350, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Window);
		btn.SetType(button_type_close);
		
		xcgui::XEle ele(20,50,100,100,m_Window);

        m_Window.ShowWindow(SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowElement  MyWindowt;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




