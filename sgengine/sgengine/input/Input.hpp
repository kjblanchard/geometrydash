////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once

#include <SDL_events.h>
#include <SDL_gamecontroller.h>
#include <SDL_scancode.h>
#include <SDL_stdinc.h>
#include <vector>
#include <sgengine/input/PlayerController.hpp>

namespace SG
{
	struct GamePad;

	class Input
	{

	public:
		static bool IsKeyHeldDown(SDL_Scancode key);
		static bool IsKeyHeldDown(int controllerNum, SDL_GameControllerButton button);
		static bool KeyJustPressed(SDL_Scancode key);
		static bool KeyJustPressed(int controllerNum, SDL_GameControllerButton button);
		static bool KeyJustReleased(SDL_Scancode key);
		static bool KeyJustReleased(int controllerNum, SDL_GameControllerButton button);

		static PlayerController *GetPlayerController(int controllerToGet);
		static std::vector<std::unique_ptr<SG::PlayerController>> PlayerControllers;

		void Startup();
		/**
		 * \brief Handles Joystick events, this assigns them to the Joystick states for reference by the player controllers
		 * \param event The event passed from the Game, this should be a joystick event if it gets here
		 */
		void HandleJoystickEvent(const SDL_Event &event);
		/**
		 * \brief Updates the previous keyboard and current keyboard states
		 */
		static void UpdateKeyboardStates();
		/**
		 * \brief Updates the previous joystick states
		 */
		static void UpdatePreviousJoystickState();

	private:
		static Uint8 _previousKeyboardState[SDL_NUM_SCANCODES];
		static Uint8 _currentKeyboardState[SDL_NUM_SCANCODES];
		static std::vector<GamePad> _controllerInputs;
		static std::vector<GamePad> _lastControllerInputs;
		static int _numGamePads;
		std::vector<SDL_GameController *> _connectedControllers;
		/**
		 * @brief Initialize the keyboard states at startup.
		 * 
		 */
		// inline static void InitializeKeyboardStateArrays()
		// {
		// 	memset(_previousKeyboardState, 0, sizeof(Uint8) * SDL_NUM_SCANCODES);
		// 	memcpy(_currentKeyboardState, SDL_GetKeyboardState(nullptr), sizeof(Uint8) * SDL_NUM_SCANCODES);
		// };
		static void InitializeKeyboardStateArrays();
		static void CountPluggedInControllers();
		void AddPluggedInControllersToVector();
		static void InitializeJoystickVectors();
	};

	struct GamePad
	{
		bool buttons[SDL_CONTROLLER_BUTTON_MAX];
		int axis[SDL_CONTROLLER_AXIS_MAX];
	};
}
