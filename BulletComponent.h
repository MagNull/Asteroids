#pragma once
#include "DamageDealerComponent.h"
#include "GameObject.h"
#include "PoolObject.h"

class BulletComponent : public DamageDealerComponent, public PoolObject<BulletComponent>
{
public:
	BulletComponent(GameObject& owner, int damage) : DamageDealerComponent(owner, damage)
	{
	}

	void Update(double deltaTime) override;

	bool CheckScreenBounds() const;

	void OnCollided(GameObject* other) override;

	void Enable() override;

	void Disable() override;
};
