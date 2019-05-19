//炫彩界面库-UI设计器自动生成文件
#include "stdafx.h"
#include "Pane1.h"

CPane1::CPane1()
{
	m_hPane1=NULL;
}

BOOL CPane1::Init(HWINDOW hWindow)
{
	XC_LoadResource(L"./加载布局面板/resource.xml");
	m_hPane1=(HELE)XC_LoadLayout(L"./加载布局面板/p1.xml",hWindow);


	XEle_RegEventCPP(XC_GetObjectByUID_(ID_Btn1), XE_BNCLICK, &CPane1::OnBtnClick_ID_Btn1);
	XC_EVENT_REGISTER_MARK;


	return TRUE;
}

int  CPane1::OnBtnClick_ID_Btn1(BOOL *pbHandled)
{
	return 0;
}
XC_EVENT_IMPLEMENT_MARK(CPane1);
