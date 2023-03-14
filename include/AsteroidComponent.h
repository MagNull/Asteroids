#pragma once
#include "DamageDealerComponent.h"
#include "GameObject.h"
#include "PhysicComponent.h"
#include "PoolObject.h"

class AsteroidComponent : public DamageDealerComponent, public IDamageable, public PoolObject<AsteroidComponent>
{
public:
	AsteroidComponent(GameObject& go) : DamageDealerComponent(go, 1)
	{
		m_Owner->AddComponent<PhysicComponent>();
	}

	AsteroidComponent(GameObject& go, int damage) : DamageDealerComponent(go, damage)
	{
	}

	void Enable() override;

	void Disable() override;

	void OnCollided(GameObject* other) override;

	void TakeDamage(int damage) override;
};
