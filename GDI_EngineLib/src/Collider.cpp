#include "pch.h"
#include "Collider.h"

#include "Vector2.h"

void Collider::SetColliderInfo(const Vector2& position, const Vector2& offset, float radius, float width, float height)
{
	m_circle.position = position + offset;
	m_circle.offset = offset;
	m_circle.radius = radius;

	m_box.position = Vector2(position.x - width / 2, position.y - height / 2) + offset;
	m_box.offset = offset;
	m_box.width = width;
	m_box.height = height;

	m_ui_rect.position = position;
	m_ui_rect.width = width;
	m_ui_rect.height = height;
}

Circle Collider::GetCircleCollider()
{
	return m_circle;
}

AABB Collider::GetAABBCollider()
{
	return m_box;
}

UIRect Collider::GetUIRectCollider()
{
	return m_ui_rect;
}

void Collider::UpdateCollider(const Vector2& position)
{
	m_circle.position = position + m_circle.offset;

	m_box.position = Vector2(position.x - m_box.width / 2, position.y - m_box.height / 2) + m_box.offset;

	m_ui_rect.position = position;
}

Circle::Circle()
	: position(Vector2::Zero), offset(Vector2::Zero), radius(0.0f)
{
}

AABB::AABB()
	: position(Vector2::Zero), offset(Vector2::Zero), width(0.0f), height(0.0f)
{
}

UIRect::UIRect()
	: position(Vector2::Zero), width(0.0f), height(0.0f)
{
}
