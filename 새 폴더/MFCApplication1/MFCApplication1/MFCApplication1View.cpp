
// MFCApplication1View.cpp : CMFCApplication1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#include <math.h>
#include "nr.h"
#include "nrutil.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication1View 생성/소멸

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 그리기

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CPen penel(PS_DOT, 2, RGB(0, 0, 255));
	CPen penelGaussian(PS_ENDCAP_FLAT, 1, RGB(0, 0, 0));
	CPen penelUniform(PS_ENDCAP_FLAT, 1, RGB(255, 0, 0));

	int dum = -1, dum2 = -1, uniformIndex, gaussianIndex, i;
	int minUniform, minGaussian, maxUniform, maxGaussian;
	float uniform, gaussian;
	double a, b, m, s;
	int uniformH[1000] = {0};
	int gaussianH[1000] = {0};

	a = -2, b = 3, m = 0.5, s = 1.25;
	for(i = 0; i < 100; i++) {
		uniform = NR::ran2(dum);
		uniform = uniform * (b - a) + a;
		gaussian = NR::gasdev(dum2);
		gaussian = gaussian * s + m;
		
		//
		uniformIndex = uniform * 20 + 100;
		gaussianIndex = gaussian * 20 + 100;
		if(uniformIndex < 1000 && uniformIndex >= 0)
			uniformH[uniformIndex]++;
		if(gaussianIndex < 1000 && gaussianIndex >= 0)
			gaussianH[gaussianIndex]++;
	}
	minUniform = uniformH[0], minGaussian = gaussianH[0];
	maxUniform = uniformH[0], maxGaussian = gaussianH[0];
	for(i = 0; i < 1000; i++) {
		if(minUniform > uniformH[i])
			minUniform = uniformH[i];
		if(maxUniform < uniformH[i])
			maxUniform = uniformH[i];
		
		if(minGaussian > gaussianH[i])
			minGaussian = gaussianH[i];
		if(maxGaussian < gaussianH[i])
			maxGaussian = gaussianH[i];
	}
	for(i = 0; i < 1000; i++) {
		uniformH[i] = (uniformH[i] - minUniform) * 500/(maxUniform - minUniform);
		gaussianH[i] = (gaussianH[i] - minGaussian)*500/(maxGaussian - minGaussian);

	}
	
	pDC->SelectObject(&penelGaussian);
	for(int i = 0;i < 1000;i++) {
		pDC->MoveTo(i, 500);
		pDC->LineTo(i, 500-gaussianH[i]);
	}
	
	/*
	pDC->SelectObject(&penelUniform);
	for(int i = 0; i < 1000; i++) {
		pDC->MoveTo(i, 500);
		pDC->LineTo(i, 500 - uniformH[i]);
	}
	*/
	pDC->SelectObject(&penel);
	pDC->MoveTo(0, 500);
	pDC->LineTo(1000, 500);
	pDC->MoveTo(500, 0);
	pDC->LineTo(500, 1000);

}


// CMFCApplication1View 인쇄


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View 진단

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 메시지 처리기
