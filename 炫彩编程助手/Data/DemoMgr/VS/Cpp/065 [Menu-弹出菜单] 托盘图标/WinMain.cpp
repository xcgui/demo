#include "Common.h"


#define  WM_SHOWTASK (WM_USER+100)

class CTrayEx
{
public:
	int OnWndDestroy(BOOL *pbHandled)
	{
		DeleteTray();
		return 0;
	}
	int OnShowWindow(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		if (wParam == TRUE)
		{
			DeleteTray();
		} 
		else
		{
			CreateTray();
			
		}
		return 0;
	}
	void Create(HWINDOW hWindow)
	{
		m_hWindow = hWindow;
		XWnd_RegEventCPP(m_hWindow,WM_SHOWTASK,&CTrayEx::OnWndTray);
		XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CTrayEx::OnWndDestroy);
		XWnd_RegEventCPP(m_hWindow, XWM_MENU_SELECT, &CTrayEx::OnWndMenuSelect);
		XWnd_RegEventCPP(m_hWindow,WM_SHOWWINDOW,&CTrayEx::OnShowWindow);
	}
	void CreateTray()
	{
		NOTIFYICONDATAW tnd;
		tnd.cbSize=sizeof(NOTIFYICONDATAW);
		tnd.hWnd=XWnd_GetHWND(m_hWindow);
		tnd.uID=100;
		tnd.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
		tnd.uCallbackMessage=WM_SHOWTASK; //用户自定义的消息，即鼠标在任务栏上程序图标上动作时图标发送的消息
		tnd.hIcon=LoadIcon(NULL,IDI_APPLICATION);
		wcscpy(tnd.szTip,L"测试程序");//图标提示为"测试程序"
		Shell_NotifyIconW(NIM_ADD,&tnd);//向任务栏添加图标
	}
	void DeleteTray()
	{
		NOTIFYICONDATAW nid; 
		nid.cbSize=(DWORD)sizeof(NOTIFYICONDATAW); 
		nid.hWnd=XWnd_GetHWND(m_hWindow); 
		nid.uID=100; 
		nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ; 
		nid.uCallbackMessage=WM_SHOWTASK;//自定义的消息名称 
		nid.hIcon=LoadIcon(NULL,IDI_APPLICATION); 
		wcscpy(nid.szTip,L"程序名称");    //信息提示条为“计划任务提醒” 
		Shell_NotifyIconW(NIM_DELETE,&nid);    //在托盘区删除图标 
	}
public:
	int  OnWndMenuSelect(int nID,BOOL *pBool)
    {
		switch (nID)
		{
		case 202:
			XWnd_ShowWindow(m_hWindow,SW_SHOW);
			break;
		case 203:
			XWnd_ShowWindow(m_hWindow,SW_HIDE);
			break;
		case 204:
			XWnd_CloseWindow(m_hWindow);
			break;
		}
        XTRACE("menu-XWM_MENU_SELECT item:%d\n",nID);
        return 0;
    }
	int OnWndTray(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		
		if(wParam!=100) 
			return 1; 
		switch(lParam) 
		{    
        case WM_RBUTTONUP://右键起来时弹出快捷菜单，这里只有一个“关闭” 
			{ 
				SetForegroundWindow(XWnd_GetHWND(m_hWindow));
				
				HMENUX hMenu = XMenu_Create();
				XMenu_AddItem(hMenu, 202, L"显示");
				XMenu_AddItem(hMenu, 203, L"隐藏");
				XMenu_AddItem(hMenu, 204, L"退出");
				
				POINT pt;
				GetCursorPos(&pt);
				XMenu_Popup(hMenu, XWnd_GetHWND(m_hWindow), pt.x, pt.y);
				
			} 
			break; 
        case WM_LBUTTONDBLCLK://双击左键的处理 
			{ 
				XWnd_ShowWindow(m_hWindow,SW_SHOW);//简单的显示主窗口完事儿
			} 
			break; 
        default:
			{
				return 0;
			}
			break;
		} 
		return 0;
	}
	
	
private:
	HWINDOW m_hWindow;
};

class CTray
{
public:
	int OnWndDestroy(BOOL *pbHandled)
	{
		DeleteTray();
		return 0;
	}
	void Create(HWINDOW hWindow)
	{
		m_hWindow = hWindow;
		XWnd_RegEventCPP(m_hWindow,WM_SHOWTASK,&CTray::OnWndTray);
		XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CTray::OnWndDestroy);
		XWnd_RegEventCPP(m_hWindow, XWM_MENU_SELECT, &CTray::OnWndMenuSelect);
//		XWnd_RegEventCPP(m_hWindow,WM_SYSCOMMAND,&CTray::);
	}
	void CreateTray()
	{
		NOTIFYICONDATAW tnd;
		tnd.cbSize=sizeof(NOTIFYICONDATAW);
		tnd.hWnd=XWnd_GetHWND(m_hWindow);
		tnd.uID=100;
		tnd.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
		tnd.uCallbackMessage=WM_SHOWTASK; //用户自定义的消息，即鼠标在任务栏上程序图标上动作时图标发送的消息
		tnd.hIcon=LoadIcon(NULL,IDI_APPLICATION);
		wcscpy(tnd.szTip,L"测试程序");//图标提示为"测试程序"
		Shell_NotifyIconW(NIM_ADD,&tnd);//向任务栏添加图标
	}
	void DeleteTray()
	{
		NOTIFYICONDATAW nid; 
		nid.cbSize=(DWORD)sizeof(NOTIFYICONDATAW); 
		nid.hWnd=XWnd_GetHWND(m_hWindow); 
		nid.uID=100; 
		nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ; 
		nid.uCallbackMessage=WM_SHOWTASK;//自定义的消息名称 
		nid.hIcon=LoadIcon(NULL,IDI_APPLICATION); 
		wcscpy(nid.szTip,L"程序名称");    //信息提示条为“计划任务提醒” 
		Shell_NotifyIconW(NIM_DELETE,&nid);    //在托盘区删除图标 
	}
public:
	int  OnWndMenuSelect(int nID,BOOL *pBool)
    {
		switch (nID)
		{
		case 202:
			XWnd_ShowWindow(m_hWindow,SW_SHOW);
			break;
		case 203:
			XWnd_ShowWindow(m_hWindow,SW_HIDE);
			break;
		case 204:
			XWnd_CloseWindow(m_hWindow);
			break;
		}
        XTRACE("menu-XWM_MENU_SELECT item:%d\n",nID);
        return 0;
    }
	int OnWndTray(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{

		if(wParam!=100) 
			return 1; 
		switch(lParam) 
		{    
        case WM_RBUTTONUP://右键起来时弹出快捷菜单，这里只有一个“关闭” 
			{ 
				SetForegroundWindow(XWnd_GetHWND(m_hWindow));

				HMENUX hMenu = XMenu_Create();
				XMenu_AddItem(hMenu, 202, L"显示");
				XMenu_AddItem(hMenu, 203, L"隐藏");
				XMenu_AddItem(hMenu, 204, L"退出");

				POINT pt;
				GetCursorPos(&pt);
				XMenu_Popup(hMenu, XWnd_GetHWND(m_hWindow), pt.x, pt.y);
				
			} 
			break; 
        case WM_LBUTTONDBLCLK://双击左键的处理 
			{ 
				XWnd_ShowWindow(m_hWindow,SW_SHOW);//简单的显示主窗口完事儿
			} 
			break; 
        default:
			{
				return 0;
			}
			break;
		} 
		return 0;
	}


private:
	HWINDOW m_hWindow;
};

class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	CTray   m_Tray;
	CTrayEx m_TrayEx;
	
    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {
            m_hButton =XBtn_Create(10,10,80,25,L"隐藏",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			
			//m_Tray.Create(m_hWindow);
			m_TrayEx.Create(m_hWindow);
			
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }

    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
//		m_Tray.CreateTray();
		ShowWindow(XWnd_GetHWND(m_hWindow), SW_HIDE);

        *pBool=TRUE; //对该事件进行拦截
        return 0;    //事件的返回值
    }

private:
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




