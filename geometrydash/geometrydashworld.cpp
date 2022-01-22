#include <geometrydashworld.hpp>
#include <sgengine/graphics/SpriteBatch.hpp>
#include <sgengine/graphics/Graphics.hpp>

int main(int argc, char* args[])
{
	auto zeldaWorld = std::make_unique<geometrydashworld>();
	if (!zeldaWorld->SetupWorldComponents())
		return 0;
	zeldaWorld->Loop();
	return 1;
}

geometrydashworld::geometrydashworld()
	:World()
{
}

void geometrydashworld::Startup()
{
	_isCollisionDebug = false;
}

void geometrydashworld::Update(const double& deltaTime)
{
}

void geometrydashworld::Draw()
{
	auto spriteBatch = SG::SpriteBatch();
	_graphics->Draw(spriteBatch);

}