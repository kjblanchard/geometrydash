#include <sgengine/graphics/Graphics.hpp>
#include <SDL_image.h>
#include <sgengine/core/DebugHandler.hpp>
#include <sgengine/graphics/Image.hpp>
#include <sgengine/graphics/SpriteBatch.hpp>
#include <sgengine/core/World.hpp>

namespace SG
{

	Graphics::Graphics()
		: _screenSize(640, 480),
		  _windowSurface(nullptr),
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
		SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);

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
		_gameWindow = SDL_CreateWindow("Zelda - KJB", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenSize.X, _screenSize.Y, SDL_WINDOW_SHOWN);
		if (!_gameWindow)
		{
			SG::DebugHandler::PrintErrorMessage(ErrorCodes::WindowError);
			return false;
		}
		_windowSurface = SDL_GetWindowSurface(_gameWindow);
		if (!_windowSurface)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
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
		// _renderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED);
		_renderer = SDL_GetRenderer(_gameWindow);
		if (!_renderer)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
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
