#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"


class XHexEdit
{
public:
	XHexEdit()
	{
		m_hEle = NULL;
	}
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_hEle = XListView_Create(x,y,cx,cy,hParent);
		XListView_SetItemTemplateXML(m_hEle,L"HexEdit_Item.xml");
		
		XListView_SetItemSize(m_hEle,26,16);
		XListView_SetGroupHeight(m_hEle,0);

		m_hAdapter = XAdListView_Create();
		XListView_BindAdapter(m_hEle,m_hAdapter);
		XAdListView_Group_AddColumn(m_hAdapter,L"Null");
		XAdListView_Item_AddColumn(m_hAdapter,L"data");

		int nGroup = XAdListView_Group_AddItemText(m_hAdapter,L"0");
		

		wchar_t buf[3]={0};
		int k  = 0;
		for (int i = 1 ; i < 1000000; i++)
		{
			if ( k == 255)
			{
				k = 0;
			}
			wsprintfW(buf,L"%2.2X",k);
			XAdListView_Item_AddItemText(m_hAdapter,nGroup,buf);
			k++;
		}


		XEle_RegEventCPP(m_hEle,XE_LISTVIEW_TEMP_CREATE_END,&XHexEdit::OnListViewTemplateCreateEnd);

//		XEle_RegEventCPP(hEle,XE_LISTVIEW_DRAWITEM,)

		if (m_hEle)
		{
			m_MemDC.Create(XEle_GetHWND(m_hEle));
			m_MemDC.Resize(40,40);
		}
		return m_hEle;
	}
	int OnListViewTemplateCreateEnd(listView_item_i* pItem,BOOL *pbHandled)
	{
		HELE hEle =(HELE) XListView_GetTemplateObject(m_hEle,pItem->iGroup,pItem->iItem,10);
		if (XC_IsHELE(hEle))
		{
			XEle_RegEventCPP1(hEle,XE_PAINT,&XHexEdit::OnDraw);
		}
		return 0;
	}
	int OnDraw(HELE hEle,HDRAW hDraw,BOOL *pbHandled)
	{
		int nGroup = 0;
		int nItem  = 0;
		if (!XListView_GetItemIDFromHXCGUI(m_hEle,hEle,&nGroup,&nItem))
			return 0;

		m_MemDC.SetDCBrushColor(RGB(255,255,255));
		m_MemDC.FillRect(0,0,40,40);

		wchar_t buf[3];
		XAdListView_Item_GetTextEx(m_hAdapter,nGroup,nItem,L"data",buf,6);

		RECT rt = {0,0,26,16};
		m_MemDC.DrawText(buf,2,&rt,DT_CENTER);
//		m_MemDC.TextOutW(0,0,buf,2);

		m_MemDC.BitBlt_(hDraw);

		return 0;
	}
private:
	HXCGUI m_hAdapter;
	HELE m_hEle;

	XGDIMEMDC m_MemDC;
};



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
	HELE    m_hEle;

	XHexEdit m_Edit;
    BOOL Create() //创建窗口和按钮
    {

        m_hWindow=XWnd_Create(0,0,350,350,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {

			//创建布局，然后绑定布局到窗口顶部区域
			HXCGUI hLayoutTop = XLayout_Create();
			XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutTop);
			
			//第二个参数 设置布局大小为填充父，第三个参数此时没意义
			//第三个参数只有在 第二个参数为 layout_size_type_fixed layout_size_type_weight
			//时有意义
			XLayout_SetLayoutHeight(hLayoutTop,layout_size_type_fill,1);
			XLayout_SetLayoutWidth(hLayoutTop,layout_size_type_fill,1);


			HELE hEdit = m_Edit.Create(0,0,100,100,m_hWindow);
			XLayout_AddEle(hLayoutTop,hEdit);
			XEle_SetLayoutWidth(hEdit,layout_size_type_fill,1);
			XEle_SetLayoutHeight(hEdit,layout_size_type_fill,1);


			XWnd_AdjustLayout(m_hWindow);
            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		XDCDraw XDrawDc(hDraw);
		XDrawDc.SetBrushColor(0);
		XDCGDI XGdiDC(hDraw);
		XGdiDC.SetBrushColor(0,0);
		XDCGDIPlus GdiplusDC(hDraw);
		
		return 0;
	}
	
};


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
	
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
        XRunXCGUI(); //运行
    XExitXCGUI(); //释放资源
    return 0;
}




