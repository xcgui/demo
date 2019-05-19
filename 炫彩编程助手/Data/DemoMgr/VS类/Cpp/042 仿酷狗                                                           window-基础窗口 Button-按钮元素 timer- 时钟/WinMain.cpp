#include "Common.h"



class CMyWnd
{
public:	
	xcgui::XWnd m_Wnd;
	xcgui::XEle m_btn_left;
	xcgui::XEle m_btn_top;
	xcgui::XEle m_btn_right;
	xcgui::XEle m_btn_bottom;
	xcgui::XEle m_btn_mid;

    BOOL Create() //创建窗口和按钮
    {
		if (m_Wnd.CreateFromLayout(L".\\kugou\\resource.xml",L".\\kugou",L".\\kugou\\layout.xml"))
		{
			xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
			btn.SetType(button_type_close);

			m_btn_mid.CreateFromLayoutID(1);
			m_btn_left.CreateFromLayoutID(2);
			m_btn_top.CreateFromLayoutID(3);
			m_btn_right.CreateFromLayoutID(4);
			m_btn_bottom.CreateFromLayoutID(5);

			
			XEle_RegEventCPP(m_btn_mid,XE_MOUSESTAY,&CMyWnd::OnMouseStay);
			XEle_RegEventCPP(m_btn_mid,XE_MOUSELEAVE,&CMyWnd::OnMouseLeave);
			
			XWnd_RegEventCPP(m_Wnd,WM_TIMER,&CMyWnd::OnShowBtnTimer);
			m_Wnd.ShowWindow(SW_SHOW);
			return TRUE;
		}
        return FALSE;
    }
	int OnShowBtnTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		switch (nIDEvent)
		{
		case 10:
			{
				switch (m_showIndex)
				{
				case 0:
					m_btn_left.ShowEle(TRUE);
					break;
				case 1:
					m_btn_top.ShowEle(TRUE);
					break;
				case 2:
					m_btn_right.ShowEle(TRUE);
					break;
				case 3:
					m_btn_bottom.ShowEle(TRUE);
					m_Wnd.KillTimer(10);
					break;
				}
				m_Wnd.RedrawWnd();
				m_showIndex++;
			}
			break;
		case 11:
			{
				switch (m_hideIndex)
				{
				case 0:
					m_btn_left.ShowEle(FALSE);
					break;
				case 1:
					m_btn_top.ShowEle(FALSE);
					break;
				case 2:
					m_btn_right.ShowEle(FALSE);
					break;
				case 3:
					m_btn_bottom.ShowEle(FALSE);
					m_Wnd.KillTimer(11);
					break;
				}
				m_Wnd.RedrawWnd();
				m_hideIndex++;
			}
			break;
		}
		return 0;
	}
	int OnMouseStay(BOOL *pbHandled)
	{
		m_showIndex = 0;
		m_Wnd.SetTimer(10,150);
		return 0;
	}
	int OnMouseLeave(HELE hEleStay,BOOL *pbHandled)
	{
		m_Wnd.KillTimer(10);
		m_hideIndex = 0;
		m_Wnd.SetTimer(11,10);
		return 0;
	}
	int m_showIndex;
	int m_hideIndex;
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




