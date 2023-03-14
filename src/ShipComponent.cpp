#include "ShipComponent.h"

#include <iostream>

#include "Screen.h"

void ShipComponent::Accelerate(double deltaTime)
{
	Vector2 forward = m_Owner->GetTransform().GetForward();
	m_PhysicComponent->SetVelocity(m_PhysicComponent->GetVelocity() + forward * m_Acceleration * deltaTime);
}

void ShipComponent::Yaw(double deltaTime, bool clockwise)
{
	m_Owner->GetTransform().Rotate(clockwise ? m_AngleSpeed * deltaTime : -m_AngleSpeed * deltaTime);
}

void ShipComponent::TakeDamage(int damage)
{
	if (m_Health <= 0)
		return;
	m_Health -= damage;

	if (m_Health <= 0)
	{
		m_Health = 0;
		OnDied();
	}
}

void ShipComponent::OnDied()
{
	std::cout << "Ship destroyed";
	m_Acceleration = 0;
	m_AngleSpeed = 0;
	m_PhysicComponent->SetVelocity(Vector2::zero);
	m_OnDied();
}

void ShipComponent::Update(double deltaTime)
{
	if (m_PhysicComponent->GetVelocity().GetMagnitude() == 0)
		return;

	Vector2 velocityDirection = m_PhysicComponent->GetVelocity();
	velocityDirection.Normalize();
	m_PhysicComponent->SetVelocity(
		m_PhysicComponent->GetVelocity() -  velocityDirection* m_BrakingAcceleration *
		deltaTime);
}
