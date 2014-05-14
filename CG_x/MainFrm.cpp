// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "CG_x.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_Menu_31_CPen, OnMenu31CPen)
	ON_COMMAND(ID_Menu_32_CBrush, OnMenu32CBrush)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnMenu31CPen() 
{
	// TODO: Add your command handler code here
	/*构造三组画笔：1. 按不同线型绘制
					2. 按不同宽度绘制
					3. 按不同颜色绘制
	*/
	int i;
	int nPenStyle[] = { PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME, };
	CPen *pNewPen;
	CPen *pOldPen;
	CDC* pDC = GetDC(); //创建

	//1..按不同线型绘制
	for(i = 0; i < 7; i++)
	{
		//构造函数
		pNewPen = new CPen;
		if(pNewPen->CreatePen(nPenStyle[i], 1, RGB(0, 0, 0)))
		{
			pOldPen = pDC->SelectObject(pNewPen); //保存画笔
			pDC->MoveTo(20, 60+i*20);
			pDC->LineTo(160, 60+i*20);
			//恢复画笔
			pDC->SelectObject(pOldPen);
		}
		else{
			//error
			AfxMessageBox("CreatePen Error!");
		}
		
		//删除新笔
		delete pNewPen;
	}
	
	//2. 按不同宽度绘制
	for( i=0; i<7; i++)
	{
		//构造函数
		pNewPen = new CPen;
		if(pNewPen->CreatePen(PS_SOLID, i+1, RGB(0, 0, 0)))
		{
			pOldPen = pDC->SelectObject(pNewPen);
			//画直线
			pDC->MoveTo(200, 60+i*20);
			pDC->LineTo(340, 60+i*20);

			pDC->SelectObject(pOldPen);
		}
		else{
			//error
			AfxMessageBox("CreatePen Error!");
		}
		
		//删除新笔
		delete pNewPen;
	}

	//3. 按不同颜色绘制
	//设置颜色表
	struct tagColor{
		int r, g, b;
	}color[7] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255,255,0}, {255, 0, 255}, {0, 255, 255}, {0, 0, 0}};
	for( i=0; i<7; i++)
	{
		//构造函数
		pNewPen = new CPen;
		if(pNewPen->CreatePen(PS_SOLID, 2, RGB(color[i].r, color[i].g, color[i].b)))
		{
			pOldPen = pDC->SelectObject(pNewPen);
			//画直线
			pDC->MoveTo(380, 60+i*20);
			pDC->LineTo(520, 60+i*20);

			pDC->SelectObject(pOldPen);
		}
		else{
			//error
			AfxMessageBox("CreatePen Error!");
		}
		//删除新笔
		delete pNewPen;
	}

}

void CMainFrame::OnMenu32CBrush() 
{
	// TODO: Add your command handler code here
	//画刷
	CDC *pDC = GetDC();
	pDC->Rectangle(60, 200, 160, 300);
	//纯色画刷
	CBrush *pNewBrush;
	CBrush *pOldBrush;
	pNewBrush = new CBrush;
	if(pNewBrush->CreateSolidBrush(RGB(255, 0, 0)))
	{
		//选择新画刷
		pOldBrush = pDC->SelectObject(pNewBrush);
		//绘制矩形
		pDC->Rectangle(200, 200, 300, 400);
		//恢复原有画刷
		pDC->SelectObject(pOldBrush);

	}
	delete pNewBrush;
	//阴影画刷
	CBrush Brush(HS_DIAGCROSS, RGB(255, 255, 255));
	CBrush *pOldBrush2;
	pOldBrush2 = pDC->SelectObject(&Brush);
	pDC->SetBkColor(RGB(192, 192, 192));
	pDC->Rectangle(340, 200, 440, 300);
	pDC->SelectObject(pOldBrush2);
}


void CMainFrame::DDAMouseLine(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
{
	//实现鼠标功能，实现交互式画直线
	
}

//DEL void CMainFrame::OnMENU462MidpointEllise() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnMENU51SpeedFill() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 
//DEL 	
//DEL }

//DEL void CMainFrame::OnMenu622Cricle() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

//DEL void CMainFrame::OnMENU71MouseCodeClip() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }
