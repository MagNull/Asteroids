#pragma once
#include "GameObject.h"
#include "IShipDriver.h"

class Ship : public Component, public IShipDriver
{
public:
	Ship(GameObject& go) : Component(go)
	{
	}

	Ship(GameObject& go, int speed, int angleSpeed) : Component(go), m_speed(speed), m_angleSpeed(angleSpeed)
	{
	}

	void SetSpeed(int speed)
	{
		m_speed = speed;
	}

	void SetAngleSpeed(int angleSpeed)
	{
		m_angleSpeed = angleSpeed;
	}

	void Accelerate() override;
	void Yaw(bool clockwise) override;

private:
	int m_speed;
	int m_angleSpeed;
};
