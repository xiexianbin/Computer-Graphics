// CG_x.h : main header file for the CG_X application
//

#if !defined(AFX_CG_X_H__26EE20C0_B26E_42A0_96ED_45E485B66DF9__INCLUDED_)
#define AFX_CG_X_H__26EE20C0_B26E_42A0_96ED_45E485B66DF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCG_xApp:
// See CG_x.cpp for the implementation of this class
//

class CCG_xApp : public CWinApp
{
public:
	CCG_xApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCG_xApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCG_xApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG_X_H__26EE20C0_B26E_42A0_96ED_45E485B66DF9__INCLUDED_)
