#include "Common.h"

class CWindow_Demo
{
public:
    HWINDOW m_hWindow;
	HXCGUI hAdapter;
	HELE hComboBox;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        hComboBox=XComboBox_Create(20,40,120,20,m_hWindow);
        XComboBox_SetItemTemplateXML(hComboBox,L"ComboBox_ListBox_Item.xml");
        XRichEdit_SetText(hComboBox,L"123");

        hAdapter=XAdTable_Create();
        XComboBox_BindAdapter(hComboBox,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
		XAdTable_AddColumn(hAdapter,L"name2");

        wchar_t  buf[256]={0};
        for (int i=0;i<2;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
			int nItem = XAdTable_AddItemImage(hAdapter,XImage_LoadFile(L"1.png",TRUE));
            XAdTable_SetItemText(hAdapter,nItem,1,buf);
        }
		XComboBox_SetDropHeight(hComboBox,500);

		XEle_RegEventCPP(hComboBox,XE_COMBOBOX_SELECT,&CWindow_Demo::OnComboBoxSelect);
		XEle_RegEventCPP(hComboBox,XE_COMBOBOX_POPUP_LIST,&CWindow_Demo::OnComboBoxPopupList);


		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }

	int OnComboBoxSelect(int iItem,BOOL *pbHandled)
	{
		wchar_t buffer[MAX_PATH] = {0};
		XAdTable_GetItemText(hAdapter,iItem,1,buffer,MAX_PATH);
		XRichEdit_SetText(hComboBox,buffer);

		

		return 0;
	}

	int OnWndDrawWindow(HWINDOW hWindow,HDRAW hDraw,BOOL *pbHandled)
	{
		RECT rt;
		::GetWindowRect(XWnd_GetHWND(hWindow),&rt);
		::MoveWindow(XWnd_GetHWND(hWindow),rt.left,rt.top,rt.right-rt.left,1000,FALSE);
		::GetWindowRect(XWnd_GetHWND(hWindow),&rt);
		XWnd_AdjustLayout(hWindow);
		XWnd_AdjustLayoutObject(hWindow);

		return 0;
	}
	int CWindow_Demo::OnComboBoxPopupList(HWINDOW hWindow,HELE hListBox,BOOL *pbHandled)
	{
//		XWnd_RegEventCPP1(hWindow,WM_PAINT,&CWindow_Demo::OnWndDrawWindow);

		int k =  XComboBox_GetDropHeight(hComboBox);
		XEle_EnableBkTransparent(hListBox,TRUE);
		
		XListBox_SetItemHeightDefault(hListBox,32,32);

		RECT rt;
		::GetWindowRect(XWnd_GetHWND(hWindow),&rt);
		::MoveWindow(XWnd_GetHWND(hWindow),rt.left,rt.top,rt.right-rt.left,1000,FALSE);

		XEle_SetRectEx(hListBox,0,0,rt.right-rt.left,1000);
		*pbHandled = TRUE;
		return 0;
	}

};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
