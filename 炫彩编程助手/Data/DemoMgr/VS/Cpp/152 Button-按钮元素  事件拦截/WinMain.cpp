#include "Common.h"


class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hButton = XBtn_Create(100, 50, 60, 25,L"Button", m_hWindow);
        XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWindowButton::OnBtnClick);
		XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWindowButton::OnBtnClick1);


        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnBtnClick(BOOL *pbHandled)
    {
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"回调1",L"提示",MB_OK);
        return 0;
    }
	int OnBtnClick1(BOOL *pbHandled)
    {
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"回调2",L"提示",MB_OK);
		//重点说明，如果这里拦截了消息，那么就不会响应回调1，
		//如果没有拦截，就可以响应回调1
		*pbHandled = TRUE;
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




