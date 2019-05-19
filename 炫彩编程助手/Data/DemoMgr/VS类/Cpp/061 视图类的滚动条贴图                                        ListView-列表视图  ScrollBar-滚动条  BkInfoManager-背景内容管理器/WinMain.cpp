#include "Common.h"

class CMyWindowListView
{
public:
    xcgui::XWnd m_Wnd;
	xcgui::XListView m_listView;
    HELE    m_hListView;

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
        adapter.Item_AddColumn(L"name2");
		
        m_listView.BindAdapter(adapter);


        int  group1=adapter.Group_AddItemText(L"group1");
        int  group2=adapter.Group_AddItemText(L"group2");

		HIMAGE hImage=XImage_LoadFile(L"111.jpg");

        int index=0;
        wchar_t  temp[MAX_PATH]={0};
		int i = 0;
        for (i=0;i<20;i++)
        {
            wsprintfW(temp,L"group1-item-%d",i);
            index=adapter.Item_AddItemImage(group1,hImage);
            adapter.Item_SetText(group1,index,1,temp);
        }
		
        for (i=0;i<20;i++)
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
        


		//获取垂直滚动条
		//(备注: 无论是 list 和 listbox 只要是滚动视图类，都可以用
		// XSView_GetScrollBarV 来获取滚动条 水平的 就用 XSView_GetScrollBarH
		// 大家需要看 模块关系结构图，帮助文档中 大家对照着深刻理解下)

		//获取垂直滚动条SBar，然后获取滚动条的背景管理器，最后添加图片
		xcgui::XSBar sbar = m_listView.GetScrollBarV();
		sbar.GetBkManager().AddImage(element_state_flag_leave,XImage_LoadFile(L"bgV.png",TRUE));
		

		xcgui::XBtn btnUp = sbar.GetButtonUp();
		btnUp.SetStyle(button_style_default);
		btnUp.EnableBkTransparent(TRUE);
		xcgui::XBkM bkInfoMup = btnUp.GetBkManager();
		bkInfoMup.AddImage(button_state_flag_leave,XImage_LoadFile(L"up.png",FALSE));
		bkInfoMup.AddImage(button_state_flag_stay,XImage_LoadFile(L"up.png",FALSE));



		xcgui::XBtn btnDown = sbar.GetButtonUp();
		btnDown.SetStyle(button_style_default);
		btnDown.EnableBkTransparent(TRUE);
		xcgui::XBkM bkInfoMDown = btnDown.GetBkManager();
		bkInfoMDown.AddImage(button_state_flag_leave,XImage_LoadFile(L"down.png",FALSE));
		bkInfoMDown.AddImage(button_state_flag_stay,XImage_LoadFile(L"down.png",FALSE));
 		

		xcgui::XBtn btnSlider = sbar.GetButtonSlider();
		btnSlider.EnableBkTransparent(TRUE);
		xcgui::XBkM bkInfoMSlider = btnSlider.GetBkManager();
		HIMAGE hImageSlider = XImage_LoadFile(L"sliderV.png",TRUE);
		bkInfoMSlider.AddImage(button_state_flag_leave,hImageSlider);
		bkInfoMSlider.AddImage(button_state_flag_stay,hImageSlider);
		bkInfoMSlider.AddImage(button_state_flag_down,hImageSlider);



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
