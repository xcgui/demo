#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "窗口测试", 47)
$btn1 = XBtn_Create("20", "60", "165", "65", "炫彩按钮", $create)
$font = XFont_Create2("黑体", 18, True, False, False, False)
XEle_SetTextColor($btn1, 0x0000ff, 255)
XEle_SetFont($btn1, $font)
$btn2 = XBtn_Create("180", "260", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
