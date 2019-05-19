Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22


Public Function L(ByVal szSrc As String) As String

Dim szDes As String

 szDes = StrConv(szSrc, vbUnicode)

L = szDes
End Function



Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

    Dim hWindow As Long
    hWindow = XWnd_Create(0, 0, 500, 300, L("www.xcgui.com"), _
    0, xc_window_style_default)


    Dim hListView As Long
    hListView = XListView_Create(0, 0, 400, 200, hWindow)
    bOk = XListView_SetItemTemplateXML(hListView, L("ListView_Item.xml"))
    
    Dim hAdpte As Long
    hAdpte = XAdapterListView_Create()
    Call XListView_BindAdapter(hListView, hAdpte)
    
    Call XAdapterListView_Group_AddColumn(hAdpte, L("name3"))
    Call XAdapterListView_Item_AddColumn(hAdpte, L("name"))
    Call XAdapterListView_Item_AddColumn(hAdpte, L("name2"))
    
    
    
    Dim nGroup As Long
    nGroup = XAdapterListView_Group_AddItemText(hAdpte, L("分组1"))
    
    Dim hImage As Long
    hImage = XImage_LoadFile(L("2.png"), False)
    
    Dim nItem As Long
    'nItem = XAdapterListView_Item_AddItemImageEx(hAdpte, nGroup, L("name"), hImage)
    nItem = XAdapterListView_Item_AddItemImage(hAdpte, nGroup, hImage)
    Call XAdapterListView_Item_SetText(hAdpte, nGroup, nItem, 1, L("项目易"))
    
    
    
    nGroup = XAdapterListView_Group_AddItemText(hAdpte, L("分组1"))
    nItem = XAdapterListView_Item_AddItemImageEx(hAdpte, nGroup, L("name"), hImage)
    'nItem = XAdapterListView_Item_AddItemImage(hAdpte, nGroup, hImage)
    Call XAdapterListView_Item_SetText(hAdpte, nGroup, nItem, 1, L("项目易"))

        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

