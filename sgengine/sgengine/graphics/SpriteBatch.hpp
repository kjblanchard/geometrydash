////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <SDL_render.h>
#include <vector>

namespace SG
{
	class Image;

	class SpriteBatch
	{
	public:
		/// <summary>
		/// Add an image to draw to the screen, the graphics class will then draw all of the images
		/// </summary>
		/// <param name="imageToDraw">The image to be drawn</param>
		void AddToSpriteBatch(Image* imageToDraw)
		{
			_gameTextures.push_back(imageToDraw);

		};
		/// <summary>
		/// Add a rectangle to be drawn on the screen, this will then be a colored box drawn after all of the images are drawn, used for debugging collisions/placement
		/// </summary>
		/// <param name="debugBoxToDraw">The rectangle to be outlined</param>
		void AddToSpriteBatch(SDL_Rect* debugBoxToDraw)
		{
			_debugBoxes.push_back(debugBoxToDraw);
		};

		/// <summary>
		/// Get all of the current images in the spritebatch, should only be called by the Graphics class when drawing
		/// </summary>
		/// <returns>A list of all of the images in the spritebatch</returns>
		std::vector<Image*> GameTextures() const
		{
			return _gameTextures;
		}
		/// <summary>
		/// Get all of the current Debugboxes to be drawn to the screen on the next frame
		/// </summary>
		/// <returns>Vector of rectangles in the spritebatch</returns>
		std::vector<SDL_Rect*> DebugBoxes() const
		{
			return _debugBoxes;
		}

	private:
		std::vector<Image*> _gameTextures;
		std::vector<SDL_Rect*> _debugBoxes;
	};
}
