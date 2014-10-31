// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__206573FB_2EC2_42AD_A35B_45E19D9EFBD9__INCLUDED_)
#define AFX_CLIENTDLG_H__206573FB_2EC2_42AD_A35B_45E19D9EFBD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog
typedef struct
{
    char Name[100];
	int FileLen;
	int CMD;
	int seek;
	SOCKET sockid;
}FILEINFO;
typedef struct
{
    FILEINFO fileinfo;
    DWORD ip;
	HWND hwnd;
	int i;
}FILETRAN;

class CClientDlg : public CDialog
{
// Construction
public:
	CClientDlg(CWnd* pParent = NULL);	// standard constructor
    static DWORD WINAPI GetFileThread(LPVOID lparam);
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	int		FileLen;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD ip;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__206573FB_2EC2_42AD_A35B_45E19D9EFBD9__INCLUDED_)
