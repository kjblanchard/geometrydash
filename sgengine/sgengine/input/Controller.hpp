////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <SDL_scancode.h>
#include <map>
#include <SDL_gamecontroller.h>

namespace SG
{
	/**
	 * @brief The buttons available for the player to press.
	 * 
	 */
	enum class ControllerButtons
	{
		Default = 0,
		Up = 1,
		Right = 2,
		Down = 3,
		Left = 4,
		Y = 5,
		B = 6,
		A = 7,
		X = 8,
		Start = 9,
		Select = 10,
	};

/**
 * @brief Holds all of the buttons available in the game.
 * 
 * @tparam T The type of button (Keyboard, Gamepad, etc) that this keymapping is for.
 */
	template <typename T>
	struct KeyMapping
	{
	public:
		T UpButton;
		T RightButton;
		T DownButton;
		T LeftButton;
		T YButton;
		T BButton;
		T AButton;
		T XButton;
		T StartButton;
		T SelectButton;
	};

	class Controller
	{
	public:
		virtual ~Controller() = default;
		virtual bool IsButtonPressed(ControllerButtons controllerButton) = 0;
		virtual bool IsButtonReleased(ControllerButtons controllerButton) = 0;
		virtual bool IsButtonHeld(ControllerButtons controllerButton) = 0;
	protected:

		static const KeyMapping<SDL_Scancode>* DefaultKeyboardMap;
		static const KeyMapping<SDL_GameControllerButton>* DefaultJoystickMap;

	};
}
