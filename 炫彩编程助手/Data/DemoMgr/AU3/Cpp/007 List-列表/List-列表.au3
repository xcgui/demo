#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "500", "500", "窗口测试", 47)
$XList = XList_Create("20", "40", "440", "400", $create)
XList_AddColumn($XList, 100)
XList_AddColumn($XList, 100)
XList_AddColumn($XList, 100)
$XAm = XAdapterMap_Create()
XList_BindAdapterHeader($XList, $XAm)
XAdapterMap_AddItemText($XAm, "name", "A001")
XAdapterMap_AddItemText($XAm, "name2", "A002")
XAdapterMap_AddItemText($XAm, "name3", "A003")
$XA = XAdapterTable_Create()
XList_BindAdapter($XList, $XA)
XAdapterTable_AddColumn($XA, "name")
XAdapterTable_AddColumn($XA, "name2")
XAdapterTable_AddColumn($XA, "name3")
For $i = 0 To 10
	XAdapterTable_AddItemTextEx($XA, "name", "ListBox")
	XAdapterTable_SetItemText($XA, $i, 1, "ListBox-" & $i & "-1")
	XAdapterTable_SetItemText($XA, $i, 2, "ListBox-" & $i & "-2")
	XAdapterTable_SetItemText($XA, $i, 3, "ListBox-" & $i & "-3")
Next
$btn2 = XBtn_Create("400", "460", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc 
