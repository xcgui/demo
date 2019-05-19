#include "sxcgui.h"


HELE WINAPI SXDateTime_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXDateTime_SetStyle(HWINDOW hWindow,HELE hEle,int nStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_SetStyle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nStyle);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXDateTime_GetStyle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_GetStyle);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXDateTime_EnableSplitSlash(HWINDOW hWindow,HELE hEle,BOOL bSlash)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_EnableSplitSlash);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bSlash);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDateTime_GetTime(HWINDOW hWindow,HELE hEle,int* pnHour,int* pnMinute,int* pnSecond)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_GetTime);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pnHour);
	XP_Set3(ct,pnMinute);
	XP_Set4(ct,pnSecond);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDateTime_SetTime(HWINDOW hWindow,HELE hEle,int nHour,int nMinute,int nSecond)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_SetTime);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nHour);
	XP_Set3(ct,nMinute);
	XP_Set4(ct,nSecond);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDateTime_GetDate(HWINDOW hWindow,HELE hEle,int* pnYear,int* pnMonth,int* pnDay)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_GetDate);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pnYear);
	XP_Set3(ct,pnMonth);
	XP_Set4(ct,pnDay);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDateTime_SetDate(HWINDOW hWindow,HELE hEle,int nYear,int nMonth,int nDay)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_SetDate);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nYear);
	XP_Set3(ct,nMonth);
	XP_Set4(ct,nDay);
	XP_CALL(hWindow,ct);
	
}

COLORREF WINAPI SXDateTime_GetSelBkColor(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_GetSelBkColor);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

void WINAPI SXDateTime_SetSelBkColor(HWINDOW hWindow,HELE hEle,COLORREF crSelectBk,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_SetSelBkColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,crSelectBk);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXDateTime_GetButton(HWINDOW hWindow,HELE hEle,int nType)
{
	XP_Init();
	XP_SetType(ct,ft_XDateTime_GetButton);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXMonthCal_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XMonthCal_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXMonthCal_SetToday(HWINDOW hWindow,HELE hEle,int nYear,int nMonth,int nDay)
{
	XP_Init();
	XP_SetType(ct,ft_XMonthCal_SetToday);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nYear);
	XP_Set3(ct,nMonth);
	XP_Set4(ct,nDay);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMonthCal_GetToday(HWINDOW hWindow,HELE hEle,int* pnYear,int* pnMonth,int* pnDay)
{
	XP_Init();
	XP_SetType(ct,ft_XMonthCal_GetToday);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pnYear);
	XP_Set3(ct,pnMonth);
	XP_Set4(ct,pnDay);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMonthCal_SeSelDate(HWINDOW hWindow,HELE hEle,int nYear,int nMonth,int nDay)
{
	XP_Init();
	XP_SetType(ct,ft_XMonthCal_SeSelDate);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nYear);
	XP_Set3(ct,nMonth);
	XP_Set4(ct,nDay);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMonthCal_GetSelDate(HWINDOW hWindow,HELE hEle,int* pnYear,int* pnMonth,int* pnDay)
{
	XP_Init();
	XP_SetType(ct,ft_XMonthCal_GetSelDate);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pnYear);
	XP_Set3(ct,pnMonth);
	XP_Set4(ct,pnDay);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXMonthCal_GetButton(HWINDOW hWindow,HELE hEle,monthCal_button_type_ nType)
{
	XP_Init();
	XP_SetType(ct,ft_XMonthCal_GetButton);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

lua_State* WINAPI SXC_InitLua(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XC_InitLua);
	XP_CALL(hWindow,ct);
	return (lua_State*)XP_GetRet(ct);
}

BOOL WINAPI SXC_RunLua(HWINDOW hWindow,const char* pLuaFile)
{
	XP_Init();
	XP_SetType(ct,ft_XC_RunLua);
	XP_Set1(ct,pLuaFile);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXC_ExitLua(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XC_ExitLua);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXC_UnicodeToAnsi(HWINDOW hWindow,const wchar_t * pIn,int inLen,char * pOut,int outLen)
{
	XP_Init();
	XP_SetType(ct,ft_XC_UnicodeToAnsi);
	XP_Set1(ct,pIn);
	XP_Set2(ct,inLen);
	XP_Set3(ct,pOut);
	XP_Set4(ct,outLen);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXC_AnsiToUnicode(HWINDOW hWindow,const char * pIn,int inLen,wchar_t * pOut,int outLen)
{
	XP_Init();
	XP_SetType(ct,ft_XC_AnsiToUnicode);
	XP_Set1(ct,pIn);
	XP_Set2(ct,inLen);
	XP_Set3(ct,pOut);
	XP_Set4(ct,outLen);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXC_DebugToFileInfo(HWINDOW hWindow,const char * pInfo)
{
	XP_Init();
	XP_SetType(ct,ft_XC_DebugToFileInfo);
	XP_Set1(ct,pInfo);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXC_IsHELE(HWINDOW hWindow,HXCGUI hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XC_IsHELE);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXC_IsHWINDOW(HWINDOW hWindow,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XC_IsHWINDOW);
	XP_Set1(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXC_IsShape(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XC_IsShape);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXC_IsHXCGUI(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_TYPE nType)
{
	XP_Init();
	XP_SetType(ct,ft_XC_IsHXCGUI);
	XP_Set1(ct,hXCGUI);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HWINDOW WINAPI SXC_hWindowFromHWnd(HWINDOW hWindow,HWND hWnd)
{
	XP_Init();
	XP_SetType(ct,ft_XC_hWindowFromHWnd);
	XP_Set1(ct,hWnd);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

BOOL WINAPI SXC_SetProperty(HWINDOW hWindow,HXCGUI hXCGUI,const wchar_t* pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XC_SetProperty);
	XP_Set1(ct,hXCGUI);
	XP_Set2(ct,pName);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

const wchar_t* WINAPI SXC_GetProperty(HWINDOW hWindow,HXCGUI hXCGUI,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetProperty);
	XP_Set1(ct,hXCGUI);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (const wchar_t*)XP_GetRet(ct);
}

BOOL WINAPI SXC_RegisterWindowClassName(HWINDOW hWindow,const wchar_t* pClassName)
{
	XP_Init();
	XP_SetType(ct,ft_XC_RegisterWindowClassName);
	XP_Set1(ct,pClassName);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXC_IsSViewExtend(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XC_IsSViewExtend);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

XC_OBJECT_TYPE WINAPI SXC_GetObjectType(HWINDOW hWindow,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetObjectType);
	XP_Set1(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_TYPE)XP_GetRet(ct);
}

HXCGUI WINAPI SXC_GetObjectByID(HWINDOW hWindow,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetObjectByID);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXC_GetObjectByIDName(HWINDOW hWindow,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetObjectByIDName);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXC_GetObjectByUID(HWINDOW hWindow,int nUID)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetObjectByUID);
	XP_Set1(ct,nUID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXC_GetObjectByUIDName(HWINDOW hWindow,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetObjectByUIDName);
	XP_Set1(ct,pName);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

int WINAPI SXRes_GetIDValue(HWINDOW hWindow,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XRes_GetIDValue);
	XP_Set1(ct,pName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HIMAGE WINAPI SXRes_GetImage(HWINDOW hWindow,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XRes_GetImage);
	XP_Set1(ct,pName);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXRes_GetImageEx(HWINDOW hWindow,const wchar_t * pFileName,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XRes_GetImageEx);
	XP_Set1(ct,pFileName);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

COLORREF WINAPI SXRes_GetColor(HWINDOW hWindow,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XRes_GetColor);
	XP_Set1(ct,pName);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

HFONTX WINAPI SXRes_GetFont(HWINDOW hWindow,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XRes_GetFont);
	XP_Set1(ct,pName);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

HBKM WINAPI SXRes_GetBkM(HWINDOW hWindow,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XRes_GetBkM);
	XP_Set1(ct,pName);
	XP_CALL(hWindow,ct);
	return (HBKM)XP_GetRet(ct);
}

void WINAPI SXC_SetPaintFrequency(HWINDOW hWindow,int nMilliseconds)
{
	XP_Init();
	XP_SetType(ct,ft_XC_SetPaintFrequency);
	XP_Set1(ct,nMilliseconds);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXC_SetTextRenderingHint(HWINDOW hWindow,int nType)
{
	XP_Init();
	XP_SetType(ct,ft_XC_SetTextRenderingHint);
	XP_Set1(ct,nType);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXC_RectInRect(HWINDOW hWindow,RECT * pRect1,RECT * pRect2)
{
	XP_Init();
	XP_SetType(ct,ft_XC_RectInRect);
	XP_Set1(ct,pRect1);
	XP_Set2(ct,pRect2);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXC_CombineRect(HWINDOW hWindow,RECT * pDest,RECT * pSrc1,RECT * pSrc2)
{
	XP_Init();
	XP_SetType(ct,ft_XC_CombineRect);
	XP_Set1(ct,pDest);
	XP_Set2(ct,pSrc1);
	XP_Set3(ct,pSrc2);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXC_ShowLayoutFrame(HWINDOW hWindow,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XC_ShowLayoutFrame);
	XP_Set1(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXC_EnableDebugFile(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XC_EnableDebugFile);
	XP_Set1(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXC_SetLayoutFrameColor(HWINDOW hWindow,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XC_SetLayoutFrameColor);
	XP_Set1(ct,color);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXC_EnableErrorMessageBox(HWINDOW hWindow,BOOL bEnabel)
{
	XP_Init();
	XP_SetType(ct,ft_XC_EnableErrorMessageBox);
	XP_Set1(ct,bEnabel);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXC_LoadLayout(HWINDOW hWindow,const wchar_t * pFileName,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XC_LoadLayout);
	XP_Set1(ct,pFileName);
	XP_Set2(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXC_LoadLayoutFromString(HWINDOW hWindow,const char * pStringXML,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XC_LoadLayoutFromString);
	XP_Set1(ct,pStringXML);
	XP_Set2(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

BOOL WINAPI SXC_LoadResource(HWINDOW hWindow,const wchar_t * pFileName,const wchar_t * pDir)
{
	XP_Init();
	XP_SetType(ct,ft_XC_LoadResource);
	XP_Set1(ct,pFileName);
	XP_Set2(ct,pDir);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXC_LoadResourceFromString(HWINDOW hWindow,const char * pStringXML,const wchar_t* pFileName,const wchar_t * pDir)
{
	XP_Init();
	XP_SetType(ct,ft_XC_LoadResourceFromString);
	XP_Set1(ct,pStringXML);
	XP_Set2(ct,pFileName);
	XP_Set3(ct,pDir);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXC_LoadStyle(HWINDOW hWindow,const wchar_t * pFileName,const wchar_t * pDir)
{
	XP_Init();
	XP_SetType(ct,ft_XC_LoadStyle);
	XP_Set1(ct,pFileName);
	XP_Set2(ct,pDir);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXC_GetTextSize(HWINDOW hWindow,const wchar_t* pString,int length,HFONTX hFontX,out_ SIZE* pOutSize)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetTextSize);
	XP_Set1(ct,pString);
	XP_Set2(ct,length);
	XP_Set3(ct,hFontX);
	XP_Set4(ct,pOutSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXC_GetTextShowSize(HWINDOW hWindow,const wchar_t* pString,int length,HFONTX hFontX,out_ SIZE* pOutSize)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetTextShowSize);
	XP_Set1(ct,pString);
	XP_Set2(ct,length);
	XP_Set3(ct,hFontX);
	XP_Set4(ct,pOutSize);
	XP_CALL(hWindow,ct);
	
}

HFONTX WINAPI SXC_GetDefaultFont(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XC_GetDefaultFont);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

void WINAPI SXC_SetDefaultFont(HWINDOW hWindow,HFONTX hFontX)
{
	XP_Init();
	XP_SetType(ct,ft_XC_SetDefaultFont);
	XP_Set1(ct,hFontX);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXC_InitFont(HWINDOW hWindow,LOGFONTW * pFont,wchar_t * pName,int size,BOOL bBold,BOOL bItalic,BOOL bUnderline,BOOL bStrikeOut)
{
	XP_Init();
	XP_SetType(ct,ft_XC_InitFont);
	XP_Set1(ct,pFont);
	XP_Set2(ct,pName);
	XP_Set3(ct,size);
	XP_Set4(ct,bBold);
	XP_Set5(ct,bItalic);
	XP_Set6(ct,bUnderline);
	XP_Set7(ct,bStrikeOut);
	XP_CALL(hWindow,ct);
	
}

void* WINAPI SXC_Malloc(HWINDOW hWindow,int size)
{
	XP_Init();
	XP_SetType(ct,ft_XC_Malloc);
	XP_Set1(ct,size);
	XP_CALL(hWindow,ct);
	return (void*)XP_GetRet(ct);
}

void WINAPI SXC_Free(HWINDOW hWindow,void * p)
{
	XP_Init();
	XP_SetType(ct,ft_XC_Free);
	XP_Set1(ct,p);
	XP_CALL(hWindow,ct);
	
}

void WINAPI S_XC_SetType(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_TYPE nType)
{
	XP_Init();
	XP_SetType(ct,ft__XC_SetType);
	XP_Set1(ct,hXCGUI);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	
}

void WINAPI S_XC_AddType(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_TYPE nType)
{
	XP_Init();
	XP_SetType(ct,ft__XC_AddType);
	XP_Set1(ct,hXCGUI);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	
}

void WINAPI S_XC_BindData(HWINDOW hWindow,HXCGUI hXCGUI,int data)
{
	XP_Init();
	XP_SetType(ct,ft__XC_BindData);
	XP_Set1(ct,hXCGUI);
	XP_Set2(ct,data);
	XP_CALL(hWindow,ct);
	
}

int WINAPI S_XC_GetBindData(HWINDOW hWindow,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft__XC_GetBindData);
	XP_Set1(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXInitXCGUI(HWINDOW hWindow,wchar_t * pText)
{
	XP_Init();
	XP_SetType(ct,ft_XInitXCGUI);
	XP_Set1(ct,pText);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXRunXCGUI(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XRunXCGUI);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXExitXCGUI(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XExitXCGUI);
	XP_CALL(hWindow,ct);
	
}

XC_OBJECT_TYPE WINAPI SXObj_GetType(HWINDOW hWindow,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XObj_GetType);
	XP_Set1(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_TYPE)XP_GetRet(ct);
}

XC_OBJECT_TYPE_EX WINAPI SXObj_GetTypeEx(HWINDOW hWindow,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XObj_GetTypeEx);
	XP_Set1(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_TYPE_EX)XP_GetRet(ct);
}

void WINAPI SXUI_SetStyle(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_STYLE nStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XUI_SetStyle);
	XP_Set1(ct,hXCGUI);
	XP_Set2(ct,nStyle);
	XP_CALL(hWindow,ct);
	
}

XC_OBJECT_STYLE WINAPI SXUI_GetStyle(HWINDOW hWindow,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XUI_GetStyle);
	XP_Set1(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_STYLE)XP_GetRet(ct);
}

HBKM WINAPI SXBkM_Create(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_Create);
	XP_CALL(hWindow,ct);
	return (HBKM)XP_GetRet(ct);
}

void WINAPI SXBkM_Destroy(HWINDOW hWindow,HBKM hBkInfoM)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_Destroy);
	XP_Set1(ct,hBkInfoM);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXBkM_SetBkInfo(HWINDOW hWindow,HBKM hBkInfoM,const wchar_t * pText)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_SetBkInfo);
	XP_Set1(ct,hBkInfoM);
	XP_Set2(ct,pText);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXBkM_AddInfo(HWINDOW hWindow,HBKM hBkInfoM,const wchar_t * pText)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_AddInfo);
	XP_Set1(ct,hBkInfoM);
	XP_Set2(ct,pText);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXBkM_AddBorder(HWINDOW hWindow,HBKM hBkInfoM,int nState,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_AddBorder);
	XP_Set1(ct,hBkInfoM);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_Set5(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBkM_AddFill(HWINDOW hWindow,HBKM hBkInfoM,int nState,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_AddFill);
	XP_Set1(ct,hBkInfoM);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBkM_AddImage(HWINDOW hWindow,HBKM hBkInfoM,int nState,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_AddImage);
	XP_Set1(ct,hBkInfoM);
	XP_Set2(ct,nState);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXBkM_GetCount(HWINDOW hWindow,HBKM hBkInfoM)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_GetCount);
	XP_Set1(ct,hBkInfoM);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXBkM_Clear(HWINDOW hWindow,HBKM hBkInfoM)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_Clear);
	XP_Set1(ct,hBkInfoM);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXBkM_Draw(HWINDOW hWindow,HBKM hBkInfoM,int nState,HDRAW hDraw,RECT* pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_Draw);
	XP_Set1(ct,hBkInfoM);
	XP_Set2(ct,nState);
	XP_Set3(ct,hDraw);
	XP_Set4(ct,pRect);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXBkM_DrawEx(HWINDOW hWindow,HBKM hBkInfoM,int nState,HDRAW hDraw,RECT* pRect,int nStateFilter)
{
	XP_Init();
	XP_SetType(ct,ft_XBkM_DrawEx);
	XP_Set1(ct,hBkInfoM);
	XP_Set2(ct,nState);
	XP_Set3(ct,hDraw);
	XP_Set4(ct,pRect);
	XP_Set5(ct,nStateFilter);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXBtn_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pName,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,pName);
	XP_Set6(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

BOOL WINAPI SXBtn_IsCheck(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_IsCheck);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXBtn_SetCheck(HWINDOW hWindow,HELE hEle,BOOL bCheck)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetCheck);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bCheck);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXBtn_SetState(HWINDOW hWindow,HELE hEle,common_state3_ nState)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetState);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_CALL(hWindow,ct);
	
}

common_state3_ WINAPI SXBtn_GetState(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetState);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (common_state3_)XP_GetRet(ct);
}

button_state_ WINAPI SXBtn_GetStateEx(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetStateEx);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (button_state_)XP_GetRet(ct);
}

void WINAPI SXBtn_SetStyle(HWINDOW hWindow,HELE hEle,XC_OBJECT_STYLE nStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetStyle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nStyle);
	XP_CALL(hWindow,ct);
	
}

XC_OBJECT_STYLE WINAPI SXBtn_GetStyle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetStyle);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_STYLE)XP_GetRet(ct);
}

void WINAPI SXBtn_SetType(HWINDOW hWindow,HELE hEle,XC_OBJECT_TYPE_EX nType)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetType);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_SetTypeEx(HWINDOW hWindow,HELE hEle,XC_OBJECT_TYPE_EX nType)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetTypeEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	
}

XC_OBJECT_TYPE_EX WINAPI SXBtn_GetType(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetType);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_TYPE_EX)XP_GetRet(ct);
}

void WINAPI SXBtn_SetGroupID(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetGroupID);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXBtn_GetGroupID(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetGroupID);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXBtn_SetBindEle(HWINDOW hWindow,HELE hEle,HELE hBindEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetBindEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hBindEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXBtn_GetBindEle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetBindEle);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXBtn_SetTextAlign(HWINDOW hWindow,HELE hEle,int nFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetTextAlign);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nFlags);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXBtn_GetTextAlign(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetTextAlign);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXBtn_SetIconAlign(HWINDOW hWindow,HELE hEle,button_icon_align_ align)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetIconAlign);
	XP_Set1(ct,hEle);
	XP_Set2(ct,align);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_SetOffset(HWINDOW hWindow,HELE hEle,int x,int y)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetOffset);
	XP_Set1(ct,hEle);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_SetOffsetIcon(HWINDOW hWindow,HELE hEle,int x,int y)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetOffsetIcon);
	XP_Set1(ct,hEle);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_SetIconSpace(HWINDOW hWindow,HELE hEle,int size)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetIconSpace);
	XP_Set1(ct,hEle);
	XP_Set2(ct,size);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_GetText(HWINDOW hWindow,HELE hEle,out_ wchar_t * pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetText);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pOut);
	XP_Set3(ct,nOutLen);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_SetText(HWINDOW hWindow,HELE hEle,in_ const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetText);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_SetIcon(HWINDOW hWindow,HELE hEle,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetIcon);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_SetIconDisable(HWINDOW hWindow,HELE hEle,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_SetIconDisable);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

HIMAGE WINAPI SXBtn_GetIcon(HWINDOW hWindow,HELE hEle,int nType)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetIcon);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

void WINAPI SXBtn_AddAnimationFrame(HWINDOW hWindow,HELE hEle,HIMAGE hImage,UINT uElapse)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_AddAnimationFrame);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_Set3(ct,uElapse);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_EnableAnimation(HWINDOW hWindow,HELE hEle,BOOL bEnable,BOOL bLoopPlay)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_EnableAnimation);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_Set3(ct,bLoopPlay);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_AddBkBorder(HWINDOW hWindow,HELE hEle,button_state_ nState,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_AddBkBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_Set5(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_AddBkFill(HWINDOW hWindow,HELE hEle,button_state_ nState,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_AddBkFill);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXBtn_AddBkImage(HWINDOW hWindow,HELE hEle,button_state_ nState,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_AddBkImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXBtn_GetBkInfoCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_GetBkInfoCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXBtn_ClearBkInfo(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XBtn_ClearBkInfo);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXComboBox_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

BOOL WINAPI SXComboBox_SetSelItem(HWINDOW hWindow,HELE hEle,int iIndex)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_SetSelItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iIndex);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXComboBox_GetButtonRect(HWINDOW hWindow,HELE hEle,out_ RECT* pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_GetButtonRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_SetButtonSize(HWINDOW hWindow,HELE hEle,int size)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_SetButtonSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,size);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_SetDropHeight(HWINDOW hWindow,HELE hEle,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_SetDropHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,height);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXComboBox_GetDropHeight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_GetDropHeight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXComboBox_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_BindAdapter);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXComboBox_GetApapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_GetApapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXComboBox_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_SetItemTemplateXML);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pXmlFile);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_SetItemTemplateXMLFromString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pStringXML);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_EnableDrawButton(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_EnableDrawButton);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_EnableEdit(HWINDOW hWindow,HELE hEle,BOOL bEdit)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_EnableEdit);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEdit);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_EnableDropHeightFixed(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_EnableDropHeightFixed);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_AddBkBorder(HWINDOW hWindow,HELE hEle,comboBox_state_ nState,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_AddBkBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_Set5(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_AddBkFill(HWINDOW hWindow,HELE hEle,comboBox_state_ nState,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_AddBkFill);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXComboBox_AddBkImage(HWINDOW hWindow,HELE hEle,comboBox_state_ nState,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_AddBkImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXComboboX_GetBkInfoCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XComboboX_GetBkInfoCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXComboBox_ClearBkInfo(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_ClearBkInfo);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXComboBox_GetSelItem(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_GetSelItem);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

comboBox_state_ WINAPI SXComboBox_GetState(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XComboBox_GetState);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (comboBox_state_)XP_GetRet(ct);
}

void WINAPI SXAd_Destroy(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAd_Destroy);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXAdListView_Create(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Create);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

int WINAPI SXAdListView_Group_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_AddColumn);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Group_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t * pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_AddItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Group_AddItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t * pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_AddItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Group_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_AddItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Group_AddItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_AddItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Group_SetText(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iColumn,const wchar_t * pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_SetText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Group_SetTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,const wchar_t * pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_SetTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,pName);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Group_SetImage(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iColumn,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_SetImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Group_SetImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_SetImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,pName);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXAdListView_Group_GetCount(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_GetCount);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Item_GetCount(HWINDOW hWindow,HXCGUI hAdapter,int iGroup)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_GetCount);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Item_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_AddColumn);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Item_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_AddItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Item_AddItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,const wchar_t * pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_AddItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,pName);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Item_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_AddItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdListView_Item_AddItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_AddItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,pName);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Item_SetText(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,int iColumn,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_SetText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,iColumn);
	XP_Set5(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Item_SetTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t * pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_SetTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,pName);
	XP_Set5(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Item_SetImage(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,int iColumn,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_SetImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,iColumn);
	XP_Set5(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Item_SetImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t * pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_SetImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,pName);
	XP_Set5(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdListView_Group_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int iGroup)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_DeleteItem);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXAdListView_Group_DeleteAllChildItem(HWINDOW hWindow,HXCGUI hAdapter,int iGroup)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Group_DeleteAllChildItem);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXAdListView_Item_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_DeleteItem);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXAdListView_DeleteAll(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_DeleteAll);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXAdListView_DeleteAllGroup(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_DeleteAllGroup);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXAdListView_DeleteAllItem(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_DeleteAllItem);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXAdListView_DeleteColumnGroup(HWINDOW hWindow,HXCGUI hAdapter,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_DeleteColumnGroup);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iColumn);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXAdListView_DeleteColumnItem(HWINDOW hWindow,HXCGUI hAdapter,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_DeleteColumnItem);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iColumn);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXAdListView_Item_GetTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_GetTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,pName);
	XP_Set5(ct,pOut);
	XP_Set6(ct,nOutLen);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HIMAGE WINAPI SXAdListView_Item_GetImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdListView_Item_GetImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,pName);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HXCGUI WINAPI SXAdTable_Create(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_Create);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXAdTable_Sort(HWINDOW hWindow,HXCGUI hAdapter,int iColumn,BOOL bAscending)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_Sort);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iColumn);
	XP_Set3(ct,bAscending);
	XP_CALL(hWindow,ct);
	
}

adapter_date_type_ WINAPI SXAdTable_GetItemDataType(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemDataType);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_CALL(hWindow,ct);
	return (adapter_date_type_)XP_GetRet(ct);
}

adapter_date_type_ WINAPI SXAdTable_GetItemDataTypeEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemDataTypeEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_CALL(hWindow,ct);
	return (adapter_date_type_)XP_GetRet(ct);
}

int WINAPI SXAdTable_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_AddColumn);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_SetColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pColName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetColumn);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pColName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_AddItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_AddItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_AddItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_AddItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_AddItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_AddItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_InsertItemText(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_InsertItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_InsertItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_InsertItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_InsertItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iItem,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_InsertItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_InsertItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_InsertItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemText(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemInt(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,int nValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemInt);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,nValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemIntEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,int nValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemIntEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,nValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemFloat(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,float nValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemFloat);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,nValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemFloatEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,float nValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemFloatEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,nValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_SetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_SetItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_DeleteItem);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_DeleteItemEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int nCount)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_DeleteItemEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,nCount);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXAdTable_DeleteItemAll(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_DeleteItemAll);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXAdTable_DeleteColumnAll(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_DeleteColumnAll);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXAdTable_GetCount(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetCount);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTable_GetCountColumn(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetCountColumn);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_GetItemText(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pOut);
	XP_Set5(ct,nOutLen);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_GetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,pOut);
	XP_Set5(ct,nOutLen);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HIMAGE WINAPI SXAdTable_GetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXAdTable_GetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_GetItemInt(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,out_ int* pOutValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemInt);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pOutValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_GetItemIntEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,out_ int* pOutValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemIntEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,pOutValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_GetItemFloat(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,out_ float* pOutValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemFloat);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pOutValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTable_GetItemFloatEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,out_ float* pOutValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTable_GetItemFloatEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pName);
	XP_Set4(ct,pOutValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HXCGUI WINAPI SXAdTree_Create(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_Create);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

int WINAPI SXAdTree_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_AddColumn);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTree_SetColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pColName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_SetColumn);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pColName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTree_InsertItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pValue,int nParentID,int insertID)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_InsertItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pValue);
	XP_Set3(ct,nParentID);
	XP_Set4(ct,insertID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTree_InsertItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue,int nParentID,int insertID)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_InsertItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,pValue);
	XP_Set4(ct,nParentID);
	XP_Set5(ct,insertID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTree_InsertItemImage(HWINDOW hWindow,HXCGUI hAdapter,HIMAGE hImage,int nParentID,int insertID)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_InsertItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,hImage);
	XP_Set3(ct,nParentID);
	XP_Set4(ct,insertID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTree_InsertItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage,int nParentID,int insertID)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_InsertItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,hImage);
	XP_Set4(ct,nParentID);
	XP_Set5(ct,insertID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTree_GetCount(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_GetCount);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXAdTree_GetCountColumn(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_GetCountColumn);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXAdTree_SetItemText(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_SetItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTree_SetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_SetItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,pName);
	XP_Set4(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTree_SetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_SetItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTree_SetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_SetItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,pName);
	XP_Set4(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdTree_GetItemText(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_GetItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pOut);
	XP_Set5(ct,nOutLen);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HIMAGE WINAPI SXAdTree_GetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_GetItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,iColumn);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

BOOL WINAPI SXAdTree_GetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_GetItemTextEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,pName);
	XP_Set4(ct,pOut);
	XP_Set5(ct,nOutLen);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HIMAGE WINAPI SXAdTree_GetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_GetItemImageEx);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_Set3(ct,pName);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

BOOL WINAPI SXAdTree_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_DeleteItem);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXAdTree_DeleteItemAll(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_DeleteItemAll);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXAdTree_DeleteColumnAll(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdTree_DeleteColumnAll);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXAdMap_Create(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_Create);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

BOOL WINAPI SXAdMap_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_AddItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdMap_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_AddItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdMap_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_DeleteItem);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXAdMap_GetCount(HWINDOW hWindow,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_GetCount);
	XP_Set1(ct,hAdapter);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXAdMap_GetItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_GetItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,pOut);
	XP_Set4(ct,nOutLen);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HIMAGE WINAPI SXAdMap_GetItemImage(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_GetItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

BOOL WINAPI SXAdMap_SetItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_SetItemText);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXAdMap_SetItemImage(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XAdMap_SetItemImage);
	XP_Set1(ct,hAdapter);
	XP_Set2(ct,pName);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HDRAW WINAPI SXDraw_Create(HWINDOW hWindow,HDC hdc)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Create);
	XP_Set1(ct,hdc);
	XP_CALL(hWindow,ct);
	return (HDRAW)XP_GetRet(ct);
}

void WINAPI SXDraw_Destroy(HWINDOW hWindow,HDRAW hDraw)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Destroy);
	XP_Set1(ct,hDraw);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_SetOffset(HWINDOW hWindow,HDRAW hDraw,int x,int y)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetOffset);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_GetOffset(HWINDOW hWindow,HDRAW hDraw,out_ int * pX,out_ int * pY)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_GetOffset);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pX);
	XP_Set3(ct,pY);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_RestoreGDIOBJ(HWINDOW hWindow,HDRAW hDraw)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_RestoreGDIOBJ);
	XP_Set1(ct,hDraw);
	XP_CALL(hWindow,ct);
	
}

HDC WINAPI SXDraw_GetHDC(HWINDOW hWindow,HDRAW hDraw)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_GetHDC);
	XP_Set1(ct,hDraw);
	XP_CALL(hWindow,ct);
	return (HDC)XP_GetRet(ct);
}

void WINAPI SXDraw_SetBrushColor(HWINDOW hWindow,HDRAW hDraw,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetBrushColor);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_SetTextAlign(HWINDOW hWindow,HDRAW hDraw,int nFlag)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetTextAlign);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nFlag);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_SetTextVertical(HWINDOW hWindow,HDRAW hDraw,BOOL bVertical)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetTextVertical);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,bVertical);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_SetFontX(HWINDOW hWindow,HDRAW hDraw,HFONTX hFontx)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetFontX);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hFontx);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_SetLineWidth(HWINDOW hWindow,HDRAW hDraw,int nWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetLineWidth);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nWidth);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXDraw_SetBkMode(HWINDOW hWindow,HDRAW hDraw,BOOL bTransparent)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetBkMode);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,bTransparent);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXDraw_SetClipRect(HWINDOW hWindow,HDRAW hDraw,RECT* pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetClipRect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_ClearClip(HWINDOW hWindow,HDRAW hDraw)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_ClearClip);
	XP_Set1(ct,hDraw);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_EnableSmoothingMode(HWINDOW hWindow,HDRAW hDraw,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_EnableSmoothingMode);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

HBRUSH WINAPI SXDraw_CreateSolidBrush(HWINDOW hWindow,HDRAW hDraw,COLORREF crColor)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_CreateSolidBrush);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,crColor);
	XP_CALL(hWindow,ct);
	return (HBRUSH)XP_GetRet(ct);
}

HPEN WINAPI SXDraw_CreatePen(HWINDOW hWindow,HDRAW hDraw,int fnPenStyle,int nWidth,COLORREF crColor)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_CreatePen);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,fnPenStyle);
	XP_Set3(ct,nWidth);
	XP_Set4(ct,crColor);
	XP_CALL(hWindow,ct);
	return (HPEN)XP_GetRet(ct);
}

HRGN WINAPI SXDraw_CreateRectRgn(HWINDOW hWindow,HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_CreateRectRgn);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nLeftRect);
	XP_Set3(ct,nTopRect);
	XP_Set4(ct,nRightRect);
	XP_Set5(ct,nBottomRect);
	XP_CALL(hWindow,ct);
	return (HRGN)XP_GetRet(ct);
}

HRGN WINAPI SXDraw_CreateRoundRectRgn(HWINDOW hWindow,HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect,int nWidthEllipse,int nHeightEllipse)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_CreateRoundRectRgn);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nLeftRect);
	XP_Set3(ct,nTopRect);
	XP_Set4(ct,nRightRect);
	XP_Set5(ct,nBottomRect);
	XP_Set6(ct,nWidthEllipse);
	XP_Set7(ct,nHeightEllipse);
	XP_CALL(hWindow,ct);
	return (HRGN)XP_GetRet(ct);
}

HRGN WINAPI SXDraw_CreatePolygonRgn(HWINDOW hWindow,HDRAW hDraw,POINT * pPt,int cPoints,int fnPolyFillMode)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_CreatePolygonRgn);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pPt);
	XP_Set3(ct,cPoints);
	XP_Set4(ct,fnPolyFillMode);
	XP_CALL(hWindow,ct);
	return (HRGN)XP_GetRet(ct);
}

int WINAPI SXDraw_SelectClipRgn(HWINDOW hWindow,HDRAW hDraw,HRGN hRgn)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SelectClipRgn);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hRgn);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXDraw_FillRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillRect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_FillRectColor(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillRectColor);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXDraw_FillRgn(HWINDOW hWindow,HDRAW hDraw,HRGN hrgn,HBRUSH hbr)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillRgn);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hrgn);
	XP_Set3(ct,hbr);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXDraw_FillEllipse(HWINDOW hWindow,HDRAW hDraw,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillEllipse);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawEllipse(HWINDOW hWindow,HDRAW hDraw,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawEllipse);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_FillRoundRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillRoundRect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_Set3(ct,nWidth);
	XP_Set4(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawRoundRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawRoundRect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_Set3(ct,nWidth);
	XP_Set4(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_FillRoundRectEx(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nLeftTop,int nRightTop,int nRightBottom,int nLeftBottom)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillRoundRectEx);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_Set3(ct,nLeftTop);
	XP_Set4(ct,nRightTop);
	XP_Set5(ct,nRightBottom);
	XP_Set6(ct,nLeftBottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawRoundRectEx(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nLeftTop,int nRightTop,int nRightBottom,int nLeftBottom)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawRoundRectEx);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_Set3(ct,nLeftTop);
	XP_Set4(ct,nRightTop);
	XP_Set5(ct,nRightBottom);
	XP_Set6(ct,nLeftBottom);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXDraw_Rectangle(HWINDOW hWindow,HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Rectangle);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nLeftRect);
	XP_Set3(ct,nTopRect);
	XP_Set4(ct,nRightRect);
	XP_Set5(ct,nBottomRect);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXDraw_DrawGroupBox_Rect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,const wchar_t* pName,COLORREF textColor,BYTE textAlpha,POINT* pOffset)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawGroupBox_Rect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_Set3(ct,pName);
	XP_Set4(ct,textColor);
	XP_Set5(ct,textAlpha);
	XP_Set6(ct,pOffset);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawGroupBox_RoundRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,const wchar_t* pName,COLORREF textColor,BYTE textAlpha,POINT* pOffset,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawGroupBox_RoundRect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_Set3(ct,pName);
	XP_Set4(ct,textColor);
	XP_Set5(ct,textAlpha);
	XP_Set6(ct,pOffset);
	XP_Set7(ct,nWidth);
	XP_Set8(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_GradientFill2(HWINDOW hWindow,HDRAW hDraw,COLORREF color1,BYTE alpha1,COLORREF color2,BYTE alpha2,RECT * pRect,int mode)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_GradientFill2);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,color1);
	XP_Set3(ct,alpha1);
	XP_Set4(ct,color2);
	XP_Set5(ct,alpha2);
	XP_Set6(ct,pRect);
	XP_Set7(ct,mode);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXDraw_GradientFill4(HWINDOW hWindow,HDRAW hDraw,COLORREF color1,COLORREF color2,COLORREF color3,COLORREF color4,RECT * pRect,int mode)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_GradientFill4);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,color1);
	XP_Set3(ct,color2);
	XP_Set4(ct,color3);
	XP_Set5(ct,color4);
	XP_Set6(ct,pRect);
	XP_Set7(ct,mode);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXDraw_FrameRgn(HWINDOW hWindow,HDRAW hDraw,HRGN hrgn,HBRUSH hbr,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FrameRgn);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hrgn);
	XP_Set3(ct,hbr);
	XP_Set4(ct,nWidth);
	XP_Set5(ct,nHeight);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXDraw_FrameRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FrameRect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_FocusRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FocusRect);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawLine(HWINDOW hWindow,HDRAW hDraw,int x1,int y1,int x2,int y2)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawLine);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,x1);
	XP_Set3(ct,y1);
	XP_Set4(ct,x2);
	XP_Set5(ct,y2);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXDraw_MoveToEx(HWINDOW hWindow,HDRAW hDraw,int X,int Y,LPPOINT lpPoint)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_MoveToEx);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,X);
	XP_Set3(ct,Y);
	XP_Set4(ct,lpPoint);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXDraw_LineTo(HWINDOW hWindow,HDRAW hDraw,int nXEnd,int nYEnd)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_LineTo);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nXEnd);
	XP_Set3(ct,nYEnd);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXDraw_Polyline(HWINDOW hWindow,HDRAW hDraw,in_ POINT * pArrayPt,int arrayPtSize)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Polyline);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,pArrayPt);
	XP_Set3(ct,arrayPtSize);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXDraw_Dottedline(HWINDOW hWindow,HDRAW hDraw,int x1,int y1,int x2,int y2)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Dottedline);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,x1);
	XP_Set3(ct,y1);
	XP_Set4(ct,x2);
	XP_Set5(ct,y2);
	XP_CALL(hWindow,ct);
	
}

COLORREF WINAPI SXDraw_SetPixel(HWINDOW hWindow,HDRAW hDraw,int X,int Y,COLORREF crColor)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetPixel);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,X);
	XP_Set3(ct,Y);
	XP_Set4(ct,crColor);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

void WINAPI SXDraw_Check(HWINDOW hWindow,HDRAW hDraw,int x,int y,COLORREF color,BOOL bCheck)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Check);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_Set4(ct,color);
	XP_Set5(ct,bCheck);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXDraw_DrawIconEx(HWINDOW hWindow,HDRAW hDraw,int xLeft,int yTop,HICON hIcon,int cxWidth,int cyWidth,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawIconEx);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,xLeft);
	XP_Set3(ct,yTop);
	XP_Set4(ct,hIcon);
	XP_Set5(ct,cxWidth);
	XP_Set6(ct,cyWidth);
	XP_Set7(ct,istepIfAniCur);
	XP_Set8(ct,hbrFlickerFreeDraw);
	XP_Set9(ct,diFlags);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXDraw_BitBlt(HWINDOW hWindow,HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDC hdcSrc,int nXSrc,int nYSrc,DWORD dwRop)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_BitBlt);
	XP_Set1(ct,hDrawDest);
	XP_Set2(ct,nXDest);
	XP_Set3(ct,nYDest);
	XP_Set4(ct,nWidth);
	XP_Set5(ct,nHeight);
	XP_Set6(ct,hdcSrc);
	XP_Set7(ct,nXSrc);
	XP_Set8(ct,nYSrc);
	XP_Set9(ct,dwRop);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXDraw_BitBlt2(HWINDOW hWindow,HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDRAW hDrawSrc,int nXSrc,int nYSrc,DWORD dwRop)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_BitBlt2);
	XP_Set1(ct,hDrawDest);
	XP_Set2(ct,nXDest);
	XP_Set3(ct,nYDest);
	XP_Set4(ct,nWidth);
	XP_Set5(ct,nHeight);
	XP_Set6(ct,hDrawSrc);
	XP_Set7(ct,nXSrc);
	XP_Set8(ct,nYSrc);
	XP_Set9(ct,dwRop);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXDraw_AlphaBlend(HWINDOW hWindow,HDRAW hDraw,int nXOriginDest,int nYOriginDest,int nWidthDest,int nHeightDest,HDC hdcSrc,int nXOriginSrc,int nYOriginSrc,int nWidthSrc,int nHeightSrc,int alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_AlphaBlend);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nXOriginDest);
	XP_Set3(ct,nYOriginDest);
	XP_Set4(ct,nWidthDest);
	XP_Set5(ct,nHeightDest);
	XP_Set6(ct,hdcSrc);
	XP_Set7(ct,nXOriginSrc);
	XP_Set8(ct,nYOriginSrc);
	XP_Set9(ct,nWidthSrc);
	XP_Set10(ct,nHeightSrc);
	XP_Set11(ct,alpha);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXDraw_TriangularArrow(HWINDOW hWindow,HDRAW hDraw,int align,int x,int y,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_TriangularArrow);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,align);
	XP_Set3(ct,x);
	XP_Set4(ct,y);
	XP_Set5(ct,width);
	XP_Set6(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawPolygon(HWINDOW hWindow,HDRAW hDraw,in_ POINT * points,int nCount)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawPolygon);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,points);
	XP_Set3(ct,nCount);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawPolygonF(HWINDOW hWindow,HDRAW hDraw,in_ POINTF * points,int nCount)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawPolygonF);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,points);
	XP_Set3(ct,nCount);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_FillPolygon(HWINDOW hWindow,HDRAW hDraw,in_ POINT * points,int nCount)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillPolygon);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,points);
	XP_Set3(ct,nCount);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_FillPolygonF(HWINDOW hWindow,HDRAW hDraw,in_ POINTF * points,int nCount)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_FillPolygonF);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,points);
	XP_Set3(ct,nCount);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_Image(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,int x,int y)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Image);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hImage);
	XP_Set3(ct,x);
	XP_Set4(ct,y);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_Image2(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_Image2);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hImage);
	XP_Set3(ct,x);
	XP_Set4(ct,y);
	XP_Set5(ct,width);
	XP_Set6(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_ImageStretch(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_ImageStretch);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hImage);
	XP_Set3(ct,x);
	XP_Set4(ct,y);
	XP_Set5(ct,width);
	XP_Set6(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_ImageAdaptive(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRect,BOOL bOnlyBorder)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_ImageAdaptive);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hImage);
	XP_Set3(ct,pRect);
	XP_Set4(ct,bOnlyBorder);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_ImageExTile(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRect,int flag)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_ImageExTile);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hImage);
	XP_Set3(ct,pRect);
	XP_Set4(ct,flag);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_ImageSuper(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRect,BOOL bClip)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_ImageSuper);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hImage);
	XP_Set3(ct,pRect);
	XP_Set4(ct,bClip);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_ImageSuper2(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRcDest,RECT * pSrcRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_ImageSuper2);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,hImage);
	XP_Set3(ct,pRcDest);
	XP_Set4(ct,pSrcRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawText(HWINDOW hWindow,HDRAW hDraw,const wchar_t * lpString,int nCount,RECT* lpRect)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawText);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,lpString);
	XP_Set3(ct,nCount);
	XP_Set4(ct,lpRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_DrawTextUnderline(HWINDOW hWindow,HDRAW hDraw,const wchar_t * lpString,int nCount,RECT* lpRect,COLORREF colorLine,BYTE alphaLine)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_DrawTextUnderline);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,lpString);
	XP_Set3(ct,nCount);
	XP_Set4(ct,lpRect);
	XP_Set5(ct,colorLine);
	XP_Set6(ct,alphaLine);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_TextOut(HWINDOW hWindow,HDRAW hDraw,int nXStart,int nYStart,const wchar_t * lpString,int cbString)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_TextOut);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nXStart);
	XP_Set3(ct,nYStart);
	XP_Set4(ct,lpString);
	XP_Set5(ct,cbString);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_TextOutEx(HWINDOW hWindow,HDRAW hDraw,int nXStart,int nYStart,const wchar_t * lpString)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_TextOutEx);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nXStart);
	XP_Set3(ct,nYStart);
	XP_Set4(ct,lpString);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_TextOutA(HWINDOW hWindow,HDRAW hDraw,int nXStart,int nYStart,const char * lpString)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_TextOutA);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,nXStart);
	XP_Set3(ct,nYStart);
	XP_Set4(ct,lpString);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_SetAlpha(HWINDOW hWindow,HDRAW hDraw,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetAlpha);
	XP_Set1(ct,hDraw);
	XP_Set2(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXDraw_SetAlphaEx(HWINDOW hWindow,HDC hdc,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XDraw_SetAlphaEx);
	XP_Set1(ct,hdc);
	XP_Set2(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXEle_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

BOOL WINAPI S_XEle_RegEvent(HWINDOW hWindow,HELE hEle,UINT nEvent,xc_event* pEvent)
{
	XP_Init();
	XP_SetType(ct,ft__XEle_RegEvent);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pEvent);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI S_XEle_RemoveEvent(HWINDOW hWindow,HELE hEle,UINT nEvent,xc_event* pEvent)
{
	XP_Init();
	XP_SetType(ct,ft__XEle_RemoveEvent);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pEvent);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_RegEventC(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RegEventC);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pFun);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_RegEventC1(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RegEventC1);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pFun);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_RegEventC2(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RegEventC2);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pFun);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_RemoveEventC(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RemoveEventC);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pFun);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXEle_SendEvent(HWINDOW hWindow,HELE hEle,HELE hEventEle,int nEvent,WPARAM wParam,LPARAM lParam)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SendEvent);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hEventEle);
	XP_Set3(ct,nEvent);
	XP_Set4(ct,wParam);
	XP_Set5(ct,lParam);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXEle_PostEvent(HWINDOW hWindow,HELE hEle,HELE hEventEle,int nEvent,WPARAM wParam,LPARAM lParam)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_PostEvent);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hEventEle);
	XP_Set3(ct,nEvent);
	XP_Set4(ct,wParam);
	XP_Set5(ct,lParam);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsShow(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsShow);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsEnable(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsEnable);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsEnableFocus(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsEnableFocus);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsDrawFocus(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsDrawFocus);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsEnableEvent_XE_PAINT_END(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsEnableEvent_XE_PAINT_END);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsMouseThrough(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsMouseThrough);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsBkTransparent(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsBkTransparent);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsKeyTab(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsKeyTab);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsSwitchFocus(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsSwitchFocus);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsEnable_XE_MOUSEWHEEL(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsEnable_XE_MOUSEWHEEL);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_IsInScrollView(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsInScrollView);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXEle_Enable(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_Enable);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableFocus(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableFocus);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableDrawFocus(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableDrawFocus);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableDrawBorder(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableDrawBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableEvent_XE_PAINT_END(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableEvent_XE_PAINT_END);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableBkTransparent(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableBkTransparent);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableMouseThrough(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableMouseThrough);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableKeyTab(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableKeyTab);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableSwitchFocus(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableSwitchFocus);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableEvent_XE_MOUSEWHEEL(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableEvent_XE_MOUSEWHEEL);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableInScrollView(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableInScrollView);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXEle_SetRect(HWINDOW hWindow,HELE hEle,RECT * pRect,BOOL bRedraw)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_Set3(ct,bRedraw);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_SetRectEx(HWINDOW hWindow,HELE hEle,int x,int y,int cx,int cy,BOOL bRedraw)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetRectEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_Set4(ct,cx);
	XP_Set5(ct,cy);
	XP_Set6(ct,bRedraw);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_SetRectLogic(HWINDOW hWindow,HELE hEle,RECT * pRect,BOOL bRedraw)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetRectLogic);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_Set3(ct,bRedraw);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXEle_GetRect(HWINDOW hWindow,HELE hEle,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetRectLogic(HWINDOW hWindow,HELE hEle,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetRectLogic);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetClientRect(HWINDOW hWindow,HELE hEle,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetClientRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetWndClientRect(HWINDOW hWindow,HELE hEle,out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetWndClientRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXEle_GetWidth(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetWidth);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXEle_GetHeight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetHeight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXEle_RectWndClientToEleClient(HWINDOW hWindow,HELE hEle,in_out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RectWndClientToEleClient);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_PointWndClientToEleClient(HWINDOW hWindow,HELE hEle,in_out_ POINT * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_PointWndClientToEleClient);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_RectClientToWndClient(HWINDOW hWindow,HELE hEle,in_out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RectClientToWndClient);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_PointClientToWndClient(HWINDOW hWindow,HELE hEle,in_out_ POINT * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_PointClientToWndClient);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXEle_AddEle(HWINDOW hWindow,HELE hEle,HELE hChildEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_AddEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hChildEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_InsertEle(HWINDOW hWindow,HELE hEle,HELE hChildEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_InsertEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hChildEle);
	XP_Set3(ct,index);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXEle_RemoveEle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RemoveEle);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXEle_AddShape(HWINDOW hWindow,HELE hEle,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_AddShape);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hShape);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_SetZOrder(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetZOrder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_SetZOrderEx(HWINDOW hWindow,HELE hEle,HELE hDestEle,zorder_ nType)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetZOrderEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hDestEle);
	XP_Set3(ct,nType);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXEle_GetZOrder(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetZOrder);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXEle_SetTopmost(HWINDOW hWindow,HELE hEle,BOOL bTopmost)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetTopmost);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bTopmost);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXEle_EnableCSS(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableCSS);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_SetCssName(HWINDOW hWindow,HELE hEle,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetCssName);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	
}

const wchar_t* WINAPI SXEle_GetCssName(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetCssName);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (const wchar_t*)XP_GetRet(ct);
}

void WINAPI SXEle_ShowEle(HWINDOW hWindow,HELE hEle,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_ShowEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

XC_OBJECT_TYPE WINAPI SXEle_GetType(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetType);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_TYPE)XP_GetRet(ct);
}

HWND WINAPI SXEle_GetHWND(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetHWND);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HWND)XP_GetRet(ct);
}

HWINDOW WINAPI SXEle_GetHWINDOW(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetHWINDOW);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

void WINAPI SXEle_SetCursor(HWINDOW hWindow,HELE hEle,HCURSOR hCursor)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetCursor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hCursor);
	XP_CALL(hWindow,ct);
	
}

HCURSOR WINAPI SXEle_GetCursor(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetCursor);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HCURSOR)XP_GetRet(ct);
}

void WINAPI SXEle_SetID(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetID);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXEle_GetID(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetID);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXEle_SetUID(HWINDOW hWindow,HELE hEle,int nUID)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetUID);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nUID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXEle_GetUID(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetUID);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HELE WINAPI SXEle_GetParentEle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetParentEle);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HXCGUI WINAPI SXEle_GetParent(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetParent);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXEle_SetTextColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetTextColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

COLORREF WINAPI SXEle_GetTextColor(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetTextColor);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

void WINAPI SXEle_SetFocusBorderColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetFocusBorderColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

COLORREF WINAPI SXEle_GetFocusBorderColor(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetFocusBorderColor);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

void WINAPI SXEle_SetFont(HWINDOW hWindow,HELE hEle,HFONTX hFontx)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetFont);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hFontx);
	XP_CALL(hWindow,ct);
	
}

HFONTX WINAPI SXEle_GetFont(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetFont);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

void WINAPI SXEle_SetAlpha(HWINDOW hWindow,HELE hEle,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetAlpha);
	XP_Set1(ct,hEle);
	XP_Set2(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXEle_GetChildCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetChildCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HELE WINAPI SXEle_GetChildByIndex(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetChildByIndex);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXEle_GetChildByID(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetChildByID);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXEle_GetChildShapeCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetChildShapeCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HXCGUI WINAPI SXEle_GetChildShapeByIndex(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetChildShapeByIndex);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXEle_SetBorderSize(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetBorderSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,left);
	XP_Set3(ct,top);
	XP_Set4(ct,right);
	XP_Set5(ct,bottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetBorderSize(HWINDOW hWindow,HELE hEle,BorderSize_i* pBorder)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetBorderSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pBorder);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_SetPadding(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetPadding);
	XP_Set1(ct,hEle);
	XP_Set2(ct,left);
	XP_Set3(ct,top);
	XP_Set4(ct,right);
	XP_Set5(ct,bottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetPadding(HWINDOW hWindow,HELE hEle,PaddingSize_i* pPadding)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetPadding);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPadding);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXEle_HitChildEle(HWINDOW hWindow,HELE hEle,in_ POINT  * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_HitChildEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXEle_BindLayoutObject(HWINDOW hWindow,HELE hEle,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_BindLayoutObject);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hLayout);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXEle_GetLayoutObject(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetLayoutObject);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXEle_GetParentLayoutObject(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetParentLayoutObject);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXEle_SetUserData(HWINDOW hWindow,HELE hEle,int nData)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetUserData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nData);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXEle_GetUserData(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetUserData);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXEle_GetContentSize(HWINDOW hWindow,HELE hEle,out_ SIZE* pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetContentSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_SetCapture(HWINDOW hWindow,HELE hEle,BOOL b)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetCapture);
	XP_Set1(ct,hEle);
	XP_Set2(ct,b);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_SetLayoutWidth(HWINDOW hWindow,HELE hEle,layout_size_type_ nType,int nWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetLayoutWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nType);
	XP_Set3(ct,nWidth);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_SetLayoutHeight(HWINDOW hWindow,HELE hEle,layout_size_type_ nType,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetLayoutHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nType);
	XP_Set3(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetLayoutWidth(HWINDOW hWindow,HELE hEle,out_ layout_size_type_ * pType,out_ int * pWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetLayoutWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pType);
	XP_Set3(ct,pWidth);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetLayoutHeight(HWINDOW hWindow,HELE hEle,out_ layout_size_type_ * pType,out_ int * pHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetLayoutHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pType);
	XP_Set3(ct,pHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_RedrawEle(HWINDOW hWindow,HELE hEle,BOOL bImmediate)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RedrawEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bImmediate);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_RedrawRect(HWINDOW hWindow,HELE hEle,RECT * pRect,BOOL bImmediate)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RedrawRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_Set3(ct,bImmediate);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_Destroy(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_Destroy);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_AddBkBorder(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_AddBkBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_Set4(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_AddBkFill(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_AddBkFill);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_AddBkImage(HWINDOW hWindow,HELE hEle,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_AddBkImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXEle_GetBkInfoCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetBkInfoCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXEle_ClearBkInfo(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_ClearBkInfo);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

HBKM WINAPI SXEle_GetBkManager(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetBkManager);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HBKM)XP_GetRet(ct);
}

int WINAPI SXEle_GetStateFlags(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetStateFlags);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXEle_DrawFocus(HWINDOW hWindow,HELE hEle,HDRAW hDraw,RECT* pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_DrawFocus);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hDraw);
	XP_Set3(ct,pRect);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXEle_DrawEle(HWINDOW hWindow,HELE hEle,HDRAW hDraw)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_DrawEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hDraw);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_EnableTransparentChannel(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_EnableTransparentChannel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXEle_SetXCTimer(HWINDOW hWindow,HELE hEle,UINT nIDEvent,UINT uElapse)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetXCTimer);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nIDEvent);
	XP_Set3(ct,uElapse);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXEle_KillXCTimer(HWINDOW hWindow,HELE hEle,UINT nIDEvent)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_KillXCTimer);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nIDEvent);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXEle_SetToolTip(HWINDOW hWindow,HELE hEle,const wchar_t* pText)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_SetToolTip);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pText);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_GetToolTip(HWINDOW hWindow,HELE hEle,out_ wchar_t  * pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_GetToolTip);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pOut);
	XP_Set3(ct,nOutLen);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_PopupToolTip(HWINDOW hWindow,HELE hEle,int x,int y)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_PopupToolTip);
	XP_Set1(ct,hEle);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_AdjustLayoutObject(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_AdjustLayoutObject);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXEle_AdjustLayout(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_AdjustLayout);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXEle_RegEventTest(HWINDOW hWindow,int nEvent,BYTE* pParamType)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_RegEventTest);
	XP_Set1(ct,nEvent);
	XP_Set2(ct,pParamType);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HFONTX WINAPI SXFont_Create(HWINDOW hWindow,int size)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_Create);
	XP_Set1(ct,size);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

HFONTX WINAPI SXFont_Create2(HWINDOW hWindow,const wchar_t * pName,int size,int style)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_Create2);
	XP_Set1(ct,pName);
	XP_Set2(ct,size);
	XP_Set3(ct,style);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

HFONTX WINAPI SXFont_Create3(HWINDOW hWindow,const xc_font_info_i* pInfo)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_Create3);
	XP_Set1(ct,pInfo);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

HFONTX WINAPI SXFont_CreateEx(HWINDOW hWindow,LOGFONTW * pFontInfo)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_CreateEx);
	XP_Set1(ct,pFontInfo);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

HFONTX WINAPI SXFont_CreateFromHFONT(HWINDOW hWindow,HFONT hFont)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_CreateFromHFONT);
	XP_Set1(ct,hFont);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

HFONTX WINAPI SXFont_CreateFromFont(HWINDOW hWindow,void* pFont)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_CreateFromFont);
	XP_Set1(ct,pFont);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

HFONTX WINAPI SXFont_CreateFromFile(HWINDOW hWindow,const wchar_t* pFontFile,int size,int style)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_CreateFromFile);
	XP_Set1(ct,pFontFile);
	XP_Set2(ct,size);
	XP_Set3(ct,style);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

void WINAPI SXFont_EnableAutoDestroy(HWINDOW hWindow,HFONTX hFontX,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_EnableAutoDestroy);
	XP_Set1(ct,hFontX);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void* WINAPI SXFont_GetFont(HWINDOW hWindow,HFONTX hFontX)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_GetFont);
	XP_Set1(ct,hFontX);
	XP_CALL(hWindow,ct);
	return (void*)XP_GetRet(ct);
}

void WINAPI SXFont_GetFontInfo(HWINDOW hWindow,HFONTX hFontX,out_ xc_font_info_i* pInfo)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_GetFontInfo);
	XP_Set1(ct,hFontX);
	XP_Set2(ct,pInfo);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXFont_AddRef(HWINDOW hWindow,HFONTX hFontX)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_AddRef);
	XP_Set1(ct,hFontX);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXFont_Release(HWINDOW hWindow,HFONTX hFontX)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_Release);
	XP_Set1(ct,hFontX);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXFont_GetRefCount(HWINDOW hWindow,HFONTX hFontX)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_GetRefCount);
	XP_Set1(ct,hFontX);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXFont_Destroy(HWINDOW hWindow,HFONTX hFontX)
{
	XP_Init();
	XP_SetType(ct,ft_XFont_Destroy);
	XP_Set1(ct,hFontX);
	XP_CALL(hWindow,ct);
	
}

HWINDOW WINAPI SXFrameWnd_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pTitle,HWND hWndParent,int XCStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,pTitle);
	XP_Set6(ct,hWndParent);
	XP_Set7(ct,XCStyle);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

HWINDOW WINAPI SXFrameWnd_CreateEx(HWINDOW hWindow,DWORD dwExStyle,wchar_t* lpClassName,wchar_t* lpWindowName,DWORD dwStyle,int x,int y,int cx,int cy,HWND hWndParent,int XCStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_CreateEx);
	XP_Set1(ct,dwExStyle);
	XP_Set2(ct,lpClassName);
	XP_Set3(ct,lpWindowName);
	XP_Set4(ct,dwStyle);
	XP_Set5(ct,x);
	XP_Set6(ct,y);
	XP_Set7(ct,cx);
	XP_Set8(ct,cy);
	XP_Set9(ct,hWndParent);
	XP_Set10(ct,XCStyle);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

void WINAPI SXFrameWnd_GetLayoutAreaRect(HWINDOW hWindow,out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_GetLayoutAreaRect);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXFrameWnd_SetView(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_SetView);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXFrameWnd_SetPaneSplitBarColor(HWINDOW hWindow,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_SetPaneSplitBarColor);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXFrameWnd_SaveLayoutToFile(HWINDOW hWindow,const wchar_t* pFileName)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_SaveLayoutToFile);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pFileName);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXFrameWnd_LoadLayoutFile(HWINDOW hWindow,HELE* aPaneList,int nEleCount,const wchar_t* pFileName)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_LoadLayoutFile);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,aPaneList);
	XP_Set3(ct,nEleCount);
	XP_Set4(ct,pFileName);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXFrameWnd_AddPane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew,align_type_ align)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_AddPane);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hPaneDest);
	XP_Set3(ct,hPaneNew);
	XP_Set4(ct,align);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXFrameWnd_MergePane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew)
{
	XP_Init();
	XP_SetType(ct,ft_XFrameWnd_MergePane);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hPaneDest);
	XP_Set3(ct,hPaneNew);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadFile(HWINDOW hWindow,const wchar_t * pImageName,BOOL bStretch)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadFile);
	XP_Set1(ct,pImageName);
	XP_Set2(ct,bStretch);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadFileAdaptive(HWINDOW hWindow,const wchar_t * pImageName,int leftSize,int topSize,int rightSize,int bottomSize)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadFileAdaptive);
	XP_Set1(ct,pImageName);
	XP_Set2(ct,leftSize);
	XP_Set3(ct,topSize);
	XP_Set4(ct,rightSize);
	XP_Set5(ct,bottomSize);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadFileRect(HWINDOW hWindow,const wchar_t * pImageName,int x,int y,int cx,int cy)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadFileRect);
	XP_Set1(ct,pImageName);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_Set4(ct,cx);
	XP_Set5(ct,cy);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadResAdaptive(HWINDOW hWindow,int id,const wchar_t * pType,int leftSize,int topSize,int rightSize,int bottomSize)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadResAdaptive);
	XP_Set1(ct,id);
	XP_Set2(ct,pType);
	XP_Set3(ct,leftSize);
	XP_Set4(ct,topSize);
	XP_Set5(ct,rightSize);
	XP_Set6(ct,bottomSize);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadRes(HWINDOW hWindow,int id,const wchar_t * pType,BOOL bStretch)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadRes);
	XP_Set1(ct,id);
	XP_Set2(ct,pType);
	XP_Set3(ct,bStretch);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadZip(HWINDOW hWindow,const wchar_t * pZipFileName,const wchar_t * pImageName,const wchar_t * pPassword,BOOL bStretch)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadZip);
	XP_Set1(ct,pZipFileName);
	XP_Set2(ct,pImageName);
	XP_Set3(ct,pPassword);
	XP_Set4(ct,bStretch);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadZipAdaptive(HWINDOW hWindow,const wchar_t * pZipFileName,const wchar_t * pImageName,const wchar_t * pPassword,int x1,int x2,int y1,int y2)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadZipAdaptive);
	XP_Set1(ct,pZipFileName);
	XP_Set2(ct,pImageName);
	XP_Set3(ct,pPassword);
	XP_Set4(ct,x1);
	XP_Set5(ct,x2);
	XP_Set6(ct,y1);
	XP_Set7(ct,y2);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadZipRect(HWINDOW hWindow,const wchar_t * pZipFileName,const wchar_t * pImageName,const wchar_t * pPassword,int x,int y,int cx,int cy)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadZipRect);
	XP_Set1(ct,pZipFileName);
	XP_Set2(ct,pImageName);
	XP_Set3(ct,pPassword);
	XP_Set4(ct,x);
	XP_Set5(ct,y);
	XP_Set6(ct,cx);
	XP_Set7(ct,cy);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadMemory(HWINDOW hWindow,void* pBuffer,int nSize,BOOL bStretch)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadMemory);
	XP_Set1(ct,pBuffer);
	XP_Set2(ct,nSize);
	XP_Set3(ct,bStretch);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadMemoryRect(HWINDOW hWindow,void* pBuffer,int nSize,int x,int y,int cx,int cy,BOOL bStretch)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadMemoryRect);
	XP_Set1(ct,pBuffer);
	XP_Set2(ct,nSize);
	XP_Set3(ct,x);
	XP_Set4(ct,y);
	XP_Set5(ct,cx);
	XP_Set6(ct,cy);
	XP_Set7(ct,bStretch);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadMemoryAdaptive(HWINDOW hWindow,void* pBuffer,int nSize,int leftSize,int topSize,int rightSize,int bottomSize)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadMemoryAdaptive);
	XP_Set1(ct,pBuffer);
	XP_Set2(ct,nSize);
	XP_Set3(ct,leftSize);
	XP_Set4(ct,topSize);
	XP_Set5(ct,rightSize);
	XP_Set6(ct,bottomSize);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadFromImage(HWINDOW hWindow,void * pImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadFromImage);
	XP_Set1(ct,pImage);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadFileFromExtractIcon(HWINDOW hWindow,const wchar_t * pImageName)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadFileFromExtractIcon);
	XP_Set1(ct,pImageName);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadFileFromHICON(HWINDOW hWindow,HICON hIcon)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadFileFromHICON);
	XP_Set1(ct,hIcon);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

HIMAGE WINAPI SXImage_LoadFileFromHBITMAP(HWINDOW hWindow,HBITMAP hBitmap)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_LoadFileFromHBITMAP);
	XP_Set1(ct,hBitmap);
	XP_CALL(hWindow,ct);
	return (HIMAGE)XP_GetRet(ct);
}

BOOL WINAPI SXImage_IsStretch(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_IsStretch);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXImage_IsAdaptive(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_IsAdaptive);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXImage_IsTile(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_IsTile);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXImage_SetDrawType(HWINDOW hWindow,HIMAGE hImage,image_draw_type_ nType)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_SetDrawType);
	XP_Set1(ct,hImage);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXImage_SetDrawTypeAdaptive(HWINDOW hWindow,HIMAGE hImage,int leftSize,int topSize,int rightSize,int bottomSize)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_SetDrawTypeAdaptive);
	XP_Set1(ct,hImage);
	XP_Set2(ct,leftSize);
	XP_Set3(ct,topSize);
	XP_Set4(ct,rightSize);
	XP_Set5(ct,bottomSize);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXImage_SetTranColor(HWINDOW hWindow,HIMAGE hImage,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_SetTranColor);
	XP_Set1(ct,hImage);
	XP_Set2(ct,color);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXImage_SetTranColorEx(HWINDOW hWindow,HIMAGE hImage,COLORREF color,BYTE tranColor)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_SetTranColorEx);
	XP_Set1(ct,hImage);
	XP_Set2(ct,color);
	XP_Set3(ct,tranColor);
	XP_CALL(hWindow,ct);
	
}

float WINAPI SXImage_SetRotateAngle(HWINDOW hWindow,HIMAGE hImage,float fAngle)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_SetRotateAngle);
	XP_Set1(ct,hImage);
	XP_Set2(ct,fAngle);
	XP_CALL(hWindow,ct);
	return (float)XP_GetRet(ct);
}

void WINAPI SXImage_EnableTranColor(HWINDOW hWindow,HIMAGE hImage,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_EnableTranColor);
	XP_Set1(ct,hImage);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXImage_EnableAutoDestroy(HWINDOW hWindow,HIMAGE hImage,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_EnableAutoDestroy);
	XP_Set1(ct,hImage);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXImage_EnableCenter(HWINDOW hWindow,HIMAGE hImage,BOOL bCenter)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_EnableCenter);
	XP_Set1(ct,hImage);
	XP_Set2(ct,bCenter);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXImage_IsCenter(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_IsCenter);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

image_draw_type_ WINAPI SXImage_GetDrawType(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_GetDrawType);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (image_draw_type_)XP_GetRet(ct);
}

int WINAPI SXImage_GetWidth(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_GetWidth);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXImage_GetHeight(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_GetHeight);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXImage_AddRef(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_AddRef);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXImage_Release(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_Release);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXImage_GetRefCount(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_GetRefCount);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXImage_Destroy(HWINDOW hWindow,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XImage_Destroy);
	XP_Set1(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXLayout_Create(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_Create);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXLayout_Destroy(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_Destroy);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_AddEle(HWINDOW hWindow,HXCGUI hLayout,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_AddEle);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_AddLayoutObject(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hLayoutObject)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_AddLayoutObject);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hLayoutObject);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_AddShape(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_AddShape);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hShape);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXLayout_Add(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_Add);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hChild);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXLayout_Insert(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_Insert);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hChild);
	XP_Set3(ct,index);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXLayout_RemoveLayout(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_RemoveLayout);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_RemoveChild(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_RemoveChild);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hChild);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXLayout_GetZOrder(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetZOrder);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hChild);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXLayout_AdjustLayout(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_AdjustLayout);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_SetRectFrame(HWINDOW hWindow,HXCGUI hLayout,RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetRectFrame);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_GetRect(HWINDOW hWindow,HXCGUI hLayout,out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetRect);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_GetRectFrame(HWINDOW hWindow,HXCGUI hLayout,out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetRectFrame);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

HWINDOW WINAPI SXLayout_GetWindow(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetWindow);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

HELE WINAPI SXLayout_GetEle(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetEle);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HXCGUI WINAPI SXLayout_GetParentLayout(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetParentLayout);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXLayout_GetParent(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetParent);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXLayout_SetID(HWINDOW hWindow,HXCGUI hLayout,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetID);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXLayout_GetID(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetID);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXLayout_SetUID(HWINDOW hWindow,HXCGUI hLayout,int nUID)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetUID);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,nUID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXLayout_GetUID(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetUID);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXLayout_SetHorizon(HWINDOW hWindow,HXCGUI hLayout,BOOL bHorizon)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetHorizon);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,bHorizon);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_SetAlignH(HWINDOW hWindow,HXCGUI hLayout,layout_align_ nAlign)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetAlignH);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,nAlign);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_SetAlignV(HWINDOW hWindow,HXCGUI hLayout,layout_align_ nAlign)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetAlignV);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,nAlign);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_SetPadding(HWINDOW hWindow,HXCGUI hLayout,int left,int top,int right,int bottom)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetPadding);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,left);
	XP_Set3(ct,top);
	XP_Set4(ct,right);
	XP_Set5(ct,bottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_SetSpace(HWINDOW hWindow,HXCGUI hLayout,int nSpace)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetSpace);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,nSpace);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_SetLayoutWidth(HWINDOW hWindow,HXCGUI hLayout,layout_size_type_ nType,int nWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetLayoutWidth);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,nType);
	XP_Set3(ct,nWidth);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_SetLayoutHeight(HWINDOW hWindow,HXCGUI hLayout,layout_size_type_ nType,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_SetLayoutHeight);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,nType);
	XP_Set3(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_GetLayoutWidth(HWINDOW hWindow,HXCGUI hLayout,out_ layout_size_type_ * pType,out_ int * pWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetLayoutWidth);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,pType);
	XP_Set3(ct,pWidth);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_GetLayoutHeight(HWINDOW hWindow,HXCGUI hLayout,out_ layout_size_type_ * pType,out_ int * pHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetLayoutHeight);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,pType);
	XP_Set3(ct,pHeight);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXLayout_GetWidth(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetWidth);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXLayout_GetHeight(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetHeight);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXLayout_GetWidthIn(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetWidthIn);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXLayout_GetHeightIn(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetHeightIn);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXLayout_GetContentSize(HWINDOW hWindow,HXCGUI hLayout,out_ SIZE* pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetContentSize);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXLayout_ShowLayout(HWINDOW hWindow,HXCGUI hLayout,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_ShowLayout);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXLayout_GetChildCount(HWINDOW hWindow,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetChildCount);
	XP_Set1(ct,hLayout);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

XC_OBJECT_TYPE WINAPI SXLayout_GetChildType(HWINDOW hWindow,HXCGUI hLayout,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetChildType);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (XC_OBJECT_TYPE)XP_GetRet(ct);
}

HXCGUI WINAPI SXLayout_GetChild(HWINDOW hWindow,HXCGUI hLayout,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_GetChild);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXLayout_Draw(HWINDOW hWindow,HXCGUI hLayout,HDRAW hDraw)
{
	XP_Init();
	XP_SetType(ct,ft_XLayout_Draw);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hDraw);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SLayout_SetEle(HWINDOW hWindow,HXCGUI hLayout,HELE hParent)
{
	XP_Init();
	XP_SetType(ct,ft_Layout_SetEle);
	XP_Set1(ct,hLayout);
	XP_Set2(ct,hParent);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXListBox_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXListBox_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetDrawItemBkFlags);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nFlags);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXListBox_SetItemData(HWINDOW hWindow,HELE hEle,int iItem,int nUserData)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,nUserData);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXListBox_GetItemData(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXListBox_SetItemInfo(HWINDOW hWindow,HELE hEle,int iItem,in_ listBox_item_info_i * pItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetItemInfo);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXListBox_GetItemInfo(HWINDOW hWindow,HELE hEle,int iItem,out_ listBox_item_info_i * pItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetItemInfo);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,pItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXListBox_AddItemBkBorder(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_AddItemBkBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_Set5(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListBox_AddItemBkFill(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_AddItemBkFill);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListBox_AddItemBkImage(HWINDOW hWindow,HELE hEle,list_item_state_ nState,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_AddItemBkImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXListBox_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetItemBkInfoCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXListBox_ClearItemBkInfo(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_ClearItemBkInfo);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXListBox_SetSelectItem(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetSelectItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXListBox_GetSelectItem(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetSelectItem);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXListBox_CancelSelectItem(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_CancelSelectItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXListBox_CancelSelectAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_CancelSelectAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXListBox_GetSelectAll(HWINDOW hWindow,HELE hEle,out_ int * pArray,int nArraySize)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetSelectAll);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pArray);
	XP_Set3(ct,nArraySize);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXListBox_GetSelectCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetSelectCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXListBox_GetItemMouseStay(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetItemMouseStay);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXListBox_SelectAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SelectAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXListBox_SetItemHeightDefault(HWINDOW hWindow,HELE hEle,int nHeight,int nSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetItemHeightDefault);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nHeight);
	XP_Set3(ct,nSelHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListBox_GetItemHeightDefault(HWINDOW hWindow,HELE hEle,out_ int * pHeight,out_ int * pSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetItemHeightDefault);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pHeight);
	XP_Set3(ct,pSelHeight);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXListBox_GetItemIndexFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetItemIndexFromHXCGUI);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXListBox_SetRowSpace(HWINDOW hWindow,HELE hEle,int nSpace)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetRowSpace);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nSpace);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXListBox_GetRowSpace(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetRowSpace);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXListBox_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_HitTest);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXListBox_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_HitTestOffset);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXListBox_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetItemTemplateXML);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pXmlFile);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXListBox_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_SetItemTemplateXMLFromString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pStringXML);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HXCGUI WINAPI SXListBox_GetTemplateObject(HWINDOW hWindow,HELE hEle,int iItem,int nTempItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetTemplateObject);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,nTempItemID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXListBox_EnableMultiSel(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_EnableMultiSel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXListBox_CreateAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_CreateAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXListBox_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_BindAdapter);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXListBox_GetAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_GetAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXListBox_Sort(HWINDOW hWindow,HELE hEle,int iColumnAdapter,BOOL bAscending)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_Sort);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iColumnAdapter);
	XP_Set3(ct,bAscending);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListBox_RefreshData(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_RefreshData);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListBox_RefreshItem(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListBox_RefreshItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	
}

HTEMP WINAPI SXTemp_Load(HWINDOW hWindow,XC_OBJECT_TYPE nType,const wchar_t* pFileName)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_Load);
	XP_Set1(ct,nType);
	XP_Set2(ct,pFileName);
	XP_CALL(hWindow,ct);
	return (HTEMP)XP_GetRet(ct);
}

HTEMP WINAPI SXTemp_LoadFromString(HWINDOW hWindow,XC_OBJECT_TYPE nType,const char* pStringXML)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_LoadFromString);
	XP_Set1(ct,nType);
	XP_Set2(ct,pStringXML);
	XP_CALL(hWindow,ct);
	return (HTEMP)XP_GetRet(ct);
}

BOOL WINAPI SXTemp_Destroy(HWINDOW hWindow,HTEMP hTemp)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_Destroy);
	XP_Set1(ct,hTemp);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HTEMP WINAPI SXTemp_Create(HWINDOW hWindow,XC_OBJECT_TYPE nType)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_Create);
	XP_Set1(ct,nType);
	XP_CALL(hWindow,ct);
	return (HTEMP)XP_GetRet(ct);
}

BOOL WINAPI SXTemp_AddNodeRoot(HWINDOW hWindow,HTEMP hTemp,void* pNode)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_AddNodeRoot);
	XP_Set1(ct,hTemp);
	XP_Set2(ct,pNode);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXTemp_AddNode(HWINDOW hWindow,void* pParentNode,void* pNode)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_AddNode);
	XP_Set1(ct,pParentNode);
	XP_Set2(ct,pNode);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void* WINAPI SXTemp_CreateNode(HWINDOW hWindow,XC_OBJECT_TYPE nType)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_CreateNode);
	XP_Set1(ct,nType);
	XP_CALL(hWindow,ct);
	return (void*)XP_GetRet(ct);
}

BOOL WINAPI SXTemp_SetNodeAttribute(HWINDOW hWindow,void* pNode,const wchar_t* pName,const wchar_t* pAttr)
{
	XP_Init();
	XP_SetType(ct,ft_XTemp_SetNodeAttribute);
	XP_Set1(ct,pNode);
	XP_Set2(ct,pName);
	XP_Set3(ct,pAttr);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXList_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XList_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXList_AddColumn(HWINDOW hWindow,HELE hEle,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XList_AddColumn);
	XP_Set1(ct,hEle);
	XP_Set2(ct,width);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXList_InsertColumn(HWINDOW hWindow,HELE hEle,int width,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_InsertColumn);
	XP_Set1(ct,hEle);
	XP_Set2(ct,width);
	XP_Set3(ct,iItem);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXList_EnableMultiSel(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XList_EnableMultiSel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_EnableDragChangeColumnWidth(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XList_EnableDragChangeColumnWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_EnableVScrollBarTop(HWINDOW hWindow,HELE hEle,BOOL bTop)
{
	XP_Init();
	XP_SetType(ct,ft_XList_EnableVScrollBarTop);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bTop);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_EnableItemBkFullRow(HWINDOW hWindow,HELE hEle,BOOL bFull)
{
	XP_Init();
	XP_SetType(ct,ft_XList_EnableItemBkFullRow);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bFull);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_SetSort(HWINDOW hWindow,HELE hEle,int iColumn,int iColumnAdapter,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetSort);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iColumn);
	XP_Set3(ct,iColumnAdapter);
	XP_Set4(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int style)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetDrawItemBkFlags);
	XP_Set1(ct,hEle);
	XP_Set2(ct,style);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_SetColumnWidth(HWINDOW hWindow,HELE hEle,int iItem,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetColumnWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_SetColumnMinWidth(HWINDOW hWindow,HELE hEle,int iItem,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetColumnMinWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_SetColumnWidthFixed(HWINDOW hWindow,HELE hEle,int iColumn,BOOL bFixed)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetColumnWidthFixed);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iColumn);
	XP_Set3(ct,bFixed);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXList_GetColumnWidth(HWINDOW hWindow,HELE hEle,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetColumnWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iColumn);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXList_GetColumnCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetColumnCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXList_DeleteColumn(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_DeleteColumn);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXList_DeleteColumnAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_DeleteColumnAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXList_SetItemData(HWINDOW hWindow,HELE hEle,int iItem,int iSubItem,int data)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iSubItem);
	XP_Set4(ct,data);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXList_GetItemData(HWINDOW hWindow,HELE hEle,int iItem,int iSubItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,iSubItem);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXList_SetSelectItem(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetSelectItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXList_GetSelectItem(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetSelectItem);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXList_GetSelectItemCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetSelectItemCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXList_SetSelectAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetSelectAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXList_GetSelectAll(HWINDOW hWindow,HELE hEle,out_ int * pArray,int nArraySize)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetSelectAll);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pArray);
	XP_Set3(ct,nArraySize);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXList_CancelSelectItem(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_CancelSelectItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXList_CancelSelectAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_CancelSelectAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXList_GetHeaderHELE(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetHeaderHELE);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXList_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XList_BindAdapter);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_BindAdapterHeader(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XList_BindAdapterHeader);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXList_CreateAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_CreateAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXList_CreateAdapterHeader(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_CreateAdapterHeader);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXList_GetAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXList_GetAdapterHeader(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetAdapterHeader);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

BOOL WINAPI SXList_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetItemTemplateXML);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pXmlFile);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXList_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetItemTemplateXMLFromString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pStringXML);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HXCGUI WINAPI SXList_GetTemplateObject(HWINDOW hWindow,HELE hEle,int iItem,int nTempItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetTemplateObject);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,nTempItemID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

int WINAPI SXList_GetItemIndexFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetItemIndexFromHXCGUI);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HXCGUI WINAPI SXList_GetHeaderTemplateObject(HWINDOW hWindow,HELE hEle,int iItem,int nTempItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetHeaderTemplateObject);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_Set3(ct,nTempItemID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

int WINAPI SXList_GetHeaderItemIndexFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetHeaderItemIndexFromHXCGUI);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXList_SetHeaderHeight(HWINDOW hWindow,HELE hEle,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetHeaderHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,height);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXList_GetHeaderHeight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetHeaderHeight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXList_AddItemBkBorder(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XList_AddItemBkBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_Set5(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_AddItemBkFill(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XList_AddItemBkFill);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_AddItemBkImage(HWINDOW hWindow,HELE hEle,list_item_state_ nState,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XList_AddItemBkImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXList_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetItemBkInfoCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXList_ClearItemBkInfo(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_ClearItemBkInfo);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_SetItemHeightDefault(HWINDOW hWindow,HELE hEle,int nHeight,int nSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetItemHeightDefault);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nHeight);
	XP_Set3(ct,nSelHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_GetItemHeightDefault(HWINDOW hWindow,HELE hEle,out_ int * pHeight,out_ int * pSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetItemHeightDefault);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pHeight);
	XP_Set3(ct,pSelHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_SetRowSpace(HWINDOW hWindow,HELE hEle,int nSpace)
{
	XP_Init();
	XP_SetType(ct,ft_XList_SetRowSpace);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nSpace);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXList_GetRowSpace(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_GetRowSpace);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXList_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt,out_ int * piItem,out_ int * piSubItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_HitTest);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_Set3(ct,piItem);
	XP_Set4(ct,piSubItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXList_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt,out_ int * piItem,out_ int * piSubItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_HitTestOffset);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_Set3(ct,piItem);
	XP_Set4(ct,piSubItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXList_RefreshData(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XList_RefreshData);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXList_RefreshItem(HWINDOW hWindow,HELE hEle,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XList_RefreshItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iItem);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXListView_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HXCGUI WINAPI SXListView_CreateAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_CreateAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXListView_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_BindAdapter);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXListView_GetAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

BOOL WINAPI SXListView_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetItemTemplateXML);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pXmlFile);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXListView_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetItemTemplateXMLFromString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pStringXML);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HXCGUI WINAPI SXListView_GetTemplateObject(HWINDOW hWindow,HELE hEle,int iGroup,int iItem,int nTempItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetTemplateObject);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,nTempItemID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXListView_GetTemplateObjectGroup(HWINDOW hWindow,HELE hEle,int iGroup,int nTempItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetTemplateObjectGroup);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,nTempItemID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

BOOL WINAPI SXListView_GetItemIDFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI,out_ int* piGroup,out_ int* piItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetItemIDFromHXCGUI);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hXCGUI);
	XP_Set3(ct,piGroup);
	XP_Set4(ct,piItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXListView_HitTest(HWINDOW hWindow,HELE hEle,in_ POINT* pPt,out_ int* pOutGroup,out_ int* pOutItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_HitTest);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_Set3(ct,pOutGroup);
	XP_Set4(ct,pOutItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXListView_HitTestOffset(HWINDOW hWindow,HELE hEle,in_ POINT * pPt,out_ int* pOutGroup,out_ int* pOutItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_HitTestOffset);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_Set3(ct,pOutGroup);
	XP_Set4(ct,pOutItem);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXListView_EnableMultiSel(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_EnableMultiSel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetDrawItemBkFlags);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nFlags);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXListView_SetSelectItem(HWINDOW hWindow,HELE hEle,int iGroup,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetSelectItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXListView_GetSelectItem(HWINDOW hWindow,HELE hEle,int * piGroup,int * piItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetSelectItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,piGroup);
	XP_Set3(ct,piItem);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXListView_GetSelectItemCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetSelectItemCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXListView_GetSelectItemAll(HWINDOW hWindow,HELE hEle,out_ listView_item_id_i * pArray,int nArraySize)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetSelectItemAll);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pArray);
	XP_Set3(ct,nArraySize);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXListView_SetSelectItemAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetSelectItemAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_CancelSelectItemAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_CancelSelectItemAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetColumnSpace(HWINDOW hWindow,HELE hEle,int space)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetColumnSpace);
	XP_Set1(ct,hEle);
	XP_Set2(ct,space);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetRowSpace(HWINDOW hWindow,HELE hEle,int space)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetRowSpace);
	XP_Set1(ct,hEle);
	XP_Set2(ct,space);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetAlignSizeLeft(HWINDOW hWindow,HELE hEle,int size)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetAlignSizeLeft);
	XP_Set1(ct,hEle);
	XP_Set2(ct,size);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetAlignSizeTop(HWINDOW hWindow,HELE hEle,int size)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetAlignSizeTop);
	XP_Set1(ct,hEle);
	XP_Set2(ct,size);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetItemSize(HWINDOW hWindow,HELE hEle,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetItemSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,width);
	XP_Set3(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_GetItemSize(HWINDOW hWindow,HELE hEle,SIZE* pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetItemSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetGroupHeight(HWINDOW hWindow,HELE hEle,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetGroupHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,height);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXListView_GetGroupHeight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetGroupHeight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXListView_SetGroupUserData(HWINDOW hWindow,HELE hEle,int iGroup,int nData)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetGroupUserData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,nData);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_SetItemUserData(HWINDOW hWindow,HELE hEle,int iGroup,int iItem,int nData)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_SetItemUserData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_Set4(ct,nData);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXListView_GetGroupUserData(HWINDOW hWindow,HELE hEle,int iGroup)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetGroupUserData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXListView_GetItemUserData(HWINDOW hWindow,HELE hEle,int iGroup,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetItemUserData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXListView_AddItemBkBorder(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_AddItemBkBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_Set5(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_AddItemBkFill(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_AddItemBkFill);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_AddItemBkImage(HWINDOW hWindow,HELE hEle,list_item_state_ nState,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_AddItemBkImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXListView_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_GetItemBkInfoCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXListView_ClearItemBkInfo(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_ClearItemBkInfo);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_RefreshData(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_RefreshData);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXListView_RefreshItem(HWINDOW hWindow,HELE hEle,int iGroup,int iItem)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_RefreshItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,iItem);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXListView_ExpandGroup(HWINDOW hWindow,HELE hEle,int iGroup,BOOL bExpand)
{
	XP_Init();
	XP_SetType(ct,ft_XListView_ExpandGroup);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iGroup);
	XP_Set3(ct,bExpand);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXMenuBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XMenuBar_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXMenuBar_AddButton(HWINDOW hWindow,HELE hEle,const wchar_t * pText)
{
	XP_Init();
	XP_SetType(ct,ft_XMenuBar_AddButton);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pText);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXMenuBar_SetButtonHeight(HWINDOW hWindow,HELE hEle,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XMenuBar_SetButtonHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,height);
	XP_CALL(hWindow,ct);
	
}

HMENUX WINAPI SXMenuBar_GetMenu(HWINDOW hWindow,HELE hEle,int nIndex)
{
	XP_Init();
	XP_SetType(ct,ft_XMenuBar_GetMenu);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nIndex);
	XP_CALL(hWindow,ct);
	return (HMENUX)XP_GetRet(ct);
}

BOOL WINAPI SXMenuBar_DeleteButton(HWINDOW hWindow,HELE hEle,int nIndex)
{
	XP_Init();
	XP_SetType(ct,ft_XMenuBar_DeleteButton);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nIndex);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HMENUX WINAPI SXMenu_Create(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_Create);
	XP_CALL(hWindow,ct);
	return (HMENUX)XP_GetRet(ct);
}

void WINAPI SXMenu_AddItem(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,int parentId,int nFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_AddItem);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,pText);
	XP_Set4(ct,parentId);
	XP_Set5(ct,nFlags);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_AddItemIcon(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,int nParentID,HIMAGE hImage,int nFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_AddItemIcon);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,pText);
	XP_Set4(ct,nParentID);
	XP_Set5(ct,hImage);
	XP_Set6(ct,nFlags);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_InsertItem(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,int nFlags,int insertID)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_InsertItem);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,pText);
	XP_Set4(ct,nFlags);
	XP_Set5(ct,insertID);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_InsertItemIcon(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,HIMAGE hIcon,int nFlags,int insertID)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_InsertItemIcon);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,pText);
	XP_Set4(ct,hIcon);
	XP_Set5(ct,nFlags);
	XP_Set6(ct,insertID);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_SetAutoDestroy(HWINDOW hWindow,HMENUX hMenu,BOOL bAuto)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetAutoDestroy);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,bAuto);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_EnableDrawBackground(HWINDOW hWindow,HMENUX hMenu,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_EnableDrawBackground);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_EnableDrawItem(HWINDOW hWindow,HMENUX hMenu,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_EnableDrawItem);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXMenu_Popup(HWINDOW hWindow,HMENUX hMenu,HWND hParentWnd,int x,int y,HELE hParentEle,menu_popup_position_ nPosition)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_Popup);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,hParentWnd);
	XP_Set3(ct,x);
	XP_Set4(ct,y);
	XP_Set5(ct,hParentEle);
	XP_Set6(ct,nPosition);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXMenu_DestroyMenu(HWINDOW hWindow,HMENUX hMenu)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_DestroyMenu);
	XP_Set1(ct,hMenu);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_CloseMenu(HWINDOW hWindow,HMENUX hMenu)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_CloseMenu);
	XP_Set1(ct,hMenu);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXMenu_SetBkImage(HWINDOW hWindow,HMENUX hMenu,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetBkImage);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXMenu_SetItemText(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetItemText);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,pText);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXMenu_GetItemText(HWINDOW hWindow,HMENUX hMenu,int nID,out_ wchar_t * pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_GetItemText);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,pOut);
	XP_Set4(ct,nOutLen);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXMenu_GetItemTextLength(HWINDOW hWindow,HMENUX hMenu,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_GetItemTextLength);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXMenu_SetItemIcon(HWINDOW hWindow,HMENUX hMenu,int nID,HIMAGE hIcon)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetItemIcon);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,hIcon);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXMenu_SetItemFlags(HWINDOW hWindow,HMENUX hMenu,int nID,int uFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetItemFlags);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,uFlags);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXMenu_SetItemHeight(HWINDOW hWindow,HMENUX hMenu,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetItemHeight);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,height);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXMenu_GetItemHeight(HWINDOW hWindow,HMENUX hMenu)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_GetItemHeight);
	XP_Set1(ct,hMenu);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXMenu_SetBorderColor(HWINDOW hWindow,HMENUX hMenu,COLORREF crColor,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetBorderColor);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,crColor);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXMenu_GetLeftWidth(HWINDOW hWindow,HMENUX hMenu)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_GetLeftWidth);
	XP_Set1(ct,hMenu);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXMenu_GetLeftSpaceText(HWINDOW hWindow,HMENUX hMenu)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_GetLeftSpaceText);
	XP_Set1(ct,hMenu);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXMenu_GetItemCount(HWINDOW hWindow,HMENUX hMenu)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_GetItemCount);
	XP_Set1(ct,hMenu);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXMenu_SetItemCheck(HWINDOW hWindow,HMENUX hMenu,int nID,BOOL bCheck)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_SetItemCheck);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_Set3(ct,bCheck);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXMenu_IsItemCheck(HWINDOW hWindow,HMENUX hMenu,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XMenu_IsItemCheck);
	XP_Set1(ct,hMenu);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HWINDOW WINAPI SXModalWnd_Create(HWINDOW hWindow,int nWidth,int nHeight,const wchar_t * pTitle,HWND hWndParent,int XCStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XModalWnd_Create);
	XP_Set1(ct,nWidth);
	XP_Set2(ct,nHeight);
	XP_Set3(ct,pTitle);
	XP_Set4(ct,hWndParent);
	XP_Set5(ct,XCStyle);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

HWINDOW WINAPI SXModalWnd_CreateEx(HWINDOW hWindow,DWORD dwExStyle,const wchar_t* lpClassName,const wchar_t* lpWindowName,DWORD dwStyle,int x,int y,int cx,int cy,HWND hWndParent,int XCStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XModalWnd_CreateEx);
	XP_Set1(ct,dwExStyle);
	XP_Set2(ct,lpClassName);
	XP_Set3(ct,lpWindowName);
	XP_Set4(ct,dwStyle);
	XP_Set5(ct,x);
	XP_Set6(ct,y);
	XP_Set7(ct,cx);
	XP_Set8(ct,cy);
	XP_Set9(ct,hWndParent);
	XP_Set10(ct,XCStyle);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

void WINAPI SXModalWnd_EnableAutoClose(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XModalWnd_EnableAutoClose);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXModalWnd_EnableEscClose(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XModalWnd_EnableEscClose);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXModalWnd_DoModal(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XModalWnd_DoModal);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXModalWnd_EndModal(HWINDOW hWindow,int nResult)
{
	XP_Init();
	XP_SetType(ct,ft_XModalWnd_EndModal);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nResult);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXPane_Create(HWINDOW hWindow,const wchar_t * pName,int nWidth,int nHeight,HWINDOW hFrameWnd)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_Create);
	XP_Set1(ct,pName);
	XP_Set2(ct,nWidth);
	XP_Set3(ct,nHeight);
	XP_Set4(ct,hFrameWnd);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXPane_SetView(HWINDOW hWindow,HELE hEle,HELE hView)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_SetView);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hView);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXPane_IsShowPane(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_IsShowPane);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXPane_SetSize(HWINDOW hWindow,HELE hEle,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_SetSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nWidth);
	XP_Set3(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

pane_state_ WINAPI SXPane_GetState(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_GetState);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (pane_state_)XP_GetRet(ct);
}

void WINAPI SXPane_GetViewRect(HWINDOW hWindow,HELE hEle,out_ RECT* pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_GetViewRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXPane_SetTitle(HWINDOW hWindow,HELE hEle,wchar_t* pTitle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_SetTitle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pTitle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXPane_GetTitle(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_GetTitle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pOut);
	XP_Set3(ct,nOutLen);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXPane_SetCaptionHeight(HWINDOW hWindow,HELE hEle,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_SetCaptionHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXPane_GetCaptionHeight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_GetCaptionHeight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXPane_HidePane(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_HidePane);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXPane_ShowPane(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_ShowPane);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXPane_DockPane(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_DockPane);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXPane_LockPane(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_LockPane);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXPane_FloatPane(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPane_FloatPane);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXFloatWnd_EnableCaptionContent(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XFloatWnd_EnableCaptionContent);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HXCGUI WINAPI SXFloatWnd_GetCaptionLayout(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XFloatWnd_GetCaptionLayout);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HXCGUI WINAPI SXFloatWnd_GetCaptionShapeText(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XFloatWnd_GetCaptionShapeText);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HELE WINAPI SXFloatWnd_GetCaptionButtonClose(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XFloatWnd_GetCaptionButtonClose);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXFloatWnd_SetTitle(HWINDOW hWindow,const wchar_t* pTitle)
{
	XP_Init();
	XP_SetType(ct,ft_XFloatWnd_SetTitle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pTitle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXFloatWnd_GetTitle(HWINDOW hWindow,out_ wchar_t* pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XFloatWnd_GetTitle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pOut);
	XP_Set3(ct,nOutLen);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXProgBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXProgBar_SetRange(HWINDOW hWindow,HELE hEle,int range)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_SetRange);
	XP_Set1(ct,hEle);
	XP_Set2(ct,range);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXProgBar_GetRange(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_GetRange);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXProgBar_SetSpaceTwo(HWINDOW hWindow,HELE hEle,int leftSize,int rightSize)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_SetSpaceTwo);
	XP_Set1(ct,hEle);
	XP_Set2(ct,leftSize);
	XP_Set3(ct,rightSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXProgBar_SetPos(HWINDOW hWindow,HELE hEle,int pos)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_SetPos);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pos);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXProgBar_GetPos(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_GetPos);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXProgBar_SetHorizon(HWINDOW hWindow,HELE hEle,BOOL bHorizon)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_SetHorizon);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bHorizon);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXProgBar_SetImageLoad(HWINDOW hWindow,HELE hEle,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XProgBar_SetImageLoad);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXPGrid_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXPGrid_AddItem(HWINDOW hWindow,HELE hEle,const wchar_t * pName,propertyGrid_item_type_ nType,int nParentID)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_AddItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pName);
	XP_Set3(ct,nType);
	XP_Set4(ct,nParentID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXPGrid_AddItemString(HWINDOW hWindow,HELE hEle,const wchar_t * pName,const wchar_t * pValue,int nParentID)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_AddItemString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pName);
	XP_Set3(ct,pValue);
	XP_Set4(ct,nParentID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXPGrid_DeleteAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_DeleteAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXPGrid_GetItemHELE(HWINDOW hWindow,HELE hEle,int nItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_GetItemHELE);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXPGrid_SetWidth(HWINDOW hWindow,HELE hEle,int nWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_SetWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nWidth);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXPGrid_SetItemValue(HWINDOW hWindow,HELE hEle,int nItemID,const wchar_t* pValue)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_SetItemValue);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_Set3(ct,pValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXPGrid_SetItemValueInt(HWINDOW hWindow,HELE hEle,int nItemID,int nValue)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_SetItemValueInt);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_Set3(ct,nValue);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXPGrid_SetItemData(HWINDOW hWindow,HELE hEle,int nItemID,int nUserData)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_SetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_Set3(ct,nUserData);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXPGrid_GetItemData(HWINDOW hWindow,HELE hEle,int nItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_GetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

const wchar_t* WINAPI SXPGrid_GetItemValue(HWINDOW hWindow,HELE hEle,int nItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_GetItemValue);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_CALL(hWindow,ct);
	return (const wchar_t*)XP_GetRet(ct);
}

int WINAPI SXPGrid_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt,BOOL * pbExpandButton)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_HitTest);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_Set3(ct,pbExpandButton);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXPGrid_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt,BOOL * pbExpandButton)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_HitTestOffset);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_Set3(ct,pbExpandButton);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXPGrid_ExpandItem(HWINDOW hWindow,HELE hEle,int nItemID,BOOL bExpand)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_ExpandItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_Set3(ct,bExpand);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXPGrid_GetSelItem(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_GetSelItem);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXPGrid_SetSelItem(HWINDOW hWindow,HELE hEle,int nItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_SetSelItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nItemID);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXPGrid_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XPGrid_SetDrawItemBkFlags);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nFlags);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXRichEditColor_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditColor_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXRichEditColor_SetColor(HWINDOW hWindow,HELE hEle,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditColor_SetColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_CALL(hWindow,ct);
	
}

COLORREF WINAPI SXRichEditColor_GetColor(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditColor_GetColor);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

HELE WINAPI SXRichEditSet_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditSet_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXRichEditFile_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditFile_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXRichEditFile_SetOpenFileType(HWINDOW hWindow,HELE hEle,const wchar_t * pType)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditFile_SetOpenFileType);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pType);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEditFile_SetDefaultFile(HWINDOW hWindow,HELE hEle,const wchar_t * pFile)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditFile_SetDefaultFile);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pFile);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEditFile_SetRelativeDir(HWINDOW hWindow,HELE hEle,const wchar_t * pDir)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditFile_SetRelativeDir);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pDir);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXRichEditFolder_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditFolder_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXRichEditFolder_SetDefaultDir(HWINDOW hWindow,HELE hEle,const wchar_t* pDir)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEditFolder_SetDefaultDir);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pDir);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXRichEdit_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXRichEdit_InsertString(HWINDOW hWindow,HELE hEle,const wchar_t * pString,HFONTX hFont)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_InsertString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pString);
	XP_Set3(ct,hFont);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXRichEdit_InsertImage(HWINDOW hWindow,HELE hEle,HIMAGE hImage,const wchar_t * pImagePath)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_InsertImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_Set3(ct,pImagePath);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_InsertGif(HWINDOW hWindow,HELE hEle,HIMAGE hImage,const wchar_t * pImagePath)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_InsertGif);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_Set3(ct,pImagePath);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXRichEdit_InsertStringEx(HWINDOW hWindow,HELE hEle,int iRow,int iColumn,const wchar_t * pString,HFONTX hFont)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_InsertStringEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iRow);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,pString);
	XP_Set5(ct,hFont);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXRichEdit_InsertImageEx(HWINDOW hWindow,HELE hEle,int iRow,int iColumn,HIMAGE hImage,const wchar_t * pImagePath)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_InsertImageEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iRow);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,hImage);
	XP_Set5(ct,pImagePath);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_InsertGifEx(HWINDOW hWindow,HELE hEle,int iRow,int iColumn,HIMAGE hImage,const wchar_t * pImagePath)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_InsertGifEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iRow);
	XP_Set3(ct,iColumn);
	XP_Set4(ct,hImage);
	XP_Set5(ct,pImagePath);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXRichEdit_EnableReadOnly(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_EnableReadOnly);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_EnableMultiLine(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_EnableMultiLine);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_EnablePassword(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_EnablePassword);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_EnableAutoWrap(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_EnableAutoWrap);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_EnableAutoSelAll(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_EnableAutoSelAll);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_EnableVerticalCenter(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_EnableVerticalCenter);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXRichEdit_IsEmpty(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_IsEmpty);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_IsReadOnly(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_IsReadOnly);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_IsMultiLine(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_IsMultiLine);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_IsPassword(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_IsPassword);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_IsAutoWrap(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_IsAutoWrap);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXRichEdit_SetLimitNum(HWINDOW hWindow,HELE hEle,int nNumber)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetLimitNum);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nNumber);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_SetCaretColor(HWINDOW hWindow,HELE hEle,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetCaretColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_SetText(HWINDOW hWindow,HELE hEle,const wchar_t* pString)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetText);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pString);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_SetTextInt(HWINDOW hWindow,HELE hEle,int nVaule)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetTextInt);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nVaule);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXRichEdit_GetText(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int len)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetText);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pOut);
	XP_Set3(ct,len);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXRichEdit_GetHTMLFormat(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int len)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetHTMLFormat);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pOut);
	XP_Set3(ct,len);
	XP_CALL(hWindow,ct);
	
}

void* WINAPI SXRichEdit_GetData(HWINDOW hWindow,HELE hEle,out_ int * pDataSize)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pDataSize);
	XP_CALL(hWindow,ct);
	return (void*)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_InsertData(HWINDOW hWindow,HELE hEle,void * pData,int iRow,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_InsertData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pData);
	XP_Set3(ct,iRow);
	XP_Set4(ct,iColumn);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXRichEdit_GetTextLength(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetTextLength);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXRichEdit_SetRowHeight(HWINDOW hWindow,HELE hEle,UINT nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetRowHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_SetDefaultText(HWINDOW hWindow,HELE hEle,const wchar_t* pString)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetDefaultText);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pString);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_SetDefaultTextColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetDefaultTextColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_SetCurrentInputTextColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetCurrentInputTextColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXRichEdit_GetCurrentRow(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetCurrentRow);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXRichEdit_GetCurrentColumn(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetCurrentColumn);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXRichEdit_SetCurrentPos(HWINDOW hWindow,HELE hEle,int iRow,int iColumn)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetCurrentPos);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iRow);
	XP_Set3(ct,iColumn);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXRichEdit_GetRowCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetRowCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXRichEdit_GetRowLength(HWINDOW hWindow,HELE hEle,int iRow)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetRowLength);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iRow);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXRichEdit_GetSelectText(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int len)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetSelectText);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pOut);
	XP_Set3(ct,len);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_GetSelectPosition(HWINDOW hWindow,HELE hEle,out_ Position_i * pBegin,out_ Position_i * pEnd)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_GetSelectPosition);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pBegin);
	XP_Set3(ct,pEnd);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_SetSelect(HWINDOW hWindow,HELE hEle,int iStartRow,int iStartCol,int iEndRow,int iEndCol)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetSelect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,iStartRow);
	XP_Set3(ct,iStartCol);
	XP_Set4(ct,iEndRow);
	XP_Set5(ct,iEndCol);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_SetItemFontEx(HWINDOW hWindow,HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,HFONTX hFont)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetItemFontEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,beginRow);
	XP_Set3(ct,beginColumn);
	XP_Set4(ct,endRow);
	XP_Set5(ct,endColumn);
	XP_Set6(ct,hFont);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_SetItemColorEx(HWINDOW hWindow,HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetItemColorEx);
	XP_Set1(ct,hEle);
	XP_Set2(ct,beginRow);
	XP_Set3(ct,beginColumn);
	XP_Set4(ct,endRow);
	XP_Set5(ct,endColumn);
	XP_Set6(ct,color);
	XP_Set7(ct,alpha);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXRichEdit_CancelSelect(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_CancelSelect);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXRichEdit_SetSelectBkColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SetSelectBkColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXRichEdit_SelectAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_SelectAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_DeleteSelect(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_DeleteSelect);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXRichEdit_DeleteAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_DeleteAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXRichEdit_ClipboardCut(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_ClipboardCut);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_ClipboardCopy(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_ClipboardCopy);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXRichEdit_ClipboardPaste(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XRichEdit_ClipboardPaste);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXSBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXSBar_SetRange(HWINDOW hWindow,HELE hEle,int range)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_SetRange);
	XP_Set1(ct,hEle);
	XP_Set2(ct,range);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXSBar_GetRange(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_GetRange);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXSBar_ShowButton(HWINDOW hWindow,HELE hEle,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_ShowButton);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSBar_SetSliderLength(HWINDOW hWindow,HELE hEle,int length)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_SetSliderLength);
	XP_Set1(ct,hEle);
	XP_Set2(ct,length);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSBar_SetSliderMinLength(HWINDOW hWindow,HELE hEle,int minLength)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_SetSliderMinLength);
	XP_Set1(ct,hEle);
	XP_Set2(ct,minLength);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSBar_SetSliderPadding(HWINDOW hWindow,HELE hEle,int nPadding)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_SetSliderPadding);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nPadding);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXSBar_SetHorizon(HWINDOW hWindow,HELE hEle,BOOL bHorizon)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_SetHorizon);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bHorizon);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXSBar_GetSliderMaxLength(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_GetSliderMaxLength);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXSBar_ScrollUp(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_ScrollUp);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSBar_ScrollDown(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_ScrollDown);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSBar_ScrollTop(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_ScrollTop);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSBar_ScrollBottom(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_ScrollBottom);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSBar_ScrollPos(HWINDOW hWindow,HELE hEle,int pos)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_ScrollPos);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pos);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXSBar_GetButtonUp(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_GetButtonUp);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXSBar_GetButtonDown(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_GetButtonDown);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXSBar_GetButtonSlider(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSBar_GetButtonSlider);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXSView_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

BOOL WINAPI SXSView_SetTotalSize(HWINDOW hWindow,HELE hEle,int cx,int cy)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_SetTotalSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,cx);
	XP_Set3(ct,cy);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXSView_GetTotalSize(HWINDOW hWindow,HELE hEle,SIZE * pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetTotalSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXSView_SetLineSize(HWINDOW hWindow,HELE hEle,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_SetLineSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nWidth);
	XP_Set3(ct,nHeight);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXSView_GetLineSize(HWINDOW hWindow,HELE hEle,out_ SIZE * pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetLineSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSView_SetScrollBarSize(HWINDOW hWindow,HELE hEle,int size)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_SetScrollBarSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,size);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXSView_GetViewPosH(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetViewPosH);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXSView_GetViewPosV(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetViewPosV);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXSView_GetViewWidth(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetViewWidth);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXSView_GetViewHeight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetViewHeight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXSView_GetViewRect(HWINDOW hWindow,HELE hEle,out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetViewRect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXSView_GetScrollBarH(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetScrollBarH);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXSView_GetScrollBarV(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetScrollBarV);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXSView_SetBorderSize(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_SetBorderSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,left);
	XP_Set3(ct,top);
	XP_Set4(ct,right);
	XP_Set5(ct,bottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSView_GetBorderSize(HWINDOW hWindow,HELE hEle,out_ BorderSize_i* pBorder)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_GetBorderSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pBorder);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXSView_ScrollPosH(HWINDOW hWindow,HELE hEle,int pos)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollPosH);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pos);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollPosV(HWINDOW hWindow,HELE hEle,int pos)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollPosV);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pos);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollPosXH(HWINDOW hWindow,HELE hEle,int posX)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollPosXH);
	XP_Set1(ct,hEle);
	XP_Set2(ct,posX);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollPosYV(HWINDOW hWindow,HELE hEle,int posY)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollPosYV);
	XP_Set1(ct,hEle);
	XP_Set2(ct,posY);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXSView_ShowSBarH(HWINDOW hWindow,HELE hEle,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ShowSBarH);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSView_ShowSBarV(HWINDOW hWindow,HELE hEle,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ShowSBarV);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSView_EnableAutoShowScrollBar(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_EnableAutoShowScrollBar);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXSView_ScrollLeftLine(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollLeftLine);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollRightLine(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollRightLine);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollTopLine(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollTopLine);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollBottomLine(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollBottomLine);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollLeft(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollLeft);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollRight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollRight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollTop(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollTop);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXSView_ScrollBottom(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSView_ScrollBottom);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXShape_GetParentEle(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetParentEle);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HXCGUI WINAPI SXShape_GetParentLayout(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetParentLayout);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

HWINDOW WINAPI SXShape_GetHWINDOW(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetHWINDOW);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

HXCGUI WINAPI SXShape_GetParent(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetParent);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShape_RemoveShape(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_RemoveShape);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShape_SetID(HWINDOW hWindow,HXCGUI hShape,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_SetID);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXShape_GetID(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetID);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXShape_SetUID(HWINDOW hWindow,HXCGUI hShape,int nUID)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_SetUID);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nUID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXShape_GetUID(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetUID);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXShape_Redraw(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_Redraw);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXShape_GetWidth(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetWidth);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXShape_GetHeight(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetHeight);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXShape_GetRect(HWINDOW hWindow,HXCGUI hShape,out_ RECT* pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetRect);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShape_SetRect(HWINDOW hWindow,HXCGUI hShape,in_  RECT* pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_SetRect);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShape_GetContentSize(HWINDOW hWindow,HXCGUI hShape,out_ SIZE* pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_GetContentSize);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShape_ShowLayout(HWINDOW hWindow,HXCGUI hShape,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_ShowLayout);
	XP_Set1(ct,hShape);
	XP_Set2(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShape_AdjustLayout(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_AdjustLayout);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShape_Destroy(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XShape_Destroy);
	XP_Set1(ct,hShape);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXShapeText_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pName,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,pName);
	XP_Set6(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShapeText_SetText(HWINDOW hWindow,HXCGUI hTextBlock,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetText);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_GetText(HWINDOW hWindow,HXCGUI hTextBlock,out_ wchar_t * pOut,int nOutLen)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_GetText);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,pOut);
	XP_Set3(ct,nOutLen);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXShapeText_GetTextLength(HWINDOW hWindow,HXCGUI hTextBlock)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_GetTextLength);
	XP_Set1(ct,hTextBlock);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXShapeText_SetFont(HWINDOW hWindow,HXCGUI hTextBlock,HFONTX hFontx)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetFont);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,hFontx);
	XP_CALL(hWindow,ct);
	
}

HFONTX WINAPI SXShapeText_GetFont(HWINDOW hWindow,HXCGUI hTextBlock)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_GetFont);
	XP_Set1(ct,hTextBlock);
	XP_CALL(hWindow,ct);
	return (HFONTX)XP_GetRet(ct);
}

void WINAPI SXShapeText_SetTextColor(HWINDOW hWindow,HXCGUI hTextBlock,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetTextColor);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

COLORREF WINAPI SXShapeText_GetTextColor(HWINDOW hWindow,HXCGUI hTextBlock)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_GetTextColor);
	XP_Set1(ct,hTextBlock);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

void WINAPI SXShapeText_SetTextAlign(HWINDOW hWindow,HXCGUI hTextBlock,int align)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetTextAlign);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,align);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_SetOffset(HWINDOW hWindow,HXCGUI hTextBlock,int x,int y)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetOffset);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_SetLayoutWidth(HWINDOW hWindow,HXCGUI hTextBlock,layout_size_type_ nType,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetLayoutWidth);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,nType);
	XP_Set3(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_SetLayoutHeight(HWINDOW hWindow,HXCGUI hTextBlock,layout_size_type_ nType,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetLayoutHeight);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,nType);
	XP_Set3(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_GetLayoutWidth(HWINDOW hWindow,HXCGUI hTextBlock,out_ layout_size_type_ * pType,out_ int * pWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_GetLayoutWidth);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,pType);
	XP_Set3(ct,pWidth);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_GetLayoutHeight(HWINDOW hWindow,HXCGUI hTextBlock,out_ layout_size_type_ * pType,out_ int * pHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_GetLayoutHeight);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,pType);
	XP_Set3(ct,pHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_EnableCSS(HWINDOW hWindow,HXCGUI hTextBlock,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_EnableCSS);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeText_SetCssName(HWINDOW hWindow,HXCGUI hTextBlock,const wchar_t* pName)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_SetCssName);
	XP_Set1(ct,hTextBlock);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	
}

const wchar_t* WINAPI SXShapeText_GetCssName(HWINDOW hWindow,HXCGUI hTextBlock)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeText_GetCssName);
	XP_Set1(ct,hTextBlock);
	XP_CALL(hWindow,ct);
	return (const wchar_t*)XP_GetRet(ct);
}

HXCGUI WINAPI SXShapePic_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XShapePic_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShapePic_SetImage(HWINDOW hWindow,HXCGUI hShape,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XShapePic_SetImage);
	XP_Set1(ct,hShape);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapePic_SetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XShapePic_SetLayoutWidth);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nType);
	XP_Set3(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapePic_SetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XShapePic_SetLayoutHeight);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nType);
	XP_Set3(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapePic_GetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XShapePic_GetLayoutWidth);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pType);
	XP_Set3(ct,pWidth);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapePic_GetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XShapePic_GetLayoutHeight);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pType);
	XP_Set3(ct,pHeight);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXShapeGif_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGif_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShapeGif_SetImage(HWINDOW hWindow,HXCGUI hShape,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGif_SetImage);
	XP_Set1(ct,hShape);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGif_SetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGif_SetLayoutWidth);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nType);
	XP_Set3(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGif_SetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGif_SetLayoutHeight);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nType);
	XP_Set3(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGif_GetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGif_GetLayoutWidth);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pType);
	XP_Set3(ct,pWidth);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGif_GetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGif_GetLayoutHeight);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pType);
	XP_Set3(ct,pHeight);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXShapeRect_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShapeRect_SetBorderColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_SetBorderColor);
	XP_Set1(ct,hShape);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeRect_SetFillColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_SetFillColor);
	XP_Set1(ct,hShape);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeRect_SetRoundAngle(HWINDOW hWindow,HXCGUI hShape,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_SetRoundAngle);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nWidth);
	XP_Set3(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeRect_GetRoundAngle(HWINDOW hWindow,HXCGUI hShape,out_ int * pWidth,out_ int * pHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_GetRoundAngle);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pWidth);
	XP_Set3(ct,pHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeRect_EnableBorder(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_EnableBorder);
	XP_Set1(ct,hShape);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeRect_EnableFill(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_EnableFill);
	XP_Set1(ct,hShape);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeRect_EnableRoundAngle(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeRect_EnableRoundAngle);
	XP_Set1(ct,hShape);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXShapeEllipse_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeEllipse_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShapeEllipse_SetBorderColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeEllipse_SetBorderColor);
	XP_Set1(ct,hShape);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeEllipse_SetFillColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeEllipse_SetFillColor);
	XP_Set1(ct,hShape);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeEllipse_EnableBorder(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeEllipse_EnableBorder);
	XP_Set1(ct,hShape);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeEllipse_EnableFill(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeEllipse_EnableFill);
	XP_Set1(ct,hShape);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXShapeGroupBox_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t* pName,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,pName);
	XP_Set6(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShapeGroupBox_SetBorderColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_SetBorderColor);
	XP_Set1(ct,hShape);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_SetTextColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_SetTextColor);
	XP_Set1(ct,hShape);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_SetFontX(HWINDOW hWindow,HXCGUI hShape,HFONTX hFontX)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_SetFontX);
	XP_Set1(ct,hShape);
	XP_Set2(ct,hFontX);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_SetTextOffset(HWINDOW hWindow,HXCGUI hShape,int offsetX,int offsetY)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_SetTextOffset);
	XP_Set1(ct,hShape);
	XP_Set2(ct,offsetX);
	XP_Set3(ct,offsetY);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_SetRoundAngle(HWINDOW hWindow,HXCGUI hShape,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_SetRoundAngle);
	XP_Set1(ct,hShape);
	XP_Set2(ct,nWidth);
	XP_Set3(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_SetText(HWINDOW hWindow,HXCGUI hShape,const wchar_t* pText)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_SetText);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pText);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_GetTextOffset(HWINDOW hWindow,HXCGUI hShape,out_ int * pOffsetX,out_ int * pOffsetY)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_GetTextOffset);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pOffsetX);
	XP_Set3(ct,pOffsetY);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_GetRoundAngle(HWINDOW hWindow,HXCGUI hShape,out_ int * pWidth,out_ int * pHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_GetRoundAngle);
	XP_Set1(ct,hShape);
	XP_Set2(ct,pWidth);
	XP_Set3(ct,pHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeGroupBox_EnableRoundAngle(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeGroupBox_EnableRoundAngle);
	XP_Set1(ct,hShape);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXShapeLine_Create(HWINDOW hWindow,int x1,int y1,int x2,int y2,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeLine_Create);
	XP_Set1(ct,x1);
	XP_Set2(ct,y1);
	XP_Set3(ct,x2);
	XP_Set4(ct,y2);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXShapeLine_SetPosition(HWINDOW hWindow,HXCGUI hShape,int x1,int y1,int x2,int y2)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeLine_SetPosition);
	XP_Set1(ct,hShape);
	XP_Set2(ct,x1);
	XP_Set3(ct,y1);
	XP_Set4(ct,x2);
	XP_Set5(ct,y2);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXShapeLine_SetColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XShapeLine_SetColor);
	XP_Set1(ct,hShape);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXSliderBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXSliderBar_SetRange(HWINDOW hWindow,HELE hEle,int range)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_SetRange);
	XP_Set1(ct,hEle);
	XP_Set2(ct,range);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXSliderBar_GetRange(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_GetRange);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXSliderBar_SetButtonWidth(HWINDOW hWindow,HELE hEle,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_SetButtonWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSliderBar_SetButtonHeight(HWINDOW hWindow,HELE hEle,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_SetButtonHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSliderBar_SetSpaceTwo(HWINDOW hWindow,HELE hEle,int leftSize,int rightSize)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_SetSpaceTwo);
	XP_Set1(ct,hEle);
	XP_Set2(ct,leftSize);
	XP_Set3(ct,rightSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSliderBar_SetPos(HWINDOW hWindow,HELE hEle,int pos)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_SetPos);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pos);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXSliderBar_GetPos(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_GetPos);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HELE WINAPI SXSliderBar_GetButton(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_GetButton);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXSliderBar_SetHorizon(HWINDOW hWindow,HELE hEle,BOOL bHorizon)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_SetHorizon);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bHorizon);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXSliderBar_SetImageLoad(HWINDOW hWindow,HELE hEle,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XSliderBar_SetImageLoad);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXTabBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXTabBar_AddLabel(HWINDOW hWindow,HELE hEle,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_AddLabel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTabBar_InsertLabel(HWINDOW hWindow,HELE hEle,int index,wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_InsertLabel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_Set3(ct,pName);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXTabBar_DeleteLabel(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_DeleteLabel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXTabBar_DeleteLabelAll(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_DeleteLabelAll);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXTabBar_GetLabel(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetLabel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXTabBar_GetLabelClose(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetLabelClose);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXTabBar_GetButtonLeft(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetButtonLeft);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXTabBar_GetButtonRight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetButtonRight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXTabBar_GetSelect(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetSelect);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTabBar_GetLabelSpacing(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetLabelSpacing);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTabBar_GetLabelCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetLabelCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTabBar_GetindexByEle(HWINDOW hWindow,HELE hEle,HELE hLabel)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_GetindexByEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hLabel);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXTabBar_SetLabelSpacing(HWINDOW hWindow,HELE hEle,int spacing)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetLabelSpacing);
	XP_Set1(ct,hEle);
	XP_Set2(ct,spacing);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_SetPadding(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetPadding);
	XP_Set1(ct,hEle);
	XP_Set2(ct,left);
	XP_Set3(ct,top);
	XP_Set4(ct,right);
	XP_Set5(ct,bottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_SetSelect(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetSelect);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_SetUp(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetUp);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_SetDown(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetDown);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_EnableTile(HWINDOW hWindow,HELE hEle,BOOL bTile)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_EnableTile);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bTile);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_EnableClose(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_EnableClose);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_SetCloseSize(HWINDOW hWindow,HELE hEle,SIZE * pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetCloseSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_SetTurnButtonSize(HWINDOW hWindow,HELE hEle,SIZE * pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetTurnButtonSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTabBar_SetLabelWidth(HWINDOW hWindow,HELE hEle,int index,int nWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_SetLabelWidth);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_Set3(ct,nWidth);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXTabBar_ShowLabel(HWINDOW hWindow,HELE hEle,int index,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XTabBar_ShowLabel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_Set3(ct,bShow);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXTextLink_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t* pName,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XTextLink_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,pName);
	XP_Set6(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXTextLink_EnableUnderlineLeave(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XTextLink_EnableUnderlineLeave);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTextLink_EnableUnderlineStay(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XTextLink_EnableUnderlineStay);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTextLink_SetTextColorStay(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XTextLink_SetTextColorStay);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTextLink_SetUnderlineColorLeave(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XTextLink_SetUnderlineColorLeave);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTextLink_SetUnderlineColorStay(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XTextLink_SetUnderlineColorStay);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXToolBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXToolBar_InsertEle(HWINDOW hWindow,HELE hEle,HELE hNewEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_InsertEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hNewEle);
	XP_Set3(ct,index);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXToolBar_InsertSeparator(HWINDOW hWindow,HELE hEle,int index,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_InsertSeparator);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_Set3(ct,color);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXToolBar_EnableButtonMenu(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_EnableButtonMenu);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXToolBar_GetHEle(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_GetHEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXToolBar_GetButtonLeft(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_GetButtonLeft);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXToolBar_GetButtonRight(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_GetButtonRight);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXToolBar_GetButtonMenu(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_GetButtonMenu);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXToolBar_SetSpace(HWINDOW hWindow,HELE hEle,int nSize)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_SetSpace);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXToolBar_DeleteEle(HWINDOW hWindow,HELE hEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_DeleteEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXToolBar_DeleteAllEle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XToolBar_DeleteAllEle);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXTree_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,hParent);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXTree_EnableDragItem(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_EnableDragItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_EnableConnectLine(HWINDOW hWindow,HELE hEle,BOOL bEnable,BOOL bSolid)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_EnableConnectLine);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_Set3(ct,bSolid);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_EnableExpand(HWINDOW hWindow,HELE hEle,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_EnableExpand);
	XP_Set1(ct,hEle);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_SetConnectLineColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetConnectLineColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_SetExpandButtonSize(HWINDOW hWindow,HELE hEle,int nWidth,int nHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetExpandButtonSize);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nWidth);
	XP_Set3(ct,nHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_SetConnectLineLength(HWINDOW hWindow,HELE hEle,int nLength)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetConnectLineLength);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nLength);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_SetDragInsertPositionColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetDragInsertPositionColor);
	XP_Set1(ct,hEle);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXTree_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetItemTemplateXML);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pXmlFile);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXTree_SetItemTemplateXMLSel(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetItemTemplateXMLSel);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pXmlFile);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXTree_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetItemTemplateXMLFromString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pStringXML);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXTree_SetItemTemplateXMLSelFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetItemTemplateXMLSelFromString);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pStringXML);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXTree_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetDrawItemBkFlags);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nFlags);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXTree_SetItemData(HWINDOW hWindow,HELE hEle,int nID,int nUserData)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_Set3(ct,nUserData);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXTree_GetItemData(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetItemData);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXTree_SetSelectItem(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetSelectItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXTree_GetSelectItem(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetSelectItem);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXTree_IsExpand(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_IsExpand);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXTree_ExpandItem(HWINDOW hWindow,HELE hEle,int nID,BOOL bExpand)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_ExpandItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_Set3(ct,bExpand);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXTree_ExpandAllChildItem(HWINDOW hWindow,HELE hEle,int nID,BOOL bExpand)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_ExpandAllChildItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_Set3(ct,bExpand);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

int WINAPI SXTree_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_HitTest);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTree_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_HitTestOffset);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTree_GetFirstChildItem(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetFirstChildItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTree_GetEndChildItem(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetEndChildItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTree_GetPrevSiblingItem(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetPrevSiblingItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTree_GetNextSiblingItem(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetNextSiblingItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

int WINAPI SXTree_GetParentItem(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetParentItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXTree_SetIndentation(HWINDOW hWindow,HELE hEle,int nWidth)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetIndentation);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nWidth);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXTree_GetIndentation(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetIndentation);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXTree_SetItemHeight(HWINDOW hWindow,HELE hEle,int nID,int nHeight,int nSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetItemHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_Set3(ct,nHeight);
	XP_Set4(ct,nSelHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_GetItemHeight(HWINDOW hWindow,HELE hEle,int nID,out_ int * pHeight,out_ int * pSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetItemHeight);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_Set3(ct,pHeight);
	XP_Set4(ct,pSelHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_SetRowSpace(HWINDOW hWindow,HELE hEle,int nSpace)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetRowSpace);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nSpace);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXTree_GetRowSpace(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetRowSpace);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

BOOL WINAPI SXTree_MoveItem(HWINDOW hWindow,HELE hEle,int nMoveItem,int nDestItem,int nType)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_MoveItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nMoveItem);
	XP_Set3(ct,nDestItem);
	XP_Set4(ct,nType);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXTree_AddItemBkBorder(HWINDOW hWindow,HELE hEle,tree_item_state_ nState,COLORREF color,BYTE alpha,int width)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_AddItemBkBorder);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_Set5(ct,width);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_AddItemBkFill(HWINDOW hWindow,HELE hEle,tree_item_state_ nState,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_AddItemBkFill);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,color);
	XP_Set4(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_AddItemBkImage(HWINDOW hWindow,HELE hEle,tree_item_state_ nState,HIMAGE hImage)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_AddItemBkImage);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nState);
	XP_Set3(ct,hImage);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXTree_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetItemBkInfoCount);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXTree_ClearItemBkInfo(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_ClearItemBkInfo);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_SetItemHeightDefault(HWINDOW hWindow,HELE hEle,int nHeight,int nSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_SetItemHeightDefault);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nHeight);
	XP_Set3(ct,nSelHeight);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_GetItemHeightDefault(HWINDOW hWindow,HELE hEle,out_ int * pHeight,out_ int * pSelHeight)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetItemHeightDefault);
	XP_Set1(ct,hEle);
	XP_Set2(ct,pHeight);
	XP_Set3(ct,pSelHeight);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXTree_GetTemplateObject(HWINDOW hWindow,HELE hEle,int nID,int nTempItemID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetTemplateObject);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_Set3(ct,nTempItemID);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

int WINAPI SXTree_GetItemIDFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetItemIDFromHXCGUI);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hXCGUI);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HXCGUI WINAPI SXTree_CreateAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_CreateAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXTree_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_BindAdapter);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hAdapter);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXTree_GetAdapter(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_GetAdapter);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXTree_RefreshData(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_RefreshData);
	XP_Set1(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXTree_RefreshItem(HWINDOW hWindow,HELE hEle,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XTree_RefreshItem);
	XP_Set1(ct,hEle);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI S_XWnd_RegEvent(HWINDOW hWindow,UINT nEvent,xc_event* pEvent)
{
	XP_Init();
	XP_SetType(ct,ft__XWnd_RegEvent);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pEvent);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI S_XWnd_RemoveEvent(HWINDOW hWindow,UINT nEvent,xc_event* pEvent)
{
	XP_Init();
	XP_SetType(ct,ft__XWnd_RemoveEvent);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pEvent);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_RegEventC(HWINDOW hWindow,int nEvent,void * pFun)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_RegEventC);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pFun);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_RegEventC1(HWINDOW hWindow,int nEvent,void * pFun)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_RegEventC1);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pFun);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_RemoveEventC(HWINDOW hWindow,int nEvent,void * pFun)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_RemoveEventC);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nEvent);
	XP_Set3(ct,pFun);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HWINDOW WINAPI SXWnd_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pTitle,HWND hWndParent,int XCStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_Create);
	XP_Set1(ct,x);
	XP_Set2(ct,y);
	XP_Set3(ct,cx);
	XP_Set4(ct,cy);
	XP_Set5(ct,pTitle);
	XP_Set6(ct,hWndParent);
	XP_Set7(ct,XCStyle);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

HWINDOW WINAPI SXWnd_CreateEx(HWINDOW hWindow,DWORD dwExStyle,const wchar_t* lpClassName,const wchar_t* lpWindowName,DWORD dwStyle,int x,int y,int cx,int cy,HWND hWndParent,int XCStyle)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_CreateEx);
	XP_Set1(ct,dwExStyle);
	XP_Set2(ct,lpClassName);
	XP_Set3(ct,lpWindowName);
	XP_Set4(ct,dwStyle);
	XP_Set5(ct,x);
	XP_Set6(ct,y);
	XP_Set7(ct,cx);
	XP_Set8(ct,cy);
	XP_Set9(ct,hWndParent);
	XP_Set10(ct,XCStyle);
	XP_CALL(hWindow,ct);
	return (HWINDOW)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_AddEle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_AddEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_InsertEle(HWINDOW hWindow,HELE hChildEle,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_InsertEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hChildEle);
	XP_Set3(ct,index);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_AddShape(HWINDOW hWindow,HXCGUI hShape)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_AddShape);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hShape);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HWND WINAPI SXWnd_GetHWND(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetHWND);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HWND)XP_GetRet(ct);
}

void WINAPI SXWnd_EnableDragBorder(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_EnableDragBorder);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_EnableDragWindow(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_EnableDragWindow);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_EnableDragCaption(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_EnableDragCaption);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_EnableDrawBk(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_EnableDrawBk);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_EnableAutoFocus(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_EnableAutoFocus);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_EnableMaxWindow(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_EnableMaxWindow);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_RedrawWnd(HWINDOW hWindow,BOOL bImmediate)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_RedrawWnd);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bImmediate);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_RedrawWndRect(HWINDOW hWindow,RECT * pRect,BOOL bImmediate)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_RedrawWndRect);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pRect);
	XP_Set3(ct,bImmediate);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetFocusEle(HWINDOW hWindow,HELE hFocusEle)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetFocusEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hFocusEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXWnd_GetFocusEle(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetFocusEle);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXWnd_GetStayHELE(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetStayHELE);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXWnd_DrawWindow(HWINDOW hWindow,HDRAW hDraw)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_DrawWindow);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hDraw);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetCursor(HWINDOW hWindow,HCURSOR hCursor)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCursor);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hCursor);
	XP_CALL(hWindow,ct);
	
}

HCURSOR WINAPI SXWnd_GetCursor(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetCursor);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HCURSOR)XP_GetRet(ct);
}

HCURSOR WINAPI SXWnd_SetCursorSys(HWINDOW hWindow,HCURSOR hCursor)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCursorSys);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hCursor);
	XP_CALL(hWindow,ct);
	return (HCURSOR)XP_GetRet(ct);
}

void WINAPI SXWnd_SetFont(HWINDOW hWindow,HFONTX hFontx)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetFont);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hFontx);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetTextColor(HWINDOW hWindow,COLORREF color,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetTextColor);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,color);
	XP_Set3(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

COLORREF WINAPI SXWnd_GetTextColor(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetTextColor);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (COLORREF)XP_GetRet(ct);
}

void WINAPI SXWnd_SetID(HWINDOW hWindow,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetID);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	
}

int WINAPI SXWnd_GetID(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetID);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

void WINAPI SXWnd_SetCaptureEle(HWINDOW hWindow,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCaptureEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hEle);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXWnd_GetCaptureEle(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetCaptureEle);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_BindLayoutEle(HWINDOW hWindow,window_position_ nPosition,HELE hEle)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_BindLayoutEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nPosition);
	XP_Set3(ct,hEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HELE WINAPI SXWnd_GetLayoutEle(HWINDOW hWindow,window_position_ nPosition)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetLayoutEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nPosition);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

void WINAPI SXWnd_BindLayoutObject(HWINDOW hWindow,window_position_ nPosition,HXCGUI hLayout)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_BindLayoutObject);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nPosition);
	XP_Set3(ct,hLayout);
	XP_CALL(hWindow,ct);
	
}

HXCGUI WINAPI SXWnd_GetLayoutObject(HWINDOW hWindow,window_position_ nPosition)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetLayoutObject);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nPosition);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXWnd_SetLayoutSize(HWINDOW hWindow,int left,int top,int right,int bottom)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetLayoutSize);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,left);
	XP_Set3(ct,top);
	XP_Set4(ct,right);
	XP_Set5(ct,bottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_GetLayoutSize(HWINDOW hWindow,out_ BorderSize_i  * pBorderSize)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetLayoutSize);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pBorderSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetDragBorderSize(HWINDOW hWindow,int left,int top,int right,int bottom)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetDragBorderSize);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,left);
	XP_Set3(ct,top);
	XP_Set4(ct,right);
	XP_Set5(ct,bottom);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_GetDragBorderSize(HWINDOW hWindow,out_ BorderSize_i* pSize)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetDragBorderSize);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pSize);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetMinimumSize(HWINDOW hWindow,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetMinimumSize);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,width);
	XP_Set3(ct,height);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXWnd_HitChildEle(HWINDOW hWindow,POINT * pPt)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_HitChildEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pPt);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXWnd_GetChildCount(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetChildCount);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HELE WINAPI SXWnd_GetChildByIndex(HWINDOW hWindow,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetChildByIndex);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXWnd_GetChildByID(HWINDOW hWindow,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetChildByID);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

HELE WINAPI SXWnd_GetEle(HWINDOW hWindow,int nID)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetEle);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nID);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

int WINAPI SXWnd_GetChildShapeCount(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetChildShapeCount);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (int)XP_GetRet(ct);
}

HXCGUI WINAPI SXWnd_GetChildShapeByIndex(HWINDOW hWindow,int index)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetChildShapeByIndex);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,index);
	XP_CALL(hWindow,ct);
	return (HXCGUI)XP_GetRet(ct);
}

void WINAPI SXWnd_GetDrawRect(HWINDOW hWindow,RECT * pRcPaint)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetDrawRect);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pRcPaint);
	XP_CALL(hWindow,ct);
	
}

BOOL WINAPI SXWnd_ShowWindow(HWINDOW hWindow,int nCmdShow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_ShowWindow);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nCmdShow);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXWnd_AdjustLayout(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_AdjustLayout);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_AdjustLayoutObject(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_AdjustLayoutObject);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_CloseWindow(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_CloseWindow);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_CreateCaret(HWINDOW hWindow,HELE hEle,int x,int y,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_CreateCaret);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,hEle);
	XP_Set3(ct,x);
	XP_Set4(ct,y);
	XP_Set5(ct,width);
	XP_Set6(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetCaretSize(HWINDOW hWindow,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCaretSize);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,width);
	XP_Set3(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetCaretPos(HWINDOW hWindow,int x,int y)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCaretPos);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetCaretPosEx(HWINDOW hWindow,int x,int y,int width,int height)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCaretPosEx);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,x);
	XP_Set3(ct,y);
	XP_Set4(ct,width);
	XP_Set5(ct,height);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetCaretColor(HWINDOW hWindow,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCaretColor);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,color);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_ShowCaret(HWINDOW hWindow,BOOL bShow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_ShowCaret);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bShow);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_DestroyCaret(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_DestroyCaret);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	
}

HELE WINAPI SXWnd_GetCaretHELE(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetCaretHELE);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HELE)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_GetClientRect(HWINDOW hWindow,out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetClientRect);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXWnd_GetBodyRect(HWINDOW hWindow,out_ RECT * pRect)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetBodyRect);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pRect);
	XP_CALL(hWindow,ct);
	
}

UINT WINAPI SXWnd_SetTimer(HWINDOW hWindow,UINT nIDEvent,UINT uElapse)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetTimer);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nIDEvent);
	XP_Set3(ct,uElapse);
	XP_CALL(hWindow,ct);
	return (UINT)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_KillTimer(HWINDOW hWindow,UINT nIDEvent)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_KillTimer);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nIDEvent);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_SetXCTimer(HWINDOW hWindow,UINT nIDEvent,UINT uElapse)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetXCTimer);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nIDEvent);
	XP_Set3(ct,uElapse);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

BOOL WINAPI SXWnd_KillXCTimer(HWINDOW hWindow,UINT nIDEvent)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_KillXCTimer);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nIDEvent);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

HBKM WINAPI SXWnd_GetBkManager(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetBkManager);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (HBKM)XP_GetRet(ct);
}

void WINAPI SXWnd_SetTransparentType(HWINDOW hWindow,window_transparent_ nType)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetTransparentType);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nType);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetTransparentAlpha(HWINDOW hWindow,BYTE alpha)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetTransparentAlpha);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,alpha);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetTransparentColor(HWINDOW hWindow,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetTransparentColor);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,color);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetShadowInfo(HWINDOW hWindow,int nSize,int nDepth,int nAngeleSize,BOOL bRightAngle,COLORREF color)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetShadowInfo);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,nSize);
	XP_Set3(ct,nDepth);
	XP_Set4(ct,nAngeleSize);
	XP_Set5(ct,bRightAngle);
	XP_Set6(ct,color);
	XP_CALL(hWindow,ct);
	
}

window_transparent_ WINAPI SXWnd_GetTransparentType(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetTransparentType);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (window_transparent_)XP_GetRet(ct);
}

void WINAPI SXWnd_EnableCSS(HWINDOW hWindow,BOOL bEnable)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_EnableCSS);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,bEnable);
	XP_CALL(hWindow,ct);
	
}

void WINAPI SXWnd_SetCssName(HWINDOW hWindow,const wchar_t * pName)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_SetCssName);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pName);
	XP_CALL(hWindow,ct);
	
}

const wchar_t* WINAPI SXWnd_GetCssName(HWINDOW hWindow)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetCssName);
	XP_Set1(ct,hWindow);
	XP_CALL(hWindow,ct);
	return (const wchar_t*)XP_GetRet(ct);
}

// BOOL WINAPI SXWnd_RegEventTest(int nEvent,BYTE* pParamType)
// {
// XP_Init();
// XP_SetType(ct,ft_XWnd_RegEventTest);
// XP_Set1(ct,nEvent);
// XP_Set2(ct,pParamType);
// XP_CALL(hWindow,ct);
// return (BOOL)XP_GetRet(ct);
// }

BOOL WINAPI SXEle_IsChildEle(HWINDOW hWindow,HELE hEle,HELE hChildEle)
{
	XP_Init();
	XP_SetType(ct,ft_XEle_IsChildEle);
	XP_Set1(ct,hEle);
	XP_Set2(ct,hChildEle);
	XP_CALL(hWindow,ct);
	return (BOOL)XP_GetRet(ct);
}

void WINAPI SXWnd_GetShadowInfo(HWINDOW hWindow,int * pnSize,int * pnDepth,int * pnAngeleSize,BOOL * pbRightAngle,COLORREF * pColor)
{
	XP_Init();
	XP_SetType(ct,ft_XWnd_GetShadowInfo);
	XP_Set1(ct,hWindow);
	XP_Set2(ct,pnSize);
	XP_Set3(ct,pnDepth);
	XP_Set4(ct,pnAngeleSize);
	XP_Set5(ct,pbRightAngle);
	XP_Set6(ct,pColor);
	XP_CALL(hWindow,ct);
	
}


int CALLBACK OnWndProc(UINT message, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
{
	if (message != XWM_CONTROL)
		return 0;
	
	if ((int)lParam != sizeof(XCONTROL))
		return 0;
	
	PXCONTROL pControl = (PXCONTROL)wParam;
	int ret = 0;
	switch (pControl->nType)
	{
		
	case ft_XDateTime_Create:
		ret = (int)XDateTime_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XDateTime_SetStyle:
		XDateTime_SetStyle((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XDateTime_GetStyle:
		ret = (int)XDateTime_GetStyle((HELE)pControl->p1);
		break;
	case ft_XDateTime_EnableSplitSlash:
		XDateTime_EnableSplitSlash((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XDateTime_GetTime:
		XDateTime_GetTime((HELE)pControl->p1,(int*)pControl->p2,(int*)pControl->p3,(int*)pControl->p4);
		break;
	case ft_XDateTime_SetTime:
		XDateTime_SetTime((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XDateTime_GetDate:
		XDateTime_GetDate((HELE)pControl->p1,(int*)pControl->p2,(int*)pControl->p3,(int*)pControl->p4);
		break;
	case ft_XDateTime_SetDate:
		XDateTime_SetDate((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XDateTime_GetSelBkColor:
		ret = (int)XDateTime_GetSelBkColor((HELE)pControl->p1);
		break;
	case ft_XDateTime_SetSelBkColor:
		XDateTime_SetSelBkColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XDateTime_GetButton:
		ret = (int)XDateTime_GetButton((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XMonthCal_Create:
		ret = (int)XMonthCal_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XMonthCal_SetToday:
		XMonthCal_SetToday((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XMonthCal_GetToday:
		XMonthCal_GetToday((HELE)pControl->p1,(int*)pControl->p2,(int*)pControl->p3,(int*)pControl->p4);
		break;
	case ft_XMonthCal_SeSelDate:
		XMonthCal_SeSelDate((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XMonthCal_GetSelDate:
		XMonthCal_GetSelDate((HELE)pControl->p1,(int*)pControl->p2,(int*)pControl->p3,(int*)pControl->p4);
		break;
	case ft_XMonthCal_GetButton:
		ret = (int)XMonthCal_GetButton((HELE)pControl->p1,(monthCal_button_type_)pControl->p2);
		break;
	case ft_XC_InitLua:
		ret = (int)XC_InitLua();
		break;
	case ft_XC_RunLua:
		ret = (int)XC_RunLua((const char*)pControl->p1);
		break;
	case ft_XC_ExitLua:
		ret = (int)XC_ExitLua();
		break;
	case ft_XC_UnicodeToAnsi:
		ret = (int)XC_UnicodeToAnsi((const wchar_t *)pControl->p1,(int)pControl->p2,(char *)pControl->p3,(int)pControl->p4);
		break;
	case ft_XC_AnsiToUnicode:
		ret = (int)XC_AnsiToUnicode((const char *)pControl->p1,(int)pControl->p2,(wchar_t *)pControl->p3,(int)pControl->p4);
		break;
	case ft_XC_DebugToFileInfo:
		XC_DebugToFileInfo((const char *)pControl->p1);
		break;
	case ft_XC_IsHELE:
		ret = (int)XC_IsHELE((HXCGUI)pControl->p1);
		break;
	case ft_XC_IsHWINDOW:
		ret = (int)XC_IsHWINDOW((HXCGUI)pControl->p1);
		break;
	case ft_XC_IsShape:
		ret = (int)XC_IsShape((HXCGUI)pControl->p1);
		break;
	case ft_XC_IsHXCGUI:
		ret = (int)XC_IsHXCGUI((HXCGUI)pControl->p1,(XC_OBJECT_TYPE)pControl->p2);
		break;
	case ft_XC_hWindowFromHWnd:
		ret = (int)XC_hWindowFromHWnd((HWND)pControl->p1);
		break;
	case ft_XC_SetProperty:
		ret = (int)XC_SetProperty((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XC_GetProperty:
		ret = (int)XC_GetProperty((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XC_RegisterWindowClassName:
		ret = (int)XC_RegisterWindowClassName((const wchar_t*)pControl->p1);
		break;
	case ft_XC_IsSViewExtend:
		ret = (int)XC_IsSViewExtend((HELE)pControl->p1);
		break;
	case ft_XC_GetObjectType:
		ret = (int)XC_GetObjectType((HXCGUI)pControl->p1);
		break;
	case ft_XC_GetObjectByID:
		ret = (int)XC_GetObjectByID((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XC_GetObjectByIDName:
		ret = (int)XC_GetObjectByIDName((HWINDOW)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XC_GetObjectByUID:
		ret = (int)XC_GetObjectByUID((int)pControl->p1);
		break;
	case ft_XC_GetObjectByUIDName:
		ret = (int)XC_GetObjectByUIDName((const wchar_t*)pControl->p1);
		break;
	case ft_XRes_GetIDValue:
		ret = (int)XRes_GetIDValue((const wchar_t *)pControl->p1);
		break;
	case ft_XRes_GetImage:
		ret = (int)XRes_GetImage((const wchar_t *)pControl->p1);
		break;
	case ft_XRes_GetImageEx:
		ret = (int)XRes_GetImageEx((const wchar_t *)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XRes_GetColor:
		ret = (int)XRes_GetColor((const wchar_t *)pControl->p1);
		break;
	case ft_XRes_GetFont:
		ret = (int)XRes_GetFont((const wchar_t *)pControl->p1);
		break;
	case ft_XRes_GetBkM:
		ret = (int)XRes_GetBkM((const wchar_t *)pControl->p1);
		break;
	case ft_XC_SetPaintFrequency:
		XC_SetPaintFrequency((int)pControl->p1);
		break;
	case ft_XC_SetTextRenderingHint:
		XC_SetTextRenderingHint((int)pControl->p1);
		break;
	case ft_XC_RectInRect:
		ret = (int)XC_RectInRect((RECT *)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XC_CombineRect:
		XC_CombineRect((RECT *)pControl->p1,(RECT *)pControl->p2,(RECT *)pControl->p3);
		break;
	case ft_XC_ShowLayoutFrame:
		XC_ShowLayoutFrame((BOOL)pControl->p1);
		break;
	case ft_XC_EnableDebugFile:
		XC_EnableDebugFile((BOOL)pControl->p1);
		break;
	case ft_XC_SetLayoutFrameColor:
		XC_SetLayoutFrameColor((COLORREF)pControl->p1);
		break;
	case ft_XC_EnableErrorMessageBox:
		XC_EnableErrorMessageBox((BOOL)pControl->p1);
		break;
	case ft_XC_LoadLayout:
		ret = (int)XC_LoadLayout((const wchar_t *)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XC_LoadLayoutFromString:
		ret = (int)XC_LoadLayoutFromString((const char *)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XC_LoadResource:
		ret = (int)XC_LoadResource((const wchar_t *)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XC_LoadResourceFromString:
		ret = (int)XC_LoadResourceFromString((const char *)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t *)pControl->p3);
		break;
	case ft_XC_LoadStyle:
		ret = (int)XC_LoadStyle((const wchar_t *)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XC_GetTextSize:
		XC_GetTextSize((const wchar_t*)pControl->p1,(int)pControl->p2,(HFONTX)pControl->p3,(out_ SIZE*)pControl->p4);
		break;
	case ft_XC_GetTextShowSize:
		XC_GetTextShowSize((const wchar_t*)pControl->p1,(int)pControl->p2,(HFONTX)pControl->p3,(out_ SIZE*)pControl->p4);
		break;
	case ft_XC_GetDefaultFont:
		ret = (int)XC_GetDefaultFont();
		break;
	case ft_XC_SetDefaultFont:
		XC_SetDefaultFont((HFONTX)pControl->p1);
		break;
	case ft_XC_InitFont:
		XC_InitFont((LOGFONTW *)pControl->p1,(wchar_t *)pControl->p2,(int)pControl->p3,(BOOL)pControl->p4,(BOOL)pControl->p5,(BOOL)pControl->p6,(BOOL)pControl->p7);
		break;
	case ft_XC_Malloc:
		ret = (int)XC_Malloc((int)pControl->p1);
		break;
	case ft_XC_Free:
		XC_Free((void *)pControl->p1);
		break;
	case ft__XC_SetType:
		_XC_SetType((HXCGUI)pControl->p1,(XC_OBJECT_TYPE)pControl->p2);
		break;
	case ft__XC_AddType:
		_XC_AddType((HXCGUI)pControl->p1,(XC_OBJECT_TYPE)pControl->p2);
		break;
	case ft__XC_BindData:
		_XC_BindData((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft__XC_GetBindData:
		ret = (int)_XC_GetBindData((HXCGUI)pControl->p1);
		break;
	case ft_XInitXCGUI:
		ret = (int)XInitXCGUI((wchar_t *)pControl->p1);
		break;
	case ft_XRunXCGUI:
		XRunXCGUI();
		break;
	case ft_XExitXCGUI:
		XExitXCGUI();
		break;
	case ft_XObj_GetType:
		ret = (int)XObj_GetType((HXCGUI)pControl->p1);
		break;
	case ft_XObj_GetTypeEx:
		ret = (int)XObj_GetTypeEx((HXCGUI)pControl->p1);
		break;
	case ft_XUI_SetStyle:
		XUI_SetStyle((HXCGUI)pControl->p1,(XC_OBJECT_STYLE)pControl->p2);
		break;
	case ft_XUI_GetStyle:
		ret = (int)XUI_GetStyle((HXCGUI)pControl->p1);
		break;
	case ft_XBkM_Create:
		ret = (int)XBkM_Create();
		break;
	case ft_XBkM_Destroy:
		XBkM_Destroy((HBKM)pControl->p1);
		break;
	case ft_XBkM_SetBkInfo:
		ret = (int)XBkM_SetBkInfo((HBKM)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XBkM_AddInfo:
		ret = (int)XBkM_AddInfo((HBKM)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XBkM_AddBorder:
		XBkM_AddBorder((HBKM)pControl->p1,(int)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4,(int)pControl->p5);
		break;
	case ft_XBkM_AddFill:
		XBkM_AddFill((HBKM)pControl->p1,(int)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XBkM_AddImage:
		XBkM_AddImage((HBKM)pControl->p1,(int)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XBkM_GetCount:
		ret = (int)XBkM_GetCount((HBKM)pControl->p1);
		break;
	case ft_XBkM_Clear:
		XBkM_Clear((HBKM)pControl->p1);
		break;
	case ft_XBkM_Draw:
		ret = (int)XBkM_Draw((HBKM)pControl->p1,(int)pControl->p2,(HDRAW)pControl->p3,(RECT*)pControl->p4);
		break;
	case ft_XBkM_DrawEx:
		ret = (int)XBkM_DrawEx((HBKM)pControl->p1,(int)pControl->p2,(HDRAW)pControl->p3,(RECT*)pControl->p4,(int)pControl->p5);
		break;
	case ft_XBtn_Create:
		ret = (int)XBtn_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(const wchar_t *)pControl->p5,(HXCGUI)pControl->p6);
		break;
	case ft_XBtn_IsCheck:
		ret = (int)XBtn_IsCheck((HELE)pControl->p1);
		break;
	case ft_XBtn_SetCheck:
		ret = (int)XBtn_SetCheck((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XBtn_SetState:
		XBtn_SetState((HELE)pControl->p1,(common_state3_)pControl->p2);
		break;
	case ft_XBtn_GetState:
		ret = (int)XBtn_GetState((HELE)pControl->p1);
		break;
	case ft_XBtn_GetStateEx:
		ret = (int)XBtn_GetStateEx((HELE)pControl->p1);
		break;
	case ft_XBtn_SetStyle:
		XBtn_SetStyle((HELE)pControl->p1,(XC_OBJECT_STYLE)pControl->p2);
		break;
	case ft_XBtn_GetStyle:
		ret = (int)XBtn_GetStyle((HELE)pControl->p1);
		break;
	case ft_XBtn_SetType:
		XBtn_SetType((HELE)pControl->p1,(XC_OBJECT_TYPE_EX)pControl->p2);
		break;
	case ft_XBtn_SetTypeEx:
		XBtn_SetTypeEx((HELE)pControl->p1,(XC_OBJECT_TYPE_EX)pControl->p2);
		break;
	case ft_XBtn_GetType:
		ret = (int)XBtn_GetType((HELE)pControl->p1);
		break;
	case ft_XBtn_SetGroupID:
		XBtn_SetGroupID((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XBtn_GetGroupID:
		ret = (int)XBtn_GetGroupID((HELE)pControl->p1);
		break;
	case ft_XBtn_SetBindEle:
		XBtn_SetBindEle((HELE)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XBtn_GetBindEle:
		ret = (int)XBtn_GetBindEle((HELE)pControl->p1);
		break;
	case ft_XBtn_SetTextAlign:
		XBtn_SetTextAlign((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XBtn_GetTextAlign:
		ret = (int)XBtn_GetTextAlign((HELE)pControl->p1);
		break;
	case ft_XBtn_SetIconAlign:
		XBtn_SetIconAlign((HELE)pControl->p1,(button_icon_align_)pControl->p2);
		break;
	case ft_XBtn_SetOffset:
		XBtn_SetOffset((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XBtn_SetOffsetIcon:
		XBtn_SetOffsetIcon((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XBtn_SetIconSpace:
		XBtn_SetIconSpace((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XBtn_GetText:
		XBtn_GetText((HELE)pControl->p1,(out_ wchar_t *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XBtn_SetText:
		XBtn_SetText((HELE)pControl->p1,(in_ const wchar_t *)pControl->p2);
		break;
	case ft_XBtn_SetIcon:
		XBtn_SetIcon((HELE)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XBtn_SetIconDisable:
		XBtn_SetIconDisable((HELE)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XBtn_GetIcon:
		ret = (int)XBtn_GetIcon((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XBtn_AddAnimationFrame:
		XBtn_AddAnimationFrame((HELE)pControl->p1,(HIMAGE)pControl->p2,(UINT)pControl->p3);
		break;
	case ft_XBtn_EnableAnimation:
		XBtn_EnableAnimation((HELE)pControl->p1,(BOOL)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XBtn_AddBkBorder:
		XBtn_AddBkBorder((HELE)pControl->p1,(button_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4,(int)pControl->p5);
		break;
	case ft_XBtn_AddBkFill:
		XBtn_AddBkFill((HELE)pControl->p1,(button_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XBtn_AddBkImage:
		XBtn_AddBkImage((HELE)pControl->p1,(button_state_)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XBtn_GetBkInfoCount:
		ret = (int)XBtn_GetBkInfoCount((HELE)pControl->p1);
		break;
	case ft_XBtn_ClearBkInfo:
		XBtn_ClearBkInfo((HELE)pControl->p1);
		break;
	case ft_XComboBox_Create:
		ret = (int)XComboBox_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XComboBox_SetSelItem:
		ret = (int)XComboBox_SetSelItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XComboBox_GetButtonRect:
		XComboBox_GetButtonRect((HELE)pControl->p1,(out_ RECT*)pControl->p2);
		break;
	case ft_XComboBox_SetButtonSize:
		XComboBox_SetButtonSize((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XComboBox_SetDropHeight:
		XComboBox_SetDropHeight((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XComboBox_GetDropHeight:
		ret = (int)XComboBox_GetDropHeight((HELE)pControl->p1);
		break;
	case ft_XComboBox_BindAdapter:
		XComboBox_BindAdapter((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XComboBox_GetApapter:
		ret = (int)XComboBox_GetApapter((HELE)pControl->p1);
		break;
	case ft_XComboBox_SetItemTemplateXML:
		XComboBox_SetItemTemplateXML((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XComboBox_SetItemTemplateXMLFromString:
		XComboBox_SetItemTemplateXMLFromString((HELE)pControl->p1,(const char*)pControl->p2);
		break;
	case ft_XComboBox_EnableDrawButton:
		XComboBox_EnableDrawButton((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XComboBox_EnableEdit:
		XComboBox_EnableEdit((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XComboBox_EnableDropHeightFixed:
		XComboBox_EnableDropHeightFixed((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XComboBox_AddBkBorder:
		XComboBox_AddBkBorder((HELE)pControl->p1,(comboBox_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4,(int)pControl->p5);
		break;
	case ft_XComboBox_AddBkFill:
		XComboBox_AddBkFill((HELE)pControl->p1,(comboBox_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XComboBox_AddBkImage:
		XComboBox_AddBkImage((HELE)pControl->p1,(comboBox_state_)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XComboboX_GetBkInfoCount:
		ret = (int)XComboboX_GetBkInfoCount((HELE)pControl->p1);
		break;
	case ft_XComboBox_ClearBkInfo:
		XComboBox_ClearBkInfo((HELE)pControl->p1);
		break;
	case ft_XComboBox_GetSelItem:
		ret = (int)XComboBox_GetSelItem((HELE)pControl->p1);
		break;
	case ft_XComboBox_GetState:
		ret = (int)XComboBox_GetState((HELE)pControl->p1);
		break;
	case ft_XAd_Destroy:
		XAd_Destroy((HXCGUI)pControl->p1);
		break;
	case ft_XAdListView_Create:
		ret = (int)XAdListView_Create();
		break;
	case ft_XAdListView_Group_AddColumn:
		ret = (int)XAdListView_Group_AddColumn((HXCGUI)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XAdListView_Group_AddItemText:
		ret = (int)XAdListView_Group_AddItemText((HXCGUI)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XAdListView_Group_AddItemTextEx:
		ret = (int)XAdListView_Group_AddItemTextEx((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t *)pControl->p3);
		break;
	case ft_XAdListView_Group_AddItemImage:
		ret = (int)XAdListView_Group_AddItemImage((HXCGUI)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XAdListView_Group_AddItemImageEx:
		ret = (int)XAdListView_Group_AddItemImageEx((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XAdListView_Group_SetText:
		ret = (int)XAdListView_Group_SetText((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t *)pControl->p4);
		break;
	case ft_XAdListView_Group_SetTextEx:
		ret = (int)XAdListView_Group_SetTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(const wchar_t *)pControl->p4);
		break;
	case ft_XAdListView_Group_SetImage:
		ret = (int)XAdListView_Group_SetImage((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdListView_Group_SetImageEx:
		ret = (int)XAdListView_Group_SetImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdListView_Group_GetCount:
		ret = (int)XAdListView_Group_GetCount((HXCGUI)pControl->p1);
		break;
	case ft_XAdListView_Item_GetCount:
		ret = (int)XAdListView_Item_GetCount((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XAdListView_Item_AddColumn:
		ret = (int)XAdListView_Item_AddColumn((HXCGUI)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XAdListView_Item_AddItemText:
		ret = (int)XAdListView_Item_AddItemText((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3);
		break;
	case ft_XAdListView_Item_AddItemTextEx:
		ret = (int)XAdListView_Item_AddItemTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(const wchar_t *)pControl->p4);
		break;
	case ft_XAdListView_Item_AddItemImage:
		ret = (int)XAdListView_Item_AddItemImage((HXCGUI)pControl->p1,(int)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XAdListView_Item_AddItemImageEx:
		ret = (int)XAdListView_Item_AddItemImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdListView_Item_SetText:
		ret = (int)XAdListView_Item_SetText((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(const wchar_t*)pControl->p5);
		break;
	case ft_XAdListView_Item_SetTextEx:
		ret = (int)XAdListView_Item_SetTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t *)pControl->p4,(const wchar_t*)pControl->p5);
		break;
	case ft_XAdListView_Item_SetImage:
		ret = (int)XAdListView_Item_SetImage((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HIMAGE)pControl->p5);
		break;
	case ft_XAdListView_Item_SetImageEx:
		ret = (int)XAdListView_Item_SetImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t *)pControl->p4,(HIMAGE)pControl->p5);
		break;
	case ft_XAdListView_Group_DeleteItem:
		ret = (int)XAdListView_Group_DeleteItem((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XAdListView_Group_DeleteAllChildItem:
		XAdListView_Group_DeleteAllChildItem((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XAdListView_Item_DeleteItem:
		ret = (int)XAdListView_Item_DeleteItem((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XAdListView_DeleteAll:
		XAdListView_DeleteAll((HXCGUI)pControl->p1);
		break;
	case ft_XAdListView_DeleteAllGroup:
		XAdListView_DeleteAllGroup((HXCGUI)pControl->p1);
		break;
	case ft_XAdListView_DeleteAllItem:
		XAdListView_DeleteAllItem((HXCGUI)pControl->p1);
		break;
	case ft_XAdListView_DeleteColumnGroup:
		XAdListView_DeleteColumnGroup((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XAdListView_DeleteColumnItem:
		XAdListView_DeleteColumnItem((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XAdListView_Item_GetTextEx:
		ret = (int)XAdListView_Item_GetTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t*)pControl->p4,(out_ wchar_t*)pControl->p5,(int)pControl->p6);
		break;
	case ft_XAdListView_Item_GetImageEx:
		ret = (int)XAdListView_Item_GetImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t*)pControl->p4);
		break;
	case ft_XAdTable_Create:
		ret = (int)XAdTable_Create();
		break;
	case ft_XAdTable_Sort:
		XAdTable_Sort((HXCGUI)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XAdTable_GetItemDataType:
		ret = (int)XAdTable_GetItemDataType((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XAdTable_GetItemDataTypeEx:
		ret = (int)XAdTable_GetItemDataTypeEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XAdTable_AddColumn:
		ret = (int)XAdTable_AddColumn((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XAdTable_SetColumn:
		ret = (int)XAdTable_SetColumn((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XAdTable_AddItemText:
		ret = (int)XAdTable_AddItemText((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XAdTable_AddItemTextEx:
		ret = (int)XAdTable_AddItemTextEx((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XAdTable_AddItemImage:
		ret = (int)XAdTable_AddItemImage((HXCGUI)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XAdTable_AddItemImageEx:
		ret = (int)XAdTable_AddItemImageEx((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XAdTable_InsertItemText:
		ret = (int)XAdTable_InsertItemText((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XAdTable_InsertItemTextEx:
		ret = (int)XAdTable_InsertItemTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(const wchar_t*)pControl->p4);
		break;
	case ft_XAdTable_InsertItemImage:
		ret = (int)XAdTable_InsertItemImage((HXCGUI)pControl->p1,(int)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XAdTable_InsertItemImageEx:
		ret = (int)XAdTable_InsertItemImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdTable_SetItemText:
		ret = (int)XAdTable_SetItemText((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t*)pControl->p4);
		break;
	case ft_XAdTable_SetItemTextEx:
		ret = (int)XAdTable_SetItemTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(const wchar_t*)pControl->p4);
		break;
	case ft_XAdTable_SetItemInt:
		ret = (int)XAdTable_SetItemInt((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XAdTable_SetItemIntEx:
		ret = (int)XAdTable_SetItemIntEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(int)pControl->p4);
		break;
	case ft_XAdTable_SetItemFloat:
		ret = (int)XAdTable_SetItemFloat((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(float)pControl->p4);
		break;
	case ft_XAdTable_SetItemFloatEx:
		ret = (int)XAdTable_SetItemFloatEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(float)pControl->p4);
		break;
	case ft_XAdTable_SetItemImage:
		ret = (int)XAdTable_SetItemImage((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdTable_SetItemImageEx:
		ret = (int)XAdTable_SetItemImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdTable_DeleteItem:
		ret = (int)XAdTable_DeleteItem((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XAdTable_DeleteItemEx:
		ret = (int)XAdTable_DeleteItemEx((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XAdTable_DeleteItemAll:
		XAdTable_DeleteItemAll((HXCGUI)pControl->p1);
		break;
	case ft_XAdTable_DeleteColumnAll:
		XAdTable_DeleteColumnAll((HXCGUI)pControl->p1);
		break;
	case ft_XAdTable_GetCount:
		ret = (int)XAdTable_GetCount((HXCGUI)pControl->p1);
		break;
	case ft_XAdTable_GetCountColumn:
		ret = (int)XAdTable_GetCountColumn((HXCGUI)pControl->p1);
		break;
	case ft_XAdTable_GetItemText:
		ret = (int)XAdTable_GetItemText((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(out_ wchar_t*)pControl->p4,(int)pControl->p5);
		break;
	case ft_XAdTable_GetItemTextEx:
		ret = (int)XAdTable_GetItemTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(out_ wchar_t*)pControl->p4,(int)pControl->p5);
		break;
	case ft_XAdTable_GetItemImage:
		ret = (int)XAdTable_GetItemImage((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XAdTable_GetItemImageEx:
		ret = (int)XAdTable_GetItemImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XAdTable_GetItemInt:
		ret = (int)XAdTable_GetItemInt((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(out_ int*)pControl->p4);
		break;
	case ft_XAdTable_GetItemIntEx:
		ret = (int)XAdTable_GetItemIntEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(out_ int*)pControl->p4);
		break;
	case ft_XAdTable_GetItemFloat:
		ret = (int)XAdTable_GetItemFloat((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(out_ float*)pControl->p4);
		break;
	case ft_XAdTable_GetItemFloatEx:
		ret = (int)XAdTable_GetItemFloatEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(out_ float*)pControl->p4);
		break;
	case ft_XAdTree_Create:
		ret = (int)XAdTree_Create();
		break;
	case ft_XAdTree_AddColumn:
		ret = (int)XAdTree_AddColumn((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XAdTree_SetColumn:
		ret = (int)XAdTree_SetColumn((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XAdTree_InsertItemText:
		ret = (int)XAdTree_InsertItemText((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XAdTree_InsertItemTextEx:
		ret = (int)XAdTree_InsertItemTextEx((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XAdTree_InsertItemImage:
		ret = (int)XAdTree_InsertItemImage((HXCGUI)pControl->p1,(HIMAGE)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XAdTree_InsertItemImageEx:
		ret = (int)XAdTree_InsertItemImageEx((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(HIMAGE)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XAdTree_GetCount:
		ret = (int)XAdTree_GetCount((HXCGUI)pControl->p1);
		break;
	case ft_XAdTree_GetCountColumn:
		ret = (int)XAdTree_GetCountColumn((HXCGUI)pControl->p1);
		break;
	case ft_XAdTree_SetItemText:
		ret = (int)XAdTree_SetItemText((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t*)pControl->p4);
		break;
	case ft_XAdTree_SetItemTextEx:
		ret = (int)XAdTree_SetItemTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(const wchar_t*)pControl->p4);
		break;
	case ft_XAdTree_SetItemImage:
		ret = (int)XAdTree_SetItemImage((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdTree_SetItemImageEx:
		ret = (int)XAdTree_SetItemImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(HIMAGE)pControl->p4);
		break;
	case ft_XAdTree_GetItemText:
		ret = (int)XAdTree_GetItemText((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(out_ wchar_t*)pControl->p4,(int)pControl->p5);
		break;
	case ft_XAdTree_GetItemImage:
		ret = (int)XAdTree_GetItemImage((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XAdTree_GetItemTextEx:
		ret = (int)XAdTree_GetItemTextEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3,(out_ wchar_t*)pControl->p4,(int)pControl->p5);
		break;
	case ft_XAdTree_GetItemImageEx:
		ret = (int)XAdTree_GetItemImageEx((HXCGUI)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XAdTree_DeleteItem:
		ret = (int)XAdTree_DeleteItem((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XAdTree_DeleteItemAll:
		XAdTree_DeleteItemAll((HXCGUI)pControl->p1);
		break;
	case ft_XAdTree_DeleteColumnAll:
		XAdTree_DeleteColumnAll((HXCGUI)pControl->p1);
		break;
	case ft_XAdMap_Create:
		ret = (int)XAdMap_Create();
		break;
	case ft_XAdMap_AddItemText:
		ret = (int)XAdMap_AddItemText((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XAdMap_AddItemImage:
		ret = (int)XAdMap_AddItemImage((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XAdMap_DeleteItem:
		ret = (int)XAdMap_DeleteItem((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XAdMap_GetCount:
		ret = (int)XAdMap_GetCount((HXCGUI)pControl->p1);
		break;
	case ft_XAdMap_GetItemText:
		ret = (int)XAdMap_GetItemText((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(out_ wchar_t*)pControl->p3,(int)pControl->p4);
		break;
	case ft_XAdMap_GetItemImage:
		ret = (int)XAdMap_GetItemImage((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XAdMap_SetItemText:
		ret = (int)XAdMap_SetItemText((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XAdMap_SetItemImage:
		ret = (int)XAdMap_SetItemImage((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft__XC_DebugPrintf:
		_XC_DebugPrintf((int)pControl->p1,(const char *)pControl->p2,(int)pControl->p3);
		break;
	case ft__XC_DebugPrintfW:
		_XC_DebugPrintfW((int)pControl->p1,(const wchar_t *)pControl->p2,(int)pControl->p3);
		break;
	case ft_xtrace:
		xtrace((const char *)pControl->p1,(int)pControl->p2);
		break;
	case ft_xtracew:
		xtracew((const wchar_t *)pControl->p1,(int)pControl->p2);
		break;
	case ft_XDraw_Create:
		ret = (int)XDraw_Create((HDC)pControl->p1);
		break;
	case ft_XDraw_Destroy:
		XDraw_Destroy((HDRAW)pControl->p1);
		break;
	case ft_XDraw_SetOffset:
		XDraw_SetOffset((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XDraw_GetOffset:
		XDraw_GetOffset((HDRAW)pControl->p1,(out_ int *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XDraw_RestoreGDIOBJ:
		XDraw_RestoreGDIOBJ((HDRAW)pControl->p1);
		break;
	case ft_XDraw_GetHDC:
		ret = (int)XDraw_GetHDC((HDRAW)pControl->p1);
		break;
	case ft_XDraw_SetBrushColor:
		XDraw_SetBrushColor((HDRAW)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XDraw_SetTextAlign:
		XDraw_SetTextAlign((HDRAW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XDraw_SetTextVertical:
		XDraw_SetTextVertical((HDRAW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XDraw_SetFontX:
		XDraw_SetFontX((HDRAW)pControl->p1,(HFONTX)pControl->p2);
		break;
	case ft_XDraw_SetLineWidth:
		XDraw_SetLineWidth((HDRAW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XDraw_SetBkMode:
		ret = (int)XDraw_SetBkMode((HDRAW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XDraw_SetClipRect:
		XDraw_SetClipRect((HDRAW)pControl->p1,(RECT*)pControl->p2);
		break;
	case ft_XDraw_ClearClip:
		XDraw_ClearClip((HDRAW)pControl->p1);
		break;
	case ft_XDraw_EnableSmoothingMode:
		XDraw_EnableSmoothingMode((HDRAW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XDraw_CreateSolidBrush:
		ret = (int)XDraw_CreateSolidBrush((HDRAW)pControl->p1,(COLORREF)pControl->p2);
		break;
	case ft_XDraw_CreatePen:
		ret = (int)XDraw_CreatePen((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(COLORREF)pControl->p4);
		break;
	case ft_XDraw_CreateRectRgn:
		ret = (int)XDraw_CreateRectRgn((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XDraw_CreateRoundRectRgn:
		ret = (int)XDraw_CreateRoundRectRgn((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6,(int)pControl->p7);
		break;
	case ft_XDraw_CreatePolygonRgn:
		ret = (int)XDraw_CreatePolygonRgn((HDRAW)pControl->p1,(POINT *)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XDraw_SelectClipRgn:
		ret = (int)XDraw_SelectClipRgn((HDRAW)pControl->p1,(HRGN)pControl->p2);
		break;
	case ft_XDraw_FillRect:
		XDraw_FillRect((HDRAW)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XDraw_FillRectColor:
		XDraw_FillRectColor((HDRAW)pControl->p1,(RECT *)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XDraw_FillRgn:
		ret = (int)XDraw_FillRgn((HDRAW)pControl->p1,(HRGN)pControl->p2,(HBRUSH)pControl->p3);
		break;
	case ft_XDraw_FillEllipse:
		XDraw_FillEllipse((HDRAW)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XDraw_DrawEllipse:
		XDraw_DrawEllipse((HDRAW)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XDraw_FillRoundRect:
		XDraw_FillRoundRect((HDRAW)pControl->p1,(RECT *)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XDraw_DrawRoundRect:
		XDraw_DrawRoundRect((HDRAW)pControl->p1,(RECT *)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XDraw_FillRoundRectEx:
		XDraw_FillRoundRectEx((HDRAW)pControl->p1,(RECT *)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XDraw_DrawRoundRectEx:
		XDraw_DrawRoundRectEx((HDRAW)pControl->p1,(RECT *)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XDraw_Rectangle:
		ret = (int)XDraw_Rectangle((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XDraw_DrawGroupBox_Rect:
		XDraw_DrawGroupBox_Rect((HDRAW)pControl->p1,(RECT *)pControl->p2,(const wchar_t*)pControl->p3,(COLORREF)pControl->p4,(BYTE)pControl->p5,(POINT*)pControl->p6);
		break;
	case ft_XDraw_DrawGroupBox_RoundRect:
		XDraw_DrawGroupBox_RoundRect((HDRAW)pControl->p1,(RECT *)pControl->p2,(const wchar_t*)pControl->p3,(COLORREF)pControl->p4,(BYTE)pControl->p5,(POINT*)pControl->p6,(int)pControl->p7,(int)pControl->p8);
		break;
	case ft_XDraw_GradientFill2:
		XDraw_GradientFill2((HDRAW)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3,(COLORREF)pControl->p4,(BYTE)pControl->p5,(RECT *)pControl->p6,(int)pControl->p7);
		break;
	case ft_XDraw_GradientFill4:
		ret = (int)XDraw_GradientFill4((HDRAW)pControl->p1,(COLORREF)pControl->p2,(COLORREF)pControl->p3,(COLORREF)pControl->p4,(COLORREF)pControl->p5,(RECT *)pControl->p6,(int)pControl->p7);
		break;
	case ft_XDraw_FrameRgn:
		ret = (int)XDraw_FrameRgn((HDRAW)pControl->p1,(HRGN)pControl->p2,(HBRUSH)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XDraw_FrameRect:
		XDraw_FrameRect((HDRAW)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XDraw_FocusRect:
		XDraw_FocusRect((HDRAW)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XDraw_DrawLine:
		XDraw_DrawLine((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XDraw_MoveToEx:
		ret = (int)XDraw_MoveToEx((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(LPPOINT)pControl->p4);
		break;
	case ft_XDraw_LineTo:
		ret = (int)XDraw_LineTo((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XDraw_Polyline:
		ret = (int)XDraw_Polyline((HDRAW)pControl->p1,(in_ POINT *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XDraw_Dottedline:
		XDraw_Dottedline((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XDraw_SetPixel:
		ret = (int)XDraw_SetPixel((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(COLORREF)pControl->p4);
		break;
	case ft_XDraw_Check:
		XDraw_Check((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(COLORREF)pControl->p4,(BOOL)pControl->p5);
		break;
	case ft_XDraw_DrawIconEx:
		ret = (int)XDraw_DrawIconEx((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(HICON)pControl->p4,(int)pControl->p5,(int)pControl->p6,(UINT)pControl->p7,(HBRUSH)pControl->p8,(UINT)pControl->p9);
		break;
	case ft_XDraw_BitBlt:
		ret = (int)XDraw_BitBlt((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(HDC)pControl->p6,(int)pControl->p7,(int)pControl->p8,(DWORD)pControl->p9);
		break;
	case ft_XDraw_BitBlt2:
		ret = (int)XDraw_BitBlt2((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(HDRAW)pControl->p6,(int)pControl->p7,(int)pControl->p8,(DWORD)pControl->p9);
		break;
	case ft_XDraw_AlphaBlend:
		ret = (int)XDraw_AlphaBlend((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(HDC)pControl->p6,(int)pControl->p7,(int)pControl->p8,(int)pControl->p9,(int)pControl->p10,(int)pControl->p11);
		break;
	case ft_XDraw_TriangularArrow:
		XDraw_TriangularArrow((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XDraw_DrawPolygon:
		XDraw_DrawPolygon((HDRAW)pControl->p1,(in_ POINT *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XDraw_DrawPolygonF:
		XDraw_DrawPolygonF((HDRAW)pControl->p1,(in_ POINTF *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XDraw_FillPolygon:
		XDraw_FillPolygon((HDRAW)pControl->p1,(in_ POINT *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XDraw_FillPolygonF:
		XDraw_FillPolygonF((HDRAW)pControl->p1,(in_ POINTF *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XDraw_Image:
		XDraw_Image((HDRAW)pControl->p1,(HIMAGE)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XDraw_Image2:
		XDraw_Image2((HDRAW)pControl->p1,(HIMAGE)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XDraw_ImageStretch:
		XDraw_ImageStretch((HDRAW)pControl->p1,(HIMAGE)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XDraw_ImageAdaptive:
		XDraw_ImageAdaptive((HDRAW)pControl->p1,(HIMAGE)pControl->p2,(RECT *)pControl->p3,(BOOL)pControl->p4);
		break;
	case ft_XDraw_ImageExTile:
		XDraw_ImageExTile((HDRAW)pControl->p1,(HIMAGE)pControl->p2,(RECT *)pControl->p3,(int)pControl->p4);
		break;
	case ft_XDraw_ImageSuper:
		XDraw_ImageSuper((HDRAW)pControl->p1,(HIMAGE)pControl->p2,(RECT *)pControl->p3,(BOOL)pControl->p4);
		break;
	case ft_XDraw_ImageSuper2:
		XDraw_ImageSuper2((HDRAW)pControl->p1,(HIMAGE)pControl->p2,(RECT *)pControl->p3,(RECT *)pControl->p4);
		break;
	case ft_XDraw_DrawText:
		XDraw_DrawText((HDRAW)pControl->p1,(const wchar_t *)pControl->p2,(int)pControl->p3,(RECT*)pControl->p4);
		break;
	case ft_XDraw_DrawTextUnderline:
		XDraw_DrawTextUnderline((HDRAW)pControl->p1,(const wchar_t *)pControl->p2,(int)pControl->p3,(RECT*)pControl->p4,(COLORREF)pControl->p5,(BYTE)pControl->p6);
		break;
	case ft_XDraw_TextOut:
		XDraw_TextOut((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t *)pControl->p4,(int)pControl->p5);
		break;
	case ft_XDraw_TextOutEx:
		XDraw_TextOutEx((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t *)pControl->p4);
		break;
	case ft_XDraw_TextOutA:
		XDraw_TextOutA((HDRAW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const char *)pControl->p4);
		break;
	case ft_XDraw_SetAlpha:
		XDraw_SetAlpha((HDRAW)pControl->p1,(BYTE)pControl->p2);
		break;
	case ft_XDraw_SetAlphaEx:
		XDraw_SetAlphaEx((HDC)pControl->p1,(BYTE)pControl->p2);
		break;
	case ft_XEle_Create:
		ret = (int)XEle_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft__XEle_RegEvent:
		ret = (int)_XEle_RegEvent((HELE)pControl->p1,(UINT)pControl->p2,(xc_event*)pControl->p3);
		break;
	case ft__XEle_RemoveEvent:
		ret = (int)_XEle_RemoveEvent((HELE)pControl->p1,(UINT)pControl->p2,(xc_event*)pControl->p3);
		break;
	case ft_XEle_RegEventC:
		ret = (int)XEle_RegEventC((HELE)pControl->p1,(int)pControl->p2,(void *)pControl->p3);
		break;
	case ft_XEle_RegEventC1:
		ret = (int)XEle_RegEventC1((HELE)pControl->p1,(int)pControl->p2,(void *)pControl->p3);
		break;
	case ft_XEle_RegEventC2:
		ret = (int)XEle_RegEventC2((HELE)pControl->p1,(int)pControl->p2,(void *)pControl->p3);
		break;
	case ft_XEle_RemoveEventC:
		ret = (int)XEle_RemoveEventC((HELE)pControl->p1,(int)pControl->p2,(void *)pControl->p3);
		break;
	case ft_XEle_SendEvent:
		ret = (int)XEle_SendEvent((HELE)pControl->p1,(HELE)pControl->p2,(int)pControl->p3,(WPARAM)pControl->p4,(LPARAM)pControl->p5);
		break;
	case ft_XEle_PostEvent:
		ret = (int)XEle_PostEvent((HELE)pControl->p1,(HELE)pControl->p2,(int)pControl->p3,(WPARAM)pControl->p4,(LPARAM)pControl->p5);
		break;
	case ft_XEle_IsShow:
		ret = (int)XEle_IsShow((HELE)pControl->p1);
		break;
	case ft_XEle_IsEnable:
		ret = (int)XEle_IsEnable((HELE)pControl->p1);
		break;
	case ft_XEle_IsEnableFocus:
		ret = (int)XEle_IsEnableFocus((HELE)pControl->p1);
		break;
	case ft_XEle_IsDrawFocus:
		ret = (int)XEle_IsDrawFocus((HELE)pControl->p1);
		break;
	case ft_XEle_IsEnableEvent_XE_PAINT_END:
		ret = (int)XEle_IsEnableEvent_XE_PAINT_END((HELE)pControl->p1);
		break;
	case ft_XEle_IsMouseThrough:
		ret = (int)XEle_IsMouseThrough((HELE)pControl->p1);
		break;
	case ft_XEle_IsBkTransparent:
		ret = (int)XEle_IsBkTransparent((HELE)pControl->p1);
		break;
	case ft_XEle_IsKeyTab:
		ret = (int)XEle_IsKeyTab((HELE)pControl->p1);
		break;
	case ft_XEle_IsSwitchFocus:
		ret = (int)XEle_IsSwitchFocus((HELE)pControl->p1);
		break;
	case ft_XEle_IsEnable_XE_MOUSEWHEEL:
		ret = (int)XEle_IsEnable_XE_MOUSEWHEEL((HELE)pControl->p1);
		break;
	case ft_XEle_IsInScrollView:
		ret = (int)XEle_IsInScrollView((HELE)pControl->p1);
		break;
	case ft_XEle_Enable:
		XEle_Enable((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableFocus:
		XEle_EnableFocus((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableDrawFocus:
		XEle_EnableDrawFocus((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableDrawBorder:
		XEle_EnableDrawBorder((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableEvent_XE_PAINT_END:
		XEle_EnableEvent_XE_PAINT_END((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableBkTransparent:
		XEle_EnableBkTransparent((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableMouseThrough:
		XEle_EnableMouseThrough((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableKeyTab:
		XEle_EnableKeyTab((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableSwitchFocus:
		XEle_EnableSwitchFocus((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableEvent_XE_MOUSEWHEEL:
		XEle_EnableEvent_XE_MOUSEWHEEL((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableInScrollView:
		XEle_EnableInScrollView((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_SetRect:
		ret = (int)XEle_SetRect((HELE)pControl->p1,(RECT *)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XEle_SetRectEx:
		ret = (int)XEle_SetRectEx((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(BOOL)pControl->p6);
		break;
	case ft_XEle_SetRectLogic:
		ret = (int)XEle_SetRectLogic((HELE)pControl->p1,(RECT *)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XEle_GetRect:
		XEle_GetRect((HELE)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XEle_GetRectLogic:
		XEle_GetRectLogic((HELE)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XEle_GetClientRect:
		XEle_GetClientRect((HELE)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XEle_GetWndClientRect:
		XEle_GetWndClientRect((HELE)pControl->p1,(out_ RECT *)pControl->p2);
		break;
	case ft_XEle_GetWidth:
		ret = (int)XEle_GetWidth((HELE)pControl->p1);
		break;
	case ft_XEle_GetHeight:
		ret = (int)XEle_GetHeight((HELE)pControl->p1);
		break;
	case ft_XEle_RectWndClientToEleClient:
		XEle_RectWndClientToEleClient((HELE)pControl->p1,(in_out_ RECT *)pControl->p2);
		break;
	case ft_XEle_PointWndClientToEleClient:
		XEle_PointWndClientToEleClient((HELE)pControl->p1,(in_out_ POINT *)pControl->p2);
		break;
	case ft_XEle_RectClientToWndClient:
		XEle_RectClientToWndClient((HELE)pControl->p1,(in_out_ RECT *)pControl->p2);
		break;
	case ft_XEle_PointClientToWndClient:
		XEle_PointClientToWndClient((HELE)pControl->p1,(in_out_ POINT *)pControl->p2);
		break;
	case ft_XEle_AddEle:
		ret = (int)XEle_AddEle((HELE)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XEle_InsertEle:
		ret = (int)XEle_InsertEle((HELE)pControl->p1,(HELE)pControl->p2,(int)pControl->p3);
		break;
	case ft_XEle_RemoveEle:
		XEle_RemoveEle((HELE)pControl->p1);
		break;
	case ft_XEle_AddShape:
		ret = (int)XEle_AddShape((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XEle_SetZOrder:
		ret = (int)XEle_SetZOrder((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XEle_SetZOrderEx:
		ret = (int)XEle_SetZOrderEx((HELE)pControl->p1,(HELE)pControl->p2,(zorder_)pControl->p3);
		break;
	case ft_XEle_GetZOrder:
		ret = (int)XEle_GetZOrder((HELE)pControl->p1);
		break;
	case ft_XEle_SetTopmost:
		ret = (int)XEle_SetTopmost((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_EnableCSS:
		XEle_EnableCSS((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_SetCssName:
		XEle_SetCssName((HELE)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XEle_GetCssName:
		ret = (int)XEle_GetCssName((HELE)pControl->p1);
		break;
	case ft_XEle_ShowEle:
		XEle_ShowEle((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_GetType:
		ret = (int)XEle_GetType((HELE)pControl->p1);
		break;
	case ft_XEle_GetHWND:
		ret = (int)XEle_GetHWND((HELE)pControl->p1);
		break;
	case ft_XEle_GetHWINDOW:
		ret = (int)XEle_GetHWINDOW((HELE)pControl->p1);
		break;
	case ft_XEle_SetCursor:
		XEle_SetCursor((HELE)pControl->p1,(HCURSOR)pControl->p2);
		break;
	case ft_XEle_GetCursor:
		ret = (int)XEle_GetCursor((HELE)pControl->p1);
		break;
	case ft_XEle_SetID:
		XEle_SetID((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XEle_GetID:
		ret = (int)XEle_GetID((HELE)pControl->p1);
		break;
	case ft_XEle_SetUID:
		XEle_SetUID((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XEle_GetUID:
		ret = (int)XEle_GetUID((HELE)pControl->p1);
		break;
	case ft_XEle_GetParentEle:
		ret = (int)XEle_GetParentEle((HELE)pControl->p1);
		break;
	case ft_XEle_GetParent:
		ret = (int)XEle_GetParent((HELE)pControl->p1);
		break;
	case ft_XEle_SetTextColor:
		XEle_SetTextColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XEle_GetTextColor:
		ret = (int)XEle_GetTextColor((HELE)pControl->p1);
		break;
	case ft_XEle_SetFocusBorderColor:
		XEle_SetFocusBorderColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XEle_GetFocusBorderColor:
		ret = (int)XEle_GetFocusBorderColor((HELE)pControl->p1);
		break;
	case ft_XEle_SetFont:
		XEle_SetFont((HELE)pControl->p1,(HFONTX)pControl->p2);
		break;
	case ft_XEle_GetFont:
		ret = (int)XEle_GetFont((HELE)pControl->p1);
		break;
	case ft_XEle_SetAlpha:
		XEle_SetAlpha((HELE)pControl->p1,(BYTE)pControl->p2);
		break;
	case ft_XEle_GetChildCount:
		ret = (int)XEle_GetChildCount((HELE)pControl->p1);
		break;
	case ft_XEle_GetChildByIndex:
		ret = (int)XEle_GetChildByIndex((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XEle_GetChildByID:
		ret = (int)XEle_GetChildByID((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XEle_GetChildShapeCount:
		ret = (int)XEle_GetChildShapeCount((HELE)pControl->p1);
		break;
	case ft_XEle_GetChildShapeByIndex:
		ret = (int)XEle_GetChildShapeByIndex((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XEle_SetBorderSize:
		XEle_SetBorderSize((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XEle_GetBorderSize:
		XEle_GetBorderSize((HELE)pControl->p1,(BorderSize_i*)pControl->p2);
		break;
	case ft_XEle_SetPadding:
		XEle_SetPadding((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XEle_GetPadding:
		XEle_GetPadding((HELE)pControl->p1,(PaddingSize_i*)pControl->p2);
		break;
	case ft_XEle_HitChildEle:
		ret = (int)XEle_HitChildEle((HELE)pControl->p1,(in_ POINT  *)pControl->p2);
		break;
	case ft_XEle_BindLayoutObject:
		XEle_BindLayoutObject((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XEle_GetLayoutObject:
		ret = (int)XEle_GetLayoutObject((HELE)pControl->p1);
		break;
	case ft_XEle_GetParentLayoutObject:
		ret = (int)XEle_GetParentLayoutObject((HELE)pControl->p1);
		break;
	case ft_XEle_SetUserData:
		XEle_SetUserData((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XEle_GetUserData:
		ret = (int)XEle_GetUserData((HELE)pControl->p1);
		break;
	case ft_XEle_GetContentSize:
		XEle_GetContentSize((HELE)pControl->p1,(out_ SIZE*)pControl->p2);
		break;
	case ft_XEle_SetCapture:
		XEle_SetCapture((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_SetLayoutWidth:
		XEle_SetLayoutWidth((HELE)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XEle_SetLayoutHeight:
		XEle_SetLayoutHeight((HELE)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XEle_GetLayoutWidth:
		XEle_GetLayoutWidth((HELE)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XEle_GetLayoutHeight:
		XEle_GetLayoutHeight((HELE)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XEle_RedrawEle:
		XEle_RedrawEle((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_RedrawRect:
		XEle_RedrawRect((HELE)pControl->p1,(RECT *)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XEle_Destroy:
		XEle_Destroy((HELE)pControl->p1);
		break;
	case ft_XEle_AddBkBorder:
		XEle_AddBkBorder((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3,(int)pControl->p4);
		break;
	case ft_XEle_AddBkFill:
		XEle_AddBkFill((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XEle_AddBkImage:
		XEle_AddBkImage((HELE)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XEle_GetBkInfoCount:
		ret = (int)XEle_GetBkInfoCount((HELE)pControl->p1);
		break;
	case ft_XEle_ClearBkInfo:
		XEle_ClearBkInfo((HELE)pControl->p1);
		break;
	case ft_XEle_GetBkManager:
		ret = (int)XEle_GetBkManager((HELE)pControl->p1);
		break;
	case ft_XEle_GetStateFlags:
		ret = (int)XEle_GetStateFlags((HELE)pControl->p1);
		break;
	case ft_XEle_DrawFocus:
		ret = (int)XEle_DrawFocus((HELE)pControl->p1,(HDRAW)pControl->p2,(RECT*)pControl->p3);
		break;
	case ft_XEle_DrawEle:
		XEle_DrawEle((HELE)pControl->p1,(HDRAW)pControl->p2);
		break;
	case ft_XEle_EnableTransparentChannel:
		XEle_EnableTransparentChannel((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XEle_SetXCTimer:
		ret = (int)XEle_SetXCTimer((HELE)pControl->p1,(UINT)pControl->p2,(UINT)pControl->p3);
		break;
	case ft_XEle_KillXCTimer:
		ret = (int)XEle_KillXCTimer((HELE)pControl->p1,(UINT)pControl->p2);
		break;
	case ft_XEle_SetToolTip:
		XEle_SetToolTip((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XEle_GetToolTip:
		XEle_GetToolTip((HELE)pControl->p1,(out_ wchar_t  *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XEle_PopupToolTip:
		XEle_PopupToolTip((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XEle_AdjustLayoutObject:
		XEle_AdjustLayoutObject((HELE)pControl->p1);
		break;
	case ft_XEle_AdjustLayout:
		XEle_AdjustLayout((HELE)pControl->p1);
		break;
	case ft_XEle_RegEventTest:
		ret = (int)XEle_RegEventTest((int)pControl->p1,(BYTE*)pControl->p2);
		break;
	case ft_XFont_Create:
		ret = (int)XFont_Create((int)pControl->p1);
		break;
	case ft_XFont_Create2:
		ret = (int)XFont_Create2((const wchar_t *)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XFont_Create3:
		ret = (int)XFont_Create3((const xc_font_info_i*)pControl->p1);
		break;
	case ft_XFont_CreateEx:
		ret = (int)XFont_CreateEx((LOGFONTW *)pControl->p1);
		break;
	case ft_XFont_CreateFromHFONT:
		ret = (int)XFont_CreateFromHFONT((HFONT)pControl->p1);
		break;
	case ft_XFont_CreateFromFont:
		ret = (int)XFont_CreateFromFont((void*)pControl->p1);
		break;
	case ft_XFont_CreateFromFile:
		ret = (int)XFont_CreateFromFile((const wchar_t*)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XFont_EnableAutoDestroy:
		XFont_EnableAutoDestroy((HFONTX)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XFont_GetFont:
		ret = (int)XFont_GetFont((HFONTX)pControl->p1);
		break;
	case ft_XFont_GetFontInfo:
		XFont_GetFontInfo((HFONTX)pControl->p1,(out_ xc_font_info_i*)pControl->p2);
		break;
	case ft_XFont_AddRef:
		XFont_AddRef((HFONTX)pControl->p1);
		break;
	case ft_XFont_Release:
		XFont_Release((HFONTX)pControl->p1);
		break;
	case ft_XFont_GetRefCount:
		ret = (int)XFont_GetRefCount((HFONTX)pControl->p1);
		break;
	case ft_XFont_Destroy:
		XFont_Destroy((HFONTX)pControl->p1);
		break;
	case ft_XFrameWnd_Create:
		ret = (int)XFrameWnd_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(const wchar_t *)pControl->p5,(HWND)pControl->p6,(int)pControl->p7);
		break;
	case ft_XFrameWnd_CreateEx:
		ret = (int)XFrameWnd_CreateEx((DWORD)pControl->p1,(wchar_t*)pControl->p2,(wchar_t*)pControl->p3,(DWORD)pControl->p4,(int)pControl->p5,(int)pControl->p6,(int)pControl->p7,(int)pControl->p8,(HWND)pControl->p9,(int)pControl->p10);
		break;
	case ft_XFrameWnd_GetLayoutAreaRect:
		XFrameWnd_GetLayoutAreaRect((HWINDOW)pControl->p1,(out_ RECT *)pControl->p2);
		break;
	case ft_XFrameWnd_SetView:
		XFrameWnd_SetView((HWINDOW)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XFrameWnd_SetPaneSplitBarColor:
		XFrameWnd_SetPaneSplitBarColor((HWINDOW)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XFrameWnd_SaveLayoutToFile:
		ret = (int)XFrameWnd_SaveLayoutToFile((HWINDOW)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XFrameWnd_LoadLayoutFile:
		ret = (int)XFrameWnd_LoadLayoutFile((HWINDOW)pControl->p1,(HELE*)pControl->p2,(int)pControl->p3,(const wchar_t*)pControl->p4);
		break;
	case ft_XFrameWnd_AddPane:
		ret = (int)XFrameWnd_AddPane((HWINDOW)pControl->p1,(HELE)pControl->p2,(HELE)pControl->p3,(align_type_)pControl->p4);
		break;
	case ft_XFrameWnd_MergePane:
		ret = (int)XFrameWnd_MergePane((HWINDOW)pControl->p1,(HELE)pControl->p2,(HELE)pControl->p3);
		break;
	case ft_XImage_LoadFile:
		ret = (int)XImage_LoadFile((const wchar_t *)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XImage_LoadFileAdaptive:
		ret = (int)XImage_LoadFileAdaptive((const wchar_t *)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XImage_LoadFileRect:
		ret = (int)XImage_LoadFileRect((const wchar_t *)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XImage_LoadResAdaptive:
		ret = (int)XImage_LoadResAdaptive((int)pControl->p1,(const wchar_t *)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XImage_LoadRes:
		ret = (int)XImage_LoadRes((int)pControl->p1,(const wchar_t *)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XImage_LoadZip:
		ret = (int)XImage_LoadZip((const wchar_t *)pControl->p1,(const wchar_t *)pControl->p2,(const wchar_t *)pControl->p3,(BOOL)pControl->p4);
		break;
	case ft_XImage_LoadZipAdaptive:
		ret = (int)XImage_LoadZipAdaptive((const wchar_t *)pControl->p1,(const wchar_t *)pControl->p2,(const wchar_t *)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6,(int)pControl->p7);
		break;
	case ft_XImage_LoadZipRect:
		ret = (int)XImage_LoadZipRect((const wchar_t *)pControl->p1,(const wchar_t *)pControl->p2,(const wchar_t *)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6,(int)pControl->p7);
		break;
	case ft_XImage_LoadMemory:
		ret = (int)XImage_LoadMemory((void*)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XImage_LoadMemoryRect:
		ret = (int)XImage_LoadMemoryRect((void*)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6,(BOOL)pControl->p7);
		break;
	case ft_XImage_LoadMemoryAdaptive:
		ret = (int)XImage_LoadMemoryAdaptive((void*)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XImage_LoadFromImage:
		ret = (int)XImage_LoadFromImage((void *)pControl->p1);
		break;
	case ft_XImage_LoadFileFromExtractIcon:
		ret = (int)XImage_LoadFileFromExtractIcon((const wchar_t *)pControl->p1);
		break;
	case ft_XImage_LoadFileFromHICON:
		ret = (int)XImage_LoadFileFromHICON((HICON)pControl->p1);
		break;
	case ft_XImage_LoadFileFromHBITMAP:
		ret = (int)XImage_LoadFileFromHBITMAP((HBITMAP)pControl->p1);
		break;
	case ft_XImage_IsStretch:
		ret = (int)XImage_IsStretch((HIMAGE)pControl->p1);
		break;
	case ft_XImage_IsAdaptive:
		ret = (int)XImage_IsAdaptive((HIMAGE)pControl->p1);
		break;
	case ft_XImage_IsTile:
		ret = (int)XImage_IsTile((HIMAGE)pControl->p1);
		break;
	case ft_XImage_SetDrawType:
		ret = (int)XImage_SetDrawType((HIMAGE)pControl->p1,(image_draw_type_)pControl->p2);
		break;
	case ft_XImage_SetDrawTypeAdaptive:
		ret = (int)XImage_SetDrawTypeAdaptive((HIMAGE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XImage_SetTranColor:
		XImage_SetTranColor((HIMAGE)pControl->p1,(COLORREF)pControl->p2);
		break;
	case ft_XImage_SetTranColorEx:
		XImage_SetTranColorEx((HIMAGE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XImage_SetRotateAngle:
		ret = (int)XImage_SetRotateAngle((HIMAGE)pControl->p1,(float)pControl->p2);
		break;
	case ft_XImage_EnableTranColor:
		XImage_EnableTranColor((HIMAGE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XImage_EnableAutoDestroy:
		XImage_EnableAutoDestroy((HIMAGE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XImage_EnableCenter:
		XImage_EnableCenter((HIMAGE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XImage_IsCenter:
		ret = (int)XImage_IsCenter((HIMAGE)pControl->p1);
		break;
	case ft_XImage_GetDrawType:
		ret = (int)XImage_GetDrawType((HIMAGE)pControl->p1);
		break;
	case ft_XImage_GetWidth:
		ret = (int)XImage_GetWidth((HIMAGE)pControl->p1);
		break;
	case ft_XImage_GetHeight:
		ret = (int)XImage_GetHeight((HIMAGE)pControl->p1);
		break;
	case ft_XImage_AddRef:
		XImage_AddRef((HIMAGE)pControl->p1);
		break;
	case ft_XImage_Release:
		XImage_Release((HIMAGE)pControl->p1);
		break;
	case ft_XImage_GetRefCount:
		ret = (int)XImage_GetRefCount((HIMAGE)pControl->p1);
		break;
	case ft_XImage_Destroy:
		XImage_Destroy((HIMAGE)pControl->p1);
		break;
	case ft_XLayout_Create:
		ret = (int)XLayout_Create();
		break;
	case ft_XLayout_Destroy:
		XLayout_Destroy((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_AddEle:
		XLayout_AddEle((HXCGUI)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XLayout_AddLayoutObject:
		XLayout_AddLayoutObject((HXCGUI)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XLayout_AddShape:
		XLayout_AddShape((HXCGUI)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XLayout_Add:
		ret = (int)XLayout_Add((HXCGUI)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XLayout_Insert:
		ret = (int)XLayout_Insert((HXCGUI)pControl->p1,(HXCGUI)pControl->p2,(int)pControl->p3);
		break;
	case ft_XLayout_RemoveLayout:
		XLayout_RemoveLayout((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_RemoveChild:
		XLayout_RemoveChild((HXCGUI)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XLayout_GetZOrder:
		ret = (int)XLayout_GetZOrder((HXCGUI)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XLayout_AdjustLayout:
		XLayout_AdjustLayout((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_SetRectFrame:
		XLayout_SetRectFrame((HXCGUI)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XLayout_GetRect:
		XLayout_GetRect((HXCGUI)pControl->p1,(out_ RECT *)pControl->p2);
		break;
	case ft_XLayout_GetRectFrame:
		XLayout_GetRectFrame((HXCGUI)pControl->p1,(out_ RECT *)pControl->p2);
		break;
	case ft_XLayout_GetWindow:
		ret = (int)XLayout_GetWindow((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetEle:
		ret = (int)XLayout_GetEle((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetParentLayout:
		ret = (int)XLayout_GetParentLayout((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetParent:
		ret = (int)XLayout_GetParent((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_SetID:
		XLayout_SetID((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XLayout_GetID:
		ret = (int)XLayout_GetID((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_SetUID:
		XLayout_SetUID((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XLayout_GetUID:
		ret = (int)XLayout_GetUID((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_SetHorizon:
		XLayout_SetHorizon((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XLayout_SetAlignH:
		XLayout_SetAlignH((HXCGUI)pControl->p1,(layout_align_)pControl->p2);
		break;
	case ft_XLayout_SetAlignV:
		XLayout_SetAlignV((HXCGUI)pControl->p1,(layout_align_)pControl->p2);
		break;
	case ft_XLayout_SetPadding:
		XLayout_SetPadding((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XLayout_SetSpace:
		XLayout_SetSpace((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XLayout_SetLayoutWidth:
		XLayout_SetLayoutWidth((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XLayout_SetLayoutHeight:
		XLayout_SetLayoutHeight((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XLayout_GetLayoutWidth:
		XLayout_GetLayoutWidth((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XLayout_GetLayoutHeight:
		XLayout_GetLayoutHeight((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XLayout_GetWidth:
		ret = (int)XLayout_GetWidth((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetHeight:
		ret = (int)XLayout_GetHeight((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetWidthIn:
		ret = (int)XLayout_GetWidthIn((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetHeightIn:
		ret = (int)XLayout_GetHeightIn((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetContentSize:
		XLayout_GetContentSize((HXCGUI)pControl->p1,(out_ SIZE*)pControl->p2);
		break;
	case ft_XLayout_ShowLayout:
		XLayout_ShowLayout((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XLayout_GetChildCount:
		ret = (int)XLayout_GetChildCount((HXCGUI)pControl->p1);
		break;
	case ft_XLayout_GetChildType:
		ret = (int)XLayout_GetChildType((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XLayout_GetChild:
		ret = (int)XLayout_GetChild((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XLayout_Draw:
		XLayout_Draw((HXCGUI)pControl->p1,(HDRAW)pControl->p2);
		break;
	case ft_Layout_SetEle:
		Layout_SetEle((HXCGUI)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XListBox_Create:
		ret = (int)XListBox_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XListBox_SetDrawItemBkFlags:
		XListBox_SetDrawItemBkFlags((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListBox_SetItemData:
		ret = (int)XListBox_SetItemData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListBox_GetItemData:
		ret = (int)XListBox_GetItemData((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListBox_SetItemInfo:
		ret = (int)XListBox_SetItemInfo((HELE)pControl->p1,(int)pControl->p2,(in_ listBox_item_info_i *)pControl->p3);
		break;
	case ft_XListBox_GetItemInfo:
		ret = (int)XListBox_GetItemInfo((HELE)pControl->p1,(int)pControl->p2,(out_ listBox_item_info_i *)pControl->p3);
		break;
	case ft_XListBox_AddItemBkBorder:
		XListBox_AddItemBkBorder((HELE)pControl->p1,(list_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4,(int)pControl->p5);
		break;
	case ft_XListBox_AddItemBkFill:
		XListBox_AddItemBkFill((HELE)pControl->p1,(list_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XListBox_AddItemBkImage:
		XListBox_AddItemBkImage((HELE)pControl->p1,(list_item_state_)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XListBox_GetItemBkInfoCount:
		ret = (int)XListBox_GetItemBkInfoCount((HELE)pControl->p1);
		break;
	case ft_XListBox_ClearItemBkInfo:
		XListBox_ClearItemBkInfo((HELE)pControl->p1);
		break;
	case ft_XListBox_SetSelectItem:
		ret = (int)XListBox_SetSelectItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListBox_GetSelectItem:
		ret = (int)XListBox_GetSelectItem((HELE)pControl->p1);
		break;
	case ft_XListBox_CancelSelectItem:
		ret = (int)XListBox_CancelSelectItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListBox_CancelSelectAll:
		ret = (int)XListBox_CancelSelectAll((HELE)pControl->p1);
		break;
	case ft_XListBox_GetSelectAll:
		ret = (int)XListBox_GetSelectAll((HELE)pControl->p1,(out_ int *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListBox_GetSelectCount:
		ret = (int)XListBox_GetSelectCount((HELE)pControl->p1);
		break;
	case ft_XListBox_GetItemMouseStay:
		ret = (int)XListBox_GetItemMouseStay((HELE)pControl->p1);
		break;
	case ft_XListBox_SelectAll:
		ret = (int)XListBox_SelectAll((HELE)pControl->p1);
		break;
	case ft_XListBox_SetItemHeightDefault:
		XListBox_SetItemHeightDefault((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListBox_GetItemHeightDefault:
		XListBox_GetItemHeightDefault((HELE)pControl->p1,(out_ int *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XListBox_GetItemIndexFromHXCGUI:
		ret = (int)XListBox_GetItemIndexFromHXCGUI((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XListBox_SetRowSpace:
		XListBox_SetRowSpace((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListBox_GetRowSpace:
		ret = (int)XListBox_GetRowSpace((HELE)pControl->p1);
		break;
	case ft_XListBox_HitTest:
		ret = (int)XListBox_HitTest((HELE)pControl->p1,(POINT *)pControl->p2);
		break;
	case ft_XListBox_HitTestOffset:
		ret = (int)XListBox_HitTestOffset((HELE)pControl->p1,(POINT *)pControl->p2);
		break;
	case ft_XListBox_SetItemTemplateXML:
		ret = (int)XListBox_SetItemTemplateXML((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XListBox_SetItemTemplateXMLFromString:
		ret = (int)XListBox_SetItemTemplateXMLFromString((HELE)pControl->p1,(const char*)pControl->p2);
		break;
	case ft_XListBox_GetTemplateObject:
		ret = (int)XListBox_GetTemplateObject((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListBox_EnableMultiSel:
		XListBox_EnableMultiSel((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XListBox_CreateAdapter:
		ret = (int)XListBox_CreateAdapter((HELE)pControl->p1);
		break;
	case ft_XListBox_BindAdapter:
		XListBox_BindAdapter((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XListBox_GetAdapter:
		ret = (int)XListBox_GetAdapter((HELE)pControl->p1);
		break;
	case ft_XListBox_Sort:
		XListBox_Sort((HELE)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XListBox_RefreshData:
		XListBox_RefreshData((HELE)pControl->p1);
		break;
	case ft_XListBox_RefreshItem:
		XListBox_RefreshItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTemp_Load:
		ret = (int)XTemp_Load((XC_OBJECT_TYPE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XTemp_LoadFromString:
		ret = (int)XTemp_LoadFromString((XC_OBJECT_TYPE)pControl->p1,(const char*)pControl->p2);
		break;
	case ft_XTemp_Destroy:
		ret = (int)XTemp_Destroy((HTEMP)pControl->p1);
		break;
	case ft_XTemp_Create:
		ret = (int)XTemp_Create((XC_OBJECT_TYPE)pControl->p1);
		break;
	case ft_XTemp_AddNodeRoot:
		ret = (int)XTemp_AddNodeRoot((HTEMP)pControl->p1,(void*)pControl->p2);
		break;
	case ft_XTemp_AddNode:
		ret = (int)XTemp_AddNode((void*)pControl->p1,(void*)pControl->p2);
		break;
	case ft_XTemp_CreateNode:
		ret = (int)XTemp_CreateNode((XC_OBJECT_TYPE)pControl->p1);
		break;
	case ft_XTemp_SetNodeAttribute:
		ret = (int)XTemp_SetNodeAttribute((void*)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XList_Create:
		ret = (int)XList_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XList_AddColumn:
		ret = (int)XList_AddColumn((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_InsertColumn:
		ret = (int)XList_InsertColumn((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_EnableMultiSel:
		XList_EnableMultiSel((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XList_EnableDragChangeColumnWidth:
		XList_EnableDragChangeColumnWidth((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XList_EnableVScrollBarTop:
		XList_EnableVScrollBarTop((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XList_EnableItemBkFullRow:
		XList_EnableItemBkFullRow((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XList_SetSort:
		XList_SetSort((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(BOOL)pControl->p4);
		break;
	case ft_XList_SetDrawItemBkFlags:
		XList_SetDrawItemBkFlags((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_SetColumnWidth:
		XList_SetColumnWidth((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_SetColumnMinWidth:
		XList_SetColumnMinWidth((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_SetColumnWidthFixed:
		XList_SetColumnWidthFixed((HELE)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XList_GetColumnWidth:
		ret = (int)XList_GetColumnWidth((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_GetColumnCount:
		ret = (int)XList_GetColumnCount((HELE)pControl->p1);
		break;
	case ft_XList_DeleteColumn:
		ret = (int)XList_DeleteColumn((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_DeleteColumnAll:
		XList_DeleteColumnAll((HELE)pControl->p1);
		break;
	case ft_XList_SetItemData:
		ret = (int)XList_SetItemData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XList_GetItemData:
		ret = (int)XList_GetItemData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_SetSelectItem:
		ret = (int)XList_SetSelectItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_GetSelectItem:
		ret = (int)XList_GetSelectItem((HELE)pControl->p1);
		break;
	case ft_XList_GetSelectItemCount:
		ret = (int)XList_GetSelectItemCount((HELE)pControl->p1);
		break;
	case ft_XList_SetSelectAll:
		XList_SetSelectAll((HELE)pControl->p1);
		break;
	case ft_XList_GetSelectAll:
		ret = (int)XList_GetSelectAll((HELE)pControl->p1,(out_ int *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_CancelSelectItem:
		ret = (int)XList_CancelSelectItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_CancelSelectAll:
		XList_CancelSelectAll((HELE)pControl->p1);
		break;
	case ft_XList_GetHeaderHELE:
		ret = (int)XList_GetHeaderHELE((HELE)pControl->p1);
		break;
	case ft_XList_BindAdapter:
		XList_BindAdapter((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XList_BindAdapterHeader:
		XList_BindAdapterHeader((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XList_CreateAdapter:
		ret = (int)XList_CreateAdapter((HELE)pControl->p1);
		break;
	case ft_XList_CreateAdapterHeader:
		ret = (int)XList_CreateAdapterHeader((HELE)pControl->p1);
		break;
	case ft_XList_GetAdapter:
		ret = (int)XList_GetAdapter((HELE)pControl->p1);
		break;
	case ft_XList_GetAdapterHeader:
		ret = (int)XList_GetAdapterHeader((HELE)pControl->p1);
		break;
	case ft_XList_SetItemTemplateXML:
		ret = (int)XList_SetItemTemplateXML((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XList_SetItemTemplateXMLFromString:
		ret = (int)XList_SetItemTemplateXMLFromString((HELE)pControl->p1,(const char*)pControl->p2);
		break;
	case ft_XList_GetTemplateObject:
		ret = (int)XList_GetTemplateObject((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_GetItemIndexFromHXCGUI:
		ret = (int)XList_GetItemIndexFromHXCGUI((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XList_GetHeaderTemplateObject:
		ret = (int)XList_GetHeaderTemplateObject((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_GetHeaderItemIndexFromHXCGUI:
		ret = (int)XList_GetHeaderItemIndexFromHXCGUI((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XList_SetHeaderHeight:
		XList_SetHeaderHeight((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_GetHeaderHeight:
		ret = (int)XList_GetHeaderHeight((HELE)pControl->p1);
		break;
	case ft_XList_AddItemBkBorder:
		XList_AddItemBkBorder((HELE)pControl->p1,(list_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4,(int)pControl->p5);
		break;
	case ft_XList_AddItemBkFill:
		XList_AddItemBkFill((HELE)pControl->p1,(list_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XList_AddItemBkImage:
		XList_AddItemBkImage((HELE)pControl->p1,(list_item_state_)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XList_GetItemBkInfoCount:
		ret = (int)XList_GetItemBkInfoCount((HELE)pControl->p1);
		break;
	case ft_XList_ClearItemBkInfo:
		XList_ClearItemBkInfo((HELE)pControl->p1);
		break;
	case ft_XList_SetItemHeightDefault:
		XList_SetItemHeightDefault((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XList_GetItemHeightDefault:
		XList_GetItemHeightDefault((HELE)pControl->p1,(out_ int *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XList_SetRowSpace:
		XList_SetRowSpace((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XList_GetRowSpace:
		ret = (int)XList_GetRowSpace((HELE)pControl->p1);
		break;
	case ft_XList_HitTest:
		ret = (int)XList_HitTest((HELE)pControl->p1,(POINT *)pControl->p2,(out_ int *)pControl->p3,(out_ int *)pControl->p4);
		break;
	case ft_XList_HitTestOffset:
		ret = (int)XList_HitTestOffset((HELE)pControl->p1,(POINT *)pControl->p2,(out_ int *)pControl->p3,(out_ int *)pControl->p4);
		break;
	case ft_XList_RefreshData:
		XList_RefreshData((HELE)pControl->p1);
		break;
	case ft_XList_RefreshItem:
		XList_RefreshItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_Create:
		ret = (int)XListView_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XListView_CreateAdapter:
		ret = (int)XListView_CreateAdapter((HELE)pControl->p1);
		break;
	case ft_XListView_BindAdapter:
		XListView_BindAdapter((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XListView_GetAdapter:
		ret = (int)XListView_GetAdapter((HELE)pControl->p1);
		break;
	case ft_XListView_SetItemTemplateXML:
		ret = (int)XListView_SetItemTemplateXML((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XListView_SetItemTemplateXMLFromString:
		ret = (int)XListView_SetItemTemplateXMLFromString((HELE)pControl->p1,(const char*)pControl->p2);
		break;
	case ft_XListView_GetTemplateObject:
		ret = (int)XListView_GetTemplateObject((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XListView_GetTemplateObjectGroup:
		ret = (int)XListView_GetTemplateObjectGroup((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListView_GetItemIDFromHXCGUI:
		ret = (int)XListView_GetItemIDFromHXCGUI((HELE)pControl->p1,(HXCGUI)pControl->p2,(out_ int*)pControl->p3,(out_ int*)pControl->p4);
		break;
	case ft_XListView_HitTest:
		ret = (int)XListView_HitTest((HELE)pControl->p1,(in_ POINT*)pControl->p2,(out_ int*)pControl->p3,(out_ int*)pControl->p4);
		break;
	case ft_XListView_HitTestOffset:
		ret = (int)XListView_HitTestOffset((HELE)pControl->p1,(in_ POINT *)pControl->p2,(out_ int*)pControl->p3,(out_ int*)pControl->p4);
		break;
	case ft_XListView_EnableMultiSel:
		XListView_EnableMultiSel((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XListView_SetDrawItemBkFlags:
		XListView_SetDrawItemBkFlags((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_SetSelectItem:
		ret = (int)XListView_SetSelectItem((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListView_GetSelectItem:
		ret = (int)XListView_GetSelectItem((HELE)pControl->p1,(int *)pControl->p2,(int *)pControl->p3);
		break;
	case ft_XListView_GetSelectItemCount:
		ret = (int)XListView_GetSelectItemCount((HELE)pControl->p1);
		break;
	case ft_XListView_GetSelectItemAll:
		ret = (int)XListView_GetSelectItemAll((HELE)pControl->p1,(out_ listView_item_id_i *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListView_SetSelectItemAll:
		XListView_SetSelectItemAll((HELE)pControl->p1);
		break;
	case ft_XListView_CancelSelectItemAll:
		XListView_CancelSelectItemAll((HELE)pControl->p1);
		break;
	case ft_XListView_SetColumnSpace:
		XListView_SetColumnSpace((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_SetRowSpace:
		XListView_SetRowSpace((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_SetAlignSizeLeft:
		XListView_SetAlignSizeLeft((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_SetAlignSizeTop:
		XListView_SetAlignSizeTop((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_SetItemSize:
		XListView_SetItemSize((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListView_GetItemSize:
		XListView_GetItemSize((HELE)pControl->p1,(SIZE*)pControl->p2);
		break;
	case ft_XListView_SetGroupHeight:
		XListView_SetGroupHeight((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_GetGroupHeight:
		ret = (int)XListView_GetGroupHeight((HELE)pControl->p1);
		break;
	case ft_XListView_SetGroupUserData:
		XListView_SetGroupUserData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListView_SetItemUserData:
		XListView_SetItemUserData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XListView_GetGroupUserData:
		ret = (int)XListView_GetGroupUserData((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XListView_GetItemUserData:
		ret = (int)XListView_GetItemUserData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListView_AddItemBkBorder:
		XListView_AddItemBkBorder((HELE)pControl->p1,(list_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4,(int)pControl->p5);
		break;
	case ft_XListView_AddItemBkFill:
		XListView_AddItemBkFill((HELE)pControl->p1,(list_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XListView_AddItemBkImage:
		XListView_AddItemBkImage((HELE)pControl->p1,(list_item_state_)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XListView_GetItemBkInfoCount:
		ret = (int)XListView_GetItemBkInfoCount((HELE)pControl->p1);
		break;
	case ft_XListView_ClearItemBkInfo:
		XListView_ClearItemBkInfo((HELE)pControl->p1);
		break;
	case ft_XListView_RefreshData:
		XListView_RefreshData((HELE)pControl->p1);
		break;
	case ft_XListView_RefreshItem:
		XListView_RefreshItem((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XListView_ExpandGroup:
		ret = (int)XListView_ExpandGroup((HELE)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XMenuBar_Create:
		ret = (int)XMenuBar_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XMenuBar_AddButton:
		ret = (int)XMenuBar_AddButton((HELE)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XMenuBar_SetButtonHeight:
		XMenuBar_SetButtonHeight((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XMenuBar_GetMenu:
		ret = (int)XMenuBar_GetMenu((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XMenuBar_DeleteButton:
		ret = (int)XMenuBar_DeleteButton((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XMenu_Create:
		ret = (int)XMenu_Create();
		break;
	case ft_XMenu_AddItem:
		XMenu_AddItem((HMENUX)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XMenu_AddItemIcon:
		XMenu_AddItemIcon((HMENUX)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(int)pControl->p4,(HIMAGE)pControl->p5,(int)pControl->p6);
		break;
	case ft_XMenu_InsertItem:
		XMenu_InsertItem((HMENUX)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XMenu_InsertItemIcon:
		XMenu_InsertItemIcon((HMENUX)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(HIMAGE)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XMenu_SetAutoDestroy:
		XMenu_SetAutoDestroy((HMENUX)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XMenu_EnableDrawBackground:
		XMenu_EnableDrawBackground((HMENUX)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XMenu_EnableDrawItem:
		XMenu_EnableDrawItem((HMENUX)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XMenu_Popup:
		ret = (int)XMenu_Popup((HMENUX)pControl->p1,(HWND)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HELE)pControl->p5,(menu_popup_position_)pControl->p6);
		break;
	case ft_XMenu_DestroyMenu:
		XMenu_DestroyMenu((HMENUX)pControl->p1);
		break;
	case ft_XMenu_CloseMenu:
		XMenu_CloseMenu((HMENUX)pControl->p1);
		break;
	case ft_XMenu_SetBkImage:
		XMenu_SetBkImage((HMENUX)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XMenu_SetItemText:
		ret = (int)XMenu_SetItemText((HMENUX)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3);
		break;
	case ft_XMenu_GetItemText:
		ret = (int)XMenu_GetItemText((HMENUX)pControl->p1,(int)pControl->p2,(out_ wchar_t *)pControl->p3,(int)pControl->p4);
		break;
	case ft_XMenu_GetItemTextLength:
		ret = (int)XMenu_GetItemTextLength((HMENUX)pControl->p1,(int)pControl->p2);
		break;
	case ft_XMenu_SetItemIcon:
		ret = (int)XMenu_SetItemIcon((HMENUX)pControl->p1,(int)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XMenu_SetItemFlags:
		ret = (int)XMenu_SetItemFlags((HMENUX)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XMenu_SetItemHeight:
		XMenu_SetItemHeight((HMENUX)pControl->p1,(int)pControl->p2);
		break;
	case ft_XMenu_GetItemHeight:
		ret = (int)XMenu_GetItemHeight((HMENUX)pControl->p1);
		break;
	case ft_XMenu_SetBorderColor:
		XMenu_SetBorderColor((HMENUX)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XMenu_GetLeftWidth:
		ret = (int)XMenu_GetLeftWidth((HMENUX)pControl->p1);
		break;
	case ft_XMenu_GetLeftSpaceText:
		ret = (int)XMenu_GetLeftSpaceText((HMENUX)pControl->p1);
		break;
	case ft_XMenu_GetItemCount:
		ret = (int)XMenu_GetItemCount((HMENUX)pControl->p1);
		break;
	case ft_XMenu_SetItemCheck:
		ret = (int)XMenu_SetItemCheck((HMENUX)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XMenu_IsItemCheck:
		ret = (int)XMenu_IsItemCheck((HMENUX)pControl->p1,(int)pControl->p2);
		break;
	case ft_XModalWnd_Create:
		ret = (int)XModalWnd_Create((int)pControl->p1,(int)pControl->p2,(const wchar_t *)pControl->p3,(HWND)pControl->p4,(int)pControl->p5);
		break;
	case ft_XModalWnd_CreateEx:
		ret = (int)XModalWnd_CreateEx((DWORD)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3,(DWORD)pControl->p4,(int)pControl->p5,(int)pControl->p6,(int)pControl->p7,(int)pControl->p8,(HWND)pControl->p9,(int)pControl->p10);
		break;
	case ft_XModalWnd_EnableAutoClose:
		XModalWnd_EnableAutoClose((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XModalWnd_EnableEscClose:
		XModalWnd_EnableEscClose((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XModalWnd_DoModal:
		ret = (int)XModalWnd_DoModal((HWINDOW)pControl->p1);
		break;
	case ft_XModalWnd_EndModal:
		XModalWnd_EndModal((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XPane_Create:
		ret = (int)XPane_Create((const wchar_t *)pControl->p1,(int)pControl->p2,(int)pControl->p3,(HWINDOW)pControl->p4);
		break;
	case ft_XPane_SetView:
		XPane_SetView((HELE)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XPane_IsShowPane:
		ret = (int)XPane_IsShowPane((HELE)pControl->p1);
		break;
	case ft_XPane_SetSize:
		XPane_SetSize((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XPane_GetState:
		ret = (int)XPane_GetState((HELE)pControl->p1);
		break;
	case ft_XPane_GetViewRect:
		XPane_GetViewRect((HELE)pControl->p1,(out_ RECT*)pControl->p2);
		break;
	case ft_XPane_SetTitle:
		XPane_SetTitle((HELE)pControl->p1,(wchar_t*)pControl->p2);
		break;
	case ft_XPane_GetTitle:
		XPane_GetTitle((HELE)pControl->p1,(out_ wchar_t*)pControl->p2,(int)pControl->p3);
		break;
	case ft_XPane_SetCaptionHeight:
		XPane_SetCaptionHeight((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XPane_GetCaptionHeight:
		ret = (int)XPane_GetCaptionHeight((HELE)pControl->p1);
		break;
	case ft_XPane_HidePane:
		XPane_HidePane((HELE)pControl->p1);
		break;
	case ft_XPane_ShowPane:
		XPane_ShowPane((HELE)pControl->p1);
		break;
	case ft_XPane_DockPane:
		XPane_DockPane((HELE)pControl->p1);
		break;
	case ft_XPane_LockPane:
		XPane_LockPane((HELE)pControl->p1);
		break;
	case ft_XPane_FloatPane:
		XPane_FloatPane((HELE)pControl->p1);
		break;
	case ft_XFloatWnd_EnableCaptionContent:
		ret = (int)XFloatWnd_EnableCaptionContent((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XFloatWnd_GetCaptionLayout:
		ret = (int)XFloatWnd_GetCaptionLayout((HWINDOW)pControl->p1);
		break;
	case ft_XFloatWnd_GetCaptionShapeText:
		ret = (int)XFloatWnd_GetCaptionShapeText((HWINDOW)pControl->p1);
		break;
	case ft_XFloatWnd_GetCaptionButtonClose:
		ret = (int)XFloatWnd_GetCaptionButtonClose((HWINDOW)pControl->p1);
		break;
	case ft_XFloatWnd_SetTitle:
		XFloatWnd_SetTitle((HWINDOW)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XFloatWnd_GetTitle:
		XFloatWnd_GetTitle((HWINDOW)pControl->p1,(out_ wchar_t*)pControl->p2,(int)pControl->p3);
		break;
	case ft_XProgBar_Create:
		ret = (int)XProgBar_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XProgBar_SetRange:
		XProgBar_SetRange((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XProgBar_GetRange:
		ret = (int)XProgBar_GetRange((HELE)pControl->p1);
		break;
	case ft_XProgBar_SetSpaceTwo:
		XProgBar_SetSpaceTwo((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XProgBar_SetPos:
		XProgBar_SetPos((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XProgBar_GetPos:
		ret = (int)XProgBar_GetPos((HELE)pControl->p1);
		break;
	case ft_XProgBar_SetHorizon:
		XProgBar_SetHorizon((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XProgBar_SetImageLoad:
		XProgBar_SetImageLoad((HELE)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XPGrid_Create:
		ret = (int)XPGrid_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XPGrid_AddItem:
		ret = (int)XPGrid_AddItem((HELE)pControl->p1,(const wchar_t *)pControl->p2,(propertyGrid_item_type_)pControl->p3,(int)pControl->p4);
		break;
	case ft_XPGrid_AddItemString:
		ret = (int)XPGrid_AddItemString((HELE)pControl->p1,(const wchar_t *)pControl->p2,(const wchar_t *)pControl->p3,(int)pControl->p4);
		break;
	case ft_XPGrid_DeleteAll:
		XPGrid_DeleteAll((HELE)pControl->p1);
		break;
	case ft_XPGrid_GetItemHELE:
		ret = (int)XPGrid_GetItemHELE((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XPGrid_SetWidth:
		XPGrid_SetWidth((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XPGrid_SetItemValue:
		ret = (int)XPGrid_SetItemValue((HELE)pControl->p1,(int)pControl->p2,(const wchar_t*)pControl->p3);
		break;
	case ft_XPGrid_SetItemValueInt:
		ret = (int)XPGrid_SetItemValueInt((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XPGrid_SetItemData:
		ret = (int)XPGrid_SetItemData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XPGrid_GetItemData:
		ret = (int)XPGrid_GetItemData((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XPGrid_GetItemValue:
		ret = (int)XPGrid_GetItemValue((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XPGrid_HitTest:
		ret = (int)XPGrid_HitTest((HELE)pControl->p1,(POINT *)pControl->p2,(BOOL *)pControl->p3);
		break;
	case ft_XPGrid_HitTestOffset:
		ret = (int)XPGrid_HitTestOffset((HELE)pControl->p1,(POINT *)pControl->p2,(BOOL *)pControl->p3);
		break;
	case ft_XPGrid_ExpandItem:
		ret = (int)XPGrid_ExpandItem((HELE)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XPGrid_GetSelItem:
		ret = (int)XPGrid_GetSelItem((HELE)pControl->p1);
		break;
	case ft_XPGrid_SetSelItem:
		ret = (int)XPGrid_SetSelItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XPGrid_SetDrawItemBkFlags:
		XPGrid_SetDrawItemBkFlags((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XRichEditColor_Create:
		ret = (int)XRichEditColor_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XRichEditColor_SetColor:
		XRichEditColor_SetColor((HELE)pControl->p1,(COLORREF)pControl->p2);
		break;
	case ft_XRichEditColor_GetColor:
		ret = (int)XRichEditColor_GetColor((HELE)pControl->p1);
		break;
	case ft_XRichEditSet_Create:
		ret = (int)XRichEditSet_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XRichEditFile_Create:
		ret = (int)XRichEditFile_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XRichEditFile_SetOpenFileType:
		XRichEditFile_SetOpenFileType((HELE)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XRichEditFile_SetDefaultFile:
		XRichEditFile_SetDefaultFile((HELE)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XRichEditFile_SetRelativeDir:
		XRichEditFile_SetRelativeDir((HELE)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XRichEditFolder_Create:
		ret = (int)XRichEditFolder_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XRichEditFolder_SetDefaultDir:
		XRichEditFolder_SetDefaultDir((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XRichEdit_Create:
		ret = (int)XRichEdit_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XRichEdit_InsertString:
		XRichEdit_InsertString((HELE)pControl->p1,(const wchar_t *)pControl->p2,(HFONTX)pControl->p3);
		break;
	case ft_XRichEdit_InsertImage:
		ret = (int)XRichEdit_InsertImage((HELE)pControl->p1,(HIMAGE)pControl->p2,(const wchar_t *)pControl->p3);
		break;
	case ft_XRichEdit_InsertGif:
		ret = (int)XRichEdit_InsertGif((HELE)pControl->p1,(HIMAGE)pControl->p2,(const wchar_t *)pControl->p3);
		break;
	case ft_XRichEdit_InsertStringEx:
		XRichEdit_InsertStringEx((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(const wchar_t *)pControl->p4,(HFONTX)pControl->p5);
		break;
	case ft_XRichEdit_InsertImageEx:
		ret = (int)XRichEdit_InsertImageEx((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(HIMAGE)pControl->p4,(const wchar_t *)pControl->p5);
		break;
	case ft_XRichEdit_InsertGifEx:
		ret = (int)XRichEdit_InsertGifEx((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(HIMAGE)pControl->p4,(const wchar_t *)pControl->p5);
		break;
	case ft_XRichEdit_EnableReadOnly:
		XRichEdit_EnableReadOnly((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XRichEdit_EnableMultiLine:
		XRichEdit_EnableMultiLine((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XRichEdit_EnablePassword:
		XRichEdit_EnablePassword((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE:
		XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XRichEdit_EnableAutoWrap:
		XRichEdit_EnableAutoWrap((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XRichEdit_EnableAutoSelAll:
		XRichEdit_EnableAutoSelAll((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XRichEdit_EnableVerticalCenter:
		XRichEdit_EnableVerticalCenter((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XRichEdit_IsEmpty:
		ret = (int)XRichEdit_IsEmpty((HELE)pControl->p1);
		break;
	case ft_XRichEdit_IsReadOnly:
		ret = (int)XRichEdit_IsReadOnly((HELE)pControl->p1);
		break;
	case ft_XRichEdit_IsMultiLine:
		ret = (int)XRichEdit_IsMultiLine((HELE)pControl->p1);
		break;
	case ft_XRichEdit_IsPassword:
		ret = (int)XRichEdit_IsPassword((HELE)pControl->p1);
		break;
	case ft_XRichEdit_IsAutoWrap:
		ret = (int)XRichEdit_IsAutoWrap((HELE)pControl->p1);
		break;
	case ft_XRichEdit_SetLimitNum:
		XRichEdit_SetLimitNum((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XRichEdit_SetCaretColor:
		XRichEdit_SetCaretColor((HELE)pControl->p1,(COLORREF)pControl->p2);
		break;
	case ft_XRichEdit_SetText:
		XRichEdit_SetText((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XRichEdit_SetTextInt:
		XRichEdit_SetTextInt((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XRichEdit_GetText:
		ret = (int)XRichEdit_GetText((HELE)pControl->p1,(out_ wchar_t*)pControl->p2,(int)pControl->p3);
		break;
	case ft_XRichEdit_GetHTMLFormat:
		XRichEdit_GetHTMLFormat((HELE)pControl->p1,(out_ wchar_t*)pControl->p2,(int)pControl->p3);
		break;
	case ft_XRichEdit_GetData:
		ret = (int)XRichEdit_GetData((HELE)pControl->p1,(out_ int *)pControl->p2);
		break;
	case ft_XRichEdit_InsertData:
		ret = (int)XRichEdit_InsertData((HELE)pControl->p1,(void *)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XRichEdit_GetTextLength:
		ret = (int)XRichEdit_GetTextLength((HELE)pControl->p1);
		break;
	case ft_XRichEdit_SetRowHeight:
		XRichEdit_SetRowHeight((HELE)pControl->p1,(UINT)pControl->p2);
		break;
	case ft_XRichEdit_SetDefaultText:
		XRichEdit_SetDefaultText((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XRichEdit_SetDefaultTextColor:
		XRichEdit_SetDefaultTextColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XRichEdit_SetCurrentInputTextColor:
		XRichEdit_SetCurrentInputTextColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XRichEdit_GetCurrentRow:
		ret = (int)XRichEdit_GetCurrentRow((HELE)pControl->p1);
		break;
	case ft_XRichEdit_GetCurrentColumn:
		ret = (int)XRichEdit_GetCurrentColumn((HELE)pControl->p1);
		break;
	case ft_XRichEdit_SetCurrentPos:
		XRichEdit_SetCurrentPos((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XRichEdit_GetRowCount:
		ret = (int)XRichEdit_GetRowCount((HELE)pControl->p1);
		break;
	case ft_XRichEdit_GetRowLength:
		ret = (int)XRichEdit_GetRowLength((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XRichEdit_GetSelectText:
		ret = (int)XRichEdit_GetSelectText((HELE)pControl->p1,(out_ wchar_t*)pControl->p2,(int)pControl->p3);
		break;
	case ft_XRichEdit_GetSelectPosition:
		ret = (int)XRichEdit_GetSelectPosition((HELE)pControl->p1,(out_ Position_i *)pControl->p2,(out_ Position_i *)pControl->p3);
		break;
	case ft_XRichEdit_SetSelect:
		ret = (int)XRichEdit_SetSelect((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XRichEdit_SetItemFontEx:
		ret = (int)XRichEdit_SetItemFontEx((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(HFONTX)pControl->p6);
		break;
	case ft_XRichEdit_SetItemColorEx:
		ret = (int)XRichEdit_SetItemColorEx((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(COLORREF)pControl->p6,(BYTE)pControl->p7);
		break;
	case ft_XRichEdit_CancelSelect:
		XRichEdit_CancelSelect((HELE)pControl->p1);
		break;
	case ft_XRichEdit_SetSelectBkColor:
		XRichEdit_SetSelectBkColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XRichEdit_SelectAll:
		ret = (int)XRichEdit_SelectAll((HELE)pControl->p1);
		break;
	case ft_XRichEdit_DeleteSelect:
		ret = (int)XRichEdit_DeleteSelect((HELE)pControl->p1);
		break;
	case ft_XRichEdit_DeleteAll:
		XRichEdit_DeleteAll((HELE)pControl->p1);
		break;
	case ft_XRichEdit_ClipboardCut:
		ret = (int)XRichEdit_ClipboardCut((HELE)pControl->p1);
		break;
	case ft_XRichEdit_ClipboardCopy:
		ret = (int)XRichEdit_ClipboardCopy((HELE)pControl->p1);
		break;
	case ft_XRichEdit_ClipboardPaste:
		ret = (int)XRichEdit_ClipboardPaste((HELE)pControl->p1);
		break;
	case ft_XSBar_Create:
		ret = (int)XSBar_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XSBar_SetRange:
		XSBar_SetRange((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSBar_GetRange:
		ret = (int)XSBar_GetRange((HELE)pControl->p1);
		break;
	case ft_XSBar_ShowButton:
		XSBar_ShowButton((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XSBar_SetSliderLength:
		XSBar_SetSliderLength((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSBar_SetSliderMinLength:
		XSBar_SetSliderMinLength((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSBar_SetSliderPadding:
		XSBar_SetSliderPadding((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSBar_SetHorizon:
		ret = (int)XSBar_SetHorizon((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XSBar_GetSliderMaxLength:
		ret = (int)XSBar_GetSliderMaxLength((HELE)pControl->p1);
		break;
	case ft_XSBar_ScrollUp:
		ret = (int)XSBar_ScrollUp((HELE)pControl->p1);
		break;
	case ft_XSBar_ScrollDown:
		ret = (int)XSBar_ScrollDown((HELE)pControl->p1);
		break;
	case ft_XSBar_ScrollTop:
		ret = (int)XSBar_ScrollTop((HELE)pControl->p1);
		break;
	case ft_XSBar_ScrollBottom:
		ret = (int)XSBar_ScrollBottom((HELE)pControl->p1);
		break;
	case ft_XSBar_ScrollPos:
		ret = (int)XSBar_ScrollPos((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSBar_GetButtonUp:
		ret = (int)XSBar_GetButtonUp((HELE)pControl->p1);
		break;
	case ft_XSBar_GetButtonDown:
		ret = (int)XSBar_GetButtonDown((HELE)pControl->p1);
		break;
	case ft_XSBar_GetButtonSlider:
		ret = (int)XSBar_GetButtonSlider((HELE)pControl->p1);
		break;
	case ft_XSView_Create:
		ret = (int)XSView_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XSView_SetTotalSize:
		ret = (int)XSView_SetTotalSize((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XSView_GetTotalSize:
		XSView_GetTotalSize((HELE)pControl->p1,(SIZE *)pControl->p2);
		break;
	case ft_XSView_SetLineSize:
		ret = (int)XSView_SetLineSize((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XSView_GetLineSize:
		XSView_GetLineSize((HELE)pControl->p1,(out_ SIZE *)pControl->p2);
		break;
	case ft_XSView_SetScrollBarSize:
		XSView_SetScrollBarSize((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSView_GetViewPosH:
		ret = (int)XSView_GetViewPosH((HELE)pControl->p1);
		break;
	case ft_XSView_GetViewPosV:
		ret = (int)XSView_GetViewPosV((HELE)pControl->p1);
		break;
	case ft_XSView_GetViewWidth:
		ret = (int)XSView_GetViewWidth((HELE)pControl->p1);
		break;
	case ft_XSView_GetViewHeight:
		ret = (int)XSView_GetViewHeight((HELE)pControl->p1);
		break;
	case ft_XSView_GetViewRect:
		XSView_GetViewRect((HELE)pControl->p1,(out_ RECT *)pControl->p2);
		break;
	case ft_XSView_GetScrollBarH:
		ret = (int)XSView_GetScrollBarH((HELE)pControl->p1);
		break;
	case ft_XSView_GetScrollBarV:
		ret = (int)XSView_GetScrollBarV((HELE)pControl->p1);
		break;
	case ft_XSView_SetBorderSize:
		XSView_SetBorderSize((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XSView_GetBorderSize:
		XSView_GetBorderSize((HELE)pControl->p1,(out_ BorderSize_i*)pControl->p2);
		break;
	case ft_XSView_ScrollPosH:
		ret = (int)XSView_ScrollPosH((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSView_ScrollPosV:
		ret = (int)XSView_ScrollPosV((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSView_ScrollPosXH:
		ret = (int)XSView_ScrollPosXH((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSView_ScrollPosYV:
		ret = (int)XSView_ScrollPosYV((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSView_ShowSBarH:
		XSView_ShowSBarH((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XSView_ShowSBarV:
		XSView_ShowSBarV((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XSView_EnableAutoShowScrollBar:
		XSView_EnableAutoShowScrollBar((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XSView_ScrollLeftLine:
		ret = (int)XSView_ScrollLeftLine((HELE)pControl->p1);
		break;
	case ft_XSView_ScrollRightLine:
		ret = (int)XSView_ScrollRightLine((HELE)pControl->p1);
		break;
	case ft_XSView_ScrollTopLine:
		ret = (int)XSView_ScrollTopLine((HELE)pControl->p1);
		break;
	case ft_XSView_ScrollBottomLine:
		ret = (int)XSView_ScrollBottomLine((HELE)pControl->p1);
		break;
	case ft_XSView_ScrollLeft:
		ret = (int)XSView_ScrollLeft((HELE)pControl->p1);
		break;
	case ft_XSView_ScrollRight:
		ret = (int)XSView_ScrollRight((HELE)pControl->p1);
		break;
	case ft_XSView_ScrollTop:
		ret = (int)XSView_ScrollTop((HELE)pControl->p1);
		break;
	case ft_XSView_ScrollBottom:
		ret = (int)XSView_ScrollBottom((HELE)pControl->p1);
		break;
	case ft_XShape_GetParentEle:
		ret = (int)XShape_GetParentEle((HXCGUI)pControl->p1);
		break;
	case ft_XShape_GetParentLayout:
		ret = (int)XShape_GetParentLayout((HXCGUI)pControl->p1);
		break;
	case ft_XShape_GetHWINDOW:
		ret = (int)XShape_GetHWINDOW((HXCGUI)pControl->p1);
		break;
	case ft_XShape_GetParent:
		ret = (int)XShape_GetParent((HXCGUI)pControl->p1);
		break;
	case ft_XShape_RemoveShape:
		XShape_RemoveShape((HXCGUI)pControl->p1);
		break;
	case ft_XShape_SetID:
		XShape_SetID((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XShape_GetID:
		ret = (int)XShape_GetID((HXCGUI)pControl->p1);
		break;
	case ft_XShape_SetUID:
		XShape_SetUID((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XShape_GetUID:
		ret = (int)XShape_GetUID((HXCGUI)pControl->p1);
		break;
	case ft_XShape_Redraw:
		XShape_Redraw((HXCGUI)pControl->p1);
		break;
	case ft_XShape_GetWidth:
		ret = (int)XShape_GetWidth((HXCGUI)pControl->p1);
		break;
	case ft_XShape_GetHeight:
		ret = (int)XShape_GetHeight((HXCGUI)pControl->p1);
		break;
	case ft_XShape_GetRect:
		XShape_GetRect((HXCGUI)pControl->p1,(out_ RECT*)pControl->p2);
		break;
	case ft_XShape_SetRect:
		XShape_SetRect((HXCGUI)pControl->p1,(in_  RECT*)pControl->p2);
		break;
	case ft_XShape_GetContentSize:
		XShape_GetContentSize((HXCGUI)pControl->p1,(out_ SIZE*)pControl->p2);
		break;
	case ft_XShape_ShowLayout:
		XShape_ShowLayout((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShape_AdjustLayout:
		XShape_AdjustLayout((HXCGUI)pControl->p1);
		break;
	case ft_XShape_Destroy:
		XShape_Destroy((HXCGUI)pControl->p1);
		break;
	case ft_XShapeText_Create:
		ret = (int)XShapeText_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(const wchar_t *)pControl->p5,(HXCGUI)pControl->p6);
		break;
	case ft_XShapeText_SetText:
		XShapeText_SetText((HXCGUI)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XShapeText_GetText:
		XShapeText_GetText((HXCGUI)pControl->p1,(out_ wchar_t *)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeText_GetTextLength:
		ret = (int)XShapeText_GetTextLength((HXCGUI)pControl->p1);
		break;
	case ft_XShapeText_SetFont:
		XShapeText_SetFont((HXCGUI)pControl->p1,(HFONTX)pControl->p2);
		break;
	case ft_XShapeText_GetFont:
		ret = (int)XShapeText_GetFont((HXCGUI)pControl->p1);
		break;
	case ft_XShapeText_SetTextColor:
		XShapeText_SetTextColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XShapeText_GetTextColor:
		ret = (int)XShapeText_GetTextColor((HXCGUI)pControl->p1);
		break;
	case ft_XShapeText_SetTextAlign:
		XShapeText_SetTextAlign((HXCGUI)pControl->p1,(int)pControl->p2);
		break;
	case ft_XShapeText_SetOffset:
		XShapeText_SetOffset((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeText_SetLayoutWidth:
		XShapeText_SetLayoutWidth((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeText_SetLayoutHeight:
		XShapeText_SetLayoutHeight((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeText_GetLayoutWidth:
		XShapeText_GetLayoutWidth((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeText_GetLayoutHeight:
		XShapeText_GetLayoutHeight((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeText_EnableCSS:
		XShapeText_EnableCSS((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShapeText_SetCssName:
		XShapeText_SetCssName((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XShapeText_GetCssName:
		ret = (int)XShapeText_GetCssName((HXCGUI)pControl->p1);
		break;
	case ft_XShapePic_Create:
		ret = (int)XShapePic_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XShapePic_SetImage:
		XShapePic_SetImage((HXCGUI)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XShapePic_SetLayoutWidth:
		XShapePic_SetLayoutWidth((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapePic_SetLayoutHeight:
		XShapePic_SetLayoutHeight((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapePic_GetLayoutWidth:
		XShapePic_GetLayoutWidth((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapePic_GetLayoutHeight:
		XShapePic_GetLayoutHeight((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeGif_Create:
		ret = (int)XShapeGif_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XShapeGif_SetImage:
		XShapeGif_SetImage((HXCGUI)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XShapeGif_SetLayoutWidth:
		XShapeGif_SetLayoutWidth((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeGif_SetLayoutHeight:
		XShapeGif_SetLayoutHeight((HXCGUI)pControl->p1,(layout_size_type_)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeGif_GetLayoutWidth:
		XShapeGif_GetLayoutWidth((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeGif_GetLayoutHeight:
		XShapeGif_GetLayoutHeight((HXCGUI)pControl->p1,(out_ layout_size_type_ *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeRect_Create:
		ret = (int)XShapeRect_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XShapeRect_SetBorderColor:
		XShapeRect_SetBorderColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XShapeRect_SetFillColor:
		XShapeRect_SetFillColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XShapeRect_SetRoundAngle:
		XShapeRect_SetRoundAngle((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeRect_GetRoundAngle:
		XShapeRect_GetRoundAngle((HXCGUI)pControl->p1,(out_ int *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeRect_EnableBorder:
		XShapeRect_EnableBorder((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShapeRect_EnableFill:
		XShapeRect_EnableFill((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShapeRect_EnableRoundAngle:
		XShapeRect_EnableRoundAngle((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShapeEllipse_Create:
		ret = (int)XShapeEllipse_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XShapeEllipse_SetBorderColor:
		XShapeEllipse_SetBorderColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XShapeEllipse_SetFillColor:
		XShapeEllipse_SetFillColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XShapeEllipse_EnableBorder:
		XShapeEllipse_EnableBorder((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShapeEllipse_EnableFill:
		XShapeEllipse_EnableFill((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShapeGroupBox_Create:
		ret = (int)XShapeGroupBox_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(const wchar_t*)pControl->p5,(HXCGUI)pControl->p6);
		break;
	case ft_XShapeGroupBox_SetBorderColor:
		XShapeGroupBox_SetBorderColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XShapeGroupBox_SetTextColor:
		XShapeGroupBox_SetTextColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XShapeGroupBox_SetFontX:
		XShapeGroupBox_SetFontX((HXCGUI)pControl->p1,(HFONTX)pControl->p2);
		break;
	case ft_XShapeGroupBox_SetTextOffset:
		XShapeGroupBox_SetTextOffset((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeGroupBox_SetRoundAngle:
		XShapeGroupBox_SetRoundAngle((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XShapeGroupBox_SetText:
		XShapeGroupBox_SetText((HXCGUI)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XShapeGroupBox_GetTextOffset:
		XShapeGroupBox_GetTextOffset((HXCGUI)pControl->p1,(out_ int *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeGroupBox_GetRoundAngle:
		XShapeGroupBox_GetRoundAngle((HXCGUI)pControl->p1,(out_ int *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XShapeGroupBox_EnableRoundAngle:
		XShapeGroupBox_EnableRoundAngle((HXCGUI)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XShapeLine_Create:
		ret = (int)XShapeLine_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XShapeLine_SetPosition:
		XShapeLine_SetPosition((HXCGUI)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XShapeLine_SetColor:
		XShapeLine_SetColor((HXCGUI)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XSliderBar_Create:
		ret = (int)XSliderBar_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XSliderBar_SetRange:
		XSliderBar_SetRange((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSliderBar_GetRange:
		ret = (int)XSliderBar_GetRange((HELE)pControl->p1);
		break;
	case ft_XSliderBar_SetButtonWidth:
		XSliderBar_SetButtonWidth((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSliderBar_SetButtonHeight:
		XSliderBar_SetButtonHeight((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSliderBar_SetSpaceTwo:
		XSliderBar_SetSpaceTwo((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XSliderBar_SetPos:
		XSliderBar_SetPos((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XSliderBar_GetPos:
		ret = (int)XSliderBar_GetPos((HELE)pControl->p1);
		break;
	case ft_XSliderBar_GetButton:
		ret = (int)XSliderBar_GetButton((HELE)pControl->p1);
		break;
	case ft_XSliderBar_SetHorizon:
		XSliderBar_SetHorizon((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XSliderBar_SetImageLoad:
		XSliderBar_SetImageLoad((HELE)pControl->p1,(HIMAGE)pControl->p2);
		break;
	case ft_XTabBar_Create:
		ret = (int)XTabBar_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XTabBar_AddLabel:
		ret = (int)XTabBar_AddLabel((HELE)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XTabBar_InsertLabel:
		ret = (int)XTabBar_InsertLabel((HELE)pControl->p1,(int)pControl->p2,(wchar_t *)pControl->p3);
		break;
	case ft_XTabBar_DeleteLabel:
		ret = (int)XTabBar_DeleteLabel((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTabBar_DeleteLabelAll:
		XTabBar_DeleteLabelAll((HELE)pControl->p1);
		break;
	case ft_XTabBar_GetLabel:
		ret = (int)XTabBar_GetLabel((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTabBar_GetLabelClose:
		ret = (int)XTabBar_GetLabelClose((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTabBar_GetButtonLeft:
		ret = (int)XTabBar_GetButtonLeft((HELE)pControl->p1);
		break;
	case ft_XTabBar_GetButtonRight:
		ret = (int)XTabBar_GetButtonRight((HELE)pControl->p1);
		break;
	case ft_XTabBar_GetSelect:
		ret = (int)XTabBar_GetSelect((HELE)pControl->p1);
		break;
	case ft_XTabBar_GetLabelSpacing:
		ret = (int)XTabBar_GetLabelSpacing((HELE)pControl->p1);
		break;
	case ft_XTabBar_GetLabelCount:
		ret = (int)XTabBar_GetLabelCount((HELE)pControl->p1);
		break;
	case ft_XTabBar_GetindexByEle:
		ret = (int)XTabBar_GetindexByEle((HELE)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XTabBar_SetLabelSpacing:
		XTabBar_SetLabelSpacing((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTabBar_SetPadding:
		XTabBar_SetPadding((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XTabBar_SetSelect:
		XTabBar_SetSelect((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTabBar_SetUp:
		XTabBar_SetUp((HELE)pControl->p1);
		break;
	case ft_XTabBar_SetDown:
		XTabBar_SetDown((HELE)pControl->p1);
		break;
	case ft_XTabBar_EnableTile:
		XTabBar_EnableTile((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XTabBar_EnableClose:
		XTabBar_EnableClose((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XTabBar_SetCloseSize:
		XTabBar_SetCloseSize((HELE)pControl->p1,(SIZE *)pControl->p2);
		break;
	case ft_XTabBar_SetTurnButtonSize:
		XTabBar_SetTurnButtonSize((HELE)pControl->p1,(SIZE *)pControl->p2);
		break;
	case ft_XTabBar_SetLabelWidth:
		XTabBar_SetLabelWidth((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XTabBar_ShowLabel:
		ret = (int)XTabBar_ShowLabel((HELE)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XTextLink_Create:
		ret = (int)XTextLink_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(const wchar_t*)pControl->p5,(HXCGUI)pControl->p6);
		break;
	case ft_XTextLink_EnableUnderlineLeave:
		XTextLink_EnableUnderlineLeave((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XTextLink_EnableUnderlineStay:
		XTextLink_EnableUnderlineStay((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XTextLink_SetTextColorStay:
		XTextLink_SetTextColorStay((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XTextLink_SetUnderlineColorLeave:
		XTextLink_SetUnderlineColorLeave((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XTextLink_SetUnderlineColorStay:
		XTextLink_SetUnderlineColorStay((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XToolBar_Create:
		ret = (int)XToolBar_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XToolBar_InsertEle:
		ret = (int)XToolBar_InsertEle((HELE)pControl->p1,(HELE)pControl->p2,(int)pControl->p3);
		break;
	case ft_XToolBar_InsertSeparator:
		ret = (int)XToolBar_InsertSeparator((HELE)pControl->p1,(int)pControl->p2,(COLORREF)pControl->p3);
		break;
	case ft_XToolBar_EnableButtonMenu:
		XToolBar_EnableButtonMenu((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XToolBar_GetHEle:
		ret = (int)XToolBar_GetHEle((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XToolBar_GetButtonLeft:
		ret = (int)XToolBar_GetButtonLeft((HELE)pControl->p1);
		break;
	case ft_XToolBar_GetButtonRight:
		ret = (int)XToolBar_GetButtonRight((HELE)pControl->p1);
		break;
	case ft_XToolBar_GetButtonMenu:
		ret = (int)XToolBar_GetButtonMenu((HELE)pControl->p1);
		break;
	case ft_XToolBar_SetSpace:
		XToolBar_SetSpace((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XToolBar_DeleteEle:
		XToolBar_DeleteEle((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XToolBar_DeleteAllEle:
		XToolBar_DeleteAllEle((HELE)pControl->p1);
		break;
	case ft_XTree_Create:
		ret = (int)XTree_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(HXCGUI)pControl->p5);
		break;
	case ft_XTree_EnableDragItem:
		XTree_EnableDragItem((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XTree_EnableConnectLine:
		XTree_EnableConnectLine((HELE)pControl->p1,(BOOL)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XTree_EnableExpand:
		XTree_EnableExpand((HELE)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XTree_SetConnectLineColor:
		XTree_SetConnectLineColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XTree_SetExpandButtonSize:
		XTree_SetExpandButtonSize((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XTree_SetConnectLineLength:
		XTree_SetConnectLineLength((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_SetDragInsertPositionColor:
		XTree_SetDragInsertPositionColor((HELE)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XTree_SetItemTemplateXML:
		ret = (int)XTree_SetItemTemplateXML((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XTree_SetItemTemplateXMLSel:
		ret = (int)XTree_SetItemTemplateXMLSel((HELE)pControl->p1,(const wchar_t*)pControl->p2);
		break;
	case ft_XTree_SetItemTemplateXMLFromString:
		ret = (int)XTree_SetItemTemplateXMLFromString((HELE)pControl->p1,(const char*)pControl->p2);
		break;
	case ft_XTree_SetItemTemplateXMLSelFromString:
		ret = (int)XTree_SetItemTemplateXMLSelFromString((HELE)pControl->p1,(const char*)pControl->p2);
		break;
	case ft_XTree_SetDrawItemBkFlags:
		XTree_SetDrawItemBkFlags((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_SetItemData:
		ret = (int)XTree_SetItemData((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XTree_GetItemData:
		ret = (int)XTree_GetItemData((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_SetSelectItem:
		ret = (int)XTree_SetSelectItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_GetSelectItem:
		ret = (int)XTree_GetSelectItem((HELE)pControl->p1);
		break;
	case ft_XTree_IsExpand:
		ret = (int)XTree_IsExpand((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_ExpandItem:
		ret = (int)XTree_ExpandItem((HELE)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XTree_ExpandAllChildItem:
		ret = (int)XTree_ExpandAllChildItem((HELE)pControl->p1,(int)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XTree_HitTest:
		ret = (int)XTree_HitTest((HELE)pControl->p1,(POINT *)pControl->p2);
		break;
	case ft_XTree_HitTestOffset:
		ret = (int)XTree_HitTestOffset((HELE)pControl->p1,(POINT *)pControl->p2);
		break;
	case ft_XTree_GetFirstChildItem:
		ret = (int)XTree_GetFirstChildItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_GetEndChildItem:
		ret = (int)XTree_GetEndChildItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_GetPrevSiblingItem:
		ret = (int)XTree_GetPrevSiblingItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_GetNextSiblingItem:
		ret = (int)XTree_GetNextSiblingItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_GetParentItem:
		ret = (int)XTree_GetParentItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_SetIndentation:
		XTree_SetIndentation((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_GetIndentation:
		ret = (int)XTree_GetIndentation((HELE)pControl->p1);
		break;
	case ft_XTree_SetItemHeight:
		XTree_SetItemHeight((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XTree_GetItemHeight:
		XTree_GetItemHeight((HELE)pControl->p1,(int)pControl->p2,(out_ int *)pControl->p3,(out_ int *)pControl->p4);
		break;
	case ft_XTree_SetRowSpace:
		XTree_SetRowSpace((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft_XTree_GetRowSpace:
		ret = (int)XTree_GetRowSpace((HELE)pControl->p1);
		break;
	case ft_XTree_MoveItem:
		ret = (int)XTree_MoveItem((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4);
		break;
	case ft_XTree_AddItemBkBorder:
		XTree_AddItemBkBorder((HELE)pControl->p1,(tree_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4,(int)pControl->p5);
		break;
	case ft_XTree_AddItemBkFill:
		XTree_AddItemBkFill((HELE)pControl->p1,(tree_item_state_)pControl->p2,(COLORREF)pControl->p3,(BYTE)pControl->p4);
		break;
	case ft_XTree_AddItemBkImage:
		XTree_AddItemBkImage((HELE)pControl->p1,(tree_item_state_)pControl->p2,(HIMAGE)pControl->p3);
		break;
	case ft_XTree_GetItemBkInfoCount:
		ret = (int)XTree_GetItemBkInfoCount((HELE)pControl->p1);
		break;
	case ft_XTree_ClearItemBkInfo:
		XTree_ClearItemBkInfo((HELE)pControl->p1);
		break;
	case ft_XTree_SetItemHeightDefault:
		XTree_SetItemHeightDefault((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XTree_GetItemHeightDefault:
		XTree_GetItemHeightDefault((HELE)pControl->p1,(out_ int *)pControl->p2,(out_ int *)pControl->p3);
		break;
	case ft_XTree_GetTemplateObject:
		ret = (int)XTree_GetTemplateObject((HELE)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XTree_GetItemIDFromHXCGUI:
		ret = (int)XTree_GetItemIDFromHXCGUI((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XTree_CreateAdapter:
		ret = (int)XTree_CreateAdapter((HELE)pControl->p1);
		break;
	case ft_XTree_BindAdapter:
		XTree_BindAdapter((HELE)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XTree_GetAdapter:
		ret = (int)XTree_GetAdapter((HELE)pControl->p1);
		break;
	case ft_XTree_RefreshData:
		XTree_RefreshData((HELE)pControl->p1);
		break;
	case ft_XTree_RefreshItem:
		XTree_RefreshItem((HELE)pControl->p1,(int)pControl->p2);
		break;
	case ft__XWnd_RegEvent:
		ret = (int)_XWnd_RegEvent((HWINDOW)pControl->p1,(UINT)pControl->p2,(xc_event*)pControl->p3);
		break;
	case ft__XWnd_RemoveEvent:
		ret = (int)_XWnd_RemoveEvent((HWINDOW)pControl->p1,(UINT)pControl->p2,(xc_event*)pControl->p3);
		break;
	case ft_XWnd_RegEventC:
		ret = (int)XWnd_RegEventC((HWINDOW)pControl->p1,(int)pControl->p2,(void *)pControl->p3);
		break;
	case ft_XWnd_RegEventC1:
		ret = (int)XWnd_RegEventC1((HWINDOW)pControl->p1,(int)pControl->p2,(void *)pControl->p3);
		break;
	case ft_XWnd_RemoveEventC:
		ret = (int)XWnd_RemoveEventC((HWINDOW)pControl->p1,(int)pControl->p2,(void *)pControl->p3);
		break;
	case ft_XWnd_Create:
		ret = (int)XWnd_Create((int)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(const wchar_t *)pControl->p5,(HWND)pControl->p6,(int)pControl->p7);
		break;
	case ft_XWnd_CreateEx:
		ret = (int)XWnd_CreateEx((DWORD)pControl->p1,(const wchar_t*)pControl->p2,(const wchar_t*)pControl->p3,(DWORD)pControl->p4,(int)pControl->p5,(int)pControl->p6,(int)pControl->p7,(int)pControl->p8,(HWND)pControl->p9,(int)pControl->p10);
		break;
	case ft_XWnd_AddEle:
		ret = (int)XWnd_AddEle((HWINDOW)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XWnd_InsertEle:
		ret = (int)XWnd_InsertEle((HWINDOW)pControl->p1,(HELE)pControl->p2,(int)pControl->p3);
		break;
	case ft_XWnd_AddShape:
		ret = (int)XWnd_AddShape((HWINDOW)pControl->p1,(HXCGUI)pControl->p2);
		break;
	case ft_XWnd_GetHWND:
		ret = (int)XWnd_GetHWND((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_EnableDragBorder:
		XWnd_EnableDragBorder((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_EnableDragWindow:
		XWnd_EnableDragWindow((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_EnableDragCaption:
		XWnd_EnableDragCaption((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_EnableDrawBk:
		XWnd_EnableDrawBk((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_EnableAutoFocus:
		XWnd_EnableAutoFocus((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_EnableMaxWindow:
		XWnd_EnableMaxWindow((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_RedrawWnd:
		XWnd_RedrawWnd((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_RedrawWndRect:
		XWnd_RedrawWndRect((HWINDOW)pControl->p1,(RECT *)pControl->p2,(BOOL)pControl->p3);
		break;
	case ft_XWnd_SetFocusEle:
		XWnd_SetFocusEle((HWINDOW)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XWnd_GetFocusEle:
		ret = (int)XWnd_GetFocusEle((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_GetStayHELE:
		ret = (int)XWnd_GetStayHELE((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_DrawWindow:
		XWnd_DrawWindow((HWINDOW)pControl->p1,(HDRAW)pControl->p2);
		break;
	case ft_XWnd_SetCursor:
		XWnd_SetCursor((HWINDOW)pControl->p1,(HCURSOR)pControl->p2);
		break;
	case ft_XWnd_GetCursor:
		ret = (int)XWnd_GetCursor((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_SetCursorSys:
		ret = (int)XWnd_SetCursorSys((HWINDOW)pControl->p1,(HCURSOR)pControl->p2);
		break;
	case ft_XWnd_SetFont:
		XWnd_SetFont((HWINDOW)pControl->p1,(HFONTX)pControl->p2);
		break;
	case ft_XWnd_SetTextColor:
		XWnd_SetTextColor((HWINDOW)pControl->p1,(COLORREF)pControl->p2,(BYTE)pControl->p3);
		break;
	case ft_XWnd_GetTextColor:
		ret = (int)XWnd_GetTextColor((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_SetID:
		XWnd_SetID((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XWnd_GetID:
		ret = (int)XWnd_GetID((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_SetCaptureEle:
		XWnd_SetCaptureEle((HWINDOW)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XWnd_GetCaptureEle:
		ret = (int)XWnd_GetCaptureEle((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_BindLayoutEle:
		ret = (int)XWnd_BindLayoutEle((HWINDOW)pControl->p1,(window_position_)pControl->p2,(HELE)pControl->p3);
		break;
	case ft_XWnd_GetLayoutEle:
		ret = (int)XWnd_GetLayoutEle((HWINDOW)pControl->p1,(window_position_)pControl->p2);
		break;
	case ft_XWnd_BindLayoutObject:
		XWnd_BindLayoutObject((HWINDOW)pControl->p1,(window_position_)pControl->p2,(HXCGUI)pControl->p3);
		break;
	case ft_XWnd_GetLayoutObject:
		ret = (int)XWnd_GetLayoutObject((HWINDOW)pControl->p1,(window_position_)pControl->p2);
		break;
	case ft_XWnd_SetLayoutSize:
		XWnd_SetLayoutSize((HWINDOW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XWnd_GetLayoutSize:
		XWnd_GetLayoutSize((HWINDOW)pControl->p1,(out_ BorderSize_i  *)pControl->p2);
		break;
	case ft_XWnd_SetDragBorderSize:
		XWnd_SetDragBorderSize((HWINDOW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XWnd_GetDragBorderSize:
		XWnd_GetDragBorderSize((HWINDOW)pControl->p1,(out_ BorderSize_i*)pControl->p2);
		break;
	case ft_XWnd_SetMinimumSize:
		XWnd_SetMinimumSize((HWINDOW)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XWnd_HitChildEle:
		ret = (int)XWnd_HitChildEle((HWINDOW)pControl->p1,(POINT *)pControl->p2);
		break;
	case ft_XWnd_GetChildCount:
		ret = (int)XWnd_GetChildCount((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_GetChildByIndex:
		ret = (int)XWnd_GetChildByIndex((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XWnd_GetChildByID:
		ret = (int)XWnd_GetChildByID((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XWnd_GetEle:
		ret = (int)XWnd_GetEle((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XWnd_GetChildShapeCount:
		ret = (int)XWnd_GetChildShapeCount((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_GetChildShapeByIndex:
		ret = (int)XWnd_GetChildShapeByIndex((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XWnd_GetDrawRect:
		XWnd_GetDrawRect((HWINDOW)pControl->p1,(RECT *)pControl->p2);
		break;
	case ft_XWnd_ShowWindow:
		ret = (int)XWnd_ShowWindow((HWINDOW)pControl->p1,(int)pControl->p2);
		break;
	case ft_XWnd_AdjustLayout:
		XWnd_AdjustLayout((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_AdjustLayoutObject:
		XWnd_AdjustLayoutObject((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_CloseWindow:
		XWnd_CloseWindow((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_CreateCaret:
		XWnd_CreateCaret((HWINDOW)pControl->p1,(HELE)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5,(int)pControl->p6);
		break;
	case ft_XWnd_SetCaretSize:
		XWnd_SetCaretSize((HWINDOW)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XWnd_SetCaretPos:
		XWnd_SetCaretPos((HWINDOW)pControl->p1,(int)pControl->p2,(int)pControl->p3);
		break;
	case ft_XWnd_SetCaretPosEx:
		XWnd_SetCaretPosEx((HWINDOW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(int)pControl->p5);
		break;
	case ft_XWnd_SetCaretColor:
		XWnd_SetCaretColor((HWINDOW)pControl->p1,(COLORREF)pControl->p2);
		break;
	case ft_XWnd_ShowCaret:
		XWnd_ShowCaret((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_DestroyCaret:
		XWnd_DestroyCaret((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_GetCaretHELE:
		ret = (int)XWnd_GetCaretHELE((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_GetClientRect:
		ret = (int)XWnd_GetClientRect((HWINDOW)pControl->p1,(out_ RECT *)pControl->p2);
		break;
	case ft_XWnd_GetBodyRect:
		XWnd_GetBodyRect((HWINDOW)pControl->p1,(out_ RECT *)pControl->p2);
		break;
	case ft_XWnd_SetTimer:
		ret = (int)XWnd_SetTimer((HWINDOW)pControl->p1,(UINT)pControl->p2,(UINT)pControl->p3);
		break;
	case ft_XWnd_KillTimer:
		ret = (int)XWnd_KillTimer((HWINDOW)pControl->p1,(UINT)pControl->p2);
		break;
	case ft_XWnd_SetXCTimer:
		ret = (int)XWnd_SetXCTimer((HWINDOW)pControl->p1,(UINT)pControl->p2,(UINT)pControl->p3);
		break;
	case ft_XWnd_KillXCTimer:
		ret = (int)XWnd_KillXCTimer((HWINDOW)pControl->p1,(UINT)pControl->p2);
		break;
	case ft_XWnd_GetBkManager:
		ret = (int)XWnd_GetBkManager((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_SetTransparentType:
		XWnd_SetTransparentType((HWINDOW)pControl->p1,(window_transparent_)pControl->p2);
		break;
	case ft_XWnd_SetTransparentAlpha:
		XWnd_SetTransparentAlpha((HWINDOW)pControl->p1,(BYTE)pControl->p2);
		break;
	case ft_XWnd_SetTransparentColor:
		XWnd_SetTransparentColor((HWINDOW)pControl->p1,(COLORREF)pControl->p2);
		break;
	case ft_XWnd_SetShadowInfo:
		XWnd_SetShadowInfo((HWINDOW)pControl->p1,(int)pControl->p2,(int)pControl->p3,(int)pControl->p4,(BOOL)pControl->p5,(COLORREF)pControl->p6);
		break;
	case ft_XWnd_GetTransparentType:
		ret = (int)XWnd_GetTransparentType((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_EnableCSS:
		XWnd_EnableCSS((HWINDOW)pControl->p1,(BOOL)pControl->p2);
		break;
	case ft_XWnd_SetCssName:
		XWnd_SetCssName((HWINDOW)pControl->p1,(const wchar_t *)pControl->p2);
		break;
	case ft_XWnd_GetCssName:
		ret = (int)XWnd_GetCssName((HWINDOW)pControl->p1);
		break;
	case ft_XWnd_RegEventTest:
		ret = (int)XWnd_RegEventTest((int)pControl->p1,(BYTE*)pControl->p2);
		break;
	case ft_XEle_IsChildEle:
		ret = (int)XEle_IsChildEle((HELE)pControl->p1,(HELE)pControl->p2);
		break;
	case ft_XWnd_GetShadowInfo:
		XWnd_GetShadowInfo((HWINDOW)pControl->p1,(int *)pControl->p2,(int *)pControl->p3,(int *)pControl->p4,(BOOL *)pControl->p5,(COLORREF *)pControl->p6);
		break;
		
	}
	pControl->nRet = ret;
	*pbHandled = TRUE;
	return 0;
}

VOID WINAPI SXWnd_EnableSafeFunction(HWINDOW hWindow)
{
	XWnd_RegEventC(hWindow,XWM_WINDPROC,&OnWndProc);
}