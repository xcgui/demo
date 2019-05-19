#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI()
$create = XWnd_Create(0, 0, 500, 400, "窗口测试", 47)
$str = XShapeText_Create(80, 80, 20, 25, "滑动试试", $create)
$hSliderBar = XSliderBar_Create(8, 50, 150, 20, $create) ;创建滑动条元素
XSliderBar_SetRange($hSliderBar, 100) ;设置滑动范围
XSliderBar_SetButtonHeight($hSliderBar, 12) ;设置拖动按钮高度
XSliderBar_SetSpaceTwo($hSliderBar, 0, 0) ;设置两端间隔大小
XEle_EnableDrawFocus($hSliderBar, False) ;是否启用绘制焦点

$hEleBkInfoM = XEle_GetBkInfoManager($hSliderBar) ;获取元素背景内容管理器
XBkInfoM_AddFill($hEleBkInfoM, $element_state_flag_leave, 0, 255) ;添加背景内容填充(鼠标离开)

$hBtnSlider = XSliderBar_GetButton($hSliderBar) ;获取滑块按钮
$hBtnBkInfoM = XEle_GetBkInfoManager($hBtnSlider)
XBkInfoM_AddImage($hBtnBkInfoM, $button_state_flag_leave, XImage_LoadFile("滑块.png", False)) ;添加背景内容图片

XSliderBar_SetImageLoad($hSliderBar, XImage_LoadFileAdaptive("未标题-2.png", 0, 8, 0, 8)) ;设置进度贴图
XEle_EnableBkTransparent($hBtnSlider, True) ;启用背景透明

XEle_RegEventC($hSliderBar, "OnSliderBarChange", $XE_SLIDERBAR_CHANGE) ;注册滑动条滑块位置改变事件

$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_ShowWindow($create)
XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

Func OnSliderBarChange($pos)
	XShapeText_SetText($str, $pos)
	XWnd_RedrawWnd($create, True)
EndFunc   ;==>OnSliderBarChange
