#include "ShipInput.h"
#include <SDL.h>

void ShipInput::Run()
{
	m_isRunning = true;
	while (m_isRunning)
	{
		const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
		if (keyStates[SDL_SCANCODE_SPACE])
		{
			m_shipDriver->Accelerate();
		}
		if (keyStates[SDL_SCANCODE_R])
		{
			m_shipDriver->Yaw(true);
		}
		if (keyStates[SDL_SCANCODE_Q])
		{
			m_shipDriver->Yaw(false);
		}
	}
}

void ShipInput::Shutdown()
{
	m_isRunning = false;
}
