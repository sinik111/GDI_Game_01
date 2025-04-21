#include "framework.h"
#include "BackgroundTest.h"

#include "GDIRenderer.h"
#include "Resources.h"
#include "ResultCode.h"
#include "Camera.h"
#include "GameData.h"

BackgroundTest::BackgroundTest(Gdiplus::Bitmap* image, int scene)
	:m_Image(image), m_SceneNumber(scene)
{
	
}

ResultCode BackgroundTest::Initialize()
{
	m_Position = Vector2(GDIRenderer::Get().GetWidth() / 2.0f, GDIRenderer::Get().GetHeight() / 2.0f);

	return ResultCode::OK;
}

void BackgroundTest::Destroy()
{

}

void BackgroundTest::Update()
{
}

void BackgroundTest::Render()
{
	Gdiplus::Rect dst_rect;
	Gdiplus::Rect src_rect;

	src_rect.X = 0;
	src_rect.Y = 0;
	src_rect.Width = m_Image->GetWidth();
	src_rect.Height = m_Image->GetHeight();

	dst_rect.X = (int)(m_Position.x - src_rect.Width / 2);
	dst_rect.Y = (int)(m_Position.y - src_rect.Height / 2);
	dst_rect.Width = m_Image->GetWidth();
	dst_rect.Height = m_Image->GetHeight();

	GDIRenderer::Get().DrawImage(m_Image, dst_rect, src_rect);

	std::wstring timer = L"";
	switch (m_SceneNumber)
	{
	case 0:
		GDIRenderer::Get().DrawString(L"press 1 to continue", Gdiplus::Color(0, 0, 0), Vector2(300, 400));
		break;

	case 1:
		timer = L"Timer: " + std::to_wstring(GameData::Get().GetTimer());
		GDIRenderer::Get().DrawString(timer.c_str(), Gdiplus::Color(0, 0, 0), Vector2(300, 400));
		break;

	case 2:
		GDIRenderer::Get().DrawString(L"press 1 to continue", Gdiplus::Color(0, 0, 0), Vector2(300, 400));
		break;
	}
}
