#pragma once


// CInsertion dialog

class CInsertion : public CDialog
{
	DECLARE_DYNAMIC(CInsertion)

public:
	CInsertion(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInsertion();

	// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString InsertionStr;
};
