#include "Common.h"


#include <iostream>
#include <fstream>

HWINDOW  hWindow=NULL;


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    hWindow=XWnd_Create(0,0,300,200,L"炫彩界面库-窗口");//创建窗口
    if(hWindow)
    {

		HELE hEle = XEle_Create(0,0,100,100,hWindow);

 		std::ifstream ifsm("1.jpg",std::ios::binary|std::ios::in);
		ifsm.seekg(0,std::ios::end);
		int fileSize =ifsm.tellg();
//		char buffer[1574] = {0};
		char* buffer = new char[fileSize];
 
 		ifsm.seekg(0,std::ios::beg);
 		ifsm.read(buffer,fileSize);
 		ifsm.close();

		HIMAGE hImage = XImage_LoadMemory((void*)buffer,fileSize,TRUE);

		HBKM hBkInfoM = XEle_GetBkManager(hEle);
		XBkM_AddImage(hBkInfoM,element_state_flag_leave,hImage);

		//老版本使用的方法，不要在用了
//		XEle_AddBkImage(hEle,hImage);


        XWnd_ShowWindow(hWindow,SW_SHOW);//显示窗口
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}


