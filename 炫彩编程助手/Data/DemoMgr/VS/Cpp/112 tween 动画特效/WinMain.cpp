#define USE_GDIPLUS
#include "Common.h"

//#else ##plc == 6 \
//virtual double easeIn(double t,double b,double c,double d,double a,double p) 

#include "tween.h"
#include <assert.h>

#include <vector>

enum easings_io_
{
	easings_io_in,
	easings_io_out,
	easings_io_inout,
};

class CEasings
{
public:
	CEasings()
	{
		m_pObj = NULL;
		m_esCurIndex = 0;
	}
	~CEasings()
	{
		Destroy();
	}
	void Destroy()
	{
		if (m_pObj)
		{
			delete m_pObj;
			m_pObj = NULL;
		}
	}
	void Create(easings::est type,int x,int y)
	{
		Destroy();
		switch (type)
		{
		case easings::est_Quad:
			m_pObj = new easings::Quad;
			break;
		case easings::est_Cubic:
			m_pObj = new easings::Cubic;
			break;
		case easings::est_Quart:
			m_pObj = new easings::Quart;
			break;
		case easings::est_Quint:
			m_pObj = new easings::Quint;
			break;
		case easings::est_Sine:
			m_pObj = new easings::Sine;
			break;
		case easings::est_Expo:
			m_pObj = new easings::Expo;
			break;
		case easings::est_Circ:
			m_pObj = new easings::Circ;
			break;
		case easings::est_Elastic:
			m_pObj = new easings::Elastic;
			break;
		case easings::est_Back:
			m_pObj = new easings::Back;
			break;
		case easings::est_Bounce:
			m_pObj = new easings::Bounce;
			break;
		default:
			assert(0);
			break;
		}

		m_x = x;
		m_orgy = y;
		m_y = y;

		double t = 0;
		double d = 100;
		m_ep = easings::CreateParam_All(t,0,100,d);
		m_ptArray.clear();
		{
			double tx = m_x;
			for (double y = t; y <= d; y++)
			{
				POINT pt ={tx,m_orgy+ calcpos(y)};
				m_ptArray.push_back(pt);
				tx++;
			}
		}

		m_esCurIndex = 0;

	}
	double In(int index)
	{
		return m_pObj->In(SetStep(index));
	}
	double Out(int index)
	{
		SetStep(index);
	 	return m_pObj->Out(SetStep(index));
	}
	double InOut(int index)
	{
		SetStep(index);
		return m_pObj->InOut(SetStep(index));
	}

	BOOL IsStepEnd()
	{
		if (m_esCurIndex <= m_ep.d)
		{
			return FALSE;
		}
		return TRUE;
	}
	void ResetStep()
	{
		m_esCurIndex = 0;
	}
	void StepNext()
	{
		m_y = calcpos(m_esCurIndex);
		m_esCurIndex++;
	}

	void SetIO(easings_io_ io)
	{
		m_esiot = io;
	}
public:
	void DrawGraph(HDRAW hDraw)
	{
		if (m_ptArray.size())
		{
			for (size_t t = 0; t < m_ptArray.size(); t++)
			{
				XDraw_SetPixel(hDraw,m_ptArray[t].x,m_ptArray[t].y,255);
			}
		}
	}
	void DrawRectText(HDRAW hDraw,HFONTX hFont,const wchar_t* lpText)
	{
		DrawTextAndRect(hDraw,hFont,m_x,m_orgy+m_y,lpText);
	}

public:

	void DrawRect(HDRAW hDraw,int x1,int y1,int x2,int y2)
	{
		XDraw_DrawLine(hDraw,x1,y1,x2,y1);  //上
		XDraw_DrawLine(hDraw,x1,y2,x2,y2);  //下
		XDraw_DrawLine(hDraw,x1,y1,x1,y2);  //左
		XDraw_DrawLine(hDraw,x2,y1,x2,y2);  //右
	}
	void DrawRect(HDRAW hDraw,RECT rt)
	{
		DrawRect(hDraw,rt.left,rt.top,rt.right,rt.bottom);
	}
	void DrawTextAndRect(HDRAW hDraw,HFONTX hFont,int x,int y,const wchar_t* lpText)
	{
		SIZE textSize;
		XC_GetTextShowSize(lpText,wcslen(lpText),hFont,&textSize);
		RECT rt ={x ,y ,x+textSize.cx,y+textSize.cy};
		DrawRect(hDraw,rt);
		XDraw_DrawText(hDraw,lpText,wcslen(lpText),&rt);
	}

	double calcpos(int step)
	{
		double re = 0.0;
		switch (m_esiot)
		{
		case easings_io_in:
			re = In(step);
			break;
		case easings_io_out:
			re = Out(step);
			break;
		case  easings_io_inout:
			re = InOut(step);
			break;
		default:
			assert(0);
			break;
		}
		
		return re;
	}
private:
	easings::param SetStep(int t)
	{
		easings::param pm = m_ep;
		pm.t = t;
		return pm;
	}

private:
	easings::Object* m_pObj;
	easings::param m_ep;
	vector<POINT> m_ptArray;
	easings_io_ m_esiot;

	int      m_esCurIndex;

	int m_y;
	int m_x;
	int m_orgy;
};




class CMyWindowElement
{
public:
    HWINDOW m_hWindow;
	HELE m_hEle;
	HFONTX m_hFontEle;


	CEasings Quad;

	CEasings m_esarray[10];

    CMyWindowElement(){
        Init();
    }
    void Init()
    {

        m_hWindow = XWnd_Create(0, 0, 500, 400, L"炫彩界面库窗口",NULL, xc_window_style_default);
        XBtn_SetType(XBtn_Create(10, 5, 60, 20,L"close",m_hWindow),button_type_close);
		
		HXCGUI hLayoutBody = XLayout_Create();
		XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);
		XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);
		XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);

		m_hEle = XEle_Create(8,30,484,1000,m_hWindow);
		XLayout_AddEle(hLayoutBody,m_hEle);
		XEle_SetLayoutHeight(m_hEle,layout_size_type_fill,1);
		XEle_SetLayoutWidth(m_hEle,layout_size_type_fill,1);
		XEle_RegEventCPP(m_hEle,XE_PAINT,&CMyWindowElement::OnDraw);


		m_hFontEle = XEle_GetFont(m_hEle);

		XEle_RegEventCPP(
			XBtn_Create(100,5,100,20,L"开始测试",m_hWindow),
			XE_BNCLICK,
			&CMyWindowElement::OnBtnClick);

		XWnd_RegEventCPP(m_hWindow,WM_TIMER,&CMyWindowElement::OnWndTimer);

		XWnd_AdjustLayout(m_hWindow);
        XWnd_ShowWindow(m_hWindow,SW_SHOW);
    }
	int OnBtnClick(BOOL *pbHandled)
	{
		int x = 0;
		int y = 0;
		for (int i = 1; i <=  10; i++)
		{
			m_esarray[i-1].SetIO(easings_io_inout);
			m_esarray[i-1].Create((easings::est)(i-1),x,y);

			if ( (i % 5) == 0)
			{
				y += 100;
				x = 0;
			}else
			{
				x += 100;
			}
		}
		
		
		
		XWnd_SetTimer(m_hWindow,100,10);



		return 0;
	}

	int OnWndTimer(UINT nIDEvent,BOOL *pbHandled)
	{


		for (int i = 0; i <  10; i++)
		{
			if (!m_esarray[i].IsStepEnd())
			{
				m_esarray[i].StepNext();
				XEle_RedrawEle(m_hEle,TRUE);
			} 
			else
			{

				m_esarray[i].ResetStep();
//				XWnd_KillTimer(m_hWindow,nIDEvent);
				break;
			}
		}

		return 0;
	}



	int OnDraw(HDRAW hDraw,BOOL *pbHandled)
	{
		XDraw_SetBrushColor(hDraw,RGB(127,127,127));
// 		DrawTextAndRect(hDraw,XEle_GetFont(m_hEle),0,0,L"大");
// 		DrawTextAndRect(hDraw,XEle_GetFont(m_hEle),0,20,L"大色");
// 		DrawTextAndRect(hDraw,XEle_GetFont(m_hEle),0,40,L"大色秘密");
// 		DrawTextAndRect(hDraw,XEle_GetFont(m_hEle),0,60,L"大大色秘密aAb");
// 		DrawTextAndRect(hDraw,XEle_GetFont(m_hEle),0,80,L"aaaabbccaAb");


		for (int i = 0; i <  10; i++)
		{
			m_esarray[i].DrawGraph(hDraw);
			m_esarray[i].DrawRectText(hDraw,m_hFontEle,L"我");
		}

// 		Quad.DrawGraph(hDraw);
// 		Quad.DrawRectText(hDraw,m_hFontEle,L"我");
// 		DrawGraph(hDraw);
// 		DrawTextAndRect(hDraw,m_hFontEle,0,m_y,L"我");

#if 0
		wchar_t *pText = L"我aabAaaaa";//L"我是炫彩\r\n界面库";
		SIZE textSize;
		XC_GetTextShowSize(pText,wcslen(pText),XEle_GetFont(m_hEle),&textSize);

		RECT rt ={0 ,0 ,textSize.cx,textSize.cy};
		
		XDraw_Rectangle(hDraw,0 ,0 ,textSize.cx,textSize.cy);

		XDraw_SetBrushColor(hDraw,255);
		XDraw_DrawText(hDraw,pText,wcslen(pText),&rt);
#endif // if

#if 0

		SIZE uz;
		XC_GetTextShowSize(L"a",1,XEle_GetFont(m_hEle),&uz);

		OutputDebugStringW(L"10");
#endif


#if 0


		XDraw_SetBrushColor(hDraw,255);
//		XDraw_TextOut(hDraw,0,0,pText,wcslen(pText));

		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = textSize.cy;;
		
		RECT tt = {x1,y1,x2+textSize.cx,textSize.cy};

		for (int i = 1; i <= wcslen(pText); i++)
		{


			XDraw_DrawText(hDraw,pText+i-1,1,&tt);
			XDraw_DrawLine(hDraw,x1,y1,x2,y2);
XC_GetTextShowSize(pText+i-1,1,XEle_GetFont(m_hEle),&textSize);
			x1 += textSize.cx;
			x2 = x1;
			
			tt.left  += textSize.cx;
			tt.right += textSize.cx;
			

		}
//		XDraw_DrawLine(hDraw,0,0,textSize.cx,0);
#endif			
		
//		*pbHandled = TRUE;
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




