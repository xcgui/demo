#include "Common.h"

class XSPane
{
public:
	XSPane()
	{
		m_nCount = 0;
	}
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParen)
	{
		m_hEle = XEle_Create(x,y,cx,cy,hParen);
		HXCGUI	hLayout = XLayout_Create ();
		XEle_BindLayoutObject (m_hEle, hLayout);
		XLayout_SetLayoutWidth (hLayout, layout_size_type_fill, 1);
		XLayout_SetLayoutHeight (hLayout, layout_size_type_fill, 1);
		
		

		hLayoutLeft = XLayout_Create ();
		XLayout_SetLayoutWidth (hLayoutLeft, layout_size_type_fixed, 100);
		XLayout_SetLayoutHeight (hLayoutLeft, layout_size_type_fill, 1);	
		XLayout_AddLayoutObject(hLayout,hLayoutLeft);
		XLayout_SetHorizon(hLayoutLeft,FALSE);


		hLayoutRight = XLayout_Create ();
		XLayout_SetLayoutWidth (hLayoutRight, layout_size_type_weight, 1);
		XLayout_SetLayoutHeight (hLayoutRight, layout_size_type_fill, 1);	
		XLayout_AddLayoutObject(hLayout,hLayoutRight);

		m_hSview = XSView_Create(0,0,100,100,m_hEle);
		XLayout_AddEle(hLayoutRight,m_hSview);
		XEle_SetLayoutHeight(m_hSview,layout_size_type_fill,1);
		XEle_SetLayoutWidth(m_hSview,layout_size_type_fill,1);

		XEle_AdjustLayoutObject(m_hEle);
//		XLayout_AdjustLayout(hLayout);
		return m_hEle;
	}

	void AddButtonAndLayoutPane(HELE hbutton,HELE hLayoutPane)
	{
		XEle_AddEle(m_hEle,hbutton);
		XLayout_AddEle(hLayoutLeft,hbutton);
		XEle_AddEle(m_hSview,hLayoutPane);
		//将按钮绑定给 Layoutpane
//		XEle_SetUserData(hbutton,(int)hLayoutPane);
		XEle_SetUserData(hbutton,m_nCount);
		m_nCount++;
		XEle_RegEventCPP1(hbutton,XE_BNCLICK,&XSPane::OnBtnClick);
	}
	int OnBtnClick(HELE hEle,BOOL *pbHandled)
	{
		int nIndex = XEle_GetUserData(hEle);
		int nPos = nIndex*XEle_GetHeight(m_hSview);
		XSView_ScrollPosYV(m_hSview,nPos);

//		XEle_RedrawEle(m_hSview);
		//动态计算
		return 0;
	}

	void SetButtonWidth(int nWidth)
	{
		XLayout_SetLayoutWidth (hLayoutLeft, layout_size_type_fixed, nWidth);
	}

	void AdjustLayout()
	{

		//计算sview视图总大小

		HELE hPane;


		int x = 0;
		int y = 0;

		int nSViewWidth = XEle_GetWidth(m_hSview);
		int nSviewHeight= XEle_GetHeight(m_hSview);

		int nTotalWidth  = nSViewWidth;
		int nTotalHeight = 0;

		RECT rt;
		for (int i = 0; i < XEle_GetChildCount(m_hSview); i++)
		{
			hPane = XEle_GetChildByIndex(m_hSview,i);
			if (XC_GetObjectType(hPane) != XC_ELE)
			{
				continue;
			}

			
			rt.left = x;
			rt.top  = nTotalHeight;
			rt.right = nSViewWidth;
			rt.bottom= rt.top + nSviewHeight;


			XEle_SetRectEx(hPane,rt.left,rt.top,rt.right,rt.bottom);

			nTotalHeight += nSviewHeight;
		}
		XSView_SetTotalSize(m_hSview,nTotalWidth,nTotalHeight);
	}

private:
	HELE m_hEle;
	HELE m_hSview;
	HXCGUI	hLayoutLeft;
	HXCGUI	hLayoutRight;

	int m_nCount;
};




class CMyWindowScrollView
{
public:
    HWINDOW m_hWindow;
    HELE    m_hScrollView;
	XSPane m_SPane;
    CMyWindowScrollView()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 500, 450, L"炫彩界面库窗口", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

		srand(GetTickCount());
// 		HBKM hBkInfoM = XWnd_GetBkManager(m_hWindow);
// 		XBkM_AddFill(hBkInfoM,window_state_body_leave ,255,255);

		
		m_SPane.Create(8,30,400,400,m_hWindow);


		wchar_t buffer[MAX_PATH] = {0};
		for (int i = 0; i < 5; i++)
		{
			wsprintfW(buffer,L"Button%d",i);
			HELE hBtn = XBtn_Create(10,10,100,40,buffer);
			HELE hPane = XEle_Create(10,10,200,100);
			XBtn_Create(0,0,100,20,buffer,hPane);

			XEle_AddBkFill(hPane,(COLORREF)rand(),255);
			m_SPane.AddButtonAndLayoutPane(hBtn,hPane);
		}

		m_SPane.AdjustLayout();
		
//         XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_H,&CMyWindowScrollView::OnScrollViewScrollH);
//         XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_V,&CMyWindowScrollView::OnScrollViewScrollV);

		XWnd_AdjustLayoutObject(m_hWindow);
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int  OnScrollViewScrollH(int pos,BOOL *pbHandled)
    {
        XTRACE("XE_SCROLLVIEW_SCROLL_H %d \n",pos);
        return 0;
    }
    int  OnScrollViewScrollV(int pos,BOOL *pbHandled)
    {
        XTRACE("XE_SCROLLVIEW_SCROLL_V %d \n",pos);
        return 0;
    }

};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
//	XC_ShowLayoutFrame(TRUE);
    CMyWindowScrollView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}