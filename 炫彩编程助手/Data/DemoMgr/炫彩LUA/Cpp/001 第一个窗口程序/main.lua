-- the first program in every language
require("_const")  --导入常量
require("_xcgui")  --导入函数


function OnDestroy( pbHandled )
	return 0;
end
--创建窗口
local hWindow = XWnd_Create(0, 0, 400, 200,"abc炫彩",0,const.xc_window_style_default);

hBtnClose = XBtn_Create(10, 5, 60, 20,"close",hWindow);
XBtn_SetType(hBtnClose,const.button_type_close);
XWnd_RegEventC(hWindow,WM_DESTROY,OnDestroy);



--显示窗口
XWnd_ShowWindow(hWindow,5--[[SW_SHOW]]);

