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

			HELE hTabbar = XTabBar_Create(8,30,384,40,m_hWindow);

			XTabBar_EnableClose(hTabbar,TRUE);

			XTabBar_AddLabel(hTabbar,L"按钮1");
			XTabBar_AddLabel(hTabbar,L"按钮2");

			
			//XTabBar_EnableTile(hTabbar,TRUE);

			SIZE sz={20,20};
			XTabBar_SetCloseSize(hTabbar,&sz);
			
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
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




