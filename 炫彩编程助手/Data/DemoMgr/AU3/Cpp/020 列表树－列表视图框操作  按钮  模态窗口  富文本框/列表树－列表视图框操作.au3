#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****

;本例程由chzj589编写,2016-03-31

#include "XCGUI_Fun.au3"
$_width = 800
$_height = 600
$_title = "窗口测试"
$_style = 1
Global $XList, $XListBox, $XListView1
XInitXCGUI()
$create = XWnd_Create("500", "500", $_width, $_height, $_title, 47)
$str = XShapeText_Create("8", "6", "100", "20", "   炫彩界面库-列表树－列表视图框操作", $create)
$font = XFont_Create2("宋体", "12", True, False, False, False) ;创建字体
XShapeText_SetFont($str, $font) ;设置XShapeText元素字体
XShapeText_SetTextColor($str, 0x00ff66, 255) ;设置XShapeText元素颜色
$XTree = XTree_Create("20", "40", "200", "400", $create)
XEle_RegEventC($XTree, "_Tree", $XE_LBUTTONUP) ;注册列表事件,$XE_LBUTTONUP(左键抬起)....没找到单击的事件
$XA = XAdapterTree_Create()
XTree_BindAdapter($XTree, $XA)
XAdapterTree_AddColumn($XA, "name")
XAdapterTree_InsertItemText($XA, "首页", 0, -3)
$XAbtn1 = XAdapterTree_InsertItemText($XA, "列表视图", 1, -3)
XAdapterTree_InsertItemText($XA, "List-列表", 1, -3)
$it = XAdapterTree_InsertItemText($XA, "文件B", 0, -3)
XAdapterTree_InsertItemText($XA, "列表框", 1, -3)
XAdapterTree_InsertItemText($XA, "修改密码", $it, -3)
XAdapterTree_InsertItemText($XA, "动画按钮", $it, -3)
XAdapterTree_InsertItemText($XA, "编辑框", $it, -3)
$XListView = XListView_Create("225", "40", "560", "400", $create)
XEle_RegEventC($XListView, "_XListView", $XE_LBUTTONUP) ;注册列表事件
$XA = XAdapterListView_Create()
$gr = XAdapterListView_Group_AddColumn($XA, "name3")
XAdapterListView_Item_AddColumn($XA, "name")
XAdapterListView_Item_AddColumn($XA, "name2")
XListView_BindAdapter($XListView, $XA)
$group = XAdapterListView_Group_AddItemText($XA, "分组1")
$hImage = XImage_LoadFile("image\炫彩1.jpg", False)
For $i = 0 To 10
	$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
	$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
Next
$stra = XShapeText_Create("8", "446", "700", "20", "   炫彩界面库-列表树操作－－", $create)
$stra1 = XShapeText_Create("8", "491", "700", "20", "   列表视图框操作－列表框－List-列表", $create)
$stra2 = XShapeText_Create("8", "536", "700", "20", "   动画按钮－富文本编辑框", $create)
$fonta = XFont_Create2("宋体", "28", True, False, False, False) ;创建字体
XShapeText_SetFont($stra, $fonta) ;设置XShapeText元素字体
XShapeText_SetTextColor($stra, 0x0000ff, 255) ;设置XShapeText元素颜色
XShapeText_SetFont($stra1, $fonta) ;设置XShapeText元素字体
XShapeText_SetTextColor($stra1, 0x009900, 255) ;设置XShapeText元素颜色
XShapeText_SetFont($stra2, $fonta) ;设置XShapeText元素字体
XShapeText_SetTextColor($stra2, 0xff0000, 255) ;设置XShapeText元素颜色
$btnt = XBtn_Create("4", "4", "27", "23", "", $create)
$xbkt = XEle_GetBkInfoManager($btnt) ;获取元素背景内容管理器
$imgt = XImage_LoadFile("image\炫彩1.jpg", True) ;加载图片从文件
XBkInfoM_AddImage($xbkt, $button_state_flag_check_no, $imgt) ;添加背景内容图片
XBtn_SetType($btnt, $button_type_check) ;设置按钮类型
XEle_EnableDrawFocus($btnt, False)
XBtn_SetStyle($btnt, 0) ;设置按钮样式
$btna2 = XBtn_Create("738", "-2", "27", "27", "", $create)
$xbka2 = XEle_GetBkInfoManager($btna2) ;获取元素背景内容管理器
$img3 = XImage_LoadFile("image\close_03.jpg", True) ;加载图片从文件
XBkInfoM_AddImage($xbka2, $button_state_flag_check_no, $img3) ;添加背景内容图片
XBtn_SetType($btna2, $button_type_check) ;设置按钮类型
XEle_EnableDrawFocus($btna2, False)
XBtn_SetStyle($btna2, 0) ;设置按钮样式
XBtn_SetType($btna2, $button_type_min) ;设置按钮功能类型为最小化按钮
$btn2 = XBtn_Create("768", "-2", "27", "27", "", $create)
$xbka = XEle_GetBkInfoManager($btn2) ;获取元素背景内容管理器
$img3 = XImage_LoadFile("image\close_02.jpg", True) ;加载图片从文件
XBkInfoM_AddImage($xbka, $button_state_flag_check_no, $img3) ;添加背景内容图片
XBtn_SetType($btn2, $button_type_check) ;设置按钮类型
XEle_EnableDrawFocus($btn2, False)
XBtn_SetStyle($btn2, 0) ;设置按钮样式
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()
TrayTip("", "", 1, 0)

Func _Tree($bh)
	$io = XTree_GetSelectItem($XTree) ;设置选择项目
	If $io = 1 Then btna2($bh);ListView-列表视图
	If $io = 2 Then btna3($bh);ListView1-列表视图
	If $io = 3 Then btna5($bh);ListBox-列表框
	If $io = 5 Then btna4($bh);List-列表
	If $io = 6 Then btnaa($bh);打开子窗口
	If $io = 7 Then btnaa1($bh);打开子窗口
	If $io = 8 Then btnab1($bh);打开子窗口
EndFunc   ;==>_Tree
Func btna2($bh)
	$XListView = XListView_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XListView, "_XListView", $XE_LBUTTONUP) ;注册列表事件
	$XA = XAdapterListView_Create()
	$gr = XAdapterListView_Group_AddColumn($XA, "name3")
	XAdapterListView_Item_AddColumn($XA, "name")
	XAdapterListView_Item_AddColumn($XA, "name2")
	XListView_BindAdapter($XListView, $XA)
	$group = XAdapterListView_Group_AddItemText($XA, "分组1")
	$hImage = XImage_LoadFile("image\炫彩1.jpg", False)
	For $i = 0 To 10
		$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
		$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
	Next
	XWnd_RedrawWnd($create, True)
	TrayTip("", "", 1, 0)
EndFunc   ;==>btna2
Func _XListView($bh)
	TrayTip("小苹果提示", "单击ListView-列表视图条目可弹出修改数据...", 100, 1)
	$ioXListView = XListView_GetSelectItem($XListView)
	MsgBox(48, '提示', $ioXListView[3])
EndFunc   ;==>_XListView

Func btna4($bh)
	$XList = XList_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XList, "_list", $XE_LBUTTONUP) ;注册列表事件,$XE_LBUTTONUP(左键抬起)....没找到单击的事件
	$ggg = XList_SetItemTemplateXML($XList, @ScriptDir & "\List_Item.xml")
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	XList_AddColumn($XList, 100)
	$XAm = XAdapterMap_Create()
	XList_BindAdapterHeader($XList, $XAm)
	XAdapterMap_AddItemText($XAm, "name", "A001")
	XAdapterMap_AddItemText($XAm, "name2", "A002")
	XAdapterMap_AddItemText($XAm, "name3", "A003")
	XAdapterMap_AddItemText($XAm, "name4", "A004")
	XAdapterMap_AddItemText($XAm, "name5", "A005")
	$XA = XAdapterTable_Create()
	XList_BindAdapter($XList, $XA)
	XAdapterTable_AddColumn($XA, "name")
	XAdapterTable_AddColumn($XA, "name2")
	XAdapterTable_AddColumn($XA, "name3")
	XAdapterTable_AddColumn($XA, "name4")
	XAdapterTable_AddColumn($XA, "name5")
	For $i = 0 To 10
		XAdapterTable_AddItemTextEx($XA, "name", "ListBox")
		XAdapterTable_SetItemText($XA, $i, 1, "ListBox-" & $i & "-1")
		XAdapterTable_SetItemText($XA, $i, 2, "ListBox-" & $i & "-2")
		XAdapterTable_SetItemText($XA, $i, 3, "ListBox-" & $i & "-3")
		XAdapterTable_SetItemText($XA, $i, 4, "ListBox-" & $i & "-4")
		XAdapterTable_SetItemText($XA, $i, 5, "ListBox-" & $i & "-5")
	Next
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>btna4
Func _list($bh)
	TrayTip("小苹果提示", "单击List-列表条目可弹出修改数据...", 100, 1)
	$ioa = XAdapterTable_GetItemALLText($XList) ;返回选中项目的所有文本
	MsgBox(48, '提示', $ioa)

EndFunc   ;==>_list
Func btna5($bh)
	$XListBox = XListBox_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XListBox, "_XListb", $XE_LBUTTONUP) ;注册列表事件,
	$XA = XAdapterTable_Create()
	XListBox_BindAdapter($XListBox, $XA)
	XAdapterTable_AddColumn($XA, "name")
	For $i = 1 To 10
		XAdapterTable_AddItemTextEx($XA, "name", "ListBox-" & $i)
	Next
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>btna5
Func _XListb($bh)
	TrayTip("小苹果提示", "单击List-列表视图条目可弹出修改数据...", 100, 1)
	$ioXListBox = XListBox_GetSelectItem($XListBox)
	MsgBox(48, '提示', $ioXListBox)
EndFunc   ;==>_XListb
Func btna3($bh)
	$XListView1 = XListView_Create("225", "40", "560", "400", $create)
	XEle_RegEventC($XListView1, "_XListView1", $XE_LBUTTONUP) ;注册列表事件
	$XA = XAdapterListView_Create()
	$gr = XAdapterListView_Group_AddColumn($XA, "name3")
	XAdapterListView_Item_AddColumn($XA, "name")
	XAdapterListView_Item_AddColumn($XA, "name2")
	XListView_BindAdapter($XListView1, $XA)
	$group = XAdapterListView_Group_AddItemText($XA, "分组2")
	$hImage = XImage_LoadFile("image\line.ico", False)
	For $i = 0 To 10
		$index = XAdapterListView_Item_AddItemImage($XA, $group, $hImage)
		$ttt = XAdapterListView_Item_SetText($XA, $group, $index, 1, "ListView-00" & $i)
	Next
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>btna3
Func _XListView1($bh)
	TrayTip("小苹果提示", "单击ListView-列表视图条目可弹出修改数据...", 100, 1)
	$ioXListView1 = XListView_GetSelectItem($XListView1)
	MsgBox(48, '提示', $ioXListView1[3])
EndFunc   ;==>_XListView1

Func btnaa($bh)
	TrayTip("小苹果提示", "修改密码...", 100, 1)
	$hModal = XModalWnd_Create(400, 280, "dase", XWnd_GetHWND($create), $xc_window_style_modal)
	$str = XShapeText_Create("8", "6", "100", "20", "   修改密码", $hModal)
	$font = XFont_Create2("宋体", "12", True, False, False, False) ;创建字体
	XShapeText_SetFont($str, $font) ;设置XShapeText元素字体
	XShapeText_SetTextColor($str, 0x00ff66, 255) ;设置XShapeText元素颜色
	$text1 = XShapeText_Create("135", "82", "40", "20", "用户名", $hModal)
	$ComboBox1 = XComboBox_Create("175", "80", "135", "20", $hModal)
	$XAA = XAdapterTable_Create()
	XComboBox_BindApapter($ComboBox1, $XAA)
	XAdapterTable_AddColumn($XAA, "name")
	XRichEdit_SetText($ComboBox1, "admin")
	XAdapterTable_AddItemText($XAA, "aaaa")
	XAdapterTable_AddItemText($XAA, "bbbb")
	XAdapterTable_AddItemText($XAA, "cccc")
	$text2 = XShapeText_Create("135", "107", "40", "20", "密码:", $hModal)
	$XRichEdit = XRichEdit_Create("175", "105", "135", "20", $hModal)
	XEle_SetTextColor($XRichEdit, 0x0000ff, 255)
	XRichEdit_SetText($XRichEdit, "123456");
	$btn3 = XBtn_Create("310", "245", "75", "20", "关闭", $hModal)
	XBtn_SetType($btn3, $button_type_close)
	XModalWnd_DoModal($hModal)
EndFunc   ;==>btnaa
Func btnab1($bh)
	TrayTip("小苹果提示", "富文本编辑框...", 100, 1)
	$hModabl = XModalWnd_Create(400, 280, "dase", XWnd_GetHWND($create), $xc_window_style_modal)
	$str = XShapeText_Create("8", "6", "100", "20", "   富文本编辑框", $hModabl)
	$font = XFont_Create2("宋体", "12", True, False, False, False) ;创建字体
	XShapeText_SetFont($str, $font) ;设置XShapeText元素字体
	XShapeText_SetTextColor($str, 0x00ff66, 255) ;设置XShapeText元素颜色
	$XRichEditx = XRichEdit_Create("10", "40", "380", "90", $hModabl)
	$font = XFont_Create2("宋体", "12", True, False, False, False) ;创建字体
	XEle_SetFont($XRichEditx, $font) ;设置XShapeText元素字体
	XEle_SetTextColor($XRichEditx, 0xff0000, 255);设置XShapeText元素颜色
	XRichEdit_SetText($XRichEditx, "输入文本")
	$XRichEditx1 = XRichEdit_Create("10", "140", "380", "90", $hModabl)
	$font = XFont_Create2("宋体", "12", True, False, False, False) ;创建字体
	XEle_SetFont($XRichEditx1, $font) ;设置XShapeText元素字体
	XEle_SetTextColor($XRichEditx1, 0xff0000, 255)
	$read1 = XRichEdit_GetText($XRichEditx, 10, 0)
	XRichEdit_SetText($XRichEditx1, $read1[2])
	$btn3 = XBtn_Create("310", "245", "75", "20", "关闭", $hModabl)
	XBtn_SetType($btn3, $button_type_close)
	XModalWnd_DoModal($hModabl)
EndFunc   ;==>btnab1
Func btnaa1($bh)
	TrayTip("小苹果提示", "动画按钮...", 100, 1)
	$hModa2 = XModalWnd_Create(250, 280, "动画按钮", XWnd_GetHWND($create), $xc_window_style_modal)
	$str = XShapeText_Create("8", "6", "100", "20", "   动画按钮", $hModa2)
	$font = XFont_Create2("宋体", "12", True, False, False, False) ;创建字体
	XShapeText_SetFont($str, $font) ;设置XShapeText元素字体
	XShapeText_SetTextColor($str, 0x00ff66, 255) ;设置XShapeText元素颜色
	$hbtn3 = XBtn_Create("40", "50", "170", "170", "", $hModa2)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s1.png", True), 150) ;添加动画帧
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s2.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s3.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s4.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s5.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s6.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s7.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s8.png", True), 150)
	XBtn_AddAnimationFrame($hbtn3, XImage_LoadFile("image\s9.png", True), 150)
	XBtn_EnableAnimation($hbtn3, True, True) ;开始或关闭图片动画的播放
	$hbtn2 = XBtn_Create("150", "245", "75", "20", "退出程序", $hModa2)
	XBtn_SetType($hbtn2, $button_type_close)
	XEle_RegEventC($hbtn3, "_hbtn3")
	XModalWnd_DoModal($hModa2)
EndFunc   ;==>btnaa1
Func _hbtn3($bh)
	MsgBox(0, "", "你点击了我哦")
EndFunc   ;==>_hbtn3
Func btn2($bh)
	$exit = MsgBox(4, "   退出程序", "是否退出本程序?")
	If $exit = 6 Then xquit_acn($create)
EndFunc   ;==>btn2
