#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
	HELE    m_hEle;
	XMathTool m_MathTool;

	Gdiplus::Bitmap* m_pBitMap;

	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		Gdiplus::Color cor;
		m_pBitMap->GetPixel(pPt->x,pPt->y,&cor);

		byte balpha =cor.GetAlpha();
		if (balpha == 0)
		{
			MessageBoxA(NULL,"这里是空白区域，少年别白费力了",NULL,MB_OK);
			*pbHandled = TRUE;
		}

		return 0;
	}

	int  OnBtnClick(BOOL *pbHandled)
	{
		MessageBoxA(NULL,"按钮被点击",NULL,MB_OK);
		return 0;
	}
    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,350,350,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {
 			m_hEle = XBtn_Create(8,30,128,128,NULL,m_hWindow);
			XEle_EnableBkTransparent(m_hEle,TRUE);
			XEle_EnableDrawFocus(m_hEle,FALSE);

			XBtn_AddBkImage(m_hEle,button_state_leave,XImage_LoadFile(L"xuan.png"));
			XBtn_AddBkImage(m_hEle,button_state_stay,XImage_LoadFile(L"xuan2.png"));
			XBtn_AddBkImage(m_hEle,button_state_down,XImage_LoadFile(L"xuan3.png"));
			

			XEle_RegEventCPP(m_hEle,XE_PAINT, &CMyWnd::OnDraw);
			XEle_RegEventCPP(m_hEle,XE_BNCLICK,&CMyWnd::OnBtnClick);
			XEle_RegEventCPP(m_hEle,XE_LBUTTONDOWN,&CMyWnd::OnLButtonDown);


			m_pBitMap = new Gdiplus::Bitmap(L"xuan.png");

            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		XDCDraw XDrawDc(hDraw);
		XDrawDc.SetBrushColor(0);
		XDraw_EnableSmoothingMode(hDraw,FALSE);
		XDCGDI XGdiDC(hDraw);
		XGdiDC.SetBrushColor(0,0);
		XDCGDIPlus GdiplusDC(hDraw);

		testEllipse(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	VOID testEllipse(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
// 		int x = 50;
// 		int y = 50;
// 		int cx = 240;
// 		int cy = 240;
// 
// 		{
// 			POINT pt1;
// 			POINT pt2;
// 			POINT pt3;
// 			
// 			m_MathTool.AngleToPoint(x,y,cx,cy,105,&pt1,FALSE);
// 			m_MathTool.AngleToPoint(x,y,cx,cy,225,&pt2,FALSE);
// 			m_MathTool.AngleToPoint(x,y,cx,cy,345,&pt3,FALSE);
// 			//画连接线
// 			
// 			pXDrawDC->DrawLine(pt1.x,pt1.y,pt2.x,pt2.y);
// 			pXDrawDC->DrawLine(pt2.x,pt2.y,pt3.x,pt3.y);
// 			pXDrawDC->DrawLine(pt3.x,pt3.y,pt1.x,pt1.y);
// 		}
// 
// 		{
// 			POINT pt1;
// 			POINT pt2;
// 			POINT pt3;
// 			
// 			m_MathTool.AngleToPoint(x,y,cx,cy,0,&pt1,FALSE);
// 			m_MathTool.AngleToPoint(x,y,cx,cy,120,&pt2,FALSE);
// 			m_MathTool.AngleToPoint(x,y,cx,cy,240,&pt3,FALSE);
// 			//画连接线
// 			
// 			pXDrawDC->DrawLine(pt1.x,pt1.y,pt2.x,pt2.y);
// 			pXDrawDC->DrawLine(pt2.x,pt2.y,pt3.x,pt3.y);
// 			pXDrawDC->DrawLine(pt3.x,pt3.y,pt1.x,pt1.y);
// 		}
// 
// 		{
// 			POINT pt1;
// 			POINT pt2;
// 			POINT pt3;
// 			
// 			m_MathTool.AngleToPoint(x,y,cx,cy,15,&pt1,FALSE);
// 			m_MathTool.AngleToPoint(x,y,cx,cy,135,&pt2,FALSE);
// 			m_MathTool.AngleToPoint(x,y,cx,cy,255,&pt3,FALSE);
// 			//画连接线
// 			
// 			pXDrawDC->DrawLine(pt1.x,pt1.y,pt2.x,pt2.y);
// 			pXDrawDC->DrawLine(pt2.x,pt2.y,pt3.x,pt3.y);
// 			pXDrawDC->DrawLine(pt3.x,pt3.y,pt1.x,pt1.y);
// 		}
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




