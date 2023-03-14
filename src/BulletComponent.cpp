#include "BulletComponent.h"

#include "AsteroidComponent.h"
#include "Screen.h"

void BulletComponent::Update(double deltaTime)
{
	if (CheckScreenBounds())
		OnDestroyed();
}

bool BulletComponent::CheckScreenBounds() const
{
	const auto position = m_Owner->GetTransform().GetPosition();
	return position.x < -Screen::WIDTH / 2 + 1 || position.x > Screen::WIDTH / 2 - 1 ||
		position.y < -Screen::HEIGHT / 2 + 1 || position.y > Screen::HEIGHT / 2 - 1;
}

void BulletComponent::OnCollided(GameObject* other)
{
	AsteroidComponent* asteroid;
	if (!other->GetComponent(&asteroid))
		return;

	Damage(asteroid);
	OnDestroyed();
}

template <>
void PoolObject<BulletComponent>::Enable()
{
	Enable();
}

template <>
void PoolObject<BulletComponent>::Disable()
{
	Disable();
}


void BulletComponent::Enable()
{
	m_Owner->SetActive(true);
}

void BulletComponent::Disable()
{
	m_Owner->SetActive(false);
}
