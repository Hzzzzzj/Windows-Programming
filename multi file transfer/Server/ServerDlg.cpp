// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


DWORD GetInfoProc(SOCKET client,CString m_filename,HWND hwnd);

CRITICAL_SECTION CSA;

CRITICAL_SECTION CSB;


CString m_filename;

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
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_CHOOSE, OnChoose)
	ON_BN_CLICKED(ID_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
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
	InitializeCriticalSection(&CSA);
		InitializeCriticalSection(&CSB);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerDlg::OnPaint() 
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
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerDlg::OnChoose() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle="选择文件";
	fileDlg.m_ofn.lpstrFilter="所有文件(*.*)\0*.*\0\0";
	if(IDOK==fileDlg.DoModal())
	{
	      m_filename=fileDlg.GetPathName();
		  (GetDlgItem(IDC_EDIT_FILE))->SetWindowText(m_filename);
		  Invalidate();
	}
}

void CServerDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	SOCKET socketserv=socket(AF_INET,SOCK_STREAM,0);
	if(INVALID_SOCKET==socketserv)
	{
	    closesocket(socketserv);
		MessageBox("套接字创建失败","警告",MB_OK);
		return ;
	}
	SOCKADDR_IN addrserv;
	addrserv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrserv.sin_port=htons(6606);
	addrserv.sin_family=AF_INET;

	int retbind;
	retbind=bind(socketserv,(SOCKADDR*)&addrserv,sizeof(SOCKADDR));

	if(SOCKET_ERROR==retbind)
	{  
		closesocket(socketserv);
	    MessageBox("绑定失败","警告",MB_OK);
		return ;
	}

	int retlis=listen(socketserv,5);

	if(SOCKET_ERROR==retlis)
	{
	    closesocket(socketserv);
		MessageBox("监听失败","警告",MB_OK);
		return ;
	}

	SOCKADDR_IN addrconn;
	int len=sizeof(SOCKADDR);


	 HANDLE Thread[5];

    MessageBox("开启服务","警告",MB_OK);
	int i=0;
	while(i<6)
	{
	     SOCKET client;
		 client =accept(socketserv,(SOCKADDR*)&addrconn,&len);
		 
	//     MessageBox("连接成功","警告",MB_OK);
         if(INVALID_SOCKET==client)
		 {
	        closesocket(socketserv);
		    MessageBox("连接失败","警告",MB_OK);
	     	return ;
		 }
		 else
		 {
		     FILEINFO RecvFileInfo;
			 memset((char*)&RecvFileInfo,0,sizeof(RecvFileInfo));
			 if(recv(client,(char*)&RecvFileInfo,sizeof(RecvFileInfo),0)==SOCKET_ERROR)
			 {
			     closesocket(client);
				 MessageBox("接收文件信息错误","警告",MB_OK);
				 return ;
			 }
			 else
			 {
				 
			    // EnterCriticalSection(&CSA);
				 memcpy((char*)&TempFileInfo,(char*)&RecvFileInfo,sizeof(RecvFileInfo));
				 switch(TempFileInfo.CMD)
				 {
				 case 1:GetInfoProc(client,m_filename,m_hWnd);
					 break;
				 case 2:TempFileInfo.sockid=client;
					 Thread[i]= CreateThread(NULL,NULL,GetFileProc,&TempFileInfo,NULL,NULL);
					 break;
				 }
				// LeaveCriticalSection(&CSA);
				
			 }
		 }
       i+=1;
	}
	WaitForMultipleObjects(5,&Thread[1],true,INFINITE); 
	closesocket(socketserv);
		MessageBox("结束","文件传输",MB_OK);  

}

DWORD GetInfoProc(SOCKET client,CString m_filename,HWND hwnd)
{
    CFile file;
	if(file.Open(m_filename,CFile::modeRead|CFile::typeBinary))
	{
	    int FileLen=file.GetLength();
		if(send(client,(char*)&FileLen,sizeof(FileLen),0)==SOCKET_ERROR)
		{
		    closesocket(client);
			::MessageBox(hwnd,"发送文件信息错误","警告",MB_OK);
			return 0;
		}
		else{
			 CString str;            
             str.Format("文件大小%d", FileLen);    
    //        AfxMessageBox(str);
			
		}
	}
	return 0;
}

DWORD WINAPI CServerDlg::GetFileProc(LPVOID lpParameter)
{
    EnterCriticalSection(&CSB);  
	int FileLen=((FILEINFO*)lpParameter)->FileLen;
	int  Seek=((FILEINFO*)lpParameter)->seek;
	SOCKET client=((FILEINFO*)lpParameter)->sockid;
	LeaveCriticalSection(&CSB);

	CFile file;
	if(file.Open(m_filename,CFile::modeRead|CFile::typeBinary))
	{
		file.Seek(Seek,CFile::begin);
		char* date=new char[FileLen];
		int nLeft=FileLen;
		int idx=0;
		file.Read(date,FileLen);
		while(nLeft>0)
		{
		    int ret=send(client,&date[idx]	,nLeft,0);
			if(SOCKET_ERROR==ret)
			{
			    AfxMessageBox("发送文件错误");
				break;
			}
			nLeft-=ret;
			idx+=ret;
		}
		file.Close();
		delete[] date;
	}
	else
	{
	   AfxMessageBox("打开文件错误");

	}
	 
	return 0;
}
