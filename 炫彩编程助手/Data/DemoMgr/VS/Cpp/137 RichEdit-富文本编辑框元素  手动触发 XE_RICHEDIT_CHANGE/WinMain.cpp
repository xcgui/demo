#include "Common.h"

class CMyWindowRichEdit
{
public:
    HWINDOW m_hWindow;
    HELE    m_hRichEdit;
    CMyWindowRichEdit()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_hRichEdit=XRichEdit_Create(20, 40, 150, 20, m_hWindow);
        XRichEdit_InsertString(m_hRichEdit, L"123456");
    
		XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(m_hRichEdit,TRUE);

		//手动触发 XE_RICHEDIT_CHANGE 事件
		XEle_PostEvent(m_hRichEdit,m_hRichEdit,XE_RICHEDIT_CHANGE,NULL,NULL);

		XEle_RegEventCPP(m_hRichEdit,XE_RICHEDIT_CHANGE, &CMyWindowRichEdit::OnRichEditChange);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }

	
	///用户修改内容事件,只有当用户操作时才会触发,需要开启后有效, XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE()；
	/// XRichEdit_SetText()、XRichEdit_InsertString()不会触发此事件
	
	int OnRichEditChange(BOOL *pbHandled)
	{
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

