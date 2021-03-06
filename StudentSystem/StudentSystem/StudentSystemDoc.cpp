
// StudentSystemDoc.cpp: CStudentSystemDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudentSystem.h"
#endif

#include "StudentSystemDoc.h"

#include <propkey.h>
#include "CDlgHowToPlay.h"
#include "CDataInsertDlg.h"
#include <sstream>
#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CStudentSystemDoc

IMPLEMENT_DYNCREATE(CStudentSystemDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudentSystemDoc, CDocument)
	ON_COMMAND(ID_INSERT, &CStudentSystemDoc::OnInsert)
	ON_COMMAND(ID_NAMEUP, &CStudentSystemDoc::OnNameup)
	ON_COMMAND(ID_NAMEDOWN, &CStudentSystemDoc::OnNamedown)
	ON_COMMAND(ID_NUMUP, &CStudentSystemDoc::OnNumup)
	ON_COMMAND(ID_NUMDOWN, &CStudentSystemDoc::OnNumdown)
END_MESSAGE_MAP()


// CStudentSystemDoc 构造/析构

CStudentSystemDoc::CStudentSystemDoc() noexcept
{
	// TODO: 在此添加一次性构造代码
	//MessageBox(TEXT("FUCK"));
	//每个子窗口创立的时候，都会调用这个函数
	//CDlgHowToPlay dlg;
	//dlg.DoModal();
}

CStudentSystemDoc::~CStudentSystemDoc()
{
}

BOOL CStudentSystemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	//这步初始化是在视图和框架之后

	//CDlgHowToPlay dlg;
	//dlg.DoModal();
	//MessageBox(TEXT("OnNewDocument"), 0, 0, 0)

	//CScrollView* view = GetNextView();
	//AddView(view);
	//m_viewList//这个是所关联的视图
	//Detail a(TEXT("高若朋"), TEXT("171860582"), TEXT("男"), TEXT("18"));
	//Detail b(TEXT("许家铭"), TEXT("171860581"), TEXT("男"), TEXT("18"));
	//data.push_back(a);
	//data.push_back(b);
	return TRUE;
}

//自定义的文件操作

size_t CStudentSystemDoc::GetNumOfStudent() const
{
	return data.size();
}

void CStudentSystemDoc::OnInsert()
{
	// TODO: 在此添加命令处理程序代码
	CDataInsertDlg dlg;
	dlg.DoModal();
	if (dlg.flag)
		DataInsert(dlg.student_name, dlg.student_num, dlg.sex, dlg.student_age);
}

void CStudentSystemDoc::DataInsert(CString name, CString num, CString sex, CString age)
{
	Detail add(name, num, sex, age);
	data.push_back(add);
	SetModifiedFlag(true);//标记为被修改
	//UpdateAllViews();
	UpdateAllViews(NULL);//更新所有相关的VIEW
	return;
}

void CStudentSystemDoc::DataChange(int index, CString name, CString num, CString sex, CString age)
{
	data[index].name = name;
	data[index].num = num;
	data[index].sex = sex;
	data[index].age = age;
}


void CStudentSystemDoc::SortBy(int col, bool mode)
{
	//std::sort(data.begin(), data.end(), )
	int len = data.size();
	bool flag = false;
	for (int i(0); i < len;  ++i)
	{
		for (int j(0); j < len - 1; ++j)
		{
			switch(col)
			{
			case 0:
				{
				if ((data[j].name > data[j + 1].name) && mode)
				{
					std::swap(data[j], data[j + 1]);
					flag = true;
				}
				if ((data[j].name < data[j + 1].name) && !mode)
				{
					std::swap(data[j], data[j + 1]);
					flag = true;
				}
			}break;
			case 1:
				{
				//string x((LPCTSTR)data[j].num);
				if ((atoi((char*)(LPCTSTR)data[j].num) > atoi((char*)(LPCTSTR)data[j + 1].num)) && mode)
				{
					std::swap(data[j], data[j + 1]);
					flag = true;
				}
				if ((atoi((char*)(LPCTSTR)data[j].num) < atoi((char*)(LPCTSTR)data[j + 1].num)) && !mode)
				{
					std::swap(data[j], data[j + 1]);
					flag = true;
				}
			}break;
			}
		}
	}
	if (flag)
		SetModifiedFlag(1);
	return;
}


//自定义的文件操作END


// CStudentSystemDoc 序列化

void CStudentSystemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		for (int i(0), len = GetNumOfStudent(); i < len; ++i)
		{
			string inputa, inputb, inputc, inputd;
			/*USES_CONVERSION;
			inputa = W2A(data[i].name);*/
			//ar << data[i].name << TEXT(" ") << data[i].num << TEXT(" ") << data[i].sex << TEXT(" ") << data[i].age << TEXT("\n");
			//ar << inputa << " " << data[i].num << " " << data[i].sex << " " << data[i].age << "\n";
			setlocale(LC_CTYPE, "chs"); //其对应的头文件为 <locale.h>
			ar.WriteString(data[i].name);
			ar.WriteString(TEXT(" "));
			ar.WriteString(data[i].num);
			ar.WriteString(TEXT(" "));
			ar.WriteString(data[i].sex);
			ar.WriteString(TEXT(" "));
			ar.WriteString(data[i].age);
			ar.WriteString(TEXT("\n"));
		}
	}
	else
	{
		// TODO: 在此添加加载代码
		SetModifiedFlag(0);
		//MessageBox(TEXT("Try to open"));
		//CDlgHowToPlay dlg;
		//dlg.DoModal();
		setlocale(LC_CTYPE, "chs"); //其对应的头文件为 <locale.h>
		CString getline;
		ar.ReadString(getline);
		while (!getline.IsEmpty())
		{
			CString name, num, sex, age;
			/*ar.ReadString(name);
			ar.ReadString(num);
			ar.ReadString(sex);
			ar.ReadString(age);*/
			//USES_CONVERSION;
			
			string line = (char*)getline.GetBuffer(0);
			//string line = CT2A(getline); //.GetBuffer(0);
			string name_get, num_get, sex_get, age_get;
			std::istringstream record(line);
			record >> name_get >> num_get >> sex_get >> age_get;
			name.Format(_T("%hs"), name_get.c_str());
			num.Format(_T("%hs"), num_get.c_str());
			sex.Format(_T("%hs"), sex_get.c_str());
			age.Format(_T("%hs"), age_get.c_str());
			Detail input(name, num, sex, age);
			data.push_back(input);
			ar.ReadString(getline);
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CStudentSystemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CStudentSystemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CStudentSystemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CStudentSystemDoc 诊断

#ifdef _DEBUG
void CStudentSystemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudentSystemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStudentSystemDoc 命令




void CStudentSystemDoc::OnNameup()
{
	// TODO: 在此添加命令处理程序代码
	SortBy(0, true);
	UpdateAllViews(NULL);
}


void CStudentSystemDoc::OnNamedown()
{
	// TODO: 在此添加命令处理程序代码
	SortBy(0, false);
	UpdateAllViews(NULL);
}


void CStudentSystemDoc::OnNumup()
{
	// TODO: 在此添加命令处理程序代码
	SortBy(1, true);
	UpdateAllViews(NULL);
}


void CStudentSystemDoc::OnNumdown()
{
	// TODO: 在此添加命令处理程序代码
	SortBy(1, false);
	UpdateAllViews(NULL);
}
