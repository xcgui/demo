#pragma once

#include "WebBrowser.h"

class MyWebBrowser : public WebBrowser
{
public:
    MyWebBrowser(HWND hParent) : m_hWnd(hParent)
    {

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

public:
    void Navigate(LPCTSTR lpUrl)
    {
        BSTR bstrUrl = SysAllocString(lpUrl);
        m_pWebBrowser->Navigate(bstrUrl, nullptr, nullptr, nullptr, nullptr);
        SysFreeString(bstrUrl);
    }

private:
    HWND m_hWnd;
};
