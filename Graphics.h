#pragma once
#include <vector>
#include <SDL.h>

#include "GameObject.h"
#include "Texture.h"

class Graphics
{
public:
	Graphics(int width, int height);
	~Graphics();

	void Init();
	void Render(std::vector<GameObject*> gameObjects);
	Texture& CreateTexture(std::string path) const;
	void Shutdown() const;

private:
	int m_width;
	int m_height;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};
