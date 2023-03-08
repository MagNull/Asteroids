#include "Screen.h"

Vector2 Screen::ConvertToScreenPos(Vector2 worldPos)
{
	Vector2 result = worldPos;
	result.y *= -1;
	result += Vector2{WIDTH / 2, HEIGHT / 2};

	return result;
}

