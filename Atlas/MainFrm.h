
// MainFrm.h: CMainFrame 클래스의 인터페이스
//

#pragma once
#include "ChildView.h"

class AtlasInfo
{
public:
	AtlasInfo()
		: UV(0, 0, 100, 100)
	{

	}

	AtlasInfo(CString name, int left, int top, int right, int bottom)
		: UV(left, top, right, bottom), Name(name)
	{

	}

	CString	Name;
	CRect	UV;
};

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame() noexcept;
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void LoadTexture(TCHAR* InPath);
	CImage& GetRawImage();
	std::vector<AtlasInfo>& GetAtlasVec();
	bool IsSelected(AtlasInfo* pSel);
	void SelectAtlas(CPoint pt);
	void MoveSelect(CPoint pt);
	void SizeSelect(CPoint pt);
	CString getRawImgName();

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CToolBar		m_wndToolBar;
	CChildView		m_wndView;
	CImage			mRawImg;
	std::vector<AtlasInfo>	mAtlasVec;
	AtlasInfo* mSel;
	CString			mRawImgName;

// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnNewSprite();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


