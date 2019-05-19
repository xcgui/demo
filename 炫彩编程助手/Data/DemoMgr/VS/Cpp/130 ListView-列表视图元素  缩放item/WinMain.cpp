#include "Common.h"

class CMyWindowListView
{
public:
    HWINDOW m_hWindow;
    HELE    m_hListView;
	int     m_Zoom;
    CMyWindowListView()
    {
        Init();
    }
    void Init()
    {
		m_Zoom = 50;
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
		
        HIMAGE hImage=XImage_LoadFile(L"111.png",TRUE);
		
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
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);
		
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
    
		XEle_RegEventCPP(m_hListView,XE_MOUSEWHEEL,&CMyWindowListView::OnMouseWheel);
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnMouseWheel(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		if ( (nFlags&MK_CONTROL) != MK_CONTROL)
			return 0;

		unsigned short wData = (unsigned short)(nFlags >> 16 );

		SIZE size;
		if (wData == 120)
		{
			
			if (m_Zoom > 10)
			{
				//向上 缩小
				
				XListView_GetItemSize(m_hListView,&size);
				size.cx = size.cx - 10;
				size.cy = size.cy - 10;
				XListView_SetItemSize(m_hListView,size.cx,size.cy);
				m_Zoom -= 10;

			}


		}else
		{
			//向下 放大
			if (m_Zoom < 90)
			{
				//向上 缩小
				XListView_GetItemSize(m_hListView,&size);
				size.cx = size.cx + 10;
				size.cy = size.cy + 10;
				XListView_SetItemSize(m_hListView,size.cx,size.cy);
				m_Zoom += 10;
//				
			}
		}

		XListView_RefreshData(m_hListView);
		XEle_RedrawEle(m_hListView,TRUE);

		xtrace(" %d %d %f\r\n",size.cx,size.cy ,m_Zoom);

		*pbHandled = TRUE;
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
    XInitXCGUI();
    CMyWindowListView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
