#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"

#include <map>

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

	BOOL GetSizeMoreThan4GB(PLARGE_INTEGER fileSize)
	{
		return GetFileSizeEx(m_hFile,fileSize);
	}
	BOOL GetSizeLessThan4GB(DWORD* pdwSize)
	{
		LARGE_INTEGER fullSize;
		BOOL bOk = GetSizeMoreThan4GB(&fullSize);
		*pdwSize = fullSize.LowPart;
		return bOk;
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


//修改的数据保存类
class XModiyData
{
public:
	//ch 被修改的参数
	//pos 被修改数据的绝对位置
	void push(int pos,char ch)
	{
		std::map<int,char>::iterator it = m_data.find(pos);

		if ( it != m_data.end())
		{
			it->second = ch;
		}else
		{
			m_data.insert(std::pair<int,char>(pos,ch));
		}
	}
	BOOL pop(char* pCh,int * pPos)
	{
		if (IsEmpty())
			return FALSE;
		std::map<int,char>::iterator it = m_data.end();
		it--;
		if (pCh != NULL && pPos != NULL)
		{
			*pCh = it->second;
			*pPos = it->first;
		}
		m_data.erase(it);
		return TRUE;
	}
	BOOL IsEmpty()
	{
		return m_data.empty();
	}
	VOID Clear()
	{
		m_data.clear();
	}
	BOOL IsDataModify(int pos,char* pCh)
	{
		if (IsEmpty())
			return 0;
		
		std::map<int,char>::iterator it = m_data.find(pos);

		if (it == m_data.end())
			return FALSE;

		*pCh = it->second;
		return TRUE;
	}
private:
	std::map<int,char> m_data;
};


class XHexFilter
{
public:
	XHexFilter()
	{
		memset(m_TableArray,'.',256);
		unsigned char ch = 33;
		for (; ch < 128; ch++)
		{
			m_TableArray[ch] = ch;
		}
		m_TableArray[127] = '.';
	}
	void SetFilter(unsigned char index,char showedChar)
	{
		m_TableArray[index]= showedChar;
	}
	char* Filter(char* lpChar)
	{
		return m_TableArray + (unsigned char)*lpChar;
	}
private:
	char m_TableArray[256];
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
		pDicTable['a'] = 10;
        pDicTable['b'] = 11;
        pDicTable['c'] = 12;
        pDicTable['d'] = 13;
        pDicTable['e'] = 14;
        pDicTable['f'] = 15;
    }
    wchar_t HexStrToChar(const wchar_t* pBuf)
    {
        wchar_t result = 0;
        result |= ((pDicTable[pBuf[0]] << 4) & 0xF0);
        result |= pDicTable[pBuf[1]];
        return result;
    }
	// 比如a 的16进制字符串是 61 此时可以修改 6或者 1
	char CharModiy(char chSrc,int nIndex,wchar_t md)
	{
		char result = '\0';
		if (nIndex == 0)
		{//修改高位
			result |= pDicTable[md];
			result <<= 4;
			result |= (chSrc&0x0f);
		} 
		else // == 1 修改低位
		{
			result = chSrc&0xf0;
			result |= pDicTable[md];
		}
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
	VOID GetRect(RECT* pRect)
	{
		*pRect = m_rt;
	}
protected:
	RECT m_rt;
};


class XPart1 : public XPartBase
{
public:
	XPart1()
	{
		ZeroMemory(m_lpText,256);
		wcscat(m_lpText,L"offset");
	}
	VOID SetText(const wchar_t* lpText)
	{
		wcscpy(m_lpText,lpText);
	}
	void Draw(XGDIMEMDC* pMemDC)
	{
		pMemDC->DrawText(m_lpText,wcslen(m_lpText),&m_rt,DT_CENTER|DT_VCENTER);
	}
private:
	wchar_t m_lpText[128];
};


class XPart2 : public XPartBase
{
public:
	XPart2()
	{
		//m_lpText = L"000102030405060708090A0B0C0D0E0F";
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

enum CARET_IN_
{
	CARET_IN_PART1 = 1,
	CARET_IN_PART2,
	CARET_IN_PART3,
	CARET_IN_PART4,
	CARET_IN_PART5,
	CARET_IN_PART6,
};

class XHexEdit
{
public:
	XHexEdit()
	{
		m_PaddingLeft = 5;
		m_PaddingTop  = 0;
		m_nPart2BlockWidth = 20;
		m_nPart2BlockSpace = 6;
		m_nPart3BlockWidth = 15;
		m_nRowHeight = HEX_TEXT_HEIGHT;
		m_nScorBarVPos = 0;
		m_nScorBarHPos = 0;
		ZeroMemory(&m_SelectStart,sizeof(m_SelectStart));
		ZeroMemory(&m_SelectEnd,sizeof(m_SelectEnd));

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
		XEle_RegEventCPP(m_hScrollView,XE_LBUTTONDOWN,&XHexEdit::OnLButtonDown);
		XEle_RegEventCPP(m_hScrollView,XE_KEYDOWN,&XHexEdit::OnEventKeyDown);
		XEle_RegEventCPP(m_hScrollView,XE_CHAR,&XHexEdit::OnEventChar);
		XSView_SetBorderSize(m_hScrollView,0,0,0,0);

		m_Caret.Create(m_hScrollView,1,m_nRowHeight);
		m_Caret.SetColor(RGB(128,0,0));
		m_MemDC.Create(XEle_GetHWND(m_hScrollView));

		XEle_PostEvent(m_hScrollView,m_hScrollView,XE_SIZE,NULL,NULL);

		return m_hScrollView;
	}

	BOOL LoadFile(const wchar_t* lpFileName)
	{
		if (!m_File.Open(lpFileName))
			return FALSE;

		//元素控件大小变化 重新计算视图总大小
		LARGE_INTEGER fileSize;
		m_File.GetSizeMoreThan4GB(&fileSize);
		DWORD nRowCount = fileSize.LowPart / 16 + ( fileSize.LowPart % 16?1:0) ;
		int nRowHeight = m_PaddingTop+m_nRowHeight+nRowCount*m_nRowHeight+100;
		XSView_SetTotalSize(m_hScrollView,800,nRowHeight);
		XSView_SetLineSize(m_hScrollView,m_nRowHeight,m_nRowHeight);

		XEle_PostEvent(m_hScrollView,m_hScrollView,XE_SIZE,NULL,NULL);

		m_nScorBarVPos = 0;
		return TRUE;
	}


//事件接口
public:
	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		//过滤
		if (wParam == 8)
			return 0;

		//此时光标的位置得判断是在part5 还是在part6
		SELECT CaretInfo = m_SelectEnd;

		if (CaretInfo.m_CaretInWichPart == CARET_IN_PART5)
		{
			BOOL bFilter = TRUE;
			if ( wParam >= '0' && wParam <= '9')
			{
				bFilter = FALSE;
			} 
			else if ( wParam >= 'a' && wParam <= 'f')
			{
				bFilter = FALSE;
			} 
			else if( wParam >= 'A' && wParam <= 'F')
			{
				bFilter = FALSE;
			}

			SELECT CaretInfo = m_SelectEnd;

			//如果需要过滤就直接过滤了
			if ( bFilter == TRUE)
				return 0;

			//否则处理消息

			//首先判断是否已经修改过了。。。。
			char oldChar='0';
			int nScorllHideSize = m_nScorBarVPos*16;
			int nBufferIndex = CaretInfo.m_DataIndex - nScorllHideSize;

			if (m_ModData.IsDataModify(CaretInfo.m_DataIndex,&oldChar))
			{
				//如果修改过，则用修改过的数据
				char newCh = m_Format.CharModiy(oldChar,CaretInfo.m_TextIndex,(wchar_t)wParam);
				m_ModData.push(nBufferIndex+nScorllHideSize,newCh);
			} 
			else
			{
				char newCh = m_Format.CharModiy(m_Buffer.m_pBuffer[nBufferIndex],CaretInfo.m_TextIndex,(wchar_t)wParam);
				m_ModData.push(nBufferIndex+nScorllHideSize,newCh);
			}
			XEle_PostEvent(m_hScrollView,m_hScrollView,XE_KEYDOWN,VK_RIGHT,NULL);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		if (CaretInfo.m_CaretInWichPart == CARET_IN_PART6)
		{
			int nBufferIndex = CaretInfo.m_DataIndex;
			//后面还要修复
			m_ModData.push(nBufferIndex,(char)wParam);
			XEle_PostEvent(m_hScrollView,m_hScrollView,XE_KEYDOWN,VK_RIGHT,NULL);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		return 0;
	}
	int OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{

#ifdef _DEBUG
		xtrace("keydown %d \r\n",wParam);
#endif
		
		if (wParam == VK_RIGHT)
		{
			SELECT CaretInfo = m_SelectEnd;
			//分两种情况
			//在part5 还是在part6
			if (CaretInfo.m_CaretInWichPart == CARET_IN_PART5)
			{
				DWORD dwFileSize = 0;
				m_File.GetSizeLessThan4GB(&dwFileSize);
				if (CaretInfo.m_DataIndex == dwFileSize && CaretInfo.m_TextIndex == 1) 
					return 0;  //在末尾

				
				RECT rt;
				
				if (CaretInfo.m_TextIndex == 0)
				{
					int nBufferIndex =CaretInfo.m_DataIndex - m_nScorBarVPos*16;
					m_Part5.GetHexsRect(nBufferIndex,&rt);
					CaretInfo.m_TextIndex = 1;
					wchar_t* pHexText = m_Format.CharToHexStr(m_Buffer.m_pBuffer[nBufferIndex]);
					rt.left += m_MemDC.GetTextWidth(pHexText+2,1);

				}else
				{
					
					CaretInfo.m_DataIndex++;
					CaretInfo.m_TextIndex = 0;

					int nBufferIndex =CaretInfo.m_DataIndex - m_nScorBarVPos*16;
					m_Part5.GetHexsRect(nBufferIndex,&rt);
				}

				

				//相对坐标转化成绝对的坐标
				rt.top += m_nScorBarVPos*m_nRowHeight;
				m_Caret.SetPos(rt.left,rt.top);
				m_Caret.Show(TRUE);
				
				//还要分是否按住了 ctrl键
				if(GetAsyncKeyState(VK_SHIFT)&0x8000)
				{
					//多选
					m_SelectEnd = CaretInfo;
					XEle_RedrawEle(m_hScrollView);
				}else
				{
					//设置当前光标位置
					m_SelectEnd = CaretInfo;
					m_SelectStart = CaretInfo;
				}


			}
			if (CaretInfo.m_CaretInWichPart == CARET_IN_PART6)
			{
				DWORD dwFileSize = 0;
				m_File.GetSizeLessThan4GB(&dwFileSize);
				if (CaretInfo.m_DataIndex == dwFileSize) 
						return 0;  //在末尾

				CaretInfo.m_DataIndex++;

				int nBufferIndex =CaretInfo.m_DataIndex - m_nScorBarVPos*16;

				RECT rt;
				m_Part6.GetHexsRect(nBufferIndex,&rt);

				//相对坐标转化成绝对的坐标
				rt.top += m_nScorBarVPos*m_nRowHeight;


				m_Caret.SetPos(rt.left,rt.top);
				m_Caret.Show(TRUE);
				
				//还要分是否按住了 ctrl键
				if(GetAsyncKeyState(VK_SHIFT)&0x8000)
				{
					//多选
					m_SelectEnd = CaretInfo;
					XEle_RedrawEle(m_hScrollView);
				}else
				{
					//设置当前光标位置
					m_SelectEnd = CaretInfo;
					m_SelectStart = CaretInfo;
				}

			}



			return 0;
		}

		if (wParam == VK_LEFT)
		{
			SELECT CaretInfo = m_SelectEnd;
			if (CaretInfo.m_DataIndex == 0)
				return 0; //到最开头了

			//否则
			CaretInfo.m_DataIndex--;
			CaretInfo.m_TextIndex=0;

			int nBufferIndex =CaretInfo.m_DataIndex - m_nScorBarVPos*16;

			RECT rt;
			if (CaretInfo.m_CaretInWichPart == CARET_IN_PART5)
			{
				m_Part5.GetHexsRect(nBufferIndex,&rt);
			}else if(CaretInfo.m_CaretInWichPart == CARET_IN_PART6)
			{
				m_Part6.GetHexsRect(nBufferIndex,&rt);
			}else
			{
				return 0;
			}

			//相对坐标转化成绝对的坐标
			rt.top += m_nScorBarVPos*m_nRowHeight;

			m_Caret.SetPos(rt.left,rt.top);
			m_Caret.Show(TRUE);

			//还要分是否按住了 ctrl键
			if(GetAsyncKeyState(VK_SHIFT)&0x8000)
			{
				//多选
				m_SelectEnd = CaretInfo;
				XEle_RedrawEle(m_hScrollView);
			}else
			{
				//设置当前光标位置
				m_SelectEnd = CaretInfo;
				m_SelectStart = CaretInfo;
			}

		}

		if (wParam == 90 && GetAsyncKeyState(VK_CONTROL)&0x8000)
		{
			//撤销修改
			m_ModData.pop(NULL,NULL);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}

		return 0;
	}
	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		SIZE LineSize;
		XSView_GetLineSize(m_hScrollView,&LineSize);
		pPt->x += LineSize.cx*m_nScorBarHPos; //点击位置是相对位置要转换成绝对位置


		RECT rt;
		m_Part5.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{
			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width)/(m_nPart2BlockWidth+m_nPart2BlockSpace);
			int nRowIndex = (pPt->y - m_PaddingTop - m_nRowHeight)/m_nRowHeight;
			//如果当前点击坐标所在索引大于可显示数量则忽略
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;

			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);

			m_SelectStart.m_CaretInWichPart = CARET_IN_PART5;
			m_SelectStart.m_DataIndex = nOffsetIndex;

			

			RECT rtCh;
			m_Part5.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);

			char ch = m_Buffer.m_pBuffer[nRowIndex *16 + nColIndex];
			wchar_t* pHexChar = m_Format.CharToHexStr((wchar_t)ch);
			int chWidth = m_MemDC.GetTextWidth(pHexChar+2,1);




			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;
			if (pPt->x > rtCh.left+chWidth)
			{
				nCaretPosX = rtCh.left+chWidth;
				m_SelectStart.m_TextIndex = 1;
			}else
			{
				nCaretPosX = rtCh.left;
				m_SelectStart.m_TextIndex = 0;
			}

			//保存光标位置
			m_SelectEnd = m_SelectStart;

			//相对坐标转化成绝对的坐标
			nCaretPosY += m_nScorBarVPos*LineSize.cy;

			//最后显示光标
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);

			
			xtrace("caret in part5  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		m_Part6.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{
			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width - SPLIT1_WIDTH - m_Part2Width - SPLIT2_WIDTH )/(m_nPart3BlockWidth);
			int nRowIndex = (pPt->y - m_nRowHeight)/m_nRowHeight;
			//如果当前点击坐标所在索引大于可显示数量则忽略
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;
			
			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);


			m_SelectStart.m_CaretInWichPart = CARET_IN_PART6;
			m_SelectStart.m_DataIndex = nOffsetIndex;
			m_SelectStart.m_TextIndex = 0;

			m_SelectEnd = m_SelectStart;

			RECT rtCh;
			m_Part6.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);

			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;

			//相对坐标转化成绝对的坐标
			nCaretPosY += m_nScorBarVPos*m_nRowHeight;
			//最后显示光标
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);

			

			xtrace("caret in part6  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		return 0;
	}
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)
	{

		SIZE LineSize;
		XSView_GetLineSize(m_hScrollView,&LineSize);
		pPt->x += LineSize.cx*m_nScorBarHPos;

		m_MousePosX = pPt->x ;
		m_MousePosy = pPt->y;

		if ( (nFlags & MK_LBUTTON) == 0)
		{
			XEle_RedrawEle(m_hScrollView,FALSE);
			return 0;
		}

		RECT rt;
		m_Part5.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{
			if (CARET_IN_PART6 == m_SelectStart.m_CaretInWichPart)
			{
				//鼠标按下的时候是 在 part6 但是当前为part5，直接忽略
				XEle_RedrawEle(m_hScrollView);
				return 0;
			}
			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width)/(m_nPart2BlockWidth+m_nPart2BlockSpace);
			int nRowIndex = (pPt->y - m_PaddingTop - m_nRowHeight)/m_nRowHeight;
			//如果当前点击坐标所在索引大于可显示数量则忽略
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;			

			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);
			
			m_SelectEnd.m_CaretInWichPart = CARET_IN_PART5;
			m_SelectEnd.m_DataIndex = nOffsetIndex;
			
			
			RECT rtCh;
			m_Part5.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);
			
			char ch = m_Buffer.m_pBuffer[nRowIndex *16 + nColIndex];
			wchar_t* pHexChar = m_Format.CharToHexStr((wchar_t)ch);
			int chWidth = m_MemDC.GetTextWidth(pHexChar+2,1);
			
			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;
			if (pPt->x > rtCh.left+chWidth)
			{
				nCaretPosX = rtCh.left+chWidth;
				m_SelectEnd.m_TextIndex = 1;
			}else
			{
				nCaretPosX = rtCh.left;
				m_SelectEnd.m_TextIndex = 0;
			}
			
			
			//相对坐标转化成绝对的坐标
			nCaretPosY += m_nScorBarVPos*m_nRowHeight;
			
			//最后显示光标
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);
			
			
			xtrace("caret in part5  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}
		m_Part6.GetRect(&rt);
		if (IsPtInRect2(pPt,&rt))
		{

			if (m_SelectStart.m_CaretInWichPart == CARET_IN_PART5)
			{
				//鼠标按下的时候是 在 part5 但是当前为part，直接忽略
				XEle_RedrawEle(m_hScrollView);
				return 0;
			}

			int nColIndex = (pPt->x - m_PaddingLeft - m_Part1Width - SPLIT1_WIDTH - m_Part2Width - SPLIT2_WIDTH )/(m_nPart3BlockWidth);
			int nRowIndex = (pPt->y - m_nRowHeight)/m_nRowHeight;
			
			//如果当前点击坐标所在索引大于可显示数量则忽略
			if (nRowIndex *16 + nColIndex >= m_nRealShowSize)
				return 0;

			int nOffsetIndex = nRowIndex *16 + nColIndex + m_nScorBarVPos*16;
			wchar_t txtBuffer[9] = {0};
			wsprintfW(txtBuffer,L"%08X",nOffsetIndex);
			m_part1.SetText(txtBuffer);
			
			
			m_SelectEnd.m_CaretInWichPart = CARET_IN_PART6;
			m_SelectEnd.m_DataIndex = nOffsetIndex;
			m_SelectEnd.m_TextIndex = 0;
			

			
			RECT rtCh;
			m_Part6.GetHexsRect(nRowIndex *16 + nColIndex,&rtCh);
			
			int nCaretPosX = rtCh.left;
			int nCaretPosY = rtCh.top;
			
			//相对坐标转化成绝对的坐标
			nCaretPosY += m_nScorBarVPos*m_nRowHeight;
			//最后显示光标
			m_Caret.SetPos(nCaretPosX,nCaretPosY);
			m_Caret.Show(TRUE);
			
			
			
			xtrace("caret in part6  Col=%d row=%d \r\n",nColIndex,nRowIndex);
			XEle_RedrawEle(m_hScrollView);
			return 0;
		}




		XEle_RedrawEle(m_hScrollView,FALSE);




		return 0;
	}
	int OnSize(BOOL *pbHandled)
	{
		//当窗口元素大小变化后，导致滚动条范围大小变化，
		//此时滚动条所在位置


		//控件大小变化，需要做几件事

		//1 重新计算缓冲区大小
		//2 重新读取指定位置数据
		//3 重新计算各个part的坐标
		//4 重新定位插入符Caret坐标

		m_cx = XEle_GetWidth(m_hScrollView);
		m_cy = XEle_GetHeight(m_hScrollView);
		m_MemDC.Resize(1000,m_cy);

		//计算当前元素最大能显示多少个字符
	    int cy = m_cy - m_PaddingTop - m_nRowHeight;
		int nShowBufferSize = (cy / m_nRowHeight + ((cy % m_nRowHeight)?1:0))*16;
		m_Buffer.ReSize(nShowBufferSize);

		XEle_SendEvent(m_hScrollView,m_hScrollView,XE_SCROLLVIEW_SCROLL_V,(WPARAM)m_nScorBarVPos,NULL);

#ifdef _DEBUG
		xtrace("ViewPosH %d %d --\r\n",XSView_GetViewPosH(m_hScrollView),XSView_GetViewPosV(m_hScrollView));
#endif
// 		m_File.SetPoint(m_nScorBarVPos*16);
// 
// 		m_File.Read(m_Buffer.m_pBuffer,m_Buffer.m_MaxShowCount,&m_nRealShowSize);
// 
// #ifdef _DEBUG
// 		xtrace("调整大小前后实际显示数量 %d %d\r\n",nShowBufferSize,m_nRealShowSize);
// #endif
// 
// 		m_nRealRowCount = m_nRealShowSize / 16 + (m_nRealShowSize%16?1:0);
// 		m_Part4.SetRowCount(m_nRealRowCount);
// 
// 
// 		m_Part5.ReSize(m_nRealShowSize);
// 		m_Part6.ReSize(m_nRealShowSize);
// 
// 		AutoCalcPartsRect();

		
		return 0;
	}
    int  OnScrollViewScrollH(int pos,BOOL *pbHandled)
    {
		m_nScorBarHPos = pos;
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

		m_File.SetPoint(m_nScorBarVPos*16);
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


		m_MemDC.SetTextColor(RGB(128,18,0));
		// draw offset 
		m_part1.Draw(&m_MemDC);	
		m_MemDC.SetTextColor(RGB(0,0,128));
		m_part2.Draw(&m_MemDC);
		m_Part3.Draw(&m_MemDC);
		m_MemDC.SetTextColor(0);
		m_Part4.Draw(&m_MemDC);

#ifdef _DEBUG
		xtrace("type=%d Index=%d tpye=%d Index =%d\r\n",m_SelectStart.m_CaretInWichPart,m_SelectStart.m_DataIndex,
			m_SelectEnd.m_CaretInWichPart,m_SelectEnd.m_DataIndex);
#endif
		//这里需要判断是否有选中
		if (m_SelectStart.m_DataIndex == m_SelectEnd.m_DataIndex)
		{
			//没有选中
			wchar_t buffer[10] = {0};
			RECT rt;
			int nScrollPos = m_nScorBarVPos*16;
			char Modifych;

			for (int k = 0 ; k < m_Part5.GetArrayCount(); k++)
			{
				m_Part5.GetHexsRect(k,&rt);
				if (m_ModData.IsDataModify(k+nScrollPos,&Modifych))
				{
					//是修改过的数据
					wchar_t* pStrHex= m_Format.CharToHexStr(Modifych);
					COLORREF oldCor = m_MemDC.SetTextColor(RGB(255,0,0));
					m_MemDC.TextOutW(rt.left,rt.top,pStrHex+2,2);
					m_MemDC.SetTextColor(oldCor);

				}else
				{   //数据没有修改过
					wchar_t* pStrHex = m_Format.CharToHexStr((wchar_t)(m_Buffer.m_pBuffer[k]));
					m_MemDC.TextOutW(rt.left,rt.top,pStrHex+2,2);
				}
			}
			
			RECT rt6;
			for (int m = 0 ; m < m_Part6.GetArrayCount();m++)
			{
				m_Part6.GetHexsRect(m,&rt6);

				if (m_ModData.IsDataModify(m+nScrollPos,&Modifych))
				{
					//是修改过的数据
					COLORREF oldCor = m_MemDC.SetTextColor(RGB(255,0,0));
					m_MemDC.TextOutA(rt6.left,rt6.top,m_HexFilter.Filter(&Modifych),1);
					m_MemDC.SetTextColor(oldCor);
					
				}else
				{   //数据没有修改过
					m_MemDC.TextOutA(rt6.left,rt6.top,m_HexFilter.Filter(m_Buffer.m_pBuffer+m),1);
				}
			}

		}else{
			//有选中

			int nSelectStart = 0;
			int nSelectEnd   = 0;
			if (m_SelectStart.m_DataIndex > m_SelectEnd.m_DataIndex)
			{
				nSelectStart = m_SelectEnd.m_DataIndex;
				nSelectEnd   = m_SelectStart.m_DataIndex;
			} 
			else
			{
				nSelectStart = m_SelectStart.m_DataIndex;
				nSelectEnd   = m_SelectEnd.m_DataIndex;
			}

#ifdef _DEBUG
			xtrace("select start = %d  select end = %d \r\n",nSelectStart,nSelectEnd);
#endif
			wchar_t buffer[10] = {0};
			RECT rt;
			int  tmpIndex = 0; //把字符的相对索引转换成绝对索引 才能判断
			COLORREF corBk;
			COLORREF corText;
			int nScorPos = m_nScorBarVPos*16;
			for (int k = 0 ; k < m_Part5.GetArrayCount(); k++)
			{
				tmpIndex = k + nScorPos;
				if ( (tmpIndex >= nSelectStart) && (tmpIndex <= nSelectEnd) )
				{
					corBk = m_MemDC.SetBkColor(RGB(0,0,128));
					corText = m_MemDC.SetTextColor(RGB(255,255,255));
				}else
				{
					corBk = m_MemDC.SetBkColor(RGB(255,255,255));
					corText = m_MemDC.SetTextColor(RGB(0,0,0));
				}
				m_Part5.GetHexsRect(k,&rt);
				wchar_t* pStrHex = m_Format.CharToHexStr((wchar_t)(m_Buffer.m_pBuffer[k]));
				m_MemDC.TextOutW(rt.left,rt.top,pStrHex+2,2);
				m_MemDC.SetBkColor(corBk);
				m_MemDC.SetTextColor(corText);
			}
			
			RECT rt6;
			for (int m = 0 ; m < m_Part6.GetArrayCount();m++)
			{
				tmpIndex = m + nScorPos;
				if ( (tmpIndex >= nSelectStart) && (tmpIndex <= nSelectEnd) )
				{
					corBk = m_MemDC.SetBkColor(RGB(0,0,128));
					corText = m_MemDC.SetTextColor(RGB(255,255,255));
				}else
				{
					corBk = m_MemDC.SetBkColor(RGB(255,255,255));
					corText = m_MemDC.SetTextColor(RGB(0,0,0));
				}

				m_Part6.GetHexsRect(m,&rt6);
				m_MemDC.TextOutA(rt6.left,rt6.top,m_HexFilter.Filter(m_Buffer.m_pBuffer+m),1);

				m_MemDC.SetBkColor(corBk);
				m_MemDC.SetTextColor(corText);
			}

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

		m_Part1Width = m_MemDC.GetTextWidth(L"00000000",8);

		int offsetX = m_PaddingLeft;
		int offsetY = m_PaddingTop;
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
		m_Part5.SetRect(x,y,m_Part2Width,m_cy-m_nRowHeight-offsetY);
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


	int m_PaddingLeft;
	int m_PaddingTop;
	//行数索引文本的宽度
	int m_Part1Width;
	int m_Part2Width;
	int m_Part3Width;

	int m_nPart2BlockWidth; //中间16进制文本 单个宽度
	int m_nPart2BlockSpace; //中间16进制文本 间距

	int m_nPart3BlockWidth; //中间16进制文本 单个宽度

	int m_nRowHeight;

	int  m_nScorBarVPos;
	int  m_nScorBarHPos; //水平滚动位置

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

	XHexFilter m_HexFilter;

	typedef struct _tagSelect 
	{
		CARET_IN_ m_CaretInWichPart;
		int       m_TextIndex; // 比如 FF 光标是 0,1 |FF 还是 F|F 如果是 part6 只有 0
		int       m_DataIndex; //绝对坐标 buffer 偏移 + 滚动条pos
	}SELECT,*PSELECT;

	XCaret m_Caret;
	SELECT m_SelectStart;
	SELECT m_SelectEnd;
	

	XModiyData m_ModData;
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