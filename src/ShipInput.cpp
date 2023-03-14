#include "ShipInput.h"

#include <SDL.h>

void ShipInput::SetShip(IShipDriver& shipDriver, ShipShooterComponent& shooter)
{
	m_ShipDriver = &shipDriver;
	m_ShipShooter = &shooter;
}

void ShipInput::Run()
{
	m_isRunning = true;
}

void ShipInput::Update(double deltaTime)
{
	const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
	if (keyStates[SDL_SCANCODE_LSHIFT])
	{
		m_ShipDriver->Accelerate(deltaTime);
	}
	if (keyStates[SDL_SCANCODE_E])
	{
		m_ShipDriver->Yaw(deltaTime, true);
	}
	if (keyStates[SDL_SCANCODE_Q])
	{
		m_ShipDriver->Yaw(deltaTime, false);
	}
	if(keyStates[SDL_SCANCODE_SPACE])
	{
		m_ShipShooter->Shoot();
	}
}

void ShipInput::Shutdown()
{
	m_isRunning = false;
}
