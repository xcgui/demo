#include "Common.h"
#include <complex>
#include <map>


class Expo
{
public:
    double In(double t, double b, double c, double d)
    {
		return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
    }
	double Out(double t, double b, double c, double d)
    {
		return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
		if (t==0) return b;
		if (t==d) return b+c;
		if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
		return c/2 * (-pow(2, -10 * --t) + 2) + b;
    }
};


class CPageSwitch
{
public:
	CPageSwitch()
	{
		m_hCurrentPage = NULL;
	}
	VOID Create(HWINDOW hWindow,UINT IDTimer=100,UINT uElapse=10)
	{
		m_hWindow = hWindow;
		m_IDTimer = IDTimer;
		m_uElapse = uElapse;
		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CPageSwitch::OnWndTimer);
	}
	VOID SetDefaultPage(HELE hPage)
	{
		m_hCurrentPage = hPage;
	}
	VOID SetShowRect(RECT showRect)
	{
		m_ShowRect = showRect;
	}
	VOID AddPage(HELE hBtn,HELE hPage,int index)
	{
		XEle_SetUserData(hBtn,(int)hPage);
		XEle_RegEventCPP1(hBtn,XE_BNCLICK,&CPageSwitch::OnBtnClick);
//		std::map<HELE,int>
		m_map.insert(std::pair<HELE,int>(hPage,index));
	}

private:
	int OnBtnClick(HELE hBtn,BOOL *pbHandled)
	{
		//如果当前显示页面 == 要显示的页面，则忽略
		HELE hPage = (HELE)XEle_GetUserData(hBtn);
		if (hPage == m_hCurrentPage)
			return 0;

		XWnd_KillTimer(m_hWindow,m_IDTimer);

		//通过绑定的索引判断方向
		if (m_map[hPage] > m_map[m_hCurrentPage])
			m_bDir = TRUE; //从右到左
		else
			m_bDir = FALSE; //从右到左


		m_hPrevPage = m_hCurrentPage;
		XEle_GetRect(m_hPrevPage,&m_PrevRect);

		m_hCurrentPage = hPage;
		XEle_ShowEle(m_hCurrentPage,TRUE);

		m_Index = 0;
		m_c = m_ShowRect.right - m_ShowRect.left;

		if (m_bDir)
		{
			m_OrgRect.left = m_ShowRect.right;
			m_OrgRect.top  = m_ShowRect.top;

			m_OrgRect.right = m_OrgRect.left + (m_ShowRect.right-m_ShowRect.left);
			m_OrgRect.bottom= m_OrgRect.top  + (m_ShowRect.bottom-m_ShowRect.top);
		} 
		else
		{
			m_OrgRect.left = -(m_ShowRect.right-m_ShowRect.left);
			m_OrgRect.top  = m_ShowRect.top;

			m_OrgRect.right = m_ShowRect.left;
			m_OrgRect.bottom= m_OrgRect.top + (m_ShowRect.bottom-m_ShowRect.top);
		}

		XEle_SetRect(m_hCurrentPage,&m_OrgRect);

		XWnd_SetTimer(m_hWindow,m_IDTimer,m_uElapse);
		return 0;
	}

	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		if (m_Index > 100)
		{
			XWnd_KillTimer(m_hWindow,m_IDTimer);
			XEle_ShowEle(m_hPrevPage,FALSE);
			m_Index = 0;
			return 0;
		}
		if (nIDEvent == m_IDTimer)
		{
			double s = m_expo.Out(m_Index,0,m_c,100);

			RECT rc1 = m_PrevRect;
			RECT rc2 = m_OrgRect;
			if (m_bDir)
			{//右到左
				rc2.left -= s;
				rc2.right-= s;
				rc1.left -= s;
				rc1.right-= s;
			} 
			else
			{//左到右
				rc2.left += s;
				rc2.right+= s;
				rc1.left += s;
				rc1.right+= s;
			}

			xtrace("%d %d | %d %d\n",rc1.left,rc1.right,rc2.left,rc2.right);
			XEle_SetRect(m_hCurrentPage,&rc2);
			XEle_SetRect(m_hPrevPage,&rc1);
			XWnd_RedrawWnd(m_hWindow);
			m_Index++;
		}
		return 0;
	}

private:
	HWINDOW m_hWindow;
	UINT m_IDTimer;
	UINT m_uElapse;

	RECT m_ShowRect;
	Expo m_expo;
	int  m_Index;
	int  m_c;   //改变量
	HELE m_hCurrentPage;
	RECT m_PrevRect;
	HELE m_hPrevPage;
	RECT m_OrgRect;

	BOOL m_bDir; //方向 true ->从右到左，否则从左到右

	std::map<HELE,int> m_map;
};



class CPageSwitchLoop
{
public:
	CPageSwitchLoop()
	{
		m_hCurrentPage = NULL;
	}
	VOID Create(int nStartX,int nEndY,HWINDOW hWindow,UINT IDTimer=100,UINT uElapse=10)
	{
		m_StartX = nStartX;
		m_EndX   = nEndY;
		m_hWindow = hWindow;
		m_IDTimer = IDTimer;
		m_uElapse = uElapse;
		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CPageSwitchLoop::OnWndTimer);
	}
	VOID SetDefaultPage(HELE hPage)
	{
		m_hCurrentPage = hPage;
	}
	VOID AddPage(HELE hBtn,HELE hPage)
	{
		XEle_SetUserData(hBtn,(int)hPage);
		XEle_RegEventCPP1(hBtn,XE_BNCLICK,&CPageSwitchLoop::OnBtnClick);
	}

private:
	int OnBtnClick(HELE hBtn,BOOL *pbHandled)
	{
		//如果当前显示页面 == 要显示的页面，则忽略
		HELE hPage = (HELE)XEle_GetUserData(hBtn);
		if (hPage == m_hCurrentPage)
			return 0;

		XWnd_KillTimer(m_hWindow,m_IDTimer);
//		BOOL bOk = XEle_SetZOrderEx(m_hCurrentPage,NULL,zorder_top);
//		XWnd_RedrawWnd(m_hWindow);
		XEle_ShowEle(m_hCurrentPage,FALSE);
		m_hCurrentPage = hPage;
		XEle_ShowEle(m_hCurrentPage,TRUE);
		m_Index = 0;
		m_c = (m_EndX > m_StartX)?(m_bDir=FALSE,m_EndX - m_StartX):(m_bDir=TRUE,m_StartX - m_EndX);

		RECT rt;
		XEle_GetRect(m_hCurrentPage,&rt);

		m_OrgRect.left = m_StartX;
		m_OrgRect.top  = rt.top;
		m_OrgRect.right = m_OrgRect.left + XEle_GetWidth(m_hCurrentPage);
		m_OrgRect.bottom= m_OrgRect.top  + XEle_GetHeight(m_hCurrentPage);
		XEle_SetRect(m_hCurrentPage,&m_OrgRect);

		XWnd_SetTimer(m_hWindow,m_IDTimer,m_uElapse);
		return 0;
	}

	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		if (m_Index > 100)
		{
			XWnd_KillTimer(m_hWindow,m_IDTimer);
			m_Index = 0;
			return 0;
		}
		if (nIDEvent == m_IDTimer)
		{
			double s = m_expo.Out(m_Index,0,m_c,100);


			RECT rc2 = m_OrgRect;
			if (m_bDir)
			{//右到左
				rc2.left -= s;
				rc2.right-= s;
			} 
			else
			{//左到右
				rc2.left += s;
				rc2.right+= s;
			}

			xtrace("%d %d\n",rc2.left,rc2.right);
			XEle_SetRect(m_hCurrentPage,&rc2);
			XWnd_RedrawWnd(m_hWindow);
			m_Index++;
		}
		return 0;
	}

private:
	HWINDOW m_hWindow;
	int m_StartX;
	int m_EndX;
	UINT m_IDTimer;
	UINT m_uElapse;

	Expo m_expo;
	int  m_Index;
	int  m_c;   //改变量
	HELE m_hCurrentPage;
	RECT m_OrgRect;

	BOOL m_bDir; //方向 true ->从右到左，否则从左到右
};


class CMyWindowElement
{
public:
    HWINDOW m_hWindow;

	HELE	m_hBtn1;
	HELE	m_hBtn2;
	HELE	m_hBtn3;
	HELE    m_hEle1;
	HELE	m_hEle2;
	HELE	m_hEle3;

	CPageSwitch m_pageSwitch;
    CMyWindowElement(){
        Init();
    }

    void Init()
    {
		XC_LoadResource(L"Animal\\resource.xml",L"Animal");
		m_hWindow = (HWINDOW)XC_LoadLayout(L"Animal\\layout.xml");
		
		m_hBtn1 = (HELE)XC_GetObjectByID(m_hWindow, 100);
		m_hBtn2 = (HELE)XC_GetObjectByID(m_hWindow, 101);
		m_hBtn3 = (HELE)XC_GetObjectByID(m_hWindow, 102);

		m_hEle1 = (HELE)XC_GetObjectByID(m_hWindow, 200);
		m_hEle2 = (HELE)XC_GetObjectByID(m_hWindow, 201);
		m_hEle3 = (HELE)XC_GetObjectByID(m_hWindow, 202);

		XEle_ShowEle(m_hEle2,FALSE);
		XEle_ShowEle(m_hEle3,FALSE);

		m_pageSwitch.Create(m_hWindow);
		m_pageSwitch.AddPage(m_hBtn1,m_hEle1,1);
		m_pageSwitch.AddPage(m_hBtn2,m_hEle2,2);
		m_pageSwitch.AddPage(m_hBtn3,m_hEle3,3);
		m_pageSwitch.SetDefaultPage(m_hEle1);

		RECT rtBody;
		XWnd_GetBodyRect(m_hWindow,&rtBody);
		m_pageSwitch.SetShowRect(rtBody);

		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowElement  MyWindowt;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




