#include "Common.h"

class CMyWindowTree
{
public:
    HWINDOW m_hWindow;
    HELE    m_hTree;
    CMyWindowTree()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(400, 200, 350, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
        
        m_hTree= XTree_Create(20,40,300,300,m_hWindow);
        XTree_SetItemTemplateXML(m_hTree,L"Tree_Item.xml");
		
        HXCGUI hAdapter=XAdTree_Create();
        XTree_BindAdapter(m_hTree,hAdapter);
        XAdTree_AddColumn(hAdapter,L"name1");
        
        wchar_t  buf[256]={0};
        int id=0;
        for (int i=0;i<20;i++)
        {
            wsprintfW(buf,L"name-%d-0",i);
            id=XAdTree_InsertItemText(hAdapter,buf,XC_ID_ROOT,XC_ID_LAST);
        }
        
        int idc1=XAdTree_InsertItemText(hAdapter,L"Item1------1",1,XC_ID_LAST);
        int idc2=XAdTree_InsertItemText(hAdapter,L"Item1------2",1,XC_ID_LAST);
        int idc2_1=XAdTree_InsertItemText(hAdapter,L"Item1-----2--1",idc2,XC_ID_LAST);
        
        XEle_RegEventCPP(m_hTree,XE_TREE_SELECT,&CMyWindowTree::OnTreeSelect);
        XEle_RegEventCPP(m_hTree,XE_TREE_EXPAND,&CMyWindowTree::OnTreeExpand);
		
//        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE,&CMyWindowTree::OnTemplateCreate);
		XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_CREATE_END,&CMyWindowTree::OnTreeTemplateCreateEnd);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_DESTROY,&CMyWindowTree::OnTemplateDestroy);
        XEle_RegEventCPP(m_hTree,XE_TREE_TEMP_ADJUST_COORDINATE,&CMyWindowTree::OnTemplateAdjustCoordinate);
		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnTreeTemplateCreateEnd(tree_item_i* pItem,BOOL *pbHandled)
	{

// 		HXCGUI hShapeText = XTree_GetTemplateObject(m_hTree,pItem->nID,3);
// 		
// 		if (hShapeText)
// 		{
// 			HXCGUI hLayout = pItem->hLayout;
// 			
// 			XLayout_RemoveChild(hLayout,hShapeText);
// 			
// 			HXCGUI hShapeGif = XShapeGif_Create(0,0,30,30,m_hTree);
// 			XLayout_AddShape(hLayout,hShapeGif);
// 			XShapeGif_SetImage(hShapeGif,XImage_LoadFile(L"3.gif"));
// 			
// 			XLayout_AddShape(hLayout,hShapeText);
// 		}

		HXCGUI hShapeText = XTree_GetTemplateObject(m_hTree,pItem->nID,3);
		
		HXCGUI hShapeGif = XShapeGif_Create(0,0,30,30,m_hTree);

		XShapeGif_SetImage(hShapeGif,XImage_LoadFile(L"3.gif"));
		XLayout_Insert(pItem->hLayout,hShapeGif,0);

			


// 		XC_OBJECT_TYPE type = XC_GetObjectType(hShapeGif); 
// 		hShapeGif = XLayout_GetChild(hShapeGif,0);
// 		if (XC_IsHXCGUI(hShapeGif,XC_SHAPE_GIF))
// 		{
// 			return 0;
// 		}
		
		return 0;
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
