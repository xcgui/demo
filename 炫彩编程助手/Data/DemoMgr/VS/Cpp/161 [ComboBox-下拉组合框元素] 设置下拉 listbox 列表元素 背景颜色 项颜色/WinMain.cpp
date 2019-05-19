#include "Common.h"

class CWindow_Demo
{
public:
    HWINDOW m_hWindow;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);


        HELE hComboBox=XComboBox_Create(20,40,120,20,m_hWindow);
        XComboBox_SetItemTemplateXML(hComboBox,L"ComboBox_ListBox_Item.xml");
        XRichEdit_SetText(hComboBox,L"123");

        HXCGUI hAdapter=XAdTable_Create();
        XComboBox_BindAdapter(hComboBox,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");

        wchar_t  buf[256]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
            XAdTable_AddItemText(hAdapter,buf);
        }

		XEle_RegEventCPP(hComboBox,XE_COMBOBOX_POPUP_LIST,&CWindow_Demo::OnComboBoxPopupList);

		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnComboBoxPopupList(HWINDOW hWindow,HELE hListBox,BOOL *pbHandled)
	{

		XEle_EnableBkTransparent(hListBox,TRUE);

		HBKM hBkInfoM = XEle_GetBkManager(hListBox);
		XBkM_AddFill(hBkInfoM,element_state_flag_enable,0,255);
		XBkM_AddFill(hBkInfoM,listBox_state_flag_item_leave,RGB(0,128,0),255);
		XBkM_AddFill(hBkInfoM,listBox_state_flag_item_stay,RGB(0,0,128),255);


 		XWnd_EnableDrawBk(hWindow,FALSE);
		XWnd_SetTransparentType(hWindow,window_transparent_shadow);
		XWnd_SetTransparentAlpha(hWindow,200);
		XSView_SetScrollBarSize(hListBox,10);
		return 0;
	}
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
