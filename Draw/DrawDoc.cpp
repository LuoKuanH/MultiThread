
// DrawDoc.cpp : CDrawDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "ViewThread.h"
#include "MainThread.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawDoc
UINT Calculate(LPVOID pParam);
int datax[100];
int datay[100];
int data;

IMPLEMENT_DYNCREATE(CDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawDoc, CDocument)
	ON_COMMAND(ID_REDATA, &CDrawDoc::OnRedata)
END_MESSAGE_MAP()


// CDrawDoc 构造/析构

CDrawDoc::CDrawDoc()
{
	// TODO: 在此添加一次性构造代码

}

CDrawDoc::~CDrawDoc()
{
}

BOOL CDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	for (int i=0; i<10; i++)
	{
		point[i].x = i*10;
		point[i].y = i*10;
	}
	return TRUE;
}
// CDrawDoc 序列化

void CDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CDrawDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CDrawDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CDrawDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS
// CDrawDoc 诊断
#ifdef _DEBUG
void CDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

// CDrawDoc 命令


void CDrawDoc::OnRedata()
{
	// TODO: 在此添加命令处理程序代码
	/*for (int i=0; i<10; i++)
	{
		point[i].x = i*20;
		point[i].y = i*20;
	}
	UpdateAllViews(NULL);*/
	//pDrawThread = AfxBeginThread(RUNTIME_CLASS(CViewThread));
	//pPROSThread = AfxBeginThread(RUNTIME_CLASS(CMainThread));
	pDFTThread = AfxBeginThread(RUNTIME_CLASS(CMainThread));
	pDrawThread = AfxBeginThread(RUNTIME_CLASS(CViewThread));
	pThread = AfxBeginThread(Calculate,this);

}
UINT Calculate(LPVOID pParam)
{
	CDrawDoc *pdoc = (CDrawDoc*)pParam;
	CViewThread *pdrawThrd = (CViewThread*)(pdoc->pDrawThread);
	CMainThread *pUIThrdd = (CMainThread*)(pdoc->pDFTThread);
	//CViewThread *pdlgThrd = (CViewThread*)(pdoc->pPROSThread);
	for (int i =0; i<100; i++)
	{
		datax[i] = i;
		datay[i] = i*i/2;
		data = i;
		pdrawThrd->PostThreadMessage(WM_SHOW_VI,NULL,NULL);
		//pdlgThrd->PostThreadMessage(WM_PROS,NULL,NULL);
		pUIThrdd->PostThreadMessage(WM_SHOW_DFT,NULL,NULL);
		Sleep(10);
	}
	return 0;
}