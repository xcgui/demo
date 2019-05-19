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

		XListView_SetItemSize(m_hListView,180,100);
		XListView_SetGroupHeight(m_hListView,0);
		
        int  group1=XAdListView_Group_AddItemText(hAdapter,L"group1");
        int  group2=XAdListView_Group_AddItemText(hAdapter,L"group2");
		

	HIMAGE hImage =	XImage_LoadFileFromHICON((HICON) LoadImage(NULL,L"a.ico",IMAGE_ICON,0,0,LR_LOADFROMFILE));

	//如果不设置这行代码，滚动条滚动的时候就会报错
	XImage_EnableAutoDestroy(hImage,FALSE);
        //HIMAGE hImage=XImage_LoadFile(L"a.ico",TRUE);
		
        int index=0;
        wchar_t  temp[MAX_PATH]={0};
		int i = 0;
        for (i=0;i<200;i++)
        {
            wsprintfW(temp,L"炫彩界面库\r\n下载:100万",i);
            index=XAdListView_Item_AddItemImage(hAdapter,group1,hImage);
            XAdListView_Item_SetText(hAdapter,group1,index,1,temp);
        }
		
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);
		
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
		XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE_END,&CMyWindowListView::OnListViewTemplateCreateEnd);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
        

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
	int OnBtnClick(HELE hEventEle,BOOL *pbHandled)
	{
		int grounpID = 0;
		int itemID   = 0;
		XListView_GetItemIDFromHXCGUI(m_hListView,hEventEle,&grounpID,&itemID);

		wchar_t buffer[256] = {0};
		wsprintfW(buffer,L"当前按钮所在分组ID = %d \r\n 所在项目ID = %d",grounpID,itemID);
		MessageBoxW(NULL,buffer,L"提示",MB_OK);

		return 0;
	}
	int OnListViewTemplateCreateEnd(listView_item_i* pItem,BOOL *pbHandled)
	{
		//这个28 是模板里面按钮的id
		HELE hBtnInstall = (HELE)XListView_GetTemplateObject(m_hListView,pItem->iGroup,pItem->iItem,28);

		if (XC_GetObjectType(hBtnInstall) == XC_BUTTON )
		{
			XEle_RegEventCPP1(hBtnInstall,XE_BNCLICK,&CMyWindowListView::OnBtnClick);
		}
//		*pbHandled = TRUE;
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
