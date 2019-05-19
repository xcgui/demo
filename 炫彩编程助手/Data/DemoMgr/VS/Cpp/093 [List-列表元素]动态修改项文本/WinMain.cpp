#include "Common.h"

class CMyWindowList
{
public:
    HWINDOW m_hWindow;
    HELE    m_hList;
	HXCGUI hAdapter;
    CMyWindowList()
    {
        Init();
    }
	int OnBtnClick(BOOL *pbHandled)
	{
		//此种方法，修改数据适配器保存的数据
		XAdTable_SetItemText(hAdapter,0,0,L"修改1");
		XAdTable_SetItemText(hAdapter,0,1,L"修改2");
		XAdTable_SetItemText(hAdapter,0,2,L"修改3");
		XList_RefreshData(m_hList);
		XEle_RedrawEle(m_hList);

		return 0;
	}
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 550, 380, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
		HELE hBtn = XBtn_Create(100,3,200,20,L"动态修改项目文本",m_hWindow);
		XEle_RegEventCPP(hBtn,XE_BNCLICK,&CMyWindowList::OnBtnClick);

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
		
        hAdapter=XAdTable_Create();
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
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowList  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}
