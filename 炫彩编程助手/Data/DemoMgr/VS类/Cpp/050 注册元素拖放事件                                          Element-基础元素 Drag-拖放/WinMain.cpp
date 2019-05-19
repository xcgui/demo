#include "Common.h"

//#include <Shlwapi.h>
//#include <shlwapi.h>

class CMyWindowElement
{
public:
	xcgui::XWnd m_Wnd;
    CMyWindowElement(){
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
		xcgui::XEle ele(20,50,100,100,m_Wnd);
		DragAcceptFiles(m_Wnd.GetHWND(),TRUE);
		XEle_RegEventCPP(ele,XE_DROPFILES,&CMyWindowElement::OnDropFiles);

        m_Wnd.ShowWindow(SW_SHOW);
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




