#include "Common.h"



class CMyWindowMenu
{
public:
    HWINDOW m_hWindow;
    CMyWindowMenu()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
		XWnd_RegEventCPP(m_hWindow,XWM_MENU_DRAW_BACKGROUND,&CMyWindowMenu::OnWndMenuDrawBackground);
		XWnd_RegEventCPP(m_hWindow,XWM_MENU_DRAWITEM,&CMyWindowMenu::OnMenuDrawItem);
        XWnd_RegEventCPP(m_hWindow, WM_RBUTTONUP, &CMyWindowMenu::OnRButtonUp);
        XWnd_RegEventCPP(m_hWindow, XWM_MENU_SELECT, &CMyWindowMenu::OnWndMenuSelect);
        XWnd_RegEventCPP(m_hWindow, XWM_MENU_EXIT, &CMyWindowMenu::OnWndMenuExit);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnWndMenuDrawBackground(HDRAW hDraw,menu_drawBackground_i *pInfo,BOOL *pbHandled)
	{
		RECT MenuRect;
		XWnd_GetClientRect(pInfo->hWindow,&MenuRect);
		XDraw_FillRectColor(hDraw,&MenuRect,RGB(128,128,128));

		*pbHandled = TRUE;
		return 0;
	}
	int OnMenuDrawItem(HDRAW hDraw,menu_drawItem_i* pInfo,BOOL *pbHandled)
	{
		switch (pInfo->nState)
		{
		case menu_item_flags_normal:
			XDraw_FillRectColor(hDraw,&pInfo->rcItem,RGB(0,128,0));
			XDraw_SetBrushColor(hDraw,0);
			XDraw_DrawText(hDraw,pInfo->pText,wcslen(pInfo->pText),&pInfo->rcItem);
			break;
		case menu_item_flags_select:
			XDraw_FillRectColor(hDraw,&pInfo->rcItem,RGB(0,0,128));
			XDraw_SetBrushColor(hDraw,0);
			XDraw_DrawText(hDraw,pInfo->pText,wcslen(pInfo->pText),&pInfo->rcItem);
			break;
		case menu_item_flags_check:
			break;
		case menu_item_flags_popup:
			XDraw_FillRectColor(hDraw,&pInfo->rcItem,RGB(128,0,0));
			XDraw_SetBrushColor(hDraw,0);
			XDraw_DrawText(hDraw,pInfo->pText,wcslen(pInfo->pText),&pInfo->rcItem);
			break;
		case menu_item_flags_separator:
			break;
		case menu_item_flags_disable:
			break;
		default:
			{
				//这里是组合状态
				if (menu_item_flags_popup&pInfo->nState && pInfo->nState&menu_item_flags_select)
				{
					//是弹出菜单，并且此时是鼠标经过状态
					XDraw_FillRectColor(hDraw,&pInfo->rcItem,RGB(128,128,0));
					XDraw_SetBrushColor(hDraw,0);
					XDraw_DrawText(hDraw,pInfo->pText,wcslen(pInfo->pText),&pInfo->rcItem);

				}
			}

			break;
		}
		


		return 0;
	}
    BOOL OnRButtonUp(UINT flags, POINT *pPt, BOOL *pbHandled)
    {
        POINT pt = *pPt;
        //创建弹出菜单
        HMENUX hMenu = XMenu_Create();
        XMenu_AddItem(hMenu, 201, L"111");
        XMenu_AddItem(hMenu, 202, L"222");
        XMenu_AddItem(hMenu, 203, L"333");
 
        XMenu_AddItem(hMenu, 204, L"444", 203);
        XMenu_AddItem(hMenu, 205, L"555", 203);
        XMenu_AddItem(hMenu, 206, L"666", 203);
 
        XMenu_AddItem(hMenu, 207, L"777", 206);
        XMenu_AddItem(hMenu, 208, L"888", 206);
        XMenu_AddItem(hMenu, 209, L"999", 206);
 
		XMenu_EnableDrawItem(hMenu,TRUE);
		XMenu_EnableDrawBackground(hMenu,TRUE);

        ::ClientToScreen(XWnd_GetHWND(m_hWindow), &pt);
        XMenu_Popup(hMenu, XWnd_GetHWND(m_hWindow), pt.x, pt.y);
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






