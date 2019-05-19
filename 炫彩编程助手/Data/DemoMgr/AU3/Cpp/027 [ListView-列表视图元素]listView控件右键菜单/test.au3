#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
XC_ShowLayoutFrame(True) ;显示布局边界
$create = XWnd_Create(0, 0, 500, 300, "窗口测试", 47)

$hListView = XListView_Create(8, 30, 400, 200, $create)
XListView_SetItemTemplateXML($hListView, "XML-template\ListView_Item.xml")

$hAdapter = XAdapterListView_Create()
XListView_BindAdapter($hListView, $hAdapter)
XAdapterListView_Group_AddColumn($hAdapter, "name3")
XAdapterListView_Item_AddColumn($hAdapter, "name")
XAdapterListView_Item_AddColumn($hAdapter, "name2")

$group1 = XAdapterListView_Group_AddItemText($hAdapter, "group1")

$hImage = XImage_LoadFile("saomiao_down.jpg", False)
$index = XAdapterListView_Item_AddItemImage($hAdapter, $group1, $hImage)
XAdapterListView_Item_SetText($hAdapter, $group1, $index, 1, "test1")

XEle_RegEventC($hListView, "OnRButtonUp", $XE_RBUTTONUP, "int;int") ;注册鼠标右键弹起事件
XWnd_RegEventC($create, "OnWndMenuSelect", $XWM_MENU_SELECT) ;注册菜单选择事件

$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func OnRButtonUp($nFlags, $pPt)
	Local $n, $m
	$a = _POINT()
	CopyMemory($a, $pPt)
	$hj = XListView_HitTest($hListView, DllStructGetPtr($a), $n, $m)
	If $hj = 0 Then
		$hMenu = XMenu_Create() ;创建菜单.默认弹出菜单窗口关闭后自动销毁

		XMenu_AddItem($hMenu, 201, "1", $XC_ID_ROOT, 0) ;添加菜单项
		XMenu_AddItem($hMenu, 202, "2", $XC_ID_ROOT, 0)
		XMenu_AddItem($hMenu, 203, "3", $XC_ID_ROOT, 0)
		
		XMenu_AddItem($hMenu, 2031, "3-1", 203, 0)
		
		XEle_PointClientToWndClient($hListView, DllStructGetPtr($a)) ;元素客户区坐标转换到窗口客户区坐标

		ClientToScreen($create, $a) ;判断窗口内以客户区坐标表示的一个点的屏幕坐标  非零表示成功，零表示失败
		;弹出菜单
		XMenu_Popup($hMenu, XWnd_GetHWND($create), DllStructGetData($a, "x"), DllStructGetData($a, "y"), 0, 0)
	EndIf
EndFunc   ;==>OnRButtonUp

Func OnWndMenuSelect($nID)
	MsgBox(0, "", "选择的菜单ID为: " & $nID, -1, XWnd_GetHWND($create))
EndFunc   ;==>OnWndMenuSelect

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
