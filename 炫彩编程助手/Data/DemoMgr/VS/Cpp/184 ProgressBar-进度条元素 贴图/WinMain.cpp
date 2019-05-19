#include "Common.h"

class CMyWindowProgressBar
{
public:
    HWINDOW m_hWindow;
	
    HELE    m_hProgressBar;
    HELE    m_hButtonAdd;
    HELE    m_hButtonMunus;
    CMyWindowProgressBar()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hProgressBar=XProgBar_Create(20,40,260,20,m_hWindow);
        XProgBar_SetRange(m_hProgressBar,10);
        XProgBar_SetPos(m_hProgressBar,5);
        XProgBar_SetSpaceTwo(m_hProgressBar,0,0);
		
        m_hButtonAdd=XBtn_Create(20,70,50,18,L"+",m_hWindow);
        m_hButtonMunus=XBtn_Create(80,70,50,18,L"-",m_hWindow);
		

		//贴图

		//设置背景
		HBKM hBkM = XEle_GetBkManager(m_hProgressBar);
		XBkM_AddImage(hBkM,element_state_flag_leave,XImage_LoadFile(L"U_DNX_loading_l01.png"));

		//设置进度贴图
		XProgBar_SetImageLoad(m_hProgressBar,XImage_LoadFile(L"U_DNX_loading_l02.png"));

		//如果有的素材 背景是透明的，大家可以设置背景透明
		//用这个函数即可 XEle_EnableBkTransparent(m_hProgressBar,TRUE);
		
        XEle_RegEventCPP1(m_hButtonAdd,XE_BNCLICK,&CMyWindowProgressBar::OnBtnClick);
        XEle_RegEventCPP1(m_hButtonMunus,XE_BNCLICK,&CMyWindowProgressBar::OnBtnClick);
        XEle_RegEventCPP(m_hProgressBar,XE_PROGRESSBAR_CHANGE,&CMyWindowProgressBar::OnProgressBarChange);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int  OnBtnClick(HELE hEventEle, BOOL *pbHandled)
    {
        if(m_hButtonAdd==hEventEle)
        {   
            XProgBar_SetPos(m_hProgressBar,XProgBar_GetPos(m_hProgressBar)+1);
            XEle_RedrawEle(m_hProgressBar);
        }else
        {
            XProgBar_SetPos(m_hProgressBar,XProgBar_GetPos(m_hProgressBar)-1);
            XEle_RedrawEle(m_hProgressBar);
        }
        return 0;
    }
    int OnProgressBarChange(int pos,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowProgressBar  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
