#include  <sgengine/core/GameClock.hpp>
#include <SDL_timer.h>

namespace SG
{
	Clock::Clock(): CurrentTime(0)
	{
		StartTime = CurrentTime = SDL_GetTicks();
	}

	Time Clock::GetElapsedTime() const
	{
		return CurrentTime;
	}

	void Clock::Tick()
	{
		CurrentTime = SDL_GetTicks();
	}
}
