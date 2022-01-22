////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <SDL_render.h>
#include <string>
#include <memory>

namespace SG
{
	enum class SpriteSheetEnum
	{
		Default,
		TileSet,
		Link,
		LinkWalking,
		LinkWalkingHit,
		LinkAttacking,
		WoodSword,
		RedOctorok


	};

	class Spritesheet
	{
	public:
		Spritesheet(std::string fileName);
		~Spritesheet()
		{
			SDL_DestroyTexture(SpriteSheetTexture);
		}

		SDL_Texture* SpriteSheetTexture = nullptr;
		const std::string FileName;
		bool IsLoaded = false;
	};
}
