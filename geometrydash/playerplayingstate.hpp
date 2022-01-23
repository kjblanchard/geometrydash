#include <sgengine/core/State.hpp>
class Player;

class PlayerPlayingState : public SG::State
{
public:
	PlayerPlayingState(Player* link);
	~PlayerPlayingState() override = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void HandleInput() override;
	void End() override;

private:
	Player* _link;
};