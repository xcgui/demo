#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("500", "500", "500", "500", "窗口测试", 47)
$XList = XList_Create("20", "40", "440", "400", $create)
XList_SetItemHeightDefault($XList, 35, 40)  ;设置项未选中高度,选中高度
$ggg=XList_SetItemTemplateXML($XList,@ScriptDir&"\List_Item.xml")  ;加载列表模板
XList_AddColumn($XList, 100)  ;设置列宽度
XList_AddColumn($XList, 100)
XList_AddColumn($XList, 100)
$XAm = XAdapterMap_Create()
XList_BindAdapterHeader($XList, $XAm)
$XA = XAdapterTable_Create()
XList_BindAdapter($XList, $XA)
XAdapterTable_AddColumn($XA, "name")
XAdapterTable_AddColumn($XA, "name2")
XAdapterTable_AddColumn($XA, "name3")
For $i = 0 To 10
	XAdapterTable_AddItemTextEx($XA, "name", "ListBox")
	XAdapterTable_SetItemText($XA, $i, 1, "ListBox-" & $i & "-1")
	XAdapterTable_SetItemText($XA, $i, 2, "ListBox-" & $i & "-2")
Next
XEle_RegEventC1($XList, "_OnListTemplateCreateEnd", $XE_LIST_TEMP_CREATE_END, "int;int")  ;注册列表事件
$btn2 = XBtn_Create("400", "460", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)

XRunXCGUI()
Func _OnListTemplateCreateEnd($hEle, $pItem)
	$a = _list_item_i()  ;获得 list_item_i 数据结构
	CopyMemory($a, $pItem)
	$but = XList_GetTemplateObject($XList, DllStructGetData($a, 1), 20)  ;获取句柄
	$pd = XC_IsHXCGUI($but, $XC_BUTTON)  ;判断获取的句柄是否为按钮
	If $pd = True Then
		XEle_RegEventC1($but, "_but_list", 34)  ;设置按钮点击事件
	EndIf
EndFunc
Func _but_list($bh)
	$ghgh = XList_GetItemIndexFromHXCGUI($XList, $bh)  ;获取当前对象所在模板实例,属于列表中哪一个项
	$yu = XAdapterTable_GetItemText($XA, $ghgh, 1, 50)  ;获取项文本内容
	MsgBox(0,"",$yu[4])
EndFunc
Func btn2($bh)
	xquit_acn($create)
EndFunc 
