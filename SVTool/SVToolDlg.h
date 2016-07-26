
// SVToolDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "SVCCToolDlg.h"
#include "SVACPIDlg.h"


// CSVToolDlg 对话框
class CSVToolDlg : public CDialogEx
{
// 构造
public:
	CSVToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SVTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_tab;
	CSVCCToolDlg CCTool;
	CSVACPIDlg ACPI;

	afx_msg void OnClose();
};
