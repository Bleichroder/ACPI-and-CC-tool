#pragma once


// CReadMe �Ի���

class CReadMe : public CDialogEx
{
	DECLARE_DYNAMIC(CReadMe)

public:
	CReadMe(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReadMe();

// �Ի�������
	enum { IDD = IDD_ReadMe };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
