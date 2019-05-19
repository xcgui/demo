#include "Common.h"

class CMyWindowListView
{
public:
    xcgui::XWnd m_Wnd;
	xcgui::XListView m_ListView;
    CMyWindowListView()
    {
        Init();
    }
    void Init()
    {
        m_Wnd.Create(0, 0, 400, 300, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);
		
		m_ListView.Create(20,40,295,150,m_Wnd);
		m_ListView.SetItemTemplateXML(L"ListView_Item.xml");
		m_ListView.EnableDrawFocus(FALSE);

		//设置listView里面的背景颜色
		xcgui::XBkM bkInfoM = m_ListView.GetBkManager();
		bkInfoM.AddFill(element_state_flag_leave,RGB(255,0,0),255);
		bkInfoM.AddFill(listView_state_flag_item_leave,RGB(255,255,255),255);

		//影藏分组条
		m_ListView.SetGroupHeight(0);
		m_ListView.SetAlignSizeLeft(0);
		m_ListView.SetAlignSizeTop(0);
		m_ListView.SetItemSize(30,30);
		m_ListView.SetColumnSpace(1);
		m_ListView.SetRowSpace(1);
		m_ListView.SetPadding(1,1,0,0);//将内间距调整

        
		
		xcgui::XAdListView adapter;
		m_ListView.BindAdapter(adapter);

        adapter.Group_AddColumn(L"name3");
        adapter.Item_AddColumn(L"name");
			
        int  group1=adapter.Group_AddItemText(L"group1");
		
        int index=0;
        
		int i = 0;
        for (i=1;i<128;i++)
        {
			adapter.Item_AddItemText(group1,L"");
        }

//这个工程暂时用不到这些事件，原型写好，后面可以复制
        XEle_RegEventCPP(m_ListView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_ListView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);		
        XEle_RegEventCPP(m_ListView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
        XEle_RegEventCPP(m_ListView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
        XEle_RegEventCPP(m_ListView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
       
		XEle_RegEventCPP(m_ListView,XE_LISTVIEW_TEMP_CREATE_END,&CMyWindowListView::OnListViewTemplateCreateEnd);
		m_Wnd.ShowWindow(SW_SHOW);

    }
	int OnListViewTemplateCreateEnd(listView_item_i* pItem,BOOL *pbHandled)
	{
		
		//  这个9是xml模板里面的9
		HXCGUI hgif = XListView_GetTemplateObject(m_ListView,pItem->iGroup,pItem->iItem,9);
		if (XC_GetObjectType(hgif) == XC_BUTTON)
		{
			for (int i = 0; i < 10; i++)
			{
				wchar_t buffer[MAX_PATH] = {0};
				wsprintfW(buffer,L".\\68.gif.ifl\\IMG%05d.bmp",i);
				XBtn_AddAnimationFrame((HELE)hgif,XImage_LoadFile(buffer),200);
			}
			XBtn_EnableAnimation((HELE)hgif,TRUE);
		}
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
