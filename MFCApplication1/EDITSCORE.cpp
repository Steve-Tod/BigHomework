// EDITSCORE.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "EDITSCORE.h"
#include "memberclass.h"

extern std::vector<STU> stu;
void EditScore(CString &n, CString &t, CString &s, double score, std::vector<STU> &stu);
int DeleteScore(CString &n, CString &t, CString &s, std::vector<STU> &stu);
bool AvailableLength(CString &s, int min, int max);
// CEDITSCORE �Ի���

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


// CEDITSCORE ��Ϣ�������


void CEDITSCORE::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(AvailableLength(m_StuName, 1, 35) && AvailableLength(StuSub, 1, 35) && AvailableLength(m_StuTerm, 1, 35))
	{
		EditScore(m_StuName, m_StuTerm, StuSub, m_StuScore, stu);
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(L"������������Ϣ��", L"��ʾ");
	}
}


void CEDITSCORE::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	MessageBox(L"ȷ��ɾ����", L"����");
	if(DeleteScore(m_StuName, m_StuTerm, StuSub, stu))
	{
		MessageBox(L"ɾ���ɹ���", L"��ʾ");
	}
	else
	{
		MessageBox(L"ɾ��ʧ�ܣ�", L"��ʾ");
	}
}
