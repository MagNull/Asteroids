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

World::~World()
{
	for (auto object : m_gameObjects)
	{
		delete object;
	}
}
