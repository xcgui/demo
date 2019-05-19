#pragma once

#include "OleContainer.h"
#include <ExDisp.h>

class WebBrowser : public OleContainer
{
public:
    WebBrowser(HWND hParent) : m_pWebBrowser(nullptr), m_hWnd(hParent)
    {

    }

    ~WebBrowser()
    {
        if (m_pWebBrowser != nullptr)
        {
            m_pWebBrowser->Release();
            m_pWebBrowser = nullptr;
        }
    }

public:
    bool CreateWebBrowser()
    {
        if (!CreateOleObject(CLSID_WebBrowser))
        {
            return false;
        }

        RECT rect = {0};
        GetClientRect(m_hWnd, &rect);

        if (!InPlaceActive(m_hWnd, &rect))
        {
            return false;
        }

        HRESULT hr = m_pOleObj->QueryInterface(IID_IWebBrowser2, (LPVOID *)&m_pWebBrowser);

        if (FAILED(hr))
        {
            return false;
        }

        return true;
    }
    
public:
    void Navigate(LPCTSTR lpUrl)
    {
        BSTR bstrUrl = SysAllocString(lpUrl);
        m_pWebBrowser->Navigate(bstrUrl, nullptr, nullptr, nullptr, nullptr);
        SysFreeString(bstrUrl);
    }

public:
    STDMETHOD(GetWindow)(HWND *phwnd)
    {
        *phwnd = m_hWnd;
        return S_OK;

    }

    STDMETHOD(GetWindowContext)(IOleInPlaceFrame **ppFrame,
                                IOleInPlaceUIWindow **ppDoc,
                                LPRECT lprcPosRect,
                                LPRECT lprcClipRect,
                                LPOLEINPLACEFRAMEINFO lpFrameInfo)
    {
        *ppFrame = (IOleInPlaceFrame*)this;
        *ppDoc = NULL;
        AddRef();

        GetClientRect(m_hWnd, lprcPosRect);
        GetClientRect(m_hWnd, lprcClipRect);

        lpFrameInfo->cb = sizeof(OLEINPLACEFRAMEINFO);
        lpFrameInfo->fMDIApp = false;
        lpFrameInfo->hwndFrame = GetParent(m_hWnd);
        lpFrameInfo->haccel = nullptr;
        lpFrameInfo->cAccelEntries = 0;

        return S_OK;
    }

protected:
    IWebBrowser2 *m_pWebBrowser;
    HWND m_hWnd;
};
