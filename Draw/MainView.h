#pragma once


// CMainView ��ͼ

class CMainView : public CView
{
	DECLARE_DYNCREATE(CMainView)

protected:
	CMainView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMainView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	void drawline();
};


