#include "framework.h"
#include "TitleScene.h"

#include "Debug.h"
#include "Input.h"
#include "SceneManager.h"
#include "BackgroundTest.h"
#include "FileLoader.h"
#include "Resources.h"

ResultCode TitleScene::Load()
{
	Debug::Log("load Title Scene");

	Resources::Get().AddImage(L"Title", L"title_image", FileLoader::Get().LoadImageFile(L"image/title_800 600.png"));

	return ResultCode();
}

ResultCode TitleScene::Enter()
{
	BackgroundTest* pBackground = new BackgroundTest(Resources::Get().GetImage(L"Title", L"title_image"), 0);
	pBackground->Initialize();

	m_Objects.push_back(pBackground);

	return ResultCode();
}

void TitleScene::Exit()
{
	__super::Exit();
}

void TitleScene::Unload()
{
	Resources::Get().ReleaseResources(L"Title");
}

void TitleScene::Update()
{
	if (Input::Get().IsKeyReleased('1'))
	{
		SceneManager::Get().ChangeScene(L"Play");
	}

	__super::Update();
}
