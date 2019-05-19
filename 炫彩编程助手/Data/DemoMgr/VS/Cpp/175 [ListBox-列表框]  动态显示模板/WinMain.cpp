#include "Common.h"

class CMyWindowListBox
{
public:
    HWINDOW m_hWindow;
    HELE    m_hListBox;
    CMyWindowListBox()
    {
        Init();
    }
	~CMyWindowListBox()
	{
	}
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
    
        m_hListBox=XListBox_Create(20,40,400,350,m_hWindow);
        XListBox_SetItemTemplateXML(m_hListBox,L"ListBox_Item.xml");
        XSView_SetLineSize(m_hListBox,20,20);


        HXCGUI hAdapter=XAdTable_Create();
        XListBox_BindAdapter(m_hListBox,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");

        wchar_t  buf[256]={0};
        int  index=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"item-%d",i);
            index=XAdTable_AddItemTextEx(hAdapter,L"name1",buf);
            if(XC_ID_ERROR!=index)
            {
                wsprintfW(buf,L"item-1-%d",i);
                XAdTable_SetItemTextEx(hAdapter,index,L"name2",buf);

                wsprintfW(buf,L"item-2-%d",i);
                XAdTable_SetItemTextEx(hAdapter,index,L"name3",buf);
            }
        }

		XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_CREATE,&CMyWindowListBox::OnTemplateCreate);
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_DESTROY,&CMyWindowListBox::OnTemplateDestroy);
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_ADJUST_COORDINATE,&CMyWindowListBox::OnTemplateAdjustCoordinate);
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_SELECT,&CMyWindowListBox::OnListBoxSelect);
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_CREATE_END,&CMyWindowListBox::OnListBoxTemplateCreateEnd);
		XEle_RegEventCPP(m_hListBox,XE_LISTBOX_DRAWITEM,&CMyWindowListBox::OnListBoxDrawItem);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnListBoxDrawItem(HDRAW hDraw,listBox_item_i* pItem,BOOL *pbHandled)
	{
		HELE hEleLeave  = (HELE)XListBox_GetTemplateObject(m_hListBox,pItem->index,5);
		HELE hEleStay   = (HELE)XListBox_GetTemplateObject(m_hListBox,pItem->index,6);
		HELE hEleSelect = (HELE)XListBox_GetTemplateObject(m_hListBox,pItem->index,7);
		XEle_ShowEle(hEleLeave,FALSE);
		XEle_ShowEle(hEleStay,FALSE);
		XEle_ShowEle(hEleSelect,FALSE);

		switch (pItem->nState)
		{
		case list_item_state_leave:
				XEle_ShowEle(hEleLeave,TRUE);
			break;
		case list_item_state_select:
			XEle_ShowEle(hEleSelect,TRUE);
			break;
		case list_item_state_stay:
			XEle_ShowEle(hEleStay,TRUE);
			break;
		}
		xtrace("OnListBoxDrawItem\r\n");
//		*pbHandled = TRUE;
		return 0;
	}
	int OnListBoxTemplateCreateEnd(listBox_item_i* pItem,BOOL *pbHandled)
	{
		xtrace("OnListBoxTemplateCreateEnd\r\n");
		return 0;
	}
    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {
		xtrace("OnListBoxSelect\r\n");
        return 0;
    }
    int  OnTemplateCreate(listBox_item_i *pItem,BOOL *pbHandled)
    {
		xtrace("OnTemplateCreate\r\n");
        return 0;
    }
    int  OnTemplateDestroy(listBox_item_i *pItem,BOOL *pbHandled)
    {
		xtrace("OnTemplateDestroy\r\n");
        return 0;
    }
    int  OnTemplateAdjustCoordinate(listBox_item_i *pItem,BOOL *pbHandled)
    {
		xtrace("OnTemplateAdjustCoordinate\r\n");
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
//    XC_ShowLayoutFrame(TRUE);
    CMyWindowListBox  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
