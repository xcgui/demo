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
XList_EnableMultiSel($m_hList, False)
$hAdapterHeader = XAdapterMap_Create()
XList_BindAdapterHeader($m_hList, $hAdapterHeader)
XAdapterMap_AddItemText($hAdapterHeader, "name", "aaa")
$hAdapter = XAdapterTable_Create()
XList_BindAdapter($m_hList, $hAdapter)
XAdapterTable_AddColumn($hAdapter, "name")
XList_SetColumnWidth($m_hList,0,200)

For $i=0 To 19
	XAdapterTable_AddItemTextEx($hAdapter,"name", "Litem-" & $i)
Next

XEle_RegEventC1($m_hList, "OnListTemplateCreateEnd",$XE_LIST_TEMP_CREATE_END ,"int;int")
XEle_RegEventC($m_hList,  "OnRButtonUp",$XE_RBUTTONUP,"int;int")
XWnd_RegEventC($create, "OnWndMenuSelect",$XWM_MENU_SELECT)

$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func OnRButtonUp($nFlags,$pPt)
	Local $n,$m
	$a=_POINT()
	CopyMemory($a,$pPt)
	$hj=XList_HitTest($m_hList,DllStructGetPtr($a),$n,$m)
	If $hj = 0 Then
    $hMenu = XMenu_Create()

    XMenu_AddItem($hMenu, 201, "1", $XC_ID_ROOT, 0)
    XMenu_AddItem($hMenu, 202, "2", $XC_ID_ROOT, 0)
    XMenu_AddItem($hMenu, 203, "3", $XC_ID_ROOT, 0)
	
    XMenu_AddItem($hMenu, 2031, "3-1", 203, 0)
	
	XEle_PointClientToWndClient($m_hList,DllStructGetPtr($a))

    ClientToScreen($create, $a)
	
    XMenu_Popup($hMenu, XWnd_GetHWND($create), DllStructGetData($a,"x"), DllStructGetData($a,"y"), 0, 0)
EndIf
EndFunc

Func OnListTemplateCreateEnd($hEle,$pItem)
	$a=_list_item_i()
	CopyMemory($a,$pItem)
	If DllStructGetData($a,"iSubItem") = 0 Then
		$hBtn = XList_GetTemplateObject($hEle, DllStructGetData($a,"index"), 2)
		If XC_IsHXCGUI($hBtn, $XC_BUTTON) Then
			XEle_RegEventC1($hBtn, "OnButtonCheck", $XE_BUTTON_CHECK,"int;bool")
			$xz=XList_GetItemData($m_hList, DllStructGetData($a,"index"), DllStructGetData($a,"iSubItem"))
			If $xz = 1 Then
				XBtn_SetCheck($hBtn, True)
			EndIf
		EndIf
	EndIf
EndFunc

Func OnButtonCheck($hEventEle,$bCheck)
	$item = XList_GetItemIndexFromHXCGUI($m_hList, $hEventEle)
	XList_SetItemData($m_hList, $item, 0, $bCheck)
EndFunc

Func OnWndMenuSelect($nID)
	MsgBox(0,"","选择的菜单ID为: "&$nID,-1,XWnd_GetHWND($create))
EndFunc
Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2
