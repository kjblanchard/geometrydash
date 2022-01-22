////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "Clock.hpp"

namespace SG
{

	/**
	 * \brief Manages the core game loop for the game.  You can pass in the amount of FPS that you'd like to play with, but defaults at 60fps
	 */
	class GameClock
	{
	public:
		GameClock(const double& msPerTick = 1000.00/60);
		~GameClock();
		/**
		 * \brief This function should run all the time to determine if it should run a new frame
		 */
		void Tick();
		/**
		 * \brief This is called when the game performs a update of the game loop, which will subtract from the amount of time needed to update
		 */
		void UpdateClockTimer();
		/**
		 * \brief Returns if the time since last update is greater than the ms per frame
		 * \return If the game should perform a game loop update
		 */
		bool ShouldUpdate() const { return _timeSinceLastUpdate >= _msPerFrame; }
		/**
		 * \brief Checks to see if the game is getting a steady frame rate or not
		 * \return Value is true if the Update time since last frame is the ms frame time * 1.5
		 */
		bool GameIsLagging() const { return _timeSinceLastUpdate >= (_msPerFrame * 1.5); }
		/**
		 * \brief Returns a reference to the games configuration for its ms per frame
		 * \return The games ms per frame
		 */
		const double& MsPerFrame() const { return _msPerFrame; }
		/**
		 * \brief Returns the amount of time since the last update was ran
		 * \return The amount of time since the last update was ran
		 */
		const double& DeltaTime() const { return _timeSinceLastUpdate; }
		/**
		 * \brief Returns the total gametime including pause time
		 * \return Total time since the game has started
		 */
		Time TotalTime() const { return  _clock.GetElapsedTime(); }

	private:
		double _msPerFrame;
		double _previousGameRunningTime;
		double _currentGameRunningTime;
		double _thisTickDeltaTime;
		double _timeSinceLastUpdate;
		Clock _clock;
	};
}
