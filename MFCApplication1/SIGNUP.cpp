// SIGNUP.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "SIGNUP.h"
#include "afxdialogex.h"

void writechar(CString &s, const char* strPathName) ;
// CSIGNUP 对话框

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


// CSIGNUP 消息处理程序


void CSIGNUP::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE) ;
	if (m_susername.GetLength() && m_spassword.GetLength() && m_SignType.GetLength())
	{
		writechar(m_susername, "userdata.txt") ;
		writechar(m_spassword, "userdata.txt") ;
		if (m_SignType.Compare(_T("老师")) == 0)
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
		MessageBox(L"请完整输入您的信息！", L"提示！");
	}
}


