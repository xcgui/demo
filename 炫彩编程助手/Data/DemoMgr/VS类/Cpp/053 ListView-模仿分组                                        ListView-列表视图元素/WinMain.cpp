#include "Common.h"

class CMyWindowListView
{
public:
	xcgui::XWnd m_Wnd;

	xcgui::XListView m_listView;

    CMyWindowListView()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		

        m_listView.Create(20,40,400,300,m_Wnd);
        m_listView.SetItemTemplateXML(L"ListView_Item.xml");


		m_listView.AddBkFill(RGB(26,60,123),255);
		m_listView.AddItemBkFill(list_item_state_leave,0,0);
		HIMAGE hImageSelect = XImage_LoadFile(L"select.png",TRUE);
		m_listView.AddItemBkImage(list_item_state_select,hImageSelect);
		

		xcgui::XAdListView adapter;
        adapter.Group_AddColumn(L"name");
        adapter.Item_AddColumn(L"name");
        adapter.Item_AddColumn(L"name2");
		
        m_listView.BindAdapter(adapter);
		
        int  group1=adapter.Group_AddItemText(L"group1");
        int  group2=adapter.Group_AddItemText(L"group2");

		
        HIMAGE hImage=XImage_LoadFile(L"111.jpg",TRUE);
		
        int index=0;
        wchar_t  temp[MAX_PATH]={0};
		int i = 0;
        for (i=0;i<3;i++)
        {
            wsprintfW(temp,L"group1-item-%d",i);
            index=adapter.Item_AddItemImage(group1,hImage);
            adapter.Item_SetText(group1,index,1,temp);
        }
		
        for (i=0;i<3;i++)
        {
            wsprintfW(temp,L"group2-item-%d",i);
            index=adapter.Item_AddItemImage(group2,hImage);
            adapter.Item_SetText(group2,index,1,temp);

        }
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);
		
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
        
        m_Wnd.ShowWindow(SW_SHOW);
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
