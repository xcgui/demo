#include "Common.h"




class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;
    HIMAGE  m_hUserPic;
	HXCGUI hAdapter;


    HTEMP  m_pTemplate_group;
    HTEMP  m_pTemplate_sel;
    CMyWindowTree()
    {
        m_pTemplate_group=NULL;
        Init();
    }
    void Release()
    {
        if(m_pTemplate_group) XTemp_Destroy(m_pTemplate_group);
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
		XTree_EnableConnectLine(m_hTree,FALSE,FALSE);


        m_hUserPic=XImage_LoadFile(L"avatar.png");


        hAdapter=XAdTree_Create();
        XTree_BindAdapter(m_hTree,hAdapter);

		XAdTree_AddColumn (hAdapter, L"name1");//  ' ; //昵称 分组名
		XAdTree_AddColumn (hAdapter, L"userPic");//  ' ; //小头像
		XAdTree_AddColumn (hAdapter, L"msgCount");//  ' ; //标示消息数量


        wchar_t  buf[256]={0};
        int nGroupID=0;
        int nItemID=0;
        for (int iGroup=0;iGroup<5;iGroup++)
        {
            wsprintfW(buf,L"好友分组-%d",iGroup);
            nGroupID=XAdTree_InsertItemText(hAdapter,buf,XC_ID_ROOT,XC_ID_LAST);
            XTree_SetItemHeight(m_hTree,nGroupID,26,26);
            for (int i=0;i<3;i++)
            {
                wsprintfW(buf,L"我的好友-%d",i);
        nItemID = XAdTree_InsertItemText (hAdapter, buf, nGroupID, XC_ID_LAST);
        XAdTree_SetItemImageEx (hAdapter, nItemID, L"userPic", m_hUserPic);
        XAdTree_SetItemTextEx (hAdapter, nItemID, L"msgCount", L"10");

            }
        }

        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);

        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
		XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE_END,&CMyWindowTree::OnTreeTemplateCreateEnd);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnTreeSelect(int nItemID,BOOL *pbHandled)
    {
		XAdTree_SetItemTextEx(hAdapter,nItemID,L"msgCount",L"0");
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
            if(m_pTemplate_group)
                pItem->hTemp=m_pTemplate_group;
        }
        *pbHandled=TRUE;
        return 0;
    }
	int OnTreeTemplateCreateEnd(tree_item_i* pItem,BOOL *pbHandled)
	{
		HXCGUI hBtn = XTree_GetTemplateObject(m_hTree,pItem->nID,6);

		if (XC_IsHXCGUI(hBtn,XC_BUTTON))
		{
			wchar_t buf[MAX_PATH] = {0};
			XAdTree_GetItemTextEx(hAdapter,pItem->nID,L"msgCount",buf,MAX_PATH);
			if (buf[0] == L'0')
			{
				XEle_ShowEle((HELE)hBtn,FALSE);
			}
		}
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

