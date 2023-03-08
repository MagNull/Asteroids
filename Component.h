#pragma once
#include "GameObject.h"

class Component
{
public:
	Component(GameObject& owner) : m_owner(&owner)
	{
	}

	GameObject& GetGameObject()
	{
		return *m_owner;
	}

private:
	GameObject* const m_owner;
};
