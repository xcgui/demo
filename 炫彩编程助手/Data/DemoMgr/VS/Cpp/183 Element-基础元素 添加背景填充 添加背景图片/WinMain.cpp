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
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		
        HELE hEle=XEle_Create(20,50,100,100,m_hWindow);

		HBKM hBkM = XEle_GetBkManager(hEle);
		XBkM_AddFill(hBkM,element_state_flag_leave,RGB(0,128,0),255);
		//如果你想用一个图片来填充背景，那么请用下面这个函数
		//XBkM_AddImage(hBkM,element_state_flag_leave,)
		

		//这里随便说一下element_state_flag_leave 这个是组合状态，具体可以
		//查阅帮助文档的组合状态

		//组合状态都有一个明显的特征就是  _state_flag_ 切忌！

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




