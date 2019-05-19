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
        m_hWindow = XWnd_Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hListView= XListView_Create(20,40,400,300,m_hWindow);
        XListView_SetItemTemplateXML(m_hListView,L"ListView_Item.xml");
		
		XListView_SetItemSize(m_hListView,150,150);

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
            wsprintfW(temp,L"group1-1111111111111111111item-%d\r\n",i);
            index=XAdListView_Item_AddItemImage(hAdapter,group1,hImage);
            XAdListView_Item_SetText(hAdapter,group1,index,1,temp);
        }
		
        for (i=0;i<20;i++)
        {
            wsprintfW(temp,L"group2-item-%d",i);
            index=XAdListView_Item_AddItemImage(hAdapter,group2,hImage);
            XAdListView_Item_SetText(hAdapter,group2,index,1,temp);
        }
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);
		
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
		XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE_END,&CMyWindowListView::OnListViewTemplateCreateEnd);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
        
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }

	int OnDraw(HELE hEventEle,HDRAW hDraw,BOOL *pbHandled)
	{
		int nGrounp = 0;
		int nItem = 0;
		if (XListView_GetItemIDFromHXCGUI(m_hListView,hEventEle,&nGrounp,&nItem))
		{
			HXCGUI hAdapter = XListView_GetAdapter(m_hListView);
			wchar_t buffer[MAX_PATH] = {0};
			XAdListView_Item_GetTextEx(hAdapter,nGrounp,nItem,L"name2",buffer,MAX_PATH*sizeof(wchar_t));
			OutputDebugStringW(buffer);

			RECT rt;
			XEle_GetClientRect(hEventEle,&rt);
//			XEle_GetRect(hEventEle,&rt);
			XDraw_DrawText(hDraw,buffer,wcslen(buffer),&rt);
// 			HDC hDC = XDraw_GetHDC(hDraw);
// 			
// 			DrawTextW(hDC,buffer,wcslen(buffer),&rt,DT_WORDBREAK);
		}
		*pbHandled = TRUE;
		return 0;
	}
	int OnListViewTemplateCreateEnd(listView_item_i* pItem,BOOL *pbHandled)
	{
 		HXCGUI hele = XListView_GetTemplateObject(m_hListView,pItem->iGroup,pItem->iItem,99);
		if (XC_IsHXCGUI(hele,XC_ELE))
		{
			XEle_RegEventCPP1((HELE)hele,XE_PAINT,&CMyWindowListView::OnDraw);
//			*pbHandled = TRUE;
		}
// 		if (XC_IsHXCGUI(hele,XC_RICHEDIT))
// 		{
// 			HELE hEdit = (HELE)hele;
// 			XRichEdit_EnableMultiLine(hEdit,TRUE);
// 			XRichEdit_EnableAutoWrap(hEdit,TRUE);
// 			XSView_EnableAutoShowScrollBar(hEdit,FALSE);
// 			XSView_ShowSBarV(hEdit,FALSE);
// 
// 			int RowCount = XRichEdit_GetRowCount(hEdit);
// 			int RowLen = XRichEdit_GetRowLength(hEdit,RowCount-1);
// 			XRichEdit_SetItemColorEx(hEdit,0,0,RowCount-1,RowLen,255);
// 			
// 		}
		return 0;
	}
    int OnListViewSelect(int iGroup,int iItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int OnListViewExpand(int iGroup,BOOL bExpand,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateCreate(listView_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateDestroy(listView_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateAdjustCoordinate(listView_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	XC_SetLayoutFrameColor(255);
	XC_ShowLayoutFrame(TRUE);
	
    XInitXCGUI();
    CMyWindowListView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
