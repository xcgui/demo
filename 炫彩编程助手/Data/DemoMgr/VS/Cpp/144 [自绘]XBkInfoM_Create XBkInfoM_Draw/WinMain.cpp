#include "Common.h"

class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
	HBKM m_BkInfoM;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		
        HELE hEle=XEle_Create(20,50,100,100,m_hWindow);
		XBkM_AddImage(XEle_GetBkManager(hEle),element_state_flag_enable,XImage_LoadFile(L"3.png",TRUE));

		m_BkInfoM = XBkM_Create();
		XBkM_AddImage(m_BkInfoM,element_state_flag_enable,XImage_LoadFile(L"4.png",TRUE));
		
		XEle_EnableEvent_XE_PAINT_END(hEle,TRUE);
		XEle_RegEventCPP(hEle,XE_PAINT_END,&CMyWindowElement::OnDraw);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		RECT rt={20,20,60,60};
		XBkM_Draw(m_BkInfoM,element_state_flag_enable,hDraw,&rt);
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




