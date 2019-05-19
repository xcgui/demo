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
	void Init()
	{
		m_hWindow =(HWINDOW) XC_LoadLayout(L".\\8\\99.xml",NULL);

		m_hEle = (HELE)XC_GetObjectByID(12);

		m_hBtnInstall = (HELE)XC_GetObjectByID(11);
		XEle_RegEventCPP(m_hBtnInstall,XE_BNCLICK,&MainWindow::OnBtnClick);


		m_hSmallBall = (HELE)XC_GetObjectByID(10);

		XWnd_RegEventCPP(m_hWindow,WM_KEYDOWN,&MainWindow::OnWndKeyDown);
		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&MainWindow::OnWndTimer);
		srand(GetTickCount());
		XWnd_ShowWindow(m_hWindow,SW_SHOW);//显示窗口
	}

	int OnBtnClick(BOOL *pbHandled)
	{
		//m_direction = (direction_)(rand()%1);
		m_direction = direction_right;
		m_position = position_bottom;
		XWnd_SetTimer(m_hWindow,100,10);
		XEle_ShowEle(m_hBtnInstall,FALSE);
		return 0;
	}
	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		RECT rtBall;
		XEle_GetRect(m_hSmallBall,&rtBall);

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
		XEle_SetRect(m_hSmallBall,&rtBall);
		XWnd_RedrawWnd(m_hWindow);
		return 0;
	}

	int OnWndKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		switch (wParam)
		{
		case VK_LEFT:
			{
				RECT rt;
				XEle_GetRect(m_hEle,&rt);
				if (rt.left > 0)
				{
					rt.left-=10;
					rt.right-=10;
				}
				XEle_SetRect(m_hEle,&rt);
				XWnd_RedrawWnd(m_hWindow);
			}
			break;
		case VK_RIGHT:
			{
				RECT rt;
				XEle_GetRect(m_hEle,&rt);
				if (rt.right < 500)
				{
					rt.left+=10;
					rt.right+=10;
				}
				XEle_SetRect(m_hEle,&rt);
				XWnd_RedrawWnd(m_hWindow);
			}
			break;
		}
		return 0;
	}
private:
	HWINDOW m_hWindow;
	HELE m_hEle;
	HELE m_hBtnInstall;
	HELE m_hSmallBall;

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


