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
        m_hWindow = XWnd_Create(0, 0, 100, 320, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        HELE hSliderBar=XSliderBar_Create(20,40,40,225,m_hWindow);
		XSliderBar_SetHorizon(hSliderBar,FALSE);
        XSliderBar_SetRange(hSliderBar,10);
        XSliderBar_SetButtonHeight(hSliderBar,29);
        XSliderBar_SetButtonWidth(hSliderBar,29);
        XSliderBar_SetSpaceTwo(hSliderBar,10,10);


		//ÌùÍ¼´úÂë



		HBKM hBkinfoM = XEle_GetBkManager(hSliderBar);

		XBkM_AddFill(hBkinfoM,element_state_flag_enable,RGB(56,58,66),255);

		HIMAGE hImage1 = XImage_LoadFile(L"volume_slot.png");
		XBkM_AddImage(hBkinfoM,element_state_flag_enable,hImage1);

		HELE hBtnSlider = XSliderBar_GetButton(hSliderBar);
		XEle_EnableDrawFocus(hSliderBar,FALSE);
		XEle_EnableBkTransparent(hBtnSlider,TRUE);
		hBkinfoM = XEle_GetBkManager(hBtnSlider);
		HIMAGE hImageBtn = XImage_LoadFileAdaptive(L"volume_bar.png",1,14,1,14);
		XBkM_AddImage(hBkinfoM,element_state_flag_enable,hImageBtn);

		HIMAGE hImageLoad = XImage_LoadFile(L"load.png");
		XSliderBar_SetImageLoad(hSliderBar,hImageLoad);


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
