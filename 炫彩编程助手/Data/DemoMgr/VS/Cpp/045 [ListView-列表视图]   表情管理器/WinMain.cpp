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
		
        m_hListView= XListView_Create(20,40,295,150,m_hWindow);

		//设置listView里面的背景颜色
		XEle_EnableDrawFocus(m_hListView,FALSE);
		XEle_AddBkFill(m_hListView,RGB(255,0,0),255);

		//影藏分组条
		XListView_SetGroupHeight(m_hListView,0);

		XListView_SetAlignSizeLeft(m_hListView,0);
		XListView_SetAlignSizeTop(m_hListView,0); 
		XListView_SetItemSize(m_hListView,30,30); //要显示的图片大小
		XListView_SetColumnSpace (m_hListView,1); //列间距
		XListView_SetRowSpace (m_hListView,1);  //行间距
		XSView_SetBorderSize(m_hListView,1,1,0,0); //将内间距调整


        XListView_SetItemTemplateXML(m_hListView,L"ListView_Item.xml");
		
		

        HXCGUI hAdapter=XAdListView_Create();
        XAdListView_Group_AddColumn(hAdapter,L"name3");
        XAdListView_Item_AddColumn(hAdapter,L"name1");
		
        XListView_BindAdapter(m_hListView,hAdapter);		
        int  group1=XAdListView_Group_AddItemText(hAdapter,L"group1");

		HBKM hBkInfoM = XEle_GetBkManager(m_hListView);
		XBkM_AddFill(hBkInfoM,listView_state_flag_item_leave,RGB(255,255,255),255);
		

        int index=0;
        
		int i = 0;
        for (i=1;i<128;i++)
        {
			XAdListView_Item_AddItemText(hAdapter,group1,L"");
        }

//这个工程暂时用不到这些事件，原型写好，后面可以复制
//         XEle_RegEventCPP(m_hListView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
//         XEle_RegEventCPP(m_hListView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);		
//         XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
//         XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
//         XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
        

		XEle_RegEventCPP(
			m_hListView,
			XE_LISTVIEW_TEMP_CREATE_END,
			&CMyWindowListView::OnListViewTemplateCreateEnd);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnListViewTemplateCreateEnd(listView_item_i* pItem,BOOL *pbHandled)
	{
		
		//  这个9是xml模板里面的9
		HXCGUI hgif = XListView_GetTemplateObject(m_hListView,pItem->iGroup,pItem->iItem,9);
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
//     int OnListViewSelect(int iGroup,int iItem,BOOL *pbHandled)
//     {
//         *pbHandled=TRUE;
//         return 0;
//     }
//     int OnListViewExpand(int iGroup,BOOL bExpand,BOOL *pbHandled)
//     {
//         *pbHandled=TRUE;
//         return 0;
//     }
//     int  OnTemplateCreate(listView_item_i *pItem,BOOL *pbHandled)
//     {
//         *pbHandled=TRUE;
//         return 0;
//     }
//     int  OnTemplateDestroy(listView_item_i *pItem,BOOL *pbHandled)
//     {
//         *pbHandled=TRUE;
//         return 0;
//     }
//     int  OnTemplateAdjustCoordinate(listView_item_i *pItem,BOOL *pbHandled)
//     {
//         *pbHandled=TRUE;
//         return 0;
//     }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowListView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
