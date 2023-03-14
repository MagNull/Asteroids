#include "RenderComponent.h"

RenderComponent::~RenderComponent()
{
	m_Texture->Free();
	m_Texture = nullptr;
}
