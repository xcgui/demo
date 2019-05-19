Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22



Dim hEdit As Long
Dim hEdit1 As Long

Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function


Public Function OnClick(ByRef bHandle As Long) As Long

    nlen = (XRichEdit_GetTextLength(hEdit) + 1) * 2
 

    Dim buffer() As Byte

    ReDim Preserve buffer(nlen)
    
    Dim stlen As Long
    stlen = XRichEdit_GetText(hEdit, VarPtr(buffer(0)), nlen)

    Dim szData As String
    szData = CStr(buffer)
    
    Call XRichEdit_SetText(hEdit1, L(szData))
    
    
    bHandle = True
    OnClick = 0

End Function

Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

        Dim hWindow As Long
            
        hWindow = XWnd_Create(0, 0, 300, 200, L("ìÅ²ÊVBÀý×Ó"), 0, xc_window_style_default)

        hEdit = XRichEdit_Create(0, 0, 100, 20, hWindow)
        Call XRichEdit_SetText(hEdit, L("www.xcgui.com"))

        hEdit1 = XRichEdit_Create(150, 0, 100, 20, hWindow)

        hBtn = XBtn_Create(8, 30, 100, 20, L("button"), hWindow)
        
        XEle_RegEventC hBtn, XE_BNCLICK, AddressOf OnClick
        
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

