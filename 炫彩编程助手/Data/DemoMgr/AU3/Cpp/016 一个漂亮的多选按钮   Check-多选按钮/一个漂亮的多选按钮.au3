#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "600", "500", "窗口测试", $xc_window_style_default)
$btn3 = XBtn_Create("100", "100", "150", "70", "", $create)
$xbk = XEle_GetBkInfoManager($btn3)
$img1 = XImage_LoadFile("image\off1.png", True)
$img2 = XImage_LoadFile("image\on1.png", True)
XBkInfoM_AddImage($xbk, $button_state_flag_check_no, $img1)
XBkInfoM_AddImage($xbk, $button_state_flag_check, $img2)
XBtn_SetType($btn3, $button_type_check)
XBtn_SetStyle($btn3, 0)
$text = XShapeText_Create("280", "130", "100", "30", "关闭", $create)
$btn2 = XBtn_Create("280", "400", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XEle_RegEventC($btn3, "btn3")
XWnd_ShowWindow($create)

XRunXCGUI()
Func btn3($bh)
	$check = XBtn_IsCheck($btn3)
	If $check = 0 Then
		XShapeText_SetText($text, "打开")
		XWnd_RedrawWnd($create, True)
	Else
		XShapeText_SetText($text, "关闭")
		XWnd_RedrawWnd($create, True)
	EndIf
EndFunc   ;==>btn3
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
