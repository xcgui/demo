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
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hButton = XBtn_Create(100, 50, 150, 30,L"", m_hWindow);
		
		XBtn_SetType(m_hButton,button_type_check);
		XBtn_SetStyle(m_hButton,button_style_default);


		HBKM hBkInfoM = XEle_GetBkManager(m_hButton);

XBkM_AddImage(hBkInfoM,button_state_flag_leave|button_state_flag_check_no,XImage_LoadFile(L"noCheck_leave.png"));
XBkM_AddImage(hBkInfoM,button_state_flag_stay|button_state_flag_check_no,XImage_LoadFile(L"noCheck_hover.png"));
XBkM_AddImage(hBkInfoM,button_state_flag_down|button_state_flag_check_no,XImage_LoadFile(L"noCheck_down.png"));


XBkM_AddImage(hBkInfoM,button_state_flag_leave|button_state_flag_check,XImage_LoadFile(L"Check_leave.png"));
XBkM_AddImage(hBkInfoM,button_state_flag_stay|button_state_flag_check,XImage_LoadFile(L"Check_hover.png"));
XBkM_AddImage(hBkInfoM,button_state_flag_down|button_state_flag_check,XImage_LoadFile(L"Check_down.png"));




        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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




