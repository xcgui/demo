#include "Common.h"




class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;
    HIMAGE  m_hVip;
    HIMAGE  m_hQZone;
    HIMAGE  m_hAvatar;
    HIMAGE  m_hAvatarLarge;

    HTEMP  m_pTemplate_group;
	HTEMP  m_pTemplate_group2;
	HTEMP  m_pTemplate_group3;
    HTEMP  m_pTemplate_sel;
    CMyWindowTree()
    {
        m_pTemplate_group=NULL;
        Init();
    }
    void Release()
    {
        if(m_pTemplate_group) XTemp_Destroy(m_pTemplate_group);
		if(m_pTemplate_group2) XTemp_Destroy(m_pTemplate_group2);
		if(m_pTemplate_group3) XTemp_Destroy(m_pTemplate_group3);
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 320, 520, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
        
        m_hTree= XTree_Create(20,40,280,450,m_hWindow);
        XTree_SetItemHeightDefault(m_hTree,28,54);
        XTree_SetItemTemplateXML(m_hTree,L"Tree_Item_friend.xml");
        XTree_SetItemTemplateXMLSel(m_hTree,L"Tree_Item_friend_sel.xml");
        m_pTemplate_group=XTemp_Load(listItemTemp_type_tree,L"Tree_Item_group.xml");
		m_pTemplate_group2=XTemp_Load(listItemTemp_type_tree,L"Tree_Item_group2.xml");
		m_pTemplate_group3=XTemp_Load(listItemTemp_type_tree,L"Tree_Item_group3.xml");
		XTree_EnableConnectLine(m_hTree,FALSE,FALSE);

        m_hVip=XImage_LoadFile(L"vip.png");
        m_hQZone=XImage_LoadFile(L"QZone.png");
        m_hAvatar=XImage_LoadFile(L"avatar.png");
        m_hAvatarLarge=XImage_LoadFile(L"avatar_large.png");

        HXCGUI hAdapter=XAdTree_Create();
        XTree_BindAdapter(m_hTree,hAdapter);
        XAdTree_AddColumn(hAdapter,L"name1"); //昵称 分组名
        XAdTree_AddColumn(hAdapter,L"name2"); //签名 
        XAdTree_AddColumn(hAdapter,L"name3"); //小头像
        XAdTree_AddColumn(hAdapter,L"name4"); //大头像
        XAdTree_AddColumn(hAdapter,L"name5"); //VIP 图标
        XAdTree_AddColumn(hAdapter,L"name6"); //空间图标
		XAdTree_AddColumn(hAdapter,L"name7"); //空间图标
		XAdTree_AddColumn(hAdapter,L"name8"); //空间图标

        wchar_t  buf[256]={0};
        int nGroupID=0;
        int nItemID=0;
        for (int iGroup=0;iGroup<5;iGroup++)
        {
            wsprintfW(buf,L"好友分组-%d",iGroup);
            nGroupID=XAdTree_InsertItemText(hAdapter,buf,XC_ID_ROOT,XC_ID_LAST);

			XAdTree_SetItemImageEx(hAdapter,nGroupID,L"name7",m_hVip);
			XAdTree_SetItemImageEx(hAdapter,nGroupID,L"name8",m_hVip);

            XTree_SetItemHeight(m_hTree,nGroupID,26,26);
            for (int i=0;i<3;i++)
            {
                wsprintfW(buf,L"我的好友-%d",i);
                nItemID=XAdTree_InsertItemText(hAdapter,buf,nGroupID,XC_ID_LAST);
                XAdTree_SetItemTextEx(hAdapter,nItemID,L"name2",L"我的个性签名!");
                XAdTree_SetItemImageEx(hAdapter,nItemID,L"name5",m_hVip);
                XAdTree_SetItemImageEx(hAdapter,nItemID,L"name6",m_hQZone);
                XAdTree_SetItemImageEx(hAdapter,nItemID,L"name3",m_hAvatar);
                XAdTree_SetItemImageEx(hAdapter,nItemID,L"name4",m_hAvatarLarge);

            }
        }

        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);

        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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
        if(XC_ID_ERROR!=XTree_GetFirstChildItem(m_hTree,pItem->nID))
        {

			if (pItem->nID == 5)
			{
				if(m_pTemplate_group2)
					pItem->hTemp=m_pTemplate_group2;
			}else if (pItem->nID == 9)
			{
				if(m_pTemplate_group3)
					pItem->hTemp=m_pTemplate_group3;
			}else
			{
				if(m_pTemplate_group)
					pItem->hTemp=m_pTemplate_group;
			}

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
    MyWindow.Release();
    XExitXCGUI();
    return TRUE;
}

