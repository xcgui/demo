#include "Common.h"

//#include <Shlwapi.h>
//#include <shlwapi.h>

#define  MSGFLT_ADD		1
#define  MSGFLT_REMOVE	2

HWINDOW  hWindow=NULL;
int CALLBACK OnWndDropFile( HDROP hDropInfo, BOOL *pbHandled)
{
	MessageBoxA(NULL,"收到信息",NULL,MB_OK);
//	xtrace("收到消息！！！！！！！\r\n");
	return 0;
}

BOOL ChangeWndMessageFilterOk(UINT nMessage, BOOL bAllow)
{
    typedef BOOL (WINAPI * ChangeWindowMessageFilterOkFn)(UINT, DWORD);
	
    HMODULE hModUser32 = NULL;
    hModUser32 = LoadLibrary(_T("user32.dll"));
    if (hModUser32 == NULL) {
        return FALSE;
    }
	
    ChangeWindowMessageFilterOkFn pfnChangeWindowMessageFilter = (ChangeWindowMessageFilterOkFn) GetProcAddress(hModUser32, "ChangeWindowMessageFilter");
    if (pfnChangeWindowMessageFilter == NULL)
    {
        FreeLibrary(hModUser32);
        return FALSE;
    }
	
    FreeLibrary(hModUser32);
	
    return pfnChangeWindowMessageFilter(nMessage, bAllow ? MSGFLT_ADD : MSGFLT_REMOVE);
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
	DragAcceptFiles(XWnd_GetHWND(hWindow),TRUE);
    if(hWindow)
    {
		ChangeWndMessageFilterOk(WM_DROPFILES, MSGFLT_ADD);
		ChangeWndMessageFilterOk(0x0049, MSGFLT_ADD);

		XWnd_RegEventC(hWindow,WM_DROPFILES,OnWndDropFile);

        XWnd_ShowWindow(hWindow,SW_SHOW);//显示窗口
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


// 
// class CMyWindowElement
// {
// public:
//     HWINDOW m_hWindow;
//     CMyWindowElement(){
//         Init();
//     }
//     void Init()
//     {
//         m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
//    //     XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
// 		
//         HELE hEle=XEle_Create(20,50,100,100,m_hWindow);
// 		DragAcceptFiles(XWnd_GetHWND(m_hWindow),TRUE);
// //		XEle_RegEventCPP(hEle,XE_DROPFILES,&CMyWindowElement::OnDropFiles);
// 
// 		XWnd_RegEventC(m_hWindow,WM_DROPFILES,OnWndDropFile);
// //		XWnd_RegEventCPP(m_hWindow,XWM_WINDPROC,&CMyWindowElement::OnWndProc);
// 
//         XWnd_ShowWindow(m_hWindow,SW_SHOW);
//     }
// 
// 
// 	int OnWndProc(UINT message, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
// 	{
// 		switch (message)
// 		{
// 		case WM_MOUSEMOVE:
// 		case WM_MOUSEHOVER:
// 		case WM_LBUTTONUP:
// 		case WM_LBUTTONDOWN:
// 			break;
// 		default:
// //			xtrace("%d\r\n",message);
// 			break;
// 		}
// 	
// // 		if (message == WM_DROPFILES)
// // 		{
// // 			MessageBoxA(NULL,"收到回调",NULL,MB_OK);
// // 		}
// 		return 0;
// 	}
// 	int OnDropFiles(HDROP hDropInfo, BOOL *pbHandled)
// 	{
// 		MessageBoxA(NULL,NULL,NULL,MB_OK);
// 		wchar_t fileNameBuffer[MAX_PATH] = {0};
// 		UINT fileCount = DragQueryFileW(hDropInfo,0xFFFFFFFF,NULL,0);
// 
// 		for (UINT i = 0 ; i < fileCount; i++)
// 		{
// 			ZeroMemory(fileNameBuffer,MAX_PATH*sizeof(wchar_t));
// 			DragQueryFileW(hDropInfo,i,fileNameBuffer,MAX_PATH);
// 			OutputDebugStringW(fileNameBuffer);
// 		}
// 		DragFinish(hDropInfo);
// 
// 		return 0;
// 	}
// };
// 
// int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
// {
//     XInitXCGUI();
//     CMyWindowElement  MyWindowt;
//     XRunXCGUI();
//     XExitXCGUI();
//     return 0;
// }
// 



