#pragma once


// MyDialog �Ի���

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialog();

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
