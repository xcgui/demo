#include "Common.h"



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	
    BOOL Create() //创建窗口和按钮
    {
        m_hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
		if (!m_hWindow)
			return FALSE;

		HELE hBtn1 = XBtn_Create(5,5,100,20,L"第1页",m_hWindow);
		HELE hBtn2 = XBtn_Create(105,5,100,20,L"第2页",m_hWindow);

		HELE hPage1 = XEle_Create(8,30,100,100,m_hWindow);
		HELE hPage2 = XEle_Create(8,30,100,100,m_hWindow);

		XBtn_SetType(hBtn1,button_type_radio);
		XBtn_SetType(hBtn2,button_type_radio);

		XBtn_SetBindEle(hBtn1,hPage1);
		XBtn_SetBindEle(hBtn2,hPage2);

		XBtn_SetGroupID(hBtn1,10);
		XBtn_SetGroupID(hBtn2,10);

		XEle_ShowEle(hPage1,TRUE);
		XEle_ShowEle(hPage2,FALSE);

		XBtn_SetCheck(hBtn1,TRUE);
		XBtn_SetCheck(hBtn2,FALSE);

		//为了区分第一页和第二页，我分别创建一个 形状文本
		
		XShapeText_Create(0,10,100,20,L"第1页",hPage1);
		XShapeText_Create(0,10,100,20,L"第2页",hPage2);


        XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
        return TRUE;
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




