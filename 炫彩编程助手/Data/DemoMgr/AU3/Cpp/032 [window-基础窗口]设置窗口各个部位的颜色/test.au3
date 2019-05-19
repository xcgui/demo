#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "窗口测试", 47)
$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")

$hBkInfoM = XWnd_GetBkInfoManager($create)
XBkInfoM_AddFill($hBkInfoM, $window_state_body_leave, 255, 255)
XBkInfoM_AddFill($hBkInfoM, $window_state_top_leave, 128, 255)
XBkInfoM_AddFill($hBkInfoM, $window_state_left_leave, 111111, 255)
XBkInfoM_AddFill($hBkInfoM, $window_state_right_leave, 222222, 255)
XBkInfoM_AddFill($hBkInfoM, $window_state_bottom_leave, 333333, 255)

XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
