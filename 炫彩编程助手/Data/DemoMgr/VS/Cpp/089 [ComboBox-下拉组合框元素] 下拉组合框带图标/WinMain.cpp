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
		XAdTable_AddColumn(hAdapter,L"name1");


        wchar_t  buf[256]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
			int nItem = XAdTable_AddItemImage(hAdapter,XImage_LoadFile(L"1.png",TRUE));
            XAdTable_SetItemText(hAdapter,nItem,1,buf);
        }

		XEle_RegEventCPP(hComboBox,XE_COMBOBOX_SELECT,&CWindow_Demo::OnComboBoxSelect);

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
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow_Demo  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
