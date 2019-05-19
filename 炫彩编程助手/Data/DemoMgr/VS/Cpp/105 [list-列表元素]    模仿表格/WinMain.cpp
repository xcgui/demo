#include "Common.h"

class CMyWindowList
{
public:
    HWINDOW m_hWindow;
    HELE    m_hList;
	HXCGUI hAdapter;
    CMyWindowList()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 600, 500, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hList= XList_Create(8,30,580,460,m_hWindow);
        XList_SetItemTemplateXML(m_hList,L"list_table.xml");
        XSView_SetLineSize(m_hList,20,20);
		
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
		XList_AddColumn(m_hList,100);
		
        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name1",L"aaa");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"bbb");
        XAdMap_AddItemText(hAdapterHeader,L"name3",L"ccc");
        XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		
        hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");
		XAdTable_AddColumn(hAdapter,L"name4");
		XAdTable_AddColumn(hAdapter,L"name5");

		//用一个字段来保存 ComboBox的索引
		XAdTable_AddColumn(hAdapter,L"k");

		
        XList_SetColumnWidth(m_hList,0,150);
        XList_SetColumnWidth(m_hList,1,150);
        XList_SetColumnWidth(m_hList,2,150);
		
        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<40;i++)
        {
            wsprintfW(tmp,L"%d",i);
            XAdTable_AddItemText(hAdapter,tmp);
			
            wsprintfW(tmp,L"%d-1",i);  XAdTable_SetItemText(hAdapter,i,1,tmp);
	        wsprintfW(tmp,L"%d-2",i);  XAdTable_SetItemText(hAdapter,i,2,tmp);
			wsprintfW(tmp,L"%d-3",i);  XAdTable_SetItemText(hAdapter,i,3,tmp);
			wsprintfW(tmp,L"%d-4",i);  XAdTable_SetItemText(hAdapter,i,4,tmp);
        }
		
		XEle_RegEventCPP(m_hList,XE_LIST_TEMP_CREATE_END,&CMyWindowList::OnListTemplateCreateEnd);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }

	int OnRichEditColum1Change(HELE hele,BOOL *pbHandled)
	{
		wchar_t data[MAX_PATH] = {0};
		//本来应该用 下面这个函数获取文本长度，
		//然后new分配，这里为了减少代码，直接用固定的
		//XRichEdit_GetTextLength(hele);
		XRichEdit_GetText(hele,data,MAX_PATH*sizeof(wchar_t));

		int nIndex = XList_GetItemIndexFromHXCGUI(m_hList,hele);
		XAdTable_SetItemTextEx(hAdapter,nIndex,L"name1",data);

		return 0;
	}
	int OnListTemplateCreateEnd(list_item_i* pItem,BOOL *pbHandled)
	{
		if (pItem->iSubItem == 0)
		{
			HELE hRichEdit = (HELE)XList_GetTemplateObject(m_hList,pItem->index,1);
			XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(hRichEdit,TRUE);
			XEle_RegEventCPP1(hRichEdit,XE_RICHEDIT_CHANGE,&CMyWindowList::OnRichEditColum1Change);
		}else if (pItem->iSubItem == 0)
		{
			//这里重新注册一个 编辑框改变事件，和上面 == 0 的情况是一样的，
			//重新注册一个是为了区分是哪列，当然你也可以用其他办法替代
		}
		else if (pItem->iSubItem == 3)
		{
			HELE hComboBox = (HELE)XList_GetTemplateObject(m_hList,pItem->index,9);
			HXCGUI hAdapterTable = XAdTable_Create();
			XComboBox_BindAdapter(hComboBox,hAdapterTable);
			XAdTable_AddColumn(hAdapterTable,L"name1");
			XAdTable_AddItemText(hAdapterTable,L"1");
			XAdTable_AddItemText(hAdapterTable,L"2");

			int nSelect = 0;
			XAdTable_GetItemTextEx(hAdapter,pItem->index,L"k",(wchar_t*)&nSelect,4);
			XComboBox_SetSelItem(hComboBox,nSelect);

			XEle_RegEventCPP1(hComboBox,XE_COMBOBOX_SELECT,&CMyWindowList::OnComboBoxSelect);
	//		XAdTable_InsertItemText(hAdapterTable,)
		}
		return 0;
	}
	int OnComboBoxSelect(HELE hEle,int iItem,BOOL *pbHandled)
	{
		int nIndex = XList_GetItemIndexFromHXCGUI(m_hList,hEle);
		XAdTable_SetItemTextEx(hAdapter,nIndex,L"k",(const wchar_t*)&iItem);

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
