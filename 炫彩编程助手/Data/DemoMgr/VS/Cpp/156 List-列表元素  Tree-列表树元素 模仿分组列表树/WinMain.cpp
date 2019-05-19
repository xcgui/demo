#include "Common.h"

class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;

	HELE    m_hList;
    CMyWindowTree()
    {
        Init();
    }
	int OnListHeaderItemWidthChange(int iItem, int nWidth,BOOL *pbHandled)
	{
		XTree_RefreshData(m_hTree);
		XEle_RedrawEle(m_hTree,TRUE);
		return 0;
	}
    void Init()
    {
		m_hWindow =(HWINDOW) XC_LoadLayout(L"ListTree\\layout.xml");


		m_hList = (HELE)XC_GetObjectByID(m_hWindow,10);
		XList_SetItemTemplateXML(m_hList,L"ListTree\\List_Item.xml");
		XList_AddColumn(m_hList,200);
		XList_AddColumn(m_hList,100);
		XList_AddColumn(m_hList,100);

		XEle_RegEventCPP(m_hList,XE_LIST_HEADER_WIDTH_CHANGE,&CMyWindowTree::OnListHeaderItemWidthChange);

		HXCGUI hAdapterMap = XAdMap_Create();
		XAdMap_AddItemText(hAdapterMap,L"name1",L"进程名");
		XAdMap_AddItemText(hAdapterMap,L"name2",L"PID");
		XAdMap_AddItemText(hAdapterMap,L"name3",L"父进程");

		XList_BindAdapterHeader(m_hList,hAdapterMap);

		XSView_EnableAutoShowScrollBar(m_hList,FALSE);
		XSView_ShowSBarH(m_hList,FALSE);
		XSView_ShowSBarV(m_hList,FALSE);

        
		m_hTree= (HELE)XC_GetObjectByID(m_hWindow,11);
        XTree_SetItemTemplateXML(m_hTree,L"ListTree\\Tree_Item.xml");
		XTree_SetItemHeightDefault(m_hTree,30,30);
		
        HXCGUI hAdapter=XAdTree_Create();
        XTree_BindAdapter(m_hTree,hAdapter);
        XAdTree_AddColumn(hAdapter,L"name1");
		XAdTree_AddColumn(hAdapter,L"name2");
		XAdTree_AddColumn(hAdapter,L"name3");
        
        wchar_t  buf[256]={0};
        int id=0;
        for (int i=0;i<2;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
            id=XAdTree_InsertItemText(hAdapter,buf,XC_ID_ROOT,XC_ID_LAST);
			XAdTree_SetItemText(hAdapter,id,1,L"100");
			XAdTree_SetItemText(hAdapter,id,2,L"explorer.exe");
        }
        
        int idc1=XAdTree_InsertItemText(hAdapter,L"Item1------1",1,XC_ID_LAST);
		XAdTree_SetItemText(hAdapter,idc1,1,L"100");
		XAdTree_SetItemText(hAdapter,idc1,2,L"explorer.exe");
        int idc2=XAdTree_InsertItemText(hAdapter,L"Item1------2",1,XC_ID_LAST);
		XAdTree_SetItemText(hAdapter,idc2,1,L"100");
		XAdTree_SetItemText(hAdapter,idc2,2,L"explorer.exe");

        int idc2_1=XAdTree_InsertItemText(hAdapter,L"Item1-----2--1",idc2,XC_ID_LAST);
		XAdTree_SetItemText(hAdapter,idc2_1,1,L"100");
		XAdTree_SetItemText(hAdapter,idc2_1,2,L"explorer.exe");

        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);
		
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
		XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE_END,&CMyWindowTree::OnTreeTemplateCreateEnd);

        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);
		
		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnTreeTemplateCreateEnd(tree_item_i* pItem,BOOL *pbHandled)
	{
		int nTemp = XTree_GetIndentation (m_hTree);
		BorderSize_i bi;
		XSView_GetBorderSize(m_hTree,&bi);

		{
			HELE hEle1 = (HELE)XTree_GetTemplateObject(m_hTree,pItem->nID,10);
			if (XC_IsHELE(hEle1))
			{
				RECT rt;
				XEle_GetRect(hEle1,&rt);
				
				int nWidth = XList_GetColumnWidth(m_hList,0);
				XEle_SetLayoutWidth(hEle1,layout_size_type_fixed,nWidth-nTemp*pItem->nDepth-bi.leftSize);
			}
		}
		{
			HELE hEle1 = (HELE)XTree_GetTemplateObject(m_hTree,pItem->nID,11);
			if (XC_IsHELE(hEle1))
			{
				// 				RECT rt;
				// 				XEle_GetRect(hEle1,&rt);
				int nWidth = XList_GetColumnWidth(m_hList,1);
				XEle_SetLayoutWidth(hEle1,layout_size_type_fixed,nWidth);
			}
		}
		// 		{
		// 			HELE hEle1 = (HELE)XTree_GetTemplateObject(m_hTree,pItem->nID,12);
		// 			if (XC_IsHELE(hEle1))
		// 			{
		// 				RECT rt;
		// 				XEle_GetRect(hEle1,&rt);
		// 				int nWidth = XList_GetColumnWidth(m_hList,2);
		// 				XEle_SetLayoutWidth(hEle1,layout_size_type_fixed,nWidth-rt.left);
		// 			}
		// 		}

		return 0;
	}
    int OnTreeSelect(int nItemID,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int OnTreeExpand(int id,BOOL bExpand,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateCreate(tree_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateDestroy(tree_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateAdjustCoordinate(tree_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
//	XC_ShowLayoutFrame(TRUE);
    CMyWindowTree  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
