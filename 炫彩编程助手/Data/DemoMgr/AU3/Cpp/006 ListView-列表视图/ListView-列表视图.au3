#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "500", "500", "窗口测试", 47)
$XListView = XListView_Create("20", "40", "440", "400", $create)
$XA = XAdapterListView_Create()
$gr = XAdapterListView_Group_AddColumn($XA, "name3")
XAdapterListView_Item_AddColumn($XA, "name")
XAdapterListView_Item_AddColumn($XA, "name2")
XListView_BindAdapter($XListView, $XA)
$group = XAdapterListView_Group_AddItemText($XA, "分组1")
$hImage = XImage_LoadFile("lv.jpg", False)
For $i = 0 To 10
	$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
	$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
Next
$btn2 = XBtn_Create("400", "460", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
