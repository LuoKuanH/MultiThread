// MainThread.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw.h"
#include "MainThread.h"


// CMainThread
extern CDrawApp theApp;
extern int data;
IMPLEMENT_DYNCREATE(CMainThread, CWinThread)

CMainThread::CMainThread()
{
}

CMainThread::~CMainThread()
{
}

BOOL CMainThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	m_dlg.Create(IDD_PROGRESS);
	(m_dlg.m_pros).SetRange(0,100);
	//m_dlg.ShowWindow(SW_SHOW);
	return TRUE;
}

int CMainThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMainThread, CWinThread)
	ON_THREAD_MESSAGE(WM_SHOW_DFT,ShowDFT)
	ON_THREAD_MESSAGE(WM_PROS,OnPross)
END_MESSAGE_MAP()


// CMainThread 消息处理程序
void CMainThread::ShowDFT(WPARAM wParam,LPARAM lParam)
{
	////CString str;
	////double time = (double)lParam;
	////str.Format(_T("第%d个素数为%d,%f"),PrimeNumbers,result,time);
	////MessageBox(str);
	//AfxMessageBox(_T("DFT线程"));
	////drawline();
	////return 0;


	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc=theApp.GetNextDocTemplate(curTemplatePos);
	CDocTemplate *m_doc1=theApp.GetNextDocTemplate(curTemplatePos);//文档模板
	//获得文档:
	

	curTemplatePos=m_doc1->GetFirstDocPosition();
	CMainDoc *m_pdoc=(CMainDoc*)m_doc1->GetNextDoc(curTemplatePos);
	//获得视图:
	curTemplatePos=m_pdoc->GetFirstViewPosition();
	CDFTView *m_dview;
	while(curTemplatePos !=NULL)
	{
		m_dview = (CDFTView*)m_pdoc->GetNextView(curTemplatePos);
		if (m_dview->IsKindOf(RUNTIME_CLASS(CDFTView)))
		{
			m_dview->drawline();
			//AfxMessageBox(_T("没得"));
		}
		else
		{
			//AfxMessageBox(_T("没得"));
		}
	}

	//POSITION ps=m_pDocManager->GetFirstDocTemplatePosition();
	//CDocTemplate *pDocTemplate=m_pDocManager->GetNextDocTemplate(ps);
	//pDocTemplate->CloseAllDocuments(NULL);//关闭这个文档
	//pDocTemplate=m_pDocManager->GetNextDocTemplate(ps);//通过跳过文档列表中的一些文档
	//pDocTemplate = m_pDocManager->GetNextDocTemplate(ps);
	//while (ps != NULL)
	//{
	//	pDocTemplate=m_pDocManager->GetNextDocTemplate(ps);
	//
	//}
	//CMainFrame *pMain =(CMainFrame *)AfxGetMainWnd();
	//CDFTView *pView=(CDFTView *)pMain->GetActiveView();
	//pView->drawline();
}
void CMainThread::OnPross(WPARAM wParam,LPARAM lParam)
{
	m_dlg.m_pros.SetPos(data);
	Sleep(10);
	//CWnd *pi=GetDlgItem(this,IDD_PROGRESS);
	//m_dlg.OnPaint();
	
}
