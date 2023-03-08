#include "Ship.h"

void Ship::Accelerate()
{
	GetTransform().Move(GetTransform().GetForward() * m_speed);
}

void Ship::Yaw(bool clockwise)
{
	GetTransform().Rotate(clockwise ? m_angleSpeed : -m_angleSpeed);
}

