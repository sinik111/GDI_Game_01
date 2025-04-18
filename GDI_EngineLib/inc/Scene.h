#pragma once

#include "ResultCode.h"

class Object;

class Scene
{
private:
	std::vector<Object*> m_Objects;

public:
	Scene() = default;
	virtual ~Scene();

	template<typename T>
	T* CreateObject()
	{
		T* pObject = new T();
		m_Objects.push_back(pObject);

		return pObject;
	}

public:
	virtual ResultCode Load() = 0;
	virtual ResultCode Enter() = 0;
	virtual void Exit();
	virtual void Unload() = 0;

public:
	virtual void Update();
	virtual void Render();

private:
	void Clear();
};