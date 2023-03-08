#include "Game.h"
#include "Screen.h"

GameObject* go;

Game::Game()
{
	m_IsRun = false;
	m_Gfx = std::make_unique<Graphics>(Screen::WIDTH, Screen::HEIGHT);
	m_World = std::make_unique<World>();
	m_gameObjectFactory = std::make_unique<GameObjectFactory>(*m_World);
}

void Game::Init()
{
	m_Gfx->Init();
	go = &m_gameObjectFactory->Create(
		"Ship", &m_Gfx->CreateTexture("D:/VSProjects/SDL_Learn/SPRITES/PLAYER.png"));
}

void Game::Run()
{
	m_IsRun = true;
	auto transform = &go->GetTransform();
	transform->Scale(Vector2(10, 10));
	while (m_IsRun)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				m_IsRun = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_SPACE:
					{
						transform->Move(transform->GetForward() * 3);
						if (transform->GetPosition().y < -Screen::HEIGHT / 2)
							transform->SetPosition(Vector2(transform->GetPosition().x, Screen::HEIGHT / 2));
						else if (transform->GetPosition().y > Screen::HEIGHT / 2)
							transform->SetPosition(Vector2(transform->GetPosition().x, -Screen::HEIGHT / 2));

						break;
					}
					case SDLK_r:
					{
						transform->Rotate(5);
						break;
					}
				}
			}
		}
		Update();
	}
	Shutdown();
}

void Game::Update()
{
	m_Gfx->Render(m_World->GetGameObjects());
}

void Game::Shutdown()
{
	m_Gfx->Shutdown();
	SDL_Quit();
}
