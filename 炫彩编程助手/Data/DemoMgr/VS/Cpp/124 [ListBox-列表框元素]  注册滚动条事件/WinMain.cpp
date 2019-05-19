#include "Common.h"

class CMyWindowListBox
{
public:
    HWINDOW m_hWindow;
    HELE    m_hListBox;
    HELE    m_hRichEidt;
    CMyWindowListBox()
    {
        Init();
    }
	int OnHSBarScroll(int pos,BOOL *pbHandled)
	{
		xtrace("HSBar %d \n",pos);
		return 0;
	}
	int OnVSBarScroll(int pos,BOOL *pbHandled)
	{
		xtrace("VSBar %d \n",pos);
		return 0;
	}
    void Init()

    {
        m_hWindow = XWnd_Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
    
        m_hListBox=XListBox_Create(20,40,300,310,m_hWindow);
        XListBox_SetItemTemplateXML(m_hListBox,L"ListBox_Item.xml");
        XSView_SetLineSize(m_hListBox,20,20);


		HELE hSbarH = XSView_GetScrollBarH(m_hListBox);
		XEle_RegEventCPP(hSbarH,XE_SBAR_SCROLL,&CMyWindowListBox::OnHSBarScroll);
		
		HELE hSbarV = XSView_GetScrollBarV(m_hListBox);
		XEle_RegEventCPP(hSbarV,XE_SBAR_SCROLL,&CMyWindowListBox::OnVSBarScroll);

        HXCGUI hAdapter=XAdTable_Create();
        XListBox_BindAdapter(m_hListBox,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");

        wchar_t  buf[256]={0};
        int  index=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"item-%d",i);
            index=XAdTable_AddItemTextEx(hAdapter,L"name1",buf);
            if(XC_ID_ERROR!=index)
            {
                wsprintfW(buf,L"item-1-%d",i);
                XAdTable_SetItemTextEx(hAdapter,index,L"name2",buf);

                wsprintfW(buf,L"item-2-%d",i);
                XAdTable_SetItemTextEx(hAdapter,index,L"name3",buf);
            }
        }

        HELE hButton1=XBtn_Create(330,40,100,18,L"²åÈëindex=1",m_hWindow);
        XEle_RegEventCPP(hButton1,XE_BNCLICK,&CMyWindowListBox::OnBtnClickAdd);

        HELE hButton2=XBtn_Create(330,62,100,18,L"É¾³ýindex=1",m_hWindow);
        XEle_RegEventCPP(hButton2,XE_BNCLICK,&CMyWindowListBox::OnBtnClickDel);

        HELE hButton3=XBtn_Create(330,84,100,18,L"É¾³ýindex=(2-3)",m_hWindow);
        XEle_RegEventCPP(hButton3,XE_BNCLICK,&CMyWindowListBox::OnBtnClickDelEx);

        m_hRichEidt=XRichEdit_Create(330,106,120,200,m_hWindow);
        XSView_ShowSBarV(m_hRichEidt,TRUE);
        XRichEdit_EnableMultiLine(m_hRichEidt,TRUE);

        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_CREATE,&CMyWindowListBox::OnTemplateCreate);
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_DESTROY,&CMyWindowListBox::OnTemplateDestroy);
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_TEMP_ADJUST_COORDINATE,&CMyWindowListBox::OnTemplateAdjustCoordinate);
        XEle_RegEventCPP(m_hListBox,XE_LISTBOX_SELECT,&CMyWindowListBox::OnListBoxSelect);
        
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int  OnBtnClickAdd(BOOL *pbHandled)
    {
        HXCGUI hAdapter=XListBox_GetAdapter(m_hListBox);
        XAdTable_InsertItemText(hAdapter,1,L"test - insert");
        XEle_RedrawEle(m_hListBox);
        return 0;
    }
    int  OnBtnClickDel(BOOL *pbHandled)
    {
        HXCGUI hAdapter=XListBox_GetAdapter(m_hListBox);
        if(XAdTable_DeleteItem(hAdapter,1))
            XEle_RedrawEle(m_hListBox);
        return 0;
    }
    int  OnBtnClickDelEx(BOOL *pbHandled)
    {
        HXCGUI hAdapter=XListBox_GetAdapter(m_hListBox);
        if(XAdTable_DeleteItemEx(hAdapter,2,2))
            XEle_RedrawEle(m_hListBox);
        return 0;
    }
    int  OnListBoxSelect(int iItem,BOOL *pbHandled)
    {
        XRichEdit_DeleteAll(m_hRichEidt);
        int array_[100]={0};
        int count =XListBox_GetSelectAll(m_hListBox,array_,100);
        wstring  szItemList;
        HXCGUI hAdapter=XListBox_GetAdapter(m_hListBox);
        for (int i=0;i<count;i++)
        {
            szItemList+= XAdTable_GetItemText(hAdapter, array_[i], 0);
            szItemList+=L"\n";
        }
        XRichEdit_SetText(m_hRichEidt,szItemList.c_str());
		XEle_RedrawEle(m_hRichEidt);
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
