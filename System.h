#pragma once

#include "EntityPool.h"
#include "MutableTuple.h"
using namespace Components;

template <typename... Components>
class System
{
public:
	void Update()
	{
		Run();
	}

protected:
	System(ComponentPool& entityPool)
	{
		m_ComponentPool = &entityPool;
	}

	virtual void Run() = 0;

	std::vector<MutableTuple<Components*...>> m_ComponentsByEntities;
	ComponentPool* m_ComponentPool;
};
