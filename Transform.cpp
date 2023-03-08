#include "Transform.h"

#include <cmath>

Vector2 Transform::GetPosition() const
{
	return m_position;
}

double Transform::GetRotation() const
{
	return m_rotation;
}

Vector2 Transform::GetScale() const
{
	return m_scale;
}

SDL_Rect Transform::GetRect() const
{
	SDL_Rect rect;
	rect.x = m_position.x;
	rect.y = m_position.y;
	rect.w = m_scale.x;
	rect.h = m_scale.y;
	return rect;
}

Vector2 Transform::GetForward() const
{
	 return Vector2{std::sin(m_rotation * M_PI / 180),
	 					  std::cos(m_rotation * M_PI / 180)};
}

void Transform::SetPosition(Vector2 newPos)
{
	m_position = newPos;
}

void Transform::Move(Vector2 pos)
{
	m_position += pos;
}

void Transform::Rotate(double angle)
{
	m_rotation += angle;
	m_rotation = static_cast<int>(m_rotation) % 360;
}

void Transform::Scale(Vector2 scale)
{
	m_scale += scale;
}
