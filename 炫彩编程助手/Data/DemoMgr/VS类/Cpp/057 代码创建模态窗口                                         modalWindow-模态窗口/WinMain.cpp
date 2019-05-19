#include "Common.h"



class CMyWnd
{
public:
    xcgui::XWnd m_Wnd;
	
    BOOL Create() //创建窗口和按钮
    {
		m_Wnd.Create(0, 0, 350, 400, L"炫彩界面库窗口");

        if(m_Wnd)
        {
			xcgui::XBtn btn(10, 5, 60, 20,L"close",m_Wnd);
			btn.SetType(button_type_close);

			xcgui::XBtn btnPopup(10,35,80,25,L"弹出模态窗口",m_Wnd);
            XEle_RegEventCPP(btnPopup,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			
            m_Wnd.ShowWindow(SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //弹出消息框
		xcgui::XModalWnd modalWnd(200,200,L"测试",m_Wnd.GetHWND());

		xcgui::XBtn btn(10, 5, 60, 20,L"close",modalWnd);
		btn.SetType(button_type_close);

		modalWnd.DoModal();
        
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




