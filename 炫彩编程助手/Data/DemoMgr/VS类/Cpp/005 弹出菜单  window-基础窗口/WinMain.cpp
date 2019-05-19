#include "Common.h"



class CMyWindowMenu
{
public:
	xcgui::XWnd m_Window;

    CMyWindowMenu()
    {
        Init();
    }
    void Init()
    {
		m_Window.Create(0, 0, 300, 200, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Window);
		btn.SetType(button_type_close);

        XWnd_RegEventCPP(m_Window, WM_RBUTTONUP, &CMyWindowMenu::OnRButtonUp);
        XWnd_RegEventCPP(m_Window, XWM_MENU_SELECT, &CMyWindowMenu::OnWndMenuSelect);
        XWnd_RegEventCPP(m_Window, XWM_MENU_EXIT, &CMyWindowMenu::OnWndMenuExit);
        m_Window.ShowWindow(SW_SHOW);
    }
    BOOL OnRButtonUp(UINT flags, POINT *pPt, BOOL *pbHandled)
    {
        POINT pt = *pPt;
        //创建弹出菜单
		xcgui::XMenu memu;
		memu.Create();
        memu.AddItem( 201, L"111");
        memu.AddItem(202, L"222");
        memu.AddItem(203, L"333");
 
        memu.AddItem(204, L"444", 203);
        memu.AddItem(205, L"555", 203);
        memu.AddItem(206, L"666", 203);
 
        memu.AddItem(207, L"777", 206);
        memu.AddItem(208, L"888", 206);
        memu.AddItem(209, L"999", 206);
 
        ::ClientToScreen(m_Window.GetHWND(), &pt);
        memu.Popup(m_Window.GetHWND(), pt.x, pt.y);
        return 0;
    }
    int  OnWndMenuSelect(int nID,BOOL *pBool)
    {
        XTRACE("menu-item:%d\n",nID);
        return 0;
    }
    int  OnWndMenuExit(BOOL *pbHandled)
    {
        XTRACE("menu-exit \n");
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowMenu  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}






