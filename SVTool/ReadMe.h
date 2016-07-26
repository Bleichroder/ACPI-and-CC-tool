#pragma once


// CReadMe 对话框

class CReadMe : public CDialogEx
{
	DECLARE_DYNAMIC(CReadMe)

public:
	CReadMe(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CReadMe();

// 对话框数据
	enum { IDD = IDD_ReadMe };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
