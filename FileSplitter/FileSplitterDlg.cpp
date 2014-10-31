// FileSplitterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileSplitter.h"
#include "FileSplitterDlg.h"

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
// CFileSplitterDlg dialog

CFileSplitterDlg::CFileSplitterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileSplitterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileSplitterDlg)
	m_ifCreate = FALSE;
	m_ifViewReport = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileSplitterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileSplitterDlg)
	DDX_Check(pDX, IDC_CHECK1, m_ifCreate);
	DDX_Check(pDX, IDC_CHECK2, m_ifViewReport);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileSplitterDlg, CDialog)
	//{{AFX_MSG_MAP(CFileSplitterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Select, OnSelect)
	ON_BN_CLICKED(ID_SCLOSE, OnSclose)
	ON_BN_CLICKED(ID_SPLITTER, OnSplitter)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileSplitterDlg message handlers

BOOL CFileSplitterDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFileSplitterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileSplitterDlg::OnPaint() 
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
HCURSOR CFileSplitterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileSplitterDlg::OnSelect() 
{
	// TODO: Add your control notification handler code here
    CFileDialog dlg(TRUE);
	if(IDCANCEL==dlg.DoModal())
		return ;
	if(m_File.m_hFile!=CFile::hFileNull)
		OnSclose();
	m_FileName=dlg.GetFileName();
	if(!m_File.Open(m_FileName,CFile::modeRead|CFile::shareDenyWrite))
		::AfxMessageBox("无法打开文件");
	m_FilePath=dlg.GetPathName();
	m_FileTitle=dlg.GetFileTitle();
	GetDlgItem(ID_SPLITTER)->EnableWindow(TRUE);
	GetDlgItem(ID_SCLOSE)->EnableWindow(TRUE);
	SetDlgItemText(IDC_EDIT_PATH,m_FilePath);
	SetDlgItemInt(IDC_EDIT_LENGTH,m_File.GetLength()/1024);
}

void CFileSplitterDlg::OnSclose() 
{
	// TODO: Add your control notification handler code here
    if(m_File.m_hFile!=CFile::hFileNull)
	{
	    m_File.Close();
		GetDlgItem(ID_SPLITTER)->EnableWindow(FALSE);
		GetDlgItem(ID_SCLOSE)->EnableWindow(FALSE);
		SetDlgItemText(IDC_EDIT_PATH,"");
		SetDlgItemInt(IDC_EDIT_LENGTH,0);
	}

}

void CFileSplitterDlg::OnSplitter() 
{
	// TODO: Add your control notification handler code here
	ASSERT(m_File.m_hFile!=CFile::hFileNull);
	DWORD FileLength=m_File.GetLength();
	DWORD PartLength=(DWORD)1024*GetDlgItemInt(IDC_EDIT_SIZE);
    UpdateData();

	int nCount=1;
	CString strName;
	CFile wrFile;
	DWORD ReadBytes;
	 BYTE* pBuf;
	 pBuf = new BYTE[PartLength]; 
	while(1)
	{
	    ReadBytes=m_File.Read(pBuf,PartLength);
		strName.Format("%s.%d",m_FileTitle,nCount);
		wrFile.Open(strName,CFile::modeCreate|CFile::modeWrite);
		wrFile.Write(pBuf,ReadBytes);
		wrFile.Close();
		if(ReadBytes<PartLength)
			break;
		nCount++;
	}
    BOOL bSuccess=((ReadBytes+(nCount-1)*PartLength)==FileLength);
	CString strReport=_T("");

	if(bSuccess&&m_ifCreate)
	{
	    strReport+=_T("copy ");
		for(int i=1;i<nCount;i++)
		{
		   strName.Format("%s.%d /b +",m_FileTitle,i);
		   strReport+=strName;
		}
		strName.Format("%s.%d /b ",m_FileTitle,i);
		strReport+=strName;
		strReport+=m_FileName;
		strName=m_FileTitle+".bat";
		wrFile.Open(strName,CFile::modeCreate|CFile::modeWrite);
		wrFile.Write((LPCTSTR)strReport,strReport.GetLength());
	}
   if(m_ifViewReport)
   {
       strReport=m_FilePath+"\r\n";
	   strReport+=_T("以下为分割文件\r\n");
	   for(int i=1;i<=nCount;i++)
	   {
	   strName.Format("%s.%d\r\n",m_FileTitle,i);
		   strReport+=strName;
	   }
	   if(bSuccess)
	   {
	       strReport+=_T(" 分割成功	");
		   strName.Format("\r\n生成合并文件\r\n	%s.bat",m_FileTitle);
			   if(m_ifCreate)
				   strReport+=strName;
	   }
	   else
	   {
		   strReport+=_T("分割不成功");
	   }
   }
   else{
       strReport=bSuccess ? _T("分割成功") : _T("分割不成功");
   }
   ::AfxMessageBox(strReport);
}
