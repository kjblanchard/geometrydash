#include <sgengine/graphics/Image.hpp>
#include <sgengine/graphics/Spritesheet.hpp>
#include <sgengine/graphics/Graphics.hpp>
#include <sgengine/core/World.hpp>
namespace SG
{
	Graphics* Image::_graphics = nullptr;

	Image::Image(): SpriteSheet(nullptr), LocationAndSizeInSpriteSheet(), LocationAndSizeOnRenderer()
	{
	}

	Image::Image(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize): LocationAndSizeInSpriteSheet()
	{
		Size.X = LocationAndSizeOnRenderer.h = spriteSheetLocationAndSize.h;
		Size.Y = LocationAndSizeOnRenderer.w = spriteSheetLocationAndSize.w;
		LocationAndSizeInSpriteSheet = spriteSheetLocationAndSize;
		SpriteSheet = GenerateImage(spriteSheetToLoad);
	}

	Image::Image(SpriteSheetEnum spriteSheetToLoad, Point imageSize) : Size(imageSize), LocationAndSizeInSpriteSheet()
	{
		SpriteSheet = GenerateImage(spriteSheetToLoad);
		ImageIsWholeTexture = true;
		LocationAndSizeOnRenderer.h = Size.X;
		LocationAndSizeOnRenderer.w = Size.Y;
	}

	Image::Image(const SDL_Rect& spriteSheetLocationAndSize) : LocationAndSizeInSpriteSheet()
	{
		Size.X = LocationAndSizeOnRenderer.h = spriteSheetLocationAndSize.h;
		Size.Y = LocationAndSizeOnRenderer.w = spriteSheetLocationAndSize.w;
		LocationAndSizeInSpriteSheet = spriteSheetLocationAndSize;
	}

	Image::Image(Point imageSize) : Size(imageSize), LocationAndSizeInSpriteSheet()
	{
		ImageIsWholeTexture = true;
		LocationAndSizeOnRenderer.h = Size.X;
		LocationAndSizeOnRenderer.w = Size.Y;
	}

	Spritesheet* Image::GenerateImage(SpriteSheetEnum spriteSheetToLoad)
	{
		if (!_graphics)
			_graphics = World::GetGraphics();
		return _graphics->LoadFromSpriteSheet(spriteSheetToLoad);
	}

}
