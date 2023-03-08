#pragma once
#include "PositionComponent.h"
#include "ECS.h"
#include "VelocityComponent.h"

class LogPositionSystem : public System<PositionComponent, VelocityComponent>
{
public:
	LogPositionSystem(ComponentPool& entityPool) : System<PositionComponent, VelocityComponent>(entityPool)
	{
	}

protected:
	void Run() override;
};
