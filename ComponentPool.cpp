#include "ComponentPool.h"

Components::ComponentPool::ComponentPool()
{
	
}


Components::ComponentPool::~ComponentPool()
{
	for (auto m_components : m_componentsById)
	{
		delete[] m_components.second;
	}
}

