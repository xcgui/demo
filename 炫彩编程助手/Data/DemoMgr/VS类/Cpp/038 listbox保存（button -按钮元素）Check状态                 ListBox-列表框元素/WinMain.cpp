#include "Common.h"

class CMyWindowListBox
{
public:
	xcgui::XWnd m_wnd;
	xcgui::XListBox m_listBox;
    int     m_iIndex_prev; //先前选中项索引

    CMyWindowListBox()
    {
        m_iIndex_prev=-1;
        Init();
    }
    void Init()
    {
		m_wnd.Create(0, 0, 500, 400, L"炫彩界面库窗口");
		xcgui::XBtn btn(10, 5, 60, 20,L"close",m_wnd);
		btn.SetType(button_type_close);
		
        m_listBox.Create(20,40,300,310,m_wnd);
        m_listBox.SetItemTemplateXML(L"ListBox_Item.xml");
        m_listBox.SetLineSize(20,20);
        m_listBox.EnableMultiSel(FALSE);
			


		xcgui::XAdTable m_adapter;
        m_listBox.BindAdapter(m_adapter);
        m_adapter.AddColumn(L"name");
		m_adapter.AddColumn(L"name1");
		
        wchar_t  buf[256]={0};
        int  index=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"item-%d",i);
            index=m_adapter.AddItemTextEx(L"name",buf);
			m_adapter.SetItemText(index,1,L"测试");
        }
        //项选择事件
        XEle_RegEventCPP(m_listBox,XE_LISTBOX_SELECT,&CMyWindowListBox::OnListBoxSelect);
        //项模板实例化完成事件
        XEle_RegEventCPP(m_listBox,XE_LISTBOX_TEMP_CREATE_END,&CMyWindowListBox::OnListBoxTemplateCreateEnd);
        m_wnd.ShowWindow(SW_SHOW);
    }

    int  OnListBoxTemplateCreateEnd(listBox_item_i* pItem,BOOL *pbHandled)
    {
        //获取模板中(itemID=1)按钮
        xcgui::XBtn btn((HELE)m_listBox.GetTemplateObject(pItem->index,1));
        if(btn.IsHXCGUI(XC_BUTTON))
        {
			
			btn.SetCheck(m_listBox.GetItemData(pItem->index));
            btn.SetText(L"初始化");
            //注册按钮点击事件
            XEle_RegEventCPP1(btn,XE_BUTTON_CHECK,&CMyWindowListBox::OnButtonCheck);
		}

        *pbHandled=TRUE;
        return 0;
    }
	int OnButtonCheck(HELE hEventEle,BOOL bCheck,BOOL *pbHandled)
	{
		int item = m_listBox.GetItemIndexFromHXCGUI(hEventEle);
		m_listBox.SetItemData(item,bCheck);
		return 0;
	}
    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {
        if(m_iIndex_prev>=0)
        {
            //获取模板中(itemID=2)按钮
			xcgui::XBtn btn((HELE)m_listBox.GetTemplateObject(m_iIndex_prev,2));
            if(btn.IsHXCGUI(XC_BUTTON))
                btn.SetText(L"-未选择-");
        }
        m_iIndex_prev=iItem;
        if(iItem>=0)
        {
            //获取模板中(itemID=2)按钮
			xcgui::XBtn btn((HELE)m_listBox.GetTemplateObject(iItem,2));
            if(btn.IsHXCGUI(XC_BUTTON))
                btn.SetText(L"-被选择-");
        }
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowListBox  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
