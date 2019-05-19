#include "Common.h"


class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
	HELE    m_hButtonReg;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		

        m_hButton = XBtn_Create(8, 50, 100, 20,L"事件演示", m_hWindow);
        

		m_hButtonReg = XBtn_Create(120, 50, 100, 20,L"注册/移除 事件", m_hWindow);
		XBtn_SetType(m_hButtonReg,button_type_check);
		XEle_RegEventCPP(m_hButtonReg,XE_BUTTON_CHECK,&CMyWindowButton::OnButtonCheck);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnButtonCheck(BOOL bCheck,BOOL *pbHandled)
	{
		if (bCheck)
		{
			XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWindowButton::OnBtnClick);
		} 
		else
		{
			XEle_RemoveEventCPP(m_hButton,XE_BNCLICK,&CMyWindowButton::OnBtnClick);
		}
		return 0;
	}

    int OnBtnClick(BOOL *pbHandled)
    {
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowButton  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




