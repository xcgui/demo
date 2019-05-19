#include "Common.h"



class CMyWnd
{
public:
    HWINDOW hWindow; //窗口句柄
    HELE    m_hButton; //按钮句柄
	
    BOOL Create() //创建窗口和按钮
    {
			hWindow=XWnd_Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
			if(hWindow)
			{
			HXCGUI hShapePic  =XShapePic_Create(0,0,24,24,hWindow);
			HXCGUI hShapeText =XShapeText_Create(0,0,100,20,L"标准系统栏窗口");
			HELE   hBtnMin    =XBtn_Create(20,60,65,20,L"最小化",hWindow);
			HELE   hBtnMax    =XBtn_Create(20,60,90,20,L"最大化/还原",hWindow);//创建按钮
			HELE   hBtnClose  =XBtn_Create(20,60,60,20,L"关闭",hWindow);
			
			XShapePic_SetImage(hShapePic,XImage_LoadFile(L"Logo.png")); //显示logo图标
			XBtn_SetType(hBtnMin,button_type_min);
			XBtn_SetType(hBtnMax,button_type_max);
			XBtn_SetType(hBtnClose,button_type_close);
			XEle_RegEventCPP(hBtnClose,XE_BNCLICK,&CMyWnd::OnEventBtnClick);//注册按钮点击事件
			
			HXCGUI  hLayout =XLayout_Create(); //创建布局对象
			XWnd_BindLayoutObject(hWindow,window_position_top,hLayout);
			XLayout_SetLayoutWidth(hLayout,layout_size_type_fill,0);
			XLayout_SetLayoutHeight(hLayout,layout_size_type_fill,0);
			XLayout_SetAlignV(hLayout,layout_align_center);
			XLayout_SetPadding(hLayout,8,0,8,0);
			{
				//添加到布局中,显示到左侧
				XLayout_AddShape(hLayout,hShapePic);
				XLayout_AddShape(hLayout,hShapeText);
			}
			{
				//创建右侧布局对象
				HXCGUI  hLayoutRight =XLayout_Create(); 
				XLayout_AddLayoutObject(hLayout,hLayoutRight);
				XLayout_SetLayoutWidth(hLayoutRight,layout_size_type_weight,1);
				XLayout_SetLayoutHeight(hLayoutRight,layout_size_type_fill,0);
				XLayout_SetAlignV(hLayoutRight,layout_align_center);
				XLayout_SetAlignH(hLayoutRight,layout_align_right);
        
				XLayout_AddEle(hLayoutRight,hBtnMin);  //添加到布局中
				XLayout_AddEle(hLayoutRight,hBtnMax);
				XLayout_AddEle(hLayoutRight,hBtnClose);
			}
		
        
			XWnd_AdjustLayout(hWindow); //调整布局
			XWnd_ShowWindow(hWindow,SW_SHOW);

            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
    //弹出消息框
		::MessageBoxW(XWnd_GetHWND(hWindow),L"你点击了关闭按钮,即将关闭窗口",L"提示",MB_OK);
    //*pbHandled=TRUE; //对该事件进行拦截,如果不需要拦截可以去掉该行代码
    return 0;    //事件的返回值

    }
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
	XC_ShowLayoutFrame(TRUE);  //显示布局边界,调试用的
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




