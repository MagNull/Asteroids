#include "Asteroid.h"

#include "PhysicComponent.h"

Asteroid::Asteroid(std::string name, Vector2 startVelocity) : GameObject(name)
{
	PhysicComponent* physic = new PhysicComponent(*this);
}
