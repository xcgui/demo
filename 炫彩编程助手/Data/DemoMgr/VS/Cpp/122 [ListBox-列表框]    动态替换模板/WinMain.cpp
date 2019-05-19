#include "Common.h"

class CMyWindowListBox
{
public:
    HWINDOW m_hWindow;
    HELE    m_hListBox;
	HTEMP* m_Template_ListBox_Item_Select;
    CMyWindowListBox()
    {
        Init();
    }
	~CMyWindowListBox()
	{
		XTemp_Destroy(m_Template_ListBox_Item_Select);
	}
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
    
        m_hListBox=XListBox_Create(20,40,300,310,m_hWindow);
        XListBox_SetItemTemplateXML(m_hListBox,L"ListBox_Item.xml");
        XSView_SetLineSize(m_hListBox,20,20);

		m_Template_ListBox_Item_Select = XTemp_Load(XC_LISTBOX,L"ListBox_Item_Select.xml");

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


        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnListBoxTemplateCreateEnd(listBox_item_i* pItem,BOOL *pbHandled)
	{
		*pbHandled = TRUE;
		return 0;
	}
    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {
        int array_[100]={0};
        int count =XListBox_GetSelectAll(m_hListBox,array_,100);
        wstring  szItemList;
        HXCGUI hAdapter=XListBox_GetAdapter(m_hListBox);
        for (int i=0;i<count;i++)
        {
             szItemList+= XAdTable_GetItemText(hAdapter, array_[i], 0);
             szItemList+=L"\n";
        }
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateCreate(listBox_item_i *pItem,BOOL *pbHandled)
    {

		if (pItem->index%2 == 0)
		{
			pItem->pInfo = m_Template_ListBox_Item_Select;
		}

        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateDestroy(listBox_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateAdjustCoordinate(listBox_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
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
