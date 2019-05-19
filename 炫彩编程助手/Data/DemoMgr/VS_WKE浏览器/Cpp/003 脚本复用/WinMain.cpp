#include "Common.h"
#include "XWeb.h"

XC xc;

const wchar_t* DoJs(wkeWebView* webView,const char* js)
{
	wkeJSValue  jsValue = wkeRunJS(webView,js);
	wkeJSState* pState = wkeGlobalExec(webView);
	const wchar_t* ptext = wkeJSToStringW(pState,jsValue);
	return ptext;
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
 	wkeWebView* pView = wkeCreateWebView();
	std::string MD5jsCode;
	xc.ReadTextFile("hmac-md5.js",MD5jsCode);
	DoJs(pView,MD5jsCode.c_str());
	const wchar_t* pResult = DoJs(pView,"CryptoJS.MD5('dasemimi').toString(CryptoJS.enc.Hex);");
	MessageBoxW(NULL,pResult,L"jsValue",MB_OK);
	wkeDestroyWebView(pView);
    return 0;
}
