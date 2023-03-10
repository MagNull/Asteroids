#pragma once
#include <memory>

#include "EnemyFactory.h"
#include "World.h"
#include "ShipInput.h"
#include "Physics.h"
#include "Graphics.h"
#include "GameObjectFactory.h"
#include "Timer.h"

class Game
{
public:
	Game();
	Game(const Game&) = delete;
	Game(const Game&&) = delete;
	Game& operator =(Game&) = delete;

	void Init();
	void Run();
	void Update();
	void Shutdown();

private:
	void CreateObjects();

	bool m_IsRun;
	Timer m_Timer;
	std::unique_ptr<GameObject> m_ship;
	std::unique_ptr<EnemyFactory> m_enemyFactory;
	std::unique_ptr<GameObject> m_enemySpawner;
	std::unique_ptr<GameObjectFactory> m_gameObjectFactory;
	std::unique_ptr<World> m_World;
	std::unique_ptr<Graphics> m_Gfx;
	std::unique_ptr<Physics> m_Physx;
	std::unique_ptr<ShipInput> m_Input;
};
