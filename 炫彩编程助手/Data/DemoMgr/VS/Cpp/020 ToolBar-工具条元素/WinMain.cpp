#include "Common.h"

class CMyWindowToolBar
{
public:
    HWINDOW m_hWindow;
    HELE    m_hToolBar;
    CMyWindowToolBar()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 400, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hToolBar = XToolBar_Create(20, 40, 320, 28, m_hWindow);
        HELE hButton1=XBtn_Create(0,0,60,20,L"Button1");
        HELE hButton2=XBtn_Create(0,0,60,20,L"Button2");
        HELE hButton3=XBtn_Create(0,0,60,20,L"Button3");
        HELE hButton4=XBtn_Create(0,0,60,20,L"Button4");
        HELE hButton5=XBtn_Create(0,0,60,20,L"Button5");
        XToolBar_InsertEle(m_hToolBar,hButton1);
        XToolBar_InsertEle(m_hToolBar,hButton2);
        XToolBar_InsertEle(m_hToolBar,hButton3);
        XToolBar_InsertEle(m_hToolBar,hButton4);
        XToolBar_InsertEle(m_hToolBar,hButton5);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowToolBar  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
