#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"


class XAutoHeightText
{
public:
	void Create(HELE hParent)
	{
		m_MemDc.Create(XEle_GetHWND(hParent));
		m_TextColor= 0;
	}

	int CalcHeight(const wchar_t* lpText,int nCount, int nMaxWidth,HFONT hFont)
	{
		RECT rt;
		rt.left = 0;
		rt.top  = 0;
		rt.right = nMaxWidth;
		rt.bottom = 100;
		m_MemDc.DrawText(lpText,nCount,&rt,DT_WORDBREAK|DT_LEFT|DT_CALCRECT);
		return rt.bottom;
	}
	VOID reSize(int cx,int cy)
	{
		m_MemDc.Resize(cx,cy);
	}
	VOID Draw(HDRAW hDraw,int cx,int cy,const wchar_t* lpText,int nCount, RECT* lpRect)
	{
		m_MemDc.SetTextColor(m_TextColor);
		m_MemDc.FillRect(0,0,cx,cy);
		m_MemDc.DrawText(lpText,nCount,lpRect);
		m_MemDc.BitBlt3(hDraw,cx,cy);
	}
private:
	COLORREF     m_TextColor;
	XGDIMEMDC    m_MemDc;
};



class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;
	HXCGUI  m_hAdapter;
	XAutoHeightText m_AutoText;
    CMyWindowTree()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(400, 200, 350, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
        

	
		


		HXCGUI hLayoutBody = XLayout_Create();
		XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);
		XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
		XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);

        m_hTree= XTree_Create(20,40,300,300,m_hWindow);
		XLayout_AddEle(hLayoutBody,m_hTree);
		XEle_SetLayoutWidth(m_hTree,layout_size_type_fill,1);
		XEle_SetLayoutHeight(m_hTree,layout_size_type_fill,1);


		m_AutoText.Create(m_hTree);
		m_AutoText.reSize(1000,1000);

        XTree_SetItemTemplateXML(m_hTree,L"Tree_Item.xml");
//		XTree_SetItemHeightDefault(m_hTree,150,150);
		XTree_EnableConnectLine(m_hTree,FALSE,FALSE);
		XSView_SetLineSize(m_hTree,20,20);
		
        m_hAdapter=XAdTree_Create();
        XTree_BindAdapter(m_hTree,m_hAdapter);
        XAdTree_AddColumn(m_hAdapter,L"name");
		XAdTree_AddColumn(m_hAdapter,L"name2");
		XAdTree_AddColumn(m_hAdapter,L"name3");
        
        wchar_t  buf[256]={0};
        int id=0;
        for (int i=0;i<1;i++)
        {
			
            wsprintfW(buf,L"12-12",i);
            id=XAdTree_InsertItemText(m_hAdapter,buf,XC_ID_ROOT,XC_ID_LAST);
			XAdTree_SetItemText(m_hAdapter,id,1,L"炫彩界面库--软件界面开发框架,让用户快速开发桌面软件变的简单高效;功能丰富, 小巧,高度DIY自定义满足不同软件UI需求,安全(所有界面元素无句柄),支持Windows平台所有编程语言, Unicode字符编码,提供千余个API接口,完善的帮助文档及技术支持服务;炫彩界面库--软件界面开发框架,让用户快速开发桌面软件变的简单高效;功能丰富, 小巧,高度DIY自定义满足不同软件UI需求,安全(所有界面元素无句柄),支持Windows平台所有编程语言, Unicode字符编码,提供千余个API接口,完善的帮助文档及技术支持服务;");
			XAdTree_SetItemText(m_hAdapter,id,2,L"阅读次数199999");
			
//			XTree_SetItemHeight(m_hTree,id,100,100);
        }

		wsprintfW(buf,L"12-13",i);
		id=XAdTree_InsertItemText(m_hAdapter,buf,XC_ID_ROOT,XC_ID_LAST);
		XAdTree_SetItemText(m_hAdapter,id,1,L"炫彩界面库--软件界Unicode字符编码,提供千余个API接口,完善的帮助文档及技术支持服务;");
		XAdTree_SetItemText(m_hAdapter,id,2,L"阅读次数199999");



        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);		
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
		XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE_END,&CMyWindowTree::OnTreeTemplateCreateEnd);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);
		XEle_RegEventCPP(m_hTree,XE_TREE_DRAWITEM,&CMyWindowTree::OnTreeDrawItem);
		
		XEle_RegEventCPP(m_hTree,XE_SIZE,&CMyWindowTree::OnSize);

		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnSize(BOOL *pbHandled)
	{
		int nTreeWidth = XSView_GetViewWidth(m_hTree);
		HELE hSbar = XSView_GetScrollBarV(m_hTree);
		if (XEle_IsShow(hSbar))
			nTreeWidth -= XEle_GetWidth(hSbar);
		
		int nMaxWidth = nTreeWidth - 45 - 10;
		wchar_t buff[4096] = {0};

		int nID = XTree_GetFirstChildItem(m_hTree,XC_ID_ROOT);
		while (nID != XC_ID_ERROR)
		{
			XAdTree_GetItemTextEx(m_hAdapter,nID,L"name2",buff,4096);
			int nItemHeight = m_AutoText.CalcHeight(buff,wcslen(buff),nMaxWidth,NULL);
			XTree_SetItemHeight(m_hTree,nID,nItemHeight+45,nItemHeight+45);
			nID = XTree_GetNextSiblingItem(m_hTree,nID);
		}
		XTree_RefreshData(m_hTree);
		return 0;
	}
	int OnTreeDrawItem(HDRAW hDraw,tree_item_i* pItem,BOOL *pbHandled)
	{
		*pbHandled = TRUE;
		return 0;
	}
	int OnDraw(HELE hEle,HDRAW hDraw,BOOL *pbHandled)
	{
		int nID = XTree_GetItemIDFromHXCGUI(m_hTree,hEle);
		HELE hEdit =(HELE) XTree_GetTemplateObject(m_hTree,nID,10);
		if (XC_IsHELE(hEdit))
		{
			RECT rt;
			XEle_GetClientRect(hEdit,&rt);
			
			wchar_t buff[4096] = {0};
			XAdTree_GetItemTextEx(m_hAdapter,nID,L"name2",buff,4096);


			m_AutoText.Draw(hDraw,rt.right,rt.bottom,buff,wcslen(buff),&rt);
//			xtrace("-------------------------------%d\r\n",GetTickCount());
		}

		*pbHandled = TRUE;
		return 0;
	}
	
	int OnTreeTemplateCreateEnd(tree_item_i* pItem,BOOL *pbHandled)
	{
		HELE hEdit =(HELE) XTree_GetTemplateObject(m_hTree,pItem->nID,10);
		if (XC_IsHELE(hEdit))
		{
			XEle_RegEventCPP1(hEdit,XE_PAINT,&CMyWindowTree::OnDraw);
		}
		return 0;
	}
    int OnTreeSelect(int nItemID,BOOL *pbHandled)
    {
		XTree_RefreshData(m_hTree);
		XEle_RedrawEle(m_hTree);
        *pbHandled=TRUE;
        return 0;
    }
    int OnTreeExpand(int id,BOOL bExpand,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateCreate(tree_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateDestroy(tree_item_i *pItem,BOOL *pbHandled)
    {
        *pbHandled=TRUE;
        return 0;
    }
    int  OnTemplateAdjustCoordinate(tree_item_i *pItem,BOOL *pbHandled)
    {
        return 0;
    }
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{

    XInitXCGUI();
//	XC_ShowLayoutFrame(TRUE);
    CMyWindowTree  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
