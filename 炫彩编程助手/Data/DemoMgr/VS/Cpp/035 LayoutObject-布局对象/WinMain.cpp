#include "Common.h"

class CMyWindowLayout
{
public:
    HWINDOW m_hWindow;
    HELE    m_hEle;
    CMyWindowLayout()
    {
        m_hEle=NULL;
        Init();
    }
    void Init()
    {

		XC_ShowLayoutFrame(TRUE);
		XC_SetLayoutFrameColor(RGB(255,0,0));

        m_hWindow = XWnd_Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);

        m_hEle=XEle_Create(20,40,300,100,m_hWindow);
        HXCGUI hLayoutFrame=XLayout_Create();
		XEle_BindLayoutObject(m_hEle,hLayoutFrame);
		XLayout_SetLayoutWidth(hLayoutFrame,layout_size_type_fill,1);
		XLayout_SetLayoutHeight(hLayoutFrame,layout_size_type_fill,1);

        XLayout_SetAlignH(hLayoutFrame,layout_align_right);
        XLayout_SetAlignV(hLayoutFrame,layout_align_top);
        XLayout_SetPadding(hLayoutFrame,10,10,10,10);
        XLayout_SetSpace(hLayoutFrame,2);

        HELE hButton1=XBtn_Create(0,0,60,20,L"111");
        HELE hButton2=XBtn_Create(0,0,60,20,L"222");
        HELE hButton3=XBtn_Create(0,0,60,20,L"333");

        HXCGUI hShapeText=XShapeText_Create(0,0,60,20,L"ShapeText");

        XLayout_AddEle(hLayoutFrame,hButton1);
        XLayout_AddEle(hLayoutFrame,hButton2);
        XLayout_AddEle(hLayoutFrame,hButton3);
        XLayout_AddShape(hLayoutFrame,hShapeText);



		XEle_AdjustLayoutObject(m_hEle);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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
