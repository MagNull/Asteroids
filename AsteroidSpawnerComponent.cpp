#include "AsteroidSpawnerComponent.h"

#include "AsteroidFactory.h"
#include "Screen.h"

AsteroidSpawnerComponent::AsteroidSpawnerComponent(GameObject& owner, ObjectPool<AsteroidComponent>& enemyFactory,
                                                   double spawnInterval,
                                                   double asteroidMinSpeed, double asteroidMaxSpeed,
                                                   double minAngleVelocity,
                                                   double maxAngleVelocity): Component(
	owner)
{
	m_AsteroidPool = &enemyFactory;
	m_SpawnInterval = spawnInterval;
	m_AsteroidMinVelocity = asteroidMinSpeed;
	m_AsteroidMaxVelocity = asteroidMaxSpeed;
	m_AsteroidMinAngleVelocity = minAngleVelocity;
	m_AsteroidMaxAngleVelocity = maxAngleVelocity;
	m_Random = Random();
}

void AsteroidSpawnerComponent::Update(double deltaTime)
{
	static double timeSinceLastSpawn = m_SpawnInterval;
	if (timeSinceLastSpawn >= m_SpawnInterval)
	{
		SpawnAsteroid();
		timeSinceLastSpawn = 0;
	}
	else
	{
		timeSinceLastSpawn += deltaTime;
	}
}

void AsteroidSpawnerComponent::SpawnAsteroid()
{
	GameObject* astroid = &m_AsteroidPool->GetObject().GetGameObject();
	PhysicComponent* physicComponent;
	if (!astroid->GetComponent<PhysicComponent>(&physicComponent))
		return;

	physicComponent->SetVelocity(
		Vector2::GetRandomUnitVector() * m_Random.GetRandomDoubleInRange(m_AsteroidMinVelocity, m_AsteroidMaxVelocity));

	physicComponent->
		SetAnlgeVelocity(m_Random.GetRandomDoubleInRange(m_AsteroidMinAngleVelocity, m_AsteroidMaxAngleVelocity));

	astroid->GetTransform().SetPosition(Vector2(-Screen::WIDTH / 2, Screen::HEIGHT / 2));
}
