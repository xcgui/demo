#include "Common.h"

class CMyWindowRichEdit
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XRichEdit m_edit;

    CMyWindowRichEdit()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn btnClose(10, 5, 60, 20,L"close",m_Wnd);
		btnClose.SetType(button_type_close);

        m_edit.Create(20, 40, 150, 20, m_Wnd);
        m_edit.InsertString(L"123456");
    
        m_Wnd.ShowWindow(SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowRichEdit  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}

