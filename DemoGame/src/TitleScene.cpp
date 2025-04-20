#include "framework.h"
#include "TitleScene.h"

#include "Debug.h"
#include "Input.h"
#include "SceneManager.h"

ResultCode TitleScene::Load()
{
	Debug::Log("load Title Scene");

	return ResultCode();
}

ResultCode TitleScene::Enter()
{
	return ResultCode();
}

void TitleScene::Exit()
{
}

void TitleScene::Unload()
{
}

void TitleScene::Update()
{
	if (Input::Get().IsKeyReleased('A'))
	{
		SceneManager::Get().ChangeScene(L"Play");
	}
}
