#include "Timer.h"

#include <SDL_timer.h>

void Timer::Start()
{
	m_isStart = true;
	m_startTick = SDL_GetTicks();
}

void Timer::Stop()
{
	m_isStart = false;
}

size_t Timer::GetTickSinceStart() const
{
	return SDL_GetTicks() - m_startTick;
}