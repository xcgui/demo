#include "Common.h"



HWINDOW  hWindow=NULL;

//自动销毁字体
VOID AutoDestoryFont(HELE hEle)
{
	HFONTX hFontx = XFont_Create(20);
	HFONTX hFontx1 = XFont_Create(30);
	
	XEle_SetFont(hEle,hFontx);
	XEle_SetFont(hEle,hFontx1);
}
//手动销毁字体
VOID ManualDestoryFont(HELE hEle)
{
	
	HFONTX hFontx = XFont_Create(20);
	XFont_EnableAutoDestroy(hFontx,FALSE); //允许手动销毁字体

	HFONTX hFontx1 = XFont_Create(30);
	XEle_SetFont(hEle,hFontx);
	XEle_SetFont(hEle,hFontx1);

	XFont_Destroy(hFontx);
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(hWindow)
    {
        HELE hButton=XBtn_Create(10,10,80,25,L"按钮",hWindow);//创建按钮

		
		ManualDestoryFont(hButton);

        XWnd_ShowWindow(hWindow,SW_SHOW);//显示窗口		
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


