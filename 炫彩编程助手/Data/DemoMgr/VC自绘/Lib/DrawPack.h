#ifndef GDIPack_h__
#define GDIPack_h__

// 

#pragma warning(disable:4786)
#include <math.h>
#include <vector>
#include <algorithm>

#define XMakeARGB(cor,alpha)  (cor | (alpha << 24))


//////////////////////////////////////////////////////////////////////////
//数学工具
class XMathTool
{
public:
	//角度转坐标
	VOID AngleToPoint(int x,int y,int cx,int cy,int nAngle,POINT* pPt,BOOL bPercent)
	{
		
		double pi = 3.1415926535;
		int nLeft = x;
		int nTop  = y;
		int nRight = x+cx;
		int nBottom = y+cy;
		
		while (nAngle <0)
			nAngle += 360;
		
		while (nAngle>359)
			nAngle -= 360;
		
		double dAngle = ((double)nAngle)*pi/(double)180;
		
		double r;
		r = ((double)nBottom- nTop)/2.0;
		if (bPercent)
			r = r*3.0/5.0;
		
		double dOffX = (r*sin(dAngle));
		double dOffY = 0.0 - (r*cos(dAngle));
		
		double dX = ((double)(nRight+nLeft))/2.0;
		double dY = ((double)(nTop+nBottom))/2.0;
		
		pPt->x = (int)(dX + dOffX);
		pPt->y = (int)(dY + dOffY);
	}
private:
};

//font////////////////////////////////////////////////////////////////////////

class XGDIFont
{
public:
    XGDIFont()
    {
        m_hFont = NULL;
    }
    ~XGDIFont()
    {
        DestoryFont();
    }
    void DestoryFont()
    {
        if (m_hFont)
        {
            DeleteObject(m_hFont);
            m_hFont = NULL;
        }
    }
    bool CreateFromLogFontW(LOGFONTW& logfont)
    {
        DestoryFont();
        m_hFont = CreateFontIndirectW(&logfont);//字体为宋体
        return m_hFont ? true : false;
    }
    bool CreateFromLogFontW2(const wchar_t* fontName, int fontSize)
    {
        DestoryFont();
        LOGFONTW logfont = { 0 };
        logfont.lfHeight = fontSize;
        logfont.lfWeight = FW_NORMAL;
        wsprintfW(logfont.lfFaceName, L"%s", fontName);
        m_hFont = CreateFontIndirectW(&logfont);//字体为宋体
        return m_hFont ? true : false;
    }
    HFONT m_hFont;
};

class XGDIMemFont
{
public:
    XGDIMemFont()
    {
        m_hFontFile = NULL;
    }
    ~XGDIMemFont()
    {
        DestoryMemFont();
    }
    bool CreateFromMem(void* pBuffer, size_t bufferSize,const wchar_t* fontName,int fontSize)
    {
        DestoryMemFont();
        DWORD dwInsCount = 0;
        m_hFontFile = AddFontMemResourceEx(pBuffer, bufferSize, 0, &dwInsCount);

        if (m_hFontFile == NULL)
        {
            return false;
        }
        return m_GdiFont.CreateFromLogFontW2(fontName, fontSize);;
    }
    void DestoryMemFont()
    {
        if (m_hFontFile)
        {
            RemoveFontMemResourceEx(m_hFontFile);
        }
    }
	HFONT GetHFont()
	{
		return m_GdiFont.m_hFont;
	}

private:
	XGDIFont m_GdiFont;
    HANDLE m_hFontFile;
};

class XGDIFileFont 
{
public:
	XGDIMemFont m_GdiMemFont;

    bool CreateFromFile(wchar_t* pFontFile, const wchar_t* fontName, int fontSize)
    {
        HANDLE hFile = CreateFileW(pFontFile,GENERIC_READ,NULL,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            return false;
        }
        DWORD dwFileSize = GetFileSize(hFile,NULL);
        void* buffer = malloc(dwFileSize);
        DWORD dwByteRead = 0;
        if (!ReadFile(hFile,buffer,dwFileSize,&dwByteRead,NULL))
        {
            free(buffer);
            return false;
        }
        CloseHandle(hFile);

        bool bOk = m_GdiMemFont.CreateFromMem(buffer,dwByteRead,fontName,fontSize);

        free(buffer);

        return bOk;
    }
	HFONT GetHFont()
	{
		return m_GdiMemFont.GetHFont();
	}
};


// class XGDIBrush
// {
// public:
//     void CreateSolidBrush(COLORREF cor)
//     {
//         m_hBrush = ::CreateSolidBrush(cor);
//     }
// private:
//     HBRUSH  m_hBrush;
// };


class XCaret
{
public:
    VOID Create(HELE hEle,int nWdith = 1,int nHeight = 12)
    {
        m_width = nWdith;
        m_height = nHeight;
        m_hWindow = XEle_GetHWINDOW(hEle);
        XWnd_CreateCaret(m_hWindow,hEle,0,0,nWdith,nHeight);
    }
	VOID SetColor(COLORREF cor)
	{
		XWnd_SetCaretColor(m_hWindow,cor);
	}
    VOID SetPos(int x,int y)
    {
        XWnd_SetCaretPos(m_hWindow,x,y);
    }
    VOID Show(BOOL bShow)
    {
		m_bCaretShow = bShow;
        XWnd_ShowCaret(m_hWindow,bShow);
    }
	BOOL IsCaretShow()
	{
		return m_bCaretShow;
	}
    void SetHeight(int height)
    {
        m_height = height;
        XWnd_SetCaretSize(m_hWindow, m_width, m_height);
    }

private:
    int m_width;
    int m_height;
    HWINDOW m_hWindow;
	BOOL m_bCaretShow;
};


//////////////////////////////////////////////////////////////////////////

class XGDI
{
public:
    XGDI()
    {
    }
	int GetTextWidth(const wchar_t* lpText,int len)
    {
        SIZE textSize;
        GetTextExtentPoint32W(m_hDC,lpText,len,&textSize);
        return textSize.cx;
    }
    int GetTextHeight(const wchar_t* lpText,int len)
    {
        SIZE textSize;
        GetTextExtentPoint32W(m_hDC,lpText,len,&textSize);
        return textSize.cy;
    }
    BOOL GetTextSize(const wchar_t* lpText,int len,SIZE* pSize)
    {
        return GetTextExtentPoint32W(m_hDC,lpText,len,pSize);
    }
//////////////////////////////////////////////////////////////////////////
	HGDIOBJ GetStockObject(int obj)
	{
		return ::GetStockObject(obj);
	}
    HGDIOBJ SelectObject(HGDIOBJ hGdiObj)
    {
        return ::SelectObject(m_hDC,hGdiObj);
    }
    void SetDCBrushColor(COLORREF cor)
    {
        ::SetDCBrushColor(m_hDC,cor);
    }
    void SetDCPenColor(COLORREF cor)
    {
        ::SetDCPenColor(m_hDC,cor);
    }
    COLORREF SetTextColor(COLORREF cor)
    {
        return ::SetTextColor(m_hDC,cor);
    }
	COLORREF SetBkColor(COLORREF cor)
	{
		return ::SetBkColor(m_hDC,cor);
	}
    void FillRect(RECT *lprc,HBRUSH hbr)
    {
        ::FillRect(m_hDC,lprc,hbr);
    }
	void Pie_(int nLeft,int nTop,int nRight,int nBottom,int nX1,int nY1,int nX2,int nY2)
	{
		::Pie(m_hDC,nLeft,nTop,nRight,nBottom,nX1,nY1,nX2,nY2);
	}
	void Pie(int x,int y,int cx,int cy,POINT* pt1,POINT* pt2)
	{
		Pie_(x,y,x+cx,y+cy,pt1->x,pt1->y,pt2->x,pt2->y);
	}
    void FillRect(RECT *lprc)
    {
        ::FillRect(m_hDC,lprc,(HBRUSH)GetStockObject(DC_BRUSH));
    }
    void FillRect(int x,int y,int cx,int cy)
    {
		RECT rt = {x,y,x+cx,y+cy};
        ::FillRect(m_hDC,&rt,(HBRUSH)GetStockObject(DC_BRUSH));
    }
    void Rectangle(int left,int top,int right,int bottom)
    {
        ::Rectangle(m_hDC,left,top,right,bottom);
    }
	void DrawRect1(RECT* pRt)
	{
		DrawRect(pRt->left,pRt->top,pRt->right,pRt->bottom);
	}
    void DrawRect(int x1,int y1,int x2,int y2)
    {
        DrawLine(x1,y1,x2,y1);  //上
        DrawLine(x1,y2,x2,y2);  //下
        DrawLine(x1,y1,x1,y2);  //左
        DrawLine(x2,y1,x2,y2);  //右
    }
	void Polyline(POINT* ptArray,int nPtArraySize)
	{
		::Polyline(m_hDC,ptArray,nPtArraySize);
	}
    void DrawLine(int x1, int y1, int x2, int y2)
    {
        ::MoveToEx(m_hDC,x1,y1,NULL);
        ::LineTo(m_hDC,x2,y2);
    }
    void TextOutW(int x, int y, const wchar_t* pText, int len)
    {
        ::TextOutW(m_hDC, x , y, pText, len);
    }
	void TextOutA(int x, int y, const char* pText, int len)
    {
        ::TextOutA(m_hDC, x , y, pText, len);
    }
	VOID DrawText(const wchar_t* lpText,int nCount,RECT* lpRect,UINT uFormat = DT_LEFT|DT_WORDBREAK)
	{
		::DrawTextW(m_hDC,lpText,nCount,lpRect,uFormat);
	}
    //可以设置TextOutW_输出文本时是透明的，没有背景
    //TRANSPARENT
    void SetBkMode(int mode)
    {
        ::SetBkMode(m_hDC,mode);
    }
	void DrawPolygon(CONST POINT *pArray,int nArraySize)
	{
		::Polygon(m_hDC,pArray,nArraySize);
	}
	void FillPolygon(CONST POINT *pArray,int nArraySize)
	{
		
		HBRUSH hBrush = CreateSolidBrush(GetDCBrushColor(m_hDC));
		HRGN hRgn = ::CreatePolygonRgn(pArray,nArraySize,ALTERNATE);
		::FillRgn(m_hDC,hRgn,hBrush);
		DeleteObject(hBrush);
		DeleteObject(hRgn);
	}
public:
    HDC m_hDC;
};

class XDCGDI : public XGDI
{
public:
	XDCGDI(HDRAW hDraw)
	{
		Create(hDraw);
	}
	void Create(HDRAW hDraw)
	{
		m_PenColor = 0;
		m_hDC = XDraw_GetHDC(hDraw);
		SelectObject(GetStockObject(DC_BRUSH));
		SelectObject(GetStockObject(DC_PEN));
		
	}
	void SetBrushColor(COLORREF cor,BYTE alpha)
	{
		m_PenColor = 0;
		SetDCBrushColor(cor);
		SetDCPenColor(cor);
	}
	void DottedLine(int x1, int y1, int x2, int y2)
	{
		HPEN m_hPenDot = ::CreatePen(PS_DOT,1,GetDCBrushColor(m_hDC));
		HGDIOBJ hOldObject = SelectObject(m_hPenDot);
		DrawLine(x1,y1,x2,y2);
		SelectObject(hOldObject);
		DeleteObject(m_hPenDot);
	}
private:
	COLORREF m_PenColor;
	
};

class XGDIWndDC
{
public:
    XGDIWndDC()
    {
        m_hWndDC = NULL;
    }
	XGDIWndDC(HWND hWnd)
	{
        m_hWnd = hWnd;
        m_hWndDC = ::GetDC(m_hWnd);
	}
    ~XGDIWndDC()
    {
        Destroy();
    }
    void Create(HWND hWnd)
    {
        Destroy();
        m_hWnd = hWnd;
        m_hWndDC = ::GetDC(m_hWnd);
    }
	HDC GetDC()
	{
		return m_hWndDC;
	}
    void Destroy()
    {
        if (m_hWndDC != NULL)
        {
            ::ReleaseDC(m_hWnd,m_hWndDC);
            m_hWndDC = NULL;
        }
    }
public:
    HDC m_hWndDC;
    HWND m_hWnd;
};

class XGDIMEMDC : public XGDI
{
public:
    XGDIMEMDC()
    {
		m_hMemDC = NULL;
        m_memBmp = NULL;
		m_nWidth = 0;
		m_nHeight = 0;
		
    }
    ~XGDIMEMDC()
    {
        Destory();
    }
    void Create(HWND hWnd)
    {
		Destory();
		m_WndDC.Create(hWnd);
        m_hMemDC = CreateCompatibleDC(m_WndDC.GetDC());
		m_hDC = m_hMemDC;
    }
	void Resize(int cx,int cy)
	{
		if (m_nWidth == cx && m_nHeight == cy)
			return ;

		if (cx < m_nWidth && cy < m_nHeight)
			return ;

		m_nWidth  = cx;
		m_nHeight = cy;

        HBITMAP hBitMap = CreateCompatibleBitmap(m_WndDC.GetDC(),m_nWidth,m_nHeight);
        SelectObject(hBitMap);
		
        if (m_memBmp)
            DeleteObject(m_memBmp);
		
		m_memBmp = hBitMap;
	}
	BOOL BitBlt(
		HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,
		int nHeight,int nXSrc, int nYSrc, DWORD dwRop)
	{
		return XDraw_BitBlt(hDrawDest,nXDest,nYDest,nWidth,nHeight,m_hDC,nXSrc,nYSrc,dwRop);
	}
	BOOL BitBlt1(HDRAW hDrawDest)
	{
		return XDraw_BitBlt(hDrawDest,0,0,m_nWidth,m_nHeight,m_hDC,0,0,SRCCOPY);
	}
	BOOL BitBlt3_(HDRAW hDrawDest,int x,int y)
	{
		return XDraw_BitBlt(hDrawDest,x,y,m_nWidth,m_nHeight,m_hDC,0,0,SRCCOPY);
	}
	BOOL BitBlt3(HDRAW hDrawDest,int cx,int cy)
	{
		return XDraw_BitBlt(hDrawDest,0,0,cx,cy,m_hDC,0,0,SRCCOPY);
	}
	int GetBitMapWidth()
	{
		return m_nWidth;
	}
	int GetBitMapHeight()
	{
		return m_nHeight;
	}
private:
    void Destory()
    {
		if (m_hMemDC)
		{
			DeleteObject(m_hMemDC);
			m_hMemDC = NULL;
		}
        if (m_memBmp)
        {
            DeleteObject(m_memBmp);
            m_memBmp = NULL;
        }
    }
private:
	
	XGDIWndDC m_WndDC;

	HDC     m_hMemDC;
    HBITMAP m_memBmp;
	int m_nWidth;
	int m_nHeight;
};



class XImageP
{
public:
	void LoadFile(const wchar_t* lpImageFile)
	{
		m_pImage = new Gdiplus::Image(lpImageFile);
	}
	Gdiplus::Image* m_pImage;
};


class XDCGDIPlus
{
public:
	XDCGDIPlus()
	{
		Init();
	}
	~XDCGDIPlus()
	{
		UnInit();
	}
	XDCGDIPlus(HDRAW hDraw)
	{
		Init();
		CreateFromHDRAW(hDraw);
	}
	XDCGDIPlus(HDC hDC)
	{
		Init();
		CreateFromHDC(hDC);
	}
	void CreateFromHDRAW(HDRAW hDraw)
	{
		CreateFromHDC(XDraw_GetHDC(hDraw)); 
	}
	void CreateFromHDC(HDC hDC)
	{
		UnInit();
		m_pGraphic = new Gdiplus::Graphics(hDC);
		m_pFont = new Font(hDC);
		m_pBrush = new SolidBrush(Color(255,0,0,0));
		m_pPen   = new Pen(m_pBrush);

	}
	void DrawLine(int x1,int y1,int x2,int y2)
	{
		m_pGraphic->DrawLine(m_pPen,x1,y1,x2,y2);
	}

	void DrawCurve(Point* ptArray,int ptArraySize)
	{
		m_pGraphic->DrawCurve(m_pPen,ptArray,ptArraySize);
	}

	void DrawPie(int x,int y,int cx,int cy,float nStart,float nEnd)
	{
		m_pGraphic->DrawPie(m_pPen,x,y,cx,cy,nStart,nEnd);
	}
	void FillPie(int x,int y,int cx,int cy,float nStart,float nEnd)
	{
		m_pGraphic->FillPie(m_pBrush,x,y,cx,cy,nStart,nEnd);
	}
	void SetSmoothingMode(SmoothingMode smoothingMode)
	{
		m_pGraphic->SetSmoothingMode(smoothingMode);
	}

	void DrawPolygon(POINT* ptArray,int nArraySize)
	{
		m_pGraphic->DrawPolygon(m_pPen,(Point*)ptArray,nArraySize);
	}
	void FillPolygon(POINT* ptArray,int nArraySize)
	{
		m_pGraphic->FillPolygon(m_pBrush,(Point*)ptArray,nArraySize);
	}
	VOID TextOutW(int x,int y,const wchar_t* lpText,int nLen)
	{
		PointF pf(x,y);
		m_pGraphic->DrawString(lpText,nLen,m_pFont,pf,m_pBrush);
	}

	VOID SetBrushColor(COLORREF cor,BYTE alpha)
	{
		Color acor(XMakeARGB(cor,alpha));
		m_pPen->SetColor(acor);
		m_pBrush->SetColor(acor);
	}
	VOID SetPenWidth(float penWidth)
	{
		m_pPen->SetWidth(penWidth);
	}
	float GetPenWidth()
	{
		return m_pPen->GetWidth();
	}
	VOID Polyline(POINT* ptArray,int nPtArraySize)
	{
		m_pGraphic->DrawLines(m_pPen,(Point*)ptArray,nPtArraySize);
	}
	VOID DrawArc(int x,int y,int cx,int cy,float startAngle,float sweepAngle)
	{
		m_pGraphic->DrawArc(m_pPen,x,y,cx,cy,startAngle,sweepAngle);
	}
	VOID DrawEllipse(int x,int y,int cx,int cy)
	{
		m_pGraphic->DrawEllipse(m_pPen,x,y,cx,cy);
	}

	void DottedLine(int x1, int y1, int x2, int y2)
	{
		m_pPen->SetDashStyle(DashStyleDot);
		m_pGraphic->DrawLine(m_pPen,x1,y1,x2,y2);
		m_pPen->SetDashStyle(DashStyleSolid);		
	}

	void DrawEllipsePic(int x,int y,int cx,int cy,XImageP* pImage)
	{
		TextureBrush imageBrush(pImage->m_pImage);
		imageBrush.TranslateTransform(x,y);

		GraphicsPath path;
		path.AddEllipse(x,y,cx,cy);

		m_pGraphic->FillPath(&imageBrush,&path);
	}

	//画正6边型
	VOID DrawRegularHexagon(int x,int y,int cx,int cy)
	{
		XMathTool math;

		GraphicsPath path;
		
		POINT pt;
		PointF ptf[6] ;
		for (int i = 0; i < 6; i++)
		{
			math.AngleToPoint(x,y,cx,cy,i*60,&pt,FALSE);
			ptf[i].X = pt.x;
			ptf[i].Y = pt.y;
		}
		path.AddPolygon(ptf,6);

		m_pGraphic->DrawPath(m_pPen,&path);

	}
	//填充正6边型
	VOID FillRegularHexagon(int x,int y,int cx,int cy)
	{
		XMathTool math;
		
		GraphicsPath path;
		
		POINT pt;
		PointF ptf[6] ;
		for (int i = 0; i < 6; i++)
		{
			math.AngleToPoint(x,y,cx,cy,i*60,&pt,FALSE);
			ptf[i].X = pt.x;
			ptf[i].Y = pt.y;
		}
		path.AddPolygon(ptf,6);
				
		m_pGraphic->FillPath(m_pBrush,&path);
	}

private:
	void Init()
	{
		m_pGraphic = NULL;
		m_pFont    = NULL;
		m_pBrush   = NULL;
		m_pPen     = NULL;
	}
	void UnInit()
	{
		if (m_pGraphic)
		{
			delete m_pGraphic;
			m_pGraphic = NULL;
		}
		if (m_pFont)
		{
			delete m_pFont;
			m_pFont = NULL;
		}
		if (m_pBrush)
		{
			delete m_pBrush;
			m_pBrush = NULL;
		}
		if (m_pPen)
		{
			delete m_pPen;
			m_pPen = NULL;
		}
	}

private:
	Gdiplus::Graphics* m_pGraphic;

	Font* m_pFont;
	SolidBrush* m_pBrush;
	Pen*   m_pPen;
};

// class XRegularHexagon
// {
// public:
// 	int Create(int x,int y,int cx,int cy)
// 	{
// 
// 	}
// protected:
// private:
// };



class XDCDraw
{
public:
    XDCDraw(HDRAW hDraw)
    {
        m_hDraw = hDraw;
        m_hDC = XDraw_GetHDC(m_hDraw);
    }
	void GetOffset(int* px,int * py)
	{
		XDraw_GetOffset(m_hDraw,px,py);
	}
    void SetFont(HFONTX hFontx)
    {
        XDraw_SetFontX(m_hDraw,hFontx);
    }
    void TextOutW(int x,int y,const wchar_t* lpText,int nLen)
    {
        XDraw_TextOut(m_hDraw,x,y,lpText,nLen);
    }
    void DrawText(const wchar_t * lpString, int nCount, RECT* lpRect)
    {
        XDraw_DrawText(m_hDraw,lpString,nCount,lpRect);
    }
    void SetTextAlign(int nFlag)
    {
        XDraw_SetTextAlign(m_hDraw,nFlag);
    }
    void SetBrushColor(COLORREF cor,byte alpha = 255)
    {
        XDraw_SetBrushColor(m_hDraw,cor,alpha);
    }
    void SetLineWidth(int nWidth)
    {
        XDraw_SetLineWidth(m_hDraw,nWidth);
    }
    void DrawRect(int x1,int y1,int x2,int y2)
    {
        DrawLine(x1,y1,x2,y1);  //上
        DrawLine(x1,y2,x2,y2);  //下
        DrawLine(x1,y1,x1,y2);  //左
        DrawLine(x2,y1,x2,y2);  //右
    }
	void Polyline(in_ POINT *pArrayPt, int arrayPtSize)
	{
		XDraw_Polyline(m_hDraw,pArrayPt,arrayPtSize);
	}
    void Rectangle(int x1,int y1,int x2,int y2)
    {
        XDraw_Rectangle(m_hDraw,x1,y1,x2,y2);
    }
    void DrawLine(int x1, int y1, int x2, int y2)
    {
        XDraw_DrawLine(m_hDraw,x1,y1,x2,y2);
    }
    void MoveTo(POINT& pt)
    {
        XDraw_MoveToEx(m_hDraw,pt.x,pt.y);
    }
    void LineTo(POINT& pt)
    {
        XDraw_LineTo(m_hDraw,pt.x,pt.y);
    }
    void FillRect(RECT* pRect)
    {
        XDraw_FillRect(m_hDraw,pRect);
    }
	void FillRectEx(int x1,int y1,int x2,int y2)
    {
        RECT rt = {x1,y1,x2,y2};
        XDraw_FillRect(m_hDraw,&rt);
    }
    void FillRectColor(RECT* pRect,COLORREF cor)
    {
        XDraw_FillRectColor(m_hDraw,pRect,cor);
    }
	void DrawRoundRect(int x,int y,int cx,int cy,int nRoundWidth,int nRoundHeight)
	{
		RECT rt = {x,y,x+cx,y+cy};
		XDraw_DrawRoundRect(m_hDraw,&rt,nRoundWidth,nRoundHeight);
	}
	void FillRoundRect(int x,int y,int cx,int cy,int nRoundWidth,int nRoundHeight)
	{
		RECT rt = {x,y,x+cx,y+cy};
		XDraw_FillRoundRect(m_hDraw,&rt,nRoundWidth,nRoundHeight);
	}
	void DrawPolygon(POINT* pArray,int nArraySize)
	{
		XDraw_DrawPolygon(m_hDraw,pArray,nArraySize);
	}
	void FillPolygon(POINT* pArray,int nArraySize)
	{
		XDraw_FillPolygon(m_hDraw,pArray,nArraySize);
	}
	void DottedLine(int x1, int y1, int x2, int y2)
	{
		XDraw_Dottedline(m_hDraw,x1,y1,x2,y2);
	}

	void FillEllipse(RECT* pRect)
	{
		XDraw_FillEllipse(m_hDraw,pRect);
	}
	void DrawEllipse(RECT* pRect)
	{
		XDraw_DrawEllipse(m_hDraw,pRect);
	}
public:
    HDC   m_hDC;
    HDRAW m_hDraw;
};

//绘图数据/////////////////////////////////////////////////////////////

// class XDataBase
// {
// public:
// 
// protected:
// 	int m_x;
// 	int m_y;
// 	int m_cx;
// 	int m_cy;
// };




enum Triangle_Direction_
{
	Triangle_Direction_Left,
	Triangle_Direction_Top,
	Triangle_Direction_Right,
	Triangle_Direction_Bottom,
	Triangle_Direction_Error=-1,
};

//形状 三角形
template <typename T>
class XTDCTriangle
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XTDCTriangle()
	{
		m_LineColor = 0;
		m_LineAlpha = 255;

		m_IsDrawFill = TRUE;
		m_IsDrawLine = TRUE;
		m_Direction  = Triangle_Direction_Error;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void SetDirection(Triangle_Direction_ direction)
	{
		m_Direction = direction;
		switch (direction)
		{
		case Triangle_Direction_Left:
			{
				m_ptArray[0].x = m_x;
				m_ptArray[0].y = m_y+m_cy/2;

				m_ptArray[1].x = m_x+m_cx;
				m_ptArray[1].y = m_y;

				m_ptArray[2].x = m_x+m_cx;
				m_ptArray[3].y = m_y+m_cy;
			}
			break;
		case Triangle_Direction_Top:
			{
				m_ptArray[0].x = m_x;
				m_ptArray[0].y = m_y+m_cy;
				
				m_ptArray[1].x = m_x+m_cx;
				m_ptArray[1].y = m_y+m_cy;
				
				m_ptArray[2].x = m_x+m_cx/2;
				m_ptArray[2].y = m_y;
			}
			break;
		case Triangle_Direction_Right:
			{
				
				m_ptArray[0].x = m_x;
				m_ptArray[0].y = m_y;
				
				m_ptArray[1].x = m_x;
				m_ptArray[1].y = m_y+m_cy;
				
				m_ptArray[2].x = m_x+m_cx;
				m_ptArray[2].y = m_y+m_cy/2;
			}
			break;
		case Triangle_Direction_Bottom:
			{
				
				m_ptArray[0].x = m_x;
				m_ptArray[0].y = m_y;
				
				m_ptArray[1].x = m_x+m_cx;
				m_ptArray[1].y = m_y;
				
				m_ptArray[2].x = m_x+m_cx/2;
				m_ptArray[2].y = m_y+m_y;
			}
			break;
		}
	}
	void SetDrawLine(BOOL bDrawLine)
	{
		m_IsDrawLine = bDrawLine;
	}
	void SetDrawFill(BOOL bDrawFill)
	{
		m_IsDrawFill = bDrawFill;
	}




void Draw(T* pDrawTool)
{
	if (m_IsDrawLine)
	{
		pDrawTool->SetBrushColor(m_LineColor,m_LineAlpha);
		pDrawTool->DrawPolygon(m_ptArray,3);
	}
	if (m_IsDrawFill)
	{
		pDrawTool->SetBrushColor(m_FillColor,m_FillAlpha);
		pDrawTool->FillPolygon(m_ptArray,3);
	}
}
private:
	
	COLORREF m_LineColor;
	BYTE     m_LineAlpha;
	
	COLORREF m_FillColor;
	BYTE     m_FillAlpha;
protected:
	BOOL m_IsDrawFill;
	BOOL m_IsDrawLine;
	Triangle_Direction_ m_Direction;
	POINT  m_ptArray[3];
};


//直线
template <typename T>
class XTDCLine
{
public:
	VOID Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	virtual void Draw(T* pDrawDC)
	{
		pDrawDC->DrawLine(m_x,m_y,m_x+m_cx,m_y+m_cy);
    }
	void SetRect(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
protected:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
};


template < typename T>
class XTDCDottedline : public XTDCLine<T>
{
public:
    virtual void Draw(T* pDrawDC)
    {
		pDrawDC->DottedLine(m_x,m_y,m_x+m_cx,m_y+m_cy);
    }
private:
};



//等距水平数组

template <typename T>
class XTDCDataLineArrayHorizon 
{
public:
	XTDCDataLineArrayHorizon()
	{
		m_Space = 0;
		m_LineCount = 2;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}

	void SetLineCount(int nCount)
	{
		m_LineCount = nCount;
		m_Space = m_cy / (m_LineCount-1);
	}
	void GetLine(int nIndex,int& x1,int& y1,int& x2,int& y2)
	{
		x1 = m_x;
		y1 = m_y + nIndex*m_Space;
		x2 = m_x + m_cx;
		y2 = y1;
	}

	void Draw(T* pDrawTool)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		for (int i = 0; i < m_LineCount; i++)
		{
			GetLine(i,x1,y1,x2,y2);
			pDrawTool->DrawLine(x1,y1,x2,y2);
		}
	}
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;

	int  m_LineCount;
	int  m_Space;
	int  m_LineOffsetIndex;  //第一个线条的偏移
};


//等距垂直线条数组
class XDataLineArrayVertical
{
protected:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XDataLineArrayVertical()
	{
		m_Space = 0;
		m_LineCount = 2;
	}
	void SetLineCount(int nCount)
	{
		m_LineCount = nCount;
		m_Space = m_cx / (m_LineCount-1);
	}
	void GetLine(int nIndex,int& x1,int& y1,int& x2,int& y2)
	{
		x1 = m_x+m_Space*nIndex;
		y1 = m_y;
		x2 = x1;
		y2 = m_y + m_cy;
	}
protected:
	int  m_LineCount;
	int  m_Space;
};

template <typename T>
class XTDCDataLineArrayVertical : public XDataLineArrayVertical
{
public:
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void Draw(T* pDrawTool)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		for (int i = 0; i < m_LineCount; i++)
		{
			GetLine(i,x1,y1,x2,y2);
			pDrawTool->DrawLine(x1,y1,x2,y2);
		}
	}
};

///////////////////////////////////////////////////////////////
//	类    名 : XGraphEquidistantTableEx
//	基    类 : 
//	描    述 : 等距表格，代码简单易懂
//	功    能 : 
//	历史记录 : 
//	使用说明 : 
//	作    者 : dasemimi
//	时    间 : 2016年6月24日
//	备    注 : 
///////////////////////////////////////////////////////////////
template <typename T>
class XTDCEquidistantTableEx
{
public:
	void Create(int x,int y,int cx,int cy)
	{
		m_lineH.Create(x,y,cx,cy);
		m_lineV.Create(x,y,cx,cy);
		m_lineV.SetHorizon(FALSE);
	}
	void SetRowCount(int nHangCount)
	{
		m_lineH.SetLineCount(nHangCount+1);
	}
	void SetColCount(int nLieCount)
	{
		m_lineV.SetLineCount(nLieCount+1);
	}
	void Draw(T* pDrawDc)
	{
		m_lineH.Draw(pDrawDc);
		m_lineV.Draw(pDrawDc);
	}
private:
	XTDCDataLineArrayHorizon<T> m_lineH;
    XTDCDataLineArrayVertical<T> m_lineV;
};



///////////////////////////////////////////////////////////////
//	类    名 : XGraphEquidistantTable
//	基    类 : 
//	描    述 : 等距表格 效率略高一点点
//	功    能 : 
//	历史记录 : 
//	使用说明 : 
//	作    者 : dasemimi
//	时    间 : 2016年6月24日
//	备    注 : 
///////////////////////////////////////////////////////////////
template <typename T>
class XTDCEquidistantTable
{
public:
	XTDCEquidistantTable()
	{
		m_LineColor = 0;
		m_alpha     = 255;
	}
    void Create(int x,int y,int cx,int cy)
    {
        m_lineH.Create(x,y,cx,cy);
        m_lineV.Create(x,y,cx,cy);
        m_lineV.SetHorizon(FALSE);
    }
	VOID SetColumnCount(int nColCount)
	{
		m_VLineCount = nColCount + 1;
		m_lineV.SetLineCount(m_VLineCount);
	}
	VOID SetRowCount(int nRowCount)
	{
		m_HLineCount = nRowCount + 1;
		m_lineH.SetLineCount(m_HLineCount);
	}
    void Draw(XDCDraw* pDrawDc)
    {
		pDrawDc->SetBrushColor(m_LineColor,m_alpha);
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		if (m_IsHLineVisible)
		{
			for (int i = 0; i < m_HLineCount; i++)
			{
				m_lineH.GetLine(i,x1,y1,x2,y2);
				pDrawDc->DrawLine(x1,y1,x2,y2);
			}
			
		}
		if (m_IsVLineVisible)
		{
			for (int i = 0; i < m_HLineCount; i++)
			{
				m_lineV.GetLine(i,x1,y1,x2,y2);
				pDrawDc->DrawLine(x1,y1,x2,y2);
			}
		}
    }
private:
	int   m_HLineCount;
	int   m_VLineCount;

	bool  m_IsHLineVisible;
	bool  m_IsVLineVisible;
    XTDCDataLineArrayHorizon<T> m_lineH;
    XTDCDataLineArrayVertical<T> m_lineV;

	COLORREF  m_LineColor;
	BYTE      m_alpha;
};


class XDrawTextRect
{
public:
	XDrawTextRect()
	{
		m_CorText = 0;
		m_AlphaText = 255;
		m_IsFill = false;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_Rect.left = x;
		m_Rect.top  = y;
		m_Rect.right = x + cx;
		m_Rect.bottom= y + cy;
	}
	void SetTextColor(COLORREF cor,byte alpha)
    {
        m_CorText = cor;
		m_AlphaText = alpha;
    }
	void SetText(const wchar_t* pText)
	{
		m_text = pText;
	}
	void Draw(XDCDraw* pDrawDC)
	{
		if (m_IsFill)
		{
			pDrawDC->SetBrushColor(m_CorFill,m_AlphaFill);
			pDrawDC->FillRect(&m_Rect);
		}
        pDrawDC->SetBrushColor(m_CorText,m_AlphaText);
		pDrawDC->DrawText(m_text.c_str(),m_text.length(),&m_Rect);
	}
private:
	RECT m_Rect;
	std::wstring m_text;
    COLORREF m_CorText;
	byte     m_AlphaText;
	
	bool     m_IsFill;
	COLORREF m_CorFill;
	byte     m_AlphaFill;
};


class XDrawTextColor
{
public:
	XDrawTextColor()
	{
		m_Cor = 0;
		m_TextAlpha = 255;
	}
    void Create(int x,int y,const wchar_t* pText)
    {
        m_x = x;
        m_y = y;
        m_text = pText;
    }
    void SetTextColor(COLORREF cor)
    {
        m_Cor = cor;
    }
    void Draw(XDCDraw* pDrawDC)
    {
        pDrawDC->SetBrushColor(m_Cor,m_TextAlpha);
        pDrawDC->TextOutW(m_x,m_y,m_text.c_str(),m_text.length());
    }
protected:
    std::wstring m_text;
    COLORREF m_Cor;
	BYTE     m_TextAlpha;
    int m_x;
    int m_y;
};


class XDrawTextMultiEx
{
public:
    XDrawTextMultiEx()
    {
        m_nFlag = DT_WORDBREAK | DT_CENTER;
    }
    void Create(int x,int y,int cx,int cy,const wchar_t* pText)
    {
		m_rt.left = x;
		m_rt.top  = y;
		m_rt.right = x+cx;
		m_rt.bottom = y+cy;
        m_text = pText;
    }
    void SetAlign(int nFlag = DT_WORDBREAK|DT_CENTER)
    {
        m_nFlag = nFlag;
    }
    void Draw(XDCDraw* pDrawDC)
    {
        pDrawDC->SetTextAlign(m_nFlag);
        pDrawDC->DrawText(m_text.c_str(),m_text.length(),&m_rt);
    }
private:
	std::wstring m_text;
	RECT m_rt;
    int m_nFlag;
    int m_cx;
    int m_cy;
};
class XGDITextMulti
{
public:
    void Create(int x,int y,int cx,int cy,const wchar_t* pText)
    {
        m_x = x;
        m_y = y;
        m_cx = cx;
        m_cy = cy;
        m_text = pText;
    }
    void Draw(XGDI* pTextMesure)
    {
        int x = 0;
        int y = 0;

        wchar_t ch = L'\r';
        size_t Index = 0;
        size_t i = Index;
        for (; i <= m_text.size(); i++)
        {
            if (m_text.c_str()[i] == L'\r' && m_text.c_str()[i+1] == L'\n')
            {
                pTextMesure->TextOutW(m_x,m_y+y,m_text.c_str()+Index,i- Index);
                y = y+ pTextMesure->GetTextHeight(m_text.c_str()+Index,i - Index);
                i+=2;
                Index = i;
                x = 0;
            }
            x = pTextMesure->GetTextWidth(m_text.c_str()+Index,i - Index);
            if ( x >= m_cx)
            {
                pTextMesure->TextOutW(m_x,m_y+y,m_text.c_str()+Index,i- Index - 1);
                y += pTextMesure->GetTextHeight(m_text.c_str()+Index,i - Index);
                Index = i - 1;
                x = 0;
            }
        }
        if (Index < m_text.size())
        {
            pTextMesure->TextOutW(0,y,m_text.c_str()+Index,m_text.size()- Index);
        }
    }
private:
	std::wstring m_text;
	int m_x;
	int m_y;
    int m_cx;
    int m_cy;
};


class XDrawTextSelect : public XDrawTextColor
{
public:
    XDrawTextSelect()
    {
        m_SelStart = 0;
        m_SelEnd   = 0;
        m_SelectBkCor = RGB(0,0,128);
        m_SelectTextColor = RGB(255,255,255);
    }
    void Draw(XDCDraw* pDrawDC,XGDI* pTextMesure)
    {
        XDrawTextColor::Draw(pDrawDC);
        if (m_SelEnd != m_SelStart)
        {
            DrawSelect(pDrawDC,pTextMesure);
        }
    }
    void SetSelect(int nSelectStart,int nSelectEnd)
    {
        if (nSelectEnd < nSelectStart)
        {
            m_SelStart = nSelectEnd;
            m_SelEnd = nSelectStart;
        }else
        {
            m_SelStart = nSelectStart;
            m_SelEnd   = nSelectEnd;
        }
    }
    void SetSelectAll()
    {
        m_SelStart = 0;
        m_SelEnd  = m_text.length();
    }
    void SetUnSelect()
    {
        m_SelStart = m_SelEnd;
    }
private:
    void DrawSelect(XDCDraw* pDrawDC,XGDI* pTextMesure)
    {

        int x1 = m_x+ pTextMesure->GetTextWidth(m_text.c_str(),m_SelStart);
        int y1 = m_y;
        int x2 = m_x + pTextMesure->GetTextWidth(m_text.c_str(),m_SelEnd);
        int y2 = m_y + pTextMesure->GetTextHeight(m_text.c_str(),m_text.length());


        pDrawDC->SetBrushColor(m_SelectBkCor);
        pDrawDC->FillRectEx(x1,y1,x2,y2);

        pDrawDC->SetBrushColor(m_SelectTextColor);
        pDrawDC->TextOutW(x1,y1,m_text.c_str()+m_SelStart,m_SelEnd - m_SelStart);
    }

private:
    int m_SelStart;
    int m_SelEnd;
    COLORREF m_SelectBkCor;
    COLORREF m_SelectTextColor;
};

template <typename T>
class XTDataQueueVector
{
public:
    XTDataQueueVector()
    {
        m_MaxQueueSize = 10;
    }
    void SetQueueMaxSize(size_t maxSize)
    {
        m_MaxQueueSize = maxSize;
    }
    void Push(T pt)
    {
        m_Point.push_back(pt);
        if (m_Point.size() > m_MaxQueueSize)
        {
            m_Point.erase(m_Point.begin());
        }
    }
    size_t GetMaxCount()
    {
        return m_MaxQueueSize;
    }
    size_t GetCount()
    {
        return m_Point.size();
    }
    T GetData(size_t nIndex)
    {
        return m_Point[nIndex];
    }
protected:
    size_t m_MaxQueueSize;
    std::vector<T> m_Point;
};

template <typename T>
class XTDataQueue
{
public:
    XTDataQueue()
    {
        m_pDataArray = NULL;
		m_QueueSize  = 0;
		m_FirstIndex = 0;
		m_LastIndex  = 0;
		m_ArrayMaxSize = 0;
    }
    ~XTDataQueue()
    {
        Destory();
    }
    void SetQueueMaxSize(size_t nQueueSize)
    {
		if (nQueueSize == m_QueueSize)
		{   //什么都不做
			return ;
		}
		Destory();
		m_ArrayMaxSize = nQueueSize*2;
		m_pDataArray = new T[nQueueSize*2];
		m_FirstIndex = 0;
		m_LastIndex  = 0;
		m_QueueSize  = nQueueSize;
    }
    void PopData()
    {
        if (m_FirstIndex != m_LastIndex)
        {
            m_FirstIndex++;
        }
    }
    void ClearData()
    {
        m_FirstIndex = 0;
        m_LastIndex  = 0;
    }
    void PushData(T& pt)
    {
        if (m_LastIndex >= m_ArrayMaxSize)
        {
            RtlMoveMemory(m_pDataArray,m_pDataArray+m_FirstIndex,m_QueueSize*sizeof(T));
            m_FirstIndex = 0;
            m_LastIndex  = m_QueueSize-1;
        }
        m_pDataArray[m_LastIndex] = pt;
        if (m_LastIndex >= m_QueueSize)
        {
            m_FirstIndex++;
        }
        m_LastIndex++;
    }
    T* GetData(size_t Index)
    {
        return m_pDataArray+m_FirstIndex+Index;
    }
    size_t GetDataSize()
    {
        return m_LastIndex - m_FirstIndex;
    }
private:
	void Destory()
    {
        if (m_pDataArray != NULL)
        {
            delete[] m_pDataArray;
            m_pDataArray = NULL;
        }
    }
protected:
    size_t m_ArrayMaxSize;
    size_t m_QueueSize;
    size_t m_FirstIndex;
    size_t m_LastIndex;
    T* m_pDataArray;
};

//网格点坐标
template <typename T>
class XTDataGridPoint
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XTDataGridPoint()
	{
		m_nCol = 10;
		m_nRow = 10;
	}

	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}

	void SetRowCount(int nRow)
	{
		m_nRow = nRow;
		m_CellHeight = m_cy / nRow;
	}
	void SetColCount(int nCol)
	{
		m_nCol = nCol;
		m_CellWidth = m_cx / nCol;
	}
	//获得从上到下的坐标
	T GetPoint(int XIndex,int YIndex)
	{
		T pt = {m_x+XIndex*m_CellWidth,m_y+YIndex*m_CellHeight};
		return pt;
	}
	//获得从下到上的坐标
	T GetPoint_(int XIndex,int YIndex)
	{
		T pt = {m_x+XIndex*m_CellWidth,m_y+m_cy-YIndex*m_CellHeight};
		return pt;		
	}
private:
	int m_nCol;
	int m_nRow;

	int m_CellHeight;
    int m_CellWidth;
};

template <typename T>
class XTDataArray
{
public:
	//返回行号
	size_t InsertItem(size_t nIndex,const T& TC)
	{
		vector<T>::iterator it = m_ItemList.begin()+nIndex;
		m_ItemList.insert(it,TC);
		return m_ItemList.size()-1;
	}
	VOID SetItemData(size_t Index,T& t)
	{
		m_ItemList[Index] = t;
	}
	size_t GetItemCount()
	{
		return m_ItemList.size();
	}
	void ReSize(size_t nSize,T& t)
	{
		m_ItemList.resize(nSize,t);
	}
	const T& GetItem(size_t nIndex) const
	{
		return m_ItemList[nIndex];
	}
	//增加到末尾
	size_t AddItem(const T& TC)
	{
		m_ItemList.push_back(TC);
		return m_ItemList.size();
	}
	VOID DeleteItem(size_t nIndex)
	{
		std::vector<T>::iterator it = m_ItemList.begin() + nIndex;
		m_ItemList.erase(it);
	}
	void DeleteItemN(size_t nIndex,size_t nCount)
	{
		std::vector<T>::iterator itB = m_ItemList.begin() + nIndex;
		std::vector<T>::iterator itE = m_ItemList.begin() + nIndex + nCount;
		m_ItemList.erase(itB,itE);
	}
	void Clear()
	{
		m_ItemList.clear();
	}
private:
	vector<T> m_ItemList;
};


class XDataTableEx
{
protected:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	void SetColumnCount(int nColumnCount)
	{
		m_ColumnDefaultWidth = m_cx / nColumnCount;
		m_ArrayColumnWidth.ReSize(nColumnCount,m_ColumnDefaultWidth);
	}
	void SetRowCount(int nRowCount)
	{
		m_RowDefaultHeight = m_cy/nRowCount;
		m_ArrayRowHeight.ReSize(nRowCount,m_RowDefaultHeight);
	}
	void SetColumnWidth(int nIndex,int nWidth)
	{
		int nOldWidth = m_ArrayColumnWidth.GetItem(nIndex);
		m_cx = m_cx + nWidth - nOldWidth;
		m_ArrayColumnWidth.SetItemData(nIndex,nWidth);
	}
	void SetRowHeight(int nIndex,int nHeight)
	{
		int nOldHeight  = m_ArrayRowHeight.GetItem(nIndex);
		m_cy = m_cy + nHeight - nOldHeight;
		m_ArrayRowHeight.SetItemData(nIndex,nHeight);
	}
	int GetColumnCount()
	{
		return m_ArrayColumnWidth.GetItemCount();
	}
	int GetRowCount()
	{
		return m_ArrayColumnWidth.GetItemCount();
	}
	//调用这个之前必须判断 点坐标已经在整个表格内了。。。。
	BOOL Pt2Index(POINT pt,int* pOutColumn,int* pOutRow)
	{
		BOOL bOK1 = FALSE;
		BOOL bOK2 = FALSE;
		*pOutColumn = -1;
		*pOutRow = -1;
		int TempX = m_x;
		for (int i = 0; i < m_ArrayColumnWidth.GetItemCount(); i++)
		{
			TempX+= m_ArrayColumnWidth.GetItem(i);
			if (pt.x < TempX)
			{
				bOK1 = TRUE; 
				break;
			}
		}
		int TempY = m_y;
		for (int j = 0; j < m_ArrayRowHeight.GetItemCount(); j++)
		{
			TempY += m_ArrayRowHeight.GetItem(j);
			if (pt.y < TempY)
			{
				bOK2 = TRUE;
				break;
			}
		}
		return bOK1&bOK2;
	}
protected:
	int m_ColumnDefaultWidth;
	int m_RowDefaultHeight;
	XTDataArray<int> m_ArrayColumnWidth;
	XTDataArray<int> m_ArrayRowHeight;
};

template <typename T>
class XTDCTable : public XDataTableEx
{
public:
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void Draw(T* pDrawTool)
	{
		//画横线
		int x1 = m_x;
		int y1 = m_y;
		int x2 = m_x + m_cx;
		int y2 = m_y;
		for (int i = 0; i <= m_ArrayRowHeight.GetItemCount(); i++)
		{
			pDrawTool->DrawLine(x1,y1,x2,y2);
			y1+=m_ArrayRowHeight.GetItem(i);
			y2 = y1;
		}

		x1 = m_x;
		y1 = m_y;
		x2 = m_x;
		y2 = m_y + m_cy;
		for (int j = 0; j <= m_ArrayColumnWidth.GetItemCount(); j++)
		{
			pDrawTool->DrawLine(x1,y1,x2,y2);
			x1 += m_ArrayColumnWidth.GetItem(j);
			x2  = x1;
		}
	}
private:
};

class XDataCurve
{
public:
	void Create(int x,int y,int cx,int cy)
	{
        m_x = x;
        m_y = y;
        m_cx = cx;
        m_cy = cy;
		m_Convert.Create(x,y,cx,cy);
	}
	void SetRowCount(int nRow)
	{
		m_Convert.SetRowCount(nRow);
	}
	void SetColCount(int nCol)
	{
		m_Convert.SetColCount(nCol);
	}
	//设置曲线图中点的最大数量
	void SetMaxPointCount(int nMaxPointCount)
	{
		m_PointArray.SetQueueMaxSize(nMaxPointCount);
	}
	void PushIndex(int nXIndex,int nYIndex)
	{
		m_PointArray.PushData(m_Convert.GetPoint_(nXIndex,nYIndex));
	}
protected:
	int m_x;
    int m_y;
    int m_cx;
    int m_cy;
	
	XTDataGridPoint<POINT> m_Convert;
	XTDataQueue<POINT> m_PointArray;
};

template <typename T>
class XTDCCurve : public XDataCurve
{
public:
	void Draw(T* pDrawTool)
	{
		pDrawTool->Polyline(m_PointArray.GetData(0), m_PointArray.GetDataSize());
	}
};

template <typename T>
class XTDCCurveColor : public XDataCurve
{
public:
	XTDCCurveColor()
	{
		m_LineCor = 0;
		m_alpha   = 255;
	}
	void Draw(T* pDrawTool)
	{
		pDrawTool->SetBrushColor(m_LineCor,m_alpha);
		pDrawTool->Polyline(m_PointArray.GetData(0), m_PointArray.GetDataSize());
	}

	void SetLineColor(COLORREF cor,byte alpha)
	{
		m_LineCor = cor;
		m_alpha = alpha;
	}
private:
	COLORREF m_LineCor;
	byte     m_alpha;
};




struct StructText
{
    std::wstring text;
    BOOL         bShow;
};

//文字数组
template <typename T>
class XTDCTextArrayQueue
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XTDCTextArrayQueue()
	{
	}
	void SetArraySize(int nMaxArrayCount)
	{
		m_ArrayMaxCount = nMaxArrayCount;
		m_StringArray.SetQueueMaxSize(nMaxArrayCount);
	}
    void SetPos(int x,int y)
    {
        m_x = x;
        m_y = y;
    }
    void Push(const wchar_t* lpText, BOOL bShow = TRUE)
    {
        StructText data;
        data.text = lpText;
        data.bShow = bShow;
        m_StringArray.Push(data);
    }
	void DrawHorizon(T* pDrawDC)
	{
        int nSpace = m_cx / (m_ArrayMaxCount-1);
		
		for (size_t i = 0; i < m_StringArray.GetCount(); i++)
		{
			StructText TextData = m_StringArray.GetData(i);
			if (TextData.bShow)
			{
				pDrawDC->TextOutW(
					m_x+i*nSpace,
					m_y,
					TextData.text.c_str(),
					TextData.text.length());
			}
        }
	}
	void DrawVectory(T* pDrawDC)
	{
		int nSpace = m_cy / (m_ArrayMaxCount-1);
		for (size_t i = 0; i < m_StringArray.GetCount(); i++)
		{
			StructText TextData = m_StringArray.GetData(i);
			
			if (TextData.bShow)
			{
				pDrawDC->TextOutW(
					m_x,
					m_y+i*nSpace,
					TextData.text.c_str(),
					TextData.text.length());
			}
        }
	}
private:
    int m_ArrayMaxCount;
    BOOL m_bHorizon;
    XTDataQueueVector<StructText> m_StringArray;
};

//标尺不带刻度
enum Staff_Align_{
	Staff_Align_Left,
	Staff_Align_Mid,
	Staff_Align_Right,
};


//水平刻度尺
template <typename T>
class XTDataStaffHorizon
{
public:
    void Create(int x,int y,int cx,int cy)
    {
        m_x = x;
        m_y = y;
        m_cx = cx;
        m_cy = cy;

		m_line.Create(x,y,cx,0);
        m_lineArray.Create(x,y,cx,cy);

		SetAlign(Staff_Align_Left);
    }
	void SetGraduationCount(int nGraduationLine)
	{
		m_lineArray.SetLineCount(nGraduationLine);
	}
    void SetAlign(Staff_Align_ align)
    {
        m_LineAlign = align;

		int x = 0;
		int y = 0;
        switch (m_LineAlign)
        {
        case Staff_Align_Left:
			x = m_x;
			y = m_y;
            break;
        case Staff_Align_Mid:
            {
				x = m_x;
				y = m_y+m_cy;
            }
            break;
        case Staff_Align_Right:
            {
				x = m_x;
				y = m_y+m_cy;
            }
            break;
        }
		m_line.SetRect(x,y,m_cx,0);
    }
protected:
    int m_x;
    int m_y;
    int m_cx;
    int m_cy;

    Staff_Align_ m_LineAlign;

    XTDCLine<T> m_line;           //尺子
    XTDCDataLineArrayVertical<T> m_lineArray; //刻度
};

//垂直刻度尺
template <typename T>
class XTDataStaffVertical
{
public:
    void Create(int x,int y,int cx,int cy)
    {	
        m_x = x;
        m_y = y;
        m_cx = cx;
        m_cy = cy;
		
        m_lineArray.Create(x,y,cx,cy);
        m_line.SetRect(x,y,0,cy);
		SetAlign(Staff_Align_Left);
    }
	void SetGraduationCount(int nGraduationLine)
	{
		m_lineArray.SetLineCount(nGraduationLine);
	}

    void SetAlign(Staff_Align_ align)
    {
		m_LineAlign = align;
		
		int x = 0;
		int y = 0;
        switch (m_LineAlign)
        {
        case Staff_Align_Left:
			x = m_x;
			y = m_y;
            break;
        case Staff_Align_Mid:
            {
				x = m_x+m_cx/2;
				y = m_y;
            }
            break;
        case Staff_Align_Right:
            {
				x = m_x+m_cx;
				y = m_y;
            }
            break;
        }
		m_line.SetRect(x,y,0,y+m_cy);
    }
	
protected:
    int m_x;
    int m_y;
    int m_cx;
    int m_cy;

    Staff_Align_ m_LineAlign;
		
    XTDCLine<T> m_line;           //尺子
    XTDCDataLineArrayHorizon<T> m_lineArray; //刻度
};


template <typename T>
class XTDCStaffHorizon : public XTDataStaffHorizon<T>
{
public:
	void Draw(T* pDrawDC)
	{
		m_line.Draw(pDrawDC);
		m_lineArray.Draw(pDrawDC);
    }
private:
};

template <typename T>
class XTDCStaffVertical : public XTDataStaffVertical<T>
{
public:
	void Draw(T* pDrawDC)
	{
		m_line.Draw(pDrawDC);
		m_lineArray.Draw(pDrawDC);
    }
private:
};


//标尺 带刻度文本
// template <typename T>
// class XTemplateDataStaffEx
// {
// public:
//     void Create(int x,int y,int cx,int cy)
//     {
//         m_x = x;
//         m_y = y;
//         m_cx = cx;
//         m_cy = cy;
// 
//         m_Staff.Create(x,y,cx,cy);
//         m_TextQueue.Create(x,y,cx,cy);
//         m_bHorizon = TRUE;
// 
//         m_StaffOffsetX = 0;
//         m_StaffOffsetY = 0;
//         m_TextOffsetX = 0;
//         m_TextOffsetY = 0;
//     }
// 	void SetGraduationCount(int nGraduation)
// 	{
// 		m_Staff.SetGraduationLineCount(nGraduation);
// 		m_TextQueue.SetArraySize(nGraduation);
// 	}
//     void PushText(const wchar_t* lpText)
//     {
//         m_TextQueue.Push(lpText);
//     }
//     void SetHorizon(BOOL bHorizon)
//     {
//         m_bHorizon = bHorizon;
//         m_Staff.SetHorizon(bHorizon);
//         m_TextQueue.SetHorizon(bHorizon);
//     }
//     void SetStaffOffset(int x,int y)
//     {
//         m_StaffOffsetX = x;
//         m_StaffOffsetY = y;
// 		m_Staff.SetPos(m_x+ m_StaffOffsetX,m_y + m_StaffOffsetY);
//     }
//     void SetTextOffset(int x,int y)
//     {
//         m_TextOffsetX = x;
//         m_TextOffsetY = y;
// 		m_TextQueue.SetPos(m_x+ m_TextOffsetX,m_y+m_TextOffsetY);
//     }
//     void SetStaffAlign(Staff_Align_ Align)
//     {
//         m_Staff.SetAlign(Align);
//     }
//     void SetStaffSpaceTwo(int leftSpace,int rightSpace)
//     {
//         m_Staff.SetSpaceTwo(leftSpace,rightSpace);
//     }
// 
// protected:
//     int m_x;
//     int m_y;
//     int m_cx;
//     int m_cy;
// 
//     XTemplateDCStaff<T> m_Staff;
//     XTemplateDCTextArrayQueue<T>    m_TextQueue; //刻度文本
//     int         m_StaffOffsetX;
//     int         m_StaffOffsetY;
//     int         m_TextOffsetX;
//     int         m_TextOffsetY;
//     BOOL        m_bHorizon;
// };

// template <typename T>
// class XTemplateDCStaffEx : public XTemplateDataStaffEx<T>
// {
// public:
//     void Draw(T* pDrawDC)
//     {
//         m_Staff.Draw(pDrawDC);
//         m_TextQueue.Draw(pDrawDC);
//     }
// private:
// };


template <typename T>
class XTDCCpuUsage
{
public:
    void Create(int x,int y,int cx,int cy)
    {

        m_x = x;
        m_y = y;
        m_cx = cx;
        m_cy = cy;

		m_staffVWidth  = 10;
		m_staffHHeight = 10;

        m_staffexV.Create(
			x,
			y,
			m_staffVWidth,
			cy-m_staffHHeight);
        m_staffexV.SetAlign(Staff_Align_Right);

        m_staffexH.Create(
			x   + m_staffVWidth,
			m_y + cy-m_staffHHeight,
			cx  - m_staffVWidth,
			m_staffHHeight);
		m_staffexH.SetAlign(Staff_Align_Left);


        m_Curve.Create(
			x+m_staffVWidth,
			y,
			cx-m_staffVWidth,
			cy-m_staffHHeight);

    }
	//设置水平 垂直刻度数
	void SetGraduationCount(int nHCount,int nVCount)
	{
		m_staffexH.SetGraduationCount(nHCount);
		m_staffexV.SetGraduationCount(nVCount);

		m_Curve.SetRowCount(nVCount-1);
		m_Curve.SetColCount(nHCount-1);
		m_Curve.SetMaxPointCount(nHCount);
	}
    void PushPoint(int nXIndex,int nYIndex)
    {
		m_Curve.PushIndex(nXIndex,nYIndex);
    }
//     void PushTextV(const wchar_t* lpText)
//     {
//         m_staffexV.PushText(lpText);
//     }
//     void PushTextH(const wchar_t* lpText)
//     {
//         m_staffexH.PushText(lpText);
//     }

    void Draw(T* pDrawDC)
    {
        m_staffexV.Draw(pDrawDC);
        m_staffexH.Draw(pDrawDC);
        m_Curve.Draw(pDrawDC);
    }
private:
    XTDCStaffVertical<T> m_staffexV;
    XTDCStaffHorizon<T> m_staffexH;
    XTDCCurveColor<T> m_Curve;

    int m_x ;
    int m_y ;
    int m_cx ;
    int m_cy ;

	int m_staffVWidth;
	int m_staffHHeight;
};


typedef struct _tagData
{
    //表格数据相关
    BOOL     m_bFillbg;
    COLORREF m_bgCor;
    BYTE     m_bbgAlpha;
    HELE     m_hEle;
}DATA,*PDATA;

///////////////////////////////////////////////////////////////
//	类    名 : XGraphEquidistantTableFill
//	基    类 : 
//	描    述 : 等距表格填充
//	功    能 : 
//	历史记录 : 
//	使用说明 : 
//	作    者 : dasemimi
//	时    间 : 2016年6月24日
//	备    注 : 
///////////////////////////////////////////////////////////////
class XDrawEquidistantTableFill
{
public:
    XDrawEquidistantTableFill()
    {
        m_pData = NULL;
        m_x = 0;
        m_y = 0;
		m_cx = 0;
		m_cy = 0;
        m_cor = 0;
        m_alpha = 254;

		m_FillPaddingLeft   = 1;
		m_FillpaddingTop    = 1;
		m_FillpaddingRight  = 1;
	    m_FillpaddingBottom = 1;

    }
    ~XDrawEquidistantTableFill()
    {
        UnInitData();
    }

	void Create(int x,int y,int cx,int cy,int nRowCount,int nColCount)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
		m_RowCount = nRowCount;
		m_ColCount = nColCount;
		InitData();
	}
	void SetFillPadding(int nLeft,int nTop,int nRight,int nBottom)
	{
		m_FillPaddingLeft   = nLeft;
		m_FillpaddingTop    = nTop;
		m_FillpaddingRight  = nRight;
	    m_FillpaddingBottom = nBottom;
	}
    void SetFillColor(int nIndex,COLORREF cor,BYTE alpha)
    {
        m_pData[nIndex].m_bFillbg = TRUE;
        m_pData[nIndex].m_bgCor   = cor;
        m_pData[nIndex].m_bbgAlpha= alpha;
    }
    //////////////////////////////////////////////////////////////////////////
    PDATA GetData(int nIndex)
    {
        return m_pData+nIndex;
    }

    void Draw(XDCDraw* pDraw)
    {
        //先画表格
        DrawTable(pDraw);
        //然后填充表格
        for (int i = 0; i < m_ColCount*m_RowCount; i++)
        {
            if (GetData(i)->m_bFillbg)
            {
                FillIndex(pDraw,i);
            }
        }
    }

public:
    void GetRect(RECT* lpRect)
    {
        lpRect->left    = m_x;
        lpRect->top        = m_y;
        lpRect->right    = m_x+m_cx;
        lpRect->bottom    = m_y+m_cy;
    }
    void GetClientRect(RECT* lpRect)
    {
        lpRect->left    = 0;
        lpRect->top        = 0;
        lpRect->right    = m_cx;
        lpRect->bottom    = m_cy;
    }
    int PtToIndex(POINT* pt)
    {
        int nCol = (pt->x - m_x)%m_cx;
        int nRow = (pt->y - m_y)%m_cy;

        return nRow * m_RowCount + nCol;
    }
private:
	void UnInitData()
    {
        if (m_pData)
        {
            delete[] m_pData;
            m_pData = NULL;
        }
    }
	void InitData()
	{
		UnInitData();
		m_pData = new DATA[m_ColCount*m_RowCount];
        ZeroMemory(m_pData,sizeof(DATA)*m_ColCount*m_RowCount);
	}

    void DrawTable(XDCDraw* pDraw)
    {
        pDraw->SetBrushColor(m_cor,m_alpha);
        //画表格
        int nHeight = m_cy/m_RowCount;
        int nWidth  = m_cx/m_ColCount;
        //画横线
		int x1 = m_x;
		int y1 = m_y;
		int x2 = x1+m_cx;
		int y2 = y1;
        for (int i = 0; i <= m_RowCount; i++)
        {
            pDraw->DrawLine(x1,y1,x2,y2);
			y1+=nHeight;
			y2 = y1;
        }
        //画竖线
		x1 = m_x;
		y1 = m_y;
		x2 = x1;
		y2 = m_y+m_cy;
        for (int j = 0; j <= m_ColCount; j++)
        {
            pDraw->DrawLine(x1,y1,x2,y2);
			x1+=nWidth;
			x2 =x1; 
        }
    }
    void FillIndex(XDCDraw* pDraw,int nIndex)
    {
        int nRow = nIndex / m_ColCount;
        int nCol = nIndex % m_ColCount;

		int m_nCellCX = m_cx / m_ColCount; //单元格宽度
		int m_nCellCY = m_cy / m_RowCount; //单元格高度

        RECT rt;
        rt.left     = m_x + nCol*m_nCellCX + m_FillPaddingLeft;
        rt.top      = m_y + nRow*m_nCellCY + m_FillpaddingTop;
        rt.right    = rt.left+ m_nCellCX -   m_FillpaddingRight;
        rt.bottom   = rt.top + m_nCellCY -   m_FillpaddingBottom;
        pDraw->SetBrushColor(m_pData[nIndex].m_bgCor,m_pData[nIndex].m_bbgAlpha);
        pDraw->FillRect(&rt);
    }

private:
//表格线相关
    int m_x;
    int m_y;
    int m_cx;    
    int m_cy;

	int m_FillPaddingLeft;
	int m_FillpaddingTop;
	int m_FillpaddingRight;
	int m_FillpaddingBottom;

    int m_ColCount;
    int m_RowCount;

    COLORREF m_cor;
    BYTE     m_alpha;

    PDATA m_pData;
};


class XRichEdit
{
public:
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_hEdit = XSView_Create(x,y,cx,cy,hParent);

		HWND hWnd = NULL;
		if (XC_GetObjectType(hParent) == XC_WINDOW)
		{
			hWnd = XWnd_GetHWND((HWINDOW)hParent);
		}else if (XC_GetObjectType(hParent) == XC_ELE)
		{
			hWnd = XEle_GetHWND((HELE)hParent);
		}
		if (hWnd)
		{
			m_MemDC.Create(hWnd);
		}
		return m_hEdit;
	}

private:
	HELE m_hEdit;
	XGDIMEMDC m_MemDC;
	vector<HELE> m_EleArray;
};


//饼图
class XDataPie
{
protected:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XDataPie()
	{
		m_cor = 0;
		m_Alpha = 255;
		m_nStartAngle = 0;
		m_nEndAngle   = 90;
	}
	XDataPie(const XDataPie& o)
	{
		m_Alpha = o.m_Alpha;
		m_cor   = o.m_cor;
		m_nStartAngle = o.m_nStartAngle;
		m_nEndAngle   = o.m_nEndAngle;
	}
	void SetAngle(int nStart,int nEnd)
	{
		m_nStartAngle = nStart;
		m_nEndAngle   = nEnd;
	}
	VOID SetColor(COLORREF cor)
	{
		m_cor = cor;
	}
protected:
	int m_nStartAngle;
	int m_nEndAngle;
	COLORREF m_cor;
	BYTE     m_Alpha;
};

class XGDIPie : public XDataPie
{
public:
	XMathTool  m_MathTool;

	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void Draw(XGDI* pDrawTool)
	{
		//设置透明画笔，不画饼状图的外围
		HGDIOBJ oldPen = pDrawTool->SelectObject(::GetStockObject(NULL_PEN));

		POINT pt1;
		POINT pt2;
		m_MathTool.AngleToPoint(m_x,m_y,m_cx,m_cy,m_nStartAngle,&pt1,FALSE);
		m_MathTool.AngleToPoint(m_x,m_y,m_cx,m_cy,m_nEndAngle,&pt2,FALSE);
		pDrawTool->Pie(m_x,m_y,m_cx,m_cy,&pt2,&pt1);
		pDrawTool->SelectObject(oldPen);

	}
};


class XGDIPlusPie : public XDataPie
{
public:
	XGDIPlusPie()
	{

	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void Draw(XDCGDIPlus* pDrawTool)
	{
		pDrawTool->SetBrushColor(m_cor,m_Alpha);
		pDrawTool->FillPie(
			m_x,m_y,m_cx,m_cy,
			m_nStartAngle,m_nEndAngle);
	}
};

class XGDIPieSix
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XGDIPieSix()
	{
		m_hBrushLrDa	= NULL;
		m_hBrushLrZhong = NULL;
		m_hBrushLrXiao  = NULL;
		m_hBrushLcDa    = NULL;
		m_hBrushLcZhong = NULL;
		m_hBrushLcXiao  = NULL;

		m_hBrushLrDa	= CreateSolidBrush(RGB(177,28,30));
		m_hBrushLrZhong = CreateSolidBrush(RGB(203,78,80));
		m_hBrushLrXiao  = CreateSolidBrush(RGB(221,118,118));
		m_hBrushLcDa    = CreateSolidBrush(RGB(80,114,20));
		m_hBrushLcZhong = CreateSolidBrush(RGB(112,161,32));
		m_hBrushLcXiao  = CreateSolidBrush(RGB(181,197,102));
	}
	~XGDIPieSix()
	{
		if (m_hBrushLrDa)
		{
			::DeleteObject(m_hBrushLrDa);
		}
		if (m_hBrushLrZhong)
		{
			::DeleteObject(m_hBrushLrZhong);
		}
		if (m_hBrushLrXiao)
		{
			::DeleteObject(m_hBrushLrXiao);
		}
		if (m_hBrushLcDa)
		{
			::DeleteObject(m_hBrushLcDa);
		}
		if (m_hBrushLcZhong)
		{
			::DeleteObject(m_hBrushLcZhong);
		}
		if (m_hBrushLcXiao)
		{
			::DeleteObject(m_hBrushLcXiao);
		}
		
		m_hBrushLrDa	= NULL;
		m_hBrushLrZhong = NULL;
		m_hBrushLrXiao  = NULL;
		m_hBrushLcDa    = NULL;
		m_hBrushLcZhong = NULL;
		m_hBrushLcXiao  = NULL;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}

	void Draw(XGDI* pDrawTool,
		INT nLRDaDan,INT nLRZhongDan,INT nLRXiaoDan,
		INT nLCDaDan,INT nLCZhongDan,INT nLCXiaoDan)
	{

		HGDIOBJ oldPen = pDrawTool->SelectObject(::GetStockObject(NULL_PEN));

		double total = (nLRDaDan+nLRZhongDan+nLRXiaoDan+nLCDaDan+nLCZhongDan+nLCXiaoDan);
		double oneCellPrecent = 360/total;
		

 		int nIndex = 0;
 		INT nLcDa = nLCDaDan*oneCellPrecent;
		HGDIOBJ oldBrush = pDrawTool->SelectObject(m_hBrushLcDa);
		DrawPrecent(pDrawTool,nIndex,nLcDa);
 		nIndex+=nLcDa;


		INT nLcZhong = nLCZhongDan*oneCellPrecent;
		pDrawTool->SelectObject(m_hBrushLcZhong);
		DrawPrecent(pDrawTool,nIndex,nLcZhong);
		nIndex+=nLcZhong;
		
		INT nLcXiao  = nLCXiaoDan*oneCellPrecent;
		pDrawTool->SelectObject(m_hBrushLcXiao);
		DrawPrecent(pDrawTool,nIndex,nLcXiao);
		nIndex+=nLcXiao;

		int nLrXiao = nLRXiaoDan*oneCellPrecent;
		pDrawTool->SelectObject(m_hBrushLrXiao);
		DrawPrecent(pDrawTool,nIndex,nLrXiao);
		nIndex+=nLrXiao;

		INT nLrZhong = nLRZhongDan*oneCellPrecent;
		pDrawTool->SelectObject(m_hBrushLrZhong);
		DrawPrecent(pDrawTool,nIndex,nLrZhong);
		nIndex+=nLrZhong;

		int nLrDa   = nLRDaDan*oneCellPrecent;
		pDrawTool->SelectObject(m_hBrushLrDa);
		DrawPrecent(pDrawTool,nIndex,360-nIndex);

		pDrawTool->SelectObject(oldPen);
		pDrawTool->SelectObject(oldBrush);
	}
	void DrawPrecent(XGDI* pDrawTool,int nIndex,INT nCount)
	{
		POINT ptStart ;
		POINT ptEnd  ;
		CountPoint(nIndex,ptEnd,FALSE);
		CountPoint(nIndex+nCount,ptStart,FALSE);
		pDrawTool->Pie(m_x,m_y,m_cx,m_cy,&ptStart,&ptEnd);
	}
private:

	void CountPoint(int nAngle, POINT& pt, BOOL bPercent)
	{
		double pi = 3.1415926535;
		int nLeft = m_x;
		int nTop  = m_y;
		int nRight = m_x+m_cx;
		int nBottom = m_y+ m_cy;
		
		while (nAngle <0)
			nAngle += 360;
		
		while (nAngle>359)
			nAngle -= 360;
		
		double dAngle = ((double)nAngle)*pi/(double)180;
		
		double r;
		r = ((double)nBottom- nTop)/2.0;
		if (bPercent)
			r = r*3.0/5.0;
		
		double dOffX = (r*sin(dAngle));
		double dOffY = 0.0 - (r*cos(dAngle));
		
		double dX = ((double)(nRight+nLeft))/2.0;
		double dY = ((double)(nTop+nBottom))/2.0;
		
		pt.x = (int)(dX + dOffX);
		pt.y = (int)(dY + dOffY);
	}

private:
	HBRUSH m_hBrushLrDa;
	HBRUSH m_hBrushLrZhong;
	HBRUSH m_hBrushLrXiao;
	HBRUSH m_hBrushLcDa;
	HBRUSH m_hBrushLcZhong;
	HBRUSH m_hBrushLcXiao;
};

class XCommandString
{
public:
	void parese(const char* lpCmdStr,const char* lpSplitFlagStr)
	{
		char * strc = new char[strlen(lpCmdStr)+1];
		strcpy(strc, lpCmdStr);
		char* tmpStr = strtok(strc,lpSplitFlagStr);
		while (tmpStr != NULL)
		{
			resultVec.push_back(std::string(tmpStr));
			tmpStr = strtok(NULL,lpSplitFlagStr);
		}
		delete[] strc;
	}
	int GetCount()
	{
		return resultVec.size();
	}
	const char* operator [](int n)
	{
		return resultVec[n].c_str();
	}
private:
	std::vector<std::string> resultVec;
};

//比例数组，比如添加 1 2 3 4 然后设置 total 为 100，那么
//得到的就是10 20 30 40
class CScaleArray
{
public:
	void SetTotal(int nTotal)
	{
		m_nTotal = nTotal;
	}
	void AddScale(int nScale)
	{
		m_Array.push_back(nScale);
	}
	void GetScale(int nIndex)
	{

	}

private:
	std::vector<int> m_Array;
	int m_nTotal;
};

class XGDIPlusPieSix
{
	typedef struct _PieInfo 
	{
		XGDIPlusPie pie;
		int         nScale;
	}PIEINFO,*PPIEINFO;
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XGDIPlusPieSix()
	{
	}
	~XGDIPlusPieSix()
	{
		Clean();
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	//增加扇形信息
	VOID AddPieInfo(int nScale,COLORREF cor)
	{
		PPIEINFO pPi = new PIEINFO;
		pPi->pie.Create(m_x,m_y,m_cx,m_cy);
		pPi->nScale = nScale;
		pPi->pie.SetColor(cor);
		m_pieInfoArray.AddItem(pPi);
	}
	VOID Clean()
	{
		for (int i = 0; i < m_pieInfoArray.GetItemCount(); i++)
		{
			delete m_pieInfoArray.GetItem(i);
		}
		m_pieInfoArray.Clear();
	}
	//自动计算内部数据
	void AutoCalc()
	{
		int nCount = m_pieInfoArray.GetItemCount();
		if (nCount < 1)
			return ;

		if (nCount == 1)
		{
			m_pieInfoArray.GetItem(0)->pie.SetAngle(0,360);
			return;
		}

		//获得总的数量
		int m_nTotalScale = 0;
		for (int i = 0; i < m_pieInfoArray.GetItemCount(); i++)
		{
			m_nTotalScale += m_pieInfoArray.GetItem(i)->nScale;
		}
		
		//获得每个比例所占的度数，
		int nStart = 0;
		int nEnd   = 0;
		for (int j = 0; j < nCount-1; j++)
		{
			PPIEINFO pi = m_pieInfoArray.GetItem(j);
			nEnd += (int)(360.0f*pi->nScale / m_nTotalScale);
			pi->pie.SetAngle(nStart,nEnd);
			nStart = nEnd;
		}
		m_pieInfoArray.GetItem(nCount-1)->pie.SetAngle(nStart,360 - nStart);
	}
	void Draw(XDCGDIPlus* pDrawTool)
	{
		for (int i = 0; i < m_pieInfoArray.GetItemCount(); i++)
		{
			m_pieInfoArray.GetItem(i)->pie.Draw(pDrawTool);
		}
	}
private:
	XTDataArray<PPIEINFO> m_pieInfoArray;

};



class XDataRectArrayHorizon
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XDataRectArrayHorizon()
	{
		m_Space = 0;
	}
	VOID SetCount(int nCount)
	{
		m_RectCount = nCount;
		m_CellWidth = m_cx / nCount;
	}
	int GetCount(int nCount)
	{
		return m_RectCount;
	}
	VOID GetRectFromIndex(int nIndex,RECT& rt)
	{
		rt.left  = m_x + nIndex* (m_CellWidth+m_Space);
		rt.top   = m_y;
		rt.right = rt.left + m_CellWidth;
		rt.bottom = rt.top + m_cy;
	}
protected:
	int m_RectCount;
	int m_CellWidth; //一个矩形的宽度
	int m_Space; //矩形间隔
};


class XDataRectArrayVertical
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XDataRectArrayVertical()
	{
		m_Space = 0;
	}
	VOID SetCount(int nCount)
	{
		m_RectCount = nCount;
		m_CellWidth = m_cy / nCount;
	}
	int GetCount(int nCount)
	{
		return m_RectCount;
	}
	VOID GetRectFromIndex(int nIndex,RECT& rt)
	{
		rt.left  = m_x;
		rt.top   = m_y + nIndex* (m_CellWidth+m_Space);
		rt.right = rt.left + m_cx;
		rt.bottom = rt.top + m_CellWidth;
	}
protected:
	int m_RectCount;
	int m_CellWidth; //一个矩形的宽度

	int m_Space; //矩形间隔
};

template <typename T>
class XTDCRect
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XTDCRect()
	{
		m_PaddingLeft = 1;
		m_PaddingTop  = 1;
		m_paddingRight= 0;
		m_PaddingBottom = 0;
	}
//attrib
public:
	void SetPadding(int nLeft,int nTop,int nRight,int nBottom)
	{
		m_PaddingLeft = nLeft;
		m_PaddingTop = nTop;
		m_paddingRight = nRight;
		m_PaddingBottom = nBottom;
	}

	void DrawRect(T* pDrawTool)
	{
		pDrawTool->DrawRect(m_x,m_y,m_x+m_cx,m_y+m_cy);
	}
	void DrawFillRect(T* pDrawTool)
	{
		pDrawTool->FillRectEx(
			m_x+m_PaddingLeft,
			m_y+m_PaddingTop,
			m_x+m_cx-m_paddingRight,
				m_y+m_cy-m_PaddingBottom);
	}

protected:
	int m_PaddingLeft;
	int m_PaddingTop;
	int m_paddingRight;
	int m_PaddingBottom;
};



template <typename T>
class XTDCRectColor
{
public:
	XTDCRectColor()
	{
		m_CorFill = RGB(255,255,255);
		m_CorLine = 0;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void SetRectColor(COLORREF cor,BYTE alpha)
	{
		m_CorLine = cor;
		m_AlphaLine = alpha;
	}
	void SetFillColor(COLORREF cor,BYTE alpha)
	{
		m_CorFill = cor;
		m_AlphaFill = alpha;
	}

	void DrawRect(T* pDrawTool)
	{
		pDrawTool->SetBrushColor(m_CorLine,m_AlphaLine);
		m_tDCRect.DrawRect(pDrawTool);
	}
	void FillRect(T* pDrawTool)
	{
		pDrawTool->SetBrushColor(m_CorFill,m_AlphaFill);
		m_tDCRect.DrawFillRect(pDrawTool);
	}
protected:
	COLORREF m_CorLine;
	BYTE     m_AlphaLine;
	COLORREF m_CorFill;
	BYTE     m_AlphaFill;
	XTDCRect m_tDCRect;

	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
};

class XDrawRoundRect
{
public:
	XDrawRoundRect()
	{
		m_RoundWidht = 5;
		m_RoundHeight = 5;

		m_PaddingLeft = 0;
		m_PaddingTop  = 0;
		m_paddingRight = 0;
		m_PaddingBottom = 0;
	}
	VOID SetPadding(int left,int top,int right,int bottom)
	{
		m_PaddingLeft = left;
		m_PaddingTop  = top;
		m_paddingRight = right;
		m_PaddingBottom = bottom;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void DrawRoundRect(XDCDraw* pDrawTool)
	{
		pDrawTool->DrawRoundRect(m_x,m_y,m_cx,m_cy,m_RoundWidht,m_RoundHeight);
	}
	void DrawFillRoundRect(XDCDraw* pDrawTool)
	{
		pDrawTool->FillRoundRect(
			m_x+m_PaddingLeft,
			m_y+m_PaddingTop,
			m_cx-m_paddingRight,
			m_cy-m_PaddingBottom,m_RoundWidht,m_RoundHeight);
	}

public:
	void SetRoundSize(int nWidth,int nHeight)
	{
		m_RoundWidht = nWidth;
		m_RoundHeight = nHeight;
	}
private:
	int m_RoundWidht;
	int m_RoundHeight;
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
	int m_PaddingLeft;
	int m_PaddingTop;
	int m_paddingRight;
	int m_PaddingBottom;
};

//////////////////////////////////////////////////////////////////////////
//圆环
class XGDIPlusRing
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void SetSize(int nSize)
	{
		m_nSize = nSize;
	}
	VOID Draw(XDCGDIPlus* pDrawTool)
	{
		pDrawTool->SetBrushColor(m_Cor,m_alpha);
		pDrawTool->SetPenWidth(m_nSize);
		pDrawTool->DrawEllipse(m_x,m_y,m_cx,m_cy);
	}
	VOID SetColor(COLORREF cor,BYTE alpha)
	{
		m_Cor = cor;
		m_alpha = alpha;
	}
private:
	int m_nSize;
	COLORREF m_Cor;
	BYTE     m_alpha;
};

//画弧线 
class XGDIPlusArc
{
private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
public:
	XGDIPlusArc()
	{
		m_nStart = 0;
		m_nSwap  = 30;
		m_nSize  = 2;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void SetSize(int nSize)
	{
		m_nSize = nSize;
	}
	VOID SetAngle(int nStart,int nSwap)
	{
		m_nStart = nStart;
		m_nSwap  = nSwap;
	}
	VOID Draw(XDCGDIPlus* pDrawTool)
	{
		pDrawTool->SetBrushColor(m_Cor,m_alpha);
		pDrawTool->SetPenWidth(m_nSize);
		pDrawTool->DrawArc(m_x,m_y,m_cx,m_cy,m_nStart,m_nSwap);
	}
	VOID SetColor(COLORREF cor,BYTE alpha)
	{
		m_Cor = cor;
		m_alpha = alpha;
	}
private:
	int m_nSize;
	int m_nStart;
	int m_nSwap;

	COLORREF m_Cor;
	BYTE     m_alpha;
};

class XDrawEdit
{
public:
	XDrawEdit()
	{
		m_IsFillBg = FALSE;
		m_PaddingLeft   = 5;
		m_PaddingTop    = 5;
		m_PaddingRight  = 5;
		m_PaddingBottom = 5;
	}
	void Create(int x,int y,int cx,int cy)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;
	}
	void SetText(const wchar_t* lpText)
	{
		m_text = lpText;
	}

	BOOL ShowCaret(POINT* pPt)
	{
		return FALSE;
	}
protected:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
	std::wstring m_text;

	COLORREF m_TextColor;
	BYTE     m_TextAlpha;

	BOOL     m_IsFillBg; //是否填充背景
	COLORREF m_BgFillColor;
	BYTE     m_BgFillAlpha;

	int      m_PaddingLeft;
	int      m_PaddingTop;
	int      m_PaddingRight;
	int      m_PaddingBottom;
};

struct StructMetadataChar
{
	wchar_t ch;
	COLORREF chColor;
	BYTE     chAlpha;
	HFONTX   font;
};
struct StructMetadataEnter
{
	wchar_t ch;
};

enum ImageShowType
{
	ImageShowType_Normal,
	ImageShowType_Zoom,
};
struct StructMetadataImage
{
	int  iType;
	void* Imagebuffer;
	int   ImageBufferSize;
	HIMAGE hImage;
	ImageShowType showType;
};

struct StructMetaDataEle 
{
	HELE hEle;
};

struct StructMetaDataShape
{
	HXCGUI hShape;
};


enum RichType_
{
	RichType_char,
	RichType_Enter,
	RichType_Image,
	RichType_Ele,
	RichType_Shape,
};
struct StructMetadata
{
	RichType_ Richtype;
	int outerX;
	int outerY;
	int outerCX;
	int outerCY;

	int innerX;
	int innerY;
	int innerCX;
	int innerCY;

	BOOL bSelect;
	int rowIndex;
	int ColIndex;
	union
	{
		StructMetadataChar mdChar;
		StructMetadataEnter   mdEnter;
		StructMetadataImage mdImage;
		StructMetaDataEle   mdEle;
		StructMetaDataShape   mdShape;
	};
};


BOOL IsPtInRect(POINT* pt,int x,int y,int cx,int cy)
{
	if (pt->x >= x && pt->x <= x+cx && pt->y >= y && pt->y <= y + cy)
	{
		return TRUE;
	}
	return FALSE;
}
BOOL IsPtInRect2(POINT* pPt,RECT* pRt)
{
	if (pPt->x >= pRt->left && pPt->x <= pRt->right && pPt->y >= pRt->top && pPt->y <= pRt->bottom)
		return TRUE;

	return FALSE;
}

class CRichEdit
{
public:
	CRichEdit()
	{
		m_RichEditOffsetX = 10;
		m_RichEditOffsetY = 0;
		m_CaretMetaArrayIndex = 0;
		m_DefaultFont = XFont_Create(12);
	}
	void Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		//创建视图容器
		m_hView = XSView_Create(x,y,cx,cy,hParent);

//		XSView_SetTotalSize(m_hView,cx,cy);
		//创建视图
		m_hEditView = XEle_Create(0,0,cx,cy,m_hView);		
		//创建光标
		m_Caret.Create(m_hEditView);

		XEle_RegEventCPP(m_hEditView,XE_PAINT,&CRichEdit::OnDraw);
	
		XEle_RegEventCPP(m_hEditView,XE_LBUTTONDOWN,&CRichEdit::OnLButtonDown);
		XEle_RegEventCPP(m_hEditView,XE_LBUTTONUP,&CRichEdit::OnLButtonUp);

		XEle_RegEventCPP(m_hEditView,XE_CHAR,&CRichEdit::OnEventChar);

		XEle_RegEventCPP(m_hEditView,XE_KEYDOWN,&CRichEdit::OnEventKeyDown);

		XEle_RegEventCPP(m_hEditView,XE_MOUSEMOVE,&CRichEdit::OnMouseMove);
	}


	//【设置选中 单选or多选】
	// 鼠标移动 且 左键按下

	void ClearSelect()
	{   //清空选中
		for (int i = 0; i < m_MetaArray.size(); i++)
		{
			m_MetaArray[i].bSelect = FALSE;
		}
	}

	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{

		//没有按下左键的移动丢弃
		if ( (nFlags&MK_LBUTTON) != MK_LBUTTON)
		{
			m_bFirstSelect = TRUE;
			m_FirstSelect  = 0;
			return 0;
		}
		// 富文本里面没有数据的 也直接忽略
		if (m_MetaArray.size() < 1)
		{
			m_bFirstSelect = TRUE;
			//m_FirstSelect  = 0; 这个要上面的变成 flase才有意义
			return 0;
		}

		//   |A B C   此时光标索引0
		//    A|B C   此时光标索引1
		//    A B|C   此时光标索引2
		//    A B C|  此时光标索引3

		//左键按下了，此时就要搞选中了。。。
		int currentSelect = m_CaretMetaArrayIndex;

		//点坐标在元数据外矩形中
		BOOL bPtInRect = FALSE;

		for (int i = 0; i < m_MetaArray.size(); i++)
		{
			if (IsPtInRect(pPt,m_MetaArray[i].outerX,m_MetaArray[i].outerY,m_MetaArray[i].outerCX,m_MetaArray[i].outerCY))
			{

				//这里需要做一件事情，点击的位置是在元数据的左边还是右边

				currentSelect = i;
				int metaX = m_MetaArray[currentSelect].innerX;
				int metaY = m_MetaArray[currentSelect].innerY;
				int metaCX= m_MetaArray[currentSelect].innerCX;
				int metaCY= m_MetaArray[currentSelect].innerCY;


				if (pPt->x < metaX + metaCX / 2)
				{
					//左边
					m_Caret.SetHeight(m_MetaArray[currentSelect].innerCY);
					m_Caret.SetPos(metaX,metaY);
					m_CaretMetaArrayIndex = currentSelect;
				}else
				{
					//在当前索引的右边
					if (currentSelect != m_MetaArray.size() -1)
					{
						//如果不是末尾一个，那么光标索引设置到下一个
						
						currentSelect++;
						m_CaretMetaArrayIndex = currentSelect;

						m_Caret.SetPos(m_MetaArray[currentSelect].innerX,m_MetaArray[currentSelect].innerY);
						m_Caret.SetHeight(m_MetaArray[m_CaretMetaArrayIndex].innerCY);
					}
					else
					{
						//光标是末尾一个，那么需要把光标索引设置成 m_MetaArray.size()
						currentSelect = m_MetaArray.size()-1;
						m_CaretMetaArrayIndex = currentSelect+1;

						m_Caret.SetHeight(m_MetaArray[currentSelect].innerCY);
						m_Caret.SetPos(metaX+metaCX,metaY);
					}

				}

				bPtInRect = TRUE;
				break;
			}
		}

		//鼠标光标木有在矩形中，就判断光标是否在每行的末尾
		if (bPtInRect == FALSE)
		{
			//如果不在元素区域，那么现在就必须再次判断了
			
			//判断鼠标点击所在行，然后设置到此行的末尾。。
			
			BOOL bFindRowLast = FALSE;
			for (int i = 0; i < m_MetaArray.size(); i++)
			{
				if (m_MetaArray[i].outerY <= pPt->y && pPt->y <=  m_MetaArray[i].outerY+ m_MetaArray[i].outerCY)
				{
					//现在只是找到行首，还要继续找

					for (int j = i+1; j < m_MetaArray.size(); j++)
					{
						if (m_MetaArray[j].rowIndex != m_MetaArray[i].rowIndex)
						{
							bFindRowLast = TRUE;
							currentSelect = i;
							break;
						}else
						{
							i = j;
						}
					}
					if (bFindRowLast)
					{
						m_Caret.SetHeight(m_MetaArray[i].innerCY);
						m_Caret.SetPos(m_MetaArray[i].innerX,m_MetaArray[i].innerY);
						m_CaretMetaArrayIndex = i;
						XEle_RedrawEle(m_hEditView);
						break;
					}

					
				}
			}
			if (bFindRowLast == FALSE)
			{

				//光标是末尾一个，那么需要把光标索引设置成 m_MetaArray.size()
				currentSelect = m_MetaArray.size();
				m_CaretMetaArrayIndex = m_MetaArray.size() - 1;
				m_Caret.SetHeight(m_MetaArray[currentSelect].innerCY);
				int metaX = m_MetaArray[currentSelect].innerX;
				int metaY = m_MetaArray[currentSelect].innerY;
				m_Caret.SetPos(metaX,metaY);
			}
		}

		//是不是第一次选中
		if (m_bFirstSelect == TRUE)
		{
			//如果是第一次就设置
			m_bFirstSelect = FALSE;
			m_FirstSelect = currentSelect;
			xtrace("第一次选中索引 %d \r\n",currentSelect);

		}else
		{

			//清除所有选中
			ClearSelect();

			xtrace("当前选中项 %d 第一次选中 %d\r\n",currentSelect,m_FirstSelect);
			int firstSelect = 0;
			int EndSelect   = 0;
			
			if (currentSelect > m_FirstSelect)
			{
				firstSelect = m_FirstSelect;
				EndSelect   = currentSelect;
			}else
			{
				firstSelect = currentSelect;
				EndSelect   = m_FirstSelect;
			}
			
			while (firstSelect < EndSelect)
			{
				m_MetaArray[firstSelect].bSelect = TRUE;
				firstSelect++;
			}

		}

		XEle_RedrawEle(m_hEditView);
		return 0;
	}

//////////////////////////////////////////////////////////////////////////

	// A B C|  ___>    A B C   
	// D E F           D E F|         

	// A B|    ___>    A B      
	// D E F           D E|F         

	// A B C|  ___>    A B C    
	// D E             D E|           

	VOID KeyDownCaretMoveDown()
	{
		//无数据直接返回
		if (m_MetaArray.size() < 1)
			return ;

		//在末尾不处理
		if (m_MetaArray.size() == m_CaretMetaArrayIndex)
			return ;

		//判断是否为最后一行，方法直接获取最后一行的行号和当前的比较
		if (m_MetaArray[m_MetaArray.size()-1].rowIndex == m_MetaArray[m_CaretMetaArrayIndex].rowIndex)
		{
			//是最后一行 直接跳到行尾
			int nIndex = m_MetaArray.size() -1;

			int x = m_MetaArray[nIndex].outerX + m_MetaArray[nIndex].outerCX;
			int y = m_MetaArray[nIndex].innerY;
			m_Caret.SetHeight(m_MetaArray[nIndex].innerCY);
			m_Caret.SetPos(x,y);

			m_CaretMetaArrayIndex = m_MetaArray.size();
			return ;
		}
		
		//这里不是最后一行
		
		// 要考虑下一行的列数是否小于当前列
		int nCurColIndex = m_MetaArray[m_CaretMetaArrayIndex].ColIndex;
		int nCurRowIndex = m_MetaArray[m_CaretMetaArrayIndex].rowIndex;

		int nNextRowCaretIndex = m_MetaArray.size()-1;
		
		BOOL IsNextRowLast = FALSE;
		for (int i = m_CaretMetaArrayIndex+1; i < m_MetaArray.size(); i++)
		{
			if (m_MetaArray[i].rowIndex > nCurRowIndex + 1)
			{   //保存下一行的最后一个元素
				nNextRowCaretIndex = i-1;
				IsNextRowLast = TRUE;
				break;
			}
			if (m_MetaArray[i].ColIndex == nCurColIndex)
			{
				//发现目标

				int x = m_MetaArray[i].outerX;
				int y = m_MetaArray[i].innerY;
				m_Caret.SetHeight(m_MetaArray[i].innerCY);
				m_Caret.SetPos(x,y);
				
				m_CaretMetaArrayIndex = i;
				return ;
			}
		}
		//没找到
		int x = m_MetaArray[nNextRowCaretIndex].outerX + m_MetaArray[nNextRowCaretIndex].outerCX;
		int y = m_MetaArray[nNextRowCaretIndex].innerY;
		m_Caret.SetHeight(m_MetaArray[nNextRowCaretIndex].innerCY);
		m_Caret.SetPos(x,y);

		if (IsNextRowLast == FALSE)
			m_CaretMetaArrayIndex = m_MetaArray.size();
		else
			m_CaretMetaArrayIndex = nNextRowCaretIndex;		

	}

	//  A B C    ___>  A B C|
	//  D E F|         D E F

	//  A B      ___>  A B|
	//  D E F|         D E F

	//  A B C    ___>  A B|C
	//  D E|           D E

	VOID KeyDownCaretMoveUp()
	{
		//无数据
		if (m_MetaArray.size() < 1)
			return ;
		
		//光标是否在末尾
		if (m_CaretMetaArrayIndex == m_MetaArray.size())
		{
			//在末尾。。。
			//就到上一行末尾

			if (m_MetaArray[m_CaretMetaArrayIndex-1].rowIndex < 1)
			{
				//这里表示没有了，直接显示首列
				int offsetx = m_MetaArray[0].innerX;
				int offsety = m_MetaArray[0].innerY;
				m_Caret.SetHeight(m_MetaArray[0].innerCY);
				m_Caret.SetPos(offsetx,offsety);
			}else
			{


				m_CaretMetaArrayIndex--; //先修索引
				int nCurCol = m_MetaArray[m_CaretMetaArrayIndex].ColIndex;
				int nPreRowIndex = m_CaretMetaArrayIndex - nCurCol - 1;

				m_CaretMetaArrayIndex -= m_MetaArray[nPreRowIndex].ColIndex;

				int offsetx = m_MetaArray[m_CaretMetaArrayIndex].innerX;
				int offsety = m_MetaArray[m_CaretMetaArrayIndex].innerY;
				m_Caret.SetHeight(m_MetaArray[m_CaretMetaArrayIndex].innerCY);
				m_Caret.SetPos(offsetx,offsety);

			}


			for (int i = 0; i < m_MetaArray.size(); i++)
			{
				xtrace("%d %d \r\n",m_MetaArray[i].rowIndex,m_MetaArray[i].ColIndex);
			}

		

		}else
		{
			//>不在末尾


			// 是否是第一行？如果第一行就直接跳到第0个元数据了
			if (m_MetaArray[m_CaretMetaArrayIndex].rowIndex < 1)
			{
				int offsetx = m_MetaArray[0].innerX;
				int offsety = m_MetaArray[0].innerY;
				m_Caret.SetHeight(m_MetaArray[0].innerCY);
				m_Caret.SetPos(offsetx,offsety);

				m_CaretMetaArrayIndex = 0;
			}else
			{

				//不是第一行
				//则得到上一行末尾的元数据索引
				int nPreRowEndColIndex = m_CaretMetaArrayIndex - m_MetaArray[m_CaretMetaArrayIndex].ColIndex -1;


				//如果上一行的列数小于当前列的列数,则直接显示到上一行的末尾
				if (m_MetaArray[nPreRowEndColIndex].ColIndex < m_MetaArray[m_CaretMetaArrayIndex].ColIndex)
				{
					int offsetx = m_MetaArray[nPreRowEndColIndex].innerX;
					int offsety = m_MetaArray[nPreRowEndColIndex].innerY;
					m_Caret.SetHeight(m_MetaArray[nPreRowEndColIndex].innerCY);
					m_Caret.SetPos(offsetx,offsety);

					m_CaretMetaArrayIndex = nPreRowEndColIndex;
				}else
				{
					//否则直接显示到上一列和这一列相同的列数的地方

					//a b c d e    _> a|b c d e   _>中间光标移动的个数为上一行的个数
					//a|a b           a a b

					m_CaretMetaArrayIndex = m_CaretMetaArrayIndex - m_MetaArray[nPreRowEndColIndex].ColIndex - 1;

					int offsetx = m_MetaArray[m_CaretMetaArrayIndex].innerX;
					int offsety = m_MetaArray[m_CaretMetaArrayIndex].innerY;
					m_Caret.SetHeight(m_MetaArray[m_CaretMetaArrayIndex].innerCY);
					m_Caret.SetPos(offsetx,offsety);


				}

			}
			//找到上一行末尾
			


		}

	}

	VOID KeyDowCaretMoveLeft()
	{
		//分几种情况

		//第一；没有数据，啥都不做
		if (m_MetaArray.size() == 0 || m_CaretMetaArrayIndex == 0)
		{
			//随便提示一下用户，咚的一声
			MessageBeep(-1);
			return ;
		}

		//过滤 换行
		int nCaretIndex = --m_CaretMetaArrayIndex;



		int x = m_MetaArray[nCaretIndex].outerX;
		int y = m_MetaArray[nCaretIndex].outerY + m_MetaArray[nCaretIndex].outerCY - m_MetaArray[nCaretIndex].innerCY;
		m_Caret.SetHeight(m_MetaArray[nCaretIndex].innerCY);
		m_Caret.SetPos(x,y);
		m_Caret.Show(TRUE);
	}

	VOID KeyDowCaretMoveRight()
	{
		//没有数据
		if (m_MetaArray.size() == 0)
		{
			MessageBeep(-1);
			return ;
		}
		if (m_CaretMetaArrayIndex == m_MetaArray.size())
		{
			//到最尾部了，不能移动了
			MessageBeep(-1);
			return ;
		}

		++m_CaretMetaArrayIndex;
		if (m_CaretMetaArrayIndex == m_MetaArray.size())
		{
			//最尾部
			int nCaretIndex= m_CaretMetaArrayIndex-1;

			int x = m_MetaArray[nCaretIndex].outerX + m_MetaArray[nCaretIndex].outerCX;
			int y = m_MetaArray[nCaretIndex].outerY + m_MetaArray[nCaretIndex].outerCY - m_MetaArray[nCaretIndex].innerCY;
			m_Caret.SetHeight(m_MetaArray[nCaretIndex].innerCY);
			m_Caret.SetPos(x,y);
			m_Caret.Show(TRUE);
		}else
		{
			int nCaretIndex= m_CaretMetaArrayIndex;
			int x = m_MetaArray[nCaretIndex].outerX;
			int y = m_MetaArray[nCaretIndex].outerY + m_MetaArray[nCaretIndex].outerCY - m_MetaArray[nCaretIndex].innerCY;
			m_Caret.SetHeight(m_MetaArray[nCaretIndex].innerCY);
			m_Caret.SetPos(x,y);
			m_Caret.Show(TRUE);
		}
		
		


	}

	int OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		switch (wParam)
		{
		case VK_LEFT:
			{
				//【光标左移 显示光标 刷新页面】
				//左键
				KeyDowCaretMoveLeft();
				XEle_RedrawEle(m_hEditView);
			}
			break;
		case VK_UP:
			{
				//【光标上移 显示光标 刷新页面】
				//上键
				KeyDownCaretMoveUp();
				XEle_RedrawEle(m_hEditView);
			}
			break;
		case VK_RIGHT:
			{
				//【光标右移 显示光标 刷新页面】
				//右键
				KeyDowCaretMoveRight();
				XEle_RedrawEle(m_hEditView);
			}
			break;
		case VK_DOWN:
			{
				//【光标下移 显示光标 刷新页面】
				//下键
				KeyDownCaretMoveDown();
				XEle_RedrawEle(m_hEditView);
			}
			break;
		case VK_BACK:
			{
				//【删除字符】
				DelChar();
				//退格键
				*pbHandled = TRUE;
			}
			break;
		}
		return 0;
	}
//////////////////////////////////////////////////////////////////////////


	void AdjustDelCharCaretAndShow()
	{
		//如果是在末尾删除的字符
		if (m_CaretMetaArrayIndex == m_MetaArray.size())
		{
			if (m_MetaArray.size() > 0)
			{   //如果是在末尾，并且已经有数据此时需要计算
				int nEndIndex = m_MetaArray.size()-1;
				int x = m_MetaArray[nEndIndex].outerX + m_MetaArray[nEndIndex].outerCX;
				int y = m_MetaArray[nEndIndex].outerY + m_MetaArray[nEndIndex].outerCY - m_MetaArray[nEndIndex].innerCY;
				m_Caret.SetHeight(m_MetaArray[nEndIndex].innerCY);
				m_Caret.SetPos(x,y);
			}else
			{  //如果在末尾，没有数据，那么就0，0处显示光标
				m_Caret.SetPos(m_RichEditOffsetX,m_RichEditOffsetY);
			}
			m_Caret.Show(TRUE);
		} 
		else
		{
			//如果不是在末尾删除
			m_CaretMetaArrayIndex--;

			int nCaretIndex = m_CaretMetaArrayIndex;
			int x = m_MetaArray[nCaretIndex].outerX;
			int y = m_MetaArray[nCaretIndex].outerY + m_MetaArray[nCaretIndex].outerCY - m_MetaArray[nCaretIndex].innerCY;
			m_Caret.SetHeight(m_MetaArray[nCaretIndex].innerCY);
			m_Caret.SetPos(x,y);
			m_Caret.Show(TRUE);
		}
	}

	void DelChar()
	{
		if (m_MetaArray.size() == 0 || m_CaretMetaArrayIndex == 0)
		{   //没东西可以删的，少年
			MessageBeep(-1);
			return;
		}
		if (m_MetaArray.size() > 0 && m_CaretMetaArrayIndex == -1)
		{
			//删除字符
			std::vector<StructMetadata>::iterator it = m_MetaArray.begin()+m_MetaArray.size()-1;
				

			switch (it->Richtype)
			{
			case RichType_Ele:
				{
					XEle_Destroy(it->mdEle.hEle);
				}
				break;
			case RichType_Shape:
				{
					XShape_Destroy(it->mdShape.hShape);
				}
				break;
			}

			m_MetaArray.erase(it);

		}else if ( m_MetaArray.size() > 0 && m_CaretMetaArrayIndex != -1)
		{

			if (m_CaretMetaArrayIndex > 0)
			{

				std::vector<StructMetadata>::iterator it =m_MetaArray.begin()+m_CaretMetaArrayIndex-1;
					

				switch (it->Richtype)
				{
				case RichType_Ele:
					{
						XEle_Destroy(it->mdEle.hEle);
					}
					break;
				case RichType_Shape:
					{
						XShape_Destroy(it->mdShape.hShape);
					}
					break;
				}

				m_MetaArray.erase(it);
			}else
			{
				MessageBeep(-1);
			}


		}

		//重新计算元素坐标 - 重新计算行列索引
		//分三个步骤
		//第一：计算宽度，先根据宽度调整行列索引，
		//第二: 根据内围，调整外围宽度和高度
		//第三：调整外围 x y，且调整内围 x y
		//第四: 调整光标位置
		
		AdjustIndex(); //第一
		AdjustOuterWidthAndHeight();    //第二
		AdjustOuterPosAndSetInnerPos(); //第三
	
		AdjustDelCharCaretAndShow();//显示光标
		XEle_RedrawEle(m_hEditView);

	}

	//【重新计算元素坐标 - 重新计算行列索引】【重新调整光标位置】
	//大小变化 
	//增加字符 
	//删除字符

	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		if (wParam == VK_BACK)
		{   //过滤
			return 0;
		}

		// dasemimi
		// sese
		//所有数据操作的地方都要过滤掉换行符
		int nInsertIndex = -1;
		if (m_CaretMetaArrayIndex != m_MetaArray.size())
			nInsertIndex  = m_CaretMetaArrayIndex;

		if (wParam == 13)
		{
			AddEnter(wParam,nInsertIndex);
		}else
		{
			AddCh(wParam,nInsertIndex);
		}
		//增加字符
		
// 		for (int i = 0 ; i < 100000; i++)
// 		{
// 			AddCh(wParam);
// 		}

		AddShapeText((wchar_t)wParam);
		AddEleButton();
 		AddEleTextLink();
		AddEleShapeGif(L"打飞机.gif");
		AddImage(L"泪流满面.jpg");

		//重新计算元素坐标 - 重新计算行列索引
		//分三个步骤
		//第一：计算宽度，先根据宽度调整行列索引，
		//第二: 根据内围，调整外围宽度和高度
		//第三：调整外围 x y，且调整内围 x y
		//第四: 调整光标位置

		AdjustIndex(); //第一
		AdjustOuterWidthAndHeight();    //第二
		AdjustOuterPosAndSetInnerPos(); //第三

		AdjustAddCharCaretAndShow();//显示光标
		XEle_RedrawEle(m_hEditView);
		return 0;
	}


//////////////////////////////////////////////////////////////////////////


	//   |A B C   此时光标索引0
	//    A|B C   此时光标索引1
	//    A B|C   此时光标索引2
	//    A B C|  此时光标索引3


	//返回值 0 - m_MetaArray.size();
	BOOL Pt2Index(POINT* pPt,int& nIndex)
	{

		for (int i = 0; i < m_MetaArray.size(); i++)
		{
			if (IsPtInRect(pPt,m_MetaArray[i].outerX,m_MetaArray[i].outerY,m_MetaArray[i].outerCX,m_MetaArray[i].outerCY))
			{
				//判断点击位置在 元数据的 左边还是右边
				int metaX = m_MetaArray[i].outerX;
				int metaY = m_MetaArray[i].outerY;
				int metaCX= m_MetaArray[i].outerCX;
				int metaCY= m_MetaArray[i].outerCY;

				if (pPt->x < metaX + metaCX / 2)
				{
					//左边
					nIndex  = i;
				}else
				{
					//右边
					nIndex  = i + 1;
				}
				
				return TRUE;
			}
		}
		return FALSE;
	}

	//【判断光标在元数据索引】【设置光标坐标】【清除选中】
	//鼠标左键点击

	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		// 第一步 获取点击所在位置

		if ( m_MetaArray.size() == 0)
		{
			//没有数据，就显示到默认位置
			m_Caret.SetPos(m_RichEditOffsetX,m_RichEditOffsetY);
			m_Caret.Show(TRUE);

			return 0;
		} 

		int nIndex = 0;
		if (Pt2Index(pPt,nIndex))
		{
			m_CaretMetaArrayIndex = nIndex;
			
			//显示光标
//			ShowCaret();


			//一切的基础都是以元数据来设置光标的
			//所以要判断元数据是否为空，如果为空就设置到最开始
			
			if ( m_MetaArray.size() == 0)
			{
				//没有数据，就显示到默认位置
				m_Caret.SetPos(m_RichEditOffsetX,m_RichEditOffsetY);
				m_Caret.Show(TRUE);
			} 
			else
			{
				//有数据，看看是不是最末尾？
				
				
				if (m_MetaArray.size() == m_CaretMetaArrayIndex)
				{
					int nIndex = m_MetaArray.size()-1;
					//在末尾
					int offsetx = m_MetaArray[nIndex].innerX + m_MetaArray[nIndex].innerCX;
					int offsety = m_MetaArray[nIndex].innerY;
					m_Caret.SetHeight(m_MetaArray[nIndex].innerCY);
					m_Caret.SetPos(offsetx,offsety);
				}else
				{
					int nIndex = m_CaretMetaArrayIndex;
					int offsetx = m_MetaArray[nIndex].innerX;
					int offsety = m_MetaArray[nIndex].innerY;
					m_Caret.SetHeight(m_MetaArray[nIndex].innerCY);
					m_Caret.SetPos(offsetx,offsety);
				}
				
				m_Caret.Show(TRUE);
		}


			
			//第三步 清除选中
			ClearSelect();
		}else
		{
			//如果不在元素区域，那么现在就必须再次判断了

			//判断鼠标点击所在行，然后设置到此行的末尾。。

			for (int i = 0; i < m_MetaArray.size(); i++)
			{
				if (m_MetaArray[i].outerY < pPt->y && pPt->y <  m_MetaArray[i].outerY+ m_MetaArray[i].outerCY)
				{
					m_Caret.SetHeight(m_MetaArray[i].innerCY);
					m_Caret.SetPos(m_MetaArray[i].innerX,m_MetaArray[i].innerY);
					m_CaretMetaArrayIndex = i;
					XEle_RedrawEle(m_hEditView);

					m_bFirstSelect = FALSE;
					m_FirstSelect = m_CaretMetaArrayIndex;

					return 0;

				}
			}

			//否则显示到末尾
			int nIndex = m_MetaArray.size()-1;
			//在末尾
			int offsetx = m_MetaArray[nIndex].innerX + m_MetaArray[nIndex].innerCX;
			int offsety = m_MetaArray[nIndex].innerY;
			m_Caret.SetHeight(m_MetaArray[nIndex].innerCY);
			m_Caret.SetPos(offsetx,offsety);
			m_CaretMetaArrayIndex = m_MetaArray.size();
		}

		//鼠标左键按下，有可能是要选中

		m_bFirstSelect = FALSE;
		m_FirstSelect = m_CaretMetaArrayIndex;

//		LeftButtonDownSetCaretAndClearSelect(pPt);
		XEle_RedrawEle(m_hEditView);
		return 0;
	}



	//【将选中区域连接起来形成多个选中】
	//左键松开
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		return 0;
	}

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{	
		int x = 0;
		int y = 0;
//		XDraw_GetOffset(hDraw,&x,&y);
 		
// 		XDraw_TextOut(hDraw,10-x,10-y,L"大色秘密",4);

		
		for (int i = 0; i < m_MetaArray.size(); i++)
		{
			XDraw_SetBrushColor(hDraw,RGB(0,0,128));

			switch (m_MetaArray[i].Richtype)
			{
			case RichType_char:
				x = m_MetaArray[i].innerX;
				y = m_MetaArray[i].innerY;
				XDraw_TextOut(hDraw,x,y,&m_MetaArray[i].mdChar.ch,1);
				break;
			case RichType_Image:
				x = m_MetaArray[i].innerX;
				y = m_MetaArray[i].innerY;
				XDraw_Image(hDraw,m_MetaArray[i].mdImage.hImage,x,y);
				break;
			}

			//如果选中
			if (m_MetaArray[i].bSelect)
			{
				RECT rt = {m_MetaArray[i].innerX,m_MetaArray[i].innerY,
				m_MetaArray[i].innerX+m_MetaArray[i].innerCX,
				m_MetaArray[i].innerY+m_MetaArray[i].innerCY};
				XDraw_FillRectColor(hDraw,&rt,RGB(0,128,0),128);
			}
		}
		return 0;
	}
private:

	VOID AddShapeText(wchar_t ch,int insertPos = -1)
	{
		wchar_t chArray[2] = {0};
		chArray[0] = ch;

		StructMetadata md;
		md.Richtype = RichType_Shape;
		md.bSelect = FALSE;
		md.mdShape.hShape = XShapeText_Create(0,0,10,10,chArray,m_hEditView);
		if (insertPos != -1)
		{
			m_MetaArray.insert(m_MetaArray.begin()+insertPos,md); 
		}else
		{
			m_MetaArray.push_back(md);
		}	
	}
	void AddEleShapeGif(const wchar_t* lpGifFile,int insertPos = -1)
	{
		StructMetadata md;
		md.Richtype = RichType_Shape;
		md.bSelect = FALSE;
		md.mdShape.hShape = XShapeGif_Create(0,0,100,100,m_hEditView);
		XShapeGif_SetImage(md.mdShape.hShape,XImage_LoadFile(lpGifFile));

		if (insertPos != -1)
		{
			m_MetaArray.insert(m_MetaArray.begin()+insertPos,md); 
		}else
		{
			m_MetaArray.push_back(md);
		}	
	}
	

	void AddEleTextLink(int insertPos = -1)
	{
		StructMetadata md;
		md.Richtype = RichType_Ele;
		md.bSelect = FALSE;
		md.mdEle.hEle = XTextLink_Create(0,0,100,25,L"链接文本",m_hEditView);
		
		//光标处增加按钮
		if (insertPos != -1)
		{
			m_MetaArray.insert(m_MetaArray.begin()+insertPos,md); 
		}else
		{
			m_MetaArray.push_back(md);
		}	
	}

	void AddEleButton(int insertPos = -1)
	{
		StructMetadata md;
		md.Richtype = RichType_Ele;
		md.bSelect = FALSE;
		md.mdEle.hEle = XBtn_Create(0,0,100,25,L"测试按钮",m_hEditView);

		//光标处增加按钮
		if (insertPos != -1)
		{
			m_MetaArray.insert(m_MetaArray.begin()+insertPos,md); 
		}else
		{
			m_MetaArray.push_back(md);
		}	
	}

	void AddImage(const wchar_t* pImageFile,int insertPos = -1)
	{
		StructMetadata md;
		md.Richtype = RichType_Image;
		md.bSelect = FALSE;
		md.mdImage.hImage = XImage_LoadFile(pImageFile);
		//光标处增加字符
		if (insertPos != -1)
		{
			m_MetaArray.insert(m_MetaArray.begin()+insertPos,md); 
		}else
		{
			m_MetaArray.push_back(md);
		}	
	}

	VOID AddEnter(wchar_t ch,int insertPos = -1)
	{
		StructMetadata md;
		md.Richtype = RichType_Enter;
		md.mdEnter.ch = ch;
		md.bSelect = FALSE;
		//光标处增加字符
		if (insertPos != -1)
		{
			m_MetaArray.insert(m_MetaArray.begin()+insertPos,md);
		}else
		{
			m_MetaArray.push_back(md);
		}
	}
	
	VOID AddCh(wchar_t ch,int insertPos = -1)
	{
		StructMetadata md;
		md.Richtype = RichType_char;
		md.mdChar.ch = ch;
		md.mdChar.font = m_DefaultFont;
		md.bSelect = FALSE;
		//光标处增加字符
		if (insertPos != -1)
		{
			m_MetaArray.insert(m_MetaArray.begin()+insertPos,md);
		}else
		{
			m_MetaArray.push_back(md);
		}
	}

	//调整索引
	void CalcInnerCharSetSize(StructMetadata& md)
	{
		SIZE sz;
		XC_GetTextShowSize(&md.mdChar.ch,1,md.mdChar.font,&sz);
		md.innerCX = sz.cx;
		md.innerCY = sz.cy;
	}
	void CalcInnerEnterSetSize(StructMetadata& md)
	{
		md.innerCX = 0;
		md.innerCY = 12;
	}
	void CalcInnerImageSetSize(StructMetadata& md)
	{
		//mdImage.hImage
		//暂时固定死吧，大小50*50
		md.innerCX = 50;
		md.innerCY = 50;
	}
	void CalcInnerEleSetSize(StructMetadata& md)
	{
		md.innerCX = XEle_GetWidth(md.mdEle.hEle);
		md.innerCY = XEle_GetHeight(md.mdEle.hEle);
	}
	void CalcInnerShapeSetSize(StructMetadata& md)
	{
		md.innerCX = XShape_GetWidth(md.mdShape.hShape);
		md.innerCY = XShape_GetHeight(md.mdShape.hShape);
	}
	VOID AdjustIndex()
	{
		int rowIndex = 0;
		int colIndex = 0;

		//获取可视部分大小

		int viewWidth = XSView_GetViewWidth(m_hView);

		int currentWidth = 0;
		int metaWidth = 0;

		for (int i = 0; i < m_MetaArray.size(); i++)
		{
			switch (m_MetaArray[i].Richtype)
			{
			case RichType_char:
				{
					CalcInnerCharSetSize(m_MetaArray[i]);
				}
				break;
			case RichType_Enter:
				{
					//这个比较特殊，他的尺寸要和前一个相等
					//如果没有前一个就默认大小
					if ( i > 1)
					{
						
						m_MetaArray[i].innerCY = m_MetaArray[i-1].innerCY;
						m_MetaArray[i].innerCX = 0;
						xtrace("%d \r\n",m_MetaArray[i].innerCY);
					}else
					{
						CalcInnerEnterSetSize(m_MetaArray[i]);
					}
					
				}
				break;
			case RichType_Image:
				{
					CalcInnerImageSetSize(m_MetaArray[i]);
				}
				break;
			case RichType_Ele:
				{
					CalcInnerEleSetSize(m_MetaArray[i]);
				}
				break;
			case RichType_Shape:
				{
					CalcInnerShapeSetSize(m_MetaArray[i]);
				}
				break;
			}
			metaWidth = m_MetaArray[i].innerCX;

			if ( currentWidth + metaWidth < viewWidth )
			{
				m_MetaArray[i].rowIndex = rowIndex;
				m_MetaArray[i].ColIndex = colIndex;
			
				//如果是换行，必须马上调整
				if (m_MetaArray[i].Richtype == RichType_Enter)
				{
					rowIndex++;
					colIndex = 0;
					currentWidth = 0;
				}else
				{
					colIndex++;
				}

			}else
			{
				rowIndex++;
				colIndex = 0;
				currentWidth = 0;
				m_MetaArray[i].rowIndex = rowIndex;
				m_MetaArray[i].ColIndex = colIndex;
				colIndex++;
			}
			currentWidth += metaWidth;
		}
	}

	VOID AdjustOuterWidthAndHeight()
	{
		std::vector<int> rowHeightArray;
		int nRowMaxHeight = 0;
		int nCurrentRow   = 0;

		for (int i = 0; i < m_MetaArray.size(); i++)
		{
			if (m_MetaArray[i].rowIndex != nCurrentRow)
			{
				//保存行高
				rowHeightArray.push_back(nRowMaxHeight);
				nRowMaxHeight = 0;
				nCurrentRow = m_MetaArray[i].rowIndex;
			}
			
			//找到行高
			if (nRowMaxHeight < m_MetaArray[i].innerCY)
			{
				nRowMaxHeight = m_MetaArray[i].innerCY;
			}
			//调整外围元素宽度
			m_MetaArray[i].outerCX = m_MetaArray[i].innerCX;
		}
		//因为上面的for循环保存的是上一次的，当前的还没有保存
		//所以还要处理一次
		rowHeightArray.push_back(nRowMaxHeight);

		//调整行元素cy 为最大的 cy

		
		for (int j = 0; j < m_MetaArray.size(); j++)
		{
			m_MetaArray[j].outerCY = rowHeightArray[ m_MetaArray[j].rowIndex];
		}

		int viewHeight = 0;
		for (int k = 0; k < rowHeightArray.size(); k++)
		{
			 viewHeight += rowHeightArray[k];
		}

		//调整视图高度，和视图元素高度
		RECT rtEleView;
		XEle_GetRect(m_hEditView,&rtEleView);

		if (viewHeight < rtEleView.bottom - rtEleView.top)
		{
			XEle_SetRect(m_hEditView,&rtEleView);
			XSView_SetTotalSize(m_hView,rtEleView.right - rtEleView.left,rtEleView.bottom - rtEleView.top);

		}else
		{
			rtEleView.bottom = rtEleView.top + viewHeight;
			XEle_SetRect(m_hEditView,&rtEleView);
			XSView_SetTotalSize(m_hView,rtEleView.right - rtEleView.left,rtEleView.bottom - rtEleView.top);
		}

		
		
		

	}


	VOID AdjustOuterPosAndSetInnerPos()
	{
		int offsetX = 10;
		int x = offsetX;
		int y = 0;
		int rowIndex = 0;
		int	lastHeight = 0;
		int	lastWidth  = 0;


		for (int i = 0; i < m_MetaArray.size(); i++)
		{
			if ( rowIndex != m_MetaArray[i].rowIndex )
			{   //复位
				y+=lastHeight;
				x = offsetX;
				rowIndex = m_MetaArray[i].rowIndex;
			}else
			{
				lastHeight = m_MetaArray[i].outerCY;
			}

			m_MetaArray[i].outerX = x;
			m_MetaArray[i].outerY = y;
			
			x+= m_MetaArray[i].innerCX;

			//外围调整完毕，根据外围调整内围
			int innery = m_MetaArray[i].outerY + m_MetaArray[i].outerCY- m_MetaArray[i].innerCY;
			int innerx = m_MetaArray[i].outerX;
			m_MetaArray[i].innerX = innerx;
			m_MetaArray[i].innerY = innery;

			switch (m_MetaArray[i].Richtype)
			{
			case RichType_Ele:
				{
					RECT rtEle;
					rtEle.left = innerx;
					rtEle.top  = innery;
					rtEle.right = innerx + XEle_GetWidth(m_MetaArray[i].mdEle.hEle);
					rtEle.bottom = innery + XEle_GetHeight(m_MetaArray[i].mdEle.hEle);
					XEle_SetRect(m_MetaArray[i].mdEle.hEle,&rtEle);
				}
				break;
			case RichType_Shape:
				{
					RECT rtEle;
					rtEle.left = innerx;
					rtEle.top  = innery;
					rtEle.right = innerx + XShape_GetWidth(m_MetaArray[i].mdShape.hShape);
					rtEle.bottom = innery + XShape_GetHeight(m_MetaArray[i].mdShape.hShape);
					XShape_SetRect(m_MetaArray[i].mdShape.hShape,&rtEle);
				}
				break;
			}

		}

	}

	void AdjustAddCharCaretAndShow()
	{
		//字符增加一个，光标就要移动一个
		m_CaretMetaArrayIndex++;
		int index = m_CaretMetaArrayIndex;

		if (index == m_MetaArray.size())
		{ //在末尾
			index = m_MetaArray.size()-1;

			//这里要判断是否是换行符
			if (m_MetaArray[index].Richtype == RichType_Enter)
			{
				//找到行首
				xtracew(L"%d \r\n",m_MetaArray[index].ColIndex);
				index -= m_MetaArray[index].ColIndex;

				int x = m_MetaArray[index].innerX;
				int y = m_MetaArray[index].innerY+m_MetaArray[index].innerCY;

				m_Caret.SetHeight(12);
				m_Caret.SetPos(x,y);
			}else
			{
				int x = m_MetaArray[index].innerX + m_MetaArray[index].innerCX;
				int y = m_MetaArray[index].innerY;
				m_Caret.SetHeight(m_MetaArray[index].innerCY);
				m_Caret.SetPos(x,y);
			}
			
		} 
		else
		{
			int x = m_MetaArray[index].innerX;
			int y = m_MetaArray[index].innerY;
			m_Caret.SetHeight(m_MetaArray[index].innerCY);
			m_Caret.SetPos(x,y);		
		}

		m_Caret.Show(TRUE);
		
	}
//////////////////////////////////////////////////////////////////////////

private:
	HELE m_hView;
	HELE m_hEditView;
	std::vector<StructMetadata> m_MetaArray;

	XCaret         m_Caret;
	int            m_CaretMetaArrayIndex;;
	HFONTX         m_DefaultFont;

	BOOL		   m_bFirstSelect;
	int		       m_FirstSelect;

	int   m_RichEditOffsetX;
	int   m_RichEditOffsetY;
};


class CListViewEx
{
public:
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_hListView = XSView_Create(x,y,cx,cy,hParent);
		m_RowSpace = 10;
		m_ColSpace = 10;
		m_ItemSize.cx = 40;
		m_ItemSize.cy = 40;
		XEle_RegEventCPP(m_hListView,XE_SIZE,&CListViewEx::OnSize);
		return m_hListView;
	}
	int OnSize(BOOL *pbHandled)
	{
		return 0;
	}
	int AddEle(HELE hEleItem)
	{
		XEle_AddEle(m_hListView,hEleItem);
		m_hEleArray.push_back(hEleItem);
		return m_hEleArray.size() - 1;
	}
	VOID SetRowSpace(int nSpace)
	{
		m_RowSpace = nSpace;
	}
	VOID SetColumnSpace(int nSpace)
	{
		m_ColSpace = nSpace;
	}
	VOID SetItemSize(int cx,int cy)
	{
		m_ItemSize.cx = cx;
		m_ItemSize.cy = cy;
	}
private:
	HELE m_hListView;
	std::vector<HELE> m_hEleArray;
	int m_RowSpace;
	int m_ColSpace;

	SIZE m_ItemSize;

	int m_ViewRowMaxShowCount;
	int m_ViewColMaxShowCount;
};




enum ShapeEditType_
{
	ShapeEditType_HexChar,
	ShapeEditType_Char,
};

class CHexEdit
{
public:
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_x = x;
		m_y = y;
		m_cx = cx;
		m_cy = cy;


// 		XEle_RegEventCPP(m_hEditView,XE_PAINT,&CRichEdit::OnDraw);
// 		XEle_RegEventCPP(m_hEditView,XE_LBUTTONDOWN,&CRichEdit::OnLButtonDown);
// 		XEle_RegEventCPP(m_hEditView,XE_LBUTTONUP,&CRichEdit::OnLButtonUp);
// 		XEle_RegEventCPP(m_hEditView,XE_CHAR,&CRichEdit::OnEventChar);
// 		XEle_RegEventCPP(m_hEditView,XE_KEYDOWN,&CRichEdit::OnEventKeyDown);
// 		XEle_RegEventCPP(m_hEditView,XE_MOUSEMOVE,&CRichEdit::OnMouseMove);

	}

private:

	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		switch (m_VitualFocusIndex)
		{
		case ShapeEditType_HexChar:
			{

			}
			break;
		case ShapeEditType_Char:
			{

			}
			break;
		}

		return 0;
	}
	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		//复位左键按下移动标志
		m_bMouseMoveWithLButtonDown = FALSE;




		//判断光标所在hex位置，还是 char位置
		//根据位置设置高亮

		return 0;
	}
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{
		//没有按下左键的移动丢弃
		if ( (nFlags&MK_LBUTTON) != MK_LBUTTON)
		{
			return 0;
		}

		//鼠标左键按下并且移动了。。
		m_bMouseMoveWithLButtonDown = TRUE;


		//设置 左键按下移动标志
		return 0;
	}
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{

		return 0;
	}


	int OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		switch (wParam)
		{
		case VK_LEFT:
			{
				//【光标左移 显示光标 刷新页面】
				//左键
			}
			break;
		case VK_UP:
			{
				//【光标上移 显示光标 刷新页面】
				//上键
			}
			break;
		case VK_RIGHT:
			{
				//【光标右移 显示光标 刷新页面】
				//右键
			}
			break;
		case VK_DOWN:
			{
				//【光标下移 显示光标 刷新页面】
				//下键
			}
			break;
		case VK_BACK:
			{
				//退格键
				*pbHandled = TRUE;
			}
			break;
		}
		return 0;
	}

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		//绘制 
	}

private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;

	int m_VitualFocusIndex;
	BOOL m_bMouseMoveWithLButtonDown;
};



//主要功能，把hex编辑器的界面画出来，做为显示，至于交互，交给其他模块了

class XHexMemDC
{
public:
	void Create(int cx,int cy,HELE hEle)
	{
		m_MemDc.Create(XEle_GetHWND(hEle));
		m_MemDc.Resize(cx,cy);
		m_nRowHeight = m_MemDc.GetTextHeight(L"炫",1);
	}



	void Draw(HDRAW hDraw)
	{
		m_MemDc.BitBlt1(hDraw);
	}

private:

	void Paint()
	{
		//先填充背景
		HGDIOBJ oldObj = m_MemDc.SelectObject(m_MemDc.GetStockObject(DC_BRUSH));
		m_MemDc.SetDCBrushColor(RGB(255,255,255));
		m_MemDc.FillRect(0,0,m_MemDc.GetBitMapWidth(),m_MemDc.GetBitMapHeight());
		m_MemDc.SelectObject(oldObj);

		//画表头

	}


private:
	XGDIMEMDC m_MemDc;

	int m_nRowHeight;
};


#endif // GDIPack_h__