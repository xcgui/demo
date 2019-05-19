#include "Common.h"



class CMyWnd
{
public:

	xcgui::XWnd m_Wnd;
	
    BOOL Create() //创建窗口和按钮
    {
		m_Wnd.CreateFromLayout(L"界面模板\\resource.xml",L"界面模板",L"界面模板\\layout.xml");

        if(m_Wnd)
        {
			xcgui::XBtn btnClose(10, 5, 60, 20,L"close",m_Wnd);
			btnClose.SetType(button_type_close);

			xcgui::XBtn btn;
			btn.CreateFromLayoutID(m_Wnd,10); //对应模板里面 ID = 10;
            XEle_RegEventCPP(btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			
			m_Wnd.AdjustLayout();
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




