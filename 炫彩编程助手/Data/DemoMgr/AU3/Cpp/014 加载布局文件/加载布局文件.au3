#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
XC_LoadResource("resource.xml")
$create = XC_LoadLayout("test.xml")
$btn1 = XC_GetObjectByID(101)
XEle_RegEventC($btn1, "btn1")
$btn2 = XC_GetObjectByID(102)
XEle_RegEventC($btn2, "btn2")
$btn3 = XC_GetObjectByID(201)
XEle_RegEventC($btn3, "btn3")
XWnd_ShowWindow($create)
XRunXCGUI()
Func btn1($bh)
	xquit_acn($create)
EndFunc   ;==>btn1
Func btn2($bh)
	MsgBox(0, "", "这是一个对话框!")
EndFunc   ;==>btn2
Func btn3($bh)
	ShellExecute("iexplore.exe", "www.xcgui.com")
EndFunc   ;==>btn3
