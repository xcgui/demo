#include "Common.h"

class CMyWindowScrollView
{
public:
    HWINDOW m_hWindow;
    HELE    m_hScrollView;
    CMyWindowScrollView()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 300, L"ìÅ²Ê½çÃæ¿â´°¿Ú", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hScrollView=XSView_Create(20,50,200,200,m_hWindow);
        XSView_SetTotalSize(m_hScrollView,300,300);
        XBtn_Create(10,10,100,20,L"Button1",m_hScrollView);
        XBtn_Create(10,40,100,20,L"Button2",m_hScrollView);
        XBtn_Create(10,70,100,20,L"Button3",m_hScrollView);
		
        XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_H,&CMyWindowScrollView::OnScrollViewScrollH);
        XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_V,&CMyWindowScrollView::OnScrollViewScrollV);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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