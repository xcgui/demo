// MyEdit.cpp : Defines the entry point for the application.
//

#include "Common.h"


class CCaret
{
public:
	CCaret()
	{
		m_nWidth = 1;
		m_nHeight= 12;
	}
	VOID Create(HELE hEle)
	{
		m_hEle = hEle;
		XWnd_CreateCaret(XEle_GetHWINDOW(m_hEle),m_hEle,m_nWidth,m_nHeight);
	}
	VOID SetWidth(int nWidth)
	{
		m_nWidth = nWidth;
		XWnd_SetCaretSize(XEle_GetHWINDOW(m_hEle),m_nWidth,m_nHeight);
	}
	VOID SetHeight(int nHeight)
	{
		m_nHeight = nHeight;
		XWnd_SetCaretSize(XEle_GetHWINDOW(m_hEle),m_nWidth,m_nHeight);
	}
	VOID SetPos(int x,int y)
	{
		XWnd_SetCaretPos(XEle_GetHWINDOW(m_hEle),x,y);
	}
	VOID Show(BOOL bShow)
	{
		XWnd_ShowCaret(XEle_GetHWINDOW(m_hEle),bShow);
	}
private:
	HELE m_hEle;
	int m_nWidth;
	int m_nHeight;
};



CCaret g_Caret;

int CALLBACK OnLButtonDown(HELE hEventEle,UINT nFlags, POINT *pPt,BOOL *pbHandled)
{
	g_Caret.SetPos(pPt->x,pPt->y);
	g_Caret.Show(TRUE);
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	//鼠标点击 插入符出现
	XInitXCGUI();

	HWINDOW hWindow = XWnd_Create(0,0,400,200,L"编辑框");

 	HELE hEle = XEle_Create(10,30,300,150,hWindow);
	XEle_RegEventC1(hEle,XE_LBUTTONDOWN,OnLButtonDown);


	g_Caret.Create(hEle);
// 
// 	CMyEle myEdit;
// 	myEdit.Create(hEle);

	XWnd_ShowWindow(hWindow,SW_SHOW);
	XRunXCGUI();
	XExitXCGUI();

	return 0;
}



