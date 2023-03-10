#include "ShipComponent.h"
#include "Screen.h"

void ShipComponent::Accelerate(double deltaTime)
{
	Vector2 forward = m_owner->GetTransform().GetForward();
	m_PhysicComponent->SetVelocity(m_PhysicComponent->GetVelocity() + forward * m_acceleration * deltaTime);
}

void ShipComponent::Yaw(double deltaTime, bool clockwise)
{
	m_owner->GetTransform().Rotate(clockwise ? m_angleSpeed * deltaTime : -m_angleSpeed * deltaTime);
}
