#include "Common.h"


class CMyWindowDrag
{
public:
	HWINDOW m_hWindow;
	HELE    m_hButton_close;
	HELE    m_hEleA;
	HELE    m_hEleB;
	CMyWindowDrag() {
		Init();
	}
	void Init()
	{
		m_hWindow = XWnd_Create(0, 0, 500, 500, L"ìÅ²Ê½çÃæ¿â´°¿Ú", NULL, xc_window_style_default);
		m_hButton_close = XBtn_Create(400, 5, 60, 20, L"close", m_hWindow);
		XBtn_SetType(m_hButton_close, button_type_close);
		
		int left = 50;
		int top = 50;
		m_hEleA = XEle_Create(left, top, 200, 200, m_hWindow); top += 205;
		m_hEleB = XEle_Create(left, top, 200, 200, m_hWindow);
		XEle_SetBorderSize(m_hEleA, 5, 5, 5, 5);
		XEle_SetBorderSize(m_hEleB, 5, 5, 5, 5);
		
		XEle_SetDragBorder(m_hEleB, element_position_left | element_position_top | element_position_bottom | element_position_right);
		XEle_SetDragBorderBindEle(m_hEleB, element_position_top, m_hEleA, 5);
		
		XEle_SetMinSize(m_hEleA,0,100);
		//XEle_SetMaxSize(m_hEleA, 220, 220);
		
		XEle_SetMinSize(m_hEleB, 0, 100);
		
		XEle_RegEventCPP(m_hEleA,XE_PAINT, &CMyWindowDrag::OnDraw);
		XWnd_ShowWindow(m_hWindow, SW_SHOW);
	}
	
	int OnDraw(HDRAW hDraw, BOOL *pbHandled)
	{
		RECT rect;
		XEle_GetClientRect(m_hEleA, &rect);
		XDraw_SetBrushColor(hDraw, RGB(200,0,0));
		XDraw_FrameRect(hDraw, &rect);
		
		*pbHandled = TRUE;
		return 0;
	}
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	XInitXCGUI();
	CMyWindowDrag  MyWindow;
	XRunXCGUI();
	XExitXCGUI();
	return 0;
}