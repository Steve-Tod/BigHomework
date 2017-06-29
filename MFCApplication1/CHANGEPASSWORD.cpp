// CHANGEPASSWORD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CHANGEPASSWORD.h"
#include "afxdialogex.h"


// CCHANGEPASSWORD 对话框

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


// CCHANGEPASSWORD 消息处理程序


void CCHANGEPASSWORD::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_NameChange.GetLength() && m_PassOld.GetLength() && m_PassNew.GetLength())
	{
	}
	else
	{
		MessageBox(L"请输入完整信息，不要超过35个字符");
	}
	CDialogEx::OnOK();
}
