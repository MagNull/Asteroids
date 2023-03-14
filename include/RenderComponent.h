#pragma once
#include "Component.h"
#include "Texture.h"

class RenderComponent : public Component
{
public:
	RenderComponent(GameObject& gameObject) : Component(gameObject)
	{
	}

	RenderComponent(GameObject& gameObject, Texture& texture, int drawOrder = 0)
		: Component(gameObject)
		  , m_Texture(&texture)
		  , m_drawOrder(drawOrder)
	{
	}

	~RenderComponent();

	Texture& GetTexture() const
	{
		return *m_Texture;
	}

	int GetDrawOrder() const
	{
		return m_drawOrder;
	}

private:
	Texture* m_Texture;
	int m_drawOrder;
};
