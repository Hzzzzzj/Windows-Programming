// filetreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "filetree.h"
#include "filetreeDlg.h"

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
// CFiletreeDlg dialog

CFiletreeDlg::CFiletreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFiletreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFiletreeDlg)
	m_FileName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFiletreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFiletreeDlg)
	DDX_Control(pDX, IDC_TREE1, m_FileTree);
	DDX_Text(pDX, IDC_EDIT_NAME, m_FileName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFiletreeDlg, CDialog)
	//{{AFX_MSG_MAP(CFiletreeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnDblclkTree1)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiletreeDlg message handlers

BOOL CFiletreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//	m_iImageList.Create(24, 24, TRUE,1, 0);
	//HICON hIcon = NULL;
//	hIcon = (HICON)::LoadImage(::AfxGetInstanceHandle(), 
//		MAKEINTRESOURCE(IDR_MAINFRAME), IMAGE_ICON, 24, 24, 0);
//	m_iImageList.Add(hIcon);
//	m_FileTree.SetImageList ( &m_iImageList,TVSIL_NORMAL );
	BrowseFile(0,"c:");//遍历"成绩表"文件夹内的所有目录

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFiletreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFiletreeDlg::OnPaint() 
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
void CFiletreeDlg::BrowseFile(int CALLNUM,CString strFile)
{
     CALLNUM++;
	 CFileFind ff;
	 CString szDir=strFile;

	 if(szDir.Right(1)!="\\")
	 {
	      szDir+="\\";
	 }
	 szDir += "*.*";

		BOOL res = ff.FindFile(szDir);
	while(res)
	{
	     res=ff.FindNextFile();
		 if(ff.IsDirectory()&&!ff.IsDots())
		 {
		     CString strPath=ff.GetFilePath();
			 CString strTitle=ff.GetFileName();
			 int i=0;
			/*
			switch(CALLNUM)
			 {
			 case 1:
					strHTFir = m_FileTree.InsertItem(strTitle,0,0,NULL);						
					break;
				case 2:
					strHTSec = m_FileTree.InsertItem(strTitle,0,0,strHTFir);											
					break;
				case 3:
					strHtThi = m_FileTree.InsertItem(strTitle,0,0,strHTSec);					
					break;
				case 4:
					strHtFor = m_FileTree.InsertItem(strTitle,0,0,strHtThi);					
					break;
				default:
					strHtFif = m_FileTree.InsertItem(strTitle,0,0,strHtFor);
					break;
			 }
			 */
			 if(CALLNUM==1)
			 {
			     strHt[1] = m_FileTree.InsertItem(strTitle,0,0,NULL);	
			 }
			 else
			 {
			     	strHt[CALLNUM] = m_FileTree.InsertItem(strTitle,0,0,strHt[CALLNUM-1]);
			 }
			 BrowseFile(CALLNUM,strPath);
		 }
		 else if(!ff.IsDirectory()&&!ff.IsDots())
		 {
		      	CString strPath;
			CString strTitle;
			strPath = ff.GetFilePath();
			strTitle = ff.GetFileName();
		/*	switch(CALLNUM)
			{
			case 1:
				strRoot = m_FileTree.InsertItem(strTitle,0,0,NULL);
				break;
			case 2:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHTFir);
				break;
			case 3:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHTSec);				
				break;
			case 4:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHtThi);
				break;
			case 5:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHtFor);
				break;
			default:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHtFif);
				break;
				}
				*/
			if(CALLNUM==1)
			{
			    strRoot = m_FileTree.InsertItem(strTitle,0,0,NULL);
			}
			else
			{
			  strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHt[CALLNUM-1]);  
			}
		
		 }
	}
	 ff.Close();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFiletreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
CString str = "c:";


void CFiletreeDlg::OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
    HTREEITEM s = m_FileTree.GetSelectedItem();
   
	str+="/";
	str+=m_FileTree.GetItemText(s);
	
    GetDlgItem(IDC_EDIT_NAME)->SetWindowText(str);

    //AfxMessageBox(str);
	*pResult = 0;

}
