#pragma once
class GameObject;

class Component
{
public:
	Component(GameObject& owner) : m_Owner(&owner)
	{
	}

	GameObject& GetGameObject()
	{
		return *m_Owner;
	}

	virtual void Update(double deltaTime)
	{
		
	}

	virtual void OnCollided(GameObject* other)
	{
		
	}

protected:
	GameObject* const m_Owner;
};
