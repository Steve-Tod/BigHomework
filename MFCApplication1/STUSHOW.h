#pragma once
#include "afxwin.h"


// CSTUSHOW 对话框

class CSTUSHOW : public CDialogEx
{
	DECLARE_DYNAMIC(CSTUSHOW)

public:
	CSTUSHOW(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSTUSHOW();

// 对话框数据
	enum { IDD = IDD_DIALOGSTU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_STUTerm;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeTerm();
	CString m_Semester;
};
