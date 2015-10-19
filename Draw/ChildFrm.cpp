
// ChildFrm.cpp : CChildFrame 类的实现
//

#include "stdafx.h"
#include "Draw.h"

#include "ChildFrm.h"
//#include "DFTView.h"
//#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int g_outwindows = 0;
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// CChildFrame 构造/析构

CChildFrame::CChildFrame()
{
	// TODO: 在此添加成员初始化代码
	g_outwindows++;
}

CChildFrame::~CChildFrame()
{
	g_outwindows--;
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;
	int width = GetSystemMetrics ( SM_CXSCREEN ); 
	int height= GetSystemMetrics ( SM_CYSCREEN );
	if(g_outwindows == 1)
	{

		//cs.x = 575;
		//cs.y = 0;
		cs.x = width * 2/5;
		cs.y = 0;
		cs.cx = width * 2/5;
		cs.cy = height * 2/5;
		cs.style = cs.style & ~FWS_ADDTOTITLE;
		//CString s = "FDTD仿真软件";
		cs.lpszName = _T("动态显示");
	}
	if(g_outwindows == 2)
	{//cs.x = 570;
		//cs.y = 300;
		cs.x = width * 2/5;
		cs.y = height * 2/5;
		cs.cx = width * 2/5;
		cs.cy = height * 2/5;
		cs.style = cs.style & ~FWS_ADDTOTITLE;
		//CString s = "FDTD仿真软件";
		cs.lpszName = _T("时域解");
	}
	return TRUE;
}

// CChildFrame 诊断

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame 消息处理程序


//BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	//m_wndSplitter1.CreateStatic(this,1,2);
//	//m_wndSplitter1.CreateView(0,0,RUNTIME_CLASS(CDrawView),
//	//	CSize(300,0),pContext);
//
//	//m_wndSplitter2.CreateStatic(&m_wndSplitter1,2,1,
//	//	WS_CHILD | WS_VISIBLE,m_wndSplitter1.IdFromRowCol(0,1));
//	//return CMDIChildWndEx::OnCreateClient(lpcs, pContext);
//
//	/*m_wndSplitter1.CreateView(0,0,RUNTIME_CLASS(CDFTView),
//		CSize(0,150),pContext);*/
////
////	m_wndSplitter1.CreateView(0,0,RUNTIME_CLASS(CDrawView),
////		CSize(300,0),pContext);
//	return TRUE;
//}
