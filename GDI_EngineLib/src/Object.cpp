#include "pch.h"
#include "Object.h"

Object::Object()
	: m_IsDestroyed(false)
{

}

void Object::Destroy()
{
	m_IsDestroyed = true;
}

const Collider& Object::GetCollider()
{
	return m_Collider;
}

bool Object::IsDestroyed()
{
	return m_IsDestroyed;
}

void Object::Collide(Object& object, const std::wstring& groupName)
{

}