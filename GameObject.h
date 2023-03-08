#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Texture.h"
#include "Transform.h"

struct RenderData
{
	Texture* Texture;
	int DrawOrder;
};

class GameObject
{
public:
	GameObject(std::string name, Vector2 pos, RenderData renderData);
	~GameObject();

	Transform& GetTransform()
	{
		return m_transform;
	}

	const RenderData& GetRenderData() const
	{
		return m_renderData;
	}

	std::string GetName() const
	{
		return m_name;
	}

	void AddComponent(Component* component);

	template <typename ComponentT>
	void AddComponent()
	{
		ComponentT* component = new ComponentT(*this);
		m_components.push_back(component);
	}

	template <typename ComponentT>
	bool GetComponent(ComponentT* out) const
	{
		for (Component* component : m_components)
		{
			ComponentT* castedComponent = dynamic_cast<ComponentT*>(component);
			if (castedComponent != nullptr)
			{
				*out = *castedComponent;
				return true;
			}
		}

		return false;
	}

private:
	std::vector<Component*> m_components;
	std::string m_name;
	Transform m_transform;
	RenderData m_renderData;
};
