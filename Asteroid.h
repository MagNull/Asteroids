#pragma once
#include "GameObject.h"

class Asteroid : public GameObject
{
public:
	Asteroid(std::string name, Vector2 startVelocity);
};

