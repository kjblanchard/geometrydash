// #include <core/World.hpp>
// // #include "SDL.h"
// // #include <iostream>
// // #include "core/DebugHandler.h"
// // #include "core/GameClock.h"
// // #include "core/GameObjectList.h"
// // #include "graphics/Graphics.h"
// // #include "input/Input.h"
// // #include "graphics/SpriteBatch.h"
// // #include "SDL_mixer.h"
// // #include "core/Sound.h"


// namespace SG
// {
// 	//statics
// 	std::unique_ptr<Graphics>  World::_graphics = nullptr;
// 	World* World::_instance = nullptr;
// 	Sound* World::_sound = nullptr;



// 	World::World()
// 		: _gameWindow(nullptr), _gameClock{std::make_unique<GameClock>()},_input{std::make_unique<Input>()}
// 	{
// 		LoadConfigFromJson();
// 		_graphics = std::make_unique<class Graphics>();
// 		if (_instance == nullptr)
// 			_instance = this;
// 	}


// 	World::~World()
// 	{
// 		SDL_DestroyWindow(_gameWindow);
// 		SDL_Quit();
// 	}

// 	bool World::SetupWorldComponents() const
// 	{
// 		if (!InitializeSdl())
// 			return false;
// 		if (!_graphics->Startup())
// 			return false;
// 		if (!InitializeSdlMixer())
// 			return false;
// 		_input->Startup();
// 		return true;
// 	}

// 	bool World::InitializeSdl()
// 	{
// 		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0)
// 		{
// 			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
// 			return false;
// 		}
// 		return true;

// 	}

// 	bool World::InitializeSdlMixer() const
// 	{
// 		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
// 		{
// 			DebugHandler::PrintErrorMessage(ErrorCodes::SDLMixerError);
// 			return false;
// 		}
// 		_sound = new Sound();
// 		return true;
// 	}

// 	/// <summary>
// 	/// Loads the configuration file from the json appsettings.json file.  This needs to be done in the constructor, before graphics
// 	/// </summary>
// 	/// <returns>Returns true if it actually generated a value from the configuration</returns>
// 	bool World::LoadConfigFromJson()
// 	{
// 		SG::Configuration::GenerateJsonFromConfigFile("appsettings.json");
// 		if (!SG::Configuration::GenerateValuesFromJson())
// 			return false;
// 		return true;
// 	}


// 	void World::Loop()
// 	{
// 		Startup();
// 		while (!shouldQuit)
// 		{
// 			_gameClock->Tick();
// 			if (_gameClock->ShouldUpdate())
// 			{
// 				if (_gameClock->GameIsLagging())
// 					DebugHandler::PrintErrorMessage(ErrorCodes::GameSlowdown, _gameClock->DeltaTime());
// 				while (_gameClock->ShouldUpdate())
// 				{
// 					HandleInput();
// 					Update(_gameClock->MsPerFrame());
// 					_gameClock->UpdateClockTimer();
// 				}
// 				Draw();
// 			}
// 		}
// 	}


// 	bool World::HandleEvents()
// 	{
// 		SDL_Event event;
// 		while (SDL_PollEvent(&event) != 0)
// 		{
// 			if (event.type == SDL_QUIT)
// 			{
// 				shouldQuit = true;
// 				return false;
// 			}
// 			_input->HandleJoystickEvent(event);
// 		}
// 		return true;
// 	}

// 	void World::HandleInput()
// 	{
// 		Input::UpdatePreviousJoystickState();
// 		HandleEvents();
// 		Input::UpdateKeyboardStates();
// 	}


// 	void World::Draw()
// 	{

// 	}
// }
