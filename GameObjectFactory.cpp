#include "GameObjectFactory.h"

#include "ShipComponent.h"

GameObjectFactory::~GameObjectFactory()
{
	m_World = nullptr;
}

GameObject& GameObjectFactory::Create(std::string name, Vector2 pos) const
{
	GameObject* newGO = new GameObject(name, pos);
	m_World->AddGameObject(newGO);

	return *newGO;
}
