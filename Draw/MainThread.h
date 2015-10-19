#pragma once

#include "DFTView.h"
#include "MainView.h"
#include "DrawDoc.h"
#include "MainDoc.h"
#include "ProsDlg.h"
// CMainThread
#define WM_SHOW_DFT WM_USER + 3
#define WM_PROS     WM_USER + 5
class CMainThread : public CWinThread
{
	DECLARE_DYNCREATE(CMainThread)

protected:
	CMainThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CMainThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	afx_msg void ShowDFT(WPARAM wParam,LPARAM lParam);
	afx_msg void OnPross(WPARAM wParam,LPARAM lParam);
protected:
	DECLARE_MESSAGE_MAP()
public:
	CProsDlg m_dlg;
};


