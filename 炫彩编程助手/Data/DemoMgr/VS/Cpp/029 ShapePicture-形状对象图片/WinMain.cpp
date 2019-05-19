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
        m_hWindow = XWnd_Create(0, 0, 400, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);

        HXCGUI hPicture=XShapePic_Create(20,50,100,100,m_hWindow);
        XShapePic_SetImage(hPicture,XImage_LoadFile(L"image.png"));

        XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    XC_ShowLayoutFrame(TRUE);

    CMyWindowShape  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
