#include "Common.h"


class Quint
{
public:

    double In(double t, double b, double c, double d)
    {
		return c*(t/=d)*t*t*t*t + b;
    }
	double Out(double t, double b, double c, double d)
    {
        return c*((t=t/d-1)*t*t*t*t + 1) + b;
    }
	double InOut(double t, double b, double c, double d)
    {
		if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
		return c/2*((t-=2)*t*t*t*t + 2) + b;
    }
};



class CMyWnd
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
	byte    m_nIndex;
	Quint   m_Quint;
    CMyWnd(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hButton = XBtn_Create(100, 50, 60, 25,L"Button", m_hWindow);
        XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnBtnClick);
		


		XEle_RegEventCPP(m_hButton,XE_MOUSESTAY, &CMyWnd::OnMouseStay);
		XEle_RegEventCPP(m_hButton,XE_MOUSELEAVE, &CMyWnd::OnMouseLeave);





		m_nIndex = 0;
		XWnd_RegEventCPP(m_hWindow, WM_TIMER, &CMyWnd::OnWndTimer);
		


        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnMouseLeave(HELE hEleStay,BOOL *pbHandled)
	{
		XWnd_KillTimer(m_hWindow,10);
		HBKM hBkInfoM = XEle_GetBkManager(m_hButton);
		XBkM_Clear(hBkInfoM);
		XEle_RedrawEle(m_hButton,TRUE);
		return 0;
	}
	int OnMouseStay(BOOL *pbHandled)
	{
		m_nIndex = 0;
		XWnd_KillTimer(m_hWindow,10);
		XWnd_SetTimer(m_hWindow,10,100);
		return 0;
	}
	int OnWndTimer(UINT nIDEvent, BOOL *pbHandled)
	{
		
		if (m_nIndex < 100)
		{
			int argb = 0;
			int alpha = m_Quint.Out(m_nIndex,0,255,100);
			argb = alpha;
			argb = argb << 24;
			argb |= 255;

			HBKM hBkInfoM = XEle_GetBkManager(m_hButton);
			wchar_t buffer[255]={0};
			wsprintfW(buffer,L"{5:1(1)2(15)3(0,0,0,0)10(1)20(0)8(0.00)7(3)11(1)12(%d)13(%d);}",argb,alpha);
			OutputDebugStringW(buffer);
			XBkM_SetBkInfo(hBkInfoM,buffer);
			m_nIndex++;
			XEle_RedrawEle(m_hButton);
		}else
		{
			XWnd_KillTimer(m_hWindow,10);
		}


		return 0;
	}
    int OnBtnClick(BOOL *pbHandled)
    {
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWnd  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




