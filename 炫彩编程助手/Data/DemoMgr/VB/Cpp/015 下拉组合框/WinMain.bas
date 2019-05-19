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


    Dim hComboBox As Long
    hComboBox = XComboBox_Create(0, 0, 100, 20, hWindow)
    
    Call XComboBox_SetItemTemplateXML(hComboBox, L("ComboBox_ListBox_Item.xml"))
   
    Dim hAdapte As Long
    hAdapte = XAdapterTable_Create()
    Call XComboBox_BindApapter(hComboBox, hAdapte)
    Call XAdapterTable_AddColumn(hAdapte, L("name"))


    Call XAdapterTable_AddItemText(hAdapte, L("dasemimi"))
    Call XAdapterTable_AddItemText(hAdapte, L("dasemimi2"))
    
    
    Call XComboBox_SetSelItem(hComboBox, 0)


    
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

