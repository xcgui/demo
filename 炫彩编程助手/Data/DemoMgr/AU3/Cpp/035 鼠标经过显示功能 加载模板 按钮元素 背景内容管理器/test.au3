#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****

#include "XCGUI_Fun.au3"
XInitXCGUI()
XC_LoadResource("res\resource.xml", "res")
$hWindow = XC_LoadLayout("res\layout.xml", 0)
$hBk = XWnd_GetBkInfoManager($hWindow)
$hEleBase = XC_GetObjectByID(10)
$hElePane = XC_GetObjectByID(11)
XEle_EnableMouseThrough($hEleBase, True)

XWnd_RegEventC($hWindow, "OnWndMouseHover", $WM_MOUSEHOVER, "int;int") ;WM_MOUSEHOVER 窗口鼠标进入消息
XWnd_RegEventC($hWindow, "OnWndMouseLeave", $WM_MOUSELEAVE) ;WM_MOUSELEAVE 窗口鼠标离开消息

XWnd_AdjustLayout($hWindow)
XWnd_ShowWindow($hWindow)
XRunXCGUI()

Func OnWndMouseHover($nFlags, $pPt)
	XBkInfoM_SetBkInfo($hBk, "{5:1(1)2(15)3(0,0,0,0)10(0)20(1)8(0.00)21(1)22(33554431)23(1);}")
	XEle_ShowEle($hElePane, True)
	XWnd_RedrawWnd($hWindow, True)
EndFunc   ;==>OnWndMouseHover

Func OnWndMouseLeave($bh)
	XBkInfoM_Clear($hBk)
	XEle_ShowEle($hElePane, False)
	XWnd_RedrawWnd($hWindow, True)
EndFunc   ;==>OnWndMouseLeave

Func btn2($bh)
	xquit_acn($hWindow)
EndFunc   ;==>btn2
