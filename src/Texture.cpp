#include "Texture.h"

#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>


Texture::Texture() : m_texture(nullptr), m_width(0), m_height(0)
{
}

Texture::Texture(const Texture& texture)
{
	m_texture = texture.m_texture;
	m_width = texture.m_width;
	m_height = texture.m_height;
}

Texture::Texture(std::string textureText, std::string fontPath, SDL_Color color, SDL_Renderer* renderer)
{
	LoadFromText(textureText, fontPath, renderer, color);
}

Texture::Texture(std::string path, SDL_Renderer* renderer)
{
	LoadFromImage(path, renderer);
}

Texture::~Texture()
{
	Free();
}

void Texture::Render(SDL_FRect drawRect,
                     SDL_Renderer* renderer, SDL_Rect* clip, double angle, SDL_FPoint* center,
                     SDL_RendererFlip flip) const
{
	drawRect.w *= m_width;
	drawRect.h *= m_height;
	if (clip != nullptr)
	{
		drawRect.w = clip->w;
		drawRect.h = clip->h;
	}

	SDL_RenderCopyExF(renderer, m_texture, clip, &drawRect, angle, center, flip);
}


void Texture::LoadFromImage(std::string path, SDL_Renderer* renderer)
{
	Free();
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cout << "Failed to load surface with " << SDL_GetError();
		throw std::exception{};
	}
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));

	m_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	m_width = loadedSurface->w;
	m_height = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);
}

void Texture::LoadFromText(std::string text, std::string fontPath, SDL_Renderer* renderer, SDL_Color color)
{
	Free();
	SDL_Surface* loadedSurface = TTF_RenderText_Solid(TTF_OpenFont(fontPath.c_str(), 32), text.c_str(), color);
	if (loadedSurface == nullptr)
	{
		std::cout << "Failed to load surface with " << SDL_GetError();
		throw std::exception{};
	}

	m_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	m_width = loadedSurface->w;
	m_height = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);
}

void Texture::Free()
{
	if (m_texture == nullptr)
		return;
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
	m_width = 0;
	m_height = 0;
}

void Texture::SetColor(int8_t r, int8_t g, int8_t b) const
{
	SDL_SetTextureColorMod(m_texture, r, g, b);
}

void Texture::SetAlpha(int8_t a) const
{
	SDL_SetTextureAlphaMod(m_texture, a);
}

void Texture::SetBlendMode(SDL_BlendMode mode) const
{
	SDL_SetTextureBlendMode(m_texture, mode);
}
