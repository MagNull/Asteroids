#include "ColliderComponent.h"
#include "GameObject.h"

void ColliderComponent::OnCollided(GameObject* other)
{
	auto components = m_Owner->GetComponents();
	for (auto co : components)
	{
		if(co == this)
			continue;

		co->OnCollided(other);
	}
}
