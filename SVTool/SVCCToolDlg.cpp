// SVCCToolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SVTool.h"
#include "SVCCToolDlg.h"
#include "afxdialogex.h"
#include "ReadMe.h"


// CSVCCToolDlg �Ի���

IMPLEMENT_DYNAMIC(CSVCCToolDlg, CDialogEx)

CSVCCToolDlg::CSVCCToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSVCCToolDlg::IDD, pParent)
{

}

CSVCCToolDlg::~CSVCCToolDlg()
{
}

void CSVCCToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSVCCToolDlg, CDialogEx)
	ON_BN_CLICKED(IDC_PATH_BUTTON, &CSVCCToolDlg::OnBnClickedPathButton)
	ON_BN_CLICKED(IDOK, &CSVCCToolDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSVCCToolDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_README_BUTTON, &CSVCCToolDlg::OnBnClickedReadmeButton)
END_MESSAGE_MAP()


// CSVCCToolDlg ��Ϣ�������


void CSVCCToolDlg::OnBnClickedPathButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR   szPath[_MAX_PATH];  
	BROWSEINFO   bi;  
	//   ָ�������ڣ��ڶԻ�����ʾ�ڼ䣬�����ڽ�������  
	bi.hwndOwner   =   NULL;  
	//   ���ָ��NULL�����ԡ����桱Ϊ��  
	bi.pidlRoot   =   NULL;  
	//   ��һ�н���ʾ�ڶԻ���Ķ���  
	bi.lpszTitle   =     _T("ѡ��Ҫ�������ļ���");  
	bi.pszDisplayName   =   szPath;  
	//   ֻ�����ļ�ϵͳ�д��ڵ��ļ���  
	bi.ulFlags   =   BIF_RETURNONLYFSDIRS;  
	bi.lpfn   =   NULL;   //   �ص�������ָ��  
	bi.lParam   =   NULL;   //   ����ص������Ĳ��� 

	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		if(SHGetPathFromIDList(pItemIDList, szPath))
		{
			sourcepath = szPath;
		}
	}
	SetDlgItemText(IDC_SOURCE_PATH_EDIT, sourcepath);
}


void CSVCCToolDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	GetDlgItemText(IDC_SOURCE_PATH_EDIT,sourcepath);
	TCHAR SysTmpPath[MAX_PATH];
	GetTempPath(MAX_PATH,SysTmpPath);
	batchpath = SysTmpPath;
	batchpath+=_T("CCtool.bat");
	if(sourcepath == _T("D:\\CCData\\200MS")	)	//·����û������·��
	{
		switch (GetCheckedRadioButton(IDC_200MS_RADIO,IDC_4GB_RADIO))
		{
		case IDC_200MS_RADIO:
			{
				filestyle = _T("200MS ");
				sourcepath = _T("D:\\CCData\\200MS");
				SetDlgItemText(IDC_SOURCE_PATH_EDIT, sourcepath);
				if(IsDlgButtonChecked(IDC_CHECK1))
				{
					dirpath = _T(" C:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK2))
				{
					dirpath = _T(" D:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK3))
				{
					dirpath = _T(" E:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK4))
				{
					dirpath = _T(" F:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK5))
				{
					dirpath = _T(" G:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK6))
				{
					dirpath = _T(" H:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK7))
				{
					dirpath = _T(" I:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK8))
				{
					dirpath = _T(" J:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK9))
				{
					dirpath = _T(" K:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK10))
				{
					dirpath = _T(" L:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK11))
				{
					dirpath = _T(" M:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK12))
				{
					dirpath = _T(" N:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK13))
				{
					dirpath = _T(" O:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK14))
				{
					dirpath = _T(" P:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK15))
				{
					dirpath = _T(" Q:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK16))
				{
					dirpath = _T(" R:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK17))
				{
					dirpath = _T(" S:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK18))
				{
					dirpath = _T(" T:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK19))
				{
					dirpath = _T(" U:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK20))
				{
					dirpath = _T(" V:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK21))
				{
					dirpath = _T(" W:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK22))
				{
					dirpath = _T(" X:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK23))
				{
					dirpath = _T(" Y:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK24))
				{
					dirpath = _T(" Z:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if((IsDlgButtonChecked(IDC_CHECK24)|IsDlgButtonChecked(IDC_CHECK23)|IsDlgButtonChecked(IDC_CHECK22)|IsDlgButtonChecked(IDC_CHECK21)|IsDlgButtonChecked(IDC_CHECK20)|
					IsDlgButtonChecked(IDC_CHECK19)|IsDlgButtonChecked(IDC_CHECK18)|IsDlgButtonChecked(IDC_CHECK17)|IsDlgButtonChecked(IDC_CHECK16)|IsDlgButtonChecked(IDC_CHECK15)|
					IsDlgButtonChecked(IDC_CHECK14)|IsDlgButtonChecked(IDC_CHECK13)|IsDlgButtonChecked(IDC_CHECK12)|IsDlgButtonChecked(IDC_CHECK11)|IsDlgButtonChecked(IDC_CHECK10)|
					IsDlgButtonChecked(IDC_CHECK9)|IsDlgButtonChecked(IDC_CHECK8)|IsDlgButtonChecked(IDC_CHECK7)|IsDlgButtonChecked(IDC_CHECK6)|IsDlgButtonChecked(IDC_CHECK5)|
					IsDlgButtonChecked(IDC_CHECK4)|IsDlgButtonChecked(IDC_CHECK3)|IsDlgButtonChecked(IDC_CHECK2)|IsDlgButtonChecked(IDC_CHECK1))==0)
				{
					AfxMessageBox(_T("û��ѡ����Ч���̷�"),MB_OKCANCEL| MB_ICONWARNING);
				}
				break;
			}

		case IDC_200MB_RADIO:
			{
				filestyle = _T("200MB ");
				sourcepath = _T("D:\\CCData\\200MB");
				SetDlgItemText(IDC_SOURCE_PATH_EDIT, sourcepath);
				if(IsDlgButtonChecked(IDC_CHECK1))
				{
					dirpath = _T(" C:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK2))
				{
					dirpath = _T(" D:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK3))
				{
					dirpath = _T(" E:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK4))
				{
					dirpath = _T(" F:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK5))
				{
					dirpath = _T(" G:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK6))
				{
					dirpath = _T(" H:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK7))
				{
					dirpath = _T(" I:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK8))
				{
					dirpath = _T(" J:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK9))
				{
					dirpath = _T(" K:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK10))
				{
					dirpath = _T(" L:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK11))
				{
					dirpath = _T(" M:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK12))
				{
					dirpath = _T(" N:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK13))
				{
					dirpath = _T(" O:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK14))
				{
					dirpath = _T(" P:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK15))
				{
					dirpath = _T(" Q:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK16))
				{
					dirpath = _T(" R:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK17))
				{
					dirpath = _T(" S:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK18))
				{
					dirpath = _T(" T:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK19))
				{
					dirpath = _T(" U:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK20))
				{
					dirpath = _T(" V:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK21))
				{
					dirpath = _T(" W:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK22))
				{
					dirpath = _T(" X:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK23))
				{
					dirpath = _T(" Y:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK24))
				{
					dirpath = _T(" Z:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if((IsDlgButtonChecked(IDC_CHECK24)|IsDlgButtonChecked(IDC_CHECK23)|IsDlgButtonChecked(IDC_CHECK22)|IsDlgButtonChecked(IDC_CHECK21)|IsDlgButtonChecked(IDC_CHECK20)|
					IsDlgButtonChecked(IDC_CHECK19)|IsDlgButtonChecked(IDC_CHECK18)|IsDlgButtonChecked(IDC_CHECK17)|IsDlgButtonChecked(IDC_CHECK16)|IsDlgButtonChecked(IDC_CHECK15)|
					IsDlgButtonChecked(IDC_CHECK14)|IsDlgButtonChecked(IDC_CHECK13)|IsDlgButtonChecked(IDC_CHECK12)|IsDlgButtonChecked(IDC_CHECK11)|IsDlgButtonChecked(IDC_CHECK10)|
					IsDlgButtonChecked(IDC_CHECK9)|IsDlgButtonChecked(IDC_CHECK8)|IsDlgButtonChecked(IDC_CHECK7)|IsDlgButtonChecked(IDC_CHECK6)|IsDlgButtonChecked(IDC_CHECK5)|
					IsDlgButtonChecked(IDC_CHECK4)|IsDlgButtonChecked(IDC_CHECK3)|IsDlgButtonChecked(IDC_CHECK2)|IsDlgButtonChecked(IDC_CHECK1))==0)
				{
					MessageBox(_T("û��ѡ����Ч���̷�"),_T("warning"),MB_OKCANCEL| MB_ICONWARNING);
				}
				break;
			}

		case IDC_1GS_RADIO:
			{
				filestyle = _T("1GS ");
				sourcepath = _T("D:\\CCData\\1GS");
				SetDlgItemText(IDC_SOURCE_PATH_EDIT, sourcepath);
				if(IsDlgButtonChecked(IDC_CHECK1))
				{
					dirpath = _T(" C:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK2))
				{
					dirpath = _T(" D:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK3))
				{
					dirpath = _T(" E:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK4))
				{
					dirpath = _T(" F:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK5))
				{
					dirpath = _T(" G:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK6))
				{
					dirpath = _T(" H:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK7))
				{
					dirpath = _T(" I:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK8))
				{
					dirpath = _T(" J:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK9))
				{
					dirpath = _T(" K:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK10))
				{
					dirpath = _T(" L:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK11))
				{
					dirpath = _T(" M:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK12))
				{
					dirpath = _T(" N:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK13))
				{
					dirpath = _T(" O:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK14))
				{
					dirpath = _T(" P:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK15))
				{
					dirpath = _T(" Q:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK16))
				{
					dirpath = _T(" R:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK17))
				{
					dirpath = _T(" S:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK18))
				{
					dirpath = _T(" T:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK19))
				{
					dirpath = _T(" U:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK20))
				{
					dirpath = _T(" V:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK21))
				{
					dirpath = _T(" W:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK22))
				{
					dirpath = _T(" X:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK23))
				{
					dirpath = _T(" Y:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK24))
				{
					dirpath = _T(" Z:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if((IsDlgButtonChecked(IDC_CHECK24)|IsDlgButtonChecked(IDC_CHECK23)|IsDlgButtonChecked(IDC_CHECK22)|IsDlgButtonChecked(IDC_CHECK21)|IsDlgButtonChecked(IDC_CHECK20)|
					IsDlgButtonChecked(IDC_CHECK19)|IsDlgButtonChecked(IDC_CHECK18)|IsDlgButtonChecked(IDC_CHECK17)|IsDlgButtonChecked(IDC_CHECK16)|IsDlgButtonChecked(IDC_CHECK15)|
					IsDlgButtonChecked(IDC_CHECK14)|IsDlgButtonChecked(IDC_CHECK13)|IsDlgButtonChecked(IDC_CHECK12)|IsDlgButtonChecked(IDC_CHECK11)|IsDlgButtonChecked(IDC_CHECK10)|
					IsDlgButtonChecked(IDC_CHECK9)|IsDlgButtonChecked(IDC_CHECK8)|IsDlgButtonChecked(IDC_CHECK7)|IsDlgButtonChecked(IDC_CHECK6)|IsDlgButtonChecked(IDC_CHECK5)|
					IsDlgButtonChecked(IDC_CHECK4)|IsDlgButtonChecked(IDC_CHECK3)|IsDlgButtonChecked(IDC_CHECK2)|IsDlgButtonChecked(IDC_CHECK1))==0)
				{
					MessageBox(_T("û��ѡ����Ч���̷�"),_T("warning"),MB_OKCANCEL| MB_ICONWARNING);
				}
				break;
			}

		case IDC_1GB_RADIO:
			{
				filestyle = _T("1GB ");
				sourcepath = _T("D:\\CCData\\1GB");
				SetDlgItemText(IDC_SOURCE_PATH_EDIT, sourcepath);
				if(IsDlgButtonChecked(IDC_CHECK1))
				{
					dirpath = _T(" C:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK2))
				{
					dirpath = _T(" D:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK3))
				{
					dirpath = _T(" E:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK4))
				{
					dirpath = _T(" F:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK5))
				{
					dirpath = _T(" G:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK6))
				{
					dirpath = _T(" H:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK7))
				{
					dirpath = _T(" I:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK8))
				{
					dirpath = _T(" J:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK9))
				{
					dirpath = _T(" K:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK10))
				{
					dirpath = _T(" L:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK11))
				{
					dirpath = _T(" M:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK12))
				{
					dirpath = _T(" N:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK13))
				{
					dirpath = _T(" O:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK14))
				{
					dirpath = _T(" P:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK15))
				{
					dirpath = _T(" Q:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK16))
				{
					dirpath = _T(" R:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK17))
				{
					dirpath = _T(" S:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK18))
				{
					dirpath = _T(" T:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK19))
				{
					dirpath = _T(" U:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK20))
				{
					dirpath = _T(" V:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK21))
				{
					dirpath = _T(" W:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK22))
				{
					dirpath = _T(" X:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK23))
				{
					dirpath = _T(" Y:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK24))
				{
					dirpath = _T(" Z:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if((IsDlgButtonChecked(IDC_CHECK24)|IsDlgButtonChecked(IDC_CHECK23)|IsDlgButtonChecked(IDC_CHECK22)|IsDlgButtonChecked(IDC_CHECK21)|IsDlgButtonChecked(IDC_CHECK20)|
					IsDlgButtonChecked(IDC_CHECK19)|IsDlgButtonChecked(IDC_CHECK18)|IsDlgButtonChecked(IDC_CHECK17)|IsDlgButtonChecked(IDC_CHECK16)|IsDlgButtonChecked(IDC_CHECK15)|
					IsDlgButtonChecked(IDC_CHECK14)|IsDlgButtonChecked(IDC_CHECK13)|IsDlgButtonChecked(IDC_CHECK12)|IsDlgButtonChecked(IDC_CHECK11)|IsDlgButtonChecked(IDC_CHECK10)|
					IsDlgButtonChecked(IDC_CHECK9)|IsDlgButtonChecked(IDC_CHECK8)|IsDlgButtonChecked(IDC_CHECK7)|IsDlgButtonChecked(IDC_CHECK6)|IsDlgButtonChecked(IDC_CHECK5)|
					IsDlgButtonChecked(IDC_CHECK4)|IsDlgButtonChecked(IDC_CHECK3)|IsDlgButtonChecked(IDC_CHECK2)|IsDlgButtonChecked(IDC_CHECK1))==0)
				{
					MessageBox(_T("û��ѡ����Ч���̷�"),_T("warning"),MB_OKCANCEL| MB_ICONWARNING);
				}
				break;
			}

		case IDC_4GB_RADIO:
			{
				filestyle = _T("4GB ");
				sourcepath = _T("D:\\CCData\\4GB");
				SetDlgItemText(IDC_SOURCE_PATH_EDIT, sourcepath);
				if(IsDlgButtonChecked(IDC_CHECK1))
				{
					dirpath = _T(" C:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK2))
				{
					dirpath = _T(" D:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK3))
				{
					dirpath = _T(" E:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK4))
				{
					dirpath = _T(" F:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK5))
				{
					dirpath = _T(" G:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK6))
				{
					dirpath = _T(" H:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK7))
				{
					dirpath = _T(" I:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK8))
				{
					dirpath = _T(" J:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK9))
				{
					dirpath = _T(" K:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK10))
				{
					dirpath = _T(" L:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK11))
				{
					dirpath = _T(" M:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK12))
				{
					dirpath = _T(" N:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK13))
				{
					dirpath = _T(" O:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK14))
				{
					dirpath = _T(" P:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK15))
				{
					dirpath = _T(" Q:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK16))
				{
					dirpath = _T(" R:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK17))
				{
					dirpath = _T(" S:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK18))
				{
					dirpath = _T(" T:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK19))
				{
					dirpath = _T(" U:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK20))
				{
					dirpath = _T(" V:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK21))
				{
					dirpath = _T(" W:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK22))
				{
					dirpath = _T(" X:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK23))
				{
					dirpath = _T(" Y:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if(IsDlgButtonChecked(IDC_CHECK24))
				{
					dirpath = _T(" Z:\\CCData");
					CString para = filestyle + sourcepath + dirpath;
					ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
				}
				if((IsDlgButtonChecked(IDC_CHECK24)|IsDlgButtonChecked(IDC_CHECK23)|IsDlgButtonChecked(IDC_CHECK22)|IsDlgButtonChecked(IDC_CHECK21)|IsDlgButtonChecked(IDC_CHECK20)|
					IsDlgButtonChecked(IDC_CHECK19)|IsDlgButtonChecked(IDC_CHECK18)|IsDlgButtonChecked(IDC_CHECK17)|IsDlgButtonChecked(IDC_CHECK16)|IsDlgButtonChecked(IDC_CHECK15)|
					IsDlgButtonChecked(IDC_CHECK14)|IsDlgButtonChecked(IDC_CHECK13)|IsDlgButtonChecked(IDC_CHECK12)|IsDlgButtonChecked(IDC_CHECK11)|IsDlgButtonChecked(IDC_CHECK10)|
					IsDlgButtonChecked(IDC_CHECK9)|IsDlgButtonChecked(IDC_CHECK8)|IsDlgButtonChecked(IDC_CHECK7)|IsDlgButtonChecked(IDC_CHECK6)|IsDlgButtonChecked(IDC_CHECK5)|
					IsDlgButtonChecked(IDC_CHECK4)|IsDlgButtonChecked(IDC_CHECK3)|IsDlgButtonChecked(IDC_CHECK2)|IsDlgButtonChecked(IDC_CHECK1))==0)
				{
					MessageBox(_T("û��ѡ����Ч���̷�"),_T("warning"),MB_OKCANCEL| MB_ICONWARNING);
				}
				break;
			}
		}
	}

	else				//�û�ѡ��·��
	{
		filestyle = _T("UserSelect ");
		if(IsDlgButtonChecked(IDC_CHECK1))
		{
			dirpath = _T(" C:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK2))
		{
			dirpath = _T(" D:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK3))
		{
			dirpath = _T(" E:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK4))
		{
			dirpath = _T(" F:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK5))
		{
			dirpath = _T(" G:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK6))
		{
			dirpath = _T(" H:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK7))
		{
			dirpath = _T(" I:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK8))
		{
			dirpath = _T(" J:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK9))
		{
			dirpath = _T(" K:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK10))
		{
			dirpath = _T(" L:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK11))
		{
			dirpath = _T(" M:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK12))
		{
			dirpath = _T(" N:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK13))
		{
			dirpath = _T(" O:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK14))
		{
			dirpath = _T(" P:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK15))
		{
			dirpath = _T(" Q:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK16))
		{
			dirpath = _T(" R:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK17))
		{
			dirpath = _T(" S:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK18))
		{
			dirpath = _T(" T:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK19))
		{
			dirpath = _T(" U:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK20))
		{
			dirpath = _T(" V:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK21))
		{
			dirpath = _T(" W:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK22))
		{
			dirpath = _T(" X:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK23))
		{
			dirpath = _T(" Y:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if(IsDlgButtonChecked(IDC_CHECK24))
		{
			dirpath = _T(" Z:\\CCData");
			CString para = filestyle + sourcepath + dirpath;
			ShellExecuteW(NULL, _T("open"), batchpath, para, NULL, SW_SHOW);
		}
		if((IsDlgButtonChecked(IDC_CHECK24)|IsDlgButtonChecked(IDC_CHECK23)|IsDlgButtonChecked(IDC_CHECK22)|IsDlgButtonChecked(IDC_CHECK21)|IsDlgButtonChecked(IDC_CHECK20)|
			IsDlgButtonChecked(IDC_CHECK19)|IsDlgButtonChecked(IDC_CHECK18)|IsDlgButtonChecked(IDC_CHECK17)|IsDlgButtonChecked(IDC_CHECK16)|IsDlgButtonChecked(IDC_CHECK15)|
			IsDlgButtonChecked(IDC_CHECK14)|IsDlgButtonChecked(IDC_CHECK13)|IsDlgButtonChecked(IDC_CHECK12)|IsDlgButtonChecked(IDC_CHECK11)|IsDlgButtonChecked(IDC_CHECK10)|
			IsDlgButtonChecked(IDC_CHECK9)|IsDlgButtonChecked(IDC_CHECK8)|IsDlgButtonChecked(IDC_CHECK7)|IsDlgButtonChecked(IDC_CHECK6)|IsDlgButtonChecked(IDC_CHECK5)|
			IsDlgButtonChecked(IDC_CHECK4)|IsDlgButtonChecked(IDC_CHECK3)|IsDlgButtonChecked(IDC_CHECK2)|IsDlgButtonChecked(IDC_CHECK1))==0)
		{
			AfxMessageBox(_T("û��ѡ����Ч���̷�"),MB_OKCANCEL| MB_ICONWARNING);
		}
	}
}


void CSVCCToolDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filename;
	TCHAR SysTmpPath[MAX_PATH];
	GetTempPath(MAX_PATH,SysTmpPath);
	filename = SysTmpPath;
	filename+=_T("CCtool.bat");

	CFileFind finder;
	BOOL iffind = finder.FindFile(filename);
	if(iffind)
	{
		CFile CCbat;
		CCbat.Remove(filename);
	}

	GetTempPath(MAX_PATH,SysTmpPath);
	filename = SysTmpPath;
	filename+=_T("count.bat");
	iffind = finder.FindFile(filename);
	if(iffind)
	{
		CFile CCcount;
		CCcount.Remove(filename);
	}
	return;
	//CDialogEx::OnCancel();
}


void CSVCCToolDlg::OnBnClickedReadmeButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;

	CReadMe readme;
	nRes = readme.DoModal();

	if(nRes == IDCANCEL)
		return;
}
