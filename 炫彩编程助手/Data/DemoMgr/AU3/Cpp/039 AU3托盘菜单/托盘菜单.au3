#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****

Opt("TrayMenuMode", 1) ;设置不显示默认菜单项目 (脚本暂停中/退出)
#include "XCGUI_Fun.au3"
#include <Constants.au3>

XInitXCGUI()
$create = XWnd_Create(0, 0, 600, 500, "窗口测试", 47)
XWnd_RegEventC($create, "OnWndMenuSelect", $XWM_MENU_SELECT)
$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

While 1
	Switch TrayGetMsg()
		Case $TRAY_EVENT_SECONDARYDOWN ;鼠标右键被点击
			_tray()
	EndSwitch
WEnd

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
Func _tray()
	$traypos = MouseGetPos()
	$hMenu = XMenu_Create() ;创建菜单.默认弹出菜单窗口关闭后自动销毁
	XMenu_AddItem($hMenu, 201, "1", $XC_ID_ROOT, 0) ;添加菜单项
	XMenu_AddItem($hMenu, 202, "2", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, 203, "3", $XC_ID_ROOT, 0)
	XMenu_AddItem($hMenu, 2031, "3-1", 203, 0)
	;弹出菜单
	XMenu_Popup($hMenu, XWnd_GetHWND($create), $traypos[0], $traypos[1], 0, 0)
EndFunc   ;==>_tray
Func OnWndMenuSelect($nID)
	MsgBox(0, "", "选择的菜单ID为: " & $nID, -1, XWnd_GetHWND($create))
EndFunc   ;==>OnWndMenuSelect
