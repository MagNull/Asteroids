#pragma once
#include "IShipDriver.h"

class ShipInput
{
public:
	ShipInput(IShipDriver& shipDriver) : m_shipDriver(&shipDriver)
	{
	}

	void Run();
	void Update(double deltaTime);

	void Shutdown();
private:
	bool m_isRunning;
	IShipDriver* m_shipDriver;
};
