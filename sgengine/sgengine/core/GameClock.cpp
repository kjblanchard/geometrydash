#include  <sgengine/core/GameClock.hpp>

namespace SG
{

	GameClock::GameClock(const double& msPerTick): _msPerFrame(msPerTick), _previousGameRunningTime(0.0), _currentGameRunningTime(0.0), _thisTickDeltaTime(0.0),
	                                               _timeSinceLastUpdate(0.0)
	{
	}

	GameClock::~GameClock()
	{
	}

	void GameClock::Tick()
	{
		_clock.Tick();
		_previousGameRunningTime = _currentGameRunningTime;
		_currentGameRunningTime = _clock.GetElapsedTime().Milliseconds();
		_thisTickDeltaTime = _currentGameRunningTime - _previousGameRunningTime;
		_timeSinceLastUpdate += _thisTickDeltaTime;
	}

	void GameClock::UpdateClockTimer()
	{
		_timeSinceLastUpdate -= _msPerFrame;
		if (_timeSinceLastUpdate < 0)
			_timeSinceLastUpdate = 0;
	}
}
