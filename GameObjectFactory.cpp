#include "GameObjectFactory.h"

#include "Ship.h"

GameObjectFactory::~GameObjectFactory()
{
	m_World = nullptr;
}

GameObject& GameObjectFactory::Create(std::string name, Texture* texture, Vector2 pos)
{
	GameObject* newGO = new GameObject(name, pos, RenderData{texture, 0});
	m_World->AddGameObject(newGO);

	return *newGO;
}
