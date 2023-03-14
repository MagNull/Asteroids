#include "Graphics.h"

#include <algorithm>
#include <iostream>
#include <SDL_image.h>

#include "RenderComponent.h"
#include "Screen.h"
#include "Texture.h"


Graphics::Graphics(int width, int height) : m_width(width), m_height(height)
{
}


void Graphics::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		throw std::exception{SDL_GetError()};
	}
	m_Window = SDL_CreateWindow("Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	                            m_width, m_height, SDL_WINDOW_SHOWN);

	if (m_Window == nullptr)
	{
		throw std::exception{SDL_GetError()};
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

	if (m_Renderer == nullptr)
	{
		throw std::exception{SDL_GetError()};
	}
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);

	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)))
	{
		throw std::exception{SDL_GetError()};
	}
}

void Graphics::Shutdown() const
{
	SDL_RenderClear(m_Renderer);

	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
}

Graphics::~Graphics()
{
	m_Renderer = nullptr;
	m_Window = nullptr;
}

void Graphics::Render(std::vector<GameObject*> gameObjects)
{
	SDL_RenderClear(m_Renderer);
	std::sort(gameObjects.begin(), gameObjects.end(), [](GameObject* one, GameObject* second)
	{
		RenderComponent* render1;
		if(one->GetComponent<RenderComponent>(&render1))
			return false;

		RenderComponent* render2;
		if(second->GetComponent<RenderComponent>(&render2))
			return false;

		return render1->GetDrawOrder() > render2->GetDrawOrder();
	});
	for (GameObject* gameObject : gameObjects)
	{
		if (!gameObject->IsActive())
			continue;

		RenderComponent* renderComp = nullptr;
		if (!gameObject->GetComponent<RenderComponent>(&renderComp))
			continue;

		auto transform = gameObject->GetTransform();

		Vector2 fromWorldToScreenPos = Screen::ConvertToScreenPos(transform.GetPosition());
		auto drawRect = transform.GetRect();
		drawRect.x = fromWorldToScreenPos.x;
		drawRect.y = fromWorldToScreenPos.y;

		renderComp->GetTexture().Render(drawRect,
		                                m_Renderer, nullptr, transform.GetRotation(), nullptr,
		                                SDL_FLIP_NONE);
	}
	SDL_RenderPresent(m_Renderer);
}

Texture& Graphics::CreateTexture(std::string path) const
{
	return *new Texture(path, m_Renderer);
}

void Graphics::Clear() const
{
	SDL_RenderClear(m_Renderer);
}
