
// DrawDoc.h : CDrawDoc ��Ľӿ�
//


#pragma once


class CDrawDoc : public CDocument
{
protected: // �������л�����
	CDrawDoc();
	DECLARE_DYNCREATE(CDrawDoc)

// ����
public:
	CPoint point[20];
// ����
public:
	CWinThread *pThread;
	CWinThread *pDFTThread;
	CWinThread *pDrawThread;
	CWinThread *pPROSThread;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnRedata();
};
