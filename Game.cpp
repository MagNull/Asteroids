#include "Game.h"

#include "EnemySpawnerComponent.h"
#include "RenderComponent.h"
#include "Screen.h"
#include "ShipComponent.h"

Game::Game()
{
	m_IsRun = false;
	m_Gfx = std::make_unique<Graphics>(Screen::WIDTH, Screen::HEIGHT);
	m_Physx = std::make_unique<Physics>();
	m_Timer = Timer();
	m_World = std::make_unique<World>();
	m_gameObjectFactory = std::make_unique<GameObjectFactory>(*m_World);
}

void Game::Init()
{
	m_Gfx->Init();
	CreateObjects();
	ShipComponent* shipComponent;
	m_ship->GetComponent<ShipComponent>(&shipComponent);
	m_Input = std::make_unique<ShipInput>(*shipComponent);
}

void Game::CreateObjects()
{
	m_ship = std::unique_ptr<GameObject>{&m_gameObjectFactory->Create("Ship")};
	auto shipComponent = new ShipComponent(*m_ship, 50, 60);
	m_ship->AddComponent(shipComponent);
	m_ship->AddComponent(
		new RenderComponent(*m_ship, m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/PLAYER.png")));
	m_ship->GetTransform().SetSize(Vector2::one * 2);

	m_enemyFactory = std::make_unique<EnemyFactory>(
		*m_gameObjectFactory,
		m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/ROCK.png"),
		m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/PLAYER.png")
	);

	m_enemySpawner = std::unique_ptr<GameObject>{&m_gameObjectFactory->Create("EnemySpawner")};
	m_enemySpawner->AddComponent(
		new EnemySpawnerComponent(*m_enemySpawner, *m_enemyFactory, 2, 20, 50, -30, 30));
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
	static double deltaTime;
	deltaTime = (double)m_Timer.GetTickSinceStart() / 1000;
	m_Timer.Start();

	m_Input->Update(deltaTime);
	m_Physx->Update(m_World->GetGameObjects(), deltaTime);

	for (auto gameObject : m_World->GetGameObjects())
	{
		gameObject->Update(deltaTime);
	}

	m_Gfx->Render(m_World->GetGameObjects());

	m_Timer.Stop();
}

void Game::Shutdown()
{
	m_Timer.Stop();
	m_Gfx->Shutdown();
	SDL_Quit();
}
