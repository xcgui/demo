#include "Common.h"


class CWindow_Demo
{
public:
    HWINDOW m_hWindow;
    HELE     m_hButton;
    HWINDOW  m_hWindowModal;
    CWindow_Demo()
    {
        m_hWindowModal=NULL;
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(100,100,400, 300, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hButton=XBtn_Create(20,50,120,20,L"popup-modalWindow",m_hWindow);
        XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CWindow_Demo::OnBtnClick);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int  OnBtnClick(BOOL *pbHandled)
    {
		m_hWindowModal = XModalWnd_CreateEx(0,L"_",L"ìÅ²Ê",0,100,100,200, 200,XWnd_GetHWND(m_hWindow));
    //    m_hWindowModal = XModalWnd_Create(200, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",XWnd_GetHWND(m_hWindow));
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindowModal),button_type_close);
        int nResult=XModalWnd_DoModal(m_hWindowModal);
        XTRACE("exit modal %d \n",nResult);
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
	XC_RegisterWindowClassName(L"_");
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}





