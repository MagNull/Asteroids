#include "Game.h"
#include "Screen.h"
#include "Ship.h"

Game::Game()
{
	m_IsRun = false;
	m_Gfx = std::make_unique<Graphics>(Screen::WIDTH, Screen::HEIGHT);
	m_World = std::make_unique<World>();
	m_gameObjectFactory = std::make_unique<GameObjectFactory>(*m_World);
	m_ship = std::make_unique<GameObject>(m_gameObjectFactory->Create(
		"Ship", &m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/PLAYER.png")));
	auto shipComponent = new Ship(*m_ship, 1, 1);
	m_Input = std::make_unique<ShipInput>(*shipComponent);
}

void Game::Init()
{
	m_Gfx->Init();
}

void Game::Run()
{
	m_IsRun = true;
	m_Input->Run();
	while (m_IsRun)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				m_IsRun = false;
		}
		Update();
	}
	Shutdown();
}

void Game::Update()
{
	m_Input->Update();
	m_Gfx->Render(m_World->GetGameObjects());
}

void Game::Shutdown()
{
	m_Gfx->Shutdown();
	SDL_Quit();
}
