#include "Common.h"
#include <complex>


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


class CMyWindowElement
{
public:
    HWINDOW m_hWindow;

	HELE	m_hBtn1;
	HELE	m_hBtn2;

	HELE    m_hEle;
	HELE	m_hEle1;
	HELE	m_hEle2;


	Expo m_expo;

	int  m_Index;
	int  m_c;   //¸Ä±äÁ¿

    CMyWindowElement(){
		m_Index = 0;
        Init();
    }
	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		switch (nIDEvent)
		{
		case 100:
			{

				
				if (m_Index > 100)
				{
					XWnd_KillTimer(m_hWindow,100);
					break;
				}

				double s = m_expo.Out(m_Index,0,m_c,100);

				SetCurRect(m_hEle,m_hEle1,m_hEle2,s);

				XEle_RedrawEle(m_hEle);
				m_Index++;
			}
			break;
		}
		return 0;
	}

	VOID SetCurRect(HELE hEleOrg,HELE hEle1,HELE hEle2,double s)
	{
		RECT rcOrg;
		XEle_GetClientRect(hEleOrg,&rcOrg);
		
		RECT rc1 = rcOrg;
		
		rc1.left -= s;
		rc1.right-= s;	
		
		XEle_SetRect(hEle1,&rc1);
		
		RECT rc2 = rcOrg;
		rc2.left = rcOrg.right;
		rc2.right= rc2.left+rcOrg.right;
		
		rc2.left -= s;
		rc2.right-= s;

		XEle_SetRect(hEle2,&rc2);
	}

	VOID fuwei(HELE hEleOrg,HELE hEle1,HELE hEle2)
	{
		RECT rcOrg;
		XEle_GetClientRect(hEleOrg,&rcOrg);

		m_c = rcOrg.right - rcOrg.left;
		

		RECT rc1 = rcOrg;
		XEle_SetRect(hEle1,&rcOrg);

		RECT rc2 = rcOrg;
		rc2.left = rc1.right;
		rc2.right= rc2.left+rcOrg.right;

		XEle_SetRect(hEle2,&rc2);
	}
	int OnBtnClick(BOOL *pbHandled)
	{

		XWnd_SetTimer(m_hWindow,100,10);
		return 0;
	}
	int OnBtnClick1(BOOL *pbHandled)
	{
		fuwei(m_hEle,m_hEle1,m_hEle2);
		m_Index = 0;
		XEle_RedrawEle(m_hEle);
		return 0;
	}
    void Init()
    {
		XC_LoadResource(L"Animal\\resource.xml",L"Animal");
		m_hWindow = (HWINDOW)XC_LoadLayout(L"Animal\\layout.xml");
		
		m_hBtn1 = (HELE)XC_GetObjectByID(m_hWindow, 100);
		m_hBtn2 = (HELE)XC_GetObjectByID(m_hWindow, 101);

		XEle_RegEventCPP(m_hBtn1,XE_BNCLICK,&CMyWindowElement::OnBtnClick);
		XEle_RegEventCPP(m_hBtn2,XE_BNCLICK,&CMyWindowElement::OnBtnClick1);

		m_hEle  = (HELE)XC_GetObjectByID(m_hWindow, 200);
		m_hEle1 = (HELE)XC_GetObjectByID(m_hWindow, 201);
		m_hEle2 = (HELE)XC_GetObjectByID(m_hWindow, 202);

		XWnd_AdjustLayout(m_hWindow);


		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CMyWindowElement::OnWndTimer);

		
 		RECT rtOrg;
 		XEle_GetClientRect(m_hEle,&rtOrg);
		fuwei(m_hEle,m_hEle1,m_hEle2);




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




