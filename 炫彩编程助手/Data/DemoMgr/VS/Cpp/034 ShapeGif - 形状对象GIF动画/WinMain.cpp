#include "Common.h"

class CMyWindowGif
{
public:
    HWINDOW m_hWindow;
    HELE    m_hButton;
    HXCGUI  m_hGif1;
    HXCGUI  m_hGif2;
    CMyWindowGif(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 350, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
    
        m_hGif1=XShapeGif_Create(20,50,100,100,m_hWindow);
        XShapeGif_SetImage(m_hGif1,XImage_LoadFile(L"image\\gif.gif"));

        m_hGif2=XShapeGif_Create(150,50,100,100,m_hWindow);
        XShapeGif_SetImage(m_hGif2,XImage_LoadFile(L"image\\gif.gif"));

        m_hButton = XBtn_Create(260, 50, 60, 20,L"销毁", m_hWindow);
        XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWindowGif::OnBtnClick);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnBtnClick(BOOL *pbHandled)
    {
        if(m_hGif1){ XShape_Destroy(m_hGif1); m_hGif1=NULL; }
        if(m_hGif2){ XShape_Destroy(m_hGif2); m_hGif2=NULL; }
        XWnd_RedrawWnd(m_hWindow);
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    XC_ShowLayoutFrame(TRUE);
	
    CMyWindowGif  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
