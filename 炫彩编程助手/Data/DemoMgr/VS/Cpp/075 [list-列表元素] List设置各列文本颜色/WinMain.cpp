#include "Common.h"

class CMyWindowList
{
public:
    HWINDOW m_hWindow;
    HELE    m_hList;
    CMyWindowList()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 550, 380, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hList= XList_Create(20,40,500,300,m_hWindow);
        XList_SetItemTemplateXML(m_hList,L"List_Item.xml");
        XSView_SetLineSize(m_hList,20,20);
		
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
		
        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name1",L"aaa");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"bbb");
        XAdMap_AddItemText(hAdapterHeader,L"name3",L"ccc");
        XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		
        HXCGUI hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");
		
        XList_SetColumnWidth(m_hList,0,150);
        XList_SetColumnWidth(m_hList,1,150);
        XList_SetColumnWidth(m_hList,2,150);
		
        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
            XAdTable_AddItemText(hAdapter,tmp);
			
            wsprintfW(tmp,L"child-%d-1",i);  XAdTable_SetItemText(hAdapter,i,1,tmp);
            wsprintfW(tmp,L"child-%d-2",i);  XAdTable_SetItemText(hAdapter,i,2,tmp);
        }

//		XEle_RegEventCPP(m_hList,XE_LIST_SELECT,&CMyWindowList::OnListSelect);
//		XEle_RegEventCPP1(m_hList,XE_LBUTTONDOWN,&CMyWindowList::OnLButtonDown);
//		XEle_RegEventCPP(m_hList,XE_LBUTTONUP,&CMyWindowList::OnLButtonUp);
		XEle_RegEventCPP(m_hList,XE_LIST_TEMP_CREATE_END,&CMyWindowList::OnListTemplateCreateEnd);
//		XEle_RegEventCPP(m_hList,XE_LIST_TEMP_CREATE,&CMyWindowList::OnListTemplateCreate);
//		XEle_RegEventCPP(m_hList,XE_MOUSEMOVE,&CMyWindowList::OnListMouseMove);
//		XEle_RegEventCPP(m_hList,XE_LIST_DRAWITEM,&CMyWindowList::OnListDrawItem);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnListSelect(int iItem,BOOL *pbHandled)
	{

		return 0;
	}
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		return 0;
	}
	int OnLButtonDown(HELE hEventEle,UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		HELE hEle = XEle_HitChildEle(hEventEle,pPt);
		if (XC_GetObjectType(hEle) == XC_BUTTON)
		{
		
			XBtn_SetCheck(hEle,!XBtn_IsCheck(hEle));
		}
//		int nId = (hEventEle);
		return 0;
	}
	int OnListDrawItem(HDRAW hDraw,list_item_i* pItem,BOOL *pbHandled)
	{
HXCGUI hBtn = XList_GetTemplateObject(m_hList,pItem->index,6);
		*pbHandled = TRUE;
		return 0;
	}

	int OnListTemplateCreateEnd(list_item_i* pItem,BOOL *pbHandled)
	{
		static HELE hEle;
		HXCGUI hBtn = XList_GetTemplateObject(m_hList,pItem->index,6);
		if (XC_GetObjectType(hBtn) == XC_BUTTON)
		{
			if (hEle != (HELE)hBtn)
			{
				XEle_EnableBkTransparent((HELE)hBtn,TRUE);
//				XEle_EnableMouseThrough((HELE)hBtn,TRUE);
				XEle_RegEventCPP1((HELE)hBtn,XE_MOUSEMOVE,&CMyWindowList::OnMouseMove);
				hEle  = (HELE)hBtn;
			}
		}

		HXCGUI hShapeText = XList_GetTemplateObject(m_hList,pItem->index,2);
		if (XC_GetObjectType(hShapeText) == XC_SHAPE_TEXT)
		{
			XShapeText_SetTextColor(hShapeText,RGB(255,0,0),255);
		}
		hShapeText = XList_GetTemplateObject(m_hList,pItem->index,3);
		if (XC_GetObjectType(hShapeText) == XC_SHAPE_TEXT)
		{
			XShapeText_SetTextColor(hShapeText,RGB(0,255,0),255);
		}

		
		

		*pbHandled = TRUE;
		return 0;
	}

	int OnListTemplateCreate(list_item_i* pItem,BOOL *pbHandled)
	{
// 		int nCount = XLayout_GetChildCount(pItem->hLayout);
// 		int nType = XLayout_GetChildType(pItem->hLayout,1);
// 		HXCGUI hBtn = XLayout_GetChild(pItem->hLayout,0);
		HXCGUI hBtn = XList_GetTemplateObject(m_hList,pItem->index,6);
		if (XC_GetObjectType(hBtn) == XC_BUTTON)
		{
			XEle_EnableBkTransparent((HELE)hBtn,TRUE);
//			XEle_EnableMouseThrough((HELE)hBtn,TRUE);
		}

		*pbHandled = TRUE;
		return 0;
	}
	int OnMouseMove(HELE hEventEle,UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{
		RECT rt;
		XEle_GetRect(hEventEle,&rt);
//		XEle_PointClientToWndClient()
//		HELE hParentEle = XEle_GetParentEle(hEventEle);
		int heightNormal,heightSel;
		XList_GetItemHeightDefault(m_hList,&heightNormal,&heightSel);
		POINT pt;
		pt.x = rt.left - 2;
		pt.y = rt.top + heightNormal;
		XEle_PostEvent(m_hList,m_hList,XE_MOUSEMOVE,(WPARAM)nFlags,(LPARAM)&pt);
		*pbHandled = TRUE;
		return 0;
	}
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowList  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
