#include "Common.h"


class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
	HIMAGE  m_hImage;

	POINT   m_ptDown;
	POINT   m_ptMove;
	BOOL    m_bShowMovePic;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hButton = XBtn_Create(100, 50, 60, 25,L"Button", m_hWindow);
        XEle_RegEventCPP1(m_hButton,XE_LBUTTONDOWN,&CMyWindowButton::OnBtnLButtonDown);


		XWnd_RegEventCPP(m_hWindow,WM_MOUSEMOVE,&CMyWindowButton::OnWndMouseMove);
		XWnd_RegEventCPP(m_hWindow,WM_LBUTTONDOWN,&CMyWindowButton::OnWndLButtonDown);
		XWnd_RegEventCPP(m_hWindow,WM_LBUTTONUP,&CMyWindowButton::OnLButtonUp);
		XWnd_RegEventCPP(m_hWindow,WM_PAINT,&CMyWindowButton::OnWndDrawWindow);
		
		m_bShowMovePic =FALSE;


        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnWndLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		m_ptDown = *pPt;
		return 0;
	}
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		m_bShowMovePic = FALSE;
		XImage_Destroy(m_hImage);
		m_hImage = NULL;
		XWnd_RedrawWnd(m_hWindow);

		return 0;
	}
	int OnBtnLButtonDown(HELE hEle,UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		HWND hWnd = XEle_GetHWND(hEle);
		HDC  hDC  = ::GetDC(hWnd);
		RECT rt;
		XEle_GetRect(hEle,&rt);
		m_hImage = CopyDCToBitmap(hDC,&rt);
		
		m_bShowMovePic = TRUE;

		return 0;
	}
	int OnWndMouseMove(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		if (nFlags & MK_LBUTTON  &&  m_bShowMovePic )
		{
			//左键按下了
			m_ptMove = *pPt;

			XWnd_RedrawWnd(m_hWindow);

			xtrace("move\r\n");
		}
		return 0;
	}

	int OnWndDrawWindow(HDRAW hDraw,BOOL *pbHandled)
	{
		if (m_bShowMovePic)
		{
			RECT rt;
			XEle_GetRect(m_hButton,&rt);

			int x = rt.left + (m_ptMove.x - m_ptDown.x);
			int y = rt.top  + (m_ptMove.y - m_ptDown.y);
			XDraw_Image(hDraw,m_hImage,x,y);
			xtrace("draw %d %d\r\n",x,y);

// 			XEle_GetClientRect(m_hButton,&rt);
// 			rt.left = x;
// 			rt.top  = y;
// 			rt.right = rt.left+rt.right;
// 			rt.bottom = rt.bottom + rt.top;
// 			XDraw_FocusRect(hDraw,&rt);
		}
		*pbHandled = TRUE;
		return 0;
	}

	
    int OnBtnClick(BOOL *pbHandled)
    {
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
        return 0;
    }


	HIMAGE CopyDCToBitmap(HDC hDC, LPRECT lpRect)
	{
		if(!hDC || !lpRect || IsRectEmpty(lpRect))
			return NULL;
		
		HDC hMemDC;  
		HBITMAP hBitmap, hOldBitmap;  
		int nX, nY, nX2, nY2;  
		int nWidth, nHeight; 
		
		nX = lpRect->left;
		nY = lpRect->top;
		nX2 = lpRect->right;
		nY2 = lpRect->bottom;
		nWidth = nX2 - nX;
		nHeight = nY2 - nY;
		
		hMemDC = CreateCompatibleDC(hDC);
		
		hBitmap = CreateCompatibleBitmap(hDC, nWidth, nHeight);
		
		hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
		
		StretchBlt(hMemDC, 0, 0, nWidth, nHeight, hDC, nX, nY, nWidth, nHeight, SRCCOPY);
		
		hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap); 
		
		DeleteDC(hMemDC);
		DeleteObject(hOldBitmap);
		

		
		
		return XImage_LoadFileFromHBITMAP(hBitmap);
	}
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowButton  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




