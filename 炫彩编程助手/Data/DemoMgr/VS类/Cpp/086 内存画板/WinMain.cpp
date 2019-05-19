// MyEdit.cpp : Defines the entry point for the application.
//
#include "Common.h"
//#include "stdafx.h"
//#include "TableData.h"

class CTextColor
{
public:
	CTextColor(HDC hDC,COLORREF cor)
	{
		m_hDC = hDC;
		m_Cor = ::SetTextColor(hDC,cor);
	}
	~CTextColor()
	{
		::SetTextColor(m_hDC,m_Cor);
	}
private:
	HDC m_hDC;
	COLORREF m_Cor;
};

class CBrush
{
public:
	CBrush(COLORREF cor)
	{
		m_hBrush = ::CreateSolidBrush(cor);
	}
	~CBrush()
	{
		::DeleteObject(m_hBrush);
	}
	HGDIOBJ GetBrush()
	{
		return m_hBrush;
	}
private:
	HBRUSH m_hBrush;
};


class CSelectObject
{
public:
	CSelectObject(HDC hDC,HGDIOBJ obj)
	{
		m_hDC = hDC;
		m_hOrgObject = SelectObject(m_hDC,obj);
	}
	~CSelectObject()
	{
		SelectObject(m_hDC,m_hOrgObject);
	}
private:
	HDC		m_hDC;
	HGDIOBJ m_hOrgObject;
};


class CMemPad
{
public:
	CMemPad()
	{

	}
	~CMemPad()
	{
		DeleteDC(m_hMemDC);
	}
	VOID Create(HELE hEle)
	{
		HDC hWndDC = ::GetDC(XEle_GetHWND(hEle));
		HBITMAP hBmp = CreateCompatibleBitmap(hWndDC,100,100);
		m_hMemDC = CreateCompatibleDC(NULL);
		SelectObject(m_hMemDC,hBmp);
//		SetBkMode(m_hMemDC,TRANSPARENT);
		ReleaseDC(XEle_GetHWND(hEle),hWndDC);
	}
	VOID DrawLine(CBrush* pBrush,int x1,int y1,int x2,int y2)
	{
		CSelectObject obj(m_hMemDC,pBrush->GetBrush());
		::MoveToEx(m_hMemDC,x1,y1,NULL);
		::LineTo(m_hMemDC,x2,y2);
	}
	VOID DrawText(const wchar_t* lpText,int nLen,int left,int top,int right,int bottom,UINT uFormat)
	{
		RECT rt;
		rt.left = left;
		rt.top  = top;
		rt.right = right;
		rt.bottom = bottom;
		::DrawTextW(m_hMemDC,lpText,nLen,&rt,uFormat);
	}
	VOID TextOut(int x,int y,const wchar_t* lpText,int nSize,COLORREF cor = 0)
	{
		CTextColor TextCor(m_hMemDC,cor);
		::TextOutW(m_hMemDC,x,y,lpText,nSize);
	}
	VOID FillRect(CBrush* pBrush,int x,int y,int cx,int cy)
	{
		RECT rt;
		rt.left = x;
		rt.top  = y;
		rt.right = x+cx;
		rt.bottom= y+cy;
		::FillRect(m_hMemDC,&rt,(HBRUSH)pBrush->GetBrush());
	}
	HDC GetHDC()
	{
		return m_hMemDC;
	}
	
	BOOL Draw(HDRAW hDraw,int cx,int cy)
	{
		return XDraw_BitBlt(hDraw,0,0,cx,cy,m_hMemDC,0,0,SRCCOPY);
	}
private:
	HDC m_hMemDC;
};

CMemPad Mempad;
int CALLBACK OnPaintEnd(HELE hEventEle,HDRAW hDraw,BOOL *pbHandled)
{

	
	Mempad.Draw(hDraw,100,100);

	*pbHandled = TRUE;
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	XInitXCGUI();
	HWINDOW hWindow = XWnd_Create(0,0,400,630,L"±à¼­¿ò");

 	HELE hEle = XEle_Create(10,30,400,600,hWindow);

	XEle_EnableEvent_XE_PAINT_END(hEle,TRUE);
	XEle_RegEventC1(hEle,XE_PAINT_END,OnPaintEnd);

	Mempad.Create(hEle);

	Mempad.TextOut(0,20,L"ìÅ²Ê½çÃæ¿â",5,RGB(0,255,0));

// 	CMyEle myEdit;
// 	myEdit.Create(hEle);

	XWnd_ShowWindow(hWindow,SW_SHOW);
	XRunXCGUI();
	XExitXCGUI();

	return 0;
}



