#include "Common.h"


class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
		HWINDOW hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库-窗口");//创建窗口
		if (hWindow)
		{
			HELE hButton = XBtn_Create(100, 50, 80, 25, L"Button", hWindow); //创建按钮
	
			XBtn_AddBkImage(hButton, button_state_leave, XImage_LoadFile(L"image\\Sys\\msg_icon_info.png")); //设置鼠标离开状态贴图
			XBtn_AddBkImage(hButton, button_state_stay, XImage_LoadFile(L"image\\Sys\\msg_icon_error.png")); //设置鼠标停留状态贴图
			XBtn_AddBkImage(hButton, button_state_down, XImage_LoadFile(L"image\\Sys\\msg_icon_check.png")); //设置鼠标按下状态贴图
			
		}
		XWnd_ShowWindow(hWindow, SW_SHOW);//显示

    }
    int OnBtnClick(BOOL *pbHandled)
    {
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowButton  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




