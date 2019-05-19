#ifndef EWE_V1_H
#define EWE_V1_H

#define WKE_BUILD
#define WKE_STATIC

#define EWE_WNDCLASS L"EweWindow"


typedef char                   utf8;
typedef struct EweWindow       EweWindow;
typedef struct WTFString       WTFString;

#include "wke.h"

WKE_API void*          WKE_CALL wkeGetUserData( wkeWebView* );
WKE_API void           WKE_CALL wkeSetUserData( wkeWebView*, void* ud );

WKE_API bool           WKE_CALL wkeIsDirty(wkeWebView* webView);
WKE_API void           WKE_CALL wkeSetDirty(wkeWebView* webView, bool dirty);

WKE_API void           WKE_CALL wkeSetWTFString( WTFString* rstr, const wchar_t* _value );
WKE_API const wchar_t* WKE_CALL wkeGetWTFString( WTFString* rstr );
WKE_API int            WKE_CALL wkeJSParamCount(wkeJSState* es);
WKE_API wkeJSType      WKE_CALL wkeJSParamType(wkeJSState* es, int argIdx);
WKE_API wkeJSValue     WKE_CALL wkeJSParam(wkeJSState* es, int argIdx);

WKE_API void           WKE_CALL wkeLoadFile(wkeWebView* webView, const wkeChar* html);


WKE_API HWND           WKE_CALL wkeCreateWindow( HWND hParent );
WKE_API EweWindow*     WKE_CALL wkeGetFromWindow( HWND hwnd );
WKE_API wkeWebView*    WKE_CALL wkeGetWebView( EweWindow* wke );

WKE_API void           WKE_CALL wkeLimitPlugins( wkeWebView* webView, bool bTrue );
WKE_API void           WKE_CALL wkeDisableWOFF( bool isDisable );

WKE_API void           WKE_CALL wkePaintDC(wkeWebView* webView, HDC hdc );
WKE_API void           WKE_CALL wkePaint(wkeWebView* webView, void* bits, int pitch);
WKE_API void           WKE_CALL PaintLayeredWindow( HWND targetHwnd, HDC targetHwndDc, HDC bitmapDc );

WKE_API void           WKE_CALL wkeWindowMessageFilter( EweWindow* wke, LRESULT (WKE_CALL *filterProc) ( EweWindow* wke, UINT uMsg,WPARAM wParam,LPARAM lParam ) );
WKE_API void           WKE_CALL wkeWindowOnPaint( EweWindow* wke, bool (WKE_CALL *windowOnPaint) ( wkeWebView* webView, unsigned char* bits, unsigned w, unsigned h, HDC dst ) );
WKE_API void           WKE_CALL wkeOnWindowDestroy( EweWindow* wke, void (WKE_CALL *windowOnDestroy)( EweWindow* wke ) );
WKE_API void           WKE_CALL wkeOnJsCall( wkeWebView* webView,         wkeJSValue   (WKE_CALL *onJsCall) ( wkeJSState* es ) );

WKE_API void           WKE_CALL wkeCallOnMainThreadAndWait( void(WKE_CALL *_callback)(void*), void* context);



// 当 wkeOnReadFile 调用 setData 将文件重定向到 setData里面的数据
WKE_API void           WKE_CALL wkeOnReadFile( void (WKE_CALL *_callback)( void* _caller, const char* szFile,  void (WKE_CALL *setData)( void* _caller, const char* data, unsigned length ) ) );



WKE_API int            WKE_CALL wkeJSToInt(wkeJSState* es, wkeJSValue v);
WKE_API float          WKE_CALL wkeJSToFloat(wkeJSState* es, wkeJSValue v);
WKE_API double         WKE_CALL wkeJSToDouble(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSToBool(wkeJSState* es, wkeJSValue v);
WKE_API const wchar_t* WKE_CALL wkeJSToString(wkeJSState* es, wkeJSValue v);



WKE_API char*          WKE_CALL WkeCharToUtf8String( const wkeChar*  );

WKE_API wkeChar*       WKE_CALL Utf8StringToWkeChar( const char*  );


/*

WKE_API void           WKE_CALL wkeReload(wkeWebView* webView);
WKE_API void           WKE_CALL wkeStopLoading(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGoBack(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGoForward(wkeWebView* webView);

WKE_API int            WKE_CALL wkeGetWidth(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetHeight(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetContentWidth(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetContentHeight(wkeWebView* webView);

WKE_API wkeRect        WKE_CALL wkeGetCaretRect(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeFireMouseEvent(wkeWebView* webView, unsigned int message, int x, int y, unsigned int flags);
WKE_API bool           WKE_CALL wkeFireMouseWheelEvent(wkeWebView* webView, int x, int y, int delta, unsigned int flags);
WKE_API bool           WKE_CALL wkeFireKeyUpEvent(wkeWebView* webView, unsigned int virtualKeyCode, unsigned int flags, bool systemKey);
WKE_API bool           WKE_CALL wkeFireKeyDownEvent(wkeWebView* webView, unsigned int virtualKeyCode, unsigned int flags, bool systemKey);
WKE_API bool           WKE_CALL wkeFireKeyPressEvent(wkeWebView* webView, unsigned int charCode, unsigned int flags, bool systemKey);




//加载状态
typedef enum{
	WKE_STATE_NULL,
    WKE_STATE_LOADING,
    WKE_STATE_LOADING_SUCCEED,
    WKE_STATE_LOADING_FAILED,
    WKE_STATE_DOCUMENT_READY,
} wkeLoadingStatus;

WKE_API wkeLoadingStatus WKE_CALL wkeGetLoadingStatus(wkeWebView* webView);

WKE_API bool           WKE_CALL wkeIsLoadingSucceeded(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeIsLoadingFailed(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeIsLoadingCompleted(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeIsDocumentReady(wkeWebView* webView);


WKE_API void           WKE_CALL wkeSetHostWindow(wkeWebView* webWindow, HWND hostWindow);
WKE_API HWND           WKE_CALL wkeGetHostWindow( wkeWebView* webView );

WKE_API void           WKE_CALL wkeSetZoomFactor(wkeWebView* webView, float factor);
WKE_API float          WKE_CALL wkeGetZoomFactor(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetCookieEnabled(wkeWebView* webView, bool enable);
WKE_API bool           WKE_CALL wkeIsCookieEnabled(wkeWebView* webView);



WKE_API bool           WKE_CALL wkeIsTransparent(wkeWebView* webView);
WKE_API void           WKE_CALL wkeSetTransparent(wkeWebView* webView, bool transparent);

WKE_API void           WKE_CALL wkeSetFocus(wkeWebView* webView);
WKE_API void           WKE_CALL wkeKillFocus(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetMediaVolume(wkeWebView* webView, float volume);
WKE_API float          WKE_CALL wkeGetMediaVolume(wkeWebView* webView);



WKE_API const wchar_t* WKE_CALL wkeGetCookieW(wkeWebView* webView);
WKE_API const wchar_t* WKE_CALL wkeTitleW(wkeWebView* webView);


//执行编辑器命令
//     SelectAll   全选
//     Copy        复制
//     Cut         剪切
//     Paste       粘贴
//     Delete      删除
WKE_API int            WKE_CALL wkeExecCommand(wkeWebView* webView, const wchar_t* command, const wchar_t* args);


////////////////////////////////////////////////////////////////////////////////////////////////////////
// JavaScript 相关接口

typedef struct wkeJSData{
	wkeJSValue (WKE_CALL *propertyGet)(wkeJSState* es, wkeJSValue object, const char* propertyName);
	bool       (WKE_CALL *propertySet)(wkeJSState* es, wkeJSValue object, const char* propertyName, wkeJSValue value);
	wkeJSValue (WKE_CALL *callAsFunction)(wkeJSState* es, wkeJSValue object, wkeJSValue* args, int argCount);
	void       (WKE_CALL *finalize)(wkeJSData* data);
} wkeJSData;


WKE_API wkeJSValue    WKE_CALL wkeJSObject(wkeJSState* es, wkeJSData* obj);
WKE_API wkeJSValue    WKE_CALL wkeJSFunction(wkeJSState* es, wkeJSData* obj);
WKE_API wkeJSData*    WKE_CALL wkeJSGetData(wkeJSState* es, wkeJSValue object);



WKE_API wkeJSState*    WKE_CALL wkeGlobalExec(wkeWebView* webView);
WKE_API wkeJSValue     WKE_CALL wkeRunJS(wkeWebView* webView, const utf8* script);
WKE_API wkeJSValue     WKE_CALL wkeRunJSW(wkeWebView* webView, const wchar_t* script);
WKE_API wkeWebView*    WKE_CALL wkeJSGetWebView(wkeJSState* es);



WKE_API wkeJSType      WKE_CALL wkeJSTypeOf(wkeJSValue v);

WKE_API void           WKE_CALL wkeJSAddRef(wkeJSState* es, wkeJSValue val);
WKE_API void           WKE_CALL wkeJSReleaseRef(wkeJSState* es, wkeJSValue val);

WKE_API bool           WKE_CALL wkeJSIsNumber(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsString(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsBool(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsObject(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsFunction(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsUndefined(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsNull(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsArray(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsTrue(wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsFalse(wkeJSValue v);

WKE_API wkeJSValue     WKE_CALL wkeJSInt(int n);
WKE_API wkeJSValue     WKE_CALL wkeJSFloat(float f);
WKE_API wkeJSValue     WKE_CALL wkeJSDouble(double d);
WKE_API wkeJSValue     WKE_CALL wkeJSTrue();
WKE_API wkeJSValue     WKE_CALL wkeJSFalse();
WKE_API wkeJSValue     WKE_CALL wkeJSBool(bool b);
WKE_API wkeJSValue     WKE_CALL wkeJSNull();
WKE_API wkeJSValue     WKE_CALL wkeJSEmptyArray(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSGlobalObject(wkeJSState* es);  //return the window object
WKE_API wkeJSValue     WKE_CALL wkeJSEval(wkeJSState* es, const utf8* str);
WKE_API wkeJSValue     WKE_CALL wkeJSEvalW(wkeJSState* es, const wchar_t* str);
WKE_API wkeJSValue     WKE_CALL wkeJSCall(wkeJSState* es, wkeJSValue func, wkeJSValue thisObject, wkeJSValue* args, int argCount);
WKE_API wkeJSValue     WKE_CALL wkeJSCallGlobal(wkeJSState* es, wkeJSValue func, wkeJSValue* args, int argCount);
WKE_API wkeJSValue     WKE_CALL wkeJSGet(wkeJSState* es, wkeJSValue object, const char* prop);
WKE_API void           WKE_CALL wkeJSSet(wkeJSState* es, wkeJSValue object, const char* prop, wkeJSValue v);
WKE_API wkeJSValue     WKE_CALL wkeJSGetGlobal(wkeJSState* es, const char* prop);
WKE_API void           WKE_CALL wkeJSSetGlobal(wkeJSState* es, const char* prop, wkeJSValue v);
WKE_API wkeJSValue     WKE_CALL wkeJSGetAt(wkeJSState* es, wkeJSValue object, int index);
WKE_API void           WKE_CALL wkeJSSetAt(wkeJSState* es, wkeJSValue object, int index, wkeJSValue v);
WKE_API int            WKE_CALL wkeJSGetLength(wkeJSState* es, wkeJSValue object);
WKE_API void           WKE_CALL wkeJSSetLength(wkeJSState* es, wkeJSValue object, int length);
WKE_API void           WKE_CALL wkeJSCollectGarbge(); //garbage collect


////////////////////////////////////////////////////////////////////////////////////////////////////////
// 事件回调接口




WKE_API void           WKE_CALL wkeOnTitleChanged( wkeWebView* webView  , void         (WKE_CALL *TitleChangedCallback) ( wkeWebView* eweWebview, const wchar_t* title ) );
WKE_API void           WKE_CALL wkeOnAlertBox( wkeWebView* webView,       void         (WKE_CALL *AlertBoxCallback)( wkeWebView* webView, const wchar_t* msg) );
WKE_API void           WKE_CALL wkeOnURLChanged( wkeWebView* webView,     void         (WKE_CALL *UrlChangedCallback) ( wkeWebView* eweWebview, const wchar_t* url ) );
WKE_API void           WKE_CALL wkeOnConsoleMessage( wkeWebView* webView, void         (WKE_CALL *ConsoleMessageCallback)( wkeWebView* webView, int MsgSoure, int type, int level, WTFString* msgText, int lineNumer, WTFString* url ) );
WKE_API void           WKE_CALL wkeOnNavigation( wkeWebView* webView,     eweNavAction (WKE_CALL *NavigationCallback)( wkeWebView* webView, eweNavigationType navigationType, const wchar_t* url) );
WKE_API void           WKE_CALL wkeOnDocumentReady( wkeWebView* webView,  void         (WKE_CALL *DocumentReadyCallback)( wkeWebView* webView, const wchar_t* url, const wkeJSState* frameJSState, const wkeJSState* mainFrameJSState ) );
WKE_API void           WKE_CALL wkeOnLoadingFinish( wkeWebView* webView,  void         (WKE_CALL *LoadingFinishCallback)( wkeWebView* webView, const wchar_t* url, eweLoadingResult result ) );

WKE_API void           WKE_CALL wkeOnConfirmBox( wkeWebView* webView,     bool         (WKE_CALL *ConfirmBoxCallback)( wkeWebView* webView, const wchar_t* msg) );
WKE_API void           WKE_CALL wkeOnPromptBox( wkeWebView* webView,      bool         (WKE_CALL *PromptBoxCallback)( wkeWebView* webView, const wchar_t* msg, const wchar_t* defaultResult, WTFString* result) );
WKE_API void           WKE_CALL wkeOnDidDownloadCallback( void (WKE_CALL  *callback_)( const wchar_t* url, const char* data, unsigned size ) );

*/


#endif // EWE_V1_H

