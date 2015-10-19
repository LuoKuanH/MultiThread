// MainView.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "MainView.h"


// CMainView
extern int datax[100];
extern int datay[100];
IMPLEMENT_DYNCREATE(CMainView, CView)

CMainView::CMainView()
{

}

CMainView::~CMainView()
{
}

BEGIN_MESSAGE_MAP(CMainView, CView)
END_MESSAGE_MAP()


// CMainView 绘图

void CMainView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	//CClientDC dc (this);
	//for (int i=0; i<100; i++)
	//{
	//	dc.MoveTo(i,150);
	//	dc.LineTo(5*i,150);
	//	Sleep(10);
	//}
}


// CMainView 诊断

#ifdef _DEBUG
void CMainView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMainView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMainView 消息处理程序
void CMainView::drawline()
{
	//CWindowDC dc(this);
	//CPen pen1(PS_SOLID,1,RGB(0,255,0)); ////建立一个画笔类对象，构造时设置画笔属性
	//dc.SelectObject(&pen1);
	CClientDC dc (this);
	//CRect rect;
	//GetClientRect(&rect);
	//dc.MoveTo(rect.left,rect.bottom/2);
	//dc.LineTo(rect.right/2,rect.bottom/2);
	CPen pen1(PS_SOLID,1,RGB(0,255,0)); ////建立一个画笔类对象，构造时设置画笔属性
	dc.SelectObject(&pen1);
	for (int i=0; i<100; i++)
	{
		dc.MoveTo(datax[i],150);
		dc.LineTo(datay[i],150);
		//Sleep(10);
	}
}