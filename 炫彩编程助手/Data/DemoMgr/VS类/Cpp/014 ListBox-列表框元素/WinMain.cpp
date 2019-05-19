#include "Common.h"

class CMyWindowListBox
{
public:
	xcgui::XWnd m_wnd;
	xcgui::XListBox m_listBox;
	xcgui::XRichEdit m_richEdit;

    CMyWindowListBox()
    {
        Init();
    }
    void Init()
    {
		m_wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_wnd);
		btn.SetType(button_type_close);

        m_listBox.Create(20,40,300,310,m_wnd);
        m_listBox.SetItemTemplateXML(L"ListBox_Item.xml");
        m_listBox.SetLineSize(20,20);

		xcgui::XAdTable m_adapter;
        m_listBox.BindAdapter(m_adapter);
        m_adapter.AddColumn(L"name");
        m_adapter.AddColumn(L"name2");
        m_adapter.AddColumn(L"name3");

        wchar_t  buf[256]={0};
        int  index=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"item-%d",i);
            index=m_adapter.AddItemTextEx(L"name",buf);
            if(XC_ID_ERROR!=index)
            {
                wsprintfW(buf,L"item-1-%d",i);
                m_adapter.SetItemTextEx(index,L"name2",buf);

                wsprintfW(buf,L"item-2-%d",i);
                m_adapter.SetItemTextEx(index,L"name3",buf);
            }
        }

		xcgui::XBtn btn1,btn2,btn3;

        btn1.Create(330,40,100,18,L"²åÈëindex=1",m_wnd);
        XEle_RegEventCPP(btn1,XE_BNCLICK,&CMyWindowListBox::OnBtnClickAdd);

        btn2.Create(330,62,100,18,L"É¾³ýindex=1",m_wnd);
        XEle_RegEventCPP(btn2,XE_BNCLICK,&CMyWindowListBox::OnBtnClickDel);

        btn3.Create(330,84,100,18,L"É¾³ýindex=(2-3)",m_wnd);
        XEle_RegEventCPP(btn3,XE_BNCLICK,&CMyWindowListBox::OnBtnClickDelEx);

        m_richEdit.Create(330,106,120,200,m_wnd);
        m_richEdit.ShowSBarV(TRUE);
        m_richEdit.EnableMultiLine(TRUE);

        XEle_RegEventCPP(m_listBox,XE_LISTBOX_TEMP_CREATE,&CMyWindowListBox::OnTemplateCreate);
        XEle_RegEventCPP(m_listBox,XE_LISTBOX_TEMP_DESTROY,&CMyWindowListBox::OnTemplateDestroy);
        XEle_RegEventCPP(m_listBox,XE_LISTBOX_TEMP_ADJUST_COORDINATE,&CMyWindowListBox::OnTemplateAdjustCoordinate);
        XEle_RegEventCPP(m_listBox,XE_LISTBOX_SELECT,&CMyWindowListBox::OnListBoxSelect);
        
        m_wnd.ShowWindow(SW_SHOW);
    }
    int  OnBtnClickAdd(BOOL *pbHandled)
    {
		m_listBox.GetAdapter().InsertItemText(1,L"test - insert");
		m_listBox.RedrawEle();

        return 0;
    }
    int  OnBtnClickDel(BOOL *pbHandled)
    {
        if(m_listBox.GetAdapter().DeleteItem(1))
            m_listBox.RedrawEle();
        return 0;
    }
    int  OnBtnClickDelEx(BOOL *pbHandled)
    {

        if(m_listBox.GetAdapter().DeleteItemEx(2,2))
            m_listBox.RedrawEle();
        return 0;
    }
    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {
        m_richEdit.DeleteAll();
        int array_[100]={0};
        int count =m_listBox.GetSelectAll(array_,100);
        wstring  szItemList;
        wchar_t  name[MAX_PATH]={0};
		xcgui::XAdTable adapter =m_listBox.GetAdapter();
        for (int i=0;i<count;i++)
        {
            if(adapter.GetItemText(array_[i],0,name,MAX_PATH))
            {
                szItemList+=name;
                szItemList+=L"\n";
            }
        }
        m_richEdit.SetText(szItemList.c_str());
		m_richEdit.RedrawEle();
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateCreate(listBox_item_i *pItem,BOOL *pbHandled)
    {
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
