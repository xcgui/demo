// WinMainView.h : interface of the CWinMainView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINMAINVIEW_H__6F3118CB_12AA_4B8E_97C8_2B67A24D1144__INCLUDED_)
#define AFX_WINMAINVIEW_H__6F3118CB_12AA_4B8E_97C8_2B67A24D1144__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWinMainView : public CView
{
protected: // create from serialization only
	CWinMainView();
	DECLARE_DYNCREATE(CWinMainView)

// Attributes
public:
	CWinMainDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinMainView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWinMainView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
	HWINDOW m_hWindow;

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWinMainView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in WinMainView.cpp
inline CWinMainDoc* CWinMainView::GetDocument()
   { return (CWinMainDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMAINVIEW_H__6F3118CB_12AA_4B8E_97C8_2B67A24D1144__INCLUDED_)
