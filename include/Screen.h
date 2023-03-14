#pragma once
#include "Vector2.h"

struct Screen
{
	static const int WIDTH = 640;
	static const int HEIGHT = 480;

	static Vector2 ConvertToScreenPos(Vector2 worldPos);
};
