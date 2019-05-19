#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "600", "500", "窗口测试",$xc_window_style_default)
$btn3 = XBtn_Create("100", "100", "150", "150", "", $create)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s1.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s2.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s3.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s4.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s5.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s6.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s7.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s8.png",True),150)
XBtn_AddAnimationFrame($btn3,XImage_LoadFile("image\s9.png",True),150)
XBtn_EnableAnimation($btn3,True,True)
$btn2 = XBtn_Create("280", "400", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XEle_RegEventC($btn3, "btn3")
XWnd_ShowWindow($create)
XRunXCGUI()
Func btn3($bh)
	MsgBox(0,"","你点击了我哦")
EndFunc

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
