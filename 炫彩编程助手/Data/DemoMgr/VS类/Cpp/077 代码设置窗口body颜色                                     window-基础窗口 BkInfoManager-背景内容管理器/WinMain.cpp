#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	
    BOOL Create() //创建窗口和按钮
    {
		m_Wnd.Create(0,0,400,300,L"炫彩界面库-窗口");
        if(m_Wnd)
        {
			xcgui::XBtn btnClose(10, 5, 60, 20,L"close",m_Wnd);
			btnClose.SetType(button_type_close);

			xcgui::XBtn btn(100,5,80,25,L"按钮",m_Wnd);
            XEle_RegEventCPP(btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			

			//首先，获取背景管理器的句柄，然后通过背景管理器来添加填充颜色
			//当然你可以可以添加背景贴图，可以添加其他的
			//如果要设置上面，左边，右边，下面蓝色区域的颜色，可以用这个window_state_ 
			//开头的，来设置
			m_Wnd.GetBkManager().AddFill(window_state_body_leave,RGB(128,15,50),255);
            m_Wnd.ShowWindow(SW_SHOW); //显示窗口

            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //弹出消息框
        MessageBoxW(m_Wnd.GetHWND(),L"你点击了按钮",L"提示",MB_OK);
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




