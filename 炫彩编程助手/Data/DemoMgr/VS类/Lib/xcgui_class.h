#ifndef xcgui_class_h__
#define xcgui_class_h__
/********************************************************************
created:	2016/03/31
created:	31:3:2016   14:11
filename: 	xcgui_class.h
file path:	
file base:	xcgui_class
file ext:	h
author:		dasemimi
ver:        2.1.1
modify      2017年4月1日18:30:53
purpose:	use xcgui easily
*********************************************************************/
//包含炫彩界面库文件
#include "xcgui.h"
#pragma comment(lib, "XCGUI.lib")
#include <assert.h>

namespace xcgui
{

	class XTemplate
	{
	public:
		XTemplate()
		{
			m_template = NULL;
		}
		~XTemplate()
		{
			if (m_template)
			{
				XTemp_Destroy(m_template);
				m_template = NULL;
			}
		}
		void Load(XC_OBJECT_TYPE nType,const wchar_t* pTemplateFileName)
		{
			m_template = XTemp_Load(nType,pTemplateFileName);
			assert(m_template != NULL);
		}
		operator HTEMP()
		{
			return m_template;
		}
	private:
		HTEMP m_template;
};

class XBkM
{
public:
	HBKM hBkInfoM;
	XBkM()
	{
	}
	XBkM(HBKM hBkInfoMIn)
	{
		hBkInfoM = hBkInfoMIn;
	}
	HBKM Create()
	{
		return  XBkM_Create();
	}
	void Destroy()
	{
		XBkM_Destroy(hBkInfoM);
	}
	int SetBkInfo(const wchar_t *pText)
	{
		return  XBkM_SetBkInfo(hBkInfoM, pText);
	}
	int AddInfo(const wchar_t *pText)
	{
		return XBkM_AddInfo(hBkInfoM,pText);
	}
	
	void AddBorder(int nState, COLORREF color, BYTE alpha, int width)
	{
		XBkM_AddBorder(hBkInfoM, nState, color, alpha, width);
	}
	void AddFill(int nState, COLORREF color, BYTE alpha)
	{
		XBkM_AddFill(hBkInfoM, nState, color, alpha);
	}
	void AddImage(int nState, HIMAGE hImage)
	{
		XBkM_AddImage(hBkInfoM, nState, hImage);
	}
	int GetCount()
	{
		return  XBkM_GetCount(hBkInfoM);
	}
	void Clear()
	{
		XBkM_Clear(hBkInfoM);
	}
	BOOL Draw(int nState, HDRAW hDraw, RECT *pRect)
	{
		return  XBkM_Draw(hBkInfoM, nState, hDraw, pRect);
	}
	BOOL DrawEx(int nState, HDRAW hDraw, RECT *pRect, int nStateFilter)
	{
		return  XBkM_DrawEx(hBkInfoM, nState, hDraw, pRect, nStateFilter);
	}
};

class XLayout
{
public:
	HXCGUI hLayout;
	XLayout()
	{
		Create();
	}
	XLayout(HXCGUI hLayoutIn)
	{
		hLayout = hLayoutIn;
	}
	XLayout(HWINDOW hWindow,int nID)
	{
		CreateFromLayoutID(hWindow,nID);
	}
	XLayout(HWINDOW hWindow,const wchar_t *pName)
	{
		CreateFromLayoutResIDValue(hWindow,pName);
	}
	XLayout(layout_size_type_ nWidthType,int nWith,layout_size_type_ nHeightType,int nHeight )
	{
		Create(nWidthType,nWith,nHeightType,nHeight);
	}
	BOOL CreateFromLayoutID(HWINDOW hWindow,int nID)
	{
		hLayout = XC_GetObjectByID(hWindow,nID);
		return hLayout?TRUE:FALSE;
	}
	BOOL CreateFromLayoutResIDValue(HWINDOW hWindow,const wchar_t *pName)
	{
		hLayout = XC_GetObjectByIDName(hWindow,pName);
		return hLayout?TRUE:FALSE;
	}
	operator BOOL()
	{
		return hLayout?TRUE:FALSE;
	}
	operator bool()
	{
		return hLayout?TRUE:FALSE;
	}
	operator HXCGUI()
	{
		return hLayout;
	}
	BOOL Create(layout_size_type_ nWidthType,int nWith,layout_size_type_ nHeightType,int nHeight)
	{
		BOOL bOk = Create();
		SetLayoutWidth(nWidthType,nWith);
		SetLayoutHeight(nHeightType,nHeight);
		return bOk;
	}
public:
	BOOL Create()
    {
		hLayout = XLayout_Create();
        return hLayout?TRUE:FALSE;
    }
    void Destroy()
    {
        XLayout_Destroy(hLayout);
    }
    void AddEle(HELE hEle)
    {
        XLayout_AddEle(hLayout, hEle);
    }
    void AddLayoutObject(HXCGUI hLayoutObject)
    {
        XLayout_AddLayoutObject(hLayout, hLayoutObject);
    }
    void AddShape(HXCGUI hShape)
    {
        XLayout_AddShape(hLayout, hShape);
    }
    BOOL Add(HXCGUI hChild)
    {
        return  XLayout_Add(hLayout, hChild);
    }
    BOOL Insert(HXCGUI hChild, int index)
    {
        return  XLayout_Insert(hLayout, hChild, index);
    }
    void RemoveLayout()
    {
        XLayout_RemoveLayout(hLayout);
    }
    void RemoveChild(HXCGUI hChild)
    {
        XLayout_RemoveChild(hLayout, hChild);
    }
    int GetZOrder(HXCGUI hChild)
    {
        return  XLayout_GetZOrder(hLayout, hChild);
    }
    void AdjustLayout()
    {
        XLayout_AdjustLayout(hLayout);
    }
    void SetRectFrame(RECT *pRect)
    {
        XLayout_SetRectFrame(hLayout, pRect);
    }
    void GetRect(out_ RECT *pRect)
    {
        XLayout_GetRect(hLayout, pRect);
    }
    void GetRectFrame(out_ RECT *pRect)
    {
        XLayout_GetRectFrame(hLayout, pRect);
    }
    HWINDOW GetWindow()
    {
        return  XLayout_GetWindow(hLayout);
    }
    HELE GetEle()
    {
        return  XLayout_GetEle(hLayout);
    }
    HXCGUI GetParentLayout()
    {
        return  XLayout_GetParentLayout(hLayout);
    }
    HXCGUI GetParent()
    {
        return  XLayout_GetParent(hLayout);
    }
    void SetID(int nID)
    {
        XLayout_SetID(hLayout, nID);
    }
    int GetID()
    {
        return  XLayout_GetID(hLayout);
    }
    void SetHorizon(BOOL bHorizon)
    {
        XLayout_SetHorizon(hLayout, bHorizon);
    }
    void SetAlignH(layout_align_ nAlign)
    {
        XLayout_SetAlignH(hLayout, nAlign);
    }
    void SetAlignV(layout_align_ nAlign)
    {
        XLayout_SetAlignV(hLayout, nAlign);
    }
    void SetPadding(int left, int top, int right, int bottom)
    {
        XLayout_SetPadding(hLayout, left, top, right, bottom);
    }
    void SetSpace(int nSpace)
    {
        XLayout_SetSpace(hLayout, nSpace);
    }
    void SetLayoutWidth(layout_size_type_ nType, int nWidth)
    {
        XLayout_SetLayoutWidth(hLayout, nType, nWidth);
    }
    void SetLayoutHeight(layout_size_type_ nType, int nHeight)
    {
        XLayout_SetLayoutHeight(hLayout, nType, nHeight);
    }
    void GetLayoutWidth(out_ layout_size_type_ * pType, out_ int *pWidth)
    {
        XLayout_GetLayoutWidth(hLayout, pType, pWidth);
    }
    void GetLayoutHeight(out_ layout_size_type_ * pType, out_ int *pHeight)
    {
        XLayout_GetLayoutHeight(hLayout, pType, pHeight);
    }
    int GetWidth()
    {
        return  XLayout_GetWidth(hLayout);
    }
    int GetHeight()
    {
        return  XLayout_GetHeight(hLayout);
    }
    int GetWidthIn()
    {
        return  XLayout_GetWidthIn(hLayout);
    }
    int GetHeightIn()
    {
        return  XLayout_GetHeightIn(hLayout);
    }
    void GetContentSize(out_ SIZE *pSize)
    {
        XLayout_GetContentSize(hLayout, pSize);
    }
    void ShowLayout(BOOL bShow)
    {
        XLayout_ShowLayout(hLayout, bShow);
    }
    int GetChildCount()
    {
        return  XLayout_GetChildCount(hLayout);
    }
    XC_OBJECT_TYPE GetChildType(int index)
    {
        return  XLayout_GetChildType(hLayout, index);
    }
    HXCGUI GetChild(int index)
    {
        return  XLayout_GetChild(hLayout, index);
    }
    void Draw(HDRAW hDraw)
    {
        XLayout_Draw(hLayout, hDraw);
    }
	void SetUID(int nUID)
	{
		XLayout_SetUID(hLayout,nUID);
	}
	int GetUID()
	{
		return XLayout_GetUID(hLayout);
	}
	
};

class XWndBase
{

public:
	HWINDOW hWindow;
	operator HXCGUI()
	{
		return hWindow;
	}
	operator HWINDOW()
	{
		return hWindow;
	}
	operator HWND()
	{
		return XWnd_GetHWND(hWindow);
	}
	operator BOOL()
	{
		return hWindow?TRUE:FALSE;
	}
public:
	void RegEventC(int nEvent, void *pFun)
	{
		XWnd_RegEventC(hWindow, nEvent, pFun);
	}
	void RegEventC1(int nEvent, void *pFun)
	{
		XWnd_RegEventC1(hWindow, nEvent, pFun);
	}
	BOOL XWnd_RemoveEventC(int nEvent, void *pFun)
	{
		return  XWnd_RemoveEventC(nEvent, pFun);
	}
	BOOL AddEle(HELE hEle)
	{
		return  XWnd_AddEle(hWindow, hEle);
	}
	BOOL InsertEle(HELE hChildEle, int index)
	{
		return  XWnd_InsertEle(hWindow, hChildEle, index);
	}
	BOOL AddShape(HXCGUI hShape)
	{
		return  XWnd_AddShape(hWindow, hShape);
	}
	HWND GetHWND()
	{
		return  XWnd_GetHWND(hWindow);
	}
	void EnableDragBorder(BOOL bEnable)
	{
		XWnd_EnableDragBorder(hWindow, bEnable);
	}
	void EnableDragWindow(BOOL bEnable)
	{
		XWnd_EnableDragWindow(hWindow, bEnable);
	}
	void EnableDragCaption(BOOL bEnable)
	{
		XWnd_EnableDragCaption(hWindow, bEnable);
	}
	void EnableDrawBk(BOOL bEnable)
	{
		XWnd_EnableDrawBk(hWindow, bEnable);
	}
	void EnableAutoFocus(BOOL bEnable)
	{
		XWnd_EnableAutoFocus(hWindow, bEnable);
	}
	void EnableMaxWindow(BOOL bEnable)
	{
		XWnd_EnableMaxWindow(hWindow, bEnable);
	}
	void RedrawWnd(BOOL bImmediate = FALSE)
	{
		XWnd_RedrawWnd(hWindow, bImmediate);
	}
	void RedrawWndRect(RECT *pRect, BOOL bImmediate =  FALSE)
	{
		XWnd_RedrawWndRect(hWindow, pRect, bImmediate);
	}
	void SetFocusEle(HELE hFocusEle)
	{
		XWnd_SetFocusEle(hWindow, hFocusEle);
	}
	HELE GetFocusEle()
	{
		return  XWnd_GetFocusEle(hWindow);
	}
	HELE GetStayHELE()
	{
		return  XWnd_GetStayHELE(hWindow);
	}
	void SetCursor(HCURSOR hCursor)
	{
		XWnd_SetCursor(hWindow, hCursor);
	}
	HCURSOR GetCursor()
	{
		return  XWnd_GetCursor(hWindow);
	}
	HCURSOR SetCursorSys(HCURSOR hCursor)
	{
		return  XWnd_SetCursorSys(hWindow, hCursor);
	}
	void SetFont(HFONTX hFontx)
	{
		XWnd_SetFont(hWindow, hFontx);
	}
	void SetID(int nID)
	{
		XWnd_SetID(hWindow, nID);
	}
	int GetID()
	{
		return  XWnd_GetID(hWindow);
	}
	void SetCaptureEle(HELE hEle)
	{
		XWnd_SetCaptureEle(hWindow, hEle);
	}
	HELE GetCaptureEle()
	{
		return  XWnd_GetCaptureEle(hWindow);
	}
	BOOL BindLayoutEle(window_position_ nPosition, HELE hEle)
	{
		return  XWnd_BindLayoutEle(hWindow, nPosition, hEle);
	}
	HELE GetLayoutEle(window_position_ nPosition)
	{
		return  XWnd_GetLayoutEle(hWindow, nPosition);
	}
	void BindLayoutObject(window_position_ nPosition, HXCGUI hLayout)
	{
		XWnd_BindLayoutObject(hWindow, nPosition, hLayout);
	}
	XLayout GetLayoutObject(window_position_ nPosition)
	{
		XLayout Layout(XWnd_GetLayoutObject(hWindow, nPosition));
		return  Layout;
	}
	void SetLayoutSize(int left, int top, int right, int bottom)
	{
		XWnd_SetLayoutSize(hWindow, left, top, right, bottom);
	}
	void GetLayoutSize(out_ BorderSize_i * pBorderSize)
	{
		XWnd_GetLayoutSize(hWindow, pBorderSize);
	}
	void SetDragBorderSize(int left, int top, int right, int bottom)
	{
		XWnd_SetDragBorderSize(hWindow, left, top, right, bottom);
	}
	void GetDragBorderSize(out_ BorderSize_i* pSize)
	{
		XWnd_GetDragBorderSize(hWindow, pSize);
	}
	void SetMinimumSize(int width, int height)
	{
		XWnd_SetMinimumSize(hWindow, width, height);
	}
	HELE HitChildEle(POINT *pPt)
	{
		return  XWnd_HitChildEle(hWindow, pPt);
	}
	int GetChildCount()
	{
		return  XWnd_GetChildCount(hWindow);
	}
	HELE GetChildByIndex(int index)
	{
		return  XWnd_GetChildByIndex(hWindow, index);
	}
	HELE GetChildByID(int nID)
	{
		return  XWnd_GetChildByID(hWindow, nID);
	}
	HELE GetEle(int nID)
	{
		return  XWnd_GetEle(hWindow, nID);
	}
	int GetChildShapeCount()
	{
		return  XWnd_GetChildShapeCount(hWindow);
	}
	HXCGUI GetChildShapeByIndex(int index)
	{
		return  XWnd_GetChildShapeByIndex(hWindow, index);
	}
	void GetDrawRect(RECT *pRcPaint)
	{
		XWnd_GetDrawRect(hWindow, pRcPaint);
	}
	BOOL ShowWindow(int nCmdShow)
	{
		return  XWnd_ShowWindow(hWindow, nCmdShow);
	}
	void AdjustLayout()
	{
		XWnd_AdjustLayout(hWindow);
	}
	void AdjustLayoutObject()
	{
		XWnd_AdjustLayoutObject(hWindow);
	}
	void CloseWindow()
	{
		XWnd_CloseWindow(hWindow);
	}
	void CreateCaret(HELE hEle, int x,int y,int width, int height)
	{
		XWnd_CreateCaret(hWindow, hEle,x,y,width, height);
	}
	void SetCaretSize(int width, int height)
	{
		XWnd_SetCaretSize(hWindow, width, height);
	}
	void SetCaretPos(int x, int y)
	{
		XWnd_SetCaretPos(hWindow, x, y);
	}
	void SetCaretPosEx(int x, int y, int width, int height)
	{
		XWnd_SetCaretPosEx(hWindow, x, y, width, height);
	}
	void SetCaretColor(COLORREF color)
	{
		XWnd_SetCaretColor(hWindow, color);
	}
	void ShowCaret(BOOL bShow)
	{
		XWnd_ShowCaret(hWindow, bShow);
	}
	void DestroyCaret()
	{
		XWnd_DestroyCaret(hWindow);
	}
	HELE GetCaretHELE()
	{
		return  XWnd_GetCaretHELE(hWindow);
	}
	BOOL GetClientRect(out_ RECT *pRect)
	{
		return  XWnd_GetClientRect(hWindow, pRect);
	}
	void GetBodyRect(out_ RECT *pRect)
	{
		XWnd_GetBodyRect(hWindow, pRect);
	}
	UINT SetTimer(UINT nIDEvent, UINT uElapse)
	{
		return  XWnd_SetTimer(hWindow, nIDEvent, uElapse);
	}
	BOOL KillTimer(UINT nIDEvent)
	{
		return  XWnd_KillTimer(hWindow, nIDEvent);
	}
	XBkM GetBkManager()
	{
		return  XWnd_GetBkManager(hWindow);
	}
	void SetTransparentType(window_transparent_ nType)
	{
		XWnd_SetTransparentType(hWindow, nType);
	}
	void SetTransparentAlpha(BYTE alpha)
	{
		XWnd_SetTransparentAlpha(hWindow, alpha);
	}
	void SetTransparentColor(COLORREF color)
	{
		XWnd_SetTransparentColor(hWindow, color);
	}
	BOOL SetXCTimer(UINT nIDEvent, UINT uElapse)
	{
		return XWnd_SetXCTimer(hWindow,nIDEvent,uElapse);
	}
	BOOL KillXCTimer(UINT nIDEvent)
	{
		return XWnd_KillXCTimer(hWindow,nIDEvent);
	}

	void DrawWindow(HDRAW hDraw)
	{
		XWnd_DrawWindow(hWindow,hDraw);
	}
	void SetTextColor( COLORREF color,BYTE alpha)
	{
		XWnd_SetTextColor( hWindow,  color, alpha);
	}
	COLORREF GetTextColor()
	{
		return XWnd_GetTextColor(hWindow);
	}

	void EnableCSS(BOOL bEnable)
	{
		XWnd_EnableCSS( hWindow, bEnable);
	}
	void  SetCssName(const wchar_t *pName)
	{
		XWnd_SetCssName( hWindow,pName);
	}
	const wchar_t* GetCssName()
	{
		return XWnd_GetCssName(hWindow);
	}
	void SetShadowInfo(int nSize, int nDepth, int nAngeleSize,BOOL bRightAngle,COLORREF color)
	{
		XWnd_SetShadowInfo(hWindow,nSize,nDepth,nAngeleSize,bRightAngle,color);
	}
	void GetShadowInfo(int *pnSize, int *pnDepth, int *pnAngeleSize,BOOL *pbRightAngle,COLORREF *pColor)
	{
		XWnd_GetShadowInfo(hWindow,pnSize,pnDepth,pnAngeleSize,pbRightAngle,pColor);
	}
	window_transparent_ GetTransparentType()
	{
		return XWnd_GetTransparentType(hWindow);
	}

	HXCGUI GetObjectById(int nID)
	{
		return XC_GetObjectByID(hWindow,nID);
	}
public:
	//窗口透明，异性
	void SetTransparentType_shaped()
	{
		XWnd_SetTransparentType(hWindow,window_transparent_shaped);
	}
	//指定色透明
	void SetTransparentType_simple(COLORREF color)
	{
		XWnd_SetTransparentType(hWindow,window_transparent_simple);
		XWnd_SetTransparentColor(hWindow,color);
	}

	XLayout GetLayoutObject_body()
	{
		return GetLayoutObject(window_position_body);
	}
	XLayout GetLayoutObject_left()
	{
		return GetLayoutObject(window_position_left);
	}
	XLayout GetLayoutObject_top()
	{
		return GetLayoutObject(window_position_top);
	}
	XLayout GetLayoutObject_right()
	{
		return GetLayoutObject(window_position_right);
	}
	XLayout GetLayoutObject_bottom()
	{
		return GetLayoutObject(window_position_bottom);
	}
};

class XWindowLayout : public XWndBase
{
public:
	BOOL CreateFromLayout(const wchar_t *pLayoutFileName,HXCGUI hParent = NULL)
	{
		hWindow = (HWINDOW)XC_LoadLayout(pLayoutFileName, hParent);
        return  hWindow?TRUE:FALSE;
	}
    BOOL CreateFromLayout(
		const wchar_t *pResourceFileName,
		const wchar_t *pResourceDir,
		const wchar_t *pLayoutFileName,
		HXCGUI hParent = NULL)
    {
		XC_LoadResource(pResourceFileName, pResourceDir);
		hWindow = (HWINDOW)XC_LoadLayout(pLayoutFileName, hParent);
        return  hWindow?TRUE:FALSE;
    }
    BOOL CreateFromLayoutString(
		const char *pResourceStringXML,
		const wchar_t *pDir,
		const char *pLayoutStringXML,
		HXCGUI hParent = NULL)
    {
		XC_LoadResourceFromString(pResourceStringXML, pDir);
		hWindow = (HWINDOW)XC_LoadLayoutFromString(pLayoutStringXML, hParent);
        return  hWindow?TRUE:FALSE;
    }
};

class XWnd : public XWindowLayout
{
public:
	XWnd()
	{

	}
	XWnd(int cx,int cy,const wchar_t* pTitle)
	{
		hWindow = XWnd_Create(0,0,cx,cy,pTitle);
	}
	XWnd(int x,int y,int cx,int cy,const wchar_t* pTitle,HWND hWndParent = NULL,xc_window_style_ nstyle = xc_window_style_default)
	{
		hWindow = XWnd_Create(x,y,cx,cy,pTitle,hWndParent,nstyle);
	}
	XWnd(const wchar_t *pLayoutFileName,HXCGUI hParent = NULL)
	{
		CreateFromLayout(pLayoutFileName, hParent);
	}
	XWnd(
		const wchar_t *pResourceFileName,
		const wchar_t *pResourceDir,
		const wchar_t *pLayoutFileName,
		HXCGUI hParent = NULL)
	{
		CreateFromLayout(pResourceFileName,pResourceDir,pLayoutFileName,hParent);
	}

public:
	HWINDOW Create(int cx,int cy,const wchar_t* pTitle,HWND hWndParent = NULL,xc_window_style_ nstyle = xc_window_style_default)
	{
		hWindow = XWnd_Create(0,0,cx,cy,pTitle,hWndParent,nstyle);
		return hWindow;
	}
	HWINDOW Create(int x,int y,int cx,int cy,const wchar_t* pTitle,HWND hWndParent = NULL,xc_window_style_ nstyle = xc_window_style_default)
	{
		hWindow = XWnd_Create(x,y,cx,cy,pTitle,hWndParent,nstyle);
		return hWindow;
	}
	HWINDOW CreateEx(DWORD dwExStyle, const wchar_t *lpClassName, const wchar_t *lpWindowName, DWORD dwStyle, int x, int y, int cx, int cy, HWND hWndParent = NULL, int XCStyle = xc_window_style_default)
	{
		hWindow = XWnd_CreateEx(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, cx, cy, hWndParent, XCStyle);
		return  hWindow;
	}

};

class XModalWnd : public XWindowLayout
{
public:
	XModalWnd()
	{

	}
	XModalWnd(int nWidth, int nHeight, wchar_t *pTitle, HWND hWndParent, int XCStyle = xc_window_style_modal)
	{
		hWindow = XModalWnd_Create(nWidth, nHeight, pTitle, hWndParent, XCStyle);
	}
	HWINDOW Create(int nWidth, int nHeight,const wchar_t *pTitle, HWND hWndParent, int XCStyle = xc_window_style_modal)
	{
		hWindow = XModalWnd_Create(nWidth, nHeight, pTitle, hWndParent, XCStyle);
		return  hWindow;
	}
	HWINDOW CreateEx(DWORD dwExStyle,const wchar_t *lpClassName,const wchar_t *lpWindowName, DWORD dwStyle, int x, int y, int cx, int cy, HWND hWndParent, int XCStyle = xc_window_style_modal)
	{
		hWindow = XModalWnd_CreateEx(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, cx, cy, hWndParent, XCStyle);
		return hWindow;
	}
	void EnableAutoClose(BOOL bEnable)
	{
		XModalWnd_EnableAutoClose(hWindow, bEnable);
	}
	int DoModal()
	{
		return  XModalWnd_DoModal(hWindow);
	}
	void EndModal(int nResult)
	{
		XModalWnd_EndModal(hWindow, nResult);
	}
	void EnableEscClose(BOOL bEnable)
	{
		XModalWnd_EnableEscClose(hWindow,bEnable);
	}
	
};

class XFloatWnd : public XWndBase
{
public:
	BOOL EnableCaptionContent(BOOL bEnable)
	{
		return  XFloatWnd_EnableCaptionContent(hWindow,bEnable);
	}
	HXCGUI GetCaptionLayout()
	{
		return  XFloatWnd_GetCaptionLayout(hWindow);
	}
	HXCGUI GetCaptionShapeText()
	{
		return  XFloatWnd_GetCaptionShapeText(hWindow);
	}
	HELE GetCaptionButtonClose()
	{
		return  XFloatWnd_GetCaptionButtonClose(hWindow);
	}
	void SetTitle(const wchar_t *pTitle)
	{
		XFloatWnd_SetTitle(hWindow, pTitle);
	}
	void GetTitle(out_ wchar_t *pOut, int nOutLen)
	{
		XFloatWnd_GetTitle(hWindow, pOut, nOutLen);
	}
};

class XFrameWnd : public XWndBase
{
public:
	
	HWINDOW Create(int x, int y, int cx, int cy, wchar_t *pTitle, HWND hWndParent = NULL, int XCStyle = xc_window_style_default)
	{
		hWindow = XFrameWnd_Create(x, y, cx, cy, pTitle, hWndParent, XCStyle);
		return hWindow;
	}
	HWINDOW CreateEx(DWORD dwExStyle, wchar_t *lpClassName, wchar_t *lpWindowName, DWORD dwStyle, int x, int y, int cx, int cy, HWND hWndParent, int XCStyle)
	{
		return  XFrameWnd_CreateEx(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, cx, cy, hWndParent, XCStyle);
	}
	void GetLayoutAreaRect(out_ RECT *pRect)
	{
		XFrameWnd_GetLayoutAreaRect(hWindow, pRect);
	}
	void SetView(HELE hEle)
	{
		XFrameWnd_SetView(hWindow, hEle);
	}
	void SetPaneSplitBarColor(COLORREF color, BYTE alpha = 255)
	{
		XFrameWnd_SetPaneSplitBarColor(hWindow, color, alpha);
	}
	BOOL AddPane(HELE hPaneDest, HELE hPaneNew, align_type_ align)
	{
		return  XFrameWnd_AddPane(hWindow, hPaneDest, hPaneNew, align);
	}
	BOOL MergePane(HELE hPaneDest, HELE hPaneNew)
	{
		return  XFrameWnd_MergePane(hWindow, hPaneDest, hPaneNew);
	}
	BOOL SaveLayoutToFile(const wchar_t* pFileName)
	{
		return XFrameWnd_SaveLayoutToFile(hWindow,pFileName);
	}

	BOOL LoadLayoutFile( HELE* aPaneList, int nEleCount, const wchar_t* pFileName)
	{
		return XFrameWnd_LoadLayoutFile(hWindow,aPaneList,nEleCount,pFileName);
	}

};

class XEleBase
{
public:
	XEleBase()
	{
		
	}
	XEleBase(HELE hEleIn)
	{
		this->hEle = hEleIn;
	}
	operator HXCGUI()
	{
		return hEle;
	}
	operator HELE()
	{
		return hEle;
	}
	operator BOOL()
	{
		return hEle?TRUE:FALSE;
	}
	BOOL IsHXCGUI(XC_OBJECT_TYPE nType)
    {
        return  XC_IsHXCGUI(hEle, nType);
    }
	BOOL IsSViewExtend()
	{
		return  XC_IsSViewExtend(hEle);
	}
	void RegEventC(int nEvent, void *pFun)
	{
		XEle_RegEventC(hEle, nEvent, pFun);
	}
	void RegEventC1(int nEvent, void *pFun)
	{
		XEle_RegEventC1(hEle, nEvent, pFun);
	}
	void RegEventC2(int nEvent, void *pFun)
	{
		XEle_RegEventC2(hEle, nEvent, pFun);
	}
	BOOL RemoveEventC(int nEvent, void *pFun)
	{
		return  XEle_RemoveEventC(hEle, nEvent, pFun);
	}
	int SendEvent(HELE hEventEle, int nEvent, WPARAM wParam, LPARAM lParam)
	{
		return  XEle_SendEvent(hEle, hEventEle, nEvent, wParam, lParam);
	}
	BOOL PostEvent(HELE hEventEle, int nEvent, WPARAM wParam, LPARAM lParam)
	{
		return  XEle_PostEvent(hEle, hEventEle, nEvent, wParam, lParam);
	}
	BOOL IsShow()
	{
		return  XEle_IsShow(hEle);
	}
	BOOL IsEnable()
	{
		return  XEle_IsEnable(hEle);
	}
	BOOL IsEnableFocus()
	{
		return  XEle_IsEnableFocus(hEle);
	}
	BOOL IsDrawFocus()
	{
		return  XEle_IsDrawFocus(hEle);
	}
	BOOL IsEnableEvent_XE_PAINT_END()
	{
		return  XEle_IsEnableEvent_XE_PAINT_END(hEle);
	}
	BOOL IsMouseThrough()
	{
		return  XEle_IsMouseThrough(hEle);
	}
	BOOL IsBkTransparent()
	{
		return  XEle_IsBkTransparent(hEle);
	}
	BOOL IsKeyTab()
	{
		return  XEle_IsKeyTab(hEle);
	}
	BOOL IsSwitchFocus()
	{
		return  XEle_IsSwitchFocus(hEle);
	}
	BOOL IsEnable_XE_MOUSEWHEEL()
	{
		return  XEle_IsEnable_XE_MOUSEWHEEL(hEle);
	}
	void Enable(BOOL bEnable)
	{
		XEle_Enable(hEle, bEnable);
	}
	void EnableFocus(BOOL bEnable)
	{
		XEle_EnableFocus(hEle, bEnable);
	}
	void EnableDrawFocus(BOOL bEnable)
	{
		XEle_EnableDrawFocus(hEle, bEnable);
	}
	void EnableEvent_XE_PAINT_END(BOOL bEnable)
	{
		XEle_EnableEvent_XE_PAINT_END(hEle, bEnable);
	}
	void EnableBkTransparent(BOOL bEnable)
	{
		XEle_EnableBkTransparent(hEle, bEnable);
	}
	void EnableMouseThrough(BOOL bEnable)
	{
		XEle_EnableMouseThrough(hEle, bEnable);
	}
	void EnableKeyTab(BOOL bEnable)
	{
		XEle_EnableKeyTab(hEle, bEnable);
	}
	void EnableSwitchFocus(BOOL bEnable)
	{
		XEle_EnableSwitchFocus(hEle, bEnable);
	}
	void EnableEvent_XE_MOUSEWHEEL(BOOL bEnable)
	{
		XEle_EnableEvent_XE_MOUSEWHEEL(hEle, bEnable);
	}
	BOOL SetRect(RECT *pRect, BOOL bRedraw = FALSE)
	{
		return  XEle_SetRect(hEle, pRect, bRedraw);
	}
	BOOL SetRectEx(int x, int y, int cx, int cy, BOOL bRedraw = FALSE)
	{
		return  XEle_SetRectEx(hEle, x, y, cx, cy, bRedraw);
	}
	BOOL SetRectLogic(RECT *pRect, BOOL bRedraw = FALSE)
	{
		return  XEle_SetRectLogic(hEle, pRect, bRedraw);
	}
	void GetRect(RECT *pRect)
	{
		XEle_GetRect(hEle, pRect);
	}
	void GetRectLogic(RECT *pRect)
	{
		XEle_GetRectLogic(hEle, pRect);
	}
	void GetClientRect(RECT *pRect)
	{
		XEle_GetClientRect(hEle, pRect);
	}
	void GetWndClientRect(out_ RECT *pRect)
	{
		XEle_GetWndClientRect(hEle, pRect);
	}
	int GetWidth()
	{
		return  XEle_GetWidth(hEle);
	}
	int GetHeight()
	{
		return  XEle_GetHeight(hEle);
	}
	void RectWndClientToEleClient(in_out_ RECT *pRect)
	{
		XEle_RectWndClientToEleClient(hEle, pRect);
	}
	void PointWndClientToEleClient(in_out_ POINT *pPt)
	{
		XEle_PointWndClientToEleClient(hEle, pPt);
	}
	void RectClientToWndClient(in_out_ RECT *pRect)
	{
		XEle_RectClientToWndClient(hEle, pRect);
	}
	void PointClientToWndClient(in_out_ POINT *pPt)
	{
		XEle_PointClientToWndClient(hEle, pPt);
	}
	BOOL AddEle(HELE hChildEle)
	{
		return  XEle_AddEle(hEle, hChildEle);
	}
	BOOL InsertEle(HELE hChildEle, int index)
	{
		return  XEle_InsertEle(hEle, hChildEle, index);
	}
	void RemoveEle()
	{
		XEle_RemoveEle(hEle);
	}
	BOOL AddShape(HXCGUI hShape)
	{
		return  XEle_AddShape(hEle, hShape);
	}
	BOOL SetZOrder(int index)
	{
		return  XEle_SetZOrder(hEle, index);
	}
	BOOL SetZOrderEx(HELE hDestEle, zorder_ nType)
	{
		return  XEle_SetZOrderEx(hEle, hDestEle, nType);
	}
	int GetZOrder()
	{
		return  XEle_GetZOrder(hEle);
	}
	void ShowEle(BOOL bShow)
	{
		XEle_ShowEle(hEle, bShow);
	}
	XC_OBJECT_TYPE GetType()
	{
		return  XEle_GetType(hEle);
	}
	HWND GetHWND()
	{
		return  XEle_GetHWND(hEle);
	}
	HWINDOW GetHWINDOW()
	{
		return  XEle_GetHWINDOW(hEle);
	}
	void SetCursor(HCURSOR hCursor)
	{
		XEle_SetCursor(hEle, hCursor);
	}
	HCURSOR GetCursor()
	{
		return  XEle_GetCursor(hEle);
	}
	void SetID(int nID)
	{
		XEle_SetID(hEle, nID);
	}
	int GetID()
	{
		return  XEle_GetID(hEle);
	}
	void SetUID(int nUID)
	{
		XEle_SetUID(hEle,nUID);
	}
	int GetUID()
	{
		return XEle_GetUID(hEle);
	}

	HELE GetParentEle()
	{
		return  XEle_GetParentEle(hEle);
	}
	HXCGUI GetParent()
	{
		return  XEle_GetParent(hEle);
	}
	void SetTextColor(COLORREF color, BYTE alpha = 255)
	{
		XEle_SetTextColor(hEle, color, alpha);
	}
	COLORREF GetTextColor()
	{
		return  XEle_GetTextColor(hEle);
	}
	void SetFocusBorderColor(COLORREF color, BYTE alpha = 255)
	{
		XEle_SetFocusBorderColor(hEle, color, alpha);
	}
	COLORREF GetFocusBorderColor()
	{
		return  XEle_GetFocusBorderColor(hEle);
	}
	void SetFont(HFONTX hFontx)
	{
		XEle_SetFont(hEle, hFontx);
	}
	HFONTX GetFont()
	{
		return  XEle_GetFont(hEle);
	}
	void SetAlpha(BYTE alpha)
	{
		XEle_SetAlpha(hEle, alpha);
	}
	int GetChildCount()
	{
		return  XEle_GetChildCount(hEle);
	}
	HELE GetChildByIndex(int index)
	{
		return  XEle_GetChildByIndex(hEle, index);
	}
	HELE GetChildByID(int nID)
	{
		return  XEle_GetChildByID(hEle, nID);
	}
	int GetChildShapeCount()
	{
		return  XEle_GetChildShapeCount(hEle);
	}
	HXCGUI GetChildShapeByIndex(int index)
	{
		return  XEle_GetChildShapeByIndex(hEle, index);
	}
	HELE HitChildEle(in_ POINT *pPt)
	{
		return  XEle_HitChildEle(hEle, pPt);
	}
	void BindLayoutObject(HXCGUI hLayout)
	{
		XEle_BindLayoutObject(hEle, hLayout);
	}
	HXCGUI GetLayoutObject()
	{
		return  XEle_GetLayoutObject(hEle);
	}
	HXCGUI GetParentLayoutObject()
	{
		return  XEle_GetParentLayoutObject(hEle);
	}
	void SetUserData(int nData)
	{
		XEle_SetUserData(hEle, nData);
	}
	int GetUserData()
	{
		return  XEle_GetUserData(hEle);
	}
	void GetContentSize(out_ SIZE *pSize)
	{
		XEle_GetContentSize(hEle, pSize);
	}
	void SetCapture(BOOL b)
	{
		XEle_SetCapture(hEle, b);
	}
	void SetLayoutWidth(layout_size_type_ nType, int nWidth)
	{
		XEle_SetLayoutWidth(hEle, nType, nWidth);
	}
	void SetLayoutHeight(layout_size_type_ nType, int nHeight)
	{
		XEle_SetLayoutHeight(hEle, nType, nHeight);
	}
	void GetLayoutWidth(out_ layout_size_type_ * pType, out_ int *pWidth)
	{
		XEle_GetLayoutWidth(hEle, pType, pWidth);
	}
	void GetLayoutHeight(out_ layout_size_type_ * pType, out_ int *pHeight)
	{
		XEle_GetLayoutHeight(hEle, pType, pHeight);
	}
	void RedrawEle(BOOL bImmediate = FALSE)
	{
		XEle_RedrawEle(hEle, bImmediate);
	}
	void RedrawRect(RECT *pRect, BOOL bImmediate = FALSE)
	{
		XEle_RedrawRect(hEle, pRect, bImmediate);
	}
	void Destroy()
	{
		XEle_Destroy(hEle);
	}
	void AddBkBorder(COLORREF color, BYTE alpha, int width)
	{
		XEle_AddBkBorder(hEle, color, alpha, width);
	}
	void AddBkFill(COLORREF color, BYTE alpha)
	{
		XEle_AddBkFill(hEle, color, alpha);
	}
	void AddBkImage(HIMAGE hImage)
	{
		XEle_AddBkImage(hEle, hImage);
	}
	int GetBkInfoCount()
	{
		return  XEle_GetBkInfoCount(hEle);
	}
	void ClearBkInfo()
	{
		XEle_ClearBkInfo(hEle);
	}
	XBkM GetBkManager()
	{
		XBkM bk(XEle_GetBkManager(hEle));
		return  bk;
	}
	int GetStateFlags()
	{
		return  XEle_GetStateFlags(hEle);
	}
	BOOL DrawFocus(HDRAW hDraw, RECT *pRect)
	{
		return  XEle_DrawFocus(hEle, hDraw, pRect);
	}
	void EnableTransparentChannel(BOOL bEnable)
	{
		XEle_EnableTransparentChannel(hEle, bEnable);
	}
	void SetToolTip(const wchar_t *pText)
	{
		XEle_SetToolTip(hEle, pText);
	}
	void GetToolTip(out_ wchar_t *pOut, int nOutLen)
	{
		XEle_GetToolTip(hEle, pOut, nOutLen);
	}
	void PopupToolTip( int x, int y)
	{
		XEle_PopupToolTip(hEle, x,y);
	}
	void AdjustLayoutObject()
	{
		XEle_AdjustLayoutObject(hEle);
	}
	void AdjustLayout()
	{
		XEle_AdjustLayout(hEle);
	}

	BOOL IsInScrollView()
	{
		return XEle_IsInScrollView(hEle);
	}
	void EnableDrawBorder(BOOL bEnable)
	{
		XEle_EnableDrawBorder(hEle,bEnable);
	}
	void EnableInScrollView(BOOL bEnable)
	{
		XEle_EnableInScrollView(hEle,bEnable);
	}

	BOOL SetTopmost(BOOL bTopmost)
	{
		return XEle_SetTopmost(hEle,bTopmost);
	}

	BOOL SetXCTimer(UINT nIDEvent,UINT uElapse)
	{
		return XEle_SetXCTimer(hEle,nIDEvent,uElapse);
	}

	BOOL KillXCTimer(UINT nIDEvent)
	{
		return XEle_KillXCTimer(hEle,nIDEvent);
	}

	void EnableCSS(BOOL bEnable)
	{
		XEle_EnableCSS(hEle,bEnable);
	}
	void SetCssName(const wchar_t *pName)
	{
		XEle_SetCssName(hEle,pName);
	}
	const wchar_t* GetCssName()
	{
		return XEle_GetCssName(hEle);
	}
	void DrawEle(HDRAW hDraw)
	{
		XEle_DrawEle(hEle,hDraw);
	}
	BOOL IsChildEle(HELE hChildEle)
	{
		return XEle_IsChildEle(hEle,hChildEle);
	}
	HELE hEle;
};

class XEleLayout : public XEleBase
{
public:
	XC_OBJECT_TYPE GetObjectType()
    {
        return  XC_GetObjectType(hEle);
    }
	BOOL CreateFromLayoutID(HWINDOW hWindow,int nID)
	{
		hEle = (HELE)XC_GetObjectByID(hWindow,nID);
		return hEle?TRUE:FALSE;
	}
	BOOL CreateFromLayoutResIDValue(HWINDOW hWindow,const wchar_t *pName)
	{
		hEle = (HELE)XC_GetObjectByID(hWindow,XRes_GetIDValue(pName));
		return hEle?TRUE:FALSE;
	}
};

class XEle : public  XEleLayout 
{
public:
	XEle()
	{

	}
	XEle(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XEle(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x, y, cx, cy, hParent);
	}
	BOOL CreateFromLayoutPane(
		const wchar_t *pLayoutFileName,
		HXCGUI hParent = NULL)
	{
		hEle = (HELE)XC_LoadLayout(pLayoutFileName, hParent);
        return  hEle?TRUE:FALSE;
	}
    BOOL CreateFromLayout(
		const wchar_t *pResourceFileName,
		const wchar_t *pResourceDir,
		const wchar_t *pLayoutFileName,
		HXCGUI hParent = NULL)
    {
		XC_LoadResource(pResourceFileName, pResourceDir);
		hEle = (HELE)XC_LoadLayout(pLayoutFileName, hParent);
        return  hEle?TRUE:FALSE;
    }
    BOOL CreateFromLayoutString(
		const char *pResourceStringXML,
		const wchar_t *pDir,
		const char *pLayoutStringXML,
		HXCGUI hParent = NULL)
    {
		XC_LoadResourceFromString(pResourceStringXML, pDir);
		hEle = (HELE)XC_LoadLayoutFromString(pLayoutStringXML, hParent);
        return  hEle?TRUE:FALSE;
    }
public:
	BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		hEle =  XEle_Create(x, y, cx, cy, hParent);
		return hEle?TRUE:FALSE;
    }
	BOOL Create(HXCGUI hParent =  NULL)
	{
		hEle =  XEle_Create(0, 0, 100, 20, hParent);
		return hEle?TRUE:FALSE;
    }
	
};

class XBtnBase : public XEleLayout
{
public:
	XBtnBase()
	{
		
	}
	BOOL IsCheck()
    {
        return  XBtn_IsCheck(hEle);
    }
    BOOL SetCheck(BOOL bCheck)
    {
        return  XBtn_SetCheck(hEle, bCheck);
    }
    void SetState(common_state3_ nState)
    {
        XBtn_SetState(hEle, nState);
    }
    common_state3_ GetState()
    {
        return  XBtn_GetState(hEle);
    }
    button_state_ GetStateEx()
    {
        return  XBtn_GetStateEx(hEle);
    }
    void SetStyle(XC_OBJECT_STYLE nStyle)
    {
        XBtn_SetStyle(hEle, nStyle);
    }
    XC_OBJECT_STYLE GetStyle()
    {
        return  XBtn_GetStyle(hEle);
    }
    void SetType(XC_OBJECT_TYPE_EX nType)
    {
        XBtn_SetType(hEle, nType);
    }
    XC_OBJECT_TYPE_EX GetType()
    {
        return  XBtn_GetType(hEle);
    }
    void SetGroupID(int nID)
    {
        XBtn_SetGroupID(hEle, nID);
    }
    int GetGroupID()
    {
        return  XBtn_GetGroupID(hEle);
    }
    void SetBindEle(HELE hBindEle)
    {
        XBtn_SetBindEle(hEle, hBindEle);
    }
    HELE GetBindEle()
    {
        return  XBtn_GetBindEle(hEle);
    }
    void SetTextAlign(int nFlags)
    {
        XBtn_SetTextAlign(hEle, nFlags);
    }
    int GetTextAlign()
    {
        return  XBtn_GetTextAlign(hEle);
    }
    void SetIconAlign(button_icon_align_ align)
    {
        XBtn_SetIconAlign(hEle, align);
    }
    void SetOffset(int x, int y)
    {
        XBtn_SetOffset(hEle, x, y);
    }
    void SetOffsetIcon(int x, int y)
    {
        XBtn_SetOffsetIcon(hEle, x, y);
    }
    void SetIconSpace(int size)
    {
        XBtn_SetIconSpace(hEle, size);
    }
    void GetText(out_ wchar_t *pOut, int nOutLen)
    {
        XBtn_GetText(hEle, pOut, nOutLen);
    }
    void SetText(in_ const wchar_t *pName)
    {
        XBtn_SetText(hEle, pName);
    }
    void SetIcon(HIMAGE hImage)
    {
        XBtn_SetIcon(hEle, hImage);
    }
    void SetIconDisable(HIMAGE hImage)
    {
        XBtn_SetIconDisable(hEle, hImage);
    }
    void AddAnimationFrame(HIMAGE hImage, UINT uElapse)
    {
        XBtn_AddAnimationFrame(hEle, hImage, uElapse);
    }
    void EnableAnimation(BOOL bEnable, BOOL bLoopPlay = FALSE)
    {
        XBtn_EnableAnimation(hEle, bEnable, bLoopPlay);
    }
    void AddBkBorder(button_state_ nState, COLORREF color, BYTE alpha, int width)
    {
        XBtn_AddBkBorder(hEle, nState, color, alpha, width);
    }
    void AddBkFill(button_state_ nState, COLORREF color, BYTE alpha)
    {
        XBtn_AddBkFill(hEle, nState, color, alpha);
    }
    void AddBkImage(button_state_ nState, HIMAGE hImage)
    {
        XBtn_AddBkImage(hEle, nState, hImage);
    }
    int GetBkInfoCount()
    {
        return  XBtn_GetBkInfoCount(hEle);
    }
    void ClearBkInfo()
    {
        XBtn_ClearBkInfo(hEle);
    }

	HIMAGE GetIcon(HELE hEle, int nType)
	{
	 return XBtn_GetIcon(hEle,nType);
	}
};

class XBtn : public XBtnBase
{
public:
	XBtn()
	{
	}
	XBtn(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XBtn(const wchar_t *pName, HXCGUI hParent = NULL)
	{
		Create(pName, hParent);
	}
	XBtn(int cx,int cy,const wchar_t* pName,HXCGUI hParent = NULL)
	{
		Create(cx, cy, pName, hParent);
	}
	XBtn(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent = NULL)
	{
		Create(x, y, cx, cy, pName, hParent);
	}
public:
    BOOL Create(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent =  NULL)
    {
		hEle = XBtn_Create(x, y, cx, cy, pName, hParent);
        return  hEle?TRUE:FALSE;
    }
	BOOL Create(int cx, int cy, const wchar_t *pName, HXCGUI hParent =  NULL)
    {
		return Create(0, 0, cx, cy, pName, hParent);
    }
	BOOL Create(const wchar_t *pName, HXCGUI hParent)
	{
		return Create(0, 0, 100, 20, pName, hParent);
	}
};

class XTextLink : public XBtnBase
{
public:
	XTextLink()
	{
	}
	XTextLink(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XTextLink(const wchar_t *pName, HXCGUI hParent =  NULL)
	{
		Create(0, 0, 100, 20, pName, hParent);
	}
	XTextLink(int x, int y, int cx, int cy,HXCGUI hParent = NULL)
	{
		Create(x,y,cx,cy,NULL,NULL);
	}
	XTextLink(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,pName,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent =  NULL)
    {
		hEle = XTextLink_Create(x, y, cx, cy, pName, hParent);
        return hEle;
    }
    void EnableUnderlineLeave(BOOL bEnable)
    {
        XTextLink_EnableUnderlineLeave(hEle, bEnable);
    }
    void EnableUnderlineStay(BOOL bEnable)
    {
        XTextLink_EnableUnderlineStay(hEle, bEnable);
    }
    void SetTextColorStay(COLORREF color, BYTE alpha)
    {
        XTextLink_SetTextColorStay(hEle, color, alpha);
    }
    void SetUnderlineColorLeave(COLORREF color, BYTE alpha)
    {
        XTextLink_SetUnderlineColorLeave(hEle, color, alpha);
    }
    void SetUnderlineColorStay(COLORREF color, BYTE alpha)
    {
        XTextLink_SetUnderlineColorStay(hEle, color, alpha);
    }
};


class XSBar : public XEleBase
{
public:
	XSBar()
	{
		
	}
	XSBar(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XSBar(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
	
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
    {
		hEle = XSBar_Create(x, y, cx, cy, hParent);
		return hEle;
    }
    void SetRange(int range)
    {
        XSBar_SetRange(hEle, range);
    }
    int GetRange()
    {
        return  XSBar_GetRange(hEle);
    }
    void ShowButton(BOOL bShow)
    {
        XSBar_ShowButton(hEle, bShow);
    }
    void SetSliderLength(int length)
    {
        XSBar_SetSliderLength(hEle, length);
    }
    void SetSliderMinLength(int minLength)
    {
        XSBar_SetSliderMinLength(hEle, minLength);
    }
    BOOL SetHorizon(BOOL bHorizon)
    {
        return  XSBar_SetHorizon(hEle, bHorizon);
    }
    int GetSliderMaxLength()
    {
        return  XSBar_GetSliderMaxLength(hEle);
    }
    BOOL ScrollUp()
    {
        return  XSBar_ScrollUp(hEle);
    }
    BOOL ScrollDown()
    {
        return  XSBar_ScrollDown(hEle);
    }
    BOOL ScrollTop()
    {
        return  XSBar_ScrollTop(hEle);
    }
    BOOL ScrollBottom()
    {
        return  XSBar_ScrollBottom(hEle);
    }
    BOOL ScrollPos(int pos)
    {
        return  XSBar_ScrollPos(hEle, pos);
    }
	
    XBtn GetButtonUp()
    {
		XBtn btn(XSBar_GetButtonUp(hEle));
        return  btn;
    }
    XBtn GetButtonDown()
    {
		XBtn btn(XSBar_GetButtonDown(hEle));
        return btn;
    }
    XBtn GetButtonSlider()
    {
		XBtn btn(XSBar_GetButtonSlider(hEle));
        return  btn;
    }
	void SetSliderPadding( int nPadding)
	{
		XSBar_SetSliderPadding(hEle,nPadding);
	}
	
	
};

class XSViewBase : public XEleLayout
{
public:
	void SetScrollBarSize(int size)
	{
		XSView_SetScrollBarSize(hEle,size);
	}
    BOOL SetTotalSize(int cx, int cy)
    {
        return  XSView_SetTotalSize(hEle, cx, cy);
    }
    void GetTotalSize(SIZE *pSize)
    {
        XSView_GetTotalSize(hEle, pSize);
    }
    BOOL SetLineSize(int nWidth, int nHeight)
    {
        return  XSView_SetLineSize(hEle, nWidth, nHeight);
    }
    void GetLineSize(out_ SIZE *pSize)
    {
        XSView_GetLineSize(hEle, pSize);
    }
    int GetViewPosH()
    {
        return  XSView_GetViewPosH(hEle);
    }
    int GetViewPosV()
    {
        return  XSView_GetViewPosV(hEle);
    }
    int GetViewWidth()
    {
        return  XSView_GetViewWidth(hEle);
    }
    int GetViewHeight()
    {
        return  XSView_GetViewHeight(hEle);
    }
    void GetViewRect(out_ RECT *pRect)
    {
        XSView_GetViewRect(hEle, pRect);
    }
    XSBar GetScrollBarH()
    {
		XSBar sbar(XSView_GetScrollBarH(hEle));
        return  sbar;
    }
    XSBar GetScrollBarV()
    {
		XSBar sbar(XSView_GetScrollBarV(hEle));
        return  sbar;
    }

	/// 兼容函数
    void SetPadding(int left, int top, int right, int bottom)
    {
        XSView_SetBorderSize(hEle, left, top, right, bottom);
    }
    void GetPadding(out_ PaddingSize_i* pPadding)
    {
        XSView_GetBorderSize(hEle, pPadding);
    }
	///兼容结束
    void SetBorderSize(int left, int top, int right, int bottom)
    {
        XSView_SetBorderSize(hEle, left, top, right, bottom);
    }
    void GetBorderSize(out_ BorderSize_i* pPadding)
    {
        XSView_GetBorderSize(hEle, pPadding);
    }


    BOOL ScrollPosH(int pos)
    {
        return  XSView_ScrollPosH(hEle, pos);
    }
    BOOL ScrollPosV(int pos)
    {
        return  XSView_ScrollPosV(hEle, pos);
    }
    BOOL ScrollPosXH(int posX)
    {
        return  XSView_ScrollPosXH(hEle, posX);
    }
    BOOL ScrollPosYV(int posY)
    {
        return  XSView_ScrollPosYV(hEle, posY);
    }
    void ShowSBarH(BOOL bShow)
    {
        XSView_ShowSBarH(hEle, bShow);
    }
    void ShowSBarV(BOOL bShow)
    {
        XSView_ShowSBarV(hEle, bShow);
    }
    void EnableAutoShowScrollBar(BOOL bEnable)
    {
        XSView_EnableAutoShowScrollBar(hEle, bEnable);
    }
    BOOL ScrollLeftLine()
    {
        return  XSView_ScrollLeftLine(hEle);
    }
    BOOL ScrollRightLine()
    {
        return  XSView_ScrollRightLine(hEle);
    }
    BOOL ScrollTopLine()
    {
        return  XSView_ScrollTopLine(hEle);
    }
    BOOL ScrollBottomLine()
    {
        return  XSView_ScrollBottomLine(hEle);
    }
    BOOL ScrollLeft()
    {
        return  XSView_ScrollLeft(hEle);
    }
    BOOL ScrollRight()
    {
        return  XSView_ScrollRight(hEle);
    }
    BOOL ScrollTop()
    {
        return  XSView_ScrollTop(hEle);
    }
    BOOL ScrollBottom()
    {
        return  XSView_ScrollBottom(hEle);
    }
};

class XSView : public XSViewBase
{
public:
	XSView()
	{

	}
	XSView(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XSView(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x, y, cx, cy, hParent);
	}
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
    {
		hEle = XSView_Create(x, y, cx, cy, hParent);
        return hEle?TRUE:FALSE;
    }
};

class XAd
{
public:
    void Destroy(HXCGUI hAdapter)
    {
		XAd_Destroy(hAdapter);
    }
	operator HXCGUI()
	{
		return hAdapter;
	}
	HXCGUI hAdapter;
};

class XAdTable : public XAd
{
public:
	XAdTable()
	{
		hAdapter = XAdTable_Create();
	}
	XAdTable(HXCGUI hAdapterIn)
	{
		hAdapter = hAdapterIn;
	}
    int AddColumn(const wchar_t *pName)
    {
        return  XAdTable_AddColumn(hAdapter, pName);
    }
    int SetColumn(const wchar_t *pColName)
    {
        return  XAdTable_SetColumn(hAdapter, pColName);
    }
    int AddItemText(const wchar_t *pValue)
    {
        return  XAdTable_AddItemText(hAdapter, pValue);
    }
    int AddItemTextEx(const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdTable_AddItemTextEx(hAdapter, pName, pValue);
    }
    int AddItemImage(HIMAGE hImage)
    {
        return  XAdTable_AddItemImage(hAdapter, hImage);
    }
    int AddItemImageEx(const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdTable_AddItemImageEx(hAdapter, pName, hImage);
    }
    int InsertItemText(int iItem, const wchar_t *pValue)
    {
        return  XAdTable_InsertItemText(hAdapter, iItem, pValue);
    }
    int InsertItemTextEx(int iItem, const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdTable_InsertItemTextEx(hAdapter, iItem, pName, pValue);
    }
    int InsertItemImage(int iItem, HIMAGE hImage)
    {
        return  XAdTable_InsertItemImage(hAdapter, iItem, hImage);
    }
    int InsertItemImageEx(int iItem, const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdTable_InsertItemImageEx(hAdapter, iItem, pName, hImage);
    }
    BOOL SetItemText(int iItem, int iColumn, const wchar_t *pValue)
    {
        return  XAdTable_SetItemText(hAdapter, iItem, iColumn, pValue);
    }
    BOOL SetItemTextEx(int iItem, const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdTable_SetItemTextEx(hAdapter, iItem, pName, pValue);
    }
    BOOL SetItemImage(int iItem, int iColumn, HIMAGE hImage)
    {
        return  XAdTable_SetItemImage(hAdapter, iItem, iColumn, hImage);
    }
    BOOL SetItemImageEx(int iItem, const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdTable_SetItemImageEx(hAdapter, iItem, pName, hImage);
    }
    BOOL DeleteItem(int iItem)
    {
        return  XAdTable_DeleteItem(hAdapter, iItem);
    }
    BOOL DeleteItemEx(int iItem, int nCount)
    {
        return  XAdTable_DeleteItemEx(hAdapter, iItem, nCount);
    }
    void DeleteItemAll()
    {
        XAdTable_DeleteItemAll(hAdapter);
    }
    void DeleteColumnAll()
    {
        XAdTable_DeleteColumnAll(hAdapter);
    }
    int GetCount()
    {
        return  XAdTable_GetCount(hAdapter);
    }
    int GetCountColumn()
    {
        return  XAdTable_GetCountColumn(hAdapter);
    }
    BOOL GetItemText(int iItem, int iColumn, out_ wchar_t *pOut, int nOutLen)
    {
        return  XAdTable_GetItemText(hAdapter, iItem, iColumn, pOut, nOutLen);
    }
    HIMAGE GetItemImage(int iItem, int iColumn)
    {
        return  XAdTable_GetItemImage(hAdapter, iItem, iColumn);
    }
    BOOL GetItemTextEx(int iItem, const wchar_t *pName, out_ wchar_t *pOut, int nOutLen)
    {
        return  XAdTable_GetItemTextEx(hAdapter, iItem, pName, pOut, nOutLen);
    }
    HIMAGE GetItemImageEx(int iItem, const wchar_t *pName)
    {
        return  XAdTable_GetItemImageEx(hAdapter, iItem, pName);
    }
	VOID Sort(int iColumn, BOOL bAscending)//排序
	{
		XAdTable_Sort(hAdapter,iColumn,bAscending); 
	}
	adapter_date_type_ GetItemDataType(int iItem, int iColumn)
	{
		return XAdTable_GetItemDataType(hAdapter,iItem,iColumn);
	}

	adapter_date_type_ GetItemDataTypeEx(int iItem,const wchar_t* pName)
	{
		return XAdTable_GetItemDataTypeEx(hAdapter,iItem,pName);
	}
	BOOL SetItemInt(int iItem,int iColumn,int nValue)
	{
		return XAdTable_SetItemInt(hAdapter,iItem,iColumn,nValue);
	}

	BOOL SetItemIntEx(int iItem,const wchar_t* pName,int nValue)
	{
		return XAdTable_SetItemIntEx(hAdapter,iItem,pName,nValue);
	}
	BOOL SetItemFloat(int iItem,int iColumn,float nValue)
	{
		return XAdTable_SetItemFloat(hAdapter,iItem,iColumn,nValue);
	}
	BOOL SetItemFloatEx(int iItem,const wchar_t* pName,float nValue)
	{
		return XAdTable_SetItemFloatEx(hAdapter,iItem,pName,nValue);
	}
	BOOL GetItemInt(int iItem,int iColumn,out_ int* pOutValue)
	{
		return XAdTable_GetItemInt(hAdapter,iItem,iColumn,pOutValue);
	}
	BOOL GetItemIntEx(int iItem,const wchar_t* pName,out_ int* pOutValue)
	{
		return XAdTable_GetItemIntEx(hAdapter,iItem,pName,pOutValue);
	}

	BOOL GetItemFloat(int iItem,int iColumn,out_ float* pOutValue)
	{
		return XAdTable_GetItemFloat(hAdapter,iItem,iColumn,pOutValue);
	}
	BOOL GetItemFloatEx(int iItem,const wchar_t* pName,out_ float* pOutValue)
	{
		return XAdTable_GetItemFloatEx(hAdapter,iItem,pName,pOutValue);
	}

};

class XAdListView : public XAd
{
public:
	XAdListView()
	{
		hAdapter = XAdListView_Create();
	}
	XAdListView(HXCGUI hAdapterIn)
	{
		hAdapter = hAdapterIn;
	}
    int Group_AddColumn(const wchar_t *pName)
    {
        return  XAdListView_Group_AddColumn(hAdapter, pName);
    }
    int Group_AddItemText(const wchar_t *pValue)
    {
        return  XAdListView_Group_AddItemText(hAdapter, pValue);
    }
    int Group_AddItemTextEx(const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdListView_Group_AddItemTextEx(hAdapter, pName, pValue);
    }
    int Group_AddItemImage(HIMAGE hImage)
    {
        return  XAdListView_Group_AddItemImage(hAdapter, hImage);
    }
    int Group_AddItemImageEx(const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdListView_Group_AddItemImageEx(hAdapter, pName, hImage);
    }
    BOOL Group_SetText(int iGroup, int iColumn, const wchar_t *pValue)
    {
        return  XAdListView_Group_SetText(hAdapter, iGroup, iColumn, pValue);
    }
    BOOL Group_SetTextEx(int iGroup, const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdListView_Group_SetTextEx(hAdapter, iGroup, pName, pValue);
    }
    BOOL Group_SetImage(int iGroup, int iColumn, HIMAGE hImage)
    {
        return  XAdListView_Group_SetImage(hAdapter, iGroup, iColumn, hImage);
    }
    BOOL Group_SetImageEx(int iGroup, const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdListView_Group_SetImageEx(hAdapter, iGroup, pName, hImage);
    }
    int Group_GetCount()
    {
        return  XAdListView_Group_GetCount(hAdapter);
    }
    int Item_GetCount(int iGroup)
    {
        return  XAdListView_Item_GetCount(hAdapter, iGroup);
    }
    int Item_AddColumn(const wchar_t *pName)
    {
        return  XAdListView_Item_AddColumn(hAdapter, pName);
    }
    int Item_AddItemText(int iGroup, const wchar_t *pValue)
    {
        return  XAdListView_Item_AddItemText(hAdapter, iGroup, pValue);
    }
    int Item_AddItemTextEx(int iGroup, const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdListView_Item_AddItemTextEx(hAdapter, iGroup, pName, pValue);
    }
    int Item_AddItemImage(int iGroup, HIMAGE hImage)
    {
        return  XAdListView_Item_AddItemImage(hAdapter, iGroup, hImage);
    }
    int Item_AddItemImageEx(int iGroup, const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdListView_Item_AddItemImageEx(hAdapter, iGroup, pName, hImage);
    }
    BOOL Item_SetText(int iGroup, int iItem, int iColumn, const wchar_t *pValue)
    {
        return  XAdListView_Item_SetText(hAdapter, iGroup, iItem, iColumn, pValue);
    }
    BOOL Item_SetTextEx(int iGroup, int iItem, const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdListView_Item_SetTextEx(hAdapter, iGroup, iItem, pName, pValue);
    }
    BOOL Item_SetImage(int iGroup, int iItem, int iColumn, HIMAGE hImage)
    {
        return  XAdListView_Item_SetImage(hAdapter, iGroup, iItem, iColumn, hImage);
    }
    BOOL Item_SetImageEx(int iGroup, int iItem, const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdListView_Item_SetImageEx(hAdapter, iGroup, iItem, pName, hImage);
    }
    BOOL Group_DeleteItem(int iGroup)
    {
        return  XAdListView_Group_DeleteItem(hAdapter, iGroup);
    }
    void Group_DeleteAllChildItem(int iGroup)
    {
        XAdListView_Group_DeleteAllChildItem(hAdapter, iGroup);
    }
    BOOL Item_DeleteItem(int iGroup, int iItem)
    {
        return  XAdListView_Item_DeleteItem(hAdapter, iGroup, iItem);
    }
    void DeleteAll()
    {
        XAdListView_DeleteAll(hAdapter);
    }
    void DeleteAllGroup()
    {
        XAdListView_DeleteAllGroup(hAdapter);
    }
    void DeleteAllItem()
    {
        XAdListView_DeleteAllItem(hAdapter);
    }
    void DeleteColumnGroup(int iColumn)
    {
        XAdListView_DeleteColumnGroup(hAdapter, iColumn);
    }
    void DeleteColumnItem(int iColumn)
    {
        XAdListView_DeleteColumnItem(hAdapter, iColumn);
    }
    BOOL Item_GetTextEx(int iGroup, int iItem, const wchar_t *pName, out_ wchar_t *pOut, int nOutLen)
    {
        return  XAdListView_Item_GetTextEx(hAdapter, iGroup, iItem, pName, pOut, nOutLen);
    }
    HIMAGE Item_GetImageEx(int iGroup, int iItem, const wchar_t *pName)
    {
        return  XAdListView_Item_GetImageEx(hAdapter, iGroup, iItem, pName);
    }
};

class XAdTree : public XAd
{
public:
	XAdTree()
	{
		hAdapter = XAdTree_Create();
	}
	XAdTree(HXCGUI hAdapterIn)
	{
		hAdapter = hAdapterIn;
	}
    int AddColumn(const wchar_t *pName)
    {
        return  XAdTree_AddColumn(hAdapter, pName);
    }
    int SetColumn(const wchar_t *pColName)
    {
        return  XAdTree_SetColumn(hAdapter, pColName);
    }
    int InsertItemText(const wchar_t *pValue, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST)
    {
        return  XAdTree_InsertItemText(hAdapter, pValue, nParentID, insertID);
    }
    int InsertItemTextEx(const wchar_t *pName, const wchar_t *pValue, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST)
    {
        return  XAdTree_InsertItemTextEx(hAdapter, pName, pValue, nParentID, insertID);
    }
    int InsertItemImage(HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST)
    {
        return  XAdTree_InsertItemImage(hAdapter, hImage, nParentID, insertID);
    }
    int InsertItemImageEx(const wchar_t *pName, HIMAGE hImage, int nParentID = XC_ID_ROOT, int insertID = XC_ID_LAST)
    {
        return  XAdTree_InsertItemImageEx(hAdapter, pName, hImage, nParentID, insertID);
    }
    int GetCount()
    {
        return  XAdTree_GetCount(hAdapter);
    }
    int GetCountColumn()
    {
        return  XAdTree_GetCountColumn(hAdapter);
    }
    BOOL SetItemText(int nID, int iColumn, const wchar_t *pValue)
    {
        return  XAdTree_SetItemText(hAdapter, nID, iColumn, pValue);
    }
    BOOL SetItemTextEx(int nID, const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdTree_SetItemTextEx(hAdapter, nID, pName, pValue);
    }
    BOOL SetItemImage(int nID, int iColumn, HIMAGE hImage)
    {
        return  XAdTree_SetItemImage(hAdapter, nID, iColumn, hImage);
    }
    BOOL SetItemImageEx(int nID, const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdTree_SetItemImageEx(hAdapter, nID, pName, hImage);
    }
    BOOL GetItemTextEx(int nID, const wchar_t *pName, out_ wchar_t *pOut, int nOutLen)
    {
        return  XAdTree_GetItemTextEx(hAdapter, nID, pName, pOut, nOutLen);
    }
    HIMAGE GetItemImageEx(int nID, const wchar_t *pName)
    {
        return  XAdTree_GetItemImageEx(hAdapter, nID, pName);
    }
    BOOL DeleteItem(int nID)
    {
        return  XAdTree_DeleteItem(hAdapter, nID);
    }
    void DeleteItemAll()
    {
        XAdTree_DeleteItemAll(hAdapter);
    }
    void DeleteColumnAll()
    {
        XAdTree_DeleteColumnAll(hAdapter);
    }
	BOOL GetItemText(int nID, int iColumn,out_ wchar_t* pOut,int nOutLen)
	{
		return XAdTree_GetItemText(hAdapter,nID,iColumn,pOut,nOutLen);
	}
	HIMAGE GetItemImage(int nID, int iColumn)
	{
		return XAdTree_GetItemImage(hAdapter,nID,iColumn);
	}
};

class XAdMap : public XAd
{
public:
	XAdMap()
	{
		hAdapter = XAdMap_Create();
	}
	XAdMap(HXCGUI hAdapterIn)
	{
		hAdapter = hAdapterIn;
	}
    BOOL AddItemText(const wchar_t *pName, const wchar_t *pValue)
    {
        return  XAdMap_AddItemText(hAdapter, pName, pValue);
    }
    BOOL AddItemImage(const wchar_t *pName, HIMAGE hImage)
    {
        return  XAdMap_AddItemImage(hAdapter, pName, hImage);
    }
    BOOL DeleteItem(const wchar_t *pName)
    {
        return  XAdMap_DeleteItem(hAdapter, pName);
    }
    int GetCount()
    {
        return  XAdMap_GetCount(hAdapter);
    }
    BOOL GetItemText(const wchar_t *pName, out_ wchar_t *pOut, int nOutLen)
    {
        return  XAdMap_GetItemText(hAdapter, pName, pOut, nOutLen);
    }
    HIMAGE GetItemImage(const wchar_t *pName)
    {
        return  XAdMap_GetItemImage(hAdapter, pName);
    }
	BOOL SetItemText(const wchar_t* pName,const wchar_t* pValue)
	{
		return XAdMap_SetItemText(hAdapter,pName,pValue);
	}
	BOOL SetItemImage(const wchar_t* pName,HIMAGE hImage)
	{
		return XAdMap_SetItemImage(hAdapter,pName,hImage);
	}

};

class XList : public XSViewBase
{
public:
	XList()
	{
	}
	XList(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XList(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hEle = XList_Create(x, y, cx, cy, hParent);
        return hEle?TRUE:FALSE;
    }
    int AddColumn(int width)
    {
        return  XList_AddColumn(hEle, width);
    }
    int InsertColumn(int width, int iItem)
    {
        return  XList_InsertColumn(hEle, width, iItem);
    }
    void EnableMultiSel(BOOL bEnable)
    {
        XList_EnableMultiSel(hEle, bEnable);
    }
    void EnableDragChangeColumnWidth(BOOL bEnable)
    {
        XList_EnableDragChangeColumnWidth(hEle, bEnable);
    }
    void SetDrawItemBkFlags(int style)
    {
        XList_SetDrawItemBkFlags(hEle, style);
    }
    void SetColumnWidth(int iItem, int width)
    {
        XList_SetColumnWidth(hEle, iItem, width);
    }
    void SetColumnMinWidth(int iItem, int width)
    {
        XList_SetColumnMinWidth(hEle, iItem, width);
    }
    void SetColumnWidthFixed(int iColumn, BOOL bFixed)
    {
        XList_SetColumnWidthFixed(hEle, iColumn, bFixed);
    }
    int GetColumnWidth(int iColumn)
    {
        return  XList_GetColumnWidth(hEle, iColumn);
    }
    int GetColumnCount()
    {
        return  XList_GetColumnCount(hEle);
    }
    BOOL DeleteColumn(int iItem)
    {
        return  XList_DeleteColumn(hEle, iItem);
    }
    void DeleteColumnAll()
    {
        XList_DeleteColumnAll(hEle);
    }
    BOOL SetItemData(int iItem, int iSubItem, int data)
    {
        return  XList_SetItemData(hEle, iItem, iSubItem, data);
    }
    int GetItemData(int iItem, int iSubItem)
    {
        return  XList_GetItemData(hEle, iItem, iSubItem);
    }
    BOOL SetSelectItem(int iItem)
    {
        return  XList_SetSelectItem(hEle, iItem);
    }
    int GetSelectItem()
    {
        return  XList_GetSelectItem(hEle);
    }
    int GetSelectItemCount()
    {
        return  XList_GetSelectItemCount(hEle);
    }
    void SetSelectAll()
    {
        XList_SetSelectAll(hEle);
    }
    int GetSelectAll(out_ int *pArray, int nArraySize)
    {
        return  XList_GetSelectAll(hEle, pArray, nArraySize);
    }
    BOOL CancelSelectItem(int iItem)
    {
        return  XList_CancelSelectItem(hEle, iItem);
    }
    void CancelSelectAll()
    {
        XList_CancelSelectAll(hEle);
    }
    XEle GetHeaderHELE()
    {
		XEle ele(XList_GetHeaderHELE(hEle));
        return  ele;
    }
    void BindAdapter(XAdTable hAdapter)
    {
        XList_BindAdapter(hEle, hAdapter);
    }
    void BindAdapterHeader(XAdMap hAdapter)
    {
        XList_BindAdapterHeader(hEle, hAdapter);
    }
    XAdTable GetAdapter()
    {
		XAdTable table(XList_GetAdapter(hEle));
        return  table;
    }
    BOOL SetItemTemplateXML(const wchar_t *pXmlFile)
    {
        return  XList_SetItemTemplateXML(hEle, pXmlFile);
    }
    BOOL SetItemTemplateXMLFromString(const char *pStringXML)
    {
        return  XList_SetItemTemplateXMLFromString(hEle, pStringXML);
    }
    HXCGUI GetTemplateObject(int iItem, int nTempItemID)
    {
        return  XList_GetTemplateObject(hEle, iItem, nTempItemID);
    }
    int GetItemIndexFromHXCGUI(HXCGUI hXCGUI)
    {
        return  XList_GetItemIndexFromHXCGUI(hEle, hXCGUI);
    }
    HXCGUI GetHeaderTemplateObject(int iItem, int nTempItemID)
    {
        return  XList_GetHeaderTemplateObject(hEle, iItem, nTempItemID);
    }
    int GetHeaderItemIndexFromHXCGUI(HXCGUI hXCGUI)
    {
        return  XList_GetHeaderItemIndexFromHXCGUI(hEle, hXCGUI);
    }
    void SetHeaderHeight(int height)
    {
        XList_SetHeaderHeight(hEle, height);
    }
    int GetHeaderHeight()
    {
        return  XList_GetHeaderHeight(hEle);
    }
    void AddItemBkBorder(list_item_state_ nState, COLORREF color, BYTE alpha, int width)
    {
        XList_AddItemBkBorder(hEle, nState, color, alpha, width);
    }
    void AddItemBkFill(list_item_state_ nState, COLORREF color, BYTE alpha)
    {
        XList_AddItemBkFill(hEle, nState, color, alpha);
    }
    void AddItemBkImage(list_item_state_ nState, HIMAGE hImage)
    {
        XList_AddItemBkImage(hEle, nState, hImage);
    }
    int GetItemBkInfoCount()
    {
        return  XList_GetItemBkInfoCount(hEle);
    }
    void ClearItemBkInfo()
    {
        XList_ClearItemBkInfo(hEle);
    }
    void SetItemHeightDefault(int nHeight, int nSelHeight)
    {
        XList_SetItemHeightDefault(hEle, nHeight, nSelHeight);
    }
    void GetItemHeightDefault(out_ int *pHeight, out_ int *pSelHeight)
    {
        XList_GetItemHeightDefault(hEle, pHeight, pSelHeight);
    }
    void SetRowSpace(int nSpace)
    {
        XList_SetRowSpace(hEle, nSpace);
    }
    int GetRowSpace()
    {
        return  XList_GetRowSpace(hEle);
    }
    BOOL HitTest(POINT *pPt, out_ int *piItem, out_ int *piSubItem)
    {
        return  XList_HitTest(hEle, pPt, piItem, piSubItem);
    }
    BOOL HitTestOffset(POINT *pPt, out_ int *piItem, out_ int *piSubItem)
    {
        return  XList_HitTestOffset(hEle, pPt, piItem, piSubItem);
    }
    void RefreshData()
    {
        XList_RefreshData(hEle);
    }
	void EnableVScrollBarTop(BOOL bTop)
	{
		XList_EnableVScrollBarTop(hEle,bTop);
	}
	void EnableItemBkFullRow(BOOL bFull)
	{
		XList_EnableItemBkFullRow(hEle,bFull);
	}
	HXCGUI CreateAdapter()
	{
		return XList_CreateAdapter(hEle);
	}
	HXCGUI CreateAdapterHeader()
	{
		return XList_CreateAdapterHeader(hEle);
	}
	HXCGUI GetAdapterHeader()
	{
		return XList_GetAdapterHeader(hEle);
	}
	
	void RefreshItem(int iItem)
	{
		XList_RefreshItem(hEle,iItem);
	}
};

class XListBox : public XSViewBase
{
public:
	XListBox()
	{

	}
	XListBox(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XListBox(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hEle = XListBox_Create(x, y, cx, cy, hParent);
        return hEle;
    }
    void SetDrawItemBkFlags(int nFlags)
    {
        XListBox_SetDrawItemBkFlags(hEle, nFlags);
    }
    BOOL SetItemData(int iItem, int nUserData)
    {
        return  XListBox_SetItemData(hEle, iItem, nUserData);
    }
    int GetItemData(int iItem)
    {
        return  XListBox_GetItemData(hEle, iItem);
    }
    BOOL SetItemInfo(int iItem, in_ listBox_item_info_i *pItem)
    {
        return  XListBox_SetItemInfo(hEle, iItem, pItem);
    }
    BOOL GetItemInfo(int iItem, out_ listBox_item_info_i *pItem)
    {
        return  XListBox_GetItemInfo(hEle, iItem, pItem);
    }
    void AddItemBkBorder(list_item_state_ nState, COLORREF color, BYTE alpha, int width)
    {
        XListBox_AddItemBkBorder(hEle, nState, color, alpha, width);
    }
    void AddItemBkFill(list_item_state_ nState, COLORREF color, BYTE alpha)
    {
        XListBox_AddItemBkFill(hEle, nState, color, alpha);
    }
    void AddItemBkImage(list_item_state_ nState, HIMAGE hImage)
    {
        XListBox_AddItemBkImage(hEle, nState, hImage);
    }
    int GetItemBkInfoCount()
    {
        return  XListBox_GetItemBkInfoCount(hEle);
    }
    void ClearItemBkInfo()
    {
        XListBox_ClearItemBkInfo(hEle);
    }
    BOOL SetSelectItem(int iItem)
    {
        return  XListBox_SetSelectItem(hEle, iItem);
    }
    int GetSelectItem()
    {
        return  XListBox_GetSelectItem(hEle);
    }
    BOOL CancelSelectItem(int iItem)
    {
        return  XListBox_CancelSelectItem(hEle, iItem);
    }
    BOOL CancelSelectAll()
    {
        return  XListBox_CancelSelectAll(hEle);
    }
    int GetSelectAll(out_ int *pArray, int nArraySize)
    {
        return  XListBox_GetSelectAll(hEle, pArray, nArraySize);
    }
    int GetSelectCount()
    {
        return  XListBox_GetSelectCount(hEle);
    }
    int GetItemMouseStay()
    {
        return  XListBox_GetItemMouseStay(hEle);
    }
    BOOL SelectAll()
    {
        return  XListBox_SelectAll(hEle);
    }
    void SetItemHeightDefault(int nHeight, int nSelHeight)
    {
        XListBox_SetItemHeightDefault(hEle, nHeight, nSelHeight);
    }
    void GetItemHeightDefault(out_ int *pHeight, out_ int *pSelHeight)
    {
        XListBox_GetItemHeightDefault(hEle, pHeight, pSelHeight);
    }
    int GetItemIndexFromHXCGUI(HXCGUI hXCGUI)
    {
        return  XListBox_GetItemIndexFromHXCGUI(hEle, hXCGUI);
    }
    void SetRowSpace(int nSpace)
    {
        XListBox_SetRowSpace(hEle, nSpace);
    }
    int GetRowSpace()
    {
        return  XListBox_GetRowSpace(hEle);
    }
    int HitTest(POINT *pPt)
    {
        return  XListBox_HitTest(hEle, pPt);
    }
    int HitTestOffset(POINT *pPt)
    {
        return  XListBox_HitTestOffset(hEle, pPt);
    }
    BOOL SetItemTemplateXML(const wchar_t *pXmlFile)
    {
        return  XListBox_SetItemTemplateXML(hEle, pXmlFile);
    }
    BOOL SetItemTemplateXMLFromString(const char *pStringXML)
    {
        return  XListBox_SetItemTemplateXMLFromString(hEle, pStringXML);
    }
    HXCGUI GetTemplateObject(int iItem, int nTempItemID)
    {
        return  XListBox_GetTemplateObject(hEle, iItem, nTempItemID);
    }
    void EnableMultiSel(BOOL bEnable)
    {
        XListBox_EnableMultiSel(hEle, bEnable);
    }
    void BindAdapter(XAdTable hAdapter)
    {
        XListBox_BindAdapter(hEle, hAdapter);
    }
    XAdTable GetAdapter()
    {
		XAdTable table(XListBox_GetAdapter(hEle));
        return  table;
    }
    void RefreshData()
    {
        XListBox_RefreshData(hEle);
    }
	VOID Sort( int iColumnAdapter,BOOL bAscending)
	{
		XListBox_Sort(hEle,iColumnAdapter,bAscending);
	}
	VOID SetSort(int iColumn, int iColumnAdapter, BOOL bEnable)//设置排序
	{
		XList_SetSort(hEle,iColumn,iColumnAdapter,bEnable);
	}

	VOID RefreshItem(int iItem)
	{
		XListBox_RefreshItem(hEle,iItem);
	}
};

class XListView : public XSViewBase
{
public:
	XListView()
	{

	}
	XListView(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XListView(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hEle = XListView_Create(x, y, cx, cy, hParent);
        return hEle;
    }
    void BindAdapter(XAdListView hAdapter)
    {
        XListView_BindAdapter(hEle, hAdapter);
    }
    XAdListView GetAdapter()
    {
		XAdListView adapter(XListView_GetAdapter(hEle));
        return  adapter;
    }
    BOOL SetItemTemplateXML(const wchar_t *pXmlFile)
    {
        return  XListView_SetItemTemplateXML(hEle, pXmlFile);
    }
    BOOL SetItemTemplateXMLFromString(const char *pStringXML)
    {
        return  XListView_SetItemTemplateXMLFromString(hEle, pStringXML);
    }
    HXCGUI GetTemplateObject(int iGroup, int iItem, int nTempItemID)
    {
        return  XListView_GetTemplateObject(hEle, iGroup, iItem, nTempItemID);
    }
    HXCGUI GetTemplateObjectGroup(int iGroup, int nTempItemID)
    {
        return  XListView_GetTemplateObjectGroup(hEle, iGroup, nTempItemID);
    }
    BOOL GetItemIDFromHXCGUI(HXCGUI hXCGUI, out_ int *piGroup, out_ int *piItem)
    {
        return  XListView_GetItemIDFromHXCGUI(hEle, hXCGUI, piGroup, piItem);
    }
    BOOL HitTest(in_ POINT *pPt, out_ int *pOutGroup, out_ int *pOutItem)
    {
        return  XListView_HitTest(hEle, pPt, pOutGroup, pOutItem);
    }
    int HitTestOffset(in_ POINT *pPt, out_ int *pOutGroup, out_ int *pOutItem)
    {
        return  XListView_HitTestOffset(hEle, pPt, pOutGroup, pOutItem);
    }
    void EnableMultiSel(BOOL bEnable)
    {
        XListView_EnableMultiSel(hEle, bEnable);
    }
    void SetDrawItemBkFlags(int nFlags)
    {
        XListView_SetDrawItemBkFlags(hEle, nFlags);
    }
    BOOL SetSelectItem(int iGroup, int iItem)
    {
        return  XListView_SetSelectItem(hEle, iGroup, iItem);
    }
    BOOL GetSelectItem(int *piGroup, int *piItem)
    {
        return  XListView_GetSelectItem(hEle, piGroup, piItem);
    }
    int GetSelectItemCount()
    {
        return  XListView_GetSelectItemCount(hEle);
    }
    int GetSelectItemAll(out_ listView_item_id_i *pArray, int nArraySize)
    {
        return  XListView_GetSelectItemAll(hEle, pArray, nArraySize);
    }
    void SetSelectItemAll()
    {
        XListView_SetSelectItemAll(hEle);
    }
    void CancelSelectItemAll()
    {
        XListView_CancelSelectItemAll(hEle);
    }
    void SetColumnSpace(int space)
    {
        XListView_SetColumnSpace(hEle, space);
    }
    void SetRowSpace(int space)
    {
        XListView_SetRowSpace(hEle, space);
    }
    void SetAlignSizeLeft(int size)
    {
        XListView_SetAlignSizeLeft(hEle, size);
    }
    void SetAlignSizeTop(int size)
    {
        XListView_SetAlignSizeTop(hEle, size);
    }
    void SetItemSize(int width, int height)
    {
        XListView_SetItemSize(hEle, width, height);
    }
    void GetItemSize(SIZE *pSize)
    {
        XListView_GetItemSize(hEle, pSize);
    }
    void SetGroupHeight(int height)
    {
        XListView_SetGroupHeight(hEle, height);
    }
    int GetGroupHeight()
    {
        return  XListView_GetGroupHeight(hEle);
    }
    void SetGroupUserData(int iGroup, int nData)
    {
        XListView_SetGroupUserData(hEle, iGroup, nData);
    }
    void SetItemUserData(int iGroup, int iItem, int nData)
    {
        XListView_SetItemUserData(hEle, iGroup, iItem, nData);
    }
    int GetGroupUserData(int iGroup)
    {
        return  XListView_GetGroupUserData(hEle, iGroup);
    }
    int GetItemUserData(int iGroup, int iItem)
    {
        return  XListView_GetItemUserData(hEle, iGroup, iItem);
    }
    void AddItemBkBorder(list_item_state_ nState, COLORREF color, BYTE alpha, int width)
    {
        XListView_AddItemBkBorder(hEle, nState, color, alpha, width);
    }
    void AddItemBkFill(list_item_state_ nState, COLORREF color, BYTE alpha)
    {
        XListView_AddItemBkFill(hEle, nState, color, alpha);
    }
    void AddItemBkImage(list_item_state_ nState, HIMAGE hImage)
    {
        XListView_AddItemBkImage(hEle, nState, hImage);
    }
    int GetItemBkInfoCount()
    {
        return  XListView_GetItemBkInfoCount(hEle);
    }
    void ClearItemBkInfo()
    {
        XListView_ClearItemBkInfo(hEle);
    }
    void RefreshData()
    {
        XListView_RefreshData(hEle);
    }
    BOOL ExpandGroup(int iGroup, BOOL bExpand)
    {
        return  XListView_ExpandGroup(hEle, iGroup, bExpand);
    }
	HXCGUI CreateAdapter()
	{
		return XListView_CreateAdapter(hEle);
	}

	void RefreshItem(int iGroup,int iItem)
	{
		XListView_RefreshItem(hEle,iGroup,iItem);
	}
};

class XTree : public XSViewBase
{
public:
	XTree()
	{
	}
	XTree(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XTree(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hEle = XTree_Create(x, y, cx, cy, hParent);
        return  hEle;
    }
    void EnableDragItem(BOOL bEnable)
    {
        XTree_EnableDragItem(hEle, bEnable);
    }
    void EnableConnectLine(BOOL bEnable, BOOL bSolid)
    {
        XTree_EnableConnectLine(hEle, bEnable, bSolid);
    }
    void SetConnectLineColor(COLORREF color, BYTE alpha)
    {
        XTree_SetConnectLineColor(hEle, color, alpha);
    }
    BOOL SetItemTemplateXML(const wchar_t *pXmlFile)
    {
        return  XTree_SetItemTemplateXML(hEle, pXmlFile);
    }
    BOOL SetItemTemplateXMLSel(const wchar_t *pXmlFile)
    {
        return  XTree_SetItemTemplateXMLSel(hEle, pXmlFile);
    }
    BOOL SetItemTemplateXMLFromString(const char *pStringXML)
    {
        return  XTree_SetItemTemplateXMLFromString(hEle, pStringXML);
    }
    BOOL SetItemTemplateXMLSelFromString(const char *pStringXML)
    {
        return  XTree_SetItemTemplateXMLSelFromString(hEle, pStringXML);
    }
    void SetDrawItemBkFlags(int nFlags)
    {
        XTree_SetDrawItemBkFlags(hEle, nFlags);
    }
    BOOL SetItemData(int nID, int nUserData)
    {
        return  XTree_SetItemData(hEle, nID, nUserData);
    }
    int GetItemData(int nID)
    {
        return  XTree_GetItemData(hEle, nID);
    }
    BOOL SetSelectItem(int nID)
    {
        return  XTree_SetSelectItem(hEle, nID);
    }
    int GetSelectItem()
    {
        return  XTree_GetSelectItem(hEle);
    }
    BOOL IsExpand(int nID)
    {
        return  XTree_IsExpand(hEle, nID);
    }
    BOOL ExpandItem(int nID, BOOL bExpand)
    {
        return  XTree_ExpandItem(hEle, nID, bExpand);
    }
    int HitTest(POINT *pPt)
    {
        return  XTree_HitTest(hEle, pPt);
    }
    int HitTestOffset(POINT *pPt)
    {
        return  XTree_HitTestOffset(hEle, pPt);
    }
    int GetFirstChildItem(int nID)
    {
        return  XTree_GetFirstChildItem(hEle, nID);
    }
    int GetEndChildItem(int nID)
    {
        return  XTree_GetEndChildItem(hEle, nID);
    }
    int GetPrevSiblingItem(int nID)
    {
        return  XTree_GetPrevSiblingItem(hEle, nID);
    }
    int GetNextSiblingItem(int nID)
    {
        return  XTree_GetNextSiblingItem(hEle, nID);
    }
    int GetParentItem(int nID)
    {
        return  XTree_GetParentItem(hEle, nID);
    }
    void SetIndentation(int nWidth)
    {
        XTree_SetIndentation(hEle, nWidth);
    }
    int GetIndentation()
    {
        return  XTree_GetIndentation(hEle);
    }
    void SetItemHeight(int nID, int nHeight, int nSelHeight)
    {
        XTree_SetItemHeight(hEle, nID, nHeight, nSelHeight);
    }
    void GetItemHeight(int nID, out_ int *pHeight, out_ int *pSelHeight)
    {
        XTree_GetItemHeight(hEle, nID, pHeight, pSelHeight);
    }
    void SetRowSpace(int nSpace)
    {
        XTree_SetRowSpace(hEle, nSpace);
    }
    int GetRowSpace()
    {
        return  XTree_GetRowSpace(hEle);
    }
    BOOL MoveItem(int nMoveItem, int nDestItem, int nType)
    {
        return  XTree_MoveItem(hEle, nMoveItem, nDestItem, nType);
    }
    void AddItemBkBorder(tree_item_state_ nState, COLORREF color, BYTE alpha, int width)
    {
        XTree_AddItemBkBorder(hEle, nState, color, alpha, width);
    }
    void AddItemBkFill(tree_item_state_ nState, COLORREF color, BYTE alpha)
    {
        XTree_AddItemBkFill(hEle, nState, color, alpha);
    }
    void AddItemBkImage(tree_item_state_ nState, HIMAGE hImage)
    {
        XTree_AddItemBkImage(hEle, nState, hImage);
    }
    int GetItemBkInfoCount()
    {
        return  XTree_GetItemBkInfoCount(hEle);
    }
    void ClearItemBkInfo()
    {
        XTree_ClearItemBkInfo(hEle);
    }
    void SetItemHeightDefault(int nHeight, int nSelHeight)
    {
        XTree_SetItemHeightDefault(hEle, nHeight, nSelHeight);
    }
    void GetItemHeightDefault(out_ int *pHeight, out_ int *pSelHeight)
    {
        XTree_GetItemHeightDefault(hEle, pHeight, pSelHeight);
    }
    HXCGUI GetTemplateObject(int nID, int nTempItemID)
    {
        return  XTree_GetTemplateObject(hEle, nID, nTempItemID);
    }
    int GetItemIDFromHXCGUI(HXCGUI hXCGUI)
    {
        return  XTree_GetItemIDFromHXCGUI(hEle, hXCGUI);
    }
    void BindAdapter(XAdTree hAdapter)
    {
        XTree_BindAdapter(hEle, hAdapter);
    }
    XAdTree GetAdapter()
    {
		XAdTree adapter(XTree_GetAdapter(hEle));
        return  adapter;
    }
    void RefreshData()
    {
        XTree_RefreshData(hEle);
    }
	HXCGUI CreateAdapter()
	{
		return XTree_CreateAdapter(hEle);
	}

	void EnableExpand(HELE hEle,BOOL bEnable)
	{
		XTree_EnableExpand(hEle,bEnable);
	}
	void SetConnectLineLength( int nLength)
	{
		XTree_SetConnectLineLength(hEle,nLength);
	}

	void RefreshItem(int nID)
	{
		XTree_RefreshItem(hEle,nID);
	}
	BOOL ExpandAllChildItem(int nID,BOOL bExpand)
	{
		return XTree_ExpandAllChildItem(hEle,nID,bExpand);
	}
	
};

class XPGrid : public XSViewBase
{
public:
	XPGrid()
	{

	}
	XPGrid(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XPGrid(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hEle = XPGrid_Create(x, y, cx, cy, hParent);
        return  hEle;
    }
    int AddItem(const wchar_t *pName, propertyGrid_item_type_ nType, int nParentID = XC_ID_ROOT)
    {
        return  XPGrid_AddItem(hEle, pName, nType, nParentID);
    }
    int AddItemString(const wchar_t *pName, const wchar_t *pValue, int nParentID = XC_ID_ROOT)
    {
        return  XPGrid_AddItemString(hEle, pName, pValue, nParentID);
    }
    void DeleteAll()
    {
        XPGrid_DeleteAll(hEle);
    }
    HELE GetItemHELE(int nItemID)
    {
        return  XPGrid_GetItemHELE(hEle, nItemID);
    }
    void SetWidth(int nWidth)
    {
        XPGrid_SetWidth(hEle, nWidth);
    }
    BOOL SetItemValue(int nItemID, const wchar_t *pValue)
    {
        return  XPGrid_SetItemValue(hEle, nItemID, pValue);
    }
    BOOL SetItemValueInt(int nItemID, int nValue)
    {
        return  XPGrid_SetItemValueInt(hEle, nItemID, nValue);
    }
    int HitTest(POINT *pPt, BOOL *pbExpandButton)
    {
        return  XPGrid_HitTest(hEle, pPt, pbExpandButton);
    }
    int HitTestOffset(POINT *pPt, BOOL *pbExpandButton)
    {
        return  XPGrid_HitTestOffset(hEle, pPt, pbExpandButton);
    }
    BOOL ExpandItem(int nItemID, BOOL bExpand)
    {
        return  XPGrid_ExpandItem(hEle, nItemID, bExpand);
    }
    int GetSelItem()
    {
        return  XPGrid_GetSelItem(hEle);
    }
    BOOL SetSelItem(int nItemID)
    {
        return  XPGrid_SetSelItem(hEle, nItemID);
    }
	BOOL SetItemData(int nItemID, int nUserData)
	{
		return XPGrid_SetItemData(hEle,nItemID,nUserData);
	}
	int GetItemData(int nItemID)
	{
		return XPGrid_GetItemData(hEle,nItemID);
	}
	void SetDrawItemBkFlags(int nFlags)
	{
		XPGrid_SetDrawItemBkFlags(hEle,nFlags);
	}
};

class XRichEditBase : public XSViewBase
{
public:
	void InsertString(const wchar_t *pString, HFONTX hFont=NULL)
    {
        XRichEdit_InsertString(hEle, pString, hFont);
    }
    BOOL InsertImage(HIMAGE hImage, const wchar_t *pImagePath)
    {
        return  XRichEdit_InsertImage(hEle, hImage, pImagePath);
    }
    BOOL InsertGif(HIMAGE hImage, const wchar_t *pImagePath)
    {
        return  XRichEdit_InsertGif(hEle, hImage, pImagePath);
    }
    void InsertStringEx(int iRow, int iColumn, const wchar_t *pString, HFONTX hFont=NULL)
    {
        XRichEdit_InsertStringEx(hEle, iRow, iColumn, pString, hFont);
    }
    BOOL InsertImageEx(int iRow, int iColumn, HIMAGE hImage, const wchar_t *pImagePath)
    {
        return  XRichEdit_InsertImageEx(hEle, iRow, iColumn, hImage, pImagePath);
    }
    BOOL InsertGifEx(int iRow, int iColumn, HIMAGE hImage, const wchar_t *pImagePath)
    {
        return  XRichEdit_InsertGifEx(hEle, iRow, iColumn, hImage, pImagePath);
    }
    void EnableReadOnly(BOOL bEnable)
    {
        XRichEdit_EnableReadOnly(hEle, bEnable);
    }
    void EnableMultiLine(BOOL bEnable)
    {
        XRichEdit_EnableMultiLine(hEle, bEnable);
    }
    void EnablePassword(BOOL bEnable)
    {
        XRichEdit_EnablePassword(hEle, bEnable);
    }
    void EnableEvent_XE_RICHEDIT_CHANGE(BOOL bEnable)
    {
        XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(hEle, bEnable);
    }
    void EnableAutoWrap(BOOL bEnable)
    {
        XRichEdit_EnableAutoWrap(hEle, bEnable);
    }
    void EnableAutoSelAll(BOOL bEnable)
    {
        XRichEdit_EnableAutoSelAll(hEle, bEnable);
    }
    void SetLimitNum(int nNumber)
    {
        XRichEdit_SetLimitNum(hEle, nNumber);
    }
    void SetText(const wchar_t *pString)
    {
        XRichEdit_SetText(hEle, pString);
    }
    void SetTextInt(int nVaule)
    {
        XRichEdit_SetTextInt(hEle, nVaule);
    }
    int GetText(out_ wchar_t *pOut, int len)
    {
        return  XRichEdit_GetText(hEle, pOut, len);
    }
    void GetHTMLFormat(out_ wchar_t *pOut, int len)
    {
        XRichEdit_GetHTMLFormat(hEle, pOut, len);
    }
    void *GetData(out_ int *pDataSize = NULL)
    {
        return  XRichEdit_GetData(hEle, pDataSize);
    }
    BOOL InsertData(void *pData, int iRow, int iColumn)
    {
        return  XRichEdit_InsertData(hEle, pData, iRow, iColumn);
    }
    int GetTextLength()
    {
        return  XRichEdit_GetTextLength(hEle);
    }
    void SetRowHeight(UINT nHeight)
    {
        XRichEdit_SetRowHeight(hEle, nHeight);
    }
    void SetDefaultText(const wchar_t *pString)
    {
        XRichEdit_SetDefaultText(hEle, pString);
    }
    void SetDefaultTextColor(COLORREF color, BYTE alpha)
    {
        XRichEdit_SetDefaultTextColor(hEle, color, alpha);
    }
    int GetCurrentRow()
    {
        return  XRichEdit_GetCurrentRow(hEle);
    }
    int GetCurrentColumn()
    {
        return  XRichEdit_GetCurrentColumn(hEle);
    }
    void SetCurrentPos(int iRow, int iColumn)
    {
        XRichEdit_SetCurrentPos(hEle, iRow, iColumn);
    }
    int GetRowCount()
    {
        return  XRichEdit_GetRowCount(hEle);
    }
    int GetRowLength(int iRow)
    {
        return  XRichEdit_GetRowLength(hEle, iRow);
    }
    int GetSelectText(out_ wchar_t *pOut, int len)
    {
        return  XRichEdit_GetSelectText(hEle, pOut, len);
    }
    BOOL GetSelectPosition(out_ Position_i *pBegin, out_ Position_i *pEnd)
    {
        return  XRichEdit_GetSelectPosition(hEle, pBegin, pEnd);
    }
    BOOL SetSelect(int iStartRow, int iStartCol, int iEndRow, int iEndCol)
    {
        return  XRichEdit_SetSelect(hEle, iStartRow, iStartCol, iEndRow, iEndCol);
    }
    BOOL SetItemFontEx(int beginRow, int beginColumn, int endRow, int endColumn, HFONTX hFont)
    {
        return  XRichEdit_SetItemFontEx(hEle, beginRow, beginColumn, endRow, endColumn, hFont);
    }
    BOOL SetItemColorEx(int beginRow, int beginColumn, int endRow, int endColumn, COLORREF color, BYTE alpha = 255)
    {
        return  XRichEdit_SetItemColorEx(hEle, beginRow, beginColumn, endRow, endColumn, color, alpha);
    }
    void CancelSelect()
    {
        XRichEdit_CancelSelect(hEle);
    }
    void SetSelectBkColor(COLORREF color, BYTE alpha = 255)
    {
        XRichEdit_SetSelectBkColor(hEle, color, alpha);
    }
    BOOL IsEmpty()
    {
        return  XRichEdit_IsEmpty(hEle);
    }
    BOOL SelectAll()
    {
        return  XRichEdit_SelectAll(hEle);
    }
    BOOL DeleteSelect()
    {
        return  XRichEdit_DeleteSelect(hEle);
    }
    void DeleteAll()
    {
        XRichEdit_DeleteAll(hEle);
    }
    BOOL ClipboardCut()
    {
        return  XRichEdit_ClipboardCut(hEle);
    }
    BOOL ClipboardCopy()
    {
        return  XRichEdit_ClipboardCopy(hEle);
    }
    BOOL ClipboardPaste()
    {
        return  XRichEdit_ClipboardPaste(hEle);
    }
	void SetCaretColor(COLORREF color)
	{
		XRichEdit_SetCaretColor(hEle,color);
	}
	void EnableVerticalCenter(BOOL bEnable)
	{
		XRichEdit_EnableVerticalCenter(hEle,bEnable);
	}
	BOOL IsReadOnly()
	{
		return XRichEdit_IsReadOnly(hEle);
	}
	BOOL IsMultiLine()
	{
		return XRichEdit_IsMultiLine(hEle);
	}
	BOOL IsPassword()
	{
		return XRichEdit_IsPassword(hEle);
	}
	BOOL IsAutoWrap()
	{
		XRichEdit_IsAutoWrap(hEle);
	}	
};

class XComboBox : public XRichEditBase
{
public:
	XComboBox()
	{

	}
	XComboBox(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XComboBox(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
    {
		hEle = XComboBox_Create(x, y, cx, cy, hParent);
        return  hEle?TRUE:FALSE;
    }
    BOOL SetSelItem(int iIndex)
    {
        return  XComboBox_SetSelItem(hEle, iIndex);
    }
    void GetButtonRect(out_ RECT *pRect)
    {
        XComboBox_GetButtonRect(hEle, pRect);
    }
    void SetButtonSize(int size)
    {
        XComboBox_SetButtonSize(hEle, size);
    }
    void SetDropHeight(int height)
    {
        XComboBox_SetDropHeight(hEle, height);
    }
    int GetDropHeight()
    {
        return  XComboBox_GetDropHeight(hEle);
    }
    void BindApapter(HXCGUI hAdapter)
    {
        XComboBox_BindApapter(hEle, hAdapter);
    }
    HXCGUI GetApapter()
    {
        return  XComboBox_GetApapter(hEle);
    }
    void SetItemTemplateXML(const wchar_t *pXmlFile)
    {
        XComboBox_SetItemTemplateXML(hEle, pXmlFile);
    }
    void SetItemTemplateXMLFromString(const char *pStringXML)
    {
        XComboBox_SetItemTemplateXMLFromString(hEle, pStringXML);
    }
    void EnableDrawButton(BOOL bEnable)
    {
        XComboBox_EnableDrawButton(hEle, bEnable);
    }
    void EnableEdit(BOOL bEdit)
    {
        XComboBox_EnableEdit(hEle, bEdit);
    }
    void AddBkBorder(comboBox_state_ nState, COLORREF color, BYTE alpha, int width)
    {
        XComboBox_AddBkBorder(hEle, nState, color, alpha, width);
    }
    void AddBkFill(comboBox_state_ nState, COLORREF color, BYTE alpha)
    {
        XComboBox_AddBkFill(hEle, nState, color, alpha);
    }
    void AddBkImage(comboBox_state_ nState, HIMAGE hImage)
    {
        XComboBox_AddBkImage(hEle, nState, hImage);
    }
    void ClearBkInfo()
    {
        XComboBox_ClearBkInfo(hEle);
    }
    int GetSelItem()
    {
        return  XComboBox_GetSelItem(hEle);
    }
    comboBox_state_ GetState()
    {
        return  XComboBox_GetState(hEle);
    }
	
	int GetBkInfoCount(HELE hEle)
    {
        return  XComboboX_GetBkInfoCount(hEle);
    }
	void EnableDropHeightFixed(BOOL bEnable)
	{
		XComboBox_EnableDropHeightFixed(hEle,bEnable);
	}
	
};

class XRichEdit : public XRichEditBase
{
public:
	XRichEdit()
	{

	}
	XRichEdit(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XRichEdit(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
    {
		hEle = XRichEdit_Create(x, y, cx, cy, hParent);
        return  hEle?TRUE:FALSE;
    }
};


class XRichEditColor : public XRichEditBase
{
public:
	XRichEditColor()
	{
		
	}
	XRichEditColor(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XRichEditColor(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent)
    {
		hEle = XRichEditColor_Create(x, y, cx, cy, hParent);
        return  hEle;
    }
    void SetColor(COLORREF color)
    {
        XRichEditColor_SetColor(hEle, color);
    }
    COLORREF GetColor()
    {
        return  XRichEditColor_GetColor(hEle);
    }
};
class XRichEditSet : public XRichEditBase
{
public:
	XRichEditSet()
	{
		
	}
	XRichEditSet(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XRichEditSet(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent)
    {
		hEle = XRichEditSet_Create(x, y, cx, cy, hParent);
        return  hEle;
    }
};

class XRichEditFile : public XRichEditBase
{
public:
	XRichEditFile()
	{
		
	}
	XRichEditFile(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XRichEditFile(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
    {
		hEle = XRichEditFile_Create(x, y, cx, cy, hParent);
        return hEle;
    }
    void SetOpenFileType(const wchar_t *pType)
    {
        XRichEditFile_SetOpenFileType(hEle, pType);
    }
    void SetDefaultFile(const wchar_t *pFile)
    {
        XRichEditFile_SetDefaultFile(hEle, pFile);
    }
    void SetRelativeDir(const wchar_t *pDir)
    {
        XRichEditFile_SetRelativeDir(hEle, pDir);
    }
};

class XRichEditFolder : public XRichEditBase
{
public:
	XRichEditFolder()
	{
		
	}
	XRichEditFolder(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XRichEditFolder(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent)
    {
		hEle = XRichEditFolder_Create(x, y, cx, cy, hParent);
        return hEle; 
    }
    void SetDefaultDir(const wchar_t *pDir)
    {
        XRichEditFolder_SetDefaultDir(hEle, pDir);
    }
};

class XMenu
{
public:
	HMENUX hMenu;
	XMenu()
	{

	}
	XMenu(HMENUX hMenuIn)
	{
		hMenu = hMenuIn;
	}
    HMENUX Create()
    {
        hMenu = XMenu_Create();
		return hMenu;
    }
    void AddItem(int nID, const wchar_t *pText, int parentId =  XC_ID_ROOT, int nFlags =  0)
    {
        XMenu_AddItem(hMenu, nID, pText, parentId, nFlags);
    }
    void AddItemIcon(int nID, const wchar_t *pText, int nParentID, HIMAGE hImage, int nFlags = 0)
    {
        XMenu_AddItemIcon(hMenu, nID, pText, nParentID, hImage, nFlags);
    }
    void InsertItem(int nID, const wchar_t *pText, int nFlags, int insertID)
    {
        XMenu_InsertItem(hMenu, nID, pText, nFlags, insertID);
    }
    void InsertItemIcon(int nID, const wchar_t *pText, HIMAGE hIcon, int nFlags, int insertID)
    {
        XMenu_InsertItemIcon(hMenu, nID, pText, hIcon, nFlags, insertID);
    }
    void SetAutoDestroy(BOOL bAuto)
    {
        XMenu_SetAutoDestroy(hMenu, bAuto);
    }
    void EnableDrawBackground(BOOL bEnable)
    {
        XMenu_EnableDrawBackground(hMenu, bEnable);
    }
    void EnableDrawItem(BOOL bEnable)
    {
        XMenu_EnableDrawItem(hMenu, bEnable);
    }
    BOOL Popup(HWND hParentWnd, int x, int y, HELE hParentEle = NULL, menu_popup_position_ nPosition = menu_popup_position_left_top)
    {
        return  XMenu_Popup(hMenu, hParentWnd, x, y, hParentEle, nPosition);
    }
    void DestroyMenu()
    {
        XMenu_DestroyMenu(hMenu);
    }
    void CloseMenu()
    {
        XMenu_CloseMenu(hMenu);
    }
    void SetBkImage(HIMAGE hImage)
    {
        XMenu_SetBkImage(hMenu, hImage);
    }
    BOOL SetItemText(int nID, const wchar_t *pText)
    {
        return  XMenu_SetItemText(hMenu, nID, pText);
    }
    BOOL GetItemText(int nID, out_ wchar_t *pOut, int nOutLen)
    {
        return  XMenu_GetItemText(hMenu, nID, pOut, nOutLen);
    }
    int GetItemTextLength(int nID)
    {
        return  XMenu_GetItemTextLength(hMenu, nID);
    }
    BOOL SetItemIcon(int nID, HIMAGE hIcon)
    {
        return  XMenu_SetItemIcon(hMenu, nID, hIcon);
    }
    BOOL SetItemFlags(int nID, int uFlags)
    {
        return  XMenu_SetItemFlags(hMenu, nID, uFlags);
    }
    void SetItemHeight(int height)
    {
        XMenu_SetItemHeight(hMenu, height);
    }
    int GetItemHeight()
    {
        return  XMenu_GetItemHeight(hMenu);
    }
    void SetBorderColor(COLORREF crColor, BYTE alpha = 255)
    {
        XMenu_SetBorderColor(hMenu, crColor, alpha);
    }
    int GetLeftWidth()
    {
        return  XMenu_GetLeftWidth(hMenu);
    }
    int GetLeftSpaceText()
    {
        return  XMenu_GetLeftSpaceText(hMenu);
    }
    int GetItemCount()
    {
        return  XMenu_GetItemCount(hMenu);
    }
    BOOL SetItemCheck(int nID, BOOL bCheck)
    {
        return  XMenu_SetItemCheck(hMenu, nID, bCheck);
    }
    BOOL IsItemCheck(int nID)
    {
        return  XMenu_IsItemCheck(hMenu, nID);
    }
};

class XMenuBar : public XEleBase
{
public:
	XMenuBar()
	{
		
	}
	XMenuBar(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XMenuBar(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}	
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
    {
		hEle = XMenuBar_Create(x, y, cx, cy, hParent);
		return hEle?TRUE:FALSE;
    }
    int AddButton(const wchar_t *pText)
    {
        return  XMenuBar_AddButton(hEle, pText);
    }
    void SetButtonHeight(int height)
    {
        XMenuBar_SetButtonHeight(hEle, height);
    }
    XMenu GetMenu(int nIndex)
    {
		XMenu menu(XMenuBar_GetMenu(hEle, nIndex));
        return  menu;
    }
    BOOL DeleteButton(int nIndex)
    {
        return  XMenuBar_DeleteButton(hEle, nIndex);
    }
};

class XToolBar : public XEleBase
{
public:
	XToolBar()
	{
		
	}
	XToolBar(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XToolBar(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}	
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hEle = XToolBar_Create(x, y, cx, cy, hParent);
		return hEle;
    }
    int InsertEle(HELE hNewEle, int index = -1)
    {
        return  XToolBar_InsertEle(hEle, hNewEle, index);
    }
    int InsertSeparator(int index = -1,COLORREF color=RGB(128,128,128))
    {
        return  XToolBar_InsertSeparator(hEle, index,color);
    }
    void EnableButtonMenu(BOOL bEnable)
    {
        XToolBar_EnableButtonMenu(hEle, bEnable);
    }
    HELE GetHEle(int index)
    {
        return  XToolBar_GetHEle(hEle, index);
    }
    HELE GetButtonLeft()
    {
        return  XToolBar_GetButtonLeft(hEle);
    }
    HELE GetButtonRight()
    {
        return  XToolBar_GetButtonRight(hEle);
    }
    HELE GetButtonMenu()
    {
        return  XToolBar_GetButtonMenu(hEle);
    }
    void SetSpace(int nSize)
    {
        XToolBar_SetSpace(hEle, nSize);
    }
    void DeleteEle(int index)
    {
        XToolBar_DeleteEle(hEle, index);
    }
    void DeleteAllEle()
    {
        XToolBar_DeleteAllEle(hEle);
    }
};

class XTabBar : public XEleBase
{
public:
	XTabBar()
	{
		
	}
	XTabBar(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XTabBar(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}		
    HELE Create(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
    {
		hEle = XTabBar_Create(x, y, cx, cy, hParent);
		return hEle;
    }
    int AddLabel(const wchar_t *pName)
    {
        return  XTabBar_AddLabel(hEle, pName);
    }
    int InsertLabel(int index, wchar_t *pName)
    {
        return  XTabBar_InsertLabel(hEle, index, pName);
    }
    BOOL DeleteLabel(int index)
    {
        return  XTabBar_DeleteLabel(hEle, index);
    }
    void DeleteLabelAll()
    {
        XTabBar_DeleteLabelAll(hEle);
    }
    HELE GetLabel(int index)
    {
        return  XTabBar_GetLabel(hEle, index);
    }
    HELE GetLabelClose(int index)
    {
        return  XTabBar_GetLabelClose(hEle, index);
    }
    HELE GetButtonLeft()
    {
        return  XTabBar_GetButtonLeft(hEle);
    }
    HELE GetButtonRight()
    {
        return  XTabBar_GetButtonRight(hEle);
    }
    int GetSelect()
    {
        return  XTabBar_GetSelect(hEle);
    }
    int GetLabelSpacing()
    {
        return  XTabBar_GetLabelSpacing(hEle);
    }
    int GetLabelCount()
    {
        return  XTabBar_GetLabelCount(hEle);
    }
    void SetLabelSpacing(int spacing)
    {
        XTabBar_SetLabelSpacing(hEle, spacing);
    }
    void SetSelect(int index)
    {
        XTabBar_SetSelect(hEle, index);
    }
    void SetUp()
    {
        XTabBar_SetUp(hEle);
    }
    void SetDown()
    {
        XTabBar_SetDown(hEle);
    }
    void EnableTile(BOOL bTile)
    {
        XTabBar_EnableTile(hEle, bTile);
    }
    void EnableClose(BOOL bEnable)
    {
        XTabBar_EnableClose(hEle, bEnable);
    }
    void SetCloseSize(SIZE *pSize)
    {
        XTabBar_SetCloseSize(hEle, pSize);
    }
    void SetTurnButtonSize(SIZE *pSize)
    {
        XTabBar_SetTurnButtonSize(hEle, pSize);
    }
    BOOL ShowLabel(int index, BOOL bShow)
    {
        return  XTabBar_ShowLabel(hEle, index, bShow);
    }

	int GetindexByEle(HELE hLabel)
	{
		return XTabBar_GetindexByEle(hEle,hLabel);
	}
	void SetLabelWidth(int index, int nWidth)
	{
		XTabBar_SetLabelWidth(hEle,index,nWidth);
	}
	void SetPadding(int left,int top,int right,int bottom)
	{
		XTabBar_SetPadding(hEle,left,top,right,bottom);
	}

	
};

class XSliderBar : public XEleBase
{
public:
	XSliderBar()
	{
		
	}
	XSliderBar(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XSliderBar(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}	
	BOOL Create(int x,int y,int cx,int cy,HXCGUI hParent=NULL)
	{
		hEle = XSliderBar_Create(x,y,cx,cy,hParent);
		return hEle?TRUE:FALSE;
	}
	void SetRange(int range)
	{
		XSliderBar_SetRange(hEle,range);
	}
	int GetRange()
	{
		return XSliderBar_GetRange(hEle);
	}
	void SetButtonWidth(int width)
	{
		XSliderBar_SetButtonWidth(hEle,width);
	}
	void SetButtonHeight(int height)
	{
		XSliderBar_SetButtonHeight(hEle,height);
	}
	
	void SetSpaceTwo(int leftSize,int rightSize)
	{
		XSliderBar_SetSpaceTwo(hEle,leftSize,rightSize);
	}
	void SetPos(int pos)
	{
		XSliderBar_SetPos(hEle,pos);
	}
	int GetPos()
	{
		return XSliderBar_GetPos(hEle);
	}
	
	XBtn GetButton()
	{
		XBtn btn(XSliderBar_GetButton(hEle));
		return btn;
	}
	
	void SetHorizon(BOOL bHorizon)
	{
		XSliderBar_SetHorizon(hEle,bHorizon);
	}
	void SetImageLoad(HIMAGE hImage)
	{
		XSliderBar_SetImageLoad(hEle,hImage);
	}
};

class XProgBar : public XEleBase
{
public:
	XProgBar()
	{
		
	}
	XProgBar(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XProgBar(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}	
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hEle = XProgBar_Create(x, y, cx, cy, hParent);
		return hEle?TRUE:FALSE;
    }
    void SetRange(int range)
    {
        XProgBar_SetRange(hEle, range);
    }
    int GetRange()
    {
        return  XProgBar_GetRange(hEle);
    }
    void SetSpaceTwo(int leftSize, int rightSize)
    {
        XProgBar_SetSpaceTwo(hEle, leftSize, rightSize);
    }
    void SetPos(int pos)
    {
        XProgBar_SetPos(hEle, pos);
    }
    int GetPos()
    {
        return  XProgBar_GetPos(hEle);
    }
    void SetHorizon(BOOL bHorizon)
    {
        XProgBar_SetHorizon(hEle, bHorizon);
    }
    void SetImageLoad(HIMAGE hImage)
    {
        XProgBar_SetImageLoad(hEle, hImage);
    }
};

class XDateTime : public XEleBase
{
public:
	XDateTime()
	{
		
	}
	XDateTime(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XDateTime(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent)
    {
		hEle = XDateTime_Create(x, y, cx, cy, hParent);
        return hEle?TRUE:FALSE; 
    }
    void SetStyle(int nStyle)
    {
        XDateTime_SetStyle(hEle, nStyle);
    }
    int GetStyle()
    {
        return  XDateTime_GetStyle(hEle);
    }
    void GetTime(int *pnHour, int *pnMinute, int *pnSecond)
    {
        XDateTime_GetTime(hEle, pnHour, pnMinute, pnSecond);
    }
    void SetTime(int nHour, int nMinute, int nSecond)
    {
        XDateTime_SetTime(hEle, nHour, nMinute, nSecond);
    }
    void GetDate(int *pnYear, int *pnMonth, int *pnDay)
    {
        XDateTime_GetDate(hEle, pnYear, pnMonth, pnDay);
    }
    void SetDate(int nYear, int nMonth, int nDay)
    {
        XDateTime_SetDate(hEle, nYear, nMonth, nDay);
    }
    COLORREF GetSelBkColor()
    {
        return  XDateTime_GetSelBkColor(hEle);
    }
    void SetSelBkColor(COLORREF crSelectBk, BYTE alpha =  255)
    {
        XDateTime_SetSelBkColor(hEle, crSelectBk, alpha);
    }
    HELE GetButton(int nType)
    {
        return  XDateTime_GetButton(hEle, nType);
    }
};

class XMonthCal : public XEleBase
{
public:
	XMonthCal()
	{
		
	}
	XMonthCal(HELE hEleIn)
	{
		hEle = hEleIn;
	}
	XMonthCal(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    BOOL Create(int x, int y, int cx, int cy, HXCGUI hParent)
    {
		hEle = XMonthCal_Create(x, y, cx, cy, hParent);
        return  hEle?TRUE:FALSE;
    }
    void SetToday(int nYear, int nMonth, int nDay)
    {
        XMonthCal_SetToday(hEle, nYear, nMonth, nDay);
    }
    void GetToday(int *pnYear, int *pnMonth, int *pnDay)
    {
        XMonthCal_GetToday(hEle, pnYear, pnMonth, pnDay);
    }
    void SeSelDate(int nYear, int nMonth, int nDay)
    {
        XMonthCal_SeSelDate(hEle, nYear, nMonth, nDay);
    }
    void GetSelDate(int *pnYear, int *pnMonth, int *pnDay)
    {
        XMonthCal_GetSelDate(hEle, pnYear, pnMonth, pnDay);
    }
    HELE GetButton(monthCal_button_type_ nType)
    {
        return  XMonthCal_GetButton(hEle, nType);
    }	
};

class XPane : public XEleBase
{
public:
	XPane()
	{
		
	}
	XPane(HELE hEle)
	{
		hEle = hEle;
	}
	XPane(const wchar_t *pName, int nWidth, int nHeight, HWINDOW hFrameWnd = NULL)
	{
		Create(pName,nWidth,nHeight,hFrameWnd);
	}
    BOOL Create(const wchar_t *pName, int nWidth, int nHeight, HWINDOW hFrameWnd = NULL)
    {
		hEle = XPane_Create(pName, nWidth, nHeight, hFrameWnd);
        return hEle?TRUE:FALSE;
    }
    void SetView(HELE hView)
    {
        XPane_SetView(hEle, hView);
    }
    BOOL IsShowPane()
    {
        return  XPane_IsShowPane(hEle);
    }
    void SetTitle(wchar_t *pTitle)
    {
        XPane_SetTitle(hEle, pTitle);
    }
    void GetTitle(out_ wchar_t *pOut, int nOutLen)
    {
        XPane_GetTitle(hEle, pOut, nOutLen);
    }
    void SetCaptionHeight(int nHeight)
    {
        XPane_SetCaptionHeight(hEle, nHeight);
    }
    int GetCaptionHeight()
    {
        return  XPane_GetCaptionHeight(hEle);
    }
    void HidePane()
    {
        XPane_HidePane(hEle);
    }
    void ShowPane()
    {
        XPane_ShowPane(hEle);
    }
    void DockPane()
    {
        XPane_DockPane(hEle);
    }
    void LockPane()
    {
        XPane_LockPane(hEle);
    }
    void FloatPane()
    {
        XPane_FloatPane(hEle);
    }
	void SetSize(int nWidth, int nHeight)
	{
		XPane_SetSize(hEle,nWidth,nHeight);
	}
	pane_state_ GetState()
	{
		return XPane_GetState(hEle);
	}

	void GetViewRect(RECT* pRect)
	{
		XPane_GetViewRect(hEle,pRect);
	}

};

class XShape
{
public:
	HXCGUI hShape;
	operator BOOL()
	{
		return hShape?TRUE:FALSE;
	}
	operator HXCGUI()
	{
		return hShape;
	}
	BOOL IsHXCGUI(XC_OBJECT_TYPE nType)
    {
        return  XC_IsHXCGUI(hShape, nType);
    }
    HELE GetParentEle()
    {
        return  XShape_GetParentEle(hShape);
    }
    HXCGUI GetParentLayout()
    {
        return  XShape_GetParentLayout(hShape);
    }
    HWINDOW GetHWINDOW()
    {
        return  XShape_GetHWINDOW(hShape);
    }
    HXCGUI GetParent()
    {
        return  XShape_GetParent(hShape);
    }
    void RemoveShape()
    {
        XShape_RemoveShape(hShape);
    }
    void SetID(int nID)
    {
        XShape_SetID(hShape, nID);
    }
    int GetID()
    {
        return  XShape_GetID(hShape);
    }
    void Redraw()
    {
        XShape_Redraw(hShape);
    }
    int GetWidth()
    {
        return  XShape_GetWidth(hShape);
    }
    int GetHeight()
    {
        return  XShape_GetHeight(hShape);
    }
    void GetRect(out_ RECT *pRect)
    {
        XShape_GetRect(hShape, pRect);
    }
    void SetRect(in_ RECT *pRect)
    {
        XShape_SetRect(hShape, pRect);
    }
    void GetContentSize(out_ SIZE *pSize)
    {
        XShape_GetContentSize(hShape, pSize);
    }
    void ShowLayout(BOOL bShow)
    {
        XShape_ShowLayout(hShape, bShow);
    }
    void AdjustLayout()
    {
        XShape_AdjustLayout(hShape);
    }
    void Destroy()
    {
        XShape_Destroy(hShape);
		hShape = NULL;
    }
	void SetUID(int nUID)
	{
		XShape_SetUID(hShape,nUID);
	}
	int  GetUID()
	{
		return XShape_GetUID(hShape);
	}
};

class XShapeLayout : public XShape
{
public:
	XC_OBJECT_TYPE GetObjectType()
    {
        return  XC_GetObjectType(hShape);
    }
    HXCGUI GetObjectByID(HWINDOW hWindow,int nID)
    {
		hShape = XC_GetObjectByID(hWindow,nID);
        return  hShape;
    }
    int GetResIDValue(const wchar_t *pName)
    {
        return  XRes_GetIDValue(pName);
    }
	// 封装以后更方便
	HXCGUI GetObjectByResID(HWINDOW hWindow,const wchar_t *pName)
	{
		hShape = XC_GetObjectByID(hWindow,XRes_GetIDValue(pName));
		return hShape;
	}
};

class XShapeText : public XShapeLayout
{
public:
	XShapeText()
	{

	}
	XShapeText(HXCGUI hShapeIn)
	{
		hShape = hShapeIn;
	}
	XShapeText(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,NULL,hParent);
	}
	XShapeText(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent = NULL)
	{
		Create(x,y,cx,cy,pName,hParent);
	}
    HXCGUI Create(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent = NULL)
    {
		hShape = XShapeText_Create(x, y, cx, cy, pName, hParent);
        return hShape;
    }
    void SetText(const wchar_t *pName)
    {
        XShapeText_SetText(hShape, pName);
    }
    void GetText(out_ wchar_t *pOut, int nOutLen)
    {
        XShapeText_GetText(hShape, pOut, nOutLen);
    }
    int GetTextLength()
    {
        return  XShapeText_GetTextLength(hShape);
    }
    void SetFont(HFONTX hFontx)
    {
        XShapeText_SetFont(hShape, hFontx);
    }
    void SetTextColor(COLORREF color, BYTE alpha)
    {
        XShapeText_SetTextColor(hShape, color, alpha);
    }
    COLORREF GetTextColor()
    {
        return  XShapeText_GetTextColor(hShape);
    }
    void SetTextAlign(int align)
    {
        XShapeText_SetTextAlign(hShape, align);
    }
    void SetOffset(int x, int y)
    {
        XShapeText_SetOffset(hShape, x, y);
    }
    void SetLayoutWidth(layout_size_type_ nType, int width)
    {
        XShapeText_SetLayoutWidth(hShape, nType, width);
    }
    void SetLayoutHeight(layout_size_type_ nType, int height)
    {
        XShapeText_SetLayoutHeight(hShape, nType, height);
    }
    void GetLayoutWidth(out_ layout_size_type_ * pType, out_ int *pWidth)
    {
        XShapeText_GetLayoutWidth(hShape, pType, pWidth);
    }
    void GetLayoutHeight(out_ layout_size_type_ * pType, out_ int *pHeight)
    {
        XShapeText_GetLayoutHeight(hShape, pType, pHeight);
    }	
	HFONTX GetFont()
	{
		return XShapeText_GetFont(hShape);
	}

	void EnableCSS(BOOL bEnable)
	{
		XShapeText_EnableCSS(hShape,bEnable);
	}
	void SetCssName(const wchar_t* pName)
	{
		XShapeText_SetCssName(hShape,pName);
	}
	const wchar_t* GetCssName()
	{
		return XShapeText_GetCssName(hShape);
	}
};
class XShapePic : public XShapeLayout
{
public:
	XShapePic()
	{

	}
	XShapePic(HXCGUI hParent)
	{
		hShape = XShapePic_Create(0, 0, 100, 20, hParent);
	}
	XShapePic(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hShape = XShapePic_Create(x, y, cx, cy, hParent);
        return hShape;
    }
    void SetImage(HIMAGE hImage)
    {
        XShapePic_SetImage(hShape, hImage);
    }
    void SetLayoutWidth(layout_size_type_ nType, int width)
    {
        XShapePic_SetLayoutWidth(hShape, nType, width);
    }
    void SetLayoutHeight(layout_size_type_ nType, int height)
    {
        XShapePic_SetLayoutHeight(hShape, nType, height);
    }
    void GetLayoutWidth(out_ layout_size_type_ * pType, out_ int *pWidth)
    {
        XShapePic_GetLayoutWidth(hShape, pType, pWidth);
    }
    void GetLayoutHeight(out_ layout_size_type_ * pType, out_ int *pHeight)
    {
        XShapePic_GetLayoutHeight(hShape, pType, pHeight);
    }	
};

class XShapeGif : public XShapeLayout
{
public:
	XShapeGif()
	{

	}
	XShapeGif(HXCGUI hShapeIn)
	{
		hShape = hShapeIn;
	}

	XShapeGif(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}

    HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hShape = XShapeGif_Create(x, y, cx, cy, hParent);
        return hShape;
    }
    void SetImage(HIMAGE hImage)
    {
        XShapeGif_SetImage(hShape, hImage);
    }
    void SetLayoutWidth(layout_size_type_ nType, int width)
    {
        XShapeGif_SetLayoutWidth(hShape, nType, width);
    }
    void SetLayoutHeight(layout_size_type_ nType, int height)
    {
        XShapeGif_SetLayoutHeight(hShape, nType, height);
    }
    void GetLayoutWidth(out_ layout_size_type_ * pType, out_ int *pWidth)
    {
        XShapeGif_GetLayoutWidth(hShape, pType, pWidth);
    }
    void GetLayoutHeight(out_ layout_size_type_ * pType, out_ int *pHeight)
    {
        XShapeGif_GetLayoutHeight(hShape, pType, pHeight);
    }	
};

class XShapeRect : public XShapeLayout
{
public:
	XShapeRect()
	{
		
	}
	XShapeRect(HXCGUI hShapeIn)
	{
		hShape = hShapeIn;
	}
	
	XShapeRect(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hShape = XShapeRect_Create(x, y, cx, cy, hParent);
        return hShape;
    }
    void SetBorderColor(COLORREF color, BYTE alpha = 255)
    {
        XShapeRect_SetBorderColor(hShape, color, alpha);
    }
    void SetFillColor(COLORREF color, BYTE alpha = 255)
    {
        XShapeRect_SetFillColor(hShape, color, alpha);
    }
    void SetRoundAngle(int nWidth, int nHeight)
    {
        XShapeRect_SetRoundAngle(hShape, nWidth, nHeight);
    }
    void GetRoundAngle(out_ int *pWidth, out_ int *pHeight)
    {
        XShapeRect_GetRoundAngle(hShape, pWidth, pHeight);
    }
    void EnableBorder(BOOL bEnable)
    {
        XShapeRect_EnableBorder(hShape, bEnable);
    }
    void EnableFill(BOOL bEnable)
    {
        XShapeRect_EnableFill(hShape, bEnable);
    }
    void EnableRoundAngle(BOOL bEnable)
    {
        XShapeRect_EnableRoundAngle(hShape, bEnable);
    }
};

class XShapeEllipse : public XShapeLayout
{
public:
	XShapeEllipse()
	{
		
	}
	XShapeEllipse(HXCGUI hShapeIn)
	{
		hShape = hShapeIn;
	}
	XShapeEllipse(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HXCGUI Create(int x, int y, int cx, int cy, HXCGUI hParent = NULL)
    {
		hShape =  XShapeEllipse_Create(x, y, cx, cy, hParent);
        return hShape;
    }
    void SetBorderColor(COLORREF color, BYTE alpha = 255)
    {
        XShapeEllipse_SetBorderColor(hShape, color, alpha);
    }
    void SetFillColor(COLORREF color, BYTE alpha = 255)
    {
        XShapeEllipse_SetFillColor(hShape, color, alpha);
    }
    void EnableBorder(BOOL bEnable)
    {
        XShapeEllipse_EnableBorder(hShape, bEnable);
    }
    void EnableFill(BOOL bEnable)
    {
        XShapeEllipse_EnableFill(hShape, bEnable);
    }
};

class XShapeGroupBox : public XShapeLayout
{
public:
	XShapeGroupBox()
	{
		
	}
	XShapeGroupBox(HXCGUI hShapeIn)
	{
		hShape = hShapeIn;
	}
	XShapeGroupBox(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,NULL,hParent);
	}
	XShapeGroupBox(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,pName,hParent);
	}
    HXCGUI Create(int x, int y, int cx, int cy, const wchar_t *pName, HXCGUI hParent = NULL)
    {
		hShape = XShapeGroupBox_Create(x, y, cx, cy, pName, hParent);
        return hShape;
    }
    void SetBorderColor(COLORREF color, BYTE alpha = 255)
    {
        XShapeGroupBox_SetBorderColor(hShape, color, alpha);
    }
    void SetTextColor(COLORREF color, BYTE alpha = 255)
    {
        XShapeGroupBox_SetTextColor(hShape, color, alpha);
    }
    void SetFontX(HFONTX hFontX)
    {
        XShapeGroupBox_SetFontX(hShape, hFontX);
    }
    void SetTextOffset(int offsetX, int offsetY)
    {
        XShapeGroupBox_SetTextOffset(hShape, offsetX, offsetY);
    }
    void SetRoundAngle(int nWidth, int nHeight)
    {
        XShapeGroupBox_SetRoundAngle(hShape, nWidth, nHeight);
    }
    void SetText(const wchar_t *pText)
    {
        XShapeGroupBox_SetText(hShape, pText);
    }
    void GetTextOffset(out_ int *pOffsetX, out_ int *pOffsetY)
    {
        XShapeGroupBox_GetTextOffset(hShape, pOffsetX, pOffsetY);
    }
    void GetRoundAngle(out_ int *pWidth, out_ int *pHeight)
    {
        XShapeGroupBox_GetRoundAngle(hShape, pWidth, pHeight);
    }
    void EnableRoundAngle(BOOL bEnable)
    {
        XShapeGroupBox_EnableRoundAngle(hShape, bEnable);
    }	
};

class XShapeLine : public XShapeLayout
{
public:
	XShapeLine()
	{
		
	}
	XShapeLine(HXCGUI hShapeIn)
	{
		hShape = hShapeIn;
	}
	XShapeLine(int x, int y, int cx, int cy, HXCGUI hParent =  NULL)
	{
		Create(x,y,cx,cy,hParent);
	}
    HXCGUI Create(int x1, int y1, int x2, int y2, HXCGUI hParent = NULL)
    {
		hShape = XShapeLine_Create(x1, y1, x2, y2, hParent);
        return hShape;
    }
    void SetPosition(int x1, int y1, int x2, int y2)
    {
        XShapeLine_SetPosition(hShape, x1, y1, x2, y2);
    }
    void SetColor(COLORREF color, BYTE alpha)
    {
        XShapeLine_SetColor(hShape, color, alpha);
    }	
};

class XImage
{
public:
	
    HIMAGE LoadFile(const wchar_t *pImageName, BOOL bStretch = FALSE)
    {
        return  XImage_LoadFile(pImageName, bStretch);
    }
    HIMAGE LoadFileAdaptive(const wchar_t *pImageName, int leftSize, int topSize, int rightSize, int bottomSize)
    {
        return  XImage_LoadFileAdaptive(pImageName, leftSize, topSize, rightSize, bottomSize);
    }
    HIMAGE LoadFileRect(const wchar_t *pImageName, int x, int y, int cx, int cy)
    {
        return  XImage_LoadFileRect(pImageName, x, y, cx, cy);
    }
    HIMAGE LoadResAdaptive(int id, const wchar_t *pType, int leftSize, int topSize, int rightSize, int bottomSize)
    {
        return  XImage_LoadResAdaptive(id, pType, leftSize, topSize, rightSize, bottomSize);
    }
    HIMAGE LoadRes(int id, const wchar_t *pType, BOOL bStretch = FALSE)
    {
        return  XImage_LoadRes(id, pType, bStretch);
    }
    HIMAGE LoadZip(const wchar_t *pZipFileName, const wchar_t *pImageName, const wchar_t *pPassword = NULL, BOOL bStretch = FALSE)
    {
        return  XImage_LoadZip(pZipFileName, pImageName, pPassword, bStretch);
    }
    HIMAGE LoadZipAdaptive(const wchar_t *pZipFileName, const wchar_t *pImageName, const wchar_t *pPassword, int x1, int x2, int y1, int y2)
    {
        return  XImage_LoadZipAdaptive(pZipFileName, pImageName, pPassword, x1, x2, y1, y2);
    }
    HIMAGE LoadZipRect(const wchar_t *pZipFileName, const wchar_t *pImageName, const wchar_t *pPassword, int x, int y, int cx, int cy)
    {
        return  XImage_LoadZipRect(pZipFileName, pImageName, pPassword, x, y, cx, cy);
    }
    HIMAGE LoadMemory(void *pBuffer, int nSize, BOOL bStretch)
    {
        return  XImage_LoadMemory(pBuffer, nSize, bStretch);
    }
    HIMAGE LoadMemoryRect(void *pBuffer, int nSize, int x, int y, int cx, int cy, BOOL bStretch)
    {
        return  XImage_LoadMemoryRect(pBuffer, nSize, x, y, cx, cy, bStretch);
    }
    HIMAGE LoadMemoryAdaptive(void *pBuffer, int nSize, int leftSize, int topSize, int rightSize, int bottomSize)
    {
        return  XImage_LoadMemoryAdaptive(pBuffer, nSize, leftSize, topSize, rightSize, bottomSize);
    }
    HIMAGE LoadFromImage(void *pImage)
    {
        return  XImage_LoadFromImage(pImage);
    }
    HIMAGE LoadFileFromExtractIcon(const wchar_t *pImageName)
    {
        return  XImage_LoadFileFromExtractIcon(pImageName);
    }
    HIMAGE LoadFileFromHICON(HICON hIcon)
    {
        return  XImage_LoadFileFromHICON(hIcon);
    }
    HIMAGE LoadFileFromHBITMAP(HBITMAP hBitmap)
    {
        return  XImage_LoadFileFromHBITMAP(hBitmap);
    }
    BOOL IsStretch(HIMAGE hImage)
    {
        return  XImage_IsStretch(hImage);
    }
    BOOL IsAdaptive(HIMAGE hImage)
    {
        return  XImage_IsAdaptive(hImage);
    }
    BOOL IsTile(HIMAGE hImage)
    {
        return  XImage_IsTile(hImage);
    }
    BOOL SetDrawType(HIMAGE hImage, image_draw_type_ nType)
    {
        return  XImage_SetDrawType(hImage, nType);
    }
    BOOL SetDrawTypeAdaptive(HIMAGE hImage, int leftSize, int topSize, int rightSize, int bottomSize)
    {
        return  XImage_SetDrawTypeAdaptive(hImage, leftSize, topSize, rightSize, bottomSize);
    }
    void SetTranColor(HIMAGE hImage, COLORREF color)
    {
        XImage_SetTranColor(hImage, color);
    }
    void SetTranColorEx(HIMAGE hImage, COLORREF color, BYTE tranColor)
    {
        XImage_SetTranColorEx(hImage, color, tranColor);
    }
    float SetRotateAngle(HIMAGE hImage, float fAngle)
    {
        return  XImage_SetRotateAngle(hImage, fAngle);
    }
    void EnableTranColor(HIMAGE hImage, BOOL bEnable)
    {
        XImage_EnableTranColor(hImage, bEnable);
    }
    void EnableAutoDestroy(HIMAGE hImage, BOOL bEnable)
    {
        XImage_EnableAutoDestroy(hImage, bEnable);
    }
    void EnableCenter(HIMAGE hImage, BOOL bCenter)
    {
        XImage_EnableCenter(hImage, bCenter);
    }
    BOOL IsCenter(HIMAGE hImage)
    {
        return  XImage_IsCenter(hImage);
    }
    image_draw_type_ GetDrawType(HIMAGE hImage)
    {
        return  XImage_GetDrawType(hImage);
    }
    int GetWidth(HIMAGE hImage)
    {
        return  XImage_GetWidth(hImage);
    }
    int GetHeight(HIMAGE hImage)
    {
        return  XImage_GetHeight(hImage);
    }
    void AddRef(HIMAGE hImage)
    {
        XImage_AddRef(hImage);
    }
    void Release(HIMAGE hImage)
    {
        XImage_Release(hImage);
    }
    int GetRefCount(HIMAGE hImage)
    {
        return  XImage_GetRefCount(hImage);
    }
    void Destroy(HIMAGE hImage)
    {
        XImage_Destroy(hImage);
    }	
};


class XTemp
{
public:
	HTEMP LoadTemplate(XC_OBJECT_TYPE nType, const wchar_t *pFileName)
	{
		return  XTemp_Load(nType, pFileName);
	}
	HTEMP LoadTemplateFromString(XC_OBJECT_TYPE nType, const char *pStringXML)
	{
		return  XTemp_LoadFromString(nType, pStringXML);
	}
	void TemplateDestroy(HTEMP pInfo)
	{
		XTemp_Destroy(pInfo);
	}
private:
};



class XC
{
public:
	lua_State* InitLua()
	{
		return XC_InitLua();
	}
	BOOL RunLua(const char* lpszLuaFile)
	{
		return XC_RunLua(lpszLuaFile);
	}
	BOOL ExitLua()
	{
		return XC_ExitLua();
	}
	HXCGUI GetObjectByUID(int nUID)
	{
		return XC_GetObjectByUID(nUID);
	}
	HXCGUI GetObjectByUIDName(const wchar_t* pName)
	{
		return XC_GetObjectByUIDName(pName);
	}
	HIMAGE GetResImage(const wchar_t *pName)
	{
		return XRes_GetImage(pName);
	}
    int UnicodeToAnsi(const wchar_t *pIn, int inLen, char *pOut, int outLen)
    {
        return  XC_UnicodeToAnsi(pIn, inLen, pOut, outLen);
    }
    int AnsiToUnicode(const char *pIn, int inLen, wchar_t *pOut, int outLen)
    {
        return  XC_AnsiToUnicode(pIn, inLen, pOut, outLen);
    }
    void DebugToFileInfo(const char *pInfo)
    {
        XC_DebugToFileInfo(pInfo);
    }
    BOOL IsHELE(HXCGUI hEle)
    {
        return  XC_IsHELE(hEle);
    }
    BOOL IsHWINDOW(HXCGUI hWindow)
    {
        return  XC_IsHWINDOW(hWindow);
    }
    BOOL IsShape(HXCGUI hShape)
    {
        return  XC_IsShape(hShape);
    }
    HWINDOW hWindowFromHWnd(HWND hWnd)
    {
        return  XC_hWindowFromHWnd(hWnd);
    }
    BOOL RegisterWindowClassName(const wchar_t *pClassName)
    {
        return  XC_RegisterWindowClassName(pClassName);
    }
    void SetPaintFrequency(int nMilliseconds)
    {
        XC_SetPaintFrequency(nMilliseconds);
    }
    BOOL RectInRect(RECT *pRect1, RECT *pRect2)
    {
        return  XC_RectInRect(pRect1, pRect2);
    }
    void CombineRect(RECT *pDest, RECT *pSrc1, RECT *pSrc2)
    {
        XC_CombineRect(pDest, pSrc1, pSrc2);
    }
    void ShowLayoutFrame(BOOL bShow)
    {
        XC_ShowLayoutFrame(bShow);
    }
    void EnableDebugFile(BOOL bEnable)
    {
        XC_EnableDebugFile(bEnable);
    }
    void SetLayoutFrameColor(COLORREF color)
    {
        XC_SetLayoutFrameColor(color);
    }
    void EnableErrorMessageBox(BOOL bEnabel)
    {
        XC_EnableErrorMessageBox(bEnabel);
    }
    HXCGUI LoadLayout(const wchar_t *pFileName, HXCGUI hParent = NULL)
    {
        return  XC_LoadLayout(pFileName, hParent);
    }
    HXCGUI LoadLayoutFromString(const char *pStringXML, HXCGUI hParent = NULL)
    {
        return  XC_LoadLayoutFromString(pStringXML, hParent);
    }
    BOOL LoadResource(const wchar_t *pFileName, const wchar_t *pResFolder = NULL)
    {
        return  XC_LoadResource(pFileName, pResFolder);
    }
    BOOL LoadResourceFromString(const char *pStringXML, const wchar_t *pResFolder = NULL)
    {
        return  XC_LoadResourceFromString(pStringXML, pResFolder);
    }
    void GetTextSize(const wchar_t *pString, int length, HFONTX hFontX, out_ SIZE *pOutSize)
    {
        XC_GetTextSize(pString, length, hFontX, pOutSize);
    }
    void GetTextShowSize(const wchar_t *pString, int length, HFONTX hFontX, out_ SIZE *pOutSize)
    {
        XC_GetTextShowSize(pString, length, hFontX, pOutSize);
    }
    HFONTX GetDefaultFont()
    {
        return  XC_GetDefaultFont();
    }
    void SetDefaultFont(HFONTX hFontX)
    {
        XC_SetDefaultFont(hFontX);
    }
    void InitFont(LOGFONTW *pFont, wchar_t *pName, int size, BOOL bBold = FALSE, BOOL bItalic = FALSE, BOOL bUnderline = FALSE, BOOL bStrikeOut = FALSE)
    {
        XC_InitFont(pFont, pName, size, bBold, bItalic, bUnderline, bStrikeOut);
    }
    void *Malloc(int size)
    {
        return  XC_Malloc(size);
    }
    void Free(void *p)
    {
        XC_Free(p);
    }
	void SetTextRenderingHint(int  nType)
	{
		XC_SetTextRenderingHint(nType);
	}
	BOOL SetProperty(HXCGUI hXCGUI, const wchar_t* pName, const wchar_t* pValue)
	{
		return XC_SetProperty(hXCGUI,pName,pValue);
	}
	const wchar_t*  GetProperty(HXCGUI hXCGUI, const wchar_t* pName)
	{
		return XC_GetProperty(hXCGUI,pName);
	}
	HIMAGE GetResImageEx(const wchar_t *pFileName,const wchar_t *pName)
	{
		return XRes_GetImageEx(pFileName,pName);
	}
	COLORREF GetResColor(const wchar_t *pName)
	{
		return XRes_GetColor(pName);
	}
	HFONTX GetResFont(const wchar_t *pName)
	{
		return XRes_GetFont(pName);
	}
	HBKM XRes_GetResBkM(const wchar_t *pName)
	{
		return XRes_GetResBkM(pName);
	}
	BOOL LoadStyle(const wchar_t *pFileName,const wchar_t *pDir=NULL)
	{
		return XC_LoadStyle(pFileName,pDir);
	}
	XC_OBJECT_TYPE XObj_GetType(HXCGUI hXCGUI)
	{
		return XObj_GetType(hXCGUI);
	}
	XC_OBJECT_TYPE_EX XObj_GetTypeEx(HXCGUI hXCGUI)
	{
		return XObj_GetTypeEx(hXCGUI);
	}

	void XUI_SetStyle(HXCGUI hXCGUI, XC_OBJECT_STYLE nStyle)
	{
		XUI_SetStyle(hXCGUI,nStyle);
	}
	XC_OBJECT_STYLE XUI_GetStyle(HXCGUI hXCGUI)
	{
		return XUI_GetStyle(hXCGUI);
	}

};

class XDraw
{
public:
	
	HDRAW hDraw;
	
    HDRAW Create(HDC hdc)
    {
        return  XDraw_Create(hdc);
    }
    void Destroy()
    {
        XDraw_Destroy(hDraw);
    }
    void SetOffset(int x, int y)
    {
        XDraw_SetOffset(hDraw, x, y);
    }
    void GetOffset(out_ int *pX, out_ int *pY)
    {
        XDraw_GetOffset(hDraw, pX, pY);
    }
    void RestoreGDIOBJ()
    {
        XDraw_RestoreGDIOBJ(hDraw);
    }
    HDC GetHDC()
    {
        return  XDraw_GetHDC(hDraw);
    }
    void SetBrushColor(COLORREF color, BYTE alpha = 255)
    {
        XDraw_SetBrushColor(hDraw, color, alpha);
    }
    void SetTextAlign(int nFlag)
    {
        XDraw_SetTextAlign(hDraw, nFlag);
    }
    void SetTextVertical(BOOL bVertical)
    {
        XDraw_SetTextVertical(hDraw, bVertical);
    }
    void SetFontX(HFONTX hFontx)
    {
        XDraw_SetFontX(hDraw, hFontx);
    }
    void SetLineWidth(int nWidth)
    {
        XDraw_SetLineWidth(hDraw, nWidth);
    }
    int SetBkMode(BOOL bTransparent)
    {
        return  XDraw_SetBkMode(hDraw, bTransparent);
    }
    void EnableSmoothingMode(BOOL bEnable)
    {
        XDraw_EnableSmoothingMode(hDraw, bEnable);
    }
    HBRUSH CreateSolidBrush(COLORREF crColor)
    {
        return  XDraw_CreateSolidBrush(hDraw, crColor);
    }
    HPEN CreatePen(int fnPenStyle, int nWidth, COLORREF crColor)
    {
        return  XDraw_CreatePen(hDraw, fnPenStyle, nWidth, crColor);
    }
    HRGN CreateRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
    {
        return  XDraw_CreateRectRgn(hDraw, nLeftRect, nTopRect, nRightRect, nBottomRect);
    }
    HRGN CreateRoundRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse)
    {
        return  XDraw_CreateRoundRectRgn(hDraw, nLeftRect, nTopRect, nRightRect, nBottomRect, nWidthEllipse, nHeightEllipse);
    }
    HRGN CreatePolygonRgn(POINT *pPt, int cPoints, int fnPolyFillMode)
    {
        return  XDraw_CreatePolygonRgn(hDraw, pPt, cPoints, fnPolyFillMode);
    }
    int SelectClipRgn(HRGN hRgn)
    {
        return  XDraw_SelectClipRgn(hDraw, hRgn);
    }
    void FillRect(RECT *pRect)
    {
        XDraw_FillRect(hDraw, pRect);
    }
    void FillRectColor(RECT *pRect, COLORREF color, BYTE alpha = 255)
    {
        XDraw_FillRectColor(hDraw, pRect, color, alpha);
    }
    BOOL FillRgn(HRGN hrgn, HBRUSH hbr)
    {
        return  XDraw_FillRgn(hDraw, hrgn, hbr);
    }
    void FillEllipse(RECT *pRect)
    {
        XDraw_FillEllipse(hDraw, pRect);
    }
    void DrawEllipse(RECT *pRect)
    {
        XDraw_DrawEllipse(hDraw, pRect);
    }
    void FillRoundRect(RECT *pRect, int nWidth, int nHeight)
    {
        XDraw_FillRoundRect(hDraw, pRect, nWidth, nHeight);
    }
    void DrawRoundRect(RECT *pRect, int nWidth, int nHeight)
    {
        XDraw_DrawRoundRect(hDraw, pRect, nWidth, nHeight);
    }
    BOOL Rectangle(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
    {
        return  XDraw_Rectangle(hDraw, nLeftRect, nTopRect, nRightRect, nBottomRect);
    }
    void DrawGroupBox_Rect(RECT *pRect, const wchar_t *pName, COLORREF textColor, BYTE textAlpha, POINT *pOffset)
    {
        XDraw_DrawGroupBox_Rect(hDraw, pRect, pName, textColor, textAlpha, pOffset);
    }
    void DrawGroupBox_RoundRect(RECT *pRect, const wchar_t *pName, COLORREF textColor, BYTE textAlpha, POINT *pOffset, int nWidth, int nHeight)
    {
        XDraw_DrawGroupBox_RoundRect(hDraw, pRect, pName, textColor, textAlpha, pOffset, nWidth, nHeight);
    }
    void GradientFill2(COLORREF color1, BYTE alpha1, COLORREF color2, BYTE alpha2, RECT *pRect, int mode)
    {
        XDraw_GradientFill2(hDraw, color1, alpha1, color2, alpha2, pRect, mode);
    }
    BOOL GradientFill4(COLORREF color1, COLORREF color2, COLORREF color3, COLORREF color4, RECT *pRect, int mode)
    {
        return  XDraw_GradientFill4(hDraw, color1, color2, color3, color4, pRect, mode);
    }
    BOOL FrameRgn(HRGN hrgn, HBRUSH hbr, int nWidth, int nHeight)
    {
        return  XDraw_FrameRgn(hDraw, hrgn, hbr, nWidth, nHeight);
    }
    void FrameRect(RECT *pRect)
    {
        XDraw_FrameRect(hDraw, pRect);
    }
    void FocusRect(RECT *pRect)
    {
        XDraw_FocusRect(hDraw, pRect);
    }
    void DrawLine(int x1, int y1, int x2, int y2)
    {
        XDraw_DrawLine(hDraw, x1, y1, x2, y2);
    }
    BOOL MoveToEx(int X, int Y, LPPOINT lpPoint =  NULL)
    {
        return  XDraw_MoveToEx(hDraw, X, Y, lpPoint);
    }
    BOOL LineTo(int nXEnd, int nYEnd)
    {
        return  XDraw_LineTo(hDraw, nXEnd, nYEnd);
    }
    BOOL Polyline(in_ POINT *pArrayPt, int arrayPtSize)
    {
        return  XDraw_Polyline(hDraw, pArrayPt, arrayPtSize);
    }
    void Dottedline(int x1, int y1, int x2, int y2)
    {
        XDraw_Dottedline(hDraw, x1, y1, x2, y2);
    }
    COLORREF SetPixel(int X, int Y, COLORREF crColor)
    {
        return  XDraw_SetPixel(hDraw, X, Y, crColor);
    }
    void Check(int x, int y, COLORREF color, BOOL bCheck)
    {
        XDraw_Check(hDraw, x, y, color, bCheck);
    }
    BOOL DrawIconEx(int xLeft, int yTop, HICON hIcon, int cxWidth, int cyWidth, UINT istepIfAniCur, HBRUSH hbrFlickerFreeDraw, UINT diFlags)
    {
        return  XDraw_DrawIconEx(hDraw, xLeft, yTop, hIcon, cxWidth, cyWidth, istepIfAniCur, hbrFlickerFreeDraw, diFlags);
    }
    BOOL BitBlt(int nXDest, int nYDest, int nWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop)
    {
        return  XDraw_BitBlt(hDraw, nXDest, nYDest, nWidth, nHeight, hdcSrc, nXSrc, nYSrc, dwRop);
    }
    BOOL BitBlt2(int nXDest, int nYDest, int nWidth, int nHeight, HDRAW hDrawSrc, int nXSrc, int nYSrc, DWORD dwRop)
    {
        return  XDraw_BitBlt2(hDraw, nXDest, nYDest, nWidth, nHeight, hDrawSrc, nXSrc, nYSrc, dwRop);
    }
    BOOL AlphaBlend(int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, int alpha)
    {
        return  XDraw_AlphaBlend(hDraw, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, alpha);
    }
    void TriangularArrow(int align, int x, int y, int width, int height)
    {
        XDraw_TriangularArrow(hDraw, align, x, y, width, height);
    }
    void DrawPolygon(in_ POINT *points, int nCount)
    {
        XDraw_DrawPolygon(hDraw, points, nCount);
    }
    void DrawPolygonF(in_ POINTF *points, int nCount)
    {
        XDraw_DrawPolygonF(hDraw, points, nCount);
    }
    void FillPolygon(in_ POINT *points, int nCount)
    {
        XDraw_FillPolygon(hDraw, points, nCount);
    }
    void FillPolygonF(in_ POINTF *points, int nCount)
    {
        XDraw_FillPolygonF(hDraw, points, nCount);
    }
    void Image(HIMAGE hImage, int x, int y)
    {
        XDraw_Image(hDraw, hImage, x, y);
    }
    void Image2(HIMAGE hImage, int x, int y, int width, int height)
    {
        XDraw_Image2(hDraw, hImage, x, y, width, height);
    }
    void ImageStretch(HIMAGE hImage, int x, int y, int width, int height)
    {
        XDraw_ImageStretch(hDraw, hImage, x, y, width, height);
    }
    void ImageAdaptive(HIMAGE hImage, RECT *pRect, BOOL bOnlyBorder = FALSE)
    {
        XDraw_ImageAdaptive(hDraw, hImage, pRect, bOnlyBorder);
    }
    void ImageExTile(HIMAGE hImage, RECT *pRect, int flag =  0)
    {
        XDraw_ImageExTile(hDraw, hImage, pRect, flag);
    }
    void ImageSuper(HIMAGE hImage, RECT *pRect, BOOL bClip = FALSE)
    {
        XDraw_ImageSuper(hDraw, hImage, pRect, bClip);
    }
    void ImageSuper2(HIMAGE hImage, RECT *pRcDest, RECT *pSrcRect)
    {
        XDraw_ImageSuper2(hDraw, hImage, pRcDest, pSrcRect);
    }
    void DrawText(const wchar_t *lpString, int nCount, RECT *lpRect)
    {
        XDraw_DrawText(hDraw, lpString, nCount, lpRect);
    }
    void DrawTextUnderline(const wchar_t *lpString, int nCount, RECT *lpRect, COLORREF colorLine, BYTE alphaLine = 255)
    {
        XDraw_DrawTextUnderline(hDraw, lpString, nCount, lpRect, colorLine, alphaLine);
    }
    void TextOut(int nXStart, int nYStart, const wchar_t *lpString, int cbString)
    {
        XDraw_TextOut(hDraw, nXStart, nYStart, lpString, cbString);
    }
    void TextOutEx(int nXStart, int nYStart, const wchar_t *lpString)
    {
        XDraw_TextOutEx(hDraw, nXStart, nYStart, lpString);
    }
    void TextOutA(int nXStart, int nYStart, const char *lpString)
    {
        XDraw_TextOutA(hDraw, nXStart, nYStart, lpString);
    }
    void SetAlpha(BYTE alpha)
    {
        XDraw_SetAlpha(hDraw, alpha);
    }
    void SetAlphaEx(HDC hdc,BYTE alpha)
    {
        XDraw_SetAlphaEx(hdc, alpha);
    }

	void SetClipRect(RECT* pRect)
	{
		XDraw_SetClipRect(hDraw,pRect);
	}
	void ClearClip()
	{
		XDraw_ClearClip(hDraw);
	}
	void FillRoundRectEx(RECT *pRect,int nLeftTop,int nRightTop, int nRightBottom, int nLeftBottom)
	{
		XDraw_FillRoundRectEx(hDraw,pRect,nLeftTop,nRightTop,nRightBottom,nLeftBottom);
	}
	void DrawRoundRectEx(RECT *pRect,int nLeftTop,int nRightTop, int nRightBottom, int nLeftBottom)
	{
		XDraw_DrawRoundRectEx(hDraw,pRect,nLeftTop,nRightTop,nRightBottom,nLeftBottom);
	}
};

class XFont
{
public:
	HFONTX hFontX;
    HFONTX Create(int size)
    {
        return  XFont_Create(size);
    }
    HFONTX Create2(const wchar_t *pName=L"宋体",int size=12, int style=xc_fontStyle_regular)
    {
        return  XFont_Create2(pName, size, style);
    }
    HFONTX Create3(const xc_font_info_i* pInfo)
    {
        return  XFont_Create3(pInfo);
    }
    HFONTX CreateEx(LOGFONTW *pFontInfo)
    {
        return  XFont_CreateEx(pFontInfo);
    }
    HFONTX CreateFromHFONT(HFONT hFont)
    {
        return  XFont_CreateFromHFONT(hFont);
    }
    HFONTX CreateFromFont(void* pFont)
    {
        return  XFont_CreateFromFont(pFont);
    }
	HFONTX CreateFromFile(const wchar_t* pFontFile,int size=12, int style=xc_fontStyle_regular)
	{
		return XFont_CreateFromFile(pFontFile,size,style);
	}
    void EnableAutoDestroy(BOOL bEnable)
    {
        XFont_EnableAutoDestroy(hFontX, bEnable);
    }
    void *GetFont()
    {
        return  XFont_GetFont(hFontX);
    }
    void GetFontInfo(out_ xc_font_info_i *pInfo)
    {
        XFont_GetFontInfo(hFontX, pInfo);
    }
    void AddRef()
    {
        XFont_AddRef(hFontX);
    }
    void Release()
    {
        XFont_Release(hFontX);
    }
    int GetRefCount()
    {
        return  XFont_GetRefCount(hFontX);
    }
    void Destroy()
    {
        XFont_Destroy(hFontX);
    }	
};

} // namespace xcgui

#endif // xcgui_class_h__