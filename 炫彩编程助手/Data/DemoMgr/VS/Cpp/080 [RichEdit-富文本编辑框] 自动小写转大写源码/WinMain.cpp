#include "Common.h"

class CMyWindowRichEdit
{
public:
    HWINDOW m_hWindow;
    HELE    m_hRichEdit;
    HELE    m_hRichEdit2;
    CMyWindowRichEdit()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_hRichEdit=XRichEdit_Create(20, 40, 150, 20, m_hWindow);
        XRichEdit_InsertString(m_hRichEdit,L"123456");
    
		XEle_RegEventCPP(m_hRichEdit,XE_CHAR,&CMyWindowRichEdit::OnEventChar);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		if (wParam > 96 && wParam < 123)
		{
			wParam -= 32;
			XEle_SendEvent(m_hRichEdit,m_hRichEdit,XE_CHAR,wParam,NULL);
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

