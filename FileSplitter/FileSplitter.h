// FileSplitter.h : main header file for the FILESPLITTER application
//

#if !defined(AFX_FILESPLITTER_H__4AB8361C_B1A5_47A0_A76C_076938F94423__INCLUDED_)
#define AFX_FILESPLITTER_H__4AB8361C_B1A5_47A0_A76C_076938F94423__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileSplitterApp:
// See FileSplitter.cpp for the implementation of this class
//

class CFileSplitterApp : public CWinApp
{
public:
	CFileSplitterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSplitterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileSplitterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILESPLITTER_H__4AB8361C_B1A5_47A0_A76C_076938F94423__INCLUDED_)
