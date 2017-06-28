// STUSHOW.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "STUSHOW.h"
#include "afxdialogex.h"
#include "memberclass.h"
#include <vector>

extern std::vector<STU> stu;
extern CString username;
int FindStu(const char*s, std::vector<STU> &stu);
int This;
// CSTUSHOW 对话框

IMPLEMENT_DYNAMIC(CSTUSHOW, CDialogEx)

CSTUSHOW::CSTUSHOW(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSTUSHOW::IDD, pParent)
	, m_Semester(_T(""))
{

}

CSTUSHOW::~CSTUSHOW()
{
}

void CSTUSHOW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TERM, m_STUTerm);
	DDX_CBString(pDX, IDC_TERM, m_Semester);
}


BEGIN_MESSAGE_MAP(CSTUSHOW, CDialogEx)
	ON_CBN_SELCHANGE(IDC_TERM, &CSTUSHOW::OnCbnSelchangeTerm)
END_MESSAGE_MAP()


// CSTUSHOW 消息处理程序


BOOL CSTUSHOW::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	USES_CONVERSION;
	char *s = T2A(username);
	This = FindStu(s, stu);

	stu[This].GetTerm(m_STUTerm);
	CStatic *Welcome = new CStatic;
	CString Wel(_T("欢迎"));
	Wel += username;
	Wel += _T("同学！");
	Welcome->Create(Wel, WS_CHILD | WS_VISIBLE, CRect(10, 10, 220, 50), this, 998);
	
	return TRUE;
}


void CSTUSHOW::OnCbnSelchangeTerm()
{
	// TODO: 在此添加控件通知处理程序代码
	if (This >=0)
	{
		CListCtrl *Sclist = new CListCtrl;
		Sclist->Create(LVS_REPORT | WS_CHILD | WS_VISIBLE, CRect(40, 110, 350, 400), this, 999);
		Sclist->InsertColumn(0, _T("Subject"), LVCFMT_LEFT, 155);
		Sclist->InsertColumn(1, _T("Score"), LVCFMT_LEFT, 155);
		CString Sem;
		m_STUTerm.GetLBText(m_STUTerm.GetCurSel(),Sem);
		stu[This].SctoList(Sclist, Sem);
	}
}
