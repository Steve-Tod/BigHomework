#pragma once


// CSIGNUP �Ի���

class CSIGNUP : public CDialogEx
{
	DECLARE_DYNAMIC(CSIGNUP)

public:
	CSIGNUP(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSIGNUP();

// �Ի�������
	enum { IDD = IDD_SIGNUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_susername;
	CString m_spassword;
	afx_msg void OnBnClickedOk();
	BOOL m_Checkstu;
	BOOL m_Checktea;
	afx_msg void OnBnClickedCheckstu();
	CString m_SignType;
	CString m_spasswordSure;
};
