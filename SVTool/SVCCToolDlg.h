#pragma once


// CSVCCToolDlg 对话框

class CSVCCToolDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSVCCToolDlg)

public:
	CSVCCToolDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSVCCToolDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_CCTool };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString filestyle,batchpath,sourcepath,dirpath;
	afx_msg void OnBnClickedPathButton();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedReadmeButton();
};
