#include <sgengine/core/GameObject.hpp>

namespace SG{
    class ImageComponent;
}

class player : public SG::GameObject
{
private:

public:
    player();
    SG::ImageComponent* imageComp;
    ~player();
    void Draw(SG::SpriteBatch& spriteBatch) override;
};

