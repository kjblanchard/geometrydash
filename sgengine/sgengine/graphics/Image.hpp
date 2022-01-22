////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <SDL_render.h>
#include <sgengine/core/Point.hpp>

namespace SG
{
	enum class SpriteSheetEnum;
	class Spritesheet;
	class Graphics;

	class Image
	{


	public:
		Image();
		Image(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize);
		Image(SpriteSheetEnum spriteSheetToLoad, Point imageSize);
		/// <summary>
		/// These constructors are used in the animation controller, and are not a static image.
		/// </summary>
		/// <param name="spriteSheetLocationAndSize"></param>
		Image(const SDL_Rect& spriteSheetLocationAndSize);
		Image(Point imageSize);
		Spritesheet* SpriteSheet;
		Point Location;
		Point Size;
		SDL_Rect LocationAndSizeInSpriteSheet;
		SDL_Rect LocationAndSizeOnRenderer;
		bool ImageIsWholeTexture = false;
	private:
		static Spritesheet* GenerateImage(SpriteSheetEnum spriteSheetToLoad);
		static Graphics* _graphics;
	};
}
