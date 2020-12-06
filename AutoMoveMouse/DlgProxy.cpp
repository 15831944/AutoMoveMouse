﻿
// DlgProxy.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AutoMoveMouse.h"
#include "DlgProxy.h"
#include "AutoMoveMouseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoMoveMouseDlgAutoProxy

IMPLEMENT_DYNCREATE(CAutoMoveMouseDlgAutoProxy, CCmdTarget)

CAutoMoveMouseDlgAutoProxy::CAutoMoveMouseDlgAutoProxy()
{
	EnableAutomation();

	// 为使应用程序在自动化对象处于活动状态时一直保持
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CAutoMoveMouseDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CAutoMoveMouseDlg)))
		{
			m_pDialog = reinterpret_cast<CAutoMoveMouseDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CAutoMoveMouseDlgAutoProxy::~CAutoMoveMouseDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CAutoMoveMouseDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CAutoMoveMouseDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAutoMoveMouseDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IAutoMoveMouse 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {33252f45-046f-437c-8ec6-f7e7d46cdb0c}
static const IID IID_IAutoMoveMouse =
{0x33252f45,0x046f,0x437c,{0x8e,0xc6,0xf7,0xe7,0xd4,0x6c,0xdb,0x0c}};

BEGIN_INTERFACE_MAP(CAutoMoveMouseDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CAutoMoveMouseDlgAutoProxy, IID_IAutoMoveMouse, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏是在此项目的 pch.h 中定义的
// {8466947c-e1b9-423c-9eb2-9a9545fef3b9}
IMPLEMENT_OLECREATE2(CAutoMoveMouseDlgAutoProxy, "AutoMoveMouse.Application", 0x8466947c,0xe1b9,0x423c,0x9e,0xb2,0x9a,0x95,0x45,0xfe,0xf3,0xb9)


// CAutoMoveMouseDlgAutoProxy 消息处理程序
