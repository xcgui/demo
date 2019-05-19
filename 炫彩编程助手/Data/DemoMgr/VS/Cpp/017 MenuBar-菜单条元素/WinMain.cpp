#include "Common.h"

class CMyWindowMenuBar
{
public:
    HWINDOW m_hWindow;
    HELE    m_MenuBar;
    CMyWindowMenuBar()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_MenuBar = XMenuBar_Create(20,40,260,28,m_hWindow);
        XMenuBar_AddButton(m_MenuBar, L"文件");
        XMenuBar_AddButton(m_MenuBar, L"编辑");
        XMenuBar_AddButton(m_MenuBar, L"视图");
        XMenuBar_AddButton(m_MenuBar, L"aaa");
        HMENUX hMenu=XMenuBar_GetMenu(m_MenuBar,0);
        if(hMenu)
        {
            XMenu_AddItem(hMenu, 101, L"101");
            XMenu_AddItem(hMenu, 102, L"102");
            XMenu_AddItem(hMenu, 103, L"103");
            //XMenu_AddItem(hMenu, 0, L"",XC_ID_ROOT,menu_item_flags_separator); //分隔栏
            XMenu_AddItem(hMenu, 1031, L"3-1",103);
        }
        hMenu=XMenuBar_GetMenu(m_MenuBar,1);
        if(hMenu)
        {
            XMenu_AddItem(hMenu, 201, L"201");
            XMenu_AddItem(hMenu, 202, L"202");
            XMenu_AddItem(hMenu, 203, L"203");

        }
        hMenu=XMenuBar_GetMenu(m_MenuBar,2);
        if(hMenu)
        {
            XMenu_AddItem(hMenu, 301, L"301");
        }
        
        XEle_RegEventCPP(m_MenuBar,XE_MENU_SELECT,&CMyWindowMenuBar::OnWndMenuSelect);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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
