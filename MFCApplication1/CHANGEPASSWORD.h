#pragma once


// CCHANGEPASSWORD �Ի���

class CCHANGEPASSWORD : public CDialogEx
{
	DECLARE_DYNAMIC(CCHANGEPASSWORD)

public:
	CCHANGEPASSWORD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCHANGEPASSWORD();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_NameChange;
	CString m_PassOld;
	CString m_PassNew;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
};
