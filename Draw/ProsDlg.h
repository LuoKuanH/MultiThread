#pragma once
#include "afxcmn.h"


// CProsDlg �Ի���

class CProsDlg : public CDialog
{
	DECLARE_DYNAMIC(CProsDlg)

public:
	CProsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProsDlg();

// �Ի�������
	enum { IDD = IDD_PROGRESS };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_pros;
	afx_msg void OnPaint();
};
