Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22



Dim hEdit As Long
Dim hEdit1 As Long

Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function




Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

    Dim hWindow As Long
    hWindow = XWnd_Create(0, 0, 500, 300, L("www.xcgui.com"), _
    0, xc_window_style_default)

    Dim hsview  As Long
    hsview = XSView_Create(0, 0, 200, 200, hWindow)
    
    Call XSView_SetTotalSize(hsview, 1000, 1000)
    
    hBkInfoM = XEle_GetBkInfoManager(hsview)
  
    XBkInfoM_AddFill hBkInfoM, element_state_flag_leave, 255, 255
    
    Call XBtn_Create(0, 0, 100, 100, L("�Ų�"), hsview)
    
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

