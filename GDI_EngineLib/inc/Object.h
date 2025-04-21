#pragma once

#include "ResultCode.h"
#include "Vector2.h"
#include "Collider.h"

class Object
{
protected:
	Vector2 m_Position;
	Collider m_Collider;
	bool m_IsDestroyed;

public:
	Object();
	virtual ~Object() = default;

public:
	virtual ResultCode Initialize() = 0;
	virtual void Destroy();

public:
	virtual void Update() = 0;
	virtual void Render() = 0;

public:
	const Collider& GetCollider();
	bool IsDestroyed();
	virtual void Collide(Object& object, const std::wstring& groupName);
};