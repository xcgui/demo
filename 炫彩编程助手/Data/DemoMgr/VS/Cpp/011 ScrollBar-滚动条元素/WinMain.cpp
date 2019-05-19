#include "Common.h"

class CMyWindowScrollBar
{
public:
    HWINDOW m_hWindow;
    CMyWindowScrollBar()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 300, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        HELE hSBar1=XSBar_Create(20,50,200,20,m_hWindow);
		
        HELE hSBar2=XSBar_Create(230,50,20,200,m_hWindow);
        XSBar_SetHorizon(hSBar2,FALSE);
		
        XEle_RegEventCPP(hSBar1,XE_SBAR_SCROLL,&CMyWindowScrollBar::OnSBarScroll);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnSBarScroll(int pos,BOOL *pbHandled)
    {
        XTRACE("pos=%d \n",pos);
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowScrollBar  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
