#pragma once
#include "Component.h"
#include "Vector2.h"

class PhysicComponent : public Component
{
	friend class Physics;
public:
	PhysicComponent(GameObject& gameObject) : Component(gameObject)
	{
	}

	void SetVelocity(Vector2 value)
	{
		m_Velocity = value;
	}

	Vector2 GetVelocity() const
	{
		return m_Velocity;
	}

	void SetAnlgeVelocity(double value)
	{
		m_AngleVelocity = value;
	}

	double GetAngleVelocity() const
	{
		return m_AngleVelocity;
	}

	void OnCollided(GameObject* other);

private:
	Vector2 m_Velocity;
	double m_AngleVelocity = 0.0;
};

inline void PhysicComponent::OnCollided(GameObject* other)
{

}
