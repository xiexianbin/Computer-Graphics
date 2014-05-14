// CG_xView.cpp : implementation of the CCG_xView class
//

#include "stdafx.h"
#include "CG_x.h"

#include "CG_xDoc.h"
#include "CG_xView.h"

#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCG_xView

IMPLEMENT_DYNCREATE(CCG_xView, CView)

BEGIN_MESSAGE_MAP(CCG_xView, CView)
	//{{AFX_MSG_MAP(CCG_xView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CANCELMODE()
	ON_WM_MOUSEMOVE()
	ON_WM_CAPTURECHANGED()
	ON_COMMAND(ID_MENU_33_MouseSprint, OnMENU33MouseSprint)
	ON_COMMAND(ID_MENU_341_DDAOnDraw, OnMENU341DDAOnDraw)
	ON_COMMAND(ID_MENU_342_FangDa10, OnMENU342FangDa10)
	ON_COMMAND(ID_MENU_343_MouseLine, OnMENU343MouseLine)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CHAR()
	ON_COMMAND(ID_MENU_CLEARALL, OnMenuClearall)
	ON_COMMAND(ID_MENU_35_PEN, OnMenu35Pen)
	ON_COMMAND(ID_MENU_461_MidpointCircle, OnMENU461MidpointCircle)
	ON_COMMAND(ID_MENU_462_MidpointEllise, OnMENU462MidpointEllise)
	ON_COMMAND(ID_MENU_COLOR, OnMenuColor)
	ON_COMMAND(ID_MENU_51_SpeedFill, OnMENU51SpeedFill)
	ON_COMMAND(ID_MENU_52_SpeedFill_Zhongzi, OnMENU52SpeedFillZhongzi)
	ON_WM_LBUTTONUP()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_MENU_611_LINE, OnMenu611Line)
	ON_COMMAND(ID_MENU_612_CRICLE, OnMenu612Cricle)
	ON_COMMAND(ID_MENU_621_LINE, OnMenu621Line)
	ON_COMMAND(ID_MENU_622_CRICLE, OnMenu622Cricle)
	ON_COMMAND(ID_MENU_37_DOTLINE, OnMenu37Dotline)
	ON_COMMAND(ID_MENU_71_Mouse_Code_Clip, OnMENU71MouseCodeClip)
	ON_COMMAND(ID_MENU_81_Par, OnMENU81Par)
	ON_COMMAND(ID_MENU_82_Hermite, OnMENU82Hermite)
	ON_COMMAND(ID_MENU_83_Bezier, OnMENU83Bezier)
	ON_COMMAND(ID_MENU_84_Bezier3, OnMENU84Bezier3)
	ON_COMMAND(ID_MENU_85_3ByangtaoLine, OnMENU853ByangtaoLine)
	ON_COMMAND(ID_MENU_CHANGE_pingyi, OnMENUCHANGEpingyi)
	ON_COMMAND(ID_MENU_CHANGE_XUANXZHUAN, OnMenuChangeXuanxzhuan)
	ON_COMMAND(ID_MENU_CHANGE_FANGDASUOXIAO, OnMenuChangeFangdasuoxiao)
	ON_COMMAND(ID_MENU_Other_Flowers, OnMENUOtherFlowers)
	ON_COMMAND(ID_MENU_OTHERS_JIAOHUSHIYIDONGTUXING, OnMenuOthersJiaohushiyidongtuxing)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCG_xView construction/destruction

CCG_xView::CCG_xView()
{
	// TODO: add construction code here
	m_bO.x = 0;
	m_bO.y = 0; //圆心
	m_bR.x = 0;
	m_bR.y = 0; //圆上的点
	m_ist = 0; //圆心与圆上的点区别
	m_p1.x = 0; m_p1.y = 0; //起点
	m_p2.x = 0; m_p2.y = 0; //终点
	m_ist = 0; //0,第1点， 1， 第二点 //用于交互式画直线、画圆、
	m_r = 0; //圆的半径

	//交互式画椭圆
	LeftTop.x = 0;
	LeftTop.y = 0;//左上角坐标初值
	RightBottom.x = 0;
	RightBottom.y = 0;//右下角坐标初值
	CenterPoint.x = 0;
	CenterPoint.y = 0;//中心坐标初值
	a = 0; b = 0;//长轴和短轴长度
	
	//构造函数，初始化数据
	stack_top = 0;

	//鼠标实现交互式剪切线段效果
	WL = 100;
	WR = 400;
	WB = 100;
	WT = 300;

	// 利用鼠标实现交互式移动图形
	// 直线段初始化
	p1.x=0;p1.y=0;
	p2.x=0;p2.y=0;
	mp1.x=0;mp1.y=0;
	mp2.x=0;mp2.y=0;
    m_ist=0;//0,鼠标第一点，1，鼠标第2点
}

CCG_xView::~CCG_xView()
{
}

BOOL CCG_xView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCG_xView drawing

void CCG_xView::OnDraw(CDC* pDC)
{
	CCG_xDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
//	pDC->TextOut( 30, 30, "hello, worle!");

		
	


}

/////////////////////////////////////////////////////////////////////////////
// CCG_xView printing

BOOL CCG_xView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCG_xView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCG_xView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCG_xView diagnostics

#ifdef _DEBUG
void CCG_xView::AssertValid() const
{
	CView::AssertValid();
}

void CCG_xView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCG_xDoc* CCG_xView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCG_xDoc)));
	return (CCG_xDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCG_xView message handlers

void CCG_xView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//获得pDC
	CDC *pDC = GetDC();
	//橡皮筋技术画圆
	if(m_Type == 1){
		//pDC->TextOut(30, 50, "LButtonDown!");
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist)
		{
			m_bO = m_bR = point;//记录第一次的圆心位置
			m_ist++;
		}
		else
		{
			m_bR = point; //记录第二次的单击鼠标位置，定圆心
			m_ist--;
			DrawCircle(pDC, m_bO, m_bR);//画圆
		}
		ReleaseDC(pDC);
	}else if(m_Type == 2){
		//交互式画直线、
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //是起点
		{
			m_p1 = m_p2 = point;//记录第一次点击鼠标位置，定起点
			m_ist++;
		}else{
			m_p2 = point; //记录第二次单击鼠标的位置，定终点
			m_ist--; //为新绘图作准备
			DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255, 0, 0));//绘制新直线
		}
		ReleaseDC(pDC); //释放设备环境
	}else if(m_Type == 3){
		//铅笔功能（徒手画线）
/*		m_isButtondown = true;
		SetCapture();
		CPenpen(PS_SOLID, m_penwidth, m_FontColor);
		CPen *pOldPen = pDC->SelectObject(&pen);
		pDC->MoveTo(point);
		pDC->SelectObject(pOldPen);
		m_oldpoint = point;
*/		
		
	}else if(m_Type == 4){
		//4：中点法交互式画圆
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //绘制圆
		{
			m_bO = m_bR = point; //记录第一次单击鼠标位置，确定圆心
			m_ist++;
		}else{
			m_bR = point; //记录第二次单击鼠标的位置，定圆周上的点
			m_ist--;
			m_r = ComputeRadius(m_bO, m_bR);
			MidpointCircle(pDC, m_bO.x, m_bO.y, m_r, RGB(255, 0, 0));
		}
		ReleaseDC(pDC); //释放设备环境
	}else if(m_Type == 5){
		//5：中点法交互式画椭圆
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //第一个点，左上角
		{
			LeftTop = RightBottom = point; //记录第一次单击鼠标位置
			m_ist++;
		}else{
			RightBottom = point; //记录第二次单击鼠标的位置
			m_ist--;
			CenterPoint.x = (LeftTop.x + RightBottom.x)/2;
			CenterPoint.y = (LeftTop.y + RightBottom.y)/2;
			a = (int)abs(RightBottom.x - LeftTop.x)/2;
			b = (int)abs(RightBottom.y - LeftTop.y)/2;
			MidpointEllise(pDC, CenterPoint.x, CenterPoint.y, a, b, RGB(255, 0, 0));
		}
		ReleaseDC(pDC); //释放设备环境
	}else if(m_Type == 6){

	}else if(m_Type == 7){

	}else if(m_Type == 8){
		//8：点划线
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //是起点
		{
			m_p1 = m_p2 = point;//记录第一次点击鼠标位置，定起点
			m_ist++;
		}else{
			m_p2 = point; //记录第二次单击鼠标的位置，定终点
			m_ist--; //为新绘图作准备
			DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255, 0, 0));//绘制新直线
		}
		ReleaseDC(pDC); //释放设备环境
	}else if(m_Type == 10){
		//10：交互式编码剪切算法剪切线段 
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //起点
		{
			m_p1 = m_p2 = point; //记录第一次单击鼠标位置，定起点
			m_ist++;
		}else{
			m_p2 = point; //记录第二次单击鼠标的位置，定终点
			m_ist --;
			pDC->MoveTo(m_p1.x, m_p1.y); //绘制新直线
			pDC->LineTo(m_p2.x, m_p2.y);
		}
		//使用异或方式擦除新直线

		//设置异或绘图模式，并保存原来绘图模式
		int nDrawmode = pDC->SetROP2(R2_NOT);
		pDC->MoveTo(m_p1.x, m_p1.y); 
		pDC->MoveTo(m_p2.x, m_p2.y);
		pDC->SetROP2(nDrawmode); //回复绘图模

		//用红色画出剪切线段
		CPen PenRed(PS_SOLID, 1, RGB(255, 0, 0)); //定义红色笔
		pDC->SelectObject(&PenRed);
		C_S_Line(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y);
		ReleaseDC(pDC); //释放设备环境
	}else if(m_Type == 11){
		// 利用鼠标实现交互式移动图形
		pDC->SelectStockObject(NULL_BRUSH);
		if (!m_ist)
		{
		  mp1=mp2=point;
		  m_ist++;
		}
		else
		{
			mp2=point;  //记录第二次单击鼠标的位置
			m_ist--;   // 为下一次移动作准备
	    }
	}
	CView::OnLButtonDown(nFlags, point);
}

void CCG_xView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CCG_xView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDC *pDC = GetDC();

	//****************************************鼠标移动***********************************************//
	char tbuf[80];
	sprintf(tbuf, "Mouse Position:(%3d, %3d)      ", point.x, point.y);
	//当鼠标移动时输出当前位置
	pDC->TextOut(700, 10, tbuf);
		
	if(m_Type == 1){
		//mouse Over
		int nDrawmode = pDC->SetROP2(R2_NOT); //设置异或绘图模式，并保存原来的绘图模式
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1)
		{
			CPoint prePnt, curPnt;
			prePnt = m_bR; //获取鼠标所在的前一位置
			curPnt = point;
			//绘制橡皮筋线
			DrawCircle(pDC, m_bO, prePnt);
			DrawCircle(pDC, m_bO, curPnt);
			m_bR = point;
		}
		pDC->SetROP2(nDrawmode);
		ReleaseDC(pDC);
	}else if(m_Type == 2){ //鼠标移动画直线
		int nDrawmode = pDC->SetROP2(R2_NOT); //设置异或绘图模式，并保存原来的绘图模式
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1)
		{
			CPoint prePnt, curPnt;
			prePnt = m_p2; //获得鼠标所在的前一位置
			curPnt = point;
			//绘制橡皮筋线
			DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255,0,0));
			//使用异或模式重复画直线，擦除所画直线
			DDAMouseLine(pDC, m_p1.x, m_p1.y, curPnt.x, curPnt.y, RGB(255, 0, 0));
			//用当前位置作为直线的终点
			m_p2 = point;
		}
		//恢复元绘图模式
		pDC->SetROP2(nDrawmode);
		ReleaseDC(pDC);
	}else if(m_Type == 3){


	}else if(m_Type == 4){
		//4：中点法交互式画圆
		int nDrawmode = pDC->SetROP2(R2_NOT); //设置异或绘图模式，并保存原来绘图模式
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1){
			CPoint prePnt, curPnt;
			prePnt = m_bR; //获取鼠标所在的前一位置
			curPnt = point;
			//绘制橡皮筋线
			m_r = ComputeRadius(m_bO, prePnt);
			MidpointCircle(pDC, m_bO.x, m_bO.y, m_r, RGB(255, 0, 0));//用异或模式重复画圆，擦出所画的圆
			m_r = ComputeRadius(m_bO, curPnt);
			MidpointCircle(pDC, m_bO.x, m_bO.y, m_r, RGB(255, 0, 0));//用当前位置作为圆周上的点画圆
			m_bR = point;
		}
		pDC->SetROP2(nDrawmode); //恢复原绘图模式

		ReleaseDC(pDC);
	}else if(m_Type == 5){
		//5：中点法交互式画椭圆
		int nDrawmode = pDC->SetROP2(R2_NOT); //设置异或绘图模式，并保存原来绘图模式
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1){
			CPoint prePnt, curPnt;
			prePnt = RightBottom; //获取鼠标所在的前一位置
			curPnt = point;
			//绘制橡皮筋线
			CenterPoint.x = (LeftTop.x+prePnt.x)/2;
			CenterPoint.y = (LeftTop.y+prePnt.y)/2;
			a = (int)abs(prePnt.x-LeftTop.x)/2;
			b = (int)abs(prePnt.y-LeftTop.y)/2;
			MidpointEllise(pDC, CenterPoint.x, CenterPoint.y, a, b, RGB(255, 0, 0));//用异或模式重复画tuo圆，擦出所画的tuo圆
			//用当前点作为右下角点，画椭圆
			CenterPoint.x = (LeftTop.x+curPnt.x)/2;
			CenterPoint.y = (LeftTop.y+curPnt.y)/2;
			a = (int)abs(curPnt.x-LeftTop.x)/2;
			b = (int)abs(curPnt.y-LeftTop.y)/2;
			MidpointEllise(pDC, CenterPoint.x, CenterPoint.y, a, b, RGB(255, 0, 0));
			RightBottom = point;
		}
		pDC->SetROP2(nDrawmode); //恢复原绘图模式

		ReleaseDC(pDC);
	}else if(m_Type == 10){
		//10：交互式编码剪切算法剪切线段 
		int nDrawmode = pDC->SetROP2(R2_NOT); //设置异或绘图模式，并保存原来绘图模式
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1)
		{
			CPoint prePnt, curPnt;
			prePnt = m_p2; //获得鼠标所在的前一位置
			curPnt = point;
			//绘制橡皮筋线
			pDC->MoveTo(m_p1.x, m_p1.y);
			pDC->LineTo(prePnt.x, prePnt.y);

			//用异或模式重复画直线，擦除所画的直线
			pDC->MoveTo(m_p1.x, m_p1.y);
			pDC->LineTo(curPnt.x, curPnt.y);
			//用当前位置画直线
			m_p2 = point;
		}
		pDC->SetROP2(nDrawmode); //恢复原绘图模式
		ReleaseDC(pDC);
	}else if(m_Type == 11){
		int nDrawmode=pDC->SetROP2(R2_NOT); //设置异或绘图模式，并保存原来绘图模式
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist==1)
		{
			CPoint prePnt,curPnt;
			int dx,dy;
			prePnt=mp2;  //获得鼠标所在的前一位置
			curPnt=point;
			//绘制橡皮筋线
			pDC->MoveTo(p1);pDC->LineTo(p2);//用异或模式擦出所画的直线
			dx=curPnt.x-prePnt.x;dy=curPnt.y-prePnt.y;
			p1.x=p1.x+dx;p1.y=p1.y+dy;
			p2.x=p2.x+dx;p2.y=p2.y+dy;
			pDC->MoveTo(p1);pDC->LineTo(p2);  //用当前位置绘出直线
			mp2=point;
		}	
		pDC->SetROP2(nDrawmode);  //恢复原绘图模式
		ReleaseDC(pDC);  //释放设备环境
	}
	CView::OnMouseMove(nFlags, point);
}

void CCG_xView::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CView::OnCaptureChanged(pWnd);
}


void CCG_xView::DrawCircle(CDC *pDC, CPoint cenp, CPoint arbp)
{
	//画圆
	int radius = ComputeRadius(cenp, arbp);
	//由圆心确定所画圆的外切区域
	CRect rc(cenp.x - radius, cenp.y - radius, cenp.x + radius, cenp.y + radius);
	pDC->Ellipse(rc);
}


int CCG_xView::ComputeRadius(CPoint cenp, CPoint ardp)
{
	int dx = cenp.x - ardp.x;
	int dy = cenp.y - ardp.y;
	return (int)sqrt(dx*dx + dy*dy);

}

void CCG_xView::OnMENU33MouseSprint() 
{
	// TODO: Add your command handler code here
	//初始化鼠标
	m_Type = 1;
	l_Type = 0;
	//橡皮筋技术画圆
	CDC *pDC = GetDC();
	pDC->SelectStockObject(NULL_BRUSH);
	//初始化圆心(0, 0) 圆上的点(0, 0)
	m_bO.x = 0;
	m_bO.y = 0;
	m_bR.x = 0;
	m_bR.y = 0;

	DrawCircle(pDC, m_bO, m_bR);
}

//DEL void CCG_xView::ddaline(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
//DEL {
//DEL 	//实现DDA画线程序
//DEL 	int length, i;
//DEL 	float x, y, dx, dy;
//DEL 	length = abs(x1 - x0);
//DEL 	if(abs(y1-y0)>length)
//DEL 	{
//DEL 		length=abs(y1-y0);
//DEL 		dx=(x1-x0)/length;
//DEL 		dy=(y1-y0)/length;
//DEL 		x=x0+0.5;
//DEL 		y=y0+0.5;
//DEL 		for(i=1; i<=length; i++)
//DEL 		{
//DEL 			pDC->SetPixel((int)x, (int)y, color);
//DEL 			x = x+dx;
//DEL 			y = y+dy;
//DEL 		}
//DEL 	}
//DEL }

void CCG_xView::ddaline(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
{
	//实现DDA画线程序
	int length, i;
	double x, y, dx, dy;
	length = abs(x1 - x0);
	if(abs(y1-y0)>length)
	{
		length=abs(y1-y0);
		dx=(double)(x1-x0)/length;
		dy=(double)(y1-y0)/length;
		x=x0+0.5;
		y=y0+0.5;
		for(i=1; i<=length; i++)
		{
			pDC->SetPixel((int)x, (int)y, color);
			x = x+dx;
			y = y+dy;
		}
	}
	else
	{
		length=abs(x1-x0);
		dx=(x1-x0)/length;
		dy=(y1-y0)/length;
		x=x0+0.5;
		y=y0+0.5;
		for(i=1; i<=length; i++)
		{
			pDC->SetPixel((int)x, (int)y, color);
			x = x+dx;
			y = y+dy;
		}
	}
}

void CCG_xView::OnMENU341DDAOnDraw() 
{
	// TODO: Add your command handler code here
	//实现DDA画线程序
	CDC *pDC = GetDC();
	ddaline(pDC, 100, 100, 400, 100, RGB(255, 0, 0));
	ddaline(pDC, 400, 100, 400, 400, RGB(0, 255, 0));
	ddaline(pDC, 400, 400, 100, 400, RGB(0, 0, 255));
	ddaline(pDC, 100, 400, 100, 100, RGB(255, 255, 0));
	ddaline(pDC, 100, 100, 400, 400, RGB(255, 0, 255));
	ddaline(pDC, 100, 400, 400, 100, RGB(0, 255, 255));
}

void CCG_xView::OnMENU342FangDa10() 
{
	// TODO: Add your command handler code here
	//放大10倍后的算法
	CDC *pDC = GetDC();
	//画网格
	int gi, gj;
	//画横线
	pDC->TextOut(90, 90, "(100, 100)");
	pDC->MoveTo(100, 100);
	for(gj = 100; gj<=400; gj=gj+10)
	{
		pDC->MoveTo(100, gj);
		pDC->LineTo(600, gj);
	}
	//画竖线
	pDC->MoveTo(100, 100);
	for(gi = 100; gi<=600; gi=gi+10)
	{
		pDC->MoveTo(gi, 100);
		pDC->LineTo(gi, 400);
	}
	pDC->TextOut(590, 410, "(600, 400)");

	//画出像焦点
	DDA2Line(pDC, 100, 100, 600, 400, RGB(255, 0, 0));
	
}

void CCG_xView::DDA2Line(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
{
	//DDA2Line()函数
	int length, i, tx, ty;
	double x, y, dx, dy;
	length = abs(x1 - x0);
	if(abs(y1-y0)>length)
	{
		length = abs(y1 - y0);
		dx = (float)(x1 - x0)/length;
		dy = (float)(y1 - y0)/length;
		x = x0;
		y = y0;
		for( i = 0; i<=length; i=i+10)
		{
			tx = (int)((x+5)/10)*10;
			ty = (int)((y+5)/10)*10;

			pDC->SetPixel(tx, ty, color);
			pDC->Ellipse(tx -5, ty - 5, tx+5, ty+5);
			x = x +dx*10;
			y = y + dy*10;
		}
	}
	else{
		length = abs(x1 - x0);
		dx = (float)(x1 - x0)/length;
		dy = (float)(y1 - y0)/length;
		x = x0;
		y = y0;
		for( i = 0; i<=length; i=i+10)
		{
			tx = (int)((x+5)/10)*10;
			ty = (int)((y+5)/10)*10;

			pDC->SetPixel(tx, ty, color);
			pDC->Ellipse(tx -5, ty - 5, tx+5, ty+5);
			x = x + dx*10;
			y = y + dy*10;
		}

	}
}


void CCG_xView::OnMENU343MouseLine() 
{
	// TODO: Add your command handler code here
	//初始化鼠标类型
	m_Type = 2;
	//实现交互式画直线
	CDC *pDC = GetDC();
	pDC->SelectStockObject(NULL_BRUSH);
	//初始化直线起点(0, 0) 终点(0, 0)
	m_p1.x = 0;
	m_p1.y = 0;
	m_p2.x = 0;
	m_p2.y = 0;
	//调用自定义的成员函数，用鼠标画直线
	DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255, 0, 0));
}

void CCG_xView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CCG_xView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CCG_xView::DDAMouseLine(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
{
	//定义数组，标志是否划线   点划线
	int array1[35] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
	int count = 0;
	//p42第7步
	int length, i;
	double x, y, dx, dy;
	length = abs(x1-x0);
	if(abs(y1-y0)>length)
	{
		length = abs(y1 - y0);
		dx = (double)(x1- x0)/length;
		dy = (double)(y1 - y0)/length;
		x = x0+0.5;
		y = y0+0.5;

		//实线
		
		for(i = 1; i<=length; i++)
		{
			if(m_Type == 8 && array1[(count++)%35]==0){
				//什么都不做
				count = count%35;
			}else{
				count++;
				pDC->SetPixel((int)x, (int)y, color);
				if(l_Type == 1){
					//线刷子技术画直线
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x, (int)y-2, color);
					pDC->SetPixel((int)x, (int)y+2, color);
				}else if(l_Type == 2){
					//方刷子技术画直线
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x-1, (int)y, color);
					pDC->SetPixel((int)x+1, (int)y, color);

					pDC->SetPixel((int)x-1, (int)y-1, color);
					pDC->SetPixel((int)x-1, (int)y+1, color);
					pDC->SetPixel((int)x+1, (int)y-1, color);
					pDC->SetPixel((int)x+1, (int)y+1, color);
				}
			}
			x = x+dx;
			y = y+dy;
		}
	}else{
	//	length = abs(y1 - y0);
		dx = (double)(x1- x0)/length;
		dy = (double)(y1 - y0)/length;
		x = x0+0.5;
		y = y0+0.5;
		for(i = 1; i<=length; i++)
		{
			if(m_Type == 8 && array1[(count++)%35]==0){
				//什么都不做
				count = count%35;
			}else{
				count++;
				pDC->SetPixel((int)x, (int)y, color);
				if(l_Type == 1){
					//线刷子技术画直线
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x, (int)y-2, color);
					pDC->SetPixel((int)x, (int)y+2, color);
				}else if(l_Type == 2){
					//方刷子技术画直线
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x-1, (int)y, color);
					pDC->SetPixel((int)x+1, (int)y, color);

					pDC->SetPixel((int)x-1, (int)y-1, color);
					pDC->SetPixel((int)x-1, (int)y+1, color);
					pDC->SetPixel((int)x+1, (int)y-1, color);
				}
			}
			x = x+dx;
			y = y+dy;
		}
	}
}

void CCG_xView::OnMenuClearall() 
{
	// TODO: Add your command handler code here
	///实现清屏功能  p34页
//	key = 0;
	RedrawWindow();
	m_Type = 0;
	l_Type = 0;
}

void CCG_xView::OnMenu35Pen() 
{
	// TODO: Add your command handler code here
	//p33页，铅笔功能
	//设置鼠标类型为3：铅笔功能（徒手画线）
	m_Type = 3;
	l_Type = 0;
	m_FontColor = RGB(0, 255, 0);
	m_penwidth = 1;
	
}

void CCG_xView::OnMENU461MidpointCircle() 
{
	// TODO: Add your command handler code here
	//p44交互式画圆
	//设置鼠标类型为：中点法交互式画圆
	m_Type = 4;
	l_Type = 0;
	
}

void CCG_xView::MidpointCircle(CDC *pDC, int x0, int y0, int r, COLORREF color)
{
	//中点法扫描转换算法--画圆
	int x, y;
	double d;
	x = 0;
	y = r;
	d = 1.25 - r;
	CirPot(pDC, x0, y0, x, y, color);
	while(x<=y){
		if(d<0){
			d+=2*x+3;
			x++;
		}else{
			d+=2*(x-y)+5;
			x++;
			y--;
		}
		CirPot(pDC, x0, y0, x, y, color);
	}//while
}

void CCG_xView::CirPot(CDC *pDC, int x0, int y0, int x, int y, COLORREF color)
{
	//画1/8圆
	pDC->SetPixel((x0+x), (y0+y), color);
	pDC->SetPixel((x0+y), (y0+x), color);
	pDC->SetPixel((x0+y), (y0-x), color);
	pDC->SetPixel((x0+x), (y0-y), color);
	pDC->SetPixel((x0-x), (y0-y), color);
	pDC->SetPixel((x0-y), (y0-x), color);
	pDC->SetPixel((x0-y), (y0+x), color);
	pDC->SetPixel((x0-x), (y0+y), color);
	if(l_Type == 1){
		for(int k = 1; k<4; k++){
			pDC->SetPixel((x0+x), (y0+y)-k, color);
			pDC->SetPixel((x0+x), (y0+y)+k, color);

			pDC->SetPixel((x0+y), (y0+x)-k, color);
			pDC->SetPixel((x0+y), (y0+x)+k, color);

			pDC->SetPixel((x0+y), (y0-x)-k, color);
			pDC->SetPixel((x0+y), (y0-x)+k, color);

			pDC->SetPixel((x0+x), (y0-y)-k, color);
			pDC->SetPixel((x0+x), (y0-y)+k, color);

			pDC->SetPixel((x0-x), (y0-y)-k, color);
			pDC->SetPixel((x0-x), (y0-y)+k, color);

			pDC->SetPixel((x0-y), (y0-x)-k, color);
			pDC->SetPixel((x0-y), (y0-x)+k, color);

			pDC->SetPixel((x0-y), (y0+x)-k, color);
			pDC->SetPixel((x0-y), (y0+x)+k, color);

			pDC->SetPixel((x0-x), (y0+y)-k, color);
			pDC->SetPixel((x0-x), (y0+y)+k, color);
		}

	}else if(l_Type == 2){
		for(int k = 1; k<4; k++){
			pDC->SetPixel((x0+x), (y0+y)-k, color);
			pDC->SetPixel((x0+x), (y0+y)+k, color);
			pDC->SetPixel((x0+x)-k, (y0+y), color);
			pDC->SetPixel((x0+x)+k, (y0+y), color);


			pDC->SetPixel((x0+y), (y0+x)-k, color);
			pDC->SetPixel((x0+y), (y0+x)+k, color);
			pDC->SetPixel((x0+y)-k, (y0+x), color);
			pDC->SetPixel((x0+y)+k, (y0+x), color);

			pDC->SetPixel((x0+y), (y0-x)-k, color);
			pDC->SetPixel((x0+y), (y0-x)+k, color);
			pDC->SetPixel((x0+y)-k, (y0-x), color);
			pDC->SetPixel((x0+y)+k, (y0-x), color);


			pDC->SetPixel((x0+x), (y0-y)-k, color);
			pDC->SetPixel((x0+x), (y0-y)+k, color);
			pDC->SetPixel((x0+x)-k, (y0-y), color);
			pDC->SetPixel((x0+x)+k, (y0-y), color);

			pDC->SetPixel((x0-x), (y0-y)-k, color);
			pDC->SetPixel((x0-x), (y0-y)+k, color);
			pDC->SetPixel((x0-x)-k, (y0-y), color);
			pDC->SetPixel((x0-x)+k, (y0-y), color);

			pDC->SetPixel((x0-y), (y0-x)-k, color);
			pDC->SetPixel((x0-y), (y0-x)+k, color);
			pDC->SetPixel((x0-y)-k, (y0-x), color);
			pDC->SetPixel((x0-y)+k, (y0-x), color);

			pDC->SetPixel((x0-y), (y0+x)-k, color);
			pDC->SetPixel((x0-y), (y0+x)+k, color);
			pDC->SetPixel((x0-y)-k, (y0+x), color);
			pDC->SetPixel((x0-y)+k, (y0+x), color);

			pDC->SetPixel((x0-x), (y0+y)-k, color);
			pDC->SetPixel((x0-x), (y0+y)+k, color);
			pDC->SetPixel((x0-x)-k, (y0+y), color);
			pDC->SetPixel((x0-x)+k, (y0+y), color);
		}

	}

}

void CCG_xView::OnMENU462MidpointEllise() 
{
	// TODO: Add your command handler code here
	//p48交互式画椭圆
	//设置鼠标类型为：中点法交互式画椭圆
	m_Type = 5;
}

void CCG_xView::MidpointEllise(CDC *pDC, int x0, int y0, int a, int b, COLORREF color)
{
	//中点法扫描转换算法--椭圆
	int x, y;
	double d1, d2;
	x = 0;
	y =b;
	d1 = b*b+a*a*(-b+0.25);
	pDC->SetPixel(x+x0, y+y0, color);
	while(b*b*(x+1)<a*a*(y-0.5)){
		if(d1<0){
			d1 += b*b*(2*x+3);
			x++;
		}else{
			d1 += (b*b*(2*x+3)+a*a*(-2*y+2));
			x++;
			y--;
		}
		ElisePot(pDC, x0, y0, x, y, color);
	}//while 上半部分
	d2 = (b*(x+0.5))*(b*(x+0.5))+(a*(y-1))*(a*(y-1))-(a*b)*(a*b);
	while(y>0){
		if(d2<0){
			d2 += b*b*(2*x+2)+a*a*(-2*y+3);
			x++;
			y--;
		}else{
			d2 += a*a*(-2*y+3);
			y--;
		}
		ElisePot(pDC, x0, y0, x, y, color);
	}//while 下半部分

}

void CCG_xView::ElisePot(CDC *pDC, int x0, int y0, int x, int y, COLORREF color)
{
	//画1/4椭圆
	pDC->SetPixel((x0+x), (y0+y), color);
	pDC->SetPixel((x0+x), (y0-y), color);
	pDC->SetPixel((x0-x), (y0-y), color);
	pDC->SetPixel((x0-x), (y0+y), color);
}

void CCG_xView::OnMenuColor() 
{
	// TODO: Add your command handler code here
	//实现颜色板选择颜色
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT | CC_FULLOPEN;
	dlg.m_cc.rgbResult = m_PenColor;

	//m_PenColor是一个成员变量，用来保存当前颜色
	if(IDOK == dlg.DoModal()){
		m_PenColor = dlg.m_cc.rgbResult;
	}
	
}

void CCG_xView::OnMENU51SpeedFill() 
{
	// TODO: Add your command handler code here
		//扫面线填充算法
	//m_Type:6：扫面线填充算法
	m_Type = 6;
	l_Type = 0;
	//定义画笔颜色
	CPen PenRed(PS_SOLID, 1, RGB(255, 0, 0)); //定义红色笔
	CPen PenBlue(PS_SOLID, 1, RGB(0, 0, 255)); //定义蓝色笔
	int x, y;
	//用蓝色画笔画出多边行的边界
	CDC* pDC = GetDC();
	pDC->SelectObject(&PenBlue);
	POINT polygon[5] = {{300, 120}, {390, 160}, {430, 320}, {180, 300}, {150, 240}};
	pDC->Polygon(polygon, 5);
	//定义种子位置，并景色oldcolor和填充色newcolor
	x = 300;
	y = 200;
	COLORREF newcolor = RGB(255, 0, 0);
	COLORREF oldcolor = RGB(255, 255, 255);
	//调用扫描线填充算法
	floodfill4(x, y, oldcolor, newcolor);
	
}

int CCG_xView::stackpop()
{
	//定义出栈
	int val;
	val = stack[stack_top];
	stack_top = stack_top-1;
	return val;
}

void CCG_xView::stackpush(int p_xy)
{
	//定义入栈
	stack_top += 1;
	stack[stack_top] = p_xy;

}

void CCG_xView::setstackempty()
{
	//清空栈
	int i;
	for(i = 0; i<=stack_top; i++){
		stack[i] = 0;
		stack_top = 0;
	}

}

int CCG_xView::isstackempty()
{
	//判断栈是否为空栈
	if(stack_top>0){
		return 1;
	}else{
		return 0;
	}

}

void CCG_xView::floodfill4(int x, int y, COLORREF oldcolor, COLORREF newcolor)
{

	int yy = y;
	int xx = x;
	//四连通算法
	CDC* pDC = GetDC();
	int xl, xr, x0, xnextspan;
	bool spanNeedFill;
	//将栈清空
	setstackempty();
	//种子入栈
	stackpush(x);
	stackpush(y);
	while(isstackempty()!=0){
		//栈定出栈，注意出栈顺序
		y = stackpop();
		x = stackpop();
		pDC->SetPixel(x, y, newcolor);
		x0 = x+1;
		while(pDC->GetPixel(x0, y) == oldcolor){
			//向右填充
			pDC->SetPixel(x0, y, newcolor);
			x0++;
		}
		xr = x0-1; //最右元素
		x0 = x-1;
		while(pDC->GetPixel(x0, y) == oldcolor){ //向左填充
			if(y>120){
				pDC->SetPixel(x0, y, newcolor);
				x0--;
			}else{
				break;
			}
		}
		xl = x0+1; //最左元素
		/*xl                                           xr*/
		//处理下面的一条扫描线
		x0 = xl;
		y = y+1;
		while(x0<=xr){
			spanNeedFill = false;
			while(pDC->GetPixel(x0, y) == oldcolor){
				if(spanNeedFill == false)
					spanNeedFill = true;
				x0++;
			}
			if(spanNeedFill){
				if(x0 == xr){
					stackpush(x0);
					stackpush(y);
				}else{
					stackpush(x0-1);
					stackpush(y);
				}
				spanNeedFill = false;
			}//end if
			xnextspan = x0;
			while(pDC->GetPixel(x, y)!=oldcolor && x0<xr)
				x0++;
			if(xnextspan == x0)
				x0++;
		}//end of while(x0<=xr)

	}//end of while(!isstackempty())

///////////////////处理上边的线
	y = yy;
	x = xx;
	//将栈清空
	setstackempty();
	//种子入栈
	stackpush(x);
	stackpush(y);
	while(isstackempty()!=0){
		//栈定出栈，注意出栈顺序
		y = stackpop();
		x = stackpop();
	//	pDC->SetPixel(x, y, newcolor);
		x0 = x;
		while(pDC->GetPixel(x0, y) == oldcolor){ //向右填充
			if(y>120){
				pDC->SetPixel(x0, y, newcolor);
				x0++;
			}else{
				return ;
			}

		}
		xr = x0-1; //最右元素
		x0 = x-1;
		while(pDC->GetPixel(x0, y) == oldcolor){ //向左填充
			pDC->SetPixel(x0, y, newcolor);
			x0--;
		}
		xl = x0+1; //最左元素
		if(xl == xr){
			setstackempty();
		}
		/*xl                                           xr*/
		//处理上面的一条扫描线
		x0 = (int)(xr+xl)/2;

		y = y-1;
		while(x0<=xr){
			spanNeedFill = false;
			while(pDC->GetPixel(x0, y) == oldcolor){
				if(spanNeedFill == false)
					spanNeedFill = true;
				x0++;
			} //
/*			if(spanNeedFill){
				if(x0 == xr){
					stackpush(x0);
					stackpush(y);
				}else{*/
					stackpush(x0-1);
					stackpush(y);
					break;
	//			}
				spanNeedFill = false;
	//		}//end if
			xnextspan = x0;
			while(pDC->GetPixel(x, y)!=oldcolor && x0<xr)
				x0++;


		}//end of while(x0<=xr)

	}//end of while(!isstackempty())


}

void CCG_xView::SeedFill(int xe, int ye, COLORREF newcolor, COLORREF oldcolor)
{
	//实现种子填充算法
	CClientDC dc(this);
	//以种子点为背景色
	if(dc.GetPixel(xe, ye) == oldcolor){
		SeedFill(xe-1, ye, newcolor, oldcolor);
		SeedFill(xe+1, ye, newcolor, oldcolor);
		SeedFill(xe, ye-1, newcolor, oldcolor);
		SeedFill(xe, ye+1, newcolor, oldcolor);
	}//递归
}

void CCG_xView::OnMENU52SpeedFillZhongzi() 
{
	// TODO: Add your command handler code here
	//调用种子填充算法
	m_Type = 7;
	l_Type = 0;
	
}

void CCG_xView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if( m_Type== 7){
		//7：种子填充算法
		int xe = point.x;
		int ye = point.y;
//		printf("(%d, %d)", xe, ye);
		int newcolor = RGB(255, 0, 0);
		int oldcolor = RGB(255, 255, 255);
		SeedFill(xe, ye, newcolor, oldcolor);

	}
	
	CView::OnLButtonUp(nFlags, point);
}

void CCG_xView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	
}

void CCG_xView::OnMenu611Line() 
{
	// TODO: Add your command handler code here
	//线刷子交互式画直线
	m_Type = 2;
	l_Type = 1;
	
}

void CCG_xView::OnMenu612Cricle() 
{
	// TODO: Add your command handler code here
	//线刷子交互式画圆
	m_Type = 4;
	l_Type = 1;
	
}

void CCG_xView::OnMenu621Line() 
{
	// TODO: Add your command handler code here
	//线刷子技术画直线
	m_Type = 2;
	l_Type = 2;
}

void CCG_xView::OnMenu622Cricle() 
{
	// TODO: Add your command handler code here
	//方刷子交互式画圆
	m_Type = 4;
	l_Type = 2;
}

void CCG_xView::OnMenu37Dotline() 
{
	// TODO: Add your command handler code here
	//点划线
	m_Type = 8;
	
}

void CCG_xView::OnMENU71MouseCodeClip() 
{
	// TODO: Add your command handler code here
	//p60用鼠标实现交互式剪切效果
	m_Type = 10;
	l_Type = 0;
	//定义画笔
	CPen PenRed(PS_SOLID, 1, RGB(255, 0, 0)); //定义红笔
	CPen PenBlue(PS_SOLID, 1, RGB(0, 0, 255));//定义蓝色笔

	CDC *pDC = GetDC();
	//先画出窗口，用蓝笔
	pDC->SelectObject(&PenBlue);
	pDC->Rectangle(WL, WB, WR, WT);
	
}

void CCG_xView::encode(int x, int y, int *code)
{
	//图形剪切算法中实现区分9个区域
	int c = 0;
	if(x<WL){
		c = c | LEFT;
	}else if(x>WR){
		c = c | RIGHT;
	}
	if(y<WB){
		c = c | BOTTOM;
	}else if(y>WT){
		c = c | TOP;
	}
	*code = c;

}

int CCG_xView::C_S_Line(CDC *pDC, int x1, int y1, int x2, int y2)
{
	//p60用鼠标实现交互式剪切效果
	
	int code1, code2, code, x, y;
	encode(x1, y1, &code1); //(x1, y1)处的编码
	encode(x2, y2, &code2); //(x2, y2)处的编码
	while(code1 != 0 || code2 != 0) //当code1不等于0 或 code2不等于0
	{
		//当code1与code2不等于0,在同侧
		if((code1&code2)!=0)
			return 0;
		if(code1 ==0)
			code = code2;
		//求交点
		if((LEFT&code)!=0){
			x = WL;
			y = y1+(y2-y2)*(WL-x1)/(x2-x1);
		}else if((RIGHT&code)!=0){
			x = WR;
			y = y1+(y2-y1)*(WR-x1)/(x2-x1);
		}else if((BOTTOM&code)!=0){
			y = WB;
			x = x1+(x2-x1)*(WR-y1)/(y2-y1);
		}else if((TOP&code)!=0){
			y = WT;
			x = x1+(x2-x1)*(WT-y1)/(y2-y1);
		}
		if(code == code1){
			x1 = x;
			y1 = y;
			encode(x, y, &code1);
		}else{
			x2 = x;
			y2 = y;
			encode(x, y, &code2);
		}
	}// end while, 表示code1, code2都为0，其中的线段为可视部分

	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);

	return 0;
}

void CCG_xView::OnMENU81Par() 
{
	// p74抛物线程序设计
	Par(100, 700, 300, 100, 500, 600);
	
}

// 已知起点、中点和终点三个控制点的坐标
void CCG_xView::Par(int xs, int ys, int xm, int ym, int xe, int ye)
{
	// 实现抛物线算法
	CDC *pDC = GetDC();
	// 划线
	pDC->MoveTo(xs, ys);
	pDC->LineTo(xm, ym);
	pDC->MoveTo(xm, ym);
	pDC->LineTo(xe, ye);
	double n, t, dt, ax, ay, bx, by, cx, cy;
	int i;
	ax = xe - 2 * xm + xs;
	ay = ye - 2 * ym + ys;
	bx = 2.0 * (xm - xs);
	by = 2.0 * (ym - ys);
	cx = xs;
	cy = ys;
	n = sqrt(ax * ax + ay * ay);
	n = sqrt(n * 100.0);
	pDC->MoveTo(xs, ys);
	dt = 1.0/n;
	t = 0;
	for(i = 0; i<=n; i++){
		pDC->LineTo((int)(ax * t * t + bx * t + cx), (int)(ay * t * t + by * t + cy));
		t = t+dt;
	}
	pDC->LineTo(xe, ye);

}

void CCG_xView::OnMENU82Hermite() 
{
	// TODO: Add your command handler code here
	// p75Hermite曲线设计
	CDC *pDC = GetDC();
	int i,px0,py0,px1,py1,curx,cury,k0,k1;
	double t,dt,rx0,ry0,rx1,ry1;
	k0=300;
	k1=10;
	px0=40;
	py0=40;
	px1=240;
	py1=40;
	rx0=k0*0.8320;
	ry0=k0*0.5547;
	rx1=k1*0.8320;
	ry1=-0.5547;
    //画坐标轴线
	pDC->MoveTo(20, 20);
	pDC->LineTo(300,20);
	pDC->MoveTo(20, 20);
	pDC->LineTo(20,150);
    //画曲线
	dt=0.01;
	t=0;
	pDC->MoveTo(px0,py0);
    for(i=0;i<=100;i++)
	{
		curx=(int)(h03(t)*px0+h13(t)*px1+h23(t)*rx0+h33(t)*rx1);
        cury=(int)(h03(t)*py0+h13(t)*py1+h23(t)*ry0+h33(t)*ry1);
        pDC->LineTo(curx,cury);
		t=t+dt;
	} 
	getchar();
//	closegraph();
//	restorecrtmode();
}

void CCG_xView::OnMENU83Bezier() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	int i, j, n=2;  //n=2 表示二次Bezier曲线
	double curx,cury,t,b;
    double  dt=0.01;
    int array[4][2]={{30,100},{100,30},{50,150},{200,40}};
    CPen PenRed(PS_SOLID,1,RGB(255,0,0));//定义红色笔
    CPen PenBlue(PS_SOLID,1,RGB(0,0,255));//定义蓝色笔
    //首先绘出特征多边形
    pDC->SelectObject(&PenBlue);
    pDC->MoveTo(array[0][0],array[0][1]);
    for (i=0;i<=n;i++)
	{
        pDC->LineTo(array[i][0],array[i][1]);
        //绘制Bezier曲线
        pDC->MoveTo(array[0][0],array[0][1]); //回到起点
        pDC->SelectObject(&PenRed);
        t=0.0;
		for (i=0;i<=(int)1/dt;i++)
        {
           curx=0; cury=0;
           for(j=0;j<=n;j++)
           {  
              b=Bernstein(j,n,t);
              curx=curx+array[j][0]*b;
              cury=cury+array[j][1]*b;
   	       }
           pDC->LineTo((int)curx,(int)cury);
           t=t+dt;
        }
	}

}

// 1
int CCG_xView::Multiply_n(int m, int n)
{
	int i,j,a;
	if (m!=0)
	{
		a=1;
		for (i=m+1;i<=n;i++)   //求（m+1）(m+2)…(n-1).n
			a=a*i;
		for (j=1;j<=n-m;j++)   //求(n-m)!和C mn
			a=a/j;
		return a;
	}
	else
		return 1;
}
// 2
double CCG_xView::Bernstein(int m, int n, double t)
{
	int i,j;
	double sum;
	sum=Multiply_n(m,n);  //求C mn
	for (i=1;i<=m;i++)
		sum=sum*t;          // C mn tm
	for (j=1;j<=n-m;j++)
		sum=sum*(1-t);     // C mn tm(1-t)n-m
	return sum;
}

void CCG_xView::OnMENU84Bezier3() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	// 3次Bezier曲线
	int i;
	int x0,y0,x1,y1,x2,y2,x3,y3,curx,cury;
	double t,dt;
	// 创建两个不同颜色的画笔
	CPen PenRed(PS_SOLID,1,RGB(255,0,0));
	CPen PenBlue(PS_SOLID,1,RGB(0,0,255));

	// 设置控制点，绘出特征多边形
	x0=220;y0=10;x1=410;y1=10;x2=225;y2=150;x3=410;y3=100;
	pDC->SelectObject(PenBlue); //使用蓝色画笔
	pDC->MoveTo(x0,y0);
	pDC->LineTo(x1,y1);
	pDC->LineTo(x2,y2);
	pDC->LineTo(x3,y3);
	//绘制Bezier曲线
	pDC->MoveTo(x0,y0);
	t=0; dt=0.01;  //t从0到1，每步增加0.01,取100个点
	pDC->SelectObject(PenRed); //使用红色画笔
	for (i=0;i<=100;i++)
	{
		curx=(int)(b03(t)*x0+b13(t)*x1+b23(t)*x2+b33(t)*x3);
		cury=(int)(b03(t)*y0+b13(t)*y1+b23(t)*y2+b33(t)*y3);
		pDC->LineTo(curx,cury);
		t=t+dt;
	}
}

double CCG_xView::b03(double t)
{
	return(pow(1-t,3));
}

double CCG_xView::b13(double t)
{
	return(3*t*pow(1-t,2));
}

double CCG_xView::b23(double t)
{
	return(3*(1-t)*t*t);
}

double CCG_xView::b33(double t)
{
	return(t*t*t);
}

double CCG_xView::h03(double t)
{
	return (2*pow(t,3)-3*t*t+1);
}

double CCG_xView::h13(double t)
{
	return (-2*pow(t,3)+3*t*t);
}

double CCG_xView::h23(double t)
{
	return (pow(t,3)-2*t*t+t);
}


double CCG_xView::h33(double t)
{
	return (pow(t,3)-2*t*t);
}	

void CCG_xView::OnMENU853ByangtaoLine() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	//三次B样条曲线
	int n,m,pointnum,i,j;
	int x[10],y[10];
	double curx,cury; //(x[i],y[i])为顶点坐标
	double t,dt;
	 
	n=3; pointnum=5; //5个顶点，则绘制（5-3）=2段B样条曲线
	x[1]=10;y[1]=200;x[2]=40;y[2]=100;x[3]=100;y[3]=100;
	x[4]=150;y[4]=150;x[5]=150;y[5]=200;
	//绘出特征多边形
	pDC->MoveTo(x[1],y[1]);
	for (i=2;i<=pointnum;i++)
		pDC->LineTo(x[i],y[i]);
	//绘制B样条曲线
	m=pointnum-n;  dt=0.01;
	for (i=1;i<=m;i++)    //绘制m条B样条曲线
	{
		t=0;
		for (j=0;j<=100;j++) // 绘制每一条B样条曲线
		{
			curx=f03(t)*x[i]+f13(t)*x[i+1]+f23(t)*x[i+2]+f33(t)*x[i+3];
			cury=f03(t)*y[i]+f13(t)*y[i+1]+f23(t)*y[i+2]+f33(t)*y[i+3];
			if (j==0)
				pDC->MoveTo((int)curx,(int)cury);
			else
			{
				pDC->LineTo((int)curx,(int)cury);
				t+=dt;
			}
		}
	}

}

double CCG_xView::f03(double t)
{
	return ((-pow(t,3)+3*pow(t,2)-3*t+1)/6);
}

double CCG_xView::f13(double t)
{
	return ((3*pow(t,3)-6*pow(t,2)+4)/6);
}

double CCG_xView::f23(double t)
{
	return ((-3*pow(t,3)+3*pow(t,2)+3*t+1)/6);
}

double CCG_xView::f33(double t)
{
	return (pow(t,3)/6);
}

void CCG_xView::OnMENUCHANGEpingyi() 
{
	// 平移变换
	CDC *pDC=GetDC();
	int x,y,px,py,xx,yy,dx,dy;
	dx=80;
	dy=-50;
	double hx;
	CPoint tp;
	for (xx=-50;xx<=50;xx=xx+10) 
	{
		for (yy=-50;yy<=50;yy=yy+10)
		{
			for(x=-180;x<=180;x++)
			{
				hx=x*3.1415926/180;
				y=(int)(100*sin(hx));  
				px=320+x+xx;
				py=240-y-yy;
				tp.x=px;tp.y=py;
				pDC->SetPixel(tp,RGB(255,0,0));
			}
		}
	}
}

void CCG_xView::OnMenuChangeXuanxzhuan() 
{
	// 旋转变幻
	CDC *pDC=GetDC();
	int x, y, ang;
	double hx, hd, px, py;
	CPoint tp;
	for (ang=0;ang<=180;ang=ang+10)
	{
	    hd=ang*3.1415926/180;
		for(x=-180;x<=180;x++)
		{
			hx=x*3.1415926/180;
			y=(int)(100*sin(hx));  //正玄函数
			px=320+(x*cos(hd)-y*sin(hd));
			py=240-(x*sin(hd)+y*cos(hd)); //旋转后的坐标
			tp.x=(long)px;
			tp.y=(long)py;
			pDC->SetPixel(tp,RGB(255,0,0));
		}
	}
}

void CCG_xView::OnMenuChangeFangdasuoxiao() 
{
	// 放大缩小变幻
	CDC *pDC=GetDC();
	int x, y;
	double px, py;
    double hx, sx, sy;
    CPoint tp;
    sx=1.5;sy=0.5;     //不等比例放缩
	//放缩前
    for(x=-180;x<=180;x++)
	{
		hx=x*3.1415926/180;
		y=(int)(100*sin(hx));  //正玄函数
		px=320+x;
		py=240-y;
		tp.x=(long)px;
		tp.y=(long)py;
		pDC->SetPixel(tp,RGB(255,0,0));
	}
	//放缩后
	for(x=-180;x<=180;x++)
	{
		hx=x*3.1415926/180;
		y=(int)(100*sin(hx));  //正玄函数
		px=320+(int)x*sx;
		py=240-(int)y*sy;  //比例变换
		tp.x=(long)px;
		tp.y=(long)py;
		pDC->SetPixel(tp,RGB(0,0,255));
	}
}

void CCG_xView::OnMENUOtherFlowers() 
{
	// 花
	CDC *pDC=GetDC();
	ASSERT_VALID(pDC);
	MidpointEllise(pDC, 430, 220, 100, 40, RGB(255,0,0));
	MidpointEllise(pDC, 430, 220, 40, 100, RGB(255,0,0));
	PositiveNegativeParabola(pDC, -0.7, -20, 3, RGB(255,0,0));
	PositiveNegativeParabola(pDC, -0.1, -20, 3, RGB(255,0,0));
}

void CCG_xView::PositiveNegativeParabola(CDC *pDC, double a, double b, double c, int color)
{
	// 花的实现
	int x, y;
	double d;
    x=0;
    y=0;
    pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
    if(a>0)
	{   
		y=1;
		pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
		d=1;
		while(y<=30)
		{
			if(d>=0)
			{
				d=d-2*a*x-a;
				x++;
			}
			else
			{
				d=d+1;
                y++;
			}
            pDC->SetPixel((int)(-x+450+b), (int)(y+225+c), color);
            pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
		}
	}
    else if(a<0)
	{
		x=1;
        pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
        d=1;
        while(y>=-35)
		{
            if(d>=0)
			{
                d=d-1;
                y--;
			}
            else
			{
                d=d-2*a*x-a;
                x++;
			}
            pDC->SetPixel((int)(-x+450+b), (int)(y+225+c), color);
			pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
		}
	}
}

void CCG_xView::OnMenuOthersJiaohushiyidongtuxing() 
{
	// 交互式移动图形
	CDC *pDC=GetDC();
	m_Type = 11; 	
	//绘出一条直线
	p1.x=200;p1.y=100;
	p2.x=550;p2.y=300;
	pDC->MoveTo(p1);
	pDC->LineTo(p2);

}
