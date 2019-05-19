#include-once
;~   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;~   +                                                       +
;~   +             炫彩界面库 AU3版本                        +
;~   +                                                       +
;~   +  程序编写: guland   E-Mail:398651301@qq.com           +
;~   +  炫彩版本: 1.9.6.0   UDF版本: 2.22                    +
;~   +  发布日期:2016年4月09日                               +
;~   +  众多没能一一测试,欢迎大家指正或建议                  +
;~   +                                                       +
;~   +                                                       +
;~   +  官方网站:                                            +
;~   +      http://www.autoitx.com  ( AutoIt3 )              +
;~   +      http://www.xcgui.com  ( 炫彩 )                   +
;~   +                                                       +
;~   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;~   V2.22更新内容：
;~   修正上一个版本中发现的一些错误
;~   简化了一些函数的操作以及参数
;~   修改一些函数的调用方法以及参数详情请参阅炫彩助手中的相关例程和ReadMe.txt文件

;~ =================== 代码开始 ===================================
Global Const $XC_ERROR = -1
Global Const $XC_WINDOW = 1
Global Const $XC_MODALWINDOW = 2
Global Const $XC_FRAMEWND = 3
Global Const $XC_FLOATWND = 4
Global Const $XC_COMBOBOXWINDOW = 11
Global Const $XC_POPUPMENUWINDOW = 12
Global Const $XC_POPUPMENUCHILDWINDOW = 13
Global Const $XC_ELE = 21
Global Const $XC_BUTTON = 22
Global Const $XC_RICHEDIT = 23
Global Const $XC_COMBOBOX = 24
Global Const $XC_SCROLLBAR = 25
Global Const $XC_SCROLLVIEW = 26
Global Const $XC_LIST = 27
Global Const $XC_LISTBOX = 28
Global Const $XC_LISTVIEW = 29
Global Const $XC_TREE = 30
Global Const $XC_MENUBAR = 31
Global Const $XC_SLIDERBAR = 32
Global Const $XC_PROGRESSBAR = 33
Global Const $XC_TOOLBAR = 34
Global Const $XC_MONTHCAL = 35
Global Const $XC_DATETIME = 36
Global Const $XC_PROPERTYGRID = 37
Global Const $XC_RICHEDIT_COLOR = 38
Global Const $XC_RICHEDIT_SET = 39
Global Const $XC_TABBAR = 40
Global Const $XC_TEXTLINK = 41
Global Const $XC_PANE = 42
Global Const $XC_PANE_SPLIT = 43
Global Const $XC_MENUBAR_BUTTON = 44
Global Const $XC_TOOLBAR_BUTTON = 45
Global Const $XC_PROPERTYPAGE_LABEL = 46
Global Const $XC_PIER = 47
Global Const $XC_BUTTON_MENU = 48
Global Const $XC_VIRTUAL_ELE = 49
Global Const $XC_RICHEDIT_FILE = 50
Global Const $XC_RICHEDIT_FOLDER = 51
Global Const $XC_LIST_HEADER = 52
Global Const $XC_SHAPE = 61
Global Const $XC_SHAPE_TEXT = 62
Global Const $XC_SHAPE_PICTURE = 63
Global Const $XC_SHAPE_RECT = 64
Global Const $XC_SHAPE_ELLIPSE = 65
Global Const $XC_SHAPE_LINE = 66
Global Const $XC_SHAPE_GROUPBOX = 67
Global Const $XC_SHAPE_GIF = 68
Global Const $XC_MENU = 81
Global Const $XC_IMAGE = 82
Global Const $XC_HDRAW = 83
Global Const $XC_FONT = 84
Global Const $XC_FLASH = 85
Global Const $XC_PANE_CELL = 86
Global Const $XC_WEB = 87
Global Const $XC_LAYOUT_OBJECT = 101
Global Const $XC_ADAPTER = 102
Global Const $XC_ADAPTER_TABLE = 103
Global Const $XC_ADAPTER_TREE = 104
Global Const $XC_ADAPTER_LISTVIEW = 105
Global Const $XC_ADAPTER_MAP = 106
Global Const $XC_LAYOUT_LISTVIEW = 111
Global Const $XC_LAYOUT_LIST = 112
Global Const $XC_LAYOUT_OBJECT_GROUP = 113
Global Const $XC_LAYOUT_OBJECT_ITEM = 114
Global Const $XC_LAYOUT_PANEL = 115
Global Const $XC_BKINFOM = 116
Global Const $xc_window_style_nothing = 0
Global Const $xc_window_style_caption = 1
Global Const $xc_window_style_border = 2
Global Const $xc_window_style_center = 4
Global Const $xc_window_style_drag_border = 8
Global Const $xc_window_style_drag_window = 16
Global Const $xc_window_style_allow_maxWindow = 32
Global Const $xc_window_style_default = 47
Global Const $xc_window_style_default2 = 43
Global Const $xc_window_style_modal = 7
Global Const $window_position_error = -1
Global Const $window_position_top = 0
Global Const $window_position_bottom = 1
Global Const $window_position_left = 2
Global Const $window_position_right = 3
Global Const $window_position_body = 4
Global Const $window_position_window = 5
Global Const $window_transparent_false = 0
Global Const $window_transparent_shaped = 1
Global Const $window_transparent_shadow = 2
Global Const $window_transparent_simple = 3
Global Const $window_transparent_win7 = 4
Global Const $menu_item_flags_normal = 0
Global Const $menu_item_flags_select = 1
Global Const $menu_item_flags_check = 2
Global Const $menu_item_flags_popup = 4
Global Const $menu_item_flags_separator = 8
Global Const $menu_item_flags_disable = 16
Global Const $menu_popup_position_left_top = 0
Global Const $menu_popup_position_left_bottom = 1
Global Const $menu_popup_position_right_top = 2
Global Const $menu_popup_position_right_bottom = 3
Global Const $menu_popup_position_center_left = 4
Global Const $menu_popup_position_center_top = 5
Global Const $menu_popup_position_center_right = 6
Global Const $menu_popup_position_center_bottom = 7
Global Const $image_draw_type_default = 0
Global Const $image_draw_type_stretch = 1
Global Const $image_draw_type_adaptive = 2
Global Const $image_draw_type_tile = 3
Global Const $image_draw_type_fixed_ratio = 4
Global Const $image_draw_type_adaptive_border = 5
Global Const $common_state3_leave = 0
Global Const $common_state3_stay = 1
Global Const $common_state3_down = 2
Global Const $button_state_leave = 0
Global Const $button_state_stay = 1
Global Const $button_state_down = 2
Global Const $button_state_check = 3
Global Const $button_state_disable = 4
Global Const $button_type_default = 0
Global Const $button_type_check = 1
Global Const $button_type_radio = 2
Global Const $button_type_close = 3
Global Const $button_type_min = 4
Global Const $button_type_max = 5
Global Const $button_style_default = 0
Global Const $button_style_check = 1
Global Const $button_style_radio = 2
Global Const $button_style_scrollbar_up = 3
Global Const $button_style_scrollbar_down = 4
Global Const $button_style_scrollbar_left = 5
Global Const $button_style_scrollbar_right = 6
Global Const $button_style_scrollbar_slider = 7
Global Const $button_style_tabBar_button = 8
Global Const $button_style_toolBar_left = 9
Global Const $button_style_toolBar_right = 10
Global Const $button_style_toolBar_expand = 11
Global Const $button_style_pane_close = 12
Global Const $button_style_pane_lock = 13
Global Const $button_style_pane_menu = 14
Global Const $button_style_pane_dockH = 15
Global Const $button_style_pane_dockV = 16
Global Const $comboBox_state_leave = 0
Global Const $comboBox_state_stay = 1
Global Const $comboBox_state_down = 2
Global Const $list_item_state_leave = 0
Global Const $list_item_state_stay = 1
Global Const $list_item_state_select = 2
Global Const $tree_item_state_leave = 0
Global Const $tree_item_state_stay = 1
Global Const $tree_item_state_select = 2
Global Const $button_icon_align_left = 0
Global Const $button_icon_align_top = 1
Global Const $button_icon_align_right = 2
Global Const $button_icon_align_bottom = 3
Global Const $layout_size_type_fixed = 0
Global Const $layout_size_type_fill = 1
Global Const $layout_size_type_auto = 2
Global Const $layout_size_type_weight = 3
Global Const $layout_size_type_disable = 4
Global Const $list_drawItemBk_flags_nothing = 0
Global Const $list_drawItemBk_flags_leave = 1
Global Const $list_drawItemBk_flags_stay = 2
Global Const $list_drawItemBk_flags_select = 4
Global Const $list_drawItemBk_flags_group_leave = 8
Global Const $messageBox_flags_other = 0
Global Const $messageBox_flags_ok = 1
Global Const $messageBox_flags_cancel = 2
Global Const $propertyGrid_item_type_text = 0
Global Const $propertyGrid_item_type_edit = 1
Global Const $propertyGrid_item_type_edit_color = 2
Global Const $propertyGrid_item_type_edit_file = 3
Global Const $propertyGrid_item_type_edit_set = 4
Global Const $propertyGrid_item_type_comboBox = 5
Global Const $propertyGrid_item_type_group = 6
Global Const $zorder_top = 1
Global Const $zorder_bottom = 2
Global Const $zorder_before = 3
Global Const $zorder_after = 4
Global Const $layout_align_left = 0
Global Const $layout_align_top = 1
Global Const $layout_align_right = 2
Global Const $layout_align_bottom = 3
Global Const $layout_align_center = 4
Global Const $layout_align_equidistant = 5
Global Const $align_error = -1
Global Const $align_left = 0
Global Const $align_top = 1
Global Const $align_right = 2
Global Const $align_bottom = 3
Global Const $align_center = 4
Global Const $dock_align_left = 0
Global Const $dock_align_top = 1
Global Const $dock_align_right = 2
Global Const $dock_align_bottom = 3
Global Const $pane_state_any = 0
Global Const $pane_state_lock = 1
Global Const $pane_state_dock = 2
Global Const $pane_state_float = 3
Global Const $bkInfo_type_error = 0
Global Const $bkInfo_type_fill = 1
Global Const $bkInfo_type_border = 2
Global Const $bkInfo_type_image = 3
Global Const $bkInfo_type_triangle = 4
Global Const $bkInfo_type_rectangle = 5
Global Const $bkInfo_type_ellipse = 6
Global Const $bkInfo_type_roundRect = 7
Global Const $window_state_flag_nothing = 0
Global Const $window_state_whole_leave = 1
Global Const $window_state_body_leave = 2
Global Const $window_state_top_leave = 4
Global Const $window_state_bottom_leave = 8
Global Const $window_state_left_leave = 16
Global Const $window_state_right_leave = 32
Global Const $element_state_flag_nothing = 0
Global Const $element_state_flag_enable = 1
Global Const $element_state_flag_disable = 2
Global Const $element_state_flag_focus = 4
Global Const $element_state_flag_focus_no = 8
Global Const $element_state_flag_leave = 16
Global Const $element_state_flag_stay = 32
Global Const $element_state_flag_down = 64
Global Const $button_state_flag_leave = 16
Global Const $button_state_flag_stay = 32
Global Const $button_state_flag_down = 64
Global Const $button_state_flag_check = 128
Global Const $button_state_flag_check_no = 256
Global Const $button_state_flag_WindowRestore = 512
Global Const $button_state_flag_WindowMaximize = 1024
Global Const $comboBox_state_flag_leave = 16
Global Const $comboBox_state_flag_stay = 32
Global Const $comboBox_state_flag_down = 64
Global Const $listBox_state_flag_item_leave = 128
Global Const $listBox_state_flag_item_stay = 256
Global Const $listBox_state_flag_item_select = 512
Global Const $listBox_state_flag_item_select_no = 1024
Global Const $list_state_flag_item_leave = 128
Global Const $list_state_flag_item_stay = 256
Global Const $list_state_flag_item_select = 512
Global Const $list_state_flag_item_select_no = 1024
Global Const $listView_state_flag_item_leave = 128
Global Const $listView_state_flag_item_stay = 256
Global Const $listView_state_flag_item_select = 512
Global Const $listView_state_flag_item_select_no = 1024
Global Const $listView_state_flag_group_leave = 2048
Global Const $listView_state_flag_group_stay = 4096
Global Const $listView_state_flag_group_select = 8192
Global Const $listView_state_flag_group_select_no = 16384
Global Const $tree_state_flag_item_leave = 128
Global Const $tree_state_flag_item_stay = 256
Global Const $tree_state_flag_item_select = 512
Global Const $tree_state_flag_item_select_no = 1024
Global Const $monthCal_state_flag_leave = 16
Global Const $monthCal_state_flag_item_leave = 128
Global Const $monthCal_state_flag_item_stay = 256
Global Const $monthCal_state_flag_item_down = 512
Global Const $monthCal_state_flag_item_select = 1024
Global Const $monthCal_state_flag_item_select_no = 2048
Global Const $monthCal_state_flag_item_today = 4096
Global Const $monthCal_state_flag_item_other = 8192
Global Const $monthCal_state_flag_item_last_month = 16384
Global Const $monthCal_state_flag_item_cur_month = 32768
Global Const $monthCal_state_flag_item_next_month = 65536
Global Const $propertyGrid_state_flag_item_leave = 128
Global Const $propertyGrid_state_flag_item_stay = 256
Global Const $propertyGrid_state_flag_item_select = 512
Global Const $propertyGrid_state_flag_item_select_no = 1024
Global Const $pane_state_flag_leave = 128
Global Const $pane_state_flag_stay = 256
Global Const $pane_state_flag_caption = 512
Global Const $pane_state_flag_body = 1024
Global Const $monthCal_button_type_today = 0
Global Const $monthCal_button_type_last_year = 1
Global Const $monthCal_button_type_next_year = 2
Global Const $monthCal_button_type_last_month = 3
Global Const $monthCal_button_type_next_month = 4
Global Const $XWM_WINDPROC = 28672
Global Const $XWM_REDRAW_ELE = 28675
Global Const $XWM_DRAW_T = 28673
Global Const $XWM_MENU_POPUP = 28677
Global Const $XWM_MENU_POPUP_WND = 28678
Global Const $XWM_MENU_SELECT = 28679
Global Const $XWM_MENU_EXIT = 28680
Global Const $XWM_MENU_DRAW_BACKGROUND = 28681
Global Const $XWM_MENU_DRAWITEM = 28682
Global Const $XWM_COMBOBOX_POPUP_DROPLIST = 28683
Global Const $XWM_FLOAT_PANE = 28684
Global Const $XC_WINDOW_BODY = 10
Global Const $IDM_CLIP = 1000000000
Global Const $IDM_COPY = 1000000001
Global Const $IDM_PASTE = 1000000002
Global Const $IDM_DELETE = 1000000003
Global Const $IDM_SELECTALL = 1000000004
Global Const $IDM_DELETEALL = 1000000005
Global Const $IDM_LOCK = 1000000006
Global Const $IDM_DOCK = 1000000007
Global Const $IDM_FLOAT = 1000000008
Global Const $IDM_HIDE = 1000000009
Global Const $XE_LBUTTONDOWN = 10
Global Const $XE_LBUTTONUP = 11
Global Const $XE_RBUTTONDOWN = 12
Global Const $XE_RBUTTONUP = 13
Global Const $XE_LBUTTONDBCLICK = 14
Global Const $XE_RBUTTONDBCLICK = 15
Global Const $XE_SETFOCUS = 31
Global Const $XE_KILLFOCUS = 32
Global Const $XE_DESTROY = 33
Global Const $XE_BNCLICK = 34
Global Const $XE_BUTTON_CHECK = 35
Global Const $XE_SIZE = 36
Global Const $XE_SHOW = 37
Global Const $XE_SETFONT = 38
Global Const $XE_KEYDOWN = 39
Global Const $XE_CHAR = 40
Global Const $XE_SETCAPTURE = 51
Global Const $XE_KILLCAPTURE = 52
Global Const $XE_SETCURSOR = 53
Global Const $XE_SCROLLVIEW_SCROLL_H = 54
Global Const $XE_SCROLLVIEW_SCROLL_V = 55
Global Const $XE_SBAR_SCROLL = 56
Global Const $XE_MENU_POPUP = 57
Global Const $XE_MENU_POPUP_WND = 58
Global Const $XE_MENU_SELECT = 59
Global Const $XE_MENU_DRAW_BACKGROUND = 60
Global Const $XE_MENU_DRAWITEM = 61
Global Const $XE_MENU_EXIT = 62
Global Const $XE_SLIDERBAR_CHANGE = 63
Global Const $XE_PROGRESSBAR_CHANGE = 64
Global Const $XE_COMBOBOX_SELECT = 71
Global Const $XE_COMBOBOX_POPUP_LIST = 72
Global Const $XE_COMBOBOX_EXIT_LIST = 73
Global Const $XE_LISTBOX_TEMP_CREATE = 81
Global Const $XE_LISTBOX_TEMP_CREATE_END = 82
Global Const $XE_LISTBOX_TEMP_DESTROY = 83
Global Const $XE_LISTBOX_TEMP_ADJUST_COORDINATE = 84
Global Const $XE_LISTBOX_DRAWITEM = 85
Global Const $XE_LISTBOX_SELECT = 86
Global Const $XE_LIST_TEMP_CREATE = 101
Global Const $XE_LIST_TEMP_CREATE_END = 102
Global Const $XE_LIST_TEMP_DESTROY = 103
Global Const $XE_LIST_TEMP_ADJUST_COORDINATE = 104
Global Const $XE_LIST_DRAWITEM = 105
Global Const $XE_LIST_SELECT = 106
Global Const $XE_LIST_HEADER_DRAWITEM = 107
Global Const $XE_LIST_HEADER_CLICK = 108
Global Const $XE_LIST_HEADER_WIDTH_CHANGE = 109
Global Const $XE_LIST_HEADER_TEMP_CREATE = 110
Global Const $XE_LIST_HEADER_TEMP_CREATE_END = 111
Global Const $XE_LIST_HEADER_TEMP_DESTROY = 112
Global Const $XE_LIST_HEADER_TEMP_ADJUST_COORDINATE = 113
Global Const $XE_TREE_TEMP_CREATE = 121
Global Const $XE_TREE_TEMP_CREATE_END = 122
Global Const $XE_TREE_TEMP_DESTROY = 123
Global Const $XE_TREE_TEMP_ADJUST_COORDINATE = 124
Global Const $XE_TREE_DRAWITEM = 125
Global Const $XE_TREE_SELECT = 126
Global Const $XE_TREE_EXPAND = 127
Global Const $XE_TREE_DRAG_ITEM_ING = 128
Global Const $XE_TREE_DRAG_ITEM = 129
Global Const $XE_LISTVIEW_TEMP_CREATE = 141
Global Const $XE_LISTVIEW_TEMP_CREATE_END = 142
Global Const $XE_LISTVIEW_TEMP_DESTROY = 143
Global Const $XE_LISTVIEW_TEMP_ADJUST_COORDINATE = 144
Global Const $XE_LISTVIEW_DRAWITEM = 145
Global Const $XE_LISTVIEW_SELECT = 146
Global Const $XE_LISTVIEW_EXPAND = 147
Global Const $XE_PGRID_VALUE_CHANGE = 151
Global Const $XE_PGRID_ITEM_SET = 152
Global Const $XE_PGRID_ITEM_SELECT = 153
Global Const $XE_RICHEDIT_CHANGE = 161
Global Const $XE_RICHEDIT_SET = 162
Global Const $XE_TABBAR_SELECT = 221
Global Const $XE_TABBAR_DELETE = 222
Global Const $XE_MONTHCAL_CHANGE = 231
Global Const $XE_DATETIME_CHANGE = 241
Global Const $XE_DATETIME_POPUP_MONTHCAL = 242
Global Const $XE_DATETIME_EXIT_MONTHCAL = 243
Global Const $XE_DROPFILES = 250
Global Const $XC_PARAM_HIMAGE = 10
Global Const $XC_PARAM_HDRAW = 11
Global Const $XC_PARAM_P_RECT = 12
Global Const $XC_PARAM_P_POINT = 13
Global Const $XC_PARAM_P_SIZE = 14
Global Const $XC_PARAM_P_BOOL = 15
Global Const $XC_PARAM_P_listBox_item_i = 16
Global Const $XC_PARAM_P_list_header_item_i = 17
Global Const $XC_PARAM_P_list_item_i = 18
Global Const $XC_PARAM_P_listView_item_i = 19
Global Const $XC_PARAM_P_tree_item_i = 20
Global Const $XC_PARAM_P_menu_popupWnd = 21
Global Const $XC_PARAM_P_menu_drawBackground = 22
Global Const $XC_PARAM_P_menu_drawItem = 23
Global Const $XC_PARAM_HDROP = 24
Global Const $XC_PARAM_P_tree_dragItem_i = 25
Global Const $XC_WINDOW_TOP = 1
Global Const $XC_WINDOW_BOTTOM = 2
Global Const $XC_WINDOW_LEFT = 3
Global Const $XC_WINDOW_RIGHT = 4
Global Const $XC_WINDOW_TOPLEFT = 5
Global Const $XC_WINDOW_TOPRIGHT = 6
Global Const $XC_WINDOW_BOTTOMLEFT = 7
Global Const $XC_WINDOW_BOTTOMRIGHT = 8
Global Const $XC_WINDOW_CAPTION = 9
Global Const $XC_ID_ROOT = 0
Global Const $XE_ELEPROCE = 1
Global Const $XE_PAINT_END = 3
Global Const $XE_MOUSESTAY = 6
Global Const $XE_MOUSEHOVER = 7
Global Const $XE_MOUSELEAVE = 8
Global Const $XE_MOUSEWHEEL = 9
Global Const $XE_PAINT = 2
Global Const $XE_PAINT_SCROLLVIEW = 4
Global Const $XE_MOUSEMOVE = 5
Global Const $XC_PARAM_int = 1
Global Const $XC_PARAM_uint = 2
Global Const $XC_PARAM_BOOL = 3
Global Const $XC_PARAM_CHAR = 4
Global Const $XC_PARAM_BYTE = 5
Global Const $XC_PARAM_HXCGUI = 6
Global Const $XC_PARAM_HWINDOW = 7
Global Const $XC_PARAM_HELE = 8
Global Const $XC_PARAM_HMENUX = 9
Global Const $XC_ID_ERROR = -1
Global Const $XC_ID_FIRST = -2
Global Const $XC_ID_LAST = -3
Global Const $WM_MOUSEHOVER= 673
Global Const $WM_MOUSELEAVE= 675
Global Const $WM_MOVE= 3
Global Const $TME_LEAVE= 2
Global Const $TME_HOVER= 1
Global Const $WM_PAINT= 15

;=================自定义数据类型开始=======================
Func _POINTF()
	Return DllStructCreate("float x;float y")
EndFunc
Func _POINT()
	Return DllStructCreate("int x;int y")
EndFunc
Func _Size()
	Return DllStructCreate("int cx;int cy")
EndFunc
Func _BorderSize()
	Return DllStructCreate("int leftSize;int topSize;int rightSize;int bottomSize")
EndFunc
Func _SpaceSize()
	Return DllStructCreate("int leftSize;int topSize;int rightSize;int bottomSize")
EndFunc
Func _PaddingSize()
	Return DllStructCreate("int leftSize;int topSize;int rightSize;int bottomSize")
EndFunc
Func _RECTF()
	Return DllStructCreate("float left;float top;float right;float bottom")
EndFunc
Func _RECT()
	Return DllStructCreate("int left;int top;int right;int bottom")
EndFunc
Func _Position()
	Return DllStructCreate("int iRow;int iColumn")
EndFunc
Func _template_info_i()
	Return DllStructCreate("int info")
EndFunc
Func _listBox_item_i()
	Return DllStructCreate("int nUserData;int nHeight;int nSelHeight;int nState;int index;ptr rcItem[4];int hLayout;int Info")
EndFunc
Func _listBox_item_Info_i()
	Return DllStructCreate("int nUserData;int nHeight;int nSelHeight")
EndFunc
Func _listView_item_id_i()
	Return DllStructCreate("int iGroup;int iItem")
EndFunc
Func _list_item_i()
	Return DllStructCreate("int index;int iSubItem;int nUserData;int nState;ptr rcItem[4];int hLayout;int Info")
EndFunc
Func _list_header_item_i()
	Return DllStructCreate("int index;int nUserData;int nState;ptr rcItem[4];int hLayout;int Info")
EndFunc
Func _tree_item_i()
	Return DllStructCreate("int nID;int nDepth;int nState;int nHeight;int nSelHeight;int nUserData;bool bExpand;ptr rcItem[4];int hLayout;int Info")
EndFunc
Func _listView_item_i()
	Return DllStructCreate("int iGroup;int iItem;int nUserData;int nState;ptr rcItem[4];int hLayout;int Info")
EndFunc
Func _layout_info_i()
	Return DllStructCreate("int widthType;int heightType;short width;short height")
EndFunc
Func _menu_popupWnd_i()
	Return DllStructCreate("int hWindow;int nParentID")
EndFunc
Func _menu_drawBackground_i()
	Return DllStructCreate("int hMenu;int hWindow;int nParentID")
EndFunc
Func _menu_drawItem_i()
	Return DllStructCreate("int hMenu;int hWindow;int nID;int nState;ptr rcItem[4];int hIcon;str Text")
EndFunc
Func _tree_drag_item_i()
	Return DllStructCreate("int nDragItem;int nDestItem;int nType")
EndFunc
Func _xc_font_info_i()
	Return DllStructCreate("int nSize;bool bBold;bool bItalic;bool bUnderline;bool bStrikeout;short aName[32]")
EndFunc
Func _monthCal_item_i()
	Return DllStructCreate("int nDay;int nType;int nState;ptr rcItem[4]")
EndFunc
Func _MinMaxInfo()
	Return DllStructCreate("int ptReserved[2];int ptMaxSize[2];int ptMaxPosition[2];int ptMinTrackSize[2];int ptMaxTrackSize[2]")
EndFunc
;=================自定义数据类型结束=======================
If Not FileExists(@ScriptDir & "\XCGUI.dll") Then
	MsgBox(266160,"?","没有找到XCGUI.dll!!"&@CRLF&"请将XCGUI.dll放到程序根目录!")
	Exit
EndIf
Local $_xcdll = DllOpen(@ScriptDir & "\XCGUI.dll")

;~ ============================================
;~   CopyMemory($_pa,$_pb,$_s1=1,$_s2=0,$_ss=1)
;~   功能: 复制内存数据
;~   参数: $_pa  目标内存
;~         $_pb  源内存
;~         $_s1  目标内存是否输入数据结构，1/0
;~         $_s2  源内存是否输入数据结构，1/0
;~         $_ss  设置数据结构大小,1为目标内存,0为源内存
;~ ============================================
Func CopyMemory($_pa,$_pb,$_s1=1,$_s2=0,$_ss=1)
	If $_ss=1 Then
		$_GetSize=DllStructGetSize($_pa)
	Else
		$_GetSize=DllStructGetSize($_pb)
	EndIf
	If $_s1=1 Then
		$_pa=DllStructGetPtr($_pa)
	EndIf
	If $_s2=1 Then
		$_pb=DllStructGetPtr($_pb)
	EndIf
	DllCall("Kernel32.dll","none","RtlMoveMemory","ptr",$_pa,"ptr",$_pb,"int",$_GetSize)
EndFunc

Func ClientToScreen($_hwnd,$_point)
	DllCall("user32.dll","int","ClientToScreen","hwnd",XWnd_GetHWND($_hwnd),"ptr",DllStructGetPtr($_point))
EndFunc

Func pHandle($_pHandle,$_bool=True)
	$a=DllStructCreate("bool")
	CopyMemory($a,$_pHandle)
	DllStructSetData($a,1,$_bool)
	CopyMemory($_pHandle,$a,0,1,0)
EndFunc

;=================全局API开始=======================
;~ ============================================
;~   XInitXCGUI()
;~   功能:初始化界面库.
;~ ============================================
Func XInitXCGUI()
	DllCall($_xcdll, "bool", "XInitXCGUI", "int", "0")
EndFunc   ;==>XInitXCGUI

;~ ============================================
;~   XRunXCGUI()
;~   功能: 运行消息循环,当炫彩窗口数量为0时退出.
;~ ============================================
Func XRunXCGUI()
	DllCall($_xcdll, "none", "XRunXCGUI")
EndFunc   ;==>XRunXCGUI

;~ ============================================
;~   XExitXCGUI()
;~   功能: 退出界面库释放资源.
;~ ============================================
Func XExitXCGUI()
	DllCall($_xcdll, "none", "XExitXCGUI")
EndFunc   ;==>XExitXCGUI

;~ ============================================
;~   XQuit_ACN($_win)
;~   功能: 退出程序.
;~   参数: $_win  主窗口句柄
;~ ============================================
Func XQuit_ACN($_win)
	XWnd_CloseWindow($_win)
	XExitXCGUI()
	Exit
EndFunc

;~ ============================================
;~   XC_EnableDebugFile($_bEnabel)
;~   功能: 是否输出调试文件 xcgui_debug.txt
;~   参数: $_bEnabel  True/False
;~ ============================================
Func XC_EnableDebugFile($_bEnabel)
	DllCall($_xcdll, "none", "XC_EnableDebugFile", "bool", $_bEnabel)
EndFunc

Func XC_DebugToFileInfo($_pInfo)
	DllCall($_xcdll, "none", "XC_DebugToFileInfo", "str", $_pInfo)
EndFunc   ;==>XC_DebugToFileInfo

Func XC_EnableErrorMessageBox($_bEnabel)
	DllCall($_xcdll, "none", "XC_EnableErrorMessageBox", "bool", $_bEnabel)
EndFunc   ;==>XC_EnableErrorMessageBox

Func XC_SetLayoutFrameColor($_color)
	DllCall($_xcdll, "none", "XC_SetLayoutFrameColor", "int", $_color)
EndFunc   ;==>XC_SetLayoutFrameColor

Func XC_ShowLayoutFrame($_bShow)
	DllCall($_xcdll, "none", "XC_ShowLayoutFrame", "int", $_bShow)
EndFunc   ;==>XC_ShowLayoutFrame

Func XC_CombineRect($_pDest, $_pSrc1, $_pSrc2)
	DllCall($_xcdll, "none", "XC_CombineRect", "int", $_pDest, "int", $_pSrc1, "int", $_pSrc2)
EndFunc   ;==>XC_CombineRect

Func XC_SetPaintFrequency($_nMilliseconds)
	DllCall($_xcdll, "none", "XC_SetPaintFrequency", "int", $_nMilliseconds)
EndFunc   ;==>XC_SetPaintFrequency

Func XC_IsHELE($_hEle)
	$_XC = DllCall($_xcdll, "bool", "XC_SetPaintFrequency", "hwnd", $_hEle)
	Return $_XC[0]
EndFunc   ;==>XC_IsHELE

Func XC_IsHWINDOW($_hWindow)
	$_XC = DllCall($_xcdll, "bool", "XC_IsHWINDOW", "int", $_hWindow)
	Return $_XC[0]
EndFunc   ;==>XC_IsHWINDOW

Func XC_IsShape($_hShape)
	$_XC = DllCall($_xcdll, "bool", "XC_IsShape", "int", $_hShape)
	Return $_XC[0]
EndFunc   ;==>XC_IsShape

Func XC_IsHXCGUI($_hXCGUI, $_nType)
	$_XC = DllCall($_xcdll, "bool", "XC_IsHXCGUI", "int", $_hXCGUI, "int", $_nType)
	Return $_XC[0]
EndFunc   ;==>XC_IsHXCGUI

Func XC_hWindowFromHWnd($_hWnd)
	$_XC = DllCall($_xcdll, "hwnd", "XC_hWindowFromHWnd", "hwnd", $_hWnd)
	Return $_XC[0]
EndFunc   ;==>XC_hWindowFromHWnd

Func XC_IsSViewExtend($_hEle)
	$_XC = DllCall($_xcdll, "bool", "XC_IsSViewExtend", "int", $_hEle)
	Return $_XC[0]
EndFunc   ;==>XC_IsSViewExtend

Func XC_GetObjectType($_hXCGUI)
	$_XC = DllCall($_xcdll, "int", "XC_GetObjectType", "int", $_hXCGUI)
	Return $_XC[0]
EndFunc   ;==>XC_IsSViewExtend

Func XC_GetObjectByID($_nID)
	$_XC = DllCall($_xcdll, "int", "XC_GetObjectByID", "int", $_nID)
	Return $_XC[0]
EndFunc   ;==>XC_GetObjectByID

Func XC_GetResIDValue($_pName)
	$_XC = DllCall($_xcdll, "int", "XC_GetResIDValue", "wstr", $_pName)
	Return $_XC[0]
EndFunc   ;==>XC_GetResIDValue

Func XC_RectInRect($_pSrc1, $_pSrc2)
	$_XC = DllCall($_xcdll, "int", "XC_RectInRect", "int", $_pSrc1, "int", $_pSrc2)
	Return $_XC[0]
EndFunc   ;==>XC_RectInRect
;=================全局API结束=======================
;=================window-基础窗口开始=======================
;~ ==================================================================
;~   XWnd_Create($_x,$_y,$_width,$_height,$_title,$_style,$_parent=0)
;~   功能: 创建窗口
;~   参数: $_x          窗口左上角x坐标.
;~   	   $_y          窗口左上角y坐标.
;~         $_width      窗口宽度.
;~         $_height     窗口高度.
;~         $_title      窗口标题.
;~         $_style      GUI库窗口样式.
;~         $_parent     父窗口句柄，（可选参数）

;~   返回值:
;~       成功: 返回GUI窗口句柄
;~ ==================================================================
Func XWnd_Create($_x, $_y, $_width, $_height, $_title, $_style, $_parent = 0)
	$_Create = DllCall($_xcdll, "hwnd", "XWnd_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", $_title, "HWND", $_parent, "int", $_style)
	Return $_Create[0]
EndFunc   ;==>XWnd_Create
;~ ==================================================================
;~   XWnd_CreateEx($_ExStyle, $_ClassName, $_WindowName, $_dwstyle, $_x, $_y, $_width, $_height, $_style, $_parent = 0)
;~   功能: 创建窗口,高级模式
;~   参数: $_ExStyle    窗口扩展样式.
;~         $_ClassName  窗口类名.
;~         $_WindowName 窗口名.
;~         $_dwstyle    窗口样式
;~         $_x          窗口左上角x坐标.
;~   	   $_y          窗口左上角y坐标.
;~         $_width      窗口宽度.
;~         $_height     窗口高度.
;~         $_style      GUI库窗口样式.
;~         $_parent     父窗口句柄，（可选参数）

;~   返回值:
;~       成功: 返回GUI窗口句柄
;~ ==================================================================
Func XWnd_CreateEx($_ExStyle, $_ClassName, $_WindowName, $_dwstyle, $_x, $_y, $_width, $_height, $_style, $_parent = 0)
	$_Create = DllCall($_xcdll, "hwnd", "XWnd_CreateEx", "DWORD", $_ExStyle, "wstr", $_ClassName, "wstr", $_WindowName, "DWORD", $_dwstyle, "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", "HWND", $_parent, "int", $_style)
	Return $_Create[0]
EndFunc   ;==>XWnd_CreateEx
;~ ======================================================
;~ XWnd_RegEventC($_hwnd, $_fun, $_event = 34 ,$_parameter="int")
;~  功能: 注册事件函数C方式,事件函数省略自身HWINDOW句柄.
;~  参数:$_hwnd    窗口句柄
;~       $_fun     事件类型
;~ 	  $_event   事件函数,(可选参数,默认为点击事件)
;~ ======================================================
Func XWnd_RegEventC($_hWnd, $_fun, $_event = 34, $_parameter="int")
	DllCall($_xcdll, "none", "XWnd_RegEventC", "hwnd", $_hWnd, "int", $_event, "ptr", DllCallbackGetPtr(DllCallbackRegister($_fun, "int", $_parameter)))
EndFunc   ;==>XWnd_RegEventC
;~ ======================================================
;~ XWnd_RegEventC1($_hwnd, $_fun, $_event = 34)
;~  功能: 注册事件函数C方式,事件函数不省略自身HWINDOW句柄.
;~  参数:$_hwnd    窗口句柄
;~       $_fun     事件类型
;~ 	  $_event   事件函数,(可选参数,默认为点击事件)
;~ ======================================================
Func XWnd_RegEventC1($_hWnd, $_fun, $_event = 34, $_parameter="int")
	DllCall($_xcdll, "none", "XWnd_RegEventC1", "hwnd", $_hWnd, "int", $_event, "ptr", DllCallbackGetPtr(DllCallbackRegister($_fun, "int", $_parameter)))
EndFunc   ;==>XWnd_RegEventC1

Func XWnd_SetDragBorderSize($_win, $_left, $_top, $_right, $_bottom)
	DllCall($_xcdll, "int", "XWnd_SetDragBorderSize", "hwnd", $_win, "int", $_left, "int", $_top, "int", $_right, "int", $_bottom)
EndFunc   ;==>XWnd_SetDragBorderSize
;~ ======================================================
;~ XWnd_RedrawWnd($_win,$_bImmediate)
;~ 功能: 重绘窗口
;~ 参数: $_win          窗口句柄
;~       $_bImmediate   是否立即重绘,默认为否.
;~                     TRUE立即重绘,FALSE放入消息队列延迟重绘
;~ ======================================================
Func XWnd_RedrawWnd($_win, $_bImmediate)
	DllCall($_xcdll, "none", "XWnd_RedrawWnd", "hwnd", $_win, "bool", $_bImmediate)
EndFunc   ;==>XWnd_RedrawWnd
;~ ======================================================
;~ XWnd_SetTransparentType($_win, $_alpha)
;~  功能: 设置透明窗口,同时可以通过该函数关闭透明窗口
;~  参数: $_win    窗口句柄
;~        $_alpha  窗口透明类型
;~ ======================================================
Func XWnd_SetTransparentType($_win, $_alpha)
	DllCall($_xcdll, "none", "XWnd_SetTransparentType", "hwnd", $_win, "BYTE", $_alpha)
EndFunc   ;==>XWnd_SetTransparentType
;~ ======================================================
;~ XWnd_SetTransparentAlpha($_win, $_alpha)
;~  功能: 设置透明窗口的透明度,已内置刷新功能,无需再次调用刷新功能
;~  参数: $_win     窗口句柄
;~        $_alpha   窗口透明度,范围0-255之间,0透明,255不透明
;~ ======================================================
Func XWnd_SetTransparentAlpha($_win, $_alpha)
	DllCall($_xcdll, "none", "XWnd_SetTransparentAlpha", "hwnd", $_win, "int", $_alpha)
	XWnd_RedrawWnd($_win, True)
EndFunc   ;==>XWnd_SetTransparentAlpha
;~ ======================================================
;~ XWnd_SetTransparentColor($_win, $_color)
;~  功能: 设置透明窗口的透明色
;~  参数: $_win     窗口句柄
;~        $_color   窗口透明色
;~ ======================================================
Func XWnd_SetTransparentColor($_win, $_color)
	DllCall($_xcdll, "int", "XWnd_SetTransparentColor", "hwnd", $_win, "int", $_color)
	XWnd_RedrawWnd($_win, True)
EndFunc   ;==>XWnd_SetTransparentColor
;~ ==================================
;~ Wnd_ShowWindow($_win)
;~ 功能: 显示窗口
;~ 参数: $_win  GUI窗口句柄
;~ ==================================
Func XWnd_ShowWindow($_win)
	DllCall($_xcdll, "int", "XWnd_ShowWindow", "hwnd", $_win, "int", @SW_SHOW)
EndFunc   ;==>XWnd_ShowWindow
;~ ==================================
;~ XWnd_CloseWindow($_win)
;~ 功能: 关闭窗口
;~ 参数: $_win  GUI窗口句柄
;~ ==================================
Func XWnd_CloseWindow($_win)
	DllCall($_xcdll, "none", "XWnd_CloseWindow", "hwnd", $_win)
EndFunc   ;==>XWnd_CloseWindow
;~ ==========================================
;~ XWnd_EnableDragBorder($_win,$_enable)
;~ 功能: 启用拖动窗口边框
;~ 参数: $_win  GUI窗口句柄
;~ 	  $_enable  True(启用),False(不启用)
;~ ==========================================
Func XWnd_EnableDragBorder($_win, $_enable)
	DllCall($_xcdll, "none", "XWnd_EnableDragBorder", "hwnd", $_win, "bool", $_enable)
EndFunc   ;==>XWnd_EnableDragBorder
;~ ==========================================
;~ XWnd_EnableDragCaption($_win,$_enable)
;~ 功能: 启用拖动窗口标题栏
;~ 参数: $_win  GUI窗口句柄
;~ 	  $_enable  True(启用),False(不启用)
;~ ==========================================
Func XWnd_EnableDragCaption($_win, $_enable)
	DllCall($_xcdll, "none", "XWnd_EnableDragCaption", "hwnd", $_win, "bool", $_enable)
EndFunc   ;==>XWnd_EnableDragCaption
;~ ==========================================
;~ XWnd_EnableDragWindow($_win,$_enable)
;~ 功能: 启用拖动窗口
;~ 参数: $_win  GUI窗口句柄
;~ 	  $_enable  True(启用),False(不启用)
;~ ==========================================
Func XWnd_EnableDragWindow($_win, $_enable)
	DllCall($_xcdll, "none", "XWnd_EnableDragWindow", "hwnd", $_win, "bool", $_enable)
EndFunc   ;==>XWnd_EnableDragWindow
;~ ==========================================
;~ XWnd_EnableDrawBk($_win,$_enable)
;~ 功能: 是否绘制窗口背景
;~ 参数: $_win  GUI窗口句柄
;~ 	  $_enable  True(启用),False(不启用)
;~ ==========================================
Func XWnd_EnableDrawBk($_win, $_enable)
	DllCall($_xcdll, "none", "XWnd_EnableDrawBk", "hwnd", $_win, "bool", $_enable)
EndFunc   ;==>XWnd_EnableDrawBk
;~ ==========================================
;~ XWnd_EnableMaxWindow($_win,$_enable)
;~ 功能: 允许窗口最大化
;~ 参数: $_win  GUI窗口句柄
;~ 	  $_enable  True(启用),False(不启用)
;~ ==========================================
Func XWnd_EnableMaxWindow($_win, $_enable)
	DllCall($_xcdll, "none", "XWnd_EnableMaxWindow", "hwnd", $_win, "bool", $_enable)
EndFunc   ;==>XWnd_EnableMaxWindow

Func XWnd_EnableAutoFocus($_win, $_enable)
	DllCall($_xcdll, "none", "XWnd_EnableAutoFocus", "hwnd", $_win, "bool", $_enable)
EndFunc   ;==>XWnd_EnableAutoFocus

Func XWnd_RemovegEvent($_hWnd, $_fun, $_event = 34)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_RemovegEvent", "hwnd", $_hWnd, "int", $_event, "ptr", DllCallbackGetPtr(DllCallbackRegister($_fun, "int", "BOOL")))
	Return $_XWnd[0]
EndFunc   ;==>XWnd_RemovegEvent

Func XWnd_AddEle($_hWnd, $_hEle)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_AddEle", "hwnd", $_hWnd, "hwnd", $_hEle)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_AddEle

Func XWnd_InsertEle($_hWnd, $_hEle, $_index)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_InsertEle", "hwnd", $_hWnd, "hwnd", $_hEle, "int", $_index)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_InsertEle

Func XWnd_AddShape($_hWnd, $_hShape)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_AddShape", "hwnd", $_hWnd, "int", $_hShape)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_AddShape

Func XWnd_RedrawWndRect($_win, $_pRect, $_bImmediate)
	DllCall($_xcdll, "none", "XWnd_RedrawWndRect", "hwnd", $_win, "int", $_pRect, "bool", $_bImmediate)
EndFunc   ;==>XWnd_RedrawWndRect

Func XWnd_SetFocusEle($_win, $_hFocusEle)
	DllCall($_xcdll, "none", "XWnd_SetFocusEle", "hwnd", $_win, "hwnd", $_hFocusEle)
EndFunc   ;==>XWnd_SetFocusEle

Func XWnd_GetFocusEle($_hWnd)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetFocusEle", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetFocusEle

Func XWnd_GetStayHELE($_hWnd)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetStayHELE", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetStayHELE

Func XWnd_SetCursor($_win, $_hCursor)
	DllCall($_xcdll, "none", "XWnd_SetCursor", "hwnd", $_win, "int", $_hCursor)
EndFunc   ;==>XWnd_SetCursor

Func XWnd_GetCursor($_hWnd)
	$_XWnd = DllCall($_xcdll, "int", "XWnd_GetCursor", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetCursor

Func XWnd_GetHWND($_hWnd)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetHWND", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetHWND

Func XWnd_SetCaptureEle($_win, $_hEle)
	DllCall($_xcdll, "none", "XWnd_SetCaptureEle", "hwnd", $_win, "hwnd", $_hEle)
EndFunc   ;==>XWnd_SetCaptureEle

Func XWnd_GetCaptureEle($_hWnd)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetCaptureEle", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetCaptureEle

Func XWnd_GetDrawRect($_win, $_pRcPaint)
	DllCall($_xcdll, "none", "XWnd_GetDrawRect", "hwnd", $_win, "int", $_pRcPaint)
EndFunc   ;==>XWnd_GetDrawRect

Func XWnd_BindLayoutEle($_hWnd, $_nPosition, $_hEle)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_BindLayoutEle", "hwnd", $_hWnd, "int", $_nPosition, "hwnd", $_hEle)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_BindLayoutEle

Func XWnd_GetLayoutEle($_hWnd, $_nPosition)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetLayoutEle", "hwnd", $_hWnd, "int", $_nPosition)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetLayoutEle

Func XWnd_SetCursorSys($_hWnd, $_hCursor)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_SetCursorSys", "hwnd", $_hWnd, "int", $_hCursor)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_SetCursorSys

Func XWnd_SetFont($_win, $_hFontx)
	DllCall($_xcdll, "none", "XWnd_SetFont", "hwnd", $_win, "hwnd", $_hFontx)
EndFunc   ;==>XWnd_SetFont

Func XWnd_GetID($_hWnd)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetID", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetID

Func XWnd_SetID($_win, $_nID)
	DllCall($_xcdll, "none", "XWnd_SetID", "hwnd", $_win, "int", $_nID)
EndFunc   ;==>XWnd_SetID

Func XWnd_SetLayoutSize($_win, $_left, $_top, $_right, $_bottom)
	DllCall($_xcdll, "none", "XWnd_SetLayoutSize", "hwnd", $_win, "int", $_left, "int", $_top, "int", $_right, "hwnd", $_bottom)
EndFunc   ;==>XWnd_SetLayoutSize

Func XWnd_SetMinimumSize($_win, $_width, $_height)
	DllCall($_xcdll, "none", "XWnd_SetMinimumSize", "hwnd", $_win, "int", $_width, "int", $_height)
EndFunc   ;==>XWnd_SetMinimumSize

Func XWnd_HitChildEle($_hWnd, $_pPt)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_HitChildEle", "hwnd", $_hWnd, "int", $_pPt)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_HitChildEle

Func XWnd_GetChildCount($_hWnd)
	$_XWnd = DllCall($_xcdll, "int", "XWnd_GetChildCount", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetChildCount

Func XWnd_GetChildByIndex($_hWnd, $_index)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetChildByIndex", "hwnd", $_hWnd, "int", $_index)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetChildByIndex

Func XWnd_GetChildByID($_hWnd, $_nID)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetChildByID", "hwnd", $_hWnd, "int", $_nID)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetChildByID

Func XWnd_GetEle($_hWnd, $_nID)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetEle", "hwnd", $_hWnd, "int", $_nID)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetEle

Func XWnd_GetChildShapeCount($_hWnd)
	$_XWnd = DllCall($_xcdll, "int", "XWnd_GetChildShapeCount", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetChildShapeCount

Func XWnd_GetChildShapeByIndex($_hWnd, $_index)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetChildShapeByIndex", "hwnd", $_hWnd, "int", $_index)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetChildShapeByIndex

Func XWnd_BindLayoutObject($_win, $_nPosition, $_hLayout)
	DllCall($_xcdll, "none", "XWnd_BindLayoutObject", "hwnd", $_win, "int", $_nPosition, "int", $_hLayout)
EndFunc   ;==>XWnd_BindLayoutObject

Func XWnd_GetLayoutObject($_hWnd, $_nPosition)
	$_XWnd = DllCall($_xcdll, "int", "XWnd_GetLayoutObject", "hwnd", $_hWnd, "int", $_nPosition)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetLayoutObject

Func XWnd_AdjustLayout($_win)
	DllCall($_xcdll, "none", "XWnd_AdjustLayout", "hwnd", $_win)
EndFunc   ;==>XWnd_AdjustLayout

Func XWnd_AdjustLayoutObject($_win)
	DllCall($_xcdll, "none", "XWnd_AdjustLayoutObject", "hwnd", $_win)
EndFunc   ;==>XWnd_AdjustLayoutObject

Func XWnd_CreateCaret($_win, $_hEle, $_width, $_height)
	DllCall($_xcdll, "none", "XWnd_CreateCaret", "hwnd", $_win, "hwnd", $_hEle, "int", $_width, "int", $_height)
EndFunc   ;==>XWnd_CreateCaret

Func XWnd_SetCaretSize($_win, $_width, $_height)
	DllCall($_xcdll, "none", "XWnd_SetCaretSize", "hwnd", $_win, "int", $_width, "int", $_height)
EndFunc   ;==>XWnd_SetCaretSize

Func XWnd_SetCaretPos($_win, $_x, $_y)
	DllCall($_xcdll, "none", "XWnd_SetCaretPos", "hwnd", $_win, "int", $_x, "int", $_y)
EndFunc   ;==>XWnd_SetCaretPos

Func XWnd_SetCaretPosEx($_win, $_x, $_y, $_width, $_height)
	DllCall($_xcdll, "none", "XWnd_SetCaretPosEx", "hwnd", $_win, "int", $_x, "int", $_y, "int", $_width, "int", $_height)
EndFunc   ;==>XWnd_SetCaretPosEx

Func XWnd_SetCaretColor($_win, $_color)
	DllCall($_xcdll, "none", "XWnd_SetCaretColor", "hwnd", $_win, "int", $_color)
EndFunc   ;==>XWnd_SetCaretColor

Func XWnd_ShowCaret($_win, $_bShow)
	DllCall($_xcdll, "none", "XWnd_ShowCaret", "hwnd", $_win, "bool", $_bShow)
EndFunc   ;==>XWnd_ShowCaret

Func XWnd_DestroyCaret($_win)
	DllCall($_xcdll, "none", "XWnd_DestroyCaret", "hwnd", $_win)
EndFunc   ;==>XWnd_ShowCaret

Func XWnd_GetCaretHELE($_hWnd)
	$_XWnd = DllCall($_xcdll, "int", "XWnd_GetCaretHELE", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetCaretHELE

Func XWnd_GetClientRect($_hWnd, $_pRect)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_GetClientRect", "hwnd", $_hWnd, "int", $_pRect)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetClientRect

Func XWnd_GetBodyRect($_hWnd, $_pRect)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_GetBodyRect", "hwnd", $_hWnd, "int", $_pRect)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetBodyRect

Func XWnd_KillTimer($_hWnd, $_nIDEvent)
	$_XWnd = DllCall($_xcdll, "bool", "XWnd_KillTimer", "hwnd", $_hWnd, "uint", $_nIDEvent)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_KillTimer

Func XWnd_GetBkInfoManager($_hWnd)
	$_XWnd = DllCall($_xcdll, "hwnd", "XWnd_GetBkInfoManager", "hwnd", $_hWnd)
	Return $_XWnd[0]
EndFunc   ;==>XWnd_GetBkInfoManager
;=================window-基础窗口结束=======================
;=================FrameWindow-框架窗口开始=======================
Func XFrameWnd_Create($_x, $_y, $_width, $_height, $_title, $_style, $_parent = 0)
	$_Create = DllCall($_xcdll, "hwnd", "XFrameWnd_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", $_title, "HWND", $_parent, "int", $_style)
	Return $_Create[0]
EndFunc   ;==>XFrameWnd_Create

Func XFrameWnd_CreateEx($_ExStyle, $_ClassName, $_WindowName, $_dwstyle, $_x, $_y, $_width, $_height, $_style, $_parent = 0)
	$_Create = DllCall($_xcdll, "hwnd", "XFrameWnd_CreateEx", "DWORD", $_ExStyle, "wstr", $_ClassName, "wstr", $_WindowName, "DWORD", $_dwstyle, "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", "HWND", $_parent, "int", $_style)
	Return $_Create[0]
EndFunc   ;==>XFrameWnd_CreateEx

Func XFrameWnd_GetLayoutAreaRect($_hWnd, $_pRect)
	DllCall($_xcdll, "none", "XFrameWnd_GetLayoutAreaRect", "hwnd", $_hWnd, "int", $_pRect)
EndFunc   ;==>XFrameWnd_GetLayoutAreaRect

Func XFrameWnd_SetView($_hWnd, $_hEle)
	DllCall($_xcdll, "none", "XFrameWnd_SetView", "hwnd", $_hWnd, "hwnd", $_hEle)
EndFunc   ;==>XFrameWnd_SetView

Func XFrameWnd_SetPaneSplitBarColor($_hWnd, $_color, $_alpha)
	DllCall($_xcdll, "none", "XFrameWnd_SetPaneSplitBarColor", "hwnd", $_hWnd, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XFrameWnd_SetPaneSplitBarColor

Func XFrameWnd_AddPane($_hEle, $_hPaneDest, $_hPaneNew, $_align)
	$_XFrameWnd = DllCall($_xcdll, "bool", "XFrameWnd_AddPane", "hwnd", $_hEle, "hwnd", $_hPaneDest, "hwnd", $_hPaneNew, "int", $_align)
	Return $_XFrameWnd[0]
EndFunc   ;==>XFrameWnd_AddPane

Func XFrameWnd_MergePane($_hEle, $_hPaneDest, $_hPaneNew)
	$_XFrameWnd = DllCall($_xcdll, "bool", "XFrameWnd_MergePane", "hwnd", $_hEle, "hwnd", $_hPaneDest, "hwnd", $_hPaneNew)
	Return $_XFrameWnd[0]
EndFunc   ;==>XFrameWnd_MergePane
;=================FrameWindow-框架窗口结束=======================
;=================modalWindow-模态窗口=======================
Func XModalWnd_Create($_width, $_height, $_title, $_parent,$_style)
	$_Create = DllCall($_xcdll, "hwnd", "XModalWnd_Create", "int", $_width, "int", $_height, "wstr", $_title, "HWND", $_parent, "int", $_style)
	Return $_Create[0]
EndFunc   ;==>XModalWnd_Create

Func XModalWnd_CreateEx($_ExStyle, $_ClassName, $_WindowName, $_dwstyle, $_x, $_y, $_width, $_height,$_parent, $_style )
	$_Create = DllCall($_xcdll, "hwnd", "XModalWnd_CreateEx", "DWORD", $_ExStyle, "wstr", $_ClassName, "wstr", $_WindowName, "DWORD", $_dwstyle, "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", "HWND", $_parent, "int", $_style)
	Return $_Create[0]
EndFunc   ;==>XModalWnd_CreateEx

Func XModalWnd_EnableAutoClose($_hWnd, $_bEnable)
	DllCall($_xcdll, "none", "XModalWnd_EnableAutoClose", "hwnd", $_hWnd, "bool", $_bEnable)
EndFunc   ;==>XModalWnd_EnableAutoClose

Func XModalWnd_DoModal($_hWnd)
	$_XModalWnd = DllCall($_xcdll, "int", "XModalWnd_DoModal", "hwnd", $_hWnd)
	Return $_XModalWnd[0]
EndFunc   ;==>XModalWnd_DoModal

Func XModalWnd_EndModal($_hWnd, $_nResult)
	DllCall($_xcdll, "none", "XModalWnd_EndModal", "hwnd", $_hWnd, "int", $_nResult)
EndFunc   ;==>XModalWnd_EnableAutoClose
;=================modalWindow-模态窗口结束=======================
;=================Menu-弹出菜单开始=======================
Func XMenu_Create()
	$_XMenu = DllCall($_xcdll, "hwnd", "XMenu_Create")
	Return $_XMenu[0]
EndFunc   ;==>XMenu_Create

Func XMenu_AddItem($_hMenu, $_nID, $_pText, $_nParentID, $_nFlags)
	DllCall($_xcdll, "none", "XMenu_AddItem", "hwnd", $_hMenu, "int", $_nID, "wstr", $_pText, "int", $_nParentID, "int", $_nFlags)
EndFunc   ;==>XMenu_AddItem

Func XMenu_AddItemIcon($_hMenu, $_nID, $_pText, $_nParentID, $_hIcon, $_nFlags)
	DllCall($_xcdll, "none", "XMenu_AddItemIcon", "hwnd", $_hMenu, "int", $_nID, "wstr", $_pText, "int", $_nParentID, "hwnd", $_hIcon, "int", $_nFlags)
EndFunc   ;==>XMenu_AddItemIcon

Func XMenu_InsertItem($_hMenu, $_nID, $_pText, $_nFlags, $_insertID)
	DllCall($_xcdll, "none", "XMenu_InsertItem", "hwnd", $_hMenu, "int", $_nID, "wstr", $_pText, "int", $_nFlags, "int", $_insertID)
EndFunc   ;==>XMenu_InsertItem

Func XMenu_InsertItemIcon($_hMenu, $_nID, $_pText, $_hIcon, $_nFlags, $_insertID)
	DllCall($_xcdll, "none", "XMenu_InsertItemIcon", "hwnd", $_hMenu, "int", $_nID, "wstr", $_pText, "hwnd", $_hIcon, "int", $_nFlags, "int", $_insertID)
EndFunc   ;==>XMenu_InsertItemIcon

Func XMenu_SetAutoDestroy($_hMenu, $_bAuto)
	DllCall($_xcdll, "none", "XMenu_SetAutoDestroy", "hwnd", $_hMenu, "bool", $_bAuto)
EndFunc   ;==>XMenu_SetAutoDestroy

Func XMenu_EnableDrawBackground($_hMenu, $_bEnable)
	DllCall($_xcdll, "none", "XMenu_EnableDrawBackground", "hwnd", $_hMenu, "bool", $_bEnable)
EndFunc   ;==>XMenu_EnableDrawBackground

Func XMenu_EnableDrawItem($_hMenu, $_bEnable)
	DllCall($_xcdll, "none", "XMenu_EnableDrawItem", "hwnd", $_hMenu, "bool", $_bEnable)
EndFunc   ;==>XMenu_EnableDrawItem

Func XMenu_Popup($_hMenu, $_hParentWnd, $_x, $_y, $_hParentEle, $_nPosition)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_Popup", "hwnd", $_hMenu, "hwnd", $_hParentWnd, "int", $_x, "int", $_y, "hwnd", $_hParentEle, "int", $_nPosition)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_Popup

Func XMenu_DestroyMenu($_hMenu)
	DllCall($_xcdll, "none", "XMenu_DestroyMenu", "hwnd", $_hMenu)
EndFunc   ;==>XMenu_DestroyMenu

Func XMenu_CloseMenu($_hMenu)
	DllCall($_xcdll, "none", "XMenu_CloseMenu", "hwnd", $_hMenu)
EndFunc   ;==>XMenu_CloseMenu

Func XMenu_SetBkImage($_hMenu, $_hImage)
	DllCall($_xcdll, "none", "XMenu_SetBkImage", "hwnd", $_hMenu, "hwnd", $_hImage)
EndFunc   ;==>XMenu_SetBkImage

Func XMenu_SetItemText($_hMenu, $_nID, $_pText)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_SetItemText", "hwnd", $_hMenu, "int", $_nID, "wstr", $_pText)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_SetItemText

Func XMenu_GetItemText($_hMenu, $_nID, $_pOut, $_nOutLen)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_GetItemText", "hwnd", $_hMenu, "int", $_nID, "int", $_pOut, "wstr", $_nOutLen)
	Return $_XMenu
EndFunc   ;==>XMenu_GetItemText

Func XMenu_GetItemTextLength($_hMenu, $_nID)
	$_XMenu = DllCall($_xcdll, "int", "XMenu_GetItemTextLength", "hwnd", $_hMenu, "int", $_nID)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_GetItemTextLength

Func XMenu_SetItemIcon($_hMenu, $_nID, $_hIcon)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_SetItemIcon", "hwnd", $_hMenu, "int", $_nID, "hwnd", $_hIcon)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_SetItemIcon

Func XMenu_SetItemFlags($_hMenu, $_nID, $_uFlags)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_SetItemFlags", "hwnd", $_hMenu, "int", $_nID, "int", $_uFlags)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_SetItemFlags

Func XMenu_SetItemHeight($_hMenu, $_height)
	DllCall($_xcdll, "none", "XMenu_SetItemHeight", "hwnd", $_hMenu, "int", $_height)
EndFunc   ;==>XMenu_SetItemHeight

Func XMenu_GetItemHeight($_hMenu)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_GetItemHeight", "hwnd", $_hMenu)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_GetItemHeight

Func XMenu_SetBorderColor($_hMenu, $_crColor, $_alpha)
	DllCall($_xcdll, "none", "XMenu_SetBorderColor", "hwnd", $_hMenu, "int", $_crColor, "byte", $_alpha)
EndFunc   ;==>XMenu_SetBorderColor

Func XMenu_GetLeftWidth($_hMenu)
	$_XMenu = DllCall($_xcdll, "int", "XMenu_GetLeftWidth", "hwnd", $_hMenu)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_GetLeftWidth

Func XMenu_GetLeftSpaceText($_hMenu)
	$_XMenu = DllCall($_xcdll, "int", "XMenu_GetLeftSpaceText", "hwnd", $_hMenu)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_GetLeftSpaceText

Func XMenu_GetItemCount($_hMenu)
	$_XMenu = DllCall($_xcdll, "int", "XMenu_GetItemCount", "hwnd", $_hMenu)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_GetItemCount

Func XMenu_SetItemCheck($_hMenu, $_nID, $_bCheck)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_SetItemCheck", "hwnd", $_hMenu, "int", $_nID, "bool", $_bCheck)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_SetItemCheck

Func XMenu_IsItemCheck($_hMenu, $_nID)
	$_XMenu = DllCall($_xcdll, "bool", "XMenu_IsItemCheck", "hwnd", $_hMenu, "int", $_nID)
	Return $_XMenu[0]
EndFunc   ;==>XMenu_IsItemCheck
;=================Menu-弹出菜单结束=======================
;=================Button-按钮开始=======================
Func XBtn_Create($_x, $_y, $_width, $_height, $_pName, $_parent)
	$_XBtn = DllCall($_xcdll, "hwnd", "XBtn_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", $_pName, "hwnd", $_parent)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_Create

Func XBtn_IsCheck($_hEle)
	$_XBtn = DllCall($_xcdll, "bool", "XBtn_IsCheck", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_IsCheck

Func XBtn_SetCheck($_hEle, $_check)
	$_XBtn = DllCall($_xcdll, "bool", "XBtn_SetCheck", "hwnd", $_hEle, "bool", $_check)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_SetCheck

Func XBtn_SetStyle($_hEle, $_style)
	DllCall($_xcdll, "none", "XBtn_SetStyle", "hwnd", $_hEle, "int", $_style)
EndFunc   ;==>XBtn_SetStyle

Func XBtn_SetState($_hEle, $_state)
	DllCall($_xcdll, "none", "XBtn_SetState", "hwnd", $_hEle, "int", $_state)
EndFunc   ;==>XBtn_SetState

Func XBtn_GetState($_hEle)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetState", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_GetState

Func XBtn_GetStateEx($_hEle)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetStateEx", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_GetStateEx

Func XBtn_GetStyle($_hEle)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetStyle", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_GetStyle

Func XBtn_SetType($_hEle, $_type)
	DllCall($_xcdll, "none", "XBtn_SetType", "hwnd", $_hEle, "int", $_type)
EndFunc   ;==>XBtn_SetType

Func XBtn_GetType($_hEle)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetType", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_GetType

Func XBtn_SetGroupID($_hEle, $_id)
	DllCall($_xcdll, "none", "XBtn_SetGroupID", "hwnd", $_hEle, "int", $_id)
EndFunc   ;==>XBtn_SetGroupID

Func XBtn_GetGroupID($_hEle)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetGroupID", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_GetGroupID

Func XBtn_SetBindEle($_hEle, $_hBindEle)
	DllCall($_xcdll, "none", "XBtn_SetBindEle", "hwnd", $_hEle, "int", $_hBindEle)
EndFunc   ;==>XBtn_SetBindEle

Func XBtn_GetBindEle($_hEle)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetBindEle", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_GetBindEle

Func XBtn_SetTextAlign($_hEle, $_nFlags)
	DllCall($_xcdll, "none", "XBtn_SetTextAlign", "hwnd", $_hEle, "int", $_nFlags)
EndFunc   ;==>XBtn_SetTextAlign

Func XBtn_GetTextAlign($_hEle)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetTextAlign", "hwnd", $_hEle)
	Return $_XBtn[0]
EndFunc   ;==>XBtn_GetTextAlign

Func XBtn_SetIconAlign($_hEle, $_align)
	DllCall($_xcdll, "none", "XBtn_SetIconAlign", "hwnd", $_hEle, "int", $_align)
EndFunc   ;==>XBtn_SetIconAlign

Func XBtn_SetOffset($_hEle, $_x, $_y)
	DllCall($_xcdll, "none", "XBtn_SetOffset", "hwnd", $_hEle, "int", $_x, "int", $_y)
EndFunc   ;==>XBtn_SetOffset

Func XBtn_SetOffsetIcon($_hEle, $_x, $_y)
	DllCall($_xcdll, "none", "XBtn_SetOffsetIcon", "hwnd", $_hEle, "int", $_x, "int", $_y)
EndFunc   ;==>XBtn_SetOffsetIcon

Func XBtn_SetIconSpace($_hEle, $_size)
	DllCall($_xcdll, "none", "XBtn_SetIconSpace", "hwnd", $_hEle, "int", $_size)
EndFunc   ;==>XBtn_SetIconSpace

Func XBtn_GetText($_hEle, $_pOut, $_nOutLen)
	$_XBtn = DllCall($_xcdll, "int", "XBtn_GetText", "hwnd", $_hEle, "wstr", $_pOut, "int", $_nOutLen)
	Return $_XBtn[2]
EndFunc   ;==>XBtn_GetText

Func XBtn_SetText($_hEle, $_pName)
	DllCall($_xcdll, "none", "XBtn_SetText", "hwnd", $_hEle, "wstr", $_pName)
EndFunc   ;==>XBtn_SetText

Func XBtn_SetIcon($_hEle, $_hImage)
	DllCall($_xcdll, "none", "XBtn_SetIcon", "hwnd", $_hEle, "ptr", $_hImage)
EndFunc   ;==>XBtn_SetIcon

Func XBtn_SetIconDisable($_hEle, $_hImage)
	DllCall($_xcdll, "none", "XBtn_SetIconDisable", "hwnd", $_hEle, "ptr", $_hImage)
EndFunc   ;==>XBtn_SetIconDisable

Func XBtn_AddAnimationFrame($_hEle, $_hImage, $_uElapse)
	DllCall($_xcdll, "none", "XBtn_AddAnimationFrame", "hwnd", $_hEle, "ptr", $_hImage, "int", $_uElapse)
EndFunc   ;==>XBtn_AddAnimationFrame

Func XBtn_EnableAnimation($_hEle, $_bEnable, $_bLoopPlay)
	DllCall($_xcdll, "none", "XBtn_EnableAnimation", "hwnd", $_hEle, "bool", $_bEnable, "bool", $_bLoopPlay)
EndFunc   ;==>XBtn_EnableAnimation
;=================Button-按钮结束=======================

;=================ComboBox-下拉组合框开始=======================
Func XComboBox_Create($_x, $_y, $_width, $_height, $_parent)
	$_Xcb = DllCall($_xcdll, "hwnd", "XComboBox_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_parent)
	Return $_Xcb[0]
EndFunc   ;==>XComboBox_Create

Func XComboBox_SetSelItem($_hEle, $_iIndex)
	$_Xcb = DllCall($_xcdll, "bool", "XComboBox_SetSelItem", "hwnd", $_hEle, "bool", $_iIndex)
	Return $_Xcb[0]
EndFunc   ;==>XComboBox_SetSelItem

Func XComboBox_BindApapter($_hEle, $_hAdapter)
	DllCall($_xcdll, "none", "XComboBox_BindApapter", "hwnd", $_hEle, "bool", $_hAdapter)
EndFunc   ;==>XComboBox_BindApapter

Func XComboBox_GetApapter($_hEle)
	$_Xcb = DllCall($_xcdll, "int", "XComboBox_BindApapter", "hwnd", $_hEle)
	Return $_Xcb[0]
EndFunc   ;==>XComboBox_GetApapter

Func XComboBox_GetButtonRect($_hEle)
	$_Xcb = DllCall($_xcdll, "int", "XComboBox_GetButtonRect", "hwnd", $_hEle)
	Return $_Xcb[0]
EndFunc   ;==>XComboBox_GetButtonRect

Func XComboBox_SetButtonSize($_hEle, $_size)
	DllCall($_xcdll, "none", "XComboBox_SetButtonSize", "hwnd", $_hEle, "int", $_size)
EndFunc   ;==>XComboBox_SetButtonSize

Func XComboBox_SetDropHeight($_hEle, $_height)
	DllCall($_xcdll, "none", "XComboBox_SetDropHeight", "hwnd", $_hEle, "int", $_height)
EndFunc   ;==>XComboBox_SetDropHeight

Func XComboBox_GetDropHeight($_hEle)
	$_Xcb = DllCall($_xcdll, "int", "XComboBox_GetDropHeight", "hwnd", $_hEle)
	Return $_Xcb[0]
EndFunc   ;==>XComboBox_GetDropHeight

Func XComboBox_SetItemTemplateXML($_hEle, $_pXmlFile)
	DllCall($_xcdll, "none", "XComboBox_SetItemTemplateXML", "hwnd", $_hEle, "wstr", $_pXmlFile)
EndFunc   ;==>XComboBox_SetItemTemplateXML

Func XComboBox_SetItemTemplateXMLFromString($_hEle, $_pStringXML)
	DllCall($_xcdll, "none", "XComboBox_SetItemTemplateXMLFromString", "hwnd", $_hEle, "wstr", $_pStringXML)
EndFunc   ;==>XComboBox_SetItemTemplateXMLFromString

Func XComboBox_EnableDrawButton($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XComboBox_EnableDrawButton", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XComboBox_EnableDrawButton

Func XComboBox_EnableEdit($_hEle, $_bEdit)
	DllCall($_xcdll, "none", "XComboBox_EnableEdit", "hwnd", $_hEle, "bool", $_bEdit)
EndFunc   ;==>XComboBox_EnableEdit

Func XComboBox_AddBkBorder($_hEle, $_nState, $_color, $_alpha, $_width)
	DllCall($_xcdll, "none", "XComboBox_AddBkBorder", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha, "int", $_width)
EndFunc   ;==>XComboBox_AddBkBorder

Func XComboBox_AddBkFill($_hEle, $_nState, $_color, $_alpha)
	DllCall($_xcdll, "none", "XComboBox_AddBkFill", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XComboBox_AddBkFill

Func XComboBox_AddBkImage($_hEle, $_nState, $_hImage)
	DllCall($_xcdll, "none", "XComboBox_AddBkImage", "hwnd", $_hEle, "int", $_nState, "ptr", $_hImage)
EndFunc   ;==>XComboBox_AddBkImage

Func XComboboX_GetBkInfoCount($_hEle)
	$_Xcb = DllCall($_xcdll, "int", "XComboboX_GetBkInfoCount", "hwnd", $_hEle)
	Return $_Xcb[0]
EndFunc   ;==>XComboboX_GetBkInfoCount

Func XComboBox_ClearBkInfo($_hEle)
	DllCall($_xcdll, "int", "XComboBox_ClearBkInfo", "hwnd", $_hEle)
EndFunc   ;==>XComboBox_ClearBkInfo

Func XComboBox_GetSelItem($_hEle)
	$_Xcb = DllCall($_xcdll, "int", "XComboBox_GetSelItem", "hwnd", $_hEle)
	Return $_Xcb[0]
EndFunc   ;==>XComboBox_GetSelItem

Func XComboBox_GetState($_hEle)
	$_Xcb = DllCall($_xcdll, "int", "XComboBox_GetState", "hwnd", $_hEle)
	Return $_Xcb[0]
EndFunc   ;==>XComboBox_GetState
;=================ComboBox-下拉组合框结束=======================

;=================Element-基础元素开始=======================
Func XEle_Create($_x, $_y, $_width, $_height, $_parent)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_parent)
	Return $_XEle[0]
EndFunc   ;==>XEle_Create

Func XEle_RegEventC($_hWnd, $_fun, $_event = 34,$_parameter="int")
	$_ptr=DllCallbackGetPtr(DllCallbackRegister($_fun, "int", $_parameter))
	DllCall($_xcdll, "none", "XEle_RegEventC", "hwnd", $_hWnd, "int", $_event, "ptr", $_ptr)
	Return $_ptr
EndFunc   ;==>XEle_RegEventC

Func XEle_RegEventC1($_hEle, $_pFun, $_nEvent = 34,$_parameter="int")
	$_ptr=DllCallbackGetPtr(DllCallbackRegister($_pFun, "int", $_parameter))
	DllCall($_xcdll, "none", "XEle_RegEventC1", "hwnd", $_hEle, "int", $_nEvent, "ptr",$_ptr )
	Return $_ptr
EndFunc   ;==>XEle_RegEventC1

Func XEle_RegEventC2($_hEle, $_pFun, $_nEvent = 34,$_parameter="int")
	$_ptr=DllCallbackGetPtr(DllCallbackRegister($_pFun, "int", $_parameter))
	DllCall($_xcdll, "none", "XEle_RegEventC2", "hwnd", $_hEle, "int", $_nEvent, "ptr", $_ptr)
	Return $_ptr
EndFunc   ;==>XEle_RegEventC2

Func XEle_RemoveEventC($_hEle, $_nEvent, $_pFun)
	$_XEle = DllCall($_xcdll, "bool", "XEle_RemoveEventC", "hwnd", $_hEle, "int", $_nEvent, "ptr", $_pFun)
	Return $_XEle[0]
EndFunc   ;==>XEle_RemoveEventC

Func XEle_GetRect($_hEle)
	$_a = DllStructCreate("int x;int y")
	$_XEle = DllCall($_xcdll, "none", "XEle_GetRect", "hwnd", $_hEle, "ptr",DllStructGetPtr($_a))
	Local $_zuobiao[2]
	$_zuobiao[0] = DllStructGetData($_a,1)
	$_zuobiao[1] = DllStructGetData($_a,2)
	Return $_zuobiao
EndFunc

Func XEle_SendEvent($_hEle, $_hEventEle, $_nEvent, $_wParam, $_lParam)
	$_XEle = DllCall($_xcdll, "int", "XEle_SendEvent", "hwnd", $_hEle, "hwnd", $_hEventEle, "int", $_nEvent, "ptr", $_wParam, "ptr", $_lParam)
	Return $_XEle[0]
EndFunc   ;==>XEle_SendEvent

Func XEle_PostEvent($_hEle, $_hEventEle, $_nEvent, $_wParam, $_lParam)
	$_XEle = DllCall($_xcdll, "int", "XEle_PostEvent", "hwnd", $_hEle, "hwnd", $_hEventEle, "int", $_nEvent, "ptr", $_wParam, "ptr", $_lParam)
	Return $_XEle[0]
EndFunc   ;==>XEle_PostEvent

Func XEle_GetBkInfoManager($_hEle)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetBkInfoManager", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetWidth

Func XEle_GetWidth($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetWidth", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc

Func XEle_GetHeight($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetHeight", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetHeight

Func XEle_GetType($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetType", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetType

Func XEle_GetHWND($_hEle)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetHWND", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetHWND

Func XEle_GetHWINDOW($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetHWINDOW", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetHWINDOW

Func XEle_GetCursor($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetCursor", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetCursor

Func XEle_GetLayoutObject($_hEle)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetLayoutObject", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc

Func XEle_GetParentLayoutObject($_hEle)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetParentLayoutObject", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc

Func XEle_SetCursor($_hEle)
	DllCall($_xcdll, "int", "XEle_SetCursor", "hwnd", $_hEle)
EndFunc   ;==>XEle_SetCursor

Func XEle_AddEle($_hEle, $_hChildEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_AddEle", "hwnd", $_hEle, "hwnd", $_hChildEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_AddEle

Func XEle_SetUserData($_hEle, $_nData)
	DllCall($_xcdll, "none", "XEle_SetUserData", "hwnd", $_hEle, "int", $_nData)
EndFunc

Func XEle_PointClientToWndClient($_hEle, $_pPt)
	DllCall($_xcdll, "none", "XEle_SetUserData", "hwnd", $_hEle, "ptr*", $_pPt)
EndFunc

Func XEle_GetLayoutWidth($_hEle, $_pType,$_pWidth)
	DllCall($_xcdll, "none", "XEle_GetLayoutWidth", "hwnd", $_hEle, "int", $_pType,"int", $_pWidth)
EndFunc

Func XEle_GetLayoutHeight($_hEle, $_pType,$_pHeight)
	DllCall($_xcdll, "none", "XEle_GetLayoutHeight", "hwnd", $_hEle, "int", $_pType,"int", $_pHeight)
EndFunc

Func XEle_GetToolTip($_hEle, $_pOut,$_nOutLen)
	DllCall($_xcdll, "none", "XEle_GetToolTip", "hwnd", $_hEle, "int", $_pOut,"int", $_nOutLen)
EndFunc

Func XEle_GetContentSize($_hEle, $_pSize)
	DllCall($_xcdll, "none", "XEle_GetContentSize", "hwnd", $_hEle, "int", $_pSize)
EndFunc

Func XEle_GetUserData($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetUserData", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc

Func XEle_BindLayoutObject($_hEle, $_hLayout)
	DllCall($_xcdll, "none", "XEle_BindLayoutObject", "hwnd", $_hEle, "hwnd", $_hLayout)
EndFunc

Func XEle_SetCapture($_hEle, $_b)
	DllCall($_xcdll, "none", "XEle_SetCapture", "hwnd", $_hEle, "bool", $_b)
EndFunc

Func XEle_EnableTransparentChannel($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableTransparentChannel", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc

Func XEle_SetLayoutWidth($_hEle, $_nType,$_nWidth)
	DllCall($_xcdll, "none", "XEle_SetLayoutWidth", "hwnd", $_hEle, "int", $_nType,"int",$_nWidth)
EndFunc

Func XEle_EnableToolTip($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableToolTip", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc

Func XEle_SetToolTip($_hEle, $_pText)
	DllCall($_xcdll, "none", "XEle_SetToolTip", "hwnd", $_hEle, "wstr", $_pText)
EndFunc

Func XEle_SetLayoutHeight($_hEle, $_nType,$_nHeight)
	DllCall($_xcdll, "none", "XEle_SetLayoutHeight", "hwnd", $_hEle, "int", $_nType,"int",$_nHeight)
EndFunc

Func XEle_InsertEle($_hEle, $_hChildEle, $_index)
	$_XEle = DllCall($_xcdll, "bool", "XEle_InsertEle", "hwnd", $_hEle, "hwnd", $_hChildEle, "int", $_index)
	Return $_XEle[0]
EndFunc   ;==>XEle_InsertEle

Func XEle_ShowEle($_hEle, $_bShow)
	DllCall($_xcdll, "int", "XEle_ShowEle", "hwnd", $_hEle, "bool", $_bShow)
EndFunc   ;==>XEle_ShowEle

Func XEle_SetRect($_hEle, $_pRect, $_bRedraw)
	$_XEle = DllCall($_xcdll, "bool", "XEle_SetRect", "hwnd", $_hEle, "prt", $_pRect, "bool", $_bRedraw)
	Return $_XEle[0]
EndFunc   ;==>XEle_SetRect

Func XEle_SetRectEx($_hEle, $_x, $_y, $_width, $_height, $_bRedraw)
	$_XEle = DllCall($_xcdll, "bool", "XEle_SetRectEx", "hwnd", $_hEle, "int", $_x, "int", $_y, "int", $_width, "int", $_height, "bool", $_bRedraw)
	Return $_XEle[0]
EndFunc   ;==>XEle_SetRectEx

Func XEle_SetRectLogic($_hEle, $_pRect, $_bRedraw)
	$_XEle = DllCall($_xcdll, "bool", "XEle_SetRectLogic", "hwnd", $_hEle, "prt", $_pRect, "bool", $_bRedraw)
	Return $_XEle[0]
EndFunc   ;==>XEle_SetRectLogic

Func XEle_SetID($_hEle, $_id)
	DllCall($_xcdll, "none", "XEle_SetID", "hwnd", $_hEle, "int", $_id)
EndFunc   ;==>XEle_SetID

Func XEle_IsShow($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsShow", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsShow

Func XEle_IsDrawFocus($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsDrawFocus", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsDrawFocus

Func XEle_IsEnable($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsEnable", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsEnable

Func XEle_IsEnableFocus($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsEnableFocus", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsEnableFocus

Func XEle_IsMouseThrough($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsMouseThrough", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsMouseThrough

Func XEle_HitChildEle($_hEle, $_pPt)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_HitChildEle", "hwnd", $_hEle, "int*", $_pPt)
	Return $_XEle[0]
EndFunc   ;==>XEle_HitChildEle

Func XEle_IsBkTransparent($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsBkTransparent", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsBkTransparent

Func XEle_IsEnableEvent_XE_PAINT_END($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsEnableEvent_XE_PAINT_END", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsEnableEvent_XE_PAINT_END

Func XEle_IsKeyTab($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsKeyTab", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsKeyTab

Func XEle_IsSwitchFocus($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsSwitchFocus", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsSwitchFocus

Func XEle_IsEnable_XE_MOUSEWHEEL($_hEle)
	$_XEle = DllCall($_xcdll, "bool", "XEle_IsEnable_XE_MOUSEWHEEL", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_IsEnable_XE_MOUSEWHEEL

Func XEle_Enable($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_SetID", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_Enable

Func XEle_EnableFocus($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableFocus", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableFocus

Func XEle_EnableDrawFocus($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableDrawFocus", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableDrawFocus

Func XEle_EnableEvent_XE_PAINT_END($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableEvent_XE_PAINT_END", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableEvent_XE_PAINT_END

Func XEle_EnableBkTransparent($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableBkTransparent", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableBkTransparent

Func XEle_EnableMouseThrough($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableMouseThrough", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableMouseThrough

Func XEle_EnableKeyTab($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableKeyTab", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableKeyTab

Func XEle_EnableSwitchFocus($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_SetID", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableSwitchFocus

Func XEle_EnableEvent_XE_MOUSEWHEEL($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XEle_EnableEvent_XE_MOUSEWHEEL", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XEle_EnableEvent_XE_MOUSEWHEEL

Func XEle_GetParentEle($_hEle)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetParentEle", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetParentEle

Func XEle_GetParent($_hEle)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetParent", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetParent

Func XEle_RemoveEle($_hEle)
	DllCall($_xcdll, "none", "XEle_RemoveEle", "hwnd", $_hEle)
EndFunc   ;==>XEle_RemoveEle

Func XEle_AdjustLayoutObject($_hEle)
	DllCall($_xcdll, "none", "XEle_AdjustLayoutObject", "hwnd", $_hEle)
EndFunc 

Func XEle_AdjustLayout($_hEle)
	DllCall($_xcdll, "none", "XEle_AdjustLayout", "hwnd", $_hEle)
EndFunc 

Func XEle_AddShape($_hEle, $_hShape)
	$_XEle = DllCall($_xcdll, "bool", "XEle_AddShape", "hwnd", $_hEle, "ptr", $_hShape)
	Return $_XEle[0]
EndFunc   ;==>XEle_AddShape

Func XEle_SetZOrder($_hEle, $_index)
	$_XEle = DllCall($_xcdll, "bool", "XEle_SetZOrder", "hwnd", $_hEle, "int", $_index)
	Return $_XEle[0]
EndFunc   ;==>XEle_SetZOrder

Func XEle_GetZOrder($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetZOrder", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetZOrder

Func XEle_RedrawEle($_hEle, $_bImmediate)
	DllCall($_xcdll, "none", "XEle_RedrawEle", "hwnd", $_hEle, "bool", $_bImmediate)
EndFunc   ;==>XEle_RedrawEle

Func XEle_RedrawRect($_hEle, $_pRect, $_bImmediate)
	DllCall($_xcdll, "none", "XEle_RedrawRect", "hwnd", $_hEle, "int*", $_pRect, "bool", $_bImmediate)
EndFunc   ;==>XEle_RedrawRect

Func XEle_GetChildCount($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetChildCount", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetChildCount

Func XEle_GetChildByIndex($_hEle, $_index)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetChildByIndex", "hwnd", $_hEle, "int", $_index)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetChildByIndex

Func XEle_GetChildByID($_hEle, $_id)
	$_XEle = DllCall($_xcdll, "hwnd", "XEle_GetChildByID", "hwnd", $_hEle, "int", $_id)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetChildByID

Func XEle_GetChildShapeCount($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetChildShapeCount", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetChildShapeCount

Func XEle_GetChildShapeByIndex($_hEle, $_index)
	$_XEle = DllCall($_xcdll, "ptr", "XEle_GetChildShapeByIndex", "hwnd", $_hEle, "int", $_index)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetChildShapeByIndex

Func XEle_SetTextColor($_hEle, $_color, $_bImmediate)
	DllCall($_xcdll, "none", "XEle_SetTextColor", "hwnd", $_hEle, "int", $_color, "byte", $_bImmediate)
EndFunc   ;==>XEle_SetTextColor

Func XEle_GetTextColor($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetTextColor", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetTextColor

Func XEle_SetFocusBorderColor($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XEle_SetFocusBorderColor", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XEle_SetFocusBorderColor

Func XEle_GetFocusBorderColor($_hEle)
	$_XEle = DllCall($_xcdll, "int", "XEle_GetFocusBorderColor", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetFocusBorderColor

Func XEle_SetFont($_hEle, $_hFontx)
	DllCall($_xcdll, "none", "XEle_SetFont", "hwnd", $_hEle, "hwnd", $_hFontx)
EndFunc   ;==>XEle_SetFont

Func XEle_GetFont($_hEle)
	$_XEle = DllCall($_xcdll, "wstr", "XEle_GetFont", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetFont

Func XEle_SetAlpha($_hEle, $_alpha)
	DllCall($_xcdll, "none", "XEle_SetAlpha", "hwnd", $_hEle, "byte", $_alpha)
EndFunc   ;==>XEle_SetAlpha

Func XEle_Destroy($_hEle)
	DllCall($_xcdll, "none", "XEle_Destroy", "hwnd", $_hEle)
EndFunc   ;==>XEle_Destroy

Func XEle_AddBkBorder($_hEle, $_color, $_alpha, $_width)
	DllCall($_xcdll, "none", "XEle_AddBkBorder", "hwnd", $_hEle, "int", $_color, "byte", $_alpha, "int", $_width)
EndFunc   ;==>XEle_AddBkBorder

Func XEle_AddBkFill($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XEle_AddBkFill", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XEle_AddBkFill

Func XEle_AddBkImage($_hEle, $_hImage)
	DllCall($_xcdll, "none", "XEle_AddBkImage", "hwnd", $_hEle, "ptr", $_hImage)
EndFunc   ;==>XEle_AddBkImage

Func XEle_GetBkInfoCount($_hEle)
	$_XEle = DllCall($_xcdll, "wstr", "XEle_GetBkInfoCount", "hwnd", $_hEle)
	Return $_XEle[0]
EndFunc   ;==>XEle_GetBkInfoCount

Func XEle_ClearBkInfo($_hEle)
	DllCall($_xcdll, "none", "XEle_ClearBkInfo", "hwnd", $_hEle)
EndFunc   ;==>XEle_ClearBkInfo

Func XEle_GetStateFlags($_hEle)
	DllCall($_xcdll, "none", "XEle_GetStateFlags", "hwnd", $_hEle)
EndFunc   ;==>XEle_GetStateFlags

Func XEle_DrawFocus($_hEle, $_hDraw, $_pRect)
	$_XEle = DllCall($_xcdll, "bool", "XEle_DrawFocus", "hwnd", $_hEle, "int", $_hDraw, "int*", $_pRect)
	Return $_XEle[0]
EndFunc   ;==>XEle_DrawFocus

;=================Element-基础元素结束=======================

;=================ListBox-列表框开始=======================
Func XListBox_Create($_x, $_y, $_width, $_height, $_parent)
	$_Xlb = DllCall($_xcdll, "hwnd", "XListBox_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_parent)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_Create

Func XListBox_SetDrawItemBkFlags($_hEle, $_nFlags)
	DllCall($_xcdll, "none", "XListBox_SetDrawItemBkFlags", "hwnd", $_hEle, "int", $_nFlags)
EndFunc   ;==>XListBox_SetDrawItemBkFlags

Func XListBox_SetRowSpace($_hEle, $_nSpace)
	DllCall($_xcdll, "none", "XListBox_SetRowSpace", "hwnd", $_hEle, "int", $_nSpace)
EndFunc

Func XListBox_SetItemData($_hEle, $_iItem, $_nUserData)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_SetItemData", "hwnd", $_hEle, "int", $_iItem, "int", $_nUserData)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_SetItemData

Func XListBox_GetTemplateObject($_hEle, $_iItem, $_nTempItemID)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_GetTemplateObject", "hwnd", $_hEle, "int", $_iItem, "int", $_nTempItemID)
	Return $_Xlb[0]
EndFunc

Func XListBox_GetItemData($_hEle, $_iItem)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_GetItemData", "hwnd", $_hEle, "int", $_iItem)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_GetItemData

Func XListBox_GetRowSpace($_hEle)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_GetRowSpace", "hwnd", $_hEle)
	Return $_Xlb[0]
EndFunc 

Func XListBox_GetItemIndexFromHXCGUI($_hEle, $_hXCGUI)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_GetItemIndexFromHXCGUI", "hwnd", $_hEle, "hwnd", $_hXCGUI)
	Return $_Xlb[0]
EndFunc

Func XListBox_AddItemBkBorder($_hEle, $_nState, $_color, $_alpha, $_width)
	DllCall($_xcdll, "none", "XListBox_AddItemBkBorder", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha, "int", $_width)
EndFunc   ;==>XListBox_AddItemBkBorder

Func XListBox_AddItemBkFill($_hEle, $_nState, $_color, $_alpha)
	DllCall($_xcdll, "none", "XListBox_AddItemBkFill", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XListBox_AddItemBkFill

Func XListBox_AddItemBkImage($_hEle, $_nState, $_nimage)
	DllCall($_xcdll, "none", "XListBox_AddItemBkImage", "hwnd", $_hEle, "int", $_nState, "ptr", $_nimage)
EndFunc   ;==>XListBox_AddItemBkImage

Func XListBox_GetItemBkInfoCount($_hEle)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_GetItemBkInfoCount", "hwnd", $_hEle)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_GetItemBkInfoCount

Func XListBox_ClearItemBkInfo($_hEle)
	DllCall($_xcdll, "none", "XListBox_ClearItemBkInfo", "hwnd", $_hEle)
EndFunc   ;==>XListBox_ClearItemBkInfo

Func XListBox_SetItemInfo($_hEle, $_iItem, $_pItem)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_SetItemInfo", "hwnd", $_hEle, "int", $_iItem, "int*", $_pItem)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_SetItemInfo

Func XListBox_GetItemInfo($_hEle, $_iItem, $_pItem)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_GetItemInfo", "hwnd", $_hEle, "int", $_iItem, "int*", $_pItem)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_GetItemInfo

Func XListBox_SetSelectItem($_hEle, $_iItem)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_SetSelectItem", "hwnd", $_hEle, "int", $_iItem)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_SetSelectItem

Func XListBox_GetSelectItem($_hEle)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_GetSelectItem", "hwnd", $_hEle)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_GetSelectItem

Func XListBox_CancelSelectItem($_hEle, $_iItem)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_CancelSelectItem", "hwnd", $_hEle, "int", $_iItem)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_CancelSelectItem

Func XListBox_CancelSelectAll($_hEle)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_CancelSelectAll", "hwnd", $_hEle)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_CancelSelectAll

Func XListBox_GetSelectAll($_hEle, $_pArray, $_nArraySize)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_GetSelectAll", "hwnd", $_hEle, "int*", $_pArray, "int", $_nArraySize)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_GetSelectAll

Func XListBox_GetSelectCount($_hEle)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_GetSelectCount", "hwnd", $_hEle)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_GetSelectCount

Func XListBox_SelectAll($_hEle)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_SelectAll", "hwnd", $_hEle)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_SelectAll

Func XListBox_SetItemHeightDefault($_hEle, $_nHeight, $_nSelHeight)
	DllCall($_xcdll, "none", "XListBox_SetItemHeightDefault", "hwnd", $_hEle, "int", $_nHeight, "int", $_nSelHeight)
EndFunc   ;==>XListBox_SetItemHeightDefault

Func XListBox_GetItemHeightDefault($_hEle, $_pHeight, $_pSelHeight)
	DllCall($_xcdll, "none", "XListBox_GetItemHeightDefault", "hwnd", $_hEle, "int*", $_pHeight, "int*", $_pSelHeight)
EndFunc   ;==>XListBox_GetItemHeightDefault

Func XListBox_HitTest($_hEle, $_pPt)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_HitTest", "hwnd", $_hEle, "int*", $_pPt)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_HitTest

Func XListBox_HitTestOffset($_hEle, $_pPt)
	$_Xlb = DllCall($_xcdll, "int", "XListBox_HitTestOffset", "hwnd", $_hEle, "int*", $_pPt)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_HitTestOffset

Func XListBox_SetItemTemplateXML($_hEle, $_pXmlFile)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_SetItemTemplateXML", "hwnd", $_hEle, "wstr", $_pXmlFile)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_SetItemTemplateXML

Func XListBox_GetAdapter($_hEle)
	$_Xlb = DllCall($_xcdll, "hwnd", "XListBox_GetAdapter", "hwnd", $_hEle)
	Return $_Xlb[0]
EndFunc

Func XListBox_SetItemTemplateXMLFromString($_hEle, $_pStringXML)
	$_Xlb = DllCall($_xcdll, "bool", "XListBox_SetItemTemplateXMLFromString", "hwnd", $_hEle, "wstr", $_pStringXML)
	Return $_Xlb[0]
EndFunc   ;==>XListBox_SetItemTemplateXMLFromString

Func XListBox_EnableMultiSel($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XListBox_EnableMultiSel", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XListBox_EnableMultiSel

Func XListBox_BindAdapter($_hEle, $_hAdapter)
	DllCall($_xcdll, "none", "XListBox_BindAdapter", "hwnd", $_hEle, "int", $_hAdapter)
EndFunc   ;==>XListBox_BindAdapter

Func XListBox_RefreshData($_hEle)
	DllCall($_xcdll, "none", "XListBox_RefreshData", "hwnd", $_hEle)
EndFunc   ;==>XListBox_RefreshData
;=================ListBox-列表框结束=======================

;=================list-列表开始=======================
Func XList_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XList = DllCall($_xcdll, "hwnd", "XList_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XList[0]
EndFunc   ;==>XList_Create

Func XList_AddColumn($_hEle, $_width)
	$_XList = DllCall($_xcdll, "int", "XList_AddColumn", "hwnd", $_hEle, "int", $_width)
	Return $_XList[0]
EndFunc   ;==>XList_AddColumn

Func XList_InsertColumn($_hEle, $_width, $_iItem)
	$_XList = DllCall($_xcdll, "int", "XList_InsertColumn", "hwnd", $_hEle, "int", $_width, "int", $_iItem)
	Return $_XList[0]
EndFunc   ;==>XList_InsertColumn

Func XList_GetRowSpace($_hEle)
	$_XList = DllCall($_xcdll, "int", "XList_GetRowSpace", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc

Func XList_EnableMultiSel($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XList_EnableMultiSel", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XList_EnableMultiSel

Func XList_SetRowSpace($_hEle, $_nSpace)
	DllCall($_xcdll, "none", "XList_SetRowSpace", "hwnd", $_hEle, "int", $_nSpace)
EndFunc

Func XList_EnableDragChangeColumnWidth($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XList_EnableDragChangeColumnWidth", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XList_EnableDragChangeColumnWidth

Func XList_SetDrawItemBkFlags($_hEle, $_nFlags)
	DllCall($_xcdll, "none", "XList_SetDrawItemBkFlags", "hwnd", $_hEle, "int", $_nFlags)
EndFunc   ;==>XList_SetDrawItemBkFlags

Func XList_SetColumnWidth($_hEle,$_iItem, $_width)
	DllCall($_xcdll, "none", "XList_SetColumnWidth", "hwnd", $_hEle,"int",$_iItem, "int", $_width)
EndFunc   ;==>XList_SetColumnWidth

Func XList_SetColumnMinWidth($_hEle,$_iItem, $_width)
	DllCall($_xcdll, "none", "XList_SetColumnMinWidth", "hwnd", $_hEle,"int",$_iItem, "int", $_width)
EndFunc   ;==>XList_SetColumnMinWidth

Func XList_SetColumnWidthFixed($_hEle, $_iColumn,$_bFixed)
	DllCall($_xcdll, "none", "XList_SetColumnWidthFixed", "hwnd", $_hEle,"int",$_iColumn, "bool", $_bFixed)
EndFunc   ;==>XList_SetColumnWidthFixed

Func XList_GetColumnWidth($_hEle, $_iColumn)
	$_XList = DllCall($_xcdll, "int", "XList_GetColumnWidth", "hwnd", $_hEle, "int", $_iColumn)
	Return $_XList[0]
EndFunc   ;==>XList_GetColumnWidth

Func XList_GetColumnCount($_hEle)
	$_XList = DllCall($_xcdll, "int", "XList_GetColumnCount", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc   ;==>XList_GetColumnCount

Func XList_SetItemData($_hEle, $_iItem, $_iSubItem, $_data)
	$_XList = DllCall($_xcdll, "bool", "XList_SetItemData", "hwnd", $_hEle, "int", $_iItem, "int", $_iSubItem, "int", $_data)
	Return $_XList[0]
EndFunc   ;==>XList_SetItemData

Func XList_GetItemData($_hEle, $_iItem, $_iSubItem)
	$_XList = DllCall($_xcdll, "int", "XList_GetItemData", "hwnd", $_hEle, "int", $_iItem, "int", $_iSubItem)
	Return $_XList[0]
EndFunc   ;==>XList_GetItemData

Func XList_SetSelectItem($_hEle, $_iItem, $_bSelect)
	$_XList = DllCall($_xcdll, "bool", "XList_SetSelectItem", "hwnd", $_hEle, "int", $_iItem, "bool", $_bSelect)
	Return $_XList[0]
EndFunc   ;==>XList_SetSelectItem

Func XList_GetSelectItem($_hEle)
	$_XList = DllCall($_xcdll, "int", "XList_GetSelectItem", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc   ;==>XList_GetSelectItem

Func XList_GetSelectItemCount($_hEle)
	$_XList = DllCall($_xcdll, "int", "XList_GetSelectItemCount", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc   ;==>XList_GetSelectItemCount

Func XList_SetSelectAll($_hEle)
	DllCall($_xcdll, "none", "XList_SetSelectAll", "hwnd", $_hEle)
EndFunc   ;==>XList_SetSelectAll

Func XList_GetSelectAll($_hEle, $_pArray, $_nArraySize)
	$_XList = DllCall($_xcdll, "int", "XList_GetSelectAll", "hwnd", $_hEle, "int*", $_pArray, "int", $_nArraySize)
	Return $_XList[0]
EndFunc   ;==>XList_GetSelectAll

Func XList_CancelSelectItem($_hEle, $_iItem)
	$_XList = DllCall($_xcdll, "bool", "XList_CancelSelectItem", "hwnd", $_hEle, "int", $_iItem)
	Return $_XList[0]
EndFunc   ;==>XList_CancelSelectItem

Func XList_CancelSelectAll($_hEle)
	DllCall($_xcdll, "none", "XList_CancelSelectAll", "hwnd", $_hEle)
EndFunc   ;==>XList_CancelSelectAll

Func XList_GetHeaderHELE($_hEle)
	$_XList = DllCall($_xcdll, "hwnd", "XList_GetHeaderHELE", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc   ;==>XList_GetHeaderHELE

Func XList_DeleteColumn($_hEle, $_iItem)
	$_XList = DllCall($_xcdll, "bool", "XList_DeleteColumn", "hwnd", $_hEle, "int", $_iItem)
	Return $_XList[0]
EndFunc   ;==>XList_DeleteColumn

Func XList_DeleteColumnAll($_hEle)
	DllCall($_xcdll, "none", "XList_DeleteColumnAll", "hwnd", $_hEle)
EndFunc   ;==>XList_DeleteColumnAll

Func XList_SetItemTemplateXML($_hEle, $_pXmlFile)
	$_XList = DllCall($_xcdll, "bool", "XList_SetItemTemplateXML", "hwnd", $_hEle, "wstr", $_pXmlFile)
	Return $_XList[0]
EndFunc   ;==>XList_SetItemTemplateXML

Func XList_SetItemTemplateXMLFromString($_hEle, $_pStringXML)
	$_XList = DllCall($_xcdll, "bool", "XList_SetItemTemplateXMLFromString", "hwnd", $_hEle, "str", $_pStringXML)
	Return $_XList[0]
EndFunc   ;==>XList_SetItemTemplateXMLFromString

Func XList_GetItemIndexFromHXCGUI($_hEle, $_hXCGUI)
	$_XList = DllCall($_xcdll, "int", "XList_GetItemIndexFromHXCGUI", "hwnd", $_hEle, "hwnd", $_hXCGUI)
	Return $_XList[0]
EndFunc 

Func XList_GetHeaderItemIndexFromHXCGUI($_hEle, $_hXCGUI)
	$_XList = DllCall($_xcdll, "int", "XList_GetHeaderItemIndexFromHXCGUI", "hwnd", $_hEle, "hwnd", $_hXCGUI)
	Return $_XList[0]
EndFunc 

Func XList_GetTemplateObject($_hEle, $_iItem, $_nTempItemID)
	$_XList = DllCall($_xcdll, "hwnd", "XList_GetTemplateObject", "hwnd", $_hEle, "int", $_iItem, "int", $_nTempItemID)
	Return $_XList[0]
EndFunc   ;==>XList_GetTemplateObject

Func XList_GetHeaderTemplateObject($_hEle, $_iItem, $_nTempItemID)
	$_XList = DllCall($_xcdll, "hwnd", "XList_GetHeaderTemplateObject", "hwnd", $_hEle, "int", $_iItem, "int", $_nTempItemID)
	Return $_XList[0]
EndFunc   ;==>XList_GetHeaderTemplateObject

Func XList_HitTest($_hEle, $_pPt, $_piItem,$_piSubItem)
	$_XList = DllCall($_xcdll, "bool", "XList_HitTest", "hwnd", $_hEle, "ptr*", $_pPt, "int*", $_piItem,"int*",$_piSubItem)
	Return $_XList[0]
EndFunc

Func XList_HitTestOffset($_hEle, $_pPt, $_piItem,$_piSubItem)
	$_XList = DllCall($_xcdll, "bool", "XList_HitTestOffset", "hwnd", $_hEle, "int", $_pPt, "int", $_piItem,"int",$_piSubItem)
	Return $_XList[0]
EndFunc

Func XList_SetHeaderHeight($_hEle, $_height)
	DllCall($_xcdll, "none", "XList_SetHeaderHeight", "hwnd", $_hEle, "int", $_height)
EndFunc   ;==>XList_SetHeaderHeight

Func XList_GetHeaderHeight($_hEle)
	$_XList = DllCall($_xcdll, "int", "XList_GetHeaderHeight", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc   ;==>XList_GetHeaderHeight

Func XList_AddItemBkBorder($_hEle, $_nState, $_color, $_alpha, $_width)
	DllCall($_xcdll, "none", "XList_AddItemBkBorder", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha, "int", $_width)
EndFunc   ;==>XList_AddItemBkBorder

Func XList_AddItemBkFill($_hEle, $_nState, $_color, $_alpha)
	DllCall($_xcdll, "none", "XList_AddItemBkFill", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XList_AddItemBkFill

Func XList_AddItemBkImage($_hEle, $_nState, $_hImage)
	DllCall($_xcdll, "none", "XList_AddItemBkImage", "hwnd", $_hEle, "int", $_nState, "ptr", $_hImage)
EndFunc   ;==>XList_AddItemBkImage

Func XList_GetItemHeightDefault($_hEle, $_pHeight, $_pSelHeight)
	DllCall($_xcdll, "none", "XList_GetItemHeightDefault", "hwnd", $_hEle, "int", $_pHeight, "int", $_pSelHeight)
EndFunc

Func XList_GetItemBkInfoCount($_hEle)
	$_XList = DllCall($_xcdll, "int", "XList_GetItemBkInfoCount", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc   ;==>XList_GetItemBkInfoCount

Func XList_GetAdapter($_hEle)
	$_XList = DllCall($_xcdll, "hwnd", "XList_GetAdapter", "hwnd", $_hEle)
	Return $_XList[0]
EndFunc

Func XList_ClearItemBkInfo($_hEle)
	DllCall($_xcdll, "none", "XList_ClearItemBkInfo", "hwnd", $_hEle)
EndFunc   ;==>XList_ClearItemBkInfo

Func XList_SetItemHeightDefault($_hEle, $_nHeight, $_nSelHeight)
	DllCall($_xcdll, "none", "XList_SetItemHeightDefault", "hwnd", $_hEle, "int", $_nHeight, "int", $_nSelHeight)
EndFunc   ;==>XList_SetItemHeightDefault

Func XList_RefreshData($_hEle)
	DllCall($_xcdll, "none", "XList_RefreshData", "hwnd", $_hEle)
EndFunc   ;==>XList_RefreshData

Func XList_BindAdapterHeader($_hEle, $_hAdapter)
	DllCall($_xcdll, "none", "XList_BindAdapterHeader", "hwnd", $_hEle, "int", $_hAdapter)
EndFunc   ;==>XList_BindAdapterHeader

Func XList_BindAdapter($_hEle, $_hAdapter)
	DllCall($_xcdll, "none", "XList_BindAdapter", "hwnd", $_hEle, "int", $_hAdapter)
EndFunc   ;==>XList_BindAdapter
;=================list-列表结束=======================

;=================ListView-列表视图开始=======================
Func XListView_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XLv = DllCall($_xcdll, "hwnd", "XListView_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XLv[0]
EndFunc   ;==>XListView_Create

Func XListView_SetItemTemplateXML($_hEle, $_pXmlFile)
	$_XLv = DllCall($_xcdll, "bool", "XListView_SetItemTemplateXML", "hwnd", $_hEle, "wstr*", $_pXmlFile)
	Return $_XLv[0]
EndFunc   ;==>XListView_SetItemTemplateXML

Func XListView_SetItemTemplateXMLFromString($_hEle, $_pStringXML)
	$_XLv = DllCall($_xcdll, "bool", "XListView_SetItemTemplateXMLFromString", "hwnd", $_hEle, "str*", $_pStringXML)
	Return $_XLv[0]
EndFunc   ;==>XListView_SetItemTemplateXMLFromString

Func XListView_GetTemplateObject($_hEle, $_iGroup, $_iItem, $_nTempItemID)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetTemplateObject", "hwnd", $_hEle, "int", $_iGroup, "int", $_iItem, "int", $_nTempItemID)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetTemplateObject

Func XListView_GetTemplateObjectGroup($_hEle, $_iGroup, $_nTempItemID)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetTemplateObjectGroup", "hwnd", $_hEle, "int", $_iGroup, "int", $_nTempItemID)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetTemplateObjectGroup

Func XListView_GetItemIDFromHXCGUI($_hEle, $_hXCGUI, $_piGroup, $_piItem)
	$_XLv = DllCall($_xcdll, "bool", "XListView_GetItemIDFromHXCGUI", "hwnd", $_hEle, "int", $_hXCGUI, "int*", $_piGroup, "int*", $_piItem)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetItemIDFromHXCGUI

Func XListView_HitTest($_hEle, $_pPt, $_pOutGroup, $_pOutItem)
	$_XLv = DllCall($_xcdll, "bool", "XListView_HitTest", "hwnd", $_hEle, "ptr*", $_pPt, "int*", $_pOutGroup, "int*", $_pOutItem)
	Return $_XLv[0]
EndFunc   ;==>XListView_HitTest

Func XListView_HitTestOffset($_hEle, $_pPt, $_pOutGroup, $_pOutItem)
	$_XLv = DllCall($_xcdll, "bool", "XListView_HitTestOffset", "hwnd", $_hEle, "ptr*", $_pPt, "int*", $_pOutGroup, "int*", $_pOutItem)
	Return $_XLv[0]
EndFunc

Func XListView_EnableMultiSel($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XListView_EnableMultiSel", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XListView_EnableMultiSel

Func XListView_SetDrawItemBkFlags($_hEle, $_nFlags)
	DllCall($_xcdll, "none", "XListView_SetDrawItemBkFlags", "hwnd", $_hEle, "int", $_nFlags)
EndFunc   ;==>XListView_SetDrawItemBkFlags

Func XListView_SetSelectItem($_hEle, $_iGroup, $_iItem)
	$_XLv = DllCall($_xcdll, "bool", "XListView_SetSelectItem", "hwnd", $_hEle, "int", $_iGroup, "int", $_iItem)
	Return $_XLv[0]
EndFunc   ;==>XListView_SetSelectItem

Func XListView_GetSelectItem($_hEle, $_piGroup=0, $_piItem=0)
	$_XLv = DllCall($_xcdll, "bool", "XListView_GetSelectItem", "hwnd", $_hEle, "int*", $_piGroup, "int*", $_piItem)
	Return $_XLv
EndFunc   ;==>XListView_GetSelectItem

Func XListView_GetSelectItemCount($_hEle)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetSelectItemCount", "hwnd", $_hEle)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetSelectItemCount

Func XListView_GetSelectItemAll($_hEle, $_pArray, $_nArraySize)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetSelectItemAll", "hwnd", $_hEle, "int*", $_pArray, "int", $_nArraySize)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetSelectItemAll

Func XListView_SetSelectItemAll($_hEle)
	DllCall($_xcdll, "none", "XListView_SetSelectItemAll", "hwnd", $_hEle)
EndFunc   ;==>XListView_SetSelectItemAll

Func XListView_CancelSelectItemAll($_hEle)
	DllCall($_xcdll, "none", "XListView_CancelSelectItemAll", "hwnd", $_hEle)
EndFunc   ;==>XListView_CancelSelectItemAll

Func XListView_SetColumnSpace($_hEle, $_space)
	DllCall($_xcdll, "none", "XListView_SetColumnSpace", "hwnd", $_hEle, "int", $_space)
EndFunc   ;==>XListView_SetColumnSpace

Func XListView_GetItemSize($_hEle, $_pSize)
	DllCall($_xcdll, "none", "XListView_GetItemSize", "hwnd", $_hEle, "int", $_pSize)
EndFunc

Func XListView_SetRowSpace($_hEle, $_space)
	DllCall($_xcdll, "none", "XListView_SetRowSpace", "hwnd", $_hEle, "int", $_space)
EndFunc   ;==>XListView_SetRowSpace

Func XListView_SetAlignSizeLeft($_hEle, $_size)
	DllCall($_xcdll, "none", "XListView_SetAlignSizeLeft", "hwnd", $_hEle, "int", $_size)
EndFunc   ;==>XListView_SetAlignSizeLeft

Func XListView_SetAlignSizeTop($_hEle, $_size)
	DllCall($_xcdll, "none", "XListView_SetAlignSizeTop", "hwnd", $_hEle, "int", $_size)
EndFunc   ;==>XListView_SetAlignSizeTop

Func XListView_SetItemSize($_hEle, $_height)
	DllCall($_xcdll, "none", "XListView_SetItemSize", "hwnd", $_hEle, "int", $_height)
EndFunc   ;==>XListView_SetItemSize

Func XListView_SetGroupHeight($_hEle, $_height)
	DllCall($_xcdll, "none", "XListView_SetGroupHeight", "hwnd", $_hEle, "int", $_height)
EndFunc   ;==>XListView_SetGroupHeight

Func XXListView_GetGroupHeight($_hEle)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetGroupHeight", "hwnd", $_hEle)
	Return $_XLv[0]
EndFunc   ;==>XXListView_GetGroupHeight

Func XListView_SetGroupUserData($_hEle, $_iGroup, $_nData)
	DllCall($_xcdll, "none", "XListView_SetGroupUserData", "hwnd", $_hEle, "int", $_iGroup, "int", $_nData)
EndFunc   ;==>XListView_SetGroupUserData

Func XListView_SetItemUserData($_hEle, $_iGroup, $_iItem, $_nData)
	DllCall($_xcdll, "none", "XListView_SetItemUserData", "hwnd", $_hEle, "int", $_iGroup, "int", $_iItem, "int", $_nData)
EndFunc   ;==>XListView_SetItemUserData

Func XListView_GetGroupUserData($_hEle, $_iGroup)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetGroupUserData", "hwnd", $_hEle, "int", $_iGroup)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetGroupUserData

Func XListView_GetItemUserData($_hEle, $_iGroup, $_iItem)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetItemUserData", "hwnd", $_hEle, "int", $_iGroup, "int", $_iItem)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetItemUserData

Func XListView_AddItemBkBorder($_hEle, $_nState, $_color, $_alpha, $_width)
	DllCall($_xcdll, "none", "XListView_AddItemBkBorder", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha, "int", $_width)
EndFunc   ;==>XListView_AddItemBkBorder

Func XListView_AddItemBkFill($_hEle, $_nState, $_color, $_alpha)
	DllCall($_xcdll, "none", "XListView_AddItemBkFill", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XListView_AddItemBkFill

Func XListView_AddItemBkImage($_hEle, $_nState, $_hImage)
	DllCall($_xcdll, "none", "XListView_AddItemBkImage", "hwnd", $_hEle, "int", $_nState, "ptr", $_hImage)
EndFunc   ;==>XListView_AddItemBkImage

Func XListView_GetItemBkInfoCount($_hEle)
	$_XLv = DllCall($_xcdll, "int", "XListView_GetItemBkInfoCount", "hwnd", $_hEle)
	Return $_XLv[0]
EndFunc   ;==>XListView_GetItemBkInfoCount

Func XListView_GetAdapter($_hEle)
	$_XLv = DllCall($_xcdll, "hwnd", "XListView_GetAdapter", "hwnd", $_hEle)
	Return $_XLv[0]
EndFunc

Func XListView_ClearItemBkInfo($_hEle)
	DllCall($_xcdll, "none", "XListView_ClearItemBkInfo", "hwnd", $_hEle)
EndFunc   ;==>XListView_ClearItemBkInfo

Func XListView_RefreshData($_hEle)
	DllCall($_xcdll, "none", "XListView_RefreshData", "hwnd", $_hEle)
EndFunc   ;==>XListView_RefreshData

Func XListView_ExpandGroup($_hEle, $_iGroup, $_bExpand)
	$_XLv = DllCall($_xcdll, "bool", "XListView_ExpandGroup", "hwnd", $_hEle, "int", $_iGroup, "bool", $_bExpand)
	Return $_XLv[0]
EndFunc   ;==>XListView_ExpandGroup

Func XListView_BindAdapter($_hEle, $_hAdapter)
	DllCall($_xcdll, "none", "XListView_BindAdapter", "hwnd", $_hEle, "int", $_hAdapter)
EndFunc   ;==>XListView_BindAdapter

;=================ListView-列表视图结束=======================

;=================MenuBar-菜单条开始=======================
Func XMenuBar_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XMenuBar = DllCall($_xcdll, "hwnd", "XMenuBar_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XMenuBar[0]
EndFunc   ;==>XMenuBar_Create

Func XMenuBar_AddButton($_hEle, $_pText)
	$_XMenuBar = DllCall($_xcdll, "int", "XMenuBar_AddButton", "hwnd", $_hEle, "wstr*", $_pText)
	Return $_XMenuBar[0]
EndFunc   ;==>XMenuBar_AddButton

Func XMenuBar_SetButtonHeight($_hEle, $_height)
	DllCall($_xcdll, "none", "XMenuBar_SetButtonHeight", "hwnd", $_hEle, "int", $_height)
EndFunc   ;==>XMenuBar_SetButtonHeight

Func XMenuBar_GetMenu($_hEle, $_nIndex)
	$_XMenuBar = DllCall($_xcdll, "hwnd", "XMenuBar_GetMenu", "hwnd", $_hEle, "int", $_nIndex)
	Return $_XMenuBar[0]
EndFunc   ;==>XMenuBar_GetMenu

Func XMenuBar_DeleteButton($_hEle, $_nIndex)
	$_XMenuBar = DllCall($_xcdll, "bool", "XMenuBar_DeleteButton", "hwnd", $_hEle, "int", $_nIndex)
	Return $_XMenuBar[0]
EndFunc   ;==>XMenuBar_DeleteButton
;=================MenuBar-菜单条结束=======================

;=================pane - Pane元素开始=======================
Func XPane_Create($_pName, $_width, $_height, $_hFrameWnd)
	$_XPane = DllCall($_xcdll, "hwnd", "XMenuBar_Create", "wstr*", $_pName, "int", $_width, "int", $_height, "hwnd", $_hFrameWnd)
	Return $_XPane[0]
EndFunc   ;==>XPane_Create

Func XPane_SetView($_hEle, $_hView)
	DllCall($_xcdll, "none", "XPane_SetView", "hwnd", $_hEle, "int", $_hView)
EndFunc   ;==>XPane_SetView

Func XPane_SetTitle($_hEle, $_pTitle)
	DllCall($_xcdll, "none", "XPane_SetTitle", "hwnd", $_hEle, "wstr*", $_pTitle)
EndFunc   ;==>XPane_SetTitle

Func XPane_GetTitle($_hEle, $_pOut, $_nOutLen)
	DllCall($_xcdll, "none", "XPane_GetTitle", "hwnd", $_hEle, "wstr*", $_pOut, "int", $_nOutLen)
EndFunc   ;==>XPane_GetTitle

Func XPane_SetCaptionHeight($_hEle, $_nHeight)
	DllCall($_xcdll, "none", "XPane_SetCaptionHeight", "hwnd", $_hEle, "int", $_nHeight)
EndFunc   ;==>XPane_SetCaptionHeight

Func XPane_GetCaptionHeight($_pName)
	$_XPane = DllCall($_xcdll, "int", "XPane_GetCaptionHeight", "hwnd", $_pName)
	Return $_XPane[0]
EndFunc   ;==>XPane_GetCaptionHeight

Func XPane_IsShowPane($_pName)
	$_XPane = DllCall($_xcdll, "bool", "XPane_IsShowPane", "hwnd", $_pName)
	Return $_XPane[0]
EndFunc   ;==>XPane_IsShowPane

Func XPane_HidePane($_hEle)
	DllCall($_xcdll, "none", "XPane_HidePane", "hwnd", $_hEle)
EndFunc   ;==>XPane_HidePane

Func XPane_ShowPane($_hEle)
	DllCall($_xcdll, "none", "XPane_ShowPane", "hwnd", $_hEle)
EndFunc   ;==>XPane_ShowPane

Func XPane_DockPane($_hEle)
	DllCall($_xcdll, "none", "XPane_DockPane", "hwnd", $_hEle)
EndFunc   ;==>XPane_DockPane

Func XPane_LockPane($_hEle)
	DllCall($_xcdll, "none", "XPane_LockPane", "hwnd", $_hEle)
EndFunc   ;==>XPane_LockPane

Func XPane_FloatPane($_hEle)
	DllCall($_xcdll, "none", "XPane_FloatPane", "hwnd", $_hEle)
EndFunc   ;==>XPane_FloatPane
;=================pane - Pane元素结束=======================

;=================ProgressBar-进度条开始=======================
Func XProgBar_Create($_x, $_y, $_width, $_height, $_hFrameWnd)
	$_XProgBar = DllCall($_xcdll, "hwnd", "XProgBar_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hFrameWnd)
	Return $_XProgBar[0]
EndFunc   ;==>XProgBar_Create

Func XProgBar_SetRange($_hEle, $_range)
	DllCall($_xcdll, "none", "XProgBar_SetRange", "hwnd", $_hEle, "int", $_range)
EndFunc   ;==>XProgBar_SetRange

Func XProgBar_GetRange($_pName)
	$_XProgBar = DllCall($_xcdll, "int", "XProgBar_GetRange", "hwnd", $_pName)
	Return $_XProgBar[0]
EndFunc   ;==>XProgBar_GetRange

Func XProgBar_SetImageLoad($_hEle, $_hImage)
	DllCall($_xcdll, "none", "XProgBar_SetImageLoad", "hwnd", $_hEle, "ptr", $_hImage)
EndFunc   ;==>XProgBar_SetImageLoad

Func XProgBar_SetSpaceTwo($_hEle, $_leftSize, $_rightSize)
	DllCall($_xcdll, "none", "XProgBar_SetSpaceTwo", "hwnd", $_hEle, "int", $_leftSize, "int", $_rightSize)
EndFunc   ;==>XProgBar_SetSpaceTwo

Func XProgBar_SetPos($_hEle, $_pos)
	DllCall($_xcdll, "none", "XProgBar_SetPos", "hwnd", $_hEle, "int", $_pos)
EndFunc   ;==>XProgBar_SetPos

Func XProgBar_GetPos($_pName)
	$_XProgBar = DllCall($_xcdll, "int", "XProgBar_GetPos", "hwnd", $_pName)
	Return $_XProgBar[0]
EndFunc   ;==>XProgBar_GetPos

Func XProgBar_SetHorizon($_hEle, $_bHorizon)
	DllCall($_xcdll, "none", "XProgBar_SetHorizon", "hwnd", $_hEle, "bool", $_bHorizon)
EndFunc   ;==>XProgBar_SetHorizon
;=================ProgressBar-进度条结束=======================
;=================RichEdit-富文本编辑框开始=======================
Func XRichEdit_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XRichEdit = DllCall($_xcdll, "hwnd", "XRichEdit_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_Create

Func XRichEdit_InsertString($_hEle, $_pString, $_pFont, $_color)
	DllCall($_xcdll, "none", "XRichEdit_InsertString", "hwnd", $_hEle, "wstr", $_pString, "hwnd", $_pFont, "int", $_color)
EndFunc   ;==>XRichEdit_InsertString

Func XRichEdit_SetDefaultTextColor($_hEle,$_color,$_alpha)
	DllCall($_xcdll, "none", "XRichEdit_SetDefaultTextColor", "hwnd", $_hEle, "int", $_color,"byte",$_alpha)
EndFunc 

Func XRichEdit_InsertImage($_hEle, $_hImage, $_pImagePath)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_InsertImage", "hwnd", $_hEle, "ptr", $_hImage, "wstr", $_pImagePath)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_InsertImage

Func XRichEdit_InsertGif($_hEle, $_hImage, $_pImagePath)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_InsertGif", "hwnd", $_hEle, "ptr", $_hImage, "wstr", $_pImagePath)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_InsertGif

Func XRichEdit_InsertStringEx($_hEle, $_iRow, $_iColumn, $_pString, $_pFont, $_color)
	DllCall($_xcdll, "none", "XRichEdit_InsertStringEx", "hwnd", $_hEle, "int", $_iRow, "int", $_iColumn, "wstr", $_pString, "hwnd", $_pFont, "int", $_color)
EndFunc   ;==>XRichEdit_InsertStringEx

Func XRichEdit_InsertImageEx($_hEle, $_iRow, $_iColumn, $_hImage, $_pImagePath)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_InsertImageEx", "hwnd", $_hEle, "int", $_iRow, "int", $_iColumn, "ptr", $_hImage, "wstr", $_pImagePath)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_InsertImageEx

Func XRichEdit_InsertGifEx($_hEle, $_iRow, $_iColumn, $_hImage, $_pImagePath)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_InsertGifEx", "hwnd", $_hEle, "int", $_iRow, "int", $_iColumn, "ptr", $_hImage, "wstr", $_pImagePath)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_InsertGifEx

Func XRichEdit_SetText($_hEle, $_pString)
	DllCall($_xcdll, "none", "XRichEdit_SetText", "hwnd", $_hEle, "wstr", $_pString)
EndFunc   ;==>XRichEdit_SetText

Func XRichEdit_SetLimitNum($_hEle, $_nNumber)
	DllCall($_xcdll, "none", "XRichEdit_SetLimitNum", "hwnd", $_hEle, "int", $_nNumber)
EndFunc

Func XRichEdit_SetDefaultText($_hEle, $_pString)
	DllCall($_xcdll, "none", "XRichEdit_SetDefaultText", "hwnd", $_hEle, "wstr", $_pString)
EndFunc

Func XRichEdit_SetTextInt($_hEle, $_nVaule)
	DllCall($_xcdll, "none", "XRichEdit_SetTextInt", "hwnd", $_hEle, "int", $_nVaule)
EndFunc   ;==>XRichEdit_SetTextInt

Func XRichEdit_GetText($_hEle, $_len, $_pOut=0)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_GetText", "hwnd", $_hEle, "wstr", $_pOut, "int", $_len)
	Return $_XRichEdit
EndFunc   ;==>XRichEdit_GetText

Func XRichEdit_InsertData($_hEle, $_pData, $_iRow, $_iColumn)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_InsertData", "hwnd", $_hEle, "ptr", $_pData, "int", $_iRow, "int", $_iColumn)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_InsertData

Func XRichEdit_EnableReadOnly($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XRichEdit_EnableReadOnly", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XRichEdit_EnableReadOnly

Func XRichEdit_EnableMultiLine($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XRichEdit_EnableMultiLine", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XRichEdit_EnableMultiLine

Func XRichEdit_EnablePassword($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XRichEdit_EnablePassword", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XRichEdit_EnablePassword

Func XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE

Func XRichEdit_EnableAutoWrap($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XRichEdit_EnableAutoWrap", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XRichEdit_EnableAutoWrap

Func XRichEdit_EnableAutoCancelSel($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XRichEdit_EnableAutoCancelSel", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XRichEdit_EnableAutoCancelSel

Func XRichEdit_EnableAutoSelAll($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XRichEdit_EnableAutoSelAll", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XRichEdit_EnableAutoSelAll

Func XRichEdit_GetTextLength($_hEle)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_GetTextLength", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_GetTextLength

Func XRichEdit_SetRowHeight($_hEle, $_nHeight)
	DllCall($_xcdll, "none", "XRichEdit_SetRowHeight", "hwnd", $_hEle, "uint", $_nHeight)
EndFunc   ;==>XRichEdit_SetRowHeight

Func XRichEdit_GetCurrentRow($_hEle)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_GetCurrentRow", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_GetCurrentRow

Func XRichEdit_GetCurrentColumn($_hEle)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_GetCurrentColumn", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_GetCurrentColumn

Func XRichEdit_SetCurrentPos($_hEle, $_iRow, $_iColumn)
	DllCall($_xcdll, "none", "XRichEdit_SetCurrentPos", "hwnd", $_hEle, "int", $_iRow, "int", $_iColumn)
EndFunc   ;==>XRichEdit_SetCurrentPos

Func XRichEdit_GetHTMLFormat($_hEle, $_pOut, $_len)
	DllCall($_xcdll, "none", "XRichEdit_GetHTMLFormat", "hwnd", $_hEle, "int", $_pOut, "int", $_len)
EndFunc

Func XRichEdit_GetRowCount($_hEle)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_GetRowCount", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_GetRowCount

Func XRichEdit_GetRowLength($_hEle, $_iRow)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_GetRowLength", "hwnd", $_hEle, "int", $_iRow)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_GetRowLength

Func XRichEdit_GetData($_hEle, $_pDataSize)
	$_XRichEdit = DllCall($_xcdll, "prt", "XRichEdit_GetData", "hwnd", $_hEle, "int", $_pDataSize)
	Return $_XRichEdit[0]
EndFunc

Func XRichEdit_GetSelectText($_hEle, $_pOut, $_len)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_GetSelectText", "hwnd", $_hEle, "wstr", $_pOut, "int", $_len)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_GetSelectText

Func XRichEdit_GetSelectPosition($_hEle, $_pBegin, $_pEnd)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_GetSelectPosition", "hwnd", $_hEle, "int", $_pBegin, "int", $_pEnd)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_GetSelectPosition

Func XRichEdit_SetSelect($_hEle, $_iStartRow, $_iStartCol, $_iEndRow, $_iEndCol)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_SetSelect", "hwnd", $_hEle, "int", $_iStartRow, "int", $_iStartCol, "int", $_iEndRow, "int", $_iEndCol)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_SetSelect

Func XRichEdit_SetItemFontEx($_hEle, $_beginRow, $_beginColumn, $_iEndRow, $_endColumn, $_pFont)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_SetItemFontEx", "hwnd", $_hEle, "int", $_beginRow, "int", $_beginColumn, "int", $_iEndRow, "int", $_endColumn, "hwnd", $_pFont)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_SetItemFontEx

Func XRichEdit_SetItemColorEx($_hEle, $_beginRow, $_beginColumn, $_iEndRow, $_endColumn, $_color, $_alpha)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_SetItemColorEx", "hwnd", $_hEle, "int", $_beginRow, "int", $_beginColumn, "int", $_iEndRow, "int", $_endColumn, "int", $_color, "byte", $_alpha)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_SetItemColorEx

Func XRichEdit_CancelSelect($_hEle)
	DllCall($_xcdll, "none", "XRichEdit_CancelSelect", "hwnd", $_hEle)
EndFunc   ;==>XRichEdit_CancelSelect

Func XRichEdit_SetSelectBkColor($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XRichEdit_SetSelectBkColor", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XRichEdit_SetSelectBkColor

Func XRichEdit_IsEmpty($_hEle)
	$_XRichEdit = DllCall($_xcdll, "bool", "WINAPI XRichEdit_IsEmpty", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_IsEmpty

Func XRichEdit_SelectAll($_hEle)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_SelectAll", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_SelectAll

Func XRichEdit_DeleteSelect($_hEle)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_DeleteSelect", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_DeleteSelect

Func XRichEdit_ClipboardCut($_hEle)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_ClipboardCut", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_ClipboardCut

Func XRichEdit_ClipboardCopy($_hEle)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_ClipboardCopy", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_ClipboardCopy

Func XRichEdit_ClipboardPaste($_hEle)
	$_XRichEdit = DllCall($_xcdll, "bool", "XRichEdit_ClipboardPaste", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_ClipboardPaste

Func XRichEdit_DeleteAll($_hEle)
	$_XRichEdit = DllCall($_xcdll, "int", "XRichEdit_DeleteAll", "hwnd", $_hEle)
	Return $_XRichEdit[0]
EndFunc   ;==>XRichEdit_DeleteAll
;=================RichEdit-富文本编辑框结束=======================
;=================ScrollBar-滚动条开始=======================
Func XSBar_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XSBar = DllCall($_xcdll, "hwnd", "XSBar_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_Create

Func XSBar_SetRange($_hEle, $_range)
	DllCall($_xcdll, "none", "XSBar_SetRange", "hwnd", $_hEle, "int", $_range)
EndFunc   ;==>XSBar_SetRange

Func XSBar_GetRange($_hEle)
	$_XSBar = DllCall($_xcdll, "int", "XSBar_GetRange", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_GetRange

Func XSBar_ShowButton($_hEle, $_bShow)
	DllCall($_xcdll, "none", "XSBar_ShowButton", "hwnd", $_hEle, "bool", $_bShow)
EndFunc   ;==>XSBar_ShowButton

Func XSBar_SetSliderLength($_hEle, $_length)
	DllCall($_xcdll, "none", "XSBar_SetSliderLength", "hwnd", $_hEle, "int", $_length)
EndFunc   ;==>XSBar_SetSliderLength

Func XSBar_SetSliderMinLength($_hEle, $_minLength)
	DllCall($_xcdll, "none", "XSBar_SetSliderMinLength", "hwnd", $_hEle, "int", $_minLength)
EndFunc   ;==>XSBar_SetSliderMinLength

Func XSBar_SetHorizon($_hEle, $_bHorizon)
	$_XSBar = DllCall($_xcdll, "bool", "XSBar_SetHorizon", "hwnd", $_hEle, "bool", $_bHorizon)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_SetHorizon

Func XSBar_GetSliderMaxLength($_hEle)
	$_XSBar = DllCall($_xcdll, "int", "XSBar_GetSliderMaxLength", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_GetSliderMaxLength

Func XSBar_ScrollUp($_hEle)
	$_XSBar = DllCall($_xcdll, "bool", "XSBar_ScrollUp", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_ScrollUp

Func XSBar_ScrollDown($_hEle)
	$_XSBar = DllCall($_xcdll, "bool", "XSBar_ScrollDown", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_ScrollDown

Func XSBar_ScrollTop($_hEle)
	$_XSBar = DllCall($_xcdll, "bool", "XSBar_ScrollTop", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_ScrollTop

Func XSBar_ScrollBottom($_hEle)
	$_XSBar = DllCall($_xcdll, "bool", "XSBar_ScrollBottom", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_ScrollBottom

Func XSBar_ScrollPos($_hEle, $_pos)
	$_XSBar = DllCall($_xcdll, "bool", "XSBar_ScrollPos", "hwnd", $_hEle, "int", $_pos)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_ScrollPos

Func XSBar_GetButtonUp($_hEle)
	$_XSBar = DllCall($_xcdll, "hwnd", "XSBar_GetButtonUp", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_GetButtonUp

Func XSBar_GetButtonDown($_hEle)
	$_XSBar = DllCall($_xcdll, "hwnd", "XSBar_GetButtonDown", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_GetButtonDown

Func XSBar_GetButtonSlider($_hEle)
	$_XSBar = DllCall($_xcdll, "hwnd", "XSBar_GetButtonSlider", "hwnd", $_hEle)
	Return $_XSBar[0]
EndFunc   ;==>XSBar_GetButtonSlider
;=================ScrollBar-滚动条结束=======================
;=================ScrollView-滚动视图开始=======================
Func XSView_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XSView = DllCall($_xcdll, "hwnd", "XSView_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XSView[0]
EndFunc   ;==>XSView_Create

Func XSView_SetTotalSize($_hEle, $_width, $_height)
	$_XSView = DllCall($_xcdll, "bool", "XSView_SetTotalSize", "hwnd", $_hEle, "int", $_width, "int", $_height)
	Return $_XSView[0]
EndFunc   ;==>XSView_SetTotalSize

Func XSView_SetLineSize($_hEle, $_nwidth, $_nHeight)
	$_XSView = DllCall($_xcdll, "bool", "XSView_SetLineSize", "hwnd", $_hEle, "int", $_nwidth, "int", $_nHeight)
	Return $_XSView[0]
EndFunc   ;==>XSView_SetLineSize

Func XSView_GetViewPosH($_hEle)
	$_XSView = DllCall($_xcdll, "int", "XSView_GetViewPosH", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_GetViewPosH

Func XSView_GetViewPosV($_hEle)
	$_XSView = DllCall($_xcdll, "int", "XSView_GetViewPosV", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_GetViewPosV

Func XSView_GetViewWidth($_hEle)
	$_XSView = DllCall($_xcdll, "int", "XSView_GetViewWidth", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_GetViewWidth

Func XSView_GetViewHeight($_hEle)
	$_XSView = DllCall($_xcdll, "int", "XSView_GetViewHeight", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_GetViewHeight

Func XSView_GetScrollBarH($_hEle)
	$_XSView = DllCall($_xcdll, "hwnd", "XSView_GetScrollBarH", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_GetScrollBarH

Func XSView_GetScrollBarV($_hEle)
	$_XSView = DllCall($_xcdll, "hwnd", "XSView_GetScrollBarV", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_GetScrollBarV

Func XSView_SetPadding($_hEle, $_left, $_top, $_right, $_bottom)
	DllCall($_xcdll, "none", "XSView_SetPadding", "hwnd", $_hEle, "int", $_left, "int", $_top, "int", $_right, "hwnd", $_bottom)
EndFunc   ;==>XSView_SetPadding

Func XSView_ScrollPosH($_hEle, $_pos)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollPosH", "hwnd", $_hEle, "int", $_pos)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollPosH

Func XSView_ScrollPosV($_hEle, $_pos)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollPosV", "hwnd", $_hEle, "int", $_pos)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollPosV

Func XSView_ScrollPosxH($_hEle, $_posx)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollPosxH", "hwnd", $_hEle, "int", $_posx)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollPosxH

Func XSView_GetLineSize($_hEle, $_pSize)
	DllCall($_xcdll, "none", "XSView_GetLineSize", "hwnd", $_hEle, "ptr", $_pSize)
EndFunc

Func XSView_GetPadding($_hEle, $_pPadding)
	DllCall($_xcdll, "none", "XSView_GetPadding", "hwnd", $_hEle, "ptr", $_pPadding)
EndFunc

Func XSView_GetViewRect($_hEle, $_pRect)
	DllCall($_xcdll, "none", "XSView_GetViewRect", "hwnd", $_hEle, "ptr", $_pRect)
EndFunc

Func XSView_GetTotalSize($_hEle, $_pSize)
	DllCall($_xcdll, "none", "XSView_GetTotalSize", "hwnd", $_hEle, "ptr", $_pSize)
EndFunc

Func XSView_ScrollPosyV($_hEle, $_posy)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollPosyV", "hwnd", $_hEle, "int", $_posy)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollPosyV

Func XSView_ShowSBarH($_hEle, $_bShow)
	DllCall($_xcdll, "none", "XSView_ShowSBarH", "hwnd", $_hEle, "bool", $_bShow)
EndFunc   ;==>XSView_ShowSBarH

Func XSView_ShowSBarV($_hEle, $_bShow)
	DllCall($_xcdll, "none", "XSView_ShowSBarV", "hwnd", $_hEle, "bool", $_bShow)
EndFunc   ;==>XSView_ShowSBarV

Func XSView_EnableAutoShowScrollBar($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XSView_EnableAutoShowScrollBar", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XSView_EnableAutoShowScrollBar

Func XSView_ScrollLeftLine($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollLeftLine", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollLeftLine

Func XSView_ScrollRightLine($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollRightLine", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollRightLine

Func XSView_ScrollTopLine($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollTopLine", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollTopLine

Func XSView_ScrollBottomLine($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollBottomLine", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollBottomLine

Func XSView_ScrollLeft($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollLeft", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollLeft

Func XSView_ScrollRight($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollRight", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollRight

Func XSView_ScrollTop($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollTop", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollTop

Func XSView_ScrollBottom($_hEle)
	$_XSView = DllCall($_xcdll, "bool", "XSView_ScrollBottom", "hwnd", $_hEle)
	Return $_XSView[0]
EndFunc   ;==>XSView_ScrollBottom
;=================ScrollView-滚动视图结束=======================
;=================SliderBar-滑动条元素开始=======================
Func XSliderBar_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XSli = DllCall($_xcdll, "hwnd", "XSliderBar_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XSli[0]
EndFunc   ;==>XSliderBar_Create

Func XSliderBar_SetRange($_hEle, $_range)
	DllCall($_xcdll, "none", "XSliderBar_SetRange", "hwnd", $_hEle, "int", $_range)
EndFunc   ;==>XSliderBar_SetRange

Func XSliderBar_GetRange($_hEle)
	$_XSli = DllCall($_xcdll, "int", "XSliderBar_GetRange", "hwnd", $_hEle)
	Return $_XSli[0]
EndFunc   ;==>XSliderBar_GetRange

Func XSliderBar_SetImageLoad($_hEle, $_hImage)
	DllCall($_xcdll, "none", "XSliderBar_SetImageLoad", "hwnd", $_hEle, "ptr", $_hImage)
EndFunc   ;==>XSliderBar_SetImageLoad

Func XSliderBar_SetButtonWidth($_hEle, $_width)
	DllCall($_xcdll, "none", "XSliderBar_SetButtonWidth", "hwnd", $_hEle, "int", $_width)
EndFunc   ;==>XSliderBar_SetButtonWidth

Func XSliderBar_SetButtonHeight($_hEle, $_height)
	DllCall($_xcdll, "none", "XSliderBar_SetButtonHeight", "hwnd", $_hEle, "int", $_height)
EndFunc   ;==>XSliderBar_SetButtonHeight

Func XSliderBar_SetSpaceTwo($_hEle, $_leftSize, $_rightSize)
	DllCall($_xcdll, "none", "XSliderBar_SetSpaceTwo", "hwnd", $_hEle, "int", $_leftSize, "int", $_rightSize)
EndFunc   ;==>XSliderBar_SetSpaceTwo

Func XSliderBar_SetPos($_hEle, $_pos)
	DllCall($_xcdll, "none", "XSliderBar_SetPos", "hwnd", $_hEle, "int", $_pos)
EndFunc   ;==>XSliderBar_SetPos

Func XSliderBar_SetHorizon($_hEle, $_bHorizon)
	DllCall($_xcdll, "none", "XSliderBar_SetHorizon", "hwnd", $_hEle, "bool", $_bHorizon)
EndFunc   ;==>XSliderBar_SetHorizon

Func XSliderBar_GetPos($_hEle)
	$_XSli = DllCall($_xcdll, "int", "XSliderBar_GetPos", "hwnd", $_hEle)
	Return $_XSli[0]
EndFunc   ;==>XSliderBar_GetPos

Func XSliderBar_GetButton($_hEle)
	$_XSli = DllCall($_xcdll, "hwnd", "XSliderBar_GetButton", "hwnd", $_hEle)
	Return $_XSli[0]
EndFunc   ;==>XSliderBar_GetButton
;=================SliderBar-滑动条元素结束=======================
;=================tabBar -TabBar元素开始=======================
Func XTabBar_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XTab = DllCall($_xcdll, "hwnd", "XTabBar_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_Create

Func XTabBar_AddLabel($_hEle, $_pName)
	$_XTab = DllCall($_xcdll, "int", "XTabBar_AddLabel", "hwnd", $_hEle, "wstr", $_pName)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_AddLabel

Func XTabBar_InsertLabel($_hEle, $_index, $_pName)
	$_XTab = DllCall($_xcdll, "int", "XTabBar_InsertLabel", "hwnd", $_hEle, "int", $_index, "wstr", $_pName)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_InsertLabel

Func XTabBar_DeleteLabel($_hEle, $_index)
	$_XTab = DllCall($_xcdll, "bool", "XTabBar_DeleteLabel", "hwnd", $_hEle, "int", $_index)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_DeleteLabel

Func XTabBar_DeleteLabelAll($_hEle)
	DllCall($_xcdll, "none", "XTabBar_DeleteLabelAll", "hwnd", $_hEle)
EndFunc   ;==>XTabBar_DeleteLabelAll

Func XTabBar_GetLabel($_hEle, $_index)
	$_XTab = DllCall($_xcdll, "hwnd", "XTabBar_GetLabel", "hwnd", $_hEle, "int", $_index)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_GetLabel

Func XTabBar_GetLabelClose($_hEle, $_index)
	$_XTab = DllCall($_xcdll, "hwnd", "XTabBar_GetLabelClose", "hwnd", $_hEle, "int", $_index)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_GetLabelClose

Func XTabBar_GetButtonLeft($_hEle)
	$_XTab = DllCall($_xcdll, "hwnd", "XTabBar_GetButtonLeft", "hwnd", $_hEle)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_GetButtonLeft

Func XTabBar_GetButtonRight($_hEle)
	$_XTab = DllCall($_xcdll, "hwnd", "XTabBar_GetButtonRight", "hwnd", $_hEle)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_GetButtonRight

Func XTabBar_GetSelect($_hEle)
	$_XTab = DllCall($_xcdll, "int", "XTabBar_GetSelect", "hwnd", $_hEle)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_GetSelect

Func XTabBar_GetLabelSpacing($_hEle)
	$_XTab = DllCall($_xcdll, "int", "XTabBar_GetLabelSpacing", "hwnd", $_hEle)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_GetLabelSpacing

Func XTabBar_GetLabelCount($_hEle)
	$_XTab = DllCall($_xcdll, "int", "XTabBar_GetLabelCount", "hwnd", $_hEle)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_GetLabelCount

Func XTabBar_SetLabelSpacing($_hEle, $_spacing)
	DllCall($_xcdll, "none", "XTabBar_SetLabelSpacing", "hwnd", $_hEle, "int", $_spacing)
EndFunc   ;==>XTabBar_SetLabelSpacing

Func XTabBar_SetSelect($_hEle, $_index)
	DllCall($_xcdll, "none", "XTabBar_SetSelect", "hwnd", $_hEle, "int", $_index)
EndFunc   ;==>XTabBar_SetSelect

Func XTabBar_SetUp($_hEle)
	DllCall($_xcdll, "none", "XTabBar_SetUp", "hwnd", $_hEle)
EndFunc   ;==>XTabBar_SetUp

Func XTabBar_SetDown($_hEle)
	DllCall($_xcdll, "none", "XTabBar_SetDown", "hwnd", $_hEle)
EndFunc   ;==>XTabBar_SetDown

Func XTabBar_EnableTile($_hEle, $_bTile)
	DllCall($_xcdll, "none", "XTabBar_EnableTile", "hwnd", $_hEle, "bool", $_bTile)
EndFunc   ;==>XTabBar_EnableTile

Func XTabBar_EnableClose($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XTabBar_EnableTile", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XTabBar_EnableClose

Func XTabBar_SetCloseSize($_hEle, $_pSize)
	DllCall($_xcdll, "none", "XTabBar_SetCloseSize", "hwnd", $_hEle, "int", $_pSize)
EndFunc   ;==>XTabBar_SetCloseSize

Func XTabBar_SetTurnButtonSize($_hEle, $_pSize)
	DllCall($_xcdll, "none", "XTabBar_SetTurnButtonSize", "hwnd", $_hEle, "int", $_pSize)
EndFunc   ;==>XTabBar_SetTurnButtonSize

Func XTabBar_ShowLabel($_hEle, $_index, $_bShow)
	$_XTab = DllCall($_xcdll, "bool", "XTabBar_ShowLabel", "hwnd", $_hEle, "int", $_index, "bool", $_bShow)
	Return $_XTab[0]
EndFunc   ;==>XTabBar_ShowLabel
;=================tabBar -TabBar元素结束=======================
;=================Image-图片操作结束=======================
Func XTextLink_Create($_x, $_y, $_width, $_height, $_pName, $_hparent)
	$_XTextLink = DllCall($_xcdll, "hwnd", "XTextLink_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", $_pName, "hwnd", $_hparent)
	Return $_XTextLink[0]
EndFunc   ;==>XTextLink_Create

Func XTextLink_EnableUnderlineLeave($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XTextLink_EnableUnderlineLeave", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XTextLink_EnableUnderlineLeave

Func XTextLink_EnableUnderlineStay($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XTextLink_EnableUnderlineStay", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XTextLink_EnableUnderlineStay

Func XTextLink_SetTextColorStay($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XTextLink_SetTextColorStay", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XTextLink_SetTextColorStay

Func XTextLink_SetUnderlineColorLeave($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XTextLink_SetUnderlineColorLeave", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XTextLink_SetUnderlineColorLeave

Func XTextLink_SetUnderlineColorStay($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XTextLink_SetUnderlineColorStay", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XTextLink_SetUnderlineColorStay
;=================Image-图片操作开始=======================
;=================ToolBar-工具条开始=======================
Func XToolBar_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XToolBar = DllCall($_xcdll, "hwnd", "XToolBar_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XToolBar[0]
EndFunc   ;==>XToolBar_Create

Func XToolBar_InsertEle($_hEle, $_hNewEle, $_index)
	$_XToolBar = DllCall($_xcdll, "int", "XToolBar_InsertEle", "hwnd", $_hEle, "hwnd", $_hNewEle, "int", $_index)
	Return $_XToolBar[0]
EndFunc   ;==>XToolBar_InsertEle

Func XToolBar_InsertSeparator($_hEle, $_index)
	$_XToolBar = DllCall($_xcdll, "int", "XToolBar_InsertSeparator", "hwnd", $_hEle, "int", $_index)
	Return $_XToolBar[0]
EndFunc   ;==>XToolBar_InsertSeparator

Func XToolBar_EnableButtonMenu($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XToolBar_EnableButtonMenu", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XToolBar_EnableButtonMenu

Func XToolBar_GetHEle($_hEle, $_index)
	$_XToolBar = DllCall($_xcdll, "hwnd", "XToolBar_GetHEle", "hwnd", $_hEle, "int", $_index)
	Return $_XToolBar[0]
EndFunc   ;==>XToolBar_GetHEle

Func XToolBar_GetButtonLeft($_hEle)
	$_XToolBar = DllCall($_xcdll, "hwnd", "XToolBar_GetButtonLeft", "hwnd", $_hEle)
	Return $_XToolBar[0]
EndFunc   ;==>XToolBar_GetButtonLeft

Func XToolBar_GetButtonRight($_hEle)
	$_XToolBar = DllCall($_xcdll, "hwnd", "XToolBar_GetButtonRight", "hwnd", $_hEle)
	Return $_XToolBar[0]
EndFunc   ;==>XToolBar_GetButtonRight

Func XToolBar_GetButtonMenu($_hEle)
	$_XToolBar = DllCall($_xcdll, "hwnd", "XToolBar_GetButtonMenu", "hwnd", $_hEle)
	Return $_XToolBar[0]
EndFunc   ;==>XToolBar_GetButtonMenu

Func XToolBar_SetSpace($_hEle, $_nSize)
	DllCall($_xcdll, "none", "XToolBar_SetSpace", "hwnd", $_hEle, "int", $_nSize)
EndFunc   ;==>XToolBar_SetSpace

Func XToolBar_DeleteEle($_hEle, $_index)
	DllCall($_xcdll, "none", "XToolBar_DeleteEle", "hwnd", $_hEle, "int", $_index)
EndFunc   ;==>XToolBar_DeleteEle

Func XToolBar_DeleteAllEle($_hEle)
	DllCall($_xcdll, "none", "XToolBar_DeleteAllEle", "hwnd", $_hEle)
EndFunc   ;==>XToolBar_DeleteAllEle
;=================ToolBar-工具条结束=======================
;=================Tree-列表树元素开始=======================
Func XTree_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XTree = DllCall($_xcdll, "hwnd", "XTree_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XTree[0]
EndFunc   ;==>XTree_Create

Func XTree_EnableDragItem($_hEle, $_bEnable)
	DllCall($_xcdll, "none", "XTree_EnableDragItem", "hwnd", $_hEle, "bool", $_bEnable)
EndFunc   ;==>XTree_EnableDragItem

Func XTree_SetRowSpace($_hEle, $_nSpace)
	DllCall($_xcdll, "none", "XTree_SetRowSpace", "hwnd", $_hEle, "int", $_nSpace)
EndFunc

Func XTree_SetExpandButtonContentSpace($_hEle, $_nSpace)
	DllCall($_xcdll, "none", "XTree_SetExpandButtonContentSpace", "hwnd", $_hEle, "int", $_nSpace)
EndFunc

Func XTree_SetDragInsertPositionColor($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XTree_SetDragInsertPositionColor", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XTree_SetDragInsertPositionColor

Func XTree_SetExpandButtonSize($_hEle, $_nWidth, $_nHeight)
	DllCall($_xcdll, "none", "XTree_SetExpandButtonSize", "hwnd", $_hEle, "int", $_nWidth, "int", $_nHeight)
EndFunc

Func XTree_SetConnectLineColor($_hEle, $_color, $_alpha)
	DllCall($_xcdll, "none", "XTree_SetConnectLineColor", "hwnd", $_hEle, "int", $_color, "byte", $_alpha)
EndFunc 

Func XTree_EnableConnectLine($_hEle, $_bEnable, $_bSolid)
	DllCall($_xcdll, "none", "XTree_EnableConnectLine", "hwnd", $_hEle, "bool", $_bEnable, "bool", $_bSolid)
EndFunc

Func XTree_SetItemTemplateXML($_hEle, $_pXmlFile)
	$_XTree = DllCall($_xcdll, "bool", "XTree_SetItemTemplateXML", "hwnd", $_hEle, "wstr", $_pXmlFile)
	Return $_XTree[0]
EndFunc   ;==>XTree_SetItemTemplateXML

Func XTree_SetItemTemplateXMLSel($_hEle, $_pXmlFile)
	$_XTree = DllCall($_xcdll, "bool", "XTree_SetItemTemplateXMLSel", "hwnd", $_hEle, "wstr", $_pXmlFile)
	Return $_XTree[0]
EndFunc   ;==>XTree_SetItemTemplateXMLSel

Func XTree_SetItemTemplateXMLFromString($_hEle, $_pXmlFile)
	$_XTree = DllCall($_xcdll, "bool", "XTree_SetItemTemplateXMLFromString", "hwnd", $_hEle, "wstr", $_pXmlFile)
	Return $_XTree[0]
EndFunc   ;==>XTree_SetItemTemplateXMLFromString

Func XTree_SetItemTemplateXMLSelFromString($_hEle, $_pXmlFile)
	$_XTree = DllCall($_xcdll, "bool", "XTree_SetItemTemplateXMLSelFromString", "hwnd", $_hEle, "wstr", $_pXmlFile)
	Return $_XTree[0]
EndFunc   ;==>XTree_SetItemTemplateXMLSelFromString

Func XTree_SetDrawItemBkFlags($_hEle, $_nFlags)
	DllCall($_xcdll, "none", "XTree_SetDrawItemBkFlags", "hwnd", $_hEle, "int", $_nFlags)
EndFunc   ;==>XTree_SetDrawItemBkFlags

Func XTree_SetItemData($_hEle, $_nID, $_nUserData)
	$_XTree = DllCall($_xcdll, "bool", "XTree_SetItemData", "hwnd", $_hEle, "int", $_nID, "int", $_nUserData)
	Return $_XTree[0]
EndFunc   ;==>XTree_SetItemData

Func XTree_GetItemData($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetItemData", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetItemData

Func XTree_GetRowSpace($_hEle)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetRowSpace", "hwnd", $_hEle)
	Return $_XTree[0]
EndFunc

Func XTree_SetSelectItem($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "bool", "XTree_SetSelectItem", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XTree_SetSelectItem

Func XTree_GetSelectItem($_hEle)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetSelectItem", "hwnd", $_hEle)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetSelectItem

Func XTree_IsExpand($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "bool", "XTree_IsExpand", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XTree_IsExpand

Func XTree_ExpandItem($_hEle, $_nID, $_bExpand)
	$_XTree = DllCall($_xcdll, "bool", "XTree_ExpandItem", "hwnd", $_hEle, "int", $_nID, "bool", $_bExpand)
	Return $_XTree[0]
EndFunc   ;==>XTree_ExpandItem

Func XTree_HitTest($_hEle, $_pPt)
	$_XTree = DllCall($_xcdll, "int", "XTree_HitTest", "hwnd", $_hEle, "int", $_pPt)
	Return $_XTree[0]
EndFunc   ;==>XTree_HitTest

Func XTree_HitTestOffet($_hEle, $_pPt)
	$_XTree = DllCall($_xcdll, "int", "XTree_HitTestOffet", "hwnd", $_hEle, "int", $_pPt)
	Return $_XTree[0]
EndFunc   ;==>XTree_HitTestOffet

Func XTree_GetFirstChildItem($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetFirstChildItem", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetFirstChildItem

Func XTree_GetEndChildItem($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetEndChildItem", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetEndChildItem

Func XXTree_GetPrevSiblingItem($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetPrevSiblingItem", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XXTree_GetPrevSiblingItem

Func XTree_GetNextSiblingItem($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetNextSiblingItem", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetNextSiblingItem

Func XTree_GetParentItem($_hEle, $_nID)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetParentItem", "hwnd", $_hEle, "int", $_nID)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetParentItem

Func XTree_BindAdapter($_hEle, $_hAdapter)
	DllCall($_xcdll, "none", "XTree_BindAdapter", "hwnd", $_hEle, "int", $_hAdapter)
EndFunc   ;==>XTree_BindAdapter

Func XTree_GetAdapter($_hEle)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetAdapter", "hwnd", $_hEle)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetAdapter

Func XTree_RefreshData($_hEle)
	DllCall($_xcdll, "none", "XTree_BindAdapter", "hwnd", $_hEle)
EndFunc   ;==>XTree_RefreshData

Func XTree_SetIndentation($_hEle, $_nwidth)
	DllCall($_xcdll, "none", "XTree_SetIndentation", "hwnd", $_hEle, "int", $_nwidth)
EndFunc   ;==>XTree_SetIndentation

Func XTree_GetIndentation($_hEle)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetIndentation", "hwnd", $_hEle)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetIndentation

Func XTree_SetItemHeightDefault($_hEle, $_nHeight, $_nSelHeight)
	DllCall($_xcdll, "none", "XTree_SetItemHeightDefault", "hwnd", $_hEle, "int", $_nHeight, "int", $_nSelHeight)
EndFunc   ;==>XTree_SetItemHeightDefault

Func XTree_GetItemHeightDefault($_hEle, $_pHeight, $_pSelHeight)
	DllCall($_xcdll, "none", "XTree_GetItemHeightDefault", "hwnd", $_hEle, "int", $_pHeight, "int", $_pSelHeight)
EndFunc

Func XTree_SetItemHeight($_hEle, $_nID, $_nHeight, $_nSelHeight)
	DllCall($_xcdll, "none", "XTree_SetItemHeight", "hwnd", $_hEle, "int", $_nID, "int", $_nHeight, "int", $_nSelHeight)
EndFunc   ;==>XTree_SetItemHeight

Func XTree_GetItemHeight($_hEle, $_nID, $_pHeight, $_pSelHeight)
	DllCall($_xcdll, "none", "XTree_GetItemHeight", "hwnd", $_hEle, "int", $_nID, "int", $_pHeight, "int", $_pSelHeight)
EndFunc

Func XTree_MoveItem($_hEle, $_nMoveItem, $_nDestItem, $_nType)
	$_XTree = DllCall($_xcdll, "int", "XTree_MoveItem", "hwnd", $_hEle, "int", $_nMoveItem, "int", $_nDestItem, "int", $_nType)
	Return $_XTree[0]
EndFunc   ;==>XTree_MoveItem

Func XTree_AddItemBkBorder($_hEle, $_nState, $_color, $_alpha, $_width)
	DllCall($_xcdll, "none", "XTree_AddItemBkBorder", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha, "int", $_width)
EndFunc   ;==>XTree_AddItemBkBorder

Func XTree_AddItemBkFill($_hEle, $_nState, $_color, $_alpha)
	DllCall($_xcdll, "none", "XTree_AddItemBkFill", "hwnd", $_hEle, "int", $_nState, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XTree_AddItemBkFill

Func XTree_AddItemBkImage($_hEle, $_nState, $_hImage)
	DllCall($_xcdll, "none", "XTree_AddItemBkImage", "hwnd", $_hEle, "int", $_nState, "ptr", $_hImage)
EndFunc   ;==>XTree_AddItemBkImage

Func XTree_GetItemBkInfoCount($_hEle)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetItemBkInfoCount", "hwnd", $_hEle)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetItemBkInfoCount

Func XTree_ClearItemBkInfo($_hEle)
	DllCall($_xcdll, "none", "XTree_ClearItemBkInfo", "hwnd", $_hEle)
EndFunc   ;==>XTree_ClearItemBkInfo

Func XTree_GetTemplateObject($_hEle, $_nID, $_TempItemID)
	$_XTree = DllCall($_xcdll, "hwnd", "XTree_GetTemplateObject", "hwnd", $_hEle, "int", $_nID, "int", $_TempItemID)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetTemplateObject

Func XTree_GetItemIDFromHXCGUI($_hEle, $_hXCGUI)
	$_XTree = DllCall($_xcdll, "int", "XTree_GetItemIDFromHXCGUI", "hwnd", $_hEle, "hwnd", $_hXCGUI)
	Return $_XTree[0]
EndFunc   ;==>XTree_GetItemIDFromHXCGUI
;=================Tree-列表树元素结束=======================
;=================DateTime-日期时间开始=======================
Func XDateTime_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XDate = DllCall($_xcdll, "hwnd", "XDateTime_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XDate[0]
EndFunc   ;==>XDateTime_Create

Func XDateTime_SetStyle($_hEle, $_nStyle)
	DllCall($_xcdll, "none", "XDateTime_SetStyle", "hwnd", $_hEle, "int", $_nStyle)
EndFunc   ;==>XDateTime_SetStyle

Func XDateTime_GetStyle($_hEle)
	$_XDate = DllCall($_xcdll, "int", "XDateTime_GetStyle", "hwnd", $_hEle)
	Return $_XDate[0]
EndFunc   ;==>XDateTime_GetStyle

Func XDateTime_GetButton($_hEle, $_nType)
	$_XDate = DllCall($_xcdll, "hwnd", "XDateTime_GetButton", "hwnd", $_hEle, "int", $_nType)
	Return $_XDate[0]
EndFunc   ;==>XDateTime_GetButton

Func XDateTime_GetSelBkColor($_hEle)
	$_XDate = DllCall($_xcdll, "int", "XDateTime_GetSelBkColor", "hwnd", $_hEle)
	Return $_XDate[0]
EndFunc   ;==>XDateTime_GetSelBkColor

Func XDateTime_SetSelBkColor($_hEle, $_crSelectBk, $_alpha)
	DllCall($_xcdll, "none", "XDateTime_SetSelBkColor", "hwnd", $_hEle, "int", $_crSelectBk, "byte", $_alpha)
EndFunc   ;==>XDateTime_SetSelBkColor

Func XDateTime_SetDate($_hEle, $_nYear, $_nMonth, $_nDay)
	DllCall($_xcdll, "none", "XDateTime_SetDate", "hwnd", $_hEle, "int", $_nYear, "int", $_nMonth, "int", $_nDay)
EndFunc   ;==>XDateTime_SetDate

Func XDateTime_GetDate($_hEle, $_pnYear, $_pnMonth, $_pnDay)
	DllCall($_xcdll, "none", "XDateTime_GetDate", "hwnd", $_hEle, "int", $_pnYear, "int", $_pnMonth, "int", $_pnDay)
EndFunc

Func XDateTime_GetTime($_hEle, $_pnHour, $_pnMinute, $_pnSecond)
	DllCall($_xcdll, "none", "XDateTime_GetTime", "hwnd", $_hEle, "int", $_pnHour, "int", $_pnMinute, "int", $_pnSecond)
EndFunc

Func XDateTime_SetTime($_hEle, $_nHour, $_nMinute, $_nSecond)
	DllCall($_xcdll, "none", "XDateTime_SetDate", "hwnd", $_hEle, "int", $_nHour, "int", $_nMinute, "int", $_nSecond)
EndFunc   ;==>XDateTime_SetTime
;=================DateTime-日期时间结束=======================
;=================MonthCal-月历卡片开始=======================
Func XMonthCal_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XMon = DllCall($_xcdll, "hwnd", "XMonthCal_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XMon[0]
EndFunc   ;==>XMonthCal_Create

Func XMonthCal_GetButton($_hEle, $_nType)
	$_XMon = DllCall($_xcdll, "hwnd", "XMonthCal_Create", "hwnd", $_hEle, "int", $_nType)
	Return $_XMon[0]
EndFunc   ;==>XMonthCal_GetButton

Func XMonthCal_SetToday($_hEle, $_nYear, $_nMonth, $_nDay)
	DllCall($_xcdll, "none", "XMonthCal_SetToday", "hwnd", $_hEle, "int", $_nYear, "int", $_nMonth, "int", $_nDay)
EndFunc   ;==>XMonthCal_SetToday

Func XMonthCal_SeSelDate($_hEle, $_nYear, $_nMonth, $_nDay)
	DllCall($_xcdll, "none", "XMonthCal_SeSelDate", "hwnd", $_hEle, "int", $_nYear, "int", $_nMonth, "int", $_nDay)
EndFunc   ;==>XMonthCal_SeSelDate

Func XMonthCal_GetToday($_hEle, $_pnYear, $_pnMonth, $_pnDay)
	DllCall($_xcdll, "none", "XMonthCal_GetToday", "hwnd", $_hEle, "int", $_pnYear, "int", $_pnMonth, "int", $_pnDay)
EndFunc

Func XMonthCal_GetSelDate($_hEle, $_nYear, $_nMonth, $_nDay)
	DllCall($_xcdll, "none", "XMonthCal_GetSelDate", "hwnd", $_hEle, "int*", $_nYear, "int*", $_nMonth, "int*", $_nDay)
EndFunc   ;==>XMonthCal_GetSelDate
;=================MonthCal-月历卡片结束=======================
;=================Shape-形状对象开始=======================
Func XShape_GetParentEle($_hShape)
	$_XShape = DllCall($_xcdll, "hwnd", "XShape_GetParentEle", "hwnd", $_hShape)
	Return $_XShape[0]
EndFunc   ;==>XShape_GetParentEle

Func XShape_GetParentLayout($_hShape)
	$_XShape = DllCall($_xcdll, "hwnd", "XShape_GetParentLayout", "hwnd", $_hShape)
	Return $_XShape[0]
EndFunc   ;==>XShape_GetParentLayout

Func XShape_GetHWINDOW($_hShape)
	$_XShape = DllCall($_xcdll, "hwnd", "XShape_GetHWINDOW", "hwnd", $_hShape)
	Return $_XShape[0]
EndFunc   ;==>XShape_GetHWINDOW

Func XShape_GetParent($_hShape)
	$_XShape = DllCall($_xcdll, "hwnd", "XShape_GetParent", "hwnd", $_hShape)
	Return $_XShape[0]
EndFunc   ;==>XShape_GetParent

Func XShape_RemoveShape($_hShape)
	DllCall($_xcdll, "none", "XShape_RemoveShape", "hwnd", $_hShape)
EndFunc   ;==>XShape_RemoveShape

Func XShape_SetID($_hShape, $_nID)
	DllCall($_xcdll, "none", "XShape_SetID", "hwnd", $_hShape, "int", $_nID)
EndFunc   ;==>XShape_SetID

Func XShapeText_GetText($_hShape, $_pOut,$_nOutLen)
	$XShape=DllCall($_xcdll, "none", "XShapeText_GetText", "hwnd", $_hShape, "wstr", $_pOut,"int",$_nOutLen)
	Return $XShape
EndFunc

Func XShape_GetContentSize($_hShape, $_pSize)
	DllCall($_xcdll, "none", "XShape_GetContentSize", "hwnd", $_hShape, "int", $_pSize)
EndFunc

Func XShape_GetRect($_hShape, $_pRect)
	DllCall($_xcdll, "none", "XShape_GetRect", "hwnd", $_hShape, "int", $_pRect)
EndFunc

Func XShape_GetID($_hShape)
	$_XShape = DllCall($_xcdll, "hwnd", "XShape_GetID", "hwnd", $_hShape)
	Return $_XShape[0]
EndFunc   ;==>XShape_GetID

Func XShape_Redraw($_hShape)
	DllCall($_xcdll, "none", "XShape_Redraw", "hwnd", $_hShape)
EndFunc   ;==>XShape_Redraw

Func XShape_GetWidth($_hShape)
	$_XShape = DllCall($_xcdll, "int", "XShape_GetWidth", "hwnd", $_hShape)
	Return $_XShape[0]
EndFunc   ;==>XShape_GetWidth

Func XShape_GetHeight($_hShape)
	$_XShape = DllCall($_xcdll, "int", "XShape_GetHeight", "hwnd", $_hShape)
	Return $_XShape[0]
EndFunc   ;==>XShape_GetHeight

Func XShape_SetRect($_hShape, $_pRect)
	DllCall($_xcdll, "none", "XShape_SetRect", "hwnd", $_hShape, "int", $_pRect)
EndFunc   ;==>XShape_SetRect

Func XShape_ShowLayout($_hShape, $_bShow)
	DllCall($_xcdll, "none", "XShape_ShowLayout", "hwnd", $_hShape, "bool", $_bShow)
EndFunc   ;==>XShape_ShowLayout

Func XShape_AdjustLayout($_hShape)
	DllCall($_xcdll, "none", "XShape_AdjustLayout", "hwnd", $_hShape)
EndFunc   ;==>XShape_AdjustLayout

Func XShape_Destroy($_hShape)
	DllCall($_xcdll, "none", "XShape_Destroy", "hwnd", $_hShape)
EndFunc   ;==>XShape_Destroy
;=================Shape-形状对象结束=======================
;=================ShapeText-形状对象文本开始=======================
Func XShapeText_Create($_x, $_y, $_width, $_height, $_pName, $_hparent)
	$_XShapeT = DllCall($_xcdll, "hwnd", "XShapeText_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", $_pName, "hwnd", $_hparent)
	Return $_XShapeT[0]
EndFunc   ;==>XShapeText_Create

Func XShapeText_SetText($_hTextBlock, $_pName)
	DllCall($_xcdll, "none", "XShapeText_SetText", "hwnd", $_hTextBlock, "wstr", $_pName)
EndFunc   ;==>XShapeText_SetText

Func XShapeText_GetTextLength($_hTextBlock)
	$_XShapeT = DllCall($_xcdll, "int", "XShapeText_GetTextLength", "hwnd", $_hTextBlock)
	Return $_XShapeT[0]
EndFunc   ;==>XShapeText_GetTextLength

Func XShapeText_SetFont($_hTextBlock, $_hFontx)
	DllCall($_xcdll, "none", "XShapeText_SetFont", "hwnd", $_hTextBlock, "hwnd", $_hFontx)
EndFunc   ;==>XShapeText_SetFont

Func XShapeText_SetTextColor($_hTextBlock, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeText_SetTextColor", "hwnd", $_hTextBlock, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeText_SetTextColor

Func XShapeText_GetTextColor($_hTextBlock)
	$_XShapeT = DllCall($_xcdll, "int", "XShapeText_GetTextColor", "hwnd", $_hTextBlock)
	Return $_XShapeT[0]
EndFunc   ;==>XShapeText_GetTextColor

Func XShapeText_SetTextAlign($_hTextBlock, $_align)
	DllCall($_xcdll, "none", "XShapeText_SetTextAlign", "hwnd", $_hTextBlock, "int", $_align)
EndFunc   ;==>XShapeText_SetTextAlign

Func XShapeText_SetOffset($_hTextBlock, $_x, $_y)
	DllCall($_xcdll, "none", "XShapeText_SetOffset", "hwnd", $_hTextBlock, "int", $_x, "int", $_y)
EndFunc   ;==>XShapeText_SetOffset

Func XShapeText_SetLayoutWidth($_hTextBlock, $_nType, $_width)
	DllCall($_xcdll, "none", "XShapeText_SetLayoutWidth", "hwnd", $_hTextBlock, "int", $_nType, "int", $_width)
EndFunc   ;==>XShapeText_SetLayoutWidth

Func XShapeText_SetLayoutHeight($_hTextBlock, $_nType, $_height)
	DllCall($_xcdll, "none", "XShapeText_SetLayoutHeight", "hwnd", $_hTextBlock, "int", $_nType, "int", $_height)
EndFunc   ;==>XShapeText_SetLayoutHeight

Func XShapeText_GetLayoutWidth($_hTextBlock, $_nType, $_width)
	DllCall($_xcdll, "none", "XShapeText_GetLayoutWidth", "hwnd", $_hTextBlock, "int", $_nType, "int", $_width)
EndFunc   ;==>XShapeText_GetLayoutWidth

Func XShapeText_GetLayoutHeight($_hTextBlock, $_nType, $_height)
	DllCall($_xcdll, "none", "XShapeText_GetLayoutHeight", "hwnd", $_hTextBlock, "int", $_nType, "int", $_height)
EndFunc   ;==>XShapeText_GetLayoutHeight
;=================ShapeText-形状对象文本结束=======================
;=================ShapePicture-形状对象图片开始=======================
Func XShapePic_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XShapeP = DllCall($_xcdll, "hwnd", "XShapePic_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XShapeP[0]
EndFunc   ;==>XShapePic_Create

Func XShapePic_SetImage($_hShape, $_hImage)
	DllCall($_xcdll, "none", "XShapePic_SetImage", "hwnd", $_hShape, "ptr", $_hImage)
EndFunc   ;==>XShapePic_SetImage

Func XShapePic_SetLayoutWidth($_hShape, $_nType, $_width)
	DllCall($_xcdll, "none", "XShapePic_SetLayoutWidth", "hwnd", $_hShape, "int", $_nType, "int", $_width)
EndFunc   ;==>XShapePic_SetLayoutWidth

Func XShapePic_GetLayoutWidth($_hShape, $_pType, $_pwidth)
	DllCall($_xcdll, "none", "XShapePic_GetLayoutWidth", "hwnd", $_hShape, "int", $_pType, "int", $_pwidth)
EndFunc

Func XShapePic_SetLayoutHeight($_hShape, $_nType, $_height)
	DllCall($_xcdll, "none", "XShapePic_SetLayoutHeight", "hwnd", $_hShape, "int", $_nType, "int", $_height)
EndFunc   ;==>XShapePic_SetLayoutHeight
;=================ShapePicture-形状对象图片结束=======================
;=================ShapeGif-形状对象GIF开始=======================
Func XShapeGif_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XShapeG = DllCall($_xcdll, "hwnd", "XShapeGif_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XShapeG[0]
EndFunc   ;==>XShapeGif_Create

Func XShapeGif_SetImage($_hShape, $_hImage)
	DllCall($_xcdll, "none", "XShapeGif_SetImage", "hwnd", $_hShape, "ptr", $_hImage)
EndFunc   ;==>XShapeGif_SetImage

Func XShapeGif_SetLayoutWidth($_hShape, $_nType, $_width)
	DllCall($_xcdll, "none", "XShapeGif_SetLayoutWidth", "hwnd", $_hShape, "int", $_nType, "int", $_width)
EndFunc   ;==>XShapeGif_SetLayoutWidth

Func XShapeGif_SetLayoutHeight($_hShape, $_nType, $_height)
	DllCall($_xcdll, "none", "XShapeGif_SetLayoutHeight", "hwnd", $_hShape, "int", $_nType, "int", $_height)
EndFunc   ;==>XShapeGif_SetLayoutHeight
;=================ShapeGif-形状对象GIF结束=======================
;=================ShapeRect-矩形形状对象开始=======================
Func XShapeRect_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XShapeR = DllCall($_xcdll, "hwnd", "XShapeRect_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XShapeR[0]
EndFunc   ;==>XShapeRect_Create

Func XShapeRect_SetBorderColor($_hShape, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeRect_SetBorderColor", "hwnd", $_hShape, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeRect_SetBorderColor

Func XShapeRect_SetFillColor($_hShape, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeRect_SetFillColor", "hwnd", $_hShape, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeRect_SetFillColor

Func XShapeRect_SetRoundAngle($_hShape, $_nwidth, $_nHeight)
	DllCall($_xcdll, "none", "XShapeRect_SetRoundAngle", "hwnd", $_hShape, "int", $_nwidth, "int", $_nHeight)
EndFunc   ;==>XShapeRect_SetRoundAngle

Func XShapePic_GetLayoutHeight($_hShape, $_pType, $_pHeight)
	DllCall($_xcdll, "none", "XShapePic_GetLayoutHeight", "hwnd", $_hShape, "int", $_pType, "int", $_pHeight)
EndFunc

Func XShapeRect_EnableBorder($_hShape, $_bEnable)
	DllCall($_xcdll, "none", "XShapeRect_EnableBorder", "hwnd", $_hShape, "bool", $_bEnable)
EndFunc   ;==>XShapeRect_EnableBorder

Func XShapeRect_EnableFill($_hShape, $_bEnable)
	DllCall($_xcdll, "none", "XShapeRect_EnableFill", "hwnd", $_hShape, "bool", $_bEnable)
EndFunc   ;==>XShapeRect_EnableFill

Func XShapeRect_EnableRoundAngle($_hShape, $_bEnable)
	DllCall($_xcdll, "none", "XShapeRect_EnableRoundAngle", "hwnd", $_hShape, "bool", $_bEnable)
EndFunc   ;==>XShapeRect_EnableRoundAngle
;=================ShapeRect-矩形形状对象结束=======================
;=================ShapeEllipse-圆形(形状对象)开始=======================
Func XShapeEllipse_Create($_x, $_y, $_width, $_height, $_hparent)
	$_XShapeE = DllCall($_xcdll, "hwnd", "XShapeEllipse_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "hwnd", $_hparent)
	Return $_XShapeE[0]
EndFunc   ;==>XShapeEllipse_Create

Func XShapeEllipse_SetBorderColor($_hShape, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeEllipse_SetBorderColor", "hwnd", $_hShape, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeEllipse_SetBorderColor

Func XShapeEllipse_SetFillColor($_hShape, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeEllipse_SetFillColor", "hwnd", $_hShape, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeEllipse_SetFillColor

Func XShapeEllipse_EnableBorder($_hShape, $_bEnable)
	DllCall($_xcdll, "none", "XShapeEllipse_EnableBorder", "hwnd", $_hShape, "bool", $_bEnable)
EndFunc   ;==>XShapeEllipse_EnableBorder

Func XShapeEllipse_EnableFill($_hShape, $_bEnable)
	DllCall($_xcdll, "none", "XShapeEllipse_EnableFill", "hwnd", $_hShape, "bool", $_bEnable)
EndFunc   ;==>XShapeEllipse_EnableFill
;=================ShapeEllipse-圆形(形状对象)结束=======================
;=================ShapeGroupBox-组框(形状对象)开始=======================
Func XShapeGroupBox_Create($_x, $_y, $_width, $_height, $_pName, $_hparent)
	$_XShapeG = DllCall($_xcdll, "hwnd", "XShapeGroupBox_Create", "int", $_x, "int", $_y, "int", $_width, "int", $_height, "wstr", $_pName, "hwnd", $_hparent)
	Return $_XShapeG[0]
EndFunc   ;==>XShapeGroupBox_Create

Func XShapeGroupBox_SetBorderColor($_hShape, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeGroupBox_SetBorderColor", "hwnd", $_hShape, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeGroupBox_SetBorderColor

Func XShapeGroupBox_SetTextColor($_hShape, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeGroupBox_SetTextColor", "hwnd", $_hShape, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeGroupBox_SetTextColor

Func XShapeGroupBox_SetFontX($_hShape, $_hFontx)
	DllCall($_xcdll, "none", "XShapeGroupBox_SetFontX", "hwnd", $_hShape, "hwnd", $_hFontx)
EndFunc   ;==>XShapeGroupBox_SetFontX

Func XShapeGroupBox_SetTextOffset($_hShape, $_offsetX, $_offsetY)
	DllCall($_xcdll, "none", "XShapeGroupBox_SetTextOffset", "hwnd", $_hShape, "int", $_offsetX, "int", $_offsetY)
EndFunc   ;==>XShapeGroupBox_SetTextOffset

Func XShapeGroupBox_SetRoundAngle($_hShape, $_nwidth, $_nHeight)
	DllCall($_xcdll, "none", "XShapeGroupBox_SetRoundAngle", "hwnd", $_hShape, "int", $_nwidth, "int", $_nHeight)
EndFunc   ;==>XShapeGroupBox_SetRoundAngle

Func XShapeGroupBox_SetText($_hShape, $_pText)
	DllCall($_xcdll, "none", "XShapeGroupBox_SetText", "hwnd", $_hShape, "wstr", $_pText)
EndFunc   ;==>XShapeGroupBox_SetText

Func XShapeGroupBox_GetTextOffset($_hShape, $_offsetX, $_offsetY)
	DllCall($_xcdll, "none", "XShapeGroupBox_GetTextOffset", "hwnd", $_hShape, "int", $_offsetX, "int", $_offsetY)
EndFunc   ;==>XShapeGroupBox_GetTextOffset

Func XShapeGroupBox_GetRoundAngle($_hShape, $_nwidth, $_nHeight)
	DllCall($_xcdll, "none", "XShapeGroupBox_GetRoundAngle", "hwnd", $_hShape, "int", $_nwidth, "int", $_nHeight)
EndFunc   ;==>XShapeGroupBox_GetRoundAngle

Func XShapeGroupBox_EnableRoundAngle($_hShape, $_bEnable)
	DllCall($_xcdll, "none", "XShapeGroupBox_EnableRoundAngle", "hwnd", $_hShape, "bool", $_bEnable)
EndFunc   ;==>XShapeGroupBox_EnableRoundAngle
;=================ShapeGroupBox-组框(形状对象)结束=======================
;=================ShapeLine-直线(形状对象)开始=======================
Func XShapeLine_Create($_x1, $_y1, $_x2, $_y2, $_hparent)
	$_XShapeL = DllCall($_xcdll, "hwnd", "XShapeLine_Create", "int", $_x1, "int", $_y1, "int", $_x2, "int", $_y2, "hwnd", $_hparent)
	Return $_XShapeL[0]
EndFunc   ;==>XShapeLine_Create

Func XShapeLine_SetPosition($_hShape, $_x1, $_y1, $_x2, $_y2)
	DllCall($_xcdll, "none", "XShapeLine_SetPosition", "hwnd", $_hShape, "int", $_x1, "int", $_y1, "int", $_x2, "int", $_y2)
EndFunc   ;==>XShapeLine_SetPosition

Func XShapeLine_SetColor($_hShape, $_color, $_alpha)
	DllCall($_xcdll, "none", "XShapeLine_SetColor", "hwnd", $_hShape, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XShapeLine_SetColor
;=================ShapeLine-直线(形状对象)结束=======================
;=================BkInfoManager-背景内容管理器开始=======================
Func XBkInfoM_Create()
	$_XBkInfoM = DllCall($_xcdll, "hwnd", "XBkInfoM_Create")
	Return $_XBkInfoM[0]
EndFunc   ;==>XBkInfoM_Create

Func XBkInfoM_Destroy($_hBkInfoM)
	DllCall($_xcdll, "none", "XBkInfoM_Destroy", "hwnd", $_hBkInfoM)
EndFunc   ;==>XBkInfoM_Destroy

Func XBkInfoM_SetBkInfo($_hBkInfoM, $_pText)
	$_XBkInfoM = DllCall($_xcdll, "int", "XBkInfoM_SetBkInfo", "hwnd", $_hBkInfoM, "wstr", $_pText)
	Return $_XBkInfoM[0]
EndFunc   ;==>XBkInfoM_SetBkInfo

Func XBkInfoM_AddBorder($_hBkInfoM, $_nState, $_color, $_alpha, $_width)
	DllCall($_xcdll, "none", "XBkInfoM_AddBorder", "hwnd", $_hBkInfoM, "int", $_nState, "int", $_color, "byte", $_alpha, "int", $_width)
EndFunc   ;==>XBkInfoM_AddBorder

Func XBkInfoM_AddFill($_hBkInfoM, $_nState, $_color, $_alpha)
	DllCall($_xcdll, "none", "XBkInfoM_AddFill", "hwnd", $_hBkInfoM, "int", $_nState, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XBkInfoM_AddFill

Func XBkInfoM_AddImage($_hBkInfoM, $_nState, $_hImage)
	DllCall($_xcdll, "none", "XBkInfoM_AddImage", "hwnd", $_hBkInfoM, "int", $_nState, "hwnd", $_hImage)
EndFunc   ;==>XBkInfoM_AddImage

Func XBkInfoM_GetCount($_hBkInfoM)
	$_XBkInfoM = DllCall($_xcdll, "int", "XBkInfoM_GetCount", "hwnd", $_hBkInfoM)
	Return $_XBkInfoM[0]
EndFunc   ;==>XBkInfoM_GetCount

Func XBkInfoM_Clear($_hBkInfoM)
	DllCall($_xcdll, "none", "XBkInfoM_Clear", "hwnd", $_hBkInfoM)
EndFunc   ;==>XBkInfoM_Clear

Func XBkInfoM_Draw($_hBkInfoM, $_nState, $_hDraw, $_pRect)
	$_XBkInfoM = DllCall($_xcdll, "bool", "XBkInfoM_Draw", "hwnd", $_hBkInfoM, "int", $_nState, "int", $_hDraw, "int", $_pRect)
	Return $_XBkInfoM[0]
EndFunc   ;==>XBkInfoM_Draw

Func XBkInfoM_DrawEx($_hBkInfoM, $_nState, $_hDraw, $_pRect, $_nStateFilter)
	$_XBkInfoM = DllCall($_xcdll, "bool", "XBkInfoM_DrawEx", "hwnd", $_hBkInfoM, "int", $_nState, "int", $_hDraw, "int", $_pRect, "int", $_nStateFilter)
	Return $_XBkInfoM[0]
EndFunc   ;==>XBkInfoM_DrawEx
;=================BkInfoManager-背景内容管理器结束=======================
;=================Draw-图形绘制开始=======================
Func XDraw_Create($_hdc)
	$_XDraw = DllCall($_xcdll, "hwnd", "XDraw_Create", "hwnd", $_hdc)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_Create

Func XDraw_Destroy($_hDraw)
	DllCall($_xcdll, "none", "XDraw_Destroy", "hwnd", $_hDraw)
EndFunc   ;==>XDraw_Destroy

Func XDraw_SetOffset($_hDraw, $_x, $_y)
	DllCall($_xcdll, "none", "XDraw_SetOffset", "hwnd", $_hDraw, "int", $_x, "int", $_y)
EndFunc   ;==>XDraw_SetOffset

Func XDraw_GetOffset($_hDraw, $_x, $_y)
	DllCall($_xcdll, "none", "XDraw_SetOffset", "hwnd", $_hDraw, "int", $_x, "int", $_y)
EndFunc   ;==>XDraw_GetOffset

Func XDraw_RestoreGDIOBJ($_hDraw)
	DllCall($_xcdll, "none", "XDraw_RestoreGDIOBJ", "hwnd", $_hDraw)
EndFunc   ;==>XDraw_RestoreGDIOBJ

Func XDraw_GetHDC($_hDraw)
	$_XDraw = DllCall($_xcdll, "hwnd", "XDraw_GetHDC", "hwnd", $_hDraw)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_GetHDC

Func XDraw_SetBrushColor($_hDraw, $_color, $_alpha)
	DllCall($_xcdll, "none", "XDraw_SetBrushColor", "hwnd", $_hDraw, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XDraw_SetBrushColor

Func XDraw_SetTextVertical($_hDraw, $_bVertical)
	DllCall($_xcdll, "none", "XDraw_SetTextVertical", "hwnd", $_hDraw, "bool", $_bVertical)
EndFunc   ;==>XDraw_SetTextVertical

Func XDraw_SetTextAlign($_hDraw, $_nFlag)
	DllCall($_xcdll, "none", "XDraw_SetTextAlign", "hwnd", $_hDraw, "int", $_nFlag)
EndFunc   ;==>XDraw_SetTextAlign

Func XDraw_SetFontX($_hDraw, $_hFontx)
	DllCall($_xcdll, "none", "XDraw_SetFontX", "hwnd", $_hDraw, "hwnd", $_hFontx)
EndFunc   ;==>XDraw_SetFontX

Func XDraw_SetFont($_hDraw, $_size)
	DllCall($_xcdll, "none", "XDraw_SetFont", "hwnd", $_hDraw, "int", $_size)
EndFunc   ;==>XDraw_SetFont

Func XDraw_SetFont2($_hDraw, $_pName, $_size)
	DllCall($_xcdll, "none", "XDraw_SetFont2", "hwnd", $_hDraw, "wstr", $_pName, "int", $_size)
EndFunc   ;==>XDraw_SetFont2

Func XDraw_SetFont3($_hDraw, $_pLogFont)
	DllCall($_xcdll, "none", "XDraw_SetFont3", "hwnd", $_hDraw, "hwnd", $_pLogFont)
EndFunc   ;==>XDraw_SetFont3

Func XDraw_SetLineWidth($_hDraw, $_nwidth)
	DllCall($_xcdll, "none", "XDraw_SetLineWidth", "hwnd", $_hDraw, "int", $_nwidth)
EndFunc   ;==>XDraw_SetLineWidth

Func XDraw_SetBkMode($_hDraw, $_bTransparent)
	$_XDraw = DllCall($_xcdll, "int", "XDraw_SetBkMode", "hwnd", $_hDraw, "bool", $_bTransparent)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_SetBkMode

Func XDraw_EnableSmoothingMode($_hDraw, $_bEnable)
	DllCall($_xcdll, "none", "XDraw_EnableSmoothingMode", "hwnd", $_hDraw, "bool", $_bEnable)
EndFunc   ;==>XDraw_EnableSmoothingMode

Func XDraw_CreateSolidBrush($_hDraw, $_crColor)
	$_XDraw = DllCall($_xcdll, "hwnd", "XDraw_CreateSolidBrush", "hwnd", $_hDraw, "int", $_crColor)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_CreateSolidBrush

Func XDraw_CreatePen($_hDraw, $_fnPenStyle, $_nwidth, $_crColor)
	$_XDraw = DllCall($_xcdll, "hwnd", "XDraw_CreatePen", "hwnd", $_hDraw, "int", $_fnPenStyle, "int", $_nwidth, "int", $_crColor)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_CreatePen

Func XDraw_CreateRectRgn($_hDraw, $_nLeftRect, $_nTopRect, $_nRightRect, $_nBottomRect)
	$_XDraw = DllCall($_xcdll, "hwnd", "XDraw_CreateRectRgn", "hwnd", $_hDraw, "int", $_nLeftRect, "int", $_nTopRect, "int", $_nRightRect, "int", $_nBottomRect)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_CreateRectRgn

Func XDraw_CreateRoundRectRgn($_hDraw, $_nLeftRect, $_nTopRect, $_nRightRect, $_nBottomRect, $_nWidthEllipse, $_nHeightEllipse)
	$_XDraw = DllCall($_xcdll, "hwnd", "XDraw_CreateRoundRectRgn", "hwnd", $_hDraw, "int", $_nLeftRect, "int", $_nTopRect, "int", $_nRightRect, "int", $_nBottomRect, "int", $_nWidthEllipse, "int", $_nHeightEllipse)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_CreateRoundRectRgn

Func XDraw_CreatePolygonRgn($_hDraw, $_pPt, $_cPoints, $_fnPolyFillMode)
	$_XDraw = DllCall($_xcdll, "hwnd", "XDraw_CreatePolygonRgn", "hwnd", $_hDraw, "int", $_pPt, "int", $_cPoints, "int", $_fnPolyFillMode)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_CreatePolygonRgn

Func XDraw_SelectClipRgn($_hDraw, $_pRect)
	$_XDraw = DllCall($_xcdll, "int", "XDraw_SelectClipRgn", "hwnd", $_hDraw, "hwnd", $_pRect)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_SelectClipRgn

Func XDraw_FillRectColor($_hDraw, $_pRect, $_color, $_alpha)
	DllCall($_xcdll, "none", "XDraw_FillRectColor", "hwnd", $_hDraw, "ptr", $_pRect, "int", $_color, "byte", $_alpha)
EndFunc   ;==>XDraw_FillRectColor

Func XDraw_FillRect($_hDraw, $_pRect)
	DllCall($_xcdll, "none", "XDraw_FillRect", "hwnd", $_hDraw, "ptr", $_pRect)
EndFunc 

Func XDraw_FillRgn($_hDraw, $_hrgn, $_hbr)
	$_XDraw = DllCall($_xcdll, "bool", "XDraw_FillRgn", "hwnd", $_hDraw, "hwnd", $_hrgn, "hwnd", $_hbr)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_FillRgn

Func XDraw_FillEllipse($_hDraw, $_pRect)
	DllCall($_xcdll, "none", "XDraw_FillEllipse", "hwnd", $_hDraw, "int", $_pRect)
EndFunc   ;==>XDraw_FillEllipse

Func XDraw_DrawEllipse($_hDraw, $_pRect)
	DllCall($_xcdll, "none", "XDraw_DrawEllipse", "hwnd", $_hDraw, "int", $_pRect)
EndFunc   ;==>XDraw_DrawEllipse

Func XDraw_FillRoundRect($_hDraw, $_pRect, $_nwidth, $_nHeight)
	DllCall($_xcdll, "none", "XDraw_FillRoundRect", "hwnd", $_hDraw, "int", $_pRect, "int", $_nwidth, "int", $_nHeight)
EndFunc   ;==>XDraw_FillRoundRect

Func XDraw_DrawRoundRect($_hDraw, $_pRect, $_nwidth, $_nHeight)
	DllCall($_xcdll, "none", "XDraw_DrawRoundRect", "hwnd", $_hDraw, "int", $_pRect, "int", $_nwidth, "int", $_nHeight)
EndFunc   ;==>XDraw_DrawRoundRect

Func XDraw_Rectangle($_hDraw, $_nLeftRect, $_nTopRect, $_nRightRect, $_nBottomRect)
	$_XDraw = DllCall($_xcdll, "bool", "XDraw_Rectangle", "hwnd", $_hDraw, "int", $_nLeftRect, "int", $_nTopRect, "int", $_nRightRect, "int", $_nBottomRect)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_Rectangle

Func XDraw_DrawGroupBox_Rect($_hDraw, $_pRect, $_pName, $_textColor, $_textAlpha, $_pOffset)
	DllCall($_xcdll, "none", "XDraw_DrawGroupBox_Rect", "hwnd", $_hDraw, "int", $_pRect, "wstr", $_pName, "int", $_textColor, "byte", $_textAlpha, "int", $_pOffset)
EndFunc   ;==>XDraw_DrawGroupBox_Rect

Func XDraw_DrawGroupBox_RoundRect($_hDraw, $_pRect, $_pName, $_textColor, $_textAlpha, $_pOffset, $_nwidth, $_nHeight)
	DllCall($_xcdll, "none", "XDraw_DrawGroupBox_RoundRect", "hwnd", $_hDraw, "int", $_pRect, "wstr", $_pName, "int", $_textColor, "byte", $_textAlpha, "int", $_pOffset, "int", $_nwidth, "int", $_nHeight)
EndFunc   ;==>XDraw_DrawGroupBox_RoundRect

Func XDraw_GradientFill2($_hDraw, $_color1, $_alpha1, $_color2, $_alpha2, $_pRect, $_mode)
	DllCall($_xcdll, "none", "XDraw_GradientFill2", "hwnd", $_hDraw, "int", $_color1, "byte", $_alpha1, "int", $_color2, "byte", $_alpha2, "int", $_pRect, "int", $_mode)
EndFunc   ;==>XDraw_GradientFill2

Func XDraw_GradientFill4($_hDraw, $_color1, $_color2, $_color3, $_color4, $_pRect, $_mode)
	$_XDraw = DllCall($_xcdll, "bool", "XDraw_GradientFill4", "hwnd", $_hDraw, "int", $_color1, "int", $_color2, "int", $_color3, "int", $_color4, "int", $_pRect, "int", $_mode)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_GradientFill4

Func XDraw_FrameRgn($_hDraw, $_hrgn, $_hbr, $_nwidth, $_nHeight)
	$_XDraw = DllCall($_xcdll, "bool", "XDraw_FrameRgn", "hwnd", $_hDraw, "hwnd", $_hrgn, "hwnd", $_hbr, "int", $_nwidth, "int", $_nHeight)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_FrameRgn

Func XDraw_FrameRect($_hDraw, $_pRect)
	DllCall($_xcdll, "none", "XDraw_FrameRect", "hwnd", $_hDraw, "int", $_pRect)
EndFunc   ;==>XDraw_FrameRect

Func XDraw_DrawLine($_hDraw, $_x1, $_y1, $_x2, $_y2)
	DllCall($_xcdll, "none", "XDraw_DrawLine", "hwnd", $_hDraw, "int", $_x1, "int", $_y1, "int", $_x2, "int", $_y2)
EndFunc   ;==>XDraw_DrawLine

Func XDraw_FocusRect($_hDraw, $_pRect)
	DllCall($_xcdll, "none", "XDraw_FocusRect", "hwnd", $_hDraw, "int", $_pRect)
EndFunc   ;==>XDraw_FocusRect

Func XDraw_MoveToEx($_hDraw, $_x, $_y, $_lpPoint)
	$_XDraw = DllCall($_xcdll, "bool", "XDraw_MoveToEx", "hwnd", $_hDraw, "int", $_x, "int", $_y, "int", $_lpPoint)
	Return $_XDraw[0]
EndFunc   ;==>XDraw_MoveToEx
;=================Draw-图形绘制结束=======================
;=================FontX-炫彩字体开始=======================
Func XFont_Create($_size)
	$_XFont = DllCall($_xcdll, "hwnd", "XFont_Create", "int", $_size)
	Return $_XFont[0]
EndFunc   ;==>XFont_Create

Func XFont_Create2($_pName, $_size, $_bBold, $_bItalic, $_bUnderline, $_bStrikeOut)
	$_XFont = DllCall($_xcdll, "hwnd", "XFont_Create2", "wstr", $_pName, "int", $_size, "bool", $_bBold, "bool", $_bItalic, "bool", $_bUnderline, "bool", $_bStrikeOut)
	Return $_XFont[0]
EndFunc   ;==>XFont_Create2

Func XFont_Create3($_pInfo)
	$_XFont = DllCall($_xcdll, "hwnd", "XFont_Create3", "hwnd", $_pInfo)
	Return $_XFont[0]
EndFunc   ;==>XFont_Create3

Func XFont_CreateEx($_pInfo)
	$_XFont = DllCall($_xcdll, "hwnd", "XFont_CreateEx", "hwnd", $_pInfo)
	Return $_XFont[0]
EndFunc   ;==>XFont_CreateEx

Func XFont_CreateFromHFONT($_pInfo)
	$_XFont = DllCall($_xcdll, "hwnd", "XFont_CreateFromHFONT", "hwnd", $_pInfo)
	Return $_XFont[0]
EndFunc   ;==>XFont_CreateFromHFONT

Func XFont_CreateFromFont($_pFont)
	$_XFont = DllCall($_xcdll, "hwnd", "XFont_CreateFromFont", "ptr*", $_pFont)
	Return $_XFont[0]
EndFunc   ;==>XFont_CreateFromFont

Func XFont_GetFont($_pFont)
	$_XFont = DllCall($_xcdll, "ptr", "XFont_GetFont", "hwnd", $_pFont)
	Return $_XFont[0]
EndFunc

Func XFont_GetRefCount($_hFontX)
	$_XFont = DllCall($_xcdll, "int", "XFont_GetRefCount", "hwnd", $_hFontX)
	Return $_XFont[0]
EndFunc

Func XFont_EnableAutoDestroy($_hFontx, $_bEnable)
	DllCall($_xcdll, "none", "XFont_EnableAutoDestroy", "hwnd", $_hFontx, "bool", $_bEnable)
EndFunc   ;==>XFont_EnableAutoDestroy

Func XFont_GetFontInfo($_hFontx, $_pInfo)
	DllCall($_xcdll, "none", "XFont_GetFontInfo", "hwnd", $_hFontx, "int", $_pInfo)
EndFunc

Func XFont_Release($_hFontx)
	DllCall($_xcdll, "none", "XFont_Release", "hwnd", $_hFontx)
EndFunc

Func XFont_AddRef($_hFontx)
	DllCall($_xcdll, "none", "XFont_AddRef", "hwnd", $_hFontx)
EndFunc

Func XFont_Destroy($_hFontx)
	DllCall($_xcdll, "none", "XFont_Destroy", "hwnd", $_hFontx)
EndFunc   ;==>XFont_Destroy
;=================FontX-炫彩字体结束=======================
;=================Image-图片操作开始=======================
Func XImage_LoadFile($_pImageName, $_bStretch)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadFile", "wstr", $_pImageName, "bool", $_bStretch)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadFile

Func XImage_LoadFileAdaptive($_pImageName, $_leftSize, $_topSize, $_rightSize, $_bottomSize)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadFileAdaptive", "wstr", $_pImageName, "int", $_leftSize, "int", $_topSize, "int", $_rightSize, "int", $_bottomSize)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadFileAdaptive

Func XImage_LoadFileRect($_pImageName, $_x, $_y, $_nwidth, $_nHeight)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadFileRect", "wstr", $_pImageName, "int", $_x, "int", $_y, "int", $_nwidth, "int", $_nHeight)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadFileRect

Func XImage_LoadResAdaptive($_pImageName, $_leftSize, $_topSize, $_rightSize, $_bottomSize)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadResAdaptive", "wstr", $_pImageName, "int", $_leftSize, "int", $_topSize, "int", $_rightSize, "int", $_bottomSize)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadResAdaptive

Func XImage_LoadRes($_id, $_pType, $_bStretch)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadRes", "int", $_id, "wstr", $_pType, "bool", $_bStretch)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadRes

Func XImage_LoadZip($_pZipFileName, $_pImageName, $_pPassword, $_bStretch)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadZip", "wstr", $_pZipFileName, "wstr", $_pImageName, "wstr", $_pPassword, "bool", $_bStretch)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadZip

Func XImage_LoadZipAdaptive($_pZipFileName, $_pImageName, $_pPassword, $_x1, $_x2, $_y1, $_y2)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadZipAdaptive", "wstr", $_pZipFileName, "wstr", $_pImageName, "wstr", $_pPassword, "int", $_x1, "int", $_x2, "int", $_y1, "int", $_y2)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadZipAdaptive

Func XImage_LoadZipRect($_pZipFileName, $_pImageName, $_pPassword, $_x, $_y, $_nwidth, $_nHeight)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadZipRect", "wstr", $_pZipFileName, "wstr", $_pImageName, "wstr", $_pPassword, "int", $_x, "int", $_y, "int", $_nwidth, "int", $_nHeight)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadZipRect

Func XImage_LoadMemory($_pBuffer, $_nSize, $_bStretch)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadMemory", "ptr", $_pBuffer, "int", $_nSize, "bool", $_bStretch)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadMemory

Func XImage_LoadMemoryRect($_pBuffer, $_nSize, $_x, $_y, $_nwidth, $_nHeight)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadMemoryRect", "ptr", $_pBuffer, "int", $_nSize, "int", $_x, "int", $_y, "int", $_nwidth, "int", $_nHeight)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadMemoryRect

Func XImage_LoadMemoryAdaptive($_pBuffer, $_nSize, $_leftSize, $_topSize, $_rightSize, $_bottomSize)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadMemoryAdaptive", "ptr", $_pBuffer, "int", $_nSize, "int", $_leftSize, "int", $_topSize, "int", $_rightSize, "int", $_bottomSize)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadMemoryAdaptive

Func XImage_LoadFromImage($_pImage)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadFromImage", "ptr", $_pImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadFromImage

Func XImage_GetRefCount($_hImage)
	$_XImage = DllCall($_xcdll, "int", "XImage_GetRefCount", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc

Func XImage_AddRef($_hImage)
	DllCall($_xcdll, "none", "XImage_AddRef", "hwnd", $_hImage)
EndFunc

Func XImage_LoadFileFromExtractIcon($_pImageName)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadFileFromExtractIcon", "wstr", $_pImageName)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadFileFromExtractIcon

Func XImage_LoadFileFromHICON($_hIcon)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadFileFromHICON", "hwnd", $_hIcon)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadFileFromHICON

Func XImage_LoadFileFromHBITMAP($_hBitmap)
	$_XImage = DllCall($_xcdll, "HWnd", "XImage_LoadFileFromHBITMAP", "hwnd", $_hBitmap)
	Return $_XImage[0]
EndFunc   ;==>XImage_LoadFileFromHBITMAP

Func XImage_IsStretch($_hImage)
	$_XImage = DllCall($_xcdll, "bool", "XImage_IsStretch", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_IsStretch

Func XImage_IsAdaptive($_hImage)
	$_XImage = DllCall($_xcdll, "bool", "XImage_IsAdaptive", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_IsAdaptive

Func XImage_IsTile($_hImage)
	$_XImage = DllCall($_xcdll, "bool", "XImage_IsTile", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_IsTile

Func XImage_SetDrawType($_hImage, $_nType)
	$_XImage = DllCall($_xcdll, "bool", "XImage_IsTile", "hwnd", $_hImage, "int", $_nType)
	Return $_XImage[0]
EndFunc   ;==>XImage_SetDrawType

Func XImage_SetDrawTypeAdaptive($_hImage, $_leftSize, $_topSize, $_rightSize, $_bottomSize)
	$_XImage = DllCall($_xcdll, "bool", "XImage_SetDrawTypeAdaptive", "hwnd", $_hImage, "int", $_leftSize, "int", $_topSize, "int", $_rightSize, "int", $_bottomSize)
	Return $_XImage[0]
EndFunc   ;==>XImage_SetDrawTypeAdaptive

Func XImage_SetTranColor($_hImage, $_color)
	DllCall($_xcdll, "none", "XImage_SetTranColor", "hwnd", $_hImage, "int", $_color)
EndFunc   ;==>XImage_SetTranColor

Func XImage_SetTranColorEx($_hImage, $_color, $_tranColor)
	DllCall($_xcdll, "none", "XImage_SetTranColorEx", "hwnd", $_hImage, "int", $_color, "byte", $_tranColor)
EndFunc   ;==>XImage_SetTranColorEx

Func XImage_SetRotateAngle($_hImage, $_fAngle)
	$_XImage = DllCall($_xcdll, "int", "XImage_SetRotateAngle", "hwnd", $_hImage, "int", $_fAngle)
	Return $_XImage[0]
EndFunc   ;==>XImage_SetRotateAngle

Func XImage_EnableTranColor($_hImage, $_bEnable)
	DllCall($_xcdll, "none", "XImage_EnableTranColor", "hwnd", $_hImage, "bool", $_bEnable)
EndFunc   ;==>XImage_EnableTranColor

Func XImage_EnableAutoDestroy($_hImage, $_bEnable)
	DllCall($_xcdll, "none", "XImage_EnableAutoDestroy", "hwnd", $_hImage, "bool", $_bEnable)
EndFunc   ;==>XImage_EnableAutoDestroy

Func XImage_EnableCenter($_hImage, $_bEnable)
	DllCall($_xcdll, "none", "XImage_EnableCenter", "hwnd", $_hImage, "bool", $_bEnable)
EndFunc   ;==>XImage_EnableCenter

Func XImage_IsCenter($_hImage)
	$_XImage = DllCall($_xcdll, "bool", "XImage_IsCenter", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_IsCenter

Func XImage_GetDrawType($_hImage)
	$_XImage = DllCall($_xcdll, "int", "XImage_GetDrawType", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_GetDrawType

Func XImage_GetWidth($_hImage)
	$_XImage = DllCall($_xcdll, "int", "XImage_GetWidth", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_GetWidth

Func XImage_GetHeight($_hImage)
	$_XImage = DllCall($_xcdll, "int", "XImage_GetHeight", "hwnd", $_hImage)
	Return $_XImage[0]
EndFunc   ;==>XImage_GetHeight

Func XImage_Release($_hImage)
	DllCall($_xcdll, "none", "XImage_Release", "hwnd", $_hImage)
EndFunc   ;==>XImage_Release

Func XImage_Destroy($_hImage)
	DllCall($_xcdll, "none", "XImage_Destroy", "hwnd", $_hImage)
EndFunc   ;==>XImage_Destroy
;=================Image-图片操作结束=======================
;=================LayoutObject-布局对象开始=======================
Func XLayout_Create()
	$_XLayout = DllCall($_xcdll, "HWnd", "XLayout_Create")
	Return $_XLayout[0]
EndFunc   ;==>XLayout_Create

Func XLayout_Destroy($_hLayout)
	DllCall($_xcdll, "none", "XLayout_Destroy", "int", $_hLayout)
EndFunc   ;==>XLayout_Destroy

Func XLayout_AddEle($_hLayout, $_hEle)
	DllCall($_xcdll, "none", "XLayout_AddEle", "int", $_hLayout, "hwnd", $_hEle)
EndFunc   ;==>XLayout_AddEle

Func XLayout_AddLayoutObject($_hLayout, $_hLayoutObject)
	DllCall($_xcdll, "none", "XLayout_AddLayoutObject", "int", $_hLayout, "int", $_hLayoutObject)
EndFunc   ;==>XLayout_AddLayoutObject

Func XLayout_AddShape($_hLayout, $_hShape)
	DllCall($_xcdll, "none", "XLayout_AddShape", "int", $_hLayout, "int", $_hShape)
EndFunc   ;==>XLayout_AddShape

Func XLayout_Add($_hLayout, $_hChild)
	$_XLayout = DllCall($_xcdll, "bool", "XLayout_Add", "int", $_hLayout, "int", $_hChild)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_Add

Func XLayout_Insert($_hLayout, $_hChild, $_index)
	$_XLayout = DllCall($_xcdll, "bool", "XLayout_Insert", "int", $_hLayout, "int", $_hChild, "int", $_index)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_Insert

Func XLayout_RemoveLayout($_hLayout)
	DllCall($_xcdll, "none", "XLayout_RemoveLayout", "int", $_hLayout)
EndFunc   ;==>XLayout_RemoveLayout

Func XLayout_RemoveChild($_hLayout, $_hChild)
	DllCall($_xcdll, "none", "XLayout_RemoveChild", "int", $_hLayout, "int", $_hChild)
EndFunc   ;==>XLayout_RemoveChild

Func XLayout_GetZOrder($_hLayout, $_hChild)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetZOrder", "int", $_hLayout, "int", $_hChild)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetZOrder

Func XLayout_AdjustLayout($_hLayout)
	DllCall($_xcdll, "none", "XLayout_AdjustLayout", "int", $_hLayout)
EndFunc   ;==>XLayout_AdjustLayout

Func XLayout_GetEle($_hLayout)
	$_XLayout = DllCall($_xcdll, "hwnd", "XLayout_GetEle", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetEle

Func XLayout_GetParentLayout($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetParentLayout", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetParentLayout

Func XLayout_GetParent($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetParent", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetParent

Func XLayout_GetWindow($_hLayout)
	$_XLayout = DllCall($_xcdll, "hwnd", "XLayout_GetWindow", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetWindow

Func XLayout_SetID($_hLayout, $_nID)
	DllCall($_xcdll, "none", "XLayout_RemoveChild", "int", $_hLayout, "int", $_nID)
EndFunc   ;==>XLayout_SetID

Func XLayout_GetID($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetID", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetID

Func XLayout_SetHorizon($_hLayout, $_bHorizon)
	DllCall($_xcdll, "none", "XLayout_SetHorizon", "int", $_hLayout, "bool", $_bHorizon)
EndFunc   ;==>XLayout_SetHorizon

Func XLayout_SetRectFrame($_hLayout, $_pRect)
	DllCall($_xcdll, "none", "XLayout_SetRectFrame", "int", $_hLayout, "int", $_pRect)
EndFunc   ;==>XLayout_SetRectFrame

Func XLayout_GetRect($_hLayout, $_pRect)
	DllCall($_xcdll, "none", "XLayout_GetRect", "int", $_hLayout, "int", $_pRect)
EndFunc   ;==>XLayout_GetRect

Func XLayout_GetRectFrame($_hLayout, $_pRect)
	DllCall($_xcdll, "none", "XLayout_GetRectFrame", "int", $_hLayout, "int", $_pRect)
EndFunc   ;==>XLayout_GetRectFrame

Func XLayout_SetAlignH($_hLayout, $_nAlign)
	DllCall($_xcdll, "none", "XLayout_SetAlignH", "int", $_hLayout, "int", $_nAlign)
EndFunc   ;==>XLayout_SetAlignH

Func XLayout_SetAlignV($_hLayout, $_nAlign)
	DllCall($_xcdll, "none", "XLayout_SetAlignV", "int", $_hLayout, "int", $_nAlign)
EndFunc   ;==>XLayout_SetAlignV

Func XLayout_GetContentSize($_hLayout, $_pSize)
	DllCall($_xcdll, "none", "XLayout_GetContentSize", "int", $_hLayout, "int", $_pSize)
EndFunc

Func XLayout_SetPadding($_hLayout, $_leftSize, $_topSize, $_rightSize, $_bottomSize)
	DllCall($_xcdll, "none", "XLayout_SetPadding", "int", $_hLayout, "int", $_leftSize, "int", $_topSize, "int", $_rightSize, "int", $_bottomSize)
EndFunc   ;==>XLayout_SetPadding

Func XLayout_SetLayoutWidth($_hLayout, $_nType, $_nwidth)
	DllCall($_xcdll, "none", "XLayout_SetLayoutWidth", "int", $_hLayout, "int", $_nType, "int", $_nwidth)
EndFunc   ;==>XLayout_SetLayoutWidth

Func XLayout_GetLayoutWidth($_hLayout, $_pType, $_pwidth)
	DllCall($_xcdll, "none", "XLayout_GetLayoutWidth", "int", $_hLayout, "int", $_pType, "int", $_pwidth)
EndFunc 

Func XLayout_GetLayoutHeight($_hLayout, $_pType, $_pHeight)
	DllCall($_xcdll, "none", "XLayout_GetLayoutHeight", "int", $_hLayout, "int", $_pType, "int", $_pHeight)
EndFunc 

Func XLayout_SetLayoutHeight($_hLayout, $_nType, $_nHeight)
	DllCall($_xcdll, "none", "XLayout_SetLayoutHeight", "int", $_hLayout, "int", $_nType, "int", $_nHeight)
EndFunc   ;==>XLayout_SetLayoutHeight

Func XLayout_SetSpace($_hLayout, $_nSpace)
	DllCall($_xcdll, "none", "XLayout_SetSpace", "int", $_hLayout, "int", $_nSpace)
EndFunc   ;==>XLayout_SetSpace

Func XLayout_GetWidth($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetWidth", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetWidth

Func XLayout_GetHeight($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetHeight", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetHeight

Func XLayout_GetWidthIn($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetWidthIn", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetWidthIn

Func XLayout_GetHeightIn($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetHeightIn", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetHeightIn

Func XLayout_ShowLayout($_hLayout, $_bShow)
	DllCall($_xcdll, "none", "XLayout_ShowLayout", "int", $_hLayout, "bool", $_bShow)
EndFunc   ;==>XLayout_ShowLayout

Func XLayout_GetChildCount($_hLayout)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetChildCount", "int", $_hLayout)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetChildCount

Func XLayout_GetChildType($_hLayout, $_index)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetChildType", "int", $_hLayout, "int", $_index)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetChildType

Func XLayout_GetChild($_hLayout, $_index)
	$_XLayout = DllCall($_xcdll, "int", "XLayout_GetChild", "int", $_hLayout, "int", $_index)
	Return $_XLayout[0]
EndFunc   ;==>XLayout_GetChild

Func XLayout_Draw($_hLayout, $_hDraw)
	DllCall($_xcdll, "none", "XLayout_Draw", "int", $_hLayout, "hwnd", $_hDraw)
EndFunc   ;==>XLayout_Draw
;=================LayoutObject-布局对象结束=======================
;=================AdapterListView-数据适配器-列表视元素开始====================
Func XAdapterListView_Create()
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Create")
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Create

Func XAdapterListView_Group_AddColumn($_hAdapter, $_pName)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Group_AddColumn", "int", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_AddColumn

Func XAdapterListView_Group_AddItemText($_hAdapter, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Group_AddItemText", "int", $_hAdapter, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_AddItemText

Func XAdapterListView_Group_AddItemTextEx($_hAdapter, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Group_AddItemTextEx", "int", $_hAdapter, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_AddItemTextEx

Func XAdapterListView_Group_AddItemImage($_hAdapter, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Group_AddItemImage", "int", $_hAdapter, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_AddItemImage

Func XAdapterListView_Group_AddItemImageEx($_hAdapter, $_pName, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Group_AddItemImageEx", "int", $_hAdapter, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_AddItemImageEx

Func XAdapterListView_Group_SetText($_hAdapter, $_iGroup, $_iColumn, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Group_SetText", "int", $_hAdapter, "int", $_iGroup, "int", $_iColumn, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_SetText

Func XAdapterListView_Group_SetTextEx($_hAdapter, $_iGroup, $_pName, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Group_SetTextEx", "int", $_hAdapter, "int", $_iGroup, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_SetTextEx

Func XAdapterListView_Group_SetImage($_hAdapter, $_iGroup, $_iColumn, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Group_SetImage", "int", $_hAdapter, "int", $_iGroup, "int", $_iColumn, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_SetImage

Func XAdapterListView_Group_SetImageEx($_hAdapter, $_iGroup, $_pName, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Group_SetImageEx", "int", $_hAdapter, "int", $_iGroup, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_SetImageEx

Func XAdapterListView_Item_AddColumn($_hAdapter, $_pName)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Item_AddColumn", "int", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_AddColumn

Func XAdapterListView_Group_GetCount($_hAdapter)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Group_GetCount", "int", $_hAdapter)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_GetCount

Func XAdapterListView_Item_GetCount($_hAdapter, $_iGroup)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Item_GetCount", "int", $_hAdapter, "int", $_iGroup)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_GetCount

Func XAdapterListView_Item_AddItemText($_hAdapter, $_iGroup, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Item_AddItemText", "int", $_hAdapter, "int", $_iGroup, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_AddItemText

Func XAdapterListView_Item_AddItemTextEx($_hAdapter, $_iGroup, $_pName, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Item_AddItemTextEx", "int", $_hAdapter, "int", $_iGroup, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_AddItemTextEx

Func XAdapterListView_Item_AddItemImage($_hAdapter, $_iGroup, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Item_AddItemImage", "int", $_hAdapter, "int", $_iGroup, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_AddItemImage

Func XAdapterListView_Item_AddItemImageEx($_hAdapter, $_iGroup, $_pName, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "int", "XAdapterListView_Item_AddItemImageEx", "int", $_hAdapter, "int", $_iGroup, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_AddItemImageEx

Func XAdapterListView_Group_DeleteItem($_hAdapter, $_iGroup)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Group_DeleteItem", "int", $_hAdapter, "int", $_iGroup)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Group_DeleteItem

Func XAdapterListView_Group_DeleteAllChildItem($_hAdapter, $_iGroup)
	DllCall($_xcdll, "none", "XAdapterListView_Group_DeleteAllChildItem", "int", $_hAdapter, "int", $_iGroup)
EndFunc   ;==>XAdapterListView_Group_DeleteAllChildItem

Func XAdapterListView_Item_DeleteItem($_hAdapter, $_iGroup, $_iItem)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Item_DeleteItem", "int", $_hAdapter, "int", $_iGroup, "int", $_iItem)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_DeleteItem

Func XAdapterListView_DeleteAll($_hAdapter)
	DllCall($_xcdll, "none", "XAdapterListView_DeleteAll", "int", $_hAdapter)
EndFunc   ;==>XAdapterListView_DeleteAll

Func XAdapterListView_DeleteAllGroup($_hAdapter)
	DllCall($_xcdll, "none", "XAdapterListView_DeleteAllGroup", "int", $_hAdapter)
EndFunc   ;==>XAdapterListView_DeleteAllGroup

Func XAdapterListView_DeleteAllItem($_hAdapter)
	DllCall($_xcdll, "none", "XAdapterListView_DeleteAllItem", "int", $_hAdapter)
EndFunc   ;==>XAdapterListView_DeleteAllItem

Func XAdapterListView_DeleteColumnGroup($_hAdapter, $_iColumn)
	DllCall($_xcdll, "none", "XAdapterListView_DeleteColumnGroup", "int", $_hAdapter, "int", $_iColumn)
EndFunc   ;==>XAdapterListView_DeleteColumnGroup

Func XAdapterListView_DeleteColumnItem($_hAdapter, $_iColumn)
	DllCall($_xcdll, "none", "XAdapterListView_DeleteColumnItem", "int", $_hAdapter, "int", $_iColumn)
EndFunc   ;==>XAdapterListView_DeleteColumnItem

Func XAdapterListView_Item_GetTextEx($_hAdapter, $_iGroup, $_iItem, $_pName, $pout,$_nOutLen)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Item_GetTextEx", "int", $_hAdapter, "int", $_iGroup, "int", $_iItem, "wstr", $_pName, "wstr",$pout,"wstr", $_nOutLen)
	Return $_XAdapterL
EndFunc   ;==>XAdapterListView_Item_GetTextEx

Func XAdapterListView_Item_GetImageEx($_hAdapter, $_iGroup, $_iItem, $_pName)
	$_XAdapterL = DllCall($_xcdll, "hwnd", "XAdapterListView_Item_GetImageEx", "int", $_hAdapter, "int", $_iGroup, "int", $_iItem, "wstr", $_pName)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_GetImageEx

Func XAdapterListView_Item_SetText($_hAdapter, $_iGroup, $_iItem, $_iColumn, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Item_SetText", "int", $_hAdapter, "int", $_iGroup, "int", $_iItem, "int", $_iColumn, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_SetText

Func XAdapterListView_Item_SetTextEx($_hAdapter, $_iGroup, $_iItem, $_pName, $_pValue)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Item_SetTextEx", "int", $_hAdapter, "int", $_iGroup, "int", $_iItem, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_SetTextEx

Func XAdapterListView_Item_SetImage($_hAdapter, $_iGroup, $_iItem, $_iColumn, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Item_SetImage", "int", $_hAdapter, "int", $_iGroup, "int", $_iItem, "int", $_iColumn, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_SetImage

Func XAdapterListView_Item_SetImageEx($_hAdapter, $_iGroup, $_iItem, $_pName, $_hImage)
	$_XAdapterL = DllCall($_xcdll, "bool", "XAdapterListView_Item_SetImageEx", "int", $_hAdapter, "int", $_iGroup, "int", $_iItem, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterL[0]
EndFunc   ;==>XAdapterListView_Item_SetImageEx
;=================AdapterListView-数据适配器-列表视元素结束====================
;=================AdapterTable-数据适配器-XList-XListBox结束====================
Func XAdapterTable_Create()
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_Create")
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_Create

Func XAdapterTable_AddColumn($_hAdapter, $_pName)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_AddColumn", "hwnd", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_AddColumn

Func XAdapterTable_SetColumn($_hAdapter, $_pName)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_SetColumn", "hwnd", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_SetColumn

Func XAdapterTable_AddItemText($_hAdapter, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_AddItemText", "hwnd", $_hAdapter, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_AddItemText

Func XAdapterTable_GetItemALLText($_hEle)
	$_ada=XList_GetAdapter($_hEle)
	$_col=XAdapterTable_GetCountColumn($_ada)
	Dim $_io
	For $_i=0 To  $_col-1
		$_text=XAdapterTable_GetItemText($_ada,XList_GetSelectItem($_hEle),$_i,50)
		$_io &=$_text[4]&"|"
	Next
	Return $_io
EndFunc

Func XAdapterTable_AddItemTextEx($_hAdapter, $_pName, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_AddItemTextEx", "hwnd", $_hAdapter, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_AddItemTextEx

Func XAdapterTable_AddItemImage($_hAdapter, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_AddItemImage", "hwnd", $_hAdapter, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_AddItemImage

Func XAdapterTable_AddItemImageEx($_hAdapter, $_pName, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_AddItemImageEx", "hwnd", $_hAdapter, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_AddItemImageEx

Func XAdapterTable_InsertItemText($_hAdapter, $_iItem, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_InsertItemText", "hwnd", $_hAdapter, "int", $_iItem, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_InsertItemText

Func XAdapterTable_InsertItemTextEx($_hAdapter, $_iItem, $_pName, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_InsertItemTextEx", "hwnd", $_hAdapter, "int", $_iItem, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_InsertItemTextEx

Func XAdapterTable_InsertItemImage($_hAdapter, $_iItem, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_InsertItemImage", "hwnd", $_hAdapter, "int", $_iItem, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_InsertItemImage

Func XAdapterTable_InsertItemImageEx($_hAdapter, $_iItem, $_pName, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_InsertItemImageEx", "hwnd", $_hAdapter, "int", $_iItem, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_InsertItemImageEx

Func XAdapterTable_SetItemText($_hAdapter, $_iItem, $_iColumn, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_SetItemText", "hwnd", $_hAdapter, "int", $_iItem, "int", $_iColumn, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_SetItemText

Func XAdapterTable_SetItemTextEx($_hAdapter, $_iItem, $_pName, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_SetItemTextEx", "hwnd", $_hAdapter, "int", $_iItem, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_SetItemTextEx

Func XAdapterTable_SetItemImage($_hAdapter, $_iItem, $_iColumn, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_SetItemImage", "hwnd", $_hAdapter, "int", $_iItem, "int", $_iColumn, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_SetItemImage

Func XAdapterTable_SetItemImageEx($_hAdapter, $_iItem, $_pName, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_SetItemImageEx", "hwnd", $_hAdapter, "int", $_iItem, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_SetItemImageEx

Func XAdapterTable_DeleteItem($_hAdapter, $_iItem)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_DeleteItem", "hwnd", $_hAdapter, "int", $_iItem)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_DeleteItem

Func XAdapterTable_DeleteItemEx($_hAdapter, $_iItem, $_nCount)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_DeleteItemEx", "hwnd", $_hAdapter, "int", $_iItem, "int", $_nCount)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_DeleteItemEx

Func XAdapterTable_DeleteItemAll($_hAdapter)
	DllCall($_xcdll, "none", "XAdapterTable_DeleteItemAll", "hwnd", $_hAdapter)
EndFunc   ;==>XAdapterTable_DeleteItemAll

Func XAdapterTable_DeleteColumnAll($_hAdapter)
	DllCall($_xcdll, "none", "XAdapterTable_DeleteColumnAll", "hwnd", $_hAdapter)
EndFunc   ;==>XAdapterTable_DeleteColumnAll

Func XAdapterTable_GetCount($_hAdapter)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_GetCount", "hwnd", $_hAdapter)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_GetCount

Func XAdapterTable_GetCountColumn($_hAdapter)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTable_GetCountColumn", "hwnd", $_hAdapter)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_GetCountColumn

Func XAdapterTable_GetItemText($_hAdapter, $_iItem, $_iColumn, $_nOutLen, $_pOut=0)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_GetItemText", "hwnd", $_hAdapter, "int", $_iItem, "int", $_iColumn, "wstr", $_pOut, "int", $_nOutLen)
	Return $_XAdapterT
EndFunc   ;==>XAdapterTable_GetItemText

Func XAdapterTable_GetItemImage($_hAdapter, $_iItem, $_nCount)
	$_XAdapterT = DllCall($_xcdll, "hwnd", "XAdapterTable_GetItemImage", "hwnd", $_hAdapter, "int", $_iItem, "int", $_nCount)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_GetItemImage

Func XAdapterTable_GetItemTextEx($_hAdapter, $_iItem, $_pName, $_nOutLen, $_pOut=0)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTable_GetItemTextEx", "hwnd", $_hAdapter, "int", $_iItem, "wstr", $_pName, "wstr", $_pOut, "int", $_nOutLen)
	Return $_XAdapterT
EndFunc   ;==>XAdapterTable_GetItemTextEx

Func XAdapterTable_GetItemImageEx($_hAdapter, $_iItem, $_pName)
	$_XAdapterT = DllCall($_xcdll, "hwnd", "XAdapterTable_GetItemImageEx", "hwnd", $_hAdapter, "int", $_iItem, "wstr", $_pName)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTable_GetItemImageEx
;=================AdapterTable-数据适配器-XList-XListBox结束====================
;=================AAdapterMap-数据适配器-单列Map开始====================
Func XAdapterMap_Create()
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterMap_Create")
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterMap_Create

Func XAdapterMap_AddItemText($_hAdapter, $_pName, $_pValue)
	$_XAdapterM = DllCall($_xcdll, "bool", "XAdapterMap_AddItemText", "int", $_hAdapter, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterM[0]
EndFunc   ;==>XAdapterMap_AddItemText

Func XAdapterMap_AddItemImage($_hAdapter, $_pName, $_hImage)
	$_XAdapterM = DllCall($_xcdll, "bool", "XAdapterMap_AddItemImage", "int", $_hAdapter, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterM[0]
EndFunc   ;==>XAdapterMap_AddItemImage

Func XAdapterMap_DeleteItem($_hAdapter, $_pName)
	$_XAdapterM = DllCall($_xcdll, "bool", "XAdapterMap_DeleteItem", "int", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterM[0]
EndFunc   ;==>XAdapterMap_DeleteItem

Func XAdapterMap_GetCount($_hAdapter)
	$_XAdapterM = DllCall($_xcdll, "int", "XAdapterMap_GetCount", "int", $_hAdapter)
	Return $_XAdapterM[0]
EndFunc   ;==>XAdapterMap_GetCount

Func XAdapterMap_GetItemText($_hAdapter, $_pName, $_pOut, $_nOutLen)
	$_XAdapterM = DllCall($_xcdll, "bool", "XAdapterMap_GetItemText", "int", $_hAdapter, "wstr", $_pName, "wstr", $_pOut, "int", $_nOutLen)
	Return $_XAdapterM
EndFunc   ;==>XAdapterMap_GetItemText

Func XAdapterMap_GetItemImage($_hAdapter, $_pName)
	$_XAdapterM = DllCall($_xcdll, "hwnd", "XAdapterMap_GetItemImage", "int", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterM[0]
EndFunc   ;==>XAdapterMap_GetItemImage
;=================AAdapterMap-数据适配器-单列Map结束====================
;=================AdapterTree-数据适配器-树元素开始====================
Func XAdapterTree_Create()
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_Create")
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_Create

Func XAdapterTree_AddColumn($_hAdapter, $_pName)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_AddColumn", "int", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_AddColumn

Func XAdapterTree_SetColumn($_hAdapter, $_pName)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_SetColumn", "int", $_hAdapter, "wstr", $_pName)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_SetColumn

Func XAdapterTree_InsertItemText($_hAdapter, $_pValue, $_nParentID, $_nsertID)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_InsertItemText", "int", $_hAdapter, "wstr", $_pValue, "int", $_nParentID, "int", $_nsertID)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_InsertItemText

Func XAdapterTree_InsertItemTextEx($_hAdapter, $_pName, $_pValue, $_nParentID, $_nsertID)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_InsertItemTextEx", "int", $_hAdapter, "wstr", $_pName, "wstr", $_pValue, "int", $_nParentID, "int", $_nsertID)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_InsertItemTextEx

Func XAdapterTree_InsertItemImage($_hAdapter, $_nimage, $_nParentID, $_nsertID)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_InsertItemImage", "int", $_hAdapter, "hwnd", $_nimage, "int", $_nParentID, "int", $_nsertID)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_InsertItemImage

Func XAdapterTree_InsertItemImageEx($_hAdapter, $_pName, $_nimage, $_nParentID, $_nsertID)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_InsertItemImageEx", "int", $_hAdapter, "wstr", $_pName, "hwnd", $_nimage, "int", $_nParentID, "int", $_nsertID)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_InsertItemImageEx

Func XAdapterTree_GetCount($_hAdapter)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_GetCount", "int", $_hAdapter)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_GetCount

Func XAdapterTree_GetCountColumn($_hAdapter)
	$_XAdapterT = DllCall($_xcdll, "int", "XAdapterTree_GetCountColumn", "int", $_hAdapter)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_GetCountColumn

Func XAdapterTree_SetItemText($_hAdapter, $_nID, $_iColumn, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTree_SetItemText", "int", $_hAdapter, "int", $_nID, "int", $_iColumn, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_SetItemText

Func XAdapterTree_SetItemTextEx($_hAdapter, $_nID, $_pName, $_pValue)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTree_SetItemTextEx", "int", $_hAdapter, "int", $_nID, "wstr", $_pName, "wstr", $_pValue)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_SetItemTextEx

Func XAdapterTree_SetItemImage($_hAdapter, $_nID, $_iColumn, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTree_SetItemImage", "int", $_hAdapter, "int", $_nID, "int", $_iColumn, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_SetItemImage

Func XAdapterTree_SetItemImageEx($_hAdapter, $_nID, $_pName, $_hImage)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTree_SetItemImageEx", "int", $_hAdapter, "int", $_nID, "wstr", $_pName, "hwnd", $_hImage)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_SetItemImageEx

Func XAdapterTree_GetItemTextEx($_hAdapter, $_nID, $_pName, $_pOut, $_nOutLen)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTree_GetItemTextEx", "int", $_hAdapter, "int", $_nID, "wstr", $_pName, "wstr", $_pOut, "int", $_nOutLen)
	Return $_XAdapterT
EndFunc   ;==>XAdapterTree_GetItemTextEx

Func XAdapterTree_GetItemImageEx($_hAdapter, $_nID, $_pName)
	$_XAdapterT = DllCall($_xcdll, "hwnd", "XAdapterTree_GetItemImageEx", "int", $_hAdapter, "int", $_nID, "wstr", $_pName)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_GetItemImageEx

Func XAdapterTree_DeleteItem($_hAdapter, $_nID)
	$_XAdapterT = DllCall($_xcdll, "bool", "XAdapterTree_DeleteItem", "int", $_hAdapter, "int", $_nID)
	Return $_XAdapterT[0]
EndFunc   ;==>XAdapterTree_DeleteItem

Func XAdapterTree_DeleteItemAll($_hAdapter)
	DllCall($_xcdll, "none", "XAdapterTree_DeleteItemAll", "int", $_hAdapter)
EndFunc   ;==>XAdapterTree_DeleteItemAll

Func XAdapterTree_DeleteColumnAll($_hAdapter)
	DllCall($_xcdll, "none", "XAdapterTree_DeleteColumnAll", "int", $_hAdapter)
EndFunc   ;==>XAdapterTree_DeleteColumnAll
;=================AdapterTree-数据适配器-树元素结束====================
;=================UI设计器支持开始=======================
Func XC_LoadLayout($_pFileName, $_hparent=0)
	$_XC = DllCall($_xcdll, "int", "XC_LoadLayout", "wstr", $_pFileName, "int", $_hparent)
	Return $_XC[0]
EndFunc   ;==>XC_LoadLayout

Func XC_LoadLayoutFromString($_pStringXML, $_hparent)
	$_XC = DllCall($_xcdll, "int", "XC_LoadLayoutFromString", "str", $_pStringXML, "int", $_hparent)
	Return $_XC[0]
EndFunc   ;==>XC_LoadLayoutFromString

Func XC_LoadResource($_pFileName, $_pDir="")
	$_XC = DllCall($_xcdll, "bool", "XC_LoadResource", "wstr", $_pFileName, "wstr", $_pDir)
	Return $_XC[0]
EndFunc   ;==>XC_LoadResource

Func XC_LoadResourceFromString($_pStringXML, $_pDir)
	$_XC = DllCall($_xcdll, "bool", "XC_LoadResourceFromString", "str", $_pStringXML, "wstr", $_pDir)
	Return $_XC[0]
EndFunc   ;==>XC_LoadResourceFromString

Func XC_LoadTemplate($_nType, $_pFileName)
	$_XC = DllCall($_xcdll, "int", "XC_LoadTemplate", "int", $_nType, "wstr", $_pFileName)
	Return $_XC[0]
EndFunc   ;==>XC_LoadTemplate

Func XC_LoadTemplateFromString($_nType, $_pStringXML)
	$_XC = DllCall($_xcdll, "int", "XC_LoadTemplateFromString", "int", $_nType, "str", $_pStringXML)
	Return $_XC[0]
EndFunc   ;==>XC_LoadTemplateFromString

Func XC_TemplateDestroy($_pInfo)
	DllCall($_xcdll, "none", "XC_TemplateDestroy", "int", $_pInfo)
EndFunc   ;==>XC_TemplateDestroy

Func XC_InitFont($_pFont, $_pName, $_size, $_bBold, $_bItalic, $_bUnderline, $_bStrikeOut)
	DllCall($_xcdll, "none", "XC_InitFont", "hwnd", $_pFont, "wstr", $_pName, "int", $_size, "bool", $_bBold, "bool", $_bItalic, "bool", $_bUnderline, "bool", $_bStrikeOut)
EndFunc   ;==>XC_InitFont

Func XC_Malloc($_size)
	$_XC = DllCall($_xcdll, "ptr", "XC_Malloc", "int", $_size)
	Return $_XC[0]
EndFunc   ;==>XC_Malloc

Func XC_Free($_p)
	DllCall($_xcdll, "none", "XC_Free", "ptr", $_p)
EndFunc   ;==>XC_Free
;=================UI设计器支持结束=======================
