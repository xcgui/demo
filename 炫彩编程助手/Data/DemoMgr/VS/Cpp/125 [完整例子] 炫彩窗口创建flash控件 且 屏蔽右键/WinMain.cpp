// LoadFlash.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "WinMain.h"

//调用界面库

//#include <afx.h>

#include <atlbase.h>
extern CComModule _Module;
#include <atlwin.h>

#include <comdef.h>
#include "flash32_11_7_700_224.tlh"
#include <string>
using namespace std;
using namespace ShockwaveFlashObjects;
CComModule _Module;
CComPtr<IShockwaveFlash> m_flash = NULL;

#if _MSC_VER == 1200  // MS VC++6.0 _MSC_VER=1200 vc6
#pragma comment(lib, "atl.lib") 
#endif
#include "Common.h"

#define MAX_LOADSTRING 100

class FlashSink : public ShockwaveFlashObjects::_IShockwaveFlashEvents
{
public:
	LPCONNECTIONPOINT       m_ConnectionPoint;
	DWORD                   m_dwCookie;
	int                     m_nRefCount;

public:
	FlashSink()
	{
		m_dwCookie = 0;
		m_ConnectionPoint = NULL;
		m_nRefCount = 0;
	}

	virtual ~FlashSink()
	{
	}

	HRESULT Init(CComPtr<IShockwaveFlash> ptrFlash)
	{
		HRESULT aResult = NOERROR;
		LPCONNECTIONPOINTCONTAINER aConnectionPoint = NULL;
		if ((ptrFlash->QueryInterface(IID_IConnectionPointContainer, (void**)&aConnectionPoint) == S_OK) &&
			(aConnectionPoint->FindConnectionPoint(__uuidof(ShockwaveFlashObjects::_IShockwaveFlashEvents), &m_ConnectionPoint) == S_OK))
		{
			IDispatch* aDispatch = NULL;
			QueryInterface(__uuidof(IDispatch), (void**)&aDispatch);
			if (aDispatch != NULL)
			{
				aResult = m_ConnectionPoint->Advise((LPUNKNOWN)aDispatch, &m_dwCookie);
				aDispatch->Release();
			}
		}
		if (aConnectionPoint != NULL)
			aConnectionPoint->Release();

		return aResult;
	}

	HRESULT Shutdown()
	{
		HRESULT aResult = S_OK;

		if (m_ConnectionPoint)
		{
			if (m_dwCookie)
			{
				aResult = m_ConnectionPoint->Unadvise(m_dwCookie);
				m_dwCookie = 0;
			}

			m_ConnectionPoint->Release();
			m_ConnectionPoint = NULL;
		}

		return aResult;
	}

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID* ppv)
	{
		*ppv = NULL;

		if (riid == IID_IUnknown)
		{
			*ppv = (LPUNKNOWN)this;
			AddRef();
			return S_OK;
		}
		else if (riid == IID_IDispatch)
		{
			*ppv = (IDispatch*)this;
			AddRef();
			return S_OK;
		}
		else if (riid == __uuidof(ShockwaveFlashObjects::_IShockwaveFlashEvents))
		{
			*ppv = (ShockwaveFlashObjects::_IShockwaveFlashEvents*) this;
			AddRef();
			return S_OK;
		}
		else
		{
			return E_NOTIMPL;
		}
	}

	ULONG STDMETHODCALLTYPE AddRef()
	{
		return ++m_nRefCount;
	}

	ULONG STDMETHODCALLTYPE Release()
	{
		int aRefCount = --m_nRefCount;
		if (aRefCount == 0)
			delete this;

		return aRefCount;
	}

	// IDispatch method
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT* pctinfo)
	{
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
	{
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames,
		UINT cNames, LCID lcid, DISPID* rgDispId)
	{
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
		WORD wFlags, ::DISPPARAMS __RPC_FAR *pDispParams, VARIANT __RPC_FAR *pVarResult,
		::EXCEPINFO __RPC_FAR *pExcepInfo, UINT __RPC_FAR *puArgErr)
	{
		switch (dispIdMember)
		{
		case 0x7a6:
			break;
		case 150:
			break;
		case DISPID_READYSTATECHANGE:
			break;
		default:
			return DISP_E_MEMBERNOTFOUND;
		}

		return NOERROR;
	}

	HRESULT OnReadyStateChange(long newState)
	{
		MessageBoxW(NULL, L"", L"Read", MB_OK);
		return S_OK;
	}

	HRESULT OnProgress(long percentDone)
	{
		MessageBoxW(NULL, L"", L"Done", MB_OK);
		return S_OK;
	}

	HRESULT FSCommand(_bstr_t command, _bstr_t args)   // flash调用C++    FSCommand(方法名，参数内容)
	{
		MessageBoxW(NULL, (command), L"Done", MB_OK);
		return S_OK;
	}
};

#include <cstring>


void MyGetDirectory(wchar_t* pDir, int size)
{

#ifdef _DEBUG
	GetCurrentDirectoryW(size,pDir);
#else

	if(0!=GetModuleFileNameW(NULL,pDir,size))
	{
		wchar_t *pFilePath=wcsrchr(pDir, L'\\' );
		if(pFilePath)
		{
			pFilePath[0]=L'\0';
		}
	}
#endif

}
std::wstring ReturnPath()
{
	std::wstring    sPath;
	wchar_t buff[MAX_PATH] = {0};


	MyGetDirectory(buff,MAX_PATH);

	sPath = buff;
	return    sPath;
}

// class CFlashWindow : public CAxWindow
// {
// public:
//     CFlashWindow(HWND hWnd = NULL)
//     {
//
//     }
//     BOOL Create(int x, int y, int cx, int cy, HWND hWndParent,
//         const wchar_t* szWindowName = NULL, DWORD dwStyle = 0, DWORD dwExStyle = 0)
//     {
//         m_hWindow = XWnd_CreateEx(dwExStyle, GetWndClassName(), szWindowName, dwStyle, x, y, cx, cy, hWndParent,0);
//         m_hWnd = XWnd_GetHWND(m_hWindow);
//         return m_hWindow?TRUE:FALSE;
//     }
//
// private:
//     HWINDOW m_hWindow;
// };


WNDPROC g_OldWndProc = NULL;


LRESULT CALLBACK WindowProc(HWND hwnd,      // handle to window
    UINT uMsg,      // message identifier
    WPARAM wParam,  // first message parameter
    LPARAM lParam   // second message parameter
    )
{


    if (uMsg == WM_RBUTTONDOWN || uMsg == WM_RBUTTONUP)//右键拦截【但是FLASH上右键拦截不到】
    {
        return 0;
    }

    return CallWindowProc(g_OldWndProc,hwnd, uMsg, wParam, lParam);
}


// typedef int (callback* myfunction)(void);
// myfunction  myfunction = null;
// hinstance handle = null ;
// handle = LoadLibrary("trdragdroptreectrl.ocx");
// 
// if( handle != null )
// {
// 	myfunction = GetProcAddress(handle, "DllRegisterServer");
// 	if( myfunction != null )
// 	{
// 		myfunction();
// 	}
// }

class ComDll
{
public:
	HRESULT Regesiter(const char* lpszDllName)
	{ 
		HRESULT retValue = 0;
		hMoudle = LoadLibrary(lpszDllName);
		if (hMoudle == NULL)
			return retValue;
		
		DWORD dwFucPrt = (DWORD)GetProcAddress(hMoudle, "DllRegisterServer");
		__asm
		{
			call dwFucPrt;
			mov  retValue,eax;
		}
		return retValue;
	}
	HRESULT UnRegester()
	{
		HRESULT retValue = 0;
		if (hMoudle == NULL)
			return retValue;
		DWORD dwFucPrt = (DWORD)GetProcAddress(hMoudle, "DllUnregisterServer");
		__asm
		{
			call dwFucPrt;
			mov  retValue,eax;
		}
		FreeLibrary(hMoudle);
		return retValue;
	}

private:
	HMODULE hMoudle;
};



class CMyWindow
{
public:
	HWINDOW m_hWindow;
//	ComDll  m_dll;
	FlashSink  flashSink;
	CAxWindow m_wndView;
	CMyWindow(){
//		m_dll.Regesiter("Flash32_11_7_700_224.ocx");
		Init();

	}
	~CMyWindow()
	{
//		m_dll.UnRegester();
	}

    void RegFlashWindowProc()
    {
        HWND hWnd = XWnd_GetHWND(m_hWindow);
        hWnd = ::GetWindow(hWnd, GW_CHILD);
        hWnd = ::GetWindow(hWnd, GW_CHILD);
        g_OldWndProc = (WNDPROC)SetWindowLong(hWnd, GWL_WNDPROC, (LONG)WindowProc);

    }
	void Init()
	{


		m_hWindow = XWnd_Create(0, 0, 800, 600, L"炫彩界面库窗口", NULL, xc_window_style_default);
		XBtn_SetType(XBtn_Create(0, 0, 60, 20, L"close", m_hWindow), button_type_close);

		//创建FLASH控件
		

		 
		RECT rc = { 20, 40, 600, 500 };

//         m_FlashWnd.Create(20, 40, 600, 500, XWnd_GetHWND(m_hWindow), L"ShockwaveFlash.ShockwaveFlash", WS_CHILD | WS_VISIBLE);
//         m_FlashWnd.QueryControl(__uuidof(ShockwaveFlashObjects::IShockwaveFlash), reinterpret_cast<void**>(&m_flash));


//		afxoleinit
		AtlAxWinInit();
//		afxEnableControlContainer
//		AfxEnableControlContainer();


 		HWND hWndFlash = m_wndView.Create(XWnd_GetHWND(m_hWindow), rc, TEXT("ShockwaveFlash.ShockwaveFlash"), WS_CHILD | WS_VISIBLE);
		if (hWndFlash)
		{

			HRESULT hr = m_wndView.QueryControl(__uuidof(ShockwaveFlashObjects::IShockwaveFlash), reinterpret_cast<void**>(&m_flash));
			if (SUCCEEDED(hr))
			{
				RegFlashWindowProc();
				
				
				flashSink.Init(m_flash);
				
				std::wstring temp;
				temp = ReturnPath();
				temp += L"\\Null.swf";
				m_flash->LoadMovie(0, temp.c_str());
			}
			
			


		}


		XWnd_RegEventCPP(m_hWindow, XWM_WINDPROC, &CMyWindow::OnWndRButtonDown0);
		XWnd_ShowWindow(m_hWindow, SW_SHOW);
	}

	int OnWndRButtonDown0(UINT message, WPARAM wParam, LPARAM lParam, BOOL *pbHandled)
	{
		if (message >= 516 && message <= 517)//右键拦截【但是FLASH上右键拦截不到】
		{
			*pbHandled = true;
			return 0;
		}
		return 0;
	}

};


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	XInitXCGUI();
	CMyWindow  MyWindow;
	XRunXCGUI();
	XExitXCGUI();
	return 0;
}

