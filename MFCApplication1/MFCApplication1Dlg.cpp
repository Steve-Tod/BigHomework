// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "SIGNUP.h"
#include "STUSHOW.h"
#include "HOMEPAGE.h"
#include "CHANGEPASSWORD.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//声明的函数
int logincheck(CString &a, CString &b) ;
bool AvailableLength(CString &s, int min, int max);
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
CString  username, password ; //用于存储用户名和密码
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, m_username(_T(""))
	, m_password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHANGEPASSWORD, &CMFCApplication1Dlg::OnBnClickedChangepassword)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
CDialogEx::OnInitDialog();

// 将“关于...”菜单项添加到系统菜单中。

//	IDM_ABOUTBOX 必须在系统命令范围内。
ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
ASSERT(IDM_ABOUTBOX < 0xF000);

CMenu* pSysMenu = GetSystemMenu(FALSE);
if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
	}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::OnBnClickedOk()
{
	UpdateData(TRUE) ;
	CString utemp = m_username, ptemp = m_password ;
	int Type = logincheck(utemp, ptemp);
	if (AvailableLength(m_username, 1, 35) && AvailableLength(m_password, 1, 35))
	{
		if (Type == 1)
		{
			username = m_username ;
			this->ShowWindow(SW_HIDE);
			CSTUSHOW *stu = new CSTUSHOW;
			int Res = stu->DoModal();
			if (Res = IDCANCEL)
			{
				m_username.Empty();
				m_password.Empty();
				UpdateData(FALSE);
				this->ShowWindow(SW_SHOW);
			}
		}
		else if(Type == 2)
		{
			username = m_username ;
			this->ShowWindow(SW_HIDE);
			CHOMEPAGE *Tea = new CHOMEPAGE;
			int Res = Tea->DoModal();
			if (Res = IDCANCEL)
			{
				m_username.Empty();
				m_password.Empty();
				UpdateData(FALSE);
				this->ShowWindow(SW_SHOW);
			}
		}
		else
		{
			MessageBox(_T("密码或用户名错误！")) ;
		}
	}
	else
	{
		MessageBox(L"请输入完整信息，且不要超过35个字符！");
	}
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CSIGNUP newsign ;
	newsign.DoModal() ;
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;
}


void CMFCApplication1Dlg::OnBnClickedChangepassword()
{
	// TODO: 在此添加控件通知处理程序代码
	CCHANGEPASSWORD *New = new CCHANGEPASSWORD;
	New->DoModal();
}
