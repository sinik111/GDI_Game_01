#pragma once

#include "WinApp.h"
#include "ResultCode.h"

class DemoGameApp :
	public WinApp
{
public:
	DemoGameApp() = default;
	~DemoGameApp() = default;

	ResultCode Initialize();
	void Shutdown() override;

	void MessageProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};