#include "GameObject.h"

GameObject::GameObject(std::string name, Vector2 pos, RenderData renderData)
{
	m_name = name;
	m_transform = Transform{pos};
	m_renderData = renderData;
}

GameObject::~GameObject()
{
	m_renderData.Texture->Free();
	m_renderData.Texture = nullptr;
}
