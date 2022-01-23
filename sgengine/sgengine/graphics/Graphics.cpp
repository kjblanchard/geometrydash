#include <sgengine/graphics/Graphics.hpp>
#include <SDL_image.h>
#include <sgengine/core/DebugHandler.hpp>
#include <sgengine/graphics/Image.hpp>
#include <sgengine/graphics/SpriteBatch.hpp>
#include <sgengine/core/World.hpp>

namespace SG
{

	Graphics::Graphics()
		: _displayResolution(1920, 1080),
		  _worldResolution(512, 288),
		  //   _windowSurface(nullptr),
		  _renderer(nullptr)
	{
	}

	bool Graphics::Startup()
	{

		if (!CreateGameWindow())
			return false;
		if (!InitializeSdlImg())
			return false;
		if (!CreateRenderer())
			return false;
		return true;
	}

	void Graphics::Draw(SpriteBatch &spriteBatch)
	{
		SDL_RenderClear(_renderer);
		for (auto *sprite : spriteBatch.GameTextures())
		{
			if (sprite->ImageIsWholeTexture)
				SDL_RenderCopy(_renderer, sprite->SpriteSheet->SpriteSheetTexture, NULL, &sprite->LocationAndSizeOnRenderer);
			else
				SDL_RenderCopy(_renderer, sprite->SpriteSheet->SpriteSheetTexture, &sprite->LocationAndSizeInSpriteSheet, &sprite->LocationAndSizeOnRenderer);
		}
		for (auto debugBox : spriteBatch.DebugBoxes())
		{
			SDL_RenderDrawRect(_renderer, debugBox);
		}
		SDL_RenderPresent(_renderer);
	}

	Spritesheet *Graphics::LoadFromSpriteSheet(SpriteSheetEnum spriteSheetToLoad)
	{
		auto *lookup = _spriteSheetMap.at(spriteSheetToLoad);
		if (lookup)
		{

			if (!lookup->IsLoaded)
			{
				lookup->SpriteSheetTexture = LoadTexture(lookup->FileName);
				lookup->IsLoaded = true;
				return lookup;
			}
			return lookup;
		}
		DebugHandler::PrintErrorMessage(ErrorCodes::SDLSpriteSheetError);
		return nullptr;
	}

	bool Graphics::CreateGameWindow()
	{
		_gameWindow = SDL_CreateWindow("Geometry Dash!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _displayResolution.X, _displayResolution.Y, SDL_WINDOW_SHOWN);
		if (!_gameWindow)
		{
			SG::DebugHandler::PrintErrorMessage(ErrorCodes::WindowError);
			return false;
		}
		return true;
	}

	bool Graphics::InitializeSdlImg()
	{
		const int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLImageError);
			return false;
		}
		return true;
	}

	bool Graphics::CreateRenderer()
	{
		_renderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!_renderer)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
		SDL_RenderSetLogicalSize(_renderer, _worldResolution.X, _worldResolution.Y);
		return true;
	}

	struct SDL_Texture *Graphics::LoadTexture(std::string fileName)
	{
		fileName.insert(0, "assets/graphics/");
		SDL_Texture *newTexture = nullptr;
		SDL_Surface *loadedSurface = IMG_Load(fileName.c_str());
		if (!loadedSurface)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLImageError);
			return newTexture;
		}
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (!newTexture)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLTextureError);
			return newTexture;
		}
		SDL_FreeSurface(loadedSurface);
		return newTexture;
	}

}
