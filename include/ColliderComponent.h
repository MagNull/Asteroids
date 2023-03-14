#pragma once
#include "Component.h"

class ColliderComponent : public Component
{
public:
	ColliderComponent(GameObject& owner) : Component(owner), m_width(0), m_height(0)
	{
	}

	ColliderComponent(GameObject& owner, int width, int height) : Component(owner), m_width(width), m_height(height)
	{
	}

	void OnCollided(GameObject* other) override;

	int GetWidth() const
	{
		return m_width;
	}

	int GetHeight() const
	{
		return m_height;
	}

private:
	int m_width;
	int m_height;
};
