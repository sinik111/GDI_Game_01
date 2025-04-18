#include "framework.h"
#include "DemoGameApp.h"
#include "resource.h"

#include "Debug.h"
#include "Input.h"
#include "FileLoader.h"
#include "SceneManager.h"

#include "TitleScene.h"
#include "PlayScene.h"
#include "ResultScene.h"

ResultCode DemoGameApp::Initialize()
{
	ResultCode rc = ResultCode::OK;

	HINSTANCE hInstance = GetModuleHandleW(NULL);

	m_ClassStyle = CS_HREDRAW | CS_VREDRAW;
	m_WindowStyle = WS_OVERLAPPEDWINDOW;
	
	m_hCursor = LoadCursorW(NULL, IDC_ARROW);
	m_hIcon = LoadIconW(hInstance, MAKEINTRESOURCE(IDI_DEMOGAME));
	m_hIconSmall = LoadIconW(hInstance, MAKEINTRESOURCE(IDI_SMALL));

	m_X = CW_USEDEFAULT;
	m_Y = CW_USEDEFAULT;
	m_Width = 800;
	m_Height = 600;

	m_ClassName = L"gdi";
	m_WindowName = L"GDI_DemoGame";

	rc = __super::Initialize();
	if (rc != ResultCode::OK)
	{
		Debug::Log("Initialize fail DemoGameApp::Initialize");

		return ResultCode::FAIL;
	}

	FileLoader::Get().Initialize(m_ModulePath, L"bin", L"res");

	SceneManager::Get().CreateScene<TitleScene>(L"Title");
	SceneManager::Get().CreateScene<PlayScene>(L"Play");
	SceneManager::Get().CreateScene<ResultScene>(L"Play");

	SceneManager::Get().ChangeScene(L"Title");

	return ResultCode::OK;
}

void DemoGameApp::Shutdown()
{
	__super::Shutdown();
}

void DemoGameApp::MessageProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	__super::MessageProc(hWnd, uMsg, wParam, lParam);

	switch (uMsg)
	{
	case WM_CREATE:
		break;
	}
}
