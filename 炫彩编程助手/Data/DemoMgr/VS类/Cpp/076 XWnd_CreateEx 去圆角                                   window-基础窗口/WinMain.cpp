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
		XC_RegisterWindowClassName(L"大色秘密");
		m_Wnd.CreateEx(WS_EX_CLIENTEDGE,L"大色秘密",L"代理IP",WS_OVERLAPPED|WS_VISIBLE,0, 0, 300, 200);
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);

		XWnd_RegEventCPP(m_Wnd,WM_PAINT,&CMyWindowButton::OnWndDrawWindow);
        m_Wnd.ShowWindow(SW_SHOW);	
    }
	int OnWndDrawWindow(HDRAW hDraw,BOOL *pbHandled)
	{
		SetWindowRgn(m_Wnd.GetHWND(),NULL,FALSE);
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




