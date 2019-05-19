#include "Common.h"

class CMyWindowShape
{
public:
	xcgui::XWnd m_Wnd;

    CMyWindowShape()
    {
        Init();
    }
    void Init()
    {
        m_Wnd.Create(0, 0, 400, 300, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);


		xcgui::XEle ele(60,60,200,200,m_Wnd);
		xcgui::XShapeText text(0,0,100,20,L"123456",ele);

        text.SetLayoutWidth(layout_size_type_auto,0);
        text.SetLayoutHeight(layout_size_type_auto,0);
    
		m_Wnd.ShowWindow(SW_SHOW);

    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    XC_ShowLayoutFrame(TRUE); //显示布局边框

    CMyWindowShape  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}

