#pragma once
#include <functional>

#include "GameObject.h"
#include "IDamageable.h"
#include "IShipDriver.h"
#include "PhysicComponent.h"

class ShipComponent : public Component, public IShipDriver, public IDamageable
{
public:
	ShipComponent(GameObject& go) : Component(go)
	{
		m_PhysicComponent = new PhysicComponent(go);
		go.AddComponent(m_PhysicComponent);
	}

	ShipComponent(GameObject& go, double acceleration, double braking, int angleSpeed, int health, const std::function<void()> onDied) :
		Component(go), m_Acceleration(acceleration), m_BrakingAcceleration(braking),
		m_AngleSpeed(angleSpeed), m_Health(health), m_OnDied(onDied)
	{
		m_PhysicComponent = new PhysicComponent(go);
		go.AddComponent(m_PhysicComponent);
	}

	void SetAngleSpeed(int angleSpeed)
	{
		m_AngleSpeed = angleSpeed;
	}

	void TakeDamage(int damage) override;
	void OnDied();

	void Update(double deltaTime) override;

	void Accelerate(double deltaTime) override;
	void Yaw(double deltaTime, bool clockwise) override;

private:
	PhysicComponent* m_PhysicComponent;
	double m_Acceleration;
	double m_BrakingAcceleration;
	int m_AngleSpeed;
	int m_Health;
	std::function<void()> m_OnDied;
};
