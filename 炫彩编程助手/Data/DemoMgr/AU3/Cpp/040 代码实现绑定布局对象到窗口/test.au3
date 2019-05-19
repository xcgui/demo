#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****

#include "XCGUI_Fun.au3"

XInitXCGUI()

$create = XWnd_Create(0, 0, 600, 500, "窗口测试", 47)
$Layout = XLayout_Create() ;创建布局对象
XWnd_BindLayoutObject($create, $window_position_body, $Layout);绑定布局对象到窗口body区域
$btn = XBtn_Create("400", "360", "75", "25", "test", $create)
XLayout_AddEle($Layout, $btn) ;添加元素到布局对象,自动将元素添加到父UI中
XLayout_SetAlignH($Layout, $layout_align_center) ;设置水平对齐方式为居中
XLayout_SetAlignV($Layout, $layout_align_center) ;设置垂直对齐方式为居中
XLayout_SetLayoutWidth($Layout, $layout_size_type_fill, 0) ;设置宽度为填充父
XLayout_SetLayoutHeight($Layout, $layout_size_type_fill, 0) ;设置高度为填充父
;XLayout_ShowLayout($Layout,True)  ;显示布局对象,在调试的时候可以使用此命令,它会显示布局的边界

$btn2 = XBtn_Create("400", "4", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2")
XWnd_AdjustLayout($create)
XWnd_ShowWindow($create)

XRunXCGUI()

Func btn2($bh)
	xquit_acn($create)
EndFunc   ;==>btn2

