#pragma once


// CDlgHowToPlay 对话框

class CDlgHowToPlay : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgHowToPlay)

public:
	CDlgHowToPlay(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgHowToPlay();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOWTOPLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnHowtoplay();
};
