#pragma once
#include "GameObject.h"
#include "Random.h"

class EnemyFactory;

class EnemySpawnerComponent : public Component
{
public:
	EnemySpawnerComponent(GameObject& owner, EnemyFactory& enemyFactory, double spawnInterval,
	                      double enemyMinSpeed, double enemyMaxSpeed, double minAngleVelocity, double maxAngleVelocity);

	void Update(double deltaTime) override;

private:
	void SpawnEnemy();
	Random m_Random;
	EnemyFactory* m_EnemyFactory;
	double m_EnemyMinVelocity;
	double m_EnemyMaxVelocity;
	double m_EnemyMinAngleVelocity;
	double m_EnemyMaxAngleVelocity;
	double m_SpawnInterval;
};
