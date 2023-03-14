#include "AsteroidComponent.h"

#include "BulletComponent.h"
#include "ShipComponent.h"

void AsteroidComponent::OnCollided(GameObject* other)
{
	ShipComponent* ship;
	if (!other->GetComponent<ShipComponent>(&ship))
		return;

	Damage(ship);
}

void AsteroidComponent::TakeDamage(int damage)
{
	PhysicComponent* p;
	m_Owner->GetComponent(&p);
	p->SetVelocity(Vector2::zero);
	OnDestroyed();
}

template <>
void PoolObject<AsteroidComponent>::Enable()
{
	Enable();
}

template <>
void PoolObject<AsteroidComponent>::Disable()
{
	Disable();
}

void AsteroidComponent::Enable()
{
	m_Owner->SetActive(true);
}

void AsteroidComponent::Disable()
{
	m_Owner->SetActive(false);
}
