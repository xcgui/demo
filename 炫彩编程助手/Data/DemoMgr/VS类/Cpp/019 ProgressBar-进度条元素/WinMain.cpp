#include "Common.h"

class CMyWindowProgressBar
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;

	xcgui::XProgBar m_progbar;
	xcgui::XBtn m_btnAdd;
	xcgui::XBtn m_btnMunus;

    CMyWindowProgressBar()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
        m_progbar.Create(20,40,260,20,m_Wnd);
        m_progbar.SetRange(10);
        m_progbar.SetPos(5);
        m_progbar.SetSpaceTwo(10,10);
		
        m_btnAdd.Create(20,70,50,18,L"+",m_Wnd);
        m_btnMunus.Create(80,70,50,18,L"-",m_Wnd);
		
        XEle_RegEventCPP1(m_btnAdd,XE_BNCLICK,&CMyWindowProgressBar::OnBtnClick);
        XEle_RegEventCPP1(m_btnMunus,XE_BNCLICK,&CMyWindowProgressBar::OnBtnClick);
        XEle_RegEventCPP(m_progbar,XE_PROGRESSBAR_CHANGE,&CMyWindowProgressBar::OnProgressBarChange);
        m_Wnd.ShowWindow(SW_SHOW);
    }
    int  OnBtnClick(HELE hEventEle, BOOL *pbHandled)
    {
        if(m_btnAdd.hEle==hEventEle)
        {   
            m_progbar.SetPos(m_progbar.GetPos()+1);
            m_progbar.RedrawEle();
        }else
        {
            m_progbar.SetPos(m_progbar.GetPos()-1);
            m_progbar.RedrawEle();
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
