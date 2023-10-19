
// MFCApplication8View.h : interface of the CMFCApplication8View class
//

#pragma once


class CMFCApplication8View : public CView
{
protected: // create from serialization only
	CMFCApplication8View();
	DECLARE_DYNCREATE(CMFCApplication8View)

	// Attributes
public:
	CMFCApplication8Doc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// Implementation
public:
	virtual ~CMFCApplication8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRemove();
	afx_msg void OnInsertion();
	CString ViewInsertionStr;
	afx_msg void OnSelection();
	CString ViewSelectionStr;
	afx_msg void OnBubble();
	CString ViewBubbleStr;
};

#ifndef _DEBUG  // debug version in MFCApplication8View.cpp
inline CMFCApplication8Doc* CMFCApplication8View::GetDocument() const
{
	return reinterpret_cast<CMFCApplication8Doc*>(m_pDocument);
}
#endif

