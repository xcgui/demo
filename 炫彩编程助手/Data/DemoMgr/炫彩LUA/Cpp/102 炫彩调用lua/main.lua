-- the first program in every language
require("_const")
require("_xcgui")

local hWindow = XWnd_Create(0, 0, 400, 200,"abcìÅ²Ê",0,const.xc_window_style_default);
XWnd_ShowWindow(hWindow,5--[[SW_SHOW]]);