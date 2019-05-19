#include "Common.h"


class CMyWindowElement
{
public:
	xcgui::XWnd m_Wnd;

    CMyWindowElement(){
        Init();
    }

    void Init()
    {
		HFONTX hFontx = XFont_CreateFromFile(L"Abduction2000.TTF");
		XC_SetDefaultFont(hFontx);
        m_Wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_Wnd),button_type_close);
		

		
		m_Wnd.ShowWindow(SW_SHOW);
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




