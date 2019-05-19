;@Ahk2Exe-SetVersion 1.0.0.0

#Include <class_xc>
#NoEnv
#NoTrayIcon
#SingleInstance Force
SetWorkingDir %A_ScriptDir%
SetBatchLines -1

xc.XInitXCGUI()

dir := "res\"
xc.XC_LoadResource(dir "resource.xml", dir) ; 加载资源文件
m_hWindow := xc.XC_LoadLayout(dir "layout.xml") ; 加载布局文件

hSB := xc.XC_GetObjectByID(100)
xc.XSliderBar_SetSpaceTwo(hSB, 25, 15)
xc.XSliderBar_SetButtonWidth(hSB, 74)
xc.XSliderBar_SetButtonHeight(hSB, 63)

hSB_Btn := xc.XSliderBar_GetButton(hSB)
	xc.XEle_EnableBkTransparent(hSB_Btn, True)
	xc.XEle_EnableDrawFocus(hSB_Btn, False)

	; 设置动画帧
	Loop, 5
	{
		hImage := xc.XImage_LoadFile(dir "image\f" A_Index ".png")
		xc.XBtn_AddAnimationFrame(hSB_Btn, hImage, 100)
	}
	xc.XBtn_EnableAnimation(hSB_Btn, True, True)

	xc.XEle_RegEventC2(hSB_Btn, XE_MOUSESTAY:=6, "btn_OnMouseStay")
	xc.XEle_RegEventC2(hSB_Btn, XE_MOUSELEAVE:=8, "btn_OnMouseLeave")

xc.XWnd_AdjustLayout(m_hWindow)
xc.XWnd_ShowWindow(m_hWindow)

xc.XSliderBar_SetPos(hSB, 0)
SetTimer, move_test, -500
xc.XRunXCGUI()
xc.XExitXCGUI()
ExitApp

move_test:
	hGUI := xc.XWnd_GetHWND(m_hWindow)

	global isMoving := True
	xc.XSliderBar_SetPos(hSB, curPos:=14)
	lastPos := 0
	Loop {
		If (curPos > 20)
			Sleep, 30
		Else
			Sleep, 500
		curPos := xc.XSliderBar_GetPos(hSB)
		curPos += 1
		If lastPos && (curPos != lastPos+1)
			curPos += 13
		xc.XSliderBar_SetPos(hSB, curPos)
		xc.XEle_RedrawEle(hSB, True)
		lastPos := curPos
		OutputDebug, % curPos
	} Until (curPos >= 100) || !WinExist("ahk_id " hGUI)

	isMoving := False
	xc.XBtn_EnableAnimation(hSB_Btn, False, False) ; 要先关闭（隐藏）动画才能修改循环播放开关
	xc.XBtn_EnableAnimation(hSB_Btn, True, False)
Return

; 鼠标进入则开始播放动画
btn_OnMouseStay(hEle) {
	If !isMoving
		xc.XBtn_EnableAnimation(hEle, False, False) ; 要先关闭（隐藏）动画才能修改循环播放开关
	,	xc.XBtn_EnableAnimation(hEle, True, True)
}

; 鼠标离开则停止播放动画
btn_OnMouseLeave(hEle) {
	If !isMoving
		xc.XBtn_EnableAnimation(hEle, False, False) ; 要先关闭（隐藏）动画才能修改循环播放开关
	,	xc.XBtn_EnableAnimation(hEle, True, False)
}
