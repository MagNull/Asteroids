#include "GameObject.h"

GameObject::~GameObject()
{
	for (auto component : m_Components)
	{
		delete component;
	}
}

void GameObject::Update(double deltaTime)
{
	if(!IsActive())
		return;

	for (auto component : m_Components)
	{
		component->Update(deltaTime);
	}
}

void GameObject::AddComponent(Component* component)
{
	m_Components.push_back(component);
}
