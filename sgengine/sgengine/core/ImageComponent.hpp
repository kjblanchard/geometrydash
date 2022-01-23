////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <SDL_render.h>
#include <memory>
#include <sgengine/core/Component.hpp>
#include <sgengine/graphics/Spritesheet.hpp>
#include <sgengine/core/Point.hpp>

namespace SG
{
	class Image;
	class SpriteBatch;
	class GameObject;

	/// <summary>
	/// The component that draws an image on the screen.  Can be used by itself, but also used in the animation controllers.
	/// </summary>
	class ImageComponent : public Component
	{
	public:
		/// <summary>
		/// These two constructors are for static images that will not be controlled by the animation controller, they will need a spritesheet
		/// </summary>
		/// <param name="spriteSheetToLoad">The enum value of the spritesheet to use</param>
		/// <param name="spriteSheetLocationAndSize">The location and size within the spritesheet to display</param>
		/// <param name="gameObject">The owner</param>
		ImageComponent(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize, GameObject* gameObject);
		/// <summary>
		/// Used for a single static image within a sprite, not really a spritesheet, likely not used much
		/// </summary>
		/// <param name="spriteSheetToLoad">The sprite sheet enum</param>
		/// <param name="imageSize">Point of the image size in xy</param>
		/// <param name="gameObject">The owner</param>
		ImageComponent(SpriteSheetEnum spriteSheetToLoad, Point imageSize, GameObject* gameObject);
		/// <summary>
		/// This is used for animation components
		/// </summary>
		/// <param name="spriteSheetLocationAndSize">The location and size of the image in the spritesheet at the default</param>
		/// <param name="gameObject"></param>
		ImageComponent(const SDL_Rect& spriteSheetLocationAndSize, GameObject* gameObject);
		~ImageComponent();

		/// <summary>
		/// This Update function takes in a location to update the sprite with
		/// </summary>
		/// <param name="location"></param>
		void Update(Point location);
		/// <summary>
		/// Adds the image to the spritebatch that's passed in
		/// </summary>
		/// <param name="spriteBatch"></param>
		void Draw(SpriteBatch& spriteBatch) override;

		/// <summary>
		/// Updates the held image's location in the spritesheet, used by animation controller
		/// </summary>
		/// <param name="locationInSpriteSheet">The new location of the image</param>
		void UpdateSpriteSheetLocation(const Point& locationInSpriteSheet) const;

		/// <summary>
		/// Used by the animation controller when changing between animations.
		/// </summary>
		/// <param name="spriteSheet">The new spritesheet that should be placed into the Image class</param>
		void UpdateImageSpriteSheet(Spritesheet* spriteSheet) const;
		std::unique_ptr<Image> image;
	private:
		void UpdateSpriteDestinationInWorld(const Point& worldLocation);
		SG::Point _location;

	};
}
