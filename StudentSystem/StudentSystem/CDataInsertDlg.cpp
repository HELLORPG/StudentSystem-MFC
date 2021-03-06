// CDataInsertDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "CDataInsertDlg.h"
#include "afxdialogex.h"


// CDataInsertDlg 对话框

IMPLEMENT_DYNAMIC(CDataInsertDlg, CDialogEx)

CDataInsertDlg::CDataInsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT, pParent)
	, student_name(_T(""))
	, student_num(_T(""))
	, student_age(_T(""))
{

}

CDataInsertDlg::~CDataInsertDlg()
{
}

void CDataInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, student_name);
	//  DDX_Control(pDX, IDC_EDIT2, student_num);
	//  DDX_Control(pDX, IDC_EDIT4, student_age);
	DDX_Text(pDX, IDC_EDIT1, student_name);
	DDX_Text(pDX, IDC_EDIT2, student_num);
	DDX_Text(pDX, IDC_EDIT4, student_age);
	DDX_Control(pDX, IDC_COMBO1, student_sex);
}


BEGIN_MESSAGE_MAP(CDataInsertDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDataInsertDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDataInsertDlg::OnCbnSelchangeCombo1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CDataInsertDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CDataInsertDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDataInsertDlg 消息处理程序


//确定添加学生信息之后的点击事件
void CDataInsertDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//应该对多个值进行有效判断

	UpdateData(TRUE);
	//更新数据，拿到最新的数据

	if (student_name.IsEmpty())
	{
		MessageBox(TEXT("输入的学生姓名不能为空"));
		return;
	}
	else if (student_num.IsEmpty())
	{
		MessageBox(TEXT("输入的学生学号不能为空"));
		return;
	}
	else if (student_age.IsEmpty())
	{
		MessageBox(TEXT("输入的学生年龄不能为空"));
		return;
	}
	else if (sex != "男" && sex != "女")
	{
		MessageBox(TEXT("请正确选择性别"));
	}
	else
	{
		flag = true;
		ENTER = false;
		OnOK();
	}
}

//学生性别的选择
void CDataInsertDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	int index = student_sex.GetCurSel();

	//CString sex;
	student_sex.GetLBText(index, sex);

	//MessageBox(sex);
}





void CDataInsertDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	//OnBnClickedButton1();
}


void CDataInsertDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	if (ENTER)
		OnBnClickedButton1();

	if (flag)
		CDialogEx::OnOK();
	else
	{
		CDialogEx::OnCancel();
	}
}
