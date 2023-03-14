#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Transform.h"

class GameObject final
{
	friend class GameObjectFactory;

public:
	~GameObject();

	Transform& GetTransform()
	{
		return m_Transform;
	}

	std::string GetName() const
	{
		return m_Name;
	}

	void SetActive(bool value)
	{
		m_isActive = value;
	}

	bool IsActive() const
	{
		return m_isActive;
	}

	void Update(double deltaTime);

	void AddComponent(Component* component);

	std::vector<Component*> GetComponents() const
	{
		return m_Components;
	}

	template <typename ComponentT>
	void AddComponent()
	{
		ComponentT* component = new ComponentT(*this);
		m_Components.push_back(component);
	}

	template <typename ComponentT>
	bool GetComponent(ComponentT** out) const
	{
		for (Component* component : m_Components)
		{
			ComponentT* castedComponent = dynamic_cast<ComponentT*>(component);
			if (castedComponent != nullptr)
			{
				*out = castedComponent;
				return true;
			}
		}

		return false;
	}
	template <typename ComponentT>
	ComponentT* GetComponent() const
	{
		for (Component* component : m_Components)
		{
			ComponentT* castedComponent = dynamic_cast<ComponentT*>(component);
			if (castedComponent != nullptr)
			{
				return castedComponent;
			}
		}

		return nullptr;
	}

private:
	GameObject(std::string name, Vector2 pos = Vector2::zero) : m_Name(name), m_Transform(Transform{pos})
	{
	}

	GameObject() : m_Name(""), m_Transform(Transform{Vector2::zero})
	{
	}

	std::vector<Component*> m_Components;
	std::string m_Name;
	Transform m_Transform;
	bool m_isActive = true;
};
