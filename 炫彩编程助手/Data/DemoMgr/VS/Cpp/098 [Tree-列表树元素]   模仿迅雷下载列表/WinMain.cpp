#include "Common.h"




class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;

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
        m_hWindow = XWnd_Create(0, 0, 600, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
        
        m_hTree= XTree_Create(20,40,500,350,m_hWindow);
        XTree_SetItemHeightDefault(m_hTree,28,54);
        XTree_SetItemTemplateXML(m_hTree,L"Tree_Item_friend.xml");
        XTree_SetItemTemplateXMLSel(m_hTree,L"Tree_Item_friend_sel.xml");
		XTree_EnableConnectLine(m_hTree,FALSE,FALSE);

		HBKM hBkInfoM = XEle_GetBkManager(m_hTree);
		XBkM_AddFill(hBkInfoM,tree_state_flag_item_select,RGB(210,239,255),255);
		XBkM_AddFill(hBkInfoM,tree_state_flag_item_leave,RGB(255,255,255),0);
	
		XBkM_AddFill(hBkInfoM,element_state_flag_leave,RGB(255,255,255),255);


        HXCGUI hAdapter=XAdTree_Create();
        XTree_BindAdapter(m_hTree,hAdapter);
        XAdTree_AddColumn(hAdapter,L"name1"); //昵称 分组名
        XAdTree_AddColumn(hAdapter,L"name2"); //签名 
        XAdTree_AddColumn(hAdapter,L"name3"); //小头像
         XAdTree_AddColumn(hAdapter,L"name4"); //大头像
         XAdTree_AddColumn(hAdapter,L"name5"); //VIP 图标
         XAdTree_AddColumn(hAdapter,L"name6"); //空间图标
         XAdTree_AddColumn(hAdapter,L"name7"); //VIP 图标
         XAdTree_AddColumn(hAdapter,L"name8"); //空间图标

		 XAdTree_AddColumn(hAdapter,L"name9"); //空间图标

        wchar_t  buf[256]={0};
        int nGroupID=0;
        int nItemID=0;
        for (int iGroup=0;iGroup<5;iGroup++)
        {
            wsprintfW(buf,L"QQ聊天软件%d",iGroup);
            nGroupID=XAdTree_InsertItemImageEx(hAdapter,L"name9",XImage_LoadFile(L"ico.png"),XC_ID_ROOT,XC_ID_LAST);
            XTree_SetItemHeight(m_hTree,nGroupID,40,80);

			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name1",buf);
			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name2",L"128 MB");
			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name3",L"暂停");

			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name4",L"55.00%");
			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name5",L"高速通道服务暂停中");
			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name6",L"等待取回本地");
			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name7",L"接收 60 MB");
			XAdTree_SetItemTextEx(hAdapter,nGroupID,L"name8",L"接收 10 MB");
        }

        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);

		XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE_END,&CMyWindowTree::OnTreeTemplateCreateEnd);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnTreeTemplateCreateEnd(tree_item_i* pItem,BOOL *pbHandled)
	{

		HXCGUI hProgBar = XTree_GetTemplateObject(m_hTree,pItem->nID,2);
		if (XC_IsHXCGUI(hProgBar,XC_PROGRESSBAR))
		{
			XProgBar_SetSpaceTwo((HELE)hProgBar,0,0);
			XProgBar_SetPos((HELE)hProgBar,50);
			XProgBar_SetImageLoad((HELE)hProgBar,XImage_LoadFile(L"jindu.png",TRUE)); //进度条在这里贴图
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
//         if(XC_ID_ERROR!=XTree_GetFirstChildItem(m_hTree,pItem->nID))
//         {
//             if(m_pTemplate_group)
//                 pItem->pInfo=m_pTemplate_group;
//         }
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

