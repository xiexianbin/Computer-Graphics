// CG_xDoc.h : interface of the CCG_xDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CG_XDOC_H__0D0EF93E_3CC8_4B4E_A60C_0315AB0BBAD6__INCLUDED_)
#define AFX_CG_XDOC_H__0D0EF93E_3CC8_4B4E_A60C_0315AB0BBAD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCG_xDoc : public CDocument
{
protected: // create from serialization only
	CCG_xDoc();
	DECLARE_DYNCREATE(CCG_xDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCG_xDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCG_xDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCG_xDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG_XDOC_H__0D0EF93E_3CC8_4B4E_A60C_0315AB0BBAD6__INCLUDED_)
