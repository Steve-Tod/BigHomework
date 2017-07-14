// MFCApplication1Dlg.cpp : ʵ���ļ�
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

//�����ĺ���
int logincheck(CString &a, CString &b) ;
bool AvailableLength(CString &s, int min, int max);
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
CString  username, password ; //���ڴ洢�û���������
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



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


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
CDialogEx::OnInitDialog();

// ��������...���˵�����ӵ�ϵͳ�˵��С�

//	IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
			MessageBox(_T("������û�������")) ;
		}
	}
	else
	{
		MessageBox(L"������������Ϣ���Ҳ�Ҫ����35���ַ���");
	}
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCHANGEPASSWORD *New = new CCHANGEPASSWORD;
	New->DoModal();
}
