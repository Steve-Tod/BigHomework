#pragma once


// CEDITSCORE �Ի���

class CEDITSCORE : public CDialogEx
{
	DECLARE_DYNAMIC(CEDITSCORE)

public:
	CEDITSCORE(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEDITSCORE();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_StuName;
	CString m_StuTerm;
	CString StuSub;
	double m_StuScore;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
};
