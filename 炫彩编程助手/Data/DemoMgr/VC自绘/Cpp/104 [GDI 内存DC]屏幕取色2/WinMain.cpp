#define  _WIN32_WINNT 0x500
#define USE_GDIPLUS
#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hEleBody;
	
    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {

			HXCGUI hLayoutBody = XLayout_Create();
			XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);
			XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);
			XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);

			m_hEleBody = XEle_Create(0,0,100,100,m_hWindow);
			XLayout_AddEle(hLayoutBody,m_hEleBody);
			XEle_SetLayoutHeight(m_hEleBody,layout_size_type_fill,1);
			XEle_SetLayoutWidth(m_hEleBody,layout_size_type_fill,1);

			XLayout_SetPadding(hLayoutBody,5,5,5,5);

			XEle_RegEventCPP(m_hEleBody,XE_PAINT,&CMyWnd::OnDraw);

			XEle_RegEventCPP(m_hEleBody,XE_XC_TIMER,&CMyWnd::OnEleXCTimer);
			XEle_SetXCTimer(m_hEleBody,100,100);

			XWnd_SetTransparentType(m_hWindow,window_transparent_shadow);
			XWnd_SetTransparentAlpha(m_hWindow,255);
			XWnd_SetShadowInfo(m_hWindow,10,200,10,TRUE,0);

			XWnd_AdjustLayout(m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
	int OnEleXCTimer(UINT nTimerID,BOOL *pbHandled)
	{
		XEle_RedrawEle(m_hEleBody,TRUE);
		return 0;
	}
	int OnDraw(HDRAW hDraw, BOOL *pbHandled)
	{
		HDC hdcScreen = ::GetDC(::GetDesktopWindow());//CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
		
		HDC memhdc = ::CreateCompatibleDC(NULL);
//		HBITMAP menbmp = CreateBitmap(hdcScreen, 210, 210);
		HBITMAP menbmp = ::CreateCompatibleBitmap(hdcScreen, 210, 210);
		
		//::SetBkMode(memhdc, TRANSPARENT);
		::SelectObject(memhdc, menbmp);
		
		

		
		POINT pt;
		GetCursorPos(&pt);
		
		
		
		int parent_w = 210; //父窗口的大小w
		int parent_h = 210; //父窗口的大小h
		int pbit = 10;     //放大倍数
		
		int MyWidth = parent_w / pbit;
		int MyHeight = parent_h / pbit;
		
		int maxx = GetDeviceCaps(hdcScreen, HORZRES) - MyWidth;
		int maxy = GetDeviceCaps(hdcScreen, VERTRES) - MyHeight;
		
		int sourcex = pt.x - MyWidth / 2;
		int sourcey = pt.y - MyHeight / 2;
		
		if (sourcex < 0)	sourcex = 0;
		if (sourcex > maxx)	sourcex = maxx;
		if (sourcey < 0)	sourcey = 0;
		if (sourcey > maxy)	sourcey = maxy;
		
		int xoffset = (pt.x - sourcex) * pbit;
		int yoffset = (pt.y - sourcey) * pbit;
		
//		SetStretchBltMode(memhdc,WHITEONBLACK);
//		RECT rt = {0,0,210,210};
//		SetDCBrushColor(memhdc,0);
//		FillRect(memhdc,&rt,(HBRUSH)GetStockObject(18));

// 		Graphics gp(memhdc);
// 		SolidBrush br(Color(255,0,0,0));
// 		gp.FillRectangle(&br,0,0,210,210);


		::StretchBlt(memhdc, 0, 0, parent_w, parent_h, hdcScreen, sourcex, sourcey, MyWidth, MyHeight, SRCCOPY|CAPTUREBLT);

//		::StretchBlt(memhdc, 0, 0, parent_w, parent_h, hdcScreen, sourcex, sourcey, MyWidth, MyHeight, SRCPAINT|CAPTUREBLT);
		
		HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		::SelectObject(memhdc, hPen);
		MoveToEx(memhdc, xoffset - 1, yoffset - 1, NULL);
		LineTo(memhdc, xoffset + pbit, yoffset - 1);
		LineTo(memhdc, xoffset + pbit, yoffset + pbit);
		LineTo(memhdc, xoffset - 1, yoffset + pbit);
		LineTo(memhdc, xoffset - 1, yoffset - 1);
	
		RECT rt = {0,0,210,210};		
		XDraw_FillRectColor(hDraw,&rt,RGB(0,0,0));

		XDraw_BitBlt(hDraw, 0, 0, 210, 210, memhdc, 0, 0, SRCPAINT);
		

// 		XDraw_FillRectColor(hDraw,&rt,RGB(220,220,220));
// 		XDraw_BitBlt(hDraw, 0, 0, 210, 210, memhdc, 0, 0, SRCPAINT);
		
		
//		XDraw_AlphaBlend(hDraw,0,0,210,210,memhdc,0,0,210,210,255);

		
		::DeleteDC(memhdc);
		::DeleteObject(menbmp);
		return 0;
	}

	HBITMAP CreateBitmap(HDC m_MemDC, int nWidth, int nHeight)  
    {  
        BITMAPINFO bi;  
        bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);  
        bi.bmiHeader.biBitCount = 32;  
        bi.bmiHeader.biHeight = nHeight;  
        bi.bmiHeader.biWidth  = nWidth;  
        bi.bmiHeader.biPlanes = 1;  
        bi.bmiHeader.biCompression = BI_RGB;  
        bi.bmiHeader.biXPelsPerMeter = 0;  
        bi.bmiHeader.biYPelsPerMeter = 0;  
        bi.bmiHeader.biClrUsed = 0;  
        bi.bmiHeader.biSizeImage = 0;  
        bi.bmiHeader.biSizeImage = nWidth * nHeight * bi.bmiHeader.biBitCount / 8;  
		
        HBITMAP m_hBmp = ::CreateDIBSection(m_MemDC, &bi, 0, NULL, 0, 0);//创建32位位图  

		return m_hBmp;
    }  
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




