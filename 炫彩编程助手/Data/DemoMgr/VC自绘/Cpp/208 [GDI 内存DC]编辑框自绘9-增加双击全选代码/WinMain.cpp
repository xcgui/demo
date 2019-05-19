#define  USE_GDIPACK
#define USE_GDIPLUS
#include "Common.h"
#include "DrawPack.h"



//把文字偏移和文本封装成一个整体，减少外部变量
//增加程序的可读性
class XVString
{
public:
	XVString()
	{
		m_nTextShowOffset = 0;
	}
	VOID SetText(const wchar_t* lpText)
	{
		m_Text = lpText;
	}
	VOID SetVOffset(int nTextShowOffset)
	{
		m_nTextShowOffset = nTextShowOffset;
	}
	int  GetVOffset()
	{
		return m_nTextShowOffset;
	}
	const wchar_t* GetVText()
	{
		return  m_Text.c_str()+m_nTextShowOffset;
	}
	size_t GetVLen()
	{
		return m_Text.length()-m_nTextShowOffset;
	}
	void DeleteCh(int nPos)
	{
		m_Text.erase(m_Text.begin()+m_nTextShowOffset+nPos);
	}
	void InsertCh(int nPos,wchar_t ch)
	{
		m_Text.insert(m_Text.begin()+m_nTextShowOffset+nPos,ch);
	}
public:


private:
	//文字显示偏移
	int			 m_nTextShowOffset;
	std::wstring m_Text;
};



class CMyWnd
{
public:
    HWINDOW m_hWindow; //窗口句柄
	HELE    m_hEle;

	XGDIMEMDC m_memDC;
	XCaret    m_Caret;

	XVString  m_Text;
	
	RECT         m_RectText;
	int			 m_CaretInTextIndex;

	

	BOOL     m_bFullSelect;

	
    BOOL Create()
    {
        m_hWindow=XWnd_Create(0,0,350,350,L"炫彩界面库-窗口"); //创建窗口
        if(m_hWindow)
        {
 			m_hEle = XEle_Create(8,35,105,20,m_hWindow);

			m_memDC.Create(XEle_GetHWND(m_hEle));
			m_memDC.Resize(300,300);


			//初始化字符串和字符串所占的矩形
			m_Text.SetText(L"炫彩界面库-www.xcgui.com");
			SIZE sz;
			m_memDC.GetTextSize(m_Text.GetVText(),m_Text.GetVLen(),&sz);
			m_RectText.left  = 0;
			m_RectText.top   = 0;
			m_RectText.right = 100;
			m_RectText.bottom = 20;

			//光标是自绘可编辑控件不可缺少的东西
			m_Caret.Create(m_hEle);
			m_Caret.SetHeight(sz.cy);

			m_bFullSelect = FALSE;



			XEle_RegEventCPP(m_hEle,XE_LBUTTONDOWN,&CMyWnd::OnLButtonDown);
			XEle_RegEventCPP(m_hEle,XE_LBUTTONUP,&CMyWnd::OnLButtonUp);
			XEle_RegEventCPP(m_hEle,XE_LBUTTONDBCLICK,&CMyWnd::OnLButtonDBClick);
			XEle_RegEventCPP(m_hEle,XE_CHAR,&CMyWnd::OnEventChar);
			XEle_RegEventCPP(m_hEle,XE_KEYDOWN,&CMyWnd::OnEventKeyDown);
			XEle_RegEventCPP(m_hEle,XE_MOUSEMOVE,&CMyWnd::OnMouseMove);
			XEle_RegEventCPP(m_hEle,XE_PAINT, &CMyWnd::OnDraw);

            XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
            return TRUE;
        }
        return FALSE;
    }
	int OnLButtonDBClick(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		if (m_bFullSelect == FALSE)
		{
			m_bFullSelect = TRUE;
			XEle_RedrawEle(m_hEle);
		}
		return 0;
	}

	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		m_memDC.SelectObject(m_memDC.GetStockObject(DC_BRUSH));
		m_memDC.SetDCBrushColor(RGB(128,128,128));
		m_memDC.FillRect(0,0,300,300);
		m_memDC.SetBkMode(TRANSPARENT); //让文字背景透明


		m_memDC.SelectObject(m_memDC.GetStockObject(DC_PEN));
		if (m_bFullSelect)
		{
			m_memDC.SetDCBrushColor(RGB(0,0,128));
			SIZE  sz;
			m_memDC.GetTextSize(m_Text.GetVText(),m_Text.GetVLen(),&sz);
			RECT rt={0};
			rt.right = sz.cx;
			rt.bottom = sz.cy;
			m_memDC.FillRect(&rt);

			m_memDC.SetTextColor(RGB(255,255,255));
		}else
		{
			m_memDC.SetTextColor(RGB(0,0,0));
		}
//绘制文本
		
		
		m_memDC.TextOutW(
			m_RectText.left,
			m_RectText.top,
			m_Text.GetVText(),m_Text.GetVLen());


		m_memDC.BitBlt1(hDraw);
		return 0;
	}

	int OnLButtonDown(UINT nFlags, POINT *pPt,BOOL *pbHandled)
	{
		if (m_bFullSelect == TRUE)
		{
			m_bFullSelect = FALSE;
			XEle_RedrawEle(m_hEle);
		}
		//首先我们需要判断点击位置是否在文字矩形内
		if (IsPtInRect2(pPt,&m_RectText) == FALSE)
		{
			//如果不在 隐藏光标，返回
			m_Caret.Show(FALSE);
			return 0;
		}
		
		//如果在，得判断出所在字符串位置索引
		int nLeftWidth = 0;
		int nCharLen   = 0;
		for (int i = 0; i < m_Text.GetVLen(); i++)
		{
			nCharLen = m_memDC.GetTextWidth(m_Text.GetVText()+i,1);
			if (m_RectText.left + nLeftWidth + nCharLen > pPt->x)
			{
				m_CaretInTextIndex = i;
				break;
			}
			nLeftWidth+=nCharLen;
		}

		m_Caret.SetPos(m_RectText.left + nLeftWidth,m_RectText.top);
		m_Caret.Show(TRUE);
		//刷新一下
		XEle_RedrawEle(m_hEle);

		return 0;
	}
	int OnLButtonUp(UINT nFlags, POINT *pPt,BOOL *pbHandled)	{		return 0;	}
	int OnMouseMove(UINT nFlags, POINT *pPt, BOOL *pbHandled)	{		return 0;	}

	int GetShowCount()
	{
		int nLeftWidth = 0;
		int nCharWidth = 0;
		int nEdithWidth = m_RectText.right-m_RectText.left;

		int i;
		for (i = 0; i < m_Text.GetVLen(); i++)
		{
			nCharWidth = m_memDC.GetTextWidth(m_Text.GetVText()+i,1);
			if (nLeftWidth+nCharWidth > nEdithWidth)
			{
				break;
			}
			nLeftWidth+=nCharWidth;
		}
		return i;
	}

	int OnEventKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		switch (wParam)
		{
		case VK_LEFT:
			{

				if (m_CaretInTextIndex == 0)
				{
					int nOffset = m_Text.GetVOffset();
					if (nOffset>3)
					{
						nOffset -=3;
						m_CaretInTextIndex+=2;
					}else if (nOffset>2)
					{
						nOffset-=2;
						m_CaretInTextIndex++;
					}else if (nOffset > 1)
					{
						nOffset--;
					}else
					{
						return 0;
					}
					m_Text.SetVOffset(nOffset);
				}else
				{
					m_CaretInTextIndex--;
				}
				int x = m_RectText.left+m_memDC.GetTextWidth(m_Text.GetVText(),m_CaretInTextIndex);
				int y = m_RectText.top;

				m_Caret.SetPos(x,y);
				XEle_RedrawEle(m_hEle);
			}
			break;
		case VK_RIGHT:
			{
				//这里需要计算一下，因为编辑框有的时候只显示文本中的几个文字
				//被显示的文字后面会有没显示完毕的。所以这里要判断一下

				if (m_CaretInTextIndex == m_Text.GetVLen())
					return 0;//在末尾，直接忽略

				//获取当前显示的最大字符数
				int nMaxEditShowCharCount = GetShowCount();
				//判断当前插入符位置是否再可显示区域的末尾
				if (m_CaretInTextIndex > nMaxEditShowCharCount-1)
				{
					//在末尾，
					int nOffset = m_Text.GetVOffset();
					nOffset+=2;
					m_Text.SetVOffset(nOffset);
					m_CaretInTextIndex--;
				}
				else
				{
					m_CaretInTextIndex++;
				}

				int x = m_RectText.left+m_memDC.GetTextWidth(m_Text.GetVText(),m_CaretInTextIndex);
				int y = m_RectText.top;
				
				m_Caret.SetPos(x,y);
				XEle_RedrawEle(m_hEle);

			}
			break;
		case VK_BACK:
			{
				if (m_Text.GetVOffset()+m_CaretInTextIndex == 0)
				{
					MessageBeep(-1);
					return 0;
				}
				m_Text.DeleteCh(m_CaretInTextIndex-1);
				XEle_PostEvent(m_hEle,m_hEle,XE_KEYDOWN,(WPARAM)VK_LEFT,0);

				*pbHandled = TRUE;
			}
			break;
		}
		return 0;	
	}
	int OnEventChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
	{
		//光标都没显示，就别编辑了
		if (wParam == VK_BACK)
			return 0;
		if (m_Caret.IsCaretShow() == FALSE)
			return 0;

		//光标位置插入字符
		m_Text.InsertCh(m_CaretInTextIndex,(wchar_t)wParam);
		//移动光标
		XEle_PostEvent(m_hEle,m_hEle,XE_KEYDOWN,(WPARAM)VK_RIGHT,0);

		return 0;
	}
};


int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{

    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
        XRunXCGUI(); //运行
    XExitXCGUI(); //释放资源
    return 0;
}




