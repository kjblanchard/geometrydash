////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <cinttypes>
#include <sgengine/core/Time.hpp>

namespace SG
{
	/// <summary>
	/// Holds Time Variables, it is automatically initialized with the start time when a new timer is created.
	/// </summary>
	struct Clock
	{
		Clock();
		Time GetElapsedTime() const;
		void Tick();

		uint32_t StartTime;
		uint32_t CurrentTime;
	};


}
