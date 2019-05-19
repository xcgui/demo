// WinMainView.cpp : implementation of the CWinMainView class
//

#include "stdafx.h"
#include "WinMain.h"

#include "WinMainDoc.h"
#include "WinMainView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinMainView

IMPLEMENT_DYNCREATE(CWinMainView, CView)

BEGIN_MESSAGE_MAP(CWinMainView, CView)
	//{{AFX_MSG_MAP(CWinMainView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinMainView construction/destruction

CWinMainView::CWinMainView()
{
	// TODO: add construction code here

}

CWinMainView::~CWinMainView()
{
}

BOOL CWinMainView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWinMainView drawing

void CWinMainView::OnDraw(CDC* pDC)
{
	CWinMainDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CWinMainView printing

BOOL CWinMainView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWinMainView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWinMainView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWinMainView diagnostics

#ifdef _DEBUG
void CWinMainView::AssertValid() const
{
	CView::AssertValid();
}

void CWinMainView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinMainDoc* CWinMainView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinMainDoc)));
	return (CWinMainDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWinMainView message handlers

int CWinMainView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_hWindow = XWnd_CreateEx(
		0,NULL,L"Ï≈≤ ΩÁ√Êø‚",WS_CHILD|WS_VISIBLE,0,0,200,100,m_hWnd);
	XWnd_ShowWindow(m_hWindow,SW_SHOW);
	return 0;
}

void CWinMainView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	::MoveWindow(XWnd_GetHWND(m_hWindow),0,0,cx,cy,FALSE);
	// TODO: Add your message handler code here
}
