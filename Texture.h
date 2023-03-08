#pragma once
#include <SDL_render.h>
#include <string>

class Texture
{
public:
	Texture();
	Texture(std::string path, SDL_Renderer* renderer);
	Texture(std::string textureText, std::string fontPath, SDL_Color color, SDL_Renderer* renderer);
	~Texture();

	int Width() const
	{
		return m_width;
	}

	int Height() const
	{
		return m_height;
	}

	void Render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip,
                     double angle, SDL_Point* center, SDL_RendererFlip flip) const;

	void SetColor(int8_t r, int8_t g, int8_t b) const;

	void SetAlpha(int8_t a) const;
	void SetBlendMode(SDL_BlendMode mode) const;

	void Free();

	void LoadFromImage(std::string path, SDL_Renderer* renderer);
	void LoadFromText(std::string text, std::string fontPath, SDL_Renderer* renderer, SDL_Color color);

private:
	SDL_Texture* m_texture;
	int m_width;
	int m_height;
};