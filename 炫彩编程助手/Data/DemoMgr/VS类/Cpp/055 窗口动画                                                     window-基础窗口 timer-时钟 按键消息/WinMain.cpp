#include "Common.h"




enum position_
{
	position_left,
	position_top,
	position_right,
	position_bottom,
};
enum direction_
{
	direction_left,   //顺时针
	direction_right,  //逆时针
};

class MainWindow
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XEle m_Ele;
	xcgui::XBtn install;
	xcgui::XEle m_SmallBall;
	void Init()
	{
		m_Wnd.CreateFromLayout(L".\\8\\99.xml");
		m_Ele.CreateFromLayoutID(12);



		install.CreateFromLayoutID(11);
		XEle_RegEventCPP(install,XE_BNCLICK,&MainWindow::OnBtnClick);

		m_SmallBall.CreateFromLayoutID(10);

		XWnd_RegEventCPP(m_Wnd,WM_KEYDOWN,&MainWindow::OnWndKeyDown);
		XWnd_RegEventCPP(m_Wnd,WM_TIMER,&MainWindow::OnWndTimer);
		srand(GetTickCount());
		m_Wnd.ShowWindow(SW_SHOW);//显示窗口
	}

	int OnBtnClick(BOOL *pbHandled)
	{
		//m_direction = (direction_)(rand()%1);
		m_direction = direction_right;
		m_position = position_bottom;
		m_Wnd.SetTimer(100,10);
		install.ShowEle(FALSE);
		return 0;
	}
	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		RECT rtBall;
		m_SmallBall.GetRect(&rtBall);

		int nSpeed = 1;

		switch (m_position)
		{
		case position_left:
			{
				if (m_direction == direction_left)
				{
					if (rtBall.top > 20)
					{
						rtBall.left +=nSpeed;
						rtBall.right +=nSpeed;
						rtBall.top -=nSpeed;
						rtBall.bottom-=nSpeed;
					}else
					{
						m_position = position_top;
					}
					
				}else
				{
					if (rtBall.bottom < 420)
					{
						rtBall.left+=nSpeed;
						rtBall.right+=nSpeed;
						rtBall.top +=nSpeed;
						rtBall.bottom+=nSpeed;
					}else
					{
						m_position = position_bottom;
					}
				}
			}
			break;
		case position_top:
			{
				if (m_direction == direction_left)
				{
					if (rtBall.right < 500)
					{
						rtBall.left +=nSpeed;
						rtBall.right +=nSpeed;
						rtBall.top +=nSpeed;
						rtBall.bottom+=nSpeed;
					}else
					{
						m_position = position_right;
					}
					
				}else
				{
					if (rtBall.left > 0)
					{
						rtBall.left-=nSpeed;
						rtBall.right-=nSpeed;
						rtBall.top +=nSpeed;
						rtBall.bottom+=nSpeed;
					}else
					{
						m_position = position_left;
					}
				}
			}
			break;
		case position_right:
			{
				if (m_direction == direction_left)
				{
					if (rtBall.bottom < 420)
					{
						rtBall.left -=nSpeed;
						rtBall.right -=nSpeed;
						rtBall.top +=nSpeed;
						rtBall.bottom+=nSpeed;
					}else
					{
						m_position = position_bottom;
					}
					
				}else
				{
					if (rtBall.top > 20)
					{
						rtBall.left-=nSpeed;
						rtBall.right-=nSpeed;
						rtBall.top -=nSpeed;
						rtBall.bottom-=nSpeed;
					}else
					{
						m_position = position_top;
					}
				}
			}
			break;
		case position_bottom:
			{
				if (m_direction == direction_left)
				{
					if (rtBall.left > 0)
					{
						rtBall.left-=nSpeed;
						rtBall.right-=nSpeed;
						rtBall.top -=nSpeed;
						rtBall.bottom-=nSpeed;
					}else
					{
						m_position = position_left;
					}
					
				}else
				{
					if (rtBall.right < 500)
					{
						rtBall.left+=nSpeed;
						rtBall.right+=nSpeed;
						rtBall.top -=nSpeed;
						rtBall.bottom-=nSpeed;
					}else
					{
						m_position = position_right;
					}
				}
			}
			break;
		}
		m_SmallBall.SetRect(&rtBall);
		m_Wnd.RedrawWnd(TRUE);
		return 0;
	}
	
	int OnWndKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		switch (wParam)
		{
		case VK_LEFT:
			{
				RECT rt;
				m_Ele.GetRect(&rt);
				if (rt.left > 0)
				{
					rt.left-=10;
					rt.right-=10;
				}
				m_Ele.SetRect(&rt);
				m_Wnd.RedrawWnd();
			}
			break;
		case VK_RIGHT:
			{
				RECT rt;
				m_Ele.GetRect(&rt);
				if (rt.right < 500)
				{
					rt.left+=10;
					rt.right+=10;
				}
				m_Ele.SetRect(&rt);
				m_Wnd.RedrawWnd();
			}
			break;
		}
		return 0;
	}
private:
	direction_  m_direction;
	position_ m_position;
};


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    
	MainWindow mainWindow;
	mainWindow.Init();

    XRunXCGUI(); //运行
    XExitXCGUI(); //释放资源
    return 0;
}


