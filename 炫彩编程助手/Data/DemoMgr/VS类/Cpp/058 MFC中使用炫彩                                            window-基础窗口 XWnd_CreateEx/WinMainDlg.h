// WinMainDlg.h : header file
//

#if !defined(AFX_WINMAINDLG_H__55DE9D01_4E48_4A8B_BF5E_E316531D9528__INCLUDED_)
#define AFX_WINMAINDLG_H__55DE9D01_4E48_4A8B_BF5E_E316531D9528__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWinMainDlg dialog

class CWinMainDlg : public CDialog
{
// Construction
public:
	CWinMainDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWinMainDlg)
	enum { IDD = IDD_WINMAIN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinMainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMAINDLG_H__55DE9D01_4E48_4A8B_BF5E_E316531D9528__INCLUDED_)
