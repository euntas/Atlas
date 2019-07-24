
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Atlas.h"
#include "ChildView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_DROPFILES()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	CRect rc;
	GetClientRect(rc);

	if (CMainFrame * pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd()))
	{
		CImage& RawImg = pMainFrame->GetRawImage();
		if (!RawImg.IsNull())
		{
			float ratioClient = (float)rc.Width() / (float)rc.Height();
			float ratio = (float)RawImg.GetWidth() / (float)RawImg.GetHeight();
			CRect rc2 = rc;
			if (ratioClient < ratio)
				rc2.bottom *= ((float)rc.Height() / (float)rc.Width());
			else
				rc2.right *= ((float)rc.Height() / (float)rc.Width());

			RawImg.Draw(dc, rc2);

			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);

			CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
			CPen Selpen(PS_SOLID, 1, RGB(0, 255, 0));
			

			auto& vec = pMainFrame->GetAtlasVec();
			for (auto& it : vec)
			{
				if (pMainFrame->IsSelected(&it))
				{
					dc.SelectObject(&Selpen);
				}
				else
				{
					dc.SelectObject(&pen);
				}

				dc.Rectangle(it.UV);
			}
		}	
	}

	

	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	TCHAR szPathName[MAX_PATH];
	DragQueryFile(hDropInfo, 0, szPathName, MAX_PATH);	
	DragFinish(hDropInfo);

	if (CMainFrame* pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd()))
	{
		pMainFrame->LoadTexture(szPathName);
		Invalidate();
	}

	CWnd::OnDropFiles(hDropInfo);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	DragAcceptFiles();

	return 0;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (CMainFrame * pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd()))
	{
		pMainFrame->SelectAtlas(point);
		Invalidate();
	}
	
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON)
	{
		if (nFlags & MK_CONTROL)
		{
			if (CMainFrame * pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd()))
			{
				if (PrevPoint.x == 0 && PrevPoint.y == 0)
					PrevPoint = point;

				pMainFrame->SizeSelect(point - PrevPoint);
				PrevPoint = point;
			}
		}
		else
		{
			if (CMainFrame * pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd()))
			{
				pMainFrame->MoveSelect(point);
				Invalidate();
			}
		}
		
	}
	
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	PrevPoint.x = 0;
	PrevPoint.y = 0;

	CWnd::OnLButtonUp(nFlags, point);
}
