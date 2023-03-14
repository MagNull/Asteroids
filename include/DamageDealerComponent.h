#pragma once
#include "Component.h"
#include "IDamageable.h"

class DamageDealerComponent : public Component
{
public:
	DamageDealerComponent(GameObject& go) : Component(go), m_Damage(0)
	{
	}

	DamageDealerComponent(GameObject& go, int damage) : Component(go), m_Damage(damage)
	{
	}

	void Damage(IDamageable* damageable);

private:
	int m_Damage;
};
