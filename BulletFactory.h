#pragma once
#include "BulletComponent.h"
#include "Texture.h"
#include "GameObjectFactory.h"

class BulletFactory
{
public:
	BulletFactory(GameObjectFactory& gameObjectFactory, Texture& bulletTexture, int bulletDamage) :
		m_GameObjectFactory(&gameObjectFactory), m_BulletTexture(&bulletTexture),
		m_BulletDamage(bulletDamage)
	{
	}

	GameObject& Create();

private:
	GameObjectFactory* m_GameObjectFactory;
	Texture* m_BulletTexture;
	int m_BulletDamage;
};
