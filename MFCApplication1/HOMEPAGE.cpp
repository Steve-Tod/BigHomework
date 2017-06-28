// HOMEPAGE.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "HOMEPAGE.h"
#include "afxdialogex.h"
#include <vector>
#include "memberclass.h"
#include "EDITSCORE.h"

extern CString username, password ;
extern std::vector<STU> stu;
int FindStu(const char*s, std::vector<STU> &stu);
void ScoretoFile(std::vector<STU> &stu, const char* strPathName);
int StuNum;
// CHOMEPAGE 对话框

IMPLEMENT_DYNAMIC(CHOMEPAGE, CDialogEx)

CHOMEPAGE::CHOMEPAGE(CWnd* pParent /*=NULL*/): CDialogEx(CHOMEPAGE::IDD, pParent), welcome(NULL)
, m_SearchName(_T(""))
{
	
}

CHOMEPAGE::~CHOMEPAGE()
{
}

void CHOMEPAGE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SearchName);
	DDX_Control(pDX, IDC_LIST1, SclistForTea);
}


BEGIN_MESSAGE_MAP(CHOMEPAGE, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCHSTU, &CHOMEPAGE::OnBnClickedSearchstu)
	ON_BN_CLICKED(IDC_SEARCHSTU, &CHOMEPAGE::OnBnClickedSearchstu)
	ON_BN_CLICKED(IDC_BUTTON2, &CHOMEPAGE::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CHOMEPAGE::OnBnClickedCancel)
END_MESSAGE_MAP()


// CHOMEPAGE 消息处理程序
BOOL CHOMEPAGE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CStatic *Welcome = new CStatic;
	CString Wel(_T("欢迎"));
	Wel += username;
	Wel += _T("老师！");
	Welcome->Create(Wel, WS_CHILD | WS_VISIBLE, CRect(10, 10, 220, 50), this, 997);
	//列表初始化
	RECT rect;   
	SclistForTea.GetWindowRect(&rect);   
    long   width = rect.right - rect.left; 
	SclistForTea.InsertColumn(0, _T("Semester"), LVCFMT_LEFT, width / 3);
	SclistForTea.InsertColumn(1, _T("Subject"), LVCFMT_LEFT, width / 3);
	SclistForTea.InsertColumn(2, _T("Score"), LVCFMT_LEFT, width / 3);

	return TRUE;
}
void CHOMEPAGE::OnBnClickedSearchstu()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	USES_CONVERSION;
	char *s = T2A(m_SearchName);

	StuNum = FindStu(s, stu);

	SclistForTea.DeleteAllItems();

	CListCtrl *List = &SclistForTea;
	if (StuNum >= 0)
	{
		stu[StuNum].SctoList(List);
	}
	else
	{
		MessageBox(_T("查无此人！"), _T("提示"), MB_OK) ;
	}
}



void CHOMEPAGE::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CEDITSCORE NewEdit;
	NewEdit.DoModal();
}


void CHOMEPAGE::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	ScoretoFile(stu, "score.txt");
	CDialogEx::OnCancel();
}
