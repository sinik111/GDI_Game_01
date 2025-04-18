#pragma once

#include "Singleton.h"

class Object;
class Collider;
class Vector2;
struct AABB;
struct Circle;
struct UIRect;

class CollisionManager
	: public Singleton<CollisionManager>
{
	friend class Singleton<CollisionManager>;

private:
	std::unordered_map<std::wstring, std::vector<Object*>> m_CandidateGroups;

private:
	CollisionManager() = default;
	~CollisionManager() = default;

public:
	void ClearCandidates();
	void ResisterGameObject(const std::wstring& group, Object* object);

public:
	//void AABBCollisionPlayerAndBoxes();

public:
	static bool CheckUIRectContainPosition(const UIRect& ui_rect, const Vector2& position);

private:
	bool IsAABBCollide(const AABB& aabb1, const AABB& aabb2);
	bool IsCircleCollide(const Circle& circle1, const Circle& circle2);
};