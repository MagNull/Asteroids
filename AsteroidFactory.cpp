#include "AsteroidFactory.h"

#include "AsteroidComponent.h"
#include "ColliderComponent.h"

GameObject& AsteroidFactory::Create()
{
	GameObject* asteroid = &m_GameObjectFactory->Create("Asteroid");
	asteroid->AddComponent<AsteroidComponent>();
	auto texture = new Texture(*m_AsteroidTexture);
	asteroid->AddComponent(new RenderComponent(*asteroid, *texture, 1));
	asteroid->AddComponent(new ColliderComponent(*asteroid, texture->GetWidth(), texture->GetHeight()));
	return *asteroid;
}
