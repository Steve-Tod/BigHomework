// EDITSCORE.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "EDITSCORE.h"
#include "memberclass.h"

extern std::vector<STU> stu;
void EditScore(CString &n, CString &t, CString &s, double score, std::vector<STU> &stu);
int DeleteScore(CString &n, CString &t, CString &s, std::vector<STU> &stu);
bool AvailableLength(CString &s, int min, int max);
// CEDITSCORE 对话框

IMPLEMENT_DYNAMIC(CEDITSCORE, CDialogEx)

CEDITSCORE::CEDITSCORE(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEDITSCORE::IDD, pParent)
	, m_StuName(_T(""))
	, m_StuTerm(_T(""))
	, StuSub(_T(""))
	, m_StuScore(0)
{

}

CEDITSCORE::~CEDITSCORE()
{
}

void CEDITSCORE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StuName);
	DDX_Text(pDX, IDC_EDIT2, m_StuTerm);
	DDX_Text(pDX, IDC_EDIT3, StuSub);
	DDX_Text(pDX, IDC_EDIT4, m_StuScore);
}


BEGIN_MESSAGE_MAP(CEDITSCORE, CDialogEx)
	ON_BN_CLICKED(IDOK, &CEDITSCORE::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CEDITSCORE::OnBnClickedButton3)
END_MESSAGE_MAP()


// CEDITSCORE 消息处理程序


void CEDITSCORE::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(AvailableLength(m_StuName, 1, 35) && AvailableLength(StuSub, 1, 35) && AvailableLength(m_StuTerm, 1, 35))
	{
		EditScore(m_StuName, m_StuTerm, StuSub, m_StuScore, stu);
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(L"请输入完整信息！", L"提示");
	}
}


void CEDITSCORE::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	MessageBox(L"确定删除？", L"警告");
	if(DeleteScore(m_StuName, m_StuTerm, StuSub, stu))
	{
		MessageBox(L"删除成功！", L"提示");
	}
	else
	{
		MessageBox(L"删除失败！", L"提示");
	}
}
