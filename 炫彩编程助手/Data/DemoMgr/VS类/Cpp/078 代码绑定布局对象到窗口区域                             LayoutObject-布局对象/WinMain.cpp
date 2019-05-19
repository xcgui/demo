#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	
    BOOL Create() //创建窗口和按钮
    {
		//有的时候需要查看一下布局是否正确，可以设置布局的颜色，然后显示
		//因为布局主要作用是用来规划元素的坐标位置，一般是不用显示的
		//下面这两句代码，可以放在窗口创建之前
		XC_SetLayoutFrameColor(RGB(255,0,0));
		XC_ShowLayoutFrame(TRUE);

        m_Wnd.Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_Wnd)
        {
			xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
			m_btn.SetType(button_type_close);			

			//创建布局，然后绑定布局到窗口顶部区域
			xcgui::XLayout layoutBody;
			m_Wnd.BindLayoutObject(window_position_body,layoutBody);

			//第二个参数 设置布局大小为填充父，第三个参数此时没意义
			//第三个参数只有在 第二个参数为 layout_size_type_fixed layout_size_type_weight
			//时有意义
			layoutBody.SetLayoutHeight(layout_size_type_fill,1);
			layoutBody.SetLayoutWidth(layout_size_type_fill,1);

			//调整布局
			m_Wnd.AdjustLayout();
            m_Wnd.ShowWindow(SW_SHOW); //显示窗口

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




