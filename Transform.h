#pragma once
#include <SDL_rect.h>
#include "Vector2.h"

class Transform
{
public:
	Transform(Vector2 pos = Vector2(1, 1), double rotation = 0, Vector2 scale = Vector2(1, 1)) :
		m_position(pos), m_rotation(rotation), m_scale(scale)
	{
	}

	Vector2 GetPosition() const;

	double GetRotation() const;

	Vector2 GetScale() const;

	SDL_Rect GetRect() const;

	Vector2 GetForward() const;

	void SetPosition(Vector2 newPos);

	void Move(Vector2 pos);
	void Rotate(double angle);
	void Scale(Vector2 scale);

private:
	Vector2 m_position;
	double m_rotation;
	Vector2 m_scale;
};
