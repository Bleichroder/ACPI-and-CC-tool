// SVACPIDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SVTool.h"
#include "SVACPIDlg.h"
#include "afxdialogex.h"
#include <atlbase.h>  
#include <afxpriv.h>  
#include <WbemIdl.h>
#include <string.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"WbemUuid.lib")


// CSVACPIDlg 对话框

IMPLEMENT_DYNAMIC(CSVACPIDlg, CDialogEx)

CSVACPIDlg::CSVACPIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSVACPIDlg::IDD, pParent)
{
	
}

CSVACPIDlg::~CSVACPIDlg()
{
}

void CSVACPIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSVACPIDlg, CDialogEx)
	ON_EN_CHANGE(IDC_State, &CSVACPIDlg::OnEnChangeState)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_S3BUTTON, &CSVACPIDlg::OnBnClickedS3button)
	ON_BN_CLICKED(IDC_S4BUTTON, &CSVACPIDlg::OnBnClickedS4button)
	ON_BN_CLICKED(IDC_S5BUTTON, &CSVACPIDlg::OnBnClickedS5button)
	ON_BN_CLICKED(IDC_RbBUTTON, &CSVACPIDlg::OnBnClickedRbbutton)
	ON_BN_CLICKED(IDC_PBUTTON, &CSVACPIDlg::OnBnClickedPbutton)
	ON_BN_CLICKED(IDC_ClsBUTTON, &CSVACPIDlg::OnBnClickedClsbutton)
END_MESSAGE_MAP()


// CSVACPIDlg 消息处理程序


void CSVACPIDlg::OnEnChangeState()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//按下S3 button
void CSVACPIDlg::OnBnClickedS3button()
{
	// TODO: 在此添加控件通知处理程序代码
	CString BN_S3disp;
	int waketime;
	GetDlgItemText(IDC_S3BUTTON,BN_S3disp);
	if(BN_S3disp == _T("Run S1/S3"))
	{
		SetDlgItemText(IDC_S3BUTTON,_T("Stop S1/S3"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S4BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S5BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_RbBUTTON)->EnableWindow(FALSE);

		CString cdtime,temp;
		GetDlgItemText(IDC_Countdown,cdtime);
		int value = _ttoi(cdtime);
		if(value<5||value>100) 
		{
			AfxMessageBox(_T(" warning! count down TIME is invalid!"));
			SetDlgItemText(IDC_S4BUTTON,_T("Run S1/S3"));
			GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);
			return;
		}
		SetDlgItemText(IDC_time_to_run,cdtime);

		GetDlgItemText(IDC_Loop,temp);
		value = _ttoi(temp);
		if(value<1||value>9999)  
		{
			AfxMessageBox(_T(" warning! LOOP set is invalid!"));
			SetDlgItemText(IDC_S4BUTTON,_T("Run S1/S3"));
			GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);
			return;
		}
		SetDlgItemText(IDC_Loop_time,_T("0"));

		CString powerset_path;
		TCHAR SysTmpPath[MAX_PATH];
		GetTempPath(MAX_PATH,SysTmpPath);
		powerset_path = SysTmpPath;powerset_path+=_T("setpower.bat");
		CFile pwsetbat(powerset_path,CFile::modeCreate | CFile::modeReadWrite);
		char pwrcfg[1024] = "@echo off\r\npowercfg -setacvalueindex 381b4222-f694-41f0-9685-ff5bb260df2e fea3413e-7e05-4911-9a71-700331f1c294 0e796bdb-100d-47d6-a2d5-f7d2daa51f51 000\r\n\
powercfg -setdcvalueindex 381b4222-f694-41f0-9685-ff5bb260df2e 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setacvalueindex 381b4222-f694-41f0-9685-ff5bb260df2e 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setdcvalueindex 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setacvalueindex 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setacvalueindex a1841308-3541-4fab-bc81-f71556f20b4a 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setdcvalueindex a1841308-3541-4fab-bc81-f71556f20b4a 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
";
		pwsetbat.Write(pwrcfg, sizeof(pwrcfg)-1);
		pwsetbat.Flush();
		pwsetbat.Close();
		ShellExecute(NULL,_T("open"),powerset_path,NULL,NULL,SW_SHOWNORMAL);

		int i = rootpath.ReverseFind('\\');
		logpath = rootpath.Left(i+1)+_T("Suspend.LOG");
		if(PathFileExists(logpath))
			DeleteFile(logpath);
		errorpath = rootpath.Left(i+1)+_T("ERROR_Suspend.LOG");
		if(PathFileExists(errorpath))
			DeleteFile(errorpath);
		CStdioFile log;
		log.Open(logpath, CFile::modeCreate|CFile::modeReadWrite);
		info = hardwareinfo();
		log.WriteString(info+_T("\r\n"));
		log.Flush();
		log.Close();

		SetDlgItemText(IDC_HWINFO,info);

		HANDLE hTimer;
		LARGE_INTEGER liDueTime;
		liDueTime.QuadPart = -1000000000;

		hTimer = CreateWaitableTimer(NULL,FALSE,_T("SVacpiTimer"));
		if(hTimer == NULL)
		{
			AfxMessageBox(_T("CreateWaitableTimer failed"));
			return;
		}

		waketime = 50;
		if (!SetWaitableTimer(hTimer, &liDueTime,waketime*1000, NULL, NULL, TRUE))
		{
			AfxMessageBox(_T("SetWaitableTimer failed (%d)\n"), GetLastError());
			return;
		}
		else
		{
			CString CurrTime;
			SYSTEMTIME st;GetLocalTime(&st);
			CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
			state = _T("-----------Suspend Test------------\r\nLoop 1 Start at : ");
			state += CurrTime;
			SetDlgItemText(IDC_State,state);
			SetTimer(20,1000,NULL);

		}

	}

	else
	{
		KillTimer(20);
		CString powerset_path;
		TCHAR SysTmpPath[MAX_PATH];
		GetTempPath(MAX_PATH,SysTmpPath);
		powerset_path = SysTmpPath;powerset_path+=_T("setpower.bat");

		CFileFind finder;
		BOOL isfind = finder.FindFile(powerset_path);
		if(isfind)
			DeleteFile(powerset_path);

		SetDlgItemText(IDC_S3BUTTON,_T("Run S1/S3"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);
	}
}

//按下S4 button
void CSVACPIDlg::OnBnClickedS4button()
{
	// TODO: 在此添加控件通知处理程序代码
	CString BN_S4disp;
	int waketime;
	GetDlgItemText(IDC_S4BUTTON,BN_S4disp);
	if(BN_S4disp == _T("Run S4"))
	{
		SetDlgItemText(IDC_S4BUTTON,_T("Stop S4"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S3BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S5BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_RbBUTTON)->EnableWindow(FALSE);

		CString cdtime,temp;
		GetDlgItemText(IDC_Countdown,cdtime);
		int value = _ttoi(cdtime);
		if(value<5||value>100) 
		{
			AfxMessageBox(_T(" warning! count down TIME is invalid!"));
			SetDlgItemText(IDC_S4BUTTON,_T("Run S4"));
			GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);
			return;
		}
		SetDlgItemText(IDC_time_to_run,cdtime);

		GetDlgItemText(IDC_Loop,temp);
		value = _ttoi(temp);
		if(value<1||value>9999)  
		{
			AfxMessageBox(_T(" warning! LOOP set is invalid!"));
			SetDlgItemText(IDC_S4BUTTON,_T("Run S4"));
			GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
			GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
			GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);
			return;
		}
		SetDlgItemText(IDC_Loop_time,_T("0"));

		CString powerset_path;
		TCHAR SysTmpPath[MAX_PATH];
		GetTempPath(MAX_PATH,SysTmpPath);
		powerset_path = SysTmpPath;powerset_path+=_T("setpower.bat");
		CFile pwsetbat(powerset_path,CFile::modeCreate | CFile::modeReadWrite);
		char pwrcfg[1024] = "@echo off\r\npowercfg -setacvalueindex 381b4222-f694-41f0-9685-ff5bb260df2e fea3413e-7e05-4911-9a71-700331f1c294 0e796bdb-100d-47d6-a2d5-f7d2daa51f51 000\r\n\
powercfg -setdcvalueindex 381b4222-f694-41f0-9685-ff5bb260df2e 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setacvalueindex 381b4222-f694-41f0-9685-ff5bb260df2e 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setdcvalueindex 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setacvalueindex 8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setacvalueindex a1841308-3541-4fab-bc81-f71556f20b4a 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
powercfg -setdcvalueindex a1841308-3541-4fab-bc81-f71556f20b4a 238c9fa8-0aad-41ed-83f4-97be242c8f20 bd3b718a-0680-4d9d-8ab2-e1d2b4ac806d 001\r\n\
";
		pwsetbat.Write(pwrcfg, sizeof(pwrcfg)-1);
		pwsetbat.Flush();
		pwsetbat.Close();
		ShellExecute(NULL,_T("open"),powerset_path,NULL,NULL,SW_SHOWNORMAL);

		int i = rootpath.ReverseFind('\\');
		logpath = rootpath.Left(i+1)+_T("Hibernate.LOG");
		if(PathFileExists(logpath))
			DeleteFile(logpath);
		errorpath = rootpath.Left(i+1)+_T("ERROR_Hibernate.LOG");
		if(PathFileExists(errorpath))
			DeleteFile(errorpath);
		CStdioFile log;
		log.Open(logpath, CFile::modeCreate|CFile::modeReadWrite);
		info = hardwareinfo();
		log.WriteString(info+_T("\r\n"));
		log.Flush();
		log.Close();

		SetDlgItemText(IDC_HWINFO,info);

		HANDLE hTimer;
		LARGE_INTEGER liDueTime;
		liDueTime.QuadPart = -1000000000;

		hTimer = CreateWaitableTimer(NULL,FALSE,_T("SVacpiTimer"));
		if(hTimer == NULL)
		{
			AfxMessageBox(_T("CreateWaitableTimer failed"));
			return;
		}

		waketime = 50;
		if (!SetWaitableTimer(hTimer, &liDueTime,waketime*1000, NULL, NULL, TRUE))
		{
			AfxMessageBox(_T("SetWaitableTimer failed (%d)\n"), GetLastError());
			return;
		}
		else
		{
			CString CurrTime;
			SYSTEMTIME st;GetLocalTime(&st);
			CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
			state = _T("-----------Hibernate Test------------\r\nLoop 1 Start at : ");
			state += CurrTime;
			SetDlgItemText(IDC_State,state);
			SetTimer(20,1000,NULL);

		}

	}

	else
	{
		KillTimer(20);
		CString powerset_path;
		TCHAR SysTmpPath[MAX_PATH];
		GetTempPath(MAX_PATH,SysTmpPath);
		powerset_path = SysTmpPath;powerset_path+=_T("setpower.bat");

		CFileFind finder;
		BOOL isfind = finder.FindFile(powerset_path);
		if(isfind)
			DeleteFile(powerset_path);

		SetDlgItemText(IDC_S4BUTTON,_T("Run S4"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);
	}
}

//按下S5 button
void CSVACPIDlg::OnBnClickedS5button()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegKey hKey;
	DWORD dwReturn = 0;

	CString BN_S5disp;
	GetDlgItemText(IDC_S5BUTTON,BN_S5disp);
	if(BN_S5disp == _T("Run S5"))
	{
		//新建项
		hKey.Create(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information"));
		CString HWinfo = hardwareinfo();
		CString temp = _T("0");
		CString rbFullAppPath =_T("\"");
		SetDlgItemText(IDC_HWINFO,HWinfo);
		SetDlgItemText(IDC_Loop_time,_T("0"));

		//日志文件
		int i = rootpath.ReverseFind('\\');
		logpath = rootpath.Left(i+1)+_T("RTC.LOG");
		if(PathFileExists(logpath))
			DeleteFile(logpath);
		errorpath = rootpath.Left(i+1)+_T("ERROR_RTC.LOG");
		if(PathFileExists(errorpath))
			DeleteFile(errorpath);
		CStdioFile log;
		log.Open(logpath, CFile::modeCreate|CFile::modeReadWrite);
		log.WriteString(HWinfo+_T("\r\n"));
		log.Flush();
		log.Close();

		//把设置添加到新建的项中
		if(hKey.Open(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information")) == ERROR_SUCCESS)
		{
			hKey.SetValue(temp,_T("LastLoop"));
			temp = _T("S5");
			ACPIs = temp;
			hKey.SetValue(temp,_T("CurrState"));
			temp = _T("1");
			hKey.SetValue(HWinfo,_T("OrigHWInfo"));
		}

		GetDlgItemText(IDC_Countdown,temp);
		hKey.SetValue(logpath,_T("LogPath"));
		hKey.SetValue(errorpath,_T("ErrorPath"));
		int value = _ttoi(temp);
		if(value<5||value>100) {AfxMessageBox(_T(" warning! count down TIME is invalid!"));return;}
		SetDlgItemText(IDC_time_to_run,temp);
		hKey.SetValue(temp,_T("SetTime"));

		GetDlgItemText(IDC_Loop,temp);
		value = _ttoi(temp);
		if(value<1||value>9999)  {AfxMessageBox(_T(" warning! LOOP set is invalid!"));return;}
		hKey.SetValue(temp,_T("SetLoop"));

		hKey.Close();

		//添加开机启动项
		TCHAR rbPath[MAX_PATH];
		GetModuleFileName(NULL,rbPath,MAX_PATH);
		rootpath = rbPath;
		rbFullAppPath = rbFullAppPath + rootpath +rbFullAppPath;
		if(hKey.Open(HKEY_CURRENT_USER,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run")) != ERROR_SUCCESS)
			AfxMessageBox(_T("error open auto_run reg key!!!"));
		else
			hKey.SetValue(rbFullAppPath,_T("SVRtc"));

		hKey.Close();

		//系统时间
		SYSTEMTIME st;
		GetLocalTime(&st);
		temp.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
		state = _T("-----------RTC Test------------\r\nLoop 1 Start at : ");
		state += temp;
		SetDlgItemText(IDC_State,state);

		SetDlgItemText(IDC_S5BUTTON,_T("Stop S5"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S3BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S4BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_RbBUTTON)->EnableWindow(FALSE);


		SetTimer(21,1000,NULL);
	}

	else
	{
		KillTimer(21);
		HKEY hKey;
		SetDlgItemText(IDC_S5BUTTON,_T("Run S5"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);

		SHDeleteKey(HKEY_CURRENT_USER,_T("Software\\SVACPI"));
		if(RegOpenKeyEx(HKEY_CURRENT_USER,
					_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),
					0,
					KEY_WRITE,
					&hKey)==ERROR_SUCCESS)
		RegDeleteValue(hKey,_T("SVRtc"));
		RegCloseKey(hKey);
	}
}

//按下Reboot button
void CSVACPIDlg::OnBnClickedRbbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegKey hKey;
	DWORD dwReturn = 0;

	CString BN_Rbdisp;
	GetDlgItemText(IDC_RbBUTTON,BN_Rbdisp);
	if(BN_Rbdisp == _T("Reboot"))
	{
		//新建项
		hKey.Create(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information"));
		CString HWinfo = hardwareinfo();
		CString temp = _T("0");
		CString rbFullAppPath =_T("\"");
		SetDlgItemText(IDC_HWINFO,HWinfo);
		SetDlgItemText(IDC_Loop_time,_T("0"));

		//日志文件
		int i = rootpath.ReverseFind('\\');
		logpath = rootpath.Left(i+1)+_T("Reboot.LOG");
		if(PathFileExists(logpath))
			DeleteFile(logpath);
		errorpath = rootpath.Left(i+1)+_T("ERROR_Reboot.LOG");
		if(PathFileExists(errorpath))
			DeleteFile(errorpath);
		CStdioFile log;
		log.Open(logpath, CFile::modeCreate|CFile::modeReadWrite);
		log.WriteString(HWinfo+_T("\r\n"));
		log.Flush();
		log.Close();

		//把设置添加到新建的项中
		if(hKey.Open(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information")) == ERROR_SUCCESS)
		{
			hKey.SetValue(HWinfo,_T("OrigHWInfo"));
			hKey.SetValue(logpath,_T("LogPath"));
			hKey.SetValue(temp,_T("LastLoop"));
			hKey.SetValue(errorpath,_T("ErrorPath"));
			temp = _T("Reboot");
			ACPIs = temp;
			hKey.SetValue(temp,_T("CurrState"));
			temp = _T("1");
		}

		GetDlgItemText(IDC_Countdown,temp);
		int value = _ttoi(temp);
		if(value<5||value>100) {AfxMessageBox(_T(" warning! count down TIME is invalid!"));return;}
		SetDlgItemText(IDC_time_to_run,temp);
		hKey.SetValue(temp,_T("SetTime"));

		GetDlgItemText(IDC_Loop,temp);
		value = _ttoi(temp);
		if(value<1||value>9999)  {AfxMessageBox(_T(" warning! LOOP set is invalid!"));return;}
		hKey.SetValue(temp,_T("SetLoop"));

		hKey.Close();

		//添加开机启动项
		rbFullAppPath = rbFullAppPath + rootpath +rbFullAppPath;
		if(hKey.Open(HKEY_CURRENT_USER,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run")) != ERROR_SUCCESS)
			AfxMessageBox(_T("error open auto_run reg key!!!"));
		else
			hKey.SetValue(rbFullAppPath,_T("SVReboot"));

		hKey.Close();

		//系统时间
		SYSTEMTIME st;
		GetLocalTime(&st);
		temp.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
		state = _T("-----------Reboot Test------------\r\nLoop 1 Start at : ");
		state += temp;
		SetDlgItemText(IDC_State,state);

		SetDlgItemText(IDC_RbBUTTON,_T("Stop Reboot"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S3BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S4BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S5BUTTON)->EnableWindow(FALSE);


		SetTimer(21,1000,NULL);
	}

	else
	{
		KillTimer(21);
		HKEY hKey;
		SetDlgItemText(IDC_RbBUTTON,_T("Reboot"));
		GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);

		SHDeleteKey(HKEY_CURRENT_USER,_T("Software\\SVACPI"));
		if(RegOpenKeyEx(HKEY_CURRENT_USER,
					_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),
					0,
					KEY_WRITE,
					&hKey)==ERROR_SUCCESS)
		RegDeleteValue(hKey,_T("SVReboot"));
		RegCloseKey(hKey);
	}
}


//定时器实现S3、S4、S5和reboot
void CSVACPIDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch(nIDEvent)
	{
	case 20:
		{
			CString looptemp;
			GetDlgItemText(IDC_Loop_time, looptemp);
			int looptime = _ttoi(looptemp);
			GetDlgItemText(IDC_Loop, looptemp);
			int setloop = _ttoi(looptemp);

			//到达已设定圈数
			if(looptime==setloop)
			{
				KillTimer(20);

				CString CurrTime;
				SYSTEMTIME st;GetLocalTime(&st);
				CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
				state = state+ _T("\r\nFinished at : ") + CurrTime;
				SetDlgItemText(IDC_State, state);

				CString logstate;
				logstate = _T("Finished at : ") + CurrTime;
				CStdioFile log;
				log.Open(logpath, CFile::modeReadWrite);
				log.SeekToEnd();
				CString HWInfo;
				HWInfo = hardwareinfo();
				log.WriteString(_T("\r\n")+HWInfo);
				log.WriteString(logstate);

				CString cosCurr,cost;
				cosCurr.Format(_T("%d:%d"),st.wMinute,st.wSecond);
				int nPos =lasttime.Find(_T(":"));
				int costTime = GetCostTime(cosCurr,lasttime);
				cost.Format(_T("%d"),costTime);
				cost = _T("\r\ncost  ") + cost +_T("s\r\n");
				log.WriteString(cost);

				log.Flush();
				log.Close();
				SetDlgItemText(IDC_HWINFO, HWInfo);
				if(CheckDiffInfo(ACPIs, info, HWInfo))
					GetDlgItem(IDC_STATIC_Error)->EnableWindow(TRUE);

				CString powerset_path;
				TCHAR SysTmpPath[MAX_PATH];
				GetTempPath(MAX_PATH,SysTmpPath);
				powerset_path = SysTmpPath;powerset_path+=_T("setpower.bat");

				CFileFind finder;
				BOOL isfind = finder.FindFile(powerset_path);
				if(isfind)
					DeleteFile(powerset_path);

				GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
				GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
				GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);

				if(GetDlgItem(IDC_S3BUTTON)->IsWindowEnabled()) 
				{
					SetDlgItemText(IDC_S3BUTTON,_T("Run S1/S3"));
					GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
				}
				if(GetDlgItem(IDC_S4BUTTON)->IsWindowEnabled()) 
				{
					SetDlgItemText(IDC_S4BUTTON,_T("Run S4"));
					GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
				}
				return;
			}

			CString CountTime;
			GetDlgItemText(IDC_time_to_run,CountTime);
			int curr = _ttoi(CountTime);curr--;
			CountTime.Format(_T("%d"),curr);
			SetDlgItemText(IDC_time_to_run,CountTime);
			CString cdtime;
			GetDlgItemText(IDC_Countdown,cdtime);
			int countd = _ttoi(cdtime);

			//显示完成时间
			if(curr == (countd-1))
			{
				if(looptime>0)
				{
					CString CurrTime;
					SYSTEMTIME st;GetLocalTime(&st);
					CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
					state = state+ _T("\r\nFinished at : ") + CurrTime;
					SetDlgItemText(IDC_State, state);

					CString logstate;
					logstate = _T("Finished at : ") + CurrTime;
					CStdioFile log;
					log.Open(logpath, CFile::modeReadWrite);
					log.SeekToEnd();
					CString HWInfo;
					HWInfo = hardwareinfo();
					log.WriteString(_T("\r\n")+HWInfo);
					log.WriteString(logstate);

					CString cosCurr,cost;
					cosCurr.Format(_T("%d:%d"),st.wMinute,st.wSecond);
					int nPos =lasttime.Find(_T(":"));
					int costTime = GetCostTime(cosCurr,lasttime);
					cost.Format(_T("%d"),costTime);
					cost = _T("\r\ncost  ") + cost +_T("s\r\n");
					log.WriteString(cost);

					log.Flush();
					log.Close();

					SetDlgItemText(IDC_HWINFO, HWInfo);
					if(CheckDiffInfo(ACPIs, info, HWInfo))
						GetDlgItem(IDC_STATIC_Error)->EnableWindow(TRUE);
				}
			}

			//倒计时结束,开始S1/S3\S4
			if(curr == 0)
			{
				HANDLE hToken; 
				TOKEN_PRIVILEGES tkp; 

				CString temp;
				GetDlgItemText(IDC_Countdown, temp);
				SetDlgItemText(IDC_time_to_run, temp);

				GetDlgItemText(IDC_Loop_time, temp);
				int loop = _ttoi(temp);

				CString CurrTime;
				SYSTEMTIME st;GetLocalTime(&st);
				CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
				lasttime.Format(_T("%d:%d"),st.wMinute,st.wSecond);
				if(GetDlgItem(IDC_S3BUTTON)->IsWindowEnabled()) 
				{
					state.Format(_T("-----------Suspend Test------------\r\nLoop %d Start at : "),loop+1);
					ACPIs = _T("S3");
				}
				if(GetDlgItem(IDC_S4BUTTON)->IsWindowEnabled()) 
				{
					state.Format(_T("-----------Hibernate Test------------\r\nLoop %d Start at : "),loop+1);
					ACPIs = _T("S4");
				}
				state+=CurrTime;
				SetDlgItemText(IDC_State, state);

				CStdioFile log;
				log.Open(logpath, CFile::modeReadWrite);
				log.SeekToEnd();
				log.WriteString(state);
				log.Flush();
				log.Close();

				loop++;
				temp.Format(_T("%d"),loop);
				SetDlgItemText(IDC_Loop_time, temp);

				// Get a token for this process. 

				if (!OpenProcessToken(GetCurrentProcess(), 
					TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) 
				{AfxMessageBox(_T("OpenProcessToken fail(%d)\n"),GetLastError());return;}

				// Get the LUID for the Restart privilege. 

				LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
					&tkp.Privileges[0].Luid); 

				tkp.PrivilegeCount = 1;  // one privilege to set    
				tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 

				// Get the shutdown privilege for this process. 

				AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
					(PTOKEN_PRIVILEGES)NULL, 0); 
				if (GetLastError() != ERROR_SUCCESS) 
				{AfxMessageBox(_T("AdjustTokenPrivileges Fail"));return;}

				if(GetDlgItem(IDC_S3BUTTON)->IsWindowEnabled()) 
					//SetSuspendState(FALSE,TRUE,FALSE);	
					SetSystemPowerState(TRUE,FALSE);
				else if(GetDlgItem(IDC_S4BUTTON)->IsWindowEnabled()) 
					SetSystemPowerState(FALSE,TRUE);
			}
			break;
		}

	case 21:
		{
			CString looptemp;
			GetDlgItemText(IDC_Loop_time, looptemp);
			int looptime = _ttoi(looptemp);
			GetDlgItemText(IDC_Loop, looptemp);
			int setloop = _ttoi(looptemp);

			//到达已设定圈数
			if(looptime==setloop)
			{
				KillTimer(21);

				CString CurrTime;
				SYSTEMTIME st;GetLocalTime(&st);
				CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
				CRegKey Key;
				TCHAR TMP[1024];
				CString temp;
				DWORD dwcount = 1024;
				if(Key.Open(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information")) == ERROR_SUCCESS)
					Key.QueryValue(TMP,_T("State"),&dwcount);
				temp = TMP;
				state = temp+ _T("\r\nFinished at : ") + CurrTime;
				SetDlgItemText(IDC_State, state);
				
				Key.QueryValue(TMP,_T("LogPath"),&dwcount);
				logpath = TMP;
				Key.Close();

				CString logstate;
				logstate = _T("Finished at : ") + CurrTime;
				CStdioFile log;
				log.Open(logpath, CFile::modeReadWrite);
				log.SeekToEnd();
				CString HWInfo;
				HWInfo =hardwareinfo();
				log.WriteString(_T("\r\n")+HWInfo);
				log.WriteString(logstate);

				CString cosCurr,cost;
				cosCurr.Format(_T("%d:%d"),st.wMinute,st.wSecond);
				CRegKey cKey;
				if(cKey.Open(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information")) == ERROR_SUCCESS)
					cKey.QueryValue(TMP,_T("LastShutDownTime"),&dwcount);
				temp = TMP;
				int nPos =temp.Find(_T(":"));
				int costTime = GetCostTime(cosCurr,temp.Right(temp.GetLength()-nPos-1));
				cost.Format(_T("%d"),costTime);
				cost = _T("\r\ncost  ") + cost +_T("s\r\n");
				log.WriteString(cost);

				log.Flush();
				log.Close();
				cKey.Close();

				HKEY hKey;
				if(GetDlgItem(IDC_S5BUTTON)->IsWindowEnabled()) 
				{
					SetDlgItemText(IDC_S5BUTTON,_T("Run S5"));
				}
				if(GetDlgItem(IDC_RbBUTTON)->IsWindowEnabled()) 
				{
					SetDlgItemText(IDC_RbBUTTON,_T("Reboot"));
				}
				
				GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
				GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
				GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
				GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
				GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);

				SHDeleteKey(HKEY_CURRENT_USER,_T("Software\\SVACPI"));
				if(RegOpenKeyEx(HKEY_CURRENT_USER,
					_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),
					0,
					KEY_WRITE,
					&hKey)==ERROR_SUCCESS)
				{
					RegDeleteValue(hKey,_T("SVRtc"));
					RegDeleteValue(hKey,_T("SVReboot"));
				}
				RegCloseKey(hKey);

				return;
			}

			CString CountTime;
			GetDlgItemText(IDC_time_to_run,CountTime);
			int curr = _ttoi(CountTime);curr--;
			CountTime.Format(_T("%d"),curr);
			SetDlgItemText(IDC_time_to_run,CountTime);
			CString cdtime;
			GetDlgItemText(IDC_Countdown,cdtime);
			int countd = _ttoi(cdtime);

			//显示完成时间
			if(curr == (countd-1))
			{
				if(looptime>0)
				{
					CString CurrTime;
					SYSTEMTIME st;GetLocalTime(&st);
					CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
					CRegKey hKey;
					TCHAR TMP[1024];
					CString temp;
					DWORD dwcount = 1024;
					if(hKey.Open(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information")) == ERROR_SUCCESS)
						hKey.QueryValue(TMP,_T("State"),&dwcount);
					temp = TMP;
					state = temp+ _T("\r\nFinished at : ") + CurrTime;
					SetDlgItemText(IDC_State, state);
					hKey.QueryValue(TMP,_T("LogPath"),&dwcount);
					logpath = TMP;
					hKey.Close();

					CString logstate;
					logstate = _T("Finished at : ") + CurrTime;
					CStdioFile log;
					log.Open(logpath, CFile::modeReadWrite);
					log.SeekToEnd();
					CString HWInfo;
					HWInfo =hardwareinfo();
					log.WriteString(_T("\r\n")+HWInfo);
					log.WriteString(logstate);

					CString cosCurr,cost;
					cosCurr.Format(_T("%d:%d"),st.wMinute,st.wSecond);
					CRegKey cKey;
					if(cKey.Open(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information")) == ERROR_SUCCESS)
						cKey.QueryValue(TMP,_T("LastShutDownTime"),&dwcount);
					temp = TMP;
					int nPos =temp.Find(_T(":"));
					int costTime = GetCostTime(cosCurr,temp.Right(temp.GetLength()-nPos-1));
					cost.Format(_T("%d"),costTime);
					cost = _T("\r\ncost  ") + cost +_T("s\r\n");
					log.WriteString(cost);

					log.Flush();
					log.Close();
					cKey.Close();
				}
			}

			//倒计时结束,开始S5
			if(curr == 0)
			{
				HANDLE hToken; 
				TOKEN_PRIVILEGES tkp; 
				CRegKey hKey;

				CString temp;
				GetDlgItemText(IDC_Countdown, temp);
				SetDlgItemText(IDC_time_to_run, temp);

				GetDlgItemText(IDC_Loop_time, temp);
				int loop = _ttoi(temp);

				CString CurrTime;
				SYSTEMTIME st;GetLocalTime(&st);
				CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
				if(GetDlgItem(IDC_S5BUTTON)->IsWindowEnabled()) 
				{
					state.Format(_T("-----------RTC Test------------\r\nLoop %d Start at : "),loop+1);
				}
				if(GetDlgItem(IDC_RbBUTTON)->IsWindowEnabled()) 
				{
					state.Format(_T("-----------Reboot Test------------\r\nLoop %d Start at : "),loop+1);
				}
				state+=CurrTime;
				SetDlgItemText(IDC_State, state);
				loop++;

				CStdioFile log;
				log.Open(logpath, CFile::modeReadWrite);
				log.SeekToEnd();
				log.WriteString(state);
				log.Flush();
				log.Close();

				temp.Format(_T("%d"),loop);
				SetDlgItemText(IDC_Loop_time, temp);

				if(hKey.Open(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information")) == ERROR_SUCCESS)
				{
					hKey.SetValue(state,_T("State"));
					
					CString SetLoop;
					SetLoop.Format(_T("%d"),loop);
					hKey.SetValue(SetLoop,_T("LastLoop"));

					SYSTEMTIME st;
					GetLocalTime(&st);
					CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
					hKey.SetValue(CurrTime,_T("LastShutDownTime"));

					if(GetDlgItem(IDC_S5BUTTON)->IsWindowEnabled()) 
					{
						FILETIME ft;
						LARGE_INTEGER tmp;
						LONGLONG tmptime1=0,tmptime2=0;

						SystemTimeToFileTime(&st,&ft);
						tmp.LowPart = ft.dwLowDateTime;
						tmp.HighPart =ft.dwHighDateTime;
						tmptime1 = tmp.QuadPart;

						st.wHour = 0;st.wMinute =0;st.wSecond =0;st.wMilliseconds =0;

						SystemTimeToFileTime(&st,&ft);
						tmp.LowPart = ft.dwLowDateTime;
						tmp.HighPart =ft.dwHighDateTime;
						tmptime2 = tmp.QuadPart;

						tmptime1 =tmptime1-tmptime2;
						CurrTime.Format(_T("%lld"),tmptime1);
						hKey.SetValue(CurrTime,_T("RealTime"));

						SetLocalTime(&st);	
					}
				}
				hKey.Close();

				// Get a token for this process. 

				if (!OpenProcessToken(GetCurrentProcess(), 
					TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) 
				{AfxMessageBox(_T("OpenProcessToken fail(%d)\n"),GetLastError());return;}

				// Get the LUID for the Restart privilege. 

				LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
					&tkp.Privileges[0].Luid); 

				tkp.PrivilegeCount = 1;  // one privilege to set    
				tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 

				// Get the shutdown privilege for this process. 

				AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
					(PTOKEN_PRIVILEGES)NULL, 0); 
				if (GetLastError() != ERROR_SUCCESS) 
				{AfxMessageBox(_T("AdjustTokenPrivileges Fail"));return;}

				if(GetDlgItem(IDC_S5BUTTON)->IsWindowEnabled()) 
					ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 
					SHTDN_REASON_MAJOR_OTHER |
					SHTDN_REASON_MINOR_OTHER |
					SHTDN_REASON_FLAG_PLANNED);
				else if(GetDlgItem(IDC_RbBUTTON)->IsWindowEnabled()) 
					 ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 
					 SHTDN_REASON_MAJOR_OTHER |
                     SHTDN_REASON_MINOR_OTHER |
                     SHTDN_REASON_FLAG_PLANNED);

				int a,b;
				for(a=0;a<1000;a++)
					for(b=0;b<1000;b++);
			}

			break;
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CSVACPIDlg::OnBnClickedPbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	CString BN_disp;
	GetDlgItemText(IDC_PBUTTON,BN_disp);
	if(BN_disp == _T("Pause"))
	{
		KillTimer(20);
		KillTimer(21);
		SetDlgItemText(IDC_PBUTTON,_T("Continue"));
	}
	else
	{
		if(GetDlgItem(IDC_S5BUTTON)->IsWindowEnabled()||GetDlgItem(IDC_RbBUTTON)->IsWindowEnabled())
		{
			HKEY hKey;
			if(RegOpenKeyEx(HKEY_CURRENT_USER,_T("Software\\SVACPI\\ACPI Information"),0,KEY_WRITE,&hKey)!=ERROR_SUCCESS)
			{AfxMessageBox(_T("error when Open KEY \"ACPI Info\"!"));}
		
			//write current setting to KEY
			CString KeyValue =_T("0");
		
			GetDlgItemText(IDC_Countdown,KeyValue);
			int value = _ttoi(KeyValue);
			if(value<5||value>100)
			{AfxMessageBox(_T(" warning! count down TIME is invalid!"));return;}
			RegSetValueEx(hKey,_T("SetTime"),0,REG_SZ,(CONST BYTE*)KeyValue.GetBuffer(0),KeyValue.GetLength()*2);

			GetDlgItemText(IDC_Loop,KeyValue);
			value = _ttoi(KeyValue);
			if(value<1||value>9999)
			{AfxMessageBox(_T(" warning! LOOP set is invalid!"));return;}
			GetDlgItemText(IDC_Loop_time,KeyValue);
			int cval = _ttoi(KeyValue);
			if(!(value>cval))
			{AfxMessageBox(_T(" warning! LOOP set is less than current Loops!"));return;}
			RegSetValueEx(hKey,_T("SetLoop"),0,REG_SZ,(CONST BYTE*)KeyValue.GetBuffer(0),KeyValue.GetLength()*2);

			SetTimer(21,1000,NULL);
		}
		else
		{
			HANDLE hTimer;
			LARGE_INTEGER liDueTime;
			liDueTime.QuadPart = -1000000000;

			hTimer = CreateWaitableTimer(NULL,FALSE,_T("SVacpiTimer"));
			if(hTimer == NULL)
			{
				AfxMessageBox(_T("CreateWaitableTimer failed"));
				return;
			}
			//GetDlgItemText(IDC_WAKETIME,KeyValue);
			//waketime +=_ttoi(KeyValue);
			int waketime = 50;
			if (!SetWaitableTimer(hTimer, &liDueTime,waketime*1000, NULL, NULL, TRUE))
			{
				AfxMessageBox(_T("SetWaitableTimer failed (%d)\n"), GetLastError());
				return;
			}
			else
			{
				CString CurrTime;
				SYSTEMTIME st;GetLocalTime(&st);
				CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
				state = _T("-----------Hibernate Test------------\r\nLoop 1 Start at : ");
				state += CurrTime;
				SetDlgItemText(IDC_State,state);
				SetTimer(20,1000,NULL);
			}
		}
		SetDlgItemText(IDC_PBUTTON, _T("Pause"));
	}
}


void CSVACPIDlg::OnBnClickedClsbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	if(MessageBox(_T("Are you sure to clear all APCI information and log files !!"),_T("CLear ACPI information"),MB_OKCANCEL)==IDOK)
	{
		//stop count down clock
		KillTimer(20);
		KillTimer(21);
		//delete the whole log files.
		CString rbFullLogPath;
		TCHAR SysTmpPath[MAX_PATH];
		GetTempPath(MAX_PATH,SysTmpPath);
		rbFullLogPath = SysTmpPath;rbFullLogPath+=_T("setpower.bat");
		if(PathFileExists(rbFullLogPath)) DeleteFile(rbFullLogPath);

		int value = rootpath.ReverseFind('\\');
	
		rbFullLogPath = rootpath.Left(value+1)+_T("Reboot.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		rbFullLogPath = rootpath.Left(value+1)+_T("ERROR_Reboot.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		rbFullLogPath = rootpath.Left(value+1)+_T("ERROR_RTC.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		rbFullLogPath = rootpath.Left(value+1)+_T("RTC.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		rbFullLogPath = rootpath.Left(value+1)+_T("Suspend.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		rbFullLogPath = rootpath.Left(value+1)+_T("ERROR_Suspend.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		rbFullLogPath = rootpath.Left(value+1)+_T("Hibernate.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		rbFullLogPath = rootpath.Left(value+1)+_T("ERROR_Hibernate.LOG");
		if(PathFileExists(rbFullLogPath))
			DeleteFile(rbFullLogPath);
		//delete the SVACPI KEY
		HKEY hKey;
		SHDeleteKey(HKEY_CURRENT_USER,_T("Software\\SVACPI"));
		if(RegOpenKeyEx(HKEY_CURRENT_USER,
						_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),
						0,
						KEY_WRITE,
						&hKey)==ERROR_SUCCESS)
		RegDeleteValue(hKey,_T("SVReboot"));
		RegDeleteValue(hKey,_T("SVRtc"));
	
		RegCloseKey(hKey);


		//Setting the Pannel for first using
		SetDlgItemText(IDC_Loop,_T("9999"));
		SetDlgItemText(IDC_Countdown,_T("15"));
		SetDlgItemText(IDC_Loop_time,_T("0"));
		SetDlgItemText(IDC_time_to_run,_T("-"));
	
		SetDlgItemText(IDC_PBUTTON,_T("Pause"));
		SetDlgItemText(IDC_S3BUTTON,_T("Run S1/S3"));
		SetDlgItemText(IDC_S4BUTTON,_T("Run S4"));
		SetDlgItemText(IDC_S5BUTTON,_T("Run S5"));
		SetDlgItemText(IDC_RbBUTTON, _T("Reboot"));
	
	
		GetDlgItem(IDC_PBUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_S3BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S4BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_S5BUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_RbBUTTON)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_Error)->EnableWindow(FALSE);
	}
}

int CSVACPIDlg::GetCostTime(CString CurrTime, CString LastTime)
{
	int Pos = CurrTime.Find(_T(":"));
	int currM = _ttoi(CurrTime.Left(Pos));int currS = _ttoi(CurrTime.Right(CurrTime.GetLength()-Pos-1));
	Pos = LastTime.Find(_T(":"));
	int lastM = _ttoi(LastTime.Left(Pos));int lastS = _ttoi(LastTime.Right(LastTime.GetLength()-Pos-1));
	currM = currM-lastM;
	if(currM<0)
		currM+=60;
	
	
	currS =currM*60+currS-lastS;
	return currS;
}


BOOL CSVACPIDlg::CheckDiffInfo(CString ACPISx, CString OriginInfo, CString CurrInfo)
{
	CString DiffHW = _T(""),KeyValue;

	if(OriginInfo == CurrInfo)
	{
		return FALSE;
	}
	else
	{	
		int j=0,strlen = OriginInfo.GetLength(),strlen2 =CurrInfo.GetLength();

		int pflag = OriginInfo.Find(_T("\t\t"))+2;
		int nextPos = OriginInfo.Find(_T("\r\n"),pflag);

		while(nextPos<=strlen-2)
		
		{
			KeyValue = OriginInfo.Left(nextPos);
			KeyValue = KeyValue.Right(nextPos-pflag);
		
			j = CurrInfo.Find(KeyValue);
			if(j==-1)
				DiffHW +=KeyValue;
			DiffHW +=_T("\r\n");
			pflag =OriginInfo.Find(_T("\t\t"),nextPos)+2;
			nextPos =OriginInfo.Find(_T("\r\n"),pflag);
			if(pflag == 1) break;
			j=0;
		}

		SYSTEMTIME st;CString CurrTime;
		GetLocalTime(&st);
		CurrTime.Format(_T("%d-%d-%d %d:%d:%d"),st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
		CString CurrLog = _T("\r\nCurrent ERROR happened at : ")+CurrTime+_T("\r\n ");
		CurrLog += DiffHW;
		CurrLog += _T("Lost!!!\r\n");
		int i = rootpath.ReverseFind('\\');

		if(ACPIs == _T("S3"))
		{
			errorpath = rootpath.Left(i+1) + _T("ERROR_Suspend.LOG");
		}
		else if(ACPIs == _T("S4"))
		{
			errorpath = rootpath.Left(i+1) + _T("ERROR_Hibernate.LOG");
		}
		else if(ACPIs == _T("S5"))
		{
			errorpath = rootpath.Left(i+1) + _T("ERROR_RTC.LOG");
		}
		else if(ACPIs == _T("Reboot"))
		{
			errorpath = rootpath.Left(i+1) + _T("ERROR_Reboot.LOG");
		}

		if(PathFileExists(errorpath))
		{
			CStdioFile error;
			error.Open(errorpath, CFile::modeReadWrite);
			error.SeekToEnd();
			error.WriteString(CurrLog);
			error.Flush();
			error.Close();
		}
		else
		{
			CStdioFile error;
			error.Open(errorpath, CFile::modeCreate|CFile::modeReadWrite);
			error.SeekToEnd();
			error.WriteString(CurrLog);
			error.Flush();
			error.Close();
		}
		
		return TRUE;
	}
}

//获取硬件信息
CString CSVACPIDlg::hardwareinfo()
{
	CString hardwareinfo =_T("");
	//*
	HRESULT hres;
	// initialize COM. -----------------------------------
	//一、初始化COM
	hres = CoInitializeEx(0,COINIT_MULTITHREADED);
	if(SUCCEEDED(hres) || RPC_E_CHANGED_MODE == hres)
	{
		 //设置进程的安全级别，（调用COM组件时在初始化COM之后要调用CoInitializeSecurity设置进程安全级别，否则会被系统识别为病毒） 
		hres=CoInitializeSecurity(NULL,  
            -1,  
            NULL,                     
            NULL,  
            RPC_C_AUTHN_LEVEL_PKT,  
            RPC_C_IMP_LEVEL_IMPERSONATE,  
            NULL,  
            EOAC_NONE,  
            NULL);

		//二、创建一个WMI命名空间连接  
        //创建一个CLSID_WbemLocator对象  

		IWbemLocator *m_pWbemLoc = NULL;
        hres = CoCreateInstance(CLSID_WbemLocator,  
            0,  
            CLSCTX_INPROC_SERVER,  
            IID_IWbemLocator,  
            (LPVOID*)&m_pWbemLoc);  
        VERIFY(SUCCEEDED(hres));  

		//使用m_pWbemLoc连接到"root\cimv2"并设置m_pWbemSvc的指针
		IWbemServices *m_pWbemSvc = NULL;
        hres=m_pWbemLoc->ConnectServer(CComBSTR(L"ROOT\\CIMV2"),  
            NULL,  
            NULL,  
            0,  
            NULL,  
            0,  
            0,  
            &m_pWbemSvc);  
        VERIFY(SUCCEEDED(hres)); 

		//三、设置WMI连接的安全性  
        hres=CoSetProxyBlanket(m_pWbemSvc,  
            RPC_C_AUTHN_WINNT,  
            RPC_C_AUTHZ_NONE,  
            NULL,  
            RPC_C_AUTHN_LEVEL_CALL,  
            RPC_C_IMP_LEVEL_IMPERSONATE,  
            NULL,  
            EOAC_NONE);  
        VERIFY(SUCCEEDED(hres));

		//查询类ClassName中的所有字段,保存到m_pEnumClsObj中  
		IEnumWbemClassObject* m_pEnumClsObj = NULL;
		hres = m_pWbemSvc->ExecQuery(
        bstr_t("WQL"), 
        bstr_t("SELECT * FROM Win32_DiskDrive"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, 
        NULL,
        &m_pEnumClsObj);

		if (SUCCEEDED(hres))  
        {  
            //初始化vtProp值  
			VARIANT vtProp; 
  
            //返回从当前位置起的第一个对象到m_pWbemClsObj中  
			IWbemClassObject *m_pWbemClsObj;
			ULONG uReturn = 0;

			while(m_pEnumClsObj)
			{
				VariantInit(&vtProp);  

				hres=m_pEnumClsObj->Next(WBEM_INFINITE,1,&m_pWbemClsObj,&uReturn);  
				if(uReturn==0)   
				{  
					break; 
		        }
				//从m_pWbemClsObj中找出ClassMember标识的成员属性值,并保存到vtProp变量中  
				hres = m_pWbemClsObj->Get(L"InterfaceType",0,&vtProp,0,0);
				hardwareinfo += vtProp;hardwareinfo +=_T("\t\t");
				//hres = m_pWbemClsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
				//hardwareinfo +=vtProp;
				hres = m_pWbemClsObj->Get(L"Model", 0, &vtProp, 0, 0);
				hardwareinfo +=vtProp;hardwareinfo +=_T("\r\n");

				VariantClear(&vtProp);
			}
			m_pWbemClsObj->Release();
        }

		m_pWbemSvc->Release();
		m_pWbemLoc->Release();
	    m_pEnumClsObj->Release();
		CoUninitialize();
	}

	return hardwareinfo;
}