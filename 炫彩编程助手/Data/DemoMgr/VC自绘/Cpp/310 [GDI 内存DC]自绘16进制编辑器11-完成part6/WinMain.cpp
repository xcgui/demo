#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"

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
		
		if (size < m_MaxShowCount)
		{
			m_MaxShowCount = size;
			return ;
		}

		if (m_pBuffer)
			delete [] m_pBuffer;

		m_pBuffer = new char[size];
		m_MaxShowCount = size;
	}
public:
	char* m_pBuffer;
	int m_MaxShowCount;
};





class DataFormat
{
public:
    DataFormat()
    {
        ZeroMemory(pDicTable, 256);
        pDicTable['0'] = 0;
        pDicTable['1'] = 1;
        pDicTable['2'] = 2;
        pDicTable['3'] = 3;
        pDicTable['4'] = 4;
        pDicTable['5'] = 5;
        pDicTable['6'] = 6;
        pDicTable['7'] = 7;
        pDicTable['8'] = 8;
        pDicTable['9'] = 9;
        pDicTable['A'] = 10;
        pDicTable['B'] = 11;
        pDicTable['C'] = 12;
        pDicTable['D'] = 13;
        pDicTable['E'] = 14;
        pDicTable['F'] = 15;
    }
    wchar_t HexStrToChar(const wchar_t* pBuf)
    {
        wchar_t result = 0;
        result |= ((pDicTable[pBuf[0]] << 4) & 0xF0);
        result |= pDicTable[pBuf[1]];
        return result;
    }

    wchar_t* CharToHexStr(wchar_t ch)
    {
        wchar_t pHexToDecTable[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
        buffer[0] = pHexToDecTable[(ch & 0xf000) >> 12];
        buffer[1] = pHexToDecTable[(ch & 0xf00) >> 8];
        buffer[2] = pHexToDecTable[(ch & 0xf0) >> 4];
        buffer[3] = pHexToDecTable[(ch & 0xf)];
        buffer[4] = 0;
        return buffer;
    }
private:
    wchar_t pDicTable[256];
	
    wchar_t buffer[5];
};



class XPartBase
{
public:
	VOID SetRect(int x,int y,int cx,int cy)
	{
		m_rt.left = x;
		m_rt.top  = y;
		m_rt.right = x+cx;
		m_rt.bottom = y+cy;
	}
protected:
	RECT m_rt;
};


class XPart1 : public XPartBase
{
public:
	XPart1()
	{
		m_lpText = L"offset";
	}
	void Draw(XGDIMEMDC* pMemDC)
	{
		pMemDC->DrawText(m_lpText,wcslen(m_lpText),&m_rt,DT_CENTER|DT_VCENTER);
	}
private:
	wchar_t* m_lpText;
};


class XPart2 : public XPartBase
{
public:
	XPart2()
	{
		m_lpText = L"0123456789ABCDEF";
	}
	int GetChCount()
	{
		return 16;
	}
	VOID SetChRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_rtArray[nIndex].left = x;
		m_rtArray[nIndex].top  = y;
		m_rtArray[nIndex].right = x+cx;
		m_rtArray[nIndex].bottom = y+cy;
	}

	VOID Draw(XGDIMEMDC* pMemDC)
	{
		for (int i = 0; i < 16; i++)
		{
			pMemDC->DrawRect1(m_rtArray+i);
			pMemDC->DrawText(m_lpText+i,1,m_rtArray+i,DT_LEFT|DT_VCENTER);
		}
	}
private:
	RECT m_rtArray[16];
	wchar_t* m_lpText;
};


class XPart3 : public XPartBase
{
public:
	XPart3()
	{
		m_lpText = L"0123456789ABCDEF";
	}
	int GetChCount()
	{
		return 16;
	}
	VOID SetChRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_rtArray[nIndex].left = x;
		m_rtArray[nIndex].top  = y;
		m_rtArray[nIndex].right = x+cx;
		m_rtArray[nIndex].bottom = y+cy;
	}
	
	VOID Draw(XGDIMEMDC* pMemDC)
	{
		for (int i = 0; i < 16; i++)
		{
			pMemDC->DrawRect1(m_rtArray+i);
			pMemDC->DrawText(m_lpText+i,1,m_rtArray+i,DT_LEFT|DT_VCENTER);
		}
	}
private:
	RECT m_rtArray[16];
	wchar_t* m_lpText;
};


class XPart4 : public XPartBase
{
public:
	XPart4()
	{
		m_buffer[8]=L'\0';
		m_nScorbarPos = 0;
	}

	VOID SetChRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_rtArray[nIndex].left = x;
		m_rtArray[nIndex].top  = y;
		m_rtArray[nIndex].right = x+cx;
		m_rtArray[nIndex].bottom = y+cy;
	}
	int GetRowCount()
	{
		return m_nMaxShowRowCount;
	}
	VOID SetRowCount(int nRowCount)
	{
		m_nMaxShowRowCount = nRowCount;
	}
	VOID SetScrollPos(int nPos)
	{
		m_nScorbarPos = nPos;
	}

	VOID Draw(XGDIMEMDC* pMemDC)
	{
		for (int i = 0; i < m_nMaxShowRowCount; i++)
		{
			wsprintfW(m_buffer,L"%08X",i+m_nScorbarPos);
			pMemDC->TextOutW(m_rtArray[i].left,m_rtArray[i].top,m_buffer,8);
		}
	}

private:
	wchar_t m_buffer[9];
	RECT    m_rtArray[1000];
	int     m_nMaxShowRowCount;
	int     m_nScorbarPos;
};


class XPart5 : public XPartBase
{
public:
	XPart5()
	{
		m_pRtArray = NULL;
		m_ArraySize = 0;
	}

	VOID ReSize(int nSize)
	{
		if (nSize < m_ArraySize)
		{
			m_ArraySize = nSize;
			return ;
		}
		if (m_ArraySize != NULL)
		{
			delete [] m_pRtArray;
			m_pRtArray = new RECT[nSize];
		}else
		{
			m_pRtArray = new RECT[nSize];
		}
		m_ArraySize = nSize;
	}
	int GetArrayCount()
	{
		return m_ArraySize;
	}
	void SetHexsRect(int nIndex,int x,int y,int cx,int cy)
	{
		m_pRtArray[nIndex].left = x;
		m_pRtArray[nIndex].top  = y;
		m_pRtArray[nIndex].right = x+cx;
		m_pRtArray[nIndex].bottom = y+cy;
	}
	void GetHexsRect(int nIndex,RECT *pRect)
	{
		*pRect = m_pRtArray[nIndex];
	}
private:
	RECT* m_pRtArray;
	int   m_ArraySize;
};

class XPart6 : public XPart5
{
public:
	XPart6()
	{

	}
};


#define HEX_TEXT_HEIGHT 14
#define SPLIT1_WIDTH  10
#define SPLIT2_WIDTH  10

class XHexEdit
{
public:
	XHexEdit()
	{
		m_pTopLeftText = L"offset";
		m_pTopMidText  = L"0123456789ABCDEF";

		m_nPart2BlockWidth = 20;
		m_nPart2BlockSpace = 6;
		m_nPart3BlockWidth = 12;

		m_nRowSpace = 6;
		m_nRowHeight = HEX_TEXT_HEIGHT;

		m_nScorBarVPos = 0;
	}
	HELE Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{
		m_x = x, m_y = y,m_cx = cx, m_cy = cy;
        m_hScrollView=XSView_Create(m_x,m_y,m_cx,m_cy,hParent);
		XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_H,&XHexEdit::OnScrollViewScrollH);
		XEle_RegEventCPP(m_hScrollView,XE_SCROLLVIEW_SCROLL_V,&XHexEdit::OnScrollViewScrollV);
		XEle_RegEventCPP(m_hScrollView,XE_SIZE,&XHexEdit::OnSize);
		XEle_RegEventCPP(m_hScrollView,XE_PAINT_SCROLLVIEW,&XHexEdit::OnDrawScrollView);
		XEle_RegEventCPP(m_hScrollView,XE_MOUSEMOVE,&XHexEdit::OnMouseMove);
		m_MemDC.Create(XEle_GetHWND(m_hScrollView));


		XEle_PostEvent(m_hScrollView,m_hScrollView,XE_SIZE,NULL,NULL);

		return m_hScrollView;
	}

	BOOL LoadFile(const wchar_t* lpFileName)
	{
		if (!m_File.Open(lpFileName))
			return FALSE;

		XEle_PostEvent(m_hScrollView,m_hScrollView,XE_SIZE,NULL,NULL);

		m_nScorBarVPos = 0;
		return TRUE;
	}


//事件接口
public:
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{
		m_MousePosX = pPt->x;
		m_MousePosy = pPt->y;
		XEle_RedrawEle(m_hScrollView,FALSE);
		return 0;
	}
	int OnSize(BOOL *pbHandled)
	{
		//控件大小变化，需要做几件事
		//1 重新设置画板显示大小
		//2 重新计算缓冲区大小
		//3 重新读取指定位置数据
		//4 重新计算各个part的坐标
		m_Part1Width = m_MemDC.GetTextWidth(L"00000000",8)+2;

		LARGE_INTEGER fileSize;
		m_File.GetSize(&fileSize);
		int nRowCount = fileSize.QuadPart / 16+10;
		int nRowHeight = nRowCount*m_nRowHeight;
		XSView_SetTotalSize(m_hScrollView,500,nRowHeight);
		XSView_SetLineSize(m_hScrollView,m_nRowHeight,m_nRowHeight);

		m_cx = XEle_GetWidth(m_hScrollView);
		m_cy = XEle_GetHeight(m_hScrollView);
		m_MemDC.Resize(1000,m_cy);


		//计算当前元素最大能显示多少个字符
	    int cy = m_cy - m_nRowHeight;
		int nShowBufferSize = (cy / m_nRowHeight + ((cy % m_nRowHeight)?1:0))*16;
		m_Buffer.ReSize(nShowBufferSize);


		m_File.SetPoint(m_nScorBarVPos*16);
		m_File.Read(m_Buffer.m_pBuffer,m_Buffer.m_MaxShowCount,&m_nRealShowSize);



		m_nRealRowCount = m_nRealShowSize / 16 + (m_nRealShowSize%16?1:0);
		m_Part4.SetRowCount(m_nRealRowCount);


		m_Part5.ReSize(m_nRealShowSize);
		m_Part6.ReSize(m_nRealShowSize);

		AutoCalcPartsRect();
		
		return 0;
	}
    int  OnScrollViewScrollH(int pos,BOOL *pbHandled)
    {
        XTRACE("XE_SCROLLVIEW_SCROLL_H %d \n",pos);
        return 0;
    }
    int  OnScrollViewScrollV(int pos,BOOL *pbHandled)
    {

		//滚动条滚动 需要做的几件事
		// 第一，读取滚动条位置的数据，
		// 第二，如果实际读取的数据小于可显示的数据，那么重新保存一下
		// 第三 重新计算各个part的坐标
		m_nScorBarVPos = pos;

		m_File.SetPoint(pos*16);
		m_File.Read(m_Buffer.m_pBuffer,m_Buffer.m_MaxShowCount,&m_nRealShowSize);
		

		m_nRealRowCount = m_nRealShowSize / 16 + (m_nRealShowSize%16?1:0);
		m_Part4.SetRowCount(m_nRealRowCount);
		m_Part4.SetScrollPos(m_nScorBarVPos);


		m_Part5.ReSize(m_nRealShowSize);
		m_Part6.ReSize(m_nRealShowSize);

		AutoCalcPartsRect();

        XTRACE("XE_SCROLLVIEW_SCROLL_V %d \n",pos);
        return 0;
    }


	//分为6个部分

	//  | part1 | part2 | part3|
	//  |----------------------|
	//  | part4 | part5 | part6|
	//  |       |       |      |

	// part1  == offset 字符串
	// part2  == 0 - F  列标示
	// part3  == 0 - F  字符显示
	// part4  == 00000000  - FFFFFFFF  行号
	// part5  == 十六进制显示 
	// part6  == 字符形式显示


	int OnDrawScrollView(HDRAW hDraw,BOOL *pbHandled)
	{
		m_MemDC.FillRect(0,0,m_MemDC.GetBitMapWidth(),m_MemDC.GetBitMapHeight());


		m_MemDC.SetTextColor(RGB(0,0,128));

		int leftSize = 5;
		int offsetX = leftSize;
		int offsetY = 0;
		// draw offset 
		m_part1.Draw(&m_MemDC);	
		m_part2.Draw(&m_MemDC);
		m_Part3.Draw(&m_MemDC);
		m_MemDC.SetTextColor(0);
		m_Part4.Draw(&m_MemDC);
		wchar_t buffer[10] = {0};
		RECT rt;
		for (int k = 0 ; k < m_Part5.GetArrayCount(); k++)
		{
			m_Part5.GetHexsRect(k,&rt);
			wchar_t* pStrHex = m_Format.CharToHexStr((wchar_t)(m_Buffer.m_pBuffer[k]));
			m_MemDC.TextOutW(rt.left,rt.top,pStrHex+2,2);
		}

		RECT rt6;
		for (int m = 0 ; m < m_Part6.GetArrayCount();m++)
		{
			m_Part6.GetHexsRect(m,&rt6);
			m_MemDC.TextOutA(rt6.left,rt6.top,m_Buffer.m_pBuffer+m,1);
		}

		HGDIOBJ hOldObj = m_MemDC.SelectObject(m_MemDC.GetStockObject(DC_PEN));
		m_MemDC.SetDCPenColor(RGB(255,0,0));
		//画两条线,鼠标飘过即可识别
		int x1,y1,x2,y2;
		x1 = 0;
		y1 = m_MousePosy;
		x2 = m_Part1Width;
		y2 = m_MousePosy;
		m_MemDC.DrawLine(x1,y1,x2,y2);


		int x3,y3,x4,y4;
		x3 = m_MousePosX;
		y3 = m_nRowHeight;

		x4 = m_MousePosX;
		y4 = 0;
		m_MemDC.DrawLine(x3,y3,x4,y4);

		m_MemDC.SelectObject(hOldObj);

		int x,y;
		XDraw_GetOffset(hDraw,&x,&y);
		m_MemDC.BitBlt3_(hDraw,0,y);



		XDraw_SetLineWidth(hDraw,m_nRowHeight);
		

		//画两条线,鼠标飘过即可识别
// 		RECT rt1;
// 		rt1.left = 0;
// 		rt1.top  = m_MousePosy;
// 		rt1.right = m_Part1Width;
// 		rt1.bottom = m_MousePosy+m_nRowHeight/2;
// 		XDraw_FillRectColor(hDraw,&rt1,RGB(0,128,0),50);
// 
// 
// 		RECT rt2;
// 		rt2.left = m_MousePosX;
// 		rt2.top  = 0;
// 		rt2.right = m_MousePosX+m_nPart2BlockWidth/2;
// 		rt2.bottom = m_nRowHeight;
// 		XDraw_FillRectColor(hDraw,&rt2,RGB(0,128,0),50);


		return 0;
	}

private:

	VOID ReadFileData(int nPos)
	{
		DWORD dwRealReadSize = 0;
		m_File.SetPoint(nPos*16);
		m_File.Read(m_Buffer.m_pBuffer,m_Buffer.m_MaxShowCount,&dwRealReadSize);
		m_nRealShowSize = dwRealReadSize;

	}

	//自动计算所有part的坐标
	VOID AutoCalcPartsRect()
	{
		int offsetX = 5;
		int offsetY = 0;
		int x = offsetX;
		int y = offsetY; 
		m_part1.SetRect(x,y,m_Part1Width,m_nRowHeight);

		x+= m_Part1Width;
		x+= SPLIT1_WIDTH;

		m_Part2Width = (m_nPart2BlockWidth+m_nPart2BlockSpace)*m_part2.GetChCount();
		m_part2.SetRect(x,y,m_Part2Width,m_nRowHeight);

		int i ;
		for (i = 0; i < m_part2.GetChCount(); i++)
		{
			m_part2.SetChRect(i,x,y,m_nPart2BlockWidth,m_nRowHeight);
			x+=m_nPart2BlockWidth;
			x+=m_nPart2BlockSpace;
		}

		x+= SPLIT2_WIDTH;
		m_Part3Width = m_nPart3BlockWidth*m_Part3.GetChCount();
		m_Part3.SetRect(x,y,m_Part3Width,m_nRowHeight);
		for (i = 0; i < m_Part3.GetChCount(); i++)
		{
			m_Part3.SetChRect(i,x,y,m_nPart3BlockWidth,m_nRowHeight);
			x+=m_nPart3BlockWidth;
		}
		
		x = offsetX;
		y += m_nRowHeight;

		for (i = 0; i < m_Part4.GetRowCount(); i++)
		{
			m_Part4.SetChRect(i,x,y,m_Part1Width,m_nRowHeight);
			y+=m_nRowHeight;
		}


		x = offsetX+SPLIT1_WIDTH+m_Part1Width;
		y = offsetY+m_nRowHeight;
		m_Part5.SetRect(x,y,m_Part2Width,m_cy-m_nRowHeight);
		for (i = 0; i < m_Part5.GetArrayCount(); i++)
		{
			if ( (i % 16) == 0 && i != 0)
			{
				x = offsetX+SPLIT1_WIDTH+m_Part1Width;
				y+= m_nRowHeight;
			}
			m_Part5.SetHexsRect(i,x,y,m_nPart2BlockWidth,m_nRowHeight);
			x+=m_nPart2BlockWidth;
			x+=m_nPart2BlockSpace;
		}


		x = offsetX +m_Part1Width+SPLIT1_WIDTH+m_Part2Width+SPLIT2_WIDTH;
		y = offsetY + m_nRowHeight;
		m_Part6.SetRect(x,y,m_Part3Width,m_cy-m_nRowHeight);

		for (i = 0; i < m_Part6.GetArrayCount(); i++)
		{
			if ( (i %16) == 0 && i != 0)
			{
				x= offsetX +m_Part1Width+SPLIT1_WIDTH+m_Part2Width+SPLIT2_WIDTH;
				y+= m_nRowHeight;
			}
			m_Part6.SetHexsRect(i,x,y,m_nPart3BlockWidth,m_nRowHeight);
			x+=m_nPart3BlockWidth;
		}


	}

private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;

	HELE    m_hScrollView;
		
	XFile   m_File;
	XBuffer m_Buffer;
	DataFormat m_Format;
	XGDIMEMDC m_MemDC;


	//行数索引文本的宽度
	int m_Part1Width;
	int m_Part2Width;
	int m_Part3Width;

	int m_nPart2BlockWidth; //中间16进制文本 单个宽度
	int m_nPart2BlockSpace; //中间16进制文本 间距

	int m_nPart3BlockWidth; //中间16进制文本 单个宽度

	int m_nRowHeight;
	int m_nRowSpace;

	wchar_t* m_pTopLeftText;
	wchar_t* m_pTopMidText;

	int  m_nScorBarVPos;

	//为什么会有这个，因为读取的实际数据可能大于编辑框可显示的数据大小
	DWORD m_nRealShowSize;
	int m_nRealRowCount;

	int m_MousePosX;
	int m_MousePosy;


	XPart1 m_part1;
	XPart2 m_part2;
	XPart3 m_Part3;
	XPart4 m_Part4;
	XPart5 m_Part5;
	XPart6 m_Part6;
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
        m_hWindow = XWnd_Create(0, 0, 600, 300, L"炫彩界面库窗口", NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(5, 3, 60, 20, L"Close", m_hWindow),button_type_close);
		

		HELE hEle = m_HexEdit.Create(20,50,200,200,m_hWindow);
		m_HexEdit.LoadFile(L"g:\\WindowsXP-SP3-VOLMSDN.rar");

		

		HXCGUI hLayoutBody = XLayout_Create();
		XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);
		XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
		XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);
		
		XLayout_AddEle(hLayoutBody,hEle);
		XEle_SetLayoutWidth(hEle,layout_size_type_fill,1);
		XEle_SetLayoutHeight(hEle,layout_size_type_fill,1);

		XWnd_AdjustLayout(m_hWindow);
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