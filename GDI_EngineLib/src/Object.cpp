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

bool Object::IsDestroyed()
{
	return m_IsDestroyed;
}
