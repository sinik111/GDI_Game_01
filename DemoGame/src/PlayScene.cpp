#include "framework.h"
#include "PlayScene.h"

#include "Debug.h"
#include "FileLoader.h"
#include "Resources.h"
#include "Player.h"

ResultCode PlayScene::Load()
{
	Debug::Log("load Play Scene");

	Resources::Get().AddImage(L"Play", L"player_walk", FileLoader::Get().LoadImageFile(L"image/Walk.png"));
	Resources::Get().AddImage(L"Play", L"player_attack", FileLoader::Get().LoadImageFile(L"image/Attack.png"));
	Resources::Get().AddImage(L"Play", L"player_idle", FileLoader::Get().LoadImageFile(L"image/Idle.png"));

	return ResultCode();
}

ResultCode PlayScene::Enter()
{
	Player* pPlayer = CreateObject<Player>();
	pPlayer->Initialize();

	return ResultCode();
}

void PlayScene::Exit()
{
	__super::Exit();
}

void PlayScene::Unload()
{
	Resources::Get().ReleaseResources(L"Play");
}

void PlayScene::Update()
{
	__super::Update();
}
