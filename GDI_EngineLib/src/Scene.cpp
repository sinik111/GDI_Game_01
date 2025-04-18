#include "pch.h"
#include "Scene.h"

#include "Object.h"

Scene::~Scene()
{
	Clear();
}

void Scene::Exit()
{
	Clear();
}

void Scene::Update()
{
	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		(*iter)->Update();

		if ((*iter)->IsDestroyed())
		{
			delete (*iter);

			iter = m_Objects.erase(iter);

			continue;
		}

		++iter;
	}
}

void Scene::Render()
{
	for (auto& object : m_Objects)
	{
		object->Render();
	}
}

void Scene::Clear()
{
	for (auto& object : m_Objects)
	{
		delete object;
	}

	m_Objects.clear();
}
