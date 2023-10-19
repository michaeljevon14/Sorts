// Selection.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Selection.h"
#include "afxdialogex.h"


// CSelection dialog

IMPLEMENT_DYNAMIC(CSelection, CDialog)

CSelection::CSelection(CWnd* pParent /*=NULL*/)
	: CDialog(CSelection::IDD, pParent)
	, SelectionStr(_T(""))
{

}

CSelection::~CSelection()
{
}

void CSelection::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, SelectionStr);

}


BEGIN_MESSAGE_MAP(CSelection, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CSelection::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CSelection message handlers


void CSelection::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
