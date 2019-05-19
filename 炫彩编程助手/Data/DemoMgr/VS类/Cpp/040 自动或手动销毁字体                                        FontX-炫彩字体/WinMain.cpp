#include "Common.h"


//自动销毁字体
VOID AutoDestoryFont(HELE hEle)
{
	HFONTX hFontx = XFont_Create(20);
	HFONTX hFontx1 = XFont_Create(30);
	
	XEle_SetFont(hEle,hFontx);
	XEle_SetFont(hEle,hFontx1);
}
//手动销毁字体
VOID ManualDestoryFont(HELE hEle)
{
	
	HFONTX hFontx = XFont_Create(20);
	XFont_EnableAutoDestroy(hFontx,FALSE); //允许手动销毁字体

	HFONTX hFontx1 = XFont_Create(30);
	XEle_SetFont(hEle,hFontx);
	XEle_SetFont(hEle,hFontx1);

	XFont_Destroy(hFontx);
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
	xcgui::XWnd m_Wnd(0, 0, 300, 200, L"炫彩界面库窗口");
    if(m_Wnd)
    {
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);

        HELE hButton=XBtn_Create(10,30,100,100,L"按钮",m_Wnd);//创建按钮
		ManualDestoryFont(hButton);

		m_Wnd.ShowWindow(SW_SHOW);
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


