#region ;**** 参数创建于 ACNWrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#AutoIt3Wrapper_UseX64=n
#endregion ;**** 参数创建于 ACNWrapper_GUI ****
#include "XCGUI_Fun.au3"
XInitXCGUI() ;初始化
$create = XWnd_Create("500", "500", "300", "200", "窗口测试", 47) ;建立GUI窗口
$radio1 = XBtn_Create("160", "100", "75", "25", "Test", $create) ;建立按钮
$radio2 = XBtn_Create("60", "100", "75", "25", "Test", $create)
XBtn_SetGroupID($radio1, 1) ;设置按钮分组ID
XBtn_SetGroupID($radio2, 1)
XBtn_SetType($radio1, 2) ;设置按钮类型
XBtn_SetType($radio2, 2)
XBtn_SetStyle($radio1, 2) ;设置按钮样式
XBtn_SetStyle($radio2, 2)
XBtn_SetCheck($radio1, True) ;设置按钮勾选状态
$btn2 = XBtn_Create("100", "140", "75", "25", "退出程序", $create)
XEle_RegEventC($btn2, "btn2") ;注册按钮事件
XWnd_ShowWindow($create) ;显示窗口
XRunXCGUI()
Func btn2($bh) ;按钮事件
	xquit_acn($create)
EndFunc
