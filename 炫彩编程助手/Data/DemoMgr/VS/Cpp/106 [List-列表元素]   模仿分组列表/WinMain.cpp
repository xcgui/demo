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
        m_hWindow = XWnd_Create(0, 0, 550, 380, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hList= XList_Create(20,40,500,300,m_hWindow);
        XList_SetItemTemplateXML(m_hList,L"List_Item.xml");
        XSView_SetLineSize(m_hList,20,20);
		
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,300);

		
        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name1",L"aaa");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"bbb");

		
        hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
//        XAdTable_AddColumn(hAdapter,L"name3");

		
        XList_SetColumnWidth(m_hList,0,150);
        XList_SetColumnWidth(m_hList,1,300);
		
        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
            XAdTable_AddItemText(hAdapter,tmp);
			if (i % 6 == 0)
			{
				XList_SetItemData(m_hList,i,0,1);
				XList_SetItemData(m_hList,i,1,1);
			}
			
            wsprintfW(tmp,L"child-%d-1",i);
			XAdTable_SetItemText(hAdapter,i,1,tmp);
			XAdTable_SetItemText(hAdapter,i,2,L"1");

        }
		XEle_RegEventCPP(m_hList,XE_LIST_TEMP_CREATE_END,&CMyWindowList::OnListTemplateCreateEnd);
		XEle_RegEventCPP(m_hList,XE_LIST_TEMP_ADJUST_COORDINATE,&CMyWindowList::OnTemplateAdjustCoordinate);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }

	int OnButtonCheck(HELE hEle,BOOL bCheck,BOOL *pbHandled)
	{
		int nIndex = XList_GetItemIndexFromHXCGUI(m_hList,hEle);
		XAdTable_SetItemTextEx(hAdapter,nIndex,L"name3",(wchar_t*)&bCheck);

		if (bCheck)
		{
			wchar_t tmp[MAX_PATH]={0};
			for (int i= 1;i <= 5;i++)
			{
				wsprintfW(tmp,L"new item-%d",i);
				int nItem = XAdTable_InsertItemText(hAdapter,nIndex+i,tmp);

				wsprintfW(tmp,L"child-%d-1",i);
				XAdTable_SetItemText(hAdapter,nIndex+i,1,tmp);

				XAdTable_SetItemText(hAdapter,nIndex+i,2,L"1");
			}

		}else
		{
// 			//收缩，删除选项
			int nStart = nIndex+1;
			int nEnd   = nIndex+1;
			int nDelCount = XAdTable_GetCount(hAdapter);

			for (int i = 0; i < nDelCount; i++)
			{
				if (XList_GetItemData(m_hList,nEnd,0) == 1)
				{
					break;
				}
				nEnd++;
			}

			XAdTable_DeleteItemEx(hAdapter,nStart,nEnd -nStart);

			//还可以用下面这种删除法


// 			int nDelCount = XAdTable_GetCount(hAdapter);
// 
// 			for (int i = 0; i < nDelCount; i++)
// 			{
// 				if (XList_GetItemData(m_hList,nIndex+1,0) == 0)
// 				{
// 					XAdTable_DeleteItem(hAdapter,nIndex+1);
// 				}
// 			}
// 			
		}
		XList_RefreshData(m_hList);

		
		return 0;
	}
	int OnListTemplateCreateEnd(list_item_i* pItem,BOOL *pbHandled)
	{
		int nGroup = XList_GetItemData(m_hList,pItem->index,0);
		if (nGroup != 0)
		{
			if (pItem->iSubItem == 0)
			{
				HELE hEle= (HELE)XList_GetTemplateObject(m_hList,pItem->index,1);
				XEle_ShowEle(hEle,FALSE);

				
				HXCGUI hBtn = XList_GetTemplateObject(m_hList,pItem->index,4);
				XC_OBJECT_TYPE type= XC_GetObjectType(hBtn);
				if (XC_IsHXCGUI(hBtn,XC_BUTTON))
				{
					XEle_RegEventCPP1((HELE)hBtn,XE_BUTTON_CHECK,&CMyWindowList::OnButtonCheck);
					
					int bCheck = FALSE;
					XAdTable_GetItemTextEx(hAdapter,
						pItem->index,L"name3",(wchar_t*)&bCheck,4);
					XBtn_SetCheck((HELE)hBtn,bCheck);
				}

			}
			else if (pItem->iSubItem == 1)
			{
				HELE hEle= (HELE)XList_GetTemplateObject(m_hList,pItem->index,3);
				XEle_ShowEle(hEle,FALSE);

			}
			
			*pbHandled = TRUE;
		}else
		{

			if (pItem->iSubItem == 0)
			{
				HELE hEle= (HELE)XList_GetTemplateObject(m_hList,pItem->index,2);
				XEle_ShowEle(hEle,FALSE);
			}
			
		}
		return 0;
	}
	int  OnTemplateAdjustCoordinate(list_item_i *pItem,BOOL *pbHandled)
    {
		int nGroup = XList_GetItemData(m_hList,pItem->index,0);
		if (nGroup != 0)
		{
			if(pItem->iSubItem == 0)
			{
				
				pItem->rcItem.left = -50;
				pItem->rcItem.right = XEle_GetWidth(m_hList);
				HELE hEle= (HELE)XList_GetTemplateObject(m_hList,pItem->index,2);
				XEle_SetRect(hEle,&pItem->rcItem);
//				XEle_ShowEle(hEle,FALSE);
			}
			
			*pbHandled = TRUE;
		}
        *pbHandled=TRUE;
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
