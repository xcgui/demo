using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;


/*
 * name    xcgui界面库模块
 * Made    dasemimi
 * time    2017.2.24
 * ver     2.1.2
*/
namespace XCGUI
{
    using System.Text;


    unsafe public delegate int WM_LBUTTONDOWN_CPP(UInt32 nFlags, IntPtr pPt, bool* pbHandled);

    unsafe public delegate int XE_BNCLICK_CPP(bool* pbHandled);
    unsafe public delegate int XE_BNCLICK_CPP1(int hEventEle, bool* pbHandled);
    unsafe public delegate int XE_BNCLICK_CPP2(int hEle, int hEventEle, bool* pbHandled);


    unsafe public delegate int XE_LISTBOX_TEMP_CREATE_END_CPP(ref listBox_item_i listBox_item_i, bool* pbHandled);

    unsafe public delegate int XE_MENU_SELECT_CPP(int nID, bool* pbHandled);


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
        unsafe public RECT* rcItem;
        public int hLayout;
        public int pTempInfo;
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
        unsafe public RECT* rcItem;
        public int hLayout;
        public int pTempInfo;
    }
    public struct list_header_item_i
    {
        public int index;
        public int nUserData;
        public bool bSort;
        public int nSortType;
        public int iColumnAdapter;
        public int nState;
        unsafe public RECT* rcItem;
        public int hLayout;
        public int pTempInfo;
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
        unsafe public RECT* rcItem;
        public int hLayout;
        public int pTempInfo;
    }
    public struct listView_item_i
    {
        public int iGroup;
        public int iItem;
        public int nUserData;
        public int nState;
        unsafe public RECT* rcItem;
        public int hLayout;
        public int pTempInfo;
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
        unsafe public RECT rcItem;
        public int hIcon;
        [MarshalAs(UnmanagedType.LPWStr, SizeConst = 128)]
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
        unsafe public fixed short aName[32];
    }
    public struct propertyGrid_item_i
    {
        public int nType;
        public int nID;
        public int nDepth;
        public int nUserData;
        public int nNameColWidth;
        unsafe public RECT* rcItem;
        unsafe public RECT* rcExpand;
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
        unsafe public RECT* rcItem;
    }



    partial class XTemp
    {

        [DllImport("xcgui.dll", EntryPoint = "XTemp_Load", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XTemp_Load(int nType, string pFileName);

        [DllImport("xcgui.dll", EntryPoint = "XTemp_LoadFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XTemp_LoadFromString(int nType, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XTemp_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XTemp_Destroy(int hTemp);

        [DllImport("xcgui.dll", EntryPoint = "XTemp_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XTemp_Create(int nType);

        [DllImport("xcgui.dll", EntryPoint = "XTemp_AddNodeRoot", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XTemp_AddNodeRoot(int hTemp, int pNode);

        [DllImport("xcgui.dll", EntryPoint = "XTemp_AddNode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XTemp_AddNode(int pParentNode, int pNode);

        [DllImport("xcgui.dll", EntryPoint = "XTemp_CreateNode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XTemp_CreateNode(int nType);

        [DllImport("xcgui.dll", EntryPoint = "XTemp_SetNodeAttribute", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XTemp_SetNodeAttribute(int pNode, string pName, string pAttr);

    }

    partial class XDateTime
    {
        [DllImport("xcgui.dll", EntryPoint = "XDateTime_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_SetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        public static extern void SetStyle(int hEle, int nStyle);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_GetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        public static extern int GetStyle(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_GetTime", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetTime(int hEle, int pnHour, int pnMinute, int pnSecond);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_SetTime", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTime(int hEle, int nHour, int nMinute, int nSecond);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_GetDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetDate(int hEle, int pnYear, int pnMonth, int pnDay);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_SetDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDate(int hEle, int nYear, int nMonth, int nDay);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_GetSelBkColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelBkColor(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_SetSelBkColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSelBkColor(int hEle, int crSelectBk, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XDateTime_GetButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButton(int hEle, int nType);
    }

    partial class XMonthCal
    {
        [DllImport("xcgui.dll", EntryPoint = "XMonthCal_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XMonthCal_SetToday", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetToday(int hEle, int nYear, int nMonth, int nDay);

        [DllImport("xcgui.dll", EntryPoint = "XMonthCal_GetToday", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetToday(int hEle, int pnYear, int pnMonth, int pnDay);

        [DllImport("xcgui.dll", EntryPoint = "XMonthCal_SeSelDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SeSelDate(int hEle, int nYear, int nMonth, int nDay);

        [DllImport("xcgui.dll", EntryPoint = "XMonthCal_GetSelDate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetSelDate(int hEle, int pnYear, int pnMonth, int pnDay);

        [DllImport("xcgui.dll", EntryPoint = "XMonthCal_GetButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButton(int hEle, int nType);

    }

    //为了输入方便，直接搞成小写的
    partial class xc
    {
        [DllImport("user32.dll")]
        public static extern int MessageBoxA(int hWnd, string pText, string pTitle, int nType);
 
        [DllImport("xcgui.dll", EntryPoint = "_XC_SetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void _XC_SetType(int hXCGUI, int nType);

        [DllImport("xcgui.dll", EntryPoint = "_XC_AddType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void _XC_AddType(int hXCGUI, int nType);

        [DllImport("xcgui.dll", EntryPoint = "_XC_BindData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void _XC_BindData(int hXCGUI, int data);

        [DllImport("xcgui.dll", EntryPoint = "_XC_GetBindData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int _XC_GetBindData(int hXCGUI);


        [DllImport("xcgui.dll", EntryPoint = "_XC_DebugPrintf", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void _XC_DebugPrintf(int level, string pFormat, int 点点点);

        [DllImport("xcgui.dll", EntryPoint = "_XC_DebugPrintfW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void _XC_DebugPrintfW(int level, string pFormat, int 点点点);


        [DllImport("xcgui.dll", EntryPoint = "xtrace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void xtrace(string pFormat, int 点点点);

        [DllImport("xcgui.dll", EntryPoint = "xtracew", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void xtracew(string pFormat, int 点点点);


        [DllImport("xcgui.dll", EntryPoint = "XC_InitLua", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InitLua();

        [DllImport("xcgui.dll", EntryPoint = "XC_RunLua", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RunLua(string pLuaFile);

        [DllImport("xcgui.dll", EntryPoint = "XC_ExitLua", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ExitLua();

        [DllImport("xcgui.dll", EntryPoint = "XC_UnicodeToAnsi", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int UnicodeToAnsi(string pIn, int inLen, string pOut, int outLen);

        [DllImport("xcgui.dll", EntryPoint = "XC_AnsiToUnicode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AnsiToUnicode(string pIn, int inLen, string pOut, int outLen);

        [DllImport("xcgui.dll", EntryPoint = "XC_DebugToFileInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DebugToFileInfo(string pInfo);

        [DllImport("xcgui.dll", EntryPoint = "XC_IsHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsHELE(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XC_IsHWINDOW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsHWINDOW(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XC_IsShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsShape(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XC_IsHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsHXCGUI(int hXCGUI, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XC_hWindowFromHWnd", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int hWindowFromHWnd(int hWnd);

        [DllImport("xcgui.dll", EntryPoint = "XC_SetProperty", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetProperty(int hXCGUI, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetProperty", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern string GetProperty(int hXCGUI, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_RegisterWindowClassName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegisterWindowClassName(string pClassName);

        [DllImport("xcgui.dll", EntryPoint = "XC_IsSViewExtend", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsSViewExtend(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetObjectType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetObjectType(int hXCGUI);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetObjectByID(int hWindow, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByIDName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetObjectByIDName(int hWindow, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetObjectByUID(int nUID);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetObjectByUIDName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetObjectByUIDName(string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetResIDValue", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetResIDValue(string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetResImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetResImage(string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetResImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetResImageEx(string pFileName, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetResColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetResColor(string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetResFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetResFont(string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetResBkInfoM", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetResBkInfoM(string pName);

        [DllImport("xcgui.dll", EntryPoint = "XC_SetPaintFrequency", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetPaintFrequency(int nMilliseconds);

        [DllImport("xcgui.dll", EntryPoint = "XC_SetTextRenderingHint", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextRenderingHint(int nType);

        [DllImport("xcgui.dll", EntryPoint = "XC_RectInRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RectInRect(RECT* pRect1, RECT* pRect2);

        [DllImport("xcgui.dll", EntryPoint = "XC_CombineRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void CombineRect(RECT* pDest, RECT* pSrc1, RECT* pSrc2);

        [DllImport("xcgui.dll", EntryPoint = "XC_ShowLayoutFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowLayoutFrame(bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XC_EnableDebugFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDebugFile(bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XC_SetLayoutFrameColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutFrameColor(int color);

        [DllImport("xcgui.dll", EntryPoint = "XC_EnableErrorMessageBox", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableErrorMessageBox(bool bEnabel);

        [DllImport("xcgui.dll", EntryPoint = "XC_LoadLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadLayout(string pFileName, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XC_LoadLayoutFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadLayoutFromString(string pStringXML, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XC_LoadResource", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool LoadResource(string pFileName, string pDir);

        [DllImport("xcgui.dll", EntryPoint = "XC_LoadResourceFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool LoadResourceFromString(string pStringXML, string pDir);

        [DllImport("xcgui.dll", EntryPoint = "XC_LoadTemplate", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadTemplate(int nType, string pFileName);

        [DllImport("xcgui.dll", EntryPoint = "XC_LoadTemplateFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadTemplateFromString(int nType, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XC_TemplateDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void TemplateDestroy(int pInfo);

        [DllImport("xcgui.dll", EntryPoint = "XC_LoadStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool LoadStyle(string pFileName, string pDir);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetTextSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetTextSize(string pString, int length, int hFontX, SIZE* pOutSize);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetTextShowSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetTextShowSize(string pString, int length, int hFontX, SIZE* pOutSize);

        [DllImport("xcgui.dll", EntryPoint = "XC_GetDefaultFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetDefaultFont();

        [DllImport("xcgui.dll", EntryPoint = "XC_SetDefaultFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDefaultFont(int hFontX);

        [DllImport("xcgui.dll", EntryPoint = "XC_InitFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void InitFont(LOGFONTW* pFont, string pName, int size, bool bBold, bool bItalic, bool bUnderline, bool bStrikeOut);

        [DllImport("xcgui.dll", EntryPoint = "XC_Malloc", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Malloc(int size);

        [DllImport("xcgui.dll", EntryPoint = "XC_Free", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Free(int p);

        [DllImport("xcgui.dll", EntryPoint = "XInitXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XInitXCGUI(string pText);

        [DllImport("xcgui.dll", EntryPoint = "XRunXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XRunXCGUI();

        [DllImport("xcgui.dll", EntryPoint = "XExitXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XExitXCGUI();
    }

    partial class XObj
    {
        [DllImport("xcgui.dll", EntryPoint = "XObj_GetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XObj_GetType(int hXCGUI);

        [DllImport("xcgui.dll", EntryPoint = "XObj_GetTypeEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XObj_GetTypeEx(int hXCGUI);
    }
    partial class XUI
    {
        [DllImport("xcgui.dll", EntryPoint = "XUI_SetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XUI_SetStyle(int hXCGUI, int nStyle);

        [DllImport("xcgui.dll", EntryPoint = "XUI_GetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XUI_GetStyle(int hXCGUI);
    }
    partial class XBkInfoM
    {
        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create();

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hBkInfoM);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_SetBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SetBkInfo(int hBkInfoM, string pText);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_AddInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddInfo(int hBkInfoM, string pText);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_AddBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBorder(int hBkInfoM, int nState, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_AddFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddFill(int hBkInfoM, int nState, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_AddImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddImage(int hBkInfoM, int nState, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCount(int hBkInfoM);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_Clear", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Clear(int hBkInfoM);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_Draw", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Draw(int hBkInfoM, int nState, int hDraw, RECT pRect);

        [DllImport("xcgui.dll", EntryPoint = "XBkInfoM_DrawEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DrawEx(int hBkInfoM, int nState, int hDraw, RECT pRect, int nStateFilter);

    }
    partial class XBtn
    {
        [DllImport("xcgui.dll", EntryPoint = "XBtn_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, string pName, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_IsCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsCheck(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetCheck(int hEle, bool bCheck);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetState(int hEle, int nState);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetState(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetStateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetStateEx(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetStyle(int hEle, int nStyle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetStyle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetStyle(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetType(int hEle, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetTypeEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTypeEx(int hEle, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetType(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetGroupID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetGroupID(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetGroupID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetGroupID(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetBindEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBindEle(int hEle, int hBindEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetBindEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetBindEle(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextAlign(int hEle, int nFlags);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTextAlign(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetIconAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetIconAlign(int hEle, int align);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetOffset(int hEle, int x, int y);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetOffsetIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetOffsetIcon(int hEle, int x, int y);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetIconSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetIconSpace(int hEle, int size);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetText(int hEle, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetText(int hEle, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetIcon(int hEle, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_SetIconDisable", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetIconDisable(int hEle, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetIcon(int hEle, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_AddAnimationFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddAnimationFrame(int hEle, int hImage, int uElapse);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_EnableAnimation", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAnimation(int hEle, bool bEnable, bool bLoopPlay);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_AddBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkBorder(int hEle, int nState, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_AddBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkFill(int hEle, int nState, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_AddBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkImage(int hEle, int nState, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_GetBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetBkInfoCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XBtn_ClearBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearBkInfo(int hEle);
    }
    partial class XComboBox
    {
        [DllImport("xcgui.dll", EntryPoint = "XComboBox_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_SetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetSelItem(int hEle, int iIndex);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_GetButtonRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetButtonRect(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_SetButtonSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetButtonSize(int hEle, int size);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_SetDropHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDropHeight(int hEle, int height);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_GetDropHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetDropHeight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_BindApapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindApapter(int hEle, int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_GetApapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetApapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemTemplateXML(int hEle, string pXmlFile);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemTemplateXMLFromString(int hEle, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_EnableDrawButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDrawButton(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_EnableEdit", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableEdit(int hEle, bool bEdit);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_EnableDropHeightFixed", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDropHeightFixed(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_AddBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkBorder(int hEle, int nState, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_AddBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkFill(int hEle, int nState, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_AddBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkImage(int hEle, int nState, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XComboboX_GetBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetBkInfoCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_ClearBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearBkInfo(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_GetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelItem(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XComboBox_GetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetState(int hEle);
    }

    partial class XAdapter
    {
        [DllImport("xcgui.dll", EntryPoint = "XAdapter_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hAdapter);
    }
    partial class XAdapterListView
    {


        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create();

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Group_AddColumn(int hAdapter, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Group_AddItemText(int hAdapter, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_AddItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Group_AddItemTextEx(int hAdapter, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Group_AddItemImage(int hAdapter, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_AddItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Group_AddItemImageEx(int hAdapter, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Group_SetText(int hAdapter, int iGroup, int iColumn, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_SetTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Group_SetTextEx(int hAdapter, int iGroup, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Group_SetImage(int hAdapter, int iGroup, int iColumn, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_SetImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Group_SetImageEx(int hAdapter, int iGroup, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Group_GetCount(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Item_GetCount(int hAdapter, int iGroup);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Item_AddColumn(int hAdapter, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Item_AddItemText(int hAdapter, int iGroup, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_AddItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Item_AddItemTextEx(int hAdapter, int iGroup, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Item_AddItemImage(int hAdapter, int iGroup, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_AddItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Item_AddItemImageEx(int hAdapter, int iGroup, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Item_SetText(int hAdapter, int iGroup, int iItem, int iColumn, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_SetTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Item_SetTextEx(int hAdapter, int iGroup, int iItem, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Item_SetImage(int hAdapter, int iGroup, int iItem, int iColumn, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_SetImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Item_SetImageEx(int hAdapter, int iGroup, int iItem, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Group_DeleteItem(int hAdapter, int iGroup);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Group_DeleteAllChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Group_DeleteAllChildItem(int hAdapter, int iGroup);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Item_DeleteItem(int hAdapter, int iGroup, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_DeleteAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteAll(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_DeleteAllGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteAllGroup(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_DeleteAllItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteAllItem(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_DeleteColumnGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteColumnGroup(int hAdapter, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_DeleteColumnItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteColumnItem(int hAdapter, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_GetTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Item_GetTextEx(int hAdapter, int iGroup, int iItem, string pName, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterListView_Item_GetImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Item_GetImageEx(int hAdapter, int iGroup, int iItem, string pName);

    }
    partial class XAdapterTable
    {
        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create();

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_Sort", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Sort(int hAdapter, int iColumn, bool bAscending);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemDataType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemDataType(int hAdapter, int iItem, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemDataTypeEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemDataTypeEx(int hAdapter, int iItem, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddColumn(int hAdapter, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SetColumn(int hAdapter, string pColName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddItemText(int hAdapter, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_AddItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddItemTextEx(int hAdapter, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddItemImage(int hAdapter, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_AddItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddItemImageEx(int hAdapter, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_InsertItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemText(int hAdapter, int iItem, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_InsertItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemTextEx(int hAdapter, int iItem, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_InsertItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemImage(int hAdapter, int iItem, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_InsertItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemImageEx(int hAdapter, int iItem, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemText(int hAdapter, int iItem, int iColumn, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTextEx(int hAdapter, int iItem, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemInt(int hAdapter, int iItem, int iColumn, int nValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemIntEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemIntEx(int hAdapter, int iItem, string pName, int nValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemFloat", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemFloat(int hAdapter, int iItem, int iColumn, float nValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemFloatEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemFloatEx(int hAdapter, int iItem, string pName, float nValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemImage(int hAdapter, int iItem, int iColumn, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_SetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemImageEx(int hAdapter, int iItem, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteItem(int hAdapter, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_DeleteItemEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteItemEx(int hAdapter, int iItem, int nCount);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_DeleteItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteItemAll(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_DeleteColumnAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteColumnAll(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCount(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetCountColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCountColumn(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemText(int hAdapter, int iItem, int iColumn, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemTextEx(int hAdapter, int iItem, string pName, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemImage(int hAdapter, int iItem, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemImageEx(int hAdapter, int iItem, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemInt(int hAdapter, int iItem, int iColumn, int pOutValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemIntEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemIntEx(int hAdapter, int iItem, string pName, int pOutValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemFloat", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemFloat(int hAdapter, int iItem, int iColumn, float pOutValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTable_GetItemFloatEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemFloatEx(int hAdapter, int iItem, string pName, float pOutValue);

    }
    partial class XAdapterTree
    {
        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create();

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddColumn(int hAdapter, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_SetColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SetColumn(int hAdapter, string pColName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_InsertItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemText(int hAdapter, string pValue, int nParentID, int insertID);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_InsertItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemTextEx(int hAdapter, string pName, string pValue, int nParentID, int insertID);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_InsertItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemImage(int hAdapter, int hImage, int nParentID, int insertID);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_InsertItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertItemImageEx(int hAdapter, string pName, int hImage, int nParentID, int insertID);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCount(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_GetCountColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCountColumn(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemText(int hAdapter, int nID, int iColumn, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_SetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTextEx(int hAdapter, int nID, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_SetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemImage(int hAdapter, int nID, int iColumn, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_SetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemImageEx(int hAdapter, int nID, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemText(int hAdapter, int nID, int iColumn, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_GetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemImage(int hAdapter, int nID, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_GetItemTextEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemTextEx(int hAdapter, int nID, string pName, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_GetItemImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemImageEx(int hAdapter, int nID, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteItem(int hAdapter, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_DeleteItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteItemAll(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterTree_DeleteColumnAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteColumnAll(int hAdapter);


    }
    partial class XAdapterMap
    {
        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create();

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_AddItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AddItemText(int hAdapter, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_AddItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AddItemImage(int hAdapter, string pName, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_DeleteItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteItem(int hAdapter, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_GetCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCount(int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemText(int hAdapter, string pName, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_GetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemImage(int hAdapter, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemText(int hAdapter, string pName, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XAdapterMap_SetItemImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemImage(int hAdapter, string pName, int hImage);

    }
    partial class XDraw
    {
        [DllImport("xcgui.dll", EntryPoint = "XDraw_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int hdc);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hDraw);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetOffset(int hDraw, int x, int y);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_GetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetOffset(int hDraw, int pX, int pY);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_RestoreGDIOBJ", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RestoreGDIOBJ(int hDraw);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_GetHDC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHDC(int hDraw);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetBrushColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBrushColor(int hDraw, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextAlign(int hDraw, int nFlag);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetTextVertical", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextVertical(int hDraw, bool bVertical);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetFontX", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFontX(int hDraw, int hFontx);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetLineWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLineWidth(int hDraw, int nWidth);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetBkMode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SetBkMode(int hDraw, bool bTransparent);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetClipRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetClipRect(int hDraw, RECT pRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_ClearClip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearClip(int hDraw);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_EnableSmoothingMode", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableSmoothingMode(int hDraw, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_CreateSolidBrush", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateSolidBrush(int hDraw, int crColor);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_CreatePen", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreatePen(int hDraw, int fnPenStyle, int nWidth, int crColor);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_CreateRectRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateRectRgn(int hDraw, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_CreateRoundRectRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateRoundRectRgn(int hDraw, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, int nWidthEllipse, int nHeightEllipse);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_CreatePolygonRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreatePolygonRgn(int hDraw, POINT* pPt, int cPoints, int fnPolyFillMode);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SelectClipRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SelectClipRgn(int hDraw, int hRgn);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FillRect(int hDraw, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillRectColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FillRectColor(int hDraw, RECT* pRect, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool FillRgn(int hDraw, int hrgn, int hbr);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillEllipse", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FillEllipse(int hDraw, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawEllipse", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawEllipse(int hDraw, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillRoundRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FillRoundRect(int hDraw, RECT* pRect, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawRoundRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawRoundRect(int hDraw, RECT* pRect, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillRoundRectEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FillRoundRectEx(int hDraw, RECT* pRect, int nLeftTop, int nRightTop, int nRightBottom, int nLeftBottom);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawRoundRectEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawRoundRectEx(int hDraw, RECT* pRect, int nLeftTop, int nRightTop, int nRightBottom, int nLeftBottom);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_Rectangle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Rectangle(int hDraw, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawGroupBox_Rect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawGroupBox_Rect(int hDraw, RECT* pRect, string pName, int textColor, byte textAlpha, POINT* pOffset);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawGroupBox_RoundRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawGroupBox_RoundRect(int hDraw, RECT* pRect, string pName, int textColor, byte textAlpha, POINT* pOffset, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_GradientFill2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GradientFill2(int hDraw, int color1, byte alpha1, int color2, byte alpha2, RECT* pRect, int mode);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_GradientFill4", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GradientFill4(int hDraw, int color1, int color2, int color3, int color4, RECT* pRect, int mode);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FrameRgn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool FrameRgn(int hDraw, int hrgn, int hbr, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FrameRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FrameRect(int hDraw, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FocusRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FocusRect(int hDraw, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawLine(int hDraw, int x1, int y1, int x2, int y2);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_MoveToEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool MoveToEx(int hDraw, int X, int Y, POINT* lpPoint);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_LineTo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool LineTo(int hDraw, int nXEnd, int nYEnd);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_Polyline", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Polyline(int hDraw, POINT* pArrayPt, int arrayPtSize);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_Dottedline", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Dottedline(int hDraw, int x1, int y1, int x2, int y2);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetPixel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SetPixel(int hDraw, int X, int Y, int crColor);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_Check", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Check(int hDraw, int x, int y, int color, bool bCheck);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawIconEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DrawIconEx(int hDraw, int xLeft, int yTop, int hIcon, int cxWidth, int cyWidth, int istepIfAniCur, int hbrFlickerFreeDraw, int diFlags);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_BitBlt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool BitBlt(int hDrawDest, int nXDest, int nYDest, int nWidth, int nHeight, int hdcSrc, int nXSrc, int nYSrc, int dwRop);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_BitBlt2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool BitBlt2(int hDrawDest, int nXDest, int nYDest, int nWidth, int nHeight, int hDrawSrc, int nXSrc, int nYSrc, int dwRop);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_AlphaBlend", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AlphaBlend(int hDraw, int nXOriginDest, int nYOriginDest, int nWidthDest, int nHeightDest, int hdcSrc, int nXOriginSrc, int nYOriginSrc, int nWidthSrc, int nHeightSrc, int alpha);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_TriangularArrow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void TriangularArrow(int hDraw, int align, int x, int y, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawPolygon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawPolygon(int hDraw, POINT* points, int nCount);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawPolygonF", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawPolygonF(int hDraw, POINTF* points, int nCount);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillPolygon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FillPolygon(int hDraw, POINT* points, int nCount);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_FillPolygonF", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FillPolygonF(int hDraw, POINTF* points, int nCount);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_Image", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Image(int hDraw, int hImage, int x, int y);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_Image2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Image2(int hDraw, int hImage, int x, int y, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_ImageStretch", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ImageStretch(int hDraw, int hImage, int x, int y, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_ImageAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ImageAdaptive(int hDraw, int hImage, RECT* pRect, bool bOnlyBorder);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_ImageExTile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ImageExTile(int hDraw, int hImage, RECT* pRect, int flag);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_ImageSuper", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ImageSuper(int hDraw, int hImage, RECT* pRect, bool bClip);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_ImageSuper2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ImageSuper2(int hDraw, int hImage, RECT* pRcDest, RECT* pSrcRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawText(int hDraw, string lpString, int nCount, RECT* lpRect);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_DrawTextUnderline", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawTextUnderline(int hDraw, string lpString, int nCount, RECT lpRect, int colorLine, byte alphaLine);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_TextOut", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void TextOut(int hDraw, int nXStart, int nYStart, string lpString, int cbString);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_TextOutEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void TextOutEx(int hDraw, int nXStart, int nYStart, string lpString);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_TextOutA", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void TextOutA(int hDraw, int nXStart, int nYStart, string lpString);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetAlpha", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAlpha(int hDraw, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XDraw_SetAlphaEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAlphaEx(int hdc, byte alpha);
    }

    partial class XEle
    {
       unsafe public static void RegEventCPP(int hEle, int xeEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            RegEventC(hEle, xeEvent, (int)pOnBtnClick);
        }
        unsafe public static void RegEventCPP1(int hEle, int xeEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            RegEventC1(hEle, xeEvent, (int)pOnBtnClick);
        }
        unsafe public static void RegEventCPP2(int hEle, int xeEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            RegEventC2(hEle, xeEvent, (int)pOnBtnClick);
        }

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XEle_SetBorderSize(int hEle, int left, int top, int right, int bottom);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XEle_GetBorderSize(int hEle, BorderSize_i pBorder);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XEle_SetPadding(int hEle, int left, int top, int right, int bottom);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XEle_GetPadding(int hEle, PaddingSize_i pPadding);

        [DllImport("xcgui.dll", EntryPoint = "XEle_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "_XEle_RegEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool _XEle_RegEvent(int hEle, int nEvent, int pEvent);

        [DllImport("xcgui.dll", EntryPoint = "_XEle_RemoveEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool _XEle_RemoveEvent(int hEle, int nEvent, int pEvent);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RegEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegEventC(int hEle, int nEvent, int pFun);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RegEventC1", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegEventC1(int hEle, int nEvent, int pFun);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RegEventC2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegEventC2(int hEle, int nEvent, int pFun);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RemoveEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RemoveEventC(int hEle, int nEvent, int pFun);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SendEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SendEvent(int hEle, int hEventEle, int nEvent, int wParam, int lParam);

        [DllImport("xcgui.dll", EntryPoint = "XEle_PostEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool PostEvent(int hEle, int hEventEle, int nEvent, int wParam, int lParam);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsShow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsShow(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsEnable", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsEnable(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsEnableFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsEnableFocus(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsDrawFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsDrawFocus(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsEnableEvent_XE_PAINT_END", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsEnableEvent_XE_PAINT_END(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsMouseThrough", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsMouseThrough(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsBkTransparent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsBkTransparent(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsKeyTab", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsKeyTab(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsSwitchFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsSwitchFocus(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsEnable_XE_MOUSEWHEEL", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsEnable_XE_MOUSEWHEEL(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_IsInScrollView", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsInScrollView(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_Enable", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Enable(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableFocus(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableDrawFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDrawFocus(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableDrawBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDrawBorder(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableEvent_XE_PAINT_END", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableEvent_XE_PAINT_END(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableBkTransparent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableBkTransparent(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableMouseThrough", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableMouseThrough(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableKeyTab", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableKeyTab(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableSwitchFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableSwitchFocus(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableEvent_XE_MOUSEWHEEL", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableEvent_XE_MOUSEWHEEL(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableInScrollView", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableInScrollView(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetRect(int hEle, RECT* pRect, bool bRedraw);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetRectEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetRectEx(int hEle, int x, int y, int cx, int cy, bool bRedraw);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetRectLogic", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetRectLogic(int hEle, RECT* pRect, bool bRedraw);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetRect(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetRectLogic", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetRectLogic(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetClientRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetClientRect(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetWndClientRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetWndClientRect(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetWidth(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RectWndClientToEleClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RectWndClientToEleClient(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XEle_PointWndClientToEleClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void PointWndClientToEleClient(int hEle, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RectClientToWndClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RectClientToWndClient(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XEle_PointClientToWndClient", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void PointClientToWndClient(int hEle, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XEle_AddEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AddEle(int hEle, int hChildEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_InsertEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool InsertEle(int hEle, int hChildEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RemoveEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RemoveEle(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_AddShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AddShape(int hEle, int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetZOrder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetZOrder(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetZOrderEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetZOrderEx(int hEle, int hDestEle, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetZOrder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetZOrder(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetTopmost", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetTopmost(int hEle, bool bTopmost);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableCSS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableCSS(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCssName(int hEle, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern string GetCssName(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_ShowEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowEle(int hEle, bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetType(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetHWND", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHWND(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetHWINDOW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHWINDOW(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCursor(int hEle, int hCursor);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCursor(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetID(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetID(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetUID(int hEle, int nUID);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetUID(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetParentEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParentEle(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetParent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParent(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextColor(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTextColor(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetFocusBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFocusBorderColor(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetFocusBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetFocusBorderColor(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFont(int hEle, int hFontx);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetFont(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetAlpha", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAlpha(int hEle, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetChildCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetChildByIndex", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildByIndex(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetChildByID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildByID(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetChildShapeCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildShapeCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetChildShapeByIndex", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildShapeByIndex(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XEle_HitChildEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitChildEle(int hEle, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XEle_BindLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindLayoutObject(int hEle, int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLayoutObject(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetParentLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParentLayoutObject(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetUserData(int hEle, int nData);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetUserData(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetContentSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetContentSize(int hEle, SIZE* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetCapture", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCapture(int hEle, bool b);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutWidth(int hEle, int nType, int nWidth);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutHeight(int hEle, int nType, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutWidth(int hEle, int pType, int pWidth);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutHeight(int hEle, int pType, int pHeight);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RedrawEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RedrawEle(int hEle, bool bImmediate);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RedrawRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RedrawRect(int hEle, RECT* pRect, bool bImmediate);

        [DllImport("xcgui.dll", EntryPoint = "XEle_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_AddBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkBorder(int hEle, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XEle_AddBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkFill(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XEle_AddBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddBkImage(int hEle, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetBkInfoCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_ClearBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearBkInfo(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetBkInfoManager", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetBkInfoManager(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetStateFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetStateFlags(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_DrawFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DrawFocus(int hEle, int hDraw, RECT pRect);

        [DllImport("xcgui.dll", EntryPoint = "XEle_DrawEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawEle(int hEle, int hDraw);

        [DllImport("xcgui.dll", EntryPoint = "XEle_EnableTransparentChannel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableTransparentChannel(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetXCTimer(int hEle, int nIDEvent, int uElapse);

        [DllImport("xcgui.dll", EntryPoint = "XEle_KillXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool KillXCTimer(int hEle, int nIDEvent);

        [DllImport("xcgui.dll", EntryPoint = "XEle_SetToolTip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetToolTip(int hEle, string pText);

        [DllImport("xcgui.dll", EntryPoint = "XEle_GetToolTip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetToolTip(int hEle, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XEle_PopupToolTip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void PopupToolTip(int hEle, int x, int y);

        [DllImport("xcgui.dll", EntryPoint = "XEle_AdjustLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AdjustLayoutObject(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AdjustLayout(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XEle_RegEventTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegEventTest(int nEvent, int pParamType);

    }
    partial class XFont
    {
        [DllImport("xcgui.dll", EntryPoint = "XFont_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int size);

        [DllImport("xcgui.dll", EntryPoint = "XFont_Create2", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create2(string pName, int size, int style);

        [DllImport("xcgui.dll", EntryPoint = "XFont_Create3", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create3(xc_font_info_i* pInfo);

        [DllImport("xcgui.dll", EntryPoint = "XFont_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateEx(LOGFONTW* pFontInfo);

        [DllImport("xcgui.dll", EntryPoint = "XFont_CreateFromHFONT", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateFromHFONT(int hFont);

        [DllImport("xcgui.dll", EntryPoint = "XFont_CreateFromFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateFromFont(int pFont);

        [DllImport("xcgui.dll", EntryPoint = "XFont_CreateFromFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateFromFile(string pFontFile, int size, int style);

        [DllImport("xcgui.dll", EntryPoint = "XFont_EnableAutoDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAutoDestroy(int hFontX, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XFont_GetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetFont(int hFontX);

        [DllImport("xcgui.dll", EntryPoint = "XFont_GetFontInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetFontInfo(int hFontX, xc_font_info_i* pInfo);

        [DllImport("xcgui.dll", EntryPoint = "XFont_AddRef", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddRef(int hFontX);

        [DllImport("xcgui.dll", EntryPoint = "XFont_Release", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Release(int hFontX);

        [DllImport("xcgui.dll", EntryPoint = "XFont_GetRefCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRefCount(int hFontX);

        [DllImport("xcgui.dll", EntryPoint = "XFont_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hFontX);
    }

    partial class XFrameWnd
    {
        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, string pTitle, int hWndParent, int XCStyle);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateEx(int dwExStyle, string lpClassName, string lpWindowName, int dwStyle, int x, int y, int cx, int cy, int hWndParent, int XCStyle);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_GetLayoutAreaRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutAreaRect(int hWindow, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_SetView", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetView(int hWindow, int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_SetPaneSplitBarColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetPaneSplitBarColor(int hWindow, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_SaveLayoutToFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SaveLayoutToFile(int hWindow, string pFileName);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_LoadLayoutFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool LoadLayoutFile(int hWindow, int aPaneList, int nEleCount, string pFileName);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_AddPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AddPane(int hWindow, int hPaneDest, int hPaneNew, int align);

        [DllImport("xcgui.dll", EntryPoint = "XFrameWnd_MergePane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool MergePane(int hWindow, int hPaneDest, int hPaneNew);

    }
    partial class XImage
    {
        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadFile(string pImageName, bool bStretch);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadFileAdaptive(string pImageName, int leftSize, int topSize, int rightSize, int bottomSize);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadFileRect(string pImageName, int x, int y, int cx, int cy);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadResAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadResAdaptive(int id, string pType, int leftSize, int topSize, int rightSize, int bottomSize);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadRes", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadRes(int id, string pType, bool bStretch);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadZip", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadZip(string pZipFileName, string pImageName, string pPassword, bool bStretch);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadZipAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadZipAdaptive(string pZipFileName, string pImageName, string pPassword, int x1, int x2, int y1, int y2);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadZipRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadZipRect(string pZipFileName, string pImageName, string pPassword, int x, int y, int cx, int cy);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadMemory", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadMemory(int pBuffer, int nSize, bool bStretch);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadMemoryRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadMemoryRect(int pBuffer, int nSize, int x, int y, int cx, int cy, bool bStretch);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadMemoryAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadMemoryAdaptive(int pBuffer, int nSize, int leftSize, int topSize, int rightSize, int bottomSize);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadFromImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadFromImage(int pImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileFromExtractIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadFileFromExtractIcon(string pImageName);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileFromHICON", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadFileFromHICON(int hIcon);

        [DllImport("xcgui.dll", EntryPoint = "XImage_LoadFileFromHBITMAP", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int LoadFileFromHBITMAP(int hBitmap);

        [DllImport("xcgui.dll", EntryPoint = "XImage_IsStretch", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsStretch(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_IsAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsAdaptive(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_IsTile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsTile(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_SetDrawType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetDrawType(int hImage, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XImage_SetDrawTypeAdaptive", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetDrawTypeAdaptive(int hImage, int leftSize, int topSize, int rightSize, int bottomSize);

        [DllImport("xcgui.dll", EntryPoint = "XImage_SetTranColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTranColor(int hImage, int color);

        [DllImport("xcgui.dll", EntryPoint = "XImage_SetTranColorEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTranColorEx(int hImage, int color, byte tranColor);

        [DllImport("xcgui.dll", EntryPoint = "XImage_SetRotateAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern float SetRotateAngle(int hImage, float fAngle);

        [DllImport("xcgui.dll", EntryPoint = "XImage_EnableTranColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableTranColor(int hImage, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XImage_EnableAutoDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAutoDestroy(int hImage, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XImage_EnableCenter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableCenter(int hImage, bool bCenter);

        [DllImport("xcgui.dll", EntryPoint = "XImage_IsCenter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsCenter(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_GetDrawType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetDrawType(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetWidth(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeight(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_AddRef", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddRef(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_Release", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Release(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_GetRefCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRefCount(int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XImage_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hImage);
    }
    partial class XLayout
    {
        [DllImport("xcgui.dll", EntryPoint = "XLayout_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create();

        [DllImport("xcgui.dll", EntryPoint = "XLayout_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_AddEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddEle(int hLayout, int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_AddLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddLayoutObject(int hLayout, int hLayoutObject);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_AddShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddShape(int hLayout, int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_Add", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Add(int hLayout, int hChild);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_Insert", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Insert(int hLayout, int hChild, int index);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_RemoveLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RemoveLayout(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_RemoveChild", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RemoveChild(int hLayout, int hChild);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetZOrder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetZOrder(int hLayout, int hChild);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AdjustLayout(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetRectFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRectFrame(int hLayout, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetRect(int hLayout, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetRectFrame", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetRectFrame(int hLayout, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetWindow(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetEle(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetParentLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParentLayout(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetParent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParent(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetID(int hLayout, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetID(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetUID(int hLayout, int nUID);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetUID(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetHorizon(int hLayout, bool bHorizon);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetAlignH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAlignH(int hLayout, int nAlign);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetAlignV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAlignV(int hLayout, int nAlign);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetPadding(int hLayout, int left, int top, int right, int bottom);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSpace(int hLayout, int nSpace);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutWidth(int hLayout, int nType, int nWidth);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutHeight(int hLayout, int nType, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutWidth(int hLayout, int pType, int pWidth);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutHeight(int hLayout, int pType, int pHeight);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetWidth(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeight(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetWidthIn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetWidthIn(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetHeightIn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeightIn(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetContentSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetContentSize(int hLayout, SIZE* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_ShowLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowLayout(int hLayout, bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetChildCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildCount(int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetChildType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildType(int hLayout, int index);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_GetChild", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChild(int hLayout, int index);

        [DllImport("xcgui.dll", EntryPoint = "XLayout_Draw", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Draw(int hLayout, int hDraw);

        [DllImport("xcgui.dll", EntryPoint = "Layout_SetEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Layout_SetEle(int hLayout, int hParent);


    }
    partial class XListBox
    {
        [DllImport("xcgui.dll", EntryPoint = "XListBox_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDrawItemBkFlags(int hEle, int nFlags);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemData(int hEle, int iItem, int nUserData);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemData(int hEle, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemInfo(int hEle, int iItem, listBox_item_info_i* pItem);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemInfo(int hEle, int iItem, listBox_item_info_i* pItem);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkBorder(int hEle, int nState, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkFill(int hEle, int nState, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkImage(int hEle, int nState, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemBkInfoCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearItemBkInfo(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetSelectItem(int hEle, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectItem(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_CancelSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool CancelSelectItem(int hEle, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_CancelSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool CancelSelectAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectAll(int hEle, int pArray, int nArraySize);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetSelectCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemMouseStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemMouseStay(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SelectAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemHeightDefault(int hEle, int nHeight, int nSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetItemHeightDefault(int hEle, int pHeight, int pSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetItemIndexFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemIndexFromHXCGUI(int hEle, int hXCGUI);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRowSpace(int hEle, int nSpace);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRowSpace(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitTest(int hEle, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitTestOffset(int hEle, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXML(int hEle, string pXmlFile);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXMLFromString(int hEle, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTemplateObject(int hEle, int iItem, int nTempItemID);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_EnableMultiSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableMultiSel(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindAdapter(int hEle, int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_Sort", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Sort(int hEle, int iColumnAdapter, bool bAscending);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshData(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListBox_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshItem(int hEle, int iItem);
    }
    partial class XList
    {
        [DllImport("xcgui.dll", EntryPoint = "XList_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XList_AddColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddColumn(int hEle, int width);

        [DllImport("xcgui.dll", EntryPoint = "XList_InsertColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertColumn(int hEle, int width, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XList_EnableMultiSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableMultiSel(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XList_EnableDragChangeColumnWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDragChangeColumnWidth(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XList_EnableVScrollBarTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableVScrollBarTop(int hEle, bool bTop);

        [DllImport("xcgui.dll", EntryPoint = "XList_EnableItemBkFullRow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableItemBkFullRow(int hEle, bool bFull);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetSort", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSort(int hEle, int iColumn, int iColumnAdapter, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDrawItemBkFlags(int hEle, int style);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetColumnWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetColumnWidth(int hEle, int iItem, int width);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetColumnMinWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetColumnMinWidth(int hEle, int iItem, int width);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetColumnWidthFixed", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetColumnWidthFixed(int hEle, int iColumn, bool bFixed);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetColumnWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetColumnWidth(int hEle, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetColumnCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetColumnCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_DeleteColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteColumn(int hEle, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XList_DeleteColumnAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteColumnAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemData(int hEle, int iItem, int iSubItem, int data);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemData(int hEle, int iItem, int iSubItem);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetSelectItem(int hEle, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectItem(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetSelectItemCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectItemCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSelectAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectAll(int hEle, int pArray, int nArraySize);

        [DllImport("xcgui.dll", EntryPoint = "XList_CancelSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool CancelSelectItem(int hEle, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XList_CancelSelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void CancelSelectAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeaderHELE(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindAdapter(int hEle, int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XList_BindAdapterHeader", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindAdapterHeader(int hEle, int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XList_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_CreateAdapterHeader", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateAdapterHeader(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetAdapterHeader", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetAdapterHeader(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXML(int hEle, string pXmlFile);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXMLFromString(int hEle, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTemplateObject(int hEle, int iItem, int nTempItemID);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetItemIndexFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemIndexFromHXCGUI(int hEle, int hXCGUI);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeaderTemplateObject(int hEle, int iItem, int nTempItemID);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderItemIndexFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeaderItemIndexFromHXCGUI(int hEle, int hXCGUI);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetHeaderHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetHeaderHeight(int hEle, int height);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetHeaderHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeaderHeight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkBorder(int hEle, int nState, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XList_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkFill(int hEle, int nState, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XList_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkImage(int hEle, int nState, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemBkInfoCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearItemBkInfo(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemHeightDefault(int hEle, int nHeight, int nSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetItemHeightDefault(int hEle, int pHeight, int pSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XList_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRowSpace(int hEle, int nSpace);

        [DllImport("xcgui.dll", EntryPoint = "XList_GetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRowSpace(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool HitTest(int hEle, POINT* pPt, int piItem, int piSubItem);

        [DllImport("xcgui.dll", EntryPoint = "XList_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool HitTestOffset(int hEle, POINT* pPt, int piItem, int piSubItem);

        [DllImport("xcgui.dll", EntryPoint = "XList_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshData(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XList_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshItem(int hEle, int iItem);
    }
    partial class XListView
    {
        [DllImport("xcgui.dll", EntryPoint = "XListView_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XListView_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindAdapter(int hEle, int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXML(int hEle, string pXmlFile);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXMLFromString(int hEle, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTemplateObject(int hEle, int iGroup, int iItem, int nTempItemID);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetTemplateObjectGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTemplateObjectGroup(int hEle, int iGroup, int nTempItemID);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetItemIDFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemIDFromHXCGUI(int hEle, int hXCGUI, int piGroup, int piItem);

        [DllImport("xcgui.dll", EntryPoint = "XListView_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool HitTest(int hEle, POINT* pPt, int pOutGroup, int pOutItem);

        [DllImport("xcgui.dll", EntryPoint = "XListView_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitTestOffset(int hEle, POINT* pPt, int pOutGroup, int pOutItem);

        [DllImport("xcgui.dll", EntryPoint = "XListView_EnableMultiSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableMultiSel(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDrawItemBkFlags(int hEle, int nFlags);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetSelectItem(int hEle, int iGroup, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetSelectItem(int hEle, int piGroup, int piItem);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetSelectItemCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectItemCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetSelectItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectItemAll(int hEle, listView_item_id_i* pArray, int nArraySize);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetSelectItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSelectItemAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_CancelSelectItemAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void CancelSelectItemAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetColumnSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetColumnSpace(int hEle, int space);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRowSpace(int hEle, int space);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetAlignSizeLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAlignSizeLeft(int hEle, int size);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetAlignSizeTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAlignSizeTop(int hEle, int size);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetItemSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemSize(int hEle, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetItemSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetItemSize(int hEle, SIZE* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetGroupHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetGroupHeight(int hEle, int height);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetGroupHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetGroupHeight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetGroupUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetGroupUserData(int hEle, int iGroup, int nData);

        [DllImport("xcgui.dll", EntryPoint = "XListView_SetItemUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemUserData(int hEle, int iGroup, int iItem, int nData);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetGroupUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetGroupUserData(int hEle, int iGroup);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetItemUserData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemUserData(int hEle, int iGroup, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XListView_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkBorder(int hEle, int nState, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XListView_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkFill(int hEle, int nState, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XListView_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkImage(int hEle, int nState, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XListView_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemBkInfoCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearItemBkInfo(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshData(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XListView_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshItem(int hEle, int iGroup, int iItem);

        [DllImport("xcgui.dll", EntryPoint = "XListView_ExpandGroup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ExpandGroup(int hEle, int iGroup, bool bExpand);

    }
    partial class XMenuBar
    {
        [DllImport("xcgui.dll", EntryPoint = "XMenuBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XMenuBar_AddButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddButton(int hEle, string pText);

        [DllImport("xcgui.dll", EntryPoint = "XMenuBar_SetButtonHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetButtonHeight(int hEle, int height);

        [DllImport("xcgui.dll", EntryPoint = "XMenuBar_GetMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetMenu(int hEle, int nIndex);

        [DllImport("xcgui.dll", EntryPoint = "XMenuBar_DeleteButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteButton(int hEle, int nIndex);
    }
    partial class XMenu
    {
        [DllImport("xcgui.dll", EntryPoint = "XMenu_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create();

        [DllImport("xcgui.dll", EntryPoint = "XMenu_AddItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItem(int hMenu, int nID, string pText, int parentId, int nFlags);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_AddItemIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemIcon(int hMenu, int nID, string pText, int nParentID, int hImage, int nFlags);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_InsertItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void InsertItem(int hMenu, int nID, string pText, int nFlags, int insertID);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_InsertItemIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void InsertItemIcon(int hMenu, int nID, string pText, int hIcon, int nFlags, int insertID);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetAutoDestroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetAutoDestroy(int hMenu, bool bAuto);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_EnableDrawBackground", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDrawBackground(int hMenu, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_EnableDrawItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDrawItem(int hMenu, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_Popup", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool Popup(int hMenu, int hParentWnd, int x, int y, int hParentEle, int nPosition);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_DestroyMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DestroyMenu(int hMenu);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_CloseMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void CloseMenu(int hMenu);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBkImage(int hMenu, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemText(int hMenu, int nID, string pText);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetItemText(int hMenu, int nID, StringBuilder pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemTextLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemTextLength(int hMenu, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemIcon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemIcon(int hMenu, int nID, int hIcon);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemFlags(int hMenu, int nID, int uFlags);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemHeight(int hMenu, int height);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemHeight(int hMenu);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBorderColor(int hMenu, int crColor, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_GetLeftWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLeftWidth(int hMenu);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_GetLeftSpaceText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLeftSpaceText(int hMenu);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_GetItemCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemCount(int hMenu);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_SetItemCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemCheck(int hMenu, int nID, bool bCheck);

        [DllImport("xcgui.dll", EntryPoint = "XMenu_IsItemCheck", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsItemCheck(int hMenu, int nID);
    }
    partial class XModalWnd
    {
        [DllImport("xcgui.dll", EntryPoint = "XModalWnd_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int nWidth, int nHeight, string pTitle, int hWndParent, int XCStyle);

        [DllImport("xcgui.dll", EntryPoint = "XModalWnd_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateEx(int dwExStyle, string lpClassName, string lpWindowName, int dwStyle, int x, int y, int cx, int cy, int hWndParent, int XCStyle);

        [DllImport("xcgui.dll", EntryPoint = "XModalWnd_EnableAutoClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAutoClose(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XModalWnd_DoModal", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int DoModal(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XModalWnd_EndModal", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EndModal(int hWindow, int nResult);
    }
    partial class XPane
    {
        [DllImport("xcgui.dll", EntryPoint = "XPane_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(string pName, int nWidth, int nHeight, int hFrameWnd);

        [DllImport("xcgui.dll", EntryPoint = "XPane_SetView", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetView(int hEle, int hView);

        [DllImport("xcgui.dll", EntryPoint = "XPane_IsShowPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsShowPane(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_SetSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSize(int hEle, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XPane_GetState", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetState(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_GetViewRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetViewRect(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XPane_SetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTitle(int hEle, string pTitle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_GetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetTitle(int hEle, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XPane_SetCaptionHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCaptionHeight(int hEle, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XPane_GetCaptionHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCaptionHeight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_HidePane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void HidePane(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_ShowPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowPane(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_DockPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DockPane(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_LockPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void LockPane(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPane_FloatPane", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void FloatPane(int hEle);
    }
    partial class XFloatWnd
    {
        [DllImport("xcgui.dll", EntryPoint = "XFloatWnd_EnableCaptionContent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool EnableCaptionContent(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetCaptionLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCaptionLayout(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetCaptionShapeText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCaptionShapeText(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetCaptionButtonClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCaptionButtonClose(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XFloatWnd_SetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTitle(int hWindow, string pTitle);

        [DllImport("xcgui.dll", EntryPoint = "XFloatWnd_GetTitle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetTitle(int hWindow, string pOut, int nOutLen);
    }
    partial class XProgBar
    {
        [DllImport("xcgui.dll", EntryPoint = "XProgBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XProgBar_SetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRange(int hEle, int range);

        [DllImport("xcgui.dll", EntryPoint = "XProgBar_GetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRange(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XProgBar_SetSpaceTwo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSpaceTwo(int hEle, int leftSize, int rightSize);

        [DllImport("xcgui.dll", EntryPoint = "XProgBar_SetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetPos(int hEle, int pos);

        [DllImport("xcgui.dll", EntryPoint = "XProgBar_GetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetPos(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XProgBar_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetHorizon(int hEle, bool bHorizon);

        [DllImport("xcgui.dll", EntryPoint = "XProgBar_SetImageLoad", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetImageLoad(int hEle, int hImage);
    }
    partial class XPGrid
    {
        [DllImport("xcgui.dll", EntryPoint = "XPGrid_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_AddItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddItem(int hEle, string pName, int nType, int nParentID);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_AddItemString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddItemString(int hEle, string pName, string pValue, int nParentID);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_DeleteAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_GetItemHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemHELE(int hEle, int nItemID);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_SetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetWidth(int hEle, int nWidth);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_SetItemValue", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemValue(int hEle, int nItemID, string pValue);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_SetItemValueInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemValueInt(int hEle, int nItemID, int nValue);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemData(int hEle, int nItemID, int nUserData);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemData(int hEle, int nItemID);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_GetItemValue", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern string GetItemValue(int hEle, int nItemID);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitTest(int hEle, POINT* pPt, bool pbExpandButton);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitTestOffset(int hEle, POINT* pPt, bool pbExpandButton);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_ExpandItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ExpandItem(int hEle, int nItemID, bool bExpand);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_GetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelItem(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_SetSelItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetSelItem(int hEle, int nItemID);

        [DllImport("xcgui.dll", EntryPoint = "XPGrid_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDrawItemBkFlags(int hEle, int nFlags);
    }
    partial class XRichEditColor
    {
        [DllImport("xcgui.dll", EntryPoint = "XRichEditColor_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XRichEditColor_SetColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetColor(int hEle, int color);

        [DllImport("xcgui.dll", EntryPoint = "XRichEditColor_GetColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetColor(int hEle);
    }
    partial class XRichEditFile
    {
        [DllImport("xcgui.dll", EntryPoint = "XRichEditFile_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XRichEditFile_SetOpenFileType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetOpenFileType(int hEle, string pType);

        [DllImport("xcgui.dll", EntryPoint = "XRichEditFile_SetDefaultFile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDefaultFile(int hEle, string pFile);

        [DllImport("xcgui.dll", EntryPoint = "XRichEditFile_SetRelativeDir", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRelativeDir(int hEle, string pDir);
    }
    partial class XRichEditSet
    {
        [DllImport("xcgui.dll", EntryPoint = "XRichEditSet_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);
    }
    partial class XRichEditFolder
    {
        [DllImport("xcgui.dll", EntryPoint = "XRichEditFolder_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XRichEditFolder_SetDefaultDir", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDefaultDir(int hEle, string pDir);
    }
    partial class XRichEdit
    {

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void InsertString(int hEle, string pString, int hFont, int color);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool InsertImage(int hEle, int hImage, string pImagePath);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertGif", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool InsertGif(int hEle, int hImage, string pImagePath);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertStringEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void InsertStringEx(int hEle, int iRow, int iColumn, string pString, int hFont, int color);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertImageEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool InsertImageEx(int hEle, int iRow, int iColumn, int hImage, string pImagePath);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertGifEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool InsertGifEx(int hEle, int iRow, int iColumn, int hImage, string pImagePath);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableReadOnly", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableReadOnly(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableMultiLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableMultiLine(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnablePassword", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnablePassword(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableEvent_XE_RICHEDIT_CHANGE(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableAutoWrap", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAutoWrap(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableAutoSelAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAutoSelAll(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_EnableVerticalCenter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableVerticalCenter(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetLimitNum", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLimitNum(int hEle, int nNumber);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetCaretColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCaretColor(int hEle, int color);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetText(int hEle, string pString);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetTextInt", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextInt(int hEle, int nVaule);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetText(int hEle, string pOut, int len);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetHTMLFormat", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetHTMLFormat(int hEle, string pOut, int len);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetData(int hEle, int pDataSize);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_InsertData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool InsertData(int hEle, int pData, int iRow, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetTextLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTextLength(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetRowHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRowHeight(int hEle, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetDefaultText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDefaultText(int hEle, string pString);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetDefaultTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDefaultTextColor(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetCurrentRow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCurrentRow(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetCurrentColumn", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCurrentColumn(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetCurrentPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCurrentPos(int hEle, int iRow, int iColumn);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetRowCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRowCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetRowLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRowLength(int hEle, int iRow);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetSelectText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectText(int hEle, string pOut, int len);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_GetSelectPosition", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetSelectPosition(int hEle, Position_i* pBegin, Position_i* pEnd);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetSelect(int hEle, int iStartRow, int iStartCol, int iEndRow, int iEndCol);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetItemFontEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemFontEx(int hEle, int beginRow, int beginColumn, int endRow, int endColumn, int hFont);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetItemColorEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemColorEx(int hEle, int beginRow, int beginColumn, int endRow, int endColumn, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_CancelSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void CancelSelect(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SetSelectBkColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSelectBkColor(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_IsEmpty", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsEmpty(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_SelectAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SelectAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_DeleteSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteSelect(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_DeleteAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_ClipboardCut", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ClipboardCut(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_ClipboardCopy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ClipboardCopy(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XRichEdit_ClipboardPaste", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ClipboardPaste(int hEle);
    }
    partial class XSBar
    {
        [DllImport("xcgui.dll", EntryPoint = "XSBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XSBar_Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_SetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XSBar_SetRange(int hEle, int range);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_GetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XSBar_GetRange(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_ShowButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XSBar_ShowButton(int hEle, bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_SetSliderLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XSBar_SetSliderLength(int hEle, int length);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_SetSliderMinLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XSBar_SetSliderMinLength(int hEle, int minLength);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_SetSliderPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void XSBar_SetSliderPadding(int hEle, int nPadding);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XSBar_SetHorizon(int hEle, bool bHorizon);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_GetSliderMaxLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XSBar_GetSliderMaxLength(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollUp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XSBar_ScrollUp(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollDown", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XSBar_ScrollDown(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XSBar_ScrollTop(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollBottom", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XSBar_ScrollBottom(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_ScrollPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool XSBar_ScrollPos(int hEle, int pos);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_GetButtonUp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XSBar_GetButtonUp(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_GetButtonDown", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XSBar_GetButtonDown(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSBar_GetButtonSlider", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int XSBar_GetButtonSlider(int hEle);
    }
    partial class XSView
    {
        [DllImport("xcgui.dll", EntryPoint = "XSView_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XSView_SetTotalSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetTotalSize(int hEle, int cx, int cy);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetTotalSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetTotalSize(int hEle, SIZE* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XSView_SetLineSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetLineSize(int hEle, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetLineSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLineSize(int hEle, SIZE pSize);

        [DllImport("xcgui.dll", EntryPoint = "XSView_SetScrollBarSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetScrollBarSize(int hEle, int size);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetViewPosH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetViewPosH(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetViewPosV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetViewPosV(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetViewWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetViewWidth(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetViewHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetViewHeight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetViewRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetViewRect(int hEle, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetScrollBarH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetScrollBarH(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetScrollBarV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetScrollBarV(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_SetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBorderSize(int hEle, int left, int top, int right, int bottom);

        [DllImport("xcgui.dll", EntryPoint = "XSView_GetBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetBorderSize(int hEle, BorderSize_i* pBorder);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollPosH(int hEle, int pos);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollPosV(int hEle, int pos);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosXH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollPosXH(int hEle, int posX);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollPosYV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollPosYV(int hEle, int posY);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ShowSBarH", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowSBarH(int hEle, bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ShowSBarV", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowSBarV(int hEle, bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XSView_EnableAutoShowScrollBar", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAutoShowScrollBar(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollLeftLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollLeftLine(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollRightLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollRightLine(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollTopLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollTopLine(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollBottomLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollBottomLine(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollLeft(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollRight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollRight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollTop", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollTop(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSView_ScrollBottom", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ScrollBottom(int hEle);
    }
    partial class XShape
    {
        [DllImport("xcgui.dll", EntryPoint = "XShape_GetParentEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParentEle(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetParentLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParentLayout(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetHWINDOW", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHWINDOW(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetParent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParent(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_RemoveShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RemoveShape(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetID(int hShape, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetID(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_SetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetUID(int hShape, int nUID);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetUID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetUID(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_Redraw", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Redraw(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetWidth(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHeight(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetRect(int hShape, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XShape_SetRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRect(int hShape, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XShape_GetContentSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetContentSize(int hShape, SIZE* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XShape_ShowLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowLayout(int hShape, bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XShape_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AdjustLayout(int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XShape_Destroy", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void Destroy(int hShape);
    }
    partial class XShapeText
    {
        [DllImport("xcgui.dll", EntryPoint = "XShapeText_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, string pName, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetText(int hTextBlock, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_GetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetText(int hTextBlock, string pOut, int nOutLen);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_GetTextLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTextLength(int hTextBlock);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFont(int hTextBlock, int hFontx);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_GetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetFont(int hTextBlock);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextColor(int hTextBlock, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_GetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTextColor(int hTextBlock);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetTextAlign", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextAlign(int hTextBlock, int align);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetOffset(int hTextBlock, int x, int y);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutWidth(int hTextBlock, int nType, int width);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutHeight(int hTextBlock, int nType, int height);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutWidth(int hTextBlock, int pType, int pWidth);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutHeight(int hTextBlock, int pType, int pHeight);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_EnableCSS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableCSS(int hTextBlock, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_SetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCssName(int hTextBlock, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XShapeText_GetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern string GetCssName(int hTextBlock);
    }
    partial class XShapePic
    {
        [DllImport("xcgui.dll", EntryPoint = "XShapePic_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XShapePic_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetImage(int hShape, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XShapePic_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutWidth(int hShape, int nType, int width);

        [DllImport("xcgui.dll", EntryPoint = "XShapePic_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutHeight(int hShape, int nType, int height);

        [DllImport("xcgui.dll", EntryPoint = "XShapePic_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutWidth(int hShape, int pType, int pWidth);

        [DllImport("xcgui.dll", EntryPoint = "XShapePic_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutHeight(int hShape, int pType, int pHeight);

    }
    partial class XShapeGif
    {
        [DllImport("xcgui.dll", EntryPoint = "XShapeGif_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGif_SetImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetImage(int hShape, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGif_SetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutWidth(int hShape, int nType, int width);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGif_SetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutHeight(int hShape, int nType, int height);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGif_GetLayoutWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutWidth(int hShape, int pType, int pWidth);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGif_GetLayoutHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutHeight(int hShape, int pType, int pHeight);

    }
    partial class XShapeRect
    {
        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBorderColor(int hShape, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_SetFillColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFillColor(int hShape, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_SetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRoundAngle(int hShape, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_GetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetRoundAngle(int hShape, int pWidth, int pHeight);

        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_EnableBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableBorder(int hShape, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_EnableFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableFill(int hShape, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XShapeRect_EnableRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableRoundAngle(int hShape, bool bEnable);

    }
    partial class XShapeEllipse
    {
        [DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBorderColor(int hShape, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_SetFillColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFillColor(int hShape, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_EnableBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableBorder(int hShape, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XShapeEllipse_EnableFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableFill(int hShape, bool bEnable);

    }
    partial class XShapeGroupBox
    {
        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, string pName, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetBorderColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetBorderColor(int hShape, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextColor(int hShape, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetFontX", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFontX(int hShape, int hFontX);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetTextOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextOffset(int hShape, int offsetX, int offsetY);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRoundAngle(int hShape, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_SetText", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetText(int hShape, string pText);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_GetTextOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetTextOffset(int hShape, int pOffsetX, int pOffsetY);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_GetRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetRoundAngle(int hShape, int pWidth, int pHeight);

        [DllImport("xcgui.dll", EntryPoint = "XShapeGroupBox_EnableRoundAngle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableRoundAngle(int hShape, bool bEnable);

    }
    partial class XShapeLine
    {
        [DllImport("xcgui.dll", EntryPoint = "XShapeLine_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x1, int y1, int x2, int y2, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XShapeLine_SetPosition", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetPosition(int hShape, int x1, int y1, int x2, int y2);

        [DllImport("xcgui.dll", EntryPoint = "XShapeLine_SetColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetColor(int hShape, int color, byte alpha);

    }
    partial class XSliderBar
    {
        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRange(int hEle, int range);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_GetRange", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRange(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetButtonWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetButtonWidth(int hEle, int width);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetButtonHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetButtonHeight(int hEle, int height);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetSpaceTwo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSpaceTwo(int hEle, int leftSize, int rightSize);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetPos(int hEle, int pos);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_GetPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetPos(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_GetButton", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButton(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetHorizon", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetHorizon(int hEle, bool bHorizon);

        [DllImport("xcgui.dll", EntryPoint = "XSliderBar_SetImageLoad", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetImageLoad(int hEle, int hImage);
    }
    partial class XTabBar
    {
        [DllImport("xcgui.dll", EntryPoint = "XTabBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_AddLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int AddLabel(int hEle, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_InsertLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertLabel(int hEle, int index, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_DeleteLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool DeleteLabel(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_DeleteLabelAll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteLabelAll(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLabel(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabelClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLabelClose(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetButtonLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButtonLeft(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetButtonRight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButtonRight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelect(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabelSpacing", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLabelSpacing(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetLabelCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLabelCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_GetindexByEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetindexByEle(int hEle, int hLabel);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetLabelSpacing", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLabelSpacing(int hEle, int spacing);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetPadding", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetPadding(int hEle, int left, int top, int right, int bottom);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetSelect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSelect(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetUp", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetUp(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetDown", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDown(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_EnableTile", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableTile(int hEle, bool bTile);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_EnableClose", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableClose(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetCloseSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCloseSize(int hEle, SIZE* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetTurnButtonSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTurnButtonSize(int hEle, SIZE* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_SetLabelWidth", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLabelWidth(int hEle, int index, int nWidth);

        [DllImport("xcgui.dll", EntryPoint = "XTabBar_ShowLabel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ShowLabel(int hEle, int index, bool bShow);
    }
    partial class XTextLink
    {
        [DllImport("xcgui.dll", EntryPoint = "XTextLink_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, string pName, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XTextLink_EnableUnderlineLeave", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableUnderlineLeave(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XTextLink_EnableUnderlineStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableUnderlineStay(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XTextLink_SetTextColorStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextColorStay(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XTextLink_SetUnderlineColorLeave", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetUnderlineColorLeave(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XTextLink_SetUnderlineColorStay", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetUnderlineColorStay(int hEle, int color, byte alpha);

    }
    partial class XToolBar
    {
        [DllImport("xcgui.dll", EntryPoint = "XToolBar_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_InsertEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertEle(int hEle, int hNewEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_InsertSeparator", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int InsertSeparator(int hEle, int index, int color);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_EnableButtonMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableButtonMenu(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_GetHEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHEle(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_GetButtonLeft", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButtonLeft(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_GetButtonRight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButtonRight(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_GetButtonMenu", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetButtonMenu(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_SetSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetSpace(int hEle, int nSize);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_DeleteEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteEle(int hEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XToolBar_DeleteAllEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DeleteAllEle(int hEle);
    }
    partial class XTree
    {
        [DllImport("xcgui.dll", EntryPoint = "XTree_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, int hParent);

        [DllImport("xcgui.dll", EntryPoint = "XTree_EnableDragItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDragItem(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XTree_EnableConnectLine", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableConnectLine(int hEle, bool bEnable, bool bSolid);

        [DllImport("xcgui.dll", EntryPoint = "XTree_EnableExpand", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableExpand(int hEle, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetConnectLineColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetConnectLineColor(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetExpandButtonSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetExpandButtonSize(int hEle, int nWidth, int nHeight);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetConnectLineLength", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetConnectLineLength(int hEle, int nLength);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetDragInsertPositionColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDragInsertPositionColor(int hEle, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXML", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXML(int hEle, string pXmlFile);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXMLSel", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXMLSel(int hEle, string pXmlFile);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXMLFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXMLFromString(int hEle, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetItemTemplateXMLSelFromString", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemTemplateXMLSelFromString(int hEle, string pStringXML);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetDrawItemBkFlags", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDrawItemBkFlags(int hEle, int nFlags);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetItemData(int hEle, int nID, int nUserData);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetItemData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemData(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetSelectItem(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetSelectItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetSelectItem(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_IsExpand", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool IsExpand(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_ExpandItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ExpandItem(int hEle, int nID, bool bExpand);

        [DllImport("xcgui.dll", EntryPoint = "XTree_HitTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitTest(int hEle, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XTree_HitTestOffset", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitTestOffset(int hEle, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetFirstChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetFirstChildItem(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetEndChildItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetEndChildItem(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetPrevSiblingItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetPrevSiblingItem(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetNextSiblingItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetNextSiblingItem(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetParentItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetParentItem(int hEle, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetIndentation", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetIndentation(int hEle, int nWidth);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetIndentation", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetIndentation(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemHeight(int hEle, int nID, int nHeight, int nSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetItemHeight", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetItemHeight(int hEle, int nID, int pHeight, int pSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetRowSpace(int hEle, int nSpace);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetRowSpace", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetRowSpace(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_MoveItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool MoveItem(int hEle, int nMoveItem, int nDestItem, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XTree_AddItemBkBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkBorder(int hEle, int nState, int color, byte alpha, int width);

        [DllImport("xcgui.dll", EntryPoint = "XTree_AddItemBkFill", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkFill(int hEle, int nState, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XTree_AddItemBkImage", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AddItemBkImage(int hEle, int nState, int hImage);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetItemBkInfoCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemBkInfoCount(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_ClearItemBkInfo", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ClearItemBkInfo(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_SetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetItemHeightDefault(int hEle, int nHeight, int nSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetItemHeightDefault", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetItemHeightDefault(int hEle, int pHeight, int pSelHeight);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetTemplateObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTemplateObject(int hEle, int nID, int nTempItemID);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetItemIDFromHXCGUI", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetItemIDFromHXCGUI(int hEle, int hXCGUI);

        [DllImport("xcgui.dll", EntryPoint = "XTree_CreateAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_BindAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindAdapter(int hEle, int hAdapter);

        [DllImport("xcgui.dll", EntryPoint = "XTree_GetAdapter", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetAdapter(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_RefreshData", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshData(int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XTree_RefreshItem", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RefreshItem(int hEle, int nID);

    }

    partial class XWnd
    {

        unsafe public static void RegEventCPP(int hEle, int wmEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            RegEventC(hEle, wmEvent, (int)pOnBtnClick);
        }
        unsafe public static void RegEventCPP1(int hEle, int wmEvent, Delegate pFuc)
        {
            IntPtr pOnBtnClick = Marshal.GetFunctionPointerForDelegate(pFuc);
            RegEventC(hEle, wmEvent, (int)pOnBtnClick);
        }

        [DllImport("xcgui.dll", EntryPoint = "_XWnd_RegEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool _XWnd_RegEvent(int hWindow, int nEvent, int pEvent);

        [DllImport("xcgui.dll", EntryPoint = "_XWnd_RemoveEvent", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool _XWnd_RemoveEvent(int hWindow, int nEvent, int pEvent);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_RegEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegEventC(int hWindow, int nEvent, int pFun);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_RegEventC1", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegEventC1(int hWindow, int nEvent, int pFun);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_RemoveEventC", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RemoveEventC(int hWindow, int nEvent, int pFun);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_Create", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int Create(int x, int y, int cx, int cy, string pTitle, int hWndParent, int XCStyle);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_CreateEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int CreateEx(int dwExStyle, string lpClassName, string lpWindowName, int dwStyle, int x, int y, int cx, int cy, int hWndParent, int XCStyle);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_AddEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AddEle(int hWindow, int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_InsertEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool InsertEle(int hWindow, int hChildEle, int index);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_AddShape", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool AddShape(int hWindow, int hShape);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetHWND", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetHWND(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDragBorder", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDragBorder(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDragWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDragWindow(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDragCaption", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDragCaption(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_EnableDrawBk", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableDrawBk(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_EnableAutoFocus", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableAutoFocus(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_EnableMaxWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableMaxWindow(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_RedrawWnd", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RedrawWnd(int hWindow, bool bImmediate);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_RedrawWndRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void RedrawWndRect(int hWindow, RECT* pRect, bool bImmediate);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetFocusEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFocusEle(int hWindow, int hFocusEle);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetFocusEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetFocusEle(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetStayHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetStayHELE(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_DrawWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DrawWindow(int hWindow, int hDraw);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCursor(int hWindow, int hCursor);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetCursor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCursor(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCursorSys", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SetCursorSys(int hWindow, int hCursor);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetFont", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetFont(int hWindow, int hFontx);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTextColor(int hWindow, int color, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetTextColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetTextColor(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetID(int hWindow, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetID(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaptureEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCaptureEle(int hWindow, int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetCaptureEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCaptureEle(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_BindLayoutEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool BindLayoutEle(int hWindow, int nPosition, int hEle);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetLayoutEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLayoutEle(int hWindow, int nPosition);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_BindLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void BindLayoutObject(int hWindow, int nPosition, int hLayout);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetLayoutObject(int hWindow, int nPosition);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetLayoutSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetLayoutSize(int hWindow, int left, int top, int right, int bottom);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetLayoutSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetLayoutSize(int hWindow, BorderSize_i* pBorderSize);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetDragBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetDragBorderSize(int hWindow, int left, int top, int right, int bottom);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetDragBorderSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetDragBorderSize(int hWindow, BorderSize_i* pSize);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetMinimumSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetMinimumSize(int hWindow, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_HitChildEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int HitChildEle(int hWindow, POINT* pPt);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildCount(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildByIndex", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildByIndex(int hWindow, int index);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildByID", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildByID(int hWindow, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetEle", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetEle(int hWindow, int nID);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildShapeCount", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildShapeCount(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetChildShapeByIndex", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetChildShapeByIndex(int hWindow, int index);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetDrawRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetDrawRect(int hWindow, RECT* pRcPaint);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_ShowWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool ShowWindow(int hWindow, int nCmdShow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_AdjustLayout", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AdjustLayout(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_AdjustLayoutObject", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void AdjustLayoutObject(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_CloseWindow", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void CloseWindow(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_CreateCaret", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void CreateCaret(int hWindow, int hEle, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretSize", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCaretSize(int hWindow, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretPos", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCaretPos(int hWindow, int x, int y);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretPosEx", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCaretPosEx(int hWindow, int x, int y, int width, int height);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCaretColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCaretColor(int hWindow, int color);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_ShowCaret", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void ShowCaret(int hWindow, bool bShow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_DestroyCaret", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void DestroyCaret(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetCaretHELE", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetCaretHELE(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetClientRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool GetClientRect(int hWindow, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetBodyRect", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void GetBodyRect(int hWindow, RECT* pRect);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int SetTimer(int hWindow, int nIDEvent, int uElapse);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_KillTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool KillTimer(int hWindow, int nIDEvent);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool SetXCTimer(int hWindow, int nIDEvent, int uElapse);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_KillXCTimer", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool KillXCTimer(int hWindow, int nIDEvent);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetBkInfoManager", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern int GetBkInfoManager(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetTransparentType", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTransparentType(int hWindow, int nType);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetTransparentAlpha", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTransparentAlpha(int hWindow, byte alpha);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetTransparentColor", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetTransparentColor(int hWindow, int color);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_EnableCSS", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void EnableCSS(int hWindow, bool bEnable);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_SetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern void SetCssName(int hWindow, string pName);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_GetCssName", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern string GetCssName(int hWindow);

        [DllImport("xcgui.dll", EntryPoint = "XWnd_RegEventTest", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
        unsafe public static extern bool RegEventTest(int nEvent, int pParamType);
    }

    public class xcConst
    {
        public const int WM_MOUSEFIRST = 0x0200;
        public const int WM_MOUSEMOVE = 0x0200;
        public const int WM_LBUTTONDOWN = 0x0201;
        public const int WM_LBUTTONUP = 0x0202;
        public const int WM_LBUTTONDBLCLK = 0x0203;
        public const int WM_RBUTTONDOWN = 0x0204;
        public const int WM_RBUTTONUP = 0x0205;
        public const int WM_RBUTTONDBLCLK = 0x0206;
        public const int WM_MBUTTONDOWN = 0x0207;
        public const int WM_MBUTTONUP = 0x0208;
        public const int WM_MBUTTONDBLCLK = 0x0209;

        public const int XC_ERROR = -1;// '///<错误类型
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
        public const int XC_IMAGE = 82;// '///<图片操作
        public const int XC_HDRAW = 83;// '///<绘图操作
        public const int XC_FONT = 84;// '///<炫彩字体
        public const int XC_FLASH = 85;// '///<flash
        public const int XC_PANE_CELL = 86;// '///<...
        public const int XC_WEB = 87;// '///<...
        public const int XC_LAYOUT_OBJECT = 101;// '///<布局对象LayoutObject
        public const int XC_ADAPTER = 102;// '///<...
        public const int XC_ADAPTER_TABLE = 103;// '///<数据适配器AdapterTable
        public const int XC_ADAPTER_TREE = 104;// '///<数据适配器AdapterTree
        public const int XC_ADAPTER_LISTVIEW = 105;// '///<数据适配器AdapterListView
        public const int XC_ADAPTER_MAP = 106;// '///<数据适配器AdapterMap
        public const int XC_LAYOUT_LISTVIEW = 111;// '
        public const int XC_LAYOUT_LIST = 112;// '
        public const int XC_LAYOUT_OBJECT_GROUP = 113;// '
        public const int XC_LAYOUT_OBJECT_ITEM = 114;// '
        public const int XC_LAYOUT_PANEL = 115;// '
        public const int XC_BKINFOM = 116;// '
        public const int button_type_default = 0;// '///<默认类型
        public const int button_type_radio = 1;// '///<单选按钮
        public const int button_type_check = 2;// '///<复选按钮
        public const int button_type_close = 3;// '///<窗口关闭按钮
        public const int button_type_min = 4;// '///<窗口最小化按钮
        public const int button_type_max = 5;// '///<窗口最大化还原按钮
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
        public const int bkInfo_type_error = 0;// '
        public const int bkInfo_type_fill = 1;// '///<填充  old
        public const int bkInfo_type_border = 2;// '///<边框  old
        public const int bkInfo_type_image = 3;// '///<图片
        public const int bkInfo_type_triangle = 4;// '///<三角形
        public const int bkInfo_type_rectangle = 5;// '///<矩形
        public const int bkInfo_type_ellipse = 6;// '///<圆形
        public const int bkInfo_type_roundRect = 7;// '///<圆角矩形 --
        public const int bkInfo_type_group = 8;// '///<保留
        public const int bkInfo_type_ver = 9;// '///<保留
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
        public const int XWM_REDRAW_ELE = 28673;// '
        public const int XWM_WINDPROC = 28674;// '
        public const int XWM_DRAW_T = 28675;// '
        public const int XWM_TIMER_T = 28676;// '
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
        public const int XE_PAINT = 2;// '
        public const int XE_PAINT_SCROLLVIEW = 4;// '
        public const int XE_MOUSEMOVE = 5;// '
        public const int XC_ID_ERROR = -1;// '
        public const int XC_ID_FIRST = -2;// '
        public const int XC_ID_LAST = -3;// '

    }

}
