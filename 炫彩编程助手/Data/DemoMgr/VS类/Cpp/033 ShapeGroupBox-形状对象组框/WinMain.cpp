#include "Common.h"

class CMyWindowShape
{
public:
    xcgui::XWnd m_Wnd;
    CMyWindowShape()
    {
        Init();
    }
    void Init()
    {
        m_Wnd.Create(0, 0, 400, 300, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);

		xcgui::XShapeGroupBox groupBox(20,50,100,100,L"123456",m_Wnd);
        m_Wnd.ShowWindow(SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    XC_ShowLayoutFrame(TRUE);

    CMyWindowShape  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
