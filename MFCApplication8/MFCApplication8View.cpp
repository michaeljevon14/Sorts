
// MFCApplication8View.cpp : implementation of the CMFCApplication8View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication8.h"
#endif

#include "MFCApplication8Doc.h"
#include "MFCApplication8View.h"

#include "Insertion.h"
#include "Selection.h"
#include "Bubble.h"
#include <math.h>
#include <tchar.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication8View

IMPLEMENT_DYNCREATE(CMFCApplication8View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication8View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication8View::OnFilePrintPreview)
	ON_COMMAND(ID_REMOVE, &CMFCApplication8View::OnRemove)
	ON_COMMAND(ID_INSERTION, &CMFCApplication8View::OnInsertion)
	ON_COMMAND(ID_SELECTION, &CMFCApplication8View::OnSelection)
	ON_COMMAND(ID_BUBBLE, &CMFCApplication8View::OnBubble)
END_MESSAGE_MAP()

// CMFCApplication8View construction/destruction

CMFCApplication8View::CMFCApplication8View()
	: ViewSelectionStr(_T(""))
{
	// TODO: add construction code here

}

CMFCApplication8View::~CMFCApplication8View()
{
}

BOOL CMFCApplication8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication8View drawing


void CMFCApplication8View::OnDraw(CDC* pDC)
{
	CMFCApplication8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCApplication8View printing


void CMFCApplication8View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


#ifdef _DEBUG
void CMFCApplication8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication8Doc* CMFCApplication8View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication8Doc)));
	return (CMFCApplication8Doc*)m_pDocument;
}
#endif 


void CMFCApplication8View::OnRemove()
{
	// TODO: Add your command handler code here
	//::InvalidateRect(m_hWnd, NULL, true);	

	RedrawWindow();		//erase


	//the NULL argument used by InvalidateRect specifies the entire client area
	//the TRUE argument causes the background to be erased. 
}


void CMFCApplication8View::OnInsertion()		//insertion sort
{
	int  CountInsert = 0, cardvalue, picvalue, size, len, Line = 20, vc[100], val;
	CString  card, pic, text, list[1000], answer;

	CClientDC aDC(this);
	CInsertion aDlg;

	if (aDlg.DoModal() == IDOK)			//user press ok
	{
		//vc = valuecard	->	real card that changed into vc (c1=1.1 or d2=2.2)
		ViewInsertionStr = aDlg.InsertionStr;		//ViewStr

		aDC.DrawText(_T("Input:"), CRect(100, 30 + Line, 1100, 1100), 0); 
		aDC.DrawText(ViewInsertionStr, CRect(150, 30 + Line, 1100, 1100), 0); //print user input
																																		//separating cards
		ViewInsertionStr.Remove(',');		//separate with ","
		len = ViewInsertionStr.GetLength();

		//scan and putting value to card

		for (int i = 0; i < len; i += 2)		//scan card	
		{
			//create list
			text = CString(ViewInsertionStr[i]) + CString(ViewInsertionStr[i + 1]);
			list[CountInsert] = text;

			int a = i;

			//assign pic and card number
			pic = CString(ViewInsertionStr[i]);
			card = CString(ViewInsertionStr[i + 1]);

			cardvalue = 0;	picvalue = 0;

			//if 10
			if (CString(ViewInsertionStr[i + 1]) == "1")
			{
				if (CString(ViewInsertionStr[i + 2]) == "0")
				{
					cardvalue = 9;
					CString text = CString(ViewInsertionStr[i]) + CString(ViewInsertionStr[i + 1]) + CString(ViewInsertionStr[i + 2]);
					list[CountInsert] = text;
					i++;
				}
			}

			//putting value for cards
			if		(card == "2") { cardvalue = 1; }
			else if (card == "3") { cardvalue = 2; }
			else if (card == "4") { cardvalue = 3; }
			else if (card == "5") { cardvalue = 4; }
			else if (card == "6") { cardvalue = 5; }
			else if (card == "7") { cardvalue = 6; }
			else if (card == "8") { cardvalue = 7; }
			else if (card == "9") { cardvalue = 8; }
			//put in value for JQKA	,SHDC
			if		(card == "J" || card == "j") { cardvalue = 10; }
			else if (card == "Q" || card == "q") { cardvalue = 11; }
			else if (card == "K" || card == "k") { cardvalue = 12; }
			else if (card == "A" || card == "a") { cardvalue = 13; }
			//value for picture
			if		(pic == "s" || pic == "S") { picvalue = 400; }
			else if (pic == "h" || pic == "H") { picvalue = 300; }
			else if (pic == "d" || pic == "D") { picvalue = 200; }
			else if (pic == "c" || pic == "C") { picvalue = 100; }

			//changing realcard to valuecard
			val = cardvalue + picvalue;
			vc[CountInsert] = val;
			CountInsert++;
		}
		//end for scan
		
		size = len / 2;

		//insertion sorting
		aDC.DrawText(_T("Step : "), CRect(100, 70 + Line, 1100, 1100), 0);//step://Insertion sorting

		for (int i = 1; i < size; i++)
		{
			//CString arr = list[i];			
			int sel = vc[i];
			CString tmp = list[i];
			int j = i;
			while ((j>0) && (vc[j - 1] < sel))
			{
				list[j] = list[j - 1]; vc[j] = vc[j - 1];
				j--;
			}
			vc[j] = sel;
			list[j] = tmp;
			answer = "";	//reset answer array
			for (int k = 0; k < size; k++)
			{
				if (k == size - 1) 
				{ 
					answer += list[k]; 
				}
				else 
				{ 
					answer += list[k];
					answer += ',';
				}
			}
			Line += 30;

			CString a;
			a.Format(_T("%d"), i); a += ". ";
			aDC.DrawText(a, CRect(130, 70 + Line, 1100, 1100), 0);
			aDC.DrawText(answer, CRect(150, 70 + Line, 1100, 1100), 0);
		}
	}
}


void CMFCApplication8View::OnSelection()					//SELECTION SORT
{
	CClientDC aDC(this);
	CSelection aDlg;
	CString answer;
	int CountSelect = 0;

	if (aDlg.DoModal() == IDOK)			//IF user press ok
	{
		int vc[100];	//vc = valuecard	->	real card that changed into vc 

		ViewSelectionStr = aDlg.SelectionStr;		//ViewStr
		CString list[1000];

		int Line = 0; Line += 20;
		aDC.DrawText(_T("Input:"), CRect(100, 30 + Line, 1100, 1100), 0); 
		aDC.DrawText(ViewSelectionStr, CRect(150, 30 + Line, 1100, 1100), 0); //print
																																		//seperating cards
		ViewSelectionStr.Remove(',');		//seperation with ","
		int len = ViewSelectionStr.GetLength();

		//scan and putting value to card
		int count = 0;
		for (int i = 0; i < len; i += 2)		//scan card	
		{
			//create list
			CString text = CString(ViewSelectionStr[i]) + CString(ViewSelectionStr[i + 1]);
			list[count] = text;

			int a = i;
			CString card, pic;				//assign pic and card number
			pic = CString(ViewSelectionStr[i]);	card = CString(ViewSelectionStr[i + 1]);

			int cardvalue, picvalue;
			cardvalue = 0;	picvalue = 0;

			if (CString(ViewSelectionStr[i + 1]) == "1")		//if 10
			{
				if (CString(ViewSelectionStr[i + 2]) == "0")
				{
					cardvalue = 9;
					CString text = CString(ViewSelectionStr[i]) + CString(ViewSelectionStr[i + 1]) + CString(ViewSelectionStr[i + 2]);
					list[count] = text;
					i++;
				}
			}
			//putting value for cards
			if (card == "2") { cardvalue = 1; }
			else if (card == "3") { cardvalue = 2; }
			else if (card == "4") { cardvalue = 3; }
			else if (card == "5") { cardvalue = 4; }
			else if (card == "6") { cardvalue = 5; }
			else if (card == "7") { cardvalue = 6; }
			else if (card == "8") { cardvalue = 7; }
			else if (card == "9") { cardvalue = 8; }
			//put in value for JQKA	,SHDC
			if (card == "J" || card == "j") { cardvalue = 10; }
			else if (card == "Q" || card == "q") { cardvalue = 11; }
			else if (card == "K" || card == "k") { cardvalue = 12; }
			else if (card == "A" || card == "a") { cardvalue = 13; }
			//value for picture
			if (pic == "s" || pic == "S") { picvalue = 400; }
			else if (pic == "h" || pic == "H") { picvalue = 300; }
			else if (pic == "d" || pic == "D") { picvalue = 200; }
			else if (pic == "c" || pic == "C") { picvalue = 100; }

			//changing realcard to valuecard
			int val = cardvalue + picvalue;
			vc[count] = val;	// c1	 = 1 + 0.1
			count++;
		}
		//end for scan

		//selection sorting
		int size = len / 2;
		int flag;								//flag 
		aDC.DrawText(_T("Step : "), CRect(100, 70 + Line, 1100, 1100), 0);
		for (int i = 0; i < size; i++)
		{
			flag = 0;						// set flag to 0 to start first pass
			int y = i;
			for (int j = i + 1; j < size; j++)
			{
				if (vc[y]<vc[j]) { flag = 1; y = j; }	//trigger swap
			}

			//swapping
			CString tmp;		int tmpt;
			tmp = list[y];		tmpt = vc[y];
			list[y] = list[i];	vc[y] = vc[i];
			list[i] = tmp;		vc[i] = tmpt;

			CString answer;

			if (flag == 1)
			{
				for (int k = 0; k < size; k++)
				{
					answer += list[k];
					if (k < size - 1) { answer += ','; }
				}
				Line += 30;
				CString a;
				CountSelect++;
				a.Format(_T("%d"), CountSelect); a += ". ";
				aDC.DrawText(a, CRect(130, 70 + Line, 1100, 1100), 0);	
				aDC.DrawText(answer, CRect(150, 70 + Line, 1100, 1100), 0);
			}
		}
	}
}


void CMFCApplication8View::OnBubble()						//BUBBLE SORT
{
	CClientDC aDC(this);
	CBubble aDlg;
	int CountBubble = 0;

	if (aDlg.DoModal() == IDOK)			//IF user press ok
	{
		double vc[100];	//vc = valuecard	->	real card that changed into vc (c1=1.1 or d2=2.2)
		ViewBubbleStr = aDlg.BubbleStr;		//ViewStr
		CString list[1000];

		int Line = 0;
		Line += 20;

		aDC.DrawText(_T("Input:"), CRect(100, 30 + Line, 1100, 1100), 0);
		/*int width = itoa(ViewBubbleStr);
		//aDC.Ellipse(ViewBubbleStr, ViewBubbleStr, (ViewBubbleStr), (ViewBubbleStr)); //print*/

		ViewBubbleStr;		//seperation with ","
		int len = ViewBubbleStr.GetLength();

		//scan and putting value to card
		int count = 0;
		for (int i = 0; i < len; i += 2)		//scan card	
		{
			//create list
			CString text = CString(ViewBubbleStr[i]);
			list[count] = text;

			int a = i;
			CString bubble;
			bubble = CString(ViewBubbleStr[i]);


		}
		//end for scan

		int size = len / 2;

		//Bubble sorting
		CString tmptext; double tmp;
		int j = 0;
		aDC.DrawText(_T("Step : "), CRect(100, 70 + Line, 1100, 1100), 0);
		do
		{
			tmp = vc[0];								//indicator for the loop
			tmptext = list[0];
			for (int i = 1; i < size; i++)				//start checking until the end
				if (vc[i - 1] < vc[i])
				{
					tmp = vc[i];		 tmptext = list[i];					//swap
					vc[i] = vc[i - 1];	 list[i] = list[i - 1];
					vc[i - 1] = tmp;	 list[i - 1] = tmptext;
					CString answer;
					for (int k = 0; k < size; k++)			//print out 
					{
						if (k == size - 1) { answer += list[k]; }
						else { answer += list[k];	answer += ","; }	// if not end , keep printing ","
					}
					Line += 30;
					CString a;
					CountBubble++;
					a.Format(_T("%d"), CountBubble); a += ". ";
					aDC.DrawText(a, CRect(130, 70 + Line, 1100, 1100), 0);	
					aDC.DrawText(answer, CRect(150, 70 + Line, 1100, 1100), 0);
					j++;
				}
		} while (tmp != vc[0]); //tmp won't be equal vc[0] if there is swap
	}
}
