#pragma once
#include "BulletComponent.h"
#include "Component.h"
#include "ObjectPool.h"
#include "Timer.h"

class ShipShooterComponent : public Component
{
public:
	ShipShooterComponent(GameObject& owner, ObjectPool<BulletComponent>& bulletPool, double bulletSpeed, double shootDelay) : Component(owner),
		m_BulletPool(&bulletPool), m_BulletSpeed(bulletSpeed), m_ShootDelay(shootDelay)
	{
	}

	void Shoot();
private:
	ObjectPool<BulletComponent>* m_BulletPool;
	double m_BulletSpeed;
	double m_ShootDelay;
	Timer m_Timer;
};
