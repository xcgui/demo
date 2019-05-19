#include "Common.h"


xcgui::XWnd g_Wnd;
xcgui::XEle g_Ele;
xcgui::XShapeText g_ShapeText;

#define XE_USER_SETTEXT WM_USER+999




int CALLBACK OnEventProc(HELE hEventEle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
{
	switch(nEvent)
	{
	case XE_USER_SETTEXT:
		{
			g_ShapeText.SetText((wchar_t*)wParam);
			XEle_RedrawEle(hEventEle);
		}
		break;
	}
	return 0;
}

int CALLBACK OnSetText(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	g_Ele.SendEvent(g_Ele,XE_USER_SETTEXT,wParam,lParam);
	return 0;
}

DWORD WINAPI ThreadPro(LPVOID lpVoid)
{
	SYSTEMTIME tm;
	for (int i = 0; i < 10; i++)
	{
		wchar_t buffer[MAX_PATH] ={0};
		GetSystemTime(&tm);
		wsprintfW(buffer,L"%d:%d",tm.wMinute,tm.wSecond);
		SendMessageW(g_Wnd.GetHWND(),XE_USER_SETTEXT,(WPARAM)buffer,wcslen(buffer));
		Sleep(1000);
	}
	return 0;
}

//消息路由方式 线程->窗口自定义消息过程->元素过程
//


//事件响应
int CALLBACK My_EventBtnClick(BOOL *pBool)
{
    CloseHandle(CreateThread(NULL,0,ThreadPro,NULL,0,NULL));
    *pBool=TRUE; //对该事件进行拦截
    return 0;    //事件的返回值
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    g_Wnd.Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(g_Wnd)
    {
		g_Ele.Create(8,30,100,50,g_Wnd);
		//因为形状对象没有事件，所以创建一个 ele作为父，然后接受各种消息
		g_ShapeText.Create(0,0,100,20,L"初始化",g_Ele);
		g_Ele.RegEventC1(XE_ELEPROCE,OnEventProc);


		xcgui::XBtn test(10,5,80,20,L"创建线程",g_Wnd); //创建按钮
		test.RegEventC(XE_BNCLICK,My_EventBtnClick);    //注册按钮点击事件

		g_Wnd.RegEventC(XE_USER_SETTEXT,OnSetText);
		g_Wnd.ShowWindow(SW_SHOW);
		
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


