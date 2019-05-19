#include "Common.h"

class CMyWindowScrollBar
{
public:
	xcgui::XWnd m_Wnd;
	

    CMyWindowScrollBar()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"炫彩界面库窗口");
		
		xcgui::XBtn m_btn;
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
		xcgui::XSBar sbar1,sbar2;
		sbar1.Create(20,50,200,20,m_Wnd);

        sbar2.Create(230,50,20,200,m_Wnd);
        sbar2.SetHorizon(FALSE); //设置垂直
		
        XEle_RegEventCPP(sbar1,XE_SBAR_SCROLL,&CMyWindowScrollBar::OnSBarScroll);
        m_Wnd.ShowWindow(SW_SHOW);
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
