-- the first program in every language
require("_const")  --导入常量
require("_xcgui")  --导入函数

local m_hWindow = XWnd_Create(0, 0, 400, 200,"abc炫彩",0,const.xc_window_style_default);

function OnBtnClick( pbHandled )
	hWnd = XWnd_GetHWND(m_hWindow);
	m_hWindowModal = XModalWnd_Create(200, 200, "炫彩界面库窗口",hWnd,const.xc_window_style_modal);
	hBtnClose = XBtn_Create(5, 3, 60, 20, "Close", m_hWindowModal)
	XBtn_SetType(hBtnClose,const.button_type_close);
	nResult=XModalWnd_DoModal(m_hWindowModal);
	return 0;
end
--创建窗口


hBtnClose = XBtn_Create(10, 5, 100, 20,"弹出模态窗口",m_hWindow);
XEle_RegEventC(hBtnClose,const.XE_BNCLICK,OnBtnClick);

--显示窗口
XWnd_ShowWindow(m_hWindow,5--[[SW_SHOW]]);

