#include "Common.h"

class CMyWindowListView
{
public:
    HWINDOW m_hWindow;
    HELE    m_hListView;
	HXCGUI hAdapterTree;
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
		XListView_SetItemSize(m_hListView,150,200);
		
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
            wsprintfW(temp,L"楼层-%d",i);
            index=XAdListView_Item_AddItemText(hAdapter,group1,temp);

        }
		
        for (i=0;i<20;i++)
        {
            wsprintfW(temp,L"group2-item-%d",i);
            index=XAdListView_Item_AddItemText(hAdapter,group2,temp);
        }



        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_SELECT,&CMyWindowListView::OnListViewSelect);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_EXPAND,&CMyWindowListView::OnListViewExpand);
		
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE,&CMyWindowListView::OnTemplateCreate);
		XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_CREATE_END,&CMyWindowListView::OnListViewTemplateCreateEnd);

        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_DESTROY,&CMyWindowListView::OnTemplateDestroy);
        XEle_RegEventCPP(m_hListView,XE_LISTVIEW_TEMP_ADJUST_COORDINATE,&CMyWindowListView::OnTemplateAdjustCoordinate);
        



        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnListViewTemplateCreateEnd(listView_item_i* pItem,BOOL *pbHandled)
	{
		HXCGUI hShapeText = XListView_GetTemplateObject(m_hListView,pItem->iGroup,pItem->iItem,10);
		if (XC_IsHXCGUI(hShapeText,XC_SHAPE_TEXT))
		{
			HELE hParent = XShape_GetParentEle(hShapeText);
		 	HELE hTree = XTree_Create(10,10,10,10,hParent);
			XTree_SetItemTemplateXML(hTree,L"树模板.xml");

			//树控件的代码和添加数据的代码必须在这里写，
			//用户可以自己保存一个数据结构，在这里讲数据弄到数据适配器中。。

			hAdapterTree = XAdTree_Create();
			XTree_BindAdapter(hTree,hAdapterTree);
			
			XAdTree_AddColumn(hAdapterTree,L"name1");
			int nItem = XAdTree_InsertItemText(hAdapterTree,L"餐桌1");
			XAdTree_InsertItemText(hAdapterTree,L"人数(6人)",nItem);
			XAdTree_InsertItemText(hAdapterTree,L"人数(2人)",nItem);
			XAdTree_InsertItemText(hAdapterTree,L"人数(3人)",nItem);
			XAdTree_InsertItemText(hAdapterTree,L"人数(4人)",nItem);
			XAdTree_InsertItemText(hAdapterTree,L"人数(5人)",nItem);
			XAdTree_InsertItemText(hAdapterTree,L"人数(6人)",nItem);

			HXCGUI hLayout = XShape_GetParentLayout(hShapeText);
			XLayout_AddEle(hLayout,hTree);
			XEle_SetLayoutWidth(hTree,layout_size_type_fill,1);
			XEle_SetLayoutHeight(hTree,layout_size_type_weight,1);

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
