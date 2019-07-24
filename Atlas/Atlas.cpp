
// Atlas.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Atlas.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAtlasApp

BEGIN_MESSAGE_MAP(CAtlasApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CAtlasApp::OnAppAbout)
	ON_COMMAND(ID_FILE_OPEN, &CAtlasApp::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CAtlasApp::OnFileSave)
	ON_COMMAND(ID_FILE_NEW, &CAtlasApp::OnFileNew)
END_MESSAGE_MAP()


// CAtlasApp 생성

CAtlasApp::CAtlasApp() noexcept
{
	// TODO: 아래 애플리케이션 ID 문자열을 고유 ID 문자열로 바꾸십시오(권장).
	// 문자열에 대한 서식: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Atlas.AppID.NoVersion"));

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}

// 유일한 CAtlasApp 개체입니다.

CAtlasApp theApp;


// CAtlasApp 초기화

BOOL CAtlasApp::InitInstance()
{
	CWinApp::InitInstance();


	// OLE 라이브러리를 초기화합니다.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// RichEdit 컨트롤을 사용하려면 AfxInitRichEdit2()가 있어야 합니다.
	// AfxInitRichEdit2();

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 애플리케이션 마법사에서 생성된 애플리케이션"));


	// 주 창을 만들기 위해 이 코드에서는 새 프레임 창 개체를
	// 만든 다음 이를 애플리케이션의 주 창 개체로 설정합니다.
	CFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 프레임을 만들어 리소스와 함께 로드합니다.
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);





	// 창 하나만 초기화되었으므로 이를 표시하고 업데이트합니다.
	pFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pFrame->UpdateWindow();
	return TRUE;
}

int CAtlasApp::ExitInstance()
{
	//TODO: 추가한 추가 리소스를 처리합니다.
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CAtlasApp 메시지 처리기


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CAtlasApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CAtlasApp 메시지 처리기


void CAtlasApp::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (CMainFrame * pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd()))
	{
		// pMainFrame->이미지 이름

		/*
		TODO.
		<img name="">
			<img name= "", left ="" ...></img>
		</img>
		*/
		CImage& Raw = pMainFrame->GetRawImage();
		auto& Vec = pMainFrame->GetAtlasVec();
		//CFileFind asdf;
		//CFile a;
		//a.Open();
		//a.Close();
		//a.GetFilePath(); // 풀패스
		//a.GetFileTitle(); // 이름만
		//a.GetFileName(); // 이름 + 확장자
		Vec.begin()->UV.left / Raw.GetWidth();
		Vec.begin()->UV.right / Raw.GetWidth();
		Vec.begin()->UV.top / Raw.GetHeight();
		Vec.begin()->UV.bottom / Raw.GetHeight();
		// 0~1 실수
		
	}
	
}


void CAtlasApp::OnFileSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (CMainFrame * pMainFrame = static_cast<CMainFrame*>(AfxGetMainWnd()))
	{
		// pMainFrame->이미지 이름
		pMainFrame->GetAtlasVec();
	}
}


void CAtlasApp::OnFileNew()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
