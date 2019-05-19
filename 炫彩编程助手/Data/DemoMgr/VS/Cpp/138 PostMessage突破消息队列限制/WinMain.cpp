#include "Common.h"

#include "LY_MainDlg.h"


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化

	CLYMainDlgClass dlg;
	dlg.Init();
    XRunXCGUI(); //运行
    XExitXCGUI(); //释放资源
    return 0;
}


