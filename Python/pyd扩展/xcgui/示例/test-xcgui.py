print("start")
from xcgui import *

XInitXCGUI("")
hWindow = XWnd_Create(0,0,300,200,"炫彩界面库",0, xc_window_style_default)
hButton = XBtn_Create(100,80,100,30,"关闭",hWindow)
XBtn_SetType(hButton, button_type_close)
XWnd_AdjustLayout(hWindow)
XWnd_ShowWindow(hWindow, SW_SHOW)

title = XBtn_GetText(hButton)
print(title)

XRunXCGUI()
XExitXCGUI()