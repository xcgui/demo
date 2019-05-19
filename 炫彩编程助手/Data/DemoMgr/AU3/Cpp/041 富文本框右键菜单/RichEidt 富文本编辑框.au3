#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "380", "240", "窗口测试", 47)
$XRichEdit = XRichEdit_Create("20", "40", "120", "25", $create)
$btn2 = XBtn_Create("180", "40", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XEle_RegEventC($XRichEdit, "XRichEdit_menu", $XE_RBUTTONUP, "int;int") ;注册鼠标右键弹起事件
XWnd_RegEventC($create, "_menuevent", $XWM_MENU_SELECT) ;注册菜单选择事件
XWnd_ShowWindow($create)
XRunXCGUI()
While 1
	Sleep(50)
WEnd
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
Func XRichEdit_menu($nFlags, $pPt)
	Local $n, $m
	$a = _POINT()
	CopyMemory($a, $pPt)
	$hMenu = XMenu_Create() ;创建菜单.默认弹出菜单窗口关闭后自动销毁
	XMenu_AddItem($hMenu, 980201, "撤销(U)", $XC_ID_ROOT, 0) ;添加菜单项
	XMenu_SetItemFlags($hMenu, 980201, $menu_item_flags_disable)
	XMenu_AddItem($hMenu, 0, "", $XC_ID_ROOT, $menu_item_flags_separator)
	XMenu_AddItem($hMenu, $IDM_CLIP, "剪切(T)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, $IDM_COPY, "复制(C)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, $IDM_PASTE, "粘贴(V)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, $IDM_DELETE, "删除(D)", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, 0, "", $XC_ID_ROOT, $menu_item_flags_separator)
	XMenu_AddItem($hMenu, $IDM_SELECTALL, "全选(A)", $XC_ID_ROOT, 0)
	XEle_PointClientToWndClient($XRichEdit, DllStructGetPtr($a)) ;元素客户区坐标转换到窗口客户区坐标
	ClientToScreen($create, $a) ;判断窗口内以客户区坐标表示的一个点的屏幕坐标  非零表示成功，零表示失败
	;弹出菜单
	XMenu_Popup($hMenu, XWnd_GetHWND($create), DllStructGetData($a, "x"), DllStructGetData($a, "y"), 0, $menu_popup_position_left_top)
EndFunc   ;==>XRichEdit_menu

Func _menuevent($nID)
	Switch $nID
		Case 980201
			;撤销功能用处不大,所以没写
		Case $IDM_SELECTALL ;全选
			XRichEdit_SelectAll($XRichEdit)
			XWnd_RedrawWnd($create, True)
		Case $IDM_CLIP ;剪切
			XRichEdit_ClipboardCut($XRichEdit)
			XWnd_RedrawWnd($create, True)
		Case $IDM_COPY ;复制
			XRichEdit_ClipboardCopy($XRichEdit)
		Case $IDM_PASTE ;粘贴
			XRichEdit_ClipboardPaste($XRichEdit)
			XWnd_RedrawWnd($create, True)
		Case $IDM_DELETE ;删除
			XRichEdit_DeleteSelect($XRichEdit)
			XWnd_RedrawWnd($create, True)
	EndSwitch
EndFunc   ;==>_menuevent
