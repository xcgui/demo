#include "Common.h"


class CMyWindowCheck
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;

	xcgui::XBtn m_Check1;
	xcgui::XBtn m_Check2;
	xcgui::XBtn m_Check3;

    CMyWindowCheck()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
        m_Check1.Create(20, 40, 100, 20, L"Radio1", m_Wnd);
        m_Check2.Create(20, 70, 100, 20, L"Radio2", m_Wnd);
        m_Check3.Create(20, 100, 100, 20, L"Radio3", m_Wnd);
		
        m_Check1.SetGroupID(1);
        m_Check2.SetGroupID(1);
        m_Check3.SetGroupID(1);

        m_Check1.SetType(button_type_radio);
        m_Check2.SetType(button_type_radio);
        m_Check3.SetType(button_type_radio);

        m_Wnd.ShowWindow(SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowCheck  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}




