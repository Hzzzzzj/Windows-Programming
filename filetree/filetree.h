// filetree.h : main header file for the FILETREE application
//

#if !defined(AFX_FILETREE_H__529DFD40_6AC8_4717_B479_507BC7308AA6__INCLUDED_)
#define AFX_FILETREE_H__529DFD40_6AC8_4717_B479_507BC7308AA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFiletreeApp:
// See filetree.cpp for the implementation of this class
//

class CFiletreeApp : public CWinApp
{
public:
	CFiletreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiletreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFiletreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETREE_H__529DFD40_6AC8_4717_B479_507BC7308AA6__INCLUDED_)
