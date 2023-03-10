#include "EnemyFactory.h"

GameObject& EnemyFactory::Create(EnemyType type)
{
	switch (type)
	{
		case Asteroid:
		{
			GameObject* asteroid = &m_GameObjectFactory->Create("Asteroid");
			asteroid->AddComponent<PhysicComponent>();
			auto texture = new Texture(*m_AsteroidTexture);
			asteroid->AddComponent(new RenderComponent(*asteroid, *texture));
			return *asteroid;
		}
	}
}
