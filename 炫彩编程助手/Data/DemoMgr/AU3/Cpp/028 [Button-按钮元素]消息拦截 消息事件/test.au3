#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, "480", "300", "窗口测试", 47)

$btn1 = XBtn_Create(200, 100, "75", "25", "测试按钮", $create)
XEle_RegEventC($btn1, "btn1")
XEle_RegEventC($btn1, "btn3", 34, "bool") ;如果在这里面拦截了消息,那么就不会调用上面的函数了

$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn1($bh)
	MsgBox(0, "1", "这里是回调函数1", -1, XWnd_GetHWND($create))
EndFunc   ;==>btn1
Func btn3($pHandle)
	MsgBox(0, "2", "这里是回调函数2", -1, XWnd_GetHWND($create))
	pHandle($pHandle) ;消息拦截,可以把它注释掉看看有什么区别
	Return 0
EndFunc   ;==>btn3
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
