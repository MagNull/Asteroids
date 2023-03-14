#include <SDL_rect.h>
#include <vector>

#include "Physics.h"
#include "PhysicComponent.h"

void Physics::Update(std::vector<GameObject*> gameObjects, double deltaTime)
{
	std::vector<PhysicComponent*> physics;
	std::vector<ColliderComponent*> colliders;
	for (GameObject* gameObject : gameObjects)
	{
		if(!gameObject->IsActive())
			continue;

		PhysicComponent* physic = nullptr;
		ColliderComponent* collider = nullptr;
		if (gameObject->GetComponent<PhysicComponent>(&physic))
		{
			physics.push_back(physic);
		}
		if (gameObject->GetComponent<ColliderComponent>(&collider))
		{
			colliders.push_back(collider);
		}
	}

	CheckCollisions(colliders);
	ProcessVelocities(physics, deltaTime);
}

bool Physics::CheckCollision(ColliderComponent* obj1, ColliderComponent* obj2) const
{
	SDL_Rect rect1 = obj1->GetGameObject().GetTransform().GetRect();
	rect1.w *= obj1->GetWidth();
	rect1.h *= obj1->GetHeight();
	SDL_Rect rect2 = obj2->GetGameObject().GetTransform().GetRect();
	rect2.w *= obj2->GetWidth();
	rect2.h *= obj2->GetHeight();

	return SDL_HasIntersection(&rect1, &rect2);
}

void Physics::CheckCollisions(std::vector<ColliderComponent*> colliders)
{
	for (auto i = 0; i < colliders.size(); i++)
	{
		for (auto j = i + 1; j < colliders.size(); j++)
		{
			if (CheckCollision(colliders[i], colliders[j]))
			{
				colliders[i]->OnCollided(&colliders[j]->GetGameObject());
				colliders[j]->OnCollided(&colliders[i]->GetGameObject());
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
