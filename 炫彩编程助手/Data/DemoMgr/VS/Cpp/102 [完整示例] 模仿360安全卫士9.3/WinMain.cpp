#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	
	HELE m_hProgBarScan;

    BOOL Create() //创建窗口和按钮
    {

		XC_LoadResource(L"res\\resource.xml",L"res");
		m_hWindow =(HWINDOW) XC_LoadLayout(L"res\\layout.xml");

		InitPage1();

		XWnd_AdjustLayout(m_hWindow);
		XWnd_ShowWindow(m_hWindow,SW_SHOW);
		return TRUE;
    }
	void InitPage1()
	{
		//影藏应用页面
		HELE hBtn = GetEleByRes(m_hWindow, L"ID_btn_hide_Pane2");
		XEle_RegEventCPP(hBtn,XE_BNCLICK,&CMyWnd::OnBtnHidePane2Click);
		
		//更多按钮
		hBtn = GetEleByRes(m_hWindow,L"ID_btn_show_pane2");
		XEle_RegEventCPP(hBtn,XE_BNCLICK,&CMyWnd::OnBtnShowPane2Click);
		

		//扫描进度条
		m_hProgBarScan = GetEleByRes(m_hWindow,L"ID_progbar_scan");
		XProgBar_SetSpaceTwo(m_hProgBarScan,0,0);
		XProgBar_SetPos(m_hProgBarScan,0);
		XEle_SetUserData(m_hProgBarScan,0);


		//注册时钟，显示体检进度条
		XWnd_SetTimer(m_hWindow,100,10);
		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CMyWnd::OnWndTimer);


		//初始化电脑体检树
		InitTreeTiJian();
	}
	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		if (nIDEvent == 100)
		{
			int nCurPos = XEle_GetUserData(m_hProgBarScan);
			nCurPos++;
			if (nCurPos > 100)
			{
				nCurPos = 0;
//				XWnd_KillTimer(m_hWindow,100);
			}
			XProgBar_SetPos(m_hProgBarScan,nCurPos);
			XEle_SetUserData(m_hProgBarScan,nCurPos);
			XEle_RedrawEle(m_hProgBarScan,TRUE);
		}
		return 0;
	}

	int OnBtnShowPane2Click(BOOL *pbHandled)
	{
		
		HELE hPane2 = GetEleByRes(m_hWindow,L"ID_page1_pane2");
		XEle_ShowEle(hPane2,TRUE);
		XWnd_RedrawWnd(m_hWindow);
		return 0;
	}
	int OnBtnHidePane2Click(BOOL *pbHandled)
	{

		HELE hPane2 = GetEleByRes(m_hWindow,L"ID_page1_pane2");
		XEle_ShowEle(hPane2,FALSE);
		XWnd_RedrawWnd(m_hWindow);
		return 0;
	}


	//电脑体检
	HTEMP m_pTemplate_group;
	HELE m_hTree;
	void InitTreeTiJian()
	{
		m_hTree = GetEleByRes(m_hWindow,L"ID_Tree_tijian");
		XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWnd::OnTreeTemplateCreate);

		HXCGUI hAdapter = XAdTree_Create();
		XTree_BindAdapter(m_hTree,hAdapter);

		XTree_SetItemTemplateXML(m_hTree,L"res\\Treetijian\\Tree_Item_friend.xml");
		m_pTemplate_group = XTemp_Load(listItemTemp_type_tree,L"res\\Treetijian\\Tree_Item_group.xml");

		//这三个是字段是对应分组的数据
		XAdTree_AddColumn(hAdapter,L"name1"); //
		XAdTree_AddColumn(hAdapter,L"name2"); //
		XAdTree_AddColumn(hAdapter,L"name3"); //

		//这里两个字段是对应普通子项的数据
		XAdTree_AddColumn(hAdapter,L"name4");
		XAdTree_AddColumn(hAdapter,L"name5");

		HIMAGE hImage = NULL;

		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\safeitem_fine.png");
		int nGroup1 = XAdTree_InsertItemImage(hAdapter,hImage);
		XAdTree_SetItemText(hAdapter,nGroup1,1,L"安全检测(检测是否有木马、病毒、漏洞)");
		XAdTree_SetItemText(hAdapter,nGroup1,2,L"4");


		XTree_SetItemHeight(m_hTree,nGroup1,40,40);
		XTree_EnableConnectLine(m_hTree,FALSE,FALSE);


		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
		int nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
		XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"开机自启动");
		XTree_SetItemHeight(m_hTree,nItem,25,25);
		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
		XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);


		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
		nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
		XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"开机自启动2");
		XTree_SetItemHeight(m_hTree,nItem,25,25);
		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
		XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);


		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Tail_Icon.png");
		nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
		XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"开机自启动3");
		XTree_SetItemHeight(m_hTree,nItem,25,25);
		hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
		XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);

		{
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\Fault_fine.png");
			nGroup1 = XAdTree_InsertItemImage(hAdapter,hImage);
			XAdTree_SetItemText(hAdapter,nGroup1,1,L"故障检测(检测电脑硬件、软件是否有故障)");
			XAdTree_SetItemText(hAdapter,nGroup1,2,L"4");
			XTree_SetItemHeight(m_hTree,nGroup1,40,40);
			
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
			nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);	
			XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"开机自启动");
			XTree_SetItemHeight(m_hTree,nItem,25,25);
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
			XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);
			
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Icon.png");
			nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);
			XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"开机自启动2");
			XTree_SetItemHeight(m_hTree,nItem,25,25);			
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
			XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);

			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\2nd_Tail_Icon.png");
			nItem = XAdTree_InsertItemImage(hAdapter,hImage,nGroup1);			
			XAdTree_SetItemTextEx(hAdapter,nItem,L"name4",L"开机自启动3");
			XTree_SetItemHeight(m_hTree,nItem,25,25);
			hImage = XImage_LoadFile(L".\\res\\image\\page1\\2\\ItemOkIcon.png");
			XAdTree_SetItemImageEx(hAdapter,nItem,L"name5",hImage);

		}

	}

	int OnTreeTemplateCreate(tree_item_i* pItem,BOOL *pbHandled)
	{
        if(XC_ID_ERROR!=XTree_GetFirstChildItem(m_hTree,pItem->nID))
        {
            if(m_pTemplate_group)
                pItem->hTemp=m_pTemplate_group;
        }
        *pbHandled=TRUE;
		return 0;
	}

	//初始化功能app
	void InitListViewApp()
	{
		HELE hTree = GetEleByRes(m_hWindow,L"ID_ListView_app");
	}

private:
	HELE GetEleByRes(HWINDOW hWindow, const wchar_t* pResStr)
	{
		return (HELE) XC_GetObjectByID(hWindow, XRes_GetIDValue(pResStr));
	}

	HIMAGE GethImageByRes(HWINDOW hWindow,const wchar_t* pResStr)
	{
		return (HIMAGE) XC_GetObjectByID(hWindow, XRes_GetIDValue(pResStr));
	}

};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




