#include "Common.h"



class CWindow_Demo
{
public:
    HWINDOW m_hWindow;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);

		
		HELE hEle = XEle_Create(0,30,200,160,m_hWindow);
		HXCGUI hLayout = XLayout_Create();
		XEle_BindLayoutObject(hEle,hLayout);
		
		

		HELE hSbar = XSBar_Create(0,0,30,100,hEle);
		XEle_SetLayoutHeight(hSbar,layout_size_type_fill,1);
		XSBar_SetHorizon(hSbar,FALSE);

		XLayout_AddEle(hLayout,hSbar);

		XLayout_AdjustLayout(hLayout);

        XWnd_RegEventCPP(m_hWindow,WM_DESTROY,&CWindow_Demo::OnDestroy);
		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnDestroy(BOOL* pbHandled)
    {
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





