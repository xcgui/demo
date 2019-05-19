#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "300", "200", "窗口测试", 47)
$btn1 = XBtn_Create("100", "100", "75", "25", "Test", $create)
XEle_RegEventC($btn1, "btn1")
XWnd_ShowWindow($create)
XRunXCGUI()
Func btn1($bh)
	$exit = MsgBox(4, "退出程序", "是否退出本程序?")
	If $exit = 6 Then xquit_acn($create)
EndFunc   ;==>btn1

