// atlaslist.cpp: 구현 파일
//

#include "pch.h"
#include "Atlas.h"
#include "atlaslist.h"
#include "afxdialogex.h"


// atlaslist 대화 상자

IMPLEMENT_DYNAMIC(atlaslist, CDialogEx)

atlaslist::atlaslist(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

atlaslist::~atlaslist()
{
}

void atlaslist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mAtlasList);
}


BEGIN_MESSAGE_MAP(atlaslist, CDialogEx)
END_MESSAGE_MAP()


// atlaslist 메시지 처리기
