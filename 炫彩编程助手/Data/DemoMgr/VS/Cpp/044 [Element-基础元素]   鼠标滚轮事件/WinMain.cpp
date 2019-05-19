#include "Common.h"



HWINDOW  hWindow=NULL;
//事件响应

int CALLBACK OnMouseWheel(UINT nFlags,POINT *pPt,BOOL *pbHandled)
{
	MessageBoxW(NULL,L"接收到鼠标滚轮滚动消息!",L"提示",MB_OK);
	return 0;
}
int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(hWindow)
    {
		XBtn_SetType(XBtn_Create(10,10,80,25,L"关闭",hWindow),button_type_close);

		HELE hChild = XEle_Create(0,0,100,100,hWindow);
		XEle_EnableEvent_XE_MOUSEWHEEL(hChild,TRUE);
		XEle_RegEventC(hChild,XE_MOUSEWHEEL,OnMouseWheel);

        XWnd_ShowWindow(hWindow,SW_SHOW);//显示窗口
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


