#include "Common.h"

class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
	HELE m_hEle;
    CMyWindowElement(){
        Init();
    }
	int OnBtnClick(BOOL *pbHandled)
	{
		// 这个500 是自己定义的
		XEle_PostEvent(m_hEle,m_hEle,500,1,2);
		return 0;
	}
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		
		HELE hBtn = XBtn_Create(8,30,150,20,L"发送自定义消息",m_hWindow);

		XEle_RegEventCPP(hBtn,XE_BNCLICK,&CMyWindowElement::OnBtnClick);

        m_hEle = XEle_Create(20,50,100,100,m_hWindow);
		XEle_RegEventCPP(m_hEle,XE_ELEPROCE,&CMyWindowElement::OnEventProc);
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnEventProc(UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{
		if (nEvent == 500)
		{
			MessageBoxW(NULL,L"收到用户自定义消息",L"提示",MB_OK);
		}
		return 0;
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




