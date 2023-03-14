#pragma once
#include "IShipDriver.h"
#include "ShipShooterComponent.h"

class ShipInput
{
public:
	ShipInput()
	{
	}

	void SetShip(IShipDriver& shipDriver, ShipShooterComponent& shooter);

	void Run();
	void Update(double deltaTime);

	void Shutdown();
private:
	bool m_isRunning;
	IShipDriver* m_ShipDriver;
	ShipShooterComponent* m_ShipShooter;
};
