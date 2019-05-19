Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22


Public Function L(ByVal szSrc As String) As String

Dim szDes As String

 szDes = StrConv(szSrc, vbUnicode)

L = szDes
End Function
Private Function OnEventMenuSelect(ByVal nItem As Long, ByRef pbHandle As Long) As Long

Debug.Print nItem

OnEventMenuSelect = 0
End Function




Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

    Dim hWindow As Long
    hWindow = XWnd_Create(0, 0, 500, 300, L("www.xcgui.com"), _
    0, xc_window_style_default)


    Dim hMenuBar As Long
    hMenuBar = XMenuBar_Create(0, 0, 200, 30, hWindow)
    
    Dim index As Long
    index = XMenuBar_AddButton(hMenuBar, L("dasemimi"))
 '   Call XMenuBar_AddItem(hMenuBar, 0, 100, L("弹出来"), XC_ID_ROOT, 0)

   hMenu = XMenuBar_GetMenu(hMenuBar, index)
   
   XMenu_AddItem hMenu, 100, L("弹出来"), XC_ID_ROOT, 0
   

   XEle_RegEventC hMenuBar, XE_MENU_SELECT, AddressOf OnEventMenuSelect

    
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

