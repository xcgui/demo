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

// 			XEle_RegEventCPP(m_hEleBody,XE_XC_TIMER,&CMyWnd::OnEleXCTimer);
// 			XEle_SetXCTimer(m_hEleBody,100,100);

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
//		HDC hdcScreen = ::GetDC(::GetDesktopWindow());//CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
		
		HDC memhdc = ::CreateCompatibleDC(NULL);
//		HBITMAP menbmp = CreateBitmap(hdcScreen, 210, 210);
//		HBITMAP menbmp = ::CreateCompatibleBitmap(hdcScreen, 210, 210);
		HBITMAP menbmp = ::CreateCompatibleBitmap(memhdc, 210, 210);
		
		//::SetBkMode(memhdc, TRANSPARENT);
		::SelectObject(memhdc, menbmp);
		
		
		HDRAW hDrawTemp = XDraw_Create(memhdc);
		RECT rt = {0,0,210,210};
		XDraw_FillRectColor(hDraw,&rt,RGB(255,255,255),0);


		XDraw_FillRectColor(hDraw,&rt,RGB(0,0,0),0);
		XDraw_BitBlt(hDraw, 0, 0, 210, 210, memhdc, 0, 0, SRCAND);
		
		
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




