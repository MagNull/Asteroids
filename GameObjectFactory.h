#pragma once
#include "World.h"
#include "Vector2.h"

class GameObjectFactory
{
public:
	GameObjectFactory(World& world) : m_World(&world)
	{
	}

	~GameObjectFactory();

	GameObject& Create(std::string name, Vector2 pos = Vector2::zero) const;

private:
	World* m_World;
};
