#include "Common.h"

class CMyWindowSliderBar
{
public:
    HWINDOW m_hWindow;
	
    CMyWindowSliderBar()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        HELE hSliderBar=XSliderBar_Create(20,40,260,60,m_hWindow);
        XSliderBar_SetRange(hSliderBar,10);
        XSliderBar_SetButtonHeight(hSliderBar,27);
        XSliderBar_SetButtonWidth(hSliderBar,27);
        XSliderBar_SetSpaceTwo(hSliderBar,10,10);
        XEle_RegEventCPP(hSliderBar,XE_SLIDERBAR_CHANGE,&CMyWindowSliderBar::OnSliderBarChange);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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
