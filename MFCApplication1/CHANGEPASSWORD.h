#pragma once


// CCHANGEPASSWORD 对话框

class CCHANGEPASSWORD : public CDialogEx
{
	DECLARE_DYNAMIC(CCHANGEPASSWORD)

public:
	CCHANGEPASSWORD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCHANGEPASSWORD();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_NameChange;
	CString m_PassOld;
	CString m_PassNew;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
};
