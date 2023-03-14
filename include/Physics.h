#pragma once
#include <vector>

#include "ColliderComponent.h"
#include "GameObject.h"

class PhysicComponent;

class Physics
{
public:
	Physics()
	{
		
	}

	void Update(std::vector<GameObject*> physics, double deltaTime);
private:
	void CheckCollisions(std::vector<ColliderComponent*> colliders);
	bool CheckCollision(ColliderComponent* obj1, ColliderComponent* obj2) const;
	void ProcessVelocities(std::vector<PhysicComponent*> physics, double deltaTime);
};
