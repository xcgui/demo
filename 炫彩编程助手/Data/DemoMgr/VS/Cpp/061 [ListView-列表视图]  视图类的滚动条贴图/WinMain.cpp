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
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);
		
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
        


		//获取垂直滚动条
		//(备注: 无论是 list 和 listbox 只要是滚动视图类，都可以用
		// XSView_GetScrollBarV 来获取滚动条 水平的 就用 XSView_GetScrollBarH
		// 大家需要看 模块关系结构图，帮助文档中 大家对照着深刻理解下)
		HELE hSbar = XSView_GetScrollBarV(m_hListView);
		HBKM hBkInfoM = XEle_GetBkManager(hSbar); //获取滚动条的背景管理器
		HIMAGE hImageBG = XImage_LoadFile(L"bgV.png",TRUE);
		XBkM_AddImage(hBkInfoM,element_state_flag_leave,hImageBG); //然后贴图
		
		
		HELE hBtnUp = XSBar_GetButtonUp(hSbar); //获取按钮
		XBtn_SetStyle(hBtnUp,button_style_default);
		XEle_EnableBkTransparent(hBtnUp,TRUE);
		hBkInfoM = XEle_GetBkManager(hBtnUp); //获取按钮的背景管理器
		HIMAGE hImageUp = XImage_LoadFile(L"up.png",FALSE);
		XBkM_AddImage(hBkInfoM,button_state_flag_leave,hImageUp); //然后贴图
		XBkM_AddImage(hBkInfoM,button_state_flag_stay,hImageUp); //然后贴图
 		
		HELE hBtnDown = XSBar_GetButtonDown(hSbar);
		XBtn_SetStyle(hBtnDown,button_style_default);
		XEle_EnableBkTransparent(hBtnDown,TRUE);
		hBkInfoM = XEle_GetBkManager(hBtnDown); //获取按钮的背景管理器
		HIMAGE hImageDown = XImage_LoadFile(L"down.png",FALSE);
		XBkM_AddImage(hBkInfoM,button_state_flag_leave,hImageDown); //然后贴图
		XBkM_AddImage(hBkInfoM,button_state_flag_stay,hImageDown); //然后贴图
 		

		HELE hSlider = XSBar_GetButtonSlider(hSbar);
		XEle_EnableBkTransparent(hSlider,TRUE);
		hBkInfoM = XEle_GetBkManager(hSlider); //获取按钮的背景管理器
		HIMAGE hImageSlider = XImage_LoadFile(L"sliderV.png",TRUE);
		XBkM_AddImage(hBkInfoM,button_state_flag_leave,hImageSlider); //然后贴图
		XBkM_AddImage(hBkInfoM,button_state_flag_stay,hImageSlider); //然后贴图
		XBkM_AddImage(hBkInfoM,button_state_flag_down,hImageSlider); //然后贴图


        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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
