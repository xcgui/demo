#include "Common.h"

class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;
	HXCGUI hAdapter;
    CMyWindowTree()
    {
        Init();
    }

	VOID XCTypeFormat(wchar_t*pbuf , XC_OBJECT_TYPE nType)
	{

		switch (nType)
		{
		case XC_ELE:
			wsprintfW(pbuf,L"基础元素 - %d",nType);
			break;
		case XC_BUTTON:
			wsprintfW(pbuf,L"按钮 - %d",nType);
			break;
		case XC_RICHEDIT:
			wsprintfW(pbuf,L"富文本编辑框 - %d",nType);
			break;
		case XC_COMBOBOX:
			wsprintfW(pbuf,L"下拉组合框 - %d",nType);
			break;
		case XC_SCROLLBAR:
			wsprintfW(pbuf,L"滚动条 - %d",nType);
			break;
		case XC_SCROLLVIEW:
			wsprintfW(pbuf,L"滚动视图 - %d",nType);
			break;
		case XC_LIST:
			wsprintfW(pbuf,L"列表 - %d",nType);
			break;
		case XC_LISTBOX:
			wsprintfW(pbuf,L"列表框 - %d",nType);
			break;
		case XC_LISTVIEW:
			wsprintfW(pbuf,L"列表视图 - %d",nType);
			break;
		case XC_TREE:
			wsprintfW(pbuf,L"树元素 - %d",nType);
			break;
		case XC_MENUBAR:
			wsprintfW(pbuf,L"菜单条 - %d",nType);
			break;
		case XC_SLIDERBAR:
			wsprintfW(pbuf,L"滑块条 - %d",nType);
			break;
		case XC_PROGRESSBAR:
			wsprintfW(pbuf,L"进度条 - %d",nType);
			break;
		case XC_TOOLBAR:
			wsprintfW(pbuf,L"工具条 - %d",nType);
			break;
		case XC_MONTHCAL:
			wsprintfW(pbuf,L"月历框 - %d",nType);
			break;
		case XC_DATETIME:
			wsprintfW(pbuf,L"日期框 - %d",nType);
			break;
		case XC_PROPERTYGRID:
			wsprintfW(pbuf,L"属性网格 - %d",nType);
			break;
		case XC_RICHEDIT_COLOR:
			wsprintfW(pbuf,L"编辑框-颜色 - %d",nType);
			break;
		case XC_RICHEDIT_SET:
			wsprintfW(pbuf,L"富文本-Set - %d",nType);
			break;
		case XC_TABBAR:
			wsprintfW(pbuf,L"分页条 - %d",nType);
			break;
		case XC_TEXTLINK:
			wsprintfW(pbuf,L"连接文本 - %d",nType);
			break;
		default:
			wsprintfW(pbuf,L"未知 - %d",nType);
			break;

		}
		
	}

	VOID EnumWindowChildObject(HELE hParent,int nParentID)
	{
		wchar_t buffer[MAX_PATH] = {0};
		XCTypeFormat(buffer,XEle_GetType(hParent));
		int nChildID = XAdTree_InsertItemText(hAdapter,buffer,nParentID,XC_ID_LAST);

		for (int i = 0; i < XEle_GetChildCount(hParent); i++)
		{
			HELE hChild = XEle_GetChildByIndex(hParent,i);
			EnumWindowChildObject(hChild,nChildID);
		}

	}

    void Init()
    {
        m_hWindow = XWnd_Create(400, 200, 350, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
        
        m_hTree = XTree_Create(20,40,300,300,m_hWindow);
        XTree_SetItemTemplateXML(m_hTree,L"Tree_Item.xml");
		
        hAdapter = XAdTree_Create();
        XTree_BindAdapter(m_hTree,hAdapter);
        XAdTree_AddColumn(hAdapter,L"name1");
        

		int idc1=XAdTree_InsertItemText(hAdapter,L"Window",XC_ID_ROOT,XC_ID_LAST);
		for (int i  = 0 ; i < XWnd_GetChildCount(m_hWindow); i++)
		{
			HELE hChildEle = XWnd_GetChildByIndex(m_hWindow,i);
			EnumWindowChildObject(hChildEle,idc1);
		}


        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);
		
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
    int OnTreeSelect(int nItemID,BOOL *pbHandled)
    {
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
        *pbHandled=TRUE;
        return 0;
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowTree  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}
