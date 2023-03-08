#pragma once
#include <memory>
#include "GameObject.h"
#include "World.h"

class GameObjectFactory
{
public:
	GameObjectFactory(World& world) : m_World(&world)
	{
	}

	~GameObjectFactory();

	GameObject& Create(std::string name, Texture* texture, Vector2 pos = Vector2::zero);

private:
	World* m_World;
};
