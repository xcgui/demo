#if !defined(AFX_MFCDLG_H__F893F553_3749_4B79_B43D_B7E3ABE2378C__INCLUDED_)
#define AFX_MFCDLG_H__F893F553_3749_4B79_B43D_B7E3ABE2378C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MFCDlg.h : header file
//
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// CMFCDlg dialog

class CMFCDlg : public CDialog
{
// Construction
public:
	CMFCDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMFCDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDLG_H__F893F553_3749_4B79_B43D_B7E3ABE2378C__INCLUDED_)
