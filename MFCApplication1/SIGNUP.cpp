// SIGNUP.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SIGNUP.h"
#include "afxdialogex.h"

void writechar(CString &s, const char* strPathName) ;
// CSIGNUP �Ի���

IMPLEMENT_DYNAMIC(CSIGNUP, CDialogEx)

CSIGNUP::CSIGNUP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSIGNUP::IDD, pParent)
	, m_susername(_T(""))
	, m_spassword(_T(""))
	, m_Checkstu(FALSE)
	, m_Checktea(FALSE)
	, m_SignType(_T(""))
{

}

CSIGNUP::~CSIGNUP()
{
}

void CSIGNUP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_susername);
	DDX_Text(pDX, IDC_EDIT2, m_spassword);
	DDX_CBString(pDX, IDC_COMBO1, m_SignType);
}


BEGIN_MESSAGE_MAP(CSIGNUP, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSIGNUP::OnBnClickedOk)
END_MESSAGE_MAP()


// CSIGNUP ��Ϣ�������


void CSIGNUP::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE) ;
	if (m_susername.GetLength() && m_spassword.GetLength() && m_SignType.GetLength())
	{
		writechar(m_susername, "userdata.txt") ;
		writechar(m_spassword, "userdata.txt") ;
		if (m_SignType.Compare(_T("��ʦ")) == 0)
		{
			writechar(CString("2"), "userdata.txt");
		}
		else
		{
			writechar(CString("1"), "userdata.txt");
		}
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(L"����������������Ϣ��", L"��ʾ��");
	}
}


