#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	
    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {
            m_hButton =XBtn_Create(10,10,80,25,L"按钮",m_hWindow); //创建按钮
            XEle_RegEventCPP(m_hButton,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
			

			HBKM hBkM = XWnd_GetBkManager(m_hWindow);
			//如果你要贴图，请使用XBkM_AddImage
			XBkM_AddFill(hBkM,window_state_flag_left_leave,RGB(128,0,0),255);
			XBkM_AddFill(hBkM,window_state_flag_top_leave,RGB(0,128,0),255);
			XBkM_AddFill(hBkM,window_state_flag_right_leave,RGB(0,0,128),255);
			XBkM_AddFill(hBkM,window_state_flag_bottom_leave,RGB(128,128,128),255);
			XBkM_AddFill(hBkM,window_state_flag_body_leave,RGB(128,128,0),255);
				

			
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //弹出消息框
        MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
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




