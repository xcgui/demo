#include "Common.h"

class CMyWindowLayout
{
public:
    xcgui::XWnd m_Wnd;
    CMyWindowLayout()
    {
        Init();
    }
    void Init()
    {

		XC_ShowLayoutFrame(TRUE);
		XC_SetLayoutFrameColor(RGB(255,0,0));

        m_Wnd.Create(0, 0, 400, 300, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
		btn.SetType(button_type_close);

		xcgui::XEle ele(20,40,300,100,m_Wnd);
		xcgui::XLayout layout(layout_size_type_fill,1,layout_size_type_fill,1);
		ele.BindLayoutObject(layout);

		layout.SetAlignH(layout_align_right);
		layout.SetAlignV(layout_align_top);
		layout.SetPadding(10,10,10,10);
		layout.SetSpace(2);


		xcgui::XBtn btn1(0,0,60,20,L"111");
		xcgui::XBtn btn2(0,0,60,20,L"222");
		xcgui::XBtn btn3(0,0,60,20,L"333");
		xcgui::XShapeText text(0,0,60,20,L"ShapeText");

		layout.AddEle(btn1);
		layout.AddEle(btn2);
		layout.AddEle(btn3);
		layout.AddShape(text);

		XEle_AdjustLayoutObject(ele);
        m_Wnd.ShowWindow(SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    XC_ShowLayoutFrame(TRUE);
    CMyWindowLayout  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
