#pragma once
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

	virtual void Update(double deltaTime)
	{
		
	}

protected:
	GameObject* const m_owner;
};
