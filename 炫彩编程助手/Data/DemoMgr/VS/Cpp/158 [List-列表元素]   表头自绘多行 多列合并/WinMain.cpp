#include "Common.h"

class CMyWindowList
{
public:
    HWINDOW m_hWindow;
    HELE    m_hList;
    CMyWindowList()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 800, 380, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		
        m_hList= XList_Create(8,30,650,300,m_hWindow);
        XList_SetItemTemplateXML(m_hList,L"List_Item.xml");
        XSView_SetLineSize(m_hList,20,20);
		XList_SetHeaderHeight(m_hList,75);
		
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
		XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
        XList_AddColumn(m_hList,100);
		
        HXCGUI hAdapterHeader=XAdMap_Create();
        XList_BindAdapterHeader(m_hList,hAdapterHeader);
        XAdMap_AddItemText(hAdapterHeader,L"name1",L"aaa");
        XAdMap_AddItemText(hAdapterHeader,L"name2",L"bbb");
        XAdMap_AddItemText(hAdapterHeader,L"name3",L"ccc");
        XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		XAdMap_AddItemText(hAdapterHeader,L"name4",L"test");
		
        HXCGUI hAdapter=XAdTable_Create();
        XList_BindAdapter(m_hList,hAdapter);
        XAdTable_AddColumn(hAdapter,L"name1");
        XAdTable_AddColumn(hAdapter,L"name2");
        XAdTable_AddColumn(hAdapter,L"name3");
		XAdTable_AddColumn(hAdapter,L"name4");
        XAdTable_AddColumn(hAdapter,L"name5");
        XAdTable_AddColumn(hAdapter,L"name6");

        XList_SetColumnWidth(m_hList,0,100);
        XList_SetColumnWidth(m_hList,1,100);
        XList_SetColumnWidth(m_hList,2,100);
		XList_SetColumnWidth(m_hList,3,100);
        XList_SetColumnWidth(m_hList,4,100);
        XList_SetColumnWidth(m_hList,5,100);

        wchar_t tmp[MAX_PATH]={0};
        for (int i=0;i<20;i++)
        {
            wsprintfW(tmp,L"item-%d",i);
            XAdTable_AddItemText(hAdapter,tmp);
			
            wsprintfW(tmp,L"child-%d-1",i);  XAdTable_SetItemText(hAdapter,i,1,tmp);
            wsprintfW(tmp,L"child-%d-2",i);  XAdTable_SetItemText(hAdapter,i,2,tmp);
			wsprintfW(tmp,L"child-%d-3",i);  XAdTable_SetItemText(hAdapter,i,3,tmp);
            wsprintfW(tmp,L"child-%d-4",i);  XAdTable_SetItemText(hAdapter,i,4,tmp);
			wsprintfW(tmp,L"child-%d-5",i);  XAdTable_SetItemText(hAdapter,i,5,tmp);

		}

		HELE hEleHeader = XList_GetHeaderHELE(m_hList);
		XEle_EnableEvent_XE_PAINT_END(hEleHeader,TRUE);
		XEle_RegEventCPP1(hEleHeader,XE_PAINT_END,&CMyWindowList::OnPaintEnd);
		srand(GetTickCount());

		XEle_RegEventCPP(hEleHeader,XE_LIST_HEADER_DRAWITEM,&CMyWindowList::OnListHeaderDrawItem);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnPaintEnd(HELE hEle,HDRAW hDraw,BOOL *pbHandled)
	{
		RECT rt;
		XEle_GetClientRect(hEle,&rt);
		RECT rtUp  = {0,0,rt.right,25};
		RECT rtMid = {0,25,rt.right,50};
		RECT rtDown = {0,50,rt.right,75};
		
		
		XDraw_SetBrushColor(hDraw,RGB(219,12,2));
		XDraw_FillRect(hDraw,&rtUp);
		XDraw_SetBrushColor(hDraw,RGB(144,187,142));
		XDraw_FillRect(hDraw,&rtMid);
		XDraw_SetBrushColor(hDraw,RGB(240,231,140));
		XDraw_FillRect(hDraw,&rtDown);


		RECT rtText1 = {0,0,rt.right,25};
		XDraw_SetTextAlign(hDraw,textAlignFlag_center|textAlignFlag_vcenter);
		XDraw_SetBrushColor(hDraw,RGB(255,255,255));
		XDraw_DrawText(hDraw,L"用户基本信息",6,&rtText1);

		int MidLeftWidth = XList_GetColumnWidth(m_hList,0)+XList_GetColumnWidth(m_hList,1)+XList_GetColumnWidth(m_hList,2);
		RECT rtText2 = {0,25,MidLeftWidth,50};
		XDraw_SetBrushColor(hDraw,0);
		XDraw_DrawText(hDraw,L"基本信息",4,&rtText2);
		RECT rtText3 = {MidLeftWidth,25,rt.right,50};
		XDraw_DrawText(hDraw,L"籍贯信息",4,&rtText3);

		XDraw_SetBrushColor(hDraw,RGB(221,218,201));
		XDraw_DrawLine(hDraw,MidLeftWidth,26,MidLeftWidth,49);



		XDraw_SetTextAlign(hDraw,textAlignFlag_vcenter|textAlignFlag_left);
		XDraw_SetBrushColor(hDraw,0);

		int nLeftWidth = 0;
		int nTempWidth = 0;
		RECT rtText;
		rtText.top = 50;
		rtText.bottom = 75;

		wchar_t* TextArray[] = {L"公司",L"姓名",L"职位",L"住址",L"城市",L"国籍"};
		for (int i = 0; i < 6; i++)
		{
			nTempWidth = XList_GetColumnWidth(m_hList,i);
			rtText.left = nLeftWidth + 10;
			nLeftWidth+= nTempWidth;
			rtText.right = nLeftWidth;

			XDraw_DrawText(hDraw,TextArray[i],wcslen(TextArray[i]),&rtText);
		}


		XDraw_SetBrushColor(hDraw,RGB(221,218,201));
		nLeftWidth = XList_GetColumnWidth(m_hList,0);
		int x1 = nLeftWidth;
		int y1 = 49;
		int x2 = nLeftWidth;
		int y2 = 74;
		for (int j = 1; j < 6; j++)
		{
			XDraw_DrawLine(hDraw,x1,y1,x2,y2);
			nLeftWidth += XList_GetColumnWidth(m_hList,j);
			x1 = x2 = nLeftWidth;
		}


		return 0;
	}
	int OnListHeaderDrawItem(HDRAW hDraw, list_header_item_i* pItem, BOOL *pbHandled)
	{
		


		

		HXCGUI hShapeText1 = XList_GetTemplateObject(m_hList,pItem->index,1);
		HXCGUI hShapeText2 = XList_GetTemplateObject(m_hList,pItem->index,2);
//		HXCGUI hShapeText3 = XList_GetTemplateObject(m_hList,pItem->index,3);
		//竖线1
// 		RECT rtLine1 = {};
// 		XDraw_SetBrushColor(hDraw,RGB(219,221,184));
// 		XDraw_DrawLine(hDraw,)
//		*pbHandled = TRUE;
		return 0;
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
