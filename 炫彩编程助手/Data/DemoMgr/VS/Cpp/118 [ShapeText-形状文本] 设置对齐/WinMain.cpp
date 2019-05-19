#include "Common.h"

class CMyWindowShape
{
public:
    HWINDOW m_hWindow;
    CMyWindowShape()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 400, 300, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);

        HELE   hEle=XEle_Create(60,60,200,200,m_hWindow);
        HXCGUI hTextBlock=XShapeText_Create(0,0,100,20,L"123456",hEle);
        XShapeText_SetLayoutWidth(hTextBlock,layout_size_type_fixed,200);

		//因为默认布局宽度是自动，所以需要更改布局宽度为指定大小
		//设置对齐才会有用

		XShapeText_SetTextAlign(hTextBlock,DT_CENTER);


        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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

