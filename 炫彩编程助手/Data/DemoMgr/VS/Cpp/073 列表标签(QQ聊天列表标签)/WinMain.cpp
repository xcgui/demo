#include "Common.h"


#include <vector>

enum tabbar_direction_
{
	tabbar_direction_left,
	tabbar_direction_top,
	tabbar_direction_right,
	tabbar_direction_bottom
};


struct _tagLabel
{
	HELE hBtn;
	HELE hPage;
};

class CTabBar
{
public:
	HELE Init(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_hEle = XEle_Create(x,y,cx,cy,hParent);
		m_hSview = XSView_Create(0,0,cx,30,m_hEle);
		XSView_SetLineSize(m_hSview,20,20);
		//设置表头方向
		m_ViewWidth = 100;
		m_ViewHeight = 40;
 		SetLabelDirection(tabbar_direction_top);
		return m_hEle;
	}
	void SetLableSize(int cx,int cy)
	{
		m_ViewWidth = cx;
		m_ViewHeight = cy;
	}
	int GetLabelCount()
	{
		return m_LabelM.size();
	}
	int AddLabel(const wchar_t* pLabelName)
	{
		int lableSize = GetLableSize();
		_tagLabel label = CreateNewLabel(lableSize,pLabelName);
		m_LabelM.push_back(label);

		if (m_bHorizon)
		{
			ReSizeView(lableSize+100);
		}else
		{
			ReSizeView(lableSize+20);
		}

		int nIndex = m_LabelM.size() - 1;
		SetSelect(nIndex);

		return nIndex;
	}
	int InsertLabel(const wchar_t* pLabelName,int nIndexInsert)
	{
		int labelSize = GetLableSize();
		_tagLabel label = CreateNewLabel(labelSize,pLabelName);
		m_LabelM.insert(m_LabelM.begin()+nIndexInsert,label);

		if (m_bHorizon)
		{
			ReSizeView(labelSize+100);
		}else
		{
			ReSizeView(labelSize+20);
		}

		int nIndex = nIndexInsert+1;
		SetSelect(nIndex);
		return nIndex;
	}
	void SetSelect(int nIndex)
	{
		HELE hBtn = GetLabelBtn(nIndex);
		XBtn_SetCheck(hBtn,TRUE);
		XEle_RedrawEle(m_hEle);
	}
	HELE GetLabelBtn(int nIndex)
	{
		return m_LabelM[nIndex].hBtn;
	}
	HELE GetPage(int nIndex)
	{
		return m_LabelM[nIndex].hPage;
	}
	void SetLabelDirection(tabbar_direction_ nDirection)
	{
		m_Direction = nDirection;

		if (nDirection == tabbar_direction_left ||
			nDirection == tabbar_direction_right)
		{
			XSView_ShowSBarV(m_hSview,TRUE);
			XSView_ShowSBarH(m_hSview,FALSE);
			XSView_ScrollPosV(m_hSview,0);
			XSView_ScrollPosH(m_hSview,0);
			m_bHorizon = FALSE;
		}else
		{
			XSView_ShowSBarV(m_hSview,FALSE);
			XSView_ShowSBarH(m_hSview,TRUE);
			XSView_ScrollPosH(m_hSview,0);
			XSView_ScrollPosV(m_hSview,0);
			m_bHorizon = TRUE;
		}


		int labelSize = GetLableSize();
		if (m_bHorizon)
		{
			ReSizeView(labelSize);
		}else
		{
			ReSizeView(labelSize);
		}




		RECT rtView;
		RECT rtTabBar;
		XEle_GetClientRect(m_hEle,&rtTabBar);
		switch (m_Direction)
		{
		case tabbar_direction_left:
			{
				rtView.left = 0;
				rtView.top  = 0;
				rtView.right = m_ViewWidth;
				rtView.bottom = rtTabBar.bottom;
			}
			break;
		case tabbar_direction_top:
			{
				rtView.left = 0;
				rtView.top  = 0;
				rtView.right = rtTabBar.right;
				rtView.bottom = m_ViewHeight;
			}
			break;
		case tabbar_direction_right:
			{
				rtView.left = rtTabBar.right - m_ViewWidth;
				rtView.top  = 0;
				rtView.right = rtTabBar.right;
				rtView.bottom = rtTabBar.bottom;
			}
			break;
		case tabbar_direction_bottom:
			{
				rtView.top = rtTabBar.bottom - m_ViewHeight;
				rtView.left = 0;
				rtView.right = rtTabBar.right;
				rtView.bottom = rtTabBar.bottom;
			}
			break;
		}
		XEle_SetRect(m_hSview,&rtView);


		 
		ResetBtnPos();
		ResetPagePos();
		XEle_RedrawEle(m_hEle);
	}
private:

	void ResetBtnPos()
	{
		int x = 0;
		int y = 0;
		RECT rtBtn;

		int buttonWidth  = 0;
		int buttonHeight = 0;
		int nSize = 0;
// 		RECT rtClient;
// 		XEle_GetClientRect(m_hEle,&rtClient);
		for (int i = 0; i < m_LabelM.size(); i++)
		{
			XEle_GetClientRect(m_LabelM[i].hBtn,&rtBtn);
			buttonWidth = rtBtn.right;
			buttonHeight= rtBtn.bottom;
			switch (m_Direction)
			{
			case tabbar_direction_left:
				{
					rtBtn.left = 0;
					rtBtn.top += nSize;
					rtBtn.right = rtBtn.left + buttonWidth;
					rtBtn.bottom = rtBtn.top + buttonHeight;
					nSize += buttonHeight;
				}
				break;
			case tabbar_direction_top:
				{
					rtBtn.left += nSize;
					rtBtn.top  = 0;
					rtBtn.right = rtBtn.left + buttonWidth;
					rtBtn.bottom = rtBtn.top + buttonHeight;
					nSize += buttonWidth;
				}
				break;
			case  tabbar_direction_right:
				{
					rtBtn.left = 0;
					rtBtn.top += nSize;
					rtBtn.right = rtBtn.left + buttonWidth;
					rtBtn.bottom = rtBtn.top + buttonHeight;
					nSize += buttonHeight;
				}
				break;
			case tabbar_direction_bottom:
				{
					rtBtn.left += nSize;
					rtBtn.top  = 0;
					rtBtn.right = rtBtn.left + buttonWidth;
					rtBtn.bottom = rtBtn.top + buttonHeight;
					nSize += buttonWidth;
				}
				break;
			}
			XEle_SetRect(m_LabelM[i].hBtn,&rtBtn);
		}
	}
	void ResetPagePos()
	{
		int xPage = 0;
		int yPage = 0;
		int cxPage = 0;
		int cyPage = 0;

		RECT rtSView;
		XEle_GetClientRect(m_hSview,&rtSView);
		RECT rtTabBar;
		XEle_GetClientRect(m_hEle,&rtTabBar);

		switch (m_Direction)
		{
		case tabbar_direction_left:
			{
				xPage = rtSView.right;
				cxPage = rtTabBar.right - rtSView.right;
				cyPage = rtTabBar.bottom;
			}
			break;
		case tabbar_direction_top:
			{
				yPage = rtSView.bottom;
				cxPage= rtTabBar.right;
				cyPage= rtTabBar.bottom - rtSView.bottom;
			}
			break;
		case tabbar_direction_right:
			{
				cxPage = rtTabBar.right - rtSView.right;
				cyPage = rtTabBar.bottom;
			}
			break;
		case tabbar_direction_bottom:
			{
				cxPage = rtTabBar.right;
				cyPage = rtTabBar.bottom - rtSView.bottom;
			}
			break;
		}

		RECT rtPage;
		rtPage.left = xPage;
		rtPage.top = yPage;

		rtPage.right = rtPage.left+ cxPage;
		rtPage.bottom= rtPage.top + cyPage;

		for (int i = 0; i < m_LabelM.size(); i++)
		{
			XEle_SetRect(m_LabelM[i].hPage,&rtPage);
		}

	}

	void ShowPage(HELE hBtn)
	{
		for (int i = 0; i < m_LabelM.size(); i++)
		{
			if (m_LabelM[i].hBtn == hBtn)
			{
				XEle_ShowEle(m_LabelM[i].hPage,TRUE);
			}else
			{
				XEle_ShowEle(m_LabelM[i].hPage,FALSE);
			}
		}
	}

	void ReSizeView(int nsize)
	{
		int cx = 0;
		int cy = 0;
		RECT rtSview;
		XEle_GetClientRect(m_hSview,&rtSview);
		if (m_bHorizon)
		{
			cy = rtSview.bottom;
			cx = nsize;
		}else
		{
			cx = rtSview.right;
			cy = nsize;
		}
		XSView_SetTotalSize(m_hSview,cx,cy);
	}

	_tagLabel CreateNewLabel(int labelSize,const wchar_t* pLabelName)
	{
		int xBtn = 0;
		int yBtn = 0;
		int cxBtn = 100;
		int cyBtn = 20;
		if (m_bHorizon)
		{
			xBtn = labelSize;
		}else
		{
			yBtn = labelSize;
		}
		
		int xPage = 0;
		int yPage = 0;
		int cxPage = 0;
		int cyPage = 0;

		RECT rtSView;
		XEle_GetClientRect(m_hSview,&rtSView);
		RECT rtTabBar;
		XEle_GetClientRect(m_hEle,&rtTabBar);

		switch (m_Direction)
		{
		case tabbar_direction_left:
			{
				xPage = rtSView.right;
				cxPage = rtTabBar.right - rtSView.right;
				cyPage = rtTabBar.bottom;
			}
			break;
		case tabbar_direction_top:
			{
				yPage = rtSView.bottom;
				cxPage= rtTabBar.right;
				cyPage= rtTabBar.bottom - rtSView.bottom;
			}
			break;
		case tabbar_direction_right:
			{
				cxPage = rtTabBar.right - rtSView.right;
				cyPage = rtTabBar.bottom;
			}
			break;
		case tabbar_direction_bottom:
			{
				cxPage = rtTabBar.right;
				cyPage = rtTabBar.bottom - rtSView.bottom;
			}
			break;
		}

		_tagLabel labelData;
		labelData.hBtn = XBtn_Create(xBtn,yBtn,cxBtn,cyBtn,pLabelName,m_hSview);
		XBtn_SetType(labelData.hBtn,button_type_radio);
		XBtn_SetStyle(labelData.hBtn,button_style_default);
		labelData.hPage = XEle_Create(xPage,yPage,cxPage,cyPage,m_hEle);

		XEle_RegEventCPP1(labelData.hBtn,XE_BUTTON_CHECK,&CTabBar::OnLabelCheck);

		XEle_AddBkFill(labelData.hPage,rand(),255);

		return labelData;
	}

	int GetLableSize()
	{
		int nsize = 0;
		for (int i = 0 ;i < m_LabelM.size(); i++)
		{
			RECT rt;
			XEle_GetClientRect(m_LabelM[i].hBtn,&rt);
			if (m_bHorizon)
			{
				nsize += rt.right;
			}else
			{
				nsize += rt.bottom;
			}
		}
		return nsize;
	}

	int OnLabelCheck(HELE hEventEle,BOOL bCheck,BOOL *pbHandled)
	{
		ShowPage(hEventEle);
		XEle_RedrawEle(m_hEle);
		*pbHandled = TRUE;
		return 0;
	}

private:
	HELE m_hEle;
	HELE m_hSview;
	std::vector<_tagLabel> m_LabelM;
	BOOL m_bHorizon;
	tabbar_direction_ m_Direction;

	int m_ViewWidth;
	int m_ViewHeight;
};


class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	CTabBar m_tabBar;
	int  m_nCur;
	
    BOOL Create() //创建窗口和按钮
    {
		srand(GetTickCount());
        m_hWindow=XWnd_Create(0,0,500,300,L"炫彩界面库-窗口"); //创建窗口
		m_nCur = 0;
        if(m_hWindow)
        {
            m_hButton =XBtn_Create(10,5,80,20,L"增加标签",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			

			m_hButton =XBtn_Create(90,5,80,20,L"表头左",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnLeftClick); //注册按钮点击事件

			m_hButton =XBtn_Create(170,5,80,20,L"表头上",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnTopClick); //注册按钮点击事件


			m_hButton =XBtn_Create(250,5,80,20,L"表头右",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnRightClick); //注册按钮点击事件

			m_hButton =XBtn_Create(330,5,80,20,L"表头下",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnBottomClick); //注册按钮点击事件


			RECT rtBody;
			XWnd_GetBodyRect(m_hWindow,&rtBody);
			m_tabBar.Init(rtBody.left,rtBody.top,rtBody.right - rtBody.left,rtBody.bottom - rtBody.top,m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
	int OnEventBtnLeftClick(BOOL *pBool)
	{
		m_tabBar.SetLabelDirection(tabbar_direction_left);
		return 0;
	}
	int OnEventBtnTopClick(BOOL *pBool)
	{
		m_tabBar.SetLabelDirection(tabbar_direction_top);
		return 0;
	}
	int OnEventBtnRightClick(BOOL *pBool) 
	{
		m_tabBar.SetLabelDirection(tabbar_direction_right);
		return 0;
	}
	int OnEventBtnBottomClick(BOOL *pBool)
	{
		m_tabBar.SetLabelDirection(tabbar_direction_bottom);
		return 0;
	}
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
		wchar_t buffer[256] = {0};
		wsprintfW(buffer,L"大色 %d",m_nCur);
		m_nCur++;
        //弹出消息框
       // MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
		m_tabBar.AddLabel(buffer);
        *pBool=TRUE; //对该事件进行拦截
        return 0;    //事件的返回值
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




