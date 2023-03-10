#include "ShipInput.h"

#include <iostream>
#include <ostream>
#include <SDL.h>

void ShipInput::Run()
{
	m_isRunning = true;
}

void ShipInput::Update(double deltaTime)
{
	const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
	if (keyStates[SDL_SCANCODE_SPACE])
	{
		m_shipDriver->Accelerate(deltaTime);
	}
	if (keyStates[SDL_SCANCODE_R])
	{
		m_shipDriver->Yaw(deltaTime, true);
	}
	if (keyStates[SDL_SCANCODE_Q])
	{
		m_shipDriver->Yaw(deltaTime, false);
	}
}

void ShipInput::Shutdown()
{
	m_isRunning = false;
}
