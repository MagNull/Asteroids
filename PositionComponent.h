#pragma once
#include "Component.h"

namespace Components
{
	class PositionComponent : public Component
	{
		friend class ComponentPool;
	public:
		int Position;
		static const int ID;
	protected:
		PositionComponent(int entityId) : Component(entityId), Position(0)
		{
		}

	};
}
