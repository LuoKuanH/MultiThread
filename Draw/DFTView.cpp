// DFTView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "DFTView.h"
#include "DrawDoc.h"

// CDFTView
extern int datax[100];
extern int datay[100];
IMPLEMENT_DYNCREATE(CDFTView, CView)

CDFTView::CDFTView()
{

}

CDFTView::~CDFTView()
{
}

BEGIN_MESSAGE_MAP(CDFTView, CView)
END_MESSAGE_MAP()


// CDFTView ��ͼ

void CDFTView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	/*CWindowDC dc(this);
	CDrawDoc* pDoc = (CDrawDoc*)GetDocument();
	for (int i=0; i<19; i++)
	{
		dc.MoveTo(pDoc->point[i]);
		dc.LineTo(pDoc->point[i+1]);
		Sleep(100);
	}*/
	// TODO: �ڴ���ӻ��ƴ���
	//CClientDC dc (this);
	//for (int i=0; i<100; i++)
	//{
	//	dc.MoveTo(i,150);
	//	dc.LineTo(5*i,150);
	//	Sleep(10);
	//}
}

// CDFTView ���

#ifdef _DEBUG
void CDFTView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CDFTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG

// CDFTView ��Ϣ�������
void CDFTView::drawline()
{
	CClientDC dc(this);
	//CRect rect;
	//GetClientRect(&rect);
	//dc.MoveTo(rect.left,rect.bottom/2);
	//dc.LineTo(rect.right/2,rect.bottom/2);
	//CClientDC dc(this);
	CPen pen1(PS_SOLID,1,RGB(255,0,0)); ////����һ����������󣬹���ʱ���û�������
	dc.SelectObject(&pen1);
	for (int i=0; i<100; i++)
	{
		dc.MoveTo(datax[i],170);
		dc.LineTo(datay[i],170);
		//Sleep(10);
	}
}