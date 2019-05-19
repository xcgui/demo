#include "Common.h"







class CMyWindowList
{
public:
    HWINDOW m_hWindow;
    HELE    m_hList;
    HELE    m_hRichEidt;
    CMyWindowList()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 700, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);

        m_hList= XList_Create(20,40,500,300,m_hWindow);
        XList_SetItemTemplateXML(m_hList,L"List_Item.xml");
        XSView_SetLineSize(m_hList,20,20);

        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);

        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name1",L"aaa");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"bbb");
        XAdMap_AddItemText(hAdapterHeader,L"name3",L"ccc");
        XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");

        HXCGUI hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");

        XList_SetColumnWidth(m_hList,0,150);
        XList_SetColumnWidth(m_hList,1,150);
        XList_SetColumnWidth(m_hList,2,150);

        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
            XAdTable_AddItemText(hAdapter,tmp);

            wsprintfW(tmp,L"child-%d-1",i);  XAdTable_SetItemText(hAdapter,i,1,tmp);
            wsprintfW(tmp,L"child-%d-2",i);  XAdTable_SetItemText(hAdapter,i,2,tmp);
        }

        m_hRichEidt=XRichEdit_Create(525,106,120,200,m_hWindow);
        XSView_ShowSBarV(m_hRichEidt,TRUE);
        XRichEdit_EnableMultiLine(m_hRichEidt,TRUE);

        HELE hButton1=XBtn_Create(525,40,100,18,L"插入index=1",m_hWindow);
        XEle_RegEventCPP(hButton1,XE_BNCLICK,&CMyWindowList::OnBtnClickInsert);

        HELE hButton2=XBtn_Create(525,62,100,18,L"删除index=1",m_hWindow);
        XEle_RegEventCPP(hButton2,XE_BNCLICK,&CMyWindowList::OnBtnClickDel);

        HELE hButton3=XBtn_Create(525,84,100,18,L"全部删除",m_hWindow);
        XEle_RegEventCPP(hButton3,XE_BNCLICK,&CMyWindowList::OnBtnClickDelEx);

        XEle_RegEventCPP(m_hList,XE_LIST_SELECT,&CMyWindowList::OnListSelect);
        XEle_RegEventCPP(m_hList,XE_LIST_TEMP_CREATE,&CMyWindowList::OnTemplateCreate);
        XEle_RegEventCPP(m_hList,XE_LIST_TEMP_DESTROY,&CMyWindowList::OnTemplateDestroy);
        XEle_RegEventCPP(m_hList,XE_LIST_TEMP_ADJUST_COORDINATE,&CMyWindowList::OnTemplateAdjustCoordinate);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int  OnBtnClickInsert(BOOL *pbHandled)
    {
        HXCGUI hAdapter=XList_GetAdapter(m_hList);
        int index=XAdTable_InsertItemText(hAdapter,1,L"test-insert");
        XAdTable_SetItemText(hAdapter,index,1,L"insert");
        XAdTable_SetItemText(hAdapter,index,2,L"insert");
        XEle_RedrawEle(m_hList);
        return 0;
    }
    int  OnBtnClickDel(BOOL *pbHandled)
    {
        HXCGUI hAdapter=XList_GetAdapter(m_hList);
        if(XAdTable_DeleteItem(hAdapter,1))
            XEle_RedrawEle(m_hList);
        return 0;
    }
    int  OnBtnClickDelEx(BOOL *pbHandled)
    {
        HXCGUI hAdapter=XList_GetAdapter(m_hList);
		XAdTable_DeleteItemAll(hAdapter);



        int i = XAdTable_AddItemText(hAdapter,L"1");
		
        XAdTable_SetItemText(hAdapter,i,1,L"2");
        XAdTable_SetItemText(hAdapter,i,2,L"3");



		XEle_RedrawEle(m_hList);
        return 0;
    }
    int  OnListSelect(int iItem,BOOL *pbHandled)
    {
        XTRACE("select item %d \n",iItem);
        XRichEdit_DeleteAll(m_hRichEidt);
        int array_[100]={0};
        int count =XList_GetSelectAll(m_hList,array_,100);
        wstring  szItemList;
        HXCGUI hAdapter=XList_GetAdapter(m_hList);
        for (int i=0;i<count;i++)
        {
             szItemList+=XAdTable_GetItemTextEx(hAdapter,array_[i],L"name1");
             szItemList+=L"\n";
        }
        XRichEdit_SetText(m_hRichEidt,szItemList.c_str());
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateCreate(list_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateDestroy(list_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateAdjustCoordinate(list_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowList  MyWindowt;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
