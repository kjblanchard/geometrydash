#include <player.hpp>
#include <sgengine/core/ImageComponent.hpp>

player::player() : GameObject()
{
    imageComp = new SG::ImageComponent(SG::SpriteSheetEnum::Default,SG::Point(16,16), this);
}

player::~player()
{
}

void player::Draw(SG::SpriteBatch& spriteBatch){
    imageComp->Draw(spriteBatch);
}


