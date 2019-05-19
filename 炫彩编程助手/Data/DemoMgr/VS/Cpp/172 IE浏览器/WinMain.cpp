#define _UNICODE
#define UNICODE
#define _In_
#define _In_opt_
// #include <Windows.h>
// #include <tchar.h>

#include "WebBrowser.h"
#include "Common.h"
// #include "xcgui.h"
// #pragma comment(lib,"xcgui.lib")

// LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
// {
//     switch (message)
//     {
//     case WM_DESTROY:
//         PostQuitMessage(0);
//         break;
//     default:
//         return DefWindowProc(hWnd, message, wParam, lParam);
//     }
// 
//     return 0;
// }

int APIENTRY _tWinMain(_In_ HINSTANCE     hInstance,
                       _In_opt_ HINSTANCE hPrevInstance,
                       _In_ LPTSTR        lpCmdLine,
                       _In_ int           nCmdShow)
{
//     UNREFERENCED_PARAMETER(hPrevInstance);
//     UNREFERENCED_PARAMETER(lpCmdLine);
// 
//     LPTSTR CLASS_NAME = _T("WebBrowserContainer");
// 
//     WNDCLASSEX wcex    = { sizeof(WNDCLASSEX) };
//     wcex.style         = CS_HREDRAW | CS_VREDRAW;
//     wcex.lpfnWndProc   = WndProc;
//     wcex.cbClsExtra    = 0;
//     wcex.cbWndExtra    = 0;
//     wcex.hInstance     = hInstance;
//     wcex.hCursor       = LoadCursor(nullptr, IDC_ARROW);
//     wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//     wcex.lpszClassName = CLASS_NAME;
// 
//     RegisterClassEx(&wcex);
// 
//     HWND hWnd = CreateWindow(CLASS_NAME,
//                              _T("WebBrowser Sample"),
//                              WS_OVERLAPPEDWINDOW,
//                              CW_USEDEFAULT,
//                              0,
//                              CW_USEDEFAULT,
//                              0,
//                              nullptr,
//                              nullptr,
//                              hInstance,
//                              nullptr);
// 
//     if (hWnd == nullptr)
//     {
//         return 0;
//     }
// 
//     ShowWindow(hWnd, nCmdShow);
//     UpdateWindow(hWnd);


	XInitXCGUI();

	HWINDOW hWindow = XWnd_Create(0,0,800,600,L"dasemimi");
    WebBrowser wb(XWnd_GetHWND(hWindow));

    if (!wb.CreateWebBrowser())
    {
        return 0;
    }

    wb.Navigate(_T("http://www.xcgui.com/"));

	XWnd_ShowWindow(hWindow,SW_SHOW);
	XRunXCGUI();
	XExitXCGUI();

//     MSG msg = {0};
// 
//     while (GetMessage(&msg, nullptr, 0, 0))
//     {
//         if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
//         {
//             TranslateMessage(&msg);
//             DispatchMessage(&msg);
//         }
//     }
//
//    return (int)msg.wParam;
	return 0;
}
