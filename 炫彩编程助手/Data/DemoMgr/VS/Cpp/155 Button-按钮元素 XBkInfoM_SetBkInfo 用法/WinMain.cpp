#include "Common.h"


class CMyWindowButton
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton_close;
    HELE    m_hButton;
    CMyWindowButton(){
        Init();
    }
    void Init()
    {
		XC_LoadResource(L"bk\\resource.xml",L"bk");
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
		m_hButton_close = XBtn_Create(5, 3, 30, 27, L"", m_hWindow);
        XBtn_SetType(m_hButton_close,button_type_close);


		XEle_EnableBkTransparent(m_hButton_close,TRUE);
		XEle_EnableDrawFocus(m_hButton_close,FALSE);

		HBKM hBkInfoM = XEle_GetBkManager(m_hButton_close);

		//XBkM_SetBkInfo 第二个参数是一个字符串，这个字符串哪里来的？
		//这个字符串其实是设计器里面设计好，生成的。
		XBkM_SetBkInfo(hBkInfoM,L"{3:1(16)2(15)3(0,0,0,0)4(@close_01.png)8(0.00);3:1(32)2(15)3(0,0,0,0)4(@close_02.png)8(0.00);3:1(64)2(15)3(0,0,0,0)4(@close_03.png)8(0.00);3:1(2)2(15)3(0,0,0,0)4(@close_04.png)8(0.00);}");


        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowButton  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




