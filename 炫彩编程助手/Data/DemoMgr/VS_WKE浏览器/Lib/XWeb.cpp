#include "Common.h"
#include "XWeb.h"



//检查句柄错误
BOOL ERROR_IsXCGUI_DASEMIMI(HXCGUI hXCGUI, XC_OBJECT_TYPE nType,char* pFunName)
{
	if (XC_IsHXCGUI(hXCGUI, nType))
		return TRUE;
	_XC_DebugPrintf(2, "在API:%s()中, 输入句柄可能无效[%d].", pFunName, hXCGUI);
	return FALSE;
}



///////////对外接口/////////////////////////////////////////////////
/// @defgroup web web-浏览器
/// @ingroup  groupElements
/// 按钮接口列表
/// @{

/// @brief    创建浏览器
/// @param x  x坐标.
/// @param y  y坐标.
/// @param cx 宽度.
/// @param cy 高度.
/// @param hParent 父为窗口句柄或元素句柄.
/// @return   窗口句柄.
XC_API HELE WINAPI XWeb_Create(int x,int y,int cx,int cy,HXCGUI hParent)
{
	return XWeb::Create(x,y,cx,cy,hParent);
}
XC_API wkeWebView* WINAPI XWeb_GetWebView(HELE hEle)
{
	ERROR_IsXCGUI_DASEMIMI(hEle,XC_WEB,"XWeb_GetWebView");
	XWeb* pWeb = (XWeb*)_XC_GetBindData(hEle);
	return pWeb->GetWebView();
}