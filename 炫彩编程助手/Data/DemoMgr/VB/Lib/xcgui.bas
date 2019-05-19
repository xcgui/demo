Attribute VB_Name = "XCGUI"


Declare Function XDateTime_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XDateTime_SetStyle Lib "xcgui.dll" (ByVal hEle As Long, ByVal nStyle As Long)
Declare Function XDateTime_GetStyle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XDateTime_GetTime Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnHour As Long, ByVal pnMinute As Long, ByVal pnSecond As Long)
Declare Sub XDateTime_SetTime Lib "xcgui.dll" (ByVal hEle As Long, ByVal nHour As Long, ByVal nMinute As Long, ByVal nSecond As Long)
Declare Sub XDateTime_GetDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnYear As Long, ByVal pnMonth As Long, ByVal pnDay As Long)
Declare Sub XDateTime_SetDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal nYear As Long, ByVal nMonth As Long, ByVal nDay As Long)
Declare Function XDateTime_GetSelBkColor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XDateTime_SetSelBkColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal crSelectBk As Long, ByVal alpha As Byte)
Declare Function XDateTime_GetButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long) As Long
Declare Function XMonthCal_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XMonthCal_SetToday Lib "xcgui.dll" (ByVal hEle As Long, ByVal nYear As Long, ByVal nMonth As Long, ByVal nDay As Long)
Declare Sub XMonthCal_GetToday Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnYear As Long, ByVal pnMonth As Long, ByVal pnDay As Long)
Declare Sub XMonthCal_SeSelDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal nYear As Long, ByVal nMonth As Long, ByVal nDay As Long)
Declare Sub XMonthCal_GetSelDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnYear As Long, ByVal pnMonth As Long, ByVal pnDay As Long)
Declare Function XMonthCal_GetButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long) As Long
Declare Function XC_UnicodeToAnsi Lib "xcgui.dll" (ByVal pIn As String, ByVal inLen As Long, ByVal pOut As String, ByVal outLen As Long) As Long
Declare Function XC_AnsiToUnicode Lib "xcgui.dll" (ByVal pIn As String, ByVal inLen As Long, ByVal pOut As String, ByVal outLen As Long) As Long
Declare Sub XC_DebugToFileInfo Lib "xcgui.dll" (ByVal pInfo As String)
Declare Function XC_IsHELE Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XC_IsHWINDOW Lib "xcgui.dll" (ByVal hWindow As Long) As Boolean
Declare Function XC_IsShape Lib "xcgui.dll" (ByVal hShape As Long) As Boolean
Declare Function XC_IsHXCGUI Lib "xcgui.dll" (ByVal hXCGUI As Long, ByVal nType As Long) As Boolean
Declare Function XC_hWindowFromHWnd Lib "xcgui.dll" (ByVal hWnd As Long) As Long
Declare Function XC_RegisterWindowClassName Lib "xcgui.dll" (ByVal pClassName As String) As Boolean
Declare Function XC_IsSViewExtend Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XC_GetObjectType Lib "xcgui.dll" (ByVal hXCGUI As Long) As Long
Declare Function XC_GetObjectByID Lib "xcgui.dll" (ByVal nID As Long) As Long
Declare Function XC_GetResIDValue Lib "xcgui.dll" (ByVal pName As String) As Long
Declare Sub XC_SetPaintFrequency Lib "xcgui.dll" (ByVal nMilliseconds As Long)
Declare Function XC_RectInRect Lib "xcgui.dll" (ByVal pRect1 As rect, ByVal pRect2 As rect) As Boolean
Declare Sub XC_CombineRect Lib "xcgui.dll" (ByVal pDest As rect, ByVal pSrc1 As rect, ByVal pSrc2 As rect)
Declare Sub XC_ShowLayoutFrame Lib "xcgui.dll" (ByVal bShow As Boolean)
Declare Sub XC_EnableDebugFile Lib "xcgui.dll" (ByVal bEnable As Boolean)
Declare Sub XC_SetLayoutFrameColor Lib "xcgui.dll" (ByVal color As Long)
Declare Sub XC_EnableErrorMessageBox Lib "xcgui.dll" (ByVal bEnabel As Boolean)
Declare Function XC_LoadLayout Lib "xcgui.dll" (ByVal pFileName As String, ByVal hParent As Long) As Long
Declare Function XC_LoadLayoutFromString Lib "xcgui.dll" (ByVal pStringXML As String, ByVal hParent As Long) As Long
Declare Function XC_LoadResource Lib "xcgui.dll" (ByVal pFileName As String, ByVal pDir As String) As Boolean
Declare Function XC_LoadResourceFromString Lib "xcgui.dll" (ByVal pStringXML As String, ByVal pDir As String) As Boolean
Declare Function XC_LoadTemplate Lib "xcgui.dll" (ByVal nType As Long, ByVal pFileName As String) As template_info_i
Declare Function XC_LoadTemplateFromString Lib "xcgui.dll" (ByVal nType As Long, ByVal pStringXML As String) As template_info_i
Declare Sub XC_TemplateDestroy Lib "xcgui.dll" (ByVal pInfo As template_info_i)
Declare Sub XC_GetTextSize Lib "xcgui.dll" (ByVal pString As String, ByVal length As Long, ByVal hFontx As Long, ByVal pOutSize As size)
Declare Sub XC_GetTextShowSize Lib "xcgui.dll" (ByVal pString As String, ByVal length As Long, ByVal hFontx As Long, ByVal pOutSize As size)
Declare Function XC_GetDefaultFont Lib "xcgui.dll" () As Long
Declare Sub XC_SetDefaultFont Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Sub XC_InitFont Lib "xcgui.dll" (ByVal pFont As LOGFONTW, ByVal pName As String, ByVal size As Long, ByVal bBold As Boolean, ByVal bItalic As Boolean, ByVal bUnderline As Boolean, ByVal bStrikeOut As Boolean)
Declare Function XC_Malloc Lib "xcgui.dll" (ByVal size As Long) As Long
Declare Sub XC_Free Lib "xcgui.dll" (ByVal p As Long)
'Declare Sub _XC_SetType Lib "xcgui.dll" (ByVal hXCGUI As Long,ByVal nType As Long)
'Declare Sub _XC_AddType Lib "xcgui.dll" (ByVal hXCGUI As Long,ByVal nType As Long)
'Declare Sub _XC_BindData Lib "xcgui.dll" (ByVal hXCGUI As Long,ByVal data As Long)
'Declare Function _XC_GetBindData Lib "xcgui.dll" (ByVal hXCGUI As Long) As Long
Declare Function XInitXCGUI Lib "xcgui.dll" (ByVal pText As String) As Boolean
Declare Sub XRunXCGUI Lib "xcgui.dll" ()
Declare Sub XExitXCGUI Lib "xcgui.dll" ()
Declare Function XBkInfoM_Create Lib "xcgui.dll" () As Long
Declare Sub XBkInfoM_Destroy Lib "xcgui.dll" (ByVal hBkInfoM As Long)
Declare Function XBkInfoM_SetBkInfo Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal pText As String) As Long
Declare Sub XBkInfoM_AddBorder Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XBkInfoM_AddFill Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XBkInfoM_AddImage Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XBkInfoM_GetCount Lib "xcgui.dll" (ByVal hBkInfoM As Long) As Long
Declare Sub XBkInfoM_Clear Lib "xcgui.dll" (ByVal hBkInfoM As Long)
Declare Function XBkInfoM_Draw Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal hDraw As Long, ByVal pRect As rect) As Boolean
Declare Function XBkInfoM_DrawEx Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal hDraw As Long, ByVal pRect As rect, ByVal nStateFilter As Long) As Boolean
Declare Function XBtn_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal pName As String, ByVal hParent As Long) As Long
Declare Function XBtn_IsCheck Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XBtn_SetCheck Lib "xcgui.dll" (ByVal hEle As Long, ByVal bCheck As Boolean) As Boolean
Declare Sub XBtn_SetState Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long)
Declare Function XBtn_GetState Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XBtn_GetStateEx Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetStyle Lib "xcgui.dll" (ByVal hEle As Long, ByVal nStyle As Long)
Declare Function XBtn_GetStyle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetType Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long)
Declare Function XBtn_GetType Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetGroupID Lib "xcgui.dll" (ByVal hEle As Long, ByVal nID As Long)
Declare Function XBtn_GetGroupID Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetBindEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal hBindEle As Long)
Declare Function XBtn_GetBindEle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetTextAlign Lib "xcgui.dll" (ByVal hEle As Long, ByVal nFlags As Long)
Declare Function XBtn_GetTextAlign Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetIconAlign Lib "xcgui.dll" (ByVal hEle As Long, ByVal align As Long)
Declare Sub XBtn_SetOffset Lib "xcgui.dll" (ByVal hEle As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XBtn_SetOffsetIcon Lib "xcgui.dll" (ByVal hEle As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XBtn_SetIconSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal size As Long)
Declare Sub XBtn_GetText Lib "xcgui.dll" (ByVal hEle As Long, ByVal pOut As Long, ByVal nOutLen As Long)
Declare Sub XBtn_SetText Lib "xcgui.dll" (ByVal hEle As Long, ByVal pName As String)
Declare Sub XBtn_SetIcon Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Sub XBtn_SetIconDisable Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Sub XBtn_AddAnimationFrame Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long, ByVal uElapse As Long)
Declare Sub XBtn_EnableAnimation Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean, ByVal bLoopPlay As Boolean)
Declare Sub XBtn_AddBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XBtn_AddBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XBtn_AddBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XBtn_GetBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_ClearBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XComboBox_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XComboBox_SetSelItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal iIndex As Long) As Boolean
Declare Sub XComboBox_GetButtonRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XComboBox_SetButtonSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal size As Long)
Declare Sub XComboBox_SetDropHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal height As Long)
Declare Function XComboBox_GetDropHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XComboBox_BindApapter Lib "xcgui.dll" (ByVal hEle As Long, ByVal hAdapter As Long)
Declare Function XComboBox_GetApapter Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XComboBox_SetItemTemplateXML Lib "xcgui.dll" (ByVal hEle As Long, ByVal pXmlFile As String)
Declare Sub XComboBox_SetItemTemplateXMLFromString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pStringXML As String)
Declare Sub XComboBox_EnableDrawButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XComboBox_EnableEdit Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEdit As Boolean)
Declare Sub XComboBox_AddBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XComboBox_AddBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XComboBox_AddBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XComboboX_GetBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XComboBox_ClearBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XComboBox_GetSelItem Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XComboBox_GetState Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XAdapter_Destroy Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Function XAdapterListView_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterListView_Group_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterListView_Group_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pValue As String) As Long
Declare Function XAdapterListView_Group_AddItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String) As Long
Declare Function XAdapterListView_Group_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Group_AddItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Group_SetText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Group_SetTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Group_SetImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Group_SetImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Group_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterListView_Item_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long) As Long
Declare Function XAdapterListView_Item_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterListView_Item_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pValue As String) As Long
Declare Function XAdapterListView_Item_AddItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal pValue As String) As Long
Declare Function XAdapterListView_Item_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Item_AddItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Item_SetText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Item_SetTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Item_SetImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Item_SetImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Group_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long) As Boolean
Declare Sub XAdapterListView_Group_DeleteAllChildItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long)
Declare Function XAdapterListView_Item_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long) As Boolean
Declare Sub XAdapterListView_DeleteAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterListView_DeleteAllGroup Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterListView_DeleteAllItem Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterListView_DeleteColumnGroup Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iColumn As Long)
Declare Sub XAdapterListView_DeleteColumnItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iColumn As Long)
Declare Function XAdapterListView_Item_GetTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterListView_Item_GetImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String) As Long
Declare Function XAdapterTable_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterTable_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterTable_SetColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pColName As String) As Long
Declare Function XAdapterTable_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pValue As String) As Long
Declare Function XAdapterTable_AddItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String) As Long
Declare Function XAdapterTable_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal hImage As Long) As Long
Declare Function XAdapterTable_AddItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long) As Long
Declare Function XAdapterTable_InsertItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_InsertItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_InsertItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_InsertItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_SetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_SetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_SetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_SetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long) As Boolean
Declare Function XAdapterTable_DeleteItemEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal nCount As Long) As Boolean
Declare Sub XAdapterTable_DeleteItemAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterTable_DeleteColumnAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Function XAdapterTable_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTable_GetCountColumn Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTable_GetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterTable_GetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long) As Long
Declare Function XAdapterTable_GetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterTable_GetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String) As Long
Declare Function XAdapterTree_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterTree_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterTree_SetColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pColName As String) As Long
Declare Function XAdapterTree_InsertItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pValue As String, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_InsertItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_InsertItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal hImage As Long, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_InsertItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTree_GetCountColumn Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTree_SetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterTree_SetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterTree_SetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterTree_SetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterTree_GetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterTree_GetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String) As Long
Declare Function XAdapterTree_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long) As Boolean
Declare Sub XAdapterTree_DeleteItemAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterTree_DeleteColumnAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Function XAdapterMap_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterMap_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterMap_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterMap_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Boolean
Declare Function XAdapterMap_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterMap_GetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterMap_GetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
'Declare Sub _XC_DebugPrintf Lib "xcgui.dll" (ByVal level As Long,ByVal pFormat As String,ByVal 点点点 As Long)
'Declare Sub _XC_DebugPrintfW Lib "xcgui.dll" (ByVal level As Long,ByVal pFormat As String,ByVal 点点点 As Long)
'Declare Sub xtrace Lib "xcgui.dll" (ByVal pFormat As String, ByVal 点点点 As Long)
'Declare Sub xtracew Lib "xcgui.dll" (ByVal pFormat As String, ByVal 点点点 As Long)
Declare Function XDraw_Create Lib "xcgui.dll" (ByVal hdc As Long) As Long
Declare Sub XDraw_Destroy Lib "xcgui.dll" (ByVal hDraw As Long)
Declare Sub XDraw_SetOffset Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XDraw_GetOffset Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pX As Long, ByVal pY As Long)
Declare Sub XDraw_RestoreGDIOBJ Lib "xcgui.dll" (ByVal hDraw As Long)
Declare Function XDraw_GetHDC Lib "xcgui.dll" (ByVal hDraw As Long) As Long
Declare Sub XDraw_SetBrushColor Lib "xcgui.dll" (ByVal hDraw As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XDraw_SetTextAlign Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nFlag As Long)
Declare Sub XDraw_SetTextVertical Lib "xcgui.dll" (ByVal hDraw As Long, ByVal bVertical As Boolean)
Declare Sub XDraw_SetFontX Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hFontx As Long)
Declare Sub XDraw_SetFont Lib "xcgui.dll" (ByVal hDraw As Long, ByVal size As Long)
Declare Sub XDraw_SetFont2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pName As String, ByVal size As Long)
Declare Sub XDraw_SetFont3 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pLogFont As LOGFONT)
Declare Sub XDraw_SetLineWidth Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nWidth As Long)
Declare Function XDraw_SetBkMode Lib "xcgui.dll" (ByVal hDraw As Long, ByVal bTransparent As Boolean) As Long
Declare Sub XDraw_EnableSmoothingMode Lib "xcgui.dll" (ByVal hDraw As Long, ByVal bEnable As Boolean)
Declare Function XDraw_CreateSolidBrush Lib "xcgui.dll" (ByVal hDraw As Long, ByVal crColor As Long) As Long
Declare Function XDraw_CreatePen Lib "xcgui.dll" (ByVal hDraw As Long, ByVal fnPenStyle As Long, ByVal nWidth As Long, ByVal crColor As Long) As Long
Declare Function XDraw_CreateRectRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nLeftRect As Long, ByVal nTopRect As Long, ByVal nRightRect As Long, ByVal nBottomRect As Long) As Long
Declare Function XDraw_CreateRoundRectRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nLeftRect As Long, ByVal nTopRect As Long, ByVal nRightRect As Long, ByVal nBottomRect As Long, ByVal nWidthEllipse As Long, ByVal nHeightEllipse As Long) As Long
Declare Function XDraw_CreatePolygonRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pPt As Point, ByVal cPoints As Long, ByVal fnPolyFillMode As Long) As Long
Declare Function XDraw_SelectClipRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hrgn As Long) As Long
Declare Sub XDraw_FillRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_FillRectColor Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal color As Long, ByVal alpha As Byte)
Declare Function XDraw_FillRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hrgn As Long, ByVal hbr As Long) As Boolean
Declare Sub XDraw_FillEllipse Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_DrawEllipse Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_FillRoundRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Sub XDraw_DrawRoundRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Function XDraw_Rectangle Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nLeftRect As Long, ByVal nTopRect As Long, ByVal nRightRect As Long, ByVal nBottomRect As Long) As Boolean
Declare Sub XDraw_DrawGroupBox_Rect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal pName As String, ByVal textColor As Long, ByVal textAlpha As Byte, ByVal pOffset As Point)
Declare Sub XDraw_DrawGroupBox_RoundRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal pName As String, ByVal textColor As Long, ByVal textAlpha As Byte, ByVal pOffset As Point, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Sub XDraw_GradientFill2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal color1 As Long, ByVal alpha1 As Byte, ByVal color2 As Long, ByVal alpha2 As Byte, ByVal pRect As rect, ByVal mode As Long)
Declare Function XDraw_GradientFill4 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal color1 As Long, ByVal color2 As Long, ByVal color3 As Long, ByVal color4 As Long, ByVal pRect As rect, ByVal mode As Long) As Boolean
Declare Function XDraw_FrameRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hrgn As Long, ByVal hbr As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Boolean
Declare Sub XDraw_FrameRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_FocusRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_DrawLine Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long)
Declare Function XDraw_MoveToEx Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long, ByVal lpPoint As Point) As Boolean
Declare Function XDraw_LineTo Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXEnd As Long, ByVal nYEnd As Long) As Boolean
Declare Function XDraw_Polyline Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pArrayPt As Point, ByVal arrayPtSize As Long) As Boolean
Declare Sub XDraw_Dottedline Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long)
Declare Function XDraw_SetPixel Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long, ByVal crColor As Long) As Long
Declare Sub XDraw_Check Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long, ByVal color As Long, ByVal bCheck As Boolean)
Declare Function XDraw_DrawIconEx Lib "xcgui.dll" (ByVal hDraw As Long, ByVal xLeft As Long, ByVal yTop As Long, ByVal hIcon As Long, ByVal cxWidth As Long, ByVal cyWidth As Long, ByVal istepIfAniCur As Long, ByVal hbrFlickerFreeDraw As Long, ByVal diFlags As Long) As Boolean
Declare Function XDraw_BitBlt Lib "xcgui.dll" (ByVal hDrawDest As Long, ByVal nXDest As Long, ByVal nYDest As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hdcSrc As Long, ByVal nXSrc As Long, ByVal nYSrc As Long, ByVal dwRop As Long) As Boolean
Declare Function XDraw_BitBlt2 Lib "xcgui.dll" (ByVal hDrawDest As Long, ByVal nXDest As Long, ByVal nYDest As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hDrawSrc As Long, ByVal nXSrc As Long, ByVal nYSrc As Long, ByVal dwRop As Long) As Boolean
Declare Function XDraw_AlphaBlend Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXOriginDest As Long, ByVal nYOriginDest As Long, ByVal nWidthDest As Long, ByVal nHeightDest As Long, ByVal hdcSrc As Long, ByVal nXOriginSrc As Long, ByVal nYOriginSrc As Long, ByVal nWidthSrc As Long, ByVal nHeightSrc As Long, ByVal alpha As Long) As Boolean
Declare Sub XDraw_TriangularArrow Lib "xcgui.dll" (ByVal hDraw As Long, ByVal align As Long, ByVal x As Long, ByVal y As Long, ByVal width As Long, ByVal height As Long)
Declare Sub XDraw_DrawPolygon Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As Point, ByVal nCount As Long)
Declare Sub XDraw_DrawPolygonF Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As POINTF, ByVal nCount As Long)
Declare Sub XDraw_FillPolygon Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As Point, ByVal nCount As Long)
Declare Sub XDraw_FillPolygonF Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As POINTF, ByVal nCount As Long)
Declare Sub XDraw_Image Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XDraw_Image2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal x As Long, ByVal y As Long, ByVal width As Long, ByVal height As Long)
Declare Sub XDraw_ImageStretch Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal x As Long, ByVal y As Long, ByVal width As Long, ByVal height As Long)
Declare Sub XDraw_ImageAdaptive Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRect As rect, ByVal bOnlyBorder As Boolean)
Declare Sub XDraw_ImageExTile Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRect As rect, ByVal flag As Long)
Declare Sub XDraw_ImageSuper Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRect As rect, ByVal bClip As Boolean)
Declare Sub XDraw_ImageSuper2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRcDest As rect, ByVal pSrcRect As rect)
Declare Sub XDraw_DrawText Lib "xcgui.dll" (ByVal hDraw As Long, ByVal lpString As String, ByVal nCount As Long, ByVal lpRect As rect)
Declare Sub XDraw_DrawTextUnderline Lib "xcgui.dll" (ByVal hDraw As Long, ByVal lpString As String, ByVal nCount As Long, ByVal lpRect As rect, ByVal colorLine As Long, ByVal alphaLine As Byte)
Declare Sub XDraw_TextOut Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXStart As Long, ByVal nYStart As Long, ByVal lpString As String, ByVal cbString As Long)
Declare Sub XDraw_TextOutEx Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXStart As Long, ByVal nYStart As Long, ByVal lpString As String)
Declare Sub XDraw_TextOutA Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXStart As Long, ByVal nYStart As Long, ByVal lpString As String)
Declare Sub XDraw_SetAlpha Lib "xcgui.dll" (ByVal hDraw As Long, ByVal alpha As Byte)
Declare Sub XDraw_SetAlphaEx Lib "xcgui.dll" (ByVal hdc As Long, ByVal alpha As Byte)
Declare Function XEle_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XEle_RegEventEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal pEvent As Long)
Declare Function XEle_RemoveEventEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal pEvent As Long) As Boolean
Declare Sub XEle_RegEventC Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long)
Declare Sub XEle_RegEventC1 Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long)
Declare Sub XEle_RegEventC2 Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long)
Declare Function XEle_RemoveEventC Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long) As Boolean
Declare Function XEle_SendEvent Lib "xcgui.dll" (ByVal hEle As Long, ByVal hEventEle As Long, ByVal nEvent As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function XEle_PostEvent Lib "xcgui.dll" (ByVal hEle As Long, ByVal hEventEle As Long, ByVal nEvent As Long, ByVal wParam As Long, ByVal lParam As Long) As Boolean
Declare Function XEle_IsShow Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnable Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnableFocus Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsDrawFocus Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnableEvent_XE_PAINT_END Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsMouseThrough Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsBkTransparent Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsKeyTab Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsSwitchFocus Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnable_XE_MOUSEWHEEL Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Sub XEle_Enable Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableDrawFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableEvent_XE_PAINT_END Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableBkTransparent Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableMouseThrough Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableKeyTab Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableSwitchFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableEvent_XE_MOUSEWHEEL Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Function XEle_SetRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect, ByVal bRedraw As Boolean) As Boolean
Declare Function XEle_SetRectEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal bRedraw As Boolean) As Boolean
Declare Function XEle_SetRectLogic Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect, ByVal bRedraw As Boolean) As Boolean
Declare Sub XEle_GetRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_GetRectLogic Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_GetClientRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_GetWndClientRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Function XEle_GetWidth Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_RectWndClientToEleClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_PointWndClientToEleClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point)
Declare Sub XEle_RectClientToWndClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_PointClientToWndClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point)
Declare Function XEle_AddEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal hChildEle As Long) As Boolean
Declare Function XEle_InsertEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal hChildEle As Long, ByVal index As Long) As Boolean
Declare Sub XEle_RemoveEle Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XEle_AddShape Lib "xcgui.dll" (ByVal hEle As Long, ByVal hShape As Long) As Boolean
Declare Function XEle_SetZOrder Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Boolean
Declare Function XEle_SetZOrderEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal hDestEle As Long, ByVal nType As Long) As Boolean
Declare Function XEle_GetZOrder Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_ShowEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal bShow As Boolean)
Declare Function XEle_GetType Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetHWND Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetHWINDOW Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetCursor Lib "xcgui.dll" (ByVal hEle As Long, ByVal hCursor As Long)
Declare Function XEle_GetCursor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetID Lib "xcgui.dll" (ByVal hEle As Long, ByVal id As Long)
Declare Function XEle_GetID Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetParentEle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetParent Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetTextColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XEle_GetTextColor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetFocusBorderColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XEle_GetFocusBorderColor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetFont Lib "xcgui.dll" (ByVal hEle As Long, ByVal hFontx As Long)
Declare Function XEle_GetFont Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetAlpha Lib "xcgui.dll" (ByVal hEle As Long, ByVal alpha As Byte)
Declare Function XEle_GetChildCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetChildByIndex Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Function XEle_GetChildByID Lib "xcgui.dll" (ByVal hEle As Long, ByVal id As Long) As Long
Declare Function XEle_GetChildShapeCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetChildShapeByIndex Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Function XEle_HitChildEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point) As Long
Declare Sub XEle_BindLayoutObject Lib "xcgui.dll" (ByVal hEle As Long, ByVal hLayout As Long)
Declare Function XEle_GetLayoutObject Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetParentLayoutObject Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetUserData Lib "xcgui.dll" (ByVal hEle As Long, ByVal nData As Long)
Declare Function XEle_GetUserData Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_GetContentSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal pSize As size)
Declare Sub XEle_SetCapture Lib "xcgui.dll" (ByVal hEle As Long, ByVal b As Boolean)
Declare Sub XEle_SetLayoutWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long, ByVal nWidth As Long)
Declare Sub XEle_SetLayoutHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long, ByVal nHeight As Long)
Declare Sub XEle_GetLayoutWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal pType As Long, ByVal pWidth As Long)
Declare Sub XEle_GetLayoutHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal pType As Long, ByVal pHeight As Long)
Declare Sub XEle_RedrawEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal bImmediate As Boolean)
Declare Sub XEle_RedrawRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect, ByVal bImmediate As Boolean)
Declare Sub XEle_Destroy Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XEle_AddBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XEle_AddBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XEle_AddBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Function XEle_GetBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_ClearBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XEle_GetBkInfoManager Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetStateFlags Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_DrawFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal hDraw As Long, ByVal pRect As rect) As Boolean
Declare Sub XEle_EnableTransparentChannel Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_SetToolTip Lib "xcgui.dll" (ByVal hEle As Long, ByVal pText As String)
Declare Sub XEle_GetToolTip Lib "xcgui.dll" (ByVal hEle As Long, ByVal pOut As Long, ByVal nOutLen As Long)
Declare Sub XEle_EnableToolTip Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_AdjustLayoutObject Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XEle_AdjustLayout Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XEle_RegEventTest Lib "xcgui.dll" (ByVal nEvent As Long, ByVal pParamType As Long) As Boolean
Declare Function XFont_Create Lib "xcgui.dll" (ByVal size As Long) As Long
Declare Function XFont_Create2 Lib "xcgui.dll" (ByVal pName As String, ByVal size As Long, ByVal bBold As Boolean, ByVal bItalic As Boolean, ByVal bUnderline As Boolean, ByVal bStrikeOut As Boolean) As Long
Declare Function XFont_Create3 Lib "xcgui.dll" (ByVal pInfo As xc_font_info_i) As Long
Declare Function XFont_CreateEx Lib "xcgui.dll" (ByVal pFontInfo As LOGFONTW) As Long
Declare Function XFont_CreateFromHFONT Lib "xcgui.dll" (ByVal hFont As Long) As Long
Declare Function XFont_CreateFromFont Lib "xcgui.dll" (ByVal pFont As Long) As Long
Declare Sub XFont_EnableAutoDestroy Lib "xcgui.dll" (ByVal hFontx As Long, ByVal bEnable As Boolean)
Declare Function XFont_GetFont Lib "xcgui.dll" (ByVal hFontx As Long) As Long
Declare Sub XFont_GetFontInfo Lib "xcgui.dll" (ByVal hFontx As Long, ByVal pInfo As xc_font_info_i)
Declare Sub XFont_AddRef Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Sub XFont_Release Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Function XFont_GetRefCount Lib "xcgui.dll" (ByVal hFontx As Long) As Long
Declare Sub XFont_Destroy Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Function XFrameWnd_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal pTitle As String, ByVal hWndParent As Long, ByVal XCStyle As Long) As Long
Declare Function XFrameWnd_CreateEx Lib "xcgui.dll" (ByVal dwExStyle As Long, ByVal lpClassName As String, ByVal lpWindowName As String, ByVal dwStyle As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hWndParent As Long, ByVal XCStyle As Long) As Long
Declare Sub XFrameWnd_GetLayoutAreaRect Lib "xcgui.dll" (ByVal hWindow As Long, ByVal pRect As rect)
Declare Sub XFrameWnd_SetView Lib "xcgui.dll" (ByVal hWindow As Long, ByVal hEle As Long)
Declare Sub XFrameWnd_SetPaneSplitBarColor Lib "xcgui.dll" (ByVal hWindow As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XFrameWnd_AddPane Lib "xcgui.dll" (ByVal hWindow As Long, ByVal hPaneDest As Long, ByVal hPaneNew As Long, ByVal align As Long) As Boolean
Declare Function XFrameWnd_MergePane Lib "xcgui.dll" (ByVal hWindow As Long, ByVal hPaneDest As Long, ByVal hPaneNew As Long) As Boolean
Declare Function XImage_LoadFile Lib "xcgui.dll" (ByVal pImageName As String, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadFileAdaptive Lib "xcgui.dll" (ByVal pImageName As String, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Long
Declare Function XImage_LoadFileRect Lib "xcgui.dll" (ByVal pImageName As String, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long) As Long
Declare Function XImage_LoadResAdaptive Lib "xcgui.dll" (ByVal id As Long, ByVal pType As String, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Long
Declare Function XImage_LoadRes Lib "xcgui.dll" (ByVal id As Long, ByVal pType As String, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadZip Lib "xcgui.dll" (ByVal pZipFileName As String, ByVal pImageName As String, ByVal pPassword As String, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadZipAdaptive Lib "xcgui.dll" (ByVal pZipFileName As String, ByVal pImageName As String, ByVal pPassword As String, ByVal x1 As Long, ByVal x2 As Long, ByVal y1 As Long, ByVal y2 As Long) As Long
Declare Function XImage_LoadZipRect Lib "xcgui.dll" (ByVal pZipFileName As String, ByVal pImageName As String, ByVal pPassword As String, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long) As Long
Declare Function XImage_LoadMemory Lib "xcgui.dll" (ByVal pBuffer As Long, ByVal nSize As Long, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadMemoryRect Lib "xcgui.dll" (ByVal pBuffer As Long, ByVal nSize As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadMemoryAdaptive Lib "xcgui.dll" (ByVal pBuffer As Long, ByVal nSize As Long, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Long
Declare Function XImage_LoadFromImage Lib "xcgui.dll" (ByVal pImage As Long) As Long
Declare Function XImage_LoadFileFromExtractIcon Lib "xcgui.dll" (ByVal pImageName As String) As Long
Declare Function XImage_LoadFileFromHICON Lib "xcgui.dll" (ByVal hIcon As Long) As Long
Declare Function XImage_LoadFileFromHBITMAP Lib "xcgui.dll" (ByVal hBitmap As Long) As Long
Declare Function XImage_IsStretch Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_IsAdaptive Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_IsTile Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_SetDrawType Lib "xcgui.dll" (ByVal hImage As Long, ByVal nType As Long) As Boolean
Declare Function XImage_SetDrawTypeAdaptive Lib "xcgui.dll" (ByVal hImage As Long, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Boolean
Declare Sub XImage_SetTranColor Lib "xcgui.dll" (ByVal hImage As Long, ByVal color As Long)
Declare Sub XImage_SetTranColorEx Lib "xcgui.dll" (ByVal hImage As Long, ByVal color As Long, ByVal tranColor As Byte)
Declare Function XImage_SetRotateAngle Lib "xcgui.dll" (ByVal hImage As Long, ByVal fAngle As Single) As Single
Declare Sub XImage_EnableTranColor Lib "xcgui.dll" (ByVal hImage As Long, ByVal bEnable As Boolean)
Declare Sub XImage_EnableAutoDestroy Lib "xcgui.dll" (ByVal hImage As Long, ByVal bEnable As Boolean)
Declare Sub XImage_EnableCenter Lib "xcgui.dll" (ByVal hImage As Long, ByVal bCenter As Boolean)
Declare Function XImage_IsCenter Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_GetDrawType Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Function XImage_GetWidth Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Function XImage_GetHeight Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Sub XImage_AddRef Lib "xcgui.dll" (ByVal hImage As Long)
Declare Sub XImage_Release Lib "xcgui.dll" (ByVal hImage As Long)
Declare Function XImage_GetRefCount Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Sub XImage_Destroy Lib "xcgui.dll" (ByVal hImage As Long)



'
'
'vb6的数据类型有以下几种:
'Boolean数据类型 　　 变量存储为 16 位       只能是 True 或是 False
'Byte数据类型 　　　　变量存储为 8 位         范围在 0 至 255 之间
'Currency数据类型 　　变量存储为 64 位      范围可以从 -922,337,203,685,477.5808 到 922,337,203,685,477.5807
'Date数据类型 　　　　变量存储为  64 位
'                              日期范围从 100 年 1 月 1 日到 9999 年 12 月 31 日，
'                              时间可以从 0:00:00 到 23:59:59。
'
'Decimal数据类型　　  变量存储为 96 位
'
'Double数据类型 　　  变量存储为 64 位
'Integer数据类型 　　  变量存储为 16 位　　范围为 -32,768 到 32,767 之间
'Long数据类型 　　　　变量存储为 32 位　　范围从 -2,147,483,648 到 2,147,483,647
'Object数据类型 　　　存储为 32 位（4 个字节）的地址形式
'Single数据类型          变量存储为 IEEE 32 位
'
'String数据类型 字符串有两种: 变长与定长的字符串?
'                              变长字符串最多可包含大约 20 亿 ( 2^31)个字符。
'                              定长字符串可包含 1 到大约 64K ( 2^16 ) 个字符。
'用户定义数据类型
'Variant数据类型
'----------------------------------
'Boolean数据类型 Boolean 变量存储为 16 位（2 个字节）的数值形式，但只能是 True 或是 False。Boolean 变量的值显示为 True 或 False（在使用 Print 的时候），或者 #TRUE# 或 #FALSE#（在使用 Write # 的时候）。使用关键字 True 与 False 可将 Boolean 变量赋值为这两个状态中的一个。
'当转换其他的数值类型为 Boolean 值时，0 会转成 False，而其他的值则变成 True。当转换 Boolean 值为其他的数据类型时，False 成为 0，而 True 成为 -1。
'------------------------------------
'Byte数据类型
'Byte 变量存储为单精度型、无符号整型、8 位（1个字节）的数值形式，范围在 0 至 255 之间。
'Byte 数据类型在存储二进制数据时很有用。
'------------------------------------
'Currency数据类型
'Currency 变量存储为 64 位（8 个字节）整型的数值形式，然后除以 10,000 给出一个定点数，其小数点左边有 15 位数字，右边有 4 位数字。这种表示法的范围可以从 -922,337,203,685,477.5808 到 922,337,203,685,477.5807。Currency 的类型声明字符为at号 (@)。
'Currency 数据类型在货币计算与定点计算中很有用，在这种场合精度特别重要。
'------------------------------------
'Date数据类型
'Date 变量存储为 IEEE 64 位（8 个字节）浮点数值形式，其可以表示的日期范围从 100 年 1 月 1 日到 9999 年 12 月 31 日，而时间可以从 0:00:00 到 23:59:59。任何可辨认的文本日期都可以赋值给 Date 变量。日期文字须以数字符号 (#) 扩起来，例如，#January 1, 1993# 或 #1 Jan 93#。
'Date 变量会根据计算机中的短日期格式来显示。时间则根据计算机的时间格式（12 或 24 小时制）来显示。
'当其他的数值类型要转换为 Date 型时，小数点左边的值表示日期信息，而小数点右边的值则表示时间。午夜为 0 而中午为 0.5。负整数表示 1899 年 12 月 30 日之前的日期。
'------------------------------------------
'Decimal数据类型
'Decimal 变量存储为 96 位（12 个字节）无符号的整型形式，并除以一个 10 的幂数。这个变比因子决定了小数点右面的数字位数，其范围从 0 到 28。变比因子为 0（没有小数位）的情形下，最大的可能值为 +/-79,228,162,514,264,337,593,543,950,335。而在有 28 个小数位的情况下，最大值为 +/-7.9228162514264337593543950335，而最小的非零值为 +/-0.0000000000000000000000000001。
'注意 此时，Decimal 数据类型只能在 Variant中使用，也就是说，不能声明一变量为 Decimal 的类型。不过可用 Cdec 函数，创建一个子类型为 Decimal 的 Variant。
'-------------------------------------------
'Double数据类型
'Double（双精度浮点型）变量存储为 IEEE 64 位（8 个字节）浮点数值的形式，它的范围在负数的时候是从 -1.79769313486232E308 到 -4.94065645841247E-324，而正数的时候是从 4.94065645841247E-324 到 1.79769313486232E308。Double 的类型声明字符是数字符号 (#)。
'-------------------------------------------
'Integer数据类型
'Integer 变量存储为 16位（2 个字节）的数值形式，其范围为 -32,768 到 32,767 之间。Integer 的类型声明字符是百分比符号 (%)。
'也可以用 Integer 变量来表示枚举值。枚举值可包含一个有限集合，该集合包含的元素都是唯一的整数，每一个整数都在它使用时的上下文当中有其特殊意义。枚举值为在已知数量的选项中做出选择提供了一种方便的方法，例如，black = 0，white = 1 等等。较好的编程作法是使用 Const 语句将每个枚举值定义成常数。
'---------------------------------------------
'Long数据类型
'Long（长整型）变量存储为 32 位（4 个字节）有符号的数值形式，其范围从 -2,147,483,648 到 2,147,483,647。Long 的类型声明字符为和号 (&)。
'---------------------------------------------
'Object数据类型
'Object 变量存储为 32 位（4 个字节）的地址形式，其为对象的引用。利用 Set 语句，声明为 Object 的变量可以赋值为任何对象的引用。
'注意 虽然以 Object 类型声明的变量足以适应包含对各种对象的引用，但是绑定到变量引用的对象总是在晚期（运行时）绑定。要强迫在早期（编译时间）绑定的话，须将对象的引用赋值给用特定类名称声明的变量。
'-----------------------------------------------
'Single数据类型
'Single（单精度浮点型）变量存储为 IEEE 32 位（4 个字节）浮点数值的形式，它的范围在负数的时候是从 -3.402823E38 到 -1.401298E-45，而在正数的时候是从 1.401298E-45 到 3.402823E38。Single 的类型声明字符为感叹号 (!)。
'------------------------------------------------
'String数据类型
'字符串有两种: 变长与定长的字符串?
'变长字符串最多可包含大约 20 亿 ( 2^31)个字符。
'定长字符串可包含 1 到大约 64K ( 2^16 ) 个字符。
'注意 Public 定长字符串不能在类模块中使用。
'String 之字符码的范围是 0 到 255。字符集的前 128 个字符（0 到 127）对应于标准的 U.S. 键盘上的字符与符号。这前 128 个字符与 ASCII 字符集中所定义的相同。后 128 个字符（128 到 255）则代表特殊字符，例如国际字符，重音符号，货币符号及分数。String 的类型声明字符为美元号 ($)。
'---------------------------------------------------
'Variant数据类型
'
'Variant 数据类型是所有没被显式声明（用如 Dim、Private、Public 或 Static等语句）为其他类型变量的数据类型。Variant 数据类型并没有类型声明字符。
'
'Variant 是一种特殊的数据类型，除了定长 String 数据及用户定义类型外，可以包含任何种类的数据。Variant 也可以包含 Empty、Error、Nothing 及 Null等特殊值。可以用 VarType 函数或 TypeName 函数来决定如何处理 Variant 中的数据。
'
'数值数据可以是任何整型或实型数，负数时范围从 -1.797693134862315E308 到 -4.94066E-324，正数时则从 4.94066E-324 到 1.797693134862315E308。通常，数值Variant 数据保持为其 Variant 中原来的数据类型。例如，如果把一个 Integer赋值给 Variant，则接下来的运算会把此 Variant 当成 Integer 来处理。然而，如果算术运算针对含 Byte、Integer、Long 或 Single 之一的Variant 执行，并当结果超过原来数据类型的正常范围时，则在 Variant 中的结果会提升到较大的数据类型。如 Byte 则提升到 Integer，Integer 则提升到 Long，而 Long和Single 则提升为 Double。当 Variant 变量中有 Currency、Decimal 及 Double 值超过它们各自的范围时，会发生错误。
'
'可以用 Variant 数据类型来替换任何数据类型，这样会更有适应性。如果 Variant 变量的内容是数字，它可以用字符串来表示数字或是用它实际的值来表示，这将由上下文来决定，例如：
'
'Dim MyVar As Variant
'MyVar = 98052
'
'在前面的例子中，MyVar 内有一实际值为 98052 的数值。像期望的那样，算术运算子可以对 Variant 变量运算，其中包含数值或能被解释为数值的字符串数据。如果用 + 运算子来将 MyVar 与其他含有数字的 Variant 或数值类型的变量相加，结果便是一算术和。
'
'Empty 值用来标记尚未初始化（给定初始值）的Variant 变量。内含 Empty 的 Variant 在数值的上下文中表示 0，如果是用在字符串的上下文中则表示零长度的字符串 ("")。
'
'不应将 Empty 与 Null 弄混。Null 是表示 Variant 变量确实含有一个无效数据。
'
'在 Variant 中，Error 是用来指示在过程中出现错误时的特殊值。然而，不像对其他种类的错误那样，程序并不产生普通的应用程序级的错误处理。这可以让程序员，或应用程序本身，根据此错误值采取另外的行动。可以用 CVErr 函数将实数转换为错误值来产生 Error 值。
'--------------------------------------------------
'用户定义数据类型
'
'可以是任何用 Type 语句定义的数据类型。用户自定义类型可包含一个或多个某种数据类型的数据元素、数组或一个先前定义的用户自定义类型。例如：
'
'Type MyType
'  MyName As String  '定义字符串变量存储一个名字。
'  MyBirthDate As Date  '定义日期变量存储一个生日。
'  MySex As Integer  '定义整型变量存储性别
'End Type            '（0 为女，1 为男）
'
'
