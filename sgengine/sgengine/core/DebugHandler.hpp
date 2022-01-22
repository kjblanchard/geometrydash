////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include <string>


using std::string;

namespace SG
{
	enum class ErrorCodes
	{
		GenericError = 0,
		SDLError = 1,
		SDLImageError =2,
		SDLTextureError = 3,
		WindowError = 4,
		GameSlowdown = 5,
		SDLSpriteSheetError = 6,
		SDLMixerError = 7,
		AnimationError = 8

	};


	class DebugHandler
	{
	public:

		static void PrintErrorMessage(ErrorCodes codeToPrint);
		template <typename T>
		static void PrintErrorMessage(ErrorCodes codeToPrint, const T& data);


	};

	template <typename T>
	void DebugHandler::PrintErrorMessage(ErrorCodes codeToPrint, const T& data)
	{
		PrintErrorMessage(codeToPrint);
		auto numberString = std::to_string(data);
		if (!numberString.empty())
			std::cout << data << std::endl;
		else
			std::cout << "Cannot convert to string / bad data passed into debugger" << std::endl;
	}
}
