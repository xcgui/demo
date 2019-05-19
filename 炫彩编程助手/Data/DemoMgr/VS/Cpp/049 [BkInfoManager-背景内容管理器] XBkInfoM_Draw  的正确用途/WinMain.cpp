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
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
        XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CWindow_Demo::OnDestroy);

		m_hEle = XEle_Create(8,30,250,150,m_hWindow);
		XEle_AddBkFill(m_hEle,RGB(0,128,0),255);

		XEle_RegEventCPP(m_hEle,XE_PAINT,&CWindow_Demo::OnDraw);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
// 		RECT rt = {100,50,200,100};
// 		XDraw_GradientFill2(hDraw,RGB(255,0,0),255,RGB(0,255,0),255,&rt,GRADIENT_FILL_RECT_H);
// 		//如果用上面的代码，是无法绘制出来下面的渐变填充的。此时需要
// 		*pbHandled = TRUE;
// 		//但是如果拦截了消息，那么你的背景无法显示，所以正确的做法是下面这样的代码


//		如果要测试，可以注释下面的代码，把上面的注释取消掉，这样就能看到效果了

		RECT rtBkInfoM = {0,0,250,150};
		HBKM hBkInfoM = XEle_GetBkManager(m_hEle);
		XBkM_Draw(hBkInfoM,element_state_flag_leave,hDraw,&rtBkInfoM);

		RECT rt = {100,50,200,100};
		XDraw_GradientFill2(hDraw,RGB(255,0,0),255,RGB(0,255,0),255,&rt,GRADIENT_FILL_RECT_H);
		*pbHandled = TRUE;

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





