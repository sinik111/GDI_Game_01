#pragma once

#include "Vector2.h"

struct Circle
{
	Vector2 position;
	Vector2 offset;
	float radius;

	Circle();
};

struct AABB
{
	Vector2 position;
	Vector2 offset;
	float width;
	float height;

	AABB();
};

struct UIRect
{
	Vector2 position;
	float width;
	float height;

	UIRect();
};

class Collider
{
private:
	Circle m_circle;
	AABB m_box;
	UIRect m_ui_rect;

public:
	void SetColliderInfo(const Vector2& position, const Vector2& offset, float radius, float width, float height);

	Circle GetCircleCollider();
	AABB GetAABBCollider();
	UIRect GetUIRectCollider();

	void UpdateCollider(const Vector2& position);
};
