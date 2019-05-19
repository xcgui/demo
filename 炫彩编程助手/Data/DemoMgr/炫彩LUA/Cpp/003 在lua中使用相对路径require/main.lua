--lua和C++不同，require使用相对路径不能简单地使用“./xx/”这样的形式.
--在lua中使用相对路径引用第三方库的方法如下:

package.path = package.path .. ';./XCLIB/?.lua' --注意不要漏掉“；”
require("_const")  --导入常量
require("_xcgui")  --导入函数


local m_hWindow = XWnd_Create(0, 0, 400, 200,"war3helper",0,const.xc_window_style_default);
--显示窗口
XWnd_ShowWindow(m_hWindow,5--[[SW_SHOW]]);

