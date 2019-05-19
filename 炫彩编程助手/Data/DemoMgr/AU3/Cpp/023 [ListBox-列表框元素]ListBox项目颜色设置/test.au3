#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, 500, 400, "窗口测试", $xc_window_style_default)
$hListBox = XListBox_Create(8, 30, 400, 300, $create) ;创建ListBox
XListBox_SetItemTemplateXML($hListBox, "ListBox_Item.xml") ;加载ListBox模板

$hAdapter = XAdapterTable_Create() ;创建列表框元素数据适配器
XListBox_BindAdapter($hListBox, $hAdapter) ;绑定列表框元素数据适配器
XAdapterTable_AddColumn($hAdapter, "name") ;添加数据列

XListBox_AddItemBkFill($hListBox, $list_item_state_leave, 0x800000, 100) ;添加项背景内容填充(鼠标离开状态)
XListBox_AddItemBkFill($hListBox, $list_item_state_stay, 0x008000, 100) ;添加项背景内容填充(鼠标停留状态)
XListBox_AddItemBkFill($hListBox, $list_item_state_select, 0x000080, 100) ;添加项背景内容填充(选择状态 )

For $i = 1 To 20
	XAdapterTable_AddItemText($hAdapter, "ID-" & $i) ;添加数据项,默认值放到第一列
Next
XEle_RedrawEle($hListBox, False) ;重绘元素(不立即重绘)
XEle_RegEventC1($hListBox, "OnListBoxTemplateCreateEnd", $XE_LISTBOX_TEMP_CREATE_END, "int;int") ;注册列表事件到自定义函数(列表框元素,项模板创建完成事件)
XEle_RegEventC1($hListBox, "OnListBoxSelect", $XE_LISTBOX_SELECT)

$btn2 = XBtn_Create("420", "2", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

Func OnListBoxTemplateCreateEnd($hEle, $pItem)
	$a = _listBox_item_i() ;返回listBox_item_i数据结构
	CopyMemory($a, $pItem) ;复制内存数据
	$btn = XListBox_GetTemplateObject($hListBox, DllStructGetData($a, "index"), 2) ;通过模板项ID,获取实例化模板项ID对应的对象句柄
	If XC_IsHXCGUI($btn, $XC_BUTTON) Then ;判断句柄类型是否为按钮($XC_BUTTON)
		$pp = XListBox_GetItemData($hListBox, DllStructGetData($a, "index")) ;获取项用户数据
		If $pp = 0 Then
			XBtn_SetCheck($btn, False) ;设置选中状态
		Else
			XBtn_SetCheck($btn, True)
		EndIf
		XEle_RegEventC1($btn, "OnListBoxBtnClick", $XE_BNCLICK) ;注册列表按钮点击事件到自定义函数
	EndIf
EndFunc   ;==>OnListBoxTemplateCreateEnd

Func OnListBoxBtnClick($bh)
	$nItemID = XListBox_GetItemIndexFromHXCGUI($hListBox, $bh) ;获取当前对象所在模板实例,属于列表中哪一个项
	$hShapText = XListBox_GetTemplateObject($hListBox, $nItemID, 3) ;通过模板项ID,获取实例化模板项ID对应的对象句柄
	$GetText = XShapeText_GetText($hShapText, 0, 50) ;获取文本内容
	XListBox_SetItemData($hListBox, $nItemID, BitXOR(XBtn_IsCheck($bh), 1)) ;设置项用户数据,这个函数很重要,如果不适用此函数列表不会保存按钮的选择状态,不明白的可以注释掉这个函数,试试看有什么差别
	MsgBox(0, "", $GetText[2], -1, XWnd_GetHWND($create))
EndFunc   ;==>OnListBoxBtnClick

Func OnListBoxSelect($hEle,$bHandle)
	$bHandle = True  ;消息拦截
EndFunc