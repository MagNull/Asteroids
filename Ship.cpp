#include "Ship.h"

#include "Screen.h"

void Ship::Accelerate()
{
	Vector2 forward = m_owner->GetTransform().GetForward();
	m_owner->GetTransform().Move(forward * m_speed);
	auto position = m_owner->GetTransform().GetPosition();
	position = Vector2::Loop(position,
	                         Vector2(-Screen::WIDTH / 2, -Screen::HEIGHT / 2),
	                         Vector2(Screen::WIDTH / 2, Screen::HEIGHT / 2));
	m_owner->GetTransform().SetPosition(position);
}

void Ship::Yaw(bool clockwise)
{
	m_owner->GetTransform().Rotate(clockwise ? m_angleSpeed : -m_angleSpeed);
}
