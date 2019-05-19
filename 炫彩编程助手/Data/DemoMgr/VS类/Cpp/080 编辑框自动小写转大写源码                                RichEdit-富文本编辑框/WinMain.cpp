#include "Common.h"

class CMyWindowRichEdit
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XRichEdit m_Edit;
    CMyWindowRichEdit()
    {
        Init();
    }
    void Init()
    {
        m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_Wnd),button_type_close);

        m_Edit.Create(20, 40, 150, 20, m_Wnd);
        m_Edit.InsertString(L"123456");
    
		XEle_RegEventCPP(m_Edit,XE_CHAR,&CMyWindowRichEdit::OnEventChar);
        m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		if (wParam > 96 && wParam < 123)
		{
			wParam -= 32;
			m_Edit.SendEvent(m_Edit,XE_CHAR,wParam,NULL);
			*pbHandled = TRUE;
		}		
		return 0;
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

