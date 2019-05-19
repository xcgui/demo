#include "Common.h"

class CMyWindowToolBar
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;
	xcgui::XToolBar m_toolBar;
    HELE    m_hToolBar;
    CMyWindowToolBar()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 350, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
        m_toolBar.Create(20, 40, 320, 28, m_Wnd);
		AddButton(L"Button1");
		AddButton(L"Button2");
		AddButton(L"Button3");
		AddButton(L"Button4");
		AddButton(L"Button5");


        m_Wnd.ShowWindow(SW_SHOW);

    }
	void AddButton(const wchar_t* buttonName)
	{
		xcgui::XBtn btn;
		btn.Create(0,0,60,20,buttonName);
		m_toolBar.InsertEle(btn);
	}
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowToolBar  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
