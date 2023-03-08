#pragma once
#include "Component.h"

class IComponentObserver
{
public:
	virtual void OnComponentCreated(Component& component) = 0;
};
