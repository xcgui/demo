#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
	HELE    m_hEle;

    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,350,350,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {
 			m_hEle = XEle_Create(8,30,300,300,m_hWindow);
 			XEle_RegEventCPP(m_hEle,XE_PAINT, &CMyWnd::OnDraw);

            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		XDCDraw XDrawDc(hDraw);
		XDrawDc.SetBrushColor(0);
		XDCGDI XGdiDC(hDraw);
		XGdiDC.SetBrushColor(0,0);
		XDCGDIPlus GdiplusDC(hDraw);



		GdiplusDC.SetSmoothingMode(SmoothingModeHighQuality);

		int x = 10;
		int y = 10;
		int cx = 200;
		int cy = 200;

		GdiplusDC.SetBrushColor(RGB(212,212,212),255);
		GdiplusDC.DrawRegularHexagon(x,y,cx,cy);


		x+=20;
		y+=20;
		cx-=40;
		cy-=40;
		GdiplusDC.SetBrushColor(RGB(231,231,231),255);
		GdiplusDC.FillRegularHexagon(x,y,cx,cy);

		GdiplusDC.SetBrushColor(RGB(212,212,212),255);
		GdiplusDC.DrawRegularHexagon(x,y,cx,cy);


		x+=20;
		y+=20;
		cx-=40;
		cy-=40;
		GdiplusDC.SetBrushColor(RGB(255,255,255),255);
		GdiplusDC.FillRegularHexagon(x,y,cx,cy);
		
		GdiplusDC.SetBrushColor(RGB(212,212,212),255);
		GdiplusDC.DrawRegularHexagon(x,y,cx,cy);


		x+=20;
		y+=20;
		cx-=40;
		cy-=40;
		GdiplusDC.SetBrushColor(RGB(231,231,231),255);
		GdiplusDC.FillRegularHexagon(x,y,cx,cy);
		
		GdiplusDC.SetBrushColor(RGB(212,212,212),255);
		GdiplusDC.DrawRegularHexagon(x,y,cx,cy);
		
		GdiplusDC.SetSmoothingMode(SmoothingModeHighSpeed);
		return 0;
	}
	
};


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
	
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
        XRunXCGUI(); //运行
    XExitXCGUI(); //释放资源
    return 0;
}




