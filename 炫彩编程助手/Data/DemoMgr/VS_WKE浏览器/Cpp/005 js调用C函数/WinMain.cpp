#include "Common.h"
#include "XWeb.h"
#include "XWeb.cpp"


const wchar_t* g_wHtml = L"<html><head></head><body style='font-size:16px;'>"
L"输入网址: &nbsp<input id=myurl style='width:400px;' value='http://www.4399.com/flash/112689_3.htm'><button onclick=\"document.location=document.getElementById('myurl').value;\">GO</button><hr />"
L"<a href='http://www.taobao.com/'>淘宝</a><br />"
L"<a href='http://www.youku.com/'>优酷</a><br />"

L"<a href='http://www.youzu.com/'>游族</a><br />"

L"<a href='http://www.baidu.com/'>百度</a><br />"
L"<a href='http://map.baidu.com/'>百度地图</a><br />"
L"<a href='http://www.le.com/'>乐视</a><br />"
L"<a href='http://download.csdn.net/'>CSDN</a><br />"


L"<a href='http://www.yvoschaap.com/chainrxn/'>2D测试</a><br />"
L"<a href='https://www.benjoffe.com/code/demos/canvascape/textures'>3D测试</a><br />"

L"<a href='http://www.jz5u.com/soft/softdown.asp?softid=18109'>下载测试</a><br />"


L"<a href='http://workerman.net:8383/'>蝌蚪聊天室</a><br />"
L"<a href='http://chat.workerman.net/'>Websocket聊天室</a><br />"
L"<a href='http://www.workerman.net/demos/browserquest/'>Websocket在线游戏</a><br />"

L"</body></html>";

void BindEleToBody(HWINDOW hWindow, HELE hEle);



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

class XWebWnd
{
public:
	BOOL Create()
	{
		m_hWindow = XWnd_Create(0,0,500,300,L"炫彩浏览器");
		if (!m_hWindow)
			return FALSE;

		HELE hBtn = XBtn_Create(8,5,100,20,L"js调用C函数",m_hWindow);
		XEle_RegEventCPP(hBtn,XE_BNCLICK,&XWebWnd::OnBtnClick);

		m_hWeb = XWeb_Create(8,30,400,300,m_hWindow);
		BindEleToBody(m_hWindow,m_hWeb);

		wkeWebView* pWebView = XWeb_GetWebView(m_hWeb);
		wkeLoadHTMLW(pWebView,g_wHtml);
		

		wkeJSBindFunction("uubox",js_uubox,2);

		XWnd_AdjustLayout(m_hWindow);
		XWnd_ShowWindow(m_hWindow,SW_SHOW);//显示窗口	
		return TRUE;
	}
	int OnBtnClick(BOOL *pbHandled)
	{
		wkeWebView* pWebView = XWeb_GetWebView(m_hWeb);
		wkeJSState* pState = wkeGlobalExec(pWebView);
		wkeJSValue  jsValue = wkeRunJS(pWebView,"uubox('Param1','Param2')");

		MessageBoxW(NULL,wkeJSToStringW(pState,jsValue),L"返回结果",MB_OK);

		return 0;
	}

private:
	HWINDOW m_hWindow;
	HELE    m_hWeb;
};

void BindEleToBody(HWINDOW hWindow, HELE hEle)
{
	
	HXCGUI hLayoutBody = XLayout_Create();
	XWnd_BindLayoutObject(hWindow,window_position_body,hLayoutBody);
	XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
	XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);
	
	XLayout_AddEle(hLayoutBody,hEle);
	XEle_SetLayoutHeight(hEle,layout_size_type_fill,1);
	XEle_SetLayoutWidth(hEle,layout_size_type_fill,1);
}


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
	wkeDisableWOFF( false );

	XWebWnd Web;
	if (Web.Create())
		XRunXCGUI(); //运行

    XExitXCGUI(); //释放资源
    return 0;
}



