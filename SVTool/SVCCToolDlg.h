#pragma once


// CSVCCToolDlg �Ի���

class CSVCCToolDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSVCCToolDlg)

public:
	CSVCCToolDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSVCCToolDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CCTool };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString filestyle,batchpath,sourcepath,dirpath;
	afx_msg void OnBnClickedPathButton();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedReadmeButton();
};
