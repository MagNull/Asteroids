#pragma once
#include <vector>

#include "ComponentPool.h"
#include "Entity.h"

class EntityPool
{
public:
	EntityPool(Components::ComponentPool& componentPool) : m_componentPool(&componentPool)
	{
		
	}

	~EntityPool();

	Entity* CreateEntity();

	/*template <typename ... Components>
	Entity* CreateEntity(int id)
	{
		Entity* entity = CreateEntity(id);
		for (auto component : {Components...})
		{
			m_componentPool->AddComponent<>()
		}

		return entity;
	}*/

private:
	std::vector<Entity*> m_entities;
	Components::ComponentPool* m_componentPool;
};
