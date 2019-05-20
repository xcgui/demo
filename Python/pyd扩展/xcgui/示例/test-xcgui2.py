from xcgui import *

XInitXCGUI("")
XPy_Init()

def OnBtnClick(hButton,pbHandled):
	rc={}
	XEle_GetRect(hButton,rc)
	print(rc)
	rc={"left":20, "top":10,"right":180,"bottom":50}
	XEle_SetRect(hButton, rc, False, xc_adjustLayout_no)
	XWnd_RedrawWnd(hWindow , False)

hWindow = XWnd_Create(0,0,300,200,"炫彩界面库",0, xc_window_style_default)
hButton = XBtn_Create(80,60,100,30,"关闭",hWindow)
XBtn_SetType(hButton, button_type_close)

hButton = XBtn_Create(80,110,150,30,"XEle_GetRect()",hWindow)
XEle_RegEvent1(hButton, XE_BNCLICK, OnBtnClick)

XWnd_AdjustLayout(hWindow)
XWnd_ShowWindow(hWindow, SW_SHOW)

XRunXCGUI()
XExitXCGUI()