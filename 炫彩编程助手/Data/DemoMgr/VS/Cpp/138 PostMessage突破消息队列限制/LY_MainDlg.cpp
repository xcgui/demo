#include "Common.h"
#include "LY_MainDlg.h"



HXCGUI CreateTextIDC(int x,int y,int h,int w,wchar_t *idcname,HXCGUI hwnd)
{
	HXCGUI hTextBlock=XShapeText_Create(x,y,h,w ,idcname,hwnd);
	XShapeText_SetLayoutWidth(hTextBlock,layout_size_type_auto,0);
	XShapeText_SetLayoutHeight(hTextBlock,layout_size_type_auto,0);

	return hTextBlock;
}

#define WM_RICHEDIT_SET WM_USER+110

int CLYMainDlgClass::OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	XEle_SendEvent((HELE)wParam,(HELE)wParam,XE_RICHEDIT_CHANGE,NULL,NULL);
	return 0;
}

void CLYMainDlgClass::Init()
{
	int i;
	HXCGUI TXT_Arr[14];
	wchar_t str[14][0x80] = {L"1",L"2",L"3",L"4",L"5",L"6",L"7",L"8",L"9",L"10",L"11",L"12",L"13",L"14"};
	HXCGUI tempHXC;
	XC_RegisterWindowClassName(L"MAIN");
	m_hWindow = XWnd_CreateEx(WS_EX_CLIENTEDGE,L"MAIN",L"CCC",WS_OVERLAPPED|WS_VISIBLE,0,0,350,280,0, xc_window_style_caption|xc_window_style_center);
	//m_hWindow = XWnd_Create(0, 0, 350, 280, L"X-MAN",NULL, xc_window_style_caption|xc_window_style_center);


	XWnd_RegEventCPP(m_hWindow,WM_RICHEDIT_SET,&CLYMainDlgClass::OnWndOther);

	//添加label
	for (i=0;i<14;i++)
	{
		if(i<7)
		{
			tempHXC = CreateTextIDC(20,50+i*20,50,20,str[i],m_hWindow);
			XShapeText_SetTextColor(tempHXC,RGB(0,255,255),255);
			
		}
		else
		{
			tempHXC = CreateTextIDC(180,50+(i-7)*20,50,20,str[i],m_hWindow);
			XShapeText_SetTextColor(tempHXC,RGB(0,255,255),255);
			//修改必须开启
			
		}
		
	}

	//添加编辑框
	for (i=0;i<14;i++)
	{
		if(i<7)
		{
			m_Edit_Power[i]=XRichEdit_Create(90, 50+i*20, 50, 20, m_hWindow);
			XRichEdit_SetTextInt(m_Edit_Power[i],255);
			XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(m_Edit_Power[i],TRUE);
		}
		else
		{
			m_Edit_Power[i] = XRichEdit_Create(250, 50+(i-7)*20, 50, 20, m_hWindow);
			XRichEdit_SetTextInt(m_Edit_Power[i],255);
			XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(m_Edit_Power[i],TRUE);

		}
	}
	//注册修改事件
	XEle_RegEventCPP(m_Edit_Power[0],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_LXTL);
	XEle_RegEventCPP(m_Edit_Power[1],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_ZT);
	XEle_RegEventCPP(m_Edit_Power[2],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_3fq);
	XEle_RegEventCPP(m_Edit_Power[3],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_lxgl);
	XEle_RegEventCPP(m_Edit_Power[4],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_yckl);
	XEle_RegEventCPP(m_Edit_Power[5],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_lxsl);
	XEle_RegEventCPP(m_Edit_Power[6],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_ycsl);
	XEle_RegEventCPP(m_Edit_Power[7],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_cj);
	XEle_RegEventCPP(m_Edit_Power[8],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_cq);
	XEle_RegEventCPP(m_Edit_Power[9],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_dk);
 	XEle_RegEventCPP(m_Edit_Power[10],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_hg);
 	XEle_RegEventCPP(m_Edit_Power[11],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_lb);
 	XEle_RegEventCPP(m_Edit_Power[12],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_ps);
 	XEle_RegEventCPP(m_Edit_Power[13],XE_RICHEDIT_CHANGE,&CLYMainDlgClass::OnChange_nl);
	
	for (i=0;i<14;i++)
	{
		//XRichEdit_SetText(m_Edit_Power[i],L"220");
		//XRichEdit_InsertString(m_Edit_Power[i], L"220");
		//XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(m_Edit_Power[i],TRUE);
		//XRichEdit_SetTextInt(m_Edit_Power[i],220);
		PostMessage(XWnd_GetHWND(m_hWindow),WM_RICHEDIT_SET,(WPARAM)m_Edit_Power[i],NULL);

	}
	
	


	//加载资源图片
	//HIMAGE hImage = XImage_LoadRes(IDB_BG,L"PNG",TRUE);
//	HIMAGE hImage = XImage_LoadFile(L"pic\\bg_hui.png");
//	HBKM hBkInfoM = XWnd_GetBkManager(m_hWindow);

	//给图片上颜色 
//	XBkM_AddImage(hBkInfoM,window_state_whole_leave,hImage);



// 	XWnd_EnableDrawBk(m_hWindow,FALSE);
// 	XWnd_SetTransparentType(m_hWindow,window_transparent_shaped);
// 	XWnd_EnableDragWindow(m_hWindow,TRUE);

	XWnd_ShowWindow(m_hWindow,SW_SHOW);

	


}






int CLYMainDlgClass::OnChange_LXTL(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[0],0);

	return 0;
}


int CLYMainDlgClass::OnChange_ZT(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[1],1);
		return 0;
}


int CLYMainDlgClass::OnChange_3fq(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[2],2);
		return 0;
}




int CLYMainDlgClass::OnChange_lxgl(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[3],3);
		return 0;
}



int CLYMainDlgClass::OnChange_yckl(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[4],4);
		return 0;
}



int CLYMainDlgClass::OnChange_lxsl(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[5],5);
		return 0;
}




int CLYMainDlgClass::OnChange_ycsl(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[6],6);
		return 0;
}





int CLYMainDlgClass::OnChange_cj(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[7],7);
		return 0;
}




int CLYMainDlgClass::OnChange_cq(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[8],8);
		return 0;
}




int CLYMainDlgClass::OnChange_dk(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[9],9);
		return 0;
}




int CLYMainDlgClass::OnChange_hg(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[10],10);
	return 0;
}





int CLYMainDlgClass::OnChange_lb(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[11],11);
	return 0;
}



int CLYMainDlgClass::OnChange_ps(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[12],12);
	return 0;
}


int CLYMainDlgClass::OnChange_nl(BOOL* pbHandled)
{
	XRichEdit_SetTextInt(m_Edit_Power[13],13);
	return 0;
}