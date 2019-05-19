#include "Common.h"


class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
    CMyWindowElement(){
        Init();
    }

    void Init()
    {
		HFONTX hFontx = XFont_CreateFromFile(L"Abduction2000.TTF");
		XC_SetDefaultFont(hFontx);
        m_hWindow = XWnd_Create(0, 0, 400, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 100, 20,L"close",m_hWindow),button_type_close);
		

		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowElement  MyWindowt;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




