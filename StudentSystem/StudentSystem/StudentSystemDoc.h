
// StudentSystemDoc.h: CStudentSystemDoc 类的接口
//


#pragma once
#include "File.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

struct Detail
{
	CString name;
	CString num;
	CString sex;
	CString age;
	Detail(CString name, CString num, CString sex, CString age) :
		name(name), num(num), sex(sex), age(age) {}
};



class CStudentSystemDoc : public CDocument
{
protected: // 仅从序列化创建
	CStudentSystemDoc() noexcept;
	DECLARE_DYNCREATE(CStudentSystemDoc)

	//自定义的数据
	vector<Detail> data;
	
	// 特性
public:

	// 操作
public:
	void DataInsert(CString name, CString num, CString sex, CString age);
	size_t GetNumOfStudent() const;
	void SortBy(int col, bool mode);
	void DataChange(int index, CString name, CString num, CString sex, CString age);
	// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// 实现
public:
	virtual ~CStudentSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnInsert();
	afx_msg void OnNameup();
	afx_msg void OnNamedown();
	afx_msg void OnNumup();
	afx_msg void OnNumdown();
};
