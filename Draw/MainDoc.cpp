// MainDoc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw.h"
#include "MainDoc.h"


// CMainDoc

IMPLEMENT_DYNCREATE(CMainDoc, CDocument)

CMainDoc::CMainDoc()
{
}

BOOL CMainDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CMainDoc::~CMainDoc()
{
}


BEGIN_MESSAGE_MAP(CMainDoc, CDocument)
END_MESSAGE_MAP()


// CMainDoc ���

#ifdef _DEBUG
void CMainDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CMainDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CMainDoc ���л�

void CMainDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}
#endif


// CMainDoc ����
