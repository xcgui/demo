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
		m_Wnd.CreateEx(NULL,L"大色秘密",L"代理IP",WS_VISIBLE,0, 0, 300, 200);

		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);

		m_Wnd.ShowWindow(SW_SHOW);
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




