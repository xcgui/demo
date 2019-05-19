#include "Common.h"

class CPopList
{
public:
	CPopList()
	{
		m_nHeight = 100; //显示高度默认100
	}
	BOOL Create(int x,int y,int cx,int cy,HELE hParentRichEdit)
	{
		m_hParentRichEdit = hParentRichEdit;
		m_hPopWindow = XWnd_Create(x,y,cx,cy,NULL,XEle_GetHWND(hParentRichEdit),0);


		CreateList();             //创建list控件

		XWnd_BindLayoutEle(m_hPopWindow,window_position_body,m_hList);      //将其绑定到body区域

		XEle_RegEventCPP(m_hParentRichEdit,XE_KEYDOWN,&CPopList::OnEventKeyDown);
		XWnd_RegEventCPP(XEle_GetHWINDOW(hParentRichEdit),WM_MOVE,&CPopList::OnMainWndMove);
		return m_hList?TRUE:FALSE;
	}
	VOID Show()
	{
		SetPos();
		XWnd_ShowWindow(m_hPopWindow,SW_SHOWNOACTIVATE);
	}
	VOID Hide()
	{
		XWnd_ShowWindow(m_hPopWindow,SW_HIDE);
	}
	VOID SetPopHeight(int nHeight)
	{
		m_nHeight = nHeight;
	}
private:

	int OnMainWndMove(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		SetPos();
		return 0;
	}

	int OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		int nSelect = XList_GetSelectItem(m_hList);
		switch (wParam)
		{
		case VK_UP:
			{
				if (nSelect > 0)
					nSelect--;
				XList_CancelSelectAll(m_hList);
				XList_SetSelectItem(m_hList,nSelect);
				XSView_ScrollTopLine(m_hList); //向上滚动一下，确保显示
				XEle_RedrawEle(m_hList);
			}
			break;
		case VK_DOWN:
			{
				if (nSelect < XAdTable_GetCount(XList_GetAdapter(m_hList)) - 1 )
					nSelect++;
				XList_CancelSelectAll(m_hList);
				XList_SetSelectItem(m_hList,nSelect);
				XEle_RedrawEle(m_hList);
			}
			break;
		}
	
		return 0;
	}


private:
	VOID CreateList()
	{
		m_hList = XList_Create(0,0,10,10,m_hPopWindow);


		XList_SetItemTemplateXML(m_hList,L"List_Item.xml");
        XSView_SetLineSize(m_hList,20,20);
		
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
		
        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name1",L"aaa");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"bbb");
        XAdMap_AddItemText(hAdapterHeader,L"name3",L"ccc");
        XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		
        HXCGUI hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");
		
        XList_SetColumnWidth(m_hList,0,50);
        XList_SetColumnWidth(m_hList,1,50);
        XList_SetColumnWidth(m_hList,2,50);
		
        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
            XAdTable_AddItemText(hAdapter,tmp);
			
            wsprintfW(tmp,L"child-%d-1",i);  XAdTable_SetItemText(hAdapter,i,1,tmp);
            wsprintfW(tmp,L"child-%d-2",i);  XAdTable_SetItemText(hAdapter,i,2,tmp);
        }
	}

	VOID SetPos()
	{
		RECT rt;
		XEle_GetRect(m_hParentRichEdit,&rt);
		POINT pt = {rt.left,rt.top};
		HWND hParent = XEle_GetHWND(m_hParentRichEdit);
		ClientToScreen(hParent,&pt);
		::SetWindowPos(
			XWnd_GetHWND(m_hPopWindow),
			HWND_TOP,
			pt.x,
			pt.y+rt.bottom-rt.top,
			rt.right-rt.left,
			m_nHeight,
			SWP_NOACTIVATE);

		XWnd_AdjustLayout(m_hPopWindow);
	}
private:
	HELE    m_hParentRichEdit;
	int     m_nHeight;
	HWINDOW m_hPopWindow;
	HELE    m_hList;
};



class CMyComboBox
{
public:

	BOOL Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_hRichEdit = XRichEdit_Create(x,y,cx,cy,hParent);
		m_PopList.Create(0,0,10,10,m_hRichEdit); //这里的宽度会自动 和 richedit的宽度对齐

		XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(m_hRichEdit,TRUE);
		XEle_RegEventCPP(m_hRichEdit,XE_RICHEDIT_CHANGE,&CMyComboBox::OnRichEditChange);
		XEle_RegEventCPP(m_hRichEdit,XE_KILLFOCUS,&CMyComboBox::OnKillFocus);

		return m_hRichEdit?TRUE:FALSE;
	}
	int OnRichEditChange(BOOL *pbHandled)
	{
		if (XRichEdit_GetTextLength(m_hRichEdit) < 1)
		{
			m_PopList.Hide();
		}else
		{
			m_PopList.Show();
		}
		return 0;
	}
	int OnKillFocus(BOOL *pbHandled)
	{
		m_PopList.Hide();
		return 0;
	}

private:
	HELE m_hRichEdit;
	CPopList m_PopList;
};



class CWindow_Demo
{
public:
    HWINDOW m_hWindow;
	CMyComboBox m_MyComboBox;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);

		m_MyComboBox.Create(8,50,200,20,m_hWindow);

        XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CWindow_Demo::OnDestroy);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnDestroy(BOOL* pbHandled)
    {
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}





