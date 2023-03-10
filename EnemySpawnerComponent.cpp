#include "EnemySpawnerComponent.h"

#include "EnemyFactory.h"
#include "Screen.h"

EnemySpawnerComponent::EnemySpawnerComponent(GameObject& owner, EnemyFactory& enemyFactory, double spawnInterval,
                                             double enemyMinSpeed, double enemyMaxSpeed, double minAngleVelocity,
                                             double maxAngleVelocity): Component(owner)
{
	m_EnemyFactory = &enemyFactory;
	m_SpawnInterval = spawnInterval;
	m_EnemyMinVelocity = enemyMinSpeed;
	m_EnemyMaxVelocity = enemyMaxSpeed;
	m_EnemyMinAngleVelocity = minAngleVelocity;
	m_EnemyMaxAngleVelocity = maxAngleVelocity;
	m_Random = Random();
}

void EnemySpawnerComponent::Update(double deltaTime)
{
	static double timeSinceLastSpawn = 0;
	if (timeSinceLastSpawn >= m_SpawnInterval)
	{
		SpawnEnemy();
		timeSinceLastSpawn = 0;
	}
	else
	{
		timeSinceLastSpawn += deltaTime;
	}
}

void EnemySpawnerComponent::SpawnEnemy()
{
	GameObject* enemy = &m_EnemyFactory->Create(Asteroid);
	PhysicComponent* physicComponent;
	if (!enemy->GetComponent<PhysicComponent>(&physicComponent))
		return;

	physicComponent->SetVelocity(
		Vector2::GetRandomUnitVector() * m_Random.GetRandomDoubleInRange(m_EnemyMinVelocity, m_EnemyMaxVelocity));

	physicComponent->SetAnlgeVelocity(m_Random.GetRandomDoubleInRange(m_EnemyMinAngleVelocity, m_EnemyMaxAngleVelocity));

	enemy->GetTransform().SetPosition(Vector2(0, Screen::HEIGHT / 2));
}
