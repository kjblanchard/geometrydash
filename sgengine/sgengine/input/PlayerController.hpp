////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////
#pragma once
#pragma warning(push)
#pragma warning(disable : 26812)

#include <memory>

#include <sgengine/input/Controller.hpp>

namespace SG
{
	class PlayerController : public Controller
	{
	public:
		PlayerController()
		{
		}
		PlayerController(int num);
		bool IsButtonPressed(ControllerButtons controllerButton) override;
		bool IsButtonHeld(ControllerButtons controllerButton) override;
		bool IsButtonReleased(ControllerButtons controllerButton) override;

		void UpdateControllerMapping(KeyMapping<SDL_Scancode> newKeyboardMap)
		{
			_keyboardMapping = newKeyboardMap;
		}
		void UpdateControllerMapping(KeyMapping<SDL_GameControllerButton> newJoystickMap)
		{
			_joystickMapping = newJoystickMap;
		}

		void UpdateControlType(bool isUsingGamepad)
		{
			_isUsingGamePad = isUsingGamepad;
		}

		void UpdatePlayerNum(uint8_t playerNum)
		{
			_playerNum = playerNum;
		}

	private:
		KeyMapping<SDL_Scancode> _keyboardMapping{*DefaultKeyboardMap};
		KeyMapping<SDL_GameControllerButton> _joystickMapping{*DefaultJoystickMap};
		bool _isUsingGamePad{false};
		uint8_t _playerNum{ 0 };
	};
}
#pragma warning(pop)