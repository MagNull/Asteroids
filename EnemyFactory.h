#pragma once
#include "GameObjectFactory.h"
#include "PhysicComponent.h"
#include "RenderComponent.h"

enum EnemyType
{
	Asteroid,
	BigAsteroid,
	UFO
};

class EnemyFactory
{
public:
	EnemyFactory(GameObjectFactory& gameObjectFactory, Texture& asteroidTexture,
	             Texture& ufoTexture)
		: m_GameObjectFactory(&gameObjectFactory), m_AsteroidTexture(&asteroidTexture),
		  m_UfoTexture(&ufoTexture)
	{
	}

	GameObject& Create(EnemyType type);

private:
	GameObjectFactory* m_GameObjectFactory;
	Texture* m_AsteroidTexture;
	Texture* m_UfoTexture;
};
