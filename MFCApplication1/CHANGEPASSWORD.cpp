// CHANGEPASSWORD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CHANGEPASSWORD.h"
#include "afxdialogex.h"
#include <vector>
#include "memberclass.h"

// CCHANGEPASSWORD �Ի���
bool AvailableLength(CString &s, int min, int max);
void readdata(std::vector<person> &Per, const char* strPathName);
void DatatoFile(std::vector<person> &Per, const char* FilePath);
int FindUser(const char*s, std::vector<person> &stu);
std::vector<person> Per;
IMPLEMENT_DYNAMIC(CCHANGEPASSWORD, CDialogEx)

CCHANGEPASSWORD::CCHANGEPASSWORD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCHANGEPASSWORD::IDD, pParent)
	, m_NameChange(_T(""))
	, m_PassOld(_T(""))
	, m_PassNew(_T(""))
{

}

CCHANGEPASSWORD::~CCHANGEPASSWORD()
{
}

void CCHANGEPASSWORD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_NameChange);
	DDX_Text(pDX, IDC_EDIT2, m_PassOld);
	DDX_Text(pDX, IDC_EDIT3, m_PassNew);
}


BEGIN_MESSAGE_MAP(CCHANGEPASSWORD, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCHANGEPASSWORD::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCHANGEPASSWORD::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCHANGEPASSWORD ��Ϣ�������


void CCHANGEPASSWORD::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(AvailableLength(m_NameChange, 1, 35) && AvailableLength(m_PassOld, 1, 35) && AvailableLength(m_PassNew, 1, 35))
	{	
		USES_CONVERSION ;
		char *s, *po, *pn;
		s = T2A(m_NameChange);
		po = T2A(m_PassOld);
		pn = T2A(m_PassNew);
		int i = FindUser(s, Per);
		if (i >= 0)
		{
			int Result = Per[i].ChangePassword(po, pn);
			if (Result == 1)
			{
				MessageBox(L"�޸ĳɹ���");
				m_NameChange.Empty();
				m_PassNew.Empty();
				m_PassOld.Empty();
				UpdateData(FALSE);
			}
			else if (Result == 0)
			{
				MessageBox(L"�벻Ҫʹ����ͬ������:D");
			}
			else
			{
				MessageBox(L"�������");
			}
		}
		else
		{
			MessageBox(L"�޸�ʧ��");
		}
	}
	else
	{
		MessageBox(L"������������Ϣ���Ҳ�Ҫ����35���ַ�");
	}
}

BOOL CCHANGEPASSWORD::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	readdata(Per, "userdata.txt");
	return TRUE;
}


void CCHANGEPASSWORD::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DatatoFile(Per, "userdata.txt");
	CDialogEx::OnCancel();
}
