#include "BulletFactory.h"

#include "ColliderComponent.h"
#include "PhysicComponent.h"
#include "RenderComponent.h"

GameObject& BulletFactory::Create()
{
	GameObject* bulletObject = &m_GameObjectFactory->Create("Bullet");
	auto bulletComponent = new BulletComponent(*bulletObject, m_BulletDamage);
	bulletObject->AddComponent(bulletComponent);
	auto texture = new Texture(*m_BulletTexture);
	bulletObject->AddComponent(new RenderComponent(*bulletObject, *texture, 0));
	bulletObject->AddComponent(new ColliderComponent(*bulletObject, texture->GetWidth(), texture->GetHeight()));
	bulletObject->AddComponent(new PhysicComponent(*bulletObject));

	return *bulletObject;
}
