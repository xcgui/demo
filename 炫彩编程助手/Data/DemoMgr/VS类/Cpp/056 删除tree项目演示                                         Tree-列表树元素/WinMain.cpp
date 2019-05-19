#include "Common.h"

class CMyWindowTree
{
public:
    xcgui::XWnd m_Wnd;
	xcgui::XTree m_tree;
    HELE    m_hTree;
	HXCGUI hAdapter;
    CMyWindowTree()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 350, 400, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);



		
        m_tree.Create(20,40,300,300,m_Wnd);
        m_tree.SetItemTemplateXML(L"Tree_Item.xml");
		
		xcgui::XAdTree adapter;
        m_tree.BindAdapter(adapter);
        adapter.AddColumn(L"name");
		
        
        wchar_t  buf[256]={0};
        int id=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
            id=adapter.InsertItemText(buf,XC_ID_ROOT,XC_ID_LAST);
        }
        
		xcgui::XBtn delbtn(100,5,100,20,L"删除选中项",m_Wnd);
		XEle_RegEventCPP(delbtn,XE_BNCLICK,&CMyWindowTree::OnBtnClick);
//         int idc1=XAdTree_InsertItemText(hAdapter,L"Item1------1",1,XC_ID_LAST);
//         int idc2=XAdTree_InsertItemText(hAdapter,L"Item1------2",1,XC_ID_LAST);
//         int idc2_1=XAdTree_InsertItemText(hAdapter,L"Item1-----2--1",idc2,XC_ID_LAST);
        
        XEle_RegEventCPP(m_tree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_tree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);
		
        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);
		
        m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnBtnClick(BOOL *pbHandled)
	{
		int nSelect = m_tree.GetSelectItem();
		if (nSelect != -1)
		{
			m_tree.GetAdapter().DeleteItem(nSelect);
			m_tree.RedrawEle();
		}
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
