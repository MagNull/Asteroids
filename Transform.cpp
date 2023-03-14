#include "Transform.h"

#include <cmath>

#include "Screen.h"


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
	return m_size;
}

SDL_Rect Transform::GetRect() const
{
	SDL_Rect rect;
	rect.x = m_position.x;
	rect.y = m_position.y;
	rect.w = m_size.x;
	rect.h = m_size.y;
	return rect;
}

Vector2 Transform::GetForward() const
{
	return Vector2{
		std::sin(m_rotation * M_PI / 180),
		std::cos(m_rotation * M_PI / 180)
	};
}

void Transform::SetPosition(Vector2 newPos)
{
	m_position = newPos;
	m_position = Vector2::Loop(m_position,
	                           Vector2(-Screen::WIDTH / 2, -Screen::HEIGHT / 2),
	                           Vector2(Screen::WIDTH / 2, Screen::HEIGHT / 2));
}

void Transform::SetSize(Vector2 size)
{
	m_size = size;
}

void Transform::SetForward(Vector2 newForward)
{
	m_rotation = std::atan2(newForward.x, newForward.y) * 180 / M_PI;
}

void Transform::Move(Vector2 pos)
{
	m_position += pos;
	m_position = Vector2::Loop(m_position,
	                           Vector2(-Screen::WIDTH / 2, -Screen::HEIGHT / 2),
	                           Vector2(Screen::WIDTH / 2, Screen::HEIGHT / 2));
}

void Transform::Rotate(double angle)
{
	m_rotation += angle;
}
