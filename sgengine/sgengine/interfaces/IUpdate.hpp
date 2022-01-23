////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once

namespace SG
{
	class SpriteBatch;

	/// <summary>
	/// This interface brings in a startup, update, and draw function non-abstractly.  If you don't give them a value, they will be blank.
	/// </summary>
	class IUpdate
	{
	public:
		virtual ~IUpdate() = default;

		/// <summary>
		/// This function should be called only once, and should do most of the "work" of initializing after the constructor
		/// </summary>
		virtual void Startup()
		{

		}

		/// <summary>
		/// This is to be called once every frame, even if the game is lagging this will still be called as much as possible (60 times per second)
		/// </summary>
		/// <param name="deltaTime">The current time between frames, usually 16.6667, passed in from the current level</param>
		virtual void Update(const double& deltaTime)
		{
		}

		/// <summary>
		/// This will draw something to the screen, make sure to add to the spritebatch
		/// </summary>
		/// <param name="spriteBatch">Reference to a spritebatch, likely passed from the game level</param>
		virtual void Draw(SpriteBatch& spriteBatch)
		{
		}
	};
}
