#pragma once


// CSelection dialog

class CSelection : public CDialog
{
	DECLARE_DYNAMIC(CSelection)

public:
	CSelection(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelection();

	// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString SelectionStr;
	afx_msg void OnEnChangeEdit1();
};
