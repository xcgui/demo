#ifndef XWeb_h__
#define XWeb_h__
//wke作者 BlzFans
//ewe作者  蚂蚁
//特别鸣谢: 海绵宝宝 扫地僧，其他未知名的升级者



#include "ewe.h"
#pragma comment(lib,"ewe.lib")


#define GET_WHEEL_DELTA_WPARAM(wParam)  ((short)HIWORD(wParam))

class CRenderGDI
{
public:
    CRenderGDI()
        :m_hView(NULL)
        ,m_hDC(NULL)
        ,m_hBitmap(NULL)
        ,m_pixels(NULL)
        ,m_width(0)
        ,m_height(0)
    {}

    ~CRenderGDI()
    {
        if (m_hDC)
            DeleteDC(m_hDC);

        if (m_hBitmap)
            DeleteObject(m_hBitmap);
    }

    virtual bool init(HWND hView)
    {
        m_hView = hView;
        m_hDC = CreateCompatibleDC(0);

        RECT rect;
        GetClientRect(hView, &rect);
        resize(rect.right, rect.bottom);
        return true;
    }
	virtual bool initex(HWND hView,int cx,int cy)
	{
		m_hView = hView;
		m_hDC = CreateCompatibleDC(0);
		resize(cx, cy);
		return true;
	}
    virtual void resize(unsigned int w, unsigned int h)
    {
// 		if (w <= m_width && h <= m_height)
// 		{
// 			m_width = w;
// 		    m_height = h;
// 			return ;
// 		}
          if (m_width == w && m_height == h)
              return;

        m_width = w;
        m_height = h;
        m_pixels = NULL;
    }

    virtual void render(wkeWebView* webView)
    {
        if (wkeIsDirty(webView))
        {
            if (m_pixels == NULL)
                createBitmap();

            wkePaint(webView, m_pixels, 0);

            HDC hDC = GetDC(m_hView);
            BitBlt(hDC, 0, 0, m_width, m_height, m_hDC, 0, 0, SRCCOPY);
            ReleaseDC(m_hView, hDC);
        }
    }
	virtual void renderOffset(wkeWebView* webView,int x,int y)
	{
		if (wkeIsDirty(webView))
		{
			if (m_pixels == NULL)
				createBitmap();

			wkePaint(webView, m_pixels, 0);

			HDC hDC = GetDC(m_hView);
			BitBlt(hDC, x, y, m_width, m_height, m_hDC, 0, 0, SRCCOPY);
			ReleaseDC(m_hView, hDC);
		}
	}
	virtual void renderBtimap(wkeWebView* webView, HDRAW  hDraw)
	{
			if (m_pixels == NULL)
				createBitmap();
			int nWidht = wkeGetWidth(webView);
			int nHeight = wkeGetHeight(webView);
			wkePaint(webView, m_pixels, 0);
			XDraw_BitBlt(hDraw,0, 0, m_width, m_height, m_hDC, 0, 0, SRCCOPY);
	}

    void createBitmap()
    {
        BITMAPINFO bi;
        memset(&bi, 0, sizeof(bi));
        bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bi.bmiHeader.biWidth         = int(m_width);
        bi.bmiHeader.biHeight        = -int(m_height);
        bi.bmiHeader.biPlanes        = 1;
        bi.bmiHeader.biBitCount      = 32;
        bi.bmiHeader.biCompression   = BI_RGB;

        HBITMAP hbmp = ::CreateDIBSection(0, &bi, DIB_RGB_COLORS, &m_pixels, NULL, 0);

        SelectObject(m_hDC, hbmp);

        if (m_hBitmap)
            DeleteObject(m_hBitmap);

        m_hBitmap = hbmp;
    }

private:
    HWND m_hView;
    HBITMAP m_hBitmap;
    HDC m_hDC;
    unsigned int m_width;
    unsigned int m_height;
    void* m_pixels;
};



// #define TEST_WKE_WND_CLASS   L"TestWkeWndClass"
// #define WKE_GPID             ((WCHAR*)31117)
class XWeb
{
public:
	HELE Init(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_hEleView = XEle_Create(x,y,cx,cy,hParent);
		m_webView = wkeCreateWebView();
		XEle_RegEventCPP(m_hEleView,XE_SIZE,&XWeb::OnSize);
		XEle_RegEventCPP(m_hEleView,XE_PAINT,&XWeb::OnDraw);
		m_Render.initex(XEle_GetHWND(m_hEleView),cx,cy);
		wkeResize(m_webView,cx,cy);
		wkeSetHostWindow(m_webView,XEle_GetHWND(m_hEleView),0,0);

		
		XEle_RegEventCPP(m_hEleView,XE_XC_TIMER,&XWeb::OnEleXCTimer);
		XEle_SetXCTimer(m_hEleView,m_nTimerId,50);
		
		XEle_RegEventCPP(m_hEleView,XE_SIZE,&XWeb::OnSize);
		XEle_RegEventCPP(m_hEleView,XE_KEYDOWN,&XWeb::OnKeyDown);
		XEle_RegEventCPP(m_hEleView,XE_KEYUP,&XWeb::OnKeyUp);
		XEle_RegEventCPP(m_hEleView,XE_CHAR,&XWeb::OnChar);
		XEle_RegEventCPP(m_hEleView,XE_LBUTTONDOWN,&XWeb::OnLButtonDown);
		XEle_RegEventCPP(m_hEleView,XE_LBUTTONUP,&XWeb::OnLButtonUp);
		XEle_RegEventCPP(m_hEleView,XE_RBUTTONDOWN,&XWeb::OnRButtonDown);
		XEle_RegEventCPP(m_hEleView,XE_RBUTTONUP,&XWeb::OnRButtonUp);
		XEle_RegEventCPP(m_hEleView,XE_MOUSEMOVE,&XWeb::OnMouseMove);
		
		XEle_EnableEvent_XE_MOUSEWHEEL(m_hEleView,TRUE);
		XEle_RegEventCPP(m_hEleView,XE_MOUSEWHEEL,&XWeb::OnMouseWheel);
		
		XEle_RegEventCPP(m_hEleView,XE_SETFOCUS,&XWeb::OnSetFocus);
		XEle_RegEventCPP(m_hEleView,XE_KILLFOCUS,&XWeb::OnKillFocus);
		
		XEle_RegEventCPP(m_hEleView,XE_PAINT,&XWeb::OnDraw);
		XEle_RegEventCPP(m_hEleView,XE_DESTROY,&XWeb::OnDestroy);
		return m_hEleView;
	}

	static HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		
		XWeb* pWeb = new XWeb;
		HELE hEle = pWeb->Init(x,y,cx,cy,hParent);
		if (pWeb == NULL)
		{
			delete pWeb;
			pWeb = NULL;
			return NULL;
		}
		_XC_SetType(hEle,XC_WEB); //设置类型
		_XC_AddType(hEle,XC_WEB); //增加类型
		_XC_BindData(hEle, (int)pWeb); //绑定关联
		return hEle;
	}


	wkeWebView* GetWebView()
	{
		return m_webView;
	}
private:
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		m_Render.renderBtimap(m_webView,hDraw);
		*pbHandled = TRUE;
		return 0;
	}
	void UnInit()
	{
		XEle_KillXCTimer(m_hEleView,m_nTimerId);
		wkeDestroyWebView(m_webView);
	}

	int OnDestroy(BOOL *pbHandled)
	{
		UnInit();
		delete this; //释放扩展类
		return 0;
	}
	int OnSize(BOOL *pbHandled)
	{
		if (m_webView)
		{
			RECT rt;
			XEle_GetClientRect(m_hEleView,&rt);
			wkeResize(m_webView,rt.right,rt.bottom);
			m_Render.resize(rt.right,rt.bottom);
		}
		return 0;
	}

	int OnMouseWheel(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		HWND hWnd = XEle_GetHWND(m_hEleView);
		POINT pt;
		pt.x = pPt->x;
		pt.y = pPt->y;
		ScreenToClient(hWnd, &pt);

		int delta = GET_WHEEL_DELTA_WPARAM(nFlags);

		unsigned int flags = 0;

		if (nFlags & MK_CONTROL)
			flags |= WKE_CONTROL;
		if (nFlags & MK_SHIFT)
			flags |= WKE_SHIFT;

		if (nFlags & MK_LBUTTON)
			flags |= WKE_LBUTTON;
		if (nFlags & MK_MBUTTON)
			flags |= WKE_MBUTTON;
		if (nFlags & MK_RBUTTON)
			flags |= WKE_RBUTTON;

		//flags = wParam;
		if (wkeFireMouseWheelEvent(m_webView, pt.x, pt.y, delta, flags))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnLButtonDown(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		if (OnMouseEvent(XEle_GetHWND(m_hEleView),WKE_MSG_LBUTTONDOWN,nFlags,pPt))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnLButtonUp(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{

		if (OnMouseEvent(XEle_GetHWND(m_hEleView),WKE_MSG_LBUTTONUP,nFlags,pPt))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnRButtonDown(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		
		if (OnMouseEvent(XEle_GetHWND(m_hEleView),WKE_MSG_RBUTTONDOWN,nFlags,pPt))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnRButtonUp(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		if (OnMouseEvent(XEle_GetHWND(m_hEleView),WKE_MSG_RBUTTONUP,nFlags,pPt))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnMouseMove(UINT nFlags,POINT *pPt,BOOL *pbHandled)
	{
		if (OnMouseEvent(XEle_GetHWND(m_hEleView),WKE_MSG_MOUSEMOVE,nFlags,pPt))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	bool OnMouseEvent(HWND hWnd,wkeMouseMessage message,UINT nFlags,POINT *pPt)
	{
		if (message == WKE_MSG_LBUTTONDOWN || message == WKE_MSG_MBUTTONDOWN || message == WKE_MSG_RBUTTONDOWN)
		{
			XWnd_SetFocusEle(XEle_GetHWINDOW(m_hEleView),m_hEleView);
			XEle_SetCapture(m_hEleView,TRUE);
//			SetCapture(hWnd);
		}
		else if (message == WKE_MSG_LBUTTONUP || message == WKE_MSG_MBUTTONUP || message == WKE_MSG_RBUTTONUP)
		{
			XEle_SetCapture(m_hEleView,FALSE);
//			ReleaseCapture();
		}

		int x = pPt->x;
		int y = pPt->y;

		unsigned int flags = 0;

		if (nFlags & MK_CONTROL)
			flags |= WKE_CONTROL;
		if (nFlags & MK_SHIFT)
			flags |= WKE_SHIFT;

		if (nFlags & MK_LBUTTON)
			flags |= WKE_LBUTTON;
		if (nFlags & MK_MBUTTON)
			flags |= WKE_MBUTTON;
		if (nFlags & MK_RBUTTON)
			flags |= WKE_RBUTTON;

		//flags = wParam;

		return wkeFireMouseEvent(m_webView, message, x, y, flags);
	}
	int OnSetFocus(BOOL *pbHandled)
	{
		wkeSetFocus(m_webView);
		*pbHandled = TRUE;
		return 0;
	}
	int OnKillFocus(BOOL *pbHandled)
	{
		wkeKillFocus(m_webView);
		*pbHandled = TRUE;
		return 0;
	}
	int OnKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		unsigned int virtualKeyCode = wParam;
		unsigned int flags = 0;
		if (HIWORD(lParam) & KF_REPEAT)
			flags |= WKE_REPEAT;
		if (HIWORD(lParam) & KF_EXTENDED)
			flags |= WKE_EXTENDED;

		//flags = HIWORD(lParam);

		if (wkeFireKeyDownEvent(m_webView, virtualKeyCode, flags, false))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnKeyUp(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		unsigned int virtualKeyCode = wParam;
		unsigned int flags = 0;
		if (HIWORD(lParam) & KF_REPEAT)
			flags |= WKE_REPEAT;
		if (HIWORD(lParam) & KF_EXTENDED)
			flags |= WKE_EXTENDED;

		//flags = HIWORD(lParam);

		if (wkeFireKeyUpEvent(m_webView, virtualKeyCode, flags, false))
		{
			*pbHandled = TRUE;
		}
		return 0;
	}
	int OnChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		unsigned int charCode = wParam;
		unsigned int flags = 0;
		if (HIWORD(lParam) & KF_REPEAT)
			flags |= WKE_REPEAT;
		if (HIWORD(lParam) & KF_EXTENDED)
			flags |= WKE_EXTENDED;

		//flags = HIWORD(lParam);
		if (wkeFireKeyPressEvent(m_webView, charCode, flags, false))
		{
			*pbHandled = TRUE;
		}

		return 0;
	}

// 	int OnDropFiles(HDROP hDropInfo , BOOL *pbHandled)
// 	{
// 
// 		*pbHandled = TRUE;
// 		return 0;
// 	}

	int OnImeStartComposition(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		HWND hWnd = XEle_GetHWND(m_hEleView);
		wkeRect caret;
		wkeGetCaretRect(m_webView,&caret);

		CANDIDATEFORM form;
		form.dwIndex = 0;
		form.dwStyle = CFS_EXCLUDE;
		form.ptCurrentPos.x = caret.x;
		form.ptCurrentPos.y = caret.y + caret.height;
		form.rcArea.top = caret.y;
		form.rcArea.bottom = caret.y + caret.height;
		form.rcArea.left = caret.x;
		form.rcArea.right = caret.x + caret.width;

		HIMC hIMC = ImmGetContext(hWnd);
		ImmSetCandidateWindow(hIMC, &form);
		ImmReleaseContext(hWnd, hIMC);

		*pbHandled = TRUE;
		return 0;
	}

	int OnEleXCTimer(UINT nTimerID,BOOL *pbHandled)
	{
		if (nTimerID == m_nTimerId)
		{
			if (XEle_IsShow(m_hEleView))
			{
				// 			wchar_t buffer[256] = {0};
				// 			wsprintfW(buffer,L"刷新%d \r\n",GetTickCount());
				// 			OutputDebugStringW(buffer);
				//			RECT rt;
				//			XEle_GetRect(m_hEleView,&rt);
				//			m_render->renderOffset(m_webView,rt.left,rt.top);
				XEle_RedrawEle(m_hEleView,FALSE);
			}
			*pbHandled = TRUE;
		}
		return 0;
	}
private:
	HELE m_hEleView;
	int m_nTimerId;
	wkeWebView*m_webView;
	CRenderGDI m_Render;
};


XC_API HELE WINAPI XWeb_Create(int x,int y,int cx,int cy,HXCGUI hParent);
XC_API wkeWebView* WINAPI XWeb_GetWebView(HELE hEle);

#endif // XWeb_h__