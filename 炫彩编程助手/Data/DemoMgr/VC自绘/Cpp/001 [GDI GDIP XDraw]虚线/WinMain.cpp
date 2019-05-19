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
		XDraw_EnableSmoothingMode(hDraw,FALSE);
		XDCGDI XGdiDC(hDraw);
		XGdiDC.SetBrushColor(0,0);
		XDCGDIPlus GdiplusDC(hDraw);

		testDottedline(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	VOID testDottedline(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
		pXDrawDC->SetBrushColor(0);
		XTDCDottedline<XDCDraw> DrawLine;
		DrawLine.Create(10,10,100,0);
		DrawLine.Draw(pXDrawDC);

		XTDCDottedline<XDCGDI> GDILine;
		GDILine.Create(10,20,100,0);
		GDILine.Draw(pXGdiDC);

		XTDCDottedline<XDCGDIPlus> GDIPlusLine;
		GDIPlusLine.Create(10,30,100,0);
		GDIPlusLine.Draw(pGdiPlusDC);
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




