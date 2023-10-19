// Bubble.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "Bubble.h"
#include "afxdialogex.h"


// CBubble dialog

IMPLEMENT_DYNAMIC(CBubble, CDialog)

CBubble::CBubble(CWnd* pParent /*=NULL*/)
	: CDialog(CBubble::IDD, pParent)
	, BubbleStr(_T(""))
{

}

CBubble::~CBubble()
{
}

void CBubble::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, BubbleStr);

}


BEGIN_MESSAGE_MAP(CBubble, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CBubble::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CBubble message handlers


void CBubble::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
