#include "Common.h"




class CMyWindowList
{
public:
    HWINDOW m_hWindow;
    HELE    m_hList;
	HFONTX m_hHeaderFont;


    CMyWindowList()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 550, 380, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hList= XList_Create(20,40,500,300,m_hWindow);
        XList_SetItemTemplateXML(m_hList,L"List_Item.xml");
        XSView_SetLineSize(m_hList,20,20);
		
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
		
        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name1",L"aaa");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"bbb");
        XAdMap_AddItemText(hAdapterHeader,L"name3",L"ccc");
        XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		
        HXCGUI hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");
		
        XList_SetColumnWidth(m_hList,0,150);
        XList_SetColumnWidth(m_hList,1,150);
        XList_SetColumnWidth(m_hList,2,150);
		
        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<1;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
            XAdTable_AddItemText(hAdapter,tmp);
			
            wsprintfW(tmp,L"child-%d-1",i);  XAdTable_SetItemText(hAdapter,i,1,tmp);
            wsprintfW(tmp,L"child-%d-2",i);  XAdTable_SetItemText(hAdapter,i,2,tmp);
        }
		
		m_hHeaderFont = XFont_Create(20);

		XEle_RegEventCPP(m_hList,
			XE_LIST_HEADER_TEMP_CREATE_END,
			&CMyWindowList::OnListHeaderTemplateCreateEnd);
	
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnListHeaderTemplateCreateEnd(list_header_item_i* pItem,BOOL *pbHandled)
	{


		HXCGUI hShapeText = NULL;

		// 硬编码 最后这个 1 是在 模板里面，大家需要自己用设计打开模板设置
		hShapeText	= XList_GetHeaderTemplateObject(m_hList,pItem->index,1);
		if (XC_IsHXCGUI(hShapeText,XC_SHAPE_TEXT))
		{
			XShapeText_SetFont(hShapeText,m_hHeaderFont);
			*pbHandled = TRUE;
			return 0;
		}

		// 硬编码 最后这个 2 是在 模板里面，大家需要自己用设计打开模板设置
		hShapeText = XList_GetHeaderTemplateObject(m_hList,pItem->index,2);
		if (XC_IsHXCGUI(hShapeText,XC_SHAPE_TEXT))
		{
			XShapeText_SetFont(hShapeText,m_hHeaderFont);
			*pbHandled = TRUE;
			return 0;
		}

		// 硬编码 最后这个 3 是在 模板里面，大家需要自己用设计打开模板设置
		hShapeText = XList_GetHeaderTemplateObject(m_hList,pItem->index,3);
		if (XC_IsHXCGUI(hShapeText,XC_SHAPE_TEXT))
		{
			XShapeText_SetFont(hShapeText,m_hHeaderFont);
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
