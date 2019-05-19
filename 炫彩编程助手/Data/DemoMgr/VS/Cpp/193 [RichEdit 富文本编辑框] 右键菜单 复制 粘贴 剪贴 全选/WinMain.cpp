#include "Common.h"



class CMyWindowMenu
{
public:
    HWINDOW m_hWindow;
	HELE    m_hRichEdit;
    CMyWindowMenu()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		

		m_hRichEdit = XRichEdit_Create(8,30,100,25,m_hWindow);
		XEle_RegEventCPP1(m_hRichEdit,XE_RBUTTONUP,&CMyWindowMenu::OnRButtonUp);


        XWnd_RegEventCPP(m_hWindow, XWM_MENU_SELECT, &CMyWindowMenu::OnWndMenuSelect);
        XWnd_RegEventCPP(m_hWindow, XWM_MENU_EXIT, &CMyWindowMenu::OnWndMenuExit);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int  OnRButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		RECT rt;
		XEle_GetRect(m_hRichEdit,&rt);
		POINT pt = {rt.left,rt.bottom};
        //创建弹出菜单
        HMENUX hMenu = XMenu_Create();
        XMenu_AddItem(hMenu, 201, L"复制");
        XMenu_AddItem(hMenu, 202, L"粘贴");
        XMenu_AddItem(hMenu, 203, L"剪辑");
		XMenu_AddItem(hMenu, 204, L"全选");
		
		
        ::ClientToScreen(XWnd_GetHWND(m_hWindow), &pt);
        XMenu_Popup(hMenu, XWnd_GetHWND(m_hWindow), pt.x, pt.y);
		return 0;
	}
    int  OnWndMenuSelect(int nID,BOOL *pBool)
    {
		switch (nID)
		{
		case 201:
			XRichEdit_ClipboardCopy(m_hRichEdit);
			break;
		case 202:
			XRichEdit_ClipboardPaste(m_hRichEdit);
			break;
		case 203:
			XRichEdit_ClipboardCut(m_hRichEdit);
			break;
		case 204:
			XRichEdit_SelectAll(m_hRichEdit);
			XEle_RedrawEle(m_hRichEdit);
			break;
		}
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






