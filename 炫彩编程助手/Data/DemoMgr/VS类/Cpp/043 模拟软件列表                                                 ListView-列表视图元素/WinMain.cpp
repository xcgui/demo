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
        m_Wnd.Create(0, 0, 500, 400, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);
		

        m_listView.Create(20,40,400,300,m_Wnd);
        m_listView.SetItemTemplateXML(L"ListView_Item.xml");
		

		xcgui::XAdListView adapter;
        adapter.Group_AddColumn(L"name3");
        adapter.Item_AddColumn(L"name");
        adapter.Item_AddColumn(L"name1");

		m_listView.BindAdapter(adapter);
		

		m_listView.SetItemSize(180,100);
		m_listView.SetGroupHeight(0);
		
        int  group1=adapter.Group_AddItemText(L"group1");
        int  group2=adapter.Group_AddItemText(L"group2");
		
		
        HIMAGE hImage=XImage_LoadFile(L"logo_02.png",TRUE);
		
        int index=0;
        wchar_t  temp[MAX_PATH]={0};
		int i = 0;
        for (i=0;i<20;i++)
        {
            wsprintfW(temp,L"炫彩界面库\r\n下载:100万",i);
			index=adapter.Item_AddItemImage(group1,hImage);
            adapter.Item_SetText(group1,index,1,temp);
        }
		
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);
		
        XEle_RegEventCPP(m_listView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
		XEle_RegEventCPP(m_listView,XE_LISTVIEW_TEMP_CREATE_END,&CMyWindowListView::OnListViewTemplateCreateEnd);
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
	int OnBtnClick(HELE hEventEle,BOOL *pbHandled)
	{
		int grounpID = 0;
		int itemID   = 0;
		m_listView.GetItemIDFromHXCGUI(hEventEle,&grounpID,&itemID);

		wchar_t buffer[256] = {0};
		wsprintfW(buffer,L"当前按钮所在分组ID = %d \r\n 所在项目ID = %d",grounpID,itemID);
		MessageBoxW(NULL,buffer,L"提示",MB_OK);

		return 0;
	}
	int OnListViewTemplateCreateEnd(listView_item_i* pItem,BOOL *pbHandled)
	{
		//这个28 是模板里面按钮的id
		xcgui::XBtn btn((HELE)m_listView.GetTemplateObject(pItem->iGroup,pItem->iItem,28) );
		if (btn.IsHXCGUI(XC_BUTTON))
		{
			XEle_RegEventCPP1(btn,XE_BNCLICK,&CMyWindowListView::OnBtnClick);
		}
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
