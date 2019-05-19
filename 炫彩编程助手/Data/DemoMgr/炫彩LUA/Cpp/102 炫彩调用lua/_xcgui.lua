XC_API = { }
tm={}
setmetatable(XC_API,tm)
tm.__index= function (self, name)
	local  funName=name
	return function (...)
		return XC_API_CALL(funName,...)
	end
end


function XC_lua_modifyBOOL(b,v)
	return XC_API_CALL('XC_lua_modifyBOOL',b,v);
end
function XC_lua_newuserdata(nSize)
	return XC_API_CALL('XC_lua_newuserdata',nSize);
end

function XC_lua_newuserdata_wchar_t(nSize)
	return XC_API_CALL('XC_lua_newuserdata_wchar_t',nSize);
end	

function XC_lua_userdata_wchar_t_ToString(buffer)
	return XC_API_CALL('XC_lua_userdata_wchar_t_ToString',buffer);
end

--[[
function XC_modifyBOOL(b,v)
	return XC_API_CALL('XC_lua_modifyBOOL',b,v);
end

function XC_NewBufferW(nSize)
	return XC_API_CALL('XC_lua_newuserdata_wchar_t',nSize);
end	

function XC_BufferWToString(buffer)
	return XC_API_CALL('XC_lua_userdata_wchar_t_ToString',buffer);
end

function XC_New(nSize)
	return XC_API_CALL('XC_lua_newuserdata',nSize);
end
--]]




function XDateTime_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XDateTime_Create',x,y,cx,cy,hParent);
end

function XDateTime_SetStyle(hEle,nStyle)
return XC_API_CALL('XDateTime_SetStyle',hEle,nStyle);
end

function XDateTime_GetStyle(hEle)
return XC_API_CALL('XDateTime_GetStyle',hEle);
end

function XDateTime_GetTime(hEle,pnHour,pnMinute,pnSecond)
return XC_API_CALL('XDateTime_GetTime',hEle,pnHour,pnMinute,pnSecond);
end

function XDateTime_SetTime(hEle,nHour,nMinute,nSecond)
return XC_API_CALL('XDateTime_SetTime',hEle,nHour,nMinute,nSecond);
end

function XDateTime_GetDate(hEle,pnYear,pnMonth,pnDay)
return XC_API_CALL('XDateTime_GetDate',hEle,pnYear,pnMonth,pnDay);
end

function XDateTime_SetDate(hEle,nYear,nMonth,nDay)
return XC_API_CALL('XDateTime_SetDate',hEle,nYear,nMonth,nDay);
end

function XDateTime_GetSelBkColor(hEle)
return XC_API_CALL('XDateTime_GetSelBkColor',hEle);
end

function XDateTime_SetSelBkColor(hEle,crSelectBk,alpha)
return XC_API_CALL('XDateTime_SetSelBkColor',hEle,crSelectBk,alpha);
end

function XDateTime_GetButton(hEle,nType)
return XC_API_CALL('XDateTime_GetButton',hEle,nType);
end

function XMonthCal_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XMonthCal_Create',x,y,cx,cy,hParent);
end

function XMonthCal_SetToday(hEle,nYear,nMonth,nDay)
return XC_API_CALL('XMonthCal_SetToday',hEle,nYear,nMonth,nDay);
end

function XMonthCal_GetToday(hEle,pnYear,pnMonth,pnDay)
return XC_API_CALL('XMonthCal_GetToday',hEle,pnYear,pnMonth,pnDay);
end

function XMonthCal_SeSelDate(hEle,nYear,nMonth,nDay)
return XC_API_CALL('XMonthCal_SeSelDate',hEle,nYear,nMonth,nDay);
end

function XMonthCal_GetSelDate(hEle,pnYear,pnMonth,pnDay)
return XC_API_CALL('XMonthCal_GetSelDate',hEle,pnYear,pnMonth,pnDay);
end

function XMonthCal_GetButton(hEle,nType)
return XC_API_CALL('XMonthCal_GetButton',hEle,nType);
end

function XC_UnicodeToAnsi(pIn,inLen,pOut,outLen)
return XC_API_CALL('XC_UnicodeToAnsi',pIn,inLen,pOut,outLen);
end

function XC_AnsiToUnicode(pIn,inLen,pOut,outLen)
return XC_API_CALL('XC_AnsiToUnicode',pIn,inLen,pOut,outLen);
end

function XC_DebugToFileInfo(pInfo)
return XC_API_CALL('XC_DebugToFileInfo',pInfo);
end

function XC_IsHELE(hEle)
return XC_API_CALL('XC_IsHELE',hEle);
end

function XC_IsHWINDOW(hWindow)
return XC_API_CALL('XC_IsHWINDOW',hWindow);
end

function XC_IsShape(hShape)
return XC_API_CALL('XC_IsShape',hShape);
end

function XC_IsHXCGUI(hXCGUI,nType)
return XC_API_CALL('XC_IsHXCGUI',hXCGUI,nType);
end

function XC_hWindowFromHWnd(hWnd)
return XC_API_CALL('XC_hWindowFromHWnd',hWnd);
end

function XC_RegisterWindowClassName(pClassName)
return XC_API_CALL('XC_RegisterWindowClassName',pClassName);
end

function XC_IsSViewExtend(hEle)
return XC_API_CALL('XC_IsSViewExtend',hEle);
end

function XC_GetObjectType(hXCGUI)
return XC_API_CALL('XC_GetObjectType',hXCGUI);
end

function XC_GetObjectByID(hWindow,nID)
return XC_API_CALL('XC_GetObjectByID',hWindow,nID);
end

function XC_GetObjectByIDName(hWindow,pName)
return XC_API_CALL('XC_GetObjectByIDName',hWindow,pName);
end

function XC_GetResIDValue(pName)
return XC_API_CALL('XC_GetResIDValue',pName);
end

function XC_GetResImage(pName)
return XC_API_CALL('XC_GetResImage',pName);
end

function XC_SetPaintFrequency(nMilliseconds)
return XC_API_CALL('XC_SetPaintFrequency',nMilliseconds);
end

function XC_SetTextRenderingHint(nType)
return XC_API_CALL('XC_SetTextRenderingHint',nType);
end

function XC_RectInRect(pRect1,pRect2)
return XC_API_CALL('XC_RectInRect',pRect1,pRect2);
end

function XC_CombineRect(pDest,pSrc1,pSrc2)
return XC_API_CALL('XC_CombineRect',pDest,pSrc1,pSrc2);
end

function XC_ShowLayoutFrame(bShow)
return XC_API_CALL('XC_ShowLayoutFrame',bShow);
end

function XC_EnableDebugFile(bEnable)
return XC_API_CALL('XC_EnableDebugFile',bEnable);
end

function XC_SetLayoutFrameColor(color)
return XC_API_CALL('XC_SetLayoutFrameColor',color);
end

function XC_EnableErrorMessageBox(bEnabel)
return XC_API_CALL('XC_EnableErrorMessageBox',bEnabel);
end

function XC_LoadLayout(pFileName,hParent)
return XC_API_CALL('XC_LoadLayout',pFileName,hParent);
end

function XC_LoadLayoutFromString(pStringXML,hParent)
return XC_API_CALL('XC_LoadLayoutFromString',pStringXML,hParent);
end

function XC_LoadResource(pFileName,pDir)
return XC_API_CALL('XC_LoadResource',pFileName,pDir);
end

function XC_LoadResourceFromString(pStringXML,pDir)
return XC_API_CALL('XC_LoadResourceFromString',pStringXML,pDir);
end

function XC_LoadTemplate(nType,pFileName)
return XC_API_CALL('XC_LoadTemplate',nType,pFileName);
end

function XC_LoadTemplateFromString(nType,pStringXML)
return XC_API_CALL('XC_LoadTemplateFromString',nType,pStringXML);
end

function XC_TemplateDestroy(pInfo)
return XC_API_CALL('XC_TemplateDestroy',pInfo);
end

function XC_GetTextSize(pString,length,hFontX,pOutSize)
return XC_API_CALL('XC_GetTextSize',pString,length,hFontX,pOutSize);
end

function XC_GetTextShowSize(pString,length,hFontX,pOutSize)
return XC_API_CALL('XC_GetTextShowSize',pString,length,hFontX,pOutSize);
end

function XC_GetDefaultFont()
return XC_API_CALL('XC_GetDefaultFont');
end

function XC_SetDefaultFont(hFontX)
return XC_API_CALL('XC_SetDefaultFont',hFontX);
end

function XC_InitFont(pFont,pName,size,bBold,bItalic,bUnderline,bStrikeOut)
return XC_API_CALL('XC_InitFont',pFont,pName,size,bBold,bItalic,bUnderline,bStrikeOut);
end

function XC_Malloc(size)
return XC_API_CALL('XC_Malloc',size);
end

function XC_Free(p)
return XC_API_CALL('XC_Free',p);
end

function _XC_SetType(hXCGUI,nType)
return XC_API_CALL('_XC_SetType',hXCGUI,nType);
end

function _XC_AddType(hXCGUI,nType)
return XC_API_CALL('_XC_AddType',hXCGUI,nType);
end

function _XC_BindData(hXCGUI,data)
return XC_API_CALL('_XC_BindData',hXCGUI,data);
end

function _XC_GetBindData(hXCGUI)
return XC_API_CALL('_XC_GetBindData',hXCGUI);
end

function XInitXCGUI(pText)
return XC_API_CALL('XInitXCGUI',pText);
end

function XRunXCGUI()
return XC_API_CALL('XRunXCGUI');
end

function XExitXCGUI()
return XC_API_CALL('XExitXCGUI');
end

function XBkInfoM_Create()
return XC_API_CALL('XBkInfoM_Create');
end

function XBkInfoM_Destroy(hBkInfoM)
return XC_API_CALL('XBkInfoM_Destroy',hBkInfoM);
end

function XBkInfoM_SetBkInfo(hBkInfoM,pText)
return XC_API_CALL('XBkInfoM_SetBkInfo',hBkInfoM,pText);
end

function XBkInfoM_AddBorder(hBkInfoM,nState,color,alpha,width)
return XC_API_CALL('XBkInfoM_AddBorder',hBkInfoM,nState,color,alpha,width);
end

function XBkInfoM_AddFill(hBkInfoM,nState,color,alpha)
return XC_API_CALL('XBkInfoM_AddFill',hBkInfoM,nState,color,alpha);
end

function XBkInfoM_AddImage(hBkInfoM,nState,hImage)
return XC_API_CALL('XBkInfoM_AddImage',hBkInfoM,nState,hImage);
end

function XBkInfoM_GetCount(hBkInfoM)
return XC_API_CALL('XBkInfoM_GetCount',hBkInfoM);
end

function XBkInfoM_Clear(hBkInfoM)
return XC_API_CALL('XBkInfoM_Clear',hBkInfoM);
end

function XBkInfoM_Draw(hBkInfoM,nState,hDraw,pRect)
return XC_API_CALL('XBkInfoM_Draw',hBkInfoM,nState,hDraw,pRect);
end

function XBkInfoM_DrawEx(hBkInfoM,nState,hDraw,pRect,nStateFilter)
return XC_API_CALL('XBkInfoM_DrawEx',hBkInfoM,nState,hDraw,pRect,nStateFilter);
end

function XBtn_Create(x,y,cx,cy,pName,hParent)
return XC_API_CALL('XBtn_Create',x,y,cx,cy,pName,hParent);
end

function XBtn_IsCheck(hEle)
return XC_API_CALL('XBtn_IsCheck',hEle);
end

function XBtn_SetCheck(hEle,bCheck)
return XC_API_CALL('XBtn_SetCheck',hEle,bCheck);
end

function XBtn_SetState(hEle,nState)
return XC_API_CALL('XBtn_SetState',hEle,nState);
end

function XBtn_GetState(hEle)
return XC_API_CALL('XBtn_GetState',hEle);
end

function XBtn_GetStateEx(hEle)
return XC_API_CALL('XBtn_GetStateEx',hEle);
end

function XBtn_SetStyle(hEle,nStyle)
return XC_API_CALL('XBtn_SetStyle',hEle,nStyle);
end

function XBtn_GetStyle(hEle)
return XC_API_CALL('XBtn_GetStyle',hEle);
end

function XBtn_SetType(hEle,nType)
return XC_API_CALL('XBtn_SetType',hEle,nType);
end

function XBtn_SetTypeEx(hEle,nType)
return XC_API_CALL('XBtn_SetTypeEx',hEle,nType);
end

function XBtn_GetType(hEle)
return XC_API_CALL('XBtn_GetType',hEle);
end

function XBtn_SetGroupID(hEle,nID)
return XC_API_CALL('XBtn_SetGroupID',hEle,nID);
end

function XBtn_GetGroupID(hEle)
return XC_API_CALL('XBtn_GetGroupID',hEle);
end

function XBtn_SetBindEle(hEle,hBindEle)
return XC_API_CALL('XBtn_SetBindEle',hEle,hBindEle);
end

function XBtn_GetBindEle(hEle)
return XC_API_CALL('XBtn_GetBindEle',hEle);
end

function XBtn_SetTextAlign(hEle,nFlags)
return XC_API_CALL('XBtn_SetTextAlign',hEle,nFlags);
end

function XBtn_GetTextAlign(hEle)
return XC_API_CALL('XBtn_GetTextAlign',hEle);
end

function XBtn_SetIconAlign(hEle,align)
return XC_API_CALL('XBtn_SetIconAlign',hEle,align);
end

function XBtn_SetOffset(hEle,x,y)
return XC_API_CALL('XBtn_SetOffset',hEle,x,y);
end

function XBtn_SetOffsetIcon(hEle,x,y)
return XC_API_CALL('XBtn_SetOffsetIcon',hEle,x,y);
end

function XBtn_SetIconSpace(hEle,size)
return XC_API_CALL('XBtn_SetIconSpace',hEle,size);
end

function XBtn_GetText(hEle,pOut,nOutLen)
return XC_API_CALL('XBtn_GetText',hEle,pOut,nOutLen);
end

function XBtn_SetText(hEle,pName)
return XC_API_CALL('XBtn_SetText',hEle,pName);
end

function XBtn_SetIcon(hEle,hImage)
return XC_API_CALL('XBtn_SetIcon',hEle,hImage);
end

function XBtn_SetIconDisable(hEle,hImage)
return XC_API_CALL('XBtn_SetIconDisable',hEle,hImage);
end

function XBtn_AddAnimationFrame(hEle,hImage,uElapse)
return XC_API_CALL('XBtn_AddAnimationFrame',hEle,hImage,uElapse);
end

function XBtn_EnableAnimation(hEle,bEnable,bLoopPlay)
return XC_API_CALL('XBtn_EnableAnimation',hEle,bEnable,bLoopPlay);
end

function XBtn_AddBkBorder(hEle,nState,color,alpha,width)
return XC_API_CALL('XBtn_AddBkBorder',hEle,nState,color,alpha,width);
end

function XBtn_AddBkFill(hEle,nState,color,alpha)
return XC_API_CALL('XBtn_AddBkFill',hEle,nState,color,alpha);
end

function XBtn_AddBkImage(hEle,nState,hImage)
return XC_API_CALL('XBtn_AddBkImage',hEle,nState,hImage);
end

function XBtn_GetBkInfoCount(hEle)
return XC_API_CALL('XBtn_GetBkInfoCount',hEle);
end

function XBtn_ClearBkInfo(hEle)
return XC_API_CALL('XBtn_ClearBkInfo',hEle);
end

function XComboBox_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XComboBox_Create',x,y,cx,cy,hParent);
end

function XComboBox_SetSelItem(hEle,iIndex)
return XC_API_CALL('XComboBox_SetSelItem',hEle,iIndex);
end

function XComboBox_GetButtonRect(hEle,pRect)
return XC_API_CALL('XComboBox_GetButtonRect',hEle,pRect);
end

function XComboBox_SetButtonSize(hEle,size)
return XC_API_CALL('XComboBox_SetButtonSize',hEle,size);
end

function XComboBox_SetDropHeight(hEle,height)
return XC_API_CALL('XComboBox_SetDropHeight',hEle,height);
end

function XComboBox_GetDropHeight(hEle)
return XC_API_CALL('XComboBox_GetDropHeight',hEle);
end

function XComboBox_BindApapter(hEle,hAdapter)
return XC_API_CALL('XComboBox_BindApapter',hEle,hAdapter);
end

function XComboBox_GetApapter(hEle)
return XC_API_CALL('XComboBox_GetApapter',hEle);
end

function XComboBox_SetItemTemplateXML(hEle,pXmlFile)
return XC_API_CALL('XComboBox_SetItemTemplateXML',hEle,pXmlFile);
end

function XComboBox_SetItemTemplateXMLFromString(hEle,pStringXML)
return XC_API_CALL('XComboBox_SetItemTemplateXMLFromString',hEle,pStringXML);
end

function XComboBox_EnableDrawButton(hEle,bEnable)
return XC_API_CALL('XComboBox_EnableDrawButton',hEle,bEnable);
end

function XComboBox_EnableEdit(hEle,bEdit)
return XC_API_CALL('XComboBox_EnableEdit',hEle,bEdit);
end

function XComboBox_AddBkBorder(hEle,nState,color,alpha,width)
return XC_API_CALL('XComboBox_AddBkBorder',hEle,nState,color,alpha,width);
end

function XComboBox_AddBkFill(hEle,nState,color,alpha)
return XC_API_CALL('XComboBox_AddBkFill',hEle,nState,color,alpha);
end

function XComboBox_AddBkImage(hEle,nState,hImage)
return XC_API_CALL('XComboBox_AddBkImage',hEle,nState,hImage);
end

function XComboboX_GetBkInfoCount(hEle)
return XC_API_CALL('XComboboX_GetBkInfoCount',hEle);
end

function XComboBox_ClearBkInfo(hEle)
return XC_API_CALL('XComboBox_ClearBkInfo',hEle);
end

function XComboBox_GetSelItem(hEle)
return XC_API_CALL('XComboBox_GetSelItem',hEle);
end

function XComboBox_GetState(hEle)
return XC_API_CALL('XComboBox_GetState',hEle);
end

function XAdapter_Destroy(hAdapter)
return XC_API_CALL('XAdapter_Destroy',hAdapter);
end

function XAdapterListView_Create()
return XC_API_CALL('XAdapterListView_Create');
end

function XAdapterListView_Group_AddColumn(hAdapter,pName)
return XC_API_CALL('XAdapterListView_Group_AddColumn',hAdapter,pName);
end

function XAdapterListView_Group_AddItemText(hAdapter,pValue)
return XC_API_CALL('XAdapterListView_Group_AddItemText',hAdapter,pValue);
end

function XAdapterListView_Group_AddItemTextEx(hAdapter,pName,pValue)
return XC_API_CALL('XAdapterListView_Group_AddItemTextEx',hAdapter,pName,pValue);
end

function XAdapterListView_Group_AddItemImage(hAdapter,hImage)
return XC_API_CALL('XAdapterListView_Group_AddItemImage',hAdapter,hImage);
end

function XAdapterListView_Group_AddItemImageEx(hAdapter,pName,hImage)
return XC_API_CALL('XAdapterListView_Group_AddItemImageEx',hAdapter,pName,hImage);
end

function XAdapterListView_Group_SetText(hAdapter,iGroup,iColumn,pValue)
return XC_API_CALL('XAdapterListView_Group_SetText',hAdapter,iGroup,iColumn,pValue);
end

function XAdapterListView_Group_SetTextEx(hAdapter,iGroup,pName,pValue)
return XC_API_CALL('XAdapterListView_Group_SetTextEx',hAdapter,iGroup,pName,pValue);
end

function XAdapterListView_Group_SetImage(hAdapter,iGroup,iColumn,hImage)
return XC_API_CALL('XAdapterListView_Group_SetImage',hAdapter,iGroup,iColumn,hImage);
end

function XAdapterListView_Group_SetImageEx(hAdapter,iGroup,pName,hImage)
return XC_API_CALL('XAdapterListView_Group_SetImageEx',hAdapter,iGroup,pName,hImage);
end

function XAdapterListView_Group_GetCount(hAdapter)
return XC_API_CALL('XAdapterListView_Group_GetCount',hAdapter);
end

function XAdapterListView_Item_GetCount(hAdapter,iGroup)
return XC_API_CALL('XAdapterListView_Item_GetCount',hAdapter,iGroup);
end

function XAdapterListView_Item_AddColumn(hAdapter,pName)
return XC_API_CALL('XAdapterListView_Item_AddColumn',hAdapter,pName);
end

function XAdapterListView_Item_AddItemText(hAdapter,iGroup,pValue)
return XC_API_CALL('XAdapterListView_Item_AddItemText',hAdapter,iGroup,pValue);
end

function XAdapterListView_Item_AddItemTextEx(hAdapter,iGroup,pName,pValue)
return XC_API_CALL('XAdapterListView_Item_AddItemTextEx',hAdapter,iGroup,pName,pValue);
end

function XAdapterListView_Item_AddItemImage(hAdapter,iGroup,hImage)
return XC_API_CALL('XAdapterListView_Item_AddItemImage',hAdapter,iGroup,hImage);
end

function XAdapterListView_Item_AddItemImageEx(hAdapter,iGroup,pName,hImage)
return XC_API_CALL('XAdapterListView_Item_AddItemImageEx',hAdapter,iGroup,pName,hImage);
end

function XAdapterListView_Item_SetText(hAdapter,iGroup,iItem,iColumn,pValue)
return XC_API_CALL('XAdapterListView_Item_SetText',hAdapter,iGroup,iItem,iColumn,pValue);
end

function XAdapterListView_Item_SetTextEx(hAdapter,iGroup,iItem,pName,pValue)
return XC_API_CALL('XAdapterListView_Item_SetTextEx',hAdapter,iGroup,iItem,pName,pValue);
end

function XAdapterListView_Item_SetImage(hAdapter,iGroup,iItem,iColumn,hImage)
return XC_API_CALL('XAdapterListView_Item_SetImage',hAdapter,iGroup,iItem,iColumn,hImage);
end

function XAdapterListView_Item_SetImageEx(hAdapter,iGroup,iItem,pName,hImage)
return XC_API_CALL('XAdapterListView_Item_SetImageEx',hAdapter,iGroup,iItem,pName,hImage);
end

function XAdapterListView_Group_DeleteItem(hAdapter,iGroup)
return XC_API_CALL('XAdapterListView_Group_DeleteItem',hAdapter,iGroup);
end

function XAdapterListView_Group_DeleteAllChildItem(hAdapter,iGroup)
return XC_API_CALL('XAdapterListView_Group_DeleteAllChildItem',hAdapter,iGroup);
end

function XAdapterListView_Item_DeleteItem(hAdapter,iGroup,iItem)
return XC_API_CALL('XAdapterListView_Item_DeleteItem',hAdapter,iGroup,iItem);
end

function XAdapterListView_DeleteAll(hAdapter)
return XC_API_CALL('XAdapterListView_DeleteAll',hAdapter);
end

function XAdapterListView_DeleteAllGroup(hAdapter)
return XC_API_CALL('XAdapterListView_DeleteAllGroup',hAdapter);
end

function XAdapterListView_DeleteAllItem(hAdapter)
return XC_API_CALL('XAdapterListView_DeleteAllItem',hAdapter);
end

function XAdapterListView_DeleteColumnGroup(hAdapter,iColumn)
return XC_API_CALL('XAdapterListView_DeleteColumnGroup',hAdapter,iColumn);
end

function XAdapterListView_DeleteColumnItem(hAdapter,iColumn)
return XC_API_CALL('XAdapterListView_DeleteColumnItem',hAdapter,iColumn);
end

function XAdapterListView_Item_GetTextEx(hAdapter,iGroup,iItem,pName,pOut,nOutLen)
return XC_API_CALL('XAdapterListView_Item_GetTextEx',hAdapter,iGroup,iItem,pName,pOut,nOutLen);
end

function XAdapterListView_Item_GetImageEx(hAdapter,iGroup,iItem,pName)
return XC_API_CALL('XAdapterListView_Item_GetImageEx',hAdapter,iGroup,iItem,pName);
end

function XAdapterTable_Create()
return XC_API_CALL('XAdapterTable_Create');
end

function XAdapterTable_Sort(hAdapter,iColumn,bAscending)
return XC_API_CALL('XAdapterTable_Sort',hAdapter,iColumn,bAscending);
end

function XAdapterTable_GetItemDataType(hAdapter,iItem,iColumn)
return XC_API_CALL('XAdapterTable_GetItemDataType',hAdapter,iItem,iColumn);
end

function XAdapterTable_GetItemDataTypeEx(hAdapter,iItem,pName)
return XC_API_CALL('XAdapterTable_GetItemDataTypeEx',hAdapter,iItem,pName);
end

function XAdapterTable_AddColumn(hAdapter,pName)
return XC_API_CALL('XAdapterTable_AddColumn',hAdapter,pName);
end

function XAdapterTable_SetColumn(hAdapter,pColName)
return XC_API_CALL('XAdapterTable_SetColumn',hAdapter,pColName);
end

function XAdapterTable_AddItemText(hAdapter,pValue)
return XC_API_CALL('XAdapterTable_AddItemText',hAdapter,pValue);
end

function XAdapterTable_AddItemTextEx(hAdapter,pName,pValue)
return XC_API_CALL('XAdapterTable_AddItemTextEx',hAdapter,pName,pValue);
end

function XAdapterTable_AddItemImage(hAdapter,hImage)
return XC_API_CALL('XAdapterTable_AddItemImage',hAdapter,hImage);
end

function XAdapterTable_AddItemImageEx(hAdapter,pName,hImage)
return XC_API_CALL('XAdapterTable_AddItemImageEx',hAdapter,pName,hImage);
end

function XAdapterTable_InsertItemText(hAdapter,iItem,pValue)
return XC_API_CALL('XAdapterTable_InsertItemText',hAdapter,iItem,pValue);
end

function XAdapterTable_InsertItemTextEx(hAdapter,iItem,pName,pValue)
return XC_API_CALL('XAdapterTable_InsertItemTextEx',hAdapter,iItem,pName,pValue);
end

function XAdapterTable_InsertItemImage(hAdapter,iItem,hImage)
return XC_API_CALL('XAdapterTable_InsertItemImage',hAdapter,iItem,hImage);
end

function XAdapterTable_InsertItemImageEx(hAdapter,iItem,pName,hImage)
return XC_API_CALL('XAdapterTable_InsertItemImageEx',hAdapter,iItem,pName,hImage);
end

function XAdapterTable_SetItemText(hAdapter,iItem,iColumn,pValue)
return XC_API_CALL('XAdapterTable_SetItemText',hAdapter,iItem,iColumn,pValue);
end

function XAdapterTable_SetItemTextEx(hAdapter,iItem,pName,pValue)
return XC_API_CALL('XAdapterTable_SetItemTextEx',hAdapter,iItem,pName,pValue);
end

function XAdapterTable_SetItemInt(hAdapter,iItem,iColumn,nValue)
return XC_API_CALL('XAdapterTable_SetItemInt',hAdapter,iItem,iColumn,nValue);
end

function XAdapterTable_SetItemIntEx(hAdapter,iItem,pName,nValue)
return XC_API_CALL('XAdapterTable_SetItemIntEx',hAdapter,iItem,pName,nValue);
end

function XAdapterTable_SetItemFloat(hAdapter,iItem,iColumn,nValue)
return XC_API_CALL('XAdapterTable_SetItemFloat',hAdapter,iItem,iColumn,nValue);
end

function XAdapterTable_SetItemFloatEx(hAdapter,iItem,pName,nValue)
return XC_API_CALL('XAdapterTable_SetItemFloatEx',hAdapter,iItem,pName,nValue);
end

function XAdapterTable_SetItemImage(hAdapter,iItem,iColumn,hImage)
return XC_API_CALL('XAdapterTable_SetItemImage',hAdapter,iItem,iColumn,hImage);
end

function XAdapterTable_SetItemImageEx(hAdapter,iItem,pName,hImage)
return XC_API_CALL('XAdapterTable_SetItemImageEx',hAdapter,iItem,pName,hImage);
end

function XAdapterTable_DeleteItem(hAdapter,iItem)
return XC_API_CALL('XAdapterTable_DeleteItem',hAdapter,iItem);
end

function XAdapterTable_DeleteItemEx(hAdapter,iItem,nCount)
return XC_API_CALL('XAdapterTable_DeleteItemEx',hAdapter,iItem,nCount);
end

function XAdapterTable_DeleteItemAll(hAdapter)
return XC_API_CALL('XAdapterTable_DeleteItemAll',hAdapter);
end

function XAdapterTable_DeleteColumnAll(hAdapter)
return XC_API_CALL('XAdapterTable_DeleteColumnAll',hAdapter);
end

function XAdapterTable_GetCount(hAdapter)
return XC_API_CALL('XAdapterTable_GetCount',hAdapter);
end

function XAdapterTable_GetCountColumn(hAdapter)
return XC_API_CALL('XAdapterTable_GetCountColumn',hAdapter);
end

function XAdapterTable_GetItemText(hAdapter,iItem,iColumn,pOut,nOutLen)
return XC_API_CALL('XAdapterTable_GetItemText',hAdapter,iItem,iColumn,pOut,nOutLen);
end

function XAdapterTable_GetItemTextEx(hAdapter,iItem,pName,pOut,nOutLen)
return XC_API_CALL('XAdapterTable_GetItemTextEx',hAdapter,iItem,pName,pOut,nOutLen);
end

function XAdapterTable_GetItemImage(hAdapter,iItem,iColumn)
return XC_API_CALL('XAdapterTable_GetItemImage',hAdapter,iItem,iColumn);
end

function XAdapterTable_GetItemImageEx(hAdapter,iItem,pName)
return XC_API_CALL('XAdapterTable_GetItemImageEx',hAdapter,iItem,pName);
end

function XAdapterTable_GetItemInt(hAdapter,iItem,iColumn,pOutValue)
return XC_API_CALL('XAdapterTable_GetItemInt',hAdapter,iItem,iColumn,pOutValue);
end

function XAdapterTable_GetItemIntEx(hAdapter,iItem,pName,pOutValue)
return XC_API_CALL('XAdapterTable_GetItemIntEx',hAdapter,iItem,pName,pOutValue);
end

function XAdapterTable_GetItemFloat(hAdapter,iItem,iColumn,pOutValue)
return XC_API_CALL('XAdapterTable_GetItemFloat',hAdapter,iItem,iColumn,pOutValue);
end

function XAdapterTable_GetItemFloatEx(hAdapter,iItem,pName,pOutValue)
return XC_API_CALL('XAdapterTable_GetItemFloatEx',hAdapter,iItem,pName,pOutValue);
end

function XAdapterTree_Create()
return XC_API_CALL('XAdapterTree_Create');
end

function XAdapterTree_AddColumn(hAdapter,pName)
return XC_API_CALL('XAdapterTree_AddColumn',hAdapter,pName);
end

function XAdapterTree_SetColumn(hAdapter,pColName)
return XC_API_CALL('XAdapterTree_SetColumn',hAdapter,pColName);
end

function XAdapterTree_InsertItemText(hAdapter,pValue,nParentID,insertID)
return XC_API_CALL('XAdapterTree_InsertItemText',hAdapter,pValue,nParentID,insertID);
end

function XAdapterTree_InsertItemTextEx(hAdapter,pName,pValue,nParentID,insertID)
return XC_API_CALL('XAdapterTree_InsertItemTextEx',hAdapter,pName,pValue,nParentID,insertID);
end

function XAdapterTree_InsertItemImage(hAdapter,hImage,nParentID,insertID)
return XC_API_CALL('XAdapterTree_InsertItemImage',hAdapter,hImage,nParentID,insertID);
end

function XAdapterTree_InsertItemImageEx(hAdapter,pName,hImage,nParentID,insertID)
return XC_API_CALL('XAdapterTree_InsertItemImageEx',hAdapter,pName,hImage,nParentID,insertID);
end

function XAdapterTree_GetCount(hAdapter)
return XC_API_CALL('XAdapterTree_GetCount',hAdapter);
end

function XAdapterTree_GetCountColumn(hAdapter)
return XC_API_CALL('XAdapterTree_GetCountColumn',hAdapter);
end

function XAdapterTree_SetItemText(hAdapter,nID,iColumn,pValue)
return XC_API_CALL('XAdapterTree_SetItemText',hAdapter,nID,iColumn,pValue);
end

function XAdapterTree_SetItemTextEx(hAdapter,nID,pName,pValue)
return XC_API_CALL('XAdapterTree_SetItemTextEx',hAdapter,nID,pName,pValue);
end

function XAdapterTree_SetItemImage(hAdapter,nID,iColumn,hImage)
return XC_API_CALL('XAdapterTree_SetItemImage',hAdapter,nID,iColumn,hImage);
end

function XAdapterTree_SetItemImageEx(hAdapter,nID,pName,hImage)
return XC_API_CALL('XAdapterTree_SetItemImageEx',hAdapter,nID,pName,hImage);
end

function XAdapterTree_GetItemText(hAdapter,nID,iColumn,pOut,nOutLen)
return XC_API_CALL('XAdapterTree_GetItemText',hAdapter,nID,iColumn,pOut,nOutLen);
end

function XAdapterTree_GetItemImage(hAdapter,nID,iColumn)
return XC_API_CALL('XAdapterTree_GetItemImage',hAdapter,nID,iColumn);
end

function XAdapterTree_GetItemTextEx(hAdapter,nID,pName,pOut,nOutLen)
return XC_API_CALL('XAdapterTree_GetItemTextEx',hAdapter,nID,pName,pOut,nOutLen);
end

function XAdapterTree_GetItemImageEx(hAdapter,nID,pName)
return XC_API_CALL('XAdapterTree_GetItemImageEx',hAdapter,nID,pName);
end

function XAdapterTree_DeleteItem(hAdapter,nID)
return XC_API_CALL('XAdapterTree_DeleteItem',hAdapter,nID);
end

function XAdapterTree_DeleteItemAll(hAdapter)
return XC_API_CALL('XAdapterTree_DeleteItemAll',hAdapter);
end

function XAdapterTree_DeleteColumnAll(hAdapter)
return XC_API_CALL('XAdapterTree_DeleteColumnAll',hAdapter);
end

function XAdapterMap_Create()
return XC_API_CALL('XAdapterMap_Create');
end

function XAdapterMap_AddItemText(hAdapter,pName,pValue)
return XC_API_CALL('XAdapterMap_AddItemText',hAdapter,pName,pValue);
end

function XAdapterMap_AddItemImage(hAdapter,pName,hImage)
return XC_API_CALL('XAdapterMap_AddItemImage',hAdapter,pName,hImage);
end

function XAdapterMap_DeleteItem(hAdapter,pName)
return XC_API_CALL('XAdapterMap_DeleteItem',hAdapter,pName);
end

function XAdapterMap_GetCount(hAdapter)
return XC_API_CALL('XAdapterMap_GetCount',hAdapter);
end

function XAdapterMap_GetItemText(hAdapter,pName,pOut,nOutLen)
return XC_API_CALL('XAdapterMap_GetItemText',hAdapter,pName,pOut,nOutLen);
end

function XAdapterMap_GetItemImage(hAdapter,pName)
return XC_API_CALL('XAdapterMap_GetItemImage',hAdapter,pName);
end

function XAdapterMap_SetItemText(hAdapter,pName,pValue)
return XC_API_CALL('XAdapterMap_SetItemText',hAdapter,pName,pValue);
end

function XAdapterMap_SetItemImage(hAdapter,pName,hImage)
return XC_API_CALL('XAdapterMap_SetItemImage',hAdapter,pName,hImage);
end

function _XC_DebugPrintf(level,pFormat,...)
return XC_API_CALL('_XC_DebugPrintf',level,pFormat,...);
end

function _XC_DebugPrintfW(level,pFormat,...)
return XC_API_CALL('_XC_DebugPrintfW',level,pFormat,...);
end

function xtrace(pFormat,...)
return XC_API_CALL('xtrace',pFormat,...);
end

function xtracew(pFormat,...)
return XC_API_CALL('xtracew',pFormat,...);
end

function XDraw_Create(hdc)
return XC_API_CALL('XDraw_Create',hdc);
end

function XDraw_Destroy(hDraw)
return XC_API_CALL('XDraw_Destroy',hDraw);
end

function XDraw_SetOffset(hDraw,x,y)
return XC_API_CALL('XDraw_SetOffset',hDraw,x,y);
end

function XDraw_GetOffset(hDraw,pX,pY)
return XC_API_CALL('XDraw_GetOffset',hDraw,pX,pY);
end

function XDraw_RestoreGDIOBJ(hDraw)
return XC_API_CALL('XDraw_RestoreGDIOBJ',hDraw);
end

function XDraw_GetHDC(hDraw)
return XC_API_CALL('XDraw_GetHDC',hDraw);
end

function XDraw_SetBrushColor(hDraw,color,alpha)
return XC_API_CALL('XDraw_SetBrushColor',hDraw,color,alpha);
end

function XDraw_SetTextAlign(hDraw,nFlag)
return XC_API_CALL('XDraw_SetTextAlign',hDraw,nFlag);
end

function XDraw_SetTextVertical(hDraw,bVertical)
return XC_API_CALL('XDraw_SetTextVertical',hDraw,bVertical);
end

function XDraw_SetFontX(hDraw,hFontx)
return XC_API_CALL('XDraw_SetFontX',hDraw,hFontx);
end

function XDraw_SetLineWidth(hDraw,nWidth)
return XC_API_CALL('XDraw_SetLineWidth',hDraw,nWidth);
end

function XDraw_SetBkMode(hDraw,bTransparent)
return XC_API_CALL('XDraw_SetBkMode',hDraw,bTransparent);
end

function XDraw_EnableSmoothingMode(hDraw,bEnable)
return XC_API_CALL('XDraw_EnableSmoothingMode',hDraw,bEnable);
end

function XDraw_CreateSolidBrush(hDraw,crColor)
return XC_API_CALL('XDraw_CreateSolidBrush',hDraw,crColor);
end

function XDraw_CreatePen(hDraw,fnPenStyle,nWidth,crColor)
return XC_API_CALL('XDraw_CreatePen',hDraw,fnPenStyle,nWidth,crColor);
end

function XDraw_CreateRectRgn(hDraw,nLeftRect,nTopRect,nRightRect,nBottomRect)
return XC_API_CALL('XDraw_CreateRectRgn',hDraw,nLeftRect,nTopRect,nRightRect,nBottomRect);
end

function XDraw_CreateRoundRectRgn(hDraw,nLeftRect,nTopRect,nRightRect,nBottomRect,nWidthEllipse,nHeightEllipse)
return XC_API_CALL('XDraw_CreateRoundRectRgn',hDraw,nLeftRect,nTopRect,nRightRect,nBottomRect,nWidthEllipse,nHeightEllipse);
end

function XDraw_CreatePolygonRgn(hDraw,pPt,cPoints,fnPolyFillMode)
return XC_API_CALL('XDraw_CreatePolygonRgn',hDraw,pPt,cPoints,fnPolyFillMode);
end

function XDraw_SelectClipRgn(hDraw,hRgn)
return XC_API_CALL('XDraw_SelectClipRgn',hDraw,hRgn);
end

function XDraw_FillRect(hDraw,pRect)
return XC_API_CALL('XDraw_FillRect',hDraw,pRect);
end

function XDraw_FillRectColor(hDraw,pRect,color,alpha)
return XC_API_CALL('XDraw_FillRectColor',hDraw,pRect,color,alpha);
end

function XDraw_FillRgn(hDraw,hrgn,hbr)
return XC_API_CALL('XDraw_FillRgn',hDraw,hrgn,hbr);
end

function XDraw_FillEllipse(hDraw,pRect)
return XC_API_CALL('XDraw_FillEllipse',hDraw,pRect);
end

function XDraw_DrawEllipse(hDraw,pRect)
return XC_API_CALL('XDraw_DrawEllipse',hDraw,pRect);
end

function XDraw_FillRoundRect(hDraw,pRect,nWidth,nHeight)
return XC_API_CALL('XDraw_FillRoundRect',hDraw,pRect,nWidth,nHeight);
end

function XDraw_DrawRoundRect(hDraw,pRect,nWidth,nHeight)
return XC_API_CALL('XDraw_DrawRoundRect',hDraw,pRect,nWidth,nHeight);
end

function XDraw_Rectangle(hDraw,nLeftRect,nTopRect,nRightRect,nBottomRect)
return XC_API_CALL('XDraw_Rectangle',hDraw,nLeftRect,nTopRect,nRightRect,nBottomRect);
end

function XDraw_DrawGroupBox_Rect(hDraw,pRect,pName,textColor,textAlpha,pOffset)
return XC_API_CALL('XDraw_DrawGroupBox_Rect',hDraw,pRect,pName,textColor,textAlpha,pOffset);
end

function XDraw_DrawGroupBox_RoundRect(hDraw,pRect,pName,textColor,textAlpha,pOffset,nWidth,nHeight)
return XC_API_CALL('XDraw_DrawGroupBox_RoundRect',hDraw,pRect,pName,textColor,textAlpha,pOffset,nWidth,nHeight);
end

function XDraw_GradientFill2(hDraw,color1,alpha1,color2,alpha2,pRect,mode)
return XC_API_CALL('XDraw_GradientFill2',hDraw,color1,alpha1,color2,alpha2,pRect,mode);
end

function XDraw_GradientFill4(hDraw,color1,color2,color3,color4,pRect,mode)
return XC_API_CALL('XDraw_GradientFill4',hDraw,color1,color2,color3,color4,pRect,mode);
end

function XDraw_FrameRgn(hDraw,hrgn,hbr,nWidth,nHeight)
return XC_API_CALL('XDraw_FrameRgn',hDraw,hrgn,hbr,nWidth,nHeight);
end

function XDraw_FrameRect(hDraw,pRect)
return XC_API_CALL('XDraw_FrameRect',hDraw,pRect);
end

function XDraw_FocusRect(hDraw,pRect)
return XC_API_CALL('XDraw_FocusRect',hDraw,pRect);
end

function XDraw_DrawLine(hDraw,x1,y1,x2,y2)
return XC_API_CALL('XDraw_DrawLine',hDraw,x1,y1,x2,y2);
end

function XDraw_MoveToEx(hDraw,X,Y,lpPoint)
return XC_API_CALL('XDraw_MoveToEx',hDraw,X,Y,lpPoint);
end

function XDraw_LineTo(hDraw,nXEnd,nYEnd)
return XC_API_CALL('XDraw_LineTo',hDraw,nXEnd,nYEnd);
end

function XDraw_Polyline(hDraw,pArrayPt,arrayPtSize)
return XC_API_CALL('XDraw_Polyline',hDraw,pArrayPt,arrayPtSize);
end

function XDraw_Dottedline(hDraw,x1,y1,x2,y2)
return XC_API_CALL('XDraw_Dottedline',hDraw,x1,y1,x2,y2);
end

function XDraw_SetPixel(hDraw,X,Y,crColor)
return XC_API_CALL('XDraw_SetPixel',hDraw,X,Y,crColor);
end

function XDraw_Check(hDraw,x,y,color,bCheck)
return XC_API_CALL('XDraw_Check',hDraw,x,y,color,bCheck);
end

function XDraw_DrawIconEx(hDraw,xLeft,yTop,hIcon,cxWidth,cyWidth,istepIfAniCur,hbrFlickerFreeDraw,diFlags)
return XC_API_CALL('XDraw_DrawIconEx',hDraw,xLeft,yTop,hIcon,cxWidth,cyWidth,istepIfAniCur,hbrFlickerFreeDraw,diFlags);
end

function XDraw_BitBlt(hDrawDest,nXDest,nYDest,nWidth,nHeight,hdcSrc,nXSrc,nYSrc,dwRop)
return XC_API_CALL('XDraw_BitBlt',hDrawDest,nXDest,nYDest,nWidth,nHeight,hdcSrc,nXSrc,nYSrc,dwRop);
end

function XDraw_BitBlt2(hDrawDest,nXDest,nYDest,nWidth,nHeight,hDrawSrc,nXSrc,nYSrc,dwRop)
return XC_API_CALL('XDraw_BitBlt2',hDrawDest,nXDest,nYDest,nWidth,nHeight,hDrawSrc,nXSrc,nYSrc,dwRop);
end

function XDraw_AlphaBlend(hDraw,nXOriginDest,nYOriginDest,nWidthDest,nHeightDest,hdcSrc,nXOriginSrc,nYOriginSrc,nWidthSrc,nHeightSrc,alpha)
return XC_API_CALL('XDraw_AlphaBlend',hDraw,nXOriginDest,nYOriginDest,nWidthDest,nHeightDest,hdcSrc,nXOriginSrc,nYOriginSrc,nWidthSrc,nHeightSrc,alpha);
end

function XDraw_TriangularArrow(hDraw,align,x,y,width,height)
return XC_API_CALL('XDraw_TriangularArrow',hDraw,align,x,y,width,height);
end

function XDraw_DrawPolygon(hDraw,points,nCount)
return XC_API_CALL('XDraw_DrawPolygon',hDraw,points,nCount);
end

function XDraw_DrawPolygonF(hDraw,points,nCount)
return XC_API_CALL('XDraw_DrawPolygonF',hDraw,points,nCount);
end

function XDraw_FillPolygon(hDraw,points,nCount)
return XC_API_CALL('XDraw_FillPolygon',hDraw,points,nCount);
end

function XDraw_FillPolygonF(hDraw,points,nCount)
return XC_API_CALL('XDraw_FillPolygonF',hDraw,points,nCount);
end

function XDraw_Image(hDraw,hImage,x,y)
return XC_API_CALL('XDraw_Image',hDraw,hImage,x,y);
end

function XDraw_Image2(hDraw,hImage,x,y,width,height)
return XC_API_CALL('XDraw_Image2',hDraw,hImage,x,y,width,height);
end

function XDraw_ImageStretch(hDraw,hImage,x,y,width,height)
return XC_API_CALL('XDraw_ImageStretch',hDraw,hImage,x,y,width,height);
end

function XDraw_ImageAdaptive(hDraw,hImage,pRect,bOnlyBorder)
return XC_API_CALL('XDraw_ImageAdaptive',hDraw,hImage,pRect,bOnlyBorder);
end

function XDraw_ImageExTile(hDraw,hImage,pRect,flag)
return XC_API_CALL('XDraw_ImageExTile',hDraw,hImage,pRect,flag);
end

function XDraw_ImageSuper(hDraw,hImage,pRect,bClip)
return XC_API_CALL('XDraw_ImageSuper',hDraw,hImage,pRect,bClip);
end

function XDraw_ImageSuper2(hDraw,hImage,pRcDest,pSrcRect)
return XC_API_CALL('XDraw_ImageSuper2',hDraw,hImage,pRcDest,pSrcRect);
end

function XDraw_DrawText(hDraw,lpString,nCount,lpRect)
return XC_API_CALL('XDraw_DrawText',hDraw,lpString,nCount,lpRect);
end

function XDraw_DrawTextUnderline(hDraw,lpString,nCount,lpRect,colorLine,alphaLine)
return XC_API_CALL('XDraw_DrawTextUnderline',hDraw,lpString,nCount,lpRect,colorLine,alphaLine);
end

function XDraw_TextOut(hDraw,nXStart,nYStart,lpString,cbString)
return XC_API_CALL('XDraw_TextOut',hDraw,nXStart,nYStart,lpString,cbString);
end

function XDraw_TextOutEx(hDraw,nXStart,nYStart,lpString)
return XC_API_CALL('XDraw_TextOutEx',hDraw,nXStart,nYStart,lpString);
end

function XDraw_TextOutA(hDraw,nXStart,nYStart,lpString)
return XC_API_CALL('XDraw_TextOutA',hDraw,nXStart,nYStart,lpString);
end

function XDraw_SetAlpha(hDraw,alpha)
return XC_API_CALL('XDraw_SetAlpha',hDraw,alpha);
end

function XDraw_SetAlphaEx(hdc,alpha)
return XC_API_CALL('XDraw_SetAlphaEx',hdc,alpha);
end

function XEle_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XEle_Create',x,y,cx,cy,hParent);
end

function XEle_RegEventEx(hEle,pEvent)
return XC_API_CALL('XEle_RegEventEx',hEle,pEvent);
end

function XEle_RemoveEventEx(hEle,pEvent)
return XC_API_CALL('XEle_RemoveEventEx',hEle,pEvent);
end

function XEle_RegEventC(hEle,nEvent,pFun)
return XC_API_CALL('XEle_RegEventC',hEle,nEvent,pFun);
end

function XEle_RegEventC1(hEle,nEvent,pFun)
return XC_API_CALL('XEle_RegEventC1',hEle,nEvent,pFun);
end

function XEle_RegEventC2(hEle,nEvent,pFun)
return XC_API_CALL('XEle_RegEventC2',hEle,nEvent,pFun);
end

function XEle_RemoveEventC(hEle,nEvent,pFun)
return XC_API_CALL('XEle_RemoveEventC',hEle,nEvent,pFun);
end

function XEle_SendEvent(hEle,hEventEle,nEvent,wParam,lParam)
return XC_API_CALL('XEle_SendEvent',hEle,hEventEle,nEvent,wParam,lParam);
end

function XEle_PostEvent(hEle,hEventEle,nEvent,wParam,lParam)
return XC_API_CALL('XEle_PostEvent',hEle,hEventEle,nEvent,wParam,lParam);
end

function XEle_IsShow(hEle)
return XC_API_CALL('XEle_IsShow',hEle);
end

function XEle_IsEnable(hEle)
return XC_API_CALL('XEle_IsEnable',hEle);
end

function XEle_IsEnableFocus(hEle)
return XC_API_CALL('XEle_IsEnableFocus',hEle);
end

function XEle_IsDrawFocus(hEle)
return XC_API_CALL('XEle_IsDrawFocus',hEle);
end

function XEle_IsEnableEvent_XE_PAINT_END(hEle)
return XC_API_CALL('XEle_IsEnableEvent_XE_PAINT_END',hEle);
end

function XEle_IsMouseThrough(hEle)
return XC_API_CALL('XEle_IsMouseThrough',hEle);
end

function XEle_IsBkTransparent(hEle)
return XC_API_CALL('XEle_IsBkTransparent',hEle);
end

function XEle_IsKeyTab(hEle)
return XC_API_CALL('XEle_IsKeyTab',hEle);
end

function XEle_IsSwitchFocus(hEle)
return XC_API_CALL('XEle_IsSwitchFocus',hEle);
end

function XEle_IsEnable_XE_MOUSEWHEEL(hEle)
return XC_API_CALL('XEle_IsEnable_XE_MOUSEWHEEL',hEle);
end

function XEle_IsInScrollView(hEle)
return XC_API_CALL('XEle_IsInScrollView',hEle);
end

function XEle_Enable(hEle,bEnable)
return XC_API_CALL('XEle_Enable',hEle,bEnable);
end

function XEle_EnableFocus(hEle,bEnable)
return XC_API_CALL('XEle_EnableFocus',hEle,bEnable);
end

function XEle_EnableDrawFocus(hEle,bEnable)
return XC_API_CALL('XEle_EnableDrawFocus',hEle,bEnable);
end

function XEle_EnableDrawBorder(hEle,bEnable)
return XC_API_CALL('XEle_EnableDrawBorder',hEle,bEnable);
end

function XEle_EnableEvent_XE_PAINT_END(hEle,bEnable)
return XC_API_CALL('XEle_EnableEvent_XE_PAINT_END',hEle,bEnable);
end

function XEle_EnableBkTransparent(hEle,bEnable)
return XC_API_CALL('XEle_EnableBkTransparent',hEle,bEnable);
end

function XEle_EnableMouseThrough(hEle,bEnable)
return XC_API_CALL('XEle_EnableMouseThrough',hEle,bEnable);
end

function XEle_EnableKeyTab(hEle,bEnable)
return XC_API_CALL('XEle_EnableKeyTab',hEle,bEnable);
end

function XEle_EnableSwitchFocus(hEle,bEnable)
return XC_API_CALL('XEle_EnableSwitchFocus',hEle,bEnable);
end

function XEle_EnableEvent_XE_MOUSEWHEEL(hEle,bEnable)
return XC_API_CALL('XEle_EnableEvent_XE_MOUSEWHEEL',hEle,bEnable);
end

function XEle_EnableInScrollView(hEle,bEnable)
return XC_API_CALL('XEle_EnableInScrollView',hEle,bEnable);
end

function XEle_SetRect(hEle,pRect,bRedraw)
return XC_API_CALL('XEle_SetRect',hEle,pRect,bRedraw);
end

function XEle_SetRectEx(hEle,x,y,cx,cy,bRedraw)
return XC_API_CALL('XEle_SetRectEx',hEle,x,y,cx,cy,bRedraw);
end

function XEle_SetRectLogic(hEle,pRect,bRedraw)
return XC_API_CALL('XEle_SetRectLogic',hEle,pRect,bRedraw);
end

function XEle_GetRect(hEle,pRect)
return XC_API_CALL('XEle_GetRect',hEle,pRect);
end

function XEle_GetRectLogic(hEle,pRect)
return XC_API_CALL('XEle_GetRectLogic',hEle,pRect);
end

function XEle_GetClientRect(hEle,pRect)
return XC_API_CALL('XEle_GetClientRect',hEle,pRect);
end

function XEle_GetWndClientRect(hEle,pRect)
return XC_API_CALL('XEle_GetWndClientRect',hEle,pRect);
end

function XEle_GetWidth(hEle)
return XC_API_CALL('XEle_GetWidth',hEle);
end

function XEle_GetHeight(hEle)
return XC_API_CALL('XEle_GetHeight',hEle);
end

function XEle_RectWndClientToEleClient(hEle,pRect)
return XC_API_CALL('XEle_RectWndClientToEleClient',hEle,pRect);
end

function XEle_PointWndClientToEleClient(hEle,pPt)
return XC_API_CALL('XEle_PointWndClientToEleClient',hEle,pPt);
end

function XEle_RectClientToWndClient(hEle,pRect)
return XC_API_CALL('XEle_RectClientToWndClient',hEle,pRect);
end

function XEle_PointClientToWndClient(hEle,pPt)
return XC_API_CALL('XEle_PointClientToWndClient',hEle,pPt);
end

function XEle_AddEle(hEle,hChildEle)
return XC_API_CALL('XEle_AddEle',hEle,hChildEle);
end

function XEle_InsertEle(hEle,hChildEle,index)
return XC_API_CALL('XEle_InsertEle',hEle,hChildEle,index);
end

function XEle_RemoveEle(hEle)
return XC_API_CALL('XEle_RemoveEle',hEle);
end

function XEle_AddShape(hEle,hShape)
return XC_API_CALL('XEle_AddShape',hEle,hShape);
end

function XEle_SetZOrder(hEle,index)
return XC_API_CALL('XEle_SetZOrder',hEle,index);
end

function XEle_SetZOrderEx(hEle,hDestEle,nType)
return XC_API_CALL('XEle_SetZOrderEx',hEle,hDestEle,nType);
end

function XEle_GetZOrder(hEle)
return XC_API_CALL('XEle_GetZOrder',hEle);
end

function XEle_SetTopmost(hEle,bTopmost)
return XC_API_CALL('XEle_SetTopmost',hEle,bTopmost);
end

function XEle_ShowEle(hEle,bShow)
return XC_API_CALL('XEle_ShowEle',hEle,bShow);
end

function XEle_GetType(hEle)
return XC_API_CALL('XEle_GetType',hEle);
end

function XEle_GetHWND(hEle)
return XC_API_CALL('XEle_GetHWND',hEle);
end

function XEle_GetHWINDOW(hEle)
return XC_API_CALL('XEle_GetHWINDOW',hEle);
end

function XEle_SetCursor(hEle,hCursor)
return XC_API_CALL('XEle_SetCursor',hEle,hCursor);
end

function XEle_GetCursor(hEle)
return XC_API_CALL('XEle_GetCursor',hEle);
end

function XEle_SetID(hEle,id)
return XC_API_CALL('XEle_SetID',hEle,id);
end

function XEle_GetID(hEle)
return XC_API_CALL('XEle_GetID',hEle);
end

function XEle_GetParentEle(hEle)
return XC_API_CALL('XEle_GetParentEle',hEle);
end

function XEle_GetParent(hEle)
return XC_API_CALL('XEle_GetParent',hEle);
end

function XEle_SetTextColor(hEle,color,alpha)
return XC_API_CALL('XEle_SetTextColor',hEle,color,alpha);
end

function XEle_GetTextColor(hEle)
return XC_API_CALL('XEle_GetTextColor',hEle);
end

function XEle_SetFocusBorderColor(hEle,color,alpha)
return XC_API_CALL('XEle_SetFocusBorderColor',hEle,color,alpha);
end

function XEle_GetFocusBorderColor(hEle)
return XC_API_CALL('XEle_GetFocusBorderColor',hEle);
end

function XEle_SetFont(hEle,hFontx)
return XC_API_CALL('XEle_SetFont',hEle,hFontx);
end

function XEle_GetFont(hEle)
return XC_API_CALL('XEle_GetFont',hEle);
end

function XEle_SetAlpha(hEle,alpha)
return XC_API_CALL('XEle_SetAlpha',hEle,alpha);
end

function XEle_GetChildCount(hEle)
return XC_API_CALL('XEle_GetChildCount',hEle);
end

function XEle_GetChildByIndex(hEle,index)
return XC_API_CALL('XEle_GetChildByIndex',hEle,index);
end

function XEle_GetChildByID(hEle,id)
return XC_API_CALL('XEle_GetChildByID',hEle,id);
end

function XEle_GetChildShapeCount(hEle)
return XC_API_CALL('XEle_GetChildShapeCount',hEle);
end

function XEle_GetChildShapeByIndex(hEle,index)
return XC_API_CALL('XEle_GetChildShapeByIndex',hEle,index);
end

function XEle_HitChildEle(hEle,pPt)
return XC_API_CALL('XEle_HitChildEle',hEle,pPt);
end

function XEle_BindLayoutObject(hEle,hLayout)
return XC_API_CALL('XEle_BindLayoutObject',hEle,hLayout);
end

function XEle_GetLayoutObject(hEle)
return XC_API_CALL('XEle_GetLayoutObject',hEle);
end

function XEle_GetParentLayoutObject(hEle)
return XC_API_CALL('XEle_GetParentLayoutObject',hEle);
end

function XEle_SetUserData(hEle,nData)
return XC_API_CALL('XEle_SetUserData',hEle,nData);
end

function XEle_GetUserData(hEle)
return XC_API_CALL('XEle_GetUserData',hEle);
end

function XEle_GetContentSize(hEle,pSize)
return XC_API_CALL('XEle_GetContentSize',hEle,pSize);
end

function XEle_SetCapture(hEle,b)
return XC_API_CALL('XEle_SetCapture',hEle,b);
end

function XEle_SetLayoutWidth(hEle,nType,nWidth)
return XC_API_CALL('XEle_SetLayoutWidth',hEle,nType,nWidth);
end

function XEle_SetLayoutHeight(hEle,nType,nHeight)
return XC_API_CALL('XEle_SetLayoutHeight',hEle,nType,nHeight);
end

function XEle_GetLayoutWidth(hEle,pType,pWidth)
return XC_API_CALL('XEle_GetLayoutWidth',hEle,pType,pWidth);
end

function XEle_GetLayoutHeight(hEle,pType,pHeight)
return XC_API_CALL('XEle_GetLayoutHeight',hEle,pType,pHeight);
end

function XEle_RedrawEle(hEle,bImmediate)
return XC_API_CALL('XEle_RedrawEle',hEle,bImmediate);
end

function XEle_RedrawRect(hEle,pRect,bImmediate)
return XC_API_CALL('XEle_RedrawRect',hEle,pRect,bImmediate);
end

function XEle_Destroy(hEle)
return XC_API_CALL('XEle_Destroy',hEle);
end

function XEle_AddBkBorder(hEle,color,alpha,width)
return XC_API_CALL('XEle_AddBkBorder',hEle,color,alpha,width);
end

function XEle_AddBkFill(hEle,color,alpha)
return XC_API_CALL('XEle_AddBkFill',hEle,color,alpha);
end

function XEle_AddBkImage(hEle,hImage)
return XC_API_CALL('XEle_AddBkImage',hEle,hImage);
end

function XEle_GetBkInfoCount(hEle)
return XC_API_CALL('XEle_GetBkInfoCount',hEle);
end

function XEle_ClearBkInfo(hEle)
return XC_API_CALL('XEle_ClearBkInfo',hEle);
end

function XEle_GetBkInfoManager(hEle)
return XC_API_CALL('XEle_GetBkInfoManager',hEle);
end

function XEle_GetStateFlags(hEle)
return XC_API_CALL('XEle_GetStateFlags',hEle);
end

function XEle_DrawFocus(hEle,hDraw,pRect)
return XC_API_CALL('XEle_DrawFocus',hEle,hDraw,pRect);
end

function XEle_EnableTransparentChannel(hEle,bEnable)
return XC_API_CALL('XEle_EnableTransparentChannel',hEle,bEnable);
end

function XEle_SetXCTimer(hEle,nIDEvent,uElapse)
return XC_API_CALL('XEle_SetXCTimer',hEle,nIDEvent,uElapse);
end

function XEle_KillXCTimer(hEle,nIDEvent)
return XC_API_CALL('XEle_KillXCTimer',hEle,nIDEvent);
end

function XEle_SetToolTip(hEle,pText)
return XC_API_CALL('XEle_SetToolTip',hEle,pText);
end

function XEle_GetToolTip(hEle,pOut,nOutLen)
return XC_API_CALL('XEle_GetToolTip',hEle,pOut,nOutLen);
end

function XEle_EnableToolTip(hEle,bEnable)
return XC_API_CALL('XEle_EnableToolTip',hEle,bEnable);
end

function XEle_AdjustLayoutObject(hEle)
return XC_API_CALL('XEle_AdjustLayoutObject',hEle);
end

function XEle_AdjustLayout(hEle)
return XC_API_CALL('XEle_AdjustLayout',hEle);
end

function XEle_RegEventTest(nEvent,pParamType)
return XC_API_CALL('XEle_RegEventTest',nEvent,pParamType);
end

function XFont_Create(size)
return XC_API_CALL('XFont_Create',size);
end

function XFont_Create2(pName,size,style)
return XC_API_CALL('XFont_Create2',pName,size,style);
end

function XFont_Create3(pInfo)
return XC_API_CALL('XFont_Create3',pInfo);
end

function XFont_CreateEx(pFontInfo)
return XC_API_CALL('XFont_CreateEx',pFontInfo);
end

function XFont_CreateFromHFONT(hFont)
return XC_API_CALL('XFont_CreateFromHFONT',hFont);
end

function XFont_CreateFromFont(pFont)
return XC_API_CALL('XFont_CreateFromFont',pFont);
end

function XFont_CreateFromFile(pFontFile,size,style)
return XC_API_CALL('XFont_CreateFromFile',pFontFile,size,style);
end

function XFont_EnableAutoDestroy(hFontX,bEnable)
return XC_API_CALL('XFont_EnableAutoDestroy',hFontX,bEnable);
end

function XFont_GetFont(hFontX)
return XC_API_CALL('XFont_GetFont',hFontX);
end

function XFont_GetFontInfo(hFontX,pInfo)
return XC_API_CALL('XFont_GetFontInfo',hFontX,pInfo);
end

function XFont_AddRef(hFontX)
return XC_API_CALL('XFont_AddRef',hFontX);
end

function XFont_Release(hFontX)
return XC_API_CALL('XFont_Release',hFontX);
end

function XFont_GetRefCount(hFontX)
return XC_API_CALL('XFont_GetRefCount',hFontX);
end

function XFont_Destroy(hFontX)
return XC_API_CALL('XFont_Destroy',hFontX);
end

function XFrameWnd_Create(x,y,cx,cy,pTitle,hWndParent,XCStyle)
return XC_API_CALL('XFrameWnd_Create',x,y,cx,cy,pTitle,hWndParent,XCStyle);
end

function XFrameWnd_CreateEx(dwExStyle,lpClassName,lpWindowName,dwStyle,x,y,cx,cy,hWndParent,XCStyle)
return XC_API_CALL('XFrameWnd_CreateEx',dwExStyle,lpClassName,lpWindowName,dwStyle,x,y,cx,cy,hWndParent,XCStyle);
end

function XFrameWnd_GetLayoutAreaRect(hWindow,pRect)
return XC_API_CALL('XFrameWnd_GetLayoutAreaRect',hWindow,pRect);
end

function XFrameWnd_SetView(hWindow,hEle)
return XC_API_CALL('XFrameWnd_SetView',hWindow,hEle);
end

function XFrameWnd_SetPaneSplitBarColor(hWindow,color,alpha)
return XC_API_CALL('XFrameWnd_SetPaneSplitBarColor',hWindow,color,alpha);
end

function XFrameWnd_SaveLayoutToFile(hWindow,pFileName)
return XC_API_CALL('XFrameWnd_SaveLayoutToFile',hWindow,pFileName);
end

function XFrameWnd_LoadLayoutFile(hWindow,aPaneList,nEleCount,pFileName)
return XC_API_CALL('XFrameWnd_LoadLayoutFile',hWindow,aPaneList,nEleCount,pFileName);
end

function XFrameWnd_AddPane(hWindow,hPaneDest,hPaneNew,align)
return XC_API_CALL('XFrameWnd_AddPane',hWindow,hPaneDest,hPaneNew,align);
end

function XFrameWnd_MergePane(hWindow,hPaneDest,hPaneNew)
return XC_API_CALL('XFrameWnd_MergePane',hWindow,hPaneDest,hPaneNew);
end

function XImage_LoadFile(pImageName,bStretch)
return XC_API_CALL('XImage_LoadFile',pImageName,bStretch);
end

function XImage_LoadFileAdaptive(pImageName,leftSize,topSize,rightSize,bottomSize)
return XC_API_CALL('XImage_LoadFileAdaptive',pImageName,leftSize,topSize,rightSize,bottomSize);
end

function XImage_LoadFileRect(pImageName,x,y,cx,cy)
return XC_API_CALL('XImage_LoadFileRect',pImageName,x,y,cx,cy);
end

function XImage_LoadResAdaptive(id,pType,leftSize,topSize,rightSize,bottomSize)
return XC_API_CALL('XImage_LoadResAdaptive',id,pType,leftSize,topSize,rightSize,bottomSize);
end

function XImage_LoadRes(id,pType,bStretch)
return XC_API_CALL('XImage_LoadRes',id,pType,bStretch);
end

function XImage_LoadZip(pZipFileName,pImageName,pPassword,bStretch)
return XC_API_CALL('XImage_LoadZip',pZipFileName,pImageName,pPassword,bStretch);
end

function XImage_LoadZipAdaptive(pZipFileName,pImageName,pPassword,x1,x2,y1,y2)
return XC_API_CALL('XImage_LoadZipAdaptive',pZipFileName,pImageName,pPassword,x1,x2,y1,y2);
end

function XImage_LoadZipRect(pZipFileName,pImageName,pPassword,x,y,cx,cy)
return XC_API_CALL('XImage_LoadZipRect',pZipFileName,pImageName,pPassword,x,y,cx,cy);
end

function XImage_LoadMemory(pBuffer,nSize,bStretch)
return XC_API_CALL('XImage_LoadMemory',pBuffer,nSize,bStretch);
end

function XImage_LoadMemoryRect(pBuffer,nSize,x,y,cx,cy,bStretch)
return XC_API_CALL('XImage_LoadMemoryRect',pBuffer,nSize,x,y,cx,cy,bStretch);
end

function XImage_LoadMemoryAdaptive(pBuffer,nSize,leftSize,topSize,rightSize,bottomSize)
return XC_API_CALL('XImage_LoadMemoryAdaptive',pBuffer,nSize,leftSize,topSize,rightSize,bottomSize);
end

function XImage_LoadFromImage(pImage)
return XC_API_CALL('XImage_LoadFromImage',pImage);
end

function XImage_LoadFileFromExtractIcon(pImageName)
return XC_API_CALL('XImage_LoadFileFromExtractIcon',pImageName);
end

function XImage_LoadFileFromHICON(hIcon)
return XC_API_CALL('XImage_LoadFileFromHICON',hIcon);
end

function XImage_LoadFileFromHBITMAP(hBitmap)
return XC_API_CALL('XImage_LoadFileFromHBITMAP',hBitmap);
end

function XImage_IsStretch(hImage)
return XC_API_CALL('XImage_IsStretch',hImage);
end

function XImage_IsAdaptive(hImage)
return XC_API_CALL('XImage_IsAdaptive',hImage);
end

function XImage_IsTile(hImage)
return XC_API_CALL('XImage_IsTile',hImage);
end

function XImage_SetDrawType(hImage,nType)
return XC_API_CALL('XImage_SetDrawType',hImage,nType);
end

function XImage_SetDrawTypeAdaptive(hImage,leftSize,topSize,rightSize,bottomSize)
return XC_API_CALL('XImage_SetDrawTypeAdaptive',hImage,leftSize,topSize,rightSize,bottomSize);
end

function XImage_SetTranColor(hImage,color)
return XC_API_CALL('XImage_SetTranColor',hImage,color);
end

function XImage_SetTranColorEx(hImage,color,tranColor)
return XC_API_CALL('XImage_SetTranColorEx',hImage,color,tranColor);
end

function XImage_SetRotateAngle(hImage,fAngle)
return XC_API_CALL('XImage_SetRotateAngle',hImage,fAngle);
end

function XImage_EnableTranColor(hImage,bEnable)
return XC_API_CALL('XImage_EnableTranColor',hImage,bEnable);
end

function XImage_EnableAutoDestroy(hImage,bEnable)
return XC_API_CALL('XImage_EnableAutoDestroy',hImage,bEnable);
end

function XImage_EnableCenter(hImage,bCenter)
return XC_API_CALL('XImage_EnableCenter',hImage,bCenter);
end

function XImage_IsCenter(hImage)
return XC_API_CALL('XImage_IsCenter',hImage);
end

function XImage_GetDrawType(hImage)
return XC_API_CALL('XImage_GetDrawType',hImage);
end

function XImage_GetWidth(hImage)
return XC_API_CALL('XImage_GetWidth',hImage);
end

function XImage_GetHeight(hImage)
return XC_API_CALL('XImage_GetHeight',hImage);
end

function XImage_AddRef(hImage)
return XC_API_CALL('XImage_AddRef',hImage);
end

function XImage_Release(hImage)
return XC_API_CALL('XImage_Release',hImage);
end

function XImage_GetRefCount(hImage)
return XC_API_CALL('XImage_GetRefCount',hImage);
end

function XImage_Destroy(hImage)
return XC_API_CALL('XImage_Destroy',hImage);
end

function XLayout_Create()
return XC_API_CALL('XLayout_Create');
end

function XLayout_Destroy(hLayout)
return XC_API_CALL('XLayout_Destroy',hLayout);
end

function XLayout_AddEle(hLayout,hEle)
return XC_API_CALL('XLayout_AddEle',hLayout,hEle);
end

function XLayout_AddLayoutObject(hLayout,hLayoutObject)
return XC_API_CALL('XLayout_AddLayoutObject',hLayout,hLayoutObject);
end

function XLayout_AddShape(hLayout,hShape)
return XC_API_CALL('XLayout_AddShape',hLayout,hShape);
end

function XLayout_Add(hLayout,hChild)
return XC_API_CALL('XLayout_Add',hLayout,hChild);
end

function XLayout_Insert(hLayout,hChild,index)
return XC_API_CALL('XLayout_Insert',hLayout,hChild,index);
end

function XLayout_RemoveLayout(hLayout)
return XC_API_CALL('XLayout_RemoveLayout',hLayout);
end

function XLayout_RemoveChild(hLayout,hChild)
return XC_API_CALL('XLayout_RemoveChild',hLayout,hChild);
end

function XLayout_GetZOrder(hLayout,hChild)
return XC_API_CALL('XLayout_GetZOrder',hLayout,hChild);
end

function XLayout_AdjustLayout(hLayout)
return XC_API_CALL('XLayout_AdjustLayout',hLayout);
end

function XLayout_SetRectFrame(hLayout,pRect)
return XC_API_CALL('XLayout_SetRectFrame',hLayout,pRect);
end

function XLayout_GetRect(hLayout,pRect)
return XC_API_CALL('XLayout_GetRect',hLayout,pRect);
end

function XLayout_GetRectFrame(hLayout,pRect)
return XC_API_CALL('XLayout_GetRectFrame',hLayout,pRect);
end

function XLayout_GetWindow(hLayout)
return XC_API_CALL('XLayout_GetWindow',hLayout);
end

function XLayout_GetEle(hLayout)
return XC_API_CALL('XLayout_GetEle',hLayout);
end

function XLayout_GetParentLayout(hLayout)
return XC_API_CALL('XLayout_GetParentLayout',hLayout);
end

function XLayout_GetParent(hLayout)
return XC_API_CALL('XLayout_GetParent',hLayout);
end

function XLayout_SetID(hLayout,nID)
return XC_API_CALL('XLayout_SetID',hLayout,nID);
end

function XLayout_GetID(hLayout)
return XC_API_CALL('XLayout_GetID',hLayout);
end

function XLayout_SetHorizon(hLayout,bHorizon)
return XC_API_CALL('XLayout_SetHorizon',hLayout,bHorizon);
end

function XLayout_SetAlignH(hLayout,nAlign)
return XC_API_CALL('XLayout_SetAlignH',hLayout,nAlign);
end

function XLayout_SetAlignV(hLayout,nAlign)
return XC_API_CALL('XLayout_SetAlignV',hLayout,nAlign);
end

function XLayout_SetPadding(hLayout,left,top,right,bottom)
return XC_API_CALL('XLayout_SetPadding',hLayout,left,top,right,bottom);
end

function XLayout_SetSpace(hLayout,nSpace)
return XC_API_CALL('XLayout_SetSpace',hLayout,nSpace);
end

function XLayout_SetLayoutWidth(hLayout,nType,nWidth)
return XC_API_CALL('XLayout_SetLayoutWidth',hLayout,nType,nWidth);
end

function XLayout_SetLayoutHeight(hLayout,nType,nHeight)
return XC_API_CALL('XLayout_SetLayoutHeight',hLayout,nType,nHeight);
end

function XLayout_GetLayoutWidth(hLayout,pType,pWidth)
return XC_API_CALL('XLayout_GetLayoutWidth',hLayout,pType,pWidth);
end

function XLayout_GetLayoutHeight(hLayout,pType,pHeight)
return XC_API_CALL('XLayout_GetLayoutHeight',hLayout,pType,pHeight);
end

function XLayout_GetWidth(hLayout)
return XC_API_CALL('XLayout_GetWidth',hLayout);
end

function XLayout_GetHeight(hLayout)
return XC_API_CALL('XLayout_GetHeight',hLayout);
end

function XLayout_GetWidthIn(hLayout)
return XC_API_CALL('XLayout_GetWidthIn',hLayout);
end

function XLayout_GetHeightIn(hLayout)
return XC_API_CALL('XLayout_GetHeightIn',hLayout);
end

function XLayout_GetContentSize(hLayout,pSize)
return XC_API_CALL('XLayout_GetContentSize',hLayout,pSize);
end

function XLayout_ShowLayout(hLayout,bShow)
return XC_API_CALL('XLayout_ShowLayout',hLayout,bShow);
end

function XLayout_GetChildCount(hLayout)
return XC_API_CALL('XLayout_GetChildCount',hLayout);
end

function XLayout_GetChildType(hLayout,index)
return XC_API_CALL('XLayout_GetChildType',hLayout,index);
end

function XLayout_GetChild(hLayout,index)
return XC_API_CALL('XLayout_GetChild',hLayout,index);
end

function XLayout_Draw(hLayout,hDraw)
return XC_API_CALL('XLayout_Draw',hLayout,hDraw);
end

function Layout_SetEle(hLayout,hParent)
return XC_API_CALL('Layout_SetEle',hLayout,hParent);
end

function XListBox_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XListBox_Create',x,y,cx,cy,hParent);
end

function XListBox_SetDrawItemBkFlags(hEle,nFlags)
return XC_API_CALL('XListBox_SetDrawItemBkFlags',hEle,nFlags);
end

function XListBox_SetItemData(hEle,iItem,nUserData)
return XC_API_CALL('XListBox_SetItemData',hEle,iItem,nUserData);
end

function XListBox_GetItemData(hEle,iItem)
return XC_API_CALL('XListBox_GetItemData',hEle,iItem);
end

function XListBox_SetItemInfo(hEle,iItem,pItem)
return XC_API_CALL('XListBox_SetItemInfo',hEle,iItem,pItem);
end

function XListBox_GetItemInfo(hEle,iItem,pItem)
return XC_API_CALL('XListBox_GetItemInfo',hEle,iItem,pItem);
end

function XListBox_AddItemBkBorder(hEle,nState,color,alpha,width)
return XC_API_CALL('XListBox_AddItemBkBorder',hEle,nState,color,alpha,width);
end

function XListBox_AddItemBkFill(hEle,nState,color,alpha)
return XC_API_CALL('XListBox_AddItemBkFill',hEle,nState,color,alpha);
end

function XListBox_AddItemBkImage(hEle,nState,hImage)
return XC_API_CALL('XListBox_AddItemBkImage',hEle,nState,hImage);
end

function XListBox_GetItemBkInfoCount(hEle)
return XC_API_CALL('XListBox_GetItemBkInfoCount',hEle);
end

function XListBox_ClearItemBkInfo(hEle)
return XC_API_CALL('XListBox_ClearItemBkInfo',hEle);
end

function XListBox_SetSelectItem(hEle,iItem)
return XC_API_CALL('XListBox_SetSelectItem',hEle,iItem);
end

function XListBox_GetSelectItem(hEle)
return XC_API_CALL('XListBox_GetSelectItem',hEle);
end

function XListBox_CancelSelectItem(hEle,iItem)
return XC_API_CALL('XListBox_CancelSelectItem',hEle,iItem);
end

function XListBox_CancelSelectAll(hEle)
return XC_API_CALL('XListBox_CancelSelectAll',hEle);
end

function XListBox_GetSelectAll(hEle,pArray,nArraySize)
return XC_API_CALL('XListBox_GetSelectAll',hEle,pArray,nArraySize);
end

function XListBox_GetSelectCount(hEle)
return XC_API_CALL('XListBox_GetSelectCount',hEle);
end

function XListBox_GetItemMouseStay(hEle)
return XC_API_CALL('XListBox_GetItemMouseStay',hEle);
end

function XListBox_SelectAll(hEle)
return XC_API_CALL('XListBox_SelectAll',hEle);
end

function XListBox_SetItemHeightDefault(hEle,nHeight,nSelHeight)
return XC_API_CALL('XListBox_SetItemHeightDefault',hEle,nHeight,nSelHeight);
end

function XListBox_GetItemHeightDefault(hEle,pHeight,pSelHeight)
return XC_API_CALL('XListBox_GetItemHeightDefault',hEle,pHeight,pSelHeight);
end

function XListBox_GetItemIndexFromHXCGUI(hEle,hXCGUI)
return XC_API_CALL('XListBox_GetItemIndexFromHXCGUI',hEle,hXCGUI);
end

function XListBox_SetRowSpace(hEle,nSpace)
return XC_API_CALL('XListBox_SetRowSpace',hEle,nSpace);
end

function XListBox_GetRowSpace(hEle)
return XC_API_CALL('XListBox_GetRowSpace',hEle);
end

function XListBox_HitTest(hEle,pPt)
return XC_API_CALL('XListBox_HitTest',hEle,pPt);
end

function XListBox_HitTestOffset(hEle,pPt)
return XC_API_CALL('XListBox_HitTestOffset',hEle,pPt);
end

function XListBox_SetItemTemplateXML(hEle,pXmlFile)
return XC_API_CALL('XListBox_SetItemTemplateXML',hEle,pXmlFile);
end

function XListBox_SetItemTemplateXMLFromString(hEle,pStringXML)
return XC_API_CALL('XListBox_SetItemTemplateXMLFromString',hEle,pStringXML);
end

function XListBox_GetTemplateObject(hEle,iItem,nTempItemID)
return XC_API_CALL('XListBox_GetTemplateObject',hEle,iItem,nTempItemID);
end

function XListBox_EnableMultiSel(hEle,bEnable)
return XC_API_CALL('XListBox_EnableMultiSel',hEle,bEnable);
end

function XListBox_BindAdapter(hEle,hAdapter)
return XC_API_CALL('XListBox_BindAdapter',hEle,hAdapter);
end

function XListBox_GetAdapter(hEle)
return XC_API_CALL('XListBox_GetAdapter',hEle);
end

function XListBox_Sort(hEle,iColumnAdapter,bAscending)
return XC_API_CALL('XListBox_Sort',hEle,iColumnAdapter,bAscending);
end

function XListBox_RefreshData(hEle)
return XC_API_CALL('XListBox_RefreshData',hEle);
end

function XList_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XList_Create',x,y,cx,cy,hParent);
end

function XList_AddColumn(hEle,width)
return XC_API_CALL('XList_AddColumn',hEle,width);
end

function XList_InsertColumn(hEle,width,iItem)
return XC_API_CALL('XList_InsertColumn',hEle,width,iItem);
end

function XList_EnableMultiSel(hEle,bEnable)
return XC_API_CALL('XList_EnableMultiSel',hEle,bEnable);
end

function XList_EnableDragChangeColumnWidth(hEle,bEnable)
return XC_API_CALL('XList_EnableDragChangeColumnWidth',hEle,bEnable);
end

function XList_EnableVScrollBarTop(hEle,bTop)
return XC_API_CALL('XList_EnableVScrollBarTop',hEle,bTop);
end

function XList_EnableItemBkFullRow(hEle,bFull)
return XC_API_CALL('XList_EnableItemBkFullRow',hEle,bFull);
end

function XList_SetSort(hEle,iColumn,iColumnAdapter,bEnable)
return XC_API_CALL('XList_SetSort',hEle,iColumn,iColumnAdapter,bEnable);
end

function XList_SetDrawItemBkFlags(hEle,style)
return XC_API_CALL('XList_SetDrawItemBkFlags',hEle,style);
end

function XList_SetColumnWidth(hEle,iItem,width)
return XC_API_CALL('XList_SetColumnWidth',hEle,iItem,width);
end

function XList_SetColumnMinWidth(hEle,iItem,width)
return XC_API_CALL('XList_SetColumnMinWidth',hEle,iItem,width);
end

function XList_SetColumnWidthFixed(hEle,iColumn,bFixed)
return XC_API_CALL('XList_SetColumnWidthFixed',hEle,iColumn,bFixed);
end

function XList_GetColumnWidth(hEle,iColumn)
return XC_API_CALL('XList_GetColumnWidth',hEle,iColumn);
end

function XList_GetColumnCount(hEle)
return XC_API_CALL('XList_GetColumnCount',hEle);
end

function XList_DeleteColumn(hEle,iItem)
return XC_API_CALL('XList_DeleteColumn',hEle,iItem);
end

function XList_DeleteColumnAll(hEle)
return XC_API_CALL('XList_DeleteColumnAll',hEle);
end

function XList_SetItemData(hEle,iItem,iSubItem,data)
return XC_API_CALL('XList_SetItemData',hEle,iItem,iSubItem,data);
end

function XList_GetItemData(hEle,iItem,iSubItem)
return XC_API_CALL('XList_GetItemData',hEle,iItem,iSubItem);
end

function XList_SetSelectItem(hEle,iItem,bSelect)
return XC_API_CALL('XList_SetSelectItem',hEle,iItem,bSelect);
end

function XList_GetSelectItem(hEle)
return XC_API_CALL('XList_GetSelectItem',hEle);
end

function XList_GetSelectItemCount(hEle)
return XC_API_CALL('XList_GetSelectItemCount',hEle);
end

function XList_SetSelectAll(hEle)
return XC_API_CALL('XList_SetSelectAll',hEle);
end

function XList_GetSelectAll(hEle,pArray,nArraySize)
return XC_API_CALL('XList_GetSelectAll',hEle,pArray,nArraySize);
end

function XList_CancelSelectItem(hEle,iItem)
return XC_API_CALL('XList_CancelSelectItem',hEle,iItem);
end

function XList_CancelSelectAll(hEle)
return XC_API_CALL('XList_CancelSelectAll',hEle);
end

function XList_GetHeaderHELE(hEle)
return XC_API_CALL('XList_GetHeaderHELE',hEle);
end

function XList_BindAdapter(hEle,hAdapter)
return XC_API_CALL('XList_BindAdapter',hEle,hAdapter);
end

function XList_BindAdapterHeader(hEle,hAdapter)
return XC_API_CALL('XList_BindAdapterHeader',hEle,hAdapter);
end

function XList_GetAdapter(hEle)
return XC_API_CALL('XList_GetAdapter',hEle);
end

function XList_SetItemTemplateXML(hEle,pXmlFile)
return XC_API_CALL('XList_SetItemTemplateXML',hEle,pXmlFile);
end

function XList_SetItemTemplateXMLFromString(hEle,pStringXML)
return XC_API_CALL('XList_SetItemTemplateXMLFromString',hEle,pStringXML);
end

function XList_GetTemplateObject(hEle,iItem,nTempItemID)
return XC_API_CALL('XList_GetTemplateObject',hEle,iItem,nTempItemID);
end

function XList_GetItemIndexFromHXCGUI(hEle,hXCGUI)
return XC_API_CALL('XList_GetItemIndexFromHXCGUI',hEle,hXCGUI);
end

function XList_GetHeaderTemplateObject(hEle,iItem,nTempItemID)
return XC_API_CALL('XList_GetHeaderTemplateObject',hEle,iItem,nTempItemID);
end

function XList_GetHeaderItemIndexFromHXCGUI(hEle,hXCGUI)
return XC_API_CALL('XList_GetHeaderItemIndexFromHXCGUI',hEle,hXCGUI);
end

function XList_SetHeaderHeight(hEle,height)
return XC_API_CALL('XList_SetHeaderHeight',hEle,height);
end

function XList_GetHeaderHeight(hEle)
return XC_API_CALL('XList_GetHeaderHeight',hEle);
end

function XList_AddItemBkBorder(hEle,nState,color,alpha,width)
return XC_API_CALL('XList_AddItemBkBorder',hEle,nState,color,alpha,width);
end

function XList_AddItemBkFill(hEle,nState,color,alpha)
return XC_API_CALL('XList_AddItemBkFill',hEle,nState,color,alpha);
end

function XList_AddItemBkImage(hEle,nState,hImage)
return XC_API_CALL('XList_AddItemBkImage',hEle,nState,hImage);
end

function XList_GetItemBkInfoCount(hEle)
return XC_API_CALL('XList_GetItemBkInfoCount',hEle);
end

function XList_ClearItemBkInfo(hEle)
return XC_API_CALL('XList_ClearItemBkInfo',hEle);
end

function XList_SetItemHeightDefault(hEle,nHeight,nSelHeight)
return XC_API_CALL('XList_SetItemHeightDefault',hEle,nHeight,nSelHeight);
end

function XList_GetItemHeightDefault(hEle,pHeight,pSelHeight)
return XC_API_CALL('XList_GetItemHeightDefault',hEle,pHeight,pSelHeight);
end

function XList_SetRowSpace(hEle,nSpace)
return XC_API_CALL('XList_SetRowSpace',hEle,nSpace);
end

function XList_GetRowSpace(hEle)
return XC_API_CALL('XList_GetRowSpace',hEle);
end

function XList_HitTest(hEle,pPt,piItem,piSubItem)
return XC_API_CALL('XList_HitTest',hEle,pPt,piItem,piSubItem);
end

function XList_HitTestOffset(hEle,pPt,piItem,piSubItem)
return XC_API_CALL('XList_HitTestOffset',hEle,pPt,piItem,piSubItem);
end

function XList_RefreshData(hEle)
return XC_API_CALL('XList_RefreshData',hEle);
end

function XListView_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XListView_Create',x,y,cx,cy,hParent);
end

function XListView_BindAdapter(hEle,hAdapter)
return XC_API_CALL('XListView_BindAdapter',hEle,hAdapter);
end

function XListView_GetAdapter(hEle)
return XC_API_CALL('XListView_GetAdapter',hEle);
end

function XListView_SetItemTemplateXML(hEle,pXmlFile)
return XC_API_CALL('XListView_SetItemTemplateXML',hEle,pXmlFile);
end

function XListView_SetItemTemplateXMLFromString(hEle,pStringXML)
return XC_API_CALL('XListView_SetItemTemplateXMLFromString',hEle,pStringXML);
end

function XListView_GetTemplateObject(hEle,iGroup,iItem,nTempItemID)
return XC_API_CALL('XListView_GetTemplateObject',hEle,iGroup,iItem,nTempItemID);
end

function XListView_GetTemplateObjectGroup(hEle,iGroup,nTempItemID)
return XC_API_CALL('XListView_GetTemplateObjectGroup',hEle,iGroup,nTempItemID);
end

function XListView_GetItemIDFromHXCGUI(hEle,hXCGUI,piGroup,piItem)
return XC_API_CALL('XListView_GetItemIDFromHXCGUI',hEle,hXCGUI,piGroup,piItem);
end

function XListView_HitTest(hEle,pPt,pOutGroup,pOutItem)
return XC_API_CALL('XListView_HitTest',hEle,pPt,pOutGroup,pOutItem);
end

function XListView_HitTestOffset(hEle,pPt,pOutGroup,pOutItem)
return XC_API_CALL('XListView_HitTestOffset',hEle,pPt,pOutGroup,pOutItem);
end

function XListView_EnableMultiSel(hEle,bEnable)
return XC_API_CALL('XListView_EnableMultiSel',hEle,bEnable);
end

function XListView_SetDrawItemBkFlags(hEle,nFlags)
return XC_API_CALL('XListView_SetDrawItemBkFlags',hEle,nFlags);
end

function XListView_SetSelectItem(hEle,iGroup,iItem)
return XC_API_CALL('XListView_SetSelectItem',hEle,iGroup,iItem);
end

function XListView_GetSelectItem(hEle,piGroup,piItem)
return XC_API_CALL('XListView_GetSelectItem',hEle,piGroup,piItem);
end

function XListView_GetSelectItemCount(hEle)
return XC_API_CALL('XListView_GetSelectItemCount',hEle);
end

function XListView_GetSelectItemAll(hEle,pArray,nArraySize)
return XC_API_CALL('XListView_GetSelectItemAll',hEle,pArray,nArraySize);
end

function XListView_SetSelectItemAll(hEle)
return XC_API_CALL('XListView_SetSelectItemAll',hEle);
end

function XListView_CancelSelectItemAll(hEle)
return XC_API_CALL('XListView_CancelSelectItemAll',hEle);
end

function XListView_SetColumnSpace(hEle,space)
return XC_API_CALL('XListView_SetColumnSpace',hEle,space);
end

function XListView_SetRowSpace(hEle,space)
return XC_API_CALL('XListView_SetRowSpace',hEle,space);
end

function XListView_SetAlignSizeLeft(hEle,size)
return XC_API_CALL('XListView_SetAlignSizeLeft',hEle,size);
end

function XListView_SetAlignSizeTop(hEle,size)
return XC_API_CALL('XListView_SetAlignSizeTop',hEle,size);
end

function XListView_SetItemSize(hEle,width,height)
return XC_API_CALL('XListView_SetItemSize',hEle,width,height);
end

function XListView_GetItemSize(hEle,pSize)
return XC_API_CALL('XListView_GetItemSize',hEle,pSize);
end

function XListView_SetGroupHeight(hEle,height)
return XC_API_CALL('XListView_SetGroupHeight',hEle,height);
end

function XListView_GetGroupHeight(hEle)
return XC_API_CALL('XListView_GetGroupHeight',hEle);
end

function XListView_SetGroupUserData(hEle,iGroup,nData)
return XC_API_CALL('XListView_SetGroupUserData',hEle,iGroup,nData);
end

function XListView_SetItemUserData(hEle,iGroup,iItem,nData)
return XC_API_CALL('XListView_SetItemUserData',hEle,iGroup,iItem,nData);
end

function XListView_GetGroupUserData(hEle,iGroup)
return XC_API_CALL('XListView_GetGroupUserData',hEle,iGroup);
end

function XListView_GetItemUserData(hEle,iGroup,iItem)
return XC_API_CALL('XListView_GetItemUserData',hEle,iGroup,iItem);
end

function XListView_AddItemBkBorder(hEle,nState,color,alpha,width)
return XC_API_CALL('XListView_AddItemBkBorder',hEle,nState,color,alpha,width);
end

function XListView_AddItemBkFill(hEle,nState,color,alpha)
return XC_API_CALL('XListView_AddItemBkFill',hEle,nState,color,alpha);
end

function XListView_AddItemBkImage(hEle,nState,hImage)
return XC_API_CALL('XListView_AddItemBkImage',hEle,nState,hImage);
end

function XListView_GetItemBkInfoCount(hEle)
return XC_API_CALL('XListView_GetItemBkInfoCount',hEle);
end

function XListView_ClearItemBkInfo(hEle)
return XC_API_CALL('XListView_ClearItemBkInfo',hEle);
end

function XListView_RefreshData(hEle)
return XC_API_CALL('XListView_RefreshData',hEle);
end

function XListView_ExpandGroup(hEle,iGroup,bExpand)
return XC_API_CALL('XListView_ExpandGroup',hEle,iGroup,bExpand);
end

function XMenuBar_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XMenuBar_Create',x,y,cx,cy,hParent);
end

function XMenuBar_AddButton(hEle,pText)
return XC_API_CALL('XMenuBar_AddButton',hEle,pText);
end

function XMenuBar_SetButtonHeight(hEle,height)
return XC_API_CALL('XMenuBar_SetButtonHeight',hEle,height);
end

function XMenuBar_GetMenu(hEle,nIndex)
return XC_API_CALL('XMenuBar_GetMenu',hEle,nIndex);
end

function XMenuBar_DeleteButton(hEle,nIndex)
return XC_API_CALL('XMenuBar_DeleteButton',hEle,nIndex);
end

function XMenu_Create()
return XC_API_CALL('XMenu_Create');
end

function XMenu_AddItem(hMenu,nID,pText,parentId,nFlags)
return XC_API_CALL('XMenu_AddItem',hMenu,nID,pText,parentId,nFlags);
end

function XMenu_AddItemIcon(hMenu,nID,pText,nParentID,hImage,nFlags)
return XC_API_CALL('XMenu_AddItemIcon',hMenu,nID,pText,nParentID,hImage,nFlags);
end

function XMenu_InsertItem(hMenu,nID,pText,nFlags,insertID)
return XC_API_CALL('XMenu_InsertItem',hMenu,nID,pText,nFlags,insertID);
end

function XMenu_InsertItemIcon(hMenu,nID,pText,hIcon,nFlags,insertID)
return XC_API_CALL('XMenu_InsertItemIcon',hMenu,nID,pText,hIcon,nFlags,insertID);
end

function XMenu_SetAutoDestroy(hMenu,bAuto)
return XC_API_CALL('XMenu_SetAutoDestroy',hMenu,bAuto);
end

function XMenu_EnableDrawBackground(hMenu,bEnable)
return XC_API_CALL('XMenu_EnableDrawBackground',hMenu,bEnable);
end

function XMenu_EnableDrawItem(hMenu,bEnable)
return XC_API_CALL('XMenu_EnableDrawItem',hMenu,bEnable);
end

function XMenu_Popup(hMenu,hParentWnd,x,y,hParentEle,nPosition)
return XC_API_CALL('XMenu_Popup',hMenu,hParentWnd,x,y,hParentEle,nPosition);
end

function XMenu_DestroyMenu(hMenu)
return XC_API_CALL('XMenu_DestroyMenu',hMenu);
end

function XMenu_CloseMenu(hMenu)
return XC_API_CALL('XMenu_CloseMenu',hMenu);
end

function XMenu_SetBkImage(hMenu,hImage)
return XC_API_CALL('XMenu_SetBkImage',hMenu,hImage);
end

function XMenu_SetItemText(hMenu,nID,pText)
return XC_API_CALL('XMenu_SetItemText',hMenu,nID,pText);
end

function XMenu_GetItemText(hMenu,nID,pOut,nOutLen)
return XC_API_CALL('XMenu_GetItemText',hMenu,nID,pOut,nOutLen);
end

function XMenu_GetItemTextLength(hMenu,nID)
return XC_API_CALL('XMenu_GetItemTextLength',hMenu,nID);
end

function XMenu_SetItemIcon(hMenu,nID,hIcon)
return XC_API_CALL('XMenu_SetItemIcon',hMenu,nID,hIcon);
end

function XMenu_SetItemFlags(hMenu,nID,uFlags)
return XC_API_CALL('XMenu_SetItemFlags',hMenu,nID,uFlags);
end

function XMenu_SetItemHeight(hMenu,height)
return XC_API_CALL('XMenu_SetItemHeight',hMenu,height);
end

function XMenu_GetItemHeight(hMenu)
return XC_API_CALL('XMenu_GetItemHeight',hMenu);
end

function XMenu_SetBorderColor(hMenu,crColor,alpha)
return XC_API_CALL('XMenu_SetBorderColor',hMenu,crColor,alpha);
end

function XMenu_GetLeftWidth(hMenu)
return XC_API_CALL('XMenu_GetLeftWidth',hMenu);
end

function XMenu_GetLeftSpaceText(hMenu)
return XC_API_CALL('XMenu_GetLeftSpaceText',hMenu);
end

function XMenu_GetItemCount(hMenu)
return XC_API_CALL('XMenu_GetItemCount',hMenu);
end

function XMenu_SetItemCheck(hMenu,nID,bCheck)
return XC_API_CALL('XMenu_SetItemCheck',hMenu,nID,bCheck);
end

function XMenu_IsItemCheck(hMenu,nID)
return XC_API_CALL('XMenu_IsItemCheck',hMenu,nID);
end

function XModalWnd_Create(nWidth,nHeight,pTitle,hWndParent,XCStyle)
return XC_API_CALL('XModalWnd_Create',nWidth,nHeight,pTitle,hWndParent,XCStyle);
end

function XModalWnd_CreateEx(dwExStyle,lpClassName,lpWindowName,dwStyle,x,y,cx,cy,hWndParent,XCStyle)
return XC_API_CALL('XModalWnd_CreateEx',dwExStyle,lpClassName,lpWindowName,dwStyle,x,y,cx,cy,hWndParent,XCStyle);
end

function XModalWnd_EnableAutoClose(hWindow,bEnable)
return XC_API_CALL('XModalWnd_EnableAutoClose',hWindow,bEnable);
end

function XModalWnd_DoModal(hWindow)
return XC_API_CALL('XModalWnd_DoModal',hWindow);
end

function XModalWnd_EndModal(hWindow,nResult)
return XC_API_CALL('XModalWnd_EndModal',hWindow,nResult);
end

function XPane_Create(pName,nWidth,nHeight,hFrameWnd)
return XC_API_CALL('XPane_Create',pName,nWidth,nHeight,hFrameWnd);
end

function XPane_SetView(hEle,hView)
return XC_API_CALL('XPane_SetView',hEle,hView);
end

function XPane_IsShowPane(hEle)
return XC_API_CALL('XPane_IsShowPane',hEle);
end

function XPane_SetSize(hEle,nWidth,nHeight)
return XC_API_CALL('XPane_SetSize',hEle,nWidth,nHeight);
end

function XPane_GetState(hEle)
return XC_API_CALL('XPane_GetState',hEle);
end

function XPane_SetTitle(hEle,pTitle)
return XC_API_CALL('XPane_SetTitle',hEle,pTitle);
end

function XPane_GetTitle(hEle,pOut,nOutLen)
return XC_API_CALL('XPane_GetTitle',hEle,pOut,nOutLen);
end

function XPane_SetCaptionHeight(hEle,nHeight)
return XC_API_CALL('XPane_SetCaptionHeight',hEle,nHeight);
end

function XPane_GetCaptionHeight(hEle)
return XC_API_CALL('XPane_GetCaptionHeight',hEle);
end

function XPane_HidePane(hEle)
return XC_API_CALL('XPane_HidePane',hEle);
end

function XPane_ShowPane(hEle)
return XC_API_CALL('XPane_ShowPane',hEle);
end

function XPane_DockPane(hEle)
return XC_API_CALL('XPane_DockPane',hEle);
end

function XPane_LockPane(hEle)
return XC_API_CALL('XPane_LockPane',hEle);
end

function XPane_FloatPane(hEle)
return XC_API_CALL('XPane_FloatPane',hEle);
end

function XFloatWnd_EnableCaptionContent(hWindow,bEnable)
return XC_API_CALL('XFloatWnd_EnableCaptionContent',hWindow,bEnable);
end

function XFloatWnd_GetCaptionLayout(hWindow)
return XC_API_CALL('XFloatWnd_GetCaptionLayout',hWindow);
end

function XFloatWnd_GetCaptionShapeText(hWindow)
return XC_API_CALL('XFloatWnd_GetCaptionShapeText',hWindow);
end

function XFloatWnd_GetCaptionButtonClose(hWindow)
return XC_API_CALL('XFloatWnd_GetCaptionButtonClose',hWindow);
end

function XFloatWnd_SetTitle(hWindow,pTitle)
return XC_API_CALL('XFloatWnd_SetTitle',hWindow,pTitle);
end

function XFloatWnd_GetTitle(hWindow,pOut,nOutLen)
return XC_API_CALL('XFloatWnd_GetTitle',hWindow,pOut,nOutLen);
end

function XProgBar_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XProgBar_Create',x,y,cx,cy,hParent);
end

function XProgBar_SetRange(hEle,range)
return XC_API_CALL('XProgBar_SetRange',hEle,range);
end

function XProgBar_GetRange(hEle)
return XC_API_CALL('XProgBar_GetRange',hEle);
end

function XProgBar_SetSpaceTwo(hEle,leftSize,rightSize)
return XC_API_CALL('XProgBar_SetSpaceTwo',hEle,leftSize,rightSize);
end

function XProgBar_SetPos(hEle,pos)
return XC_API_CALL('XProgBar_SetPos',hEle,pos);
end

function XProgBar_GetPos(hEle)
return XC_API_CALL('XProgBar_GetPos',hEle);
end

function XProgBar_SetHorizon(hEle,bHorizon)
return XC_API_CALL('XProgBar_SetHorizon',hEle,bHorizon);
end

function XProgBar_SetImageLoad(hEle,hImage)
return XC_API_CALL('XProgBar_SetImageLoad',hEle,hImage);
end

function XPGrid_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XPGrid_Create',x,y,cx,cy,hParent);
end

function XPGrid_AddItem(hEle,pName,nType,nParentID)
return XC_API_CALL('XPGrid_AddItem',hEle,pName,nType,nParentID);
end

function XPGrid_AddItemString(hEle,pName,pValue,nParentID)
return XC_API_CALL('XPGrid_AddItemString',hEle,pName,pValue,nParentID);
end

function XPGrid_DeleteAll(hEle)
return XC_API_CALL('XPGrid_DeleteAll',hEle);
end

function XPGrid_GetItemHELE(hEle,nItemID)
return XC_API_CALL('XPGrid_GetItemHELE',hEle,nItemID);
end

function XPGrid_SetWidth(hEle,nWidth)
return XC_API_CALL('XPGrid_SetWidth',hEle,nWidth);
end

function XPGrid_SetItemValue(hEle,nItemID,pValue)
return XC_API_CALL('XPGrid_SetItemValue',hEle,nItemID,pValue);
end

function XPGrid_SetItemValueInt(hEle,nItemID,nValue)
return XC_API_CALL('XPGrid_SetItemValueInt',hEle,nItemID,nValue);
end

function XPGrid_GetItemValue(hEle,nItemID)
return XC_API_CALL('XPGrid_GetItemValue',hEle,nItemID);
end

function XPGrid_HitTest(hEle,pPt,pbExpandButton)
return XC_API_CALL('XPGrid_HitTest',hEle,pPt,pbExpandButton);
end

function XPGrid_HitTestOffset(hEle,pPt,pbExpandButton)
return XC_API_CALL('XPGrid_HitTestOffset',hEle,pPt,pbExpandButton);
end

function XPGrid_ExpandItem(hEle,nItemID,bExpand)
return XC_API_CALL('XPGrid_ExpandItem',hEle,nItemID,bExpand);
end

function XPGrid_GetSelItem(hEle)
return XC_API_CALL('XPGrid_GetSelItem',hEle);
end

function XPGrid_SetSelItem(hEle,nItemID)
return XC_API_CALL('XPGrid_SetSelItem',hEle,nItemID);
end

function XRichEditColor_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XRichEditColor_Create',x,y,cx,cy,hParent);
end

function XRichEditColor_SetColor(hEle,color)
return XC_API_CALL('XRichEditColor_SetColor',hEle,color);
end

function XRichEditColor_GetColor(hEle)
return XC_API_CALL('XRichEditColor_GetColor',hEle);
end

function XRichEditSet_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XRichEditSet_Create',x,y,cx,cy,hParent);
end

function XRichEditFile_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XRichEditFile_Create',x,y,cx,cy,hParent);
end

function XRichEditFile_SetOpenFileType(hEle,pType)
return XC_API_CALL('XRichEditFile_SetOpenFileType',hEle,pType);
end

function XRichEditFile_SetDefaultFile(hEle,pFile)
return XC_API_CALL('XRichEditFile_SetDefaultFile',hEle,pFile);
end

function XRichEditFile_SetRelativeDir(hEle,pDir)
return XC_API_CALL('XRichEditFile_SetRelativeDir',hEle,pDir);
end

function XRichEditFolder_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XRichEditFolder_Create',x,y,cx,cy,hParent);
end

function XRichEditFolder_SetDefaultDir(hEle,pDir)
return XC_API_CALL('XRichEditFolder_SetDefaultDir',hEle,pDir);
end

function XRichEdit_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XRichEdit_Create',x,y,cx,cy,hParent);
end

function XRichEdit_InsertString(hEle,pString,hFont,color)
return XC_API_CALL('XRichEdit_InsertString',hEle,pString,hFont,color);
end

function XRichEdit_InsertImage(hEle,hImage,pImagePath)
return XC_API_CALL('XRichEdit_InsertImage',hEle,hImage,pImagePath);
end

function XRichEdit_InsertGif(hEle,hImage,pImagePath)
return XC_API_CALL('XRichEdit_InsertGif',hEle,hImage,pImagePath);
end

function XRichEdit_InsertStringEx(hEle,iRow,iColumn,pString,hFont,color)
return XC_API_CALL('XRichEdit_InsertStringEx',hEle,iRow,iColumn,pString,hFont,color);
end

function XRichEdit_InsertImageEx(hEle,iRow,iColumn,hImage,pImagePath)
return XC_API_CALL('XRichEdit_InsertImageEx',hEle,iRow,iColumn,hImage,pImagePath);
end

function XRichEdit_InsertGifEx(hEle,iRow,iColumn,hImage,pImagePath)
return XC_API_CALL('XRichEdit_InsertGifEx',hEle,iRow,iColumn,hImage,pImagePath);
end

function XRichEdit_EnableReadOnly(hEle,bEnable)
return XC_API_CALL('XRichEdit_EnableReadOnly',hEle,bEnable);
end

function XRichEdit_EnableMultiLine(hEle,bEnable)
return XC_API_CALL('XRichEdit_EnableMultiLine',hEle,bEnable);
end

function XRichEdit_EnablePassword(hEle,bEnable)
return XC_API_CALL('XRichEdit_EnablePassword',hEle,bEnable);
end

function XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE(hEle,bEnable)
return XC_API_CALL('XRichEdit_EnableEvent_XE_RICHEDIT_CHANGE',hEle,bEnable);
end

function XRichEdit_EnableAutoWrap(hEle,bEnable)
return XC_API_CALL('XRichEdit_EnableAutoWrap',hEle,bEnable);
end

function XRichEdit_EnableAutoSelAll(hEle,bEnable)
return XC_API_CALL('XRichEdit_EnableAutoSelAll',hEle,bEnable);
end

function XRichEdit_SetLimitNum(hEle,nNumber)
return XC_API_CALL('XRichEdit_SetLimitNum',hEle,nNumber);
end

function XRichEdit_SetCaretColor(hEle,color)
return XC_API_CALL('XRichEdit_SetCaretColor',hEle,color);
end

function XRichEdit_SetText(hEle,pString)
return XC_API_CALL('XRichEdit_SetText',hEle,pString);
end

function XRichEdit_SetTextInt(hEle,nVaule)
return XC_API_CALL('XRichEdit_SetTextInt',hEle,nVaule);
end

function XRichEdit_GetText(hEle,pOut,len)
return XC_API_CALL('XRichEdit_GetText',hEle,pOut,len);
end

function XRichEdit_GetHTMLFormat(hEle,pOut,len)
return XC_API_CALL('XRichEdit_GetHTMLFormat',hEle,pOut,len);
end

function XRichEdit_GetData(hEle,pDataSize)
return XC_API_CALL('XRichEdit_GetData',hEle,pDataSize);
end

function XRichEdit_InsertData(hEle,pData,iRow,iColumn)
return XC_API_CALL('XRichEdit_InsertData',hEle,pData,iRow,iColumn);
end

function XRichEdit_GetTextLength(hEle)
return XC_API_CALL('XRichEdit_GetTextLength',hEle);
end

function XRichEdit_SetRowHeight(hEle,nHeight)
return XC_API_CALL('XRichEdit_SetRowHeight',hEle,nHeight);
end

function XRichEdit_SetDefaultText(hEle,pString)
return XC_API_CALL('XRichEdit_SetDefaultText',hEle,pString);
end

function XRichEdit_SetDefaultTextColor(hEle,color,alpha)
return XC_API_CALL('XRichEdit_SetDefaultTextColor',hEle,color,alpha);
end

function XRichEdit_GetCurrentRow(hEle)
return XC_API_CALL('XRichEdit_GetCurrentRow',hEle);
end

function XRichEdit_GetCurrentColumn(hEle)
return XC_API_CALL('XRichEdit_GetCurrentColumn',hEle);
end

function XRichEdit_SetCurrentPos(hEle,iRow,iColumn)
return XC_API_CALL('XRichEdit_SetCurrentPos',hEle,iRow,iColumn);
end

function XRichEdit_GetRowCount(hEle)
return XC_API_CALL('XRichEdit_GetRowCount',hEle);
end

function XRichEdit_GetRowLength(hEle,iRow)
return XC_API_CALL('XRichEdit_GetRowLength',hEle,iRow);
end

function XRichEdit_GetSelectText(hEle,pOut,len)
return XC_API_CALL('XRichEdit_GetSelectText',hEle,pOut,len);
end

function XRichEdit_GetSelectPosition(hEle,pBegin,pEnd)
return XC_API_CALL('XRichEdit_GetSelectPosition',hEle,pBegin,pEnd);
end

function XRichEdit_SetSelect(hEle,iStartRow,iStartCol,iEndRow,iEndCol)
return XC_API_CALL('XRichEdit_SetSelect',hEle,iStartRow,iStartCol,iEndRow,iEndCol);
end

function XRichEdit_SetItemFontEx(hEle,beginRow,beginColumn,endRow,endColumn,hFont)
return XC_API_CALL('XRichEdit_SetItemFontEx',hEle,beginRow,beginColumn,endRow,endColumn,hFont);
end

function XRichEdit_SetItemColorEx(hEle,beginRow,beginColumn,endRow,endColumn,color,alpha)
return XC_API_CALL('XRichEdit_SetItemColorEx',hEle,beginRow,beginColumn,endRow,endColumn,color,alpha);
end

function XRichEdit_CancelSelect(hEle)
return XC_API_CALL('XRichEdit_CancelSelect',hEle);
end

function XRichEdit_SetSelectBkColor(hEle,color,alpha)
return XC_API_CALL('XRichEdit_SetSelectBkColor',hEle,color,alpha);
end

function XRichEdit_IsEmpty(hEle)
return XC_API_CALL('XRichEdit_IsEmpty',hEle);
end

function XRichEdit_SelectAll(hEle)
return XC_API_CALL('XRichEdit_SelectAll',hEle);
end

function XRichEdit_DeleteSelect(hEle)
return XC_API_CALL('XRichEdit_DeleteSelect',hEle);
end

function XRichEdit_DeleteAll(hEle)
return XC_API_CALL('XRichEdit_DeleteAll',hEle);
end

function XRichEdit_ClipboardCut(hEle)
return XC_API_CALL('XRichEdit_ClipboardCut',hEle);
end

function XRichEdit_ClipboardCopy(hEle)
return XC_API_CALL('XRichEdit_ClipboardCopy',hEle);
end

function XRichEdit_ClipboardPaste(hEle)
return XC_API_CALL('XRichEdit_ClipboardPaste',hEle);
end

function XSBar_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XSBar_Create',x,y,cx,cy,hParent);
end

function XSBar_SetRange(hEle,range)
return XC_API_CALL('XSBar_SetRange',hEle,range);
end

function XSBar_GetRange(hEle)
return XC_API_CALL('XSBar_GetRange',hEle);
end

function XSBar_ShowButton(hEle,bShow)
return XC_API_CALL('XSBar_ShowButton',hEle,bShow);
end

function XSBar_SetSliderLength(hEle,length)
return XC_API_CALL('XSBar_SetSliderLength',hEle,length);
end

function XSBar_SetSliderMinLength(hEle,minLength)
return XC_API_CALL('XSBar_SetSliderMinLength',hEle,minLength);
end

function XSBar_SetHorizon(hEle,bHorizon)
return XC_API_CALL('XSBar_SetHorizon',hEle,bHorizon);
end

function XSBar_GetSliderMaxLength(hEle)
return XC_API_CALL('XSBar_GetSliderMaxLength',hEle);
end

function XSBar_ScrollUp(hEle)
return XC_API_CALL('XSBar_ScrollUp',hEle);
end

function XSBar_ScrollDown(hEle)
return XC_API_CALL('XSBar_ScrollDown',hEle);
end

function XSBar_ScrollTop(hEle)
return XC_API_CALL('XSBar_ScrollTop',hEle);
end

function XSBar_ScrollBottom(hEle)
return XC_API_CALL('XSBar_ScrollBottom',hEle);
end

function XSBar_ScrollPos(hEle,pos)
return XC_API_CALL('XSBar_ScrollPos',hEle,pos);
end

function XSBar_GetButtonUp(hEle)
return XC_API_CALL('XSBar_GetButtonUp',hEle);
end

function XSBar_GetButtonDown(hEle)
return XC_API_CALL('XSBar_GetButtonDown',hEle);
end

function XSBar_GetButtonSlider(hEle)
return XC_API_CALL('XSBar_GetButtonSlider',hEle);
end

function XSView_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XSView_Create',x,y,cx,cy,hParent);
end

function XSView_SetTotalSize(hEle,cx,cy)
return XC_API_CALL('XSView_SetTotalSize',hEle,cx,cy);
end

function XSView_GetTotalSize(hEle,pSize)
return XC_API_CALL('XSView_GetTotalSize',hEle,pSize);
end

function XSView_SetLineSize(hEle,nWidth,nHeight)
return XC_API_CALL('XSView_SetLineSize',hEle,nWidth,nHeight);
end

function XSView_GetLineSize(hEle,pSize)
return XC_API_CALL('XSView_GetLineSize',hEle,pSize);
end

function XSView_SetScrollBarSize(hEle,size)
return XC_API_CALL('XSView_SetScrollBarSize',hEle,size);
end

function XSView_GetViewPosH(hEle)
return XC_API_CALL('XSView_GetViewPosH',hEle);
end

function XSView_GetViewPosV(hEle)
return XC_API_CALL('XSView_GetViewPosV',hEle);
end

function XSView_GetViewWidth(hEle)
return XC_API_CALL('XSView_GetViewWidth',hEle);
end

function XSView_GetViewHeight(hEle)
return XC_API_CALL('XSView_GetViewHeight',hEle);
end

function XSView_GetViewRect(hEle,pRect)
return XC_API_CALL('XSView_GetViewRect',hEle,pRect);
end

function XSView_GetScrollBarH(hEle)
return XC_API_CALL('XSView_GetScrollBarH',hEle);
end

function XSView_GetScrollBarV(hEle)
return XC_API_CALL('XSView_GetScrollBarV',hEle);
end

function XSView_SetBorderSize(hEle,left,top,right,bottom)
return XC_API_CALL('XSView_SetBorderSize',hEle,left,top,right,bottom);
end

function XSView_GetBorderSize(hEle,pBorder)
return XC_API_CALL('XSView_GetBorderSize',hEle,pBorder);
end

function XSView_ScrollPosH(hEle,pos)
return XC_API_CALL('XSView_ScrollPosH',hEle,pos);
end

function XSView_ScrollPosV(hEle,pos)
return XC_API_CALL('XSView_ScrollPosV',hEle,pos);
end

function XSView_ScrollPosXH(hEle,posX)
return XC_API_CALL('XSView_ScrollPosXH',hEle,posX);
end

function XSView_ScrollPosYV(hEle,posY)
return XC_API_CALL('XSView_ScrollPosYV',hEle,posY);
end

function XSView_ShowSBarH(hEle,bShow)
return XC_API_CALL('XSView_ShowSBarH',hEle,bShow);
end

function XSView_ShowSBarV(hEle,bShow)
return XC_API_CALL('XSView_ShowSBarV',hEle,bShow);
end

function XSView_EnableAutoShowScrollBar(hEle,bEnable)
return XC_API_CALL('XSView_EnableAutoShowScrollBar',hEle,bEnable);
end

function XSView_ScrollLeftLine(hEle)
return XC_API_CALL('XSView_ScrollLeftLine',hEle);
end

function XSView_ScrollRightLine(hEle)
return XC_API_CALL('XSView_ScrollRightLine',hEle);
end

function XSView_ScrollTopLine(hEle)
return XC_API_CALL('XSView_ScrollTopLine',hEle);
end

function XSView_ScrollBottomLine(hEle)
return XC_API_CALL('XSView_ScrollBottomLine',hEle);
end

function XSView_ScrollLeft(hEle)
return XC_API_CALL('XSView_ScrollLeft',hEle);
end

function XSView_ScrollRight(hEle)
return XC_API_CALL('XSView_ScrollRight',hEle);
end

function XSView_ScrollTop(hEle)
return XC_API_CALL('XSView_ScrollTop',hEle);
end

function XSView_ScrollBottom(hEle)
return XC_API_CALL('XSView_ScrollBottom',hEle);
end

function XShape_GetParentEle(hShape)
return XC_API_CALL('XShape_GetParentEle',hShape);
end

function XShape_GetParentLayout(hShape)
return XC_API_CALL('XShape_GetParentLayout',hShape);
end

function XShape_GetHWINDOW(hShape)
return XC_API_CALL('XShape_GetHWINDOW',hShape);
end

function XShape_GetParent(hShape)
return XC_API_CALL('XShape_GetParent',hShape);
end

function XShape_RemoveShape(hShape)
return XC_API_CALL('XShape_RemoveShape',hShape);
end

function XShape_SetID(hShape,nID)
return XC_API_CALL('XShape_SetID',hShape,nID);
end

function XShape_GetID(hShape)
return XC_API_CALL('XShape_GetID',hShape);
end

function XShape_Redraw(hShape)
return XC_API_CALL('XShape_Redraw',hShape);
end

function XShape_GetWidth(hShape)
return XC_API_CALL('XShape_GetWidth',hShape);
end

function XShape_GetHeight(hShape)
return XC_API_CALL('XShape_GetHeight',hShape);
end

function XShape_GetRect(hShape,pRect)
return XC_API_CALL('XShape_GetRect',hShape,pRect);
end

function XShape_SetRect(hShape,pRect)
return XC_API_CALL('XShape_SetRect',hShape,pRect);
end

function XShape_GetContentSize(hShape,pSize)
return XC_API_CALL('XShape_GetContentSize',hShape,pSize);
end

function XShape_ShowLayout(hShape,bShow)
return XC_API_CALL('XShape_ShowLayout',hShape,bShow);
end

function XShape_AdjustLayout(hShape)
return XC_API_CALL('XShape_AdjustLayout',hShape);
end

function XShape_Destroy(hShape)
return XC_API_CALL('XShape_Destroy',hShape);
end

function XShapeText_Create(x,y,cx,cy,pName,hParent)
return XC_API_CALL('XShapeText_Create',x,y,cx,cy,pName,hParent);
end

function XShapeText_SetText(hTextBlock,pName)
return XC_API_CALL('XShapeText_SetText',hTextBlock,pName);
end

function XShapeText_GetText(hTextBlock,pOut,nOutLen)
return XC_API_CALL('XShapeText_GetText',hTextBlock,pOut,nOutLen);
end

function XShapeText_GetTextLength(hTextBlock)
return XC_API_CALL('XShapeText_GetTextLength',hTextBlock);
end

function XShapeText_SetFont(hTextBlock,hFontx)
return XC_API_CALL('XShapeText_SetFont',hTextBlock,hFontx);
end

function XShapeText_GetFont(hTextBlock)
return XC_API_CALL('XShapeText_GetFont',hTextBlock);
end

function XShapeText_SetTextColor(hTextBlock,color,alpha)
return XC_API_CALL('XShapeText_SetTextColor',hTextBlock,color,alpha);
end

function XShapeText_GetTextColor(hTextBlock)
return XC_API_CALL('XShapeText_GetTextColor',hTextBlock);
end

function XShapeText_SetTextAlign(hTextBlock,align)
return XC_API_CALL('XShapeText_SetTextAlign',hTextBlock,align);
end

function XShapeText_SetOffset(hTextBlock,x,y)
return XC_API_CALL('XShapeText_SetOffset',hTextBlock,x,y);
end

function XShapeText_SetLayoutWidth(hTextBlock,nType,width)
return XC_API_CALL('XShapeText_SetLayoutWidth',hTextBlock,nType,width);
end

function XShapeText_SetLayoutHeight(hTextBlock,nType,height)
return XC_API_CALL('XShapeText_SetLayoutHeight',hTextBlock,nType,height);
end

function XShapeText_GetLayoutWidth(hTextBlock,pType,pWidth)
return XC_API_CALL('XShapeText_GetLayoutWidth',hTextBlock,pType,pWidth);
end

function XShapeText_GetLayoutHeight(hTextBlock,pType,pHeight)
return XC_API_CALL('XShapeText_GetLayoutHeight',hTextBlock,pType,pHeight);
end

function XShapePic_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XShapePic_Create',x,y,cx,cy,hParent);
end

function XShapePic_SetImage(hShape,hImage)
return XC_API_CALL('XShapePic_SetImage',hShape,hImage);
end

function XShapePic_SetLayoutWidth(hShape,nType,width)
return XC_API_CALL('XShapePic_SetLayoutWidth',hShape,nType,width);
end

function XShapePic_SetLayoutHeight(hShape,nType,height)
return XC_API_CALL('XShapePic_SetLayoutHeight',hShape,nType,height);
end

function XShapePic_GetLayoutWidth(hShape,pType,pWidth)
return XC_API_CALL('XShapePic_GetLayoutWidth',hShape,pType,pWidth);
end

function XShapePic_GetLayoutHeight(hShape,pType,pHeight)
return XC_API_CALL('XShapePic_GetLayoutHeight',hShape,pType,pHeight);
end

function XShapeGif_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XShapeGif_Create',x,y,cx,cy,hParent);
end

function XShapeGif_SetImage(hShape,hImage)
return XC_API_CALL('XShapeGif_SetImage',hShape,hImage);
end

function XShapeGif_SetLayoutWidth(hShape,nType,width)
return XC_API_CALL('XShapeGif_SetLayoutWidth',hShape,nType,width);
end

function XShapeGif_SetLayoutHeight(hShape,nType,height)
return XC_API_CALL('XShapeGif_SetLayoutHeight',hShape,nType,height);
end

function XShapeGif_GetLayoutWidth(hShape,pType,pWidth)
return XC_API_CALL('XShapeGif_GetLayoutWidth',hShape,pType,pWidth);
end

function XShapeGif_GetLayoutHeight(hShape,pType,pHeight)
return XC_API_CALL('XShapeGif_GetLayoutHeight',hShape,pType,pHeight);
end

function XShapeRect_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XShapeRect_Create',x,y,cx,cy,hParent);
end

function XShapeRect_SetBorderColor(hShape,color,alpha)
return XC_API_CALL('XShapeRect_SetBorderColor',hShape,color,alpha);
end

function XShapeRect_SetFillColor(hShape,color,alpha)
return XC_API_CALL('XShapeRect_SetFillColor',hShape,color,alpha);
end

function XShapeRect_SetRoundAngle(hShape,nWidth,nHeight)
return XC_API_CALL('XShapeRect_SetRoundAngle',hShape,nWidth,nHeight);
end

function XShapeRect_GetRoundAngle(hShape,pWidth,pHeight)
return XC_API_CALL('XShapeRect_GetRoundAngle',hShape,pWidth,pHeight);
end

function XShapeRect_EnableBorder(hShape,bEnable)
return XC_API_CALL('XShapeRect_EnableBorder',hShape,bEnable);
end

function XShapeRect_EnableFill(hShape,bEnable)
return XC_API_CALL('XShapeRect_EnableFill',hShape,bEnable);
end

function XShapeRect_EnableRoundAngle(hShape,bEnable)
return XC_API_CALL('XShapeRect_EnableRoundAngle',hShape,bEnable);
end

function XShapeEllipse_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XShapeEllipse_Create',x,y,cx,cy,hParent);
end

function XShapeEllipse_SetBorderColor(hShape,color,alpha)
return XC_API_CALL('XShapeEllipse_SetBorderColor',hShape,color,alpha);
end

function XShapeEllipse_SetFillColor(hShape,color,alpha)
return XC_API_CALL('XShapeEllipse_SetFillColor',hShape,color,alpha);
end

function XShapeEllipse_EnableBorder(hShape,bEnable)
return XC_API_CALL('XShapeEllipse_EnableBorder',hShape,bEnable);
end

function XShapeEllipse_EnableFill(hShape,bEnable)
return XC_API_CALL('XShapeEllipse_EnableFill',hShape,bEnable);
end

function XShapeGroupBox_Create(x,y,cx,cy,pName,hParent)
return XC_API_CALL('XShapeGroupBox_Create',x,y,cx,cy,pName,hParent);
end

function XShapeGroupBox_SetBorderColor(hShape,color,alpha)
return XC_API_CALL('XShapeGroupBox_SetBorderColor',hShape,color,alpha);
end

function XShapeGroupBox_SetTextColor(hShape,color,alpha)
return XC_API_CALL('XShapeGroupBox_SetTextColor',hShape,color,alpha);
end

function XShapeGroupBox_SetFontX(hShape,hFontX)
return XC_API_CALL('XShapeGroupBox_SetFontX',hShape,hFontX);
end

function XShapeGroupBox_SetTextOffset(hShape,offsetX,offsetY)
return XC_API_CALL('XShapeGroupBox_SetTextOffset',hShape,offsetX,offsetY);
end

function XShapeGroupBox_SetRoundAngle(hShape,nWidth,nHeight)
return XC_API_CALL('XShapeGroupBox_SetRoundAngle',hShape,nWidth,nHeight);
end

function XShapeGroupBox_SetText(hShape,pText)
return XC_API_CALL('XShapeGroupBox_SetText',hShape,pText);
end

function XShapeGroupBox_GetTextOffset(hShape,pOffsetX,pOffsetY)
return XC_API_CALL('XShapeGroupBox_GetTextOffset',hShape,pOffsetX,pOffsetY);
end

function XShapeGroupBox_GetRoundAngle(hShape,pWidth,pHeight)
return XC_API_CALL('XShapeGroupBox_GetRoundAngle',hShape,pWidth,pHeight);
end

function XShapeGroupBox_EnableRoundAngle(hShape,bEnable)
return XC_API_CALL('XShapeGroupBox_EnableRoundAngle',hShape,bEnable);
end

function XShapeLine_Create(x1,y1,x2,y2,hParent)
return XC_API_CALL('XShapeLine_Create',x1,y1,x2,y2,hParent);
end

function XShapeLine_SetPosition(hShape,x1,y1,x2,y2)
return XC_API_CALL('XShapeLine_SetPosition',hShape,x1,y1,x2,y2);
end

function XShapeLine_SetColor(hShape,color,alpha)
return XC_API_CALL('XShapeLine_SetColor',hShape,color,alpha);
end

function XSliderBar_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XSliderBar_Create',x,y,cx,cy,hParent);
end

function XSliderBar_SetRange(hEle,range)
return XC_API_CALL('XSliderBar_SetRange',hEle,range);
end

function XSliderBar_GetRange(hEle)
return XC_API_CALL('XSliderBar_GetRange',hEle);
end

function XSliderBar_SetButtonWidth(hEle,width)
return XC_API_CALL('XSliderBar_SetButtonWidth',hEle,width);
end

function XSliderBar_SetButtonHeight(hEle,height)
return XC_API_CALL('XSliderBar_SetButtonHeight',hEle,height);
end

function XSliderBar_SetSpaceTwo(hEle,leftSize,rightSize)
return XC_API_CALL('XSliderBar_SetSpaceTwo',hEle,leftSize,rightSize);
end

function XSliderBar_SetPos(hEle,pos)
return XC_API_CALL('XSliderBar_SetPos',hEle,pos);
end

function XSliderBar_GetPos(hEle)
return XC_API_CALL('XSliderBar_GetPos',hEle);
end

function XSliderBar_GetButton(hEle)
return XC_API_CALL('XSliderBar_GetButton',hEle);
end

function XSliderBar_SetHorizon(hEle,bHorizon)
return XC_API_CALL('XSliderBar_SetHorizon',hEle,bHorizon);
end

function XSliderBar_SetImageLoad(hEle,hImage)
return XC_API_CALL('XSliderBar_SetImageLoad',hEle,hImage);
end

function XTabBar_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XTabBar_Create',x,y,cx,cy,hParent);
end

function XTabBar_AddLabel(hEle,pName)
return XC_API_CALL('XTabBar_AddLabel',hEle,pName);
end

function XTabBar_InsertLabel(hEle,index,pName)
return XC_API_CALL('XTabBar_InsertLabel',hEle,index,pName);
end

function XTabBar_DeleteLabel(hEle,index)
return XC_API_CALL('XTabBar_DeleteLabel',hEle,index);
end

function XTabBar_DeleteLabelAll(hEle)
return XC_API_CALL('XTabBar_DeleteLabelAll',hEle);
end

function XTabBar_GetLabel(hEle,index)
return XC_API_CALL('XTabBar_GetLabel',hEle,index);
end

function XTabBar_GetLabelClose(hEle,index)
return XC_API_CALL('XTabBar_GetLabelClose',hEle,index);
end

function XTabBar_GetButtonLeft(hEle)
return XC_API_CALL('XTabBar_GetButtonLeft',hEle);
end

function XTabBar_GetButtonRight(hEle)
return XC_API_CALL('XTabBar_GetButtonRight',hEle);
end

function XTabBar_GetSelect(hEle)
return XC_API_CALL('XTabBar_GetSelect',hEle);
end

function XTabBar_GetLabelSpacing(hEle)
return XC_API_CALL('XTabBar_GetLabelSpacing',hEle);
end

function XTabBar_GetLabelCount(hEle)
return XC_API_CALL('XTabBar_GetLabelCount',hEle);
end

function XTabBar_GetindexByEle(hEle,hLabel)
return XC_API_CALL('XTabBar_GetindexByEle',hEle,hLabel);
end

function XTabBar_SetLabelSpacing(hEle,spacing)
return XC_API_CALL('XTabBar_SetLabelSpacing',hEle,spacing);
end

function XTabBar_SetSelect(hEle,index)
return XC_API_CALL('XTabBar_SetSelect',hEle,index);
end

function XTabBar_SetUp(hEle)
return XC_API_CALL('XTabBar_SetUp',hEle);
end

function XTabBar_SetDown(hEle)
return XC_API_CALL('XTabBar_SetDown',hEle);
end

function XTabBar_EnableTile(hEle,bTile)
return XC_API_CALL('XTabBar_EnableTile',hEle,bTile);
end

function XTabBar_EnableClose(hEle,bEnable)
return XC_API_CALL('XTabBar_EnableClose',hEle,bEnable);
end

function XTabBar_SetCloseSize(hEle,pSize)
return XC_API_CALL('XTabBar_SetCloseSize',hEle,pSize);
end

function XTabBar_SetTurnButtonSize(hEle,pSize)
return XC_API_CALL('XTabBar_SetTurnButtonSize',hEle,pSize);
end

function XTabBar_SetLabelWidth(hEle,index,nWidth)
return XC_API_CALL('XTabBar_SetLabelWidth',hEle,index,nWidth);
end

function XTabBar_ShowLabel(hEle,index,bShow)
return XC_API_CALL('XTabBar_ShowLabel',hEle,index,bShow);
end

function XTextLink_Create(x,y,cx,cy,pName,hParent)
return XC_API_CALL('XTextLink_Create',x,y,cx,cy,pName,hParent);
end

function XTextLink_EnableUnderlineLeave(hEle,bEnable)
return XC_API_CALL('XTextLink_EnableUnderlineLeave',hEle,bEnable);
end

function XTextLink_EnableUnderlineStay(hEle,bEnable)
return XC_API_CALL('XTextLink_EnableUnderlineStay',hEle,bEnable);
end

function XTextLink_SetTextColorStay(hEle,color,alpha)
return XC_API_CALL('XTextLink_SetTextColorStay',hEle,color,alpha);
end

function XTextLink_SetUnderlineColorLeave(hEle,color,alpha)
return XC_API_CALL('XTextLink_SetUnderlineColorLeave',hEle,color,alpha);
end

function XTextLink_SetUnderlineColorStay(hEle,color,alpha)
return XC_API_CALL('XTextLink_SetUnderlineColorStay',hEle,color,alpha);
end

function XToolBar_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XToolBar_Create',x,y,cx,cy,hParent);
end

function XToolBar_InsertEle(hEle,hNewEle,index)
return XC_API_CALL('XToolBar_InsertEle',hEle,hNewEle,index);
end

function XToolBar_InsertSeparator(hEle,index)
return XC_API_CALL('XToolBar_InsertSeparator',hEle,index);
end

function XToolBar_EnableButtonMenu(hEle,bEnable)
return XC_API_CALL('XToolBar_EnableButtonMenu',hEle,bEnable);
end

function XToolBar_GetHEle(hEle,index)
return XC_API_CALL('XToolBar_GetHEle',hEle,index);
end

function XToolBar_GetButtonLeft(hEle)
return XC_API_CALL('XToolBar_GetButtonLeft',hEle);
end

function XToolBar_GetButtonRight(hEle)
return XC_API_CALL('XToolBar_GetButtonRight',hEle);
end

function XToolBar_GetButtonMenu(hEle)
return XC_API_CALL('XToolBar_GetButtonMenu',hEle);
end

function XToolBar_SetSpace(hEle,nSize)
return XC_API_CALL('XToolBar_SetSpace',hEle,nSize);
end

function XToolBar_DeleteEle(hEle,index)
return XC_API_CALL('XToolBar_DeleteEle',hEle,index);
end

function XToolBar_DeleteAllEle(hEle)
return XC_API_CALL('XToolBar_DeleteAllEle',hEle);
end

function XTree_Create(x,y,cx,cy,hParent)
return XC_API_CALL('XTree_Create',x,y,cx,cy,hParent);
end

function XTree_EnableDragItem(hEle,bEnable)
return XC_API_CALL('XTree_EnableDragItem',hEle,bEnable);
end

function XTree_EnableConnectLine(hEle,bEnable,bSolid)
return XC_API_CALL('XTree_EnableConnectLine',hEle,bEnable,bSolid);
end

function XTree_SetConnectLineColor(hEle,color,alpha)
return XC_API_CALL('XTree_SetConnectLineColor',hEle,color,alpha);
end

function XTree_SetExpandButtonSize(hEle,nWidth,nHeight)
return XC_API_CALL('XTree_SetExpandButtonSize',hEle,nWidth,nHeight);
end

function XTree_SetDragInsertPositionColor(hEle,color,alpha)
return XC_API_CALL('XTree_SetDragInsertPositionColor',hEle,color,alpha);
end

function XTree_SetItemTemplateXML(hEle,pXmlFile)
return XC_API_CALL('XTree_SetItemTemplateXML',hEle,pXmlFile);
end

function XTree_SetItemTemplateXMLSel(hEle,pXmlFile)
return XC_API_CALL('XTree_SetItemTemplateXMLSel',hEle,pXmlFile);
end

function XTree_SetItemTemplateXMLFromString(hEle,pStringXML)
return XC_API_CALL('XTree_SetItemTemplateXMLFromString',hEle,pStringXML);
end

function XTree_SetItemTemplateXMLSelFromString(hEle,pStringXML)
return XC_API_CALL('XTree_SetItemTemplateXMLSelFromString',hEle,pStringXML);
end

function XTree_SetDrawItemBkFlags(hEle,nFlags)
return XC_API_CALL('XTree_SetDrawItemBkFlags',hEle,nFlags);
end

function XTree_SetItemData(hEle,nID,nUserData)
return XC_API_CALL('XTree_SetItemData',hEle,nID,nUserData);
end

function XTree_GetItemData(hEle,nID)
return XC_API_CALL('XTree_GetItemData',hEle,nID);
end

function XTree_SetSelectItem(hEle,nID)
return XC_API_CALL('XTree_SetSelectItem',hEle,nID);
end

function XTree_GetSelectItem(hEle)
return XC_API_CALL('XTree_GetSelectItem',hEle);
end

function XTree_IsExpand(hEle,nID)
return XC_API_CALL('XTree_IsExpand',hEle,nID);
end

function XTree_ExpandItem(hEle,nID,bExpand)
return XC_API_CALL('XTree_ExpandItem',hEle,nID,bExpand);
end

function XTree_HitTest(hEle,pPt)
return XC_API_CALL('XTree_HitTest',hEle,pPt);
end

function XTree_HitTestOffset(hEle,pPt)
return XC_API_CALL('XTree_HitTestOffset',hEle,pPt);
end

function XTree_GetFirstChildItem(hEle,nID)
return XC_API_CALL('XTree_GetFirstChildItem',hEle,nID);
end

function XTree_GetEndChildItem(hEle,nID)
return XC_API_CALL('XTree_GetEndChildItem',hEle,nID);
end

function XTree_GetPrevSiblingItem(hEle,nID)
return XC_API_CALL('XTree_GetPrevSiblingItem',hEle,nID);
end

function XTree_GetNextSiblingItem(hEle,nID)
return XC_API_CALL('XTree_GetNextSiblingItem',hEle,nID);
end

function XTree_GetParentItem(hEle,nID)
return XC_API_CALL('XTree_GetParentItem',hEle,nID);
end

function XTree_SetIndentation(hEle,nWidth)
return XC_API_CALL('XTree_SetIndentation',hEle,nWidth);
end

function XTree_GetIndentation(hEle)
return XC_API_CALL('XTree_GetIndentation',hEle);
end

function XTree_SetItemHeight(hEle,nID,nHeight,nSelHeight)
return XC_API_CALL('XTree_SetItemHeight',hEle,nID,nHeight,nSelHeight);
end

function XTree_GetItemHeight(hEle,nID,pHeight,pSelHeight)
return XC_API_CALL('XTree_GetItemHeight',hEle,nID,pHeight,pSelHeight);
end

function XTree_SetRowSpace(hEle,nSpace)
return XC_API_CALL('XTree_SetRowSpace',hEle,nSpace);
end

function XTree_GetRowSpace(hEle)
return XC_API_CALL('XTree_GetRowSpace',hEle);
end

function XTree_MoveItem(hEle,nMoveItem,nDestItem,nType)
return XC_API_CALL('XTree_MoveItem',hEle,nMoveItem,nDestItem,nType);
end

function XTree_AddItemBkBorder(hEle,nState,color,alpha,width)
return XC_API_CALL('XTree_AddItemBkBorder',hEle,nState,color,alpha,width);
end

function XTree_AddItemBkFill(hEle,nState,color,alpha)
return XC_API_CALL('XTree_AddItemBkFill',hEle,nState,color,alpha);
end

function XTree_AddItemBkImage(hEle,nState,hImage)
return XC_API_CALL('XTree_AddItemBkImage',hEle,nState,hImage);
end

function XTree_GetItemBkInfoCount(hEle)
return XC_API_CALL('XTree_GetItemBkInfoCount',hEle);
end

function XTree_ClearItemBkInfo(hEle)
return XC_API_CALL('XTree_ClearItemBkInfo',hEle);
end

function XTree_SetItemHeightDefault(hEle,nHeight,nSelHeight)
return XC_API_CALL('XTree_SetItemHeightDefault',hEle,nHeight,nSelHeight);
end

function XTree_GetItemHeightDefault(hEle,pHeight,pSelHeight)
return XC_API_CALL('XTree_GetItemHeightDefault',hEle,pHeight,pSelHeight);
end

function XTree_GetTemplateObject(hEle,nID,nTempItemID)
return XC_API_CALL('XTree_GetTemplateObject',hEle,nID,nTempItemID);
end

function XTree_GetItemIDFromHXCGUI(hEle,hXCGUI)
return XC_API_CALL('XTree_GetItemIDFromHXCGUI',hEle,hXCGUI);
end

function XTree_BindAdapter(hEle,hAdapter)
return XC_API_CALL('XTree_BindAdapter',hEle,hAdapter);
end

function XTree_GetAdapter(hEle)
return XC_API_CALL('XTree_GetAdapter',hEle);
end

function XTree_RefreshData(hEle)
return XC_API_CALL('XTree_RefreshData',hEle);
end

function XWnd_RegEventEx(hWindow,pEvent)
return XC_API_CALL('XWnd_RegEventEx',hWindow,pEvent);
end

function XWnd_RemoveEventEx(hWindow,pEvent)
return XC_API_CALL('XWnd_RemoveEventEx',hWindow,pEvent);
end

function XWnd_RegEventC(hWindow,nEvent,pFun)
return XC_API_CALL('XWnd_RegEventC',hWindow,nEvent,pFun);
end

function XWnd_RegEventC1(hWindow,nEvent,pFun)
return XC_API_CALL('XWnd_RegEventC1',hWindow,nEvent,pFun);
end

function XWnd_RemovegEvent(hWindow,nEvent,pFun)
return XC_API_CALL('XWnd_RemovegEvent',hWindow,nEvent,pFun);
end

function XWnd_Create(x,y,cx,cy,pTitle,hWndParent,XCStyle)
return XC_API_CALL('XWnd_Create',x,y,cx,cy,pTitle,hWndParent,XCStyle);
end

function XWnd_CreateEx(dwExStyle,lpClassName,lpWindowName,dwStyle,x,y,cx,cy,hWndParent,XCStyle)
return XC_API_CALL('XWnd_CreateEx',dwExStyle,lpClassName,lpWindowName,dwStyle,x,y,cx,cy,hWndParent,XCStyle);
end

function XWnd_AddEle(hWindow,hEle)
return XC_API_CALL('XWnd_AddEle',hWindow,hEle);
end

function XWnd_InsertEle(hWindow,hChildEle,index)
return XC_API_CALL('XWnd_InsertEle',hWindow,hChildEle,index);
end

function XWnd_AddShape(hWindow,hShape)
return XC_API_CALL('XWnd_AddShape',hWindow,hShape);
end

function XWnd_GetHWND(hWindow)
return XC_API_CALL('XWnd_GetHWND',hWindow);
end

function XWnd_EnableDragBorder(hWindow,bEnable)
return XC_API_CALL('XWnd_EnableDragBorder',hWindow,bEnable);
end

function XWnd_EnableDragWindow(hWindow,bEnable)
return XC_API_CALL('XWnd_EnableDragWindow',hWindow,bEnable);
end

function XWnd_EnableDragCaption(hWindow,bEnable)
return XC_API_CALL('XWnd_EnableDragCaption',hWindow,bEnable);
end

function XWnd_EnableDrawBk(hWindow,bEnable)
return XC_API_CALL('XWnd_EnableDrawBk',hWindow,bEnable);
end

function XWnd_EnableAutoFocus(hWindow,bEnable)
return XC_API_CALL('XWnd_EnableAutoFocus',hWindow,bEnable);
end

function XWnd_EnableMaxWindow(hWindow,bEnable)
return XC_API_CALL('XWnd_EnableMaxWindow',hWindow,bEnable);
end

function XWnd_RedrawWnd(hWindow,bImmediate)
return XC_API_CALL('XWnd_RedrawWnd',hWindow,bImmediate);
end

function XWnd_RedrawWndRect(hWindow,pRect,bImmediate)
return XC_API_CALL('XWnd_RedrawWndRect',hWindow,pRect,bImmediate);
end

function XWnd_SetFocusEle(hWindow,hFocusEle)
return XC_API_CALL('XWnd_SetFocusEle',hWindow,hFocusEle);
end

function XWnd_GetFocusEle(hWindow)
return XC_API_CALL('XWnd_GetFocusEle',hWindow);
end

function XWnd_GetStayHELE(hWindow)
return XC_API_CALL('XWnd_GetStayHELE',hWindow);
end

function XWnd_SetCursor(hWindow,hCursor)
return XC_API_CALL('XWnd_SetCursor',hWindow,hCursor);
end

function XWnd_GetCursor(hWindow)
return XC_API_CALL('XWnd_GetCursor',hWindow);
end

function XWnd_SetCursorSys(hWindow,hCursor)
return XC_API_CALL('XWnd_SetCursorSys',hWindow,hCursor);
end

function XWnd_SetFont(hWindow,hFontx)
return XC_API_CALL('XWnd_SetFont',hWindow,hFontx);
end

function XWnd_SetID(hWindow,nID)
return XC_API_CALL('XWnd_SetID',hWindow,nID);
end

function XWnd_GetID(hWindow)
return XC_API_CALL('XWnd_GetID',hWindow);
end

function XWnd_SetCaptureEle(hWindow,hEle)
return XC_API_CALL('XWnd_SetCaptureEle',hWindow,hEle);
end

function XWnd_GetCaptureEle(hWindow)
return XC_API_CALL('XWnd_GetCaptureEle',hWindow);
end

function XWnd_BindLayoutEle(hWindow,nPosition,hEle)
return XC_API_CALL('XWnd_BindLayoutEle',hWindow,nPosition,hEle);
end

function XWnd_GetLayoutEle(hWindow,nPosition)
return XC_API_CALL('XWnd_GetLayoutEle',hWindow,nPosition);
end

function XWnd_BindLayoutObject(hWindow,nPosition,hLayout)
return XC_API_CALL('XWnd_BindLayoutObject',hWindow,nPosition,hLayout);
end

function XWnd_GetLayoutObject(hWindow,nPosition)
return XC_API_CALL('XWnd_GetLayoutObject',hWindow,nPosition);
end

function XWnd_SetLayoutSize(hWindow,left,top,right,bottom)
return XC_API_CALL('XWnd_SetLayoutSize',hWindow,left,top,right,bottom);
end

function XWnd_GetLayoutSize(hWindow,pBorderSize)
return XC_API_CALL('XWnd_GetLayoutSize',hWindow,pBorderSize);
end

function XWnd_SetDragBorderSize(hWindow,left,top,right,bottom)
return XC_API_CALL('XWnd_SetDragBorderSize',hWindow,left,top,right,bottom);
end

function XWnd_GetDragBorderSize(hWindow,pSize)
return XC_API_CALL('XWnd_GetDragBorderSize',hWindow,pSize);
end

function XWnd_SetMinimumSize(hWindow,width,height)
return XC_API_CALL('XWnd_SetMinimumSize',hWindow,width,height);
end

function XWnd_HitChildEle(hWindow,pPt)
return XC_API_CALL('XWnd_HitChildEle',hWindow,pPt);
end

function XWnd_GetChildCount(hWindow)
return XC_API_CALL('XWnd_GetChildCount',hWindow);
end

function XWnd_GetChildByIndex(hWindow,index)
return XC_API_CALL('XWnd_GetChildByIndex',hWindow,index);
end

function XWnd_GetChildByID(hWindow,nID)
return XC_API_CALL('XWnd_GetChildByID',hWindow,nID);
end

function XWnd_GetEle(hWindow,nID)
return XC_API_CALL('XWnd_GetEle',hWindow,nID);
end

function XWnd_GetChildShapeCount(hWindow)
return XC_API_CALL('XWnd_GetChildShapeCount',hWindow);
end

function XWnd_GetChildShapeByIndex(hWindow,index)
return XC_API_CALL('XWnd_GetChildShapeByIndex',hWindow,index);
end

function XWnd_GetDrawRect(hWindow,pRcPaint)
return XC_API_CALL('XWnd_GetDrawRect',hWindow,pRcPaint);
end

function XWnd_ShowWindow(hWindow,nCmdShow)
return XC_API_CALL('XWnd_ShowWindow',hWindow,nCmdShow);
end

function XWnd_AdjustLayout(hWindow)
return XC_API_CALL('XWnd_AdjustLayout',hWindow);
end

function XWnd_AdjustLayoutObject(hWindow)
return XC_API_CALL('XWnd_AdjustLayoutObject',hWindow);
end

function XWnd_CloseWindow(hWindow)
return XC_API_CALL('XWnd_CloseWindow',hWindow);
end

function XWnd_CreateCaret(hWindow,hEle,width,height)
return XC_API_CALL('XWnd_CreateCaret',hWindow,hEle,width,height);
end

function XWnd_SetCaretSize(hWindow,width,height)
return XC_API_CALL('XWnd_SetCaretSize',hWindow,width,height);
end

function XWnd_SetCaretPos(hWindow,x,y)
return XC_API_CALL('XWnd_SetCaretPos',hWindow,x,y);
end

function XWnd_SetCaretPosEx(hWindow,x,y,width,height)
return XC_API_CALL('XWnd_SetCaretPosEx',hWindow,x,y,width,height);
end

function XWnd_SetCaretColor(hWindow,color)
return XC_API_CALL('XWnd_SetCaretColor',hWindow,color);
end

function XWnd_ShowCaret(hWindow,bShow)
return XC_API_CALL('XWnd_ShowCaret',hWindow,bShow);
end

function XWnd_DestroyCaret(hWindow)
return XC_API_CALL('XWnd_DestroyCaret',hWindow);
end

function XWnd_GetCaretHELE(hWindow)
return XC_API_CALL('XWnd_GetCaretHELE',hWindow);
end

function XWnd_GetClientRect(hWindow,pRect)
return XC_API_CALL('XWnd_GetClientRect',hWindow,pRect);
end

function XWnd_GetBodyRect(hWindow,pRect)
return XC_API_CALL('XWnd_GetBodyRect',hWindow,pRect);
end

function XWnd_SetTimer(hWindow,nIDEvent,uElapse)
return XC_API_CALL('XWnd_SetTimer',hWindow,nIDEvent,uElapse);
end

function XWnd_KillTimer(hWindow,nIDEvent)
return XC_API_CALL('XWnd_KillTimer',hWindow,nIDEvent);
end

function XWnd_SetXCTimer(hWindow,nIDEvent,uElapse)
return XC_API_CALL('XWnd_SetXCTimer',hWindow,nIDEvent,uElapse);
end

function XWnd_KillXCTimer(hWindow,nIDEvent)
return XC_API_CALL('XWnd_KillXCTimer',hWindow,nIDEvent);
end

function XWnd_GetBkInfoManager(hWindow)
return XC_API_CALL('XWnd_GetBkInfoManager',hWindow);
end

function XWnd_SetTransparentType(hWindow,nType)
return XC_API_CALL('XWnd_SetTransparentType',hWindow,nType);
end

function XWnd_SetTransparentAlpha(hWindow,alpha)
return XC_API_CALL('XWnd_SetTransparentAlpha',hWindow,alpha);
end

function XWnd_SetTransparentColor(hWindow,color)
return XC_API_CALL('XWnd_SetTransparentColor',hWindow,color);
end

function XWnd_RegEventTest(nEvent,pParamType)
return XC_API_CALL('XWnd_RegEventTest',nEvent,pParamType);
end