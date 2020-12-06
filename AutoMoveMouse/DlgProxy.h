﻿
// DlgProxy.h: 头文件
//

#pragma once

class CAutoMoveMouseDlg;


// CAutoMoveMouseDlgAutoProxy 命令目标

class CAutoMoveMouseDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CAutoMoveMouseDlgAutoProxy)

	CAutoMoveMouseDlgAutoProxy();           // 动态创建所使用的受保护的构造函数

// 特性
public:
	CAutoMoveMouseDlg* m_pDialog;

// 操作
public:

// 重写
	public:
	virtual void OnFinalRelease();

// 实现
protected:
	virtual ~CAutoMoveMouseDlgAutoProxy();

	// 生成的消息映射函数

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CAutoMoveMouseDlgAutoProxy)

	// 生成的 OLE 调度映射函数

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

