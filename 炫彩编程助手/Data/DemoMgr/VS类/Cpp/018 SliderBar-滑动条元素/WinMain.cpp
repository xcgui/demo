#include "Common.h"

class CMyWindowSliderBar
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;
	
    CMyWindowSliderBar()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
		xcgui::XSliderBar sliderBar;
        sliderBar.Create(20,40,260,60,m_Wnd);
        sliderBar.SetRange(10);
        sliderBar.SetButtonHeight(27);
        sliderBar.SetButtonWidth(27);
        sliderBar.SetSpaceTwo(10,10);
        XEle_RegEventCPP(sliderBar,XE_SLIDERBAR_CHANGE,&CMyWindowSliderBar::OnSliderBarChange);
        m_Wnd.ShowWindow(SW_SHOW);
    }
    int OnSliderBarChange(int pos,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowSliderBar  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
