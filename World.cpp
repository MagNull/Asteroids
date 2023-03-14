#include "World.h"

World::World()
{
}

void World::AddGameObject(GameObject* gameObject)
{
	m_gameObjects.push_back(gameObject);
}

void World::DestroyGameObject(GameObject* gameObject)
{

}

void World::Clear()
{
	m_gameObjects.clear();
}

World::~World()
{
	for (auto object : m_gameObjects)
	{
		delete object;
	}
}
