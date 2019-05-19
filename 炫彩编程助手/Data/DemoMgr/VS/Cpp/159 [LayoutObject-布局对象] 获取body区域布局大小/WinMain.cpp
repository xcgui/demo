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
            m_hButton =XBtn_Create(10,10,80,25,L"关闭",m_hWindow); //创建按钮
			XBtn_SetType(m_hButton,button_type_close);

			//创建布局，然后绑定布局到窗口顶部区域
			HXCGUI hLayoutBody = XLayout_Create();
			XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);

			//第二个参数 设置布局大小为填充父，第三个参数此时没意义
			//第三个参数只有在 第二个参数为 layout_size_type_fixed layout_size_type_weight
			//时有意义
			XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
			XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);



			XWnd_RegEventCPP(m_hWindow,WM_SIZE,&CMyWnd::OnWndSize);


			//调整布局
			XWnd_AdjustLayout(m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
	int OnWndSize(UINT nFlags,SIZE *pSize,BOOL *pbHandled)
	{
		HXCGUI hLayout = XWnd_GetLayoutObject(m_hWindow,window_position_body);

		SIZE sz;
		// 这个的用法可以搜 XLayout_GetContentSize 找到
		XLayout_GetContentSize(hLayout,&sz);


		//得到的是 		XLayout_SetLayoutWidth() 楼主自己设置的
		layout_size_type_  tp;
		int nOutWidth;
		XLayout_GetLayoutWidth(hLayout,&tp,&nOutWidth);


		//得到真实宽度和高度
		xtrace("%d %d\r\n",XLayout_GetWidth(hLayout),XLayout_GetHeight(hLayout));
		return 0;
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化

	//有的时候需要查看一下布局是否正确，可以设置布局的颜色，然后显示
	//因为布局主要作用是用来规划元素的坐标位置，一般是不用显示的
	//下面这两句代码，可以放在窗口创建之前
	XC_SetLayoutFrameColor(RGB(255,0,0));
	XC_ShowLayoutFrame(TRUE);

    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




