// MainThread.cpp : ʵ���ļ�
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
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	m_dlg.Create(IDD_PROGRESS);
	(m_dlg.m_pros).SetRange(0,100);
	//m_dlg.ShowWindow(SW_SHOW);
	return TRUE;
}

int CMainThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMainThread, CWinThread)
	ON_THREAD_MESSAGE(WM_SHOW_DFT,ShowDFT)
	ON_THREAD_MESSAGE(WM_PROS,OnPross)
END_MESSAGE_MAP()


// CMainThread ��Ϣ�������
void CMainThread::ShowDFT(WPARAM wParam,LPARAM lParam)
{
	////CString str;
	////double time = (double)lParam;
	////str.Format(_T("��%d������Ϊ%d,%f"),PrimeNumbers,result,time);
	////MessageBox(str);
	//AfxMessageBox(_T("DFT�߳�"));
	////drawline();
	////return 0;


	POSITION curTemplatePos = theApp.GetFirstDocTemplatePosition();
	CDocTemplate *m_doc=theApp.GetNextDocTemplate(curTemplatePos);
	CDocTemplate *m_doc1=theApp.GetNextDocTemplate(curTemplatePos);//�ĵ�ģ��
	//����ĵ�:
	

	curTemplatePos=m_doc1->GetFirstDocPosition();
	CMainDoc *m_pdoc=(CMainDoc*)m_doc1->GetNextDoc(curTemplatePos);
	//�����ͼ:
	curTemplatePos=m_pdoc->GetFirstViewPosition();
	CDFTView *m_dview;
	while(curTemplatePos !=NULL)
	{
		m_dview = (CDFTView*)m_pdoc->GetNextView(curTemplatePos);
		if (m_dview->IsKindOf(RUNTIME_CLASS(CDFTView)))
		{
			m_dview->drawline();
			//AfxMessageBox(_T("û��"));
		}
		else
		{
			//AfxMessageBox(_T("û��"));
		}
	}

	//POSITION ps=m_pDocManager->GetFirstDocTemplatePosition();
	//CDocTemplate *pDocTemplate=m_pDocManager->GetNextDocTemplate(ps);
	//pDocTemplate->CloseAllDocuments(NULL);//�ر�����ĵ�
	//pDocTemplate=m_pDocManager->GetNextDocTemplate(ps);//ͨ�������ĵ��б��е�һЩ�ĵ�
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
