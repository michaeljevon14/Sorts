#pragma once


// CBubble dialog

class CBubble : public CDialog
{
	DECLARE_DYNAMIC(CBubble)

public:
	CBubble(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBubble();

	// Dialog Data
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString BubbleStr;
};
