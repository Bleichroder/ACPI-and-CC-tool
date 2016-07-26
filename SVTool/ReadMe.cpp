// ReadMe.cpp : 实现文件
//

#include "stdafx.h"
#include "SVTool.h"
#include "ReadMe.h"
#include "afxdialogex.h"


// CReadMe 对话框

IMPLEMENT_DYNAMIC(CReadMe, CDialogEx)

CReadMe::CReadMe(CWnd* pParent /*=NULL*/)
	: CDialogEx(CReadMe::IDD, pParent)
{

}

CReadMe::~CReadMe()
{
}

void CReadMe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CReadMe, CDialogEx)
END_MESSAGE_MAP()


// CReadMe 消息处理程序
