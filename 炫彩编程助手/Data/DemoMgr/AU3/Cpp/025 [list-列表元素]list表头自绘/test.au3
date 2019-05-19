#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "600", "500", "窗口测试", 47)

$m_hList = XList_Create(20, 40, 500, 300, $create)
XList_SetItemTemplateXML($m_hList, "XML-template\List_Item.xml")

XList_AddColumn($m_hList, 100)
XList_AddColumn($m_hList, 100)

$hAdapterHeader = XAdapterMap_Create()
XList_BindAdapterHeader($m_hList, $hAdapterHeader)
XAdapterMap_AddItemText($hAdapterHeader, "name", "aaa")
XAdapterMap_AddItemText($hAdapterHeader, "name2", "bbb")

$hAdapter = XAdapterTable_Create()
XList_BindAdapter($m_hList, $hAdapter)
XAdapterTable_AddColumn($hAdapter, "name")
XAdapterTable_AddColumn($hAdapter, "name2")
For $i = 0 To 19
	$nIndex = XAdapterTable_AddItemTextEx($hAdapter, "name", "Litem-" & $i)
	XAdapterTable_SetItemText($hAdapter, $nIndex, 1, "Litem-" & $i)
Next

;注册 列表元素绘制列表头项 事件到自定义函数 OnListHeaderDrawItem
XEle_RegEventC(XList_GetHeaderHELE($m_hList), "OnListHeaderDrawItem", $XE_LIST_HEADER_DRAWITEM, "int;int;bool")
$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
Func OnListHeaderDrawItem($hDraw, $pItem, $pHandle)
	$a = _list_header_item_i() ;取得list_header_item_i数据结构
	CopyMemory($a, $pItem) ;复制内存$pItem到list_header_item_i
	
	;设置画刷颜色
	XDraw_SetBrushColor($hDraw, "0x" & Hex(Random(0, 255, 1), 2) & Hex(Random(0, 255, 1), 2) & Hex(Random(0, 255, 1), 2), 255)
	XDraw_FillRect($hDraw, DllStructGetPtr($a, "rcItem")) ;通过使用指定的刷子填充一个矩形,此功能包括左侧和顶部的边界,但不包括矩形的右边和底部边界
	pHandle($pHandle)
EndFunc   ;==>OnListHeaderDrawItem
