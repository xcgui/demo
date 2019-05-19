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
    void Init()
    {
		XC_LoadResource(L"listbox\\资源文件\\resource.res",L"listbox\\");
		m_hWindow = (HWINDOW)XC_LoadLayout(L"listbox\\布局文件\\Layout.xml");

    
        m_hListBox=(HELE)XC_GetObjectByName(L"listbox");
        XListBox_SetItemTemplateXML(m_hListBox,L"listbox\\listbox.xml");
        XSView_SetLineSize(m_hListBox,20,20);

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

        XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
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
