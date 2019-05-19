#include "Common.h"


#define XE_USER_SETTEXT WM_USER+999

class XMyWnd
{
public:

	//事件响应
	int My_EventBtnClick(BOOL *pBool)
	{
		CloseHandle(CreateThread(NULL,0,&XMyWnd::ThreadPro,m_hWindow,0,NULL));
		*pBool=TRUE; //对该事件进行拦截
		return 0;    //事件的返回值
	}
	int OnSetText(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		XShapeText_SetText(m_ShapeText,(wchar_t*)wParam);
		XEle_RedrawEle(m_hEle);
		return 0;
	}
	BOOL Create()
	{

		m_hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
		if (m_hWindow == NULL)
			return FALSE;
		m_hEle = XEle_Create(8,30,100,50,m_hWindow);
		//因为形状对象没有事件，所以创建一个 ele作为父，然后接受各种消息
		m_ShapeText = XShapeText_Create(0,0,100,20,L"初始化",m_hEle);

	
        HELE hButton=XBtn_Create(10,5,80,20,L"创建线程",m_hWindow);//创建按钮
        XWnd_RegEventCPP(hButton,XE_BNCLICK,&XMyWnd::My_EventBtnClick);//注册按钮点击事件
		
		
		XWnd_RegEventCPP(m_hWindow,XE_USER_SETTEXT,&XMyWnd::OnSetText);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);//显示窗口
		return TRUE;
	}


	
static	DWORD WINAPI ThreadPro(LPVOID lpVoid)
{
HWINDOW hWindow = (HWINDOW) lpVoid;
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
private:

	HWINDOW  m_hWindow;
	HELE m_hEle;
	HXCGUI m_ShapeText;
};


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    
	XMyWnd MyWnd;
    if(MyWnd.Create())
        XRunXCGUI(); //运行
 
    XExitXCGUI(); //释放资源
    return 0;
}


