// FileSplitterDlg.h : header file
//

#if !defined(AFX_FILESPLITTERDLG_H__9DA0533D_1925_4809_9BCB_DB42921D65BF__INCLUDED_)
#define AFX_FILESPLITTERDLG_H__9DA0533D_1925_4809_9BCB_DB42921D65BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileSplitterDlg dialog

class CFileSplitterDlg : public CDialog
{
// Construction
public:
	CFileSplitterDlg(CWnd* pParent = NULL);	// standard constructor

	CFile m_File;
	CString m_FileName;
	CString m_FileTitle;
	CString m_FilePath;


	
// Dialog Data
	//{{AFX_DATA(CFileSplitterDlg)
	enum { IDD = IDD_FILESPLITTER_DIALOG };
	BOOL	m_ifCreate;
	BOOL	m_ifViewReport;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSplitterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileSplitterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelect();
	afx_msg void OnSclose();
	afx_msg void OnSplitter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILESPLITTERDLG_H__9DA0533D_1925_4809_9BCB_DB42921D65BF__INCLUDED_)
