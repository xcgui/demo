#ifndef sxcgui_h__
#define sxcgui_h__

//2.1.2 2017-5-31 20:54:29 by 大色秘密

#include "Common.h"



enum XFUNCTION_TYPE
{
	ft_XDateTime_Create,
	ft_XDateTime_SetStyle,
	ft_XDateTime_GetStyle,
	ft_XDateTime_EnableSplitSlash,
	ft_XDateTime_GetTime,
	ft_XDateTime_SetTime,
	ft_XDateTime_GetDate,
	ft_XDateTime_SetDate,
	ft_XDateTime_GetSelBkColor,
	ft_XDateTime_SetSelBkColor,
	ft_XDateTime_GetButton,
	ft_XMonthCal_Create,
	ft_XMonthCal_SetToday,
	ft_XMonthCal_GetToday,
	ft_XMonthCal_SeSelDate,
	ft_XMonthCal_GetSelDate,
	ft_XMonthCal_GetButton,
	ft_XC_InitLua,
	ft_XC_RunLua,
	ft_XC_ExitLua,
	ft_XC_UnicodeToAnsi,
	ft_XC_AnsiToUnicode,
	ft_XC_DebugToFileInfo,
	ft_XC_IsHELE,
	ft_XC_IsHWINDOW,
	ft_XC_IsShape,
	ft_XC_IsHXCGUI,
	ft_XC_hWindowFromHWnd,
	ft_XC_SetProperty,
	ft_XC_GetProperty,
	ft_XC_RegisterWindowClassName,
	ft_XC_IsSViewExtend,
	ft_XC_GetObjectType,
	ft_XC_GetObjectByID,
	ft_XC_GetObjectByIDName,
	ft_XC_GetObjectByUID,
	ft_XC_GetObjectByUIDName,
	ft_XRes_GetIDValue,
	ft_XRes_GetImage,
	ft_XRes_GetImageEx,
	ft_XRes_GetColor,
	ft_XRes_GetFont,
	ft_XRes_GetBkM,
	ft_XC_SetPaintFrequency,
	ft_XC_SetTextRenderingHint,
	ft_XC_RectInRect,
	ft_XC_CombineRect,
	ft_XC_ShowLayoutFrame,
	ft_XC_EnableDebugFile,
	ft_XC_SetLayoutFrameColor,
	ft_XC_EnableErrorMessageBox,
	ft_XC_LoadLayout,
	ft_XC_LoadLayoutFromString,
	ft_XC_LoadResource,
	ft_XC_LoadResourceFromString,
	ft_XC_LoadStyle,
	ft_XC_GetTextSize,
	ft_XC_GetTextShowSize,
	ft_XC_GetDefaultFont,
	ft_XC_SetDefaultFont,
	ft_XC_InitFont,
	ft_XC_Malloc,
	ft_XC_Free,
	ft__XC_SetType,
	ft__XC_AddType,
	ft__XC_BindData,
	ft__XC_GetBindData,
	ft_XInitXCGUI,
	ft_XRunXCGUI,
	ft_XExitXCGUI,
	ft_XObj_GetType,
	ft_XObj_GetTypeEx,
	ft_XUI_SetStyle,
	ft_XUI_GetStyle,
	ft_XBkM_Create,
	ft_XBkM_Destroy,
	ft_XBkM_SetBkInfo,
	ft_XBkM_AddInfo,
	ft_XBkM_AddBorder,
	ft_XBkM_AddFill,
	ft_XBkM_AddImage,
	ft_XBkM_GetCount,
	ft_XBkM_Clear,
	ft_XBkM_Draw,
	ft_XBkM_DrawEx,
	ft_XBtn_Create,
	ft_XBtn_IsCheck,
	ft_XBtn_SetCheck,
	ft_XBtn_SetState,
	ft_XBtn_GetState,
	ft_XBtn_GetStateEx,
	ft_XBtn_SetStyle,
	ft_XBtn_GetStyle,
	ft_XBtn_SetType,
	ft_XBtn_SetTypeEx,
	ft_XBtn_GetType,
	ft_XBtn_SetGroupID,
	ft_XBtn_GetGroupID,
	ft_XBtn_SetBindEle,
	ft_XBtn_GetBindEle,
	ft_XBtn_SetTextAlign,
	ft_XBtn_GetTextAlign,
	ft_XBtn_SetIconAlign,
	ft_XBtn_SetOffset,
	ft_XBtn_SetOffsetIcon,
	ft_XBtn_SetIconSpace,
	ft_XBtn_GetText,
	ft_XBtn_SetText,
	ft_XBtn_SetIcon,
	ft_XBtn_SetIconDisable,
	ft_XBtn_GetIcon,
	ft_XBtn_AddAnimationFrame,
	ft_XBtn_EnableAnimation,
	ft_XBtn_AddBkBorder,
	ft_XBtn_AddBkFill,
	ft_XBtn_AddBkImage,
	ft_XBtn_GetBkInfoCount,
	ft_XBtn_ClearBkInfo,
	ft_XComboBox_Create,
	ft_XComboBox_SetSelItem,
	ft_XComboBox_GetButtonRect,
	ft_XComboBox_SetButtonSize,
	ft_XComboBox_SetDropHeight,
	ft_XComboBox_GetDropHeight,
	ft_XComboBox_BindApapter,
	ft_XComboBox_GetApapter,
	ft_XComboBox_SetItemTemplateXML,
	ft_XComboBox_SetItemTemplateXMLFromString,
	ft_XComboBox_EnableDrawButton,
	ft_XComboBox_EnableEdit,
	ft_XComboBox_EnableDropHeightFixed,
	ft_XComboBox_AddBkBorder,
	ft_XComboBox_AddBkFill,
	ft_XComboBox_AddBkImage,
	ft_XComboboX_GetBkInfoCount,
	ft_XComboBox_ClearBkInfo,
	ft_XComboBox_GetSelItem,
	ft_XComboBox_GetState,
	ft_XAd_Destroy,
	ft_XAdListView_Create,
	ft_XAdListView_Group_AddColumn,
	ft_XAdListView_Group_AddItemText,
	ft_XAdListView_Group_AddItemTextEx,
	ft_XAdListView_Group_AddItemImage,
	ft_XAdListView_Group_AddItemImageEx,
	ft_XAdListView_Group_SetText,
	ft_XAdListView_Group_SetTextEx,
	ft_XAdListView_Group_SetImage,
	ft_XAdListView_Group_SetImageEx,
	ft_XAdListView_Group_GetCount,
	ft_XAdListView_Item_GetCount,
	ft_XAdListView_Item_AddColumn,
	ft_XAdListView_Item_AddItemText,
	ft_XAdListView_Item_AddItemTextEx,
	ft_XAdListView_Item_AddItemImage,
	ft_XAdListView_Item_AddItemImageEx,
	ft_XAdListView_Item_SetText,
	ft_XAdListView_Item_SetTextEx,
	ft_XAdListView_Item_SetImage,
	ft_XAdListView_Item_SetImageEx,
	ft_XAdListView_Group_DeleteItem,
	ft_XAdListView_Group_DeleteAllChildItem,
	ft_XAdListView_Item_DeleteItem,
	ft_XAdListView_DeleteAll,
	ft_XAdListView_DeleteAllGroup,
	ft_XAdListView_DeleteAllItem,
	ft_XAdListView_DeleteColumnGroup,
	ft_XAdListView_DeleteColumnItem,
	ft_XAdListView_Item_GetTextEx,
	ft_XAdListView_Item_GetImageEx,
	ft_XAdTable_Create,
	ft_XAdTable_Sort,
	ft_XAdTable_GetItemDataType,
	ft_XAdTable_GetItemDataTypeEx,
	ft_XAdTable_AddColumn,
	ft_XAdTable_SetColumn,
	ft_XAdTable_AddItemText,
	ft_XAdTable_AddItemTextEx,
	ft_XAdTable_AddItemImage,
	ft_XAdTable_AddItemImageEx,
	ft_XAdTable_InsertItemText,
	ft_XAdTable_InsertItemTextEx,
	ft_XAdTable_InsertItemImage,
	ft_XAdTable_InsertItemImageEx,
	ft_XAdTable_SetItemText,
	ft_XAdTable_SetItemTextEx,
	ft_XAdTable_SetItemInt,
	ft_XAdTable_SetItemIntEx,
	ft_XAdTable_SetItemFloat,
	ft_XAdTable_SetItemFloatEx,
	ft_XAdTable_SetItemImage,
	ft_XAdTable_SetItemImageEx,
	ft_XAdTable_DeleteItem,
	ft_XAdTable_DeleteItemEx,
	ft_XAdTable_DeleteItemAll,
	ft_XAdTable_DeleteColumnAll,
	ft_XAdTable_GetCount,
	ft_XAdTable_GetCountColumn,
	ft_XAdTable_GetItemText,
	ft_XAdTable_GetItemTextEx,
	ft_XAdTable_GetItemImage,
	ft_XAdTable_GetItemImageEx,
	ft_XAdTable_GetItemInt,
	ft_XAdTable_GetItemIntEx,
	ft_XAdTable_GetItemFloat,
	ft_XAdTable_GetItemFloatEx,
	ft_XAdTree_Create,
	ft_XAdTree_AddColumn,
	ft_XAdTree_SetColumn,
	ft_XAdTree_InsertItemText,
	ft_XAdTree_InsertItemTextEx,
	ft_XAdTree_InsertItemImage,
	ft_XAdTree_InsertItemImageEx,
	ft_XAdTree_GetCount,
	ft_XAdTree_GetCountColumn,
	ft_XAdTree_SetItemText,
	ft_XAdTree_SetItemTextEx,
	ft_XAdTree_SetItemImage,
	ft_XAdTree_SetItemImageEx,
	ft_XAdTree_GetItemText,
	ft_XAdTree_GetItemImage,
	ft_XAdTree_GetItemTextEx,
	ft_XAdTree_GetItemImageEx,
	ft_XAdTree_DeleteItem,
	ft_XAdTree_DeleteItemAll,
	ft_XAdTree_DeleteColumnAll,
	ft_XAdMap_Create,
	ft_XAdMap_AddItemText,
	ft_XAdMap_AddItemImage,
	ft_XAdMap_DeleteItem,
	ft_XAdMap_GetCount,
	ft_XAdMap_GetItemText,
	ft_XAdMap_GetItemImage,
	ft_XAdMap_SetItemText,
	ft_XAdMap_SetItemImage,
	ft__XC_DebugPrintf,
	ft__XC_DebugPrintfW,
	ft_xtrace,
	ft_xtracew,
	ft_XDraw_Create,
	ft_XDraw_Destroy,
	ft_XDraw_SetOffset,
	ft_XDraw_GetOffset,
	ft_XDraw_RestoreGDIOBJ,
	ft_XDraw_GetHDC,
	ft_XDraw_SetBrushColor,
	ft_XDraw_SetTextAlign,
	ft_XDraw_SetTextVertical,
	ft_XDraw_SetFontX,
	ft_XDraw_SetLineWidth,
	ft_XDraw_SetBkMode,
	ft_XDraw_SetClipRect,
	ft_XDraw_ClearClip,
	ft_XDraw_EnableSmoothingMode,
	ft_XDraw_CreateSolidBrush,
	ft_XDraw_CreatePen,
	ft_XDraw_CreateRectRgn,
	ft_XDraw_CreateRoundRectRgn,
	ft_XDraw_CreatePolygonRgn,
	ft_XDraw_SelectClipRgn,
	ft_XDraw_FillRect,
	ft_XDraw_FillRectColor,
	ft_XDraw_FillRgn,
	ft_XDraw_FillEllipse,
	ft_XDraw_DrawEllipse,
	ft_XDraw_FillRoundRect,
	ft_XDraw_DrawRoundRect,
	ft_XDraw_FillRoundRectEx,
	ft_XDraw_DrawRoundRectEx,
	ft_XDraw_Rectangle,
	ft_XDraw_DrawGroupBox_Rect,
	ft_XDraw_DrawGroupBox_RoundRect,
	ft_XDraw_GradientFill2,
	ft_XDraw_GradientFill4,
	ft_XDraw_FrameRgn,
	ft_XDraw_FrameRect,
	ft_XDraw_FocusRect,
	ft_XDraw_DrawLine,
	ft_XDraw_MoveToEx,
	ft_XDraw_LineTo,
	ft_XDraw_Polyline,
	ft_XDraw_Dottedline,
	ft_XDraw_SetPixel,
	ft_XDraw_Check,
	ft_XDraw_DrawIconEx,
	ft_XDraw_BitBlt,
	ft_XDraw_BitBlt2,
	ft_XDraw_AlphaBlend,
	ft_XDraw_TriangularArrow,
	ft_XDraw_DrawPolygon,
	ft_XDraw_DrawPolygonF,
	ft_XDraw_FillPolygon,
	ft_XDraw_FillPolygonF,
	ft_XDraw_Image,
	ft_XDraw_Image2,
	ft_XDraw_ImageStretch,
	ft_XDraw_ImageAdaptive,
	ft_XDraw_ImageExTile,
	ft_XDraw_ImageSuper,
	ft_XDraw_ImageSuper2,
	ft_XDraw_DrawText,
	ft_XDraw_DrawTextUnderline,
	ft_XDraw_TextOut,
	ft_XDraw_TextOutEx,
	ft_XDraw_TextOutA,
	ft_XDraw_SetAlpha,
	ft_XDraw_SetAlphaEx,
	ft_XEle_Create,
	ft__XEle_RegEvent,
	ft__XEle_RemoveEvent,
	ft_XEle_RegEventC,
	ft_XEle_RegEventC1,
	ft_XEle_RegEventC2,
	ft_XEle_RemoveEventC,
	ft_XEle_SendEvent,
	ft_XEle_PostEvent,
	ft_XEle_IsShow,
	ft_XEle_IsEnable,
	ft_XEle_IsEnableFocus,
	ft_XEle_IsDrawFocus,
	ft_XEle_IsEnableEvent_XE_PAINT_END,
	ft_XEle_IsMouseThrough,
	ft_XEle_IsBkTransparent,
	ft_XEle_IsKeyTab,
	ft_XEle_IsSwitchFocus,
	ft_XEle_IsEnable_XE_MOUSEWHEEL,
	ft_XEle_IsInScrollView,
	ft_XEle_Enable,
	ft_XEle_EnableFocus,
	ft_XEle_EnableDrawFocus,
	ft_XEle_EnableDrawBorder,
	ft_XEle_EnableEvent_XE_PAINT_END,
	ft_XEle_EnableBkTransparent,
	ft_XEle_EnableMouseThrough,
	ft_XEle_EnableKeyTab,
	ft_XEle_EnableSwitchFocus,
	ft_XEle_EnableEvent_XE_MOUSEWHEEL,
	ft_XEle_EnableInScrollView,
	ft_XEle_SetRect,
	ft_XEle_SetRectEx,
	ft_XEle_SetRectLogic,
	ft_XEle_GetRect,
	ft_XEle_GetRectLogic,
	ft_XEle_GetClientRect,
	ft_XEle_GetWndClientRect,
	ft_XEle_GetWidth,
	ft_XEle_GetHeight,
	ft_XEle_RectWndClientToEleClient,
	ft_XEle_PointWndClientToEleClient,
	ft_XEle_RectClientToWndClient,
	ft_XEle_PointClientToWndClient,
	ft_XEle_AddEle,
	ft_XEle_InsertEle,
	ft_XEle_RemoveEle,
	ft_XEle_AddShape,
	ft_XEle_SetZOrder,
	ft_XEle_SetZOrderEx,
	ft_XEle_GetZOrder,
	ft_XEle_SetTopmost,
	ft_XEle_EnableCSS,
	ft_XEle_SetCssName,
	ft_XEle_GetCssName,
	ft_XEle_ShowEle,
	ft_XEle_GetType,
	ft_XEle_GetHWND,
	ft_XEle_GetHWINDOW,
	ft_XEle_SetCursor,
	ft_XEle_GetCursor,
	ft_XEle_SetID,
	ft_XEle_GetID,
	ft_XEle_SetUID,
	ft_XEle_GetUID,
	ft_XEle_GetParentEle,
	ft_XEle_GetParent,
	ft_XEle_SetTextColor,
	ft_XEle_GetTextColor,
	ft_XEle_SetFocusBorderColor,
	ft_XEle_GetFocusBorderColor,
	ft_XEle_SetFont,
	ft_XEle_GetFont,
	ft_XEle_SetAlpha,
	ft_XEle_GetChildCount,
	ft_XEle_GetChildByIndex,
	ft_XEle_GetChildByID,
	ft_XEle_GetChildShapeCount,
	ft_XEle_GetChildShapeByIndex,
	ft_XEle_SetBorderSize,
	ft_XEle_GetBorderSize,
	ft_XEle_SetPadding,
	ft_XEle_GetPadding,
	ft_XEle_HitChildEle,
	ft_XEle_BindLayoutObject,
	ft_XEle_GetLayoutObject,
	ft_XEle_GetParentLayoutObject,
	ft_XEle_SetUserData,
	ft_XEle_GetUserData,
	ft_XEle_GetContentSize,
	ft_XEle_SetCapture,
	ft_XEle_SetLayoutWidth,
	ft_XEle_SetLayoutHeight,
	ft_XEle_GetLayoutWidth,
	ft_XEle_GetLayoutHeight,
	ft_XEle_RedrawEle,
	ft_XEle_RedrawRect,
	ft_XEle_Destroy,
	ft_XEle_AddBkBorder,
	ft_XEle_AddBkFill,
	ft_XEle_AddBkImage,
	ft_XEle_GetBkInfoCount,
	ft_XEle_ClearBkInfo,
	ft_XEle_GetBkManager,
	ft_XEle_GetStateFlags,
	ft_XEle_DrawFocus,
	ft_XEle_DrawEle,
	ft_XEle_EnableTransparentChannel,
	ft_XEle_SetXCTimer,
	ft_XEle_KillXCTimer,
	ft_XEle_SetToolTip,
	ft_XEle_GetToolTip,
	ft_XEle_PopupToolTip,
	ft_XEle_AdjustLayoutObject,
	ft_XEle_AdjustLayout,
	ft_XEle_RegEventTest,
	ft_XFont_Create,
	ft_XFont_Create2,
	ft_XFont_Create3,
	ft_XFont_CreateEx,
	ft_XFont_CreateFromHFONT,
	ft_XFont_CreateFromFont,
	ft_XFont_CreateFromFile,
	ft_XFont_EnableAutoDestroy,
	ft_XFont_GetFont,
	ft_XFont_GetFontInfo,
	ft_XFont_AddRef,
	ft_XFont_Release,
	ft_XFont_GetRefCount,
	ft_XFont_Destroy,
	ft_XFrameWnd_Create,
	ft_XFrameWnd_CreateEx,
	ft_XFrameWnd_GetLayoutAreaRect,
	ft_XFrameWnd_SetView,
	ft_XFrameWnd_SetPaneSplitBarColor,
	ft_XFrameWnd_SaveLayoutToFile,
	ft_XFrameWnd_LoadLayoutFile,
	ft_XFrameWnd_AddPane,
	ft_XFrameWnd_MergePane,
	ft_XImage_LoadFile,
	ft_XImage_LoadFileAdaptive,
	ft_XImage_LoadFileRect,
	ft_XImage_LoadResAdaptive,
	ft_XImage_LoadRes,
	ft_XImage_LoadZip,
	ft_XImage_LoadZipAdaptive,
	ft_XImage_LoadZipRect,
	ft_XImage_LoadMemory,
	ft_XImage_LoadMemoryRect,
	ft_XImage_LoadMemoryAdaptive,
	ft_XImage_LoadFromImage,
	ft_XImage_LoadFileFromExtractIcon,
	ft_XImage_LoadFileFromHICON,
	ft_XImage_LoadFileFromHBITMAP,
	ft_XImage_IsStretch,
	ft_XImage_IsAdaptive,
	ft_XImage_IsTile,
	ft_XImage_SetDrawType,
	ft_XImage_SetDrawTypeAdaptive,
	ft_XImage_SetTranColor,
	ft_XImage_SetTranColorEx,
	ft_XImage_SetRotateAngle,
	ft_XImage_EnableTranColor,
	ft_XImage_EnableAutoDestroy,
	ft_XImage_EnableCenter,
	ft_XImage_IsCenter,
	ft_XImage_GetDrawType,
	ft_XImage_GetWidth,
	ft_XImage_GetHeight,
	ft_XImage_AddRef,
	ft_XImage_Release,
	ft_XImage_GetRefCount,
	ft_XImage_Destroy,
	ft_XLayout_Create,
	ft_XLayout_Destroy,
	ft_XLayout_AddEle,
	ft_XLayout_AddLayoutObject,
	ft_XLayout_AddShape,
	ft_XLayout_Add,
	ft_XLayout_Insert,
	ft_XLayout_RemoveLayout,
	ft_XLayout_RemoveChild,
	ft_XLayout_GetZOrder,
	ft_XLayout_AdjustLayout,
	ft_XLayout_SetRectFrame,
	ft_XLayout_GetRect,
	ft_XLayout_GetRectFrame,
	ft_XLayout_GetWindow,
	ft_XLayout_GetEle,
	ft_XLayout_GetParentLayout,
	ft_XLayout_GetParent,
	ft_XLayout_SetID,
	ft_XLayout_GetID,
	ft_XLayout_SetUID,
	ft_XLayout_GetUID,
	ft_XLayout_SetHorizon,
	ft_XLayout_SetAlignH,
	ft_XLayout_SetAlignV,
	ft_XLayout_SetPadding,
	ft_XLayout_SetSpace,
	ft_XLayout_SetLayoutWidth,
	ft_XLayout_SetLayoutHeight,
	ft_XLayout_GetLayoutWidth,
	ft_XLayout_GetLayoutHeight,
	ft_XLayout_GetWidth,
	ft_XLayout_GetHeight,
	ft_XLayout_GetWidthIn,
	ft_XLayout_GetHeightIn,
	ft_XLayout_GetContentSize,
	ft_XLayout_ShowLayout,
	ft_XLayout_GetChildCount,
	ft_XLayout_GetChildType,
	ft_XLayout_GetChild,
	ft_XLayout_Draw,
	ft_Layout_SetEle,
	ft_XListBox_Create,
	ft_XListBox_SetDrawItemBkFlags,
	ft_XListBox_SetItemData,
	ft_XListBox_GetItemData,
	ft_XListBox_SetItemInfo,
	ft_XListBox_GetItemInfo,
	ft_XListBox_AddItemBkBorder,
	ft_XListBox_AddItemBkFill,
	ft_XListBox_AddItemBkImage,
	ft_XListBox_GetItemBkInfoCount,
	ft_XListBox_ClearItemBkInfo,
	ft_XListBox_SetSelectItem,
	ft_XListBox_GetSelectItem,
	ft_XListBox_CancelSelectItem,
	ft_XListBox_CancelSelectAll,
	ft_XListBox_GetSelectAll,
	ft_XListBox_GetSelectCount,
	ft_XListBox_GetItemMouseStay,
	ft_XListBox_SelectAll,
	ft_XListBox_SetItemHeightDefault,
	ft_XListBox_GetItemHeightDefault,
	ft_XListBox_GetItemIndexFromHXCGUI,
	ft_XListBox_SetRowSpace,
	ft_XListBox_GetRowSpace,
	ft_XListBox_HitTest,
	ft_XListBox_HitTestOffset,
	ft_XListBox_SetItemTemplateXML,
	ft_XListBox_SetItemTemplateXMLFromString,
	ft_XListBox_GetTemplateObject,
	ft_XListBox_EnableMultiSel,
	ft_XListBox_CreateAdapter,
	ft_XListBox_BindAdapter,
	ft_XListBox_GetAdapter,
	ft_XListBox_Sort,
	ft_XListBox_RefreshData,
	ft_XListBox_RefreshItem,
	ft_XTemp_Load,
	ft_XTemp_LoadFromString,
	ft_XTemp_Destroy,
	ft_XTemp_Create,
	ft_XTemp_AddNodeRoot,
	ft_XTemp_AddNode,
	ft_XTemp_CreateNode,
	ft_XTemp_SetNodeAttribute,
	ft_XList_Create,
	ft_XList_AddColumn,
	ft_XList_InsertColumn,
	ft_XList_EnableMultiSel,
	ft_XList_EnableDragChangeColumnWidth,
	ft_XList_EnableVScrollBarTop,
	ft_XList_EnableItemBkFullRow,
	ft_XList_SetSort,
	ft_XList_SetDrawItemBkFlags,
	ft_XList_SetColumnWidth,
	ft_XList_SetColumnMinWidth,
	ft_XList_SetColumnWidthFixed,
	ft_XList_GetColumnWidth,
	ft_XList_GetColumnCount,
	ft_XList_DeleteColumn,
	ft_XList_DeleteColumnAll,
	ft_XList_SetItemData,
	ft_XList_GetItemData,
	ft_XList_SetSelectItem,
	ft_XList_GetSelectItem,
	ft_XList_GetSelectItemCount,
	ft_XList_SetSelectAll,
	ft_XList_GetSelectAll,
	ft_XList_CancelSelectItem,
	ft_XList_CancelSelectAll,
	ft_XList_GetHeaderHELE,
	ft_XList_BindAdapter,
	ft_XList_BindAdapterHeader,
	ft_XList_CreateAdapter,
	ft_XList_CreateAdapterHeader,
	ft_XList_GetAdapter,
	ft_XList_GetAdapterHeader,
	ft_XList_SetItemTemplateXML,
	ft_XList_SetItemTemplateXMLFromString,
	ft_XList_GetTemplateObject,
	ft_XList_GetItemIndexFromHXCGUI,
	ft_XList_GetHeaderTemplateObject,
	ft_XList_GetHeaderItemIndexFromHXCGUI,
	ft_XList_SetHeaderHeight,
	ft_XList_GetHeaderHeight,
	ft_XList_AddItemBkBorder,
	ft_XList_AddItemBkFill,
	ft_XList_AddItemBkImage,
	ft_XList_GetItemBkInfoCount,
	ft_XList_ClearItemBkInfo,
	ft_XList_SetItemHeightDefault,
	ft_XList_GetItemHeightDefault,
	ft_XList_SetRowSpace,
	ft_XList_GetRowSpace,
	ft_XList_HitTest,
	ft_XList_HitTestOffset,
	ft_XList_RefreshData,
	ft_XList_RefreshItem,
	ft_XListView_Create,
	ft_XListView_CreateAdapter,
	ft_XListView_BindAdapter,
	ft_XListView_GetAdapter,
	ft_XListView_SetItemTemplateXML,
	ft_XListView_SetItemTemplateXMLFromString,
	ft_XListView_GetTemplateObject,
	ft_XListView_GetTemplateObjectGroup,
	ft_XListView_GetItemIDFromHXCGUI,
	ft_XListView_HitTest,
	ft_XListView_HitTestOffset,
	ft_XListView_EnableMultiSel,
	ft_XListView_SetDrawItemBkFlags,
	ft_XListView_SetSelectItem,
	ft_XListView_GetSelectItem,
	ft_XListView_GetSelectItemCount,
	ft_XListView_GetSelectItemAll,
	ft_XListView_SetSelectItemAll,
	ft_XListView_CancelSelectItemAll,
	ft_XListView_SetColumnSpace,
	ft_XListView_SetRowSpace,
	ft_XListView_SetAlignSizeLeft,
	ft_XListView_SetAlignSizeTop,
	ft_XListView_SetItemSize,
	ft_XListView_GetItemSize,
	ft_XListView_SetGroupHeight,
	ft_XListView_GetGroupHeight,
	ft_XListView_SetGroupUserData,
	ft_XListView_SetItemUserData,
	ft_XListView_GetGroupUserData,
	ft_XListView_GetItemUserData,
	ft_XListView_AddItemBkBorder,
	ft_XListView_AddItemBkFill,
	ft_XListView_AddItemBkImage,
	ft_XListView_GetItemBkInfoCount,
	ft_XListView_ClearItemBkInfo,
	ft_XListView_RefreshData,
	ft_XListView_RefreshItem,
	ft_XListView_ExpandGroup,
	ft_XMenuBar_Create,
	ft_XMenuBar_AddButton,
	ft_XMenuBar_SetButtonHeight,
	ft_XMenuBar_GetMenu,
	ft_XMenuBar_DeleteButton,
	ft_XMenu_Create,
	ft_XMenu_AddItem,
	ft_XMenu_AddItemIcon,
	ft_XMenu_InsertItem,
	ft_XMenu_InsertItemIcon,
	ft_XMenu_SetAutoDestroy,
	ft_XMenu_EnableDrawBackground,
	ft_XMenu_EnableDrawItem,
	ft_XMenu_Popup,
	ft_XMenu_DestroyMenu,
	ft_XMenu_CloseMenu,
	ft_XMenu_SetBkImage,
	ft_XMenu_SetItemText,
	ft_XMenu_GetItemText,
	ft_XMenu_GetItemTextLength,
	ft_XMenu_SetItemIcon,
	ft_XMenu_SetItemFlags,
	ft_XMenu_SetItemHeight,
	ft_XMenu_GetItemHeight,
	ft_XMenu_SetBorderColor,
	ft_XMenu_GetLeftWidth,
	ft_XMenu_GetLeftSpaceText,
	ft_XMenu_GetItemCount,
	ft_XMenu_SetItemCheck,
	ft_XMenu_IsItemCheck,
	ft_XModalWnd_Create,
	ft_XModalWnd_CreateEx,
	ft_XModalWnd_EnableAutoClose,
	ft_XModalWnd_EnableEscClose,
	ft_XModalWnd_DoModal,
	ft_XModalWnd_EndModal,
	ft_XPane_Create,
	ft_XPane_SetView,
	ft_XPane_IsShowPane,
	ft_XPane_SetSize,
	ft_XPane_GetState,
	ft_XPane_GetViewRect,
	ft_XPane_SetTitle,
	ft_XPane_GetTitle,
	ft_XPane_SetCaptionHeight,
	ft_XPane_GetCaptionHeight,
	ft_XPane_HidePane,
	ft_XPane_ShowPane,
	ft_XPane_DockPane,
	ft_XPane_LockPane,
	ft_XPane_FloatPane,
	ft_XFloatWnd_EnableCaptionContent,
	ft_XFloatWnd_GetCaptionLayout,
	ft_XFloatWnd_GetCaptionShapeText,
	ft_XFloatWnd_GetCaptionButtonClose,
	ft_XFloatWnd_SetTitle,
	ft_XFloatWnd_GetTitle,
	ft_XProgBar_Create,
	ft_XProgBar_SetRange,
	ft_XProgBar_GetRange,
	ft_XProgBar_SetSpaceTwo,
	ft_XProgBar_SetPos,
	ft_XProgBar_GetPos,
	ft_XProgBar_SetHorizon,
	ft_XProgBar_SetImageLoad,
	ft_XPGrid_Create,
	ft_XPGrid_AddItem,
	ft_XPGrid_AddItemString,
	ft_XPGrid_DeleteAll,
	ft_XPGrid_GetItemHELE,
	ft_XPGrid_SetWidth,
	ft_XPGrid_SetItemValue,
	ft_XPGrid_SetItemValueInt,
	ft_XPGrid_SetItemData,
	ft_XPGrid_GetItemData,
	ft_XPGrid_GetItemValue,
	ft_XPGrid_HitTest,
	ft_XPGrid_HitTestOffset,
	ft_XPGrid_ExpandItem,
	ft_XPGrid_GetSelItem,
	ft_XPGrid_SetSelItem,
	ft_XPGrid_SetDrawItemBkFlags,
	ft_XRichEditColor_Create,
	ft_XRichEditColor_SetColor,
	ft_XRichEditColor_GetColor,
	ft_XRichEditSet_Create,
	ft_XRichEditFile_Create,
	ft_XRichEditFile_SetOpenFileType,
	ft_XRichEditFile_SetDefaultFile,
	ft_XRichEditFile_SetRelativeDir,
	ft_XRichEditFolder_Create,
	ft_XRichEditFolder_SetDefaultDir,
	ft_XRichEdit_Create,
	ft_XRichEdit_InsertString,
	ft_XRichEdit_InsertImage,
	ft_XRichEdit_InsertGif,
	ft_XRichEdit_InsertStringEx,
	ft_XRichEdit_InsertImageEx,
	ft_XRichEdit_InsertGifEx,
	ft_XRichEdit_EnableReadOnly,
	ft_XRichEdit_EnableMultiLine,
	ft_XRichEdit_EnablePassword,
	ft_XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE,
	ft_XRichEdit_EnableAutoWrap,
	ft_XRichEdit_EnableAutoSelAll,
	ft_XRichEdit_EnableVerticalCenter,
	ft_XRichEdit_IsEmpty,
	ft_XRichEdit_IsReadOnly,
	ft_XRichEdit_IsMultiLine,
	ft_XRichEdit_IsPassword,
	ft_XRichEdit_IsAutoWrap,
	ft_XRichEdit_SetLimitNum,
	ft_XRichEdit_SetCaretColor,
	ft_XRichEdit_SetText,
	ft_XRichEdit_SetTextInt,
	ft_XRichEdit_GetText,
	ft_XRichEdit_GetHTMLFormat,
	ft_XRichEdit_GetData,
	ft_XRichEdit_InsertData,
	ft_XRichEdit_GetTextLength,
	ft_XRichEdit_SetRowHeight,
	ft_XRichEdit_SetDefaultText,
	ft_XRichEdit_SetDefaultTextColor,
	ft_XRichEdit_SetCurrentInputTextColor,
	ft_XRichEdit_GetCurrentRow,
	ft_XRichEdit_GetCurrentColumn,
	ft_XRichEdit_SetCurrentPos,
	ft_XRichEdit_GetRowCount,
	ft_XRichEdit_GetRowLength,
	ft_XRichEdit_GetSelectText,
	ft_XRichEdit_GetSelectPosition,
	ft_XRichEdit_SetSelect,
	ft_XRichEdit_SetItemFontEx,
	ft_XRichEdit_SetItemColorEx,
	ft_XRichEdit_CancelSelect,
	ft_XRichEdit_SetSelectBkColor,
	ft_XRichEdit_SelectAll,
	ft_XRichEdit_DeleteSelect,
	ft_XRichEdit_DeleteAll,
	ft_XRichEdit_ClipboardCut,
	ft_XRichEdit_ClipboardCopy,
	ft_XRichEdit_ClipboardPaste,
	ft_XSBar_Create,
	ft_XSBar_SetRange,
	ft_XSBar_GetRange,
	ft_XSBar_ShowButton,
	ft_XSBar_SetSliderLength,
	ft_XSBar_SetSliderMinLength,
	ft_XSBar_SetSliderPadding,
	ft_XSBar_SetHorizon,
	ft_XSBar_GetSliderMaxLength,
	ft_XSBar_ScrollUp,
	ft_XSBar_ScrollDown,
	ft_XSBar_ScrollTop,
	ft_XSBar_ScrollBottom,
	ft_XSBar_ScrollPos,
	ft_XSBar_GetButtonUp,
	ft_XSBar_GetButtonDown,
	ft_XSBar_GetButtonSlider,
	ft_XSView_Create,
	ft_XSView_SetTotalSize,
	ft_XSView_GetTotalSize,
	ft_XSView_SetLineSize,
	ft_XSView_GetLineSize,
	ft_XSView_SetScrollBarSize,
	ft_XSView_GetViewPosH,
	ft_XSView_GetViewPosV,
	ft_XSView_GetViewWidth,
	ft_XSView_GetViewHeight,
	ft_XSView_GetViewRect,
	ft_XSView_GetScrollBarH,
	ft_XSView_GetScrollBarV,
	ft_XSView_SetBorderSize,
	ft_XSView_GetBorderSize,
	ft_XSView_ScrollPosH,
	ft_XSView_ScrollPosV,
	ft_XSView_ScrollPosXH,
	ft_XSView_ScrollPosYV,
	ft_XSView_ShowSBarH,
	ft_XSView_ShowSBarV,
	ft_XSView_EnableAutoShowScrollBar,
	ft_XSView_ScrollLeftLine,
	ft_XSView_ScrollRightLine,
	ft_XSView_ScrollTopLine,
	ft_XSView_ScrollBottomLine,
	ft_XSView_ScrollLeft,
	ft_XSView_ScrollRight,
	ft_XSView_ScrollTop,
	ft_XSView_ScrollBottom,
	ft_XShape_GetParentEle,
	ft_XShape_GetParentLayout,
	ft_XShape_GetHWINDOW,
	ft_XShape_GetParent,
	ft_XShape_RemoveShape,
	ft_XShape_SetID,
	ft_XShape_GetID,
	ft_XShape_SetUID,
	ft_XShape_GetUID,
	ft_XShape_Redraw,
	ft_XShape_GetWidth,
	ft_XShape_GetHeight,
	ft_XShape_GetRect,
	ft_XShape_SetRect,
	ft_XShape_GetContentSize,
	ft_XShape_ShowLayout,
	ft_XShape_AdjustLayout,
	ft_XShape_Destroy,
	ft_XShapeText_Create,
	ft_XShapeText_SetText,
	ft_XShapeText_GetText,
	ft_XShapeText_GetTextLength,
	ft_XShapeText_SetFont,
	ft_XShapeText_GetFont,
	ft_XShapeText_SetTextColor,
	ft_XShapeText_GetTextColor,
	ft_XShapeText_SetTextAlign,
	ft_XShapeText_SetOffset,
	ft_XShapeText_SetLayoutWidth,
	ft_XShapeText_SetLayoutHeight,
	ft_XShapeText_GetLayoutWidth,
	ft_XShapeText_GetLayoutHeight,
	ft_XShapeText_EnableCSS,
	ft_XShapeText_SetCssName,
	ft_XShapeText_GetCssName,
	ft_XShapePic_Create,
	ft_XShapePic_SetImage,
	ft_XShapePic_SetLayoutWidth,
	ft_XShapePic_SetLayoutHeight,
	ft_XShapePic_GetLayoutWidth,
	ft_XShapePic_GetLayoutHeight,
	ft_XShapeGif_Create,
	ft_XShapeGif_SetImage,
	ft_XShapeGif_SetLayoutWidth,
	ft_XShapeGif_SetLayoutHeight,
	ft_XShapeGif_GetLayoutWidth,
	ft_XShapeGif_GetLayoutHeight,
	ft_XShapeRect_Create,
	ft_XShapeRect_SetBorderColor,
	ft_XShapeRect_SetFillColor,
	ft_XShapeRect_SetRoundAngle,
	ft_XShapeRect_GetRoundAngle,
	ft_XShapeRect_EnableBorder,
	ft_XShapeRect_EnableFill,
	ft_XShapeRect_EnableRoundAngle,
	ft_XShapeEllipse_Create,
	ft_XShapeEllipse_SetBorderColor,
	ft_XShapeEllipse_SetFillColor,
	ft_XShapeEllipse_EnableBorder,
	ft_XShapeEllipse_EnableFill,
	ft_XShapeGroupBox_Create,
	ft_XShapeGroupBox_SetBorderColor,
	ft_XShapeGroupBox_SetTextColor,
	ft_XShapeGroupBox_SetFontX,
	ft_XShapeGroupBox_SetTextOffset,
	ft_XShapeGroupBox_SetRoundAngle,
	ft_XShapeGroupBox_SetText,
	ft_XShapeGroupBox_GetTextOffset,
	ft_XShapeGroupBox_GetRoundAngle,
	ft_XShapeGroupBox_EnableRoundAngle,
	ft_XShapeLine_Create,
	ft_XShapeLine_SetPosition,
	ft_XShapeLine_SetColor,
	ft_XSliderBar_Create,
	ft_XSliderBar_SetRange,
	ft_XSliderBar_GetRange,
	ft_XSliderBar_SetButtonWidth,
	ft_XSliderBar_SetButtonHeight,
	ft_XSliderBar_SetSpaceTwo,
	ft_XSliderBar_SetPos,
	ft_XSliderBar_GetPos,
	ft_XSliderBar_GetButton,
	ft_XSliderBar_SetHorizon,
	ft_XSliderBar_SetImageLoad,
	ft_XTabBar_Create,
	ft_XTabBar_AddLabel,
	ft_XTabBar_InsertLabel,
	ft_XTabBar_DeleteLabel,
	ft_XTabBar_DeleteLabelAll,
	ft_XTabBar_GetLabel,
	ft_XTabBar_GetLabelClose,
	ft_XTabBar_GetButtonLeft,
	ft_XTabBar_GetButtonRight,
	ft_XTabBar_GetSelect,
	ft_XTabBar_GetLabelSpacing,
	ft_XTabBar_GetLabelCount,
	ft_XTabBar_GetindexByEle,
	ft_XTabBar_SetLabelSpacing,
	ft_XTabBar_SetPadding,
	ft_XTabBar_SetSelect,
	ft_XTabBar_SetUp,
	ft_XTabBar_SetDown,
	ft_XTabBar_EnableTile,
	ft_XTabBar_EnableClose,
	ft_XTabBar_SetCloseSize,
	ft_XTabBar_SetTurnButtonSize,
	ft_XTabBar_SetLabelWidth,
	ft_XTabBar_ShowLabel,
	ft_XTextLink_Create,
	ft_XTextLink_EnableUnderlineLeave,
	ft_XTextLink_EnableUnderlineStay,
	ft_XTextLink_SetTextColorStay,
	ft_XTextLink_SetUnderlineColorLeave,
	ft_XTextLink_SetUnderlineColorStay,
	ft_XToolBar_Create,
	ft_XToolBar_InsertEle,
	ft_XToolBar_InsertSeparator,
	ft_XToolBar_EnableButtonMenu,
	ft_XToolBar_GetHEle,
	ft_XToolBar_GetButtonLeft,
	ft_XToolBar_GetButtonRight,
	ft_XToolBar_GetButtonMenu,
	ft_XToolBar_SetSpace,
	ft_XToolBar_DeleteEle,
	ft_XToolBar_DeleteAllEle,
	ft_XTree_Create,
	ft_XTree_EnableDragItem,
	ft_XTree_EnableConnectLine,
	ft_XTree_EnableExpand,
	ft_XTree_SetConnectLineColor,
	ft_XTree_SetExpandButtonSize,
	ft_XTree_SetConnectLineLength,
	ft_XTree_SetDragInsertPositionColor,
	ft_XTree_SetItemTemplateXML,
	ft_XTree_SetItemTemplateXMLSel,
	ft_XTree_SetItemTemplateXMLFromString,
	ft_XTree_SetItemTemplateXMLSelFromString,
	ft_XTree_SetDrawItemBkFlags,
	ft_XTree_SetItemData,
	ft_XTree_GetItemData,
	ft_XTree_SetSelectItem,
	ft_XTree_GetSelectItem,
	ft_XTree_IsExpand,
	ft_XTree_ExpandItem,
	ft_XTree_ExpandAllChildItem,
	ft_XTree_HitTest,
	ft_XTree_HitTestOffset,
	ft_XTree_GetFirstChildItem,
	ft_XTree_GetEndChildItem,
	ft_XTree_GetPrevSiblingItem,
	ft_XTree_GetNextSiblingItem,
	ft_XTree_GetParentItem,
	ft_XTree_SetIndentation,
	ft_XTree_GetIndentation,
	ft_XTree_SetItemHeight,
	ft_XTree_GetItemHeight,
	ft_XTree_SetRowSpace,
	ft_XTree_GetRowSpace,
	ft_XTree_MoveItem,
	ft_XTree_AddItemBkBorder,
	ft_XTree_AddItemBkFill,
	ft_XTree_AddItemBkImage,
	ft_XTree_GetItemBkInfoCount,
	ft_XTree_ClearItemBkInfo,
	ft_XTree_SetItemHeightDefault,
	ft_XTree_GetItemHeightDefault,
	ft_XTree_GetTemplateObject,
	ft_XTree_GetItemIDFromHXCGUI,
	ft_XTree_CreateAdapter,
	ft_XTree_BindAdapter,
	ft_XTree_GetAdapter,
	ft_XTree_RefreshData,
	ft_XTree_RefreshItem,
	ft__XWnd_RegEvent,
	ft__XWnd_RemoveEvent,
	ft_XWnd_RegEventC,
	ft_XWnd_RegEventC1,
	ft_XWnd_RemoveEventC,
	ft_XWnd_Create,
	ft_XWnd_CreateEx,
	ft_XWnd_AddEle,
	ft_XWnd_InsertEle,
	ft_XWnd_AddShape,
	ft_XWnd_GetHWND,
	ft_XWnd_EnableDragBorder,
	ft_XWnd_EnableDragWindow,
	ft_XWnd_EnableDragCaption,
	ft_XWnd_EnableDrawBk,
	ft_XWnd_EnableAutoFocus,
	ft_XWnd_EnableMaxWindow,
	ft_XWnd_RedrawWnd,
	ft_XWnd_RedrawWndRect,
	ft_XWnd_SetFocusEle,
	ft_XWnd_GetFocusEle,
	ft_XWnd_GetStayHELE,
	ft_XWnd_DrawWindow,
	ft_XWnd_SetCursor,
	ft_XWnd_GetCursor,
	ft_XWnd_SetCursorSys,
	ft_XWnd_SetFont,
	ft_XWnd_SetTextColor,
	ft_XWnd_GetTextColor,
	ft_XWnd_SetID,
	ft_XWnd_GetID,
	ft_XWnd_SetCaptureEle,
	ft_XWnd_GetCaptureEle,
	ft_XWnd_BindLayoutEle,
	ft_XWnd_GetLayoutEle,
	ft_XWnd_BindLayoutObject,
	ft_XWnd_GetLayoutObject,
	ft_XWnd_SetLayoutSize,
	ft_XWnd_GetLayoutSize,
	ft_XWnd_SetDragBorderSize,
	ft_XWnd_GetDragBorderSize,
	ft_XWnd_SetMinimumSize,
	ft_XWnd_HitChildEle,
	ft_XWnd_GetChildCount,
	ft_XWnd_GetChildByIndex,
	ft_XWnd_GetChildByID,
	ft_XWnd_GetEle,
	ft_XWnd_GetChildShapeCount,
	ft_XWnd_GetChildShapeByIndex,
	ft_XWnd_GetDrawRect,
	ft_XWnd_ShowWindow,
	ft_XWnd_AdjustLayout,
	ft_XWnd_AdjustLayoutObject,
	ft_XWnd_CloseWindow,
	ft_XWnd_CreateCaret,
	ft_XWnd_SetCaretSize,
	ft_XWnd_SetCaretPos,
	ft_XWnd_SetCaretPosEx,
	ft_XWnd_SetCaretColor,
	ft_XWnd_ShowCaret,
	ft_XWnd_DestroyCaret,
	ft_XWnd_GetCaretHELE,
	ft_XWnd_GetClientRect,
	ft_XWnd_GetBodyRect,
	ft_XWnd_SetTimer,
	ft_XWnd_KillTimer,
	ft_XWnd_SetXCTimer,
	ft_XWnd_KillXCTimer,
	ft_XWnd_GetBkManager,
	ft_XWnd_SetTransparentType,
	ft_XWnd_SetTransparentAlpha,
	ft_XWnd_SetTransparentColor,
	ft_XWnd_SetShadowInfo,
	ft_XWnd_GetTransparentType,
	ft_XWnd_EnableCSS,
	ft_XWnd_SetCssName,
	ft_XWnd_GetCssName,
	ft_XWnd_RegEventTest,
	ft_XEle_IsChildEle,
	ft_XWnd_GetShadowInfo,
};




typedef int XP;

typedef struct _XCONTROL
{
	XFUNCTION_TYPE nType;
	XP nRet;   //保存着返回值
	XP p1;
	XP p2;
	XP p3;
	XP p4;
	XP p5;
	XP p6;
	XP p7;
	XP p8;
	XP p9;
	XP p10;
	XP p11;
}XCONTROL,*PXCONTROL;

#define XWM_CONTROL WM_USER+0x10000
#define XP_Init()     XCONTROL ct;
#define XP_SetType(ct,k) ct.nType = k
#define XP_Set1(ct,k)    ct.p1 = (int)k
#define XP_Set2(ct,k)    ct.p2 = (int)k
#define XP_Set3(ct,k)    ct.p3 = (int)k
#define XP_Set4(ct,k)    ct.p4 = (int)k
#define XP_Set5(ct,k)    ct.p5 = (int)k
#define XP_Set6(ct,k)    ct.p6 = (int)k
#define XP_Set7(ct,k)    ct.p7 = (int)k
#define XP_Set8(ct,k)    ct.p8 = (int)k
#define XP_Set9(ct,k)    ct.p9 = (int)k
#define XP_Set10(ct,k)   ct.p10 = (int)k
#define XP_Set11(ct,k)   ct.p11 = (int)k
#define XP_GetRet(ct)    ct.nRet
#define XP_CALL(hWindow,ct) SendMessageW(XWnd_GetHWND(hWindow),XWM_CONTROL,(WPARAM)&ct,(LPARAM)sizeof(ct))


VOID WINAPI SXWnd_EnableSafeFunction(HWINDOW hWindow);


HELE WINAPI SXDateTime_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXDateTime_SetStyle(HWINDOW hWindow,HELE hEle,int nStyle);
int WINAPI SXDateTime_GetStyle(HWINDOW hWindow,HELE hEle);
void WINAPI SXDateTime_EnableSplitSlash(HWINDOW hWindow,HELE hEle,BOOL bSlash);
void WINAPI SXDateTime_GetTime(HWINDOW hWindow,HELE hEle,int* pnHour,int* pnMinute,int* pnSecond);
void WINAPI SXDateTime_SetTime(HWINDOW hWindow,HELE hEle,int nHour,int nMinute,int nSecond);
void WINAPI SXDateTime_GetDate(HWINDOW hWindow,HELE hEle,int* pnYear,int* pnMonth,int* pnDay);
void WINAPI SXDateTime_SetDate(HWINDOW hWindow,HELE hEle,int nYear,int nMonth,int nDay);
COLORREF WINAPI SXDateTime_GetSelBkColor(HWINDOW hWindow,HELE hEle);
void WINAPI SXDateTime_SetSelBkColor(HWINDOW hWindow,HELE hEle,COLORREF crSelectBk,BYTE alpha);
HELE WINAPI SXDateTime_GetButton(HWINDOW hWindow,HELE hEle,int nType);
HELE WINAPI SXMonthCal_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXMonthCal_SetToday(HWINDOW hWindow,HELE hEle,int nYear,int nMonth,int nDay);
void WINAPI SXMonthCal_GetToday(HWINDOW hWindow,HELE hEle,int* pnYear,int* pnMonth,int* pnDay);
void WINAPI SXMonthCal_SeSelDate(HWINDOW hWindow,HELE hEle,int nYear,int nMonth,int nDay);
void WINAPI SXMonthCal_GetSelDate(HWINDOW hWindow,HELE hEle,int* pnYear,int* pnMonth,int* pnDay);
HELE WINAPI SXMonthCal_GetButton(HWINDOW hWindow,HELE hEle,monthCal_button_type_ nType);
lua_State* WINAPI SXC_InitLua(HWINDOW hWindow);
BOOL WINAPI SXC_RunLua(HWINDOW hWindow,const char* pLuaFile);
BOOL WINAPI SXC_ExitLua(HWINDOW hWindow);
int WINAPI SXC_UnicodeToAnsi(HWINDOW hWindow,const wchar_t * pIn,int inLen,char * pOut,int outLen);
int WINAPI SXC_AnsiToUnicode(HWINDOW hWindow,const char * pIn,int inLen,wchar_t * pOut,int outLen);
void WINAPI SXC_DebugToFileInfo(HWINDOW hWindow,const char * pInfo);
BOOL WINAPI SXC_IsHELE(HWINDOW hWindow,HXCGUI hEle);
BOOL WINAPI SXC_IsHWINDOW(HWINDOW hWindow,HXCGUI hXCGUI);
BOOL WINAPI SXC_IsShape(HWINDOW hWindow,HXCGUI hShape);
BOOL WINAPI SXC_IsHXCGUI(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_TYPE nType);
HWINDOW WINAPI SXC_hWindowFromHWnd(HWINDOW hWindow,HWND hWnd);
BOOL WINAPI SXC_SetProperty(HWINDOW hWindow,HXCGUI hXCGUI,const wchar_t* pName,const wchar_t* pValue);
const wchar_t* WINAPI SXC_GetProperty(HWINDOW hWindow,HXCGUI hXCGUI,const wchar_t* pName);
BOOL WINAPI SXC_RegisterWindowClassName(HWINDOW hWindow,const wchar_t* pClassName);
BOOL WINAPI SXC_IsSViewExtend(HWINDOW hWindow,HELE hEle);
XC_OBJECT_TYPE WINAPI SXC_GetObjectType(HWINDOW hWindow,HXCGUI hXCGUI);
HXCGUI WINAPI SXC_GetObjectByID(HWINDOW hWindow,int nID);
HXCGUI WINAPI SXC_GetObjectByIDName(HWINDOW hWindow,const wchar_t* pName);
HXCGUI WINAPI SXC_GetObjectByUID(HWINDOW hWindow,int nUID);
HXCGUI WINAPI SXC_GetObjectByUIDName(HWINDOW hWindow,const wchar_t* pName);
int WINAPI SXRes_GetIDValue(HWINDOW hWindow,const wchar_t * pName);
HIMAGE WINAPI SXRes_GetImage(HWINDOW hWindow,const wchar_t * pName);
HIMAGE WINAPI SXRes_GetImageEx(HWINDOW hWindow,const wchar_t * pFileName,const wchar_t * pName);
COLORREF WINAPI SXRes_GetColor(HWINDOW hWindow,const wchar_t * pName);
HFONTX WINAPI SXRes_GetFont(HWINDOW hWindow,const wchar_t * pName);
HBKM WINAPI SXRes_GetBkM(HWINDOW hWindow,const wchar_t * pName);
void WINAPI SXC_SetPaintFrequency(HWINDOW hWindow,int nMilliseconds);
void WINAPI SXC_SetTextRenderingHint(HWINDOW hWindow,int nType);
BOOL WINAPI SXC_RectInRect(HWINDOW hWindow,RECT * pRect1,RECT * pRect2);
void WINAPI SXC_CombineRect(HWINDOW hWindow,RECT * pDest,RECT * pSrc1,RECT * pSrc2);
void WINAPI SXC_ShowLayoutFrame(HWINDOW hWindow,BOOL bShow);
void WINAPI SXC_EnableDebugFile(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXC_SetLayoutFrameColor(HWINDOW hWindow,COLORREF color);
void WINAPI SXC_EnableErrorMessageBox(HWINDOW hWindow,BOOL bEnabel);
HXCGUI WINAPI SXC_LoadLayout(HWINDOW hWindow,const wchar_t * pFileName,HXCGUI hParent);
HXCGUI WINAPI SXC_LoadLayoutFromString(HWINDOW hWindow,const char * pStringXML,HXCGUI hParent);
BOOL WINAPI SXC_LoadResource(HWINDOW hWindow,const wchar_t * pFileName,const wchar_t * pDir);
BOOL WINAPI SXC_LoadResourceFromString(HWINDOW hWindow,const char * pStringXML,const wchar_t* pFileName,const wchar_t * pDir);
BOOL WINAPI SXC_LoadStyle(HWINDOW hWindow,const wchar_t * pFileName,const wchar_t * pDir);
void WINAPI SXC_GetTextSize(HWINDOW hWindow,const wchar_t* pString,int length,HFONTX hFontX,out_ SIZE* pOutSize);
void WINAPI SXC_GetTextShowSize(HWINDOW hWindow,const wchar_t* pString,int length,HFONTX hFontX,out_ SIZE* pOutSize);
HFONTX WINAPI SXC_GetDefaultFont(HWINDOW hWindow);
void WINAPI SXC_SetDefaultFont(HWINDOW hWindow,HFONTX hFontX);
void WINAPI SXC_InitFont(HWINDOW hWindow,LOGFONTW * pFont,wchar_t * pName,int size,BOOL bBold,BOOL bItalic,BOOL bUnderline,BOOL bStrikeOut);
void* WINAPI SXC_Malloc(HWINDOW hWindow,int size);
void WINAPI SXC_Free(HWINDOW hWindow,void * p);
void WINAPI S_XC_SetType(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_TYPE nType);
void WINAPI S_XC_AddType(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_TYPE nType);
void WINAPI S_XC_BindData(HWINDOW hWindow,HXCGUI hXCGUI,int data);
int WINAPI S_XC_GetBindData(HWINDOW hWindow,HXCGUI hXCGUI);
BOOL WINAPI SXInitXCGUI(HWINDOW hWindow,wchar_t * pText);
void WINAPI SXRunXCGUI(HWINDOW hWindow);
void WINAPI SXExitXCGUI(HWINDOW hWindow);
XC_OBJECT_TYPE WINAPI SXObj_GetType(HWINDOW hWindow,HXCGUI hXCGUI);
XC_OBJECT_TYPE_EX WINAPI SXObj_GetTypeEx(HWINDOW hWindow,HXCGUI hXCGUI);
void WINAPI SXUI_SetStyle(HWINDOW hWindow,HXCGUI hXCGUI,XC_OBJECT_STYLE nStyle);
XC_OBJECT_STYLE WINAPI SXUI_GetStyle(HWINDOW hWindow,HXCGUI hXCGUI);
HBKM WINAPI SXBkM_Create(HWINDOW hWindow);
void WINAPI SXBkM_Destroy(HWINDOW hWindow,HBKM hBkInfoM);
int WINAPI SXBkM_SetBkInfo(HWINDOW hWindow,HBKM hBkInfoM,const wchar_t * pText);
int WINAPI SXBkM_AddInfo(HWINDOW hWindow,HBKM hBkInfoM,const wchar_t * pText);
void WINAPI SXBkM_AddBorder(HWINDOW hWindow,HBKM hBkInfoM,int nState,COLORREF color,BYTE alpha,int width);
void WINAPI SXBkM_AddFill(HWINDOW hWindow,HBKM hBkInfoM,int nState,COLORREF color,BYTE alpha);
void WINAPI SXBkM_AddImage(HWINDOW hWindow,HBKM hBkInfoM,int nState,HIMAGE hImage);
int WINAPI SXBkM_GetCount(HWINDOW hWindow,HBKM hBkInfoM);
void WINAPI SXBkM_Clear(HWINDOW hWindow,HBKM hBkInfoM);
BOOL WINAPI SXBkM_Draw(HWINDOW hWindow,HBKM hBkInfoM,int nState,HDRAW hDraw,RECT* pRect);
BOOL WINAPI SXBkM_DrawEx(HWINDOW hWindow,HBKM hBkInfoM,int nState,HDRAW hDraw,RECT* pRect,int nStateFilter);
HELE WINAPI SXBtn_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pName,HXCGUI hParent);
BOOL WINAPI SXBtn_IsCheck(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXBtn_SetCheck(HWINDOW hWindow,HELE hEle,BOOL bCheck);
void WINAPI SXBtn_SetState(HWINDOW hWindow,HELE hEle,common_state3_ nState);
common_state3_ WINAPI SXBtn_GetState(HWINDOW hWindow,HELE hEle);
button_state_ WINAPI SXBtn_GetStateEx(HWINDOW hWindow,HELE hEle);
void WINAPI SXBtn_SetStyle(HWINDOW hWindow,HELE hEle,XC_OBJECT_STYLE nStyle);
XC_OBJECT_STYLE WINAPI SXBtn_GetStyle(HWINDOW hWindow,HELE hEle);
void WINAPI SXBtn_SetType(HWINDOW hWindow,HELE hEle,XC_OBJECT_TYPE_EX nType);
void WINAPI SXBtn_SetTypeEx(HWINDOW hWindow,HELE hEle,XC_OBJECT_TYPE_EX nType);
XC_OBJECT_TYPE_EX WINAPI SXBtn_GetType(HWINDOW hWindow,HELE hEle);
void WINAPI SXBtn_SetGroupID(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXBtn_GetGroupID(HWINDOW hWindow,HELE hEle);
void WINAPI SXBtn_SetBindEle(HWINDOW hWindow,HELE hEle,HELE hBindEle);
HELE WINAPI SXBtn_GetBindEle(HWINDOW hWindow,HELE hEle);
void WINAPI SXBtn_SetTextAlign(HWINDOW hWindow,HELE hEle,int nFlags);
int WINAPI SXBtn_GetTextAlign(HWINDOW hWindow,HELE hEle);
void WINAPI SXBtn_SetIconAlign(HWINDOW hWindow,HELE hEle,button_icon_align_ align);
void WINAPI SXBtn_SetOffset(HWINDOW hWindow,HELE hEle,int x,int y);
void WINAPI SXBtn_SetOffsetIcon(HWINDOW hWindow,HELE hEle,int x,int y);
void WINAPI SXBtn_SetIconSpace(HWINDOW hWindow,HELE hEle,int size);
void WINAPI SXBtn_GetText(HWINDOW hWindow,HELE hEle,out_ wchar_t * pOut,int nOutLen);
void WINAPI SXBtn_SetText(HWINDOW hWindow,HELE hEle,in_ const wchar_t * pName);
void WINAPI SXBtn_SetIcon(HWINDOW hWindow,HELE hEle,HIMAGE hImage);
void WINAPI SXBtn_SetIconDisable(HWINDOW hWindow,HELE hEle,HIMAGE hImage);
HIMAGE WINAPI SXBtn_GetIcon(HWINDOW hWindow,HELE hEle,int nType);
void WINAPI SXBtn_AddAnimationFrame(HWINDOW hWindow,HELE hEle,HIMAGE hImage,UINT uElapse);
void WINAPI SXBtn_EnableAnimation(HWINDOW hWindow,HELE hEle,BOOL bEnable,BOOL bLoopPlay);
void WINAPI SXBtn_AddBkBorder(HWINDOW hWindow,HELE hEle,button_state_ nState,COLORREF color,BYTE alpha,int width);
void WINAPI SXBtn_AddBkFill(HWINDOW hWindow,HELE hEle,button_state_ nState,COLORREF color,BYTE alpha);
void WINAPI SXBtn_AddBkImage(HWINDOW hWindow,HELE hEle,button_state_ nState,HIMAGE hImage);
int WINAPI SXBtn_GetBkInfoCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXBtn_ClearBkInfo(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXComboBox_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
BOOL WINAPI SXComboBox_SetSelItem(HWINDOW hWindow,HELE hEle,int iIndex);
void WINAPI SXComboBox_GetButtonRect(HWINDOW hWindow,HELE hEle,out_ RECT* pRect);
void WINAPI SXComboBox_SetButtonSize(HWINDOW hWindow,HELE hEle,int size);
void WINAPI SXComboBox_SetDropHeight(HWINDOW hWindow,HELE hEle,int height);
int WINAPI SXComboBox_GetDropHeight(HWINDOW hWindow,HELE hEle);
void WINAPI SXComboBox_BindApapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter);
HXCGUI WINAPI SXComboBox_GetApapter(HWINDOW hWindow,HELE hEle);
void WINAPI SXComboBox_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile);
void WINAPI SXComboBox_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML);
void WINAPI SXComboBox_EnableDrawButton(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXComboBox_EnableEdit(HWINDOW hWindow,HELE hEle,BOOL bEdit);
void WINAPI SXComboBox_EnableDropHeightFixed(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXComboBox_AddBkBorder(HWINDOW hWindow,HELE hEle,comboBox_state_ nState,COLORREF color,BYTE alpha,int width);
void WINAPI SXComboBox_AddBkFill(HWINDOW hWindow,HELE hEle,comboBox_state_ nState,COLORREF color,BYTE alpha);
void WINAPI SXComboBox_AddBkImage(HWINDOW hWindow,HELE hEle,comboBox_state_ nState,HIMAGE hImage);
int WINAPI SXComboboX_GetBkInfoCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXComboBox_ClearBkInfo(HWINDOW hWindow,HELE hEle);
int WINAPI SXComboBox_GetSelItem(HWINDOW hWindow,HELE hEle);
comboBox_state_ WINAPI SXComboBox_GetState(HWINDOW hWindow,HELE hEle);
void WINAPI SXAd_Destroy(HWINDOW hWindow,HXCGUI hAdapter);
HXCGUI WINAPI SXAdListView_Create(HWINDOW hWindow);
int WINAPI SXAdListView_Group_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t * pName);
int WINAPI SXAdListView_Group_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t * pValue);
int WINAPI SXAdListView_Group_AddItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t * pValue);
int WINAPI SXAdListView_Group_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,HIMAGE hImage);
int WINAPI SXAdListView_Group_AddItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage);
BOOL WINAPI SXAdListView_Group_SetText(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iColumn,const wchar_t * pValue);
BOOL WINAPI SXAdListView_Group_SetTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,const wchar_t * pValue);
BOOL WINAPI SXAdListView_Group_SetImage(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iColumn,HIMAGE hImage);
BOOL WINAPI SXAdListView_Group_SetImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,HIMAGE hImage);
int WINAPI SXAdListView_Group_GetCount(HWINDOW hWindow,HXCGUI hAdapter);
int WINAPI SXAdListView_Item_GetCount(HWINDOW hWindow,HXCGUI hAdapter,int iGroup);
int WINAPI SXAdListView_Item_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t * pName);
int WINAPI SXAdListView_Item_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pValue);
int WINAPI SXAdListView_Item_AddItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,const wchar_t * pValue);
int WINAPI SXAdListView_Item_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,HIMAGE hImage);
int WINAPI SXAdListView_Item_AddItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,const wchar_t * pName,HIMAGE hImage);
BOOL WINAPI SXAdListView_Item_SetText(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,int iColumn,const wchar_t* pValue);
BOOL WINAPI SXAdListView_Item_SetTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t * pName,const wchar_t* pValue);
BOOL WINAPI SXAdListView_Item_SetImage(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,int iColumn,HIMAGE hImage);
BOOL WINAPI SXAdListView_Item_SetImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t * pName,HIMAGE hImage);
BOOL WINAPI SXAdListView_Group_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int iGroup);
void WINAPI SXAdListView_Group_DeleteAllChildItem(HWINDOW hWindow,HXCGUI hAdapter,int iGroup);
BOOL WINAPI SXAdListView_Item_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem);
void WINAPI SXAdListView_DeleteAll(HWINDOW hWindow,HXCGUI hAdapter);
void WINAPI SXAdListView_DeleteAllGroup(HWINDOW hWindow,HXCGUI hAdapter);
void WINAPI SXAdListView_DeleteAllItem(HWINDOW hWindow,HXCGUI hAdapter);
void WINAPI SXAdListView_DeleteColumnGroup(HWINDOW hWindow,HXCGUI hAdapter,int iColumn);
void WINAPI SXAdListView_DeleteColumnItem(HWINDOW hWindow,HXCGUI hAdapter,int iColumn);
BOOL WINAPI SXAdListView_Item_GetTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen);
HIMAGE WINAPI SXAdListView_Item_GetImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iGroup,int iItem,const wchar_t* pName);
HXCGUI WINAPI SXAdTable_Create(HWINDOW hWindow);
void WINAPI SXAdTable_Sort(HWINDOW hWindow,HXCGUI hAdapter,int iColumn,BOOL bAscending);
adapter_date_type_ WINAPI SXAdTable_GetItemDataType(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn);
adapter_date_type_ WINAPI SXAdTable_GetItemDataTypeEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName);
int WINAPI SXAdTable_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName);
int WINAPI SXAdTable_SetColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pColName);
int WINAPI SXAdTable_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pValue);
int WINAPI SXAdTable_AddItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue);
int WINAPI SXAdTable_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,HIMAGE hImage);
int WINAPI SXAdTable_AddItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage);
int WINAPI SXAdTable_InsertItemText(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pValue);
int WINAPI SXAdTable_InsertItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,const wchar_t* pValue);
int WINAPI SXAdTable_InsertItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iItem,HIMAGE hImage);
int WINAPI SXAdTable_InsertItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,HIMAGE hImage);
BOOL WINAPI SXAdTable_SetItemText(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,const wchar_t* pValue);
BOOL WINAPI SXAdTable_SetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,const wchar_t* pValue);
BOOL WINAPI SXAdTable_SetItemInt(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,int nValue);
BOOL WINAPI SXAdTable_SetItemIntEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,int nValue);
BOOL WINAPI SXAdTable_SetItemFloat(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,float nValue);
BOOL WINAPI SXAdTable_SetItemFloatEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,float nValue);
BOOL WINAPI SXAdTable_SetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,HIMAGE hImage);
BOOL WINAPI SXAdTable_SetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,HIMAGE hImage);
BOOL WINAPI SXAdTable_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int iItem);
BOOL WINAPI SXAdTable_DeleteItemEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int nCount);
void WINAPI SXAdTable_DeleteItemAll(HWINDOW hWindow,HXCGUI hAdapter);
void WINAPI SXAdTable_DeleteColumnAll(HWINDOW hWindow,HXCGUI hAdapter);
int WINAPI SXAdTable_GetCount(HWINDOW hWindow,HXCGUI hAdapter);
int WINAPI SXAdTable_GetCountColumn(HWINDOW hWindow,HXCGUI hAdapter);
BOOL WINAPI SXAdTable_GetItemText(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,out_ wchar_t* pOut,int nOutLen);
BOOL WINAPI SXAdTable_GetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen);
HIMAGE WINAPI SXAdTable_GetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn);
HIMAGE WINAPI SXAdTable_GetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName);
BOOL WINAPI SXAdTable_GetItemInt(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,out_ int* pOutValue);
BOOL WINAPI SXAdTable_GetItemIntEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,out_ int* pOutValue);
BOOL WINAPI SXAdTable_GetItemFloat(HWINDOW hWindow,HXCGUI hAdapter,int iItem,int iColumn,out_ float* pOutValue);
BOOL WINAPI SXAdTable_GetItemFloatEx(HWINDOW hWindow,HXCGUI hAdapter,int iItem,const wchar_t* pName,out_ float* pOutValue);
HXCGUI WINAPI SXAdTree_Create(HWINDOW hWindow);
int WINAPI SXAdTree_AddColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName);
int WINAPI SXAdTree_SetColumn(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pColName);
int WINAPI SXAdTree_InsertItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pValue,int nParentID,int insertID);
int WINAPI SXAdTree_InsertItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue,int nParentID,int insertID);
int WINAPI SXAdTree_InsertItemImage(HWINDOW hWindow,HXCGUI hAdapter,HIMAGE hImage,int nParentID,int insertID);
int WINAPI SXAdTree_InsertItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage,int nParentID,int insertID);
int WINAPI SXAdTree_GetCount(HWINDOW hWindow,HXCGUI hAdapter);
int WINAPI SXAdTree_GetCountColumn(HWINDOW hWindow,HXCGUI hAdapter);
BOOL WINAPI SXAdTree_SetItemText(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn,const wchar_t* pValue);
BOOL WINAPI SXAdTree_SetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName,const wchar_t* pValue);
BOOL WINAPI SXAdTree_SetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn,HIMAGE hImage);
BOOL WINAPI SXAdTree_SetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName,HIMAGE hImage);
BOOL WINAPI SXAdTree_GetItemText(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn,out_ wchar_t* pOut,int nOutLen);
HIMAGE WINAPI SXAdTree_GetItemImage(HWINDOW hWindow,HXCGUI hAdapter,int nID,int iColumn);
BOOL WINAPI SXAdTree_GetItemTextEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen);
HIMAGE WINAPI SXAdTree_GetItemImageEx(HWINDOW hWindow,HXCGUI hAdapter,int nID,const wchar_t* pName);
BOOL WINAPI SXAdTree_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,int nID);
void WINAPI SXAdTree_DeleteItemAll(HWINDOW hWindow,HXCGUI hAdapter);
void WINAPI SXAdTree_DeleteColumnAll(HWINDOW hWindow,HXCGUI hAdapter);
HXCGUI WINAPI SXAdMap_Create(HWINDOW hWindow);
BOOL WINAPI SXAdMap_AddItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue);
BOOL WINAPI SXAdMap_AddItemImage(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage);
BOOL WINAPI SXAdMap_DeleteItem(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName);
int WINAPI SXAdMap_GetCount(HWINDOW hWindow,HXCGUI hAdapter);
BOOL WINAPI SXAdMap_GetItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,out_ wchar_t* pOut,int nOutLen);
HIMAGE WINAPI SXAdMap_GetItemImage(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName);
BOOL WINAPI SXAdMap_SetItemText(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,const wchar_t* pValue);
BOOL WINAPI SXAdMap_SetItemImage(HWINDOW hWindow,HXCGUI hAdapter,const wchar_t* pName,HIMAGE hImage);
// void WINAPI S_XC_DebugPrintf(HWINDOW hWindow,int level,const char * pFormat,int 点点点);
// void WINAPI S_XC_DebugPrintfW(HWINDOW hWindow,int level,const wchar_t * pFormat,int 点点点);
// void WINAPI Sxtrace(HWINDOW hWindow,const char * pFormat,int 点点点);
// void WINAPI Sxtracew(HWINDOW hWindow,const wchar_t * pFormat,int 点点点);
HDRAW WINAPI SXDraw_Create(HWINDOW hWindow,HDC hdc);
void WINAPI SXDraw_Destroy(HWINDOW hWindow,HDRAW hDraw);
void WINAPI SXDraw_SetOffset(HWINDOW hWindow,HDRAW hDraw,int x,int y);
void WINAPI SXDraw_GetOffset(HWINDOW hWindow,HDRAW hDraw,out_ int * pX,out_ int * pY);
void WINAPI SXDraw_RestoreGDIOBJ(HWINDOW hWindow,HDRAW hDraw);
HDC WINAPI SXDraw_GetHDC(HWINDOW hWindow,HDRAW hDraw);
void WINAPI SXDraw_SetBrushColor(HWINDOW hWindow,HDRAW hDraw,COLORREF color,BYTE alpha);
void WINAPI SXDraw_SetTextAlign(HWINDOW hWindow,HDRAW hDraw,int nFlag);
void WINAPI SXDraw_SetTextVertical(HWINDOW hWindow,HDRAW hDraw,BOOL bVertical);
void WINAPI SXDraw_SetFontX(HWINDOW hWindow,HDRAW hDraw,HFONTX hFontx);
void WINAPI SXDraw_SetLineWidth(HWINDOW hWindow,HDRAW hDraw,int nWidth);
int WINAPI SXDraw_SetBkMode(HWINDOW hWindow,HDRAW hDraw,BOOL bTransparent);
void WINAPI SXDraw_SetClipRect(HWINDOW hWindow,HDRAW hDraw,RECT* pRect);
void WINAPI SXDraw_ClearClip(HWINDOW hWindow,HDRAW hDraw);
void WINAPI SXDraw_EnableSmoothingMode(HWINDOW hWindow,HDRAW hDraw,BOOL bEnable);
HBRUSH WINAPI SXDraw_CreateSolidBrush(HWINDOW hWindow,HDRAW hDraw,COLORREF crColor);
HPEN WINAPI SXDraw_CreatePen(HWINDOW hWindow,HDRAW hDraw,int fnPenStyle,int nWidth,COLORREF crColor);
HRGN WINAPI SXDraw_CreateRectRgn(HWINDOW hWindow,HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect);
HRGN WINAPI SXDraw_CreateRoundRectRgn(HWINDOW hWindow,HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect,int nWidthEllipse,int nHeightEllipse);
HRGN WINAPI SXDraw_CreatePolygonRgn(HWINDOW hWindow,HDRAW hDraw,POINT * pPt,int cPoints,int fnPolyFillMode);
int WINAPI SXDraw_SelectClipRgn(HWINDOW hWindow,HDRAW hDraw,HRGN hRgn);
void WINAPI SXDraw_FillRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect);
void WINAPI SXDraw_FillRectColor(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,COLORREF color,BYTE alpha);
BOOL WINAPI SXDraw_FillRgn(HWINDOW hWindow,HDRAW hDraw,HRGN hrgn,HBRUSH hbr);
void WINAPI SXDraw_FillEllipse(HWINDOW hWindow,HDRAW hDraw,RECT * pRect);
void WINAPI SXDraw_DrawEllipse(HWINDOW hWindow,HDRAW hDraw,RECT * pRect);
void WINAPI SXDraw_FillRoundRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nWidth,int nHeight);
void WINAPI SXDraw_DrawRoundRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nWidth,int nHeight);
void WINAPI SXDraw_FillRoundRectEx(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nLeftTop,int nRightTop,int nRightBottom,int nLeftBottom);
void WINAPI SXDraw_DrawRoundRectEx(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,int nLeftTop,int nRightTop,int nRightBottom,int nLeftBottom);
BOOL WINAPI SXDraw_Rectangle(HWINDOW hWindow,HDRAW hDraw,int nLeftRect,int nTopRect,int nRightRect,int nBottomRect);
void WINAPI SXDraw_DrawGroupBox_Rect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,const wchar_t* pName,COLORREF textColor,BYTE textAlpha,POINT* pOffset);
void WINAPI SXDraw_DrawGroupBox_RoundRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect,const wchar_t* pName,COLORREF textColor,BYTE textAlpha,POINT* pOffset,int nWidth,int nHeight);
void WINAPI SXDraw_GradientFill2(HWINDOW hWindow,HDRAW hDraw,COLORREF color1,BYTE alpha1,COLORREF color2,BYTE alpha2,RECT * pRect,int mode);
BOOL WINAPI SXDraw_GradientFill4(HWINDOW hWindow,HDRAW hDraw,COLORREF color1,COLORREF color2,COLORREF color3,COLORREF color4,RECT * pRect,int mode);
BOOL WINAPI SXDraw_FrameRgn(HWINDOW hWindow,HDRAW hDraw,HRGN hrgn,HBRUSH hbr,int nWidth,int nHeight);
void WINAPI SXDraw_FrameRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect);
void WINAPI SXDraw_FocusRect(HWINDOW hWindow,HDRAW hDraw,RECT * pRect);
void WINAPI SXDraw_DrawLine(HWINDOW hWindow,HDRAW hDraw,int x1,int y1,int x2,int y2);
BOOL WINAPI SXDraw_MoveToEx(HWINDOW hWindow,HDRAW hDraw,int X,int Y,LPPOINT lpPoint);
BOOL WINAPI SXDraw_LineTo(HWINDOW hWindow,HDRAW hDraw,int nXEnd,int nYEnd);
BOOL WINAPI SXDraw_Polyline(HWINDOW hWindow,HDRAW hDraw,in_ POINT * pArrayPt,int arrayPtSize);
void WINAPI SXDraw_Dottedline(HWINDOW hWindow,HDRAW hDraw,int x1,int y1,int x2,int y2);
COLORREF WINAPI SXDraw_SetPixel(HWINDOW hWindow,HDRAW hDraw,int X,int Y,COLORREF crColor);
void WINAPI SXDraw_Check(HWINDOW hWindow,HDRAW hDraw,int x,int y,COLORREF color,BOOL bCheck);
BOOL WINAPI SXDraw_DrawIconEx(HWINDOW hWindow,HDRAW hDraw,int xLeft,int yTop,HICON hIcon,int cxWidth,int cyWidth,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
BOOL WINAPI SXDraw_BitBlt(HWINDOW hWindow,HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDC hdcSrc,int nXSrc,int nYSrc,DWORD dwRop);
BOOL WINAPI SXDraw_BitBlt2(HWINDOW hWindow,HDRAW hDrawDest,int nXDest,int nYDest,int nWidth,int nHeight,HDRAW hDrawSrc,int nXSrc,int nYSrc,DWORD dwRop);
BOOL WINAPI SXDraw_AlphaBlend(HWINDOW hWindow,HDRAW hDraw,int nXOriginDest,int nYOriginDest,int nWidthDest,int nHeightDest,HDC hdcSrc,int nXOriginSrc,int nYOriginSrc,int nWidthSrc,int nHeightSrc,int alpha);
void WINAPI SXDraw_TriangularArrow(HWINDOW hWindow,HDRAW hDraw,int align,int x,int y,int width,int height);
void WINAPI SXDraw_DrawPolygon(HWINDOW hWindow,HDRAW hDraw,in_ POINT * points,int nCount);
void WINAPI SXDraw_DrawPolygonF(HWINDOW hWindow,HDRAW hDraw,in_ POINTF * points,int nCount);
void WINAPI SXDraw_FillPolygon(HWINDOW hWindow,HDRAW hDraw,in_ POINT * points,int nCount);
void WINAPI SXDraw_FillPolygonF(HWINDOW hWindow,HDRAW hDraw,in_ POINTF * points,int nCount);
void WINAPI SXDraw_Image(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,int x,int y);
void WINAPI SXDraw_Image2(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height);
void WINAPI SXDraw_ImageStretch(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,int x,int y,int width,int height);
void WINAPI SXDraw_ImageAdaptive(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRect,BOOL bOnlyBorder);
void WINAPI SXDraw_ImageExTile(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRect,int flag);
void WINAPI SXDraw_ImageSuper(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRect,BOOL bClip);
void WINAPI SXDraw_ImageSuper2(HWINDOW hWindow,HDRAW hDraw,HIMAGE hImage,RECT * pRcDest,RECT * pSrcRect);
void WINAPI SXDraw_DrawText(HWINDOW hWindow,HDRAW hDraw,const wchar_t * lpString,int nCount,RECT* lpRect);
void WINAPI SXDraw_DrawTextUnderline(HWINDOW hWindow,HDRAW hDraw,const wchar_t * lpString,int nCount,RECT* lpRect,COLORREF colorLine,BYTE alphaLine);
void WINAPI SXDraw_TextOut(HWINDOW hWindow,HDRAW hDraw,int nXStart,int nYStart,const wchar_t * lpString,int cbString);
void WINAPI SXDraw_TextOutEx(HWINDOW hWindow,HDRAW hDraw,int nXStart,int nYStart,const wchar_t * lpString);
void WINAPI SXDraw_TextOutA(HWINDOW hWindow,HDRAW hDraw,int nXStart,int nYStart,const char * lpString);
void WINAPI SXDraw_SetAlpha(HWINDOW hWindow,HDRAW hDraw,BYTE alpha);
void WINAPI SXDraw_SetAlphaEx(HWINDOW hWindow,HDC hdc,BYTE alpha);
HELE WINAPI SXEle_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
BOOL WINAPI S_XEle_RegEvent(HWINDOW hWindow,HELE hEle,UINT nEvent,xc_event* pEvent);
BOOL WINAPI S_XEle_RemoveEvent(HWINDOW hWindow,HELE hEle,UINT nEvent,xc_event* pEvent);
BOOL WINAPI SXEle_RegEventC(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun);
BOOL WINAPI SXEle_RegEventC1(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun);
BOOL WINAPI SXEle_RegEventC2(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun);
BOOL WINAPI SXEle_RemoveEventC(HWINDOW hWindow,HELE hEle,int nEvent,void * pFun);
int WINAPI SXEle_SendEvent(HWINDOW hWindow,HELE hEle,HELE hEventEle,int nEvent,WPARAM wParam,LPARAM lParam);
BOOL WINAPI SXEle_PostEvent(HWINDOW hWindow,HELE hEle,HELE hEventEle,int nEvent,WPARAM wParam,LPARAM lParam);
BOOL WINAPI SXEle_IsShow(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsEnable(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsEnableFocus(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsDrawFocus(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsEnableEvent_XE_PAINT_END(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsMouseThrough(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsBkTransparent(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsKeyTab(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsSwitchFocus(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsEnable_XE_MOUSEWHEEL(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_IsInScrollView(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_Enable(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableFocus(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableDrawFocus(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableDrawBorder(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableEvent_XE_PAINT_END(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableBkTransparent(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableMouseThrough(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableKeyTab(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableSwitchFocus(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableEvent_XE_MOUSEWHEEL(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_EnableInScrollView(HWINDOW hWindow,HELE hEle,BOOL bEnable);
BOOL WINAPI SXEle_SetRect(HWINDOW hWindow,HELE hEle,RECT * pRect,BOOL bRedraw);
BOOL WINAPI SXEle_SetRectEx(HWINDOW hWindow,HELE hEle,int x,int y,int cx,int cy,BOOL bRedraw);
BOOL WINAPI SXEle_SetRectLogic(HWINDOW hWindow,HELE hEle,RECT * pRect,BOOL bRedraw);
void WINAPI SXEle_GetRect(HWINDOW hWindow,HELE hEle,RECT * pRect);
void WINAPI SXEle_GetRectLogic(HWINDOW hWindow,HELE hEle,RECT * pRect);
void WINAPI SXEle_GetClientRect(HWINDOW hWindow,HELE hEle,RECT * pRect);
void WINAPI SXEle_GetWndClientRect(HWINDOW hWindow,HELE hEle,out_ RECT * pRect);
int WINAPI SXEle_GetWidth(HWINDOW hWindow,HELE hEle);
int WINAPI SXEle_GetHeight(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_RectWndClientToEleClient(HWINDOW hWindow,HELE hEle,in_out_ RECT * pRect);
void WINAPI SXEle_PointWndClientToEleClient(HWINDOW hWindow,HELE hEle,in_out_ POINT * pPt);
void WINAPI SXEle_RectClientToWndClient(HWINDOW hWindow,HELE hEle,in_out_ RECT * pRect);
void WINAPI SXEle_PointClientToWndClient(HWINDOW hWindow,HELE hEle,in_out_ POINT * pPt);
BOOL WINAPI SXEle_AddEle(HWINDOW hWindow,HELE hEle,HELE hChildEle);
BOOL WINAPI SXEle_InsertEle(HWINDOW hWindow,HELE hEle,HELE hChildEle,int index);
void WINAPI SXEle_RemoveEle(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_AddShape(HWINDOW hWindow,HELE hEle,HXCGUI hShape);
BOOL WINAPI SXEle_SetZOrder(HWINDOW hWindow,HELE hEle,int index);
BOOL WINAPI SXEle_SetZOrderEx(HWINDOW hWindow,HELE hEle,HELE hDestEle,zorder_ nType);
int WINAPI SXEle_GetZOrder(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_SetTopmost(HWINDOW hWindow,HELE hEle,BOOL bTopmost);
void WINAPI SXEle_EnableCSS(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXEle_SetCssName(HWINDOW hWindow,HELE hEle,const wchar_t * pName);
const wchar_t* WINAPI SXEle_GetCssName(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_ShowEle(HWINDOW hWindow,HELE hEle,BOOL bShow);
XC_OBJECT_TYPE WINAPI SXEle_GetType(HWINDOW hWindow,HELE hEle);
HWND WINAPI SXEle_GetHWND(HWINDOW hWindow,HELE hEle);
HWINDOW WINAPI SXEle_GetHWINDOW(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetCursor(HWINDOW hWindow,HELE hEle,HCURSOR hCursor);
HCURSOR WINAPI SXEle_GetCursor(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetID(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXEle_GetID(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetUID(HWINDOW hWindow,HELE hEle,int nUID);
int WINAPI SXEle_GetUID(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXEle_GetParentEle(HWINDOW hWindow,HELE hEle);
HXCGUI WINAPI SXEle_GetParent(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetTextColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
COLORREF WINAPI SXEle_GetTextColor(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetFocusBorderColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
COLORREF WINAPI SXEle_GetFocusBorderColor(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetFont(HWINDOW hWindow,HELE hEle,HFONTX hFontx);
HFONTX WINAPI SXEle_GetFont(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetAlpha(HWINDOW hWindow,HELE hEle,BYTE alpha);
int WINAPI SXEle_GetChildCount(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXEle_GetChildByIndex(HWINDOW hWindow,HELE hEle,int index);
HELE WINAPI SXEle_GetChildByID(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXEle_GetChildShapeCount(HWINDOW hWindow,HELE hEle);
HXCGUI WINAPI SXEle_GetChildShapeByIndex(HWINDOW hWindow,HELE hEle,int index);
void WINAPI SXEle_SetBorderSize(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom);
void WINAPI SXEle_GetBorderSize(HWINDOW hWindow,HELE hEle,BorderSize_i* pBorder);
void WINAPI SXEle_SetPadding(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom);
void WINAPI SXEle_GetPadding(HWINDOW hWindow,HELE hEle,PaddingSize_i* pPadding);
HELE WINAPI SXEle_HitChildEle(HWINDOW hWindow,HELE hEle,in_ POINT  * pPt);
void WINAPI SXEle_BindLayoutObject(HWINDOW hWindow,HELE hEle,HXCGUI hLayout);
HXCGUI WINAPI SXEle_GetLayoutObject(HWINDOW hWindow,HELE hEle);
HXCGUI WINAPI SXEle_GetParentLayoutObject(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_SetUserData(HWINDOW hWindow,HELE hEle,int nData);
int WINAPI SXEle_GetUserData(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_GetContentSize(HWINDOW hWindow,HELE hEle,out_ SIZE* pSize);
void WINAPI SXEle_SetCapture(HWINDOW hWindow,HELE hEle,BOOL b);
void WINAPI SXEle_SetLayoutWidth(HWINDOW hWindow,HELE hEle,layout_size_type_ nType,int nWidth);
void WINAPI SXEle_SetLayoutHeight(HWINDOW hWindow,HELE hEle,layout_size_type_ nType,int nHeight);
void WINAPI SXEle_GetLayoutWidth(HWINDOW hWindow,HELE hEle,out_ layout_size_type_ * pType,out_ int * pWidth);
void WINAPI SXEle_GetLayoutHeight(HWINDOW hWindow,HELE hEle,out_ layout_size_type_ * pType,out_ int * pHeight);
void WINAPI SXEle_RedrawEle(HWINDOW hWindow,HELE hEle,BOOL bImmediate);
void WINAPI SXEle_RedrawRect(HWINDOW hWindow,HELE hEle,RECT * pRect,BOOL bImmediate);
void WINAPI SXEle_Destroy(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_AddBkBorder(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha,int width);
void WINAPI SXEle_AddBkFill(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
void WINAPI SXEle_AddBkImage(HWINDOW hWindow,HELE hEle,HIMAGE hImage);
int WINAPI SXEle_GetBkInfoCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_ClearBkInfo(HWINDOW hWindow,HELE hEle);
HBKM WINAPI SXEle_GetBkManager(HWINDOW hWindow,HELE hEle);
int WINAPI SXEle_GetStateFlags(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_DrawFocus(HWINDOW hWindow,HELE hEle,HDRAW hDraw,RECT* pRect);
void WINAPI SXEle_DrawEle(HWINDOW hWindow,HELE hEle,HDRAW hDraw);
void WINAPI SXEle_EnableTransparentChannel(HWINDOW hWindow,HELE hEle,BOOL bEnable);
BOOL WINAPI SXEle_SetXCTimer(HWINDOW hWindow,HELE hEle,UINT nIDEvent,UINT uElapse);
BOOL WINAPI SXEle_KillXCTimer(HWINDOW hWindow,HELE hEle,UINT nIDEvent);
void WINAPI SXEle_SetToolTip(HWINDOW hWindow,HELE hEle,const wchar_t* pText);
void WINAPI SXEle_GetToolTip(HWINDOW hWindow,HELE hEle,out_ wchar_t  * pOut,int nOutLen);
void WINAPI SXEle_PopupToolTip(HWINDOW hWindow,HELE hEle,int x,int y);
void WINAPI SXEle_AdjustLayoutObject(HWINDOW hWindow,HELE hEle);
void WINAPI SXEle_AdjustLayout(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXEle_RegEventTest(HWINDOW hWindow,int nEvent,BYTE* pParamType);
HFONTX WINAPI SXFont_Create(HWINDOW hWindow,int size);
HFONTX WINAPI SXFont_Create2(HWINDOW hWindow,const wchar_t * pName,int size,int style);
HFONTX WINAPI SXFont_Create3(HWINDOW hWindow,const xc_font_info_i* pInfo);
HFONTX WINAPI SXFont_CreateEx(HWINDOW hWindow,LOGFONTW * pFontInfo);
HFONTX WINAPI SXFont_CreateFromHFONT(HWINDOW hWindow,HFONT hFont);
HFONTX WINAPI SXFont_CreateFromFont(HWINDOW hWindow,void* pFont);
HFONTX WINAPI SXFont_CreateFromFile(HWINDOW hWindow,const wchar_t* pFontFile,int size,int style);
void WINAPI SXFont_EnableAutoDestroy(HWINDOW hWindow,HFONTX hFontX,BOOL bEnable);
void* WINAPI SXFont_GetFont(HWINDOW hWindow,HFONTX hFontX);
void WINAPI SXFont_GetFontInfo(HWINDOW hWindow,HFONTX hFontX,out_ xc_font_info_i* pInfo);
void WINAPI SXFont_AddRef(HWINDOW hWindow,HFONTX hFontX);
void WINAPI SXFont_Release(HWINDOW hWindow,HFONTX hFontX);
int WINAPI SXFont_GetRefCount(HWINDOW hWindow,HFONTX hFontX);
void WINAPI SXFont_Destroy(HWINDOW hWindow,HFONTX hFontX);
HWINDOW WINAPI SXFrameWnd_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pTitle,HWND hWndParent,int XCStyle);
HWINDOW WINAPI SXFrameWnd_CreateEx(HWINDOW hWindow,DWORD dwExStyle,wchar_t* lpClassName,wchar_t* lpWindowName,DWORD dwStyle,int x,int y,int cx,int cy,HWND hWndParent,int XCStyle);
void WINAPI SXFrameWnd_GetLayoutAreaRect(HWINDOW hWindow,out_ RECT * pRect);
void WINAPI SXFrameWnd_SetView(HWINDOW hWindow,HELE hEle);
void WINAPI SXFrameWnd_SetPaneSplitBarColor(HWINDOW hWindow,COLORREF color,BYTE alpha);
BOOL WINAPI SXFrameWnd_SaveLayoutToFile(HWINDOW hWindow,const wchar_t* pFileName);
BOOL WINAPI SXFrameWnd_LoadLayoutFile(HWINDOW hWindow,HELE* aPaneList,int nEleCount,const wchar_t* pFileName);
BOOL WINAPI SXFrameWnd_AddPane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew,align_type_ align);
BOOL WINAPI SXFrameWnd_MergePane(HWINDOW hWindow,HELE hPaneDest,HELE hPaneNew);
HIMAGE WINAPI SXImage_LoadFile(HWINDOW hWindow,const wchar_t * pImageName,BOOL bStretch);
HIMAGE WINAPI SXImage_LoadFileAdaptive(HWINDOW hWindow,const wchar_t * pImageName,int leftSize,int topSize,int rightSize,int bottomSize);
HIMAGE WINAPI SXImage_LoadFileRect(HWINDOW hWindow,const wchar_t * pImageName,int x,int y,int cx,int cy);
HIMAGE WINAPI SXImage_LoadResAdaptive(HWINDOW hWindow,int id,const wchar_t * pType,int leftSize,int topSize,int rightSize,int bottomSize);
HIMAGE WINAPI SXImage_LoadRes(HWINDOW hWindow,int id,const wchar_t * pType,BOOL bStretch);
HIMAGE WINAPI SXImage_LoadZip(HWINDOW hWindow,const wchar_t * pZipFileName,const wchar_t * pImageName,const wchar_t * pPassword,BOOL bStretch);
HIMAGE WINAPI SXImage_LoadZipAdaptive(HWINDOW hWindow,const wchar_t * pZipFileName,const wchar_t * pImageName,const wchar_t * pPassword,int x1,int x2,int y1,int y2);
HIMAGE WINAPI SXImage_LoadZipRect(HWINDOW hWindow,const wchar_t * pZipFileName,const wchar_t * pImageName,const wchar_t * pPassword,int x,int y,int cx,int cy);
HIMAGE WINAPI SXImage_LoadMemory(HWINDOW hWindow,void* pBuffer,int nSize,BOOL bStretch);
HIMAGE WINAPI SXImage_LoadMemoryRect(HWINDOW hWindow,void* pBuffer,int nSize,int x,int y,int cx,int cy,BOOL bStretch);
HIMAGE WINAPI SXImage_LoadMemoryAdaptive(HWINDOW hWindow,void* pBuffer,int nSize,int leftSize,int topSize,int rightSize,int bottomSize);
HIMAGE WINAPI SXImage_LoadFromImage(HWINDOW hWindow,void * pImage);
HIMAGE WINAPI SXImage_LoadFileFromExtractIcon(HWINDOW hWindow,const wchar_t * pImageName);
HIMAGE WINAPI SXImage_LoadFileFromHICON(HWINDOW hWindow,HICON hIcon);
HIMAGE WINAPI SXImage_LoadFileFromHBITMAP(HWINDOW hWindow,HBITMAP hBitmap);
BOOL WINAPI SXImage_IsStretch(HWINDOW hWindow,HIMAGE hImage);
BOOL WINAPI SXImage_IsAdaptive(HWINDOW hWindow,HIMAGE hImage);
BOOL WINAPI SXImage_IsTile(HWINDOW hWindow,HIMAGE hImage);
BOOL WINAPI SXImage_SetDrawType(HWINDOW hWindow,HIMAGE hImage,image_draw_type_ nType);
BOOL WINAPI SXImage_SetDrawTypeAdaptive(HWINDOW hWindow,HIMAGE hImage,int leftSize,int topSize,int rightSize,int bottomSize);
void WINAPI SXImage_SetTranColor(HWINDOW hWindow,HIMAGE hImage,COLORREF color);
void WINAPI SXImage_SetTranColorEx(HWINDOW hWindow,HIMAGE hImage,COLORREF color,BYTE tranColor);
float WINAPI SXImage_SetRotateAngle(HWINDOW hWindow,HIMAGE hImage,float fAngle);
void WINAPI SXImage_EnableTranColor(HWINDOW hWindow,HIMAGE hImage,BOOL bEnable);
void WINAPI SXImage_EnableAutoDestroy(HWINDOW hWindow,HIMAGE hImage,BOOL bEnable);
void WINAPI SXImage_EnableCenter(HWINDOW hWindow,HIMAGE hImage,BOOL bCenter);
BOOL WINAPI SXImage_IsCenter(HWINDOW hWindow,HIMAGE hImage);
image_draw_type_ WINAPI SXImage_GetDrawType(HWINDOW hWindow,HIMAGE hImage);
int WINAPI SXImage_GetWidth(HWINDOW hWindow,HIMAGE hImage);
int WINAPI SXImage_GetHeight(HWINDOW hWindow,HIMAGE hImage);
void WINAPI SXImage_AddRef(HWINDOW hWindow,HIMAGE hImage);
void WINAPI SXImage_Release(HWINDOW hWindow,HIMAGE hImage);
int WINAPI SXImage_GetRefCount(HWINDOW hWindow,HIMAGE hImage);
void WINAPI SXImage_Destroy(HWINDOW hWindow,HIMAGE hImage);
HXCGUI WINAPI SXLayout_Create(HWINDOW hWindow);
void WINAPI SXLayout_Destroy(HWINDOW hWindow,HXCGUI hLayout);
void WINAPI SXLayout_AddEle(HWINDOW hWindow,HXCGUI hLayout,HELE hEle);
void WINAPI SXLayout_AddLayoutObject(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hLayoutObject);
void WINAPI SXLayout_AddShape(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hShape);
BOOL WINAPI SXLayout_Add(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild);
BOOL WINAPI SXLayout_Insert(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild,int index);
void WINAPI SXLayout_RemoveLayout(HWINDOW hWindow,HXCGUI hLayout);
void WINAPI SXLayout_RemoveChild(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild);
int WINAPI SXLayout_GetZOrder(HWINDOW hWindow,HXCGUI hLayout,HXCGUI hChild);
void WINAPI SXLayout_AdjustLayout(HWINDOW hWindow,HXCGUI hLayout);
void WINAPI SXLayout_SetRectFrame(HWINDOW hWindow,HXCGUI hLayout,RECT * pRect);
void WINAPI SXLayout_GetRect(HWINDOW hWindow,HXCGUI hLayout,out_ RECT * pRect);
void WINAPI SXLayout_GetRectFrame(HWINDOW hWindow,HXCGUI hLayout,out_ RECT * pRect);
HWINDOW WINAPI SXLayout_GetWindow(HWINDOW hWindow,HXCGUI hLayout);
HELE WINAPI SXLayout_GetEle(HWINDOW hWindow,HXCGUI hLayout);
HXCGUI WINAPI SXLayout_GetParentLayout(HWINDOW hWindow,HXCGUI hLayout);
HXCGUI WINAPI SXLayout_GetParent(HWINDOW hWindow,HXCGUI hLayout);
void WINAPI SXLayout_SetID(HWINDOW hWindow,HXCGUI hLayout,int nID);
int WINAPI SXLayout_GetID(HWINDOW hWindow,HXCGUI hLayout);
void WINAPI SXLayout_SetUID(HWINDOW hWindow,HXCGUI hLayout,int nUID);
int WINAPI SXLayout_GetUID(HWINDOW hWindow,HXCGUI hLayout);
void WINAPI SXLayout_SetHorizon(HWINDOW hWindow,HXCGUI hLayout,BOOL bHorizon);
void WINAPI SXLayout_SetAlignH(HWINDOW hWindow,HXCGUI hLayout,layout_align_ nAlign);
void WINAPI SXLayout_SetAlignV(HWINDOW hWindow,HXCGUI hLayout,layout_align_ nAlign);
void WINAPI SXLayout_SetPadding(HWINDOW hWindow,HXCGUI hLayout,int left,int top,int right,int bottom);
void WINAPI SXLayout_SetSpace(HWINDOW hWindow,HXCGUI hLayout,int nSpace);
void WINAPI SXLayout_SetLayoutWidth(HWINDOW hWindow,HXCGUI hLayout,layout_size_type_ nType,int nWidth);
void WINAPI SXLayout_SetLayoutHeight(HWINDOW hWindow,HXCGUI hLayout,layout_size_type_ nType,int nHeight);
void WINAPI SXLayout_GetLayoutWidth(HWINDOW hWindow,HXCGUI hLayout,out_ layout_size_type_ * pType,out_ int * pWidth);
void WINAPI SXLayout_GetLayoutHeight(HWINDOW hWindow,HXCGUI hLayout,out_ layout_size_type_ * pType,out_ int * pHeight);
int WINAPI SXLayout_GetWidth(HWINDOW hWindow,HXCGUI hLayout);
int WINAPI SXLayout_GetHeight(HWINDOW hWindow,HXCGUI hLayout);
int WINAPI SXLayout_GetWidthIn(HWINDOW hWindow,HXCGUI hLayout);
int WINAPI SXLayout_GetHeightIn(HWINDOW hWindow,HXCGUI hLayout);
void WINAPI SXLayout_GetContentSize(HWINDOW hWindow,HXCGUI hLayout,out_ SIZE* pSize);
void WINAPI SXLayout_ShowLayout(HWINDOW hWindow,HXCGUI hLayout,BOOL bShow);
int WINAPI SXLayout_GetChildCount(HWINDOW hWindow,HXCGUI hLayout);
XC_OBJECT_TYPE WINAPI SXLayout_GetChildType(HWINDOW hWindow,HXCGUI hLayout,int index);
HXCGUI WINAPI SXLayout_GetChild(HWINDOW hWindow,HXCGUI hLayout,int index);
void WINAPI SXLayout_Draw(HWINDOW hWindow,HXCGUI hLayout,HDRAW hDraw);
void WINAPI SLayout_SetEle(HWINDOW hWindow,HXCGUI hLayout,HELE hParent);
HELE WINAPI SXListBox_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXListBox_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags);
BOOL WINAPI SXListBox_SetItemData(HWINDOW hWindow,HELE hEle,int iItem,int nUserData);
int WINAPI SXListBox_GetItemData(HWINDOW hWindow,HELE hEle,int iItem);
BOOL WINAPI SXListBox_SetItemInfo(HWINDOW hWindow,HELE hEle,int iItem,in_ listBox_item_info_i * pItem);
BOOL WINAPI SXListBox_GetItemInfo(HWINDOW hWindow,HELE hEle,int iItem,out_ listBox_item_info_i * pItem);
void WINAPI SXListBox_AddItemBkBorder(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha,int width);
void WINAPI SXListBox_AddItemBkFill(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha);
void WINAPI SXListBox_AddItemBkImage(HWINDOW hWindow,HELE hEle,list_item_state_ nState,HIMAGE hImage);
int WINAPI SXListBox_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXListBox_ClearItemBkInfo(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXListBox_SetSelectItem(HWINDOW hWindow,HELE hEle,int iItem);
int WINAPI SXListBox_GetSelectItem(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXListBox_CancelSelectItem(HWINDOW hWindow,HELE hEle,int iItem);
BOOL WINAPI SXListBox_CancelSelectAll(HWINDOW hWindow,HELE hEle);
int WINAPI SXListBox_GetSelectAll(HWINDOW hWindow,HELE hEle,out_ int * pArray,int nArraySize);
int WINAPI SXListBox_GetSelectCount(HWINDOW hWindow,HELE hEle);
int WINAPI SXListBox_GetItemMouseStay(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXListBox_SelectAll(HWINDOW hWindow,HELE hEle);
void WINAPI SXListBox_SetItemHeightDefault(HWINDOW hWindow,HELE hEle,int nHeight,int nSelHeight);
void WINAPI SXListBox_GetItemHeightDefault(HWINDOW hWindow,HELE hEle,out_ int * pHeight,out_ int * pSelHeight);
int WINAPI SXListBox_GetItemIndexFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI);
void WINAPI SXListBox_SetRowSpace(HWINDOW hWindow,HELE hEle,int nSpace);
int WINAPI SXListBox_GetRowSpace(HWINDOW hWindow,HELE hEle);
int WINAPI SXListBox_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt);
int WINAPI SXListBox_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt);
BOOL WINAPI SXListBox_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile);
BOOL WINAPI SXListBox_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML);
HXCGUI WINAPI SXListBox_GetTemplateObject(HWINDOW hWindow,HELE hEle,int iItem,int nTempItemID);
void WINAPI SXListBox_EnableMultiSel(HWINDOW hWindow,HELE hEle,BOOL bEnable);
HXCGUI WINAPI SXListBox_CreateAdapter(HWINDOW hWindow,HELE hEle);
void WINAPI SXListBox_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter);
HXCGUI WINAPI SXListBox_GetAdapter(HWINDOW hWindow,HELE hEle);
void WINAPI SXListBox_Sort(HWINDOW hWindow,HELE hEle,int iColumnAdapter,BOOL bAscending);
void WINAPI SXListBox_RefreshData(HWINDOW hWindow,HELE hEle);
void WINAPI SXListBox_RefreshItem(HWINDOW hWindow,HELE hEle,int iItem);
HTEMP WINAPI SXTemp_Load(HWINDOW hWindow,XC_OBJECT_TYPE nType,const wchar_t* pFileName);
HTEMP WINAPI SXTemp_LoadFromString(HWINDOW hWindow,XC_OBJECT_TYPE nType,const char* pStringXML);
BOOL WINAPI SXTemp_Destroy(HWINDOW hWindow,HTEMP hTemp);
HTEMP WINAPI SXTemp_Create(HWINDOW hWindow,XC_OBJECT_TYPE nType);
BOOL WINAPI SXTemp_AddNodeRoot(HWINDOW hWindow,HTEMP hTemp,void* pNode);
BOOL WINAPI SXTemp_AddNode(HWINDOW hWindow,void* pParentNode,void* pNode);
void* WINAPI SXTemp_CreateNode(HWINDOW hWindow,XC_OBJECT_TYPE nType);
BOOL WINAPI SXTemp_SetNodeAttribute(HWINDOW hWindow,void* pNode,const wchar_t* pName,const wchar_t* pAttr);
HELE WINAPI SXList_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
int WINAPI SXList_AddColumn(HWINDOW hWindow,HELE hEle,int width);
int WINAPI SXList_InsertColumn(HWINDOW hWindow,HELE hEle,int width,int iItem);
void WINAPI SXList_EnableMultiSel(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXList_EnableDragChangeColumnWidth(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXList_EnableVScrollBarTop(HWINDOW hWindow,HELE hEle,BOOL bTop);
void WINAPI SXList_EnableItemBkFullRow(HWINDOW hWindow,HELE hEle,BOOL bFull);
void WINAPI SXList_SetSort(HWINDOW hWindow,HELE hEle,int iColumn,int iColumnAdapter,BOOL bEnable);
void WINAPI SXList_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int style);
void WINAPI SXList_SetColumnWidth(HWINDOW hWindow,HELE hEle,int iItem,int width);
void WINAPI SXList_SetColumnMinWidth(HWINDOW hWindow,HELE hEle,int iItem,int width);
void WINAPI SXList_SetColumnWidthFixed(HWINDOW hWindow,HELE hEle,int iColumn,BOOL bFixed);
int WINAPI SXList_GetColumnWidth(HWINDOW hWindow,HELE hEle,int iColumn);
int WINAPI SXList_GetColumnCount(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXList_DeleteColumn(HWINDOW hWindow,HELE hEle,int iItem);
void WINAPI SXList_DeleteColumnAll(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXList_SetItemData(HWINDOW hWindow,HELE hEle,int iItem,int iSubItem,int data);
int WINAPI SXList_GetItemData(HWINDOW hWindow,HELE hEle,int iItem,int iSubItem);
BOOL WINAPI SXList_SetSelectItem(HWINDOW hWindow,HELE hEle,int iItem);
int WINAPI SXList_GetSelectItem(HWINDOW hWindow,HELE hEle);
int WINAPI SXList_GetSelectItemCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXList_SetSelectAll(HWINDOW hWindow,HELE hEle);
int WINAPI SXList_GetSelectAll(HWINDOW hWindow,HELE hEle,out_ int * pArray,int nArraySize);
BOOL WINAPI SXList_CancelSelectItem(HWINDOW hWindow,HELE hEle,int iItem);
void WINAPI SXList_CancelSelectAll(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXList_GetHeaderHELE(HWINDOW hWindow,HELE hEle);
void WINAPI SXList_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter);
void WINAPI SXList_BindAdapterHeader(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter);
HXCGUI WINAPI SXList_CreateAdapter(HWINDOW hWindow,HELE hEle);
HXCGUI WINAPI SXList_CreateAdapterHeader(HWINDOW hWindow,HELE hEle);
HXCGUI WINAPI SXList_GetAdapter(HWINDOW hWindow,HELE hEle);
HXCGUI WINAPI SXList_GetAdapterHeader(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXList_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile);
BOOL WINAPI SXList_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML);
HXCGUI WINAPI SXList_GetTemplateObject(HWINDOW hWindow,HELE hEle,int iItem,int nTempItemID);
int WINAPI SXList_GetItemIndexFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI);
HXCGUI WINAPI SXList_GetHeaderTemplateObject(HWINDOW hWindow,HELE hEle,int iItem,int nTempItemID);
int WINAPI SXList_GetHeaderItemIndexFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI);
void WINAPI SXList_SetHeaderHeight(HWINDOW hWindow,HELE hEle,int height);
int WINAPI SXList_GetHeaderHeight(HWINDOW hWindow,HELE hEle);
void WINAPI SXList_AddItemBkBorder(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha,int width);
void WINAPI SXList_AddItemBkFill(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha);
void WINAPI SXList_AddItemBkImage(HWINDOW hWindow,HELE hEle,list_item_state_ nState,HIMAGE hImage);
int WINAPI SXList_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXList_ClearItemBkInfo(HWINDOW hWindow,HELE hEle);
void WINAPI SXList_SetItemHeightDefault(HWINDOW hWindow,HELE hEle,int nHeight,int nSelHeight);
void WINAPI SXList_GetItemHeightDefault(HWINDOW hWindow,HELE hEle,out_ int * pHeight,out_ int * pSelHeight);
void WINAPI SXList_SetRowSpace(HWINDOW hWindow,HELE hEle,int nSpace);
int WINAPI SXList_GetRowSpace(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXList_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt,out_ int * piItem,out_ int * piSubItem);
BOOL WINAPI SXList_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt,out_ int * piItem,out_ int * piSubItem);
void WINAPI SXList_RefreshData(HWINDOW hWindow,HELE hEle);
void WINAPI SXList_RefreshItem(HWINDOW hWindow,HELE hEle,int iItem);
HELE WINAPI SXListView_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
HXCGUI WINAPI SXListView_CreateAdapter(HWINDOW hWindow,HELE hEle);
void WINAPI SXListView_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter);
HXCGUI WINAPI SXListView_GetAdapter(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXListView_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile);
BOOL WINAPI SXListView_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML);
HXCGUI WINAPI SXListView_GetTemplateObject(HWINDOW hWindow,HELE hEle,int iGroup,int iItem,int nTempItemID);
HXCGUI WINAPI SXListView_GetTemplateObjectGroup(HWINDOW hWindow,HELE hEle,int iGroup,int nTempItemID);
BOOL WINAPI SXListView_GetItemIDFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI,out_ int* piGroup,out_ int* piItem);
BOOL WINAPI SXListView_HitTest(HWINDOW hWindow,HELE hEle,in_ POINT* pPt,out_ int* pOutGroup,out_ int* pOutItem);
int WINAPI SXListView_HitTestOffset(HWINDOW hWindow,HELE hEle,in_ POINT * pPt,out_ int* pOutGroup,out_ int* pOutItem);
void WINAPI SXListView_EnableMultiSel(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXListView_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags);
BOOL WINAPI SXListView_SetSelectItem(HWINDOW hWindow,HELE hEle,int iGroup,int iItem);
BOOL WINAPI SXListView_GetSelectItem(HWINDOW hWindow,HELE hEle,int * piGroup,int * piItem);
int WINAPI SXListView_GetSelectItemCount(HWINDOW hWindow,HELE hEle);
int WINAPI SXListView_GetSelectItemAll(HWINDOW hWindow,HELE hEle,out_ listView_item_id_i * pArray,int nArraySize);
void WINAPI SXListView_SetSelectItemAll(HWINDOW hWindow,HELE hEle);
void WINAPI SXListView_CancelSelectItemAll(HWINDOW hWindow,HELE hEle);
void WINAPI SXListView_SetColumnSpace(HWINDOW hWindow,HELE hEle,int space);
void WINAPI SXListView_SetRowSpace(HWINDOW hWindow,HELE hEle,int space);
void WINAPI SXListView_SetAlignSizeLeft(HWINDOW hWindow,HELE hEle,int size);
void WINAPI SXListView_SetAlignSizeTop(HWINDOW hWindow,HELE hEle,int size);
void WINAPI SXListView_SetItemSize(HWINDOW hWindow,HELE hEle,int width,int height);
void WINAPI SXListView_GetItemSize(HWINDOW hWindow,HELE hEle,SIZE* pSize);
void WINAPI SXListView_SetGroupHeight(HWINDOW hWindow,HELE hEle,int height);
int WINAPI SXListView_GetGroupHeight(HWINDOW hWindow,HELE hEle);
void WINAPI SXListView_SetGroupUserData(HWINDOW hWindow,HELE hEle,int iGroup,int nData);
void WINAPI SXListView_SetItemUserData(HWINDOW hWindow,HELE hEle,int iGroup,int iItem,int nData);
int WINAPI SXListView_GetGroupUserData(HWINDOW hWindow,HELE hEle,int iGroup);
int WINAPI SXListView_GetItemUserData(HWINDOW hWindow,HELE hEle,int iGroup,int iItem);
void WINAPI SXListView_AddItemBkBorder(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha,int width);
void WINAPI SXListView_AddItemBkFill(HWINDOW hWindow,HELE hEle,list_item_state_ nState,COLORREF color,BYTE alpha);
void WINAPI SXListView_AddItemBkImage(HWINDOW hWindow,HELE hEle,list_item_state_ nState,HIMAGE hImage);
int WINAPI SXListView_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXListView_ClearItemBkInfo(HWINDOW hWindow,HELE hEle);
void WINAPI SXListView_RefreshData(HWINDOW hWindow,HELE hEle);
void WINAPI SXListView_RefreshItem(HWINDOW hWindow,HELE hEle,int iGroup,int iItem);
BOOL WINAPI SXListView_ExpandGroup(HWINDOW hWindow,HELE hEle,int iGroup,BOOL bExpand);
HELE WINAPI SXMenuBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
int WINAPI SXMenuBar_AddButton(HWINDOW hWindow,HELE hEle,const wchar_t * pText);
void WINAPI SXMenuBar_SetButtonHeight(HWINDOW hWindow,HELE hEle,int height);
HMENUX WINAPI SXMenuBar_GetMenu(HWINDOW hWindow,HELE hEle,int nIndex);
BOOL WINAPI SXMenuBar_DeleteButton(HWINDOW hWindow,HELE hEle,int nIndex);
HMENUX WINAPI SXMenu_Create(HWINDOW hWindow);
void WINAPI SXMenu_AddItem(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,int parentId,int nFlags);
void WINAPI SXMenu_AddItemIcon(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,int nParentID,HIMAGE hImage,int nFlags);
void WINAPI SXMenu_InsertItem(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,int nFlags,int insertID);
void WINAPI SXMenu_InsertItemIcon(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText,HIMAGE hIcon,int nFlags,int insertID);
void WINAPI SXMenu_SetAutoDestroy(HWINDOW hWindow,HMENUX hMenu,BOOL bAuto);
void WINAPI SXMenu_EnableDrawBackground(HWINDOW hWindow,HMENUX hMenu,BOOL bEnable);
void WINAPI SXMenu_EnableDrawItem(HWINDOW hWindow,HMENUX hMenu,BOOL bEnable);
BOOL WINAPI SXMenu_Popup(HWINDOW hWindow,HMENUX hMenu,HWND hParentWnd,int x,int y,HELE hParentEle,menu_popup_position_ nPosition);
void WINAPI SXMenu_DestroyMenu(HWINDOW hWindow,HMENUX hMenu);
void WINAPI SXMenu_CloseMenu(HWINDOW hWindow,HMENUX hMenu);
void WINAPI SXMenu_SetBkImage(HWINDOW hWindow,HMENUX hMenu,HIMAGE hImage);
BOOL WINAPI SXMenu_SetItemText(HWINDOW hWindow,HMENUX hMenu,int nID,const wchar_t * pText);
BOOL WINAPI SXMenu_GetItemText(HWINDOW hWindow,HMENUX hMenu,int nID,out_ wchar_t * pOut,int nOutLen);
int WINAPI SXMenu_GetItemTextLength(HWINDOW hWindow,HMENUX hMenu,int nID);
BOOL WINAPI SXMenu_SetItemIcon(HWINDOW hWindow,HMENUX hMenu,int nID,HIMAGE hIcon);
BOOL WINAPI SXMenu_SetItemFlags(HWINDOW hWindow,HMENUX hMenu,int nID,int uFlags);
void WINAPI SXMenu_SetItemHeight(HWINDOW hWindow,HMENUX hMenu,int height);
int WINAPI SXMenu_GetItemHeight(HWINDOW hWindow,HMENUX hMenu);
void WINAPI SXMenu_SetBorderColor(HWINDOW hWindow,HMENUX hMenu,COLORREF crColor,BYTE alpha);
int WINAPI SXMenu_GetLeftWidth(HWINDOW hWindow,HMENUX hMenu);
int WINAPI SXMenu_GetLeftSpaceText(HWINDOW hWindow,HMENUX hMenu);
int WINAPI SXMenu_GetItemCount(HWINDOW hWindow,HMENUX hMenu);
BOOL WINAPI SXMenu_SetItemCheck(HWINDOW hWindow,HMENUX hMenu,int nID,BOOL bCheck);
BOOL WINAPI SXMenu_IsItemCheck(HWINDOW hWindow,HMENUX hMenu,int nID);
HWINDOW WINAPI SXModalWnd_Create(HWINDOW hWindow,int nWidth,int nHeight,const wchar_t * pTitle,HWND hWndParent,int XCStyle);
HWINDOW WINAPI SXModalWnd_CreateEx(HWINDOW hWindow,DWORD dwExStyle,const wchar_t* lpClassName,const wchar_t* lpWindowName,DWORD dwStyle,int x,int y,int cx,int cy,HWND hWndParent,int XCStyle);
void WINAPI SXModalWnd_EnableAutoClose(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXModalWnd_EnableEscClose(HWINDOW hWindow,BOOL bEnable);
int WINAPI SXModalWnd_DoModal(HWINDOW hWindow);
void WINAPI SXModalWnd_EndModal(HWINDOW hWindow,int nResult);
HELE WINAPI SXPane_Create(HWINDOW hWindow,const wchar_t * pName,int nWidth,int nHeight,HWINDOW hFrameWnd);
void WINAPI SXPane_SetView(HWINDOW hWindow,HELE hEle,HELE hView);
BOOL WINAPI SXPane_IsShowPane(HWINDOW hWindow,HELE hEle);
void WINAPI SXPane_SetSize(HWINDOW hWindow,HELE hEle,int nWidth,int nHeight);
pane_state_ WINAPI SXPane_GetState(HWINDOW hWindow,HELE hEle);
void WINAPI SXPane_GetViewRect(HWINDOW hWindow,HELE hEle,out_ RECT* pRect);
void WINAPI SXPane_SetTitle(HWINDOW hWindow,HELE hEle,wchar_t* pTitle);
void WINAPI SXPane_GetTitle(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int nOutLen);
void WINAPI SXPane_SetCaptionHeight(HWINDOW hWindow,HELE hEle,int nHeight);
int WINAPI SXPane_GetCaptionHeight(HWINDOW hWindow,HELE hEle);
void WINAPI SXPane_HidePane(HWINDOW hWindow,HELE hEle);
void WINAPI SXPane_ShowPane(HWINDOW hWindow,HELE hEle);
void WINAPI SXPane_DockPane(HWINDOW hWindow,HELE hEle);
void WINAPI SXPane_LockPane(HWINDOW hWindow,HELE hEle);
void WINAPI SXPane_FloatPane(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXFloatWnd_EnableCaptionContent(HWINDOW hWindow,BOOL bEnable);
HXCGUI WINAPI SXFloatWnd_GetCaptionLayout(HWINDOW hWindow);
HXCGUI WINAPI SXFloatWnd_GetCaptionShapeText(HWINDOW hWindow);
HELE WINAPI SXFloatWnd_GetCaptionButtonClose(HWINDOW hWindow);
void WINAPI SXFloatWnd_SetTitle(HWINDOW hWindow,const wchar_t* pTitle);
void WINAPI SXFloatWnd_GetTitle(HWINDOW hWindow,out_ wchar_t* pOut,int nOutLen);
HELE WINAPI SXProgBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXProgBar_SetRange(HWINDOW hWindow,HELE hEle,int range);
int WINAPI SXProgBar_GetRange(HWINDOW hWindow,HELE hEle);
void WINAPI SXProgBar_SetSpaceTwo(HWINDOW hWindow,HELE hEle,int leftSize,int rightSize);
void WINAPI SXProgBar_SetPos(HWINDOW hWindow,HELE hEle,int pos);
int WINAPI SXProgBar_GetPos(HWINDOW hWindow,HELE hEle);
void WINAPI SXProgBar_SetHorizon(HWINDOW hWindow,HELE hEle,BOOL bHorizon);
void WINAPI SXProgBar_SetImageLoad(HWINDOW hWindow,HELE hEle,HIMAGE hImage);
HELE WINAPI SXPGrid_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
int WINAPI SXPGrid_AddItem(HWINDOW hWindow,HELE hEle,const wchar_t * pName,propertyGrid_item_type_ nType,int nParentID);
int WINAPI SXPGrid_AddItemString(HWINDOW hWindow,HELE hEle,const wchar_t * pName,const wchar_t * pValue,int nParentID);
void WINAPI SXPGrid_DeleteAll(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXPGrid_GetItemHELE(HWINDOW hWindow,HELE hEle,int nItemID);
void WINAPI SXPGrid_SetWidth(HWINDOW hWindow,HELE hEle,int nWidth);
BOOL WINAPI SXPGrid_SetItemValue(HWINDOW hWindow,HELE hEle,int nItemID,const wchar_t* pValue);
BOOL WINAPI SXPGrid_SetItemValueInt(HWINDOW hWindow,HELE hEle,int nItemID,int nValue);
BOOL WINAPI SXPGrid_SetItemData(HWINDOW hWindow,HELE hEle,int nItemID,int nUserData);
int WINAPI SXPGrid_GetItemData(HWINDOW hWindow,HELE hEle,int nItemID);
const wchar_t* WINAPI SXPGrid_GetItemValue(HWINDOW hWindow,HELE hEle,int nItemID);
int WINAPI SXPGrid_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt,BOOL * pbExpandButton);
int WINAPI SXPGrid_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt,BOOL * pbExpandButton);
BOOL WINAPI SXPGrid_ExpandItem(HWINDOW hWindow,HELE hEle,int nItemID,BOOL bExpand);
int WINAPI SXPGrid_GetSelItem(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXPGrid_SetSelItem(HWINDOW hWindow,HELE hEle,int nItemID);
void WINAPI SXPGrid_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags);
HELE WINAPI SXRichEditColor_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXRichEditColor_SetColor(HWINDOW hWindow,HELE hEle,COLORREF color);
COLORREF WINAPI SXRichEditColor_GetColor(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXRichEditSet_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
HELE WINAPI SXRichEditFile_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXRichEditFile_SetOpenFileType(HWINDOW hWindow,HELE hEle,const wchar_t * pType);
void WINAPI SXRichEditFile_SetDefaultFile(HWINDOW hWindow,HELE hEle,const wchar_t * pFile);
void WINAPI SXRichEditFile_SetRelativeDir(HWINDOW hWindow,HELE hEle,const wchar_t * pDir);
HELE WINAPI SXRichEditFolder_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXRichEditFolder_SetDefaultDir(HWINDOW hWindow,HELE hEle,const wchar_t* pDir);
HELE WINAPI SXRichEdit_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXRichEdit_InsertString(HWINDOW hWindow,HELE hEle,const wchar_t * pString,HFONTX hFont);
BOOL WINAPI SXRichEdit_InsertImage(HWINDOW hWindow,HELE hEle,HIMAGE hImage,const wchar_t * pImagePath);
BOOL WINAPI SXRichEdit_InsertGif(HWINDOW hWindow,HELE hEle,HIMAGE hImage,const wchar_t * pImagePath);
void WINAPI SXRichEdit_InsertStringEx(HWINDOW hWindow,HELE hEle,int iRow,int iColumn,const wchar_t * pString,HFONTX hFont);
BOOL WINAPI SXRichEdit_InsertImageEx(HWINDOW hWindow,HELE hEle,int iRow,int iColumn,HIMAGE hImage,const wchar_t * pImagePath);
BOOL WINAPI SXRichEdit_InsertGifEx(HWINDOW hWindow,HELE hEle,int iRow,int iColumn,HIMAGE hImage,const wchar_t * pImagePath);
void WINAPI SXRichEdit_EnableReadOnly(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXRichEdit_EnableMultiLine(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXRichEdit_EnablePassword(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXRichEdit_EnableAutoWrap(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXRichEdit_EnableAutoSelAll(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXRichEdit_EnableVerticalCenter(HWINDOW hWindow,HELE hEle,BOOL bEnable);
BOOL WINAPI SXRichEdit_IsEmpty(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_IsReadOnly(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_IsMultiLine(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_IsPassword(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_IsAutoWrap(HWINDOW hWindow,HELE hEle);
void WINAPI SXRichEdit_SetLimitNum(HWINDOW hWindow,HELE hEle,int nNumber);
void WINAPI SXRichEdit_SetCaretColor(HWINDOW hWindow,HELE hEle,COLORREF color);
void WINAPI SXRichEdit_SetText(HWINDOW hWindow,HELE hEle,const wchar_t* pString);
void WINAPI SXRichEdit_SetTextInt(HWINDOW hWindow,HELE hEle,int nVaule);
int WINAPI SXRichEdit_GetText(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int len);
void WINAPI SXRichEdit_GetHTMLFormat(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int len);
void* WINAPI SXRichEdit_GetData(HWINDOW hWindow,HELE hEle,out_ int * pDataSize);
BOOL WINAPI SXRichEdit_InsertData(HWINDOW hWindow,HELE hEle,void * pData,int iRow,int iColumn);
int WINAPI SXRichEdit_GetTextLength(HWINDOW hWindow,HELE hEle);
void WINAPI SXRichEdit_SetRowHeight(HWINDOW hWindow,HELE hEle,UINT nHeight);
void WINAPI SXRichEdit_SetDefaultText(HWINDOW hWindow,HELE hEle,const wchar_t* pString);
void WINAPI SXRichEdit_SetDefaultTextColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
void WINAPI SXRichEdit_SetCurrentInputTextColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
int WINAPI SXRichEdit_GetCurrentRow(HWINDOW hWindow,HELE hEle);
int WINAPI SXRichEdit_GetCurrentColumn(HWINDOW hWindow,HELE hEle);
void WINAPI SXRichEdit_SetCurrentPos(HWINDOW hWindow,HELE hEle,int iRow,int iColumn);
int WINAPI SXRichEdit_GetRowCount(HWINDOW hWindow,HELE hEle);
int WINAPI SXRichEdit_GetRowLength(HWINDOW hWindow,HELE hEle,int iRow);
int WINAPI SXRichEdit_GetSelectText(HWINDOW hWindow,HELE hEle,out_ wchar_t* pOut,int len);
BOOL WINAPI SXRichEdit_GetSelectPosition(HWINDOW hWindow,HELE hEle,out_ Position_i * pBegin,out_ Position_i * pEnd);
BOOL WINAPI SXRichEdit_SetSelect(HWINDOW hWindow,HELE hEle,int iStartRow,int iStartCol,int iEndRow,int iEndCol);
BOOL WINAPI SXRichEdit_SetItemFontEx(HWINDOW hWindow,HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,HFONTX hFont);
BOOL WINAPI SXRichEdit_SetItemColorEx(HWINDOW hWindow,HELE hEle,int beginRow,int beginColumn,int endRow,int endColumn,COLORREF color,BYTE alpha);
void WINAPI SXRichEdit_CancelSelect(HWINDOW hWindow,HELE hEle);
void WINAPI SXRichEdit_SetSelectBkColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
BOOL WINAPI SXRichEdit_SelectAll(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_DeleteSelect(HWINDOW hWindow,HELE hEle);
void WINAPI SXRichEdit_DeleteAll(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_ClipboardCut(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_ClipboardCopy(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXRichEdit_ClipboardPaste(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXSBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXSBar_SetRange(HWINDOW hWindow,HELE hEle,int range);
int WINAPI SXSBar_GetRange(HWINDOW hWindow,HELE hEle);
void WINAPI SXSBar_ShowButton(HWINDOW hWindow,HELE hEle,BOOL bShow);
void WINAPI SXSBar_SetSliderLength(HWINDOW hWindow,HELE hEle,int length);
void WINAPI SXSBar_SetSliderMinLength(HWINDOW hWindow,HELE hEle,int minLength);
void WINAPI SXSBar_SetSliderPadding(HWINDOW hWindow,HELE hEle,int nPadding);
BOOL WINAPI SXSBar_SetHorizon(HWINDOW hWindow,HELE hEle,BOOL bHorizon);
int WINAPI SXSBar_GetSliderMaxLength(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSBar_ScrollUp(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSBar_ScrollDown(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSBar_ScrollTop(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSBar_ScrollBottom(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSBar_ScrollPos(HWINDOW hWindow,HELE hEle,int pos);
HELE WINAPI SXSBar_GetButtonUp(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXSBar_GetButtonDown(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXSBar_GetButtonSlider(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXSView_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
BOOL WINAPI SXSView_SetTotalSize(HWINDOW hWindow,HELE hEle,int cx,int cy);
void WINAPI SXSView_GetTotalSize(HWINDOW hWindow,HELE hEle,SIZE * pSize);
BOOL WINAPI SXSView_SetLineSize(HWINDOW hWindow,HELE hEle,int nWidth,int nHeight);
void WINAPI SXSView_GetLineSize(HWINDOW hWindow,HELE hEle,out_ SIZE * pSize);
void WINAPI SXSView_SetScrollBarSize(HWINDOW hWindow,HELE hEle,int size);
int WINAPI SXSView_GetViewPosH(HWINDOW hWindow,HELE hEle);
int WINAPI SXSView_GetViewPosV(HWINDOW hWindow,HELE hEle);
int WINAPI SXSView_GetViewWidth(HWINDOW hWindow,HELE hEle);
int WINAPI SXSView_GetViewHeight(HWINDOW hWindow,HELE hEle);
void WINAPI SXSView_GetViewRect(HWINDOW hWindow,HELE hEle,out_ RECT * pRect);
HELE WINAPI SXSView_GetScrollBarH(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXSView_GetScrollBarV(HWINDOW hWindow,HELE hEle);
void WINAPI SXSView_SetBorderSize(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom);
void WINAPI SXSView_GetBorderSize(HWINDOW hWindow,HELE hEle,out_ BorderSize_i* pBorder);
BOOL WINAPI SXSView_ScrollPosH(HWINDOW hWindow,HELE hEle,int pos);
BOOL WINAPI SXSView_ScrollPosV(HWINDOW hWindow,HELE hEle,int pos);
BOOL WINAPI SXSView_ScrollPosXH(HWINDOW hWindow,HELE hEle,int posX);
BOOL WINAPI SXSView_ScrollPosYV(HWINDOW hWindow,HELE hEle,int posY);
void WINAPI SXSView_ShowSBarH(HWINDOW hWindow,HELE hEle,BOOL bShow);
void WINAPI SXSView_ShowSBarV(HWINDOW hWindow,HELE hEle,BOOL bShow);
void WINAPI SXSView_EnableAutoShowScrollBar(HWINDOW hWindow,HELE hEle,BOOL bEnable);
BOOL WINAPI SXSView_ScrollLeftLine(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSView_ScrollRightLine(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSView_ScrollTopLine(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSView_ScrollBottomLine(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSView_ScrollLeft(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSView_ScrollRight(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSView_ScrollTop(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXSView_ScrollBottom(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXShape_GetParentEle(HWINDOW hWindow,HXCGUI hShape);
HXCGUI WINAPI SXShape_GetParentLayout(HWINDOW hWindow,HXCGUI hShape);
HWINDOW WINAPI SXShape_GetHWINDOW(HWINDOW hWindow,HXCGUI hShape);
HXCGUI WINAPI SXShape_GetParent(HWINDOW hWindow,HXCGUI hShape);
void WINAPI SXShape_RemoveShape(HWINDOW hWindow,HXCGUI hShape);
void WINAPI SXShape_SetID(HWINDOW hWindow,HXCGUI hShape,int nID);
int WINAPI SXShape_GetID(HWINDOW hWindow,HXCGUI hShape);
void WINAPI SXShape_SetUID(HWINDOW hWindow,HXCGUI hShape,int nUID);
int WINAPI SXShape_GetUID(HWINDOW hWindow,HXCGUI hShape);
void WINAPI SXShape_Redraw(HWINDOW hWindow,HXCGUI hShape);
int WINAPI SXShape_GetWidth(HWINDOW hWindow,HXCGUI hShape);
int WINAPI SXShape_GetHeight(HWINDOW hWindow,HXCGUI hShape);
void WINAPI SXShape_GetRect(HWINDOW hWindow,HXCGUI hShape,out_ RECT* pRect);
void WINAPI SXShape_SetRect(HWINDOW hWindow,HXCGUI hShape,in_  RECT* pRect);
void WINAPI SXShape_GetContentSize(HWINDOW hWindow,HXCGUI hShape,out_ SIZE* pSize);
void WINAPI SXShape_ShowLayout(HWINDOW hWindow,HXCGUI hShape,BOOL bShow);
void WINAPI SXShape_AdjustLayout(HWINDOW hWindow,HXCGUI hShape);
void WINAPI SXShape_Destroy(HWINDOW hWindow,HXCGUI hShape);
HXCGUI WINAPI SXShapeText_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pName,HXCGUI hParent);
void WINAPI SXShapeText_SetText(HWINDOW hWindow,HXCGUI hTextBlock,const wchar_t * pName);
void WINAPI SXShapeText_GetText(HWINDOW hWindow,HXCGUI hTextBlock,out_ wchar_t * pOut,int nOutLen);
int WINAPI SXShapeText_GetTextLength(HWINDOW hWindow,HXCGUI hTextBlock);
void WINAPI SXShapeText_SetFont(HWINDOW hWindow,HXCGUI hTextBlock,HFONTX hFontx);
HFONTX WINAPI SXShapeText_GetFont(HWINDOW hWindow,HXCGUI hTextBlock);
void WINAPI SXShapeText_SetTextColor(HWINDOW hWindow,HXCGUI hTextBlock,COLORREF color,BYTE alpha);
COLORREF WINAPI SXShapeText_GetTextColor(HWINDOW hWindow,HXCGUI hTextBlock);
void WINAPI SXShapeText_SetTextAlign(HWINDOW hWindow,HXCGUI hTextBlock,int align);
void WINAPI SXShapeText_SetOffset(HWINDOW hWindow,HXCGUI hTextBlock,int x,int y);
void WINAPI SXShapeText_SetLayoutWidth(HWINDOW hWindow,HXCGUI hTextBlock,layout_size_type_ nType,int width);
void WINAPI SXShapeText_SetLayoutHeight(HWINDOW hWindow,HXCGUI hTextBlock,layout_size_type_ nType,int height);
void WINAPI SXShapeText_GetLayoutWidth(HWINDOW hWindow,HXCGUI hTextBlock,out_ layout_size_type_ * pType,out_ int * pWidth);
void WINAPI SXShapeText_GetLayoutHeight(HWINDOW hWindow,HXCGUI hTextBlock,out_ layout_size_type_ * pType,out_ int * pHeight);
void WINAPI SXShapeText_EnableCSS(HWINDOW hWindow,HXCGUI hTextBlock,BOOL bEnable);
void WINAPI SXShapeText_SetCssName(HWINDOW hWindow,HXCGUI hTextBlock,const wchar_t* pName);
const wchar_t* WINAPI SXShapeText_GetCssName(HWINDOW hWindow,HXCGUI hTextBlock);
HXCGUI WINAPI SXShapePic_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXShapePic_SetImage(HWINDOW hWindow,HXCGUI hShape,HIMAGE hImage);
void WINAPI SXShapePic_SetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int width);
void WINAPI SXShapePic_SetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int height);
void WINAPI SXShapePic_GetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pWidth);
void WINAPI SXShapePic_GetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pHeight);
HXCGUI WINAPI SXShapeGif_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXShapeGif_SetImage(HWINDOW hWindow,HXCGUI hShape,HIMAGE hImage);
void WINAPI SXShapeGif_SetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int width);
void WINAPI SXShapeGif_SetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,layout_size_type_ nType,int height);
void WINAPI SXShapeGif_GetLayoutWidth(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pWidth);
void WINAPI SXShapeGif_GetLayoutHeight(HWINDOW hWindow,HXCGUI hShape,out_ layout_size_type_ * pType,out_ int * pHeight);
HXCGUI WINAPI SXShapeRect_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXShapeRect_SetBorderColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha);
void WINAPI SXShapeRect_SetFillColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha);
void WINAPI SXShapeRect_SetRoundAngle(HWINDOW hWindow,HXCGUI hShape,int nWidth,int nHeight);
void WINAPI SXShapeRect_GetRoundAngle(HWINDOW hWindow,HXCGUI hShape,out_ int * pWidth,out_ int * pHeight);
void WINAPI SXShapeRect_EnableBorder(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable);
void WINAPI SXShapeRect_EnableFill(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable);
void WINAPI SXShapeRect_EnableRoundAngle(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable);
HXCGUI WINAPI SXShapeEllipse_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXShapeEllipse_SetBorderColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha);
void WINAPI SXShapeEllipse_SetFillColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha);
void WINAPI SXShapeEllipse_EnableBorder(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable);
void WINAPI SXShapeEllipse_EnableFill(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable);
HXCGUI WINAPI SXShapeGroupBox_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t* pName,HXCGUI hParent);
void WINAPI SXShapeGroupBox_SetBorderColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha);
void WINAPI SXShapeGroupBox_SetTextColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha);
void WINAPI SXShapeGroupBox_SetFontX(HWINDOW hWindow,HXCGUI hShape,HFONTX hFontX);
void WINAPI SXShapeGroupBox_SetTextOffset(HWINDOW hWindow,HXCGUI hShape,int offsetX,int offsetY);
void WINAPI SXShapeGroupBox_SetRoundAngle(HWINDOW hWindow,HXCGUI hShape,int nWidth,int nHeight);
void WINAPI SXShapeGroupBox_SetText(HWINDOW hWindow,HXCGUI hShape,const wchar_t* pText);
void WINAPI SXShapeGroupBox_GetTextOffset(HWINDOW hWindow,HXCGUI hShape,out_ int * pOffsetX,out_ int * pOffsetY);
void WINAPI SXShapeGroupBox_GetRoundAngle(HWINDOW hWindow,HXCGUI hShape,out_ int * pWidth,out_ int * pHeight);
void WINAPI SXShapeGroupBox_EnableRoundAngle(HWINDOW hWindow,HXCGUI hShape,BOOL bEnable);
HXCGUI WINAPI SXShapeLine_Create(HWINDOW hWindow,int x1,int y1,int x2,int y2,HXCGUI hParent);
void WINAPI SXShapeLine_SetPosition(HWINDOW hWindow,HXCGUI hShape,int x1,int y1,int x2,int y2);
void WINAPI SXShapeLine_SetColor(HWINDOW hWindow,HXCGUI hShape,COLORREF color,BYTE alpha);
HELE WINAPI SXSliderBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXSliderBar_SetRange(HWINDOW hWindow,HELE hEle,int range);
int WINAPI SXSliderBar_GetRange(HWINDOW hWindow,HELE hEle);
void WINAPI SXSliderBar_SetButtonWidth(HWINDOW hWindow,HELE hEle,int width);
void WINAPI SXSliderBar_SetButtonHeight(HWINDOW hWindow,HELE hEle,int height);
void WINAPI SXSliderBar_SetSpaceTwo(HWINDOW hWindow,HELE hEle,int leftSize,int rightSize);
void WINAPI SXSliderBar_SetPos(HWINDOW hWindow,HELE hEle,int pos);
int WINAPI SXSliderBar_GetPos(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXSliderBar_GetButton(HWINDOW hWindow,HELE hEle);
void WINAPI SXSliderBar_SetHorizon(HWINDOW hWindow,HELE hEle,BOOL bHorizon);
void WINAPI SXSliderBar_SetImageLoad(HWINDOW hWindow,HELE hEle,HIMAGE hImage);
HELE WINAPI SXTabBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
int WINAPI SXTabBar_AddLabel(HWINDOW hWindow,HELE hEle,const wchar_t * pName);
int WINAPI SXTabBar_InsertLabel(HWINDOW hWindow,HELE hEle,int index,wchar_t * pName);
BOOL WINAPI SXTabBar_DeleteLabel(HWINDOW hWindow,HELE hEle,int index);
void WINAPI SXTabBar_DeleteLabelAll(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXTabBar_GetLabel(HWINDOW hWindow,HELE hEle,int index);
HELE WINAPI SXTabBar_GetLabelClose(HWINDOW hWindow,HELE hEle,int index);
HELE WINAPI SXTabBar_GetButtonLeft(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXTabBar_GetButtonRight(HWINDOW hWindow,HELE hEle);
int WINAPI SXTabBar_GetSelect(HWINDOW hWindow,HELE hEle);
int WINAPI SXTabBar_GetLabelSpacing(HWINDOW hWindow,HELE hEle);
int WINAPI SXTabBar_GetLabelCount(HWINDOW hWindow,HELE hEle);
int WINAPI SXTabBar_GetindexByEle(HWINDOW hWindow,HELE hEle,HELE hLabel);
void WINAPI SXTabBar_SetLabelSpacing(HWINDOW hWindow,HELE hEle,int spacing);
void WINAPI SXTabBar_SetPadding(HWINDOW hWindow,HELE hEle,int left,int top,int right,int bottom);
void WINAPI SXTabBar_SetSelect(HWINDOW hWindow,HELE hEle,int index);
void WINAPI SXTabBar_SetUp(HWINDOW hWindow,HELE hEle);
void WINAPI SXTabBar_SetDown(HWINDOW hWindow,HELE hEle);
void WINAPI SXTabBar_EnableTile(HWINDOW hWindow,HELE hEle,BOOL bTile);
void WINAPI SXTabBar_EnableClose(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXTabBar_SetCloseSize(HWINDOW hWindow,HELE hEle,SIZE * pSize);
void WINAPI SXTabBar_SetTurnButtonSize(HWINDOW hWindow,HELE hEle,SIZE * pSize);
void WINAPI SXTabBar_SetLabelWidth(HWINDOW hWindow,HELE hEle,int index,int nWidth);
BOOL WINAPI SXTabBar_ShowLabel(HWINDOW hWindow,HELE hEle,int index,BOOL bShow);
HELE WINAPI SXTextLink_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t* pName,HXCGUI hParent);
void WINAPI SXTextLink_EnableUnderlineLeave(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXTextLink_EnableUnderlineStay(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXTextLink_SetTextColorStay(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
void WINAPI SXTextLink_SetUnderlineColorLeave(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
void WINAPI SXTextLink_SetUnderlineColorStay(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
HELE WINAPI SXToolBar_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
int WINAPI SXToolBar_InsertEle(HWINDOW hWindow,HELE hEle,HELE hNewEle,int index);
int WINAPI SXToolBar_InsertSeparator(HWINDOW hWindow,HELE hEle,int index,COLORREF color);
void WINAPI SXToolBar_EnableButtonMenu(HWINDOW hWindow,HELE hEle,BOOL bEnable);
HELE WINAPI SXToolBar_GetHEle(HWINDOW hWindow,HELE hEle,int index);
HELE WINAPI SXToolBar_GetButtonLeft(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXToolBar_GetButtonRight(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXToolBar_GetButtonMenu(HWINDOW hWindow,HELE hEle);
void WINAPI SXToolBar_SetSpace(HWINDOW hWindow,HELE hEle,int nSize);
void WINAPI SXToolBar_DeleteEle(HWINDOW hWindow,HELE hEle,int index);
void WINAPI SXToolBar_DeleteAllEle(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXTree_Create(HWINDOW hWindow,int x,int y,int cx,int cy,HXCGUI hParent);
void WINAPI SXTree_EnableDragItem(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXTree_EnableConnectLine(HWINDOW hWindow,HELE hEle,BOOL bEnable,BOOL bSolid);
void WINAPI SXTree_EnableExpand(HWINDOW hWindow,HELE hEle,BOOL bEnable);
void WINAPI SXTree_SetConnectLineColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
void WINAPI SXTree_SetExpandButtonSize(HWINDOW hWindow,HELE hEle,int nWidth,int nHeight);
void WINAPI SXTree_SetConnectLineLength(HWINDOW hWindow,HELE hEle,int nLength);
void WINAPI SXTree_SetDragInsertPositionColor(HWINDOW hWindow,HELE hEle,COLORREF color,BYTE alpha);
BOOL WINAPI SXTree_SetItemTemplateXML(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile);
BOOL WINAPI SXTree_SetItemTemplateXMLSel(HWINDOW hWindow,HELE hEle,const wchar_t* pXmlFile);
BOOL WINAPI SXTree_SetItemTemplateXMLFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML);
BOOL WINAPI SXTree_SetItemTemplateXMLSelFromString(HWINDOW hWindow,HELE hEle,const char* pStringXML);
void WINAPI SXTree_SetDrawItemBkFlags(HWINDOW hWindow,HELE hEle,int nFlags);
BOOL WINAPI SXTree_SetItemData(HWINDOW hWindow,HELE hEle,int nID,int nUserData);
int WINAPI SXTree_GetItemData(HWINDOW hWindow,HELE hEle,int nID);
BOOL WINAPI SXTree_SetSelectItem(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXTree_GetSelectItem(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXTree_IsExpand(HWINDOW hWindow,HELE hEle,int nID);
BOOL WINAPI SXTree_ExpandItem(HWINDOW hWindow,HELE hEle,int nID,BOOL bExpand);
BOOL WINAPI SXTree_ExpandAllChildItem(HWINDOW hWindow,HELE hEle,int nID,BOOL bExpand);
int WINAPI SXTree_HitTest(HWINDOW hWindow,HELE hEle,POINT * pPt);
int WINAPI SXTree_HitTestOffset(HWINDOW hWindow,HELE hEle,POINT * pPt);
int WINAPI SXTree_GetFirstChildItem(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXTree_GetEndChildItem(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXTree_GetPrevSiblingItem(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXTree_GetNextSiblingItem(HWINDOW hWindow,HELE hEle,int nID);
int WINAPI SXTree_GetParentItem(HWINDOW hWindow,HELE hEle,int nID);
void WINAPI SXTree_SetIndentation(HWINDOW hWindow,HELE hEle,int nWidth);
int WINAPI SXTree_GetIndentation(HWINDOW hWindow,HELE hEle);
void WINAPI SXTree_SetItemHeight(HWINDOW hWindow,HELE hEle,int nID,int nHeight,int nSelHeight);
void WINAPI SXTree_GetItemHeight(HWINDOW hWindow,HELE hEle,int nID,out_ int * pHeight,out_ int * pSelHeight);
void WINAPI SXTree_SetRowSpace(HWINDOW hWindow,HELE hEle,int nSpace);
int WINAPI SXTree_GetRowSpace(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXTree_MoveItem(HWINDOW hWindow,HELE hEle,int nMoveItem,int nDestItem,int nType);
void WINAPI SXTree_AddItemBkBorder(HWINDOW hWindow,HELE hEle,tree_item_state_ nState,COLORREF color,BYTE alpha,int width);
void WINAPI SXTree_AddItemBkFill(HWINDOW hWindow,HELE hEle,tree_item_state_ nState,COLORREF color,BYTE alpha);
void WINAPI SXTree_AddItemBkImage(HWINDOW hWindow,HELE hEle,tree_item_state_ nState,HIMAGE hImage);
int WINAPI SXTree_GetItemBkInfoCount(HWINDOW hWindow,HELE hEle);
void WINAPI SXTree_ClearItemBkInfo(HWINDOW hWindow,HELE hEle);
void WINAPI SXTree_SetItemHeightDefault(HWINDOW hWindow,HELE hEle,int nHeight,int nSelHeight);
void WINAPI SXTree_GetItemHeightDefault(HWINDOW hWindow,HELE hEle,out_ int * pHeight,out_ int * pSelHeight);
HXCGUI WINAPI SXTree_GetTemplateObject(HWINDOW hWindow,HELE hEle,int nID,int nTempItemID);
int WINAPI SXTree_GetItemIDFromHXCGUI(HWINDOW hWindow,HELE hEle,HXCGUI hXCGUI);
HXCGUI WINAPI SXTree_CreateAdapter(HWINDOW hWindow,HELE hEle);
void WINAPI SXTree_BindAdapter(HWINDOW hWindow,HELE hEle,HXCGUI hAdapter);
HXCGUI WINAPI SXTree_GetAdapter(HWINDOW hWindow,HELE hEle);
void WINAPI SXTree_RefreshData(HWINDOW hWindow,HELE hEle);
void WINAPI SXTree_RefreshItem(HWINDOW hWindow,HELE hEle,int nID);
BOOL WINAPI S_XWnd_RegEvent(HWINDOW hWindow,UINT nEvent,xc_event* pEvent);
BOOL WINAPI S_XWnd_RemoveEvent(HWINDOW hWindow,UINT nEvent,xc_event* pEvent);
BOOL WINAPI SXWnd_RegEventC(HWINDOW hWindow,int nEvent,void * pFun);
BOOL WINAPI SXWnd_RegEventC1(HWINDOW hWindow,int nEvent,void * pFun);
BOOL WINAPI SXWnd_RemoveEventC(HWINDOW hWindow,int nEvent,void * pFun);
HWINDOW WINAPI SXWnd_Create(HWINDOW hWindow,int x,int y,int cx,int cy,const wchar_t * pTitle,HWND hWndParent,int XCStyle);
HWINDOW WINAPI SXWnd_CreateEx(HWINDOW hWindow,DWORD dwExStyle,const wchar_t* lpClassName,const wchar_t* lpWindowName,DWORD dwStyle,int x,int y,int cx,int cy,HWND hWndParent,int XCStyle);
BOOL WINAPI SXWnd_AddEle(HWINDOW hWindow,HELE hEle);
BOOL WINAPI SXWnd_InsertEle(HWINDOW hWindow,HELE hChildEle,int index);
BOOL WINAPI SXWnd_AddShape(HWINDOW hWindow,HXCGUI hShape);
HWND WINAPI SXWnd_GetHWND(HWINDOW hWindow);
void WINAPI SXWnd_EnableDragBorder(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXWnd_EnableDragWindow(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXWnd_EnableDragCaption(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXWnd_EnableDrawBk(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXWnd_EnableAutoFocus(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXWnd_EnableMaxWindow(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXWnd_RedrawWnd(HWINDOW hWindow,BOOL bImmediate);
void WINAPI SXWnd_RedrawWndRect(HWINDOW hWindow,RECT * pRect,BOOL bImmediate);
void WINAPI SXWnd_SetFocusEle(HWINDOW hWindow,HELE hFocusEle);
HELE WINAPI SXWnd_GetFocusEle(HWINDOW hWindow);
HELE WINAPI SXWnd_GetStayHELE(HWINDOW hWindow);
void WINAPI SXWnd_DrawWindow(HWINDOW hWindow,HDRAW hDraw);
void WINAPI SXWnd_SetCursor(HWINDOW hWindow,HCURSOR hCursor);
HCURSOR WINAPI SXWnd_GetCursor(HWINDOW hWindow);
HCURSOR WINAPI SXWnd_SetCursorSys(HWINDOW hWindow,HCURSOR hCursor);
void WINAPI SXWnd_SetFont(HWINDOW hWindow,HFONTX hFontx);
void WINAPI SXWnd_SetTextColor(HWINDOW hWindow,COLORREF color,BYTE alpha);
COLORREF WINAPI SXWnd_GetTextColor(HWINDOW hWindow);
void WINAPI SXWnd_SetID(HWINDOW hWindow,int nID);
int WINAPI SXWnd_GetID(HWINDOW hWindow);
void WINAPI SXWnd_SetCaptureEle(HWINDOW hWindow,HELE hEle);
HELE WINAPI SXWnd_GetCaptureEle(HWINDOW hWindow);
BOOL WINAPI SXWnd_BindLayoutEle(HWINDOW hWindow,window_position_ nPosition,HELE hEle);
HELE WINAPI SXWnd_GetLayoutEle(HWINDOW hWindow,window_position_ nPosition);
void WINAPI SXWnd_BindLayoutObject(HWINDOW hWindow,window_position_ nPosition,HXCGUI hLayout);
HXCGUI WINAPI SXWnd_GetLayoutObject(HWINDOW hWindow,window_position_ nPosition);
void WINAPI SXWnd_SetLayoutSize(HWINDOW hWindow,int left,int top,int right,int bottom);
void WINAPI SXWnd_GetLayoutSize(HWINDOW hWindow,out_ BorderSize_i  * pBorderSize);
void WINAPI SXWnd_SetDragBorderSize(HWINDOW hWindow,int left,int top,int right,int bottom);
void WINAPI SXWnd_GetDragBorderSize(HWINDOW hWindow,out_ BorderSize_i* pSize);
void WINAPI SXWnd_SetMinimumSize(HWINDOW hWindow,int width,int height);
HELE WINAPI SXWnd_HitChildEle(HWINDOW hWindow,POINT * pPt);
int WINAPI SXWnd_GetChildCount(HWINDOW hWindow);
HELE WINAPI SXWnd_GetChildByIndex(HWINDOW hWindow,int index);
HELE WINAPI SXWnd_GetChildByID(HWINDOW hWindow,int nID);
HELE WINAPI SXWnd_GetEle(HWINDOW hWindow,int nID);
int WINAPI SXWnd_GetChildShapeCount(HWINDOW hWindow);
HXCGUI WINAPI SXWnd_GetChildShapeByIndex(HWINDOW hWindow,int index);
void WINAPI SXWnd_GetDrawRect(HWINDOW hWindow,RECT * pRcPaint);
BOOL WINAPI SXWnd_ShowWindow(HWINDOW hWindow,int nCmdShow);
void WINAPI SXWnd_AdjustLayout(HWINDOW hWindow);
void WINAPI SXWnd_AdjustLayoutObject(HWINDOW hWindow);
void WINAPI SXWnd_CloseWindow(HWINDOW hWindow);
void WINAPI SXWnd_CreateCaret(HWINDOW hWindow,HELE hEle,int x,int y,int width,int height);
void WINAPI SXWnd_SetCaretSize(HWINDOW hWindow,int width,int height);
void WINAPI SXWnd_SetCaretPos(HWINDOW hWindow,int x,int y);
void WINAPI SXWnd_SetCaretPosEx(HWINDOW hWindow,int x,int y,int width,int height);
void WINAPI SXWnd_SetCaretColor(HWINDOW hWindow,COLORREF color);
void WINAPI SXWnd_ShowCaret(HWINDOW hWindow,BOOL bShow);
void WINAPI SXWnd_DestroyCaret(HWINDOW hWindow);
HELE WINAPI SXWnd_GetCaretHELE(HWINDOW hWindow);
BOOL WINAPI SXWnd_GetClientRect(HWINDOW hWindow,out_ RECT * pRect);
void WINAPI SXWnd_GetBodyRect(HWINDOW hWindow,out_ RECT * pRect);
UINT WINAPI SXWnd_SetTimer(HWINDOW hWindow,UINT nIDEvent,UINT uElapse);
BOOL WINAPI SXWnd_KillTimer(HWINDOW hWindow,UINT nIDEvent);
BOOL WINAPI SXWnd_SetXCTimer(HWINDOW hWindow,UINT nIDEvent,UINT uElapse);
BOOL WINAPI SXWnd_KillXCTimer(HWINDOW hWindow,UINT nIDEvent);
HBKM WINAPI SXWnd_GetBkManager(HWINDOW hWindow);
void WINAPI SXWnd_SetTransparentType(HWINDOW hWindow,window_transparent_ nType);
void WINAPI SXWnd_SetTransparentAlpha(HWINDOW hWindow,BYTE alpha);
void WINAPI SXWnd_SetTransparentColor(HWINDOW hWindow,COLORREF color);
void WINAPI SXWnd_SetShadowInfo(HWINDOW hWindow,int nSize,int nDepth,int nAngeleSize,BOOL bRightAngle,COLORREF color);
window_transparent_ WINAPI SXWnd_GetTransparentType(HWINDOW hWindow);
void WINAPI SXWnd_EnableCSS(HWINDOW hWindow,BOOL bEnable);
void WINAPI SXWnd_SetCssName(HWINDOW hWindow,const wchar_t * pName);
const wchar_t* WINAPI SXWnd_GetCssName(HWINDOW hWindow);
//BOOL WINAPI SXWnd_RegEventTest(int nEvent,BYTE* pParamType);
BOOL WINAPI SXEle_IsChildEle(HWINDOW hWindow,HELE hEle,HELE hChildEle);
void WINAPI SXWnd_GetShadowInfo(HWINDOW hWindow,int * pnSize,int * pnDepth,int * pnAngeleSize,BOOL * pbRightAngle,COLORREF * pColor);


#endif // sxcgui_h__