#include "EntityPool.h"


EntityPool::~EntityPool()
{
	m_entities.clear();
}

Entity* EntityPool::CreateEntity()
{
	Entity* entity = new Entity();
	m_entities.push_back(entity);

	return entity;
}
