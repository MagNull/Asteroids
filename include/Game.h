#pragma once
#include <memory>

#include "BulletFactory.h"
#include "AsteroidFactory.h"
#include "World.h"
#include "ShipInput.h"
#include "Physics.h"
#include "Graphics.h"
#include "GameObjectFactory.h"
#include "Timer.h"

const double SHIP_ACCELERATION = 60;
const double SHIP_BRAKING = 20;
const int SHIP_ANGLE_SPEED = 180;
const int SHIP_HEALTH = 1;
const int BULLET_SPEED = 150;
const int BULLET_DAMAGE = 1;
const double SHOOT_DELAY = 0.5;

const int ASTEROID_HEALTH = 1;
const int ASTEROID_DAMAGE = 1;
const double ASTEROID_SPAWN_DELAY = 1;
const double ASTEROID_MIN_SPEED = 20;
const double ASTEROID_MAX_SPEED = 50;
const double ASTEROID_MIN_ANGLE_VELOCITY = -30;
const double ASTEROID_MAX_ANGLE_VELOCITY = 30;

class Game
{
public:
	Game();
	Game(const Game&) = delete;
	Game(const Game&&) = delete;
	Game& operator =(Game&) = delete;

	void Init();
	void CreateShip();
	void Run();
	void Update();
	void Restart();
	void Shutdown();

private:
	void CreateObjects();

	bool m_IsRun;
	Timer m_Timer;
	std::unique_ptr<GameObject> m_Ship;
	std::unique_ptr<AsteroidFactory> m_EnemyFactory;
	std::unique_ptr<BulletFactory> m_BulletFactory;
	std::unique_ptr<GameObject> m_AsteroidSpawner;
	std::unique_ptr<GameObjectFactory> m_GameObjectFactory;
	std::unique_ptr<World> m_World;
	std::unique_ptr<Graphics> m_Gfx;
	std::unique_ptr<Physics> m_Physx;
	std::unique_ptr<ShipInput> m_Input;
};
