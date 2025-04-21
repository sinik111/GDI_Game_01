#include "framework.h"
#include "UITest.h"

#include "GDIRenderer.h"
#include "Resources.h"
#include "Debug.h"
#include "ResultCode.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "Input.h"
#include "GameData.h"

ResultCode UITest::Initialize()
{
	m_Position = Vector2::Zero;

	m_Image = Resources::Get().GetImage(L"Result", L"UITest");

	m_Text = L"Score: " + std::to_wstring(GameData::Get().GetScore());

	m_Color = Gdiplus::Color(0, 0, 0);

	m_Collider.SetColliderInfo(ColliderType::UIRect, m_Position, Vector2::Zero, (float)m_Image->GetWidth(), (float)m_Image->GetHeight());

	return ResultCode::OK;
}

void UITest::Destroy()
{

}

void UITest::Update()
{
	POINT mousePoint = Input::Get().GetCursorPosition();
	Vector2 mousePos = Vector2((float)mousePoint.x, (float)mousePoint.y);


	if (CollisionManager::Get().CheckUIRectContainPosition(m_Collider, mousePos))
	{
		m_Color = Gdiplus::Color(255, 0, 0);
	}
	else
	{
		m_Color = Gdiplus::Color(0, 0, 0);
	}
}

void UITest::Render()
{
	Gdiplus::Rect dst_rect;
	Gdiplus::Rect src_rect;

	src_rect.X = 0;
	src_rect.Y = 0;
	src_rect.Width = m_Image->GetWidth();
	src_rect.Height = m_Image->GetHeight();

	dst_rect.X = (int)m_Position.x;
	dst_rect.Y = (int)m_Position.y;
	dst_rect.Width = m_Image->GetWidth();
	dst_rect.Height = m_Image->GetHeight();

	GDIRenderer::Get().DrawImage(m_Image, dst_rect, src_rect);

	GDIRenderer::Get().DrawString(m_Text.c_str(), m_Color, Vector2(500.0f, 40.0f));
}
