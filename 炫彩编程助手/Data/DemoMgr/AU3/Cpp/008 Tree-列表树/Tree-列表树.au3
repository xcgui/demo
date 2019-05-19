#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "280", "500", "窗口测试", 47)
$XListView = XTree_Create("20", "40", "200", "400", $create)
$XA = XAdapterTree_Create()
XTree_BindAdapter($XListView, $XA)
XAdapterTree_AddColumn($XA, "name")
XAdapterTree_InsertItemText($XA, "name", 0, -3)
XAdapterTree_InsertItemText($XA, "Item", 1, -3)
XAdapterTree_InsertItemText($XA, "Item", 1, -3)
$it = XAdapterTree_InsertItemText($XA, "name", 0, -3)
XAdapterTree_InsertItemText($XA, "Item", 1, -3)
XAdapterTree_InsertItemText($XA, "Item", $it, -3)
$btn2 = XBtn_Create("180", "460", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
