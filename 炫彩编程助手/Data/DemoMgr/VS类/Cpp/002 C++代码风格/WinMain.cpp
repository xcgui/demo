#include "Common.h"


class CMyWnd
{
public:
	xcgui::XWnd    m_wnd;
    BOOL Create() //创建窗口和按钮
    {
		if (m_wnd.Create(0,0,300,200,L"炫彩界面库-窗口"))
		{
			xcgui::XBtn m_btn(10,10,80,25,L"按钮",m_wnd);
            XEle_RegEventCPP(m_btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件			
			m_wnd.ShowWindow(SW_SHOW);
			return TRUE;
		}
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //弹出消息框
        MessageBoxW(m_wnd.GetHWND(),L"你点击了按钮",L"提示",MB_OK);
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




