#pragma once
#include "GameObject.h"
#include "IShipDriver.h"
#include "PhysicComponent.h"

class ShipComponent : public Component, public IShipDriver
{
public:
	ShipComponent(GameObject& go) : Component(go)
	{
		m_PhysicComponent = new PhysicComponent(go);
		go.AddComponent(m_PhysicComponent);
	}

	ShipComponent(GameObject& go, double acceleration, int angleSpeed) : Component(go), m_acceleration(acceleration),
	                                                            m_angleSpeed(angleSpeed)
	{
		m_PhysicComponent = new PhysicComponent(go);
		go.AddComponent(m_PhysicComponent);
	}

	void SetAngleSpeed(int angleSpeed)
	{
		m_angleSpeed = angleSpeed;
	}

	void Accelerate(double deltaTime) override;
	void Yaw(double deltaTime, bool clockwise) override;

private:
	PhysicComponent* m_PhysicComponent;
	double m_acceleration;
	int m_angleSpeed;
};
