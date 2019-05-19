Attribute VB_Name = "xcgui1"
Declare Function XLayout_Create Lib "xcgui.dll" () As Long
Declare Sub XLayout_Destroy Lib "xcgui.dll" (ByVal hLayout As Long)
Declare Sub XLayout_AddEle Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hEle As Long)
Declare Sub XLayout_AddLayoutObject Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hLayoutObject As Long)
Declare Sub XLayout_AddShape Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hShape As Long)
Declare Function XLayout_Add Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hChild As Long) As Boolean
Declare Function XLayout_Insert Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hChild As Long, ByVal index As Long) As Boolean
Declare Sub XLayout_RemoveLayout Lib "xcgui.dll" (ByVal hLayout As Long)
Declare Sub XLayout_RemoveChild Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hChild As Long)
Declare Function XLayout_GetZOrder Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hChild As Long) As Long
Declare Sub XLayout_AdjustLayout Lib "xcgui.dll" (ByVal hLayout As Long)
Declare Sub XLayout_SetRectFrame Lib "xcgui.dll" (ByVal hLayout As Long, ByVal pRect As rect)
Declare Sub XLayout_GetRect Lib "xcgui.dll" (ByVal hLayout As Long, ByVal pRect As rect)
Declare Sub XLayout_GetRectFrame Lib "xcgui.dll" (ByVal hLayout As Long, ByVal pRect As rect)
Declare Function XLayout_GetWindow Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Function XLayout_GetEle Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Function XLayout_GetParentLayout Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Function XLayout_GetParent Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Sub XLayout_SetID Lib "xcgui.dll" (ByVal hLayout As Long, ByVal nID As Long)
Declare Function XLayout_GetID Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Sub XLayout_SetHorizon Lib "xcgui.dll" (ByVal hLayout As Long, ByVal bHorizon As Boolean)
Declare Sub XLayout_SetAlignH Lib "xcgui.dll" (ByVal hLayout As Long, ByVal nAlign As Long)
Declare Sub XLayout_SetAlignV Lib "xcgui.dll" (ByVal hLayout As Long, ByVal nAlign As Long)
Declare Sub XLayout_SetPadding Lib "xcgui.dll" (ByVal hLayout As Long, ByVal left As Long, ByVal top As Long, ByVal right As Long, ByVal bottom As Long)
Declare Sub XLayout_SetSpace Lib "xcgui.dll" (ByVal hLayout As Long, ByVal nSpace As Long)
Declare Sub XLayout_SetLayoutWidth Lib "xcgui.dll" (ByVal hLayout As Long, ByVal nType As Long, ByVal nWidth As Long)
Declare Sub XLayout_SetLayoutHeight Lib "xcgui.dll" (ByVal hLayout As Long, ByVal nType As Long, ByVal nHeight As Long)
Declare Sub XLayout_GetLayoutWidth Lib "xcgui.dll" (ByVal hLayout As Long, ByVal pType As Long, ByVal pWidth As Long)
Declare Sub XLayout_GetLayoutHeight Lib "xcgui.dll" (ByVal hLayout As Long, ByVal pType As Long, ByVal pHeight As Long)
Declare Function XLayout_GetWidth Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Function XLayout_GetHeight Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Function XLayout_GetWidthIn Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Function XLayout_GetHeightIn Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Sub XLayout_GetContentSize Lib "xcgui.dll" (ByVal hLayout As Long, ByVal pSize As size)
Declare Sub XLayout_ShowLayout Lib "xcgui.dll" (ByVal hLayout As Long, ByVal bShow As Boolean)
Declare Function XLayout_GetChildCount Lib "xcgui.dll" (ByVal hLayout As Long) As Long
Declare Function XLayout_GetChildType Lib "xcgui.dll" (ByVal hLayout As Long, ByVal index As Long) As Long
Declare Function XLayout_GetChild Lib "xcgui.dll" (ByVal hLayout As Long, ByVal index As Long) As Long
Declare Sub XLayout_Draw Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hDraw As Long)
Declare Sub Layout_SetEle Lib "xcgui.dll" (ByVal hLayout As Long, ByVal hParent As Long)
Declare Function XListBox_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XListBox_SetDrawItemBkFlags Lib "xcgui.dll" (ByVal hEle As Long, ByVal nFlags As Long)
Declare Function XListBox_SetItemData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal nUserData As Long) As Boolean
Declare Function XListBox_GetItemData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long) As Long
Declare Function XListBox_SetItemInfo Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal pItem As listBox_item_Info_i) As Boolean
Declare Function XListBox_GetItemInfo Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal pItem As listBox_item_Info_i) As Boolean
Declare Sub XListBox_AddItemBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XListBox_AddItemBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XListBox_AddItemBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XListBox_GetItemBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XListBox_ClearItemBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XListBox_SetSelectItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long) As Boolean
Declare Function XListBox_GetSelectItem Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XListBox_CancelSelectItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long) As Boolean
Declare Function XListBox_CancelSelectAll Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XListBox_GetSelectAll Lib "xcgui.dll" (ByVal hEle As Long, ByVal pArray As Long, ByVal nArraySize As Long) As Long
Declare Function XListBox_GetSelectCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XListBox_GetItemMouseStay Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XListBox_SelectAll Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Sub XListBox_SetItemHeightDefault Lib "xcgui.dll" (ByVal hEle As Long, ByVal nHeight As Long, ByVal nSelHeight As Long)
Declare Sub XListBox_GetItemHeightDefault Lib "xcgui.dll" (ByVal hEle As Long, ByVal pHeight As Long, ByVal pSelHeight As Long)
Declare Function XListBox_GetItemIndexFromHXCGUI Lib "xcgui.dll" (ByVal hEle As Long, ByVal hXCGUI As Long) As Long
Declare Sub XListBox_SetRowSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal nSpace As Long)
Declare Function XListBox_GetRowSpace Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XListBox_HitTest Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point) As Long
Declare Function XListBox_HitTestOffset Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point) As Long
Declare Function XListBox_SetItemTemplateXML Lib "xcgui.dll" (ByVal hEle As Long, ByVal pXmlFile As String) As Boolean
Declare Function XListBox_SetItemTemplateXMLFromString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pStringXML As String) As Boolean
Declare Function XListBox_GetTemplateObject Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal nTempItemID As Long) As Long
Declare Sub XListBox_EnableMultiSel Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XListBox_BindAdapter Lib "xcgui.dll" (ByVal hEle As Long, ByVal hAdapter As Long)
Declare Function XListBox_GetAdapter Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XListBox_RefreshData Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XList_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XList_AddColumn Lib "xcgui.dll" (ByVal hEle As Long, ByVal width As Long) As Long
Declare Function XList_InsertColumn Lib "xcgui.dll" (ByVal hEle As Long, ByVal width As Long, ByVal iItem As Long) As Long
Declare Sub XList_EnableMultiSel Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XList_EnableDragChangeColumnWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XList_SetDrawItemBkFlags Lib "xcgui.dll" (ByVal hEle As Long, ByVal style As Long)
Declare Sub XList_SetColumnWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal width As Long)
Declare Sub XList_SetColumnMinWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal width As Long)
Declare Sub XList_SetColumnWidthFixed Lib "xcgui.dll" (ByVal hEle As Long, ByVal iColumn As Long, ByVal bFixed As Boolean)
Declare Function XList_GetColumnWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal iColumn As Long) As Long
Declare Function XList_GetColumnCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XList_DeleteColumn Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long) As Boolean
Declare Sub XList_DeleteColumnAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XList_SetItemData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal iSubItem As Long, ByVal data As Long) As Boolean
Declare Function XList_GetItemData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal iSubItem As Long) As Long
Declare Function XList_SetSelectItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal bSelect As Boolean) As Boolean
Declare Function XList_GetSelectItem Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XList_GetSelectItemCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XList_SetSelectAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XList_GetSelectAll Lib "xcgui.dll" (ByVal hEle As Long, ByVal pArray As Long, ByVal nArraySize As Long) As Long
Declare Function XList_CancelSelectItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long) As Boolean
Declare Sub XList_CancelSelectAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XList_GetHeaderHELE Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XList_BindAdapter Lib "xcgui.dll" (ByVal hEle As Long, ByVal hAdapter As Long)
Declare Sub XList_BindAdapterHeader Lib "xcgui.dll" (ByVal hEle As Long, ByVal hAdapter As Long)
Declare Function XList_GetAdapter Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XList_SetItemTemplateXML Lib "xcgui.dll" (ByVal hEle As Long, ByVal pXmlFile As String) As Boolean
Declare Function XList_SetItemTemplateXMLFromString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pStringXML As String) As Boolean
Declare Function XList_GetTemplateObject Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal nTempItemID As Long) As Long
Declare Function XList_GetItemIndexFromHXCGUI Lib "xcgui.dll" (ByVal hEle As Long, ByVal hXCGUI As Long) As Long
Declare Function XList_GetHeaderTemplateObject Lib "xcgui.dll" (ByVal hEle As Long, ByVal iItem As Long, ByVal nTempItemID As Long) As Long
Declare Function XList_GetHeaderItemIndexFromHXCGUI Lib "xcgui.dll" (ByVal hEle As Long, ByVal hXCGUI As Long) As Long
Declare Sub XList_SetHeaderHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal height As Long)
Declare Function XList_GetHeaderHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XList_AddItemBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XList_AddItemBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XList_AddItemBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XList_GetItemBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XList_ClearItemBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XList_SetItemHeightDefault Lib "xcgui.dll" (ByVal hEle As Long, ByVal nHeight As Long, ByVal nSelHeight As Long)
Declare Sub XList_GetItemHeightDefault Lib "xcgui.dll" (ByVal hEle As Long, ByVal pHeight As Long, ByVal pSelHeight As Long)
Declare Sub XList_SetRowSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal nSpace As Long)
Declare Function XList_GetRowSpace Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XList_HitTest Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point, ByVal piItem As Long, ByVal piSubItem As Long) As Boolean
Declare Function XList_HitTestOffset Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point, ByVal piItem As Long, ByVal piSubItem As Long) As Boolean
Declare Sub XList_RefreshData Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XListView_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XListView_BindAdapter Lib "xcgui.dll" (ByVal hEle As Long, ByVal hAdapter As Long)
Declare Function XListView_GetAdapter Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XListView_SetItemTemplateXML Lib "xcgui.dll" (ByVal hEle As Long, ByVal pXmlFile As String) As Boolean
Declare Function XListView_SetItemTemplateXMLFromString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pStringXML As String) As Boolean
Declare Function XListView_GetTemplateObject Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal nTempItemID As Long) As Long
Declare Function XListView_GetTemplateObjectGroup Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long, ByVal nTempItemID As Long) As Long
Declare Function XListView_GetItemIDFromHXCGUI Lib "xcgui.dll" (ByVal hEle As Long, ByVal hXCGUI As Long, ByVal piGroup As Long, ByVal piItem As Long) As Boolean
Declare Function XListView_HitTest Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point, ByVal pOutGroup As Long, ByVal pOutItem As Long) As Boolean
Declare Function XListView_HitTestOffset Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point, ByVal pOutGroup As Long, ByVal pOutItem As Long) As Long
Declare Sub XListView_EnableMultiSel Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XListView_SetDrawItemBkFlags Lib "xcgui.dll" (ByVal hEle As Long, ByVal nFlags As Long)
Declare Function XListView_SetSelectItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long, ByVal iItem As Long) As Boolean
Declare Function XListView_GetSelectItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal piGroup As Long, ByVal piItem As Long) As Boolean
Declare Function XListView_GetSelectItemCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XListView_GetSelectItemAll Lib "xcgui.dll" (ByVal hEle As Long, ByVal pArray As listView_item_id_i, ByVal nArraySize As Long) As Long
Declare Sub XListView_SetSelectItemAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XListView_CancelSelectItemAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XListView_SetColumnSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal space As Long)
Declare Sub XListView_SetRowSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal space As Long)
Declare Sub XListView_SetAlignSizeLeft Lib "xcgui.dll" (ByVal hEle As Long, ByVal size As Long)
Declare Sub XListView_SetAlignSizeTop Lib "xcgui.dll" (ByVal hEle As Long, ByVal size As Long)
Declare Sub XListView_SetItemSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal width As Long, ByVal height As Long)
Declare Sub XListView_GetItemSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal pSize As size)
Declare Sub XListView_SetGroupHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal height As Long)
Declare Function XListView_GetGroupHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XListView_SetGroupUserData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long, ByVal nData As Long)
Declare Sub XListView_SetItemUserData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal nData As Long)
Declare Function XListView_GetGroupUserData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long) As Long
Declare Function XListView_GetItemUserData Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long, ByVal iItem As Long) As Long
Declare Sub XListView_AddItemBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XListView_AddItemBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XListView_AddItemBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XListView_GetItemBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XListView_ClearItemBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XListView_RefreshData Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XListView_ExpandGroup Lib "xcgui.dll" (ByVal hEle As Long, ByVal iGroup As Long, ByVal bExpand As Boolean) As Boolean
Declare Function XMenuBar_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XMenuBar_AddButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal pText As String) As Long
Declare Sub XMenuBar_SetButtonHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal height As Long)
Declare Function XMenuBar_GetMenu Lib "xcgui.dll" (ByVal hEle As Long, ByVal nIndex As Long) As Long
Declare Function XMenuBar_DeleteButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal nIndex As Long) As Boolean
Declare Function XMenu_Create Lib "xcgui.dll" () As Long
Declare Sub XMenu_AddItem Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal pText As String, ByVal parentId As Long, ByVal nFlags As Long)
Declare Sub XMenu_AddItemIcon Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal pText As String, ByVal nParentID As Long, ByVal hImage As Long, ByVal nFlags As Long)
Declare Sub XMenu_InsertItem Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal pText As String, ByVal nFlags As Long, ByVal insertID As Long)
Declare Sub XMenu_InsertItemIcon Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal pText As String, ByVal hIcon As Long, ByVal nFlags As Long, ByVal insertID As Long)
Declare Sub XMenu_SetAutoDestroy Lib "xcgui.dll" (ByVal hMenu As Long, ByVal bAuto As Boolean)
Declare Sub XMenu_EnableDrawBackground Lib "xcgui.dll" (ByVal hMenu As Long, ByVal bEnable As Boolean)
Declare Sub XMenu_EnableDrawItem Lib "xcgui.dll" (ByVal hMenu As Long, ByVal bEnable As Boolean)
Declare Function XMenu_Popup Lib "xcgui.dll" (ByVal hMenu As Long, ByVal hParentWnd As Long, ByVal x As Long, ByVal y As Long, ByVal hParentEle As Long, ByVal nPosition As Long) As Boolean
Declare Sub XMenu_DestroyMenu Lib "xcgui.dll" (ByVal hMenu As Long)
Declare Sub XMenu_CloseMenu Lib "xcgui.dll" (ByVal hMenu As Long)
Declare Sub XMenu_SetBkImage Lib "xcgui.dll" (ByVal hMenu As Long, ByVal hImage As Long)
Declare Function XMenu_SetItemText Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal pText As String) As Boolean
Declare Function XMenu_GetItemText Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XMenu_GetItemTextLength Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long) As Long
Declare Function XMenu_SetItemIcon Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal hIcon As Long) As Boolean
Declare Function XMenu_SetItemFlags Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal uFlags As Long) As Boolean
Declare Sub XMenu_SetItemHeight Lib "xcgui.dll" (ByVal hMenu As Long, ByVal height As Long)
Declare Function XMenu_GetItemHeight Lib "xcgui.dll" (ByVal hMenu As Long) As Long
Declare Sub XMenu_SetBorderColor Lib "xcgui.dll" (ByVal hMenu As Long, ByVal crColor As Long, ByVal alpha As Byte)
Declare Function XMenu_GetLeftWidth Lib "xcgui.dll" (ByVal hMenu As Long) As Long
Declare Function XMenu_GetLeftSpaceText Lib "xcgui.dll" (ByVal hMenu As Long) As Long
Declare Function XMenu_GetItemCount Lib "xcgui.dll" (ByVal hMenu As Long) As Long
Declare Function XMenu_SetItemCheck Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long, ByVal bCheck As Boolean) As Boolean
Declare Function XMenu_IsItemCheck Lib "xcgui.dll" (ByVal hMenu As Long, ByVal nID As Long) As Boolean
Declare Function XModalWnd_Create Lib "xcgui.dll" (ByVal nWidth As Long, ByVal nHeight As Long, ByVal pTitle As String, ByVal hWndParent As Long, ByVal XCStyle As Long) As Long
Declare Function XModalWnd_CreateEx Lib "xcgui.dll" (ByVal dwExStyle As Long, ByVal lpClassName As String, ByVal lpWindowName As String, ByVal dwStyle As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hWndParent As Long, ByVal XCStyle As Long) As Long
Declare Sub XModalWnd_EnableAutoClose Lib "xcgui.dll" (ByVal hWindow As Long, ByVal bEnable As Boolean)
Declare Function XModalWnd_DoModal Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Sub XModalWnd_EndModal Lib "xcgui.dll" (ByVal hWindow As Long, ByVal nResult As Long)
Declare Function XPane_Create Lib "xcgui.dll" (ByVal pName As String, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hFrameWnd As Long) As Long
Declare Sub XPane_SetView Lib "xcgui.dll" (ByVal hEle As Long, ByVal hView As Long)
Declare Function XPane_IsShowPane Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Sub XPane_SetTitle Lib "xcgui.dll" (ByVal hEle As Long, ByVal pTitle As String)
Declare Sub XPane_GetTitle Lib "xcgui.dll" (ByVal hEle As Long, ByVal pOut As Long, ByVal nOutLen As Long)
Declare Sub XPane_SetCaptionHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal nHeight As Long)
Declare Function XPane_GetCaptionHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XPane_HidePane Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XPane_ShowPane Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XPane_DockPane Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XPane_LockPane Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XPane_FloatPane Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XFloatWnd_EnableCaptionContent Lib "xcgui.dll" (ByVal hWindow As Long, ByVal bEnable As Boolean) As Boolean
Declare Function XFloatWnd_GetCaptionLayout Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XFloatWnd_GetCaptionShapeText Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XFloatWnd_GetCaptionButtonClose Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Sub XFloatWnd_SetTitle Lib "xcgui.dll" (ByVal hWindow As Long, ByVal pTitle As String)
Declare Sub XFloatWnd_GetTitle Lib "xcgui.dll" (ByVal hWindow As Long, ByVal pOut As Long, ByVal nOutLen As Long)
Declare Function XProgBar_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XProgBar_SetRange Lib "xcgui.dll" (ByVal hEle As Long, ByVal range As Long)
Declare Function XProgBar_GetRange Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XProgBar_SetSpaceTwo Lib "xcgui.dll" (ByVal hEle As Long, ByVal leftSize As Long, ByVal rightSize As Long)
Declare Sub XProgBar_SetPos Lib "xcgui.dll" (ByVal hEle As Long, ByVal pos As Long)
Declare Function XProgBar_GetPos Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XProgBar_SetHorizon Lib "xcgui.dll" (ByVal hEle As Long, ByVal bHorizon As Boolean)
Declare Sub XProgBar_SetImageLoad Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Function XPGrid_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XPGrid_AddItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal pName As String, ByVal nType As Long, ByVal nParentID As Long) As Long
Declare Function XPGrid_AddItemString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pName As String, ByVal pValue As String, ByVal nParentID As Long) As Long
Declare Sub XPGrid_DeleteAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XPGrid_GetItemHELE Lib "xcgui.dll" (ByVal hEle As Long, ByVal nItemID As Long) As Long
Declare Sub XPGrid_SetWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal nWidth As Long)
Declare Function XPGrid_SetItemValue Lib "xcgui.dll" (ByVal hEle As Long, ByVal nItemID As Long, ByVal pValue As String) As Boolean
Declare Function XPGrid_SetItemValueInt Lib "xcgui.dll" (ByVal hEle As Long, ByVal nItemID As Long, ByVal nValue As Long) As Boolean
Declare Function XPGrid_GetItemValue Lib "xcgui.dll" (ByVal hEle As Long, ByVal nItemID As Long) As String
Declare Function XPGrid_HitTest Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point, ByVal pbExpandButton As Boolean) As Long
Declare Function XPGrid_HitTestOffset Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point, ByVal pbExpandButton As Boolean) As Long
Declare Function XPGrid_ExpandItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal nItemID As Long, ByVal bExpand As Boolean) As Boolean
Declare Function XPGrid_GetSelItem Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XPGrid_SetSelItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal nItemID As Long) As Boolean
Declare Function XRichEditColor_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XRichEditColor_SetColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long)
Declare Function XRichEditColor_GetColor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XRichEditSet_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XRichEditFile_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XRichEditFile_SetOpenFileType Lib "xcgui.dll" (ByVal hEle As Long, ByVal pType As String)
Declare Sub XRichEditFile_SetDefaultFile Lib "xcgui.dll" (ByVal hEle As Long, ByVal pFile As String)
Declare Sub XRichEditFile_SetRelativeDir Lib "xcgui.dll" (ByVal hEle As Long, ByVal pDir As String)
Declare Function XRichEditFolder_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XRichEditFolder_SetDefaultDir Lib "xcgui.dll" (ByVal hEle As Long, ByVal pDir As String)
Declare Function XRichEdit_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XRichEdit_InsertString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pString As String, ByVal pFont As xc_font_info_i, ByVal color As Long)
Declare Function XRichEdit_InsertImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long, ByVal pImagePath As String) As Boolean
Declare Function XRichEdit_InsertGif Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long, ByVal pImagePath As String) As Boolean
Declare Sub XRichEdit_InsertStringEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal iRow As Long, ByVal iColumn As Long, ByVal pString As String, ByVal pFont As xc_font_info_i, ByVal color As Long)
Declare Function XRichEdit_InsertImageEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal iRow As Long, ByVal iColumn As Long, ByVal hImage As Long, ByVal pImagePath As String) As Boolean
Declare Function XRichEdit_InsertGifEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal iRow As Long, ByVal iColumn As Long, ByVal hImage As Long, ByVal pImagePath As String) As Boolean
Declare Sub XRichEdit_EnableReadOnly Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XRichEdit_EnableMultiLine Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XRichEdit_EnablePassword Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XRichEdit_EnableAutoWrap Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XRichEdit_EnableAutoCancelSel Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XRichEdit_EnableAutoSelAll Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XRichEdit_SetLimitNum Lib "xcgui.dll" (ByVal hEle As Long, ByVal nNumber As Long)
Declare Sub XRichEdit_SetText Lib "xcgui.dll" (ByVal hEle As Long, ByVal pString As String)
Declare Sub XRichEdit_SetTextInt Lib "xcgui.dll" (ByVal hEle As Long, ByVal nVaule As Long)
Declare Function XRichEdit_GetText Lib "xcgui.dll" (ByVal hEle As Long,ByVal pOut As Long,ByVal nlen As Long) As Long
Declare Sub XRichEdit_GetHTMLFormat Lib "xcgui.dll" (ByVal hEle As Long,ByVal pOut As Long,ByVal nlen As Long)
Declare Function XRichEdit_GetData Lib "xcgui.dll" (ByVal hEle As Long, ByVal pDataSize As Long) As Long
Declare Function XRichEdit_InsertData Lib "xcgui.dll" (ByVal hEle As Long, ByVal pData As Long, ByVal iRow As Long, ByVal iColumn As Long) As Boolean
Declare Function XRichEdit_GetTextLength Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XRichEdit_SetRowHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal nHeight As Long)
Declare Sub XRichEdit_SetDefaultText Lib "xcgui.dll" (ByVal hEle As Long, ByVal pString As String)
Declare Sub XRichEdit_SetDefaultTextColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XRichEdit_GetCurrentRow Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XRichEdit_GetCurrentColumn Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XRichEdit_SetCurrentPos Lib "xcgui.dll" (ByVal hEle As Long, ByVal iRow As Long, ByVal iColumn As Long)
Declare Function XRichEdit_GetRowCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XRichEdit_GetRowLength Lib "xcgui.dll" (ByVal hEle As Long, ByVal iRow As Long) As Long
Declare Function XRichEdit_GetSelectText Lib "xcgui.dll" (ByVal hEle As Long,ByVal pOut As Long,ByVal nlen As Long) As Long
Declare Function XRichEdit_GetSelectPosition Lib "xcgui.dll" (ByVal hEle As Long, ByVal pBegin As Position, ByVal pEnd As Position) As Boolean
Declare Function XRichEdit_SetSelect Lib "xcgui.dll" (ByVal hEle As Long, ByVal iStartRow As Long, ByVal iStartCol As Long, ByVal iEndRow As Long, ByVal iEndCol As Long) As Boolean
Declare Function XRichEdit_SetItemFontEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal beginRow As Long, ByVal beginColumn As Long, ByVal endRow As Long, ByVal endColumn As Long, ByVal pFont As xc_font_info_i) As Boolean
Declare Function XRichEdit_SetItemColorEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal beginRow As Long, ByVal beginColumn As Long, ByVal endRow As Long, ByVal endColumn As Long, ByVal color As Long, ByVal alpha As Byte) As Boolean
Declare Sub XRichEdit_CancelSelect Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XRichEdit_SetSelectBkColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XRichEdit_IsEmpty Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XRichEdit_SelectAll Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XRichEdit_DeleteSelect Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Sub XRichEdit_DeleteAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XRichEdit_ClipboardCut Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XRichEdit_ClipboardCopy Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XRichEdit_ClipboardPaste Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSBar_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XSBar_SetRange Lib "xcgui.dll" (ByVal hEle As Long, ByVal range As Long)
Declare Function XSBar_GetRange Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XSBar_ShowButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal bShow As Boolean)
Declare Sub XSBar_SetSliderLength Lib "xcgui.dll" (ByVal hEle As Long, ByVal length As Long)
Declare Sub XSBar_SetSliderMinLength Lib "xcgui.dll" (ByVal hEle As Long, ByVal minLength As Long)
Declare Function XSBar_SetHorizon Lib "xcgui.dll" (ByVal hEle As Long, ByVal bHorizon As Boolean) As Boolean
Declare Function XSBar_GetSliderMaxLength Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSBar_ScrollUp Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSBar_ScrollDown Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSBar_ScrollTop Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSBar_ScrollBottom Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSBar_ScrollPos Lib "xcgui.dll" (ByVal hEle As Long, ByVal pos As Long) As Boolean
Declare Function XSBar_GetButtonUp Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSBar_GetButtonDown Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSBar_GetButtonSlider Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSView_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XSView_SetTotalSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal cx As Long, ByVal cy As Long) As Boolean
Declare Sub XSView_GetTotalSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal pSize As size)
Declare Function XSView_SetLineSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Boolean
Declare Sub XSView_GetLineSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal pSize As size)
Declare Function XSView_GetViewPosH Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSView_GetViewPosV Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSView_GetViewWidth Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSView_GetViewHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XSView_GetViewRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Function XSView_GetScrollBarH Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSView_GetScrollBarV Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XSView_SetPadding Lib "xcgui.dll" (ByVal hEle As Long, ByVal left As Long, ByVal top As Long, ByVal right As Long, ByVal bottom As Long)
Declare Sub XSView_GetPadding Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPadding As PaddingSize_)
Declare Function XSView_ScrollPosH Lib "xcgui.dll" (ByVal hEle As Long, ByVal pos As Long) As Boolean
Declare Function XSView_ScrollPosV Lib "xcgui.dll" (ByVal hEle As Long, ByVal pos As Long) As Boolean
Declare Function XSView_ScrollPosXH Lib "xcgui.dll" (ByVal hEle As Long, ByVal posX As Long) As Boolean
Declare Function XSView_ScrollPosYV Lib "xcgui.dll" (ByVal hEle As Long, ByVal posY As Long) As Boolean
Declare Sub XSView_ShowSBarH Lib "xcgui.dll" (ByVal hEle As Long, ByVal bShow As Boolean)
Declare Sub XSView_ShowSBarV Lib "xcgui.dll" (ByVal hEle As Long, ByVal bShow As Boolean)
Declare Sub XSView_EnableAutoShowScrollBar Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Function XSView_ScrollLeftLine Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSView_ScrollRightLine Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSView_ScrollTopLine Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSView_ScrollBottomLine Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSView_ScrollLeft Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSView_ScrollRight Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSView_ScrollTop Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XSView_ScrollBottom Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XShape_GetParentEle Lib "xcgui.dll" (ByVal hShape As Long) As Long
Declare Function XShape_GetParentLayout Lib "xcgui.dll" (ByVal hShape As Long) As Long
Declare Function XShape_GetHWINDOW Lib "xcgui.dll" (ByVal hShape As Long) As Long
Declare Function XShape_GetParent Lib "xcgui.dll" (ByVal hShape As Long) As Long
Declare Sub XShape_RemoveShape Lib "xcgui.dll" (ByVal hShape As Long)
Declare Sub XShape_SetID Lib "xcgui.dll" (ByVal hShape As Long, ByVal nID As Long)
Declare Function XShape_GetID Lib "xcgui.dll" (ByVal hShape As Long) As Long
Declare Sub XShape_Redraw Lib "xcgui.dll" (ByVal hShape As Long)
Declare Function XShape_GetWidth Lib "xcgui.dll" (ByVal hShape As Long) As Long
Declare Function XShape_GetHeight Lib "xcgui.dll" (ByVal hShape As Long) As Long
Declare Sub XShape_GetRect Lib "xcgui.dll" (ByVal hShape As Long, ByVal pRect As rect)
Declare Sub XShape_SetRect Lib "xcgui.dll" (ByVal hShape As Long, ByVal pRect As rect)
Declare Sub XShape_GetContentSize Lib "xcgui.dll" (ByVal hShape As Long, ByVal pSize As size)
Declare Sub XShape_ShowLayout Lib "xcgui.dll" (ByVal hShape As Long, ByVal bShow As Boolean)
Declare Sub XShape_AdjustLayout Lib "xcgui.dll" (ByVal hShape As Long)
Declare Sub XShape_Destroy Lib "xcgui.dll" (ByVal hShape As Long)
Declare Function XShapeText_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal pName As String, ByVal hParent As Long) As Long
Declare Sub XShapeText_SetText Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal pName As String)
Declare Sub XShapeText_GetText Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal pOut As Long, ByVal nOutLen As Long)
Declare Function XShapeText_GetTextLength Lib "xcgui.dll" (ByVal hTextBlock As Long) As Long
Declare Sub XShapeText_SetFont Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal hFontx As Long)
Declare Sub XShapeText_SetTextColor Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XShapeText_GetTextColor Lib "xcgui.dll" (ByVal hTextBlock As Long) As Long
Declare Sub XShapeText_SetTextAlign Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal align As Long)
Declare Sub XShapeText_SetOffset Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XShapeText_SetLayoutWidth Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal nType As Long, ByVal width As Long)
Declare Sub XShapeText_SetLayoutHeight Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal nType As Long, ByVal height As Long)
Declare Sub XShapeText_GetLayoutWidth Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal pType As Long, ByVal pWidth As Long)
Declare Sub XShapeText_GetLayoutHeight Lib "xcgui.dll" (ByVal hTextBlock As Long, ByVal pType As Long, ByVal pHeight As Long)
Declare Function XShapePic_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XShapePic_SetImage Lib "xcgui.dll" (ByVal hShape As Long, ByVal hImage As Long)
Declare Sub XShapePic_SetLayoutWidth Lib "xcgui.dll" (ByVal hShape As Long, ByVal nType As Long, ByVal width As Long)
Declare Sub XShapePic_SetLayoutHeight Lib "xcgui.dll" (ByVal hShape As Long, ByVal nType As Long, ByVal height As Long)
Declare Sub XShapePic_GetLayoutWidth Lib "xcgui.dll" (ByVal hShape As Long, ByVal pType As Long, ByVal pWidth As Long)
Declare Sub XShapePic_GetLayoutHeight Lib "xcgui.dll" (ByVal hShape As Long, ByVal pType As Long, ByVal pHeight As Long)
Declare Function XShapeGif_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XShapeGif_SetImage Lib "xcgui.dll" (ByVal hShape As Long, ByVal hImage As Long)
Declare Sub XShapeGif_SetLayoutWidth Lib "xcgui.dll" (ByVal hShape As Long, ByVal nType As Long, ByVal width As Long)
Declare Sub XShapeGif_SetLayoutHeight Lib "xcgui.dll" (ByVal hShape As Long, ByVal nType As Long, ByVal height As Long)
Declare Sub XShapeGif_GetLayoutWidth Lib "xcgui.dll" (ByVal hShape As Long, ByVal pType As Long, ByVal pWidth As Long)
Declare Sub XShapeGif_GetLayoutHeight Lib "xcgui.dll" (ByVal hShape As Long, ByVal pType As Long, ByVal pHeight As Long)
Declare Function XShapeRect_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XShapeRect_SetBorderColor Lib "xcgui.dll" (ByVal hShape As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XShapeRect_SetFillColor Lib "xcgui.dll" (ByVal hShape As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XShapeRect_SetRoundAngle Lib "xcgui.dll" (ByVal hShape As Long, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Sub XShapeRect_GetRoundAngle Lib "xcgui.dll" (ByVal hShape As Long, ByVal pWidth As Long, ByVal pHeight As Long)
Declare Sub XShapeRect_EnableBorder Lib "xcgui.dll" (ByVal hShape As Long, ByVal bEnable As Boolean)
Declare Sub XShapeRect_EnableFill Lib "xcgui.dll" (ByVal hShape As Long, ByVal bEnable As Boolean)
Declare Sub XShapeRect_EnableRoundAngle Lib "xcgui.dll" (ByVal hShape As Long, ByVal bEnable As Boolean)
Declare Function XShapeEllipse_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XShapeEllipse_SetBorderColor Lib "xcgui.dll" (ByVal hShape As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XShapeEllipse_SetFillColor Lib "xcgui.dll" (ByVal hShape As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XShapeEllipse_EnableBorder Lib "xcgui.dll" (ByVal hShape As Long, ByVal bEnable As Boolean)
Declare Sub XShapeEllipse_EnableFill Lib "xcgui.dll" (ByVal hShape As Long, ByVal bEnable As Boolean)
Declare Function XShapeGroupBox_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal pName As String, ByVal hParent As Long) As Long
Declare Sub XShapeGroupBox_SetBorderColor Lib "xcgui.dll" (ByVal hShape As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XShapeGroupBox_SetTextColor Lib "xcgui.dll" (ByVal hShape As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XShapeGroupBox_SetFontX Lib "xcgui.dll" (ByVal hShape As Long, ByVal hFontx As Long)
Declare Sub XShapeGroupBox_SetTextOffset Lib "xcgui.dll" (ByVal hShape As Long, ByVal offsetX As Long, ByVal offsetY As Long)
Declare Sub XShapeGroupBox_SetRoundAngle Lib "xcgui.dll" (ByVal hShape As Long, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Sub XShapeGroupBox_SetText Lib "xcgui.dll" (ByVal hShape As Long, ByVal pText As String)
Declare Sub XShapeGroupBox_GetTextOffset Lib "xcgui.dll" (ByVal hShape As Long, ByVal pOffsetX As Long, ByVal pOffsetY As Long)
Declare Sub XShapeGroupBox_GetRoundAngle Lib "xcgui.dll" (ByVal hShape As Long, ByVal pWidth As Long, ByVal pHeight As Long)
Declare Sub XShapeGroupBox_EnableRoundAngle Lib "xcgui.dll" (ByVal hShape As Long, ByVal bEnable As Boolean)
Declare Function XShapeLine_Create Lib "xcgui.dll" (ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long, ByVal hParent As Long) As Long
Declare Sub XShapeLine_SetPosition Lib "xcgui.dll" (ByVal hShape As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long)
Declare Sub XShapeLine_SetColor Lib "xcgui.dll" (ByVal hShape As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XSliderBar_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XSliderBar_SetRange Lib "xcgui.dll" (ByVal hEle As Long, ByVal range As Long)
Declare Function XSliderBar_GetRange Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XSliderBar_SetButtonWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal width As Long)
Declare Sub XSliderBar_SetButtonHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal height As Long)
Declare Sub XSliderBar_SetSpaceTwo Lib "xcgui.dll" (ByVal hEle As Long, ByVal leftSize As Long, ByVal rightSize As Long)
Declare Sub XSliderBar_SetPos Lib "xcgui.dll" (ByVal hEle As Long, ByVal pos As Long)
Declare Function XSliderBar_GetPos Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XSliderBar_GetButton Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XSliderBar_SetHorizon Lib "xcgui.dll" (ByVal hEle As Long, ByVal bHorizon As Boolean)
Declare Sub XSliderBar_SetImageLoad Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Function XTabBar_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XTabBar_AddLabel Lib "xcgui.dll" (ByVal hEle As Long, ByVal pName As String) As Long
Declare Function XTabBar_InsertLabel Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long, ByVal pName As String) As Long
Declare Function XTabBar_DeleteLabel Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Boolean
Declare Sub XTabBar_DeleteLabelAll Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XTabBar_GetLabel Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Function XTabBar_GetLabelClose Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Function XTabBar_GetButtonLeft Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XTabBar_GetButtonRight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XTabBar_GetSelect Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XTabBar_GetLabelSpacing Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XTabBar_GetLabelCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XTabBar_SetLabelSpacing Lib "xcgui.dll" (ByVal hEle As Long, ByVal spacing As Long)
Declare Sub XTabBar_SetSelect Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long)
Declare Sub XTabBar_SetUp Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XTabBar_SetDown Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XTabBar_EnableTile Lib "xcgui.dll" (ByVal hEle As Long, ByVal bTile As Boolean)
Declare Sub XTabBar_EnableClose Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XTabBar_SetCloseSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal pSize As size)
Declare Sub XTabBar_SetTurnButtonSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal pSize As size)
Declare Function XTabBar_ShowLabel Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long, ByVal bShow As Boolean) As Boolean
Declare Function XTextLink_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal pName As String, ByVal hParent As Long) As Long
Declare Sub XTextLink_EnableUnderlineLeave Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XTextLink_EnableUnderlineStay Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XTextLink_SetTextColorStay Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XTextLink_SetUnderlineColorLeave Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XTextLink_SetUnderlineColorStay Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XToolBar_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XToolBar_InsertEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal hNewEle As Long, ByVal index As Long) As Long
Declare Function XToolBar_InsertSeparator Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Sub XToolBar_EnableButtonMenu Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Function XToolBar_GetHEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Function XToolBar_GetButtonLeft Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XToolBar_GetButtonRight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XToolBar_GetButtonMenu Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XToolBar_SetSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal nSize As Long)
Declare Sub XToolBar_DeleteEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long)
Declare Sub XToolBar_DeleteAllEle Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XTree_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XTree_EnableDragItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XTree_EnableConnectLine Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean, ByVal bSolid As Boolean)
Declare Sub XTree_SetConnectLineColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XTree_SetExpandButtonContentSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal nSpace As Long)
Declare Sub XTree_SetExpandButtonSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Sub XTree_SetDragInsertPositionColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XTree_SetItemTemplateXML Lib "xcgui.dll" (ByVal hEle As Long, ByVal pXmlFile As String) As Boolean
Declare Function XTree_SetItemTemplateXMLSel Lib "xcgui.dll" (ByVal hEle As Long, ByVal pXmlFile As String) As Boolean
Declare Function XTree_SetItemTemplateXMLFromString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pStringXML As String) As Boolean
Declare Function XTree_SetItemTemplateXMLSelFromString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pStringXML As String) As Boolean
Declare Sub XTree_SetDrawItemBkFlags Lib "xcgui.dll" (ByVal hEle As Long, ByVal nFlags As Long)
Declare Function XTree_SetItemData Lib "xcgui.dll" (ByVal hEle As Long, ByVal nID As Long, ByVal nUserData As Long) As Boolean
Declare Function XTree_GetItemData Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Long
Declare Function XTree_SetSelectItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Boolean
Declare Function XTree_GetSelectItem Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XTree_IsExpand Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Boolean
Declare Function XTree_ExpandItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long,ByVal bExpand As Boolean) As Boolean
Declare Function XTree_HitTest Lib "xcgui.dll" (ByVal hEle As Long,ByVal pPt As POINT) As Long
Declare Function XTree_HitTestOffset Lib "xcgui.dll" (ByVal hEle As Long,ByVal pPt As POINT) As Long
Declare Function XTree_GetFirstChildItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Long
Declare Function XTree_GetEndChildItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Long
Declare Function XTree_GetPrevSiblingItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Long
Declare Function XTree_GetNextSiblingItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Long
Declare Function XTree_GetParentItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long) As Long
Declare Sub XTree_SetIndentation Lib "xcgui.dll" (ByVal hEle As Long,ByVal nWidth As Long)
Declare Function XTree_GetIndentation Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XTree_SetItemHeight Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long,ByVal nHeight As Long,ByVal nSelHeight As Long)
Declare Sub XTree_GetItemHeight Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long,ByVal pHeight As Long,ByVal pSelHeight As Long)
Declare Sub XTree_SetRowSpace Lib "xcgui.dll" (ByVal hEle As Long,ByVal nSpace As Long)
Declare Function XTree_GetRowSpace Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XTree_MoveItem Lib "xcgui.dll" (ByVal hEle As Long,ByVal nMoveItem As Long,ByVal nDestItem As Long,ByVal nType As Long) As Boolean
Declare Sub XTree_AddItemBkBorder Lib "xcgui.dll" (ByVal hEle As Long,ByVal nState As Long,ByVal color As Long,ByVal alpha As Byte,ByVal width As Long)
Declare Sub XTree_AddItemBkFill Lib "xcgui.dll" (ByVal hEle As Long,ByVal nState As Long,ByVal color As Long,ByVal alpha As Byte)
Declare Sub XTree_AddItemBkImage Lib "xcgui.dll" (ByVal hEle As Long,ByVal nState As Long,ByVal hImage As Long)
Declare Function XTree_GetItemBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long,ByVal nState As Long) As Long
Declare Sub XTree_ClearItemBkInfo Lib "xcgui.dll" (ByVal hEle As Long,ByVal nState As Long)
Declare Sub XTree_SetItemHeightDefault Lib "xcgui.dll" (ByVal hEle As Long,ByVal nHeight As Long,ByVal nSelHeight As Long)
Declare Sub XTree_GetItemHeightDefault Lib "xcgui.dll" (ByVal hEle As Long,ByVal pHeight As Long,ByVal pSelHeight As Long)
Declare Function XTree_GetTemplateObject Lib "xcgui.dll" (ByVal hEle As Long,ByVal nID As Long,ByVal nTempItemID As Long) As Long
Declare Function XTree_GetItemIDFromHXCGUI Lib "xcgui.dll" (ByVal hEle As Long,ByVal hXCGUI As Long) As Long
Declare Sub XTree_BindAdapter Lib "xcgui.dll" (ByVal hEle As Long,ByVal hAdapter As Long)
Declare Function XTree_GetAdapter Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XTree_RefreshData Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XWnd_RegEventEx Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pEvent As Long)
Declare Function XWnd_RemoveEventEx Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pEvent As Long) As Boolean
Declare Sub XWnd_RegEventC Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nEvent As Long,ByVal pFun As Long)
Declare Sub XWnd_RegEventC1 Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nEvent As Long,ByVal pFun As Long)
Declare Function XWnd_RemovegEvent Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nEvent As Long,ByVal pFun As Long) As Boolean
Declare Function XWnd_Create Lib "xcgui.dll" (ByVal x As Long,ByVal y As Long,ByVal cx As Long,ByVal cy As Long,ByVal pTitle As String,ByVal hWndParent As Long,ByVal XCStyle As Long) As Long
Declare Function XWnd_CreateEx Lib "xcgui.dll" (ByVal dwExStyle As Long,ByVal lpClassName As String,ByVal lpWindowName As String,ByVal dwStyle As Long,ByVal x As Long,ByVal y As Long,ByVal cx As Long,ByVal cy As Long,ByVal hWndParent As Long,ByVal XCStyle As Long) As Long
Declare Function XWnd_AddEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hEle As Long) As Boolean
Declare Function XWnd_InsertEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hChildEle As Long,ByVal index As Long) As Boolean
Declare Function XWnd_AddShape Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hShape As Long) As Boolean
Declare Function XWnd_GetHWND Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Sub XWnd_EnableDragBorder Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bEnable As Boolean)
Declare Sub XWnd_EnableDragWindow Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bEnable As Boolean)
Declare Sub XWnd_EnableDragCaption Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bEnable As Boolean)
Declare Sub XWnd_EnableDrawBk Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bEnable As Boolean)
Declare Sub XWnd_EnableAutoFocus Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bEnable As Boolean)
Declare Sub XWnd_EnableMaxWindow Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bEnable As Boolean)
Declare Sub XWnd_RedrawWnd Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bImmediate As Boolean)
Declare Sub XWnd_RedrawWndRect Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pRect As RECT,ByVal bImmediate As Boolean)
Declare Sub XWnd_SetFocusEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hFocusEle As Long)
Declare Function XWnd_GetFocusEle Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XWnd_GetStayHELE Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Sub XWnd_SetCursor Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hCursor As Long)
Declare Function XWnd_GetCursor Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XWnd_SetCursorSys Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hCursor As Long) As Long
Declare Sub XWnd_SetFont Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hFontx As Long)
Declare Sub XWnd_SetID Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nID As Long)
Declare Function XWnd_GetID Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Sub XWnd_SetCaptureEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hEle As Long)
Declare Function XWnd_GetCaptureEle Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XWnd_BindLayoutEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nPosition As Long,ByVal hEle As Long) As Boolean
Declare Function XWnd_GetLayoutEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nPosition As Long) As Long
Declare Sub XWnd_BindLayoutObject Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nPosition As Long,ByVal hLayout As Long)
Declare Function XWnd_GetLayoutObject Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nPosition As Long) As Long
Declare Sub XWnd_SetLayoutSize Lib "xcgui.dll" (ByVal hWindow As Long,ByVal left As Long,ByVal top As Long,ByVal right As Long,ByVal bottom As Long)
Declare Sub XWnd_GetLayoutSize Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pBorderSize As BorderSize_)
Declare Sub XWnd_SetDragBorderSize Lib "xcgui.dll" (ByVal hWindow As Long,ByVal left As Long,ByVal top As Long,ByVal right As Long,ByVal bottom As Long)
Declare Sub XWnd_GetDragBorderSize Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pSize As BorderSize_)
Declare Sub XWnd_SetMinimumSize Lib "xcgui.dll" (ByVal hWindow As Long,ByVal width As Long,ByVal height As Long)
Declare Function XWnd_HitChildEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pPt As POINT) As Long
Declare Function XWnd_GetChildCount Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XWnd_GetChildByIndex Lib "xcgui.dll" (ByVal hWindow As Long,ByVal index As Long) As Long
Declare Function XWnd_GetChildByID Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nID As Long) As Long
Declare Function XWnd_GetEle Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nID As Long) As Long
Declare Function XWnd_GetChildShapeCount Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XWnd_GetChildShapeByIndex Lib "xcgui.dll" (ByVal hWindow As Long,ByVal index As Long) As Long
Declare Sub XWnd_GetDrawRect Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pRcPaint As RECT)
Declare Function XWnd_ShowWindow Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nCmdShow As Long) As Boolean
Declare Sub XWnd_AdjustLayout Lib "xcgui.dll" (ByVal hWindow As Long)
Declare Sub XWnd_AdjustLayoutObject Lib "xcgui.dll" (ByVal hWindow As Long)
Declare Sub XWnd_CloseWindow Lib "xcgui.dll" (ByVal hWindow As Long)
Declare Sub XWnd_CreateCaret Lib "xcgui.dll" (ByVal hWindow As Long,ByVal hEle As Long,ByVal width As Long,ByVal height As Long)
Declare Sub XWnd_SetCaretSize Lib "xcgui.dll" (ByVal hWindow As Long,ByVal width As Long,ByVal height As Long)
Declare Sub XWnd_SetCaretPos Lib "xcgui.dll" (ByVal hWindow As Long,ByVal x As Long,ByVal y As Long)
Declare Sub XWnd_SetCaretPosEx Lib "xcgui.dll" (ByVal hWindow As Long,ByVal x As Long,ByVal y As Long,ByVal width As Long,ByVal height As Long)
Declare Sub XWnd_SetCaretColor Lib "xcgui.dll" (ByVal hWindow As Long,ByVal color As Long)
Declare Sub XWnd_ShowCaret Lib "xcgui.dll" (ByVal hWindow As Long,ByVal bShow As Boolean)
Declare Sub XWnd_DestroyCaret Lib "xcgui.dll" (ByVal hWindow As Long)
Declare Function XWnd_GetCaretHELE Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Function XWnd_GetClientRect Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pRect As RECT) As Boolean
Declare Sub XWnd_GetBodyRect Lib "xcgui.dll" (ByVal hWindow As Long,ByVal pRect As RECT)
Declare Function XWnd_SetTimer Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nIDEvent As Long,ByVal uElapse As Long) As Long
Declare Function XWnd_KillTimer Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nIDEvent As Long) As Boolean
Declare Function XWnd_GetBkInfoManager Lib "xcgui.dll" (ByVal hWindow As Long) As Long
Declare Sub XWnd_SetTransparentType Lib "xcgui.dll" (ByVal hWindow As Long,ByVal nType As Long)
Declare Sub XWnd_SetTransparentAlpha Lib "xcgui.dll" (ByVal hWindow As Long,ByVal alpha As Byte)
Declare Sub XWnd_SetTransparentColor Lib "xcgui.dll" (ByVal hWindow As Long,ByVal color As Long)
Declare Function XWnd_RegEventTest Lib "xcgui.dll" (ByVal nEvent As Long,ByVal pParamType As Long) As Boolean



