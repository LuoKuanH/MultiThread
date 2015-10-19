#pragma once
#include "DrawView.h"
#include "DFTView.h"
#include "MainView.h"
#include "Draw.h"
#include "DrawDoc.h"
#include "MainDoc.h"
#include "MainFrm.h"
//#include "ProsDlg.h"
// CViewThread
#define WM_SHOW_VI  WM_USER + 2
//#define WM_PROS     WM_USER + 5
class CViewThread : public CWinThread
{
	DECLARE_DYNCREATE(CViewThread)

protected:
	CViewThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CViewThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
public:
	CDrawView *drawview;
	CDFTView  *dftview;
public:
	afx_msg void ShowView(WPARAM wParam,LPARAM lParam);
	//afx_msg void OnPross(WPARAM wParam,LPARAM lParam);
protected:
	DECLARE_MESSAGE_MAP()

public:
	void drawline();
public:
	//CProsDlg m_dlg;
};


