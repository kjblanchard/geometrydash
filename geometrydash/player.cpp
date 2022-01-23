#include <player.hpp>
#include <sgengine/core/ImageComponent.hpp>
#include <sgengine/core/InputComponent.hpp>
#include <sgengine/core/World.hpp>
#include <sgengine/input/Input.hpp>
#include <playerplayingstate.hpp>
#include <iostream>

player::player() : GameObject()
{
    imageComp = new SG::ImageComponent(SG::SpriteSheetEnum::Default,SG::Point(16,16), this);
    inputComp = new SG::InputComponent(SG::Input::GetPlayerController(0),this);

}

player::~player()
{
}

void player::GenerateStates()
{
    _objectStateMachine->AddStateToGameStateList(playerstates::PLAYING,std::unique_ptr<PlayerPlayingState>());

}

void player::Update(const double &deltaTime){
    if(inputComp->CurrentController->IsButtonPressed(SG::ControllerButtons::Down))
    {
        _location.Y += 5;
    }
    if(inputComp->CurrentController->IsButtonPressed(SG::ControllerButtons::Right))
    {
        _location.X += 5;
    }
    if(inputComp->CurrentController->IsButtonPressed(SG::ControllerButtons::Left))
    {
        _location.X -= 5;
    }
    if(inputComp->CurrentController->IsButtonPressed(SG::ControllerButtons::Up))
    {
        _location.Y -= 5;
    }

    imageComp->Update(_location);


}

void player::Draw(SG::SpriteBatch& spriteBatch){
    imageComp->Draw(spriteBatch);
}


