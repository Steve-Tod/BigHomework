#pragma once
#include "afxwin.h"


// CSTUSHOW �Ի���

class CSTUSHOW : public CDialogEx
{
	DECLARE_DYNAMIC(CSTUSHOW)

public:
	CSTUSHOW(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSTUSHOW();

// �Ի�������
	enum { IDD = IDD_DIALOGSTU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_STUTerm;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeTerm();
	CString m_Semester;
};
