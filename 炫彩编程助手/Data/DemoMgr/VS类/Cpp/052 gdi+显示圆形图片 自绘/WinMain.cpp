#define USE_GDIPLUS
#include "Common.h"

class CMyWindowElement
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XEle m_ele;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
		m_ele.Create(20,50,100,100,m_Wnd);
		XEle_RegEventCPP(m_ele,XE_PAINT,&CMyWindowElement::OnDraw)

        m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		xcgui::XBkM bkInfoM = m_ele.GetBkManager();

		bkInfoM.Clear();
		bkInfoM.AddFill(element_state_flag_leave,RGB(0,128,50),255);

		RECT rt;
		m_ele.GetClientRect(&rt);
		bkInfoM.Draw(element_state_flag_leave,hDraw,&rt);


		GraphicsPath path;
		path.AddEllipse(0,0,100,100);

		Image img(L"user.jpg");
		TextureBrush imageBrush(&img);

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




