#include "Common.h"

#include <MATH.H>


HWINDOW  hWindow=NULL;
HELE hBtn = NULL;
//事件响应

xcgui::XWnd g_Wnd;


HIMAGE g_hImageBg ;
HIMAGE g_hImageFg ;

int nDrawHeight = 0;

int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    //弹出消息框

//	CreateThread(NULL,NULL,Thread,NULL,NULL,NULL);

	nDrawHeight+=10;
	g_Wnd.RedrawWnd();
//    MessageBoxW(XWnd_GetHWND(hWindow),L"你点击了按钮",L"提示",MB_OK);
    *pBool=TRUE; //对该事件进行拦截
    return 0;    //事件的返回值
}

int CALLBACK OnWndDrawWindow(HDRAW hDraw,BOOL *pbHandled)
{

	int nWidth = XImage_GetWidth(g_hImageFg);
	int nHeight= XImage_GetHeight(g_hImageFg);

	RECT rtBgSrc = {0};
	rtBgSrc.left = 0;
	rtBgSrc.right= nWidth;
	rtBgSrc.bottom = nHeight - nDrawHeight;
	rtBgSrc.top = 0;
	RECT rtBgDes = rtBgSrc;

	XDraw_ImageSuper2(hDraw,g_hImageBg,&rtBgSrc,&rtBgDes);


	RECT rtFgSrc = {0};
	rtFgSrc.left = 0;
	rtFgSrc.right= nWidth;
	rtFgSrc.bottom = nHeight;
	rtFgSrc.top = nHeight - nDrawHeight;
	RECT rtFgDes = rtFgSrc;

//	XDraw_Image(hDraw,g_hImageFg,0,0);
//	XDraw_Image(hDraw,g_hImageBg,0,2);

	XDraw_ImageSuper2(hDraw,g_hImageFg,&rtFgSrc,&rtFgDes);

	*pbHandled = TRUE;
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{

// 	AllocConsole();                                          // 开辟控制台
// 	SetConsoleTitleW(L"Debug Output");      // 设置控制台窗口标题
// 	freopen("CONOUT$","w",stdout);             // 重定向输出

    XInitXCGUI(); //初始化
	g_Wnd.Create(0,0,457,354,L"炫彩界面库-窗口");
	if (g_Wnd)
	{
		g_hImageBg = XImage_LoadFile(L"Thermometer.png");
		g_hImageFg = XImage_LoadFile(L"shui.png");

		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",g_Wnd);
		m_btn.SetType(button_type_close);

		xcgui::XBtn btnAdd(100,5,80,25,L"不断点击",g_Wnd); //创建按钮
		btnAdd.RegEventC(XE_BNCLICK,My_EventBtnClick);     //注册按钮点击事件

		g_Wnd.EnableDragWindow(TRUE);
		g_Wnd.EnableDrawBk(FALSE);
		g_Wnd.SetTransparentType(window_transparent_shaped);
		g_Wnd.GetBkManager().AddImage(window_state_whole_leave,XImage_LoadFile(L"Thermometer.png"));
		g_Wnd.RegEventC(WM_PAINT,OnWndDrawWindow);
		g_Wnd.ShowWindow(SW_SHOW);



	}
    XRunXCGUI(); //运行
    XExitXCGUI(); //释放资源

//	FreeConsole();
    return 0;
}


