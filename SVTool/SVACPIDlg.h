#pragma once


// CSVACPIDlg �Ի���

class CSVACPIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSVACPIDlg)

public:
	CSVACPIDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSVACPIDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ACPI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeState();

public:
	CString ACPIs,state,lasttime,info;
	CString rootpath,logpath,errorpath;
	CString hardwareinfo(void);
	int GetCostTime(CString CurrTime, CString LastTime);
	BOOL CheckDiffInfo(CString ACPISx, CString OriginInfo, CString CurrInfo);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedS3button();
	afx_msg void OnBnClickedS4button();
	afx_msg void OnBnClickedS5button();
	afx_msg void OnBnClickedRbbutton();
	afx_msg void OnBnClickedPbutton();
	afx_msg void OnBnClickedClsbutton();
};
