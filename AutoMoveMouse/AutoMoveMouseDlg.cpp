
// AutoMoveMouseDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AutoMoveMouse.h"
#include "AutoMoveMouseDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define WM_INITBTN (WM_USER+1)

// CAutoMoveMouseDlg 对话框


IMPLEMENT_DYNAMIC(CAutoMoveMouseDlg, CDialogEx);

CAutoMoveMouseDlg::CAutoMoveMouseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTOMOVEMOUSE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = nullptr;
}

CAutoMoveMouseDlg::~CAutoMoveMouseDlg()
{
	// 如果该对话框有自动化代理，则
	//  此对话框的返回指针为 null，所以它知道
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != nullptr)
		m_pAutoProxy->m_pDialog = nullptr;
}

void CAutoMoveMouseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAutoMoveMouseDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_BN_CLICKED(IDC_BUTTON1, &CAutoMoveMouseDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAutoMoveMouseDlg 消息处理程序
POINT p;

BOOL CAutoMoveMouseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	HWND hWnd = GetSafeHwnd();
	RegisterHotKey(hWnd, 1001, MOD_CONTROL, 'G');
	p.x = p.y = 0x3f3f3f3f;
	::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAutoMoveMouseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAutoMoveMouseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CAutoMoveMouseDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CAutoMoveMouseDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CAutoMoveMouseDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

LRESULT CAutoMoveMouseDlg::OnHotKey(WPARAM wParam, LPARAM lParam)
{
	switch (wParam) {
	case 1001:{
		if (p.x == 0x3f3f3f3f && p.y == 0x3f3f3f3f) {
			MessageBox(L"Invalid Pos!", L"Error", MB_ICONERROR);
			return LRESULT();
		}
		SetCursorPos(p.x, p.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
	}
	return LRESULT();
}

BOOL CAutoMoveMouseDlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != nullptr)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



DWORD WINAPI OnGetPosThread(LPVOID lpParam) {
	CAutoMoveMouseDlg* p_Dlg=(CAutoMoveMouseDlg*)lpParam;
	while (true) {
		if (!KEY_DOWN(VK_LBUTTON)) {
			Sleep(100);
			continue;
		}
		if (GetCursorPos(&p)) break;// 获取鼠标当前位置
	}
	p_Dlg->GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	CString strPos;
	strPos.Format(L"%d,%d", p.x, p.y);
	p_Dlg->SetDlgItemTextW(IDC_EDIT1, strPos);
	return 0;
}

void CAutoMoveMouseDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	CreateThread(NULL, 0, OnGetPosThread, this, 0, 0);
	return;
}
