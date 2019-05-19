#include "Common.h"


class CMyWindowTree
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XTree m_tree;

    HIMAGE  m_hVip;
    HIMAGE  m_hQZone;
    HIMAGE  m_hAvatar;
    HIMAGE  m_hAvatarLarge;

	xcgui::XTemplate m_template_group;
    CMyWindowTree()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 350, 500, L"炫彩界面库窗口");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);

        
		m_tree.Create(20,40,280,450,m_Wnd);
		m_tree.SetItemHeightDefault(28,54);
        m_tree.SetItemTemplateXML(L"Tree_Item_friend.xml");
		m_tree.SetItemTemplateXMLSel(L"Tree_Item_friend_sel.xml");
		m_template_group.Load(XC_TREE,L"Tree_Item_group.xml");

		m_tree.EnableConnectLine(FALSE,FALSE);
        m_hVip=XImage_LoadFile(L"vip.png");
        m_hQZone=XImage_LoadFile(L"QZone.png");
        m_hAvatar=XImage_LoadFile(L"avatar.png");
        m_hAvatarLarge=XImage_LoadFile(L"avatar_large.png");

		xcgui::XAdTree adapter;
        m_tree.BindAdapter(adapter);

        adapter.AddColumn(L"name"); //昵称 分组名
        adapter.AddColumn(L"name2"); //签名 
        adapter.AddColumn(L"name3"); //小头像
        adapter.AddColumn(L"name4"); //大头像
        adapter.AddColumn(L"name5"); //VIP 图标
        adapter.AddColumn(L"name6"); //空间图标

        wchar_t  buf[256]={0};
        int nGroupID=0;
        int nItemID=0;
        for (int iGroup=0;iGroup<5;iGroup++)
        {
            wsprintfW(buf,L"好友分组-%d",iGroup);
            nGroupID=adapter.InsertItemText(buf,XC_ID_ROOT,XC_ID_LAST);
            m_tree.SetItemHeight(nGroupID,26,26);
            for (int i=0;i<3;i++)
            {
                wsprintfW(buf,L"我的好友-%d",i);
                nItemID=adapter.InsertItemText(buf,nGroupID,XC_ID_LAST);
                adapter.SetItemTextEx(nItemID,L"name2",L"我的个性签名!");
                adapter.SetItemImageEx(nItemID,L"name5",m_hVip);
                adapter.SetItemImageEx(nItemID,L"name6",m_hQZone);
                adapter.SetItemImageEx(nItemID,L"name3",m_hAvatar);
                adapter.SetItemImageEx(nItemID,L"name4",m_hAvatarLarge);
            }
        }

        XEle_RegEventCPP(m_tree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_tree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);

        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_tree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);

        m_Wnd.ShowWindow(SW_SHOW);
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
        if(XC_ID_ERROR!=m_tree.GetFirstChildItem(pItem->nID))
        {
			pItem->pInfo = m_template_group;
        }
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

