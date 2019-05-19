#include "Common.h"

class CMyWindowMenuBar
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;
	xcgui::XMenuBar m_menuBar;

    CMyWindowMenuBar()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"炫彩界面库窗口");
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
        m_menuBar.Create(20,40,260,28,m_Wnd);
        m_menuBar.AddButton( L"文件");
        m_menuBar.AddButton( L"编辑");
        m_menuBar.AddButton( L"视图");
        m_menuBar.AddButton( L"aaa");
		
		xcgui::XMenu menu = m_menuBar.GetMenu(0);
		menu.AddItem(101, L"101");
		menu.AddItem( 102, L"102");
		menu.AddItem( 103, L"103");
		//menu.AddItem( 0, L"",XC_ID_ROOT,menu_item_flags_separator); //分隔栏
		menu.AddItem( 1031, L"3-1",103);

		menu = m_menuBar.GetMenu(1);
        menu.AddItem(201, L"201");
        menu.AddItem(202, L"202");
        menu.AddItem(203, L"203");
		
		menu = m_menuBar.GetMenu(2);
        menu.AddItem(301, L"301");

        
        XEle_RegEventCPP(m_menuBar,XE_MENU_SELECT,&CMyWindowMenuBar::OnWndMenuSelect);
        m_Wnd.ShowWindow(SW_SHOW);
    }
    int  OnWndMenuSelect(int nID,BOOL *pbHandled)
    {
        XTRACE("select item %d \n",nID);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowMenuBar  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
