#include "Common.h"

class CMyWindowList
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XList m_list;


    CMyWindowList()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 550, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
        m_list.Create(20,40,500,300,m_Wnd);

        m_list.SetItemTemplateXML(L"List_Item.xml");
        m_list.SetLineSize(20,20);
		
        m_list.AddColumn(100);
        m_list.AddColumn(100);
        m_list.AddColumn(100);
		
		xcgui::XAdMap   m_adapterMap;
        m_list.BindAdapterHeader(m_adapterMap);
        m_adapterMap.AddItemText(L"name",L"aaa");
        m_adapterMap.AddItemText(L"name2",L"bbb");
        m_adapterMap.AddItemText(L"name3",L"ccc");
        m_adapterMap.AddItemText(L"name4",L"test");
		
		xcgui::XAdTable m_adapter;
        m_list.BindAdapter(m_adapter);
        m_adapter.AddColumn(L"name");
        m_adapter.AddColumn(L"name2");
        m_adapter.AddColumn(L"name3");
		
        m_list.SetColumnWidth(0,150);
        m_list.SetColumnWidth(1,150);
        m_list.SetColumnWidth(2,150);
		
        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
            m_adapter.AddItemText(tmp);
			
            wsprintfW(tmp,L"child-%d-1",i);  m_adapter.SetItemText(i,1,tmp);
            wsprintfW(tmp,L"child-%d-2",i);  m_adapter.SetItemText(i,2,tmp);
        }
		
        

//		XEle_RegEventCPP(m_list,XE_LIST_SELECT,&CMyWindowList::OnListSelect);
//		XEle_RegEventCPP1(m_list,XE_LBUTTONDOWN,&CMyWindowList::OnLButtonDown);
//		XEle_RegEventCPP(m_list,XE_LBUTTONUP,&CMyWindowList::OnLButtonUp);
		XEle_RegEventCPP(m_list,XE_LIST_TEMP_CREATE_END,&CMyWindowList::OnListTemplateCreateEnd);
//		XEle_RegEventCPP(m_list,XE_LIST_TEMP_CREATE,&CMyWindowList::OnListTemplateCreate);
//		XEle_RegEventCPP(m_list,XE_MOUSEMOVE,&CMyWindowList::OnListMouseMove);
//		XEle_RegEventCPP(m_list,XE_LIST_DRAWITEM,&CMyWindowList::OnListDrawItem);
		m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnListSelect(int iItem,BOOL *pbHandled)
	{

		return 0;
	}
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		return 0;
	}
	int OnListDrawItem(HDRAW hDraw,list_item_i* pItem,BOOL *pbHandled)
	{
		HXCGUI hBtn = m_list.GetTemplateObject(pItem->index,6);
		*pbHandled = TRUE;
		return 0;
	}

	int OnListTemplateCreateEnd(list_item_i* pItem,BOOL *pbHandled)
	{
		if (pItem->iSubItem == 1)
		{
			HXCGUI hShapeText = m_list.GetTemplateObject(pItem->index,2);
			if (XC_GetObjectType(hShapeText) == XC_SHAPE_TEXT)
			{
				XShapeText_SetTextColor(hShapeText,RGB(255,0,0),255);
			}
		}else if (pItem->iSubItem == 2)
		{

			HXCGUI hShapeText = m_list.GetTemplateObject(pItem->index,3);
			if (XC_GetObjectType(hShapeText) == XC_SHAPE_TEXT)
			{
				XShapeText_SetTextColor(hShapeText,RGB(0,255,0),255);
			}
		}
		*pbHandled = TRUE;
		return 0;
	}

	int OnListTemplateCreate(list_item_i* pItem,BOOL *pbHandled)
	{
		HXCGUI hBtn = m_list.GetTemplateObject(pItem->index,6);
		if (XC_GetObjectType(hBtn) == XC_BUTTON)
		{
			XEle_EnableBkTransparent((HELE)hBtn,TRUE);
		}

		*pbHandled = TRUE;
		return 0;
	}
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowList  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
