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

    Dim htree As Long
    
    htree = XTree_Create(0, 0, 300, 200, hWindow)
'    Call XTree_SetItemTemplateXML(htree, L("Tree_Item.xml"))
    
    Dim hAdapter As Long
    hAdapter = XAdapterTree_Create()
    Call XTree_BindAdapter(htree, hAdapter)
    
    Call XAdapterTree_AddColumn(hAdapter, L("name"))
    
    Dim nID As Long
    
    nID = XAdapterTree_InsertItemText(hAdapter, L("root-1"), XC_ID_ROOT, XC_ID_LAST)
    
    Call XAdapterTree_InsertItemText(hAdapter, L("root-1-1"), nID, XC_ID_LAST)
    
    nID = XAdapterTree_InsertItemText(hAdapter, L("root-2"), XC_ID_ROOT, XC_ID_LAST)
    
    Call XAdapterTree_InsertItemText(hAdapter, L("root-1-1"), nID, XC_ID_LAST)
    

        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

