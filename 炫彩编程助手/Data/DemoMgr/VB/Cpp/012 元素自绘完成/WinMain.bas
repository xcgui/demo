Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22



Dim hEdit As Long
Dim hEdit1 As Long

Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function



Public Function OnPaintEnd(ByVal hDraw As Long, ByRef pbHandle As Long) As Long

XDraw_SetBrushColor hDraw, 255, 255
Call XDraw_DrawLine(hDraw, 0, 0, 100, 100)

pbHandle = True
OnPaintEnd = 0
End Function


Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

    Dim hWindow As Long
    hWindow = XWnd_Create(0, 0, 500, 300, L("www.xcgui.com"), _
    0, xc_window_style_default)


    Dim hEle As Long
    hEle = XEle_Create(0, 0, 100, 100, hWindow)
    
    Call XEle_EnableEvent_XE_PAINT_END(hEle, True)
    Call XEle_RegEventC(hEle, XE_PAINT_END, AddressOf OnPaintEnd)
    
    
    Call XBtn_Create(0, 0, 100, 100, L("Ï≈≤ "), hsview)
    
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

