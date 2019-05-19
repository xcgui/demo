// EEdit.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


#include <vector>
using namespace std;


#define XE_PAINT_PARENT    999

class CAdjustRichEdit
{
public:
	CAdjustRichEdit(HELE hRichEdit)
	{
		m_hEdit = hRichEdit;

		HFONTX hFontX = XEle_GetFont(hRichEdit);

		int nLen = XRichEdit_GetTextLength(hRichEdit);

		wchar_t* pBuffer =new wchar_t[nLen+1];
		XRichEdit_GetText(hRichEdit,pBuffer,nLen);

		SIZE TextSize;

		XC_GetTextShowSize(pBuffer,nLen,hFontX,&TextSize);


		RECT rt;
		XEle_GetRect(hRichEdit,&rt);
		if (TextSize.cx < 100)
		{
			TextSize.cx = 100;
		}
		if (TextSize.cy < 22)
		{
			TextSize.cy = 22;
		}
		rt.right = rt.left + TextSize.cx + 10;
		rt.bottom = rt.top + TextSize.cy;
		XEle_SetRect(hRichEdit,&rt);

		delete [] pBuffer;
		pBuffer = NULL;

	}
private:
	HELE m_hEdit;
	HDC	 m_hDC;
};


int CALLBACK OnEventKeyDown(HELE hEventEle,WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	HELE hParentEle = XEle_GetParentEle(hEventEle);
	XEle_PostEvent(hParentEle,hEventEle,XE_PAINT_PARENT,0,0);
	return 0;
}

class CXEdit
{
public:
	HELE m_hEle;
	CXEdit()
	{
	}
	~CXEdit()
	{
	}
	VOID Create(int x,int y,HXCGUI hParent)
	{
		m_hEle = XRichEdit_Create(x,y,100,22,hParent);
		SetFont(12);
		//默认字体颜色
		//		SetTextColor(RGB(0,128,0));
		SetBkColor();
		XEle_RegEventC1(m_hEle,XE_KEYDOWN,OnEventKeyDown);
	}
	VOID Destory()
	{
//		printf("移除的ele句柄 %x 类句柄 %x\r\n",m_hEle,this);
//		XEle_RemoveEle(m_hEle);
		XEle_Destroy(m_hEle);
		m_hEle = NULL;
	}

	VOID GetRect(RECT* pRect)
	{
		XEle_GetRect(m_hEle,pRect);
	}
	VOID SetRect(RECT* pRect)
	{
		XEle_SetRect(m_hEle,pRect);
	}

	void SetText(const wchar_t* pText)
	{
		XRichEdit_SetText(m_hEle,pText);
	}
	VOID GetText(wchar_t* pBuffer)
	{
		XRichEdit_GetText(m_hEle,pBuffer,MAX_PATH);
	}

//属性接口
public:
	VOID SetFont(int nSize)
	{
		HFONTX hFontx = XFont_Create(nSize);
		XEle_SetFont(m_hEle,hFontx);
	}
	VOID SetTextColor(COLORREF cor=0,BYTE Alpha = 254)
	{
		XEle_SetTextColor(m_hEle,cor,Alpha);
	}
	VOID SetBkColor(COLORREF cor=RGB(230,237,228),BYTE Alpha = 254)
	{
//		XEle_SetBkColor(m_hEle,cor,Alpha);
	}
};

class CTable
{
public:
	int OnEventProc(HELE hEventEle, UINT nEvent, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{
		switch (nEvent)
		{
		case XE_PAINT_PARENT:
			CAdjustRichEdit adjust(hEventEle);
			Adjust();
			XEle_RedrawEle(m_hEle);
			*pbHandled = TRUE;
			break;
		}
		return 0;
	}
	VOID Create(int x,int y,int nRow,int nCol,HXCGUI hParent)
	{
		m_x = x;
		m_y = y;
		m_hEle = XEle_Create(x,y,400,400,hParent);

		XEle_RegEventCPP1(m_hEle,XE_ELEPROCE,&CTable::OnEventProc);

//		XEle_SetBkColor(m_hEle,RGB(128,10,60));
		m_nCol = nCol;
		m_nRow = nRow;

		int nCount = m_nRow*m_nCol;
		for (int i = 0; i < nCount; i++)
		{
			CXEdit edit;
			edit.Create(0,0,m_hEle);
			wchar_t buf[MAX_PATH] = {0};
			wsprintfW(buf,L"%d",i);
			edit.SetText(buf);
			m_EditArry.push_back(edit);
		}

	}
public:

	int InsertItem(int nRow)
	{
		for (int i = 0; i < m_nCol; i++)
		{
			CXEdit edit;
			edit.Create(0,0,m_hEle);
// 			wchar_t buf[MAX_PATH] ={0};
// 			wsprintfW(buf,L"%d",i);
// 			pedit->SetText(buf);
			m_EditArry.insert(m_EditArry.begin()+nRow*m_nCol,edit);
			printf("新插入的句柄%x \r\n",edit.m_hEle);
		}
		return m_nRow++;
	}
	VOID DeleteRow(int nRow)
	{
		vector<CXEdit>::iterator itBegin = m_EditArry.begin()+nRow*m_nCol;
		vector<CXEdit>::iterator itEnd = m_EditArry.begin()+nRow*m_nCol+m_nCol;

		vector<CXEdit>::iterator it = itBegin;
		while(it != itEnd)
		{
			(*it).Destory();
			it++;
		}
		m_EditArry.erase(itBegin,itEnd);
		m_nRow--;
	}

public:
	int GetMaxColWidth(int nCol)
	{
		int nMaxWdith = 0;
		for (int i = 0; i < m_nRow;i++)
		{
			RECT rt;
			m_EditArry[i*m_nCol+nCol].GetRect(&rt);
			if (rt.right - rt.left > nMaxWdith)
			{
				nMaxWdith = rt.right - rt.left;
			}
		}
		return nMaxWdith;
	}
	VOID SetColWidth(int nCol,int nWidth)
	{
		for (int i = 0; i < m_nRow; i++)
		{
			RECT rt;
			m_EditArry[i*m_nCol+nCol].GetRect(&rt);
			rt.right = rt.left+ nWidth;
			m_EditArry[i*m_nCol+nCol].SetRect(&rt);
		}
	}
	VOID show()
	{
		printf("--------------删除后---------------\r\n");
		for (int i = 0; i < m_EditArry.size(); i++)
		{
			printf("类 %x 编辑框句柄 %x \r\n",&m_EditArry[i],m_EditArry[i].m_hEle);
		}
	
	}

	VOID Adjust()
	{
		for (int j = 0; j < m_nCol; j++)
		{
			int nWidth = GetMaxColWidth(j);
			SetColWidth(j,nWidth);
		}

		int nEleWdith = 0;
		int nEleHeigh = 0;

		int nPosX = 0;
		int nPosY = 0;
		for (int i = 0; i < m_nRow; i++)
		{
			
			int nHeightRow = 0;
			int nWdithRow  = 0;
			for (int j = 0; j < m_nCol; j++)
			{
				RECT rt;
				m_EditArry[i*m_nCol+j].GetRect(&rt);
				int nWidth = rt.right - rt.left;
				nHeightRow = rt.bottom - rt.top;
				rt.left = nPosX;
				rt.top  = nPosY;
				rt.right= rt.left + nWidth;
				rt.bottom=rt.top  + nHeightRow;
				m_EditArry[i*m_nCol+j].SetRect(&rt);


// 				wchar_t buffer[MAX_PATH]= {0};
// 				m_EditArry[i*m_nCol+j].GetText(buffer);
// 				OutputDebugStringW(buffer);
// 				OutputDebugStringW(L"\r\n");

				nPosX += nWidth;
 				nWdithRow += nWidth;

			}
			nPosX = 0;
			nPosY += nHeightRow;

			nEleHeigh += nHeightRow;
			nEleWdith = nWdithRow;
		}

		RECT rtEle;
		XEle_GetRect(m_hEle,&rtEle);
		rtEle.right = rtEle.left + nEleWdith;
		rtEle.bottom= rtEle.top  + nEleHeigh;
		XEle_SetRect(m_hEle,&rtEle);
	}
	int GetEleCount()
	{
		return m_EditArry.size();
	}
	CXEdit& GetHEdit(int nIndex)
	{
		return m_EditArry[nIndex];
	}
private:
	int  m_x;
	int  m_y;
	HELE m_hEle;
	int m_nCol;
	int m_nRow;

	vector<CXEdit> m_EditArry;
};

class CWindow
{
public:
	VOID Create(int x,int y,int cx,int cy)
	{
		m_hWindow = XWnd_Create(x,y,cx,cy,L"XCGUI");
		m_hView = XSView_Create(0,30,800,570,m_hWindow);

		m_Table.Create(10,10,10,4,m_hView);
// 
 		m_Table.InsertItem(0);
// 		m_Table.DeleteRow(1);
		int nCount = m_Table.GetEleCount();

		m_Table.show();
		m_Table.Adjust();
		XWnd_ShowWindow(m_hWindow,SW_SHOW);
	}
private:

	int  m_x;
	int  m_y;
	HELE	m_hView;
	HWINDOW m_hWindow;

	CTable  m_Table;
};


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	AllocConsole();                            // 开辟控制台
	SetConsoleTitleW(L"Debug Output");         // 设置控制台窗口标题
	freopen("CONOUT$","w",stdout);             // 重定向输出

	XInitXCGUI();

 	CWindow Wnd;
	Wnd.Create(0,0,800,600);

	XRunXCGUI();
	XExitXCGUI();

	FreeConsole();
	return 0;
}



