
// AutoMoveMouseDlg.h: 头文件
//

#pragma once

class CAutoMoveMouseDlgAutoProxy;


// CAutoMoveMouseDlg 对话框
class CAutoMoveMouseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAutoMoveMouseDlg);
	friend class CAutoMoveMouseDlgAutoProxy;

// 构造
public:
	CAutoMoveMouseDlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CAutoMoveMouseDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOMOVEMOUSE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CAutoMoveMouseDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButton1();
};
