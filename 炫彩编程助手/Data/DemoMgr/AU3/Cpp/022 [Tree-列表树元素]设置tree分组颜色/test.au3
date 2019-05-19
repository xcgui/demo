#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create("0", "0", "320", "520", "窗口测试", 47)
$m_hTree = XTree_Create(20, 40, 280, 450, $create)  ;创建树元素
XTree_SetItemHeightDefault($m_hTree, 28, 54)  ;设置项默认高度，未选中,选中
XTree_SetItemTemplateXML($m_hTree, "xml-template-test\Tree_Item_friend.xml")  ;设置项模板文件
XTree_SetItemTemplateXMLSel($m_hTree, "xml-template-test\Tree_Item_friend_sel.xml")  ;设置项模板文件,项选中状态
$m_pTemplate_group = XC_LoadTemplate($XC_TREE, "xml-template-test\Tree_Item_group.xml")  ;项模板文件载入
$m_hVip = XImage_LoadFile("QQImage\vip.png", False)  ;加载图片并返回图片句柄
$m_hQZone = XImage_LoadFile("QQImage\QZone.png", False)
$m_hAvatar = XImage_LoadFile("QQImage\avatar.png", False)
$m_hAvatarLarge = XImage_LoadFile("QQImage\avatar_large.png", False)
$hAdapter = XAdapterTree_Create()  ;创建树元素数据适配器
XTree_BindAdapter($m_hTree, $hAdapter)  ;绑定数据适配器
XAdapterTree_AddColumn($hAdapter, "name") ;添加列 昵称 分组名
XAdapterTree_AddColumn($hAdapter, "name2") ; 签名
XAdapterTree_AddColumn($hAdapter, "name3") ; 小头像
XAdapterTree_AddColumn($hAdapter, "name4") ; 大头像
XAdapterTree_AddColumn($hAdapter, "name5") ; VIP 图标
XAdapterTree_AddColumn($hAdapter, "name6") ; 空间图标
For $i = 1 To 5  ;循环向树元素中添加内容
	$nGroupID = XAdapterTree_InsertItemText($hAdapter, "好友分组-" & $i, $XC_ID_ROOT, $XC_ID_LAST)  ;插入项,数据填充到第一列
	XTree_SetItemHeight($m_hTree, $nGroupID, 26, 26)
	For $x = 1 To 3
		$nItemID = XAdapterTree_InsertItemText($hAdapter, "好1友分组-" & $x, $nGroupID, $XC_ID_LAST)
		XAdapterTree_SetItemTextEx($hAdapter, $nItemID, "name2", "我的个性签名!")  ;设置项文件内容
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name5", $m_hVip)
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name6", $m_hQZone)
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name3", $m_hAvatar)
		XAdapterTree_SetItemImageEx($hAdapter, $nItemID, "name4", $m_hAvatarLarge)
	Next
Next
XEle_RegEventC($m_hTree, "OnTemplateCreate", $XE_TREE_TEMP_CREATE)  ;注册 树元素,项模板创建 事件到自定义函数 OnTemplateCreate
XEle_RegEventC($m_hTree, "OnTreeTemplateCreateEnd", $XE_TREE_TEMP_CREATE_END)  ;注册 树元素,项模板创建完成 事件到自定义函数 OnTreeTemplateCreateEnd
$btn2 = XBtn_Create("235", "2", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_AdjustLayout($create)
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

Func OnTreeTemplateCreateEnd($pItem)
	$a = _tree_item_i()  ;返回tree_item_i数据结构
	CopyMemory($a, $pItem)  ;复制内存数据
	$btn = XTree_GetTemplateObject($m_hTree, DllStructGetData($a, "nID"), 1)  ;通过模板项ID,获取实例化模板项ID对应的对象句柄
	$pd = XC_IsHXCGUI($btn, $XC_BUTTON)  ;判断句柄类型是否为按钮($XC_BUTTON)
	If $pd = True Then
		$unCheck = XImage_LoadFile("收.png", False)
		$check = XImage_LoadFile("开.png", False)
		XBtn_SetStyle($btn, $button_style_default)  ;设置按钮样式为默认
		$hBkInfoM = XEle_GetBkInfoManager($btn)  ;获取元素背景内容管理器
		XBkInfoM_AddImage($hBkInfoM, $button_state_flag_check_no, $unCheck)  ;添加背景内容图片(未选中)
		XBkInfoM_AddImage($hBkInfoM, $button_state_flag_check, $check)  ;;添加背景内容图片(选中)
	EndIf
	$hEle = XTree_GetTemplateObject($m_hTree, DllStructGetData($a, 1), 5)
	If XC_IsHXCGUI($hEle, $XC_ELE) Then
		$hBkInfoM = XEle_GetBkInfoManager($hEle)  
		XBkInfoM_AddFill($hBkInfoM, $element_state_flag_leave, 255, 255)  ;添加背景内容填充(鼠标离开,颜色:255,透明度:255) 
	EndIf
EndFunc   ;==>OnTreeTemplateCreateEnd

Func OnTemplateCreate($pItem)
	$a = _tree_item_i()
	CopyMemory($a, $pItem)
	$GetFirst = XTree_GetFirstChildItem($m_hTree, DllStructGetData($a, 1))  ;获取第一个子项
	If $XC_ID_ERROR < $GetFirst Then
		If DllStructGetData($a, "info") > 0 Then  ;以下是将相关模板信息写入内存
			$tm = DllStructSetData($a, "info", $m_pTemplate_group) 
			CopyMemory($pItem,$a,0,1,0)
		EndIf
	EndIf
EndFunc   ;==>OnTemplateCreate
