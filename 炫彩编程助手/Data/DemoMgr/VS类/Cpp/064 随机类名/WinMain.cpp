#include "Common.h"


class CRightPane
{
public:
	CRightPane()
	{
		m_IsMainWindowClose = FALSE;
	}
	int OnBtnSelectClick(BOOL *pbHandled)
	{
		SetSelectAll(TRUE);
		return 0;
	}
	int OnBtnUnSelectClick(BOOL *pbHandled)
	{
		SetSelectAll(FALSE);
		return 0;
	}
	void Create(HWINDOW hMainWindow)
	{
		m_hMainWindow = hMainWindow;
		m_hWindow = (HWINDOW)XC_LoadLayout(L"弹出窗口\\Layout.xml");

		m_hList = (HELE)XC_GetObjectByID(999);
		XEle_RegEventCPP(m_hList,XE_LIST_TEMP_CREATE_END,&CRightPane::OnListTemplateCreateEnd);

		m_ComboBoxAutoLogin = (HELE)XC_GetObjectByID(1001);
		m_ComboBoxVirtualType = (HELE)XC_GetObjectByID(1002);
		m_ComboBoxVirtualHardWare = (HELE)XC_GetObjectByID(1003);
		m_ComboBoxBoot = (HELE)XC_GetObjectByID(1004);
		m_ComboBoxAutoMinSize = (HELE)XC_GetObjectByID(1005);
		m_ComboBoxIpCount = (HELE)XC_GetObjectByID(1006);


		m_SelectAll = (HELE)XC_GetObjectByID(1100);
		m_UnSelectAll = (HELE)XC_GetObjectByID(1101);

		XEle_RegEventCPP(m_SelectAll,XE_BNCLICK,&CRightPane::OnBtnSelectClick);
		XEle_RegEventCPP(m_UnSelectAll,XE_BNCLICK,&CRightPane::OnBtnUnSelectClick);


		XWnd_RegEventCPP(m_hMainWindow,WM_MOVE,&CRightPane::OnWndOther);
		XWnd_RegEventCPP(m_hMainWindow,WM_DESTROY,&CRightPane::OnWndDestroy);
		XWnd_RegEventCPP(m_hWindow,WM_CLOSE,&CRightPane::OnWndClose);

		XWnd_RegEventCPP(m_hWindow,WM_SETFOCUS,&CRightPane::OnWndSetFocus);
		XWnd_RegEventCPP(m_hMainWindow,WM_SETFOCUS,&CRightPane::OnMainWndSetFocus);
		XWnd_AdjustLayout(m_hWindow);
		Hide();
		InitSetting();
	}

	int GetItemCount()
	{
		HXCGUI hAdapter = XList_GetAdapter(m_hList);
		return XAdTable_GetCount(hAdapter);
	}
	BOOL IsItemSelect(int nIndex)
	{
		return XList_GetItemData(m_hList,nIndex,0);
	}
	void SetSelectAll(BOOL bSelect)
	{
		for (int i = 0; i < GetItemCount(); i++)
		{
			XList_SetItemData(m_hList,i,0,bSelect);
		}
		XList_RefreshData(m_hList);
		XEle_RedrawEle(m_hList);
	}


	void Show()
	{
		XWnd_ShowWindow(m_hWindow,SW_SHOW);
	}
	void Hide()
	{
		XWnd_ShowWindow(m_hWindow,SW_HIDE);
	}
	void AdjustPos()
	{
		RECT rtParent;
		GetWindowRect(XWnd_GetHWND(m_hMainWindow),&rtParent);
		
		RECT rtPaneWindow;
		GetWindowRect(XWnd_GetHWND(m_hWindow),&rtPaneWindow);
		
		MoveWindow(
			XWnd_GetHWND(m_hWindow),
			rtParent.right,
			rtParent.top,
			rtPaneWindow.right - rtPaneWindow.left,
			rtPaneWindow.bottom - rtPaneWindow.top,TRUE);
	}


	int OnWndSetFocus(BOOL *pbHandled)
	{
		//SetFocus(XWnd_GetHWND(m_hMainWindow));

		return 0;
	}
	int OnMainWndSetFocus(BOOL *pbHandled)
	{
		//SetFocus(XWnd_GetHWND(m_hWindow));
		return 0;
	}

	int OnListTemplateCreateEnd(list_item_i* pItem,BOOL *pbHandled)
	{
		
		if (pItem->iSubItem == 0) //按钮在第0列
		{
			HXCGUI hBtn = XList_GetTemplateObject(m_hList,pItem->index,1);
			if (XC_GetObjectType(hBtn) == XC_BUTTON)
			{
				//记住选中状态
				BOOL isCheck = XList_GetItemData(m_hList,pItem->index,pItem->iSubItem);
				XBtn_SetCheck((HELE)hBtn,isCheck);
				XEle_RegEventCPP1((HELE)hBtn,XE_BUTTON_CHECK,&CRightPane::OnButtonCheck);
			}
		}
		
		*pbHandled = TRUE;
		return 0;
	}
	int OnButtonCheck(HELE hEventEle,BOOL bCheck,BOOL *pbHandled)
	{
		//用行项目数据来保存 选中状态
		int item = XList_GetItemIndexFromHXCGUI(m_hList,hEventEle);
		XList_SetItemData(m_hList,item,0,XBtn_IsCheck(hEventEle));
		
		return 0;
	}

	int OnWndClose(BOOL *pbHandled)
	{
		if (m_IsMainWindowClose == FALSE)
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnWndDestroy(BOOL *pbHandled)
	{
		m_IsMainWindowClose = TRUE;
		XWnd_CloseWindow(m_hWindow);
		return 0;
	}
	int OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		AdjustPos();
		return 0;
	}

private:
	void InitSetting()
	{
		//组合框初始化
 
		{
			XComboBox_SetItemTemplateXML(m_ComboBoxAutoLogin,L"弹出窗口\\ComboBox_ListBox_Item.xml");
			XRichEdit_SetText(m_ComboBoxAutoLogin,L"假");
			HXCGUI hAdapter=XAdTable_Create();
			XComboBox_BindApapter(m_ComboBoxAutoLogin,hAdapter);
			XAdTable_AddColumn(hAdapter,L"name");
			
			XAdTable_AddItemText(hAdapter,L"假");
			XAdTable_AddItemText(hAdapter,L"真");
		}

		{
			XComboBox_SetItemTemplateXML(m_ComboBoxVirtualType,L"弹出窗口\\ComboBox_ListBox_Item.xml");
			XRichEdit_SetText(m_ComboBoxVirtualType,L"R0");
			HXCGUI hAdapter=XAdTable_Create();
			XComboBox_BindApapter(m_ComboBoxVirtualType,hAdapter);
			XAdTable_AddColumn(hAdapter,L"name");
			
			XAdTable_AddItemText(hAdapter,L"R0");
			XAdTable_AddItemText(hAdapter,L"R1");
			XAdTable_AddItemText(hAdapter,L"R2");
			XAdTable_AddItemText(hAdapter,L"R3");
		}

		{
			XComboBox_SetItemTemplateXML(m_ComboBoxVirtualHardWare,L"弹出窗口\\ComboBox_ListBox_Item.xml");
			XRichEdit_SetText(m_ComboBoxVirtualHardWare,L"假");
			HXCGUI hAdapter=XAdTable_Create();
			XComboBox_BindApapter(m_ComboBoxVirtualHardWare,hAdapter);
			XAdTable_AddColumn(hAdapter,L"name");
			
			XAdTable_AddItemText(hAdapter,L"假");
			XAdTable_AddItemText(hAdapter,L"真");
		}
		{
			//开机启动
			XComboBox_SetItemTemplateXML(m_ComboBoxBoot,L"弹出窗口\\ComboBox_ListBox_Item.xml");
			XRichEdit_SetText(m_ComboBoxBoot,L"假");
			HXCGUI hAdapter=XAdTable_Create();
			XComboBox_BindApapter(m_ComboBoxBoot,hAdapter);
			XAdTable_AddColumn(hAdapter,L"name");
			
			XAdTable_AddItemText(hAdapter,L"假");
			XAdTable_AddItemText(hAdapter,L"真");
		}

		{
			//自动最小化
			XComboBox_SetItemTemplateXML(m_ComboBoxAutoMinSize,L"弹出窗口\\ComboBox_ListBox_Item.xml");
			XRichEdit_SetText(m_ComboBoxAutoMinSize,L"假");
			HXCGUI hAdapter=XAdTable_Create();
			XComboBox_BindApapter(m_ComboBoxAutoMinSize,hAdapter);
			XAdTable_AddColumn(hAdapter,L"name");
			
			XAdTable_AddItemText(hAdapter,L"假");
			XAdTable_AddItemText(hAdapter,L"真");
		}
		{
			//每个IP窗口数
			XComboBox_SetItemTemplateXML(m_ComboBoxIpCount,L"弹出窗口\\ComboBox_ListBox_Item.xml");
			XRichEdit_SetText(m_ComboBoxIpCount,L"20");
			HXCGUI hAdapter=XAdTable_Create();
			XComboBox_BindApapter(m_ComboBoxIpCount,hAdapter);
			XAdTable_AddColumn(hAdapter,L"name");
			
			XAdTable_AddItemText(hAdapter,L"10");
			XAdTable_AddItemText(hAdapter,L"20");
			XAdTable_AddItemText(hAdapter,L"50");
			XAdTable_AddItemText(hAdapter,L"100");
			XAdTable_AddItemText(hAdapter,L"200");
		}

		//list 初始化
		XList_SetItemTemplateXML(m_hList,L"弹出窗口\\List.xml");

		XList_AddColumn(m_hList,40);
        XList_AddColumn(m_hList,80);
        XList_AddColumn(m_hList,100);
		
        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name",L"选择");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"有效期");
        XAdMap_AddItemText(hAdapterHeader,L"name3",L"备注");

		
        HXCGUI hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name");
        XAdTable_AddColumn(hAdapter,L"name2");
		
        XList_SetColumnWidth(m_hList,0,40);
        XList_SetColumnWidth(m_hList,1,80);
        XList_SetColumnWidth(m_hList,2,100);

		wchar_t tmp[MAX_PATH]={0};
		int nIndex = 0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
			nIndex = XAdTable_AddItemTextEx(hAdapter,L"name",tmp);;			
            wsprintfW(tmp,L"child-%d-1",i); 
			XAdTable_SetItemTextEx(hAdapter,nIndex,L"name2",tmp);
        }

	}


private:

	HWINDOW m_hWindow;
	HWINDOW m_hMainWindow;

	HELE    m_hList;
	BOOL    m_IsMainWindowClose;

	HELE    m_ComboBoxAutoLogin;
	HELE    m_ComboBoxVirtualType;
	HELE    m_ComboBoxVirtualHardWare;
	HELE    m_ComboBoxBoot;
	HELE    m_ComboBoxAutoMinSize;
	HELE    m_ComboBoxIpCount;


	HELE    m_SelectAll;
	HELE    m_UnSelectAll;
};


class CPopWindow
{
public:
	void Create()
	{
		m_hWindow = (HWINDOW)XC_LoadLayout(L"广告窗口\\Layout.xml");

		m_hStaticText = XC_GetObjectByID(2000);
		XWnd_AdjustLayout(m_hWindow);
		
		RECT rcWorkAre;
		SystemParametersInfo(SPI_GETWORKAREA, 0, (PVOID) &rcWorkAre, 0);

		RECT rtClient;
		XWnd_GetClientRect(m_hWindow,&rtClient);
		
		SetAdText(L"我是大色秘密\r\n我是中色秘密\r\n我是小色秘密");

		MoveWindow(
			XWnd_GetHWND(m_hWindow),
			rcWorkAre.right-rtClient.right,
			rcWorkAre.bottom-rtClient.bottom,
			rtClient.right,
			rtClient.bottom,TRUE);
		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CPopWindow::OnWndTimer);
		XWnd_RegEventCPP(m_hWindow,WM_DESTROY ,&CPopWindow::OnWndDestroy);
		XWnd_SetTimer(m_hWindow,110,30*1000);
		XWnd_ShowWindow(m_hWindow,SW_SHOW);
	}

	void SetAdText(const wchar_t* pAdText)
	{
		XShapeText_SetText(m_hStaticText,pAdText);
	}

	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		if (nIDEvent == 110)
		{
			XWnd_KillTimer(m_hWindow,110);
			XWnd_CloseWindow(m_hWindow);
		}
		return 0;
	}
	int OnWndDestroy(BOOL *pbHandled)
	{
		delete this;
		return 0;
	}

private:
	HWINDOW m_hWindow;
	HXCGUI  m_hStaticText;
};




class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;

	CRightPane m_RightPane;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
		XC_RegisterWindowClassName(L"大色秘密");
		m_hWindow = XWnd_CreateEx(NULL,L"大色秘密",L"代理IP",WS_VISIBLE,0, 0, 300, 200);
        //m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);


        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_hButton = XBtn_Create(100, 50, 80, 25,L"显示更随", m_hWindow);
		XBtn_SetType(m_hButton,button_type_check);
        XEle_RegEventCPP(m_hButton,XE_BUTTON_CHECK,&CMyWindowButton::OnButtonCheck);


		HELE hBtn = XBtn_Create(100, 100, 80, 25,L"弹出广告", m_hWindow);

		XEle_RegEventCPP(hBtn,XE_BNCLICK,&CMyWindowButton::OnBtnClick);


		//主要代码。。。。
		m_RightPane.Create(m_hWindow);
		m_RightPane.AdjustPos();


        XWnd_ShowWindow(m_hWindow,SW_SHOW);

    }
	int OnBtnClick(BOOL *pbHandled)
	{
		CPopWindow* pPopWnd = new CPopWindow;
		pPopWnd->Create();
		return 0;
	}

	int OnButtonCheck(BOOL bCheck,BOOL *pbHandled)
	{
		if (bCheck)
		{
			m_RightPane.Show();
		//	m_RightPane.SetSelectAll(TRUE);
		} 
		else
		{
			m_RightPane.Hide();
		}
		
		for (int i = 0; i < m_RightPane.GetItemCount(); i++)
		{
			BOOL bCheck = m_RightPane.IsItemSelect(i);
		}

		return 0;
	}
};



int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowButton  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




