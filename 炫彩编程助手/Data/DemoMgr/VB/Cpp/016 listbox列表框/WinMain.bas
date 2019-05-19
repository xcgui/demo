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


    Dim hListBox As Long
    
    hListBox = XListBox_Create(0, 0, 200, 200, hWindow)

    
    Dim hAdapte As Long
    hAdapte = XAdapterTable_Create()
    Call XListBox_BindAdapter(hListBox, hAdapte)
    Call XAdapterTable_AddColumn(hAdapte, L("name"))


    Call XAdapterTable_AddItemText(hAdapte, L("dasemimi"))

    
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

