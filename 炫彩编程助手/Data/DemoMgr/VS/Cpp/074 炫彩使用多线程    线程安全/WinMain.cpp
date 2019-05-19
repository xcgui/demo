#include "Common.h"



HWINDOW  hWindow=NULL;
HELE g_hEle = NULL;
HXCGUI g_ShapeText = NULL;



#define XE_USER_SETTEXT WM_USER+999




int CALLBACK OnEventProc(HELE hEventEle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
{
	switch(nEvent)
	{
	case XE_USER_SETTEXT:
		{
			XShapeText_SetText(g_ShapeText,(wchar_t*)wParam);
			XEle_RedrawEle(hEventEle);
		}
		break;
	}
	return 0;
}

int CALLBACK OnSetText(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	XEle_SendEvent(g_hEle,g_hEle,XE_USER_SETTEXT,wParam,lParam);
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
		SendMessageW(XWnd_GetHWND(hWindow),XE_USER_SETTEXT,(WPARAM)buffer,wcslen(buffer));
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
    hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(hWindow)
    {
		g_hEle = XEle_Create(8,30,100,50,hWindow);
		//因为形状对象没有事件，所以创建一个 ele作为父，然后接受各种消息
		g_ShapeText = XShapeText_Create(0,0,100,20,L"初始化",g_hEle);
		XEle_RegEventC1(g_hEle,XE_ELEPROCE,OnEventProc);


        HELE hButton=XBtn_Create(10,5,80,20,L"创建线程",hWindow);//创建按钮
        XEle_RegEventC(hButton,XE_BNCLICK,My_EventBtnClick);//注册按钮点击事件
		

		XWnd_RegEventC(hWindow,XE_USER_SETTEXT,OnSetText);
        XWnd_ShowWindow(hWindow,SW_SHOW);//显示窗口
		
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


