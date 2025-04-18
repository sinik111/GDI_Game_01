#include "pch.h"
#include "CollisionManager.h"

#include "Object.h"
#include "Collider.h"
#include "Vector2.h"

void CollisionManager::ClearCandidates()
{
	m_CandidateGroups.clear();
}

void CollisionManager::ResisterGameObject(const std::wstring& group, Object* object)
{
	m_CandidateGroups[group].push_back(object);
}

//void CollisionManager::AABBCollisionPlayerAndBoxes()
//{
//	auto player_iter = m_CandidateGroups[(int)CandidateType::Player].Begin();
//	auto boxes_iter = m_CandidateGroups[(int)CandidateType::Box].Begin();
//	while (!player_iter.IsEnd())
//	{
//		AABB player_collider = (*player_iter)->GetCollider().GetAABBCollider();
//
//		while (!boxes_iter.IsEnd())
//		{
//			AABB box_collider = (*boxes_iter)->GetCollider().GetAABBCollider();
//
//			if (IsAABBCollide(player_collider, box_collider))
//			{
//				(*boxes_iter)->Destroy();
//			}
//
//			++boxes_iter;
//		}
//
//		++player_iter;
//	}
//}

bool CollisionManager::CheckUIRectContainPosition(const UIRect& ui_rect, const Vector2& position)
{
	return !(ui_rect.position.x > position.x || ui_rect.position.y > position.y ||
		ui_rect.position.x + ui_rect.width < position.x ||
		ui_rect.position.y + ui_rect.height < position.y);
}

bool CollisionManager::IsAABBCollide(const AABB& aabb1, const AABB& aabb2)
{
	return !(aabb1.position.x > aabb2.position.x + aabb2.width ||
		aabb1.position.x + aabb1.width < aabb2.position.x ||
		aabb1.position.y > aabb2.position.y + aabb2.height ||
		aabb1.position.y + aabb1.height < aabb2.position.y);
}

bool CollisionManager::IsCircleCollide(const Circle& circle1, const Circle& circle2)
{
	return Vector2::SquareDistance(circle1.position, circle2.position) <=
		(circle1.radius + circle2.radius) * (circle1.radius + circle2.radius);
}
