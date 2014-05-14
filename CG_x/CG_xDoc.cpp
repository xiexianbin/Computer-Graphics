// CG_xDoc.cpp : implementation of the CCG_xDoc class
//

#include "stdafx.h"
#include "CG_x.h"

#include "CG_xDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCG_xDoc

IMPLEMENT_DYNCREATE(CCG_xDoc, CDocument)

BEGIN_MESSAGE_MAP(CCG_xDoc, CDocument)
	//{{AFX_MSG_MAP(CCG_xDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCG_xDoc construction/destruction

CCG_xDoc::CCG_xDoc()
{
	// TODO: add one-time construction code here

}

CCG_xDoc::~CCG_xDoc()
{
}

BOOL CCG_xDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCG_xDoc serialization

void CCG_xDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCG_xDoc diagnostics

#ifdef _DEBUG
void CCG_xDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCG_xDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCG_xDoc commands
