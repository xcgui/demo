#include "Common.h"
#include "XWeb.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{

 	wkeWebView* pView = wkeCreateWebView();
	wkeJSState* pState = wkeGlobalExec(pView);
	wkeJSValue  jsValue = wkeRunJS(pView,"1+2");
	const wchar_t* ptext = wkeJSToStringW(pState,jsValue);
	MessageBoxW(NULL,ptext,L"jsValue",MB_OK);
	wkeDestroyWebView(pView);
    return 0;
}
