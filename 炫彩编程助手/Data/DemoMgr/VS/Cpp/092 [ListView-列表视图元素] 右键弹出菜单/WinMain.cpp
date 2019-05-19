#include "Common.h"

class CMyWindowListView
{
public:
    HWINDOW m_hWindow;
    HELE    m_hListView;
    CMyWindowListView()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 500, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hListView= XListView_Create(20,40,400,300,m_hWindow);
        XListView_SetItemTemplateXML(m_hListView,L"ListView_Item.xml");
		
        HXCGUI hAdapter=XAdListView_Create();
        XAdListView_Group_AddColumn(hAdapter,L"name3");
        XAdListView_Item_AddColumn(hAdapter,L"name1");
        XAdListView_Item_AddColumn(hAdapter,L"name2");
		
        XListView_BindAdapter(m_hListView,hAdapter);
		
        int  group1=XAdListView_Group_AddItemText(hAdapter,L"group1");
        int  group2=XAdListView_Group_AddItemText(hAdapter,L"group2");
		
        HIMAGE hImage=XImage_LoadFile(L"111.jpg");
		
        int index=0;
        wchar_t  temp[MAX_PATH]={0};
		int i = 0;
        for (i=0;i<20;i++)
        {
            wsprintfW(temp,L"group1-item-%d",i);
            index=XAdListView_Item_AddItemImage(hAdapter,group1,hImage);
            XAdListView_Item_SetText(hAdapter,group1,index,1,temp);
        }
		
        for (i=0;i<20;i++)
        {
            wsprintfW(temp,L"group2-item-%d",i);
            index=XAdListView_Item_AddItemImage(hAdapter,group2,hImage);
            XAdListView_Item_SetText(hAdapter,group2,index,1,temp);
        }
       
		XEle_RegEventCPP(m_hListView,XE_RBUTTONDOWN,&CMyWindowListView::OnRButtonDOWN);
		XEle_RegEventCPP(m_hListView,XE_RBUTTONUP,&CMyWindowListView::OnRButtonUp);

		XWnd_RegEventCPP(m_hWindow, XWM_MENU_SELECT, &CMyWindowListView::OnWndMenuSelect);
        XWnd_RegEventCPP(m_hWindow, XWM_MENU_EXIT, &CMyWindowListView::OnWndMenuExit);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnRButtonDOWN(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		//右键按下的时候，模拟左键点击，这样才可以选中
		//在右键松开的时候，才可以判断当前选中的是哪项
		XEle_SendEvent(m_hListView,m_hListView,XE_LBUTTONDOWN,nFlags,(LPARAM)pPt);
		XEle_SendEvent(m_hListView,m_hListView,XE_LBUTTONUP,nFlags,(LPARAM)pPt);
		XEle_RedrawEle(m_hListView);
		return 0;
	}
	int OnRButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		int nGroup = -1;
		int nItem  = -1;
		if (XListView_GetSelectItem(m_hListView,&nGroup,&nItem))
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
			
			::ClientToScreen(XWnd_GetHWND(m_hWindow), &pt);
			 XMenu_Popup(hMenu, XWnd_GetHWND(m_hWindow), pt.x, pt.y);
		}

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
    CMyWindowListView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
