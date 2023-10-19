// Insertion.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Insertion.h"
#include "afxdialogex.h"


// CInsertion dialog

IMPLEMENT_DYNAMIC(CInsertion, CDialog)

CInsertion::CInsertion(CWnd* pParent /*=NULL*/)
	: CDialog(CInsertion::IDD, pParent)
	, InsertionStr(_T(""))
{

}

CInsertion::~CInsertion()
{
}

void CInsertion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, InsertionStr);

}


BEGIN_MESSAGE_MAP(CInsertion, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CInsertion::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CInsertion message handlers


void CInsertion::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
