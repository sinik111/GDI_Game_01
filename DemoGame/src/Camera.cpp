#include "Camera.h"

#include "GDIRenderer.h"
#include "Vector2.h"

Camera::Camera(const Vector2& position, int width, int height)
	: m_position(position), m_width(width), m_height(height)
{
}

Vector2 Camera::GetPosition() const
{
	return Vector2(m_position.x - m_width / 2, m_position.y - m_height / 2);
}

Vector2 Camera::ToCameraView(const Vector2& position) const
{
	return position - GetPosition();
}

void Camera::SetPosition(const Vector2& position)
{
	m_position = position;
}
