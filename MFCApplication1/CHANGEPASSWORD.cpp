// CHANGEPASSWORD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CHANGEPASSWORD.h"
#include "afxdialogex.h"


// CCHANGEPASSWORD �Ի���

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
END_MESSAGE_MAP()


// CCHANGEPASSWORD ��Ϣ�������


void CCHANGEPASSWORD::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_NameChange.GetLength() && m_PassOld.GetLength() && m_PassNew.GetLength())
	{
	}
	else
	{
		MessageBox(L"������������Ϣ����Ҫ����35���ַ�");
	}
	CDialogEx::OnOK();
}
