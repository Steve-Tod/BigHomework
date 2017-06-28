#pragma once
#include "afxcmn.h"


// CHOMEPAGE 对话框

class CHOMEPAGE : public CDialogEx
{
	DECLARE_DYNAMIC(CHOMEPAGE)
	CStatic *welcome ;
public:
	CHOMEPAGE(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHOMEPAGE();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_SearchName;
	afx_msg void OnBnClickedSearchstu();
	CListCtrl SclistForTea;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
};
