#include "Physics.h"

#include <iostream>
#include <SDL_rect.h>
#include <vector>

#include "PhysicComponent.h"

void Physics::Update(std::vector<GameObject*> gameObjects, double deltaTime)
{
	std::vector<PhysicComponent*> physics;
	for (GameObject* gameObject : gameObjects)
	{
		PhysicComponent* physic = nullptr;
		if (gameObject->GetComponent<PhysicComponent>(&physic))
		{
			physics.push_back(physic);
		}
	}

	CheckCollisions(physics);
	ProcessVelocities(physics, deltaTime);
}

bool Physics::CheckCollision(PhysicComponent* physic1, PhysicComponent* physic2) const
{
	SDL_Rect rect1 = physic1->GetGameObject().GetTransform().GetRect();
	SDL_Rect rect2 = physic2->GetGameObject().GetTransform().GetRect();

	return SDL_HasIntersection(&rect1, &rect2);
}

void Physics::CheckCollisions(std::vector<PhysicComponent*> physics)
{
	for (int i = 0; i < physics.size(); i++)
	{
		for (int j = i + 1; j < physics.size(); j++)
		{
			if (CheckCollision(physics[i], physics[j]))
			{
				physics[i]->OnCollided(&physics[j]->GetGameObject());
				physics[j]->OnCollided(&physics[i]->GetGameObject());
			}
		}
	}
}

void Physics::ProcessVelocities(std::vector<PhysicComponent*> physics, double deltaTime)
{
	for (PhysicComponent* physic : physics)
	{
		auto transform = &physic->GetGameObject().GetTransform();
		transform->SetPosition(transform->GetPosition() + physic->GetVelocity() * deltaTime);
		transform->Rotate(physic->GetAngleVelocity() * deltaTime);
	}
}
