#pragma once


// CDFTView ��ͼ

class CDFTView : public CView
{
	DECLARE_DYNCREATE(CDFTView)

protected:
	CDFTView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDFTView();

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


