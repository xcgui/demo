/*
 * 
 * BlzFans@hotmail.com
 * http://wke.sf.net
 * http://www.github.com/BlzFans/wke
 * licence LGPL
 *
 */

/*

### 目的

 此头文件主要是在 https://www.github.com/cexer/wke 的接口基础上作了调整、优化而来。主要目的是为了统一
 逐渐出现的不同的 wke 实现分支的基础接口。
 
### 原则

 此头文件为这些不同的 wke 实现制定一个基础的接口标准，以实现在这个接口标准之上的二进制兼容。几个原则：

 - 此头文件尽量不包含其它头文件、类型定义，特别是系统相关的头文件、类型定义，避免外部依赖或产生冲突。
 - 接口中若使用到字符串，均使用 wchar_t 字符类型的字符串，同时这在里 wkeChar == wchar_t。
 - 接口定义应该简单、直接，命名完整且含义准确，避免使用“万金油”接口，比如：废除的 wkeConfigure 接口。

### 历史

2016-11-19 22:25 cexer 完成初步定义。

2016-11-19 22:52 cexer 根据群内意见修改：

    - Zero建议 增加 wkeSetHostWindow 的 WebView 的位置偏移参数。
    - Zero建议 增加 wkeOnDownloadFile 回调。
    - Zero建议 去掉 wkeSendNativeMessage、wkePostNativeMessage。
    - Zero建议 去掉脏矩形的接口，这个只需要内部实现使用。
    - 蚂蚁建议 wkeExecCommand 返回值修改为 int。
    - 蚂蚁建议 修改 wkeGetCaretRect 返回方式为参数返回。

2016-11-21 22:41 cexer 根据群内意见修改：

    - Zero建议 增加 wkeFireInternalEvent 接口。
    - Zero建议 去掉 wkeCreateWebWindow 以及其它OSR无关的函数。
    - 大家投票 修改调用约定为 stdcall。
    - Zero建议 增加 wkeSetVisible、wkeIsVisible。

2016-11-22 23:25 cexer 根据群内意见修改：

    - Zero建议 精简获取加载状态的接口，聚合为一个 wkeGetLoadingStatus。
    - 蚂蚁建议 修改 wkeLoadingStatus 的枚举值。

2016-11-23 01:58 cexer 根据群内意见修改：

    - 蚂蚁建议 增加 wkeSetStoragePath 接口，设置用于保存 localStorage、cache file、WebSQL 等文件的根目录。
    - 蚂蚁建议 修改 wkeNavigationCallback 回调的返回值，从而可指定此导航继续、中止或转换为下载。
    - Zero建议 增加回 wkeGetContentWidth、wkeGetContentHeight。
    - cexer建议 统一 FILE_XXXX 回调函数的命名为 wkeFileXxxxCallback
    - cexer建议 删除 wkeJSParamCount 等接口。
    - cexer建议 重命名 wkeJSGetState -> wkeGetJSState、wkeJSExecute -> wkeEvaluateJS、wkeJSEval -> wkeJSEvalute

2016-11-23 10:32 cexer 根据群内意见修改：

	- 蚂蚁建议 增加 WKE_STATIC 宏的判断，以支持静态链接。
	- 蚂蚁建议 调整精简 wkeWebView 等类型定义，不依赖具体实现类型。
	- cexer建议 增加 WKE_API_VERSION 指定基础接口的版本。
    - 群众呼声 改名 wkeJSEvaluate -> wkeJSEval。

### 其它

 加群 178168957 讨论。
 

*/

#ifndef WKE_H
#define WKE_H

//////////////////////////////////////////////////////////////////////////


#if defined(__cplusplus)
#   define WKE_EXTERN_C extern "C"
#else
#   define WKE_EXTERN_C
#endif


#if defined(WKE_BUILD)
#   define WKE_SYMBOL __declspec(dllexport)
#else
#   define WKE_SYMBOL __declspec(dllimport)
#endif


#if !defined(WKE_STATIC)
#   define WKE_API  WKE_EXTERN_C WKE_SYMBOL
#else
#	define WKE_API  WKE_EXTERN_C
#endif



#define WKE_CALL __stdcall

/*
    WKE 的所有实现建议都使用 A.B.C.D 的形式，其中 A 表明了接口版本，即 WKE_API_VERSION 指定的版本。
    这样只要 A 版本号（接口版本号）一致，基于此版本接口的所有实现之间就可无缝替换。
*/
#define WKE_API_VERSION   0


typedef struct 
{
    int x;
    int y;
    int width;
    int height;

} wkeRect;


typedef            wchar_t    wkeChar;
typedef struct    wkeWebView   wkeWebView;
typedef            __int64    wkeJSValue;
typedef struct  __wkeJSState  wkeJSState;
typedef struct  __wkeJSData   wkeJSData;



#if !defined(__cplusplus)
#   ifndef HAVE_BOOL
        typedef unsigned char bool;
#       define true  1
#       define false 0
#   endif

#   ifndef HAVE_WCHAR_T
        typedef unsigned short wchar_t;
#   endif
#endif


/*
 *c interface
 *----------------------------------------------------------------------------------------------------------
 *
 */

#if defined(__cplusplus)
extern "C"
{
#endif


//全局配置
WKE_API void           WKE_CALL wkeInitialize();
WKE_API void           WKE_CALL wkeFinalize();
WKE_API unsigned       WKE_CALL wkeGetVersion();
WKE_API const wkeChar* WKE_CALL wkeGetVersionString();

//全局设置
WKE_API void           WKE_CALL wkeSetProxyServer(const wkeChar* proxy);
WKE_API void           WKE_CALL wkeSetCookieFile(const wkeChar* file);
WKE_API void           WKE_CALL wkeSetStoragePath(const wkeChar* directory);

//内存操作
WKE_API void*          WKE_CALL wkeMalloc(size_t bytes);
WKE_API void           WKE_CALL wkeFree(void* ptr);


//页面创建、销毁
WKE_API wkeWebView*    WKE_CALL wkeCreateWebView();
WKE_API void           WKE_CALL wkeDestroyWebView(wkeWebView* webView);


//页面属性
WKE_API void           WKE_CALL wkeSetHostWindow(wkeWebView* webWindow, void* window, int offsetX, int offsetY);
WKE_API void*          WKE_CALL wkeGetHostWindow(wkeWebView* webWindow);

WKE_API void           WKE_CALL wkeSetUserAgent(wkeWebView* webView, const wkeChar* userAgent);
WKE_API const wkeChar* WKE_CALL wkeGetUserAgent(wkeWebView* webView);

WKE_API void           WKE_CALL wkeResize(wkeWebView* webView, int width, int height);
WKE_API int            WKE_CALL wkeGetWidth(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetHeight(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetContentWidth(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetContentHeight(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetVisible(wkeWebView* webView, bool visible);
WKE_API bool           WKE_CALL wkeIsVisible(wkeWebView* webView);

WKE_API const wkeChar* WKE_CALL wkeGetTitle(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetFocus(wkeWebView* webView);
WKE_API void           WKE_CALL wkeKillFocus(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetZoomFactor(wkeWebView* webView, float factor);
WKE_API float          WKE_CALL wkeGetZoomFactor(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetMediaVolume(wkeWebView* webView, float volume);
WKE_API float          WKE_CALL wkeGetMediaVolume(wkeWebView* webView);

WKE_API const wkeChar* WKE_CALL wkeGetCookie(wkeWebView* webView);
WKE_API void           WKE_CALL wkeSetCookieEnabled(wkeWebView* webView, bool enable);
WKE_API bool           WKE_CALL wkeIsCookieEnabled(wkeWebView* webView);


//加载、浏览相关
WKE_API void           WKE_CALL wkeLoadURL(wkeWebView* webView, const wkeChar* url);
WKE_API void           WKE_CALL wkePostURL(wkeWebView* wkeView,const wkeChar* url, const void* data, int dataBytes);
WKE_API void           WKE_CALL wkeLoadHTML(wkeWebView* webView, const wkeChar* html);

WKE_API bool           WKE_CALL wkeCanGoBack(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGoBack(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeCanGoForward(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGoForward(wkeWebView* webView);

WKE_API void           WKE_CALL wkeStopLoading(wkeWebView* webView);
WKE_API void           WKE_CALL wkeReload(wkeWebView* webView);

//加载状态
typedef enum
{
    WKE_STATE_UNINITIALIZED,    //还未调用wkeLoad函数
    WKE_STATE_LOADING,          //正在加载
    WKE_STATE_LOADING_SUCCEED,  //数据加载成功
    WKE_STATE_LOADING_FAILED,   //数据加载失败
    WKE_STATE_DOCUMENT_READY    //文档已经解析完毕

} wkeLoadingStatus;

WKE_API wkeLoadingStatus WKE_CALL wkeGetLoadingStatus(wkeWebView* webView);


//绘制相关接口
WKE_API bool           WKE_CALL wkeIsTransparent(wkeWebView* webView);
WKE_API void           WKE_CALL wkeSetTransparent(wkeWebView* webView, bool transparent);
WKE_API void           WKE_CALL wkePaint(wkeWebView* webView, void* bits, int pitch);
WKE_API bool           WKE_CALL wkeRepaintIfNeeded(wkeWebView* webView);
WKE_API void*          WKE_CALL wkeGetViewDC(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGetCaretRect(wkeWebView* webView, wkeRect* rect);


//执行编辑器命令
/*
    SelectAll   全选
    Copy        复制
    Cut         剪切
    Paste       粘贴
    Delete      删除
*/
WKE_API int            WKE_CALL wkeExecuteCommand(wkeWebView* webView, const wkeChar* command, const wkeChar* args);


//脚本接口
WKE_API wkeJSState*    WKE_CALL wkeGetJSState(wkeWebView* webView);
WKE_API wkeJSValue     WKE_CALL wkeEvaluateJS(wkeWebView* webView, const wkeChar* code);



//输入输出消息

typedef enum
{
    WKE_LBUTTON = 0x01,
    WKE_RBUTTON = 0x02,
    WKE_SHIFT   = 0x04,
    WKE_CONTROL = 0x08,
    WKE_MBUTTON = 0x10,

} wkeMouseFlags;

typedef enum
{
    WKE_EXTENDED = 0x0100,
    WKE_REPEAT = 0x4000,

} wkeKeyFlags;

typedef enum
{
    WKE_MSG_MOUSEMOVE       =  0x0200,
    WKE_MSG_LBUTTONDOWN     =  0x0201,
    WKE_MSG_LBUTTONUP       =  0x0202,
    WKE_MSG_LBUTTONDBLCLK   =  0x0203,
    WKE_MSG_RBUTTONDOWN     =  0x0204,
    WKE_MSG_RBUTTONUP       =  0x0205,
    WKE_MSG_RBUTTONDBLCLK   =  0x0206,
    WKE_MSG_MBUTTONDOWN     =  0x0207,
    WKE_MSG_MBUTTONUP       =  0x0208,
    WKE_MSG_MBUTTONDBLCLK   =  0x0209,
    WKE_MSG_MOUSEWHEEL      =  0x020A,

} wkeMouseMessage;

WKE_API bool           WKE_CALL wkeFireMouseEvent(wkeWebView* webView, wkeMouseMessage message, int x, int y, unsigned flags);
WKE_API bool           WKE_CALL wkeFireContextMenuEvent(wkeWebView* webView, int x, int y, unsigned flags);
WKE_API bool           WKE_CALL wkeFireMouseWheelEvent(wkeWebView* webView, int x, int y, int delta, unsigned flags);
WKE_API bool           WKE_CALL wkeFireKeyUpEvent(wkeWebView* webView, unsigned virtualKeyCode, unsigned flags, bool systemKey);
WKE_API bool           WKE_CALL wkeFireKeyDownEvent(wkeWebView* webView, unsigned virtualKeyCode, unsigned flags, bool systemKey);
WKE_API bool           WKE_CALL wkeFireKeyPressEvent(wkeWebView* webView, unsigned charCode, unsigned flags, bool systemKey);
WKE_API void*          WKE_CALL wkeFireInternalEvent(wkeWebView* webView, unsigned message, void* lparam, void* wparam);

//页面标题改变回调
WKE_API void           WKE_CALL wkeOnTitleChanged(wkeWebView* webView, void (WKE_CALL *TitleChangedCallback)(wkeWebView* webView, const wkeChar* title));

//页面URL改变回调
WKE_API void           WKE_CALL wkeOnURLChanged(wkeWebView* webView, void (WKE_CALL *UrlChangedCallback)(wkeWebView* webView, const wkeChar* url));

//页面绘制已更新回调
WKE_API void           WKE_CALL wkeOnPaintUpdated(wkeWebView* webView, void (WKE_CALL *wkePaintUpdatedCallback)(wkeWebView* webView, const void* hdc, int x, int y, int cx, int cy));

//alert实现回调
WKE_API void           WKE_CALL wkeOnAlertBox(wkeWebView* webView, void (WKE_CALL *AlertBoxCallback)(wkeWebView* webView, const wkeChar* message));

//confirm实现回调
WKE_API void           WKE_CALL wkeOnConfirmBox(wkeWebView* webView, bool (WKE_CALL *wkeConfirmBoxCallback)(wkeWebView* webView, const wkeChar* message));

//prompt实现回调，返回的字符串必须使用 wkeMalloc 分配内存
WKE_API void WKE_CALL wkeOnPromptBox( wkeWebView* webView, bool (WKE_CALL *PromptBoxCallback)( wkeWebView* webView, const wchar_t* msg, const wchar_t* defaultResult, WTFString* result) );

//下载回调
WKE_API void           WKE_CALL wkeOnDownloadFile(wkeWebView* webView, bool (WKE_CALL *wkeDownloadFileCallback)(wkeWebView* webView, const wkeChar* url, const wkeChar* mimeType));

//控制台消息实现回调
typedef enum 
{
    WKE_MESSAGE_SOURCE_HTML,
    WKE_MESSAGE_SOURCE_XML,
    WKE_MESSAGE_SOURCE_JS,
    WKE_MESSAGE_SOURCE_NETWORK,
    WKE_MESSAGE_SOURCE_CONSOLE_API,
    WKE_MESSAGE_SOURCE_OTHER

} wkeMessageSource;

typedef enum 
{
    WKE_MESSAGE_TYPE_LOG,
    WKE_MESSAGE_TYPE_DIR,
    WKE_MESSAGE_TYPE_DIR_XML,
    WKE_MESSAGE_TYPE_TRACE,
    WKE_MESSAGE_TYPE_START_GROUP,
    WKE_MESSAGE_TYPE_START_GROUP_COLLAPSED,
    WKE_MESSAGE_TYPE_END_GROUP,
    WKE_MESSAGE_TYPE_ASSERT

} wkeMessageType;

typedef enum 
{
    WKE_MESSAGE_LEVEL_TIP,
    WKE_MESSAGE_LEVEL_LOG,
    WKE_MESSAGE_LEVEL_WARNING,
    WKE_MESSAGE_LEVEL_ERROR,
    WKE_MESSAGE_LEVEL_DEBUG

} wkeMessageLevel;

typedef struct
{
    wkeMessageSource source;
    wkeMessageType type;
    wkeMessageLevel level;
    const wkeChar* message;
    const wkeChar* url;
    unsigned lineNumber;

} wkeConsoleMessage;


WKE_API void           WKE_CALL wkeOnConsoleMessage(wkeWebView* webView,  void (WKE_CALL *ConsoleMessageCallback)(wkeWebView* webView, const wkeConsoleMessage* message) );


//页面内发生导航回调
typedef enum
{
    WKE_NAVIGATION_TYPE_LINKCLICK,
    WKE_NAVIGATION_TYPE_FORMSUBMITTE,
    WKE_NAVIGATION_TYPE_BACKFORWARD,
    WKE_NAVIGATION_TYPE_RELOAD,
    WKE_NAVIGATION_TYPE_FORMRESUBMITT,
    WKE_NAVIGATION_TYPE_OTHER

} wkeNavigationType;

//指定导航实际动作
typedef enum
{
    WKE_NAVIGATION_CONTINUE, //继续此导航
    WKE_NAVIGATION_ABORT,    //中止此导航
    WKE_NAVIGATION_DOWNLOAD  //此导航强制转换为下载，将会触发 wkeOnDownloadFile 回调

} wkeNavigationAction;

typedef wkeNavigationAction (WKE_CALL *wkeNavigationCallback)(wkeWebView* webView, wkeNavigationType navigationType, const wkeChar* url);
WKE_API void           WKE_CALL wkeOnNavigation(wkeWebView* webView, wkeNavigationCallback callback);


//页面内新建页面窗口回调
typedef struct  
{
    wkeNavigationType navigationType;
    const wkeChar* url;
    const wkeChar* target;

    wkeRect rectangle;

    bool menuBarVisible;
    bool statusBarVisible;
    bool toolBarVisible;
    bool locationBarVisible;
    bool scrollbarsVisible;
    bool resizable;
    bool fullscreen;

} wkeNewViewInfo;


//页面文档解析完成回调
typedef struct
{
    const wkeChar* url;
    wkeJSState* frameJSState;
    wkeJSState* mainFrameJSState;

} wkeDocumentReadyInfo;


WKE_API void           WKE_CALL wkeOnDocumentReady(wkeWebView* webView, void (WKE_CALL *DocumentReadyCallback)(wkeWebView* webView, const wkeDocumentReadyInfo* info) );


//页面数据下载结束（成功或失败）回调
WKE_API void           WKE_CALL wkeOnLoadingFinish(wkeWebView* webView, void (WKE_CALL *LoadingFinishCallback)(wkeWebView* webView, const wkeChar* url, bool failed, const wkeChar* failedReason) );


//JS变量类型
typedef enum
{
	WKE_JSTYPE_NUMBER,
	WKE_JSTYPE_STRING,
	WKE_JSTYPE_BOOLEAN,
	WKE_JSTYPE_OBJECT,
	WKE_JSTYPE_FUNCTION,
	WKE_JSTYPE_UNDEFINED,

} wkeJSType;

WKE_API wkeJSType      WKE_CALL wkeJSTypeOf(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsNumber(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsString(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsBool(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsObject(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsFunction(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsUndefined(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsNull(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsArray(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsTrue(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsFalse(wkeJSState* es, wkeJSValue v);

//获取JS变量值
WKE_API int            WKE_CALL wkeJSToInt(wkeJSState* es, wkeJSValue v);
WKE_API float          WKE_CALL wkeJSToFloat(wkeJSState* es, wkeJSValue v);
WKE_API double         WKE_CALL wkeJSToDouble(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSToBool(wkeJSState* es, wkeJSValue v);
WKE_API const wkeChar* WKE_CALL wkeJSToTempString(wkeJSState* es, wkeJSValue v);

//创建JS基础变量
WKE_API wkeJSValue     WKE_CALL wkeJSInt(wkeJSState* es, int n);
WKE_API wkeJSValue     WKE_CALL wkeJSFloat(wkeJSState* es, float f);
WKE_API wkeJSValue     WKE_CALL wkeJSDouble(wkeJSState* es, double d);
WKE_API wkeJSValue     WKE_CALL wkeJSBool(wkeJSState* es, bool b);
WKE_API wkeJSValue     WKE_CALL wkeJSUndefined(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSNull(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSTrue(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSFalse(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSString(wkeJSState* es, const wkeChar* str);
WKE_API wkeJSValue     WKE_CALL wkeJSEmptyObject(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSEmptyArray(wkeJSState* es);

//绑定JS对象、函数
typedef wkeJSValue    (WKE_CALL *wkeJSGetPropertyCallback)(wkeJSState* es, wkeJSValue object, const wkeChar* prop );
typedef bool          (WKE_CALL *wkeJSSetPropertyCallback)(wkeJSState* es, wkeJSValue object, const wkeChar* prop, wkeJSValue value );
typedef wkeJSValue    (WKE_CALL *wkeJSCallAsFunctionCallback)(wkeJSState* es, wkeJSValue object, wkeJSValue* args, int argCount);
typedef void          (WKE_CALL *wkeJSFinalizeCallback)(wkeJSData* data );


typedef struct __wkeJSData
{
	wkeJSGetPropertyCallback propertyGet;
	wkeJSSetPropertyCallback propertySet;
	wkeJSFinalizeCallback finalize;
	wkeJSCallAsFunctionCallback callAsFunction;
	void* userdata;
} wkeJSData;


WKE_API wkeJSValue     WKE_CALL wkeJSObject(wkeJSState* es, wkeJSData* data );
WKE_API wkeJSValue     WKE_CALL wkeJSFunction(wkeJSState* es, wkeJSData* data );
WKE_API wkeJSData*     WKE_CALL wkeJSGetData(wkeJSState* es, wkeJSValue object);

//WebView关联操作
WKE_API wkeWebView*    WKE_CALL wkeJSGetWebView(wkeJSState* es);

//直接执行JS代码
WKE_API wkeJSValue     WKE_CALL wkeJSEval(wkeJSState* es, const wkeChar* code);

//JS对象操作
WKE_API wkeJSValue     WKE_CALL wkeJSCall(wkeJSState* es, wkeJSValue object, wkeJSValue func, const wkeJSValue* args, int argCount);
WKE_API wkeJSValue     WKE_CALL wkeJSGet(wkeJSState* es, wkeJSValue object, const wkeChar* prop);
WKE_API void           WKE_CALL wkeJSSet(wkeJSState* es, wkeJSValue object, const wkeChar* prop, wkeJSValue value);
WKE_API wkeJSValue     WKE_CALL wkeJSGetAt(wkeJSState* es, wkeJSValue object, int index);
WKE_API void           WKE_CALL wkeJSSetAt(wkeJSState* es, wkeJSValue object, int index, wkeJSValue value);
WKE_API int            WKE_CALL wkeJSGetLength(wkeJSState* es, wkeJSValue object);
WKE_API void           WKE_CALL wkeJSSetLength(wkeJSState* es, wkeJSValue object, int length);

WKE_API wkeJSValue     WKE_CALL wkeJSGlobalObject(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSCallGlobal(wkeJSState* es, wkeJSValue func, wkeJSValue* args, int argCount);
WKE_API wkeJSValue     WKE_CALL wkeJSGetGlobal(wkeJSState* es, const wkeChar* prop);
WKE_API void           WKE_CALL wkeJSSetGlobal(wkeJSState* es, const wkeChar* prop, wkeJSValue value);

//JS垃圾收集相关
WKE_API void           WKE_CALL  wkeJSAddRef(wkeJSState* es, wkeJSValue v);
WKE_API void           WKE_CALL  wkeJSReleaseRef(wkeJSState* es, wkeJSValue v);
WKE_API void           WKE_CALL  wkeJSCollectGarbge(); 




#ifdef __cplusplus
}
#endif


#endif//#ifndef WKE_H
