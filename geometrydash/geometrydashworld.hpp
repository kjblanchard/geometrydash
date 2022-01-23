////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <sgengine/core/World.hpp>

class player;

class geometrydashworld : public SG::World
{
public:
	geometrydashworld();

	player* _player;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw() override;

};