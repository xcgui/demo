#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "480", "300", "窗口测试", 47)
$XRich = XRichEdit_Create(40, 80, 200, 30, $create)
XEle_RegEventC($XRich, "OnEventChar", $XE_CHAR, "int;int;bool") ;注册XE_CHAR事件(通过TranslateMessage函数翻译的字符事件)
$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func OnEventChar($wParam, $lParam, $pbHandled)
	If $wParam >= 48 And $wParam <= 57 Then ;对比ASCII码,如果不在48-57之间那么拦截消息
		Return 0 ;ASCII码48-57 就是数字0-9
	EndIf
	pHandle($pbHandled) ;拦截消息
EndFunc   ;==>OnEventChar
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
