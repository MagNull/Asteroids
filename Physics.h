#pragma once
#include <vector>
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
	void CheckCollisions(std::vector<PhysicComponent*> physics);
	bool CheckCollision(PhysicComponent* physic1, PhysicComponent* physic2) const;
	void ProcessVelocities(std::vector<PhysicComponent*> physics, double deltaTime);
};
