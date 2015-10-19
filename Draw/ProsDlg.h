#pragma once
#include "afxcmn.h"


// CProsDlg 对话框

class CProsDlg : public CDialog
{
	DECLARE_DYNAMIC(CProsDlg)

public:
	CProsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CProsDlg();

// 对话框数据
	enum { IDD = IDD_PROGRESS };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_pros;
	afx_msg void OnPaint();
};
