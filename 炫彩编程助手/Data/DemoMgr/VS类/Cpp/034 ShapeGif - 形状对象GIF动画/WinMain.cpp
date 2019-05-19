#include "Common.h"

class CMyWindowGif
{
public:
	xcgui::XWnd m_wnd;
	xcgui::XShapeGif m_gif1;
	xcgui::XShapeGif m_gif2;

    CMyWindowGif(){
        Init();
    }
    void Init()
    {
        m_wnd.Create(0, 0, 350, 200, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_wnd);
		btn.SetType(button_type_close);

		
        m_gif1.Create(20,50,100,100,m_wnd);
        m_gif1.SetImage(XImage_LoadFile(L"image\\gif.gif"));
		
        m_gif2.Create(150,50,100,100,m_wnd);
        m_gif2.SetImage(XImage_LoadFile(L"image\\gif.gif"));
		
		xcgui::XBtn btnDestroy(260, 50, 60, 20,L"销毁",m_wnd);
        XEle_RegEventCPP(btnDestroy,XE_BNCLICK,&CMyWindowGif::OnBtnClick);
        m_wnd.ShowWindow(SW_SHOW);
    }
    int OnBtnClick(BOOL *pbHandled)
    {
        if(m_gif1)
			m_gif1.Destroy();
        if(m_gif2)
			m_gif2.Destroy();
        m_wnd.RedrawWnd();
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    XC_ShowLayoutFrame(TRUE);
	
    CMyWindowGif  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
