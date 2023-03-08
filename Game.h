#pragma once
#include <memory>

#include "World.h"
#include "ShipInput.h"
#include "Physics.h"
#include "Graphics.h"
#include "GameObjectFactory.h"

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
	bool m_IsRun;
	std::unique_ptr<GameObject> m_ship;
	std::unique_ptr<GameObjectFactory> m_gameObjectFactory;
	std::unique_ptr<World> m_World;
	std::unique_ptr<Graphics> m_Gfx;
	std::unique_ptr<Physics> m_Physx;
	std::unique_ptr<ShipInput> m_Input;
};
