#include "Common.h"


class CMyWindowCheck
{
public:
    HWINDOW m_hWindow;
    HELE    m_hCheck1;
    HELE    m_hCheck2;
    HELE    m_hCheck3;
    CMyWindowCheck()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hCheck1 = XBtn_Create(20, 40, 100, 20, L"Radio1", m_hWindow);
        m_hCheck2 = XBtn_Create(20, 70, 100, 20, L"Radio2", m_hWindow);
        m_hCheck3 = XBtn_Create(20, 100, 100, 20, L"Radio3", m_hWindow);
        XBtn_SetGroupID(m_hCheck1,1);
        XBtn_SetGroupID(m_hCheck2,1);
        XBtn_SetGroupID(m_hCheck3,1);

		//这个XBtn_SetType 是设置按钮的种类为 radio 类型
		//当然大家也可以设置为close类型等
        XBtn_SetType(m_hCheck1, button_type_radio);
        XBtn_SetType(m_hCheck2, button_type_radio);
        XBtn_SetType(m_hCheck3, button_type_radio);

		//这个XBtn_SetStyle 是设置按钮的外观，可以为Radio 或者check 或者是普通样式
		XBtn_SetStyle(m_hCheck1,button_style_radio);
		XBtn_SetStyle(m_hCheck2,button_style_radio);
		XBtn_SetStyle(m_hCheck3,button_style_radio);



        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowCheck  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}




