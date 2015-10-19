// ViewThread.cpp : 实现文件
//

#include "stdafx.h"

#include "ViewThread.h"


// CViewThread
extern int datax[100];
extern int datay[100];
extern int data;
IMPLEMENT_DYNCREATE(CViewThread, CWinThread)

CViewThread::CViewThread()
{
}

CViewThread::~CViewThread()
{
}

BOOL CViewThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	//HWND hWnd = AfxGetMainWnd()->m_hWnd;
	//POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	//CDocTemplate *m_doc=theApp.GetNextDocTemplate(curTemplatePos);
	//HDC dc = GetDC(hWnd);
	////获得文档:
	//curTemplatePos=m_doc->GetFirstDocPosition();
	//CDrawDoc *m_pdoc=(CDrawDoc*)m_doc->GetNextDoc(curTemplatePos);
	////获得视图:
	//curTemplatePos=m_pdoc->GetFirstViewPosition();
	//CDFTView *m_pview=(CDFTView*)m_pdoc->GetNextView(curTemplatePos);
	//if (m_pview->IsKindOf(RUNTIME_CLASS(CDFTView)))
	//{
	//	//AfxMessageBox(_T("haha"));
	//	//m_pview->drawline();
	//}
	//m_pview->drawline();
	//CDrawView *m_dview=(CDrawView*)m_pdoc->GetNextView(curTemplatePos);
	//if (m_dview->IsKindOf(RUNTIME_CLASS(CDrawView)))
	//{
	//	AfxMessageBox(_T("aaa"));
	//}
	/*m_pview=(CView*)m_pdoc->GetNextView(curTemplatePos);
	if (m_pview->IsKindOf(RUNTIME_CLASS(CDFTView)))
	{
		AfxMessageBox(_T("DFT"));
	}*/
	//theApp.m_pTemplateTime->OpenDocumentFile(NULL);

	/*m_dlg.Create(IDD_PROGRESS);
	(m_dlg.m_pros).SetRange(0,100);
	m_dlg.ShowWindow(SW_SHOW);*/
	//m_dlg.DoModal();
	return TRUE;
}

int CViewThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理

	//调用视图函数:
	//m_pview->OnDraw(dc);
	//CDrawDoc* pDoc = (CDrawDoc*)GetDocument();    
	//CView*   pView;      
	//POSITION   pos=pDoc->GetFirstViewPosition();      
	//while(pos!=NULL){      
	//	pView=pDoc->GetNextView(pos);      
	//	if(pView->IsKindOf(RUNTIME_CLASS(CDrawView)))      
	//		break;    
	//}     
	////pView->GetParaentFrame()->ActiveFrame();
	//pView->GetParentFrame()->ActivateFrame();
	////lineview->Draw();
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CViewThread, CWinThread)
	ON_THREAD_MESSAGE(WM_SHOW_VI,ShowView)
	//ON_THREAD_MESSAGE(WM_PROS,OnPross)
END_MESSAGE_MAP()


// CViewThread 消息处理程序
void CViewThread::ShowView(WPARAM wParam,LPARAM lParam)
{
	//CString str;
	//double time = (double)lParam;
	//str.Format(_T("第%d个素数为%d,%f"),PrimeNumbers,result,time);
	//MessageBox(str);
	//return 0;
	//HWND hWnd = AfxGetMainWnd()->m_hWnd;
	//HDC dc = GetDC(hWnd);
//AfxMessageBox(_T("Draw线程"));
//	//CDFTView *dftview;
//	//CDFTView *dview = (CDFTView *)CreateObject();
//	//dview->drawline();
//	//drawline();
////	CDFTView* dftView=(CDFTView*)GetView(RUNTIME_CLASS(CDFTView));


	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc=theApp.GetNextDocTemplate(curTemplatePos);
	//获得文档:
	curTemplatePos=m_doc->GetFirstDocPosition();
	CDrawDoc *m_pdoc=(CDrawDoc*)m_doc->GetNextDoc(curTemplatePos);
	//获得视图:
	curTemplatePos=m_pdoc->GetFirstViewPosition();
	CMainView *m_dview;
	while(curTemplatePos !=NULL)
	{
		m_dview = (CMainView*)m_pdoc->GetNextView(curTemplatePos);
		if (m_dview->IsKindOf(RUNTIME_CLASS(CMainView)))
		{
			m_dview->drawline();
			//AfxMessageBox(_T("有"));
		}
		else
		{

		}
	}
	//m_dview=(CMainView*)m_pdoc->GetNextView(curTemplatePos);
	//调用视图函数:
	//m_dview->SetActiveWindow();
	//m_dview->drawline();



//调用视图函数:

}

void CViewThread::drawline()
{
	/*HWND hWnd = AfxGetMainWnd()->m_hWnd;
	HDC dc = GetDC(hWnd);
	for (int i=0; i<100; i++)
	{
		MoveToEx(dc,datax[i],datax[i],NULL);
		LineTo(dc,datay[i],datay[i]);
	}*/
}
//void CViewThread::OnPross(WPARAM wParam,LPARAM lParam)
//{
//	m_dlg.m_pros.SetPos(data);
//}