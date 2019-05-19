using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;


/*
 * name    xcgui界面库模块
 * Made    dasemimi
 * time    2018.5.22
 * ver     2.2.3
*/
namespace XCGUI
{
    using System.Text;

    public struct LOGFONTW
    {
        public int lfHeight;
        public int lfWidth;
        public int lfEscapement;
        public int lfOrientation;
        public int lfWeight;
        public byte lfItalic;
        public byte lfUnderline;
        public byte lfStrikeOut;
        public byte lfCharSet;
        public byte lfOutPrecision;
        public byte lfClipPrecision;
        public byte lfQuality;
        public byte lfPitchAndFamily;
        unsafe public fixed ushort lfFaceName[32];
    }
    public struct LOGFONT
    {
        public int lfHeight;
        public int lfWidth;
        public int lfEscapement;
        public int lfOrientation;
        public int lfWeight;
        public byte lfItalic;
        public byte lfUnderline;
        public byte lfStrikeOut;
        public byte lfCharSet;
        public byte lfOutPrecision;
        public byte lfClipPrecision;
        public byte lfQuality;
        public byte lfPitchAndFamily;
        unsafe public fixed ushort lfFaceName[32];
    }
    public struct RECT
    {
        public int x;
        public int y;
        public int cx;
        public int cy;
    }
    public struct POINT
    {
        public int x;
        public int y;
    }
    public struct SIZE
    {
        public int cx;
        public int cy;
    }
    public struct PaddingSize_i
    {
        public int leftSize;
        public int topSize;
        public int rightSize;
        public int bottomSize;
    }
    public struct SpaceSize_i
    {
        public int leftSize;
        public int topSize;
        public int rightSize;
        public int bottomSize;
    }
    public struct MarginSize_i
    {
        public int leftSize;
        public int topSize;
        public int rightSize;
        public int bottomSize;
    }

    public struct RECTF
    {
        public float left;
        public float top;
        public float right;
        public float bottom;
    }
    public struct BorderSize_i
    {
        public int leftSize;
        public int topSize;
        public int rightSize;
        public int bottomSize;
    }
 
public struct Position_i
{
	public int iRow;
	public int iColumn;
}
public struct listBox_item_i
{
	public int index;
	public int nUserData;
	public int nHeight;
	public int nSelHeight;
	public int nState;
	public RECT rcItem;
	public int hLayout;
	public int hTemp;
}
public struct listBox_item_info_i
{
	public int nUserData;
	public int nHeight;
	public int nSelHeight;
}
public struct listView_item_id_i
{
	public int iGroup;
	public int iItem;
}
public struct list_item_i
{
	public int index;
	public int iSubItem;
	public int nUserData;
	public int nState;
	public RECT rcItem;
	public int hLayout;
	public int hTemp;
}
public struct list_header_item_i
{
	public int index;
	public int nUserData;
	public bool bSort;
	public int nSortType;
	public int iColumnAdapter;
	public int nState;
	public RECT rcItem;
	public int hLayout;
	public int hTemp;
}
public struct tree_item_i
{
	public int nID;
	public int nDepth;
	public int nHeight;
	public int nSelHeight;
	public int nUserData;
	public bool bExpand;
	public int nState;
	public RECT rcItem;
	public int hLayout;
	public int hTemp;
}
public struct listView_item_i
{
	public int iGroup;
	public int iItem;
	public int nUserData;
	public int nState;
	public RECT rcItem;
	public int hLayout;
	public int hTemp;
}
public struct layout_info_i
{
	public int widthType;
	public int heightType;
	public short width;
	public short height;
}
public struct menu_popupWnd_i
{
	public int hWindow;
	public int nParentID;
}
public struct menu_drawBackground_i
{
	public int hMenu;
	public int hWindow;
	public int nParentID;
}
public struct menu_drawItem_i
{
	public int hMenu;
	public int hWindow;
	public int nID;
	public int nState;
	public RECT rcItem;
	public int hIcon;
	public string Text;
}
public struct tree_drag_item_i
{
	public int nDragItem;
	public int nDestItem;
	public int nType;
}
public struct xc_font_info_i
{
	public int nSize;
	public int nStyle;
	unsafe public  fixed short name[32];
}
public struct propertyGrid_item_i
{
	public int nType;
	public int nID;
	public int nDepth;
	public int nUserData;
	public int nNameColWidth;
	public RECT rcItem;
	public RECT rcExpand;
	public bool bExpand;
	public bool bShow;
}
public struct POINTF
{
	public float x;
	public float y;
}
public struct monthCal_item_i
{
	public int nDay;
	public int nType;
	public int nState;
	public RECT rcItem;
}


     
    unsafe public delegate int WM_LBUTTONDOWN_CPP(UInt32 nFlags,IntPtr pPt,bool *pbHandled);

    unsafe public delegate int XE_BNCLICK_CPP(bool* pbHandled);
    unsafe public delegate int XE_BNCLICK_CPP1(int hEventEle, bool* pbHandled);
    unsafe public delegate int XE_BNCLICK_CPP2(int hEle, int hEventEle, bool* pbHandled);


    unsafe public delegate int XE_LISTBOX_TEMP_CREATE_END_CPP(ref listBox_item_i listBox_item_i, bool* pbHandled);

    unsafe public delegate int XE_MENU_SELECT_CPP(int nID, bool* pbHandled);

    partial class xc
    {
        unsafe public static void XWnd_RegEventCPP(int hEle, int wmEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            XWnd_RegEventC(hEle, wmEvent, (int)pOnBtnClick);
        }
        unsafe public static void XWnd_RegEventCPP1(int hEle, int wmEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            XWnd_RegEventC(hEle, wmEvent, (int)pOnBtnClick);
        }
        [DllImport("user32.dll")]
        public static extern int MessageBoxA(int hWnd, string pText, string pTitle, int nType);

        unsafe public static void XEle_RegEventCPP(int hEle, int xeEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            XEle_RegEventC(hEle, xeEvent, (int)pOnBtnClick);
        }
        unsafe public static void XEle_RegEventCPP1(int hEle, int xeEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            XEle_RegEventC1(hEle, xeEvent, (int)pOnBtnClick);
        }
        unsafe public static void XEle_RegEventCPP2(int hEle, int xeEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            XEle_RegEventC2(hEle, xeEvent, (int)pOnBtnClick);
        }



		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_Init", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern bool XCloudUI_Init ();

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_OpenApp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern bool XCloudUI_OpenApp (string pLocalDir,string pUrl);

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_OpenAppCmd", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern bool XCloudUI_OpenAppCmd (string pCmdLine);

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_Exit", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern void XCloudUI_Exit ();

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_EnableDependBrowser", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern void XCloudUI_EnableDependBrowser (bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_OpenUrl", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern bool XCloudUI_OpenUrl (string pUrl);

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_SetEventCallback", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern void XCloudUI_SetEventCallback (int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_GetAppDir", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern int XCloudUI_GetAppDir (string pOut,int nOutlen);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern int XDateTime_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_SetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern void XDateTime_SetStyle (int hEle,int nStyle);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_GetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern int XDateTime_GetStyle (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_EnableSplitSlash", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		public static extern void XDateTime_EnableSplitSlash (int hEle,bool bSlash);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_GetTime", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDateTime_GetTime (int hEle,int pnHour,int pnMinute,int pnSecond);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_SetTime", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDateTime_SetTime (int hEle,int nHour,int nMinute,int nSecond);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_GetDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDateTime_GetDate (int hEle,int pnYear,int pnMonth,int pnDay);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_SetDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDateTime_SetDate (int hEle,int nYear,int nMonth,int nDay);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_GetSelBkColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDateTime_GetSelBkColor (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_SetSelBkColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDateTime_SetSelBkColor (int hEle,int crSelectBk,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XDateTime_GetButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDateTime_GetButton (int hEle,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XMonthCal_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMonthCal_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XMonthCal_SetToday", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMonthCal_SetToday (int hEle,int nYear,int nMonth,int nDay);

		[DllImport("xcgui.dll", EntryPoint = "XMonthCal_GetToday", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMonthCal_GetToday (int hEle,int pnYear,int pnMonth,int pnDay);

		[DllImport("xcgui.dll", EntryPoint = "XMonthCal_SeSelDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMonthCal_SeSelDate (int hEle,int nYear,int nMonth,int nDay);

		[DllImport("xcgui.dll", EntryPoint = "XMonthCal_GetSelDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMonthCal_GetSelDate (int hEle,int pnYear,int pnMonth,int pnDay);

		[DllImport("xcgui.dll", EntryPoint = "XMonthCal_GetButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMonthCal_GetButton (int hEle,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XC_InitJS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_InitJS ();

		[DllImport("xcgui.dll", EntryPoint = "XC_ExitJS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_ExitJS ();

		[DllImport("xcgui.dll", EntryPoint = "XC_RunJS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_RunJS (string pJsFile);

		[DllImport("xcgui.dll", EntryPoint = "XC_InitLua", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_InitLua ();

		[DllImport("xcgui.dll", EntryPoint = "XC_RunLua", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_RunLua (string pLuaFile);

		[DllImport("xcgui.dll", EntryPoint = "XC_ExitLua", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_ExitLua ();

		[DllImport("xcgui.dll", EntryPoint = "XC_UnicodeToAnsi", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_UnicodeToAnsi (string pIn,int inLen,string pOut,int outLen);

		[DllImport("xcgui.dll", EntryPoint = "XC_AnsiToUnicode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_AnsiToUnicode (string pIn,int inLen,string pOut,int outLen);

		[DllImport("xcgui.dll", EntryPoint = "XC_itoa", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_itoa (int nValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_itow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_itow (int nValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_ftoa", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_ftoa (float fValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_ftow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_ftow (float fValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_atow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_atow (string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_wtoa", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_wtoa (string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_utf8tow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_utf8tow (string pUtf8);

		[DllImport("xcgui.dll", EntryPoint = "XC_utf8towEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_utf8towEx (string pUtf8,int length);

		[DllImport("xcgui.dll", EntryPoint = "XC_atoutf8", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_atoutf8 (string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_DebugToFileInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_DebugToFileInfo (string pInfo);

		[DllImport("xcgui.dll", EntryPoint = "XC_IsHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_IsHELE (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XC_IsHWINDOW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_IsHWINDOW (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XC_IsShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_IsShape (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XC_IsHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_IsHXCGUI (int hXCGUI,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XC_hWindowFromHWnd", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_hWindowFromHWnd (int hWnd);

		[DllImport("xcgui.dll", EntryPoint = "XC_SetProperty", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_SetProperty (int hXCGUI,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetProperty", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XC_GetProperty (int hXCGUI,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XC_RegisterWindowClassName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_RegisterWindowClassName (string pClassName);

		[DllImport("xcgui.dll", EntryPoint = "XC_IsSViewExtend", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_IsSViewExtend (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetObjectType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_GetObjectType (int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_GetObjectByID (int hWindow,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByIDName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_GetObjectByIDName (int hWindow,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_GetObjectByUID (int nUID);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByUIDName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_GetObjectByUIDName (string pName);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_GetObjectByName (string pName);

		[DllImport("xcgui.dll", EntryPoint = "XC_SetPaintFrequency", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_SetPaintFrequency (int nMilliseconds);

		[DllImport("xcgui.dll", EntryPoint = "XC_SetTextRenderingHint", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_SetTextRenderingHint (int nType);

		[DllImport("xcgui.dll", EntryPoint = "XC_RectInRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_RectInRect (RECT* pRect1,RECT* pRect2);

		[DllImport("xcgui.dll", EntryPoint = "XC_CombineRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_CombineRect (RECT* pDest,RECT* pSrc1,RECT* pSrc2);

		[DllImport("xcgui.dll", EntryPoint = "XC_ShowLayoutFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_ShowLayoutFrame (bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XC_EnableDebugFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_EnableDebugFile (bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XC_EnableResMonitor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_EnableResMonitor (bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XC_SetLayoutFrameColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_SetLayoutFrameColor (int color);

		[DllImport("xcgui.dll", EntryPoint = "XC_EnableErrorMessageBox", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_EnableErrorMessageBox (bool bEnabel);

		[DllImport("xcgui.dll", EntryPoint = "XC_EnableAutoExitApp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_EnableAutoExitApp (bool bEnabel);

		[DllImport("xcgui.dll", EntryPoint = "XC_LoadLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_LoadLayout (string pFileName,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XC_LoadLayoutZip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_LoadLayoutZip (string pZipFileName,string pFileName,string pPassword,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XC_LoadLayoutFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_LoadLayoutFromString (string pStringXML,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XC_LoadResource", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_LoadResource (string pFileName,string pDir);

		[DllImport("xcgui.dll", EntryPoint = "XC_LoadResourceZip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_LoadResourceZip (string pZipFileName,string pFileName,string pPassword);

		[DllImport("xcgui.dll", EntryPoint = "XC_LoadResourceFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_LoadResourceFromString (string pStringXML,string pFileName,string pDir);

		[DllImport("xcgui.dll", EntryPoint = "XC_LoadStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XC_LoadStyle (string pFileName,string pDir);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetTextSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_GetTextSize (string pString,int length,int hFontX,SIZE* pOutSize);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetTextShowSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_GetTextShowSize (string pString,int length,int hFontX,SIZE* pOutSize);

		[DllImport("xcgui.dll", EntryPoint = "XC_GetDefaultFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_GetDefaultFont ();

		[DllImport("xcgui.dll", EntryPoint = "XC_SetDefaultFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_SetDefaultFont (int hFontX);

		[DllImport("xcgui.dll", EntryPoint = "XC_AddFileSearchPath", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_AddFileSearchPath (string pPath);

		[DllImport("xcgui.dll", EntryPoint = "XC_InitFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_InitFont (LOGFONTW* pFont,string pName,int size,bool bBold,bool bItalic,bool bUnderline,bool bStrikeOut);

		[DllImport("xcgui.dll", EntryPoint = "XC_Malloc", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_Malloc (int size);

		[DllImport("xcgui.dll", EntryPoint = "XC_Free", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_Free (int p);

		[DllImport("xcgui.dll", EntryPoint = "_XC_SetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void _XC_SetType (int hXCGUI,int nType);

		[DllImport("xcgui.dll", EntryPoint = "_XC_AddType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void _XC_AddType (int hXCGUI,int nType);

		[DllImport("xcgui.dll", EntryPoint = "_XC_BindData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void _XC_BindData (int hXCGUI,int data);

		[DllImport("xcgui.dll", EntryPoint = "_XC_GetBindData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int _XC_GetBindData (int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XC_Alert", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_Alert (string pText,string pTitle);

		[DllImport("xcgui.dll", EntryPoint = "XC_Sys_ShellExecute", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XC_Sys_ShellExecute (int hwnd,string lpOperation,string lpFile,string lpParameters,string lpDirectory,int nShowCmd);

		[DllImport("xcgui.dll", EntryPoint = "XInitXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XInitXCGUI (string pText);

		[DllImport("xcgui.dll", EntryPoint = "XRunXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRunXCGUI ();

		[DllImport("xcgui.dll", EntryPoint = "XExitXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XExitXCGUI ();

		[DllImport("xcgui.dll", EntryPoint = "XC_PostQuitMessage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XC_PostQuitMessage (int nExitCode);

		[DllImport("xcgui.dll", EntryPoint = "XUI_GetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XUI_GetType (int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XUI_GetTypeEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XUI_GetTypeEx (int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XUI_SetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XUI_SetStyle (int hXCGUI,int nStyle);

		[DllImport("xcgui.dll", EntryPoint = "XUI_GetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XUI_GetStyle (int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBkM_Create ();

		[DllImport("xcgui.dll", EntryPoint = "XBkM_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBkM_Destroy (int hBkInfoM);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_SetBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBkM_SetBkInfo (int hBkInfoM,string pText);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_AddInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBkM_AddInfo (int hBkInfoM,string pText);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_AddBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBkM_AddBorder (int hBkInfoM,int nState,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_AddFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBkM_AddFill (int hBkInfoM,int nState,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_AddImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBkM_AddImage (int hBkInfoM,int nState,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBkM_GetCount (int hBkInfoM);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_Clear", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBkM_Clear (int hBkInfoM);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_Draw", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XBkM_Draw (int hBkInfoM,int nState,int hDraw,RECT pRect);

		[DllImport("xcgui.dll", EntryPoint = "XBkM_DrawEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XBkM_DrawEx (int hBkInfoM,int nState,int hDraw,RECT pRect,int nStateFilter);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_Create (int x,int y,int cx,int cy,string pName,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_IsCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XBtn_IsCheck (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XBtn_SetCheck (int hEle,bool bCheck);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetState (int hEle,int nState);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetState (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetStateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetStateEx (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetStyle (int hEle,int nStyle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetStyle (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetType (int hEle,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetTypeEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetTypeEx (int hEle,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetType (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetGroupID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetGroupID (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetGroupID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetGroupID (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetBindEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetBindEle (int hEle,int hBindEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetBindEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetBindEle (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetTextAlign (int hEle,int nFlags);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetTextAlign (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetIconAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetIconAlign (int hEle,int align);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetOffset (int hEle,int x,int y);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetOffsetIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetOffsetIcon (int hEle,int x,int y);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetIconSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetIconSpace (int hEle,int size);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_GetText (int hEle,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetText (int hEle,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetIcon (int hEle,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_SetIconDisable", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_SetIconDisable (int hEle,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetIcon (int hEle,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_AddAnimationFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_AddAnimationFrame (int hEle,int hImage,int uElapse);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_EnableAnimation", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_EnableAnimation (int hEle,bool bEnable,bool bLoopPlay);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_AddBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_AddBkBorder (int hEle,int nState,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_AddBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_AddBkFill (int hEle,int nState,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_AddBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_AddBkImage (int hEle,int nState,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_GetBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XBtn_GetBkInfoCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XBtn_ClearBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XBtn_ClearBkInfo (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XComboBox_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_SetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XComboBox_SetSelItem (int hEle,int iIndex);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_GetButtonRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_GetButtonRect (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_SetButtonSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_SetButtonSize (int hEle,int size);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_SetDropHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_SetDropHeight (int hEle,int height);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_GetDropHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XComboBox_GetDropHeight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_BindAdapter (int hEle,int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XComboBox_GetAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_SetItemTemplateXML (int hEle,string pXmlFile);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_SetItemTemplateXMLFromString (int hEle,string pStringXML);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_EnableDrawButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_EnableDrawButton (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_EnableEdit", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_EnableEdit (int hEle,bool bEdit);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_EnableDropHeightFixed", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_EnableDropHeightFixed (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_AddBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_AddBkBorder (int hEle,int nState,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_AddBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_AddBkFill (int hEle,int nState,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_AddBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_AddBkImage (int hEle,int nState,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XComboboX_GetBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XComboboX_GetBkInfoCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_ClearBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_ClearBkInfo (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_GetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XComboBox_GetSelItem (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_GetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XComboBox_GetState (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XAd_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAd_Destroy (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Create ();

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Group_AddColumn (int hAdapter,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Group_AddItemText (int hAdapter,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_AddItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Group_AddItemTextEx (int hAdapter,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Group_AddItemImage (int hAdapter,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_AddItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Group_AddItemImageEx (int hAdapter,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Group_SetText (int hAdapter,int iGroup,int iColumn,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_SetTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Group_SetTextEx (int hAdapter,int iGroup,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Group_SetImage (int hAdapter,int iGroup,int iColumn,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_SetImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Group_SetImageEx (int hAdapter,int iGroup,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Group_GetCount (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Item_GetCount (int hAdapter,int iGroup);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Item_AddColumn (int hAdapter,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Item_AddItemText (int hAdapter,int iGroup,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_AddItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Item_AddItemTextEx (int hAdapter,int iGroup,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Item_AddItemImage (int hAdapter,int iGroup,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_AddItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Item_AddItemImageEx (int hAdapter,int iGroup,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Item_SetText (int hAdapter,int iGroup,int iItem,int iColumn,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_SetTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Item_SetTextEx (int hAdapter,int iGroup,int iItem,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Item_SetImage (int hAdapter,int iGroup,int iItem,int iColumn,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_SetImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Item_SetImageEx (int hAdapter,int iGroup,int iItem,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Group_DeleteItem (int hAdapter,int iGroup);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Group_DeleteAllChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdListView_Group_DeleteAllChildItem (int hAdapter,int iGroup);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Item_DeleteItem (int hAdapter,int iGroup,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_DeleteAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdListView_DeleteAll (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_DeleteAllGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdListView_DeleteAllGroup (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_DeleteAllItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdListView_DeleteAllItem (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_DeleteColumnGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdListView_DeleteColumnGroup (int hAdapter,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_DeleteColumnItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdListView_DeleteColumnItem (int hAdapter,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_GetTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdListView_Item_GetTextEx (int hAdapter,int iGroup,int iItem,string pName,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XAdListView_Item_GetImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdListView_Item_GetImageEx (int hAdapter,int iGroup,int iItem,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_Create ();

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_Sort", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdTable_Sort (int hAdapter,int iColumn,bool bAscending);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemDataType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_GetItemDataType (int hAdapter,int iItem,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemDataTypeEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_GetItemDataTypeEx (int hAdapter,int iItem,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_AddColumn (int hAdapter,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_SetColumn (int hAdapter,string pColName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_AddItemText (int hAdapter,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_AddItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_AddItemTextEx (int hAdapter,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_AddItemImage (int hAdapter,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_AddItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_AddItemImageEx (int hAdapter,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_InsertItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_InsertItemText (int hAdapter,int iItem,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_InsertItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_InsertItemTextEx (int hAdapter,int iItem,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_InsertItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_InsertItemImage (int hAdapter,int iItem,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_InsertItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_InsertItemImageEx (int hAdapter,int iItem,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemText (int hAdapter,int iItem,int iColumn,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemTextEx (int hAdapter,int iItem,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemInt (int hAdapter,int iItem,int iColumn,int nValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemIntEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemIntEx (int hAdapter,int iItem,string pName,int nValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemFloat", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemFloat (int hAdapter,int iItem,int iColumn,float nValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemFloatEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemFloatEx (int hAdapter,int iItem,string pName,float nValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemImage (int hAdapter,int iItem,int iColumn,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_SetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_SetItemImageEx (int hAdapter,int iItem,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_DeleteItem (int hAdapter,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_DeleteItemEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_DeleteItemEx (int hAdapter,int iItem,int nCount);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_DeleteItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdTable_DeleteItemAll (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_DeleteColumnAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdTable_DeleteColumnAll (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_GetCount (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetCountColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_GetCountColumn (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_GetItemText (int hAdapter,int iItem,int iColumn,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_GetItemTextEx (int hAdapter,int iItem,string pName,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_GetItemImage (int hAdapter,int iItem,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTable_GetItemImageEx (int hAdapter,int iItem,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_GetItemInt (int hAdapter,int iItem,int iColumn,int pOutValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemIntEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_GetItemIntEx (int hAdapter,int iItem,string pName,int pOutValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemFloat", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_GetItemFloat (int hAdapter,int iItem,int iColumn,float pOutValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTable_GetItemFloatEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTable_GetItemFloatEx (int hAdapter,int iItem,string pName,float pOutValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_Create ();

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_AddColumn (int hAdapter,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_SetColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_SetColumn (int hAdapter,string pColName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_InsertItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_InsertItemText (int hAdapter,string pValue,int nParentID,int insertID);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_InsertItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_InsertItemTextEx (int hAdapter,string pName,string pValue,int nParentID,int insertID);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_InsertItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_InsertItemImage (int hAdapter,int hImage,int nParentID,int insertID);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_InsertItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_InsertItemImageEx (int hAdapter,string pName,int hImage,int nParentID,int insertID);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_GetCount (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_GetCountColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_GetCountColumn (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTree_SetItemText (int hAdapter,int nID,int iColumn,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_SetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTree_SetItemTextEx (int hAdapter,int nID,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_SetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTree_SetItemImage (int hAdapter,int nID,int iColumn,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_SetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTree_SetItemImageEx (int hAdapter,int nID,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTree_GetItemText (int hAdapter,int nID,int iColumn,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_GetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_GetItemImage (int hAdapter,int nID,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_GetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTree_GetItemTextEx (int hAdapter,int nID,string pName,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_GetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdTree_GetItemImageEx (int hAdapter,int nID,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdTree_DeleteItem (int hAdapter,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_DeleteItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdTree_DeleteItemAll (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdTree_DeleteColumnAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XAdTree_DeleteColumnAll (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdMap_Create ();

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdMap_AddItemText (int hAdapter,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdMap_AddItemImage (int hAdapter,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdMap_DeleteItem (int hAdapter,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdMap_GetCount (int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdMap_GetItemText (int hAdapter,string pName,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_GetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XAdMap_GetItemImage (int hAdapter,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdMap_SetItemText (int hAdapter,string pName,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XAdMap_SetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XAdMap_SetItemImage (int hAdapter,string pName,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "_XC_DebugPrintf", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void _XC_DebugPrintf (int level,string pFormat,int 点点点);

		[DllImport("xcgui.dll", EntryPoint = "_XC_DebugPrintfW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void _XC_DebugPrintfW (int level,string pFormat,int 点点点);

		[DllImport("xcgui.dll", EntryPoint = "xtrace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void xtrace (string pFormat,int 点点点);

		[DllImport("xcgui.dll", EntryPoint = "xtracew", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void xtracew (string pFormat,int 点点点);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_Create (int hdc);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_Destroy (int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetOffset (int hDraw,int x,int y);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_GetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_GetOffset (int hDraw,int pX,int pY);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_RestoreGDIOBJ", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_RestoreGDIOBJ (int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_GetHDC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_GetHDC (int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetBrushColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetBrushColor (int hDraw,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetTextAlign (int hDraw,int nFlag);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetTextVertical", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetTextVertical (int hDraw,bool bVertical);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetFontX", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetFontX (int hDraw,int hFontx);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetLineWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetLineWidth (int hDraw,int nWidth);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetBkMode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_SetBkMode (int hDraw,bool bTransparent);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetClipRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetClipRect (int hDraw,RECT pRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_ClearClip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_ClearClip (int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_EnableSmoothingMode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_EnableSmoothingMode (int hDraw,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_CreateSolidBrush", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_CreateSolidBrush (int hDraw,int crColor);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_CreatePen", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_CreatePen (int hDraw,int fnPenStyle,int nWidth,int crColor);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_CreateRectRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_CreateRectRgn (int hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_CreateRoundRectRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_CreateRoundRectRgn (int hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect,int nWidthEllipse,int nHeightEllipse);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_CreatePolygonRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_CreatePolygonRgn (int hDraw,POINT* pPt,int cPoints,int fnPolyFillMode);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SelectClipRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_SelectClipRgn (int hDraw,int hRgn);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FillRect (int hDraw,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillRectColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FillRectColor (int hDraw,RECT* pRect,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_FillRgn (int hDraw,int hrgn,int hbr);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillEllipse", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FillEllipse (int hDraw,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawEllipse", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawEllipse (int hDraw,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillRoundRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FillRoundRect (int hDraw,RECT* pRect,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawRoundRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawRoundRect (int hDraw,RECT* pRect,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillRoundRectEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FillRoundRectEx (int hDraw,RECT* pRect,int nLeftTop,int nRightTop,int nRightBottom,int nLeftBottom);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawRoundRectEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawRoundRectEx (int hDraw,RECT* pRect,int nLeftTop,int nRightTop,int nRightBottom,int nLeftBottom);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Rectangle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_Rectangle (int hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawGroupBox_Rect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawGroupBox_Rect (int hDraw,RECT* pRect,string pName,int textColor,byte textAlpha,POINT* pOffset);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawGroupBox_RoundRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawGroupBox_RoundRect (int hDraw,RECT* pRect,string pName,int textColor,byte textAlpha,POINT* pOffset,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_GradientFill2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_GradientFill2 (int hDraw,int color1,byte alpha1,int color2,byte alpha2,RECT* pRect,int mode);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_GradientFill4", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_GradientFill4 (int hDraw,int color1,int color2,int color3,int color4,RECT* pRect,int mode);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FrameRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_FrameRgn (int hDraw,int hrgn,int hbr,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FrameRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FrameRect (int hDraw,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FocusRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FocusRect (int hDraw,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawLine (int hDraw,int x1,int y1,int x2,int y2);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_MoveToEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_MoveToEx (int hDraw,int X,int Y,POINT* lpPoint);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_LineTo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_LineTo (int hDraw,int nXEnd,int nYEnd);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Polyline", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_Polyline (int hDraw,POINT* pArrayPt,int arrayPtSize);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Dottedline", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_Dottedline (int hDraw,int x1,int y1,int x2,int y2);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetPixel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XDraw_SetPixel (int hDraw,int X,int Y,int crColor);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Check", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_Check (int hDraw,int x,int y,int color,bool bCheck);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawIconEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_DrawIconEx (int hDraw,int xLeft,int yTop,int hIcon,int cxWidth,int cyWidth,int istepIfAniCur,int hbrFlickerFreeDraw,int diFlags);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_BitBlt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_BitBlt (int hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,int hdcSrc,int nXSrc,int nYSrc,int dwRop);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_BitBlt2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_BitBlt2 (int hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,int hDrawSrc,int nXSrc,int nYSrc,int dwRop);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_AlphaBlend", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XDraw_AlphaBlend (int hDraw,int nXOriginDest,int nYOriginDest,int nWidthDest,int nHeightDest,int hdcSrc,int nXOriginSrc,int nYOriginSrc,int nWidthSrc,int nHeightSrc,int alpha);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_TriangularArrow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_TriangularArrow (int hDraw,int align,int x,int y,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawPolygon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawPolygon (int hDraw,POINT* points,int nCount);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawPolygonF", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawPolygonF (int hDraw,POINTF * points,int nCount);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillPolygon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FillPolygon (int hDraw,POINT* points,int nCount);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_FillPolygonF", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_FillPolygonF (int hDraw,POINTF * points,int nCount);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Image", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_Image (int hDraw,int hImageFrame,int x,int y);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_Image2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_Image2 (int hDraw,int hImageFrame,int x,int y,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_ImageStretch", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_ImageStretch (int hDraw,int hImageFrame,int x,int y,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_ImageAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_ImageAdaptive (int hDraw,int hImageFrame,RECT* pRect,bool bOnlyBorder);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_ImageExTile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_ImageExTile (int hDraw,int hImageFrame,RECT* pRect,int flag);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_ImageSuper", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_ImageSuper (int hDraw,int hImageFrame,RECT* pRect,bool bClip);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_ImageSuper2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_ImageSuper2 (int hDraw,int hImageFrame,RECT* pRcDest,RECT* pSrcRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawText (int hDraw,string lpString,int nCount,RECT lpRect);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_DrawTextUnderline", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_DrawTextUnderline (int hDraw,string lpString,int nCount,RECT lpRect,int colorLine,byte alphaLine);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_TextOut", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_TextOut (int hDraw,int nXStart,int nYStart,string lpString,int cbString);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_TextOutEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_TextOutEx (int hDraw,int nXStart,int nYStart,string lpString);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_TextOutA", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_TextOutA (int hDraw,int nXStart,int nYStart,string lpString);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetAlpha", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetAlpha (int hDraw,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XDraw_SetAlphaEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XDraw_SetAlphaEx (int hdc,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XEle_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "_XEle_RegEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool _XEle_RegEvent (int hEle,int nEvent,int pEvent);

		[DllImport("xcgui.dll", EntryPoint = "_XEle_RemoveEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool _XEle_RemoveEvent (int hEle,int nEvent,int pEvent);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RegEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_RegEventC (int hEle,int nEvent,int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RegEventC1", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_RegEventC1 (int hEle,int nEvent,int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RegEventC2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_RegEventC2 (int hEle,int nEvent,int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RemoveEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_RemoveEventC (int hEle,int nEvent,int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SendEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_SendEvent (int hEle,int hEventEle,int nEvent,int wParam,int lParam);

		[DllImport("xcgui.dll", EntryPoint = "XEle_PostEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_PostEvent (int hEle,int hEventEle,int nEvent,int wParam,int lParam);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsShow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsShow (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsEnable", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsEnable (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsEnableFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsEnableFocus (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsDrawFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsDrawFocus (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsEnableEvent_XE_PAINT_END", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsEnableEvent_XE_PAINT_END (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsMouseThrough", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsMouseThrough (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsBkTransparent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsBkTransparent (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsKeyTab", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsKeyTab (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsSwitchFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsSwitchFocus (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsEnable_XE_MOUSEWHEEL", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsEnable_XE_MOUSEWHEEL (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsChildEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsChildEle (int hEle,int hChildEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsEnableLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsEnableLayout (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsEnableCanvas", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsEnableCanvas (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_Enable", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_Enable (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableFocus (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableDrawFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableDrawFocus (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableDrawBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableDrawBorder (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableCanvas", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableCanvas (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableEvent_XE_PAINT_END", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableEvent_XE_PAINT_END (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableBkTransparent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableBkTransparent (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableMouseThrough", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableMouseThrough (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableKeyTab", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableKeyTab (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableSwitchFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableSwitchFocus (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableEvent_XE_MOUSEWHEEL", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableEvent_XE_MOUSEWHEEL (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableLayout (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_SetRect (int hEle,RECT* pRect,bool bRedraw);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetRectEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_SetRectEx (int hEle,int x,int y,int cx,int cy,bool bRedraw);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetRectLogic", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_SetRectLogic (int hEle,RECT* pRect,bool bRedraw);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetRect (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetRectLogic", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetRectLogic (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetClientRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetClientRect (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetWndClientRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetWndClientRect (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetWidth (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetHeight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RectWndClientToEleClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_RectWndClientToEleClient (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XEle_PointWndClientToEleClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_PointWndClientToEleClient (int hEle,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RectClientToWndClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_RectClientToWndClient (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XEle_PointClientToWndClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_PointClientToWndClient (int hEle,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XEle_AddEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_AddEle (int hEle,int hChildEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_InsertEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_InsertEle (int hEle,int hChildEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RemoveEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_RemoveEle (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_AddShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_AddShape (int hEle,int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetZOrder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_SetZOrder (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetZOrderEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_SetZOrderEx (int hEle,int hDestEle,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetZOrder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetZOrder (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetTopmost", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_SetTopmost (int hEle,bool bTopmost);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableCSS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableCSS (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetCssName (int hEle,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XEle_GetCssName (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_ShowEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_ShowEle (int hEle,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetType (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetHWND", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetHWND (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetHWINDOW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetHWINDOW (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetCursor (int hEle,int hCursor);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetCursor (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetID (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetID (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetUID (int hEle,int nUID);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetUID (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetName (int hEle,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XEle_GetName (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetParentEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetParentEle (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetParent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetParent (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetTextColor (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetTextColor (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetFocusBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetFocusBorderColor (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetFocusBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetFocusBorderColor (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetFont (int hEle,int hFontx);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetFont (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetAlpha", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetAlpha (int hEle,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetChildCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetChildCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetChildByIndex", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetChildByIndex (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetChildByID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetChildByID (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetBorderSize (int hEle,int left,int top,int right,int bottom);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetBorderSize (int hEle,BorderSize_i pBorder);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetPadding (int hEle,int left,int top,int right,int bottom);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetPadding (int hEle,PaddingSize_i pPadding);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetLockScroll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetLockScroll (int hEle,bool bHorizon,bool bVertical);

		[DllImport("xcgui.dll", EntryPoint = "XEle_HitChildEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_HitChildEle (int hEle,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XEle_BindLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_BindLayoutObject (int hEle,int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetLayoutObject (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetParentLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetParentLayoutObject (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetUserData (int hEle,int nData);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetUserData (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetContentSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetContentSize (int hEle,SIZE* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetCapture", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetCapture (int hEle,bool b);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetLayoutWidth (int hEle,int nType,int nWidth);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetLayoutHeight (int hEle,int nType,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetLayoutWidth (int hEle,int pType,int pWidth);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetLayoutHeight (int hEle,int pType,int pHeight);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RedrawEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_RedrawEle (int hEle,bool bImmediate);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RedrawRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_RedrawRect (int hEle,RECT* pRect,bool bImmediate);

		[DllImport("xcgui.dll", EntryPoint = "XEle_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_Destroy (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_AddBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_AddBkBorder (int hEle,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XEle_AddBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_AddBkFill (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XEle_AddBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_AddBkImage (int hEle,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetBkInfoCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_ClearBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_ClearBkInfo (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetBkManager", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetBkManager (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetStateFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XEle_GetStateFlags (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_DrawFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_DrawFocus (int hEle,int hDraw,RECT pRect);

		[DllImport("xcgui.dll", EntryPoint = "XEle_DrawEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_DrawEle (int hEle,int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "XEle_EnableTransparentChannel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_EnableTransparentChannel (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_SetXCTimer (int hEle,int nIDEvent,int uElapse);

		[DllImport("xcgui.dll", EntryPoint = "XEle_KillXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_KillXCTimer (int hEle,int nIDEvent);

		[DllImport("xcgui.dll", EntryPoint = "XEle_SetToolTip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_SetToolTip (int hEle,string pText);

		[DllImport("xcgui.dll", EntryPoint = "XEle_GetToolTip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_GetToolTip (int hEle,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XEle_PopupToolTip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_PopupToolTip (int hEle,int x,int y);

		[DllImport("xcgui.dll", EntryPoint = "XEle_AdjustLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_AdjustLayoutObject (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XEle_AdjustLayout (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_RegEventTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_RegEventTest (int nEvent,int pParamType);

		[DllImport("xcgui.dll", EntryPoint = "XFont_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_Create (int size);

		[DllImport("xcgui.dll", EntryPoint = "XFont_Create2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_Create2 (string pName,int size,int style);

		[DllImport("xcgui.dll", EntryPoint = "XFont_Create3", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_Create3 (xc_font_info_i pInfo);

		[DllImport("xcgui.dll", EntryPoint = "XFont_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_CreateEx (LOGFONTW* pFontInfo);

		[DllImport("xcgui.dll", EntryPoint = "XFont_CreateFromHFONT", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_CreateFromHFONT (int hFont);

		[DllImport("xcgui.dll", EntryPoint = "XFont_CreateFromFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_CreateFromFont (int pFont);

		[DllImport("xcgui.dll", EntryPoint = "XFont_CreateFromFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_CreateFromFile (string pFontFile,int size,int style);

		[DllImport("xcgui.dll", EntryPoint = "XFont_EnableAutoDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFont_EnableAutoDestroy (int hFontX,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XFont_GetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_GetFont (int hFontX);

		[DllImport("xcgui.dll", EntryPoint = "XFont_GetFontInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFont_GetFontInfo (int hFontX,xc_font_info_i* pInfo);

		[DllImport("xcgui.dll", EntryPoint = "XFont_AddRef", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFont_AddRef (int hFontX);

		[DllImport("xcgui.dll", EntryPoint = "XFont_Release", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFont_Release (int hFontX);

		[DllImport("xcgui.dll", EntryPoint = "XFont_GetRefCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFont_GetRefCount (int hFontX);

		[DllImport("xcgui.dll", EntryPoint = "XFont_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFont_Destroy (int hFontX);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFrameWnd_Create (int x,int y,int cx,int cy,string pTitle,int hWndParent,int XCStyle);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFrameWnd_CreateEx (int dwExStyle,string lpClassName,string lpWindowName,int dwStyle,int x,int y,int cx,int cy,int hWndParent,int XCStyle);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_GetLayoutAreaRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFrameWnd_GetLayoutAreaRect (int hWindow,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_SetView", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFrameWnd_SetView (int hWindow,int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_SetPaneSplitBarColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFrameWnd_SetPaneSplitBarColor (int hWindow,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_SaveLayoutToFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XFrameWnd_SaveLayoutToFile (int hWindow,string pFileName);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_LoadLayoutFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XFrameWnd_LoadLayoutFile (int hWindow,int aPaneList,int nEleCount,string pFileName);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_AddPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XFrameWnd_AddPane (int hWindow,int hPaneDest,int hPaneNew,int align);

		[DllImport("xcgui.dll", EntryPoint = "XFrameWnd_MergePane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XFrameWnd_MergePane (int hWindow,int hPaneDest,int hPaneNew);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadFile (string pImageName);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadFileRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadFileRect (string pImageName,int x,int y,int cx,int cy);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadRes", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadRes (int id,string pType);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadZip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadZip (string pZipFileName,string pImageName,string pPassword);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadZipRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadZipRect (string pZipFileName,string pImageName,string pPassword,int x,int y,int cx,int cy);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadMemory", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadMemory (int pBuffer,int nSize);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadMemoryRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadMemoryRect (int pBuffer,int nSize,int x,int y,int cx,int cy);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadFromImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadFromImage (int pImage);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadFileFromExtractIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadFileFromExtractIcon (string pImageName);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadFileFromHICON", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadFileFromHICON (int hIcon);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_LoadFileFromHBITMAP", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_LoadFileFromHBITMAP (int hBitmap);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_EnableAutoDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImgSrc_EnableAutoDestroy (int hImage,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_GetWidth (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_GetHeight (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_AddRef", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImgSrc_AddRef (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_Release", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImgSrc_Release (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_GetRefCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImgSrc_GetRefCount (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImgSrc_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImgSrc_Destroy (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadFile (string pImageName,bool bStretch);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadFileAdaptive (string pImageName,int leftSize,int topSize,int rightSize,int bottomSize);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadFileRect (string pImageName,int x,int y,int cx,int cy);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadResAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadResAdaptive (int id,string pType,int leftSize,int topSize,int rightSize,int bottomSize);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadRes", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadRes (int id,string pType,bool bStretch);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadZip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadZip (string pZipFileName,string pImageName,string pPassword,bool bStretch);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadZipAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadZipAdaptive (string pZipFileName,string pImageName,string pPassword,int x1,int x2,int y1,int y2);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadZipRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadZipRect (string pZipFileName,string pImageName,string pPassword,int x,int y,int cx,int cy);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadMemory", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadMemory (int pBuffer,int nSize,bool bStretch);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadMemoryRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadMemoryRect (int pBuffer,int nSize,int x,int y,int cx,int cy,bool bStretch);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadMemoryAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadMemoryAdaptive (int pBuffer,int nSize,int leftSize,int topSize,int rightSize,int bottomSize);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadFromImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadFromImage (int pImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileFromExtractIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadFileFromExtractIcon (string pImageName);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileFromHICON", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadFileFromHICON (int hIcon);

		[DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileFromHBITMAP", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_LoadFileFromHBITMAP (int hBitmap);

		[DllImport("xcgui.dll", EntryPoint = "XImage_IsStretch", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XImage_IsStretch (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_IsAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XImage_IsAdaptive (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_IsTile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XImage_IsTile (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_SetDrawType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XImage_SetDrawType (int hImage,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XImage_SetDrawTypeAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XImage_SetDrawTypeAdaptive (int hImage,int leftSize,int topSize,int rightSize,int bottomSize);

		[DllImport("xcgui.dll", EntryPoint = "XImage_SetTranColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_SetTranColor (int hImage,int color);

		[DllImport("xcgui.dll", EntryPoint = "XImage_SetTranColorEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_SetTranColorEx (int hImage,int color,byte tranColor);

		[DllImport("xcgui.dll", EntryPoint = "XImage_SetRotateAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern float XImage_SetRotateAngle (int hImage,float fAngle);

		[DllImport("xcgui.dll", EntryPoint = "XImage_SetSplitEqual", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_SetSplitEqual (int hImage,int nCount,int iIndex);

		[DllImport("xcgui.dll", EntryPoint = "XImage_EnableTranColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_EnableTranColor (int hImage,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XImage_EnableAutoDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_EnableAutoDestroy (int hImage,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XImage_EnableCenter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_EnableCenter (int hImage,bool bCenter);

		[DllImport("xcgui.dll", EntryPoint = "XImage_IsCenter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XImage_IsCenter (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_GetDrawType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_GetDrawType (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_GetWidth (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_GetHeight (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_GetHIMAGE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_GetHIMAGE (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_AddRef", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_AddRef (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_Release", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_Release (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_GetRefCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XImage_GetRefCount (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XImage_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XImage_Destroy (int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_Create ();

		[DllImport("xcgui.dll", EntryPoint = "XLayout_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_Destroy (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_AddEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_AddEle (int hLayout,int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_AddLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_AddLayoutObject (int hLayout,int hLayoutObject);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_AddShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_AddShape (int hLayout,int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_Add", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XLayout_Add (int hLayout,int hChild);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_Insert", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XLayout_Insert (int hLayout,int hChild,int index);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_IsShow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XLayout_IsShow (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_RemoveLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_RemoveLayout (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_RemoveChild", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_RemoveChild (int hLayout,int hChild);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetZOrder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetZOrder (int hLayout,int hChild);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_AdjustLayout (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetRectFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetRectFrame (int hLayout,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_GetRect (int hLayout,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetRectFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_GetRectFrame (int hLayout,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetBkManager", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetBkManager (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetWindow (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetEle (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetParentLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetParentLayout (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetParent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetParent (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetID (int hLayout,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetID (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetUID (int hLayout,int nUID);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetUID (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetName (int hLayout,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XLayout_GetName (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetHorizon (int hLayout,bool bHorizon);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetAlignH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetAlignH (int hLayout,int nAlign);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetAlignV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetAlignV (int hLayout,int nAlign);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetPadding (int hLayout,int left,int top,int right,int bottom);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetSpace (int hLayout,int nSpace);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetLayoutWidth (int hLayout,int nType,int nWidth);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_SetLayoutHeight (int hLayout,int nType,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_GetLayoutWidth (int hLayout,int pType,int pWidth);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_GetLayoutHeight (int hLayout,int pType,int pHeight);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetWidth (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetHeight (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetWidthIn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetWidthIn (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetHeightIn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetHeightIn (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetContentSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_GetContentSize (int hLayout,SIZE* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_Show", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_Show (int hLayout,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_ShowLayoutFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_ShowLayoutFrame (int hLayout,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetChildCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetChildCount (int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetChildType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetChildType (int hLayout,int index);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_GetChild", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XLayout_GetChild (int hLayout,int index);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_Draw", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_Draw (int hLayout,int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "XLayout_DrawFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XLayout_DrawFrame (int hLayout,int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "Layout_SetEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void Layout_SetEle (int hLayout,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_SetDrawItemBkFlags (int hEle,int nFlags);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_SetItemData (int hEle,int iItem,int nUserData);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetItemData (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_SetItemInfo (int hEle,int iItem,listBox_item_info_i* pItem);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_GetItemInfo (int hEle,int iItem,listBox_item_info_i* pItem);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_AddItemBkBorder (int hEle,int nState,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_AddItemBkFill (int hEle,int nState,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_AddItemBkImage (int hEle,int nState,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetItemBkInfoCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_ClearItemBkInfo (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_SetSelectItem (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetSelectItem (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_CancelSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_CancelSelectItem (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_CancelSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_CancelSelectAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetSelectAll (int hEle,int pArray,int nArraySize);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetSelectCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetSelectCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemMouseStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetItemMouseStay (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_SelectAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_SetItemHeightDefault (int hEle,int nHeight,int nSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_GetItemHeightDefault (int hEle,int pHeight,int pSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemIndexFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetItemIndexFromHXCGUI (int hEle,int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_SetRowSpace (int hEle,int nSpace);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetRowSpace (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_HitTest (int hEle,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_HitTestOffset (int hEle,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_SetItemTemplateXML (int hEle,string pXmlFile);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_SetItemTemplateXMLFromString (int hEle,string pStringXML);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemTemplate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListBox_SetItemTemplate (int hEle,int hTemp);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetTemplateObject (int hEle,int iItem,int nTempItemID);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_EnableMultiSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_EnableMultiSel (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_CreateAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_BindAdapter (int hEle,int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListBox_GetAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_Sort", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_Sort (int hEle,int iColumnAdapter,bool bAscending);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_RefreshData (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListBox_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListBox_RefreshItem (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_Load", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTemp_Load (int nType,string pFileName);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_LoadZip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTemp_LoadZip (int nType,string pZipFile,string pFileName,string pPassword);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_LoadEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTemp_LoadEx (int nType,string pFileName,int pOutTemp1,int pOutTemp2);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_LoadZipEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTemp_LoadZipEx (int nType,string pZipFile,string pFileName,string pPassword,int pOutTemp1,int pOutTemp2);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_LoadFromStringEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTemp_LoadFromStringEx (int nType,string pStringXML,int pOutTemp1,int pOutTemp2);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_LoadFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTemp_LoadFromString (int nType,string pStringXML);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_GetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTemp_GetType (int hTemp);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTemp_Destroy (int hTemp);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTemp_Create (int nType);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_AddNodeRoot", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTemp_AddNodeRoot (int hTemp,int pNode);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_AddNode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTemp_AddNode (int pParentNode,int pNode);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_CreateNode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTemp_CreateNode (int nType);

		[DllImport("xcgui.dll", EntryPoint = "XTemp_SetNodeAttribute", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTemp_SetNodeAttribute (int pNode,string pName,string pAttr);

		[DllImport("xcgui.dll", EntryPoint = "XList_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XList_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_AddColumn (int hEle,int width);

		[DllImport("xcgui.dll", EntryPoint = "XList_InsertColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_InsertColumn (int hEle,int width,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XList_EnableMultiSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_EnableMultiSel (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XList_EnableDragChangeColumnWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_EnableDragChangeColumnWidth (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XList_EnableVScrollBarTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_EnableVScrollBarTop (int hEle,bool bTop);

		[DllImport("xcgui.dll", EntryPoint = "XList_EnableItemBkFullRow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_EnableItemBkFullRow (int hEle,bool bFull);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetSort", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetSort (int hEle,int iColumn,int iColumnAdapter,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetDrawItemBkFlags (int hEle,int style);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetColumnWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetColumnWidth (int hEle,int iItem,int width);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetColumnMinWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetColumnMinWidth (int hEle,int iItem,int width);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetColumnWidthFixed", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetColumnWidthFixed (int hEle,int iColumn,bool bFixed);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetColumnWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetColumnWidth (int hEle,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetColumnCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetColumnCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_DeleteColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_DeleteColumn (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XList_DeleteColumnAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_DeleteColumnAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_SetItemData (int hEle,int iItem,int iSubItem,int data);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetItemData (int hEle,int iItem,int iSubItem);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_SetSelectItem (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetSelectItem (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetSelectItemCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetSelectItemCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetSelectAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetSelectAll (int hEle,int pArray,int nArraySize);

		[DllImport("xcgui.dll", EntryPoint = "XList_CancelSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_CancelSelectItem (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XList_CancelSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_CancelSelectAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetHeaderHELE (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_BindAdapter (int hEle,int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XList_BindAdapterHeader", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_BindAdapterHeader (int hEle,int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XList_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_CreateAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_CreateAdapterHeader", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_CreateAdapterHeader (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetAdapterHeader", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetAdapterHeader (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_SetItemTemplateXML (int hEle,string pXmlFile);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_SetItemTemplateXMLFromString (int hEle,string pStringXML);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetItemTemplate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_SetItemTemplate (int hEle,int hTemp);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetTemplateObject (int hEle,int iItem,int nTempItemID);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetItemIndexFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetItemIndexFromHXCGUI (int hEle,int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetHeaderTemplateObject (int hEle,int iItem,int nTempItemID);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderItemIndexFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetHeaderItemIndexFromHXCGUI (int hEle,int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetHeaderHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetHeaderHeight (int hEle,int height);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetHeaderHeight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetVisibleRowRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_GetVisibleRowRange (int hEle,int piStart,int piEnd);

		[DllImport("xcgui.dll", EntryPoint = "XList_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_AddItemBkBorder (int hEle,int nState,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XList_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_AddItemBkFill (int hEle,int nState,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XList_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_AddItemBkImage (int hEle,int nState,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetItemBkInfoCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_ClearItemBkInfo (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetItemHeightDefault (int hEle,int nHeight,int nSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_GetItemHeightDefault (int hEle,int pHeight,int pSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetRowSpace (int hEle,int nSpace);

		[DllImport("xcgui.dll", EntryPoint = "XList_GetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XList_GetRowSpace (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetLockColumnLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetLockColumnLeft (int hEle,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetLockColumnRight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetLockColumnRight (int hEle,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XList_SetLockRowBottom", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_SetLockRowBottom (int hEle,bool bLock);

		[DllImport("xcgui.dll", EntryPoint = "XList_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_HitTest (int hEle,POINT* pPt,int piItem,int piSubItem);

		[DllImport("xcgui.dll", EntryPoint = "XList_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XList_HitTestOffset (int hEle,POINT* pPt,int piItem,int piSubItem);

		[DllImport("xcgui.dll", EntryPoint = "XList_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_RefreshData (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XList_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XList_RefreshItem (int hEle,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XListView_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_CreateAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_BindAdapter (int hEle,int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_SetItemTemplateXML (int hEle,string pXmlFile);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_SetItemTemplateXMLFromString (int hEle,string pStringXML);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetItemTemplate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_SetItemTemplate (int hEle,int hTemp);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetTemplateObject (int hEle,int iGroup,int iItem,int nTempItemID);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetTemplateObjectGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetTemplateObjectGroup (int hEle,int iGroup,int nTempItemID);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetItemIDFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_GetItemIDFromHXCGUI (int hEle,int hXCGUI,int piGroup,int piItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_HitTest (int hEle,POINT* pPt,int pOutGroup,int pOutItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_HitTestOffset (int hEle,POINT* pPt,int pOutGroup,int pOutItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_EnableMultiSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_EnableMultiSel (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetDrawItemBkFlags (int hEle,int nFlags);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_SetSelectItem (int hEle,int iGroup,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_GetSelectItem (int hEle,int piGroup,int piItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetSelectItemCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetSelectItemCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetSelectItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetSelectItemAll (int hEle,listView_item_id_i* pArray,int nArraySize);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetSelectItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetSelectItemAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_CancelSelectItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_CancelSelectItemAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetColumnSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetColumnSpace (int hEle,int space);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetRowSpace (int hEle,int space);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetAlignSizeLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetAlignSizeLeft (int hEle,int size);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetAlignSizeTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetAlignSizeTop (int hEle,int size);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetItemSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetItemSize (int hEle,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetItemSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_GetItemSize (int hEle,SIZE* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetGroupHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetGroupHeight (int hEle,int height);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetGroupHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetGroupHeight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetGroupUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetGroupUserData (int hEle,int iGroup,int nData);

		[DllImport("xcgui.dll", EntryPoint = "XListView_SetItemUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_SetItemUserData (int hEle,int iGroup,int iItem,int nData);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetGroupUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetGroupUserData (int hEle,int iGroup);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetItemUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetItemUserData (int hEle,int iGroup,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_AddItemBkBorder (int hEle,int nState,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XListView_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_AddItemBkFill (int hEle,int nState,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XListView_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_AddItemBkImage (int hEle,int nState,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XListView_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XListView_GetItemBkInfoCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_ClearItemBkInfo (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_RefreshData (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XListView_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XListView_RefreshItem (int hEle,int iGroup,int iItem);

		[DllImport("xcgui.dll", EntryPoint = "XListView_ExpandGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XListView_ExpandGroup (int hEle,int iGroup,bool bExpand);

		[DllImport("xcgui.dll", EntryPoint = "XMenuBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenuBar_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XMenuBar_AddButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenuBar_AddButton (int hEle,string pText);

		[DllImport("xcgui.dll", EntryPoint = "XMenuBar_SetButtonHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenuBar_SetButtonHeight (int hEle,int height);

		[DllImport("xcgui.dll", EntryPoint = "XMenuBar_GetMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenuBar_GetMenu (int hEle,int nIndex);

		[DllImport("xcgui.dll", EntryPoint = "XMenuBar_DeleteButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenuBar_DeleteButton (int hEle,int nIndex);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_Create ();

		[DllImport("xcgui.dll", EntryPoint = "XMenu_AddItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_AddItem (int hMenu,int nID,string pText,int parentId,int nFlags);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_AddItemIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_AddItemIcon (int hMenu,int nID,string pText,int nParentID,int hImage,int nFlags);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_InsertItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_InsertItem (int hMenu,int nID,string pText,int nFlags,int insertID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_InsertItemIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_InsertItemIcon (int hMenu,int nID,string pText,int hIcon,int nFlags,int insertID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetFirstChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetFirstChildItem (int hMenu,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetEndChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetEndChildItem (int hMenu,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetPrevSiblingItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetPrevSiblingItem (int hMenu,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetNextSiblingItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetNextSiblingItem (int hMenu,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetParentItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetParentItem (int hMenu,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetAutoDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_SetAutoDestroy (int hMenu,bool bAuto);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_EnableDrawBackground", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_EnableDrawBackground (int hMenu,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_EnableDrawItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_EnableDrawItem (int hMenu,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_Popup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenu_Popup (int hMenu,int hParentWnd,int x,int y,int hParentEle,int nPosition);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_DestroyMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_DestroyMenu (int hMenu);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_CloseMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_CloseMenu (int hMenu);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_SetBkImage (int hMenu,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenu_SetItemText (int hMenu,int nID,string pText);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenu_GetItemText (int hMenu,int nID,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemTextLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetItemTextLength (int hMenu,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenu_SetItemIcon (int hMenu,int nID,int hIcon);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenu_SetItemFlags (int hMenu,int nID,int uFlags);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_SetItemHeight (int hMenu,int height);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetItemHeight (int hMenu);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_SetBorderColor (int hMenu,int crColor,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XMenu_SetBorderSize (int hMenu,int nLeft,int nTop,int nRight,int nBottom);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetLeftWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetLeftWidth (int hMenu);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetLeftSpaceText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetLeftSpaceText (int hMenu);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XMenu_GetItemCount (int hMenu);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenu_SetItemCheck (int hMenu,int nID,bool bCheck);

		[DllImport("xcgui.dll", EntryPoint = "XMenu_IsItemCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XMenu_IsItemCheck (int hMenu,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XModalWnd_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XModalWnd_Create (int nWidth,int nHeight,string pTitle,int hWndParent,int XCStyle);

		[DllImport("xcgui.dll", EntryPoint = "XModalWnd_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XModalWnd_CreateEx (int dwExStyle,string lpClassName,string lpWindowName,int dwStyle,int x,int y,int cx,int cy,int hWndParent,int XCStyle);

		[DllImport("xcgui.dll", EntryPoint = "XModalWnd_EnableAutoClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XModalWnd_EnableAutoClose (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XModalWnd_EnableEscClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XModalWnd_EnableEscClose (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XModalWnd_DoModal", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XModalWnd_DoModal (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XModalWnd_EndModal", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XModalWnd_EndModal (int hWindow,int nResult);

		[DllImport("xcgui.dll", EntryPoint = "XPane_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPane_Create (string pName,int nWidth,int nHeight,int hFrameWnd);

		[DllImport("xcgui.dll", EntryPoint = "XPane_SetView", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_SetView (int hEle,int hView);

		[DllImport("xcgui.dll", EntryPoint = "XPane_IsShowPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XPane_IsShowPane (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_SetSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_SetSize (int hEle,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XPane_GetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPane_GetState (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_GetViewRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_GetViewRect (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XPane_SetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_SetTitle (int hEle,string pTitle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_GetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_GetTitle (int hEle,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XPane_SetCaptionHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_SetCaptionHeight (int hEle,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XPane_GetCaptionHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPane_GetCaptionHeight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_HidePane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_HidePane (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_ShowPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_ShowPane (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_DockPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_DockPane (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_LockPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_LockPane (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPane_FloatPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPane_FloatPane (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XFloatWnd_EnableCaptionContent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XFloatWnd_EnableCaptionContent (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetCaptionLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFloatWnd_GetCaptionLayout (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetCaptionShapeText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFloatWnd_GetCaptionShapeText (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetCaptionButtonClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XFloatWnd_GetCaptionButtonClose (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XFloatWnd_SetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFloatWnd_SetTitle (int hWindow,string pTitle);

		[DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XFloatWnd_GetTitle (int hWindow,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XProgBar_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_SetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XProgBar_SetRange (int hEle,int range);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_GetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XProgBar_GetRange (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_SetSpaceTwo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XProgBar_SetSpaceTwo (int hEle,int leftSize,int rightSize);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_SetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XProgBar_SetPos (int hEle,int pos);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_GetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XProgBar_GetPos (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XProgBar_SetHorizon (int hEle,bool bHorizon);

		[DllImport("xcgui.dll", EntryPoint = "XProgBar_SetImageLoad", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XProgBar_SetImageLoad (int hEle,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_AddItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_AddItem (int hEle,string pName,int nType,int nParentID);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_AddItemString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_AddItemString (int hEle,string pName,string pValue,int nParentID);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_DeleteAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPGrid_DeleteAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_GetItemHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_GetItemHELE (int hEle,int nItemID);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_SetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPGrid_SetWidth (int hEle,int nWidth);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_SetItemValue", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XPGrid_SetItemValue (int hEle,int nItemID,string pValue);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_SetItemValueInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XPGrid_SetItemValueInt (int hEle,int nItemID,int nValue);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XPGrid_SetItemData (int hEle,int nItemID,int nUserData);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_GetItemData (int hEle,int nItemID);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_GetItemValue", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XPGrid_GetItemValue (int hEle,int nItemID);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_HitTest (int hEle,POINT* pPt,bool pbExpandButton);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_HitTestOffset (int hEle,POINT* pPt,bool pbExpandButton);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_ExpandItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XPGrid_ExpandItem (int hEle,int nItemID,bool bExpand);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_GetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XPGrid_GetSelItem (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_SetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XPGrid_SetSelItem (int hEle,int nItemID);

		[DllImport("xcgui.dll", EntryPoint = "XPGrid_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XPGrid_SetDrawItemBkFlags (int hEle,int nFlags);

		[DllImport("xcgui.dll", EntryPoint = "XRes_EnableDelayLoad", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRes_EnableDelayLoad (bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRes_SetLoadFileCallback", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRes_SetLoadFileCallback (int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XRes_GetIDValue", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRes_GetIDValue (string pName);

		[DllImport("xcgui.dll", EntryPoint = "XRes_GetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRes_GetImage (string pName);

		[DllImport("xcgui.dll", EntryPoint = "XRes_GetImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRes_GetImageEx (string pFileName,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XRes_GetColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRes_GetColor (string pName);

		[DllImport("xcgui.dll", EntryPoint = "XRes_GetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRes_GetFont (string pName);

		[DllImport("xcgui.dll", EntryPoint = "XRes_GetBkM", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRes_GetBkM (string pName);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditColor_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEditColor_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditColor_SetColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEditColor_SetColor (int hEle,int color);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditColor_GetColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEditColor_GetColor (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditSet_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEditSet_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditFile_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEditFile_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditFile_SetOpenFileType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEditFile_SetOpenFileType (int hEle,string pType);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditFile_SetDefaultFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEditFile_SetDefaultFile (int hEle,string pFile);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditFile_SetRelativeDir", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEditFile_SetRelativeDir (int hEle,string pDir);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditFolder_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEditFolder_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XRichEditFolder_SetDefaultDir", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEditFolder_SetDefaultDir (int hEle,string pDir);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_InsertString (int hEle,string pString,int hFont);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_InsertImage (int hEle,int hImage,string pImagePath);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertGif", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_InsertGif (int hEle,int hImage,string pImagePath);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertStringEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_InsertStringEx (int hEle,int iRow,int iColumn,string pString,int hFont);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_InsertImageEx (int hEle,int iRow,int iColumn,int hImage,string pImagePath);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertGifEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_InsertGifEx (int hEle,int iRow,int iColumn,int hImage,string pImagePath);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableReadOnly", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_EnableReadOnly (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableMultiLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_EnableMultiLine (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnablePassword", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_EnablePassword (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableAutoWrap", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_EnableAutoWrap (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableAutoSelAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_EnableAutoSelAll (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableVerticalCenter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_EnableVerticalCenter (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_IsEmpty", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_IsEmpty (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_IsReadOnly", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_IsReadOnly (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_IsMultiLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_IsMultiLine (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_IsPassword", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_IsPassword (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_IsAutoWrap", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_IsAutoWrap (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetLimitNum", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetLimitNum (int hEle,int nNumber);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetCaretColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetCaretColor (int hEle,int color);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetText (int hEle,string pString);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetTextInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetTextInt (int hEle,int nVaule);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetText (int hEle,string pOut,int len);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetHTMLFormat", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_GetHTMLFormat (int hEle,string pOut,int len);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetData (int hEle,int pDataSize);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_InsertData (int hEle,int pData,int iRow,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetTextLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetTextLength (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetRowHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetRowHeight (int hEle,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetDefaultText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetDefaultText (int hEle,string pString);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetDefaultTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetDefaultTextColor (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetCurrentInputTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetCurrentInputTextColor (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetCurrentRow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetCurrentRow (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetCurrentColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetCurrentColumn (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetCurrentPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetCurrentPos (int hEle,int iRow,int iColumn);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetRowCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetRowCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetRowLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetRowLength (int hEle,int iRow);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetSelectText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XRichEdit_GetSelectText (int hEle,string pOut,int len);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetSelectPosition", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_GetSelectPosition (int hEle,Position_i* pBegin,Position_i* pEnd);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_SetSelect (int hEle,int iStartRow,int iStartCol,int iEndRow,int iEndCol);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetItemFontEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_SetItemFontEx (int hEle,int beginRow,int beginColumn,int endRow,int endColumn,int hFont);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetItemColorEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_SetItemColorEx (int hEle,int beginRow,int beginColumn,int endRow,int endColumn,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_CancelSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_CancelSelect (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetSelectBkColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_SetSelectBkColor (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_SelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_SelectAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_DeleteSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_DeleteSelect (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_DeleteAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XRichEdit_DeleteAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_ClipboardCut", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_ClipboardCut (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_ClipboardCopy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_ClipboardCopy (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XRichEdit_ClipboardPaste", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XRichEdit_ClipboardPaste (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSBar_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_SetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSBar_SetRange (int hEle,int range);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_GetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSBar_GetRange (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_ShowButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSBar_ShowButton (int hEle,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_SetSliderLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSBar_SetSliderLength (int hEle,int length);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_SetSliderMinLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSBar_SetSliderMinLength (int hEle,int minLength);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_SetSliderPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSBar_SetSliderPadding (int hEle,int nPadding);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSBar_SetHorizon (int hEle,bool bHorizon);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_GetSliderMaxLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSBar_GetSliderMaxLength (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollUp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSBar_ScrollUp (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollDown", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSBar_ScrollDown (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSBar_ScrollTop (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollBottom", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSBar_ScrollBottom (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSBar_ScrollPos (int hEle,int pos);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_GetButtonUp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSBar_GetButtonUp (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_GetButtonDown", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSBar_GetButtonDown (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSBar_GetButtonSlider", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSBar_GetButtonSlider (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSView_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XSView_SetTotalSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_SetTotalSize (int hEle,int cx,int cy);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetTotalSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_GetTotalSize (int hEle,SIZE* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XSView_SetLineSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_SetLineSize (int hEle,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetLineSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_GetLineSize (int hEle,SIZE pSize);

		[DllImport("xcgui.dll", EntryPoint = "XSView_SetScrollBarSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_SetScrollBarSize (int hEle,int size);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetViewPosH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSView_GetViewPosH (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetViewPosV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSView_GetViewPosV (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetViewWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSView_GetViewWidth (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetViewHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSView_GetViewHeight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetViewRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_GetViewRect (int hEle,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetScrollBarH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSView_GetScrollBarH (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetScrollBarV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSView_GetScrollBarV (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_SetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_SetBorderSize (int hEle,int left,int top,int right,int bottom);

		[DllImport("xcgui.dll", EntryPoint = "XSView_GetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_GetBorderSize (int hEle,BorderSize_i* pBorder);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollPosH (int hEle,int pos);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollPosV (int hEle,int pos);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosXH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollPosXH (int hEle,int posX);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosYV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollPosYV (int hEle,int posY);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ShowSBarH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_ShowSBarH (int hEle,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ShowSBarV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_ShowSBarV (int hEle,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XSView_EnableAutoShowScrollBar", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSView_EnableAutoShowScrollBar (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollLeftLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollLeftLine (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollRightLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollRightLine (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollTopLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollTopLine (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollBottomLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollBottomLine (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollLeft (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollRight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollRight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollTop (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSView_ScrollBottom", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XSView_ScrollBottom (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetParentEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetParentEle (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetParentLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetParentLayout (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetHWINDOW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetHWINDOW (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetParent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetParent (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_RemoveShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_RemoveShape (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_SetID (int hShape,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetID (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_SetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_SetUID (int hShape,int nUID);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetUID (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_SetName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_SetName (int hShape,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XShape_GetName (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_Redraw", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_Redraw (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetWidth (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShape_GetHeight (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_GetRect (int hShape,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XShape_SetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_SetRect (int hShape,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetWndClientRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_GetWndClientRect (int hShape,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XShape_GetContentSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_GetContentSize (int hShape,SIZE* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XShape_ShowLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_ShowLayout (int hShape,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XShape_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_AdjustLayout (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShape_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShape_Destroy (int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeText_Create (int x,int y,int cx,int cy,string pName,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetText (int hTextBlock,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_GetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_GetText (int hTextBlock,string pOut,int nOutLen);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_GetTextLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeText_GetTextLength (int hTextBlock);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetFont (int hTextBlock,int hFontx);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_GetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeText_GetFont (int hTextBlock);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetTextColor (int hTextBlock,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_GetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeText_GetTextColor (int hTextBlock);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetTextAlign (int hTextBlock,int align);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetOffset (int hTextBlock,int x,int y);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetLayoutWidth (int hTextBlock,int nType,int width);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetLayoutHeight (int hTextBlock,int nType,int height);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_GetLayoutWidth (int hTextBlock,int pType,int pWidth);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_GetLayoutHeight (int hTextBlock,int pType,int pHeight);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_EnableCSS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_EnableCSS (int hTextBlock,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_SetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeText_SetCssName (int hTextBlock,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XShapeText_GetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XShapeText_GetCssName (int hTextBlock);

		[DllImport("xcgui.dll", EntryPoint = "XShapePic_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapePic_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XShapePic_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapePic_SetImage (int hShape,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XShapePic_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapePic_SetLayoutWidth (int hShape,int nType,int width);

		[DllImport("xcgui.dll", EntryPoint = "XShapePic_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapePic_SetLayoutHeight (int hShape,int nType,int height);

		[DllImport("xcgui.dll", EntryPoint = "XShapePic_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapePic_GetLayoutWidth (int hShape,int pType,int pWidth);

		[DllImport("xcgui.dll", EntryPoint = "XShapePic_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapePic_GetLayoutHeight (int hShape,int pType,int pHeight);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGif_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeGif_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGif_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGif_SetImage (int hShape,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGif_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGif_SetLayoutWidth (int hShape,int nType,int width);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGif_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGif_SetLayoutHeight (int hShape,int nType,int height);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGif_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGif_GetLayoutWidth (int hShape,int pType,int pWidth);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGif_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGif_GetLayoutHeight (int hShape,int pType,int pHeight);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeRect_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeRect_SetBorderColor (int hShape,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_SetFillColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeRect_SetFillColor (int hShape,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_SetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeRect_SetRoundAngle (int hShape,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_GetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeRect_GetRoundAngle (int hShape,int pWidth,int pHeight);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_EnableBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeRect_EnableBorder (int hShape,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_EnableFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeRect_EnableFill (int hShape,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XShapeRect_EnableRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeRect_EnableRoundAngle (int hShape,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeEllipse_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeEllipse_SetBorderColor (int hShape,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_SetFillColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeEllipse_SetFillColor (int hShape,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_EnableBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeEllipse_EnableBorder (int hShape,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_EnableFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeEllipse_EnableFill (int hShape,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeGroupBox_Create (int x,int y,int cx,int cy,string pName,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_SetBorderColor (int hShape,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_SetTextColor (int hShape,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetFontX", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_SetFontX (int hShape,int hFontX);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetTextOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_SetTextOffset (int hShape,int offsetX,int offsetY);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_SetRoundAngle (int hShape,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_SetText (int hShape,string pText);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_GetTextOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_GetTextOffset (int hShape,int pOffsetX,int pOffsetY);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_GetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_GetRoundAngle (int hShape,int pWidth,int pHeight);

		[DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_EnableRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeGroupBox_EnableRoundAngle (int hShape,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XShapeLine_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XShapeLine_Create (int x1,int y1,int x2,int y2,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XShapeLine_SetPosition", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeLine_SetPosition (int hShape,int x1,int y1,int x2,int y2);

		[DllImport("xcgui.dll", EntryPoint = "XShapeLine_SetColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XShapeLine_SetColor (int hShape,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSliderBar_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSliderBar_SetRange (int hEle,int range);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_GetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSliderBar_GetRange (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetButtonWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSliderBar_SetButtonWidth (int hEle,int width);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetButtonHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSliderBar_SetButtonHeight (int hEle,int height);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetSpaceTwo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSliderBar_SetSpaceTwo (int hEle,int leftSize,int rightSize);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSliderBar_SetPos (int hEle,int pos);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_GetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSliderBar_GetPos (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_GetButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XSliderBar_GetButton (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSliderBar_SetHorizon (int hEle,bool bHorizon);

		[DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetImageLoad", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XSliderBar_SetImageLoad (int hEle,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_AddLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_AddLabel (int hEle,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_InsertLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_InsertLabel (int hEle,int index,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_DeleteLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTabBar_DeleteLabel (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_DeleteLabelAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_DeleteLabelAll (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetLabel (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabelClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetLabelClose (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetButtonLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetButtonLeft (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetButtonRight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetButtonRight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetSelect (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabelSpacing", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetLabelSpacing (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabelCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetLabelCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_GetindexByEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTabBar_GetindexByEle (int hEle,int hLabel);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetLabelSpacing", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetLabelSpacing (int hEle,int spacing);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetPadding (int hEle,int left,int top,int right,int bottom);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetSelect (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetUp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetUp (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetDown", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetDown (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_EnableTile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_EnableTile (int hEle,bool bTile);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_EnableClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_EnableClose (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetCloseSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetCloseSize (int hEle,SIZE* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetTurnButtonSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetTurnButtonSize (int hEle,SIZE* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_SetLabelWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTabBar_SetLabelWidth (int hEle,int index,int nWidth);

		[DllImport("xcgui.dll", EntryPoint = "XTabBar_ShowLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTabBar_ShowLabel (int hEle,int index,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XTextLink_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTextLink_Create (int x,int y,int cx,int cy,string pName,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XTextLink_EnableUnderlineLeave", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTextLink_EnableUnderlineLeave (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XTextLink_EnableUnderlineStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTextLink_EnableUnderlineStay (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XTextLink_SetTextColorStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTextLink_SetTextColorStay (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XTextLink_SetUnderlineColorLeave", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTextLink_SetUnderlineColorLeave (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XTextLink_SetUnderlineColorStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTextLink_SetUnderlineColorStay (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XToolBar_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_InsertEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XToolBar_InsertEle (int hEle,int hNewEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_InsertSeparator", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XToolBar_InsertSeparator (int hEle,int index,int color);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_EnableButtonMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XToolBar_EnableButtonMenu (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_GetHEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XToolBar_GetHEle (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_GetButtonLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XToolBar_GetButtonLeft (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_GetButtonRight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XToolBar_GetButtonRight (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_GetButtonMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XToolBar_GetButtonMenu (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_SetSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XToolBar_SetSpace (int hEle,int nSize);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_DeleteEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XToolBar_DeleteEle (int hEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XToolBar_DeleteAllEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XToolBar_DeleteAllEle (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_Create (int x,int y,int cx,int cy,int hParent);

		[DllImport("xcgui.dll", EntryPoint = "XTree_EnableDragItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_EnableDragItem (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XTree_EnableConnectLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_EnableConnectLine (int hEle,bool bEnable,bool bSolid);

		[DllImport("xcgui.dll", EntryPoint = "XTree_EnableExpand", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_EnableExpand (int hEle,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetConnectLineColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetConnectLineColor (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetExpandButtonSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetExpandButtonSize (int hEle,int nWidth,int nHeight);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetConnectLineLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetConnectLineLength (int hEle,int nLength);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetDragInsertPositionColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetDragInsertPositionColor (int hEle,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetItemTemplateXML (int hEle,string pXmlFile);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXMLSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetItemTemplateXMLSel (int hEle,string pXmlFile);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetItemTemplate (int hEle,int hTemp);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetItemTemplateSel (int hEle,int hTemp);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetItemTemplateXMLFromString (int hEle,string pStringXML);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXMLSelFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetItemTemplateXMLSelFromString (int hEle,string pStringXML);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetDrawItemBkFlags (int hEle,int nFlags);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetItemData (int hEle,int nID,int nUserData);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetItemData (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_SetSelectItem (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetSelectItem (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_IsExpand", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_IsExpand (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_ExpandItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_ExpandItem (int hEle,int nID,bool bExpand);

		[DllImport("xcgui.dll", EntryPoint = "XTree_ExpandAllChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_ExpandAllChildItem (int hEle,int nID,bool bExpand);

		[DllImport("xcgui.dll", EntryPoint = "XTree_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_HitTest (int hEle,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XTree_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_HitTestOffset (int hEle,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetFirstChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetFirstChildItem (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetEndChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetEndChildItem (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetPrevSiblingItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetPrevSiblingItem (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetNextSiblingItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetNextSiblingItem (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetParentItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetParentItem (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetIndentation", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetIndentation (int hEle,int nWidth);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetIndentation", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetIndentation (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetItemHeight (int hEle,int nID,int nHeight,int nSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_GetItemHeight (int hEle,int nID,int pHeight,int pSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetRowSpace (int hEle,int nSpace);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetRowSpace (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_MoveItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XTree_MoveItem (int hEle,int nMoveItem,int nDestItem,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XTree_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_AddItemBkBorder (int hEle,int nState,int color,byte alpha,int width);

		[DllImport("xcgui.dll", EntryPoint = "XTree_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_AddItemBkFill (int hEle,int nState,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XTree_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_AddItemBkImage (int hEle,int nState,int hImage);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetItemBkInfoCount (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_ClearItemBkInfo (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_SetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_SetItemHeightDefault (int hEle,int nHeight,int nSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_GetItemHeightDefault (int hEle,int pHeight,int pSelHeight);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetTemplateObject (int hEle,int nID,int nTempItemID);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetItemIDFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetItemIDFromHXCGUI (int hEle,int hXCGUI);

		[DllImport("xcgui.dll", EntryPoint = "XTree_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_CreateAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_BindAdapter (int hEle,int hAdapter);

		[DllImport("xcgui.dll", EntryPoint = "XTree_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XTree_GetAdapter (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_RefreshData (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XTree_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XTree_RefreshItem (int hEle,int nID);

		[DllImport("xcgui.dll", EntryPoint = "_XWnd_RegEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool _XWnd_RegEvent (int hWindow,int nEvent,int pEvent);

		[DllImport("xcgui.dll", EntryPoint = "_XWnd_RemoveEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool _XWnd_RemoveEvent (int hWindow,int nEvent,int pEvent);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_RegEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_RegEventC (int hWindow,int nEvent,int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_RegEventC1", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_RegEventC1 (int hWindow,int nEvent,int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_RemoveEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_RemoveEventC (int hWindow,int nEvent,int pFun);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_Create (int x,int y,int cx,int cy,string pTitle,int hWndParent,int XCStyle);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_CreateEx (int dwExStyle,string lpClassName,string lpWindowName,int dwStyle,int x,int y,int cx,int cy,int hWndParent,int XCStyle);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_AddEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_AddEle (int hWindow,int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_InsertEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_InsertEle (int hWindow,int hChildEle,int index);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_AddShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_AddShape (int hWindow,int hShape);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetHWND", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetHWND (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDragBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_EnableDragBorder (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDragWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_EnableDragWindow (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDragCaption", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_EnableDragCaption (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDrawBk", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_EnableDrawBk (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_EnableAutoFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_EnableAutoFocus (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_EnableMaxWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_EnableMaxWindow (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_RedrawWnd", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_RedrawWnd (int hWindow,bool bImmediate);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_RedrawWndRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_RedrawWndRect (int hWindow,RECT* pRect,bool bImmediate);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetFocusEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetFocusEle (int hWindow,int hFocusEle);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetFocusEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetFocusEle (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetStayHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetStayHELE (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_DrawWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_DrawWindow (int hWindow,int hDraw);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_Center", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_Center (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_CenterEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_CenterEx (int hWindow,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetCursor (int hWindow,int hCursor);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetCursor (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCursorSys", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_SetCursorSys (int hWindow,int hCursor);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetFont (int hWindow,int hFontx);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetTextColor (int hWindow,int color,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetTextColor (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetID (int hWindow,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetID (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaptureEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetCaptureEle (int hWindow,int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetCaptureEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetCaptureEle (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_BindLayoutEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_BindLayoutEle (int hWindow,int nPosition,int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetLayoutEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetLayoutEle (int hWindow,int nPosition);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_BindLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_BindLayoutObject (int hWindow,int nPosition,int hLayout);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetLayoutObject (int hWindow,int nPosition);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetLayoutSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetLayoutSize (int hWindow,int left,int top,int right,int bottom);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetLayoutSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_GetLayoutSize (int hWindow,BorderSize_i* pBorderSize);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetDragBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetDragBorderSize (int hWindow,int left,int top,int right,int bottom);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetDragBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_GetDragBorderSize (int hWindow,BorderSize_i* pSize);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetMinimumSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetMinimumSize (int hWindow,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_HitChildEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_HitChildEle (int hWindow,POINT* pPt);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetChildCount (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildByIndex", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetChildByIndex (int hWindow,int index);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildByID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetChildByID (int hWindow,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetChild", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetChild (int hWindow,int nID);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildShapeCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetChildShapeCount (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildShapeByIndex", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetChildShapeByIndex (int hWindow,int index);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetDrawRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_GetDrawRect (int hWindow,RECT* pRcPaint);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_ShowWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_ShowWindow (int hWindow,int nCmdShow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_AdjustLayout (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_AdjustLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_AdjustLayoutObject (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_CloseWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_CloseWindow (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_CreateCaret", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_CreateCaret (int hWindow,int hEle,int x,int y,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetCaretSize (int hWindow,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetCaretPos (int hWindow,int x,int y);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretPosEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetCaretPosEx (int hWindow,int x,int y,int width,int height);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetCaretColor (int hWindow,int color);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_ShowCaret", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_ShowCaret (int hWindow,bool bShow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_DestroyCaret", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_DestroyCaret (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetCaretHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetCaretHELE (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetClientRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_GetClientRect (int hWindow,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetBodyRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_GetBodyRect (int hWindow,RECT* pRect);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_SetTimer (int hWindow,int nIDEvent,int uElapse);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_KillTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_KillTimer (int hWindow,int nIDEvent);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_SetXCTimer (int hWindow,int nIDEvent,int uElapse);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_KillXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_KillXCTimer (int hWindow,int nIDEvent);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetBkManager", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetBkManager (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetTransparentType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetTransparentType (int hWindow,int nType);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetTransparentAlpha", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetTransparentAlpha (int hWindow,byte alpha);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetTransparentColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetTransparentColor (int hWindow,int color);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetShadowInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetShadowInfo (int hWindow,int nSize,int nDepth,int nAngeleSize,bool bRightAngle,int color);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetTransparentType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern int XWnd_GetTransparentType (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetShadowInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_GetShadowInfo (int hWindow,int pnSize,int pnDepth,int pnAngeleSize,bool pbRightAngle,int pColor);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_EnableCSS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_EnableCSS (int hWindow,bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_SetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XWnd_SetCssName (int hWindow,string pName);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_GetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern string XWnd_GetCssName (int hWindow);

		[DllImport("xcgui.dll", EntryPoint = "XWnd_RegEventTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XWnd_RegEventTest (int nEvent,int pParamType);

		[DllImport("xcgui.dll", EntryPoint = "XCloudUI_EnableTipsWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XCloudUI_EnableTipsWindow (bool bEnable);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsFocus (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XEle_IsFocusEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern bool XEle_IsFocusEx (int hEle);

		[DllImport("xcgui.dll", EntryPoint = "XComboBox_SetBindName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
		unsafe public static extern void XComboBox_SetBindName (int hEle,string pName);






    }



    public class xcConst
    {
        public const int  WM_MOUSEFIRST                   =0x0200;
        public const int  WM_MOUSEMOVE                    =0x0200;
        public const int  WM_LBUTTONDOWN                  =0x0201;
        public const int  WM_LBUTTONUP                    =0x0202;
        public const int  WM_LBUTTONDBLCLK                =0x0203;
        public const int  WM_RBUTTONDOWN                  =0x0204;
        public const int  WM_RBUTTONUP                    =0x0205;
        public const int  WM_RBUTTONDBLCLK                =0x0206;
        public const int  WM_MBUTTONDOWN                  =0x0207;
        public const int  WM_MBUTTONUP                    =0x0208;
        public const int  WM_MBUTTONDBLCLK                =0x0209;


public const int XC_ERROR = -1;// '///<错误类型
public const int XC_NOTHING = 0;// '
public const int XC_WINDOW = 1;// '///<窗口
public const int XC_MODALWINDOW = 2;// '///<模态窗口
public const int XC_FRAMEWND = 3;// '///<框架窗口
public const int XC_FLOATWND = 4;// '///<浮动窗口
public const int XC_COMBOBOXWINDOW = 11;// '//comboBoxWindow_        组合框弹出下拉列表窗口
public const int XC_POPUPMENUWINDOW = 12;// '//popupMenuWindow_       弹出菜单主窗口
public const int XC_POPUPMENUCHILDWINDOW = 13;// '//popupMenuChildWindow_  弹出菜单子窗口
public const int XC_OBJECT_UI = 20;// '///<...
public const int XC_ELE = 21;// '///<基础元素
public const int XC_BUTTON = 22;// '///<按钮
public const int XC_RICHEDIT = 23;// '///<富文本编辑框
public const int XC_COMBOBOX = 24;// '///<下拉组合框元素
public const int XC_SCROLLBAR = 25;// '///<滚动条元素
public const int XC_SCROLLVIEW = 26;// '///<滚动视图元素
public const int XC_LIST = 27;// '///<列表元素
public const int XC_LISTBOX = 28;// '///<列表框元素
public const int XC_LISTVIEW = 29;// '大图标
public const int XC_TREE = 30;// '///<树元素
public const int XC_MENUBAR = 31;// '///<菜单条
public const int XC_SLIDERBAR = 32;// '///<滑动条
public const int XC_PROGRESSBAR = 33;// '///<进度条
public const int XC_TOOLBAR = 34;// '///<工具条
public const int XC_MONTHCAL = 35;// '///<月历元素
public const int XC_DATETIME = 36;// '///<时间元素
public const int XC_PROPERTYGRID = 37;// '///<属性网格
public const int XC_RICHEDIT_COLOR = 38;// '///<颜色选择元素
public const int XC_RICHEDIT_SET = 39;// '///<...
public const int XC_TABBAR = 40;// '///<tab条
public const int XC_TEXTLINK = 41;// '///<文本链接按钮
public const int XC_PANE = 42;// '///<布局窗格
public const int XC_PANE_SPLIT = 43;// '///<布局窗格拖动分割条
public const int XC_MENUBAR_BUTTON = 44;// '///<菜单条上的按钮
public const int XC_RICHEDIT_FILE = 50;// '///<RichEditFile 文件选择编辑框
public const int XC_RICHEDIT_FOLDER = 51;// '///<RichEditFolder  文件夹选择编辑框
public const int XC_LIST_HEADER = 52;// '///<列表头元素
public const int XC_SHAPE = 61;// '///<形状对象
public const int XC_SHAPE_TEXT = 62;// '///<形状对象-文本
public const int XC_SHAPE_PICTURE = 63;// '///<形状对象-图片
public const int XC_SHAPE_RECT = 64;// '///<形状对象-矩形
public const int XC_SHAPE_ELLIPSE = 65;// '///<形状对象-圆
public const int XC_SHAPE_LINE = 66;// '///<形状对象-直线
public const int XC_SHAPE_GROUPBOX = 67;// '///<形状对象-组框
public const int XC_SHAPE_GIF = 68;// '///<形状对象-GIF
public const int XC_MENU = 81;// '///<弹出菜单
public const int XC_IMAGE = 82;// '///<图片
public const int XC_IMAGE_TEXTURE = 0;// '图片素材
public const int XC_HDRAW = 83;// '///<绘图操作
public const int XC_FONT = 84;// '///<炫彩字体
public const int XC_FLASH = 85;// '///<flash
public const int XC_PANE_CELL = 86;// '///<...
public const int XC_WEB = 87;// '///<...
public const int XC_IMAGE_FRAME = 88;// '指定图片的渲染属性
public const int XC_LAYOUT_OBJECT = 101;// '///<布局对象LayoutObject
public const int XC_ADAPTER = 102;// '///<...
public const int XC_ADAPTER_TABLE = 103;// '///<数据适配器AdapterTable
public const int XC_ADAPTER_TREE = 104;// '///<数据适配器AdapterTree
public const int XC_ADAPTER_LISTVIEW = 105;// '///<数据适配器AdapterListView
public const int XC_ADAPTER_MAP = 106;// '///<数据适配器AdapterMap
public const int XC_BKINFOM = 116;// '//背景管理器
public const int XC_LAYOUT_LISTVIEW = 111;// '
public const int XC_LAYOUT_LIST = 112;// '
public const int XC_LAYOUT_OBJECT_GROUP = 113;// '
public const int XC_LAYOUT_OBJECT_ITEM = 114;// '
public const int XC_LAYOUT_PANEL = 115;// '
public const int XC_LIST_ITEM = 121;// '//列表项模板 list_item
public const int XC_LISTVIEW_GROUP = 122;// '
public const int XC_LISTVIEW_ITEM = 123;// '
public const int button_type_default = 0;// '///<默认类型
public const int button_type_radio = 1;// '///<单选按钮
public const int button_type_check = 2;// '///<复选按钮
public const int button_type_close = 3;// '///<窗口关闭按钮
public const int button_type_min = 4;// '///<窗口最小化按钮
public const int button_type_max = 5;// '///<窗口最大化还原按钮
public const int element_type_layout = 6;// '启用布局功能的元素
public const int xc_style_default = 0;// '
public const int button_style_default = 0;// '///<默认风格
public const int button_style_check = 1;// '///<复选按钮
public const int button_style_radio = 2;// '///<单选按钮
public const int button_style_expand = 3;// '///<展开收缩按钮
public const int button_style_scrollbar_left = 4;// '左按钮
public const int button_style_scrollbar_right = 5;// '右按钮
public const int button_style_scrollbar_up = 6;// '上按钮
public const int button_style_scrollbar_down = 7;// '下按钮
public const int button_style_scrollbar_slider_h = 8;// '滑块
public const int button_style_scrollbar_slider_v = 9;// '滑块
public const int button_style_tabBar_button = 10;// '///<TabBar上的标签按钮
public const int button_style_toolBar_left = 11;// '///<ToolBar左滚动按钮
public const int button_style_toolBar_right = 12;// '///<ToolBar右滚动按钮
public const int button_style_pane_close = 13;// '///<窗格关闭按钮
public const int button_style_pane_lock = 14;// '///<窗格锁定按钮
public const int button_style_pane_menu = 15;// '///<窗格下拉菜单按钮
public const int button_style_pane_dockH = 16;// '///<框架窗口左边或右边码头上按钮
public const int button_style_pane_dockV = 17;// '///<框架窗口上边或下边码头上按钮
public const int xc_style_frameWnd_dock_left = 18;// '///<框架窗口停靠码头
public const int xc_style_frameWnd_dock_top = 19;// '///<框架窗口停靠码头
public const int xc_style_frameWnd_dock_right = 20;// '///<框架窗口停靠码头
public const int xc_style_frameWnd_dock_bottom = 21;// '///<框架窗口停靠码头
public const int xc_style_ToolBar_separator = 22;// '///<工具条上的分割线
public const int xc_style_listBox_comboBox = 23;// '///<下拉组合框弹出的listBox
public const int xc_window_style_nothing = 0;// '///<什么也没有
public const int xc_window_style_caption = 1;// '默认为绑定标题栏元素
public const int xc_window_style_border = 2;// '那么边框布局大小为0
public const int xc_window_style_center = 4;// '///<窗口居中
public const int xc_window_style_drag_border = 8;// '///<拖动窗口边框
public const int xc_window_style_drag_window = 16;// '///<拖动窗口
public const int xc_window_style_allow_maxWindow = 32;// '///允许窗口最大化
public const int xc_window_style_default = 47;// '
public const int xc_window_style_default2 = 43;// '
public const int xc_window_style_modal = 7;// '
public const int window_position_error = -1;// '///<错误
public const int window_position_top = 0;// '///<top
public const int window_position_bottom = 1;// '///<bottom
public const int window_position_left = 2;// '///<left
public const int window_position_right = 3;// '///<right
public const int window_position_body = 4;// '///<body
public const int window_position_window = 5;// '///<window 整个窗口
public const int window_transparent_false = 0;// '不透明
public const int window_transparent_shaped = 1;// '异型
public const int window_transparent_shadow = 2;// '当前未启用.
public const int window_transparent_simple = 3;// '指定透明色.
public const int window_transparent_win7 = 4;// '当前未启用.
public const int menu_item_flags_normal = 0;// '///<正常
public const int menu_item_flags_select = 1;// '///<选择
public const int menu_item_flags_check = 2;// '///<勾选
public const int menu_item_flags_popup = 4;// '///<弹出
public const int menu_item_flags_separator = 8;// 'ID号被忽略
public const int menu_item_flags_disable = 16;// '///<禁用
public const int menu_popup_position_left_top = 0;// '///<左上角
public const int menu_popup_position_left_bottom = 1;// '///<左下角
public const int menu_popup_position_right_top = 2;// '///<右上角
public const int menu_popup_position_right_bottom = 3;// '///<右下角
public const int menu_popup_position_center_left = 4;// '///<左居中
public const int menu_popup_position_center_top = 5;// '///<上居中
public const int menu_popup_position_center_right = 6;// '///<右居中
public const int menu_popup_position_center_bottom = 7;// '///<下居中
public const int image_draw_type_default = 0;// '///<默认
public const int image_draw_type_stretch = 1;// '///<拉伸
public const int image_draw_type_adaptive = 2;// '九宫格
public const int image_draw_type_tile = 3;// '///<平铺
public const int image_draw_type_fixed_ratio = 4;// '按照原始比例压缩显示图片
public const int image_draw_type_adaptive_border = 5;// '///<九宫格不绘制中间区域
public const int common_state3_leave = 0;// '///<离开
public const int common_state3_stay = 1;// '///<停留
public const int common_state3_down = 2;// '///<按下
public const int button_state_leave = 0;// '///<离开状态
public const int button_state_stay = 1;// '///<停留状态
public const int button_state_down = 2;// '///<按下状态
public const int button_state_check = 3;// '///<选中状态
public const int button_state_disable = 4;// '///<禁用状态
public const int comboBox_state_leave = 0;// '///<鼠标离开状态
public const int comboBox_state_stay = 1;// '///<鼠标停留状态
public const int comboBox_state_down = 2;// '///<按下状态
public const int list_item_state_leave = 0;// '///<项鼠标离开状态
public const int list_item_state_stay = 1;// '///<项鼠标停留状态
public const int list_item_state_select = 2;// '///<项选择状态
public const int tree_item_state_leave = 0;// '///<项鼠标离开状态
public const int tree_item_state_stay = 1;// '///<项鼠标停留状态
public const int tree_item_state_select = 2;// '///<项选择状态
public const int button_icon_align_left = 0;// '///<图标在左边
public const int button_icon_align_top = 1;// '///<图标在顶部
public const int button_icon_align_right = 2;// '///<图标在右边
public const int button_icon_align_bottom = 3;// '///<图标在底部
public const int layout_size_type_fixed = 0;// '///<指定大小
public const int layout_size_type_fill = 1;// '///<fill 填充父
public const int layout_size_type_auto = 2;// '根据内容计算大小
public const int layout_size_type_weight = 3;// '按照比例分配剩余空间
public const int layout_size_type_disable = 4;// '///<disable 不使用
public const int list_drawItemBk_flags_nothing = 0;// '///<不绘制
public const int list_drawItemBk_flags_leave = 1;// '///<绘制鼠标离开状态项背景
public const int list_drawItemBk_flags_stay = 2;// '///<绘制鼠标选择状态项背景
public const int list_drawItemBk_flags_select = 4;// '///<绘制鼠标停留状态项项背景
public const int list_drawItemBk_flags_group_leave = 8;// '当项为组时
public const int list_drawItemBk_flags_group_stay = 16;// '当项为组时
public const int messageBox_flags_other = 0;// '///<其他
public const int messageBox_flags_ok = 1;// '///<确定按钮
public const int messageBox_flags_cancel = 2;// '///<取消按钮
public const int propertyGrid_item_type_text = 0;// '字符串类型
public const int propertyGrid_item_type_edit = 1;// '///<编辑框
public const int propertyGrid_item_type_edit_color = 2;// '///<颜色选择元素
public const int propertyGrid_item_type_edit_file = 3;// '///<文件选择编辑框
public const int propertyGrid_item_type_edit_set = 4;// '///<设置
public const int propertyGrid_item_type_comboBox = 5;// '///<组合框
public const int propertyGrid_item_type_group = 6;// '///<组
public const int zorder_top = 1;// '///<最上面
public const int zorder_bottom = 2;// '///<最下面
public const int zorder_before = 3;// '///<指定目标下面
public const int zorder_after = 4;// '///<指定目标上面
public const int layout_align_left = 0;// '
public const int layout_align_top = 1;// '
public const int layout_align_right = 2;// '
public const int layout_align_bottom = 3;// '
public const int layout_align_center = 4;// '
public const int layout_align_equidistant = 5;// '
public const int align_error = -1;// '
public const int align_left = 0;// '
public const int align_top = 1;// '
public const int align_right = 2;// '
public const int align_bottom = 3;// '
public const int align_center = 4;// '
public const int dock_align_none = 0;// '
public const int dock_align_left = 1;// '
public const int dock_align_top = 2;// '
public const int dock_align_right = 3;// '
public const int dock_align_bottom = 4;// '
public const int pane_state_any = 0;// '
public const int pane_state_lock = 1;// '///<锁定
public const int pane_state_dock = 2;// '///<停靠码头
public const int pane_state_float = 3;// '///<浮动窗格
public const int textAlignFlag_left = 0;// '///<左对齐
public const int textAlignFlag_top = 0;// '///<垂直定对齐
public const int textAlignFlag_left_top = 16384;// '//内部保留
public const int textAlignFlag_center = 1;// '///<水平居中
public const int textAlignFlag_right = 2;// '///<右对齐
public const int textAlignFlag_vcenter = 4;// '///<垂直居中
public const int textAlignFlag_bottom = 8;// '///<垂直底对齐
public const int textFormatFlag_DirectionRightToLeft = 16;// '///<从右向左顺序显示文本
public const int textFormatFlag_NoWrap = 32;// '///<禁止换行
public const int textFormatFlag_DirectionVertical = 64;// '///<垂直显示文本
public const int textFormatFlag_NoFitBlackBox = 128;// '///<允许部分字符延伸该字符串的布局矩形。默认情况下，将重新定位字符以避免任何延伸
public const int textFormatFlag_DisplayFormatControl = 256;// '///<控制字符（如从左到右标记）随具有代表性的标志符号一起显示在输出中。
public const int textFormatFlag_NoFontFallback = 512;// '///<对于请求的字体中不支持的字符，禁用回退到可选字体。缺失的任何字符都用缺失标志符号的字体显示，通常是一个空的方块
public const int textFormatFlag_MeasureTrailingSpaces = 1024;// '///<包括每一行结尾处的尾随空格。在默认情况下，MeasureString 方法返回的边框都将排除每一行结尾处的空格。设置此标记以便在测定时将空格包括进去
public const int textFormatFlag_LineLimit = 2048;// '那么不显示
public const int textFormatFlag_NoClip = 4096;// '///<允许显示标志符号的伸出部分和延伸到边框外的未换行文本。在默认情况下，延伸到边框外侧的所有文本和标志符号部分都被剪裁
public const int textTrimming_None = 0;// '///<不使用去尾
public const int textTrimming_Character = 262144;// '///<以字符为单位去尾
public const int textTrimming_Word = 524288;// '///<以单词为单位去尾
public const int textTrimming_EllipsisCharacter = 32768;// '省略部分使用且略号表示
public const int textTrimming_EllipsisWord = 65536;// '
public const int textTrimming_EllipsisPath = 131072;// '///<略去字符串中间部分，保证字符的首尾都能够显示
public const int listItemTemp_type_tree = 1;// '///<tree
public const int listItemTemp_type_listBox = 2;// '///<listBox
public const int listItemTemp_type_list_head = 4;// '///<list 列表头
public const int listItemTemp_type_list_item = 8;// '///<list 列表项
public const int listItemTemp_type_listView_group = 16;// '///<listView 列表视组
public const int listItemTemp_type_listView_item = 32;// '///<listView 列表视项
public const int listItemTemp_type_list = 12;// '///<list (列表头)与(列表项)组合
public const int listItemTemp_type_listView = 48;// '///<listView (列表视组)与(列表视项)组合
public const int window_state_flag_nothing = 0;// '///<无
public const int window_state_flag_leave = 1;// '///<整个窗口
public const int window_state_flag_body_leave = 2;// '///<窗口-body
public const int window_state_flag_top_leave = 4;// '///<窗口-top
public const int window_state_flag_bottom_leave = 8;// '///<窗口-bottom
public const int window_state_flag_left_leave = 16;// '///<窗口-left
public const int window_state_flag_right_leave = 32;// '///<窗口-right
public const int element_state_flag_nothing = 0;// '///<无
public const int element_state_flag_enable = 1;// '///<启用
public const int element_state_flag_disable = 2;// '///<禁用
public const int element_state_flag_focus = 4;// '///<焦点
public const int element_state_flag_focus_no = 8;// '///<无焦点
public const int element_state_flag_focusEx = 1073741824;// '///<该元素或该元素的子元素拥有焦点
public const int element_state_flag_focusEx_no = 2147483648;// '///<无焦点Ex
public const int element_state_flag_leave = 16;// '///<鼠标离开
public const int element_state_flag_stay = 32;// '///<为扩展模块保留
public const int element_state_flag_down = 64;// '///<为扩展模块保留
public const int button_state_flag_leave = 16;// '///<鼠标离开
public const int button_state_flag_stay = 32;// '///<鼠标停留
public const int button_state_flag_down = 64;// '///<鼠标按下
public const int button_state_flag_check = 128;// '///<选中
public const int button_state_flag_check_no = 256;// '///<未选中
public const int button_state_flag_WindowRestore = 512;// '///<窗口还原
public const int button_state_flag_WindowMaximize = 1024;// '///<窗口最大化
public const int comboBox_state_flag_leave = 16;// '///<鼠标离开
public const int comboBox_state_flag_stay = 32;// '///<鼠标停留
public const int comboBox_state_flag_down = 64;// '///<鼠标按下
public const int listBox_state_flag_item_leave = 128;// '///<项鼠标离开
public const int listBox_state_flag_item_stay = 256;// '///<项鼠标停留
public const int listBox_state_flag_item_select = 512;// '///<项选择
public const int listBox_state_flag_item_select_no = 1024;// '///<项未选择
public const int list_state_flag_item_leave = 128;// '///<项鼠标离开
public const int list_state_flag_item_stay = 256;// '///<项鼠标停留
public const int list_state_flag_item_select = 512;// '///<项选择
public const int list_state_flag_item_select_no = 1024;// '///<项未选择
public const int listHeader_state_flag_item_leave = 128;// '///<项鼠标离开
public const int listHeader_state_flag_item_stay = 256;// '///<项鼠标停留
public const int listHeader_state_flag_item_down = 512;// '///<项鼠标按下
public const int listView_state_flag_item_leave = 128;// '///<项鼠标离开
public const int listView_state_flag_item_stay = 256;// '///<项鼠标停留
public const int listView_state_flag_item_select = 512;// '///<项选择
public const int listView_state_flag_item_select_no = 1024;// '///<项未选择
public const int listView_state_flag_group_leave = 2048;// '///<组鼠标离开
public const int listView_state_flag_group_stay = 4096;// '///<组鼠标停留
public const int listView_state_flag_group_select = 8192;// '///<组选择
public const int listView_state_flag_group_select_no = 16384;// '///<组未选择
public const int tree_state_flag_item_leave = 128;// '///<项鼠标离开
public const int tree_state_flag_item_stay = 256;// '暂未使用
public const int tree_state_flag_item_select = 512;// '///<项选择
public const int tree_state_flag_item_select_no = 1024;// '///<项未选择
public const int tree_state_flag_group = 2048;// '///<项为组
public const int tree_state_flag_group_no = 4096;// '///<项不为组
public const int monthCal_state_flag_leave = 16;// '///<离开状态
public const int monthCal_state_flag_item_leave = 128;// '///< 项-离开
public const int monthCal_state_flag_item_stay = 256;// '///< 项-停留
public const int monthCal_state_flag_item_down = 512;// '///< 项-按下
public const int monthCal_state_flag_item_select = 1024;// '///< 项-选择
public const int monthCal_state_flag_item_select_no = 2048;// '///< 项-未选择
public const int monthCal_state_flag_item_today = 4096;// '///< 项-今天
public const int monthCal_state_flag_item_other = 8192;// '///< 项-上月及下月
public const int monthCal_state_flag_item_last_month = 16384;// '///< 项-上月
public const int monthCal_state_flag_item_cur_month = 32768;// '///< 项-当月
public const int monthCal_state_flag_item_next_month = 65536;// '///< 项-下月
public const int propertyGrid_state_flag_item_leave = 128;// '
public const int propertyGrid_state_flag_item_stay = 256;// '
public const int propertyGrid_state_flag_item_select = 512;// '
public const int propertyGrid_state_flag_item_select_no = 1024;// '
public const int propertyGrid_state_flag_group_leave = 2048;// '
public const int propertyGrid_state_flag_group_expand = 4096;// '
public const int propertyGrid_state_flag_group_expand_no = 8192;// '
public const int pane_state_flag_leave = 16;// '
public const int pane_state_flag_stay = 32;// '
public const int pane_state_flag_caption = 128;// '
public const int pane_state_flag_body = 256;// '
public const int layout_state_flag_nothing = 0;// '///<无
public const int layout_state_flag_full = 1;// '//完整背景
public const int layout_state_flag_body = 2;// '不包含边大小
public const int monthCal_button_type_today = 0;// '///< 今天按钮
public const int monthCal_button_type_last_year = 1;// '///< 上一年
public const int monthCal_button_type_next_year = 2;// '///< 下一年
public const int monthCal_button_type_last_month = 3;// '///< 上一月
public const int monthCal_button_type_next_month = 4;// '///< 下一月
public const int xc_fontStyle_regular = 0;// '///<正常
public const int xc_fontStyle_bold = 1;// '///<粗体
public const int xc_fontStyle_italic = 2;// '///<斜体
public const int xc_fontStyle_boldItalic = 3;// '///<粗斜体
public const int xc_fontStyle_underline = 4;// '///<下划线
public const int xc_fontStyle_strikeout = 8;// '//<删除线
public const int adapter_date_type_error = -1;// '
public const int adapter_date_type_int = 0;// '///<整形
public const int adapter_date_type_float = 1;// '///<浮点型
public const int adapter_date_type_string = 2;// '///<字符串
public const int adapter_date_type_image = 3;// '///<图片
public const int event_c_ex = 1;// '
public const int event_lua_ex = 2;// '
public const int event_js_ex = 3;// '
public const int XWM_REDRAW_ELE = 28673;// '
public const int XWM_WINDPROC = 28674;// '
public const int XWM_DRAW_T = 28675;// '
public const int XWM_TIMER_T = 28676;// '
public const int XWM_CLOUDUI_DOWNLOADFILE_COMPLETE = 28678;// '
public const int XWM_CLOUNDUI_OPENURL_WAIT = 28679;// '
public const int XWM_XC_TIMER = 28677;// '
public const int XWM_MENU_POPUP = 28683;// '
public const int XWM_MENU_POPUP_WND = 28684;// '
public const int XWM_MENU_SELECT = 28685;// '
public const int XWM_MENU_EXIT = 28686;// '
public const int XWM_MENU_DRAW_BACKGROUND = 28687;// '
public const int XWM_MENU_DRAWITEM = 28688;// '
public const int XWM_COMBOBOX_POPUP_DROPLIST = 28689;// '
public const int XWM_FLOAT_PANE = 28690;// '
public const int XWM_PAINT_END = 28691;// '
public const int XWM_PAINT_DISPLAY = 28692;// '
public const int XC_WINDOW_BODY = 10;// '
public const int IDM_CLIP = 1000000000;// '
public const int IDM_COPY = 1000000001;// '
public const int IDM_PASTE = 1000000002;// '
public const int IDM_DELETE = 1000000003;// '
public const int IDM_SELECTALL = 1000000004;// '
public const int IDM_DELETEALL = 1000000005;// '
public const int IDM_LOCK = 1000000006;// '
public const int IDM_DOCK = 1000000007;// '
public const int IDM_FLOAT = 1000000008;// '
public const int IDM_HIDE = 1000000009;// '
public const int XE_LBUTTONDOWN = 10;// '
public const int XE_LBUTTONUP = 11;// '
public const int XE_RBUTTONDOWN = 12;// '
public const int XE_RBUTTONUP = 13;// '
public const int XE_LBUTTONDBCLICK = 14;// '
public const int XE_RBUTTONDBCLICK = 15;// '
public const int XE_XC_TIMER = 16;// '
public const int XE_ADJUSTLAYOUT = 17;// '
public const int XE_ADJUSTLAYOUT_END = 18;// '
public const int XE_SETFOCUS = 31;// '
public const int XE_KILLFOCUS = 32;// '
public const int XE_DESTROY = 33;// '
public const int XE_BNCLICK = 34;// '
public const int XE_BUTTON_CHECK = 35;// '
public const int XE_SIZE = 36;// '
public const int XE_SHOW = 37;// '
public const int XE_SETFONT = 38;// '
public const int XE_KEYDOWN = 39;// '
public const int XE_KEYUP = 40;// '
public const int XE_CHAR = 41;// '
public const int XE_SETCAPTURE = 51;// '
public const int XE_KILLCAPTURE = 52;// '
public const int XE_SETCURSOR = 53;// '
public const int XE_SCROLLVIEW_SCROLL_H = 54;// '
public const int XE_SCROLLVIEW_SCROLL_V = 55;// '
public const int XE_SBAR_SCROLL = 56;// '
public const int XE_MENU_POPUP = 57;// '
public const int XE_MENU_POPUP_WND = 58;// '
public const int XE_MENU_SELECT = 59;// '
public const int XE_MENU_DRAW_BACKGROUND = 60;// '
public const int XE_MENU_DRAWITEM = 61;// '
public const int XE_MENU_EXIT = 62;// '
public const int XE_SLIDERBAR_CHANGE = 63;// '
public const int XE_PROGRESSBAR_CHANGE = 64;// '
public const int XE_COMBOBOX_SELECT = 71;// '
public const int XE_COMBOBOX_SELECT_END = 74;// '
public const int XE_COMBOBOX_POPUP_LIST = 72;// '
public const int XE_COMBOBOX_EXIT_LIST = 73;// '
public const int XE_LISTBOX_TEMP_CREATE = 81;// '
public const int XE_LISTBOX_TEMP_CREATE_END = 82;// '
public const int XE_LISTBOX_TEMP_DESTROY = 83;// '
public const int XE_LISTBOX_TEMP_ADJUST_COORDINATE = 84;// '
public const int XE_LISTBOX_DRAWITEM = 85;// '
public const int XE_LISTBOX_SELECT = 86;// '
public const int XE_LIST_TEMP_CREATE = 101;// '
public const int XE_LIST_TEMP_CREATE_END = 102;// '
public const int XE_LIST_TEMP_DESTROY = 103;// '
public const int XE_LIST_TEMP_ADJUST_COORDINATE = 104;// '
public const int XE_LIST_DRAWITEM = 105;// '
public const int XE_LIST_SELECT = 106;// '
public const int XE_LIST_HEADER_DRAWITEM = 107;// '
public const int XE_LIST_HEADER_CLICK = 108;// '
public const int XE_LIST_HEADER_WIDTH_CHANGE = 109;// '
public const int XE_LIST_HEADER_TEMP_CREATE = 110;// '
public const int XE_LIST_HEADER_TEMP_CREATE_END = 111;// '
public const int XE_LIST_HEADER_TEMP_DESTROY = 112;// '
public const int XE_LIST_HEADER_TEMP_ADJUST_COORDINATE = 113;// '
public const int XE_TREE_TEMP_CREATE = 121;// '
public const int XE_TREE_TEMP_CREATE_END = 122;// '
public const int XE_TREE_TEMP_DESTROY = 123;// '
public const int XE_TREE_TEMP_ADJUST_COORDINATE = 124;// '
public const int XE_TREE_DRAWITEM = 125;// '
public const int XE_TREE_SELECT = 126;// '
public const int XE_TREE_EXPAND = 127;// '
public const int XE_TREE_DRAG_ITEM_ING = 128;// '
public const int XE_TREE_DRAG_ITEM = 129;// '
public const int XE_LISTVIEW_TEMP_CREATE = 141;// '
public const int XE_LISTVIEW_TEMP_CREATE_END = 142;// '
public const int XE_LISTVIEW_TEMP_DESTROY = 143;// '
public const int XE_LISTVIEW_TEMP_ADJUST_COORDINATE = 144;// '
public const int XE_LISTVIEW_DRAWITEM = 145;// '
public const int XE_LISTVIEW_SELECT = 146;// '
public const int XE_LISTVIEW_EXPAND = 147;// '
public const int XE_PGRID_VALUE_CHANGE = 151;// '
public const int XE_PGRID_ITEM_SET = 152;// '
public const int XE_PGRID_ITEM_SELECT = 153;// '
public const int XE_PGRID_ITEM_ADJUST_COORDINATE = 154;// '
public const int XE_PGRID_ITEM_DESTROY = 155;// '
public const int XE_PGRID_ITEM_EXPAND = 156;// '
public const int XE_RICHEDIT_CHANGE = 161;// '
public const int XE_RICHEDIT_SET = 162;// '
public const int XE_TABBAR_SELECT = 221;// '
public const int XE_TABBAR_DELETE = 222;// '
public const int XE_MONTHCAL_CHANGE = 231;// '
public const int XE_DATETIME_CHANGE = 241;// '
public const int XE_DATETIME_POPUP_MONTHCAL = 242;// '
public const int XE_DATETIME_EXIT_MONTHCAL = 243;// '
public const int XE_DROPFILES = 250;// '
public const int XC_WINDOW_TOP = 1;// '
public const int XC_WINDOW_BOTTOM = 2;// '
public const int XC_WINDOW_LEFT = 3;// '
public const int XC_WINDOW_RIGHT = 4;// '
public const int XC_WINDOW_TOPLEFT = 5;// '
public const int XC_WINDOW_TOPRIGHT = 6;// '
public const int XC_WINDOW_BOTTOMLEFT = 7;// '
public const int XC_WINDOW_BOTTOMRIGHT = 8;// '
public const int XC_WINDOW_CAPTION = 9;// '
public const int XC_ID_ROOT = 0;// '
public const int XE_ELEPROCE = 1;// '
public const int XE_PAINT_END = 3;// '
public const int XE_MOUSESTAY = 6;// '
public const int XE_MOUSEHOVER = 7;// '
public const int XE_MOUSELEAVE = 8;// '
public const int XE_MOUSEWHEEL = 9;// '
public const int CLOUDUI_flag_openUrl = 1;// '
public const int CLOUDUI_flag_downloadFile = 2;// '
public const int CLOUDUI_flag_downloadFileComplete = 3;// '
public const int CLOUDUI_flag_complete = 4;// '
public const int XE_PAINT = 2;// '
public const int XE_PAINT_SCROLLVIEW = 4;// '
public const int XE_MOUSEMOVE = 5;// '
public const int XC_ID_ERROR = -1;// '
public const int XC_ID_FIRST = -2;// '
public const int XC_ID_LAST = -3;// '



    }

}
