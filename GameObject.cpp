#include "GameObject.h"

#include "Screen.h"

GameObject::~GameObject()
{
	for (auto component : m_Components)
	{
		delete component;
	}
}

void GameObject::Update(double deltaTime)
{
	for (auto component : m_Components)
	{
		component->Update(deltaTime);
	}
	auto position = GetTransform().GetPosition();
	position = Vector2::Loop(position,
	                         Vector2(-Screen::WIDTH / 2, -Screen::HEIGHT / 2),
	                         Vector2(Screen::WIDTH / 2, Screen::HEIGHT / 2));
	GetTransform().SetPosition(position);
}

void GameObject::AddComponent(Component* component)
{
	m_Components.push_back(component);
}
