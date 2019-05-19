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

		TestTable(&XDrawDc,&XGdiDC,&GdiplusDC);
		
		return 0;
	}

	void TestTable(XDCDraw* pXDrawDC,XDCGDI* pXGdiDC,XDCGDIPlus* pGdiPlusDC)
	{
		XTDCTable<XDCGDI> GdiTable;
		GdiTable.Create(10,10,200,40);
		GdiTable.SetColumnCount(4);
		GdiTable.SetRowCount(2);
		GdiTable.SetColumnWidth(1,100);
		GdiTable.SetRowHeight(1,30);
		GdiTable.Draw(pXGdiDC);


		XTDCTable<XDCDraw> DrawTable;
		DrawTable.Create(10,70,200,40);
		DrawTable.SetColumnCount(4);
		DrawTable.SetRowCount(2);
		DrawTable.SetColumnWidth(1,100);
		DrawTable.SetRowHeight(1,30);
		DrawTable.Draw(pXDrawDC);


		XTDCTable<XDCGDIPlus> GdiPlusTable;
		GdiPlusTable.Create(10,130,200,40);
		GdiPlusTable.SetColumnCount(4);
		GdiPlusTable.SetRowCount(2);
		GdiPlusTable.SetColumnWidth(1,100);
		GdiPlusTable.SetRowHeight(1,30);
		GdiPlusTable.Draw(pGdiPlusDC);
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




