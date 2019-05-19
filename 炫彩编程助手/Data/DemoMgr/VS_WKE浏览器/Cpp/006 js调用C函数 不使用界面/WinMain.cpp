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


wkeJSValue __fastcall js_uubox(wkeJSState* es)
{
	wchar_t buffer[1024] = {0};
	wcscat(buffer,L"参数1: ");
	wcscat(buffer,wkeJSToStringW(es,wkeJSParam(es,0)));
	wcscat(buffer,L",参数2: ");
	wcscat(buffer,wkeJSToStringW(es,wkeJSParam(es,1)));
	MessageBoxW(NULL,buffer,L"调用成功",MB_OK);
	return wkeJSInt(10);
	//	return wkeJSUndefined();
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
 	wkeWebView* pView = wkeCreateWebView();

	wkeJSBindFunction("uubox",js_uubox,2);
	const wchar_t* pResult = DoJs(pView,"uubox('Param1','Param2')");

	MessageBoxW(NULL,pResult,L"调用Js返回的结果",MB_OK);
	wkeDestroyWebView(pView);
    return 0;
}
