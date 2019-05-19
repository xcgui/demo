#include "Common.h"

#define  WM_TASKBARRCLICK 0x0313

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
		XC_RegisterWindowClassName(L"大色秘密");
		m_hWindow = XWnd_CreateEx(NULL,L"大色秘密",L"代理IP",WS_VISIBLE|WS_MINIMIZEBOX ,0, 0, 300, 200,NULL);

		XWnd_RegEventCPP(m_hWindow,WM_TASKBARRCLICK,&CMyWindowButton::OnWndOther);
		XWnd_RegEventCPP(m_hWindow,WM_PAINT,&CMyWindowButton::OnWndDrawWindow);
		XWnd_RegEventCPP(m_hWindow, XWM_MENU_SELECT, &CMyWindowButton::OnWndMenuSelect);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
		
    }
	int  OnWndMenuSelect(int nID,BOOL *pBool)
    {
		switch (nID)
		{
		case 201:
			XWnd_CloseWindow(m_hWindow);
			break;
		}
        XTRACE("menu-item:%d\n",nID);
        return 0;
    }
	int OnWndDrawWindow(HDRAW hDraw,BOOL *pbHandled)
	{
		SetWindowRgn(XWnd_GetHWND(m_hWindow),NULL,FALSE);
		return 0;
	}
	int OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		POINT pt;
		GetCursorPos(&pt);

        //创建弹出菜单
        HMENUX hMenu = XMenu_Create();
        XMenu_AddItem(hMenu, 201, L"关闭");
//        ::ClientToScreen(XWnd_GetHWND(m_hWindow), &pt);
        XMenu_Popup(hMenu, XWnd_GetHWND(m_hWindow), pt.x, pt.y);
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




