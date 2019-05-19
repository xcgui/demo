#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, "480", "300", "窗口测试", 47)

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

$hBkInfoM = XEle_GetBkInfoManager($hListView)
; 设置组 离开 停留 选中 未选中颜色
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_group_leave, 0xff0000, 255)
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_group_stay, 0x00ff00, 255)
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_group_select, 0x0000ff, 255)
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_group_select_no, 0xffff00, 255)
; 设置项 离开 停留 选中 未选中颜色
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_item_stay, 0xff0000, 255)
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_item_stay, 0x00ff00, 255)
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_item_select, 0x0000ff, 255)
XBkInfoM_AddFill($hBkInfoM, $listView_state_flag_item_select_no, 0xffff00, 255)

$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
