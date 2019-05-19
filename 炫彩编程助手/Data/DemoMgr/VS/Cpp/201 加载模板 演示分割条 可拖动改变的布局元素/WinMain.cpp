#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	
    BOOL Create() //创建窗口和按钮
    {
		XC_LoadResource(L"拖动布局\\资源文件\\resource.res",L"拖动布局");
		m_hWindow=(HWINDOW)XC_LoadLayout(L"拖动布局\\布局文件\\layout.xml");
 //       m_hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {


			HELE m_hEleLeft = (HELE)XC_GetObjectByID(m_hWindow,10);
			HELE m_hEleRight = (HELE)XC_GetObjectByID(m_hWindow,11);
			XEle_SetBorderSize(m_hEleLeft, 5, 5, 5, 5);
			XEle_SetBorderSize(m_hEleRight, 5, 5, 5, 5);
			
			XEle_SetDragBorder(m_hEleRight, element_position_left | element_position_top | element_position_bottom | element_position_right);
			XEle_SetDragBorderBindEle(m_hEleRight, element_position_left, m_hEleLeft, 5);

			XWnd_AdjustLayout(m_hWindow);
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
	XC_ShowLayoutFrame(TRUE);
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




