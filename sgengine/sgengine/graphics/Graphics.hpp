////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <map>
#include <string>
#include <sgengine/graphics/Spritesheet.hpp>
#include <sgengine/core/Point.hpp>

struct SDL_Texture;
struct SDL_Surface;
struct SDL_Window;
struct SDL_Renderer;

namespace SG
{
	class SpriteBatch;

	class Graphics
	{
	public:
		Graphics();

		/**
		 * \brief This initializes some of the SDL components, and returns true if successful
		 * \return Returns true if everything was initialized properly
		 */
		bool Startup();

		/**
		 * \brief Clears render, and draws everything in the spritebatch
		 * \param spriteBatch Passed in from the level most likely of everything that needs to be drawn
		 */
		void Draw(SpriteBatch& spriteBatch );

		/**
		 * \brief Searches the Map for the specified enum, if it has already been loaded, return the pointer to it.  If it hasn't been loaded yet, load it and then return it
		 * \param spriteSheetToLoad The Enum for the spritesheet to load
		 * \return Returns the pointer to the spritesheet
		 */
		Spritesheet* LoadFromSpriteSheet(SpriteSheetEnum spriteSheetToLoad);

	private:

		bool CreateGameWindow();
		static bool InitializeSdlImg();
		bool CreateRenderer();

		/**
		 * \brief Loads a surface from a file, and converts that into a texture for use in displaying things on screen
		 * \param fileName The filename, this file should be in the assets/graphics folder
		 * \return Returns a texture if the file is found, otherwise returns a nullptr
		 */
		SDL_Texture* LoadTexture(std::string fileName);
	private:

		inline static std::map<SpriteSheetEnum, Spritesheet*> _spriteSheetMap =
		{
		{SpriteSheetEnum::Default, new Spritesheet("castle-tileset.png")},
		{SpriteSheetEnum::Link,new Spritesheet("hero.png")},
		{SpriteSheetEnum::TileSet, new Spritesheet("tileset.png")},
		{SpriteSheetEnum::LinkWalking,new Spritesheet("Link_Movement.png")},
		{SpriteSheetEnum::LinkAttacking, new Spritesheet("Link_Attack.png")},
		{SpriteSheetEnum::WoodSword,new Spritesheet("WoodSword.png")},
		{SpriteSheetEnum::RedOctorok,new Spritesheet("RedOctorok_Movement.png")},
		{SpriteSheetEnum::LinkWalkingHit, new Spritesheet("linkMovingHit.png")}
		};

		Point _displayResolution;
		Point _worldResolution;
		SDL_Window* _gameWindow{};
		SDL_Surface* _windowSurface;
		SDL_Renderer* _renderer;


	};
}
