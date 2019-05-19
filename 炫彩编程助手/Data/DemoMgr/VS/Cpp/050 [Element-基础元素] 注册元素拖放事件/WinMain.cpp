#include "Common.h"

//#include <Shlwapi.h>
//#include <shlwapi.h>

class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 200, L"ìÅ²Ê½çÃæ¿â´°¿Ú",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		
        HELE hEle=XEle_Create(20,50,100,100,m_hWindow);
		DragAcceptFiles(XWnd_GetHWND(m_hWindow),TRUE);
		XEle_RegEventCPP(hEle,XE_DROPFILES,&CMyWindowElement::OnDropFiles);

        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnDropFiles(HDROP hDropInfo, BOOL *pbHandled)
	{
		MessageBoxA(NULL,NULL,NULL,MB_OK);
		wchar_t fileNameBuffer[MAX_PATH] = {0};
		UINT fileCount = DragQueryFileW(hDropInfo,0xFFFFFFFF,NULL,0);

		for (UINT i = 0 ; i < fileCount; i++)
		{
			ZeroMemory(fileNameBuffer,MAX_PATH*sizeof(wchar_t));
			DragQueryFileW(hDropInfo,i,fileNameBuffer,MAX_PATH);
			OutputDebugStringW(fileNameBuffer);
		}
		DragFinish(hDropInfo);

		return 0;
	}
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowElement  MyWindowt;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




