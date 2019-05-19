#include "Common.h"


class CEnableWindowDock
{
public:
	CEnableWindowDock()
	{
		m_hWindow = NULL;
		m_bDocking = FALSE;
		m_bEnableDock = FALSE;
	}
	BOOL Register(HWINDOW hWindow)
	{
		m_hWindow = hWindow;
		if (m_hWindow == NULL)
			return FALSE;
		XWnd_RegEventCPP(m_hWindow,WM_MOUSEMOVE,&CEnableWindowDock::OnWndMouseMove);
		XWnd_RegEventCPP(m_hWindow,WM_MOUSELEAVE,&CEnableWindowDock::OnWndMouseLeave);
		return TRUE;
	}
	VOID SetDocking(BOOL bDock)
	{
		m_bDocking = bDock;
	}
	VOID EnableDock()
	{
		m_bEnableDock = TRUE;
	}
	VOID DisableDock()
	{
		m_bEnableDock = FALSE;
	}

	VOID GetLastDockRect(RECT* pRect)
	{
		*pRect = m_rtBeforeDock;
	}
	VOID SetLastDockRect(RECT* pRect)
	{
		m_rtBeforeDock = *pRect;
	}

	BOOL IsDock()
	{
		return m_bDocking;
	}
	
private:
	int OnWndMouseMove(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		if (!m_bEnableDock)
			return 0;
		//此时判断是否处于收缩模式，如果收缩，那么就显示，否则啥都不管
		if (!m_bDocking)
			return 0;

		MoveWindow(XWnd_GetHWND(m_hWindow),m_rtBeforeDock.left,m_rtBeforeDock.top,
			m_rtBeforeDock.right-m_rtBeforeDock.left,
			m_rtBeforeDock.bottom-m_rtBeforeDock.top,TRUE);
			
		SetWindowPos(XWnd_GetHWND(m_hWindow),HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

		m_bDocking = FALSE;
		return 0;
	}
	int OnWndMouseLeave(BOOL *pbHandled)
	{
		if (!m_bEnableDock)
			return 0;
		//当鼠标离开的时候，判断窗口位置，如果很接近边缘，就收缩起来

		//获取可用桌面大小  
		RECT rtDestTop;  
  		SystemParametersInfo(SPI_GETWORKAREA, 0, &rtDestTop, 0);
		RECT rtWindow;
		GetWindowRect(XWnd_GetHWND(m_hWindow),&rtWindow);

		if (rtWindow.left <= 0)
		{
			//停靠左边
			m_bDocking = TRUE;

			m_rtBeforeDock.left		= 0;
			m_rtBeforeDock.top		= rtWindow.top;
			m_rtBeforeDock.right	= rtWindow.right - rtWindow.left;
			m_rtBeforeDock.bottom   = rtWindow.bottom;

			MoveWindow(XWnd_GetHWND(m_hWindow),0,rtWindow.top,2,rtWindow.bottom-rtWindow.top,TRUE);
			SetWindowPos(XWnd_GetHWND(m_hWindow),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
		}else if (rtWindow.top <= 0)
		{
			//停靠顶边
			m_bDocking = TRUE;

			m_rtBeforeDock.left		= rtWindow.left;
			m_rtBeforeDock.top		= 0;
			m_rtBeforeDock.right	= rtWindow.right;
			m_rtBeforeDock.bottom   = rtWindow.bottom-rtWindow.top;
			
			MoveWindow(XWnd_GetHWND(m_hWindow),rtWindow.left,0,rtWindow.right-rtWindow.left,2,TRUE);
			SetWindowPos(XWnd_GetHWND(m_hWindow),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

		}else if (rtWindow.right >= rtDestTop.right)
		{
			//停靠右边
			m_bDocking = TRUE;

			m_rtBeforeDock.left		= rtDestTop.right-(rtWindow.right-rtWindow.left);
			m_rtBeforeDock.top		= rtWindow.top;
			m_rtBeforeDock.right	= rtDestTop.right;
			m_rtBeforeDock.bottom   = rtWindow.bottom;
			
			MoveWindow(XWnd_GetHWND(m_hWindow),
				rtDestTop.right-2,
				rtWindow.top,
				2,
				rtWindow.bottom-rtWindow.top
				,TRUE);
			SetWindowPos(XWnd_GetHWND(m_hWindow),HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);

		}else if (rtWindow.bottom >= rtDestTop.bottom)
		{
			//停靠底边
	//		m_bDock = TRUE;
		}

 
		return 0;
	}
private:
	HWINDOW m_hWindow;
	BOOL    m_bDocking;
	RECT    m_rtBeforeDock;
	BOOL    m_bEnableDock;
};


class CWindow_Demo
{
public:
    HWINDOW m_hWindow;
	CEnableWindowDock m_Docker;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
        XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CWindow_Demo::OnDestroy);
		XWnd_SetMinimumSize(m_hWindow,2,2);

		m_Docker.Register(m_hWindow);
		m_Docker.EnableDock();

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





