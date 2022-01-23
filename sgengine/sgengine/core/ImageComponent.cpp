#include <sgengine/graphics/Image.hpp>
#include <sgengine/core/ImageComponent.hpp>
#include <sgengine/graphics/SpriteBatch.hpp>


namespace SG
{
	ImageComponent::ImageComponent(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize,
		GameObject* gameObject) : Component(gameObject,SGComponentTypes::Image)
	{
		image = std::make_unique<Image>(spriteSheetToLoad, spriteSheetLocationAndSize);
	}

	ImageComponent::ImageComponent(SpriteSheetEnum spriteSheetToLoad, Point imageSize, GameObject* gameObject) : Component(gameObject,SGComponentTypes::Image)
	{
		image = std::make_unique<Image>(spriteSheetToLoad, imageSize);
	}

	ImageComponent::ImageComponent(const SDL_Rect& spriteSheetLocationAndSize, GameObject* gameObject) : Component(gameObject, SGComponentTypes::Image)
	{
		image = std::make_unique<Image>(spriteSheetLocationAndSize);
	}

	ImageComponent::~ImageComponent()
	{
	}


	void ImageComponent::Update(Point location)
	{
		UpdateSpriteDestinationInWorld(location);
	}

	void ImageComponent::Draw(SpriteBatch& spritebatch)
	{
		if(image)
			spritebatch.AddToSpriteBatch(image.get());
	}



	void ImageComponent::UpdateSpriteSheetLocation(const Point& locationInSpriteSheet) const
	{
		if(image)
		{
			image->LocationAndSizeInSpriteSheet.x = locationInSpriteSheet.X;
			image->LocationAndSizeInSpriteSheet.y = locationInSpriteSheet.Y;
		}
	}

	void ImageComponent::UpdateSpriteDestinationInWorld(const Point& worldLocation)
	{
		if(image)
		{
			image->Location = worldLocation;
			image->LocationAndSizeOnRenderer.x = worldLocation.X;
			image->LocationAndSizeOnRenderer.y = worldLocation.Y;
		}
	}

	void ImageComponent::UpdateImageSpriteSheet(Spritesheet* spriteSheet) const
	{
		image->SpriteSheet = spriteSheet;
	}
}
