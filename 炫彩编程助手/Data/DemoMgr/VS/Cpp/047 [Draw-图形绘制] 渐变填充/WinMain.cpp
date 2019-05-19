#include "Common.h"



class CWindow_Demo
{
public:
    HWINDOW m_hWindow;
	HELE	m_hEle;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
        XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CWindow_Demo::OnDestroy);

		m_hEle = XEle_Create(8,30,250,150,m_hWindow);
		XEle_RegEventCPP(m_hEle,XE_PAINT,&CWindow_Demo::OnDraw);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		RECT rt = {0,0,250,150};
		XDraw_GradientFill2(hDraw,RGB(255,0,0),255,RGB(0,255,0),255,&rt,GRADIENT_FILL_RECT_H);
		return 0;
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





