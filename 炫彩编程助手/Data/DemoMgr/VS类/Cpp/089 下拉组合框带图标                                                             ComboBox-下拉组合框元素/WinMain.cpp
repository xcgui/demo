#include "Common.h"

class CWindow_Demo
{
public:
	xcgui::XWnd      m_Wnd;
	xcgui::XComboBox m_ComboBox;
	xcgui::XAdTable adapterTable;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
        m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_Wnd),button_type_close);

		m_ComboBox.Create(20,40,120,20,m_Wnd);
        m_ComboBox.SetItemTemplateXML(L"ComboBox_ListBox_Item.xml");
        m_ComboBox.SetText(L"123");

		
        m_ComboBox.BindApapter(adapterTable);

        adapterTable.AddColumn(L"name");
		adapterTable.AddColumn(L"name1");


        wchar_t  buf[256]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
			int nItem = adapterTable.AddItemImage(XImage_LoadFile(L"1.png",TRUE));
            adapterTable.SetItemText(nItem,1,buf);
        }

		XEle_RegEventCPP(m_ComboBox,XE_COMBOBOX_SELECT,&CWindow_Demo::OnComboBoxSelect);

		m_Wnd.AdjustLayout();
		m_Wnd.ShowWindow(SW_SHOW);
    }

	int OnComboBoxSelect(int iItem,BOOL *pbHandled)
	{
		wchar_t buffer[MAX_PATH] = {0};
		adapterTable.GetItemText(iItem,1,buffer,MAX_PATH);
		m_ComboBox.SetText(buffer);
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
