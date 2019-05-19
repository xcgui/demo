Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22




Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function


Public Function OnClick(ByRef bHandle As Long) As Long

    MsgBox "大色秘密"
    bHandle = True
    OnClick = 0

End Function

Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

        Dim hWindow As Long
            
        hWindow = XWnd_Create(0, 0, 300, 200, L("炫彩VB例子"), 0, xc_window_style_default)

        hBtn = XBtn_Create(8, 30, 100, 20, L("button"), hWindow)
        
        '设置按钮为 多选框 更多的可以自己看 button_type_开头的
             XBtn_SetType hBtn, button_type_check
        ' 下面这个 是 让外观看起来像普通按钮，大家可以注释掉下面一行点
             XBtn_SetStyle hBtn, button_style_default

        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

