//炫彩界面库-UI设计器自动生成文件
#pragma once


#define       ID_Btn1       10 


class CPane1
{
public:
	HELE  m_hPane1;
	CPane1();
	BOOL Init(HWINDOW hWindow);

	XC_LAYOUT_FILE(L"./加载布局面板/p1.xml");
	int  OnBtnClick_ID_Btn1(BOOL *pbHandled);
	XC_EVENT_DECLARE_MARK;
};
