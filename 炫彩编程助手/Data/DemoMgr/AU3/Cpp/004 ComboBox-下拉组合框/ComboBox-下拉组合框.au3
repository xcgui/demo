#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "300", "200", "窗口测试", 47)
$ComboBox = XComboBox_Create("60", "40", "175", "25", $create)
$XA = XAdapterTable_Create()
XComboBox_BindApapter($ComboBox, $XA)
XAdapterTable_AddColumn($XA, "name")
XRichEdit_SetText($ComboBox, "ComboBox")
For $i = 1 To 10
	XAdapterTable_AddItemText($XA, "aaaa-" & $i)
Next
$btn2 = XBtn_Create("100", "140", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()
Func btn2($bh)
	xquit_acn($create)
EndFunc 
