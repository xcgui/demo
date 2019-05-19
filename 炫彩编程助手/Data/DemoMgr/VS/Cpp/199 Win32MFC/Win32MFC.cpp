// Win32MFC.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "resource.h"
#include "MFCDlg.h"
#define nullptr NULL
#include "Common.h"

CDialog Dlg;



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	
	HWND GetSafeWnd()
	{
		return XWnd_GetHWND(m_hWindow);
	}

    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {
            m_hButton =XBtn_Create(10,10,80,25,L"按钮",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //弹出消息框
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
        *pBool=TRUE; //对该事件进行拦截
        return 0;    //事件的返回值
    }
};



int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	if(!AfxWinInit(::GetModuleHandle(NULL),NULL,::GetCommandLine(),0))
	{
		//??_Module.LogEvent(_T("MFC初始化错误！"), EVENTLOG_ERROR_TYPE );
		return 1;
	}
 	// TODO: Place code here.
	AfxEnableControlContainer();
	XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
		Dlg.Create(IDD_DIALOG1);
		Dlg.ShowWindow(SW_SHOW);
		SetParent(Dlg.GetSafeHwnd(),MyWnd.GetSafeWnd());
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	
// #ifdef _AFXDLL
// 	Enable3dControls();			// Call this when using MFC in a shared DLL
// #else
// 	Enable3dControlsStatic();	// Call this when linking to MFC statically
// #endif
// 

	
	return 0;
}



