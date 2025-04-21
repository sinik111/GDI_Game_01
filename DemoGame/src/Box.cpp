#include "framework.h"
#include "Box.h"

#include "ResultCode.h"
#include "GDIRenderer.h"
#include "MyTime.h"
#include "Input.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "Debug.h"

Box::Box(const Vector2& position, Gdiplus::Bitmap* image)
    : m_Image(image), m_Speed(0.0f)
{
    m_Position = position;
}

ResultCode Box::Initialize()
{
    m_Speed = 100.0f;

    m_Direction = Vector2((rand() % 200 - 100) / 0.01f, (rand() % 200 - 100) / 0.01f ).Normalized();

    m_Collider.SetColliderInfo(ColliderType::AABB, m_Position, Vector2::Zero, 16.0f, 16.0f);

	return ResultCode::OK;
}

void Box::Destroy()
{
    __super::Destroy();

    Debug::Log("Box Destroyed");
}

void Box::Update()
{
    m_Position += m_Direction * m_Speed * MyTime::Get().DeltaTime();

    float screenWidth = (float)GDIRenderer::Get().GetWidth();
    float screenHeight = (float)GDIRenderer::Get().GetHeight();

    bool isAdjusted = false; // 좌표 조정이 있었을 경우에만 다시 world좌표로 바꿔주기 위한 상태 확인 변수

    if (m_Position.x < 0.0f || m_Position.x > screenWidth - 1) // x 좌표 체크
    {
        m_Position.x = m_Position.x < 0.0f ? 0.0f : screenWidth - 1; // 화면 안으로 좌표 조정

        m_Direction.x *= -1; ; // 방향 변경
    }

    if (m_Position.y < 0.0f || m_Position.y > screenHeight - 1) // y 좌표 체크
    {
        m_Position.y = m_Position.y < 0.0f ? 0.0f : screenHeight - 1; // 화면 안으로 좌표 조정

        m_Direction.y *= -1; // 방향 변경
    }

    m_Collider.UpdateCollider(m_Position);

    if (!m_IsDestroyed)
    {
        CollisionManager::Get().ResisterGameObject(L"box", this);
    }
}

void Box::Render()
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

    GDIRenderer::Get().DrawRectangle(Gdiplus::Color(0, 0, 0), Gdiplus::Rect((int)m_Collider.position.x, (int)m_Collider.position.y,
        (int)m_Collider.width, (int)m_Collider.height));
}

void Box::Collide(Object& object, const std::wstring& groupName)
{
    if (groupName == L"player")
    {
        m_IsDestroyed = true;
    }
}
