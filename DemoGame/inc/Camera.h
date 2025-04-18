#pragma once

#include "Vector2.h"

namespace Gdiplus
{
	class Rect;
}

class Camera
{
private:
	Vector2 m_position;
	int m_width;
	int m_height;

public:
	Camera(const Vector2& position, int width, int height);
	~Camera() = default;

public:
	Vector2 GetPosition() const;
	Vector2 ToCameraView(const Vector2& position) const;
	void SetPosition(const Vector2& position);
};