#include "framework.h"
#include "PlayScene.h"

#include "Debug.h"
#include "FileLoader.h"
#include "Resources.h"
#include "Player.h"
#include "Box.h"
#include "CollisionManager.h"
#include "GDIRenderer.h"
#include "BackgroundTest.h"
#include "Input.h"
#include "SceneManager.h"
#include "MyTime.h"
#include "GameData.h"

ResultCode PlayScene::Load()
{
	Debug::Log("load Play Scene");

	Resources::Get().AddImage(L"Play", L"player_walk", FileLoader::Get().LoadImageFile(L"image/Walk.png"));
	Resources::Get().AddImage(L"Play", L"player_attack", FileLoader::Get().LoadImageFile(L"image/Attack.png"));
	Resources::Get().AddImage(L"Play", L"player_idle", FileLoader::Get().LoadImageFile(L"image/Idle.png"));

	Resources::Get().AddImage(L"Play", L"red", FileLoader::Get().LoadImageFile(L"image/red.png"));
	Resources::Get().AddImage(L"Play", L"green", FileLoader::Get().LoadImageFile(L"image/green.png"));
	Resources::Get().AddImage(L"Play", L"blue", FileLoader::Get().LoadImageFile(L"image/blue.png"));

	Resources::Get().AddImage(L"Play", L"play_image", FileLoader::Get().LoadImageFile(L"image/play_800 600.png"));

	return ResultCode();
}

ResultCode PlayScene::Enter()
{
	BackgroundTest* pBackground = new BackgroundTest(Resources::Get().GetImage(L"Play", L"play_image"), 1);
	pBackground->Initialize();

	m_Objects.push_back(pBackground);

	Player* pPlayer = CreateObject<Player>();
	pPlayer->Initialize();

	int screen_width = GDIRenderer::Get().GetWidth();
	int screen_height = GDIRenderer::Get().GetHeight();

	for (int i = 0; i < 50; ++i)
	{
		Box* pBox = new Box(Vector2((float)(rand() % screen_width), (float)(rand() % screen_height)), Resources::Get().GetImage(L"Play", L"red"));
		m_Objects.push_back(pBox);
		pBox->Initialize();

		pBox = new Box(Vector2((float)(rand() % screen_width), (float)(rand() % screen_height)), Resources::Get().GetImage(L"Play", L"green"));
		m_Objects.push_back(pBox);
		pBox->Initialize();

		pBox = new Box(Vector2((float)(rand() % screen_width), (float)(rand() % screen_height)), Resources::Get().GetImage(L"Play", L"blue"));
		m_Objects.push_back(pBox);
		pBox->Initialize();
	}

	m_Timer = 10.0f;

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
	m_Timer -= MyTime::Get().DeltaTime();

	GameData::Get().SetTimer(m_Timer);

	if (m_Timer < 0.0f)
	{
		SceneManager::Get().ChangeScene(L"Result");
	}

	CollisionManager::Get().CheckCollision(L"player", L"box");

	CollisionManager::Get().ClearCandidates();

	__super::Update();
}
