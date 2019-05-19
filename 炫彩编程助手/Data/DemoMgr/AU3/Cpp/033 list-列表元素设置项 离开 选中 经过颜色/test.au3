#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, 600, 500, "窗口测试", 47)
$m_hList = XList_Create(20, 40, 500, 300, $create)
XList_SetItemTemplateXML($m_hList, "XML-template\List_Item.xml")
XList_AddColumn($m_hList, 100)
$hAdapterHeader = XAdapterMap_Create()
XList_BindAdapterHeader($m_hList, $hAdapterHeader)
XAdapterMap_AddItemText($hAdapterHeader, "name", "aaa")

$hAdapter = XAdapterTable_Create()
XList_BindAdapter($m_hList, $hAdapter)
XAdapterTable_AddColumn($hAdapter, "name")
;设置鼠标离开项, 经过项, 选中项颜色
XList_AddItemBkFill($m_hList, $list_item_state_stay, 0xff0000, 255) ;留状
XList_AddItemBkFill($m_hList, $list_item_state_leave, 0x00ff00, 255) ;离开
XList_AddItemBkFill($m_hList, $list_item_state_select, 0x0000ff, 255) ;选中

For $i = 0 To 19
	XAdapterTable_AddItemTextEx($hAdapter, "name", "Litem-" & $i)
Next
$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
