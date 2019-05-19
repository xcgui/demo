#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "窗口测试", 47)
$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")

$hSView = XSView_Create(10, 30, 400, 200, $create)  ;创建滚动视图元素
XSView_SetTotalSize($hSView, 1000, 1000) ;设置滚动视图的宽和高
XSView_SetLineSize($hSView, 10, 10) ;设置滚动单位大小
XBtn_Create(0, 0, 50, 50, "test", $hSView)
XBtn_Create(100, 900, 50, 50, "我在这", $hSView)
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
