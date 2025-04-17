#pragma once

class WinApp
{
private:
	HWND m_hWnd;
	HINSTANCE m_hInstance;
	int m_Width;
	int m_Height;
	std::wstring m_ClassName;
	std::wstring m_WindowName;
	std::wstring m_ModulePath;
	std::wstring m_WorkingPath;

public:
	WinApp();
	virtual ~WinApp() = default;

public:
	virtual ResultCode Initialize();
	virtual void Shutdown();

	void Run();

private:
	void Update();
	void Render();

private:
	virtual void MessageProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	friend LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
};