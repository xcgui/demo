#include "Common.h"

class XFile
{
public:
	BOOL Open(const wchar_t* lpFileName)
	{
		m_hFile = CreateFileW(
			lpFileName,
			GENERIC_READ|GENERIC_WRITE,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (m_hFile == INVALID_HANDLE_VALUE)
			return FALSE;

		return TRUE;
	}
	VOID Close()
	{
		CloseHandle(m_hFile);
	}
	BOOL SetPoint(int nPos)
	{
		return SetFilePointer(m_hFile,nPos,NULL,FILE_BEGIN) == INVALID_SET_FILE_POINTER ? FALSE:FALSE;
	}

	BOOL Read(VOID* pBuffer,DWORD dwBufferSize,DWORD* pdwRealReadSize)
	{
		return ReadFile(m_hFile,pBuffer,dwBufferSize,pdwRealReadSize,NULL);
	}

	BOOL GetSize(PLARGE_INTEGER fileSize)
	{
		return GetFileSizeEx(m_hFile,fileSize);
	}

private:
	HANDLE m_hFile;
};


class XBuffer
{
public:
	XBuffer()
	{
		m_pBuffer = NULL;
	}
	~XBuffer()
	{
		if (m_pBuffer)
			delete [] m_pBuffer;
	}

	void ReSize(int size)
	{
		if (m_pBuffer)
			delete [] m_pBuffer;

		m_pBuffer = new char[size];
	}
public:
	char* m_pBuffer;
	int m_MaxShowCount;
};

#define HEX_TEXT_HEIGHT 12

class XHexEdit
{
public:
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_x = x, m_y = y,m_cx = cx, m_cy = cy;

        m_hScrollView=XSView_Create(m_x,m_y,m_cx,m_cy,hParent);
		
		XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_H,&XHexEdit::OnScrollViewScrollH);
		XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_V,&XHexEdit::OnScrollViewScrollV);
		return m_hScrollView;
	}

	BOOL LoadFile(const wchar_t* lpFileName)
	{
		if (!m_File.Open(lpFileName))
			return FALSE;
		LARGE_INTEGER fileSize;
		m_File.GetSize(&fileSize);
		int nRowCount = fileSize.QuadPart / 16;
		int nRowHeight = nRowCount*HEX_TEXT_HEIGHT;	
		XSView_SetTotalSize(m_hScrollView,200,nRowHeight);
		m_Buffer.ReSize(CalcHexMaxShowCount());

		return TRUE;
	}	
    int  OnScrollViewScrollH(int pos,BOOL *pbHandled)
    {
        XTRACE("XE_SCROLLVIEW_SCROLL_H %d \n",pos);
        return 0;
    }
    int  OnScrollViewScrollV(int pos,BOOL *pbHandled)
    {

		DWORD dwRealReadSize = 0;
		m_File.SetPoint(pos);
		m_File.Read(m_Buffer.m_pBuffer,m_Buffer.m_MaxShowCount,&dwRealReadSize);
		
        XTRACE("XE_SCROLLVIEW_SCROLL_V %d \n",pos);
        return 0;
    }

private:
	//计算当前元素最大能显示多少个字符
	int CalcHexMaxShowCount()
	{
		return (m_cy / HEX_TEXT_HEIGHT + ((m_cy % HEX_TEXT_HEIGHT)?1:0) )*HEX_TEXT_HEIGHT;
	}

private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;

	HELE    m_hScrollView;
		
	XFile   m_File;
	XBuffer m_Buffer;
};

class CMyWindowScrollView
{
public:
    HWINDOW m_hWindow;

	XHexEdit m_HexEdit;

    CMyWindowScrollView()
    {
        Init();
    }
    void Init()
    {
        m_hWindow = XWnd_Create(0, 0, 300, 300, L"炫彩界面库窗口", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		

		m_HexEdit.Create(20,50,200,200,m_hWindow);
		m_HexEdit.LoadFile(L"g:\\WindowsXP-SP3-VOLMSDN.rar");

		
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }


};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CMyWindowScrollView  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return TRUE;
}