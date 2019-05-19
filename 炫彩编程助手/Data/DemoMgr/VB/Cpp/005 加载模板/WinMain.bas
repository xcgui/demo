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

    Dim szdir As String
    szdir = CurDir() + "\vb"
    
    Dim hWindow As Long
    bOk = XC_LoadResource(L("vb\resource.xml"), L(szdir))
    hWindow = XC_LoadLayout(L("vb\layout.xml"), 0)

     XWnd_AdjustLayout hWindow
     
        
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

