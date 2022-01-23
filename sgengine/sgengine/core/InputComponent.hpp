////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <sgengine/core/Component.hpp>

namespace SG
{
	class Controller;

	class InputComponent : Component
	{
	public:
		InputComponent(Controller* controller, GameObject* gameObject = nullptr);

		void TakeControl(Controller* controllerToUse);

		Controller* CurrentController;
	};
}
