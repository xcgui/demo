// WinMain.cpp : Defines the entry point for the console application.
//

#include "Common.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{

	XInitXCGUI();
	XC_InitLua();
	XC_RunLua("main.lua");

	XRunXCGUI();
	XC_ExitLua();
	XExitXCGUI();
	return 0;
}
