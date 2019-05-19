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

		testEllipse(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	VOID testEllipse(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
		int x = 50;
		int y = 50;
		int cx = 240;
		int cy = 240;

		{
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(128,128,128),20);
			pXDrawDC->FillEllipse(&rt);
		}

		{
			x+=5;
			y+=5;
			cx-=10;
			cy-=10;
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(129,175,205));
			pXDrawDC->FillEllipse(&rt);
		}

		{
			x+=30;
			y+=30;
			cx-=60;
			cy-=60;
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(149,184,206));
			pXDrawDC->FillEllipse(&rt);
		}
		{
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(255,255,255));
			pXDrawDC->DrawEllipse(&rt);
		}

		{
			x+=30;
			y+=30;
			cx-=60;
			cy-=60;
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(200,216,226));
			pXDrawDC->FillEllipse(&rt);
		}
		{
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(255,255,255));
			pXDrawDC->DrawEllipse(&rt);
		}

		{
			x+=30;
			y+=30;
			cx-=60;
			cy-=60;
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(223,231,237));
			pXDrawDC->FillEllipse(&rt);
		}
		{
			RECT rt = {x,y,x+cx,y+cy};
			pXDrawDC->SetBrushColor(RGB(255,255,255));
			pXDrawDC->DrawEllipse(&rt);
		}


		x = 55;
		y = 55;
		cx = 230;
		cy = 230;

		int CenterPosX = x+cx/2;
		int CenterPosY = y+cy/2;

		POINT pt1;
		m_MathTool.AngleToPoint(x,y,cx,cy,0,&pt1,FALSE);
		//画连接线
		pXDrawDC->DrawLine(CenterPosX,CenterPosY,pt1.x,pt1.y);


		{
			POINT pt2;
			m_MathTool.AngleToPoint(x,y,cx,cy,72,&pt2,FALSE);
			//画连接线
			pXDrawDC->DrawLine(CenterPosX,CenterPosY,pt2.x,pt2.y);
		}

		{
			POINT pt2;
			m_MathTool.AngleToPoint(x,y,cx,cy,144,&pt2,FALSE);
			//画连接线
			pXDrawDC->DrawLine(CenterPosX,CenterPosY,pt2.x,pt2.y);
		}

		{
			POINT pt2;
			m_MathTool.AngleToPoint(x,y,cx,cy,216,&pt2,FALSE);
			//画连接线
			pXDrawDC->DrawLine(CenterPosX,CenterPosY,pt2.x,pt2.y);
		}

		{
			POINT pt2;
			m_MathTool.AngleToPoint(x,y,cx,cy,288,&pt2,FALSE);
			//画连接线
			pXDrawDC->DrawLine(CenterPosX,CenterPosY,pt2.x,pt2.y);
		}

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




