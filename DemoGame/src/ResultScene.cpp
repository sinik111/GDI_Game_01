#include "framework.h"
#include "ResultScene.h"

#include "Resources.h"
#include "FileLoader.h"
#include "BackgroundTest.h"
#include "Input.h"
#include "SceneManager.h"
#include "UITest.h"

ResultCode ResultScene::Load()
{
    Resources::Get().AddImage(L"Result", L"result_image", FileLoader::Get().LoadImageFile(L"image/result_800 600.png"));
    Resources::Get().AddImage(L"Result", L"UITest", FileLoader::Get().LoadImageFile(L"image/UITest 800.png"));

    return ResultCode();
}

ResultCode ResultScene::Enter()
{
    BackgroundTest* pBackground = new BackgroundTest(Resources::Get().GetImage(L"Result", L"result_image"), 2);
    pBackground->Initialize();

    m_Objects.push_back(pBackground);


    UITest* pUITest = new UITest();
    pUITest->Initialize();

    m_Objects.push_back(pUITest);

    return ResultCode();
}

void ResultScene::Exit()
{
    __super::Exit();
}

void ResultScene::Unload()
{
    Resources::Get().ReleaseResources(L"Result");
}

void ResultScene::Update()
{
    if (Input::Get().IsKeyReleased('1'))
    {
        SceneManager::Get().ChangeScene(L"Title");
    }

    __super::Update();
}
