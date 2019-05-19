#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	
    BOOL Create() //创建窗口和按钮
    {
        m_Wnd.Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_Wnd)
        {
 			xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
			m_btn.SetType(button_type_close);
		

			xcgui::XBtn sendmsg(100, 5, 60, 20,L"发送",m_Wnd);
			XEle_RegEventCPP(sendmsg,XE_BNCLICK,&CMyWnd::OnEventBtnClick);

			XWnd_RegEventCPP(m_Wnd,WM_USER+1000,&CMyWnd::OnWndOther);
			m_Wnd.ShowWindow(SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
	int OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		MessageBoxW(NULL,L"收到消息",NULL,MB_OK);
		return 0;
	}
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //弹出消息框
        SendMessage(m_Wnd.GetHWND(),WM_USER+1000,0,0);
        *pBool=TRUE; //对该事件进行拦截
        return 0;    //事件的返回值
    }
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




