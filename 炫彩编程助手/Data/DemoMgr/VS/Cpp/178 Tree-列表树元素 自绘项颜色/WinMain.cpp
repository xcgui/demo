#include "Common.h"

class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;
    CMyWindowTree()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(400, 200, 350, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
        
        m_hTree= XTree_Create(20,40,300,300,m_hWindow);
        XTree_SetItemTemplateXML(m_hTree,L"Tree_Item.xml");
		
        HXCGUI hAdapter=XAdTree_Create();
        XTree_BindAdapter(m_hTree,hAdapter);
        XAdTree_AddColumn(hAdapter,L"name1");
        
        wchar_t  buf[256]={0};
        int id=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
            id=XAdTree_InsertItemText(hAdapter,buf,XC_ID_ROOT,XC_ID_LAST);
        }
        
        int idc1=XAdTree_InsertItemText(hAdapter,L"Item1------1",1,XC_ID_LAST);
        int idc2=XAdTree_InsertItemText(hAdapter,L"Item1------2",1,XC_ID_LAST);
        int idc2_1=XAdTree_InsertItemText(hAdapter,L"Item1-----2--1",idc2,XC_ID_LAST);
        
        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);
		
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);
		XEle_RegEventCPP(m_hTree,XE_TREE_DRAWITEM,&CMyWindowTree::OnTreeDrawItem);
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnTreeDrawItem(HDRAW hDraw,tree_item_i* pItem,BOOL *pbHandled)
	{
		if (pItem->nID % 2)
		{
			XDraw_FillRectColor(hDraw,&pItem->rcItem,RGB(128,0,0));
		}else
		{
			XDraw_FillRectColor(hDraw,&pItem->rcItem,RGB(0,128,0));
		}

		//如果拦截了，那么系统的所有状态就不会绘制了
		//所以这里大家要自己处理所有状态，选中离开，停留等状态的绘制
		//这里我只是简单的演示一下如何来绘制
		*pbHandled = TRUE;
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
    CMyWindowTree  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
