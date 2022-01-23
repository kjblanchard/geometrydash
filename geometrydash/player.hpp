#include <sgengine/core/GameObject.hpp>
#include <sgengine/interfaces/IObjectStateMachine.hpp>
#include <playerstate.hpp>

namespace SG
{
    class ImageComponent;
    class InputComponent;
}

class player : public SG::GameObject, public SG::IObjectStateMachine<playerstates>
{
private:
public:
    player();
    SG::ImageComponent *imageComp;
    SG::InputComponent *inputComp;
    ~player();
    void GenerateStates() override;

    void Draw(SG::SpriteBatch &spriteBatch) override;
    /// <summary>
    /// This is to be called once every frame, even if the game is lagging this will still be called as much as possible (60 times per second)
    /// </summary>
    /// <param name="deltaTime">The current time between frames, usually 16.6667, passed in from the current level</param>
    void Update(const double &deltaTime) override;
};
