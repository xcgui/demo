#include "Common.h"


class CMyWindowButton
{
public:
	xcgui::XWnd m_Wnd;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"炫彩界面库窗口");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
		xcgui::XBtn btn(100, 50, 60, 25,L"Button", m_Wnd);
        XEle_RegEventCPP(btn,XE_BNCLICK,&CMyWindowButton::OnBtnClick);

        m_Wnd.ShowWindow(SW_SHOW);
    }
    int OnBtnClick(BOOL *pbHandled)
    {
        MessageBoxW(m_Wnd.GetHWND(),L"你点击了按钮",L"提示",MB_OK);
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




