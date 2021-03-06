#include <SDL.h>
#include <iostream>
#include <sgengine/core/DebugHandler.hpp>
#include <sgengine/core/GameClock.hpp>
#include <sgengine/graphics/Graphics.hpp>
#include <sgengine/graphics/SpriteBatch.hpp>
#include <sgengine/core/World.hpp>
#include <sgengine/input/Input.hpp>

namespace SG
{

	//Initialize the static class variables.
	std::unique_ptr<Graphics> World::_graphics = nullptr;
	World *World::_instance = nullptr;
	FMOD::Studio::System *World::_sound = nullptr;

	World::World()
		: _gameWindow(nullptr), _gameClock{std::make_unique<GameClock>()}
	{
		_graphics = std::make_unique<class Graphics>();
		if (_instance == nullptr)
			_instance = this;
	}

	World::~World()
	{
		SDL_DestroyWindow(_gameWindow);
		SDL_Quit();
	}

	bool World::SetupWorldComponents()
	{
		if (!InitializeSdl())
			return false;
		if (!_graphics->Startup())
			return false;
		if (!InitializeFmod())
			return false;
		_input->Startup();
		return true;
	}

	bool World::InitializeSdl()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		return true;
	}

	bool World::InitializeFmod()
	{
		World::_sound = destroy();
		return true;
	}

	void World::Loop()
	{
		Startup();
		while (!shouldQuit)
		{
			_gameClock->Tick();
			if (_gameClock->ShouldUpdate())
			{
				if (_gameClock->GameIsLagging())
					DebugHandler::PrintErrorMessage(ErrorCodes::GameSlowdown, _gameClock->DeltaTime());
				while (_gameClock->ShouldUpdate())
				{
					HandleInput();
					// HandleEvents();
					Update(_gameClock->MsPerFrame());
					_gameClock->UpdateClockTimer();
					_sound->update();
				}
				Draw();
			}
			SDL_Delay(5);
			// else{
			// 	auto sleeptime = _gameClock->CalculateSleepTime();
			// 	std::cout << "The sleep time is: " << sleeptime << std::endl;
			// 	SDL_Delay(sleeptime);

			// }
		}
	}

	bool World::HandleEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				shouldQuit = true;
				return false;
			}
			_input->HandleJoystickEvent(event);
		}
		return true;
	}

	void World::HandleInput()
	{
		Input::UpdatePreviousJoystickState();
		HandleEvents();
		Input::UpdateKeyboardStates();
	}

	void World::Draw()
	{
	}

}
