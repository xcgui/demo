#include "Common.h"
#include "wkeBrowser.h"
#pragma comment(lib,"wkeBrowser.lib")


#ifndef WKE_CALL
#define WKE_CALL _cdecl
#endif


__int64 __fastcall js_msgbox(void* es)
{
	wchar_t buffer[1024] = {0};
	wcscat(buffer,L"参数1: ");
	wcscat(buffer,XWeb_JsToTempStringW(es,XWeb_JsArg(es,0)));
	wcscat(buffer,L",参数2: ");
	wcscat(buffer,XWeb_JsToTempStringW(es,XWeb_JsArg(es,1)));
	MessageBoxW(NULL,buffer,L"调用成功",MB_OK);
	return XWeb_JsUndefined();
}

void WKE_CALL onURLChanged(void* webView, void* param, void* url);
void WKE_CALL onTitleChanged(void* webView, void* param, void* title);
void WKE_CALL onDocumentReadyCallback(wkeWebView webView, void* param, const wkeDocumentReadyInfo* info);
void WKE_CALL onLoadingFinishCallback(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason);
wkeWebView WKE_CALL onCreateViewCallback(wkeWebView webView, void* param, const wkeNewViewInfo* info);






class CMyWnd
{
public:
	HWINDOW m_hWindow; //窗口句柄
	HELE    m_hButton; //按钮句柄
	HELE m_hWeb;
	HELE  m_hEditUrl;
	HELE  m_hMenuBar;
	HXCGUI m_hShapText;

	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		if (wParam == VK_RETURN)
		{
			wchar_t url[1024] ={0};
			XRichEdit_GetText(m_hEditUrl,url,1024);
			XWeb_LoadUrl(m_hWeb,url);
		}
		return 0;
	}
	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
	//	SetFocus(XWnd_GetHWND(m_hWindow));
		//		SendMessage(XWnd_GetHWND(m_hWindow),WM_KILLFOCUS,0,0);
		//		XWnd_SetFocusEle(m_hWindow,m_hEditUrl);
		return 0;
	}
	int OnWndDrawWindow(HDRAW hDraw,BOOL *pbHandled)
	{
		XEle_RedrawEle(m_hWeb);
		return 0;
	}
	BOOL Create() //创建窗口和按钮
	{
		m_hWindow = (HWINDOW) XC_LoadLayout(L"xml\\Layout.xml");
		if (!m_hWindow)
		{
			return FALSE;
		}
		XWnd_RegEventCPP(m_hWindow,WM_PAINT,&CMyWnd::OnWndDrawWindow);

		m_hEditUrl = (HELE)XC_GetObjectByID(m_hWindow,10);
		XEle_RegEventCPP(m_hEditUrl,XE_CHAR,&CMyWnd::OnEventChar);

		XEle_RegEventCPP(m_hEditUrl,XE_LBUTTONDOWN,&CMyWnd::OnLButtonDown);

		m_hShapText = XC_GetObjectByID(m_hWindow,21);


		m_hMenuBar = (HELE)XC_GetObjectByID(m_hWindow,11);
		XMenuBar_AddButton(m_hMenuBar,L"更多");
		HMENUX hMenu=XMenuBar_GetMenu(m_hMenuBar,0);
		if (hMenu)
		{
			XMenu_AddItem(hMenu,100,L"前进");
			XMenu_AddItem(hMenu,101,L"后退");
			XMenu_AddItem(hMenu,102,L"主页");
			XMenu_AddItem(hMenu,103,L"重新载入");
			XMenu_AddItem(hMenu,104,L"停止载入");
			XMenu_AddItem(hMenu,105,L"代理加载谷歌");
			XMenu_AddItem(hMenu,106,L"放大");
			XMenu_AddItem(hMenu,107,L"缩小");
			XMenu_AddItem(hMenu,108,L"恢复缩放");
			XMenu_AddItem(hMenu,109,L"获取Cookie");
			XMenu_AddItem(hMenu,110,L"js调用vc函数");
			XMenu_AddItem(hMenu,111,L"设置网页可编辑");
			XMenu_AddItem(hMenu,112,L"设置网页不可编辑");
			XMenu_AddItem(hMenu,113,L"执行js脚本");
			XMenu_AddItem(hMenu,114,L"取浏览器状态");
			XMenu_AddItem(hMenu,115,L"取浏览器版本");
			XMenu_AddItem(hMenu,116,L"调用网页对象取文本");
			XMenu_AddItem(hMenu,117,L"js模拟填表");
			XMenu_AddItem(hMenu,118,L"显示/隐藏浏览器");

		}

		RECT rtBody;
		XWnd_GetBodyRect(m_hWindow,&rtBody);
		m_hWeb = (HELE)XWeb_Create(rtBody.left,rtBody.top,rtBody.right-rtBody.left,rtBody.bottom - rtBody.top,m_hWindow);
		XWeb_LoadUrl(m_hWeb,L"http://www.xcgui.com");


 //		XWnd_EnableDrawBk(m_hWindow,FALSE);
 		XWnd_SetTransparentAlpha(m_hWindow,200);
 		XWnd_SetTransparentType(m_hWindow,window_transparent_shaped);


		XWeb_JsBindFuction("msgbox",js_msgbox,2);

		XWeb_OnURLChanged(m_hWeb,(void*)&onURLChanged,this);
		XWeb_OnTitleChanged(m_hWeb,(void*)&onTitleChanged,this);

		XWeb_OnDocumentReady(m_hWeb,onDocumentReadyCallback,NULL);
		XWeb_OnLoadingFinish(m_hWeb,onLoadingFinishCallback,NULL);
		XWeb_OnCreateView(m_hWeb,onCreateViewCallback,m_hWindow);


		XEle_RegEventCPP(m_hMenuBar,XE_MENU_SELECT,&CMyWnd::OnWndMenuSelect);

		XWnd_RegEventCPP(m_hWindow,WM_SIZE,&CMyWnd::OnWndSize);
		XWnd_AdjustLayout(m_hWindow);
		XWnd_ShowWindow(m_hWindow,SW_SHOW);
		return TRUE;
	}
	int OnWndSize(UINT nFlags,SIZE *pSize,BOOL *pbHandled)
	{
		RECT rtBody;
		XWnd_GetBodyRect(m_hWindow,&rtBody);
		XEle_SetRectEx(m_hWeb,
			rtBody.left,
			rtBody.top,
			rtBody.right - rtBody.left,
			rtBody.bottom - rtBody.top);
//		XEle_RedrawEle(m_hWeb);
		return 0;
	}
	int OnWndMenuSelect(int nID,BOOL *pbHandled)
	{
		switch (nID)
		{
		case 100:
			{
				if (XWeb_CanGoBack(m_hWeb))
				{
					XWeb_GoForward(m_hWeb);
				}
			}
			break;
		case 101:
			{
				if (XWeb_CanGoForward(m_hWeb))
				{
					XWeb_GoBack(m_hWeb);
				}
			}
			break;
		case 102:
			XWeb_LoadUrl(m_hWeb,L"http://www.xcgui.com");
			break;
		case 103:
			XWeb_Reload(m_hWeb);
			break;
		case 104:
			XWeb_StopLoading(m_hWeb);
			break;
		case 105:
			XWeb_SetProxy(m_hWeb); //前提是你要有本地的socket 5 的代理。。。不然没用
			XWeb_LoadUrl(m_hWeb,L"http://www.google.com");
			break;
		case 106:
			{
				float zom = XWeb_GetZoom(m_hWeb);
				zom+=0.3f;
				XWeb_Zoom(m_hWeb,zom);
			}
			break;
		case 107:
			{
				float zom = XWeb_GetZoom(m_hWeb);
				zom-=0.3f;
				XWeb_Zoom(m_hWeb,zom);
			}
			break;
		case 108:
			XWeb_ZoomReset(m_hWeb);
			break;
		case 109:
			{
				const wchar_t* pCookie = XWeb_GetCookie(m_hWeb);
				MessageBoxW(NULL,pCookie,L"浏览器cookie",MB_OK);
			}
			break;
		case 110:
			XWeb_LoadUrl(m_hWeb,L"file://./jsCallFunction.html");
			break;
		case 111:
			XWeb_SetEditable(m_hWeb,true);
			break;
		case 112:
			XWeb_SetEditable(m_hWeb,false);
			break;
		case 113:
			XWeb_RunJs(m_hWeb,L"javascript: alert('炫彩界面库');");
			break;
		case 114:
			{
				if (XWeb_IsDocumentReady(m_hWeb))
				{
					SetStat(L"网页准备完毕!");
				}else if (XWeb_IsLoadingCompleted(m_hWeb))
				{
					SetStat(L"网页加载完成!");
				}else if (XWeb_IsLoadingFailed(m_hWeb))
				{
					SetStat(L"加载网页失败!");
				}
			}

			break;
		case 115:
			MessageBoxA(NULL,XWeb_GetVersionString(),"版本",MB_OK);
			break;
		case 116:
			{
				void* es = XWeb_GlobalExec(m_hWeb);
				__int64 document = XWeb_JsGet(es,XWeb_JsGlobalObject(es),"document");
				__int64 body = XWeb_JsGet(es,document,"body");

				__int64 jsvalue = XWeb_JsGet(es,body,"innerText");

				MessageBoxW(NULL,XWeb_JsToTempStringW(es,jsvalue),L"网页源码",MB_OK);

			}
			break;
		case 117:
			{
				XWeb_RunJs(m_hWeb,L"javascript: \
								   document.getElementById('kw').value='炫彩界面库';\
								   document.getElementById('su').click(); ");
			}
			break;
		case 118:
			{
				XEle_ShowEle(m_hWeb,!XEle_IsShow(m_hWeb));
				XWnd_RedrawWnd(m_hWindow,TRUE);
			}
			break;
		}

		return 0;
	}
	int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
	{
		//弹出消息框
		MessageBoxW(XWnd_GetHWND(m_hWindow),L"你点击了按钮",L"提示",MB_OK);
		*pBool=TRUE; //对该事件进行拦截
		return 0;    //事件的返回值
	}
public:

	void SetUrl(const wchar_t* pURL)
	{
		XRichEdit_SetText(m_hEditUrl,pURL);
	}

	void SetStat(const wchar_t* pStat)
	{
		XShapeText_SetText(m_hShapText,pStat);
		XWnd_RedrawWnd(m_hWindow);
	}

};

void WKE_CALL onDocumentReadyCallback(wkeWebView webView, void* param, const wkeDocumentReadyInfo* info)
{
	OutputDebugStringW(XWeb_GetStringW(info->url) );
}
void WKE_CALL onLoadingFinishCallback(wkeWebView webView, void* param, const wkeString url, wkeLoadingResult result, const wkeString failedReason)
{
OutputDebugStringW(XWeb_GetStringW(url) );
}
wkeWebView WKE_CALL onCreateViewCallback(wkeWebView webView, void* param, const wkeNewViewInfo* info)
{
//	return 0;
// 	特殊的目标
// 		有 4 个保留的目标名称用作特殊的文档重定向操作：
// 		_blank
// 		浏览器总在一个新打开、未命名的窗口中载入目标文档。
// 		_self
// 		这个目标的值对所有没有指定目标的 <a> 标签是默认目标，它使得目标文档载入并显示在相同的框架或者窗口中作为源文档。这个目标是多余且不必要的，除非和文档标题 <base> 标签中的 target 属性一起使用。
	// 		_parent
	// 		这个目标使得文档载入父窗口或者包含来超链接引用的框架的框架集。如果这个引用是在窗口或者在顶级框架中，那么它与目标 _self 等效。
	// 		_top
	// 		这个目标使得文档载入包含这个超链接的窗口，用 _top 目标将会清除所有被包含的框架并将文档载入整个浏览器窗口。
	const wchar_t* target = XWeb_GetStringW(info->target);
	OutputDebugStringW(target);
	OutputDebugStringW(L"\r\n");
	if (wcscmp(target,L"_self") == 0)
	{
		return webView;
	}else if (wcscmp(target, L"") == 0 || wcscmp(target, L"_blank") == 0)
	{
		HWINDOW hPopWindow = XWnd_Create(0,0,300,500,NULL,XWnd_GetHWND((HWINDOW)param));
 		void* hWeb = XWeb_Create(0,0,300,500,hPopWindow);
 		XWeb_LoadUrl(hWeb,XWeb_GetStringW(info->url));
//		XWeb_LoadUrl(hWeb,L"about:blank");
		
		//	const wchar_t* url = XWeb_GetStringW(info->url);
		//	OutputDebugStringW(L"\r\n");
		//	OutputDebugStringW(target);
		//	OutputDebugStringW(url);
		//	OutputDebugStringW(L"\r\n");
		XWnd_ShowWindow(hPopWindow,SW_SHOW);
//		return 0;
		return (wkeWebView)XWeb_GetWebView(hWeb);
	}
	

	return 0;
}


void WKE_CALL onURLChanged(void* webView, void* param, void* url)
{
	CMyWnd* pWnd =(CMyWnd*)param;
	pWnd->SetUrl(XWeb_GetStringW(url));
}

void WKE_CALL onTitleChanged(void* webView, void* param, void* title)
{
	CMyWnd* pWnd =(CMyWnd*)param;
 	pWnd->SetStat(XWeb_GetStringW(title));
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
	XWeb_Init();
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
	XWeb_UnInit();
    XExitXCGUI(); //释放资源
    return 0;
}




