#include <sgengine/input/Controller.hpp>
#include <sgengine/core/InputComponent.hpp>

namespace SG
{
	InputComponent::InputComponent(Controller* controller, GameObject* gameObject) : Component(gameObject,SGComponentTypes::Input),CurrentController(controller)
	{
	}

	void InputComponent::TakeControl(SG::Controller* controllerToUse)
	{
		CurrentController = controllerToUse;
	}


}
