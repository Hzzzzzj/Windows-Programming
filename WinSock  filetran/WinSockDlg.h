// WinSockDlg.h : header file
//

#if !defined(AFX_WINSOCKDLG_H__9C33A884_A02C_4875_8CF1_1868DB68DF02__INCLUDED_)
#define AFX_WINSOCKDLG_H__9C33A884_A02C_4875_8CF1_1868DB68DF02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWinSockDlg dialog
#define SEND_BUFFER_SIZE 1024
#define RECV_BUFFER_SIZE 1024

#define UM_PRGRECV  WM_USER+10
#define UM_PRGSEND  WM_USER+11
#define UM_PRGRBGN  WM_USER+15
#define UM_PRGSBGN  WM_USER+17
#define UM_PRGSOVER WM_USER+13
#define UM_PRGROVER WM_USER+12
#define UM_PRGRRDY  WM_USER+14
class CWinSockDlg : public CDialog
{
// Construction
public:
	CWinSockDlg(CWnd* pParent = NULL);	// standard constructor
    static DWORD WINAPI SocketRecv(LPVOID lpParameter);
	static  DWORD WINAPI SocketSend(LPVOID lpParameter);
// Dialog Data
	//{{AFX_DATA(CWinSockDlg)
	enum { IDD = IDD_WINSOCK_DIALOG };
	CProgressCtrl	m_prgsend;
	CProgressCtrl	m_prgrecv;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinSockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
 
	// Generated message map functions
	//{{AFX_MSG(CWinSockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpen();
	afx_msg void OnRecv();
	afx_msg void OnSend();
	//}}AFX_MSG
	afx_msg void onprgrbgn(WPARAM wParam,LPARAM lParam);
	afx_msg void onprgsbgn(WPARAM wParam,LPARAM lParam);
	afx_msg void onprgsend(WPARAM wParam,LPARAM lParam);
	afx_msg void onprgsover(WPARAM wParam,LPARAM lParam);
	afx_msg void onprgrecv(WPARAM wParam,LPARAM lParam);
	afx_msg void onprgrover(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CString m_sendfname;
	BOOL m_beginprgsend;
	int m_prgsendpre;
	BOOL m_beginprgrecv;
    int m_prgrecvpre;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINSOCKDLG_H__9C33A884_A02C_4875_8CF1_1868DB68DF02__INCLUDED_)
