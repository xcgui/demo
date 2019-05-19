#define USE_GDIPLUS
#include "Common.h"

class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
	HELE m_hEle;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		
        m_hEle = XEle_Create(20,50,100,100,m_hWindow);
		XEle_RegEventCPP(m_hEle,XE_PAINT,&CMyWindowElement::OnDraw)

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		HBKM hBKinfoM = XEle_GetBkManager(m_hEle);
		XBkM_Clear(hBKinfoM);
		XBkM_AddFill(hBKinfoM,element_state_flag_leave,RGB(0,128,50),255);
		RECT rt;
		XEle_GetClientRect(m_hEle,&rt);
		XBkM_Draw(hBKinfoM,element_state_flag_leave,hDraw,&rt);

		int x = 0;
		int y = 0;
		XDraw_GetOffset(hDraw,&x,&y);

		GraphicsPath path;
		path.AddEllipse(0 - x,0 - y,100,100);

		Image img(L"user.jpg");
		TextureBrush imageBrush(&img);
		imageBrush.TranslateTransform(0-x,0-y);

		Graphics gp(XDraw_GetHDC(hDraw)); 
		gp.SetSmoothingMode(SmoothingModeAntiAlias);
		gp.FillPath(&imageBrush,&path);


		*pbHandled = TRUE;
		return 0;
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




