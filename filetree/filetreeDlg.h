// filetreeDlg.h : header file
//

#if !defined(AFX_FILETREEDLG_H__4A9AA7E5_081E_4849_8BD3_4B2EF37787B8__INCLUDED_)
#define AFX_FILETREEDLG_H__4A9AA7E5_081E_4849_8BD3_4B2EF37787B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFiletreeDlg dialog

class CFiletreeDlg : public CDialog
{
// Construction
public:
	CFiletreeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFiletreeDlg)
	enum { IDD = IDD_FILETREE_DIALOG };
	CTreeCtrl	m_FileTree;
	CString	m_FileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiletreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

		void BrowseFile(int CallNum,CString strFile);

	CImageList m_iImageList;//Õº±Í¡¥
	HTREEITEM strRoot;
/*	HTREEITEM strHTFir;
	HTREEITEM strHTSec;
	HTREEITEM strHtThi;
	HTREEITEM strHtFor;
	HTREEITEM strHtFif;
*/	HTREEITEM strHtEnd;

	HTREEITEM strHt[50];
	// Generated message map functions
	//{{AFX_MSG(CFiletreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETREEDLG_H__4A9AA7E5_081E_4849_8BD3_4B2EF37787B8__INCLUDED_)
