#pragma once
#include <SDL_rect.h>
#include "Vector2.h"

class Transform
{
public:
	Transform(Vector2 pos = Vector2(1, 1), double rotation = 0, Vector2 size = Vector2(1, 1)) :
		m_position(pos), m_rotation(rotation), m_size(size)
	{
	}

	Vector2 GetPosition() const;

	double GetRotation() const;

	Vector2 GetScale() const;

	SDL_Rect GetRect() const;

	Vector2 GetForward() const;

	void SetPosition(Vector2 newPos);

	void SetSize(Vector2 scale);

	void Move(Vector2 pos);

	void Rotate(double angle);

private:
	Vector2 m_position;
	double m_rotation;
	Vector2 m_size;
};
