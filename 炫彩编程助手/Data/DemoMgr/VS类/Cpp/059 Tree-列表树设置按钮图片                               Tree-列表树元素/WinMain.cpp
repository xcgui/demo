#include "Common.h"

class CMyWindowTree
{
public:
    xcgui::XWnd m_Wnd;
	xcgui::XTree m_tree;
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
        
        int idc1=adapter.InsertItemText(L"Item1------1",1,XC_ID_LAST);
        int idc2=adapter.InsertItemText(L"Item1------2",1,XC_ID_LAST);
        int idc2_1=adapter.InsertItemText(L"Item1-----2--1",idc2,XC_ID_LAST);
        
        XEle_RegEventCPP(m_tree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_tree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);
		
        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
		XEle_RegEventCPP(m_tree,XE_TREE_TEMP_CREATE_END,&CMyWindowTree::OnTreeTemplateCreateEnd);

        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);
		
        m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnTreeTemplateCreateEnd(tree_item_i* pItem,BOOL *pbHandled)
	{
		HELE hBtn = (HELE)m_tree.GetTemplateObject(pItem->nID,1);

		if (XC_GetObjectType(hBtn) == XC_BUTTON)
		{
			HIMAGE imageUnCheck = XImage_LoadFile(L"收.png");
			HIMAGE imageCheck = XImage_LoadFile(L"开.png");

			XBtn_SetStyle(hBtn,button_style_default);
			HBKM hBkInfoM  = XEle_GetBkManager(hBtn);
			XBkM_AddImage(hBkInfoM,button_state_flag_check,imageCheck);
			XBkM_AddImage(hBkInfoM,button_state_flag_check_no,imageUnCheck);

		}
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
