#include "Common.h"

class CMyWindowScrollView
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;
	xcgui::XSView m_sview;

    CMyWindowScrollView()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
        m_sview.Create(20,50,200,200,m_Wnd);
        m_sview.SetTotalSize(300,300);

		xcgui::XBtn btn1,btn2,btn3;

        btn1.Create(10,10,100,20,L"Button1",m_sview);
        btn2.Create(10,40,100,20,L"Button2",m_sview);
        btn3.Create(10,70,100,20,L"Button3",m_sview);
		
        XEle_RegEventCPP(m_sview,XE_SCROLLVIEW_SCROLL_H,&CMyWindowScrollView::OnScrollViewScrollH);
        XEle_RegEventCPP(m_sview,XE_SCROLLVIEW_SCROLL_V,&CMyWindowScrollView::OnScrollViewScrollV);
        m_Wnd.ShowWindow(SW_SHOW);
    }
    int  OnScrollViewScrollH(int pos,BOOL *pbHandled)
    {
        XTRACE("XE_SCROLLVIEW_SCROLL_H %d \n",pos);
        return 0;
    }
    int  OnScrollViewScrollV(int pos,BOOL *pbHandled)
    {
        XTRACE("XE_SCROLLVIEW_SCROLL_V %d \n",pos);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowScrollView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}