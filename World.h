#pragma once
#include <vector>
#include "GameObject.h"

class World
{
public:
	World();
	World(const World&) = delete;
	~World();

	void AddGameObject(GameObject* gameObject);
	void DestroyGameObject(GameObject* gameObject);

	const std::vector<GameObject*> GetGameObjects() const
	{
		return m_gameObjects;
	}

private:
	std::vector<GameObject*> m_gameObjects;
};
