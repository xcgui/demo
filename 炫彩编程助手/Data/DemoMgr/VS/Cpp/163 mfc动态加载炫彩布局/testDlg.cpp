// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

int CALLBACK OnWndLButtonDown(HWINDOW hWindow,UINT nFlags,POINT *pPt,BOOL *pbHandled)
{
	HWND hWndFocus =  GetFocus();
	if (hWndFocus != XWnd_GetHWND(hWindow))
	{
		SetFocus(XWnd_GetHWND(hWindow));
		SetActiveWindow( XWnd_GetHWND(hWindow));
		
//		XWnd_SetFocusEle(NULL,XWnd_GetFocusEle(NULL));
	}
	

	
	

	return 0;
}
int CALLBACK OnWndKeyDown(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{

	return 0;
}
int CALLBACK OnWndChar(WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	OutputDebugString("OnWndChar \r\n");
	return 0;
}


int CALLBACK EleOnLButtonDown(HELE hEle,UINT nFlags, POINT *pPt,BOOL *pbHandled)
{
	XWnd_SetFocusEle(XEle_GetHWINDOW(hEle),hEle);
	return 0;
}
int CALLBACK EleOnEventKeyDown(HELE hEle,WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{

	return 0;
}

int CALLBACK OnEventChar(HELE hEle,WPARAM wParam,LPARAM lParam,BOOL *pbHandled)
{
	OutputDebugString("OnEventChar \r\n");
	return 0;
}


BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_hWindow = XWnd_CreateEx(NULL,NULL,NULL,WS_OVERLAPPEDWINDOW|WS_CHILD|WS_VISIBLE,0,0,500,400,m_hWnd);

	HXCGUI hLayoutBody = XLayout_Create();
	XWnd_BindLayoutObject(m_hWindow,window_position_body,hLayoutBody);
	XLayout_SetLayoutWidth(hLayoutBody,layout_size_type_fill,1);
	XLayout_SetLayoutHeight(hLayoutBody,layout_size_type_fill,1);

	
	HELE hLayoutPane1 = (HELE)XC_LoadLayout(L"加载布局面板\\面板1.xml",m_hWindow);
	XLayout_AddEle(hLayoutBody,hLayoutPane1);
	
	XEle_SetLayoutHeight(hLayoutPane1,layout_size_type_fill,1);
	XEle_SetLayoutWidth(hLayoutPane1,layout_size_type_fill,1);	
	
	XWnd_RegEventC1(m_hWindow,WM_LBUTTONDOWN,OnWndLButtonDown);
	XWnd_RegEventC(m_hWindow,WM_KEYDOWN,OnWndKeyDown);
	XWnd_RegEventC(m_hWindow,WM_CHAR,OnWndChar);


	XEle_RegEventC1((HELE)XC_GetObjectByID(m_hWindow,20),XE_LBUTTONDOWN,EleOnLButtonDown);
	XEle_RegEventC1((HELE)XC_GetObjectByID(m_hWindow,20),XE_KEYDOWN,EleOnEventKeyDown);
	XEle_RegEventC1((HELE)XC_GetObjectByID(m_hWindow,20),XE_CHAR,OnEventChar);

	XWnd_AdjustLayout(m_hWindow);
	XWnd_ShowWindow(m_hWindow,SW_SHOW); //显示窗口
		

		
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CTestDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message==WM_CHAR)
	{
// 		if (::GetFocus() == XWnd_GetHWND(m_hWindow))
// 		{
// 			::SendMessage(XWnd_GetHWND(m_hWindow),pMsg->message,pMsg->wParam,pMsg->lParam);  
// 			
// 		}
		
		OutputDebugString("aaaaaaaaaaaaa\r\n");
		return false;  
	
	}
	return CDialog::PreTranslateMessage(pMsg);
}
