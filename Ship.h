#pragma once
#include "GameObject.h"
#include "IShipDriver.h"

class Ship : public GameObject, IShipDriver
{
public:
	Ship(int speed, int angleSpeed);
	void Accelerate() override;
	void Yaw(bool clockwise) override;
private:
	int m_speed;
	int m_angleSpeed;
};

