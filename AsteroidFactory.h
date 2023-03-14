#pragma once
#include "GameObjectFactory.h"
#include "PhysicComponent.h"
#include "RenderComponent.h"


class AsteroidFactory
{
public:
	AsteroidFactory(GameObjectFactory& gameObjectFactory, Texture& asteroidTexture,
	             Texture& ufoTexture)
		: m_GameObjectFactory(&gameObjectFactory), m_AsteroidTexture(&asteroidTexture),
		  m_UfoTexture(&ufoTexture)
	{
	}

	GameObject& Create();

private:
	GameObjectFactory* m_GameObjectFactory;
	Texture* m_AsteroidTexture;
	Texture* m_UfoTexture;
};
