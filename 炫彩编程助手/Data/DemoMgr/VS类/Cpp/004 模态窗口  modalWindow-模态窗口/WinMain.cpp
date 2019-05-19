#include "Common.h"


class CWindow_Demo
{
public:
	xcgui::XWnd m_Window;
	
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
		m_Window.Create(0, 0, 300, 200, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Window);
		btn.SetType(button_type_close);
		
		xcgui::XBtn btn1(20,50,120,20,L"popup-modalWindow",m_Window);
        XEle_RegEventCPP(btn1,XE_BNCLICK,&CWindow_Demo::OnBtnClick);

        m_Window.ShowWindow(SW_SHOW);
    }
    int  OnBtnClick(BOOL *pbHandled)
    {
		xcgui::XModalWnd modal(200, 200, L"炫彩界面库窗口",m_Window);

		xcgui::XBtn btn(5, 3, 60, 20, L"Close",modal);
		btn.SetType(button_type_close);

		int nResult=modal.DoModal();

        XTRACE("exit modal %d \n",nResult);
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}





