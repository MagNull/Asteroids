#pragma once
#include "GameObject.h"

class GameObject;

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

protected:
	GameObject* const m_owner;
};
