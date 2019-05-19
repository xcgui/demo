#include "Common.h"

class CWindow_Demo
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;

	xcgui::XComboBox m_combobox;
    CWindow_Demo()
    {
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		m_btn.Create(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);

        m_combobox.Create(20,40,120,20,m_Wnd);
        m_combobox.SetItemTemplateXML(L"ComboBox_ListBox_Item.xml");
		m_combobox.SetText(L"123");

		xcgui::XAdTable m_adapter;
        m_combobox.BindApapter(m_adapter);
        m_adapter.AddColumn(L"name");

        wchar_t  buf[256]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
            m_adapter.AddItemText(buf);
        }
		m_Wnd.AdjustLayout();
        m_Wnd.ShowWindow(SW_SHOW);
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
