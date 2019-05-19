#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, 320, 520, "窗口测试", 47)

$m_hTree = XTree_Create(20, 40, 280, 450, $create)
XTree_SetItemHeightDefault($m_hTree, 28, 54)

;~ 如果你看完下面的代码, 发现没有xml模板,
;~ 那么name这个字段哪里来的呢？其他例子都是有xml模板的, 只有通过模板
;~ 才能创建出你要的效果，这里看不到，是因为界面库 内置了模板
;~ 所以才有这个name字段, 如果大家不懂, 大家可以看一下其他例子,
;~ 都是通过设计器设计好 这些字段怎么显示的，才能正确的显示大家要的样式

;~ 还有一点, 如果大家要替换分组的样式, 大家可以使用
;~ m_pTemplate_group ＝ XC_LoadTemplate (#XC_TREE, L (“xml-template-test\Tree_Item_group.xml”))
;~ 而这个m_pTemplate_group 在 OnTemplateCreate 子程序中用到。。大家可以自己试试替换

$hAdapter = XAdapterTree_Create()
XTree_BindAdapter($m_hTree, $hAdapter)
XAdapterTree_AddColumn($hAdapter, "name")
For $i = 1 To 5
	$nGroupID = XAdapterTree_InsertItemText($hAdapter, "好友分组-" & $i, $XC_ID_ROOT, $XC_ID_LAST)
	XTree_SetItemHeight($m_hTree, $nGroupID, 26, 26)
	For $o = 1 To 5
		XAdapterTree_InsertItemText($hAdapter, "子项测试", $nGroupID, $XC_ID_LAST)
	Next
Next
XEle_RegEventC($m_hTree, "OnTreeSelect", $XE_TREE_SELECT, "int;bool")
;~ XEle_RegEventC($m_hTree,"OnTemplateCreate",$XE_TREE_TEMP_CREATE,"int;bool")
XEle_RegEventC($m_hTree, "OnTreeDrawItem", $XE_TREE_DRAWITEM, "int;int;bool")
$btn2 = XBtn_Create("240", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func OnTreeDrawItem($hDraw, $pItem, $pbHandled)
	$a = _tree_item_i()
	CopyMemory($a, $pItem)
	$nFirstChild = XTree_GetFirstChildItem($m_hTree, DllStructGetData($a, "nID"))
	If $nFirstChild > $XC_ID_ERROR Then
		If DllStructGetData($a, "nID") = XTree_GetParentItem($m_hTree, $nFirstChild) Then
			Switch DllStructGetData($a, "nState")
				Case $tree_item_state_leave
					XDraw_SetBrushColor($hDraw, 0xff0000, 255)
					XDraw_FillRect($hDraw, DllStructGetPtr($a, "rcItem"))
					pHandle($pbHandled)
				Case $tree_item_state_select
					XDraw_SetBrushColor($hDraw, 0x00ff00, 255)
					XDraw_FillRect($hDraw, DllStructGetPtr($a, "rcItem"))
					pHandle($pbHandled)
				Case $tree_item_state_stay
					XDraw_SetBrushColor($hDraw, 0x0000ff, 255)
					XDraw_FillRect($hDraw, DllStructGetPtr($a, "rcItem"))
					pHandle($pbHandled)
			EndSwitch
		EndIf
	EndIf
	pHandle($pbHandled)
EndFunc   ;==>OnTreeDrawItem

;~ Func OnTemplateCreate($pItem,$pbHandled)
;~ 	$a=_tree_item_i()
;~ 	CopyMemory($a,$pItem)
;~ 	If XTree_GetFirstChildItem($m_hTree, DllStructGetData($a,"nID")) > $XC_ID_ERROR Then
;~ 		If $m_pTemplate_group > 0 Then
;~ 			DllStructSetData($a,"Info",$m_pTemplate_group)
;~ 			CopyMemory($pItem,$a,0,1,0)
;~ 		EndIf
;~ 	EndIf
;~ 	pHandle($pbHandled)
;~ EndFunc

Func OnTreeSelect($nItemID, $pbHandled)
	MsgBox(0, "", "项目 " & $nItemID & " 被选中", -1, XWnd_GetHWND($create))
	pHandle($pbHandled)
EndFunc   ;==>OnTreeSelect

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
