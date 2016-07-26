
// SVToolDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "SVCCToolDlg.h"
#include "SVACPIDlg.h"


// CSVToolDlg �Ի���
class CSVToolDlg : public CDialogEx
{
// ����
public:
	CSVToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SVTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
