#include "Game.h"

#include "AsteroidSpawnerComponent.h"
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
	m_GameObjectFactory = std::make_unique<GameObjectFactory>(*m_World);
	m_BulletFactory = std::make_unique<BulletFactory>(*m_GameObjectFactory,
	                                                  m_Gfx->CreateTexture(
		                                                  "D:/VSProjects/SDL_Learn/SPRITES/BULLET.png"), 1);
	m_EnemyFactory = std::make_unique<AsteroidFactory>(
		*m_GameObjectFactory,
		m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/ROCK.png"),
		m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/PLAYER.png")
	);
}

void Game::Init()
{
	m_Gfx->Init();

	m_BulletFactory = std::make_unique<BulletFactory>(*m_GameObjectFactory,
	                                                  m_Gfx->CreateTexture(
		                                                  "D:/VSProjects/SDL_Learn/SPRITES/BULLET.png"), 1);
	m_EnemyFactory = std::make_unique<AsteroidFactory>(
		*m_GameObjectFactory,
		m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/ROCK.png"),
		m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/PLAYER.png")
	);

	CreateObjects();
	ShipComponent* shipComponent;
	m_Ship->GetComponent<ShipComponent>(&shipComponent);

	ShipShooterComponent* shipShooter;
	m_Ship->GetComponent<ShipShooterComponent>(&shipShooter);

	m_Input = std::make_unique<ShipInput>();
	m_Input->SetShip(*shipComponent, *shipShooter);
}

void Game::CreateShip()
{
	m_Ship = std::unique_ptr<GameObject>{&m_GameObjectFactory->Create("Ship")};
	auto shipComponent =
		new ShipComponent(*m_Ship, SHIP_ACCELERATION, SHIP_BRAKING, SHIP_ANGLE_SPEED, SHIP_HEALTH, [this]
		{
			Restart();
		});
	m_Ship->AddComponent(shipComponent);
	auto shipRenderer =
		new RenderComponent(*m_Ship, m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/PLAYER.png"), 1);
	m_Ship->AddComponent(shipRenderer);

	m_Ship->GetTransform().SetSize(Vector2::one * 2);

	m_Ship->AddComponent(new ColliderComponent(*m_Ship, shipRenderer->GetTexture().GetWidth(),
	                                           shipRenderer->GetTexture().GetHeight()));;
	auto bulletPool = new ObjectPool<BulletComponent>([this]() -> BulletComponent&
	{
		return *m_BulletFactory->Create().GetComponent<BulletComponent>();
	}, 10);
	auto shipShooter = new ShipShooterComponent(*m_Ship, *bulletPool, BULLET_SPEED,
	                                            SHOOT_DELAY);
	m_Ship->AddComponent(shipShooter);
}

void Game::CreateObjects()
{
	CreateShip();

	m_AsteroidSpawner = std::unique_ptr<GameObject>{&m_GameObjectFactory->Create("EnemySpawner")};
	auto asteroidsPool = new ObjectPool<AsteroidComponent>([this]() -> AsteroidComponent&
	{
		return *m_EnemyFactory->Create().GetComponent<AsteroidComponent>();
	}, 10);
	m_AsteroidSpawner->AddComponent(
		new AsteroidSpawnerComponent(*m_AsteroidSpawner, *asteroidsPool,
		                             ASTEROID_SPAWN_DELAY, ASTEROID_MIN_SPEED, ASTEROID_MAX_SPEED,
		                             ASTEROID_MIN_ANGLE_VELOCITY, ASTEROID_MAX_ANGLE_VELOCITY));
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

void Game::Restart()
{
	m_IsRun = false;
	m_World->Clear();
	m_Gfx->Clear();
	m_Timer.Stop();

	CreateObjects();

	ShipComponent* shipComponent;
	m_Ship->GetComponent<ShipComponent>(&shipComponent);

	ShipShooterComponent* shipShooter;
	m_Ship->GetComponent<ShipShooterComponent>(&shipShooter);

	m_Input->SetShip(*shipComponent, *shipShooter);

	m_IsRun = true;
	m_Timer.Start();
}

void Game::Shutdown()
{
	m_Timer.Stop();
	m_World->Clear();
	m_Timer.Stop();
	m_Gfx->Shutdown();
	SDL_Quit();
}
