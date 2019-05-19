#ifndef __LY_MAINDLG_H__
#define __LY_MAINDLG_H__


class CLYMainDlgClass
{
public:
	HWINDOW m_hWindow;
	HELE Btn_Close;

	

	HXCGUI T_RetInfo;

	HELE    m_Edit_Power[14];

	
	/*CLYMainDlgClass()
	{
		Init();
	}*/
	void Init();
	int OnDestroy(BOOL* pbHandled);

	int OnWndOther(WPARAM wParam,LPARAM lParam,BOOL *pbHandled);


	int OnChange_LXTL(BOOL *pbHandled);
	int OnChange_ZT(BOOL *pbHandled);
	int OnChange_3fq(BOOL *pbHandled);
	int OnChange_lxgl(BOOL *pbHandled);
	int OnChange_yckl(BOOL *pbHandled);
	int OnChange_lxsl(BOOL *pbHandled);
	int OnChange_ycsl(BOOL *pbHandled);
	int OnChange_cj(BOOL *pbHandled);
	int OnChange_cq(BOOL *pbHandled);
	int OnChange_dk(BOOL *pbHandled);
	int OnChange_hg(BOOL *pbHandled);
	int OnChange_lb(BOOL *pbHandled);
	int OnChange_ps(BOOL *pbHandled);
	int OnChange_nl(BOOL *pbHandled);
};



#endif