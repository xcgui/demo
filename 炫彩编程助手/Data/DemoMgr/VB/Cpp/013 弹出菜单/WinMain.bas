Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22


Public Const WM_LBUTTONDOWN As Long = &H201

Declare Function ClientToScreen Lib "User32.dll" (ByVal hWnd As Long, ByRef pPt As Point) As Long


Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function






'int CALLBACK OnWndLButtonDown(UINT flags,POINT *pPt,BOOL *pbHandled);

Public Function OnWndLButtonDown(ByVal hWindow As Long, _
                                  ByVal flags As Long, _
                                  ByRef pPt As Point, _
                                  ByRef pbHandled As Long) As Long

Dim hMenu As Long
hMenu = XMenu_Create()

Dim nItemID As Long
Call XMenu_AddItem(hMenu, 100, L("100"), XC_ID_ROOT, 0)
Call XMenu_AddItem(hMenu, 102, L("101"), 100, 0)
Call XMenu_AddItem(hMenu, 200, L("200"), 100, 0)

Dim pt As Point

pt = pPt

Call ClientToScreen(XWnd_GetHWND(hWindow), pt)


Call XMenu_Popup(hMenu, XWnd_GetHWND(hWindow), pt.x, pt.y, 0, 0)



OnWndLButtonDown = 0
End Function




Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

    Dim hWindow As Long
    hWindow = XWnd_Create(0, 0, 500, 300, L("www.xcgui.com"), _
    0, xc_window_style_default)


    Call XWnd_RegEventC1(hWindow, WM_LBUTTONDOWN, AddressOf OnWndLButtonDown)
    
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

