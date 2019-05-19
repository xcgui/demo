#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "窗口测试", $xc_window_style_default)
$btn1 = XBtn_Create("40", "80", "120", "25", "打开模态窗口", $create)
XEle_RegEventC($btn1, "btn1")
$btn2 = XBtn_Create("180", "260", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()
Func btn1($bh)
	$hModal = XModalWnd_Create(300, 150, "dase", XWnd_GetHWND($create), $xc_window_style_modal)
	$btn3 = XBtn_Create("90", "75", "75", "25", "关闭", $hModal)
	XBtn_SetType($btn3, $button_type_close)
	XModalWnd_DoModal($hModal)
EndFunc   ;==>btn1

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
