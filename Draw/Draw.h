
// Draw.h : Draw Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDrawApp:
// �йش����ʵ�֣������ Draw.cpp
//

class CDrawApp : public CWinAppEx
{
public:
	CDrawApp();

	CMultiDocTemplate* m_pTemplateTime;
	CMultiDocTemplate* m_pTemplateDFT;

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnDraw();
};

extern CDrawApp theApp;
