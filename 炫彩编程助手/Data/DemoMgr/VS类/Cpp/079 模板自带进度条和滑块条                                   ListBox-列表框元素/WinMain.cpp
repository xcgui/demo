#include "Common.h"

class CMyWindowListBox
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XListBox m_ListBox;
	xcgui::XAdTable m_Adapter;

    CMyWindowListBox()
    {
        Init();
    }
    void Init()
    {
        m_Wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_Wnd),button_type_close);
    
		m_ListBox.Create(20,40,300,310,m_Wnd);
		m_ListBox.SetItemTemplateXML(L"ListBox_Item.xml");
		m_ListBox.SetLineSize(20,20);
		m_ListBox.BindAdapter(m_Adapter);


        m_Adapter.AddColumn(L"name");
        m_Adapter.AddColumn(L"name2");
        m_Adapter.AddColumn(L"name3");
		m_Adapter.AddColumn(L"pos");
		

        wchar_t  buf[256]={0};
        int  index=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"item-%d",i);
            index=m_Adapter.AddItemTextEx(L"name",buf);
            if(XC_ID_ERROR!=index)
            {
                wsprintfW(buf,L"item-1-%d",i);
                m_Adapter.SetItemTextEx(index,L"name2",buf);

                wsprintfW(buf,L"item-2-%d",i);
                m_Adapter.SetItemTextEx(index,L"name3",buf);

				m_Adapter.SetItemTextEx(index,L"pos",L"0");
            }
        }
        XEle_RegEventCPP(m_ListBox,XE_LISTBOX_TEMP_CREATE_END,&CMyWindowListBox::OnListBoxTemplateCreateEnd);
        XEle_RegEventCPP(m_ListBox,XE_LISTBOX_TEMP_DESTROY,&CMyWindowListBox::OnTemplateDestroy);
        XEle_RegEventCPP(m_ListBox,XE_LISTBOX_TEMP_ADJUST_COORDINATE,&CMyWindowListBox::OnTemplateAdjustCoordinate);
        XEle_RegEventCPP(m_ListBox,XE_LISTBOX_SELECT,&CMyWindowListBox::OnListBoxSelect);
        
		srand(GetTickCount());

		m_Wnd.SetTimer(100,100);
		XWnd_RegEventCPP(m_Wnd,WM_TIMER,&CMyWindowListBox::OnWndTimer);

        m_Wnd.ShowWindow(SW_SHOW);
    }
	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{
		int pos = 0;

		for (int i = 0; i < m_Adapter.GetCount(); i++)
		{

			HELE hProgressBar = (HELE)m_ListBox.GetTemplateObject(i,2);
			HELE hSliderBar = (HELE)m_ListBox.GetTemplateObject(i,3);

			wchar_t outBuffer[MAX_PATH] = {0};
			m_Adapter.GetItemTextEx(i,L"pos",outBuffer,MAX_PATH*sizeof(wchar_t));
			int pos = _wtoi(outBuffer);

			pos += rand() % 10;
			if (pos > 100)
			{
				pos = 0;
			}

			wchar_t buffer[MAX_PATH] = {0};
			wsprintfW(buffer,L"%d",pos);
			m_Adapter.SetItemTextEx(i,L"pos",buffer);


			m_Adapter.SetItemText(i,0,buffer);
		}

		m_ListBox.RefreshData();
		m_ListBox.RedrawEle();

		return 0;
	}

    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {

        *pbHandled=TRUE;
        return 0;
    }
    int OnListBoxTemplateCreateEnd(listBox_item_i* pItem,BOOL *pbHandled)
    {
  		wchar_t buffer[MAX_PATH] = {0};
		m_Adapter.GetItemTextEx(pItem->index,L"pos",buffer,MAX_PATH*sizeof(wchar_t));
		int pos = _wtoi(buffer);

		 HXCGUI hProgress = m_ListBox.GetTemplateObject(pItem->index,2);
		 if (XC_IsHXCGUI(hProgress,XC_PROGRESSBAR))
		 {
			 XProgBar_SetRange((HELE)hProgress,100);
			 XProgBar_SetPos((HELE)hProgress,pos);
		 }
		 HXCGUI hSliderBar = m_ListBox.GetTemplateObject(pItem->index,3);
		 if (XC_IsHXCGUI(hSliderBar,XC_SLIDERBAR))
		 {
			 XSliderBar_SetRange((HELE)hSliderBar,100);
			 XSliderBar_SetPos((HELE)hSliderBar,pos);
		 }
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateDestroy(listBox_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateAdjustCoordinate(listBox_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    XC_ShowLayoutFrame(TRUE);
    CMyWindowListBox  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
