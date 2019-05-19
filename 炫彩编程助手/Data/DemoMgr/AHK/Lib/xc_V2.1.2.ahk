class xc {
	static _InitClass := xc._Init()
	;BkManager
		XBkM_Create(){
			Return DllCall("XCGUI\XBkM_Create")
        }
		XBkM_Destroy(HBKM){
			Return DllCall("XCGUI\XBkM_Destroy", "Int", HBKM)
        }
		XBkM_AddImage(HBkInfoM, nState, hImage){
			Return DllCall("XCGUI\XBkM_AddImage", "Int", HBkInfoM
                                              , "Int", nState
                                              , "Ptr", hImage)
		}
		
	;TextLink-静态文本连接按钮        
		XTextLink_Create(x, y, cx, cy, pName, hParent){
			Return DllCall("XCGUI\XTextLink_Create", "Int", x 
                                                 , "Int", y
                                                 , "Int", cx
                                                 , "Int", cy
                                                 , "Str", pName
                                                 , "Ptr", hParent)
		}
	;--------------------------------------------------------------------------
	; ____      ___ ____              ___                ___ 
	; `MM(      )M' `Mb(      db      )d'                `MM 
	;  `MM.     d'   YM.     ,PM.     ,P                  MM 
	;   `MM.   d'    `Mb     d'Mb     d'  ___  __     ____MM 
	;    `MM. d'      YM.   ,P YM.   ,P   `MM 6MMb   6MMMMMM 
	;     `MMd        `Mb   d' `Mb   d'    MMM9 `Mb 6M'  `MM 
	;      dMM.        YM. ,P   YM. ,P     MM'   MM MM    MM 
	;     d'`MM.       `Mb d'   `Mb d'     MM    MM MM    MM 
	;    d'  `MM.       YM,P     YM,P      MM    MM MM    MM 
	;   d'    `MM.      `MM'     `MM'      MM    MM YM.  ,MM 
	; _M(_    _)MM_      YP       YP      _MM_  _MM_ YMMMMMM_
	; 
	;--------------------------------------------------------------------------
		/*
			XC_SY_CAPTION     := 0x00000001
			XC_SY_BORDER      := 0x00000002
			XC_SY_CENTER      := 0x00000004
			XC_SY_DRAG_BORDER := 0x00000008
			XC_SY_DRAG_WINDOW := 0x00000010
			XC_SY_CAPTION | XC_SY_CENTER | XC_SY_DRAG_WINDOW = 21
			XC_SY_DEFAULT := 15 ; XC_SY_CAPTION | XC_SY_BORDER | XC_SY_CENTER | XC_SY_DRAG_BORDER
		*/
		XWnd_Create(x=0, y=0, cx=300, cy=200, pTitle="", hWndParent=0, XCStyle=15) {
			Return DllCall("XCGUI\XWnd_Create", "Int", x
			                                  , "Int", y
			                                  , "Int", cx
			                                  , "Int", cy
			                                  , "Str", pTitle
			                                  , "Ptr", hWndParent
			                                  , "Int",  XCStyle
			                                  , "Ptr")
		}
		
		XWnd_CreateEx(dwExStyle=0, lpClassName="", lpWindowName="", dwStyle=0, x=0, y=0, cx=0, cy=0, hWndParent=0, XCStyle=0) {
			Return DllCall("XCGUI\XWnd_CreateEx", "Ptr", dwExStyle
												, "Str", lpClassName
												, "Str", lpWindowName
												, "Ptr", dwStyle
												, "Int", x
												, "Int", y
												, "Int", cx
												, "Int", cy
												, "Ptr", hWndParent
												, "Int", XCStyle)
		}
		
		XWnd_ShowWindow(hWindow, nCmdShow=5) {
			Return DllCall("XCGUI\XWnd_ShowWindow", "Ptr", hWindow
			                                      , "Int", nCmdShow
			                                      , "Int")
		}

		XWnd_CloseWindow(hWindow) {
			Return DllCall("XCGUI\XWnd_CloseWindow", "Ptr", hWindow
			                                       , "Ptr")
		}

		XWnd_GetHWND(hWindow) {
			Return DllCall("XCGUI\XWnd_GetHWND", "Ptr", hWindow
			                                   , "Ptr")
		}

		XWnd_SetImage(hWindow, hImage) {
			Return DllCall("XCGUI\XWnd_SetImage", "Ptr", hWindow
			                                    , "Ptr", hImage
			                                    , "Ptr")
		}

		XWnd_SetLayoutBkColor(hWindow, nFlag, color, alpha=255) {
			/*
				XC_LAYOUT_BODY = 5 
				XC_LAYOUT_BOTTOM = 2 
				XC_LAYOUT_LEFT = 3 
				XC_LAYOUT_RIGHT = 4 
				XC_LAYOUT_TOP = 1 
			*/
			Return DllCall("XCGUI\XWnd_SetLayoutBkColor", "Ptr", hWindow
			                                            , "Int", nFlag
			                                            , "UInt", color
			                                            , "UChar", alpha
			                                            , "Ptr")
		}

		XWnd_RegEventC(hWindow, nEvent, funcName) {
			Address := RegisterCallback(funcName, "Fast")
			Return Address, DllCall("XCGUI\XWnd_RegEventC", "Ptr", hWindow
			                                     , "Int", nEvent
			                                     , "Ptr", Address
			                                     , "Ptr")
		}

		XWnd_RegEventC1(hWindow, nEvent, funcName) {
			Address := RegisterCallback(funcName, "Fast")
			Return DllCall("XCGUI\XWnd_RegEventC1", "Ptr", hWindow
			                                      , "Int", nEvent
			                                      , "Ptr", Address
			                                      , "Ptr")
		}

		XWnd_RedrawWnd(hWindow, bImmediate=0) {
			Return DllCall("XCGUI\XWnd_RedrawWnd", "Ptr", hWindow
			                                     , "Int", bImmediate)
		}

		XWnd_EnableDrawBk(hWindow, bEnable) {
			Return DllCall("XCGUI\XWnd_EnableDrawBk", "Ptr", hWindow
			                                        , "Int", bEnable
			                                        , "Ptr")
		}

		XWnd_SetTransparentColor(hWindow, color) {
			Return DllCall("XCGUI\XWnd_SetTransparentColor", "Ptr", hWindow
			                                               , "UInt", color
			                                               , "Ptr")
		}

		XWnd_SetTransparentAlpha(hWindow, alpha=255) {
			Return DllCall("XCGUI\XWnd_SetTransparentAlpha", "Ptr", hWindow
			                                               , "UChar", alpha
			                                               , "Ptr")
		}

		XWnd_SetTransparentFlag(hWindow, nFlag) {
			Return DllCall("XCGUI\XWnd_SetTransparentFlag", "Ptr", hWindow
			                                              , "Int", nFlag
			                                              , "Ptr")
		}

		XWnd_SetTransparentType(hWindow, nType) {
			Return DllCall("XCGUI\XWnd_SetTransparentType", "Ptr", hWindow
			                                              , "Int", nType
			                                              , "Ptr")
		}

		XWnd_AdjustLayout(hWindow) {
			Return DllCall("XCGUI\XWnd_AdjustLayout", "Ptr", hWindow)
		}

		XWnd_AdjustLayoutObject(hWindow) {
			Return DllCall("XCGUI\XWnd_AdjustLayoutObject", "Ptr", hWindow)
		}

		XWnd_BindLayoutObject(hWindow, nFlag, hLayout) {
			Return DllCall("XCGUI\XWnd_BindLayoutObject", "Ptr", hWindow
			                                            , "Int", nFlag
			                                            , "Ptr", hLayout
			                                            , "Ptr")
		}

		XWnd_BindLayoutEle(hWindow, nFlag, hEle) {
			Return DllCall("XCGUI\XWnd_BindLayoutEle", "Ptr", hWindow
			                                         , "Int", nFlag
			                                         , "Ptr", hEle
			                                         , "Int")
		}

		XWnd_AddEle(hWindow, hEle) {
			Return DllCall("XCGUI\XWnd_AddEle", "Ptr", hWindow
			                                  , "Ptr", hEle
			                                  , "Int")
		}

		XWnd_SetTimer(hWindow, nIDEvent, uElapse) {
			Return DllCall("XCGUI\XWnd_SetTimer", "Ptr", hWindow
			                                    , "UInt", nIDEvent
			                                    , "UInt", uElapse
			                                    , "UInt")
		}

		XWnd_KillTimer(hWindow, nIDEvent) {
			Return DllCall("XCGUI\XWnd_KillTimer", "Ptr", hWindow
			                                     , "UInt", nIDEvent
			                                     , "Int")
		}

		XWnd_EnableAutoFocus(hWindow, bEnable=True) {
			Return DllCall("XCGUI\XWnd_EnableAutoFocus", "Ptr", hWindow
			                                           , "Int", bEnable
			                                           , "Ptr")
		}

		XWnd_EnableDragWindow(hWindow, bEnable) {
			Return DllCall("XCGUI\XWnd_EnableDragWindow", "Ptr", hWindow
			                                            , "Int", bEnable
			                                            , "Ptr")
		}

		XWnd_GetBkInfoManager(hWindow, nPosition) {
			Return DllCall("XCGUI\XWnd_GetBkInfoManager", "Ptr", hWindow
			                                            , "Int", nPosition
			                                            , "Ptr")
		}

		XWnd_GetChildCount(hWindow) {
			Return DllCall("XCGUI\XWnd_GetChildCount", "Ptr", hWindow
			                                         , "Int")
		}

		XWnd_GetChildByIndex(hWindow, index) {
			Return DllCall("XCGUI\XWnd_GetChildByIndex", "Ptr", hWindow
			                                           , "Int", index
			                                           , "Ptr")
		}

		XWnd_SetLayoutSize(hWindow, left, top, right, bottom) {
			Return DllCall("XCGUI\XWnd_SetLayoutSize", "Ptr", hWindow
			                                         , "Int", left
			                                         , "Int", top
			                                         , "Int", right
			                                         , "Int", bottom
			                                         , "Ptr")
		}

		XWnd_HitChildEle(hWindow, pPt) {
			Return DllCall("XCGUI\XWnd_HitChildEle", "Ptr", hWindow
			                                       , "Ptr", pPt
			                                       , "Ptr")
		}

		XWnd_RemovegEvent(hWindow, nEvent, memberFunction) {
			Return DllCall("XCGUI\XWnd_RemovegEvent", "Ptr", hWindow
			                                        , "Int", nEvent
			                                        , "Ptr", memberFunction)
		}

		XWnd_GetClientRect(hWindow, ByRef outRECT) {
			VarSetCapacity(outRECT, 16, 0)
			Return DllCall("XCGUI\XWnd_GetClientRect", "Ptr", hWindow
			                                         , "Ptr", &outRECT)
		}

		XWnd_SetFocusEle(hWindow, hFocusEle) {
			Return DllCall("XCGUI\XWnd_SetFocusEle", "Ptr", hWindow
			                                       , "Ptr", hFocusEle)
		}
		XWnd_GetBkManager(hWindow) {
			Return DllCall("XCGUI\XWnd_GetBkManager","Ptr", hWindow)                                      
		}

		XWnd_SetShadowInfo(hWindow, nSize, nDepth, nAngeleSize, bRightAngle, color) {
			Return DllCall("XCGUI\XWnd_SetShadowInfo", "Ptr", hWindow
                                                                 , "Int", nSize
                                                                 , "Int", nDepth
                                                                 , "Int", nAngeleSize
                                                                 , "Int", bRightAngle
                                                                 , "Ptr", color)
		}


	;--------------------------------------------------------------------------
	; ____      ___ ___       ___               ___           ___ ____              ___                ___ 
	; `MM(      )M' `MMb     dMM'               `MM           `MM `Mb(      db      )d'                `MM 
	;  `MM.     d'   MMM.   ,PMM                 MM            MM  YM.     ,PM.     ,P                  MM 
	;   `MM.   d'    M`Mb   d'MM   _____     ____MM    ___     MM  `Mb     d'Mb     d'  ___  __     ____MM 
	;    `MM. d'     M YM. ,P MM  6MMMMMb   6MMMMMM  6MMMMb    MM   YM.   ,P YM.   ,P   `MM 6MMb   6MMMMMM 
	;     `MMd       M `Mb d' MM 6M'   `Mb 6M'  `MM 8M'  `Mb   MM   `Mb   d' `Mb   d'    MMM9 `Mb 6M'  `MM 
	;      dMM.      M  YM.P  MM MM     MM MM    MM     ,oMM   MM    YM. ,P   YM. ,P     MM'   MM MM    MM 
	;     d'`MM.     M  `Mb'  MM MM     MM MM    MM ,6MM9'MM   MM    `Mb d'   `Mb d'     MM    MM MM    MM 
	;    d'  `MM.    M   YP   MM MM     MM MM    MM MM'   MM   MM     YM,P     YM,P      MM    MM MM    MM 
	;   d'    `MM.   M   `'   MM YM.   ,M9 YM.  ,MM MM.  ,MM   MM     `MM'     `MM'      MM    MM YM.  ,MM 
	; _M(_    _)MM_ _M_      _MM_ YMMMMM9   YMMMMMM_`YMMM9'Yb._MM_     YP       YP      _MM_  _MM_ YMMMMMM_
	; 
	;--------------------------------------------------------------------------
		/*
			XC_SY_CAPTION     := 0x00000001
			XC_SY_BORDER      := 0x00000002
			XC_SY_CENTER      := 0x00000004
			XC_SY_DRAG_BORDER := 0x00000008
			XC_SY_DRAG_WINDOW := 0x00000010
			XC_SY_CAPTION | XC_SY_CENTER | XC_SY_DRAG_WINDOW = 21
		*/
		XModalWnd_Create(nWidth, nHeight, pTitle, hWndParent, XCStyle=21) {
			Return DllCall("XCGUI\XModalWnd_Create", "Int", nWidth
			                                       , "Int", nHeight
			                                       , "Str", pTitle
			                                       , "Ptr", hWndParent
			                                       , "Int",  XCStyle
			                                       , "Ptr")
		}

		XModalWnd_DoModal(hWindow) {
			Return DllCall("XCGUI\XModalWnd_DoModal", "Ptr", hWindow
			                                        , "Int")
		}

		XModalWnd_EndModal(hWindow, nResult=0) {
			Return DllCall("XCGUI\XModalWnd_EndModal", "Ptr", hWindow
			                                         , "Int", nResult)
		}

		XModalWnd_EnableAutoClose(hWindow, bEnable=1) {
			Return DllCall("XCGUI\XModalWnd_EnableAutoClose", "Ptr", hWindow
			                                                , "Int", bEnable)
		}



	;--------------------------------------------------------------------------
	; ____      ___ ________                     
	; `MM(      )M' `MMMMMMMb.                   
	;  `MM.     d'   MM    `Mb   /               
	;   `MM.   d'    MM     MM  /M     ___  __   
	;    `MM. d'     MM    .M9 /MMMMM  `MM 6MMb  
	;     `MMd       MMMMMMM(   MM      MMM9 `Mb 
	;      dMM.      MM    `Mb  MM      MM'   MM 
	;     d'`MM.     MM     MM  MM      MM    MM 
	;    d'  `MM.    MM     MM  MM      MM    MM 
	;   d'    `MM.   MM    .M9  YM.  ,  MM    MM 
	; _M(_    _)MM_ _MMMMMMM9'   YMMM9 _MM_  _MM_
	; 
	;--------------------------------------------------------------------------
		XBtn_Create(x=0, y=0, cx=80, cy=25, pTitle="", hWndParent=0) {
			Return DllCall("XCGUI\XBtn_Create", "Int", x
			                                  , "Int", y
			                                  , "Int", cx
			                                  , "Int", cy
			                                  , "Str", pTitle
			                                  , "Ptr", hWndParent
			                                  , "Ptr")
		}

		XBtn_SetText(hEle, pName) {
			Return DllCall("XCGUI\XBtn_SetText", "Ptr", hEle
			                                   , "Str", pName
			                                   , "Ptr")
		}

		XBtn_SetTextAlign(hEle, nFlags) {
			Return DllCall("XCGUI\XBtn_SetTextAlign", "Ptr", hEle
			                                        , "Int", nFlags
			                                        , "Ptr")
		}

		XBtn_SetOffset(hEle, x, y) {
			Return DllCall("XCGUI\XBtn_SetOffset", "Ptr", hEle
			                                     , "Int", x
			                                     , "Int", y
			                                     , "Ptr")
		}

		XBtn_SetGroupID(hEle, nID=0) {
			Return DllCall("XCGUI\XBtn_SetGroupID", "Ptr", hEle
			                                      , "Int", nID
			                                      , "Ptr")
		}

		XBtn_SetType(hEle, nStyle=0) {
			Return DllCall("XCGUI\XBtn_SetType", "Ptr", hEle
			                                   , "Int", nStyle
			                                   , "Ptr")
		}

		XBtn_SetBindEle(hEle, hBindEle) {
			Return DllCall("XCGUI\XBtn_SetBindEle", "Ptr", hEle
			                                      , "Int", hBindEle
			                                      , "Ptr")
		}

		XBtn_AddAnimationFrame(hEle, hImage, uElapse) {
			Return DllCall("XCGUI\XBtn_AddAnimationFrame", "Ptr", hEle
			                                             , "Ptr", hImage
			                                             , "UInt", uElapse
			                                             , "Ptr")
		}

		XBtn_EnableAnimation(hEle, bEnable=True, bLoopPlay=False) {
			Return DllCall("XCGUI\XBtn_EnableAnimation", "Ptr", hEle
			                                           , "Ptr", bEnable
			                                           , "UInt", bLoopPlay
			                                           , "Ptr")
		}

		XBtn_SetState(hEle, nState) {
			Return DllCall("XCGUI\XBtn_SetState", "Ptr", hEle
			                                    , "Int", nState
			                                    , "Ptr")
		}

		XBtn_SetCheck(hEle, bCheck=True) {
			static XBtn_SetCheck := xc._GetProcAddress("XBtn_SetCheck")
			Return DllCall(XBtn_SetCheck, "Ptr", hEle
			                            , "Int", bCheck
			                            , "Int")
		}

		XBtn_GetType(hEle) {
			Return DllCall("XCGUI\XBtn_GetType", "Ptr", hEle
			                                   , "Int")
		}

		XBtn_SetIcon(hEle, hImage) {
			Return DllCall("XCGUI\XBtn_SetIcon", "Ptr", hEle
			                                   , "Ptr", hImage
			                                   , "Ptr")
		}

		XBtn_SetImageLeave(hEle, hImage) {
			Return DllCall("XCGUI\XBtn_SetImageLeave", "Ptr", hEle
			                                         , "Ptr", hImage
			                                         , "Ptr")
		}

		XBtn_SetImageStay(hEle, hImage) {
			Return DllCall("XCGUI\XBtn_SetImageStay", "Ptr", hEle
			                                        , "Ptr", hImage
			                                        , "Ptr")
		}

		XBtn_SetImageDown(hEle, hImage) {
			Return DllCall("XCGUI\XBtn_SetImageDown", "Ptr", hEle
			                                        , "Ptr", hImage
			                                        , "Ptr")
		}

		XBtn_SetImageDisable(hEle, hImage) {
			Return DllCall("XCGUI\XBtn_SetImageDisable", "Ptr", hEle
			                                           , "Ptr", hImage
			                                           , "Ptr")
		}

		XBtn_SetImageCheck(hEle, hImage) {
			Return DllCall("XCGUI\XBtn_SetImageCheck", "Ptr", hEle
			                                         , "Ptr", hImage
			                                         , "Ptr")
		}

		XBtn_IsCheck(hEle) {
			Return DllCall("XCGUI\XBtn_IsCheck", "Ptr", hEle
			                                   , "Int")
		}

		XBtn_GetBindEle(hEle) {
			Return DllCall("XCGUI\XBtn_GetBindEle", "Ptr", hEle
			                                      , "Ptr")
		}

		XBtn_GetBkInfoManager(hEle, nState) {
			Return DllCall("XCGUI\XBtn_GetBkInfoManager", "Ptr", hEle
			                                            , "Int", nState
			                                            , "Ptr")
		}

		XBtn_GetText(hEle, ByRef out, len=520) {
			VarSetCapacity(out, len, 0)
			Return DllCall("XCGUI\XBtn_GetText", "Ptr", hEle
			                                   , "Str", out
			                                   , "Int", len
			                                   , "Int")
		}


	                                                                                                      
	;--------------------------------------------------------------------------
	; ____      ___    ____                             ___                 ________                        
	; `MM(      )M'   6MMMMb/                            MM                 `MMMMMMMb.                      
	;  `MM.     d'   8P    YM                            MM                  MM    `Mb                      
	;   `MM.   d'   6M      Y   _____   ___  __    __    MM____     _____    MM     MM   _____   ____   ___ 
	;    `MM. d'    MM         6MMMMMb  `MM 6MMb  6MMb   MMMMMMb   6MMMMMb   MM    .M9  6MMMMMb  `MM(   )P' 
	;     `MMd      MM        6M'   `Mb  MM69 `MM69 `Mb  MM'  `Mb 6M'   `Mb  MMMMMMM(  6M'   `Mb  `MM` ,P   
	;      dMM.     MM        MM     MM  MM'   MM'   MM  MM    MM MM     MM  MM    `Mb MM     MM   `MM,P    
	;     d'`MM.    MM        MM     MM  MM    MM    MM  MM    MM MM     MM  MM     MM MM     MM    `MM.    
	;    d'  `MM.   YM      6 MM     MM  MM    MM    MM  MM    MM MM     MM  MM     MM MM     MM    d`MM.   
	;   d'    `MM.   8b    d9 YM.   ,M9  MM    MM    MM  MM.  ,M9 YM.   ,M9  MM    .M9 YM.   ,M9   d' `MM.  
	; _M(_    _)MM_   YMMMM9   YMMMMM9  _MM_  _MM_  _MM__MYMMMM9   YMMMMM9  _MMMMMMM9'  YMMMMM9  _d_  _)MM_ 
	; 
	;--------------------------------------------------------------------------
		XComboBox_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XComboBox_Create", "Int", x
			                                       , "Int", y
			                                       , "Int", cx
			                                       , "Int", cy
			                                       , "Ptr", hParent
			                                       , "Ptr")
		}

		XComboBox_SetItemTemplateXML(hEle, pXmlFile) {
			Return DllCall("XCGUI\XComboBox_SetItemTemplateXML", "Ptr", hEle
			                                                   , "Str", pXmlFile
			                                                   , "Ptr")
		}

		XComboBox_BindApapter(hEle, hAdapter) {
			Return DllCall("XCGUI\XComboBox_BindApapter", "Ptr", hEle
			                                            , "Ptr", hAdapter
			                                            , "Ptr")
		}

		XComboBox_EnableDrawButton(hEle, bEnable=True) {
			Return DllCall("XCGUI\XComboBox_EnableDrawButton", "Ptr", hEle
			                                                 , "Int", bEnable
			                                                 , "Ptr")
		}

		XComboBox_EnableEdit(hEle, bEnable=True) {
			Return DllCall("XCGUI\XComboBox_EnableEdit", "Ptr", hEle
			                                           , "Int", bEnable
			                                           , "Ptr")
		}


	                                                                                                                              
	;--------------------------------------------------------------------------
	; ____      ___        _           ___                                              __________           ___       ___          
	; `MM(      )M'       dM.          `MM                                              MMMMMMMMMM            MM       `MM          
	;  `MM.     d'       ,MMb           MM                       /                      /   MM   \            MM        MM          
	;   `MM.   d'        d'YM.      ____MM    ___    __ ____    /M       ____   ___  __     MM        ___     MM____    MM   ____   
	;    `MM. d'        ,P `Mb     6MMMMMM  6MMMMb   `M6MMMMb  /MMMMM   6MMMMb  `MM 6MM     MM      6MMMMb    MMMMMMb   MM  6MMMMb  
	;     `MMd          d'  YM.   6M'  `MM 8M'  `Mb   MM'  `Mb  MM     6M'  `Mb  MM69 "     MM     8M'  `Mb   MM'  `Mb  MM 6M'  `Mb 
	;      dMM.        ,P   `Mb   MM    MM     ,oMM   MM    MM  MM     MM    MM  MM'        MM         ,oMM   MM    MM  MM MM    MM 
	;     d'`MM.       d'    YM.  MM    MM ,6MM9'MM   MM    MM  MM     MMMMMMMM  MM         MM     ,6MM9'MM   MM    MM  MM MMMMMMMM 
	;    d'  `MM.     ,MMMMMMMMb  MM    MM MM'   MM   MM    MM  MM     MM        MM         MM     MM'   MM   MM    MM  MM MM       
	;   d'    `MM.    d'      YM. YM.  ,MM MM.  ,MM   MM.  ,M9  YM.  , YM    d9  MM         MM     MM.  ,MM   MM.  ,M9  MM YM    d9 
	; _M(_    _)MM_ _dM_     _dMM_ YMMMMMM_`YMMM9'Yb. MMYMMM9    YMMM9  YMMMM9  _MM_       _MM_    `YMMM9'Yb._MYMMMM9  _MM_ YMMMM9  
	;                                                 MM                                                                            
	;                                                 MM                                                                            
	;                                                _MM_                                                                           
	; 
	;--------------------------------------------------------------------------
		XAdapterTable_Create() {
			Return DllCall("XCGUI\XAdapterTable_Create", "Ptr")
		}

		XAdapterTable_AddColumn(hAdapter, pName) {
			Return DllCall("XCGUI\XAdapterTable_AddColumn", "Ptr", hAdapter
			                                              , "Str", pName
			                                              , "Int")
		}

		XAdapterTable_SetColumn(hAdapter, pColName) {
			Return DllCall("XCGUI\XAdapterTable_SetColumn", "Ptr", hAdapter
			                                              , "Str", pColName
			                                              , "Int")
		}

		XAdapterTable_AddItemText(hAdapter, pValue) {
			static XAdapterTable_AddItemText := xc._GetProcAddress("XAdapterTable_AddItemText")
			Return DllCall(XAdapterTable_AddItemText, "Ptr", hAdapter
			                                        , "Str", pValue
			                                        , "Int")
		}

		XAdapterTable_AddItemTextEx(hAdapter, pName, pValue) {
			static XAdapterTable_AddItemTextEx := xc._GetProcAddress("XAdapterTable_AddItemTextEx")
			Return DllCall(XAdapterTable_AddItemTextEx, "Ptr", hAdapter
			                                          , "Str", pName
			                                          , "Str", pValue
			                                          , "Int")
		}

		XAdapterTable_InsertItemText(hAdapter, iItem, pValue) {
			Return DllCall("XCGUI\XAdapterTable_InsertItemText", "Ptr", hAdapter
			                                                   , "Int", iItem
			                                                   , "Str", pValue
			                                                   , "Int")
		}

		XAdapterTable_InsertItemTextEx(hAdapter, iItem, pName, pValue) {
			Return DllCall("XCGUI\XAdapterTable_InsertItemTextEx", "Ptr", hAdapter
			                                                     , "Int", iItem
			                                                     , "Str", pName
			                                                     , "Str", pValue
			                                                     , "Int")
		}

		XAdapterTable_DeleteItem(hAdapter, iItem) {
			Return DllCall("XCGUI\XAdapterTable_DeleteItem", "Ptr", hAdapter
			                                               , "Int", iItem
			                                               , "Int")
		}

		XAdapterTable_DeleteItemEx(hAdapter, iItem, nCount) {
			Return DllCall("XCGUI\XAdapterTable_DeleteItemEx", "Ptr", hAdapter
			                                                 , "Int", iItem
			                                                 , "Int", nCount
			                                                 , "Int")
		}

		XAdapterTable_SetItemText(hAdapter, iItem, iColumn, pValue) {
			Return DllCall("XCGUI\XAdapterTable_SetItemText", "Ptr", hAdapter
			                                                , "Int", iItem
			                                                , "Int", iColumn
			                                                , "Ptr", &pValue
			                                                , "Int")
		}

		XAdapterTable_SetItemTextEx(hAdapter, iItem, pName, pValue) {
			Return DllCall("XCGUI\XAdapterTable_SetItemTextEx", "Ptr", hAdapter
			                                                  , "Int", iItem
			                                                  , "Str", pName
			                                                  , "Str", pValue
			                                                  , "Int")
		}

		XAdapterTable_SetItemImageEx(hAdapter, iItem, pName, hImage) {
			Return DllCall("XCGUI\XAdapterTable_SetItemImageEx", "Ptr", hAdapter
			                                                   , "Int", iItem
			                                                   , "Str", pName
			                                                   , "Ptr", hImage
			                                                   , "Int")
		}

		; XAdapterTable_GetItemText(hAdapter, iItem, iColumn, ByRef pOut, ByRef nOutLen := "") {
		; 	VarSetCapacity(pOut, 1, 0)
		; 	ret := DllCall("XCGUI\XAdapterTable_GetItemText", "Ptr", hAdapter
		; 	                                                , "Int", iItem
		; 	                                                , "Int", iColumn
		; 	                                                , "Ptr", &pOut
		; 	                                                , "Int*", nOutLen
		; 	                                                , "Int")
		; 	nOutLen := VarSetCapacity(pOut, -1)
		; 	pOut := StrGet(&pOut)
		; 	Return ret
		; }

		; XAdapterTable_GetItemTextEx(hAdapter, iItem, pName, ByRef pOut, ByRef nOutLen := "") {
		; 	VarSetCapacity(pOut, 1, 0)
		; 	ret := DllCall("XCGUI\XAdapterTable_GetItemTextEx", "Ptr", hAdapter
		; 	                                                  , "Int", iItem
		; 	                                                  , "Str", pName
		; 	                                                  , "Ptr", &pOut
		; 	                                                  , "Int*", nOutLen
		; 	                                                  , "Int")
		; 	nOutLen := VarSetCapacity(pOut, -1)
		; 	pOut := StrGet(&pOut)
		; 	Return ret
		; }

		XAdapterTable_GetItemText(hAdapter, iItem, iColumn, ByRef pOut, ByRef nOutLen := "") {
			nOutLen := 1024
			VarSetCapacity(pOut, nOutLen, 0)
			Return DllCall("XCGUI\XAdapterTable_GetItemText", "Ptr", hAdapter
			                                                , "Int", iItem
			                                                , "Int", iColumn
			                                                , "Str", pOut ; "Ptr", &pOut
			                                                , "Int", nOutLen
			                                                , "Int")
		}

		XAdapterTable_GetItemTextEx(hAdapter, iItem, pName, ByRef pOut, ByRef nOutLen := "") {
			static XAdapterTable_GetItemTextEx := xc._GetProcAddress("XAdapterTable_GetItemTextEx")
			nOutLen := 1024
			VarSetCapacity(pOut, nOutLen, 0)
			Return DllCall(XAdapterTable_GetItemTextEx, "Ptr", hAdapter
			                                          , "Int", iItem
			                                          , "Str", pName
			                                          , "Str", pOut
			                                          , "Int", nOutLen
			                                          , "Int")
		}

		XAdapterTable_GetItemImageEx(hAdapter, iItem, pName) {
			Return DllCall("XCGUI\XAdapterTable_GetItemImageEx", "Ptr", hAdapter
			                                                  , "Int", iItem
			                                                  , "Str", pName
			                                                  , "Ptr")
		}

		XAdapterTable_GetCount(hAdapter) {
			Return DllCall("XCGUI\XAdapterTable_GetCount", "Ptr", hAdapter)
		}

		XAdapterTable_GetCountColumn(hAdapter) {
			Return DllCall("XCGUI\XAdapterTable_GetCountColumn", "Ptr", hAdapter)
		}

		XAdapterTable_DeleteItemAll(hAdapter) {
			Return DllCall("XCGUI\XAdapterTable_DeleteItemAll", "Ptr", hAdapter)
		}



	;--------------------------------------------------------------------------
	; ____      ___        _           ___                                              ___       ___                    
	; `MM(      )M'       dM.          `MM                                              `MMb     dMM'                    
	;  `MM.     d'       ,MMb           MM                       /                       MMM.   ,PMM                     
	;   `MM.   d'        d'YM.      ____MM    ___    __ ____    /M       ____   ___  __  M`Mb   d'MM    ___    __ ____   
	;    `MM. d'        ,P `Mb     6MMMMMM  6MMMMb   `M6MMMMb  /MMMMM   6MMMMb  `MM 6MM  M YM. ,P MM  6MMMMb   `M6MMMMb  
	;     `MMd          d'  YM.   6M'  `MM 8M'  `Mb   MM'  `Mb  MM     6M'  `Mb  MM69 "  M `Mb d' MM 8M'  `Mb   MM'  `Mb 
	;      dMM.        ,P   `Mb   MM    MM     ,oMM   MM    MM  MM     MM    MM  MM'     M  YM.P  MM     ,oMM   MM    MM 
	;     d'`MM.       d'    YM.  MM    MM ,6MM9'MM   MM    MM  MM     MMMMMMMM  MM      M  `Mb'  MM ,6MM9'MM   MM    MM 
	;    d'  `MM.     ,MMMMMMMMb  MM    MM MM'   MM   MM    MM  MM     MM        MM      M   YP   MM MM'   MM   MM    MM 
	;   d'    `MM.    d'      YM. YM.  ,MM MM.  ,MM   MM.  ,M9  YM.  , YM    d9  MM      M   `'   MM MM.  ,MM   MM.  ,M9 
	; _M(_    _)MM_ _dM_     _dMM_ YMMMMMM_`YMMM9'Yb. MMYMMM9    YMMM9  YMMMM9  _MM_    _M_      _MM_`YMMM9'Yb. MMYMMM9  
	;                                                 MM                                                        MM       
	;                                                 MM                                                        MM       
	;                                                _MM_                                                      _MM_      
	;
	;--------------------------------------------------------------------------
		XAdapterMap_Create() {
			Return DllCall("XCGUI\XAdapterMap_Create", "Ptr")
		}

		XAdapterMap_AddItemText(hAdapter, pName, pValue) {
			Return DllCall("XCGUI\XAdapterMap_AddItemText", "Ptr", hAdapter
			                                              , "Str", pName
			                                              , "Str", pValue
			                                              , "Int")
		}



	;--------------------------------------------------------------------------
	; ____      ___ __________ ___          
	; `MM(      )M' `MMMMMMMMM `MM          
	;  `MM.     d'   MM      \  MM          
	;   `MM.   d'    MM         MM   ____   
	;    `MM. d'     MM    ,    MM  6MMMMb  
	;     `MMd       MMMMMMM    MM 6M'  `Mb 
	;      dMM.      MM    `    MM MM    MM 
	;     d'`MM.     MM         MM MMMMMMMM 
	;    d'  `MM.    MM         MM MM       
	;   d'    `MM.   MM      /  MM YM    d9 
	; _M(_    _)MM_ _MMMMMMMMM _MM_ YMMMM9  
	; 
	;--------------------------------------------------------------------------
		XEle_Create(x=0, y=0, cx=80, cy=25, hParent=0) {
			Return DllCall("XCGUI\XEle_Create", "Int", x
			                                  , "Int", y
			                                  , "Int", cx
			                                  , "Int", cy
			                                  , "Ptr", hParent
			                                  , "Ptr")
		}

		XEle_RegEventC(hEle, nEvent, funcName) {
			Address := RegisterCallback(funcName, "Fast")
			Return DllCall("XCGUI\XEle_RegEventC", "Ptr", hEle
			                                     , "Int", nEvent
			                                     , "Ptr", Address
			                                     , "Ptr")
		}

		XEle_RegEventC1(hEle, nEvent, funcName) {
			Address := RegisterCallback(funcName, "Fast")
			Return DllCall("XCGUI\XEle_RegEventC1", "Ptr", hEle
			                                      , "Int", nEvent
			                                      , "Ptr", Address
			                                      , "Ptr")
		}

		XEle_RegEventC2(hEle, nEvent, funcName, EventInfo:="") {
			static XEle_RegEventC2 := xc._GetProcAddress("XEle_RegEventC2")
			Address := RegisterCallback(funcName, "",, EventInfo)
			Return Address, DllCall(XEle_RegEventC2, "Ptr", hEle
			                                       , "Int", nEvent
			                                       , "Ptr", Address
			                                       , "Ptr")
		}

		XEle_SetTextColor(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XEle_SetTextColor", "Ptr", hEle
			                                        , "UInt", color
			                                        , "UChar", alpha
			                                        , "Ptr")
		}

		XEle_SetBkColor(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XEle_SetBkColor", "Ptr", hEle
			                                      , "UInt", color
			                                      , "UChar", alpha
			                                      , "Ptr")
		}

		XEle_AddBkBorder(hEle, color, alpha=255, width=1) {
			Return DllCall("XCGUI\XEle_AddBkBorder", "Ptr", hEle
			                                       , "UInt", color
			                                       , "UChar", alpha
			                                       , "Int", width
			                                       , "Ptr")
		}

		XEle_AddBkFill(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XEle_AddBkFill", "Ptr", hEle
			                                     , "UInt", color
			                                     , "UChar", alpha
			                                     , "Ptr")
		}

		XEle_SetBorderColor(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XEle_SetBorderColor", "Ptr", hEle
			                                          , "UInt", color
			                                          , "UChar", alpha
			                                          , "Ptr")
		}

		XEle_SetFocusBorderColor(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XEle_SetFocusBorderColor", "Ptr", hEle
			                                               , "UInt", color
			                                               , "UChar", alpha
			                                               , "Ptr")
		}

		XEle_SetFont(hEle, hFontx) {
			Return DllCall("XCGUI\XEle_SetFont", "Ptr", hEle
			                                   , "Ptr", hFontx 
			                                   , "Ptr")
		}

		XEle_SetImage(hEle, hImage) {
			Return DllCall("XCGUI\XEle_SetImage", "Ptr", hEle
			                                    , "Ptr", hImage
			                                    , "Ptr")
		}

		XEle_EnableBorder(hEle, bEnable=1) {
			Return DllCall("XCGUI\XEle_EnableBorder", "Ptr", hEle
			                                        , "Int", bEnable 
			                                        , "Ptr")
		}

		XEle_Enable(hEle, bEnable=1) {
			static XEle_Enable := xc._GetProcAddress("XEle_Enable")
			Return DllCall(XEle_Enable, "Ptr", hEle
			                          , "Int", bEnable)
		}

		XEle_EnableFocus(hEle, bEnable=1) {
			Return DllCall("XCGUI\XEle_EnableFocus", "Ptr", hEle
			                                       , "Int", bEnable 
			                                       , "Ptr")
		}

		XEle_EnableDrawFocus(hEle, bEnable=1) {
			Return DllCall("XCGUI\XEle_EnableDrawFocus", "Ptr", hEle
			                                           , "Int", bEnable 
			                                           , "Ptr")
		}

		XEle_EnableBkTransparent(hEle, bEnable=1) {
			Return DllCall("XCGUI\XEle_EnableBkTransparent", "Ptr", hEle
			                                               , "Int", bEnable 
			                                               , "Ptr")
		}

		XEle_RedrawEle(hEle, bImmediate=False) {
			Return DllCall("XCGUI\XEle_RedrawEle", "Ptr", hEle
			                                     , "Int", bImmediate)
		}

		XEle_GetTemplateListItemID(hEle) {
			Return DllCall("XCGUI\XEle_GetTemplateListItemID", "Ptr", hEle
			                                                 , "Int")
		}

		XEle_GetHWND(hEle) {
			Return DllCall("XCGUI\XEle_GetHWND", "Ptr", hEle
			                                   , "Ptr")
		}

		XEle_SendEvent(hEle, hEventEle, nEvent, wParam, lParam) {
			Return DllCall("XCGUI\XEle_SendEvent", "Ptr", hEle
			                                     , "Ptr", hEventEle
			                                     , "Int", nEvent
			                                     , "UPtr", wParam
			                                     , "Ptr", lParam
			                                     , "Int")
		}

		XEle_SetToolTip(hEle, pText) {
			Return DllCall("XCGUI\XEle_SetToolTip", "Ptr", hEle
			                                      , "Str", pText
			                                      , "Ptr")
		}

		XEle_EnableToolTip(hEle, bEnable=True) {
			Return DllCall("XCGUI\XEle_EnableToolTip", "Ptr", hEle
			                                         , "Int", bEnable
			                                         , "Ptr")
		}

		XEle_EnableMouseThrough(hEle, bEnable=True) {
			Return DllCall("XCGUI\XEle_EnableMouseThrough", "Ptr", hEle
			                                              , "Int", bEnable
			                                              , "Ptr")
		}

		XEle_AddEle(hEle, hChildEle) {
			Return DllCall("XCGUI\XEle_AddEle", "Ptr", hEle
			                                  , "Ptr", hChildEle
			                                  , "Int")
		}

		XEle_ShowEle(hEle, bShow=True) {
			Return DllCall("XCGUI\XEle_ShowEle", "Ptr", hEle
			                                   , "Int", bShow
			                                   , "Ptr")
		}

		XEle_GetRect(hEle, ByRef pRect) {
			VarSetCapacity(pRect, 16, 0)
			Return DllCall("XCGUI\XEle_GetRect", "Ptr", hEle
			                                   , "Ptr", &pRect)
		}

		XEle_GetRectLogic(hEle, ByRef pRect) {
			VarSetCapacity(pRect, 16, 0)
			Return DllCall("XCGUI\XEle_GetRectLogic", "Ptr", hEle
			                                        , "Ptr", &pRect)
		}

		XEle_GetWndClientRect(hEle, ByRef pRect) {
			VarSetCapacity(pRect, 16, 0)
			Return DllCall("XCGUI\XEle_GetWndClientRect", "Ptr", hEle
			                                            , "Ptr", &pRect)
		}

		XEle_SetRect(hEle, pRect, bRedraw=True) {
			Return DllCall("XCGUI\XEle_SetRect", "Ptr", hEle
			                                   , "Ptr", pRect
			                                   , "Int", bRedraw
			                                   , "Int")
		}

		XEle_SetRectLogic(hEle, pRect, bRedraw=True) {
			Return DllCall("XCGUI\XEle_SetRectLogic", "Ptr", hEle
			                                        , "Ptr", pRect
			                                        , "Int", bRedraw
			                                        , "Int")
		}

		XEle_GetParent(hEle) {
			Return DllCall("XCGUI\XEle_GetParent", "Ptr", hEle
			                                     , "Ptr")
		}

		XEle_GetParentEle(hEle) {
			Return DllCall("XCGUI\XEle_GetParentEle", "Ptr", hEle
			                                        , "Ptr")
		}

		XEle_GetHWINDOW(hEle) {
			Return DllCall("XCGUI\XEle_GetHWINDOW", "Ptr", hEle
			                                      , "Ptr")
		}

		XEle_GetChildCount(hEle) {
			Return DllCall("XCGUI\XEle_GetChildCount", "Ptr", hEle
			                                         , "Int")
		}

		XEle_GetChildByIndex(hEle, index) {
			Return DllCall("XCGUI\XEle_GetChildByIndex", "Ptr", hEle
			                                           , "Int", index
			                                           , "Ptr")
		}

		XEle_GetChildByID(hEle, id) {
			Return DllCall("XCGUI\XEle_GetChildByID", "Ptr", hEle
			                                        , "Int", id
			                                        , "Ptr")
		}

		XEle_GetType(hEle) {
			Return DllCall("XCGUI\XEle_GetType", "Ptr", hEle
			                                   , "Int")
		}

		XEle_BindLayoutObject(hEle, hLayout) {
			Return DllCall("XCGUI\XEle_BindLayoutObject", "Ptr", hEle
			                                            , "Ptr", hLayout
			                                            , "Ptr")
		}

		XEle_Destroy(hEle) {
			Return DllCall("XCGUI\XEle_Destroy", "Ptr", hEle
			                                   , "Ptr")
		}

		XEle_SetLayoutWidth(hEle, nFlag=1, nWidth=0) {
			Return DllCall("XCGUI\XEle_SetLayoutWidth", "Ptr", hEle
			                                          , "Int", nFlag
			                                          , "Int", nWidth
			                                          , "Ptr")
		}

		XEle_SetLayoutHeight(hEle, nFlag=1, nHeight=0) {
			Return DllCall("XCGUI\XEle_SetLayoutHeight", "Ptr", hEle
			                                           , "Int", nFlag
			                                           , "Int", nHeight
			                                           , "Ptr")
		}

		XEle_SetCapture(hEle, b=True) {
			Return DllCall("XCGUI\XEle_SetCapture", "Ptr", hEle
			                                      , "Int", b
			                                      , "Ptr")
		}

		XEle_PostEvent(hEle, hEventEle, nEvent, wParam, lParam) {
			Return DllCall("XCGUI\XEle_PostEvent", "Ptr", hEle
			                                     , "Ptr", hEventEle
			                                     , "Int", nEvent
			                                     , "UPtr", wParam
			                                     , "Ptr", lParam
			                                     , "Int")
		}

		XEle_GetClientRect(hEle, ByRef pRect) {
			VarSetCapacity(pRect, 16, 0)
			Return DllCall("XCGUI\XEle_GetClientRect", "Ptr", hEle
			                                         , "Ptr", &pRect
			                                         , "Ptr")
		}

		XEle_GetLayoutObject(hEle) {
			Return DllCall("XCGUI\XEle_GetLayoutObject", "Ptr", hEle
			                                           , "Ptr")
		}

		XEle_EnableEvent_XE_PAINT_END(hEle, bEnable) {
			Return DllCall("XCGUI\XEle_EnableEvent_XE_PAINT_END", "Ptr", hEle
			                                                    , "Int", bEnable
			                                                    , "Ptr")
		}

		XEle_GetBkInfoManager(hEle) {
			Return DllCall("XCGUI\XEle_GetBkInfoManager", "Ptr", hEle
			                                            , "Ptr")
		}

		XEle_SetAlpha(hEle, alpha) {
			Return DllCall("XCGUI\XEle_SetAlpha", "Ptr", hEle
			                                    , "UChar", alpha
			                                    , "Ptr")
		}

		XEle_IsShow(hEle) {
			Return DllCall("XCGUI\XEle_IsShow", "Ptr", hEle
			                                  , "Int")
		}

		XEle_SetZOrder(hEle, index) {
			Return DllCall("XCGUI\XEle_SetZOrder", "Ptr", hEle
			                                     , "Int", index
			                                     , "Int")
		}

		XEle_SetZOrderEx(hEle, hDestEle, nType) {
			Return DllCall("XCGUI\XEle_SetZOrderEx", "Ptr", hEle
			                                       , "Ptr", hDestEle
			                                       , "Int", nType
			                                       , "Int")
		}

		XEle_HitChildEle(hEle, pPt) {
			Return DllCall("XCGUI\XEle_HitChildEle", "Ptr", hEle
			                                       , "Ptr", pPt
			                                       , "Ptr")
		}

		XEle_GetStateFlags(hEle) {
			Return DllCall("XCGUI\XEle_GetStateFlags", "Ptr", hEle
			                                         , "Int")
		}

		XEle_GetID(hEle) {
			Return DllCall("XCGUI\XEle_GetID", "Ptr", hEle
			                                 , "Int")
		}

		XEle_GetFont(hEle) {
			Return DllCall("XCGUI\XEle_GetFont", "Ptr", hEle
			                                   , "Ptr")
		}

		XEle_EnableKeyTab(hEle, bEnable=1) {
			Return DllCall("XCGUI\XEle_EnableKeyTab", "Ptr", hEle
			                                        , "Int", bEnable)
		}

		XEle_EnableSwitchFocus(hEle, bEnable=1) {
			Return DllCall("XCGUI\XEle_EnableSwitchFocus", "Ptr", hEle
			                                        , "Int", bEnable)
		}

		XEle_IsEnable(hEle) {
			Return DllCall("XCGUI\XEle_IsEnable", "Ptr", hEle)
		}

		XEle_IsBkTransparent(hEle) {
			Return DllCall("XCGUI\XEle_IsBkTransparent", "Ptr", hEle)
		}

		XEle_EnableDrawBorder(hEle, bEnable) {
			Return DllCall("XCGUI\XEle_EnableDrawBorder", "Ptr", hEle
                                                                    , "Int", bEnable)
                }

        XEle_GetBkManager(hEle){
			Return DllCall("XCGUI\XEle_GetBkManager", "Ptr", hEle)
        }

		XEle_RemoveEle(hEle){
			Return DllCall("XCGUI\XEle_RemoveEle", "Ptr", hEle)
		}

	;--------------------------------------------------------------------------
	; ____      ___ ________                              ________                     
	; `MM(      )M' `MMMMMMMb.                            `MMMMMMMb.                   
	;  `MM.     d'   MM    `Mb                             MM    `Mb                   
	;   `MM.   d'    MM     MM ___  __   _____     __      MM     MM    ___    ___  __ 
	;    `MM. d'     MM     MM `MM 6MM  6MMMMMb   6MMbMMM  MM    .M9  6MMMMb   `MM 6MM 
	;     `MMd       MM    .M9  MM69 " 6M'   `Mb 6M'`Mb    MMMMMMM(  8M'  `Mb   MM69 " 
	;      dMM.      MMMMMMM9'  MM'    MM     MM MM  MM    MM    `Mb     ,oMM   MM'    
	;     d'`MM.     MM         MM     MM     MM YM.,M9    MM     MM ,6MM9'MM   MM     
	;    d'  `MM.    MM         MM     MM     MM  YMM9     MM     MM MM'   MM   MM     
	;   d'    `MM.   MM         MM     YM.   ,M9 (M        MM    .M9 MM.  ,MM   MM     
	; _M(_    _)MM_ _MM_       _MM_     YMMMMM9   YMMMMb. _MMMMMMM9' `YMMM9'Yb._MM_    
	;                                            6M    Yb                              
	;                                            YM.   d9                              
	;                                             YMMMM9                               
	; 
	;--------------------------------------------------------------------------
		XProgBar_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XProgBar_Create", "Int", x
			                                      , "Int", y
			                                      , "Int", cx
			                                      , "Int", cy
			                                      , "Ptr", hParent
			                                      , "Ptr")
		}

		XProgBar_SetPos(hEle, pos) {
			Return DllCall("XCGUI\XProgBar_SetPos", "Ptr", hEle
			                                      , "Int", pos
			                                      , "Ptr")
		}

		XProgBar_SetRange(hEle, range) {
			Return DllCall("XCGUI\XProgBar_SetRange", "Ptr", hEle
			                                        , "Int", range
			                                        , "Ptr")
		}

		XProgBar_SetSpaceTwo(hEle, leftSize, rightSize) {
			Return DllCall("XCGUI\XProgBar_SetSpaceTwo", "Ptr", hEle
			                                           , "Int", leftSize
			                                           , "Int", rightSize
			                                           , "Ptr")
		}

		XProgBar_GetPos(hEle) {
			Return DllCall("XCGUI\XProgBar_GetPos", "Ptr", hEle
			                                      , "Int")
		}


	                                                              
	;--------------------------------------------------------------------------
	; ____      ___ ____                                            
	; `MM(      )M' `MM'                                            
	;  `MM.     d'   MM                                             
	;   `MM.   d'    MM ___  __    __      ___      __       ____   
	;    `MM. d'     MM `MM 6MMb  6MMb   6MMMMb    6MMbMMM  6MMMMb  
	;     `MMd       MM  MM69 `MM69 `Mb 8M'  `Mb  6M'`Mb   6M'  `Mb 
	;      dMM.      MM  MM'   MM'   MM     ,oMM  MM  MM   MM    MM 
	;     d'`MM.     MM  MM    MM    MM ,6MM9'MM  YM.,M9   MMMMMMMM 
	;    d'  `MM.    MM  MM    MM    MM MM'   MM   YMM9    MM       
	;   d'    `MM.   MM  MM    MM    MM MM.  ,MM  (M       YM    d9 
	; _M(_    _)MM_ _MM__MM_  _MM_  _MM_`YMMM9'Yb. YMMMMb.  YMMMM9  
	;                                             6M    Yb          
	;                                             YM.   d9          
	;                                              YMMMM9           
	; 
	;--------------------------------------------------------------------------
		XImage_LoadFile(pImageName, bStretch=False) {
			Return DllCall("XCGUI\XImage_LoadFile", "Str", pImageName
			                                      , "Int", bStretch
			                                      , "Ptr")
		}
		
		XImage_LoadZip(pZipFileName, pImageName, pPassword, bStretch=False){
			Return DllCall("XCGUI\XImage_LoadZip", "Str", pZipFileName
														, "Str", pImageName
														, "Str", pPassword
														, "Int", bStretch
														, "Ptr")
		}

		XImage_LoadFileRect(pImageName, x, y, cx, cy) {
			Return DllCall("XCGUI\XImage_LoadFileRect", "Str", pImageName
			                                          , "Int", x
			                                          , "Int", y
			                                          , "Int", cx
			                                          , "Int", cy
			                                          , "Ptr")
		}

		XImage_LoadRes(id, pType, bStretch=False) {
			Return DllCall("XCGUI\XImage_LoadRes", "Int", id
			                                     , "Str", pType
			                                     , "Int", bStretch
			                                     , "Ptr")
		}

		XImage_SetDrawType(hImage, nType=0) {
			Return DllCall("XCGUI\XImage_SetDrawType", "Ptr", hImage
			                                         , "Int", nType
			                                         , "Int")
		}

		XImage_SetDrawTypeAdaptive(hImage, leftSize, topSize, rightSize, bottomSize) {
			Return DllCall("XCGUI\XImage_SetDrawTypeAdaptive", "Ptr", hImage
			                                                 , "Int", leftSize
			                                                 , "Int", topSize
			                                                 , "Int", rightSize
			                                                 , "Int", bottomSize
			                                                 , "Int")
		}

		XImage_LoadFileAdaptive(pImageName, leftSize=0, topSize=0, rightSize=0, bottomSize=0) {
			Return DllCall("XCGUI\XImage_LoadFileAdaptive", "Str", pImageName
			                                              , "Int", leftSize
			                                              , "Int", topSize
			                                              , "Int", rightSize
			                                              , "Int", bottomSize
			                                              , "Ptr")
		}

		XImage_IsStretch(hImage) {
			Return DllCall("XCGUI\XImage_IsStretch", "Ptr", hImage
			                                       , "Int")
		}

		XImage_SetTranColorEx(hImage, color, tranColor=255) {
			Return DllCall("XCGUI\XImage_SetTranColorEx", "Ptr", hImage
			                                            , "UInt", color
			                                            , "UChar", tranColor
			                                            , "Ptr")
		}


	                                                   
	;--------------------------------------------------------------------------
	; ____      ___ ________                             
	; `MM(      )M' `MMMMMMM                             
	;  `MM.     d'   MM    \                       /     
	;   `MM.   d'    MM        _____   ___  __    /M     
	;    `MM. d'     MM   ,   6MMMMMb  `MM 6MMb  /MMMMM  
	;     `MMd       MMMMMM  6M'   `Mb  MMM9 `Mb  MM     
	;      dMM.      MM   `  MM     MM  MM'   MM  MM     
	;     d'`MM.     MM      MM     MM  MM    MM  MM     
	;    d'  `MM.    MM      MM     MM  MM    MM  MM     
	;   d'    `MM.   MM      YM.   ,M9  MM    MM  YM.  , 
	; _M(_    _)MM_ _MM_      YMMMMM9  _MM_  _MM_  YMMM9 
	; 
	;--------------------------------------------------------------------------
		XFont_Create2(pName, size=12, bBold=False, bItalic=False, bUnderline=False, bStrikeOut=False) {
			Return DllCall("XCGUI\XFont_Create2", "Str", pName
			                                    , "Int", size
			                                    , "Int", bBold
			                                    , "Int", bItalic
			                                    , "Int", bUnderline
			                                    , "Int", bStrikeOut
			                                    , "Ptr")
		}
					
		XFont_CreateFromHFONT(hFont) {
			Return DllCall("XCGUI\XFont_CreateFromHFONT", "Ptr", hFont
			                                            , "Ptr")
		}

		XFont_Destroy(hFontX) {
			Return DllCall("XCGUI\XFont_Destroy", "Ptr", hFontX
			                                    , "Ptr")
		}

		XFont_CreateFromFile(pFontFile, size, style) {
			Return DllCall("XCGUI\XFont_CreateFromFile", "Str", pFontFile
								   , "Int", size
								   , "Int", style)
		}
	                                                                                                 
	;--------------------------------------------------------------------------
	; ____      ___   ____   ___                                    __________                             
	; `MM(      )M'  6MMMMb\ `MM                                    MMMMMMMMMM                             
	;  `MM.     d'  6M'    `  MM                                    /   MM   \                       /     
	;   `MM.   d'   MM        MM  __      ___    __ ____     ____       MM       ____   ____   ___  /M     
	;    `MM. d'    YM.       MM 6MMb   6MMMMb   `M6MMMMb   6MMMMb      MM      6MMMMb  `MM(   )P' /MMMMM  
	;     `MMd       YMMMMb   MMM9 `Mb 8M'  `Mb   MM'  `Mb 6M'  `Mb     MM     6M'  `Mb  `MM` ,P    MM     
	;      dMM.          `Mb  MM'   MM     ,oMM   MM    MM MM    MM     MM     MM    MM   `MM,P     MM     
	;     d'`MM.          MM  MM    MM ,6MM9'MM   MM    MM MMMMMMMM     MM     MMMMMMMM    `MM.     MM     
	;    d'  `MM.         MM  MM    MM MM'   MM   MM    MM MM           MM     MM          d`MM.    MM     
	;   d'    `MM.  L    ,M9  MM    MM MM.  ,MM   MM.  ,M9 YM    d9     MM     YM    d9   d' `MM.   YM.  , 
	; _M(_    _)MM_ MYMMMM9  _MM_  _MM_`YMMM9'Yb. MMYMMM9   YMMMM9     _MM_     YMMMM9  _d_  _)MM_   YMMM9 
	;                                             MM                                                       
	;                                             MM                                                       
	;                                            _MM_                                                      
	;
	;--------------------------------------------------------------------------
		XShapeText_Create(x, y, cx, cy, pName, hParent) {
			Return DllCall("XCGUI\XShapeText_Create", "Int", x
			                                        , "Int", y
			                                        , "Int", cx
			                                        , "Int", cy
			                                        , "UShort", &pName
			                                        , "Ptr", hParent
			                                        , "Ptr")
		}

		XShapeText_SetText(hTextBlock, pName) {
			Return DllCall("XCGUI\XShapeText_SetText", "Ptr", hTextBlock
			                                         , "Str", pName)
		}

		XShapeText_SetFont(hTextBlock, hFontx) {
			Return DllCall("XCGUI\XShapeText_SetFont", "Ptr", hTextBlock
			                                         , "Ptr", hFontx)
		}

		XShapeText_SetTextColor(hTextBlock, color, alpha=255) {
			static XShapeText_SetTextColor := xc._GetProcAddress("XShapeText_SetTextColor")
			Return DllCall(XShapeText_SetTextColor, "Ptr", hTextBlock
			                                      , "UInt", color
			                                      , "UChar", alpha
			                                      , "Ptr")
		}

		XShapeText_SetTextAlign(hTextBlock, align) {
			Return DllCall("XCGUI\XShapeText_SetTextAlign", "Ptr", hTextBlock
			                                              , "Int", align
			                                              , "Ptr")
		}

		XShapeText_SetOffset(hTextBlock, x, y) {
			Return DllCall("XCGUI\XShapeText_SetOffset", "Ptr", hTextBlock
			                                           , "Int", x
			                                           , "Int", y
			                                           , "Ptr")
		}

		XShapeText_SetLayoutHeight(hTextBlock, nType, height) {
			Return DllCall("XCGUI\XShapeText_SetLayoutHeight", "Ptr", hTextBlock
			                                                 , "Int", nType
			                                                 , "Int", height)
		}

		XShapeText_SetLayoutWidth(hTextBlock, nType, width) {
			Return DllCall("XCGUI\XShapeText_SetLayoutWidth", "Ptr", hTextBlock
			                                                , "Int", nType
			                                                , "Int", width)
		}

		XShapeText_GetText(hTextBlock, ByRef pOut, ByRef nOutLen := 520) {
			static XShapeText_GetText := xc._GetProcAddress("XShapeText_GetText")
			nOutLen := 520
			VarSetCapacity(pOut, nOutLen, 0)
			ret := DllCall(XShapeText_GetText, "Ptr", hTextBlock
			                                 , "Str", pOut
			                                 , "Int", nOutLen
			                                 , "Ptr")
			Return ret, pOut := StrGet(&pOut, nOutLen)
		}



	;--------------------------------------------------------------------------
	; ____      ___   ____   ___                                    ________                
	; `MM(      )M'  6MMMMb\ `MM                                    `MMMMMMMb. 68b          
	;  `MM.     d'  6M'    `  MM                                     MM    `Mb Y89          
	;   `MM.   d'   MM        MM  __      ___    __ ____     ____    MM     MM ___   ____   
	;    `MM. d'    YM.       MM 6MMb   6MMMMb   `M6MMMMb   6MMMMb   MM     MM `MM  6MMMMb. 
	;     `MMd       YMMMMb   MMM9 `Mb 8M'  `Mb   MM'  `Mb 6M'  `Mb  MM    .M9  MM 6M'   Mb 
	;      dMM.          `Mb  MM'   MM     ,oMM   MM    MM MM    MM  MMMMMMM9'  MM MM    `' 
	;     d'`MM.          MM  MM    MM ,6MM9'MM   MM    MM MMMMMMMM  MM         MM MM       
	;    d'  `MM.         MM  MM    MM MM'   MM   MM    MM MM        MM         MM MM       
	;   d'    `MM.  L    ,M9  MM    MM MM.  ,MM   MM.  ,M9 YM    d9  MM         MM YM.   d9 
	; _M(_    _)MM_ MYMMMM9  _MM_  _MM_`YMMM9'Yb. MMYMMM9   YMMMM9  _MM_       _MM_ YMMMM9  
	;                                             MM                                        
	;                                             MM                                        
	;                                            _MM_                                       
	;
	;--------------------------------------------------------------------------
		XShapePic_Create(x=0, y=0, cx=80, cy=25, hParent=0) {
			Return DllCall("XCGUI\XShapePic_Create", "Int", x
			                                       , "Int", y
			                                       , "Int", cx
			                                       , "Int", cy
			                                       , "Ptr", hParent
			                                       , "Ptr")
		}

		XShapePic_SetImage(hShape, hImage) {
			Return DllCall("XCGUI\XShapePic_SetImage", "Ptr", hShape
			                                         , "Ptr", hImage
			                                         , "Ptr")
		}



	                                                                                 
	;--------------------------------------------------------------------------
	; ____      ___ ________                 ___       __________      ___             
	; `MM(      )M' `MMMMMMMb.  68b          `MM       `MMMMMMMMM      `MM 68b         
	;  `MM.     d'   MM    `Mb  Y89           MM        MM      \       MM Y89   /     
	;   `MM.   d'    MM     MM  ___   ____    MM  __    MM          ____MM ___  /M     
	;    `MM. d'     MM     MM  `MM  6MMMMb.  MM 6MMb   MM    ,    6MMMMMM `MM /MMMMM  
	;     `MMd       MM    .M9   MM 6M'   Mb  MMM9 `Mb  MMMMMMM   6M'  `MM  MM  MM     
	;      dMM.      MMMMMMM9'   MM MM    `'  MM'   MM  MM    `   MM    MM  MM  MM     
	;     d'`MM.     MM  \M\     MM MM        MM    MM  MM        MM    MM  MM  MM     
	;    d'  `MM.    MM   \M\    MM MM        MM    MM  MM        MM    MM  MM  MM     
	;   d'    `MM.   MM    \M\   MM YM.   d9  MM    MM  MM      / YM.  ,MM  MM  YM.  , 
	; _M(_    _)MM_ _MM_    \M\__MM_ YMMMM9  _MM_  _MM__MMMMMMMMM  YMMMMMM__MM_  YMMM9 
	; 
	;--------------------------------------------------------------------------
		XRichEdit_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XRichEdit_Create", "Int", x
			                                       , "Int", y
			                                       , "Int", cx
			                                       , "Int", cy
			                                       , "Ptr", hParent
			                                       , "Ptr")
		}

		XRichEdit_SetText(hEle, pName) {
			Return DllCall("XCGUI\XRichEdit_SetText", "Ptr", hEle
			                                        , "Str", pName
			                                        , "Ptr")
		}

		XRichEdit_GetText(hEle, ByRef pOut, len=520) {
			VarSetCapacity(pOut, len, 0)
			Return DllCall("XCGUI\XRichEdit_GetText", "Ptr", hEle
			                                        , "Str", pOut
			                                        , "Int", len
			                                        , "Int")
		}

		XRichEdit_DeleteAll(hEle) {
			Return DllCall("XCGUI\XRichEdit_DeleteAll", "Ptr", hEle
			                                          , "Ptr")
		}

		XRichEdit_EnableMultiLine(hEle, bEnable=True) {
			Return DllCall("XCGUI\XRichEdit_EnableMultiLine", "Ptr", hEle
			                                                , "Int", bEnable
			                                                , "Ptr")
		}

		XRichEdit_EnableAutoWrap(hEle, bEnable=True) {
			Return DllCall("XCGUI\XRichEdit_EnableAutoWrap", "Ptr", hEle
			                                               , "Int", bEnable
			                                               , "Ptr")
		}

		XRichEdit_EnableReadOnly(hEle, bEnable=True) {
			Return DllCall("XCGUI\XRichEdit_EnableReadOnly", "Ptr", hEle
			                                               , "Int", bEnable
			                                               , "Ptr")
		}

		XRichEdit_InsertString(hEle, pString, pFont="", color="") {
			Return DllCall("XCGUI\XRichEdit_InsertString", "Ptr", hEle
			                                             , "Ptr", &pString
			                                             , "Ptr", pFont
			                                             , "UInt", color
			                                             , "Ptr")
		}

		XRichEdit_EnablePassword(hEle, bEnable=True) {
			Return DllCall("XCGUI\XRichEdit_EnablePassword", "Ptr", hEle
			                                               , "Int", bEnable
			                                               , "Ptr")
		}

		XRichEdit_EnableKeyTab(hEle, bEnable=True) {
			Return DllCall("XCGUI\XRichEdit_EnableKeyTab", "Ptr", hEle
			                                             , "Int", bEnable
			                                             , "Ptr")
		}

		XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(hEle, bEnable=True) {
			Return DllCall("XCGUI\XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE", "Ptr", hEle
			                                                               , "Int", bEnable
			                                                               , "Ptr")
		}

		XRichEdit_IsEmpty(hEle) {
			static XRichEdit_IsEmpty := xc._GetProcAddress("XRichEdit_IsEmpty")
			Return DllCall(XRichEdit_IsEmpty, "Ptr", hEle
			                                , "Ptr")
		}

		XRichEdit_SelectAll(hEle) {
			Return DllCall("XCGUI\XRichEdit_SelectAll", "Ptr", hEle
			                                          , "Int")
		}

		XRichEdit_EnableAutoSelAll(hEle, bEnable=True) {
			Return DllCall("XCGUI\XRichEdit_EnableAutoSelAll", "Ptr", hEle
			                                                 , "Int", bEnable)
		}
                XRichEdit_SetLimitNum(hEle, nNumber) {
                        Return DllCall("XCGUI\XRichEdit_SetLimitNum", "Ptr", hEle
                                                                    , "Int", nNumber)
                }

		XRichEdit_GetTextLength(hEle) {
                        Return DllCall("XCGUI\XRichEdit_GetTextLength", "Ptr", hEle)                
                }
		
		XRichEdit_SetDefaultText(hEle, pString) {
			Return DllCall("XCGUI\XRichEdit_SetDefaultText", "Ptr", hEle, "Str", pString)
		}

		XRichEdit_SetDefaultTextColor(hEle, color, alpha) {
			Return DllCall("XCGUI\XRichEdit_SetDefaultTextColor", "Ptr", hEle
									    , "UInt", color
									    , "UChar", alpha)
		}

		XRichEdit_InsertStringEx(hEle, iRow, iColumn, pString, hFont) {
			Return DllCall("XCGUI\XRichEdit_InsertStringEx", "Ptr", hEle
																						, "Int", iRow
																						, "Int", iColumn
																						, "Str", pString
																						, "Ptr", hFont)
		}
	                                                        
	;--------------------------------------------------------------------------
	; ____      ___ ___       ___                             
	; `MM(      )M' `MMb     dMM'                             
	;  `MM.     d'   MMM.   ,PMM                              
	;   `MM.   d'    M`Mb   d'MM   ____   ___  __   ___   ___ 
	;    `MM. d'     M YM. ,P MM  6MMMMb  `MM 6MMb  `MM    MM 
	;     `MMd       M `Mb d' MM 6M'  `Mb  MMM9 `Mb  MM    MM 
	;      dMM.      M  YM.P  MM MM    MM  MM'   MM  MM    MM 
	;     d'`MM.     M  `Mb'  MM MMMMMMMM  MM    MM  MM    MM 
	;    d'  `MM.    M   YP   MM MM        MM    MM  MM    MM 
	;   d'    `MM.   M   `'   MM YM    d9  MM    MM  YM.   MM 
	; _M(_    _)MM_ _M_      _MM_ YMMMM9  _MM_  _MM_  YMMM9MM_
	; 
	;--------------------------------------------------------------------------
		XMenu_Create() {
			Return DllCall("XCGUI\XMenu_Create", "Ptr")
		}

		XMenu_AddItem(hMenu, nID, pText, nParentID="", uFlags="") {
			Return DllCall("XCGUI\XMenu_AddItem", "Ptr", hMenu
			                                    , "Int", nID
			                                    , "Str", pText
			                                    , "Int", nParentID
			                                    , "Int", uFlags
			                                    , "Ptr")
		}

		XMenu_InsertItem(hMenu, nID, pText, uFlags="", insertID="") {
			Return DllCall("XCGUI\XMenu_InsertItem", "Ptr", hMenu
			                                       , "Int", nID
			                                       , "Str", pText
			                                       , "Int", uFlags
			                                       , "Int", insertID
			                                       , "Ptr")
		}

		XMenu_Popup(hMenu, hParentWnd, x, y, hParentEle="", uFlags=0) {
			Return DllCall("XCGUI\XMenu_Popup", "Ptr", hMenu
			                                  , "Ptr", hParentWnd
			                                  , "Int", x
			                                  , "Int", y
			                                  , "Ptr", hParentEle
			                                  , "Int", uFlags
			                                  , "Int")
		}

		XMenu_SetAutoDestroy(hMenu, bAuto) {
			Return DllCall("XCGUI\XMenu_SetAutoDestroy", "Ptr", hMenu
			                                           , "Int", bAuto
			                                           , "Ptr")
		}

		XMenu_SetBkImage(hMenu, hImage) {
			Return DllCall("XCGUI\XMenu_SetBkImage", "Ptr", hMenu
			                                       , "Ptr", hImage
			                                       , "Ptr")
		}

		XMenu_SetBorderColor(hMenu, color, alpha=255) {
			Return DllCall("XCGUI\XMenu_SetBorderColor", "Ptr", hMenu
			                                           , "UInt", color
			                                           , "UChar", alpha
			                                           , "Ptr")
		}

		XMenu_SetItemIcon(hMenu, nID, hIcon) {
			Return DllCall("XCGUI\XMenu_SetItemIcon", "Ptr", hMenu
			                                        , "Int", nID
			                                        , "Ptr", hIcon
			                                        , "Int")
		}



	;--------------------------------------------------------------------------
	; ____      ___   ____   ________                     
	; `MM(      )M'  6MMMMb\ `MMMMMMMb.                   
	;  `MM.     d'  6M'    `  MM    `Mb                   
	;   `MM.   d'   MM        MM     MM    ___    ___  __ 
	;    `MM. d'    YM.       MM    .M9  6MMMMb   `MM 6MM 
	;     `MMd       YMMMMb   MMMMMMM(  8M'  `Mb   MM69 " 
	;      dMM.          `Mb  MM    `Mb     ,oMM   MM'    
	;     d'`MM.          MM  MM     MM ,6MM9'MM   MM     
	;    d'  `MM.         MM  MM     MM MM'   MM   MM     
	;   d'    `MM.  L    ,M9  MM    .M9 MM.  ,MM   MM     
	; _M(_    _)MM_ MYMMMM9  _MMMMMMM9' `YMMM9'Yb._MM_    
	; 
	;--------------------------------------------------------------------------
		XSBar_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XSBar_Create", "Int", x
			                                   , "Int", y
			                                   , "Int", cx
			                                   , "Int", cy
			                                   , "Ptr", hParent
			                                   , "Ptr")
		}

		XSBar_SetHorizon(hEle, bHorizon) {
			Return DllCall("XCGUI\XSBar_SetHorizon", "Ptr", hEle
			                                       , "Int", bHorizon
			                                       , "Int")
		}

		XSBar_GetButtonUp(hEle) {
			Return DllCall("XCGUI\XSBar_GetButtonUp", "Ptr", hEle
			                                        , "Ptr")
		}

		XSBar_GetButtonDown(hEle) {
			Return DllCall("XCGUI\XSBar_GetButtonDown", "Ptr", hEle
			                                          , "Ptr")
		}

		XSBar_GetButtonSlider(hEle) {
			Return DllCall("XCGUI\XSBar_GetButtonSlider", "Ptr", hEle
			                                            , "Ptr")
		}

		XSBar_GetSliderMaxLength(hEle) {
			Return DllCall("XCGUI\XSBar_GetSliderMaxLength", "Ptr", hEle
			                                               , "Ptr")
		}

		XSBar_GetRange(hEle) {
			Return DllCall("XCGUI\XSBar_GetRange", "Ptr", hEle
			                                     , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___   ____   ____     ___                               
	; `MM(      )M'  6MMMMb\ `Mb(     )d' 68b                           
	;  `MM.     d'  6M'    `  YM.     ,P  Y89                           
	;   `MM.   d'   MM        `Mb     d'  ___   ____   ____    _    ___ 
	;    `MM. d'    YM.        YM.   ,P   `MM  6MMMMb  `MM(   ,M.   )M' 
	;     `MMd       YMMMMb    `Mb   d'    MM 6M'  `Mb  `Mb   dMb   d'  
	;      dMM.          `Mb    YM. ,P     MM MM    MM   YM. ,PYM. ,P   
	;     d'`MM.          MM    `Mb d'     MM MMMMMMMM   `Mb d'`Mb d'   
	;    d'  `MM.         MM     YM,P      MM MM          YM,P  YM,P    
	;   d'    `MM.  L    ,M9     `MM'      MM YM    d9    `MM'  `MM'    
	; _M(_    _)MM_ MYMMMM9       YP      _MM_ YMMMM9      YP    YP     
	;
	;--------------------------------------------------------------------------
		XSView_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XSView_Create", "Int", x
			                                    , "Int", y
			                                    , "Int", cx
			                                    , "Int", cy
			                                    , "Ptr", hParent
			                                    , "Ptr")
		}

		XSView_GetTotalSize(hEle, ByRef pSize) {
			VarSetCapacity(pSize, 8, 0)
			Return DllCall("XCGUI\XSView_GetTotalSize", "Ptr", hEle
			                                          , "Ptr", &pSize
			                                          , "Ptr")
		}

		XSView_SetTotalSize(hEle, cx, cy) {
			Return DllCall("XCGUI\XSView_SetTotalSize", "Ptr", hEle
			                                          , "Int", cx
			                                          , "Int", cy
			                                          , "Int")
		}

		XSView_SetLineSize(hEle, nHeight, nWidth) {
			Return DllCall("XCGUI\XSView_SetLineSize", "Ptr", hEle
			                                         , "Int", nHeight
			                                         , "Int", nWidth
			                                         , "Int")
		}

		XSView_ShowSBarV(hEle, bShow) {
			Return DllCall("XCGUI\XSView_ShowSBarV", "Ptr", hEle
			                                       , "Int", bShow
			                                       , "Ptr")
		}

		XSView_GetScrollBarH(hEle) {
			Return DllCall("XCGUI\XSView_GetScrollBarH", "Ptr", hEle
			                                           , "Ptr")
		}

		XSView_GetScrollBarV(hEle) {
			Return DllCall("XCGUI\XSView_GetScrollBarV", "Ptr", hEle
			                                           , "Ptr")
		}

		XSView_EnableAutoShowScrollBar(hEle, bEnable=True) {
			Return DllCall("XCGUI\XSView_EnableAutoShowScrollBar", "Ptr", hEle
			                                                     , "Int", bEnable
			                                                     , "Ptr")
		}

		XSView_ShowSBarH(hEle, bShow=True) {
			Return DllCall("XCGUI\XSView_ShowSBarH", "Ptr", hEle
			                                       , "Int", bShow
			                                       , "Ptr")
		}

		XSView_SetPadding(hEle, left, top, right, bottom) {
			Return DllCall("XCGUI\XSView_SetPadding", "Ptr", hEle
			                                        , "Int", left
			                                        , "Int", top
			                                        , "Int", right
			                                        , "Int", bottom
			                                        , "Ptr")
		}

		XSView_GetPadding(hEle, ByRef pPadding) {
			VarSetCapacity(pPadding, 16, 0)
			DllCall("XCGUI\XSView_GetPadding", "Ptr", hEle
			                                 , "Ptr", &pPadding)
		}

		XSView_ScrollLeftLine(hEle) {
			Return DllCall("XCGUI\XSView_ScrollLeftLine", "Ptr", hEle)
		}

		XSView_ScrollRightLine(hEle) {
			Return DllCall("XCGUI\XSView_ScrollRightLine", "Ptr", hEle)
		}

		XSView_ScrollTopLine(hEle) {
			Return DllCall("XCGUI\XSView_ScrollTopLine", "Ptr", hEle)
		}

		XSView_ScrollBottomLine(hEle) {
			Return DllCall("XCGUI\XSView_ScrollBottomLine", "Ptr", hEle)
		}

		XSView_ScrollLeft(hEle) {
			Return DllCall("XCGUI\XSView_ScrollLeft", "Ptr", hEle)
		}

		XSView_ScrollRight(hEle) {
			Return DllCall("XCGUI\XSView_ScrollRight", "Ptr", hEle)
		}

		XSView_ScrollTop(hEle) {
			Return DllCall("XCGUI\XSView_ScrollTop", "Ptr", hEle)
		}

		XSView_ScrollBottom(hEle) {
			Return DllCall("XCGUI\XSView_ScrollBottom", "Ptr", hEle)
		}



	;--------------------------------------------------------------------------
	; ____      ___ ____                          
	; `MM(      )M' `MM'     68b                  
	;  `MM.     d'   MM      Y89            /     
	;   `MM.   d'    MM      ___   ____    /M     
	;    `MM. d'     MM      `MM  6MMMMb\ /MMMMM  
	;     `MMd       MM       MM MM'    `  MM     
	;      dMM.      MM       MM YM.       MM     
	;     d'`MM.     MM       MM  YMMMMb   MM     
	;    d'  `MM.    MM       MM      `Mb  MM     
	;   d'    `MM.   MM    /  MM L    ,MM  YM.  , 
	; _M(_    _)MM_ _MMMMMMM _MM_MYMMMM9    YMMM9 
	;
	;--------------------------------------------------------------------------
		XList_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XList_Create", "Int", x
			                                   , "Int", y
			                                   , "Int", cx
			                                   , "Int", cy
			                                   , "Ptr", hParent
			                                   , "Ptr")
		}

		XList_SetItemTemplateXML(hEle, pXmlFile) {
			Return DllCall("XCGUI\XList_SetItemTemplateXML", "Ptr", hEle
			                                               , "Str", pXmlFile
			                                               , "Int")
		}

		XList_AddColumn(hEle, width) {
			Return DllCall("XCGUI\XList_AddColumn", "Ptr", hEle
			                                      , "Int", width
			                                      , "Int")
		}

		XList_BindAdapterHeader(hEle, hAdapter) {
			Return DllCall("XCGUI\XList_BindAdapterHeader", "Ptr", hEle
			                                              , "Ptr", hAdapter
			                                              , "Ptr")
		}

		XList_BindAdapter(hEle, hAdapter) {
			Return DllCall("XCGUI\XList_BindAdapter", "Ptr", hEle
			                                        , "Ptr", hAdapter
			                                        , "Ptr")
		}

		XList_SetColumnWidth(hEle, iItem, width) {
			Return DllCall("XCGUI\XList_SetColumnWidth", "Ptr", hEle
			                                           , "Int", iItem
			                                           , "Int", width
			                                           , "Ptr")
		}

		XList_SetItemHeightDefault(hEle, nHeight, nSelHeight) {
			Return DllCall("XCGUI\XList_SetItemHeightDefault", "Ptr", hEle
			                                                 , "Int", nHeight
			                                                 , "Int", nSelHeight
			                                                 , "Ptr")
		}

		XList_GetAdapter(hEle) {
			Return DllCall("XCGUI\XList_GetAdapter", "Ptr", hEle
			                                       , "Ptr")
		}

		XList_GetSelectAll(hEle, ByRef pArray, nArraySize := "") {
			If !cnt := this.XList_GetSelectItemCount(hEle)
				Return 0

			VarSetCapacity(pArray, nArraySize := cnt*4, 0)
			Return DllCall("XCGUI\XList_GetSelectAll", "Ptr", hEle
			                                         , "Ptr", &pArray
			                                         , "Int", nArraySize
			                                         , "Int")
		}

		XList_SetItemColor(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XList_SetItemColor", "Ptr", hEle
			                                         , "UInt", color
			                                         , "UChar", alpha
			                                         , "Ptr")
		}

		XList_SetItemColorSel(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XList_SetItemColorSel", "Ptr", hEle
			                                            , "UInt", color
			                                            , "UChar", alpha
			                                            , "Ptr")
		}

		XList_SetItemColorStay(hEle, color, alpha=255) {
			Return DllCall("XCGUI\XList_SetItemColorStay", "Ptr", hEle
			                                             , "UInt", color
			                                             , "UChar", alpha
			                                             , "Ptr")
		}

		XList_GetTemplateObject(hEle, iItem, nTempItemID) {
			static XList_GetTemplateObject := xc._GetProcAddress("XList_GetTemplateObject")
			Return DllCall(XList_GetTemplateObject, "Ptr", hEle
			                                      , "Int", iItem
			                                      , "Int", nTempItemID
			                                      , "Ptr")
		}

		XList_GetHeaderHELE(hEle) {
			Return DllCall("XCGUI\XList_GetHeaderHELE", "Ptr", hEle
			                                          , "Ptr")
		}

		XList_GetHeaderTemplateObject(hEle, iItem, nTempItemID) {
			Return DllCall("XCGUI\XList_GetHeaderTemplateObject", "Ptr", hEle
			                                                    , "Int", iItem
			                                                    , "Int", nTempItemID
			                                                    , "Ptr")
		}

		XList_SetSelectItem(hEle, iItem, bSelect) {
			Return DllCall("XCGUI\XList_SetSelectItem", "Ptr", hEle
			                                          , "Int", iItem
			                                          , "Int", bSelect
			                                          , "Int")
		}

		XList_RefreshData(hEle) {
			Return DllCall("XCGUI\XList_RefreshData", "Ptr", hEle
			                                        , "Ptr")
		}

		XList_HitTest(hEle, pPt, ByRef piItem, ByRef piSubItem) {
			static XList_HitTest := xc._GetProcAddress("XList_HitTest")
			Return DllCall(XList_HitTest, "Ptr", hEle
			                            , "Ptr", pPt
			                            , "Int*", piItem
			                            , "Int*", piSubItem
			                            , "Int")
		}

		XList_HitTestOffset(hEle, pPt, ByRef piItem, ByRef piSubItem) {
			static XList_HitTestOffset := xc._GetProcAddress("XList_HitTestOffset")
			Return DllCall(XList_HitTestOffset, "Ptr", hEle
			                                  , "Ptr", pPt
			                                  , "Int*", piItem
			                                  , "Int*", piSubItem
			                                  , "Int")
		}

		XList_AddItemBkBorder(hEle, nState, color, alpha=255, width=1) {
			Return DllCall("xcgui\XList_AddItemBkBorder", "Ptr", hEle
			                                            , "Int", nState
			                                            , "UInt", color
			                                            , "UChar", alpha
			                                            , "Int", width
			                                            , "Ptr")
		}

		XList_AddItemBkFill(hEle, nState, color, alpha=255) {
			Return DllCall("xcgui\XList_AddItemBkFill", "Ptr", hEle
			                                          , "Int", nState
			                                          , "UInt", color
			                                          , "UChar", alpha)
		}

		XList_AddItemBkImage(hEle, nState, hImage) {
			Return DllCall("xcgui\XList_AddItemBkImage", "Ptr", hEle
			                                           , "Int", nState
			                                           , "Ptr", hImage
			                                           , "Ptr")
		}

		XList_SetDrawItemBkFlags(hEle, nFlags) {
			Return DllCall("xcgui\XList_SetDrawItemBkFlags", "Ptr", hEle
			                                               , "Int", nFlags
			                                               , "Ptr")
		}

		XList_GetSelectItemCount(hEle) {
			Return DllCall("xcgui\XList_GetSelectItemCount", "Ptr", hEle
			                                               , "Int")
		}

		XList_GetSelectItem(hEle) {
			Return DllCall("xcgui\XList_GetSelectItem", "Ptr", hEle)
		}

		XList_GetItemIndexFromHXCGUI(hEle, hXCGUI) {
			Return DllCall("xcgui\XList_GetItemIndexFromHXCGUI", "Ptr", hEle
			                                                   , "Ptr", hXCGUI
			                                                   , "Int")
		}

		XList_SetSelectAll(hEle) {
			Return DllCall("xcgui\XList_SetSelectAll", "Ptr", hEle)
		}

		XList_CancelSelectAll(hEle) {
			Return DllCall("xcgui\XList_CancelSelectAll", "Ptr", hEle)
		}

		XList_CancelSelectItem(hEle, iItem) {
			Return DllCall("xcgui\XList_CancelSelectItem", "Ptr", hEle, "Int", iItem)
		}



	;--------------------------------------------------------------------------
	; ____      ___ ____                          ________                        
	; `MM(      )M' `MM'     68b                  `MMMMMMMb.                      
	;  `MM.     d'   MM      Y89            /      MM    `Mb                      
	;   `MM.   d'    MM      ___   ____    /M      MM     MM   _____   ____   ___ 
	;    `MM. d'     MM      `MM  6MMMMb\ /MMMMM   MM    .M9  6MMMMMb  `MM(   )P' 
	;     `MMd       MM       MM MM'    `  MM      MMMMMMM(  6M'   `Mb  `MM` ,P   
	;      dMM.      MM       MM YM.       MM      MM    `Mb MM     MM   `MM,P    
	;     d'`MM.     MM       MM  YMMMMb   MM      MM     MM MM     MM    `MM.    
	;    d'  `MM.    MM       MM      `Mb  MM      MM     MM MM     MM    d`MM.   
	;   d'    `MM.   MM    /  MM L    ,MM  YM.  ,  MM    .M9 YM.   ,M9   d' `MM.  
	; _M(_    _)MM_ _MMMMMMM _MM_MYMMMM9    YMMM9 _MMMMMMM9'  YMMMMM9  _d_  _)MM_ 
	;
	;--------------------------------------------------------------------------
		XListBox_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XListBox_Create", "Int", x
			                                      , "Int", y
			                                      , "Int", cx
			                                      , "Int", cy
			                                      , "Ptr", hParent
			                                      , "Ptr")
		}

		XListBox_SetItemTemplateXML(hEle, pXmlFile) {
			Return DllCall("XCGUI\XListBox_SetItemTemplateXML", "Ptr", hEle
			                                                  , "Str", pXmlFile
			                                                  , "Int")
		}

		XListBox_BindAdapter(hEle, hAdapter) {
			Return DllCall("XCGUI\XListBox_BindAdapter", "Ptr", hEle
			                                           , "Ptr", hAdapter
			                                           , "Ptr")
		}

		XListBox_GetSelectCount(hEle) {
			Return DllCall("XCGUI\XListBox_GetSelectCount", "Ptr", hEle)
		}

		XListBox_GetSelectAll(hEle, ByRef pArray, nArraySize := "") {
			If !cnt := this.XListBox_GetSelectCount(hEle)
				Return 0

			VarSetCapacity(pArray, nArraySize := cnt*4, 0)
			Return DllCall("XCGUI\XListBox_GetSelectAll", "Ptr", hEle
			                                            , "Ptr", &pArray
			                                            , "Int", nArraySize
			                                            , "Int")
		}

		XListBox_GetAdapter(hEle) {
			Return DllCall("XCGUI\XListBox_GetAdapter", "Ptr", hEle
			                                          , "Ptr")
		}

		XListBox_GetTemplateObject(hEle, iItem, nTempItemID) {
			Return DllCall("XCGUI\XListBox_GetTemplateObject", "Ptr", hEle
			                                                 , "Int", iItem
			                                                 , "Int", nTempItemID
			                                                 , "Ptr")
		}

		XListBox_EnableMultiSel(hEle, bEnable) {
			Return DllCall("XCGUI\XListBox_EnableMultiSel", "Ptr", hEle
			                                              , "Int", bEnable
			                                              , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___ ____                          ____     ___                               
	; `MM(      )M' `MM'     68b                  `Mb(     )d' 68b                           
	;  `MM.     d'   MM      Y89            /      YM.     ,P  Y89                           
	;   `MM.   d'    MM      ___   ____    /M      `Mb     d'  ___   ____   ____    _    ___ 
	;    `MM. d'     MM      `MM  6MMMMb\ /MMMMM    YM.   ,P   `MM  6MMMMb  `MM(   ,M.   )M' 
	;     `MMd       MM       MM MM'    `  MM       `Mb   d'    MM 6M'  `Mb  `Mb   dMb   d'  
	;      dMM.      MM       MM YM.       MM        YM. ,P     MM MM    MM   YM. ,PYM. ,P   
	;     d'`MM.     MM       MM  YMMMMb   MM        `Mb d'     MM MMMMMMMM   `Mb d'`Mb d'   
	;    d'  `MM.    MM       MM      `Mb  MM         YM,P      MM MM          YM,P  YM,P    
	;   d'    `MM.   MM    /  MM L    ,MM  YM.  ,     `MM'      MM YM    d9    `MM'  `MM'    
	; _M(_    _)MM_ _MMMMMMM _MM_MYMMMM9    YMMM9      YP      _MM_ YMMMM9      YP    YP     
	;
	;--------------------------------------------------------------------------
		XListView_BindAdapter(hEle, hAdapter) {
			Return DllCall("XCGUI\XListView_BindAdapter", "Ptr", hEle
			                                            , "Ptr", hAdapter
			                                            , "Ptr")
		}

		XListView_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XListView_Create", "Int", x
			                                       , "Int", y
			                                       , "Int", cx
			                                       , "Int", cy
			                                       , "Ptr", hParent
			                                       , "Ptr")
		}

		XListView_ExpandGroup(hEle, iGroup, bExpand=True) {
			Return DllCall("XCGUI\XListView_ExpandGroup", "Ptr", hEle
			                                            , "Int", iGroup
			                                            , "Int", bExpand
			                                            , "Int")
		}

		XListView_GetAdapter(hEle) {
			Return DllCall("XCGUI\XListView_GetAdapter", "Ptr", hEle
			                                           , "Ptr")
		}

		XListView_HitTestOffset(hEle, pPt, ByRef pOutGroup, ByRef pOutItem) {
			/*
				VarSetCapacity(pPt, 8)
				MouseGetPos, x, y
				NumPut(x, pPt, 0)
				NumPut(y, pPt, 4)
				xc.XListView_HitTestOffset(m_hListView, &pPt, nGroup, nItem)
				MsgBox, % nGroup "-" nItem
			*/
			Return DllCall("XCGUI\XListView_HitTestOffset", "Ptr", hEle
			                                              , "Ptr", pPt
			                                              , "Int*", pOutGroup
			                                              , "Int*", pOutItem
			                                              , "Int")
		}

		XListView_GetGroupHeight(hEle) {
			Return DllCall("XCGUI\XListView_GetGroupHeight", "Ptr", hEle
			                                               , "Int")
		}

		XListView_GetSelectItem(hEle, ByRef piGroup, ByRef piItem) {
			Return DllCall("XCGUI\XListView_GetSelectItem", "Ptr", hEle
			                                              , "Int*", piGroup
			                                              , "Int*", piItem
			                                              , "Int")
		}

		XListView_GetTemplateObject(hEle, iGroup, iItem, nTempItemID) {
			Return DllCall("XCGUI\XListView_GetTemplateObject", "Ptr", hEle
			                                                  , "Int", iGroup
			                                                  , "Int", iItem
			                                                  , "Int", nTempItemID
			                                                  , "Ptr")
		}

		XListView_GetTemplateObjectGroup(hEle, iGroup, nTempItemID) {
			Return DllCall("XCGUI\XListView_GetTemplateObjectGroup", "Ptr", hEle
			                                                       , "Int", iGroup
			                                                       , "Int", nTempItemID
			                                                       , "Ptr")
		}

		XListView_SetColumnSpace(hEle, space) {
			Return DllCall("XCGUI\XListView_SetColumnSpace", "Ptr", hEle
			                                               , "Int", space
			                                               , "Ptr")
		}

		XListView_SetGroupHeight(hEle, height) {
			Return DllCall("XCGUI\XListView_SetGroupHeight", "Ptr", hEle
			                                               , "Int", height
			                                               , "Ptr")
		}

		XListView_SetItemBorderColorLeave(hEle, color, alpha) {
			Return DllCall("XCGUI\XListView_SetItemBorderColorLeave", "Ptr", hEle
			                                                        , "UInt", color
			                                                        , "UChar", alpha
			                                                        , "Ptr")
		}

		XListView_SetItemBorderColorSel(hEle, color, alpha) {
			Return DllCall("XCGUI\XListView_SetItemBorderColorSel", "Ptr", hEle
			                                                      , "UInt", color
			                                                      , "UChar", alpha
			                                                      , "Ptr")
		}

		XListView_SetItemBorderColorStay(hEle, color, alpha) {
			Return DllCall("XCGUI\XListView_SetItemBorderColorStay", "Ptr", hEle
			                                                       , "UInt", color
			                                                       , "UChar", alpha
			                                                       , "Ptr")
		}

		XListView_SetItemColorLeave(hEle, color, alpha) {
			Return DllCall("XCGUI\XListView_SetItemColorLeave", "Ptr", hEle
			                                                  , "UInt", color
			                                                  , "UChar", alpha
			                                                  , "Ptr")
		}

		XListView_SetItemColorSel(hEle, color, alpha) {
			Return DllCall("XCGUI\XListView_SetItemColorSel", "Ptr", hEle
			                                                , "UInt", color
			                                                , "UChar", alpha
			                                                , "Ptr")
		}

		XListView_SetItemColorStay(hEle, color, alpha) {
			Return DllCall("XCGUI\XListView_SetItemColorStay", "Ptr", hEle
			                                                 , "UInt", color
			                                                 , "UChar", alpha
			                                                 , "Ptr")
		}

		XListView_SetItemSize(hEle, width, height) {
			Return DllCall("XCGUI\XListView_SetItemSize", "Ptr", hEle
			                                            , "Int", width
			                                            , "Int", height
			                                            , "Ptr")
		}

		XListView_SetItemTemplateXML(hEle, pXmlFile) {
			Return DllCall("XCGUI\XListView_SetItemTemplateXML", "Ptr", hEle
			                                                   , "Str", pXmlFile
			                                                   , "Int")
		}

		XListView_SetRowSpace(hEle, space) {
			Return DllCall("XCGUI\XListView_SetRowSpace", "Ptr", hEle
			                                            , "Int", space
			                                            , "Ptr")
		}

		XListView_SetSelectItem(hEle, iGroup, iItem) {
			Return DllCall("XCGUI\XListView_SetSelectItem", "Ptr", hEle
			                                              , "Int", iGroup
			                                              , "Int", iItem
			                                              , "Int")
		}

		XListView_SetAlignSizeLeft(hEle, size) {
			Return DllCall("XCGUI\XListView_SetAlignSizeLeft", "Ptr", hEle
			                                                 , "Int", size
			                                                 , "Ptr")
		}

		XListView_SetAlignSizeTop(hEle, size) {
			Return DllCall("XCGUI\XListView_SetAlignSizeTop", "Ptr", hEle
			                                                , "Int", size
			                                                , "Ptr")
		}

		XListView_SetDrawItemBkFlags(hEle, nFlags) {
			Return DllCall("XCGUI\XListView_SetDrawItemBkFlags", "Ptr", hEle
			                                                   , "Int", nFlags
			                                                   , "Ptr")
		}

		XListView_AddItemBkBorder(hEle, nState, color, alpha=255, width=1) {
			Return DllCall("XCGUI\XListView_AddItemBkBorder", "Ptr", hEle
			                                                , "Int", nState
			                                                , "UInt", color
			                                                , "UChar", alpha
			                                                , "Int", width
			                                                , "Ptr")
		}

		XListView_AddItemBkFill(hEle, nState, color, alpha=255) {
			Return DllCall("XCGUI\XListView_AddItemBkFill", "Ptr", hEle
			                                              , "Int", nState
			                                              , "UInt", color
			                                              , "UChar", alpha
			                                              , "Ptr")
		}

		XListView_GetItemBkInfoManager(hEle, nState) {
			Return DllCall("XCGUI\XListView_GetItemBkInfoManager", "Ptr", hEle
			                                                     , "Int", nState
			                                                     , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___        _           ___                                              ____                          ____     ___                               
	; `MM(      )M'       dM.          `MM                                              `MM'     68b                  `Mb(     )d' 68b                           
	;  `MM.     d'       ,MMb           MM                       /                       MM      Y89            /      YM.     ,P  Y89                           
	;   `MM.   d'        d'YM.      ____MM    ___    __ ____    /M       ____   ___  __  MM      ___   ____    /M      `Mb     d'  ___   ____   ____    _    ___ 
	;    `MM. d'        ,P `Mb     6MMMMMM  6MMMMb   `M6MMMMb  /MMMMM   6MMMMb  `MM 6MM  MM      `MM  6MMMMb\ /MMMMM    YM.   ,P   `MM  6MMMMb  `MM(   ,M.   )M' 
	;     `MMd          d'  YM.   6M'  `MM 8M'  `Mb   MM'  `Mb  MM     6M'  `Mb  MM69 "  MM       MM MM'    `  MM       `Mb   d'    MM 6M'  `Mb  `Mb   dMb   d'  
	;      dMM.        ,P   `Mb   MM    MM     ,oMM   MM    MM  MM     MM    MM  MM'     MM       MM YM.       MM        YM. ,P     MM MM    MM   YM. ,PYM. ,P   
	;     d'`MM.       d'    YM.  MM    MM ,6MM9'MM   MM    MM  MM     MMMMMMMM  MM      MM       MM  YMMMMb   MM        `Mb d'     MM MMMMMMMM   `Mb d'`Mb d'   
	;    d'  `MM.     ,MMMMMMMMb  MM    MM MM'   MM   MM    MM  MM     MM        MM      MM       MM      `Mb  MM         YM,P      MM MM          YM,P  YM,P    
	;   d'    `MM.    d'      YM. YM.  ,MM MM.  ,MM   MM.  ,M9  YM.  , YM    d9  MM      MM    /  MM L    ,MM  YM.  ,     `MM'      MM YM    d9    `MM'  `MM'    
	; _M(_    _)MM_ _dM_     _dMM_ YMMMMMM_`YMMM9'Yb. MMYMMM9    YMMM9  YMMMM9  _MM_    _MMMMMMM _MM_MYMMMM9    YMMM9      YP      _MM_ YMMMM9      YP    YP     
	;                                                 MM                                                                                                         
	;                                                 MM                                                                                                         
	;                                                _MM_                                                                                                        
	;
	;--------------------------------------------------------------------------
		XAdapterListView_Create() {
			Return DllCall("XCGUI\XAdapterListView_Create", "Ptr")
		}

		XAdapterListView_Group_AddColumn(hAdapter, pName) {
			Return DllCall("XCGUI\XAdapterListView_Group_AddColumn", "Ptr", hAdapter
			                                                       , "Str", pName
			                                                       , "Int")
		}

		XAdapterListView_Item_AddColumn(hAdapter, pName) {
			Return DllCall("XCGUI\XAdapterListView_Item_AddColumn", "Ptr", hAdapter
			                                                      , "Str", pName
			                                                      , "Int")
		}

		XAdapterListView_Group_AddItemText(hAdapter, pValue) {
			Return DllCall("XCGUI\XAdapterListView_Group_AddItemText", "Ptr", hAdapter
			                                                         , "Str", pValue
			                                                         , "Int")
		}

		XAdapterListView_Item_AddItemImage(hAdapter, iGroup, hImage) {
			Return DllCall("XCGUI\XAdapterListView_Item_AddItemImage", "Ptr", hAdapter
			                                                         , "Int", iGroup
			                                                         , "Ptr", hImage
			                                                         , "Int")
		}

		XAdapterListView_Item_SetText(hAdapter, iGroup, iItem, iColumn, pValue) {
			Return DllCall("XCGUI\XAdapterListView_Item_SetText", "Ptr", hAdapter
			                                                    , "Int", iGroup
			                                                    , "Int", iItem
			                                                    , "Int", iColumn
			                                                    , "Str", pValue
			                                                    , "Int")
		}



	;--------------------------------------------------------------------------
	; ____      ___ __________                           
	; `MM(      )M' MMMMMMMMMM                           
	;  `MM.     d'  /   MM   \                           
	;   `MM.   d'       MM     ___  __   ____     ____   
	;    `MM. d'        MM     `MM 6MM  6MMMMb   6MMMMb  
	;     `MMd          MM      MM69 " 6M'  `Mb 6M'  `Mb 
	;      dMM.         MM      MM'    MM    MM MM    MM 
	;     d'`MM.        MM      MM     MMMMMMMM MMMMMMMM 
	;    d'  `MM.       MM      MM     MM       MM       
	;   d'    `MM.      MM      MM     YM    d9 YM    d9 
	; _M(_    _)MM_    _MM_    _MM_     YMMMM9   YMMMM9  
	;
	;--------------------------------------------------------------------------
		XTree_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XTree_Create", "Int", x
			                                   , "Int", y
			                                   , "Int", cx
			                                   , "Int", cy
			                                   , "Ptr", hParent
			                                   , "Ptr")
		}

		XTree_SetItemTemplateXML(hEle, pXmlFile) {
			Return DllCall("XCGUI\XTree_SetItemTemplateXML", "Ptr", hEle
			                                               , "Str", pXmlFile
			                                               , "Int")
		}

		XTree_SetItemTemplateXMLSel(hEle, pXmlFile) {
			Return DllCall("XCGUI\XTree_SetItemTemplateXMLSel", "Ptr", hEle
			                                                  , "Str", pXmlFile
			                                                  , "Int")
		}

		XTree_BindAdapter(hEle, hAdapter) {
			Return DllCall("XCGUI\XTree_BindAdapter", "Ptr", hEle
			                                        , "Ptr", hAdapter
			                                        , "Ptr")
		}

		XTree_SetItemHeight(hEle, nID, nHeight, nSelHeight) {
			Return DllCall("XCGUI\XTree_SetItemHeight", "Ptr", hEle
			                                          , "Int", nID
			                                          , "Int", nHeight
			                                          , "Int", nSelHeight
			                                          , "Ptr")
		}

		XTree_SetItemHeightDefault(hEle, nHeight, nSelHeight) {
			Return DllCall("XCGUI\XTree_SetItemHeightDefault", "Ptr", hEle
			                                                 , "Int", nHeight
			                                                 , "Int", nSelHeight
			                                                 , "Ptr")
		}

		XTree_GetFirstChildItem(hEle, nID) {
			Return DllCall("XCGUI\XTree_GetFirstChildItem", "Ptr", hEle
			                                              , "Int", nID
			                                              , "Int")
		}



	;--------------------------------------------------------------------------
	; ____      ___        _           ___                                              __________                           
	; `MM(      )M'       dM.          `MM                                              MMMMMMMMMM                           
	;  `MM.     d'       ,MMb           MM                       /                      /   MM   \                           
	;   `MM.   d'        d'YM.      ____MM    ___    __ ____    /M       ____   ___  __     MM     ___  __   ____     ____   
	;    `MM. d'        ,P `Mb     6MMMMMM  6MMMMb   `M6MMMMb  /MMMMM   6MMMMb  `MM 6MM     MM     `MM 6MM  6MMMMb   6MMMMb  
	;     `MMd          d'  YM.   6M'  `MM 8M'  `Mb   MM'  `Mb  MM     6M'  `Mb  MM69 "     MM      MM69 " 6M'  `Mb 6M'  `Mb 
	;      dMM.        ,P   `Mb   MM    MM     ,oMM   MM    MM  MM     MM    MM  MM'        MM      MM'    MM    MM MM    MM 
	;     d'`MM.       d'    YM.  MM    MM ,6MM9'MM   MM    MM  MM     MMMMMMMM  MM         MM      MM     MMMMMMMM MMMMMMMM 
	;    d'  `MM.     ,MMMMMMMMb  MM    MM MM'   MM   MM    MM  MM     MM        MM         MM      MM     MM       MM       
	;   d'    `MM.    d'      YM. YM.  ,MM MM.  ,MM   MM.  ,M9  YM.  , YM    d9  MM         MM      MM     YM    d9 YM    d9 
	; _M(_    _)MM_ _dM_     _dMM_ YMMMMMM_`YMMM9'Yb. MMYMMM9    YMMM9  YMMMM9  _MM_       _MM_    _MM_     YMMMM9   YMMMM9  
	;                                                 MM                                                                     
	;                                                 MM                                                                     
	;                                                _MM_                                                                    
	;
	;--------------------------------------------------------------------------
		XAdapterTree_Create() {
			Return DllCall("XCGUI\XAdapterTree_Create", "Ptr")
		}

		XAdapterTree_AddColumn(hAdapter, pName) {
			Return DllCall("XCGUI\XAdapterTree_AddColumn", "Ptr", hAdapter
			                                             , "Str", pName
			                                             , "Int")
		}

		XAdapterTree_InsertItemText(hAdapter, pValue, nParentID, insertID) {
			Return DllCall("XCGUI\XAdapterTree_InsertItemText", "Ptr", hAdapter
			                                                  , "Str", pValue
			                                                  , "Int", nParentID
			                                                  , "Int", insertID
			                                                  , "Int")
		}

		XAdapterTree_SetItemTextEx(hAdapter, nID, pName, pValue) {
			Return DllCall("XCGUI\XAdapterTree_SetItemTextEx", "Ptr", hAdapter
			                                                 , "Int", nID
			                                                 , "Str", pName
			                                                 , "Str", pValue
			                                                 , "Int")
		}

		XAdapterTree_SetItemImageEx(hAdapter, nID, pName, hImage) {
			Return DllCall("XCGUI\XAdapterTree_SetItemImageEx", "Ptr", hAdapter
			                                                  , "Int", nID
			                                                  , "Str", pName
			                                                  , "Ptr", hImage
			                                                  , "Int")
		}



	;--------------------------------------------------------------------------
	; ____      ___ ___       ___                             ________                     
	; `MM(      )M' `MMb     dMM'                             `MMMMMMMb.                   
	;  `MM.     d'   MMM.   ,PMM                               MM    `Mb                   
	;   `MM.   d'    M`Mb   d'MM   ____   ___  __   ___   ___  MM     MM    ___    ___  __ 
	;    `MM. d'     M YM. ,P MM  6MMMMb  `MM 6MMb  `MM    MM  MM    .M9  6MMMMb   `MM 6MM 
	;     `MMd       M `Mb d' MM 6M'  `Mb  MMM9 `Mb  MM    MM  MMMMMMM(  8M'  `Mb   MM69 " 
	;      dMM.      M  YM.P  MM MM    MM  MM'   MM  MM    MM  MM    `Mb     ,oMM   MM'    
	;     d'`MM.     M  `Mb'  MM MMMMMMMM  MM    MM  MM    MM  MM     MM ,6MM9'MM   MM     
	;    d'  `MM.    M   YP   MM MM        MM    MM  MM    MM  MM     MM MM'   MM   MM     
	;   d'    `MM.   M   `'   MM YM    d9  MM    MM  YM.   MM  MM    .M9 MM.  ,MM   MM     
	; _M(_    _)MM_ _M_      _MM_ YMMMM9  _MM_  _MM_  YMMM9MM__MMMMMMM9' `YMMM9'Yb._MM_    
	;
	;--------------------------------------------------------------------------
		XMenuBar_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XMenuBar_Create", "Int", x
			                                      , "Int", y
			                                      , "Int", cx
			                                      , "Int", cy
			                                      , "Ptr", hParent
			                                      , "Ptr")
		}

		XMenuBar_AddButton(hEle, pText) {
			Return DllCall("XCGUI\XMenuBar_AddButton", "Ptr", hEle
			                                         , "Str", pText
			                                         , "Int")
		}

		XMenuBar_AddMenuItem(hEle, index, id, pText, parentId=0, uFlags=0) {
			Return DllCall("XCGUI\XMenuBar_AddMenuItem", "Ptr", hEle
			                                           , "Int", index
			                                           , "Int", id
			                                           , "Str", pText
			                                           , "Int", parentId
			                                           , "Int", uFlags
			                                           , "Ptr")
		}

		XMenuBar_GetMenu(hEle, nIndex) {
			Return DllCall("XCGUI\XMenuBar_GetMenu", "Ptr", hEle
			                                       , "Int", nIndex
			                                       , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___   ____   ___          ___                  ________                     
	; `MM(      )M'  6MMMMb\ `MM 68b      `MM                  `MMMMMMMb.                   
	;  `MM.     d'  6M'    `  MM Y89       MM                   MM    `Mb                   
	;   `MM.   d'   MM        MM ___   ____MM   ____   ___  __  MM     MM    ___    ___  __ 
	;    `MM. d'    YM.       MM `MM  6MMMMMM  6MMMMb  `MM 6MM  MM    .M9  6MMMMb   `MM 6MM 
	;     `MMd       YMMMMb   MM  MM 6M'  `MM 6M'  `Mb  MM69 "  MMMMMMM(  8M'  `Mb   MM69 " 
	;      dMM.          `Mb  MM  MM MM    MM MM    MM  MM'     MM    `Mb     ,oMM   MM'    
	;     d'`MM.          MM  MM  MM MM    MM MMMMMMMM  MM      MM     MM ,6MM9'MM   MM     
	;    d'  `MM.         MM  MM  MM MM    MM MM        MM      MM     MM MM'   MM   MM     
	;   d'    `MM.  L    ,M9  MM  MM YM.  ,MM YM    d9  MM      MM    .M9 MM.  ,MM   MM     
	; _M(_    _)MM_ MYMMMM9  _MM__MM_ YMMMMMM_ YMMMM9  _MM_    _MMMMMMM9' `YMMM9'Yb._MM_    
	;
	;--------------------------------------------------------------------------
		XSliderBar_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XSliderBar_Create", "Int", x
			                                        , "Int", y
			                                        , "Int", cx
			                                        , "Int", cy
			                                        , "Ptr", hParent
			                                        , "Ptr")
		}

		XSliderBar_GetPos(hEle) {
			Return DllCall("XCGUI\XSliderBar_GetPos", "Ptr", hEle)
		}

		XSliderBar_GetRange(hEle) {
			Return DllCall("XCGUI\XSliderBar_GetRange", "Ptr", hEle)
		}

		XSliderBar_SetPos(hEle, pos) {
			Return DllCall("XCGUI\XSliderBar_SetPos", "Ptr", hEle
			                                        , "Int", pos)
		}

		XSliderBar_SetRange(hEle, range) {
			Return DllCall("XCGUI\XSliderBar_SetRange", "Ptr", hEle
			                                          , "Int", range)
		}

		XSliderBar_SetButtonHeight(hEle, height) {
			Return DllCall("XCGUI\XSliderBar_SetButtonHeight", "Ptr", hEle
			                                                 , "Int", height)
		}

		XSliderBar_SetButtonWidth(hEle, width) {
			Return DllCall("XCGUI\XSliderBar_SetButtonWidth", "Ptr", hEle
			                                                , "Int", width)
		}

		XSliderBar_SetSpaceTwo(hEle, leftSize, rightSize) {
			Return DllCall("XCGUI\XSliderBar_SetSpaceTwo", "Ptr", hEle
			                                             , "Int", leftSize
			                                             , "Int", rightSize
			                                             , "Ptr")
		}

		XSliderBar_GetButton(hEle) {
			Return DllCall("XCGUI\XSliderBar_GetButton", "Ptr", hEle, "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___ __________                     ___ ________                     
	; `MM(      )M' MMMMMMMMMM                     `MM `MMMMMMMb.                   
	;  `MM.     d'  /   MM   \                      MM  MM    `Mb                   
	;   `MM.   d'       MM       _____     _____    MM  MM     MM    ___    ___  __ 
	;    `MM. d'        MM      6MMMMMb   6MMMMMb   MM  MM    .M9  6MMMMb   `MM 6MM 
	;     `MMd          MM     6M'   `Mb 6M'   `Mb  MM  MMMMMMM(  8M'  `Mb   MM69 " 
	;      dMM.         MM     MM     MM MM     MM  MM  MM    `Mb     ,oMM   MM'    
	;     d'`MM.        MM     MM     MM MM     MM  MM  MM     MM ,6MM9'MM   MM     
	;    d'  `MM.       MM     MM     MM MM     MM  MM  MM     MM MM'   MM   MM     
	;   d'    `MM.      MM     YM.   ,M9 YM.   ,M9  MM  MM    .M9 MM.  ,MM   MM     
	; _M(_    _)MM_    _MM_     YMMMMM9   YMMMMM9  _MM__MMMMMMM9' `YMMM9'Yb._MM_    
	;
	;--------------------------------------------------------------------------
		XToolBar_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XToolBar_Create", "Int", x
			                                      , "Int", y
			                                      , "Int", cx
			                                      , "Int", cy
			                                      , "Ptr", hParent
			                                      , "Ptr")
		}

		XToolBar_InsertEle(hEle, hNewEle, index=-1) {
			Return DllCall("XCGUI\XToolBar_InsertEle", "Ptr", hEle
			                                         , "Ptr", hNewEle
			                                         , "Int", index
			                                         , "Int")
		}

		XToolBar_GetHEle(hEle, index) {
			Return DllCall("XCGUI\XToolBar_GetHEle", "Ptr", hEle
			                                       , "Int", index
			                                       , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___   ____   ___                                       ____          __ 
	; `MM(      )M'  6MMMMb\ `MM                                      6MMMMb/ 68b   69MM
	;  `MM.     d'  6M'    `  MM                                     8P    YM Y89  6M' `
	;   `MM.   d'   MM        MM  __      ___    __ ____     ____   6M      Y ___ _MM__ 
	;    `MM. d'    YM.       MM 6MMb   6MMMMb   `M6MMMMb   6MMMMb  MM        `MM MMMMM 
	;     `MMd       YMMMMb   MMM9 `Mb 8M'  `Mb   MM'  `Mb 6M'  `Mb MM         MM  MM   
	;      dMM.          `Mb  MM'   MM     ,oMM   MM    MM MM    MM MM     ___ MM  MM   
	;     d'`MM.          MM  MM    MM ,6MM9'MM   MM    MM MMMMMMMM MM     `M' MM  MM   
	;    d'  `MM.         MM  MM    MM MM'   MM   MM    MM MM       YM      M  MM  MM   
	;   d'    `MM.  L    ,M9  MM    MM MM.  ,MM   MM.  ,M9 YM    d9  8b    d9  MM  MM   
	; _M(_    _)MM_ MYMMMM9  _MM_  _MM_`YMMM9'Yb. MMYMMM9   YMMMM9    YMMMM9  _MM__MM_  
	;                                             MM                                    
	;                                             MM                                    
	;                                            _MM_                                   
	;
	;--------------------------------------------------------------------------
		XShapeGif_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XShapeGif_Create", "Int", x
			                                       , "Int", y
			                                       , "Int", cx
			                                       , "Int", cy
			                                       , "Ptr", hParent
			                                       , "Ptr")
		}

		XShapeGif_SetImage(hShape, hImage) {
			Return DllCall("XCGUI\XShapeGif_SetImage", "Ptr", hShape
			                                         , "Ptr", hImage
			                                         , "Ptr")
		}

		XShapeGif_SetLayoutWidth(hShape, nType, width) {
			Return DllCall("XCGUI\XShapeGif_SetLayoutWidth", "Ptr", hShape
			                                               , "Int", nType
			                                               , "Int", width
			                                               , "Ptr")
		}

		XShapeGif_SetLayoutHeight(hShape, nType, height) {
			Return DllCall("XCGUI\XShapeGif_SetLayoutHeight", "Ptr", hShape
			                                                , "Int", nType
			                                                , "Int", height
			                                                , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___   ____   ___                                    
	; `MM(      )M'  6MMMMb\ `MM                                    
	;  `MM.     d'  6M'    `  MM                                    
	;   `MM.   d'   MM        MM  __      ___    __ ____     ____   
	;    `MM. d'    YM.       MM 6MMb   6MMMMb   `M6MMMMb   6MMMMb  
	;     `MMd       YMMMMb   MMM9 `Mb 8M'  `Mb   MM'  `Mb 6M'  `Mb 
	;      dMM.          `Mb  MM'   MM     ,oMM   MM    MM MM    MM 
	;     d'`MM.          MM  MM    MM ,6MM9'MM   MM    MM MMMMMMMM 
	;    d'  `MM.         MM  MM    MM MM'   MM   MM    MM MM       
	;   d'    `MM.  L    ,M9  MM    MM MM.  ,MM   MM.  ,M9 YM    d9 
	; _M(_    _)MM_ MYMMMM9  _MM_  _MM_`YMMM9'Yb. MMYMMM9   YMMMM9  
	;                                             MM                
	;                                             MM                
	;                                            _MM_               
	;
	;--------------------------------------------------------------------------
		XShape_GetParentEle(hShape) {
			Return DllCall("XCGUI\XShape_GetParentEle", "Ptr", hShape
			                                          , "Ptr")
		}

		XShape_Destroy(hShape) {
			Return DllCall("XCGUI\XShape_Destroy", "Ptr", hShape
			                                     , "Ptr")
		}

		XShape_Redraw(hShape) {
			Return DllCall("XCGUI\XShape_Redraw", "Ptr", hShape)
		}

		XShape_RemoveShape(hShape){
			Return DllCall("XCGUI\XShape_RemoveShape", "Ptr", hShape)
		}


	;--------------------------------------------------------------------------
	; ____      ___ __________           ___       ________                     
	; `MM(      )M' MMMMMMMMMM            MM       `MMMMMMMb.                   
	;  `MM.     d'  /   MM   \            MM        MM    `Mb                   
	;   `MM.   d'       MM        ___     MM____    MM     MM    ___    ___  __ 
	;    `MM. d'        MM      6MMMMb    MMMMMMb   MM    .M9  6MMMMb   `MM 6MM 
	;     `MMd          MM     8M'  `Mb   MM'  `Mb  MMMMMMM(  8M'  `Mb   MM69 " 
	;      dMM.         MM         ,oMM   MM    MM  MM    `Mb     ,oMM   MM'    
	;     d'`MM.        MM     ,6MM9'MM   MM    MM  MM     MM ,6MM9'MM   MM     
	;    d'  `MM.       MM     MM'   MM   MM    MM  MM     MM MM'   MM   MM     
	;   d'    `MM.      MM     MM.  ,MM   MM.  ,M9  MM    .M9 MM.  ,MM   MM     
	; _M(_    _)MM_    _MM_    `YMMM9'Yb._MYMMMM9  _MMMMMMM9' `YMMM9'Yb._MM_    
	;
	;--------------------------------------------------------------------------
		XTabBar_Create(x, y, cx, cy, hParent) {
			Return DllCall("XCGUI\XTabBar_Create", "Int", x
			                                     , "Int", y
			                                     , "Int", cx
			                                     , "Int", cy
			                                     , "Ptr", hParent
			                                     , "Ptr")
		}

		XTabBar_AddLabel(hEle, pName) {
			Return DllCall("XCGUI\XTabBar_AddLabel", "Ptr", hEle
			                                       , "Str", pName
			                                       , "Int")
		}

		XTabBar_InsertLabel(hEle, index, pName) {
			Return DllCall("XCGUI\XTabBar_InsertLabel", "Ptr", hEle
			                                          , "Int", index
			                                          , "Str", pName
			                                          , "Int")
		}

		XTabBar_DeleteLabel(hEle, index) {
			Return DllCall("XCGUI\XTabBar_DeleteLabel", "Ptr", hEle
			                                          , "Int", index
			                                          , "Int")
		}

		XTabBar_DeleteLabelAll(hEle) {
			Return DllCall("XCGUI\XTabBar_DeleteLabelAll", "Ptr", hEle
			                                             , "Ptr")
		}

		XTabBar_EnableClose(hEle, bEnable=True) {
			Return DllCall("XCGUI\XTabBar_EnableClose", "Ptr", hEle
			                                          , "Int", bEnable
			                                          , "Ptr")
		}

		XTabBar_EnableTile(hEle, bEnable=True) {
			Return DllCall("XCGUI\XTabBar_EnableTile", "Ptr", hEle
			                                         , "Int", bEnable
			                                         , "Ptr")
		}

		XTabBar_GetLabel(hEle, index) {
			Return DllCall("XCGUI\XTabBar_GetLabel", "Ptr", hEle
			                                       , "Int", index
			                                       , "Ptr")
		}

		XTabBar_GetLabelCount(hEle) {
			Return DllCall("XCGUI\XTabBar_GetLabelCount", "Ptr", hEle
			                                            , "Int")
		}

		XTabBar_GetLabelSpacing(hEle) {
			Return DllCall("XCGUI\XTabBar_GetLabelSpacing", "Ptr", hEle
			                                              , "Int")
		}

		XTabBar_GetSelect(hEle) {
			Return DllCall("XCGUI\XTabBar_GetSelect", "Ptr", hEle
			                                        , "Int")
		}

		XTabBar_SetCloseSize(hEle, pSize) {
			Return DllCall("XCGUI\XTabBar_SetCloseSize", "Ptr", hEle
			                                           , "Ptr", pSize
			                                           , "Ptr")
		}

		XTabBar_SetDown(hEle) {
			Return DllCall("XCGUI\XTabBar_SetDown", "Ptr", hEle
			                                      , "Ptr")
		}

		XTabBar_SetLabelSpacing(hEle, spacing) {
			Return DllCall("XCGUI\XTabBar_SetLabelSpacing", "Ptr", hEle
			                                              , "Int", spacing
			                                              , "Ptr")
		}

		XTabBar_SetSelect(hEle, index) {
			Return DllCall("XCGUI\XTabBar_SetSelect", "Ptr", hEle
			                                        , "Int", index
			                                        , "Ptr")
		}

		XTabBar_SetTurnButtonSize(hEle, pSize) {
			Return DllCall("XCGUI\XTabBar_SetTurnButtonSize", "Ptr", hEle
			                                                , "Int", pSize
			                                                , "Ptr")
		}

		XTabBar_SetUp(hEle) {
			Return DllCall("XCGUI\XTabBar_SetUp", "Ptr", hEle
			                                    , "Ptr")
		}

		XTabBar_ShowLabel(hEle, index, bShow=True) {
			Return DllCall("XCGUI\XTabBar_ShowLabel", "Ptr", hEle
			                                        , "Int", index
			                                        , "Ptr", bShow
			                                        , "Int")
		}



	;--------------------------------------------------------------------------
	; ____      ___ ____                                                       
	; `MM(      )M' `MM'                                                       
	;  `MM.     d'   MM                                                  /     
	;   `MM.   d'    MM         ___    ____    ___   _____   ___   ___  /M     
	;    `MM. d'     MM       6MMMMb   `MM(    )M'  6MMMMMb  `MM    MM /MMMMM  
	;     `MMd       MM      8M'  `Mb   `Mb    d'  6M'   `Mb  MM    MM  MM     
	;      dMM.      MM          ,oMM    YM.  ,P   MM     MM  MM    MM  MM     
	;     d'`MM.     MM      ,6MM9'MM     MM  M    MM     MM  MM    MM  MM     
	;    d'  `MM.    MM      MM'   MM     `Mbd'    MM     MM  MM    MM  MM     
	;   d'    `MM.   MM    / MM.  ,MM      YMP     YM.   ,M9  YM.   MM  YM.  , 
	; _M(_    _)MM_ _MMMMMMM `YMMM9'Yb.     M       YMMMMM9    YMMM9MM_  YMMM9 
	;                                      d'                                  
	;                                  (8),P                                   
	;                                   YMM                                    
	;
	;--------------------------------------------------------------------------
		XLayout_Create() {
			Return DllCall("XCGUI\XLayout_Create", "Ptr")
		}

		XLayout_Destroy(hLayout) {
			Return DllCall("XCGUI\XLayout_Destroy", "Ptr", hLayout
			                                      , "Ptr")
		}

		XLayout_Draw(hLayout, hDraw) {
			Return DllCall("XCGUI\XLayout_Draw", "Ptr", hLayout
			                                   , "Ptr", hDraw
			                                   , "Ptr")
		}

		XLayout_GetChild(hLayout, index) {
			Return DllCall("XCGUI\XLayout_GetChild", "Ptr", hLayout
			                                       , "Int", index
			                                       , "Ptr")
		}

		XLayout_GetChildCount(hLayout) {
			Return DllCall("XCGUI\XLayout_GetChildCount", "Ptr", hLayout
			                                            , "Int")
		}

		XLayout_GetChildType(hLayout, index) {
			Return DllCall("XCGUI\XLayout_GetChildType", "Ptr", hLayout
			                                           , "Int", index
			                                           , "Int")
		}

		XLayout_GetContentSize(hLayout, ByRef pSize) {
			Return DllCall("XCGUI\XLayout_GetContentSize", "Ptr", hLayout
			                                             , "Int*", pSize
			                                             , "Ptr")
		}

		XLayout_GetEle(hLayout) {
			Return DllCall("XCGUI\XLayout_GetEle", "Ptr", hLayout
			                                     , "Ptr")
		}

		XLayout_GetHeight(hLayout) {
			Return DllCall("XCGUI\XLayout_GetHeight", "Ptr", hLayout
			                                        , "Int")
		}

		XLayout_GetHeightIn(hLayout) {
			Return DllCall("XCGUI\XLayout_GetHeightIn", "Ptr", hLayout
			                                          , "Int")
		}

		XLayout_GetLayoutHeight(hLayout, ByRef pFlag, ByRef pHeight) {
			Return DllCall("XCGUI\XLayout_GetLayoutHeight", "Ptr", hLayout
			                                              , "Int*", pFlag
			                                              , "Int*", pHeight
			                                              , "Ptr")
		}

		XLayout_GetLayoutWidth(hLayout, ByRef pFlag, ByRef pWidth) {
			Return DllCall("XCGUI\XLayout_GetLayoutWidth", "Ptr", hLayout
			                                             , "Int*", pFlag
			                                             , "Int*", pWidth
			                                             , "Ptr")
		}

		XLayout_GetParentLayout(hLayout) {
			Return DllCall("XCGUI\XLayout_GetParentLayout", "Ptr", hLayout
			                                              , "Ptr")
		}

		XLayout_GetRect(hLayout, pRect) {
			Return DllCall("XCGUI\XLayout_GetRect", "Ptr", hLayout
			                                      , "Ptr*", pRect
			                                      , "Ptr")
		}

		XLayout_GetRectFrame(hLayout, pRect) {
			Return DllCall("XCGUI\XLayout_GetRectFrame", "Ptr", hLayout
			                                           , "Ptr*", pRect
			                                           , "Ptr")
		}

		XLayout_GetWidth(hLayout) {
			Return DllCall("XCGUI\XLayout_GetWidth", "Ptr", hLayout
			                                       , "Int")
		}

		XLayout_GetWidthIn(hLayout) {
			Return DllCall("XCGUI\XLayout_GetWidthIn", "Ptr", hLayout
			                                         , "Int")
		}

		XLayout_GetWindow(hLayout) {
			Return DllCall("XCGUI\XLayout_GetWindow", "Ptr", hLayout
			                                        , "Ptr")
		}

		XLayout_RemoveChild(hLayout, hChild) {
			Return DllCall("XCGUI\XLayout_RemoveChild", "Ptr", hLayout
			                                          , "Ptr", hChild
			                                          , "Ptr")
		}

		XLayout_SetAlignH(hLayout, nFlag) {
			Return DllCall("XCGUI\XLayout_SetAlignH", "Ptr", hLayout
			                                        , "Int", nFlag
			                                        , "Ptr")
		}

		XLayout_SetAlignV(hLayout, nFlag) {
			Return DllCall("XCGUI\XLayout_SetAlignV", "Ptr", hLayout
			                                        , "Int", nFlag
			                                        , "Ptr")
		}

		XLayout_SetHorizon(hLayout, bHorizon) {
			Return DllCall("XCGUI\XLayout_SetHorizon", "Ptr", hLayout
			                                         , "Int", bHorizon
			                                         , "Ptr")
		}

		XLayout_SetID(hLayout, nID) {
			Return DllCall("XCGUI\XLayout_SetID", "Ptr", hLayout
			                                    , "Int", nID
			                                    , "Ptr")
		}

		XLayout_SetLayoutHeight(hLayout, nFlag, nHeight) {
			Return DllCall("XCGUI\XLayout_SetLayoutHeight", "Ptr", hLayout
			                                              , "Int", nFlag
			                                              , "Int", nHeight
			                                              , "Ptr")
		}

		XLayout_SetLayoutWidth(hLayout, nFlag, nWidth) {
			Return DllCall("XCGUI\XLayout_SetLayoutWidth", "Ptr", hLayout
			                                             , "Int", nFlag
			                                             , "Int", nWidth
			                                             , "Ptr")
		}

		XLayout_SetPadding(hLayout, left, top, right, buttom) {
			Return DllCall("XCGUI\XLayout_SetPadding", "Ptr", hLayout
			                                         , "Int", left
			                                         , "Int", top
			                                         , "Int", right
			                                         , "Int", buttom
			                                         , "Ptr")
		}

		XLayout_SetRectFrame(hLayout, pRect) {
			Return DllCall("XCGUI\XLayout_SetRectFrame", "Ptr", hLayout
			                                           , "Ptr", pRect
			                                           , "Ptr")
		}

		XLayout_SetSpace(hLayout, nSpace) {
			Return DllCall("XCGUI\XLayout_SetSpace", "Ptr", hLayout
			                                       , "Int", nSpace
			                                       , "Ptr")
		}

		XLayout_ShowLayout(hLayout, bShow=True) {
			Return DllCall("XCGUI\XLayout_ShowLayout", "Ptr", hLayout
			                                         , "Int", bShow
			                                         , "Ptr")
		}

		XLayout_AddEle(hLayout, hEle) {
			Return DllCall("XCGUI\XLayout_AddEle", "Ptr", hLayout
			                                     , "Ptr", hEle
			                                     , "Ptr")
		}

		XLayout_AddLayoutObject(hLayout, hLayoutObject) {
			Return DllCall("XCGUI\XLayout_AddLayoutObject", "Ptr", hLayout
			                                              , "Ptr", hLayoutObject
			                                              , "Ptr")
		}

		XLayout_AddShape(hLayout, hShape) {
			Return DllCall("XCGUI\XLayout_AddShape", "Ptr", hLayout
			                                       , "Ptr", hShape
			                                       , "Ptr")
		}

		XLayout_AdjustLayout(hLayout) {
			Return DllCall("XCGUI\XLayout_AdjustLayout", "Ptr", hLayout
			                                           , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___ ________                                      
	; `MM(      )M' `MMMMMMMb.                                    
	;  `MM.     d'   MM    `Mb                                    
	;   `MM.   d'    MM     MM ___  __    ___    ____    _    ___ 
	;    `MM. d'     MM     MM `MM 6MM  6MMMMb   `MM(   ,M.   )M' 
	;     `MMd       MM     MM  MM69 " 8M'  `Mb   `Mb   dMb   d'  
	;      dMM.      MM     MM  MM'        ,oMM    YM. ,PYM. ,P   
	;     d'`MM.     MM     MM  MM     ,6MM9'MM    `Mb d'`Mb d'   
	;    d'  `MM.    MM     MM  MM     MM'   MM     YM,P  YM,P    
	;   d'    `MM.   MM    .M9  MM     MM.  ,MM     `MM'  `MM'    
	; _M(_    _)MM_ _MMMMMMM9' _MM_    `YMMM9'Yb.    YP    YP     
	;
	;--------------------------------------------------------------------------
		XDraw_Create(hdc) {
			Return DllCall("XCGUI\XDraw_Create", "Ptr", hdc
			                                   , "Ptr")
		}

		XDraw_CreatePen(hDraw, fnPenStyle, nWidth, crColor) {
			Return DllCall("XCGUI\XDraw_CreatePen", "Ptr", hDraw
			                                      , "Int", fnPenStyle
			                                      , "Int", nWidth
			                                      , "UInt", crColor
			                                      , "Ptr")
		}

		XDraw_MoveToEx(hDraw, x, y, lpPoint) {
			Return DllCall("XCGUI\XDraw_MoveToEx", "Ptr", hDraw
			                                     , "Int", x
			                                     , "Int", y
			                                     , "Ptr", lpPoint
			                                     , "Int")
		}

		XDraw_LineTo(hDraw, nXEnd, nYEnd) {
			Return DllCall("XCGUI\XDraw_LineTo", "Ptr", hDraw
			                                   , "Int", nXEnd
			                                   , "Int", nYEnd
			                                   , "Int")
		}

		XDraw_Image(hDraw, hImage, x, y) {
			Return DllCall("XCGUI\XDraw_Image", "Ptr", hDraw
			                                  , "Ptr", hImage
			                                  , "Int", x
			                                  , "Int", y
			                                  , "Ptr")
		}

		XDraw_Image2(hDraw, hImage, x, y, width, height) {
			Return DllCall("XCGUI\XDraw_Image2", "Ptr", hDraw
			                                   , "Ptr", hImage
			                                   , "Int", x
			                                   , "Int", y
			                                   , "Int", width
			                                   , "Int", height
			                                   , "Ptr")
		}

		XDraw_ImageAdaptive(hDraw, hImage, pRect, bOnlyBorder) {
			static XDraw_ImageAdaptive := xc._GetProcAddress("XDraw_ImageAdaptive")
			Return DllCall(XDraw_ImageAdaptive, "Ptr", hDraw
			                                  , "Ptr", hImage
			                                  , "Ptr", &pRect
			                                  , "Int", bOnlyBorder
			                                  , "Ptr")
		}

		XDraw_DrawLine(hDraw, x1, y1, x2, y2) {
			static XDraw_DrawLine := xc._GetProcAddress("XDraw_DrawLine")
			Return DllCall(XDraw_DrawLine, "Ptr", hDraw
			                             , "Int", x1
			                             , "Int", y1
			                             , "Int", x2
			                             , "Int", y2
			                             , "Ptr")
		}

		XDraw_GradientFill2(hDraw, color1, alpha1, color2, alpha2, pRect, mode) {
			static XDraw_GradientFill2 := xc._GetProcAddress("XDraw_GradientFill2")
			Return DllCall(XDraw_GradientFill2, "Ptr", hDraw
			                                  , "UInt", color1
			                                  , "UChar", alpha1
			                                  , "UInt", color2
			                                  , "UChar", alpha2
			                                  , "Ptr", pRect
			                                  , "Int", mode
			                                  , "Ptr")
		}

		XDraw_GradientFill4(hDraw, color1, color2, color3, color4, pRect, mode) {
			static XDraw_GradientFill4 := xc._GetProcAddress("XDraw_GradientFill4")
			Return DllCall(XDraw_GradientFill4, "Ptr", hDraw
			                                  , "UInt", color1
			                                  , "UChar", color2
			                                  , "UInt", color3
			                                  , "UChar", color4
			                                  , "Ptr", pRect
			                                  , "Int", mode
			                                  , "Ptr")
		}

		XDraw_GetHDC(hDraw) {
			Return DllCall("XCGUI\XDraw_GetHDC", "Ptr", hDraw
			                                   , "Ptr")
		}

		XDraw_SetBrushColor(hDraw, color, alpha) {
			static XDraw_SetBrushColor := xc._GetProcAddress("XDraw_SetBrushColor")
			Return DllCall(XDraw_SetBrushColor, "Ptr", hDraw
			                                  , "UInt", color
			                                  , "UChar", alpha
			                                  , "Ptr")
		}



	;--------------------------------------------------------------------------
	; ____      ___ ________   ___       ____             __           ___       ___
	; `MM(      )M' `MMMMMMMb. `MM       `MM'            69MM          `MMb     dMM'
	;  `MM.     d'   MM    `Mb  MM        MM            6M' `           MMM.   ,PMM 
	;   `MM.   d'    MM     MM  MM   __   MM ___  __   _MM__   _____    M`Mb   d'MM 
	;    `MM. d'     MM    .M9  MM   d'   MM `MM 6MMb  MMMMM  6MMMMMb   M YM. ,P MM 
	;     `MMd       MMMMMMM(   MM  d'    MM  MMM9 `Mb  MM   6M'   `Mb  M `Mb d' MM 
	;      dMM.      MM    `Mb  MM d'     MM  MM'   MM  MM   MM     MM  M  YM.P  MM 
	;     d'`MM.     MM     MM  MMdM.     MM  MM    MM  MM   MM     MM  M  `Mb'  MM 
	;    d'  `MM.    MM     MM  MMPYM.    MM  MM    MM  MM   MM     MM  M   YP   MM 
	;   d'    `MM.   MM    .M9  MM  YM.   MM  MM    MM  MM   YM.   ,M9  M   `'   MM 
	; _M(_    _)MM_ _MMMMMMM9' _MM_  YM.__MM__MM_  _MM__MM_   YMMMMM9  _M_      _MM_
	;
	;--------------------------------------------------------------------------
		XBkInfoM_AddImage(hBkInfoM, nState, hImage) {
			Return DllCall("XCGUI\XBkInfoM_AddImage", "Ptr", hBkInfoM
			                                        , "Int", nState
			                                        , "Ptr", hImage
			                                        , "Ptr")
		}

		XBkInfoM_AddBorder(hBkInfoM, nState, color, alpha=255, width=1) {
			Return DllCall("XCGUI\XBkInfoM_AddBorder", "Ptr", hBkInfoM
			                                         , "Int", nState
			                                         , "UInt", color
			                                         , "UChar", alpha
			                                         , "Int", width)
		}

		XBkInfoM_AddFill(hBkInfoM, nState, color, alpha=255) {
			Return DllCall("XCGUI\XBkInfoM_AddFill", "Ptr", hBkInfoM
			                                       , "Int", nState
			                                       , "UInt", color
			                                       , "UChar", alpha)
		}

		XBkInfoM_Draw(hBkInfoM, hDraw, pRect) {
			Return DllCall("XCGUI\XBkInfoM_Draw", "Ptr", hBkInfoM
			                                    , "Ptr", hDraw
			                                    , "Ptr", pRect
			                                    , "Int")
		}

	; -------------------------------------------------------------------------

	XRunXCGUI() {
		Return DllCall("XCGUI\XRunXCGUI", "Ptr")
	}

	XExitXCGUI() {
		DllCall("XCGUI\XExitXCGUI", "Ptr")
		this._Free()
	}

	XInitXCGUI(EnableDebugFile := False) {
		DllCall("XCGUI\XInitXCGUI", "UShort", pText, "Int")
		this.XC_EnableDebugFile(EnableDebugFile)
	}
	
	XC_IsHXCGUI(hXCGUI, nType) {
		Return DllCall("XCGUI\XC_IsHXCGUI", "Ptr", hXCGUI
		                                  , "Int", nType
		                                  , "Int")
	}

	XC_IsHWINDOW(hWindow) {
		Return DllCall("XCGUI\XC_IsHWINDOW", "Ptr", hWindow
		                                   , "Int")
	}

	XC_IsHELE(hEle) {
		Return DllCall("XCGUI\XC_IsHELE", "Ptr", hEle
		                                , "Int")
	}

	XC_IsShape(hEle) {
		Return DllCall("XCGUI\XC_IsShape", "Ptr", hEle)
	}

	XC_GetObjectType(hXCGUI) {
		Return DllCall("XCGUI\XC_GetObjectType", "Ptr", hXCGUI
		                                       , "Int")
	}

	XC_GetObjectByID(nID) {
		Return DllCall("XCGUI\XC_GetObjectByID", "Int", nID
		                                       , "Ptr")
	}

	XC_GetResIDValue(pName) {
		Return DllCall("XCGUI\XC_GetResIDValue", "Ptr", &pName
		                                       , "Int")
	}

	XC_EnableDebugFile(bEnable=True) {
		Return DllCall("XCGUI\XC_EnableDebugFile", "Int", bEnable, "Ptr")
	}

	XC_LoadTemplate(nType, pFileName) {
		Return DllCall("XCGUI\XC_LoadTemplate", "Int", nType
		                                      , "Str", pFileName
		                                      , "Ptr")
	}

	XC_LoadResource(pFileName, pDir="") {
		Return DllCall("XCGUI\XC_LoadResource", "Str", pFileName
		                                      , "Str", pDir
		                                      , "Int")
	}

	XC_LoadLayout(pFileName, hParent=0) {
		Return DllCall("XCGUI\XC_LoadLayout", "Str", pFileName
		                                    , "Ptr", hParent
		                                    , "Ptr")
	}

	XC_SetLayoutFrameColor(color) {
		Return DllCall("XCGUI\XC_SetLayoutFrameColor", "UInt", color
		                                             , "Ptr")
	}

	XC_ShowLayoutFrame(bShow) {
		Return DllCall("XCGUI\XC_ShowLayoutFrame", "Int", bShow
		                                         , "Ptr")
	}

	XC_hWindowFromHWnd(hWnd) {
		Return DllCall("XCGUI\XC_hWindowFromHWnd", "Ptr", hWnd
		                                         , "Ptr")
	}

	XC_LoadLayoutFromString(ByRef StringXML, hParent=0) {
		Return DllCall("XCGUI\XC_LoadLayoutFromString", "Ptr", &StringXML
		                                              , "Ptr", hParent
		                                              , "Ptr")
	}

	; -------------------------------------------------------------------------

	_Init() {
		this.hModule := DllCall("LoadLibrary", "Str", "XCGUI.dll", "Ptr")
		Return True
	}

	_Free() {
		DllCall("FreeLibrary", "Ptr", this.hModule)
	}

	_GetProcAddress(FuncName) {
		Return DllCall("GetProcAddress", "Ptr", this.hModule, "AStr", FuncName, "Ptr")
	}
}