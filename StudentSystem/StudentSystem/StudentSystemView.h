
// StudentSystemView.h: CStudentSystemView 类的接口
//

#pragma once



class CStudentSystemView : public CScrollView
{
protected: // 仅从序列化创建
	CStudentSystemView() noexcept;
	DECLARE_DYNCREATE(CStudentSystemView)
	
	int current_student = -1;

	//bool MenuChange = false;
// 特性
public:
	CStudentSystemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	
// 实现
public:
	virtual ~CStudentSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

	
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDelete();
	virtual void OnUpdate(CScrollView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	//virtual void OnSize(UINT nType, int cx, int cy);
	void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnChange();
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // StudentSystemView.cpp 中的调试版本
inline CStudentSystemDoc* CStudentSystemView::GetDocument() const
   { return reinterpret_cast<CStudentSystemDoc*>(m_pDocument); }
#endif

