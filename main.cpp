#include <iostream>
#include "Game.h"

bool Init();
void Close();


int main(int argc, char* args[])
{
	Game game{};
	game.Init();
	game.Run();
	
	return 0;
}

//bool Init()
//{
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		std::cout << "Failed to initialize SDL video with " << SDL_GetError();
//		return false;
//	}
//	pWindow = SDL_CreateWindow("Window",
//	                           SDL_WINDOWPOS_UNDEFINED,
//	                           SDL_WINDOWPOS_UNDEFINED,
//	                           SCREEN_WIDTH,
//	                           SCREEN_HEIGHT,
//	                           SDL_WINDOW_SHOWN);
//	if (pWindow == nullptr)
//	{
//		std::cout << "Failed to create window with " << SDL_GetError();
//		return false;
//	}
//
//	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
//	if (pRenderer == nullptr)
//	{
//		std::cout << "Failed to create renderer with " << SDL_GetError();
//		return false;
//	}
//	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 0);
//
//	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)))
//	{
//		std::cout << "Failed to initialize SDL image with " << SDL_GetError();
//		return false;
//	}
//
//	if (TTF_Init() == -1)
//	{
//		std::cout << "Failed to initialize SDL TTF with " << SDL_GetError();
//		return false;
//	}
//
//	return true;
//}
