#ifndef Common_h__
#define Common_h__
/********************************************************************
	created:	2015/07/15
	created:	15:7:2015   17:37
	filename: 	Common.h
	file path:	WinMain
	file base:	Common
	file ext:	h
	author:		 大色秘密
	
	purpose:	炫彩兼容头文件(兼容vc6 vs2008 2010 2013 2015 等)
*********************************************************************/


#ifndef _UNICODE
#define _UNICODE
#define UNICODE
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
// #ifndef strcpy_s
// #define strcpy_s strcpy
// #endif
#if _MSC_VER == 1200  // MS VC++6.0 _MSC_VER=1200 vc6
	#define strcpy_s strcpy
#endif

#if _MSC_VER == 1500  // MS VC++9.0 _MSC_VER=1500 vs2008
#endif




//包含炫彩界面库文件
#pragma comment(lib, "XCGUI.lib")
#include "xcgui.h"

#define XC_SY_DEFAULT xc_window_style_default
#define XC_BUTTON_TYPE_CLOSE   button_type_close

#include <GdiPlus.h>
using namespace Gdiplus;
#define ULONG_PTR ULONG
#pragma comment(lib,"gdiplus.lib")


#ifndef _tWinMain
#ifdef _UNICODE
#define _tWinMain   wWinMain
#else
#define _tWinMain   WinMain
#endif
#endif

#ifndef _T
#define _T(x) L ## x
#endif

#ifndef wstring

#include <string>
using namespace std;
#endif



#endif // Common_h__