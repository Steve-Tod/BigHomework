#pragma once
#include "afxcmn.h"


// CHOMEPAGE �Ի���

class CHOMEPAGE : public CDialogEx
{
	DECLARE_DYNAMIC(CHOMEPAGE)
	CStatic *welcome ;
public:
	CHOMEPAGE(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHOMEPAGE();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_SearchName;
	afx_msg void OnBnClickedSearchstu();
	CListCtrl SclistForTea;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
};
