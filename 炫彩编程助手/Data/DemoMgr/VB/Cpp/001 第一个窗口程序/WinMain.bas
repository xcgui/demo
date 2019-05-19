Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22




Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function

Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

        Dim hWindow As Long
            
        hWindow = XWnd_Create(0, 0, 300, 200, L("ìÅ²ÊVBÀý×Ó"), 0, xc_window_style_default)

        XBtn_Create 8, 30, 100, 20, L("button"), hWindow
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

