#pragma once
#include "AsteroidComponent.h"
#include "GameObject.h"
#include "ObjectPool.h"
#include "Random.h"

class AsteroidFactory;

class AsteroidSpawnerComponent : public Component
{
public:
	AsteroidSpawnerComponent(GameObject& owner, ObjectPool<AsteroidComponent>& asteroidPool, double spawnInterval,
	                      double asteroidMinSpeed, double asteroidMaxSpeed, double minAngleVelocity, double maxAngleVelocity);

	void Update(double deltaTime) override;

private:
	void SpawnAsteroid();
	Random m_Random;
	ObjectPool<AsteroidComponent>* m_AsteroidPool;
	double m_AsteroidMinVelocity;
	double m_AsteroidMaxVelocity;
	double m_AsteroidMinAngleVelocity;
	double m_AsteroidMaxAngleVelocity;
	double m_SpawnInterval;
};
