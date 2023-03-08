#pragma once
#include "Component.h"

namespace Components
{
	class VelocityComponent : public Component
	{
		friend class ComponentPool;
	public:
		int Velocity;
		static const int ID;
	protected:
		VelocityComponent(int entityId) : Component(entityId), Velocity(1)
		{
		}
	};
}
